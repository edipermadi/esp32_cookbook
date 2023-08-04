#include <stdio.h>
#include <mbedtls/cipher.h>
#include <mbedtls/error.h>
#include <esp_random.h>

static unsigned long measure_cipher(mbedtls_cipher_type_t type, mbedtls_operation_t operation, mbedtls_cipher_padding_t padding) {
  uint8_t buffer[1024];
  esp_fill_random(buffer, sizeof(buffer));

  const mbedtls_cipher_info_t *info = mbedtls_cipher_info_from_type(type);

  mbedtls_cipher_context_t ctx;
  mbedtls_cipher_init(&ctx);

  // set algorithm
  int err = mbedtls_cipher_setup(&ctx, info);
  if (err != 0) {
    return err;
  }

  // generate key
  int key_len = mbedtls_cipher_get_key_bitlen(&ctx);
  uint8_t key[MBEDTLS_MAX_KEY_LENGTH];
  esp_fill_random(key, sizeof(key));

  // set key
  err = mbedtls_cipher_setkey(&ctx, key, key_len, operation);
  if (err != 0) {
    return err;
  }

  // generate iv
  int iv_len = mbedtls_cipher_get_iv_size(&ctx);
  if (iv_len > 0) {
    uint8_t iv[MBEDTLS_MAX_IV_LENGTH];
    esp_fill_random(iv, sizeof(iv));

    // set iv
    err = mbedtls_cipher_set_iv(&ctx, iv, iv_len);
    if (err != 0) {
      return err;
    }
  }

  // set padding mode
  err = mbedtls_cipher_set_padding_mode(&ctx, padding);
  if (err != 0 && err != MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA) {
    return err;
  }

  size_t output_len;
  uint8_t output[2048];

  unsigned long start;
  if (info->mode == MBEDTLS_MODE_ECB) {
    uint8_t *ptr_end = (buffer + sizeof(buffer));

    start = millis();
    for (uint8_t *ptr = buffer; ptr < ptr_end; ptr += info->block_size) {
      output_len = sizeof(output);
      err = mbedtls_cipher_update(&ctx, ptr, info->block_size, output, &output_len);
      if (err != 0) {
        return err;
      }
    }
  } else {
    start = millis();
    for (int i = 0; i < 1024; i++) {
      output_len = sizeof(output);
      err = mbedtls_cipher_update(&ctx, buffer, sizeof(buffer), output, &output_len);
      if (err != 0) {
        return err;
      }
    }
  }

  // finish cipher
  output_len = sizeof(output);
  err = mbedtls_cipher_finish(&ctx, output, &output_len);
  if (err != 0) {
    return err;
  }

  unsigned long end = millis();
  return end - start;
}

void setup() {
  Serial.begin(115200);
}

const char *get_padding_name(mbedtls_cipher_padding_t padding) {
  switch (padding) {
    case MBEDTLS_PADDING_PKCS7:
      return "MBEDTLS_PADDING_PKCS7";
    case MBEDTLS_PADDING_ONE_AND_ZEROS:
      return "MBEDTLS_PADDING_ONE_AND_ZEROS";
    case MBEDTLS_PADDING_ZEROS_AND_LEN:
      return "MBEDTLS_PADDING_ZEROS_AND_LEN";
    case MBEDTLS_PADDING_ZEROS:
      return "MBEDTLS_PADDING_ZEROS";
    case MBEDTLS_PADDING_NONE:
      return "MBEDTLS_PADDING_NONE";
    default:
      return "";
  }
}

void loop() {
  for (int j = int(MBEDTLS_CIPHER_AES_128_ECB); j < int(MBEDTLS_CIPHER_AES_256_KWP) + 1; j++) {
    mbedtls_cipher_type_t type = mbedtls_cipher_type_t(j);

    // check if algorithm is supported
    const mbedtls_cipher_info_t *info = mbedtls_cipher_info_from_type(type);
    if (info == NULL) {
      continue;
    }

    for (int k = int(MBEDTLS_PADDING_PKCS7); k < int(MBEDTLS_PADDING_NONE) + 1; k++) {
      mbedtls_cipher_padding_t padding = mbedtls_cipher_padding_t(k);
      const char *padding_name = get_padding_name(padding);

      long duration = measure_cipher(type, MBEDTLS_ENCRYPT, padding);
      if (duration < 0) {
        char error_msg[500];
        mbedtls_strerror(duration, error_msg, sizeof(error_msg));
        printf("encrypted 1MB of random data using %s (%s) with failure: %s\n", info->name, padding_name, error_msg);
      } else {
        printf("encrypted 1MB of random data using %s (%s) in %d ms\n", info->name, padding_name, duration);
      }
    }
  }

  printf("\n");
  delay(1000);
}
