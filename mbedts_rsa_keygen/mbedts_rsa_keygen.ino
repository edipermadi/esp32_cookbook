#include <stdint.h>
#include <string.h>
#include <mbedtls/rsa.h>
#include <mbedtls/entropy.h>
#include <mbedtls/ctr_drbg.h>

#define KEY_SIZE 4096
#define EXPONENT 65537

static int entropy_func(void *ctx, uint8_t *buffer, size_t length) {
  esp_fill_random(buffer, length);
  return 0;
}

void setup() {
  Serial.begin(115200);
}

void loop() {
  uint8_t perso[32];
  memset(perso, 0, sizeof(perso));
  esp_fill_random(perso, sizeof(perso));

  mbedtls_ctr_drbg_context ctx_drbg;
  mbedtls_ctr_drbg_init(&ctx_drbg);
  mbedtls_ctr_drbg_seed(&ctx_drbg, entropy_func, NULL, perso, sizeof(perso));

  // generate keypair
  mbedtls_rsa_context ctx_rsa;
  mbedtls_rsa_init(&ctx_rsa, MBEDTLS_RSA_PKCS_V15, 0);

  long int t1 = millis();
  int ret = mbedtls_rsa_gen_key(&ctx_rsa, mbedtls_ctr_drbg_random, &ctx_drbg, KEY_SIZE, EXPONENT);
  if (ret < 0) {
    Serial.println("failed to generate RSA keypair");
  } else {
    long int t2 = millis();
    Serial.printf("RSA keypair generated successfully in %d ms\n", t2 - t1);
  }

  mbedtls_rsa_free(&ctx_rsa);
  mbedtls_ctr_drbg_free(&ctx_drbg);

  // sleep
  sleep(2);
}
