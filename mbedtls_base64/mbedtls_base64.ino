#include <stdint.h>
#include <string.h>
#include <mbedtls/base64.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  uint8_t random_in[32];
  uint8_t random_out[32];
  uint8_t buffer[256];

  // clear buffers
  memset(random_in, 0, sizeof(random_in));
  memset(random_out, 0, sizeof(random_out));
  memset(buffer, 0, sizeof(buffer));

  // fill random
  esp_fill_random(random_in, sizeof(random_in));

  // encode random
  size_t encode_output_length;
  int ret = mbedtls_base64_encode(buffer, sizeof(buffer), &encode_output_length, random_in, sizeof(random_in));
  if (ret < 0) {
    Serial.println("failed to encode base64");
    return;
  }

  // decode random
  size_t decode_output_length;
  ret = mbedtls_base64_decode(random_out, sizeof(random_out), &decode_output_length, buffer, encode_output_length);
  if (ret < 0) {
    Serial.println("failed to decode base64");
    return;
  }

  // compare result
  if (memcmp(random_in, random_out, sizeof(random_out)) != 0) {
    Serial.println("decoded base64 did not match original value");
  } else {
    Serial.println("decoded base64 did match original value");
  }

  sleep(1);
}
