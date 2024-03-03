#include <string.h>
#include <mbedtls/md.h>
#include <mbedtls/pkcs5.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  uint8_t password[32];
  uint8_t salt[32];
  uint8_t key_out[32];
  int iteration = 60000;

  memset(password, 0, sizeof(password));
  memset(salt, 0, sizeof(salt));
  memset(key_out, 0, sizeof(key_out));
  
  strncpy((char *)password, "password", sizeof(password));
  size_t password_length = strlen((const char *)password);

  esp_fill_random(salt, sizeof(salt));

  long int t1 = millis();
  mbedtls_md_context_t ctx;
  mbedtls_md_init(&ctx);
  mbedtls_md_setup(&ctx, mbedtls_md_info_from_type(MBEDTLS_MD_SHA256), 1);
  mbedtls_pkcs5_pbkdf2_hmac(&ctx,
                            password,
                            password_length,
                            (unsigned char *)salt,
                            sizeof(salt),
                            iteration,
                            sizeof(key_out),
                            key_out);

  long int t2 = millis();

  Serial.printf("completed in %d ms:\n", t2 - t1);
  for(int i=0;i<sizeof(key_out);i++){
    Serial.printf("%02x", key_out[i]);
  }
  Serial.printf("\n---\n\n");
}
