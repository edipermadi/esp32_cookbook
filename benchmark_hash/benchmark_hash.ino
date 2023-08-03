#include <stdio.h>
#include <mbedtls/md.h>
#include <mbedtls/error.h>
#include <esp_random.h>

static unsigned long measure_hash(mbedtls_md_type_t type) {
  uint8_t buffer[1024];
  uint8_t digest[MBEDTLS_MD_MAX_SIZE];
  char err_msg[1024];

  esp_fill_random(buffer, sizeof(buffer));

  mbedtls_md_context_t ctx;
  mbedtls_md_init(&ctx);

  int err = mbedtls_md_setup(&ctx, mbedtls_md_info_from_type(type), 0);
  if (err != 0) {
    return err;
  }

  err = mbedtls_md_starts(&ctx);
  if (err != 0) {
    return err;
  }

  unsigned long start = millis();
  for (int i = 0; i < 1024; i++) {
    err = mbedtls_md_update(&ctx, buffer, sizeof(buffer));
    if (err != 0) {
      return err;
    }
  }

  err = mbedtls_md_finish(&ctx, digest);
  if (err != 0) {
    return err;
  }

  unsigned long end = millis();
  return end - start;
}

void setup() {
  Serial.begin(115200);
  esp_log_level_set("benchmark_hash", ESP_LOG_WARN);
}

void loop() {
  for (int i = int(MBEDTLS_MD_MD5); i < int(MBEDTLS_MD_SHA512) + 1; i++) {
    mbedtls_md_type_t type = mbedtls_md_type_t(i);
    unsigned long duration = measure_hash(type);
    switch (type) {
      case MBEDTLS_MD_MD5:
        printf("hashed 1MB of random byte using MBEDTLS_MD_MD5 in %d ms\n", duration);
        break;
      case MBEDTLS_MD_SHA1:
        printf("hashed 1MB of random byte using MBEDTLS_MD_SHA1 in %d ms\n", duration);
        break;
      case MBEDTLS_MD_SHA224:
        printf("hashed 1MB of random byte using MBEDTLS_MD_SHA224 in %d ms\n", duration);
        break;
      case MBEDTLS_MD_SHA256:
        printf("hashed 1MB of random byte using MBEDTLS_MD_SHA256 in %d ms\n", duration);
        break;
      case MBEDTLS_MD_SHA384:
        printf("hashed 1MB of random byte using MBEDTLS_MD_SHA384 in %d ms\n", duration);
        break;
      case MBEDTLS_MD_SHA512:
        printf("hashed 1MB of random byte using MBEDTLS_MD_SHA512 in %d ms\n", duration);
        break;
    }
  }

  printf("\n");
  delay(1000);
}
