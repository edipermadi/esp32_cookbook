#include <mbedtls/asn1.h>
#include <mbedtls/asn1write.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  sleep(1);

  // We will be encoding the following struct
  // {
  //    int message;
  //    []uint8_t data;
  // }

  size_t buffer_size = 1024;
  uint8_t *buffer = (uint8_t *)malloc(buffer_size);
  memset(buffer, 0, buffer_size);
  uint8_t data[8] = { 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef };

  uint8_t *buffer_start = &buffer[0];
  uint8_t *buffer_end = &buffer[buffer_size - 1];
  uint8_t *p = buffer_end;
  size_t buffer_length = 0;
  int ret = 0;

  // encode backward

  // encode data value
  ret = mbedtls_asn1_write_raw_buffer(&p, buffer_start, data, sizeof(data));
  if (ret < 0) {
    free(buffer);
    Serial.printf("error 0 %02x\n", ret);
    return;
  }
  buffer_length += ret;

  // encode data length
  ret = mbedtls_asn1_write_len(&p, buffer_start, sizeof(data));
  if (ret < 0) {
    free(buffer);
    Serial.printf("error 1 %02x\n", ret);
    return;
  }
  buffer_length += ret;

  // encode data tag
  ret = mbedtls_asn1_write_tag(&p, buffer_start, MBEDTLS_ASN1_OCTET_STRING);
  if (ret < 0) {
    free(buffer);
    Serial.printf("error 2 %02x\n", ret);
    return;
  }
  buffer_length += ret;

  // encode id value
  ret = mbedtls_asn1_write_int(&p, buffer_start, 0xaa);
  if (ret < 0) {
    free(buffer);
    Serial.printf("error 3 %02x\n", ret);
    return;
  }
  buffer_length += ret;
  
  // encode struct body length
  ret = mbedtls_asn1_write_len(&p, buffer_start, buffer_length);
  if (ret < 0) {
    free(buffer);
    Serial.printf("error 6 %02x\n", ret);
    return;
  }
  buffer_length += ret;

  // encode struct tag
  ret = mbedtls_asn1_write_tag(&p, buffer_start, MBEDTLS_ASN1_CONSTRUCTED | MBEDTLS_ASN1_SEQUENCE);
  if (ret < 0) {
    free(buffer);
    Serial.printf("error 7 %02x\n", ret);
    return;
  }
  buffer_length += ret;

  // dump result
  Serial.printf("encoded: ");
  for (int i = 0; i < buffer_length; i++) {
    Serial.printf("%02x", p[i]);
  }
  Serial.printf("\n");

  free(buffer);
}
