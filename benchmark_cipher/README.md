# ESP32 cipher benchmark using mbedtls

## Result

```
$ picocom /dev/ttyUSB0 -b 115200 -q
ets Jun  8 2016 00:22:57

rst:0x1 (POWERON_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0xee
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:1
load:0x3fff0030,len:1344
load:0x40078000,len:13964
load:0x40080400,len:3600
entry 0x400805f0
encrypted 1MB of random data using AES-128-ECB (MBEDTLS_PADDING_PKCS7) in 0 ms
encrypted 1MB of random data using AES-128-ECB (MBEDTLS_PADDING_ONE_AND_ZEROS) in 0 ms
encrypted 1MB of random data using AES-128-ECB (MBEDTLS_PADDING_ZEROS_AND_LEN) in 1 ms
encrypted 1MB of random data using AES-128-ECB (MBEDTLS_PADDING_ZEROS) in 1 ms
encrypted 1MB of random data using AES-128-ECB (MBEDTLS_PADDING_NONE) in 0 ms
encrypted 1MB of random data using AES-192-ECB (MBEDTLS_PADDING_PKCS7) in 0 ms
encrypted 1MB of random data using AES-192-ECB (MBEDTLS_PADDING_ONE_AND_ZEROS) in 0 ms
encrypted 1MB of random data using AES-192-ECB (MBEDTLS_PADDING_ZEROS_AND_LEN) in 1 ms
encrypted 1MB of random data using AES-192-ECB (MBEDTLS_PADDING_ZEROS) in 1 ms
encrypted 1MB of random data using AES-192-ECB (MBEDTLS_PADDING_NONE) in 1 ms
encrypted 1MB of random data using AES-256-ECB (MBEDTLS_PADDING_PKCS7) in 0 ms
encrypted 1MB of random data using AES-256-ECB (MBEDTLS_PADDING_ONE_AND_ZEROS) in 0 ms
encrypted 1MB of random data using AES-256-ECB (MBEDTLS_PADDING_ZEROS_AND_LEN) in 1 ms
encrypted 1MB of random data using AES-256-ECB (MBEDTLS_PADDING_ZEROS) in 1 ms
encrypted 1MB of random data using AES-256-ECB (MBEDTLS_PADDING_NONE) in 1 ms
encrypted 1MB of random data using AES-128-CBC (MBEDTLS_PADDING_PKCS7) in 121 ms
encrypted 1MB of random data using AES-128-CBC (MBEDTLS_PADDING_ONE_AND_ZEROS) in 122 ms
encrypted 1MB of random data using AES-128-CBC (MBEDTLS_PADDING_ZEROS_AND_LEN) in 121 ms
encrypted 1MB of random data using AES-128-CBC (MBEDTLS_PADDING_ZEROS) in 121 ms
encrypted 1MB of random data using AES-128-CBC (MBEDTLS_PADDING_NONE) in 121 ms
encrypted 1MB of random data using AES-192-CBC (MBEDTLS_PADDING_PKCS7) in 121 ms
encrypted 1MB of random data using AES-192-CBC (MBEDTLS_PADDING_ONE_AND_ZEROS) in 121 ms
encrypted 1MB of random data using AES-192-CBC (MBEDTLS_PADDING_ZEROS_AND_LEN) in 121 ms
encrypted 1MB of random data using AES-192-CBC (MBEDTLS_PADDING_ZEROS) in 122 ms
encrypted 1MB of random data using AES-192-CBC (MBEDTLS_PADDING_NONE) in 122 ms
encrypted 1MB of random data using AES-256-CBC (MBEDTLS_PADDING_PKCS7) in 122 ms
encrypted 1MB of random data using AES-256-CBC (MBEDTLS_PADDING_ONE_AND_ZEROS) in 122 ms
encrypted 1MB of random data using AES-256-CBC (MBEDTLS_PADDING_ZEROS_AND_LEN) in 122 ms
encrypted 1MB of random data using AES-256-CBC (MBEDTLS_PADDING_ZEROS) in 123 ms
encrypted 1MB of random data using AES-256-CBC (MBEDTLS_PADDING_NONE) in 122 ms
encrypted 1MB of random data using AES-128-CFB128 (MBEDTLS_PADDING_PKCS7) in 223 ms
encrypted 1MB of random data using AES-128-CFB128 (MBEDTLS_PADDING_ONE_AND_ZEROS) in 222 ms
encrypted 1MB of random data using AES-128-CFB128 (MBEDTLS_PADDING_ZEROS_AND_LEN) in 222 ms
encrypted 1MB of random data using AES-128-CFB128 (MBEDTLS_PADDING_ZEROS) in 223 ms
encrypted 1MB of random data using AES-128-CFB128 (MBEDTLS_PADDING_NONE) in 223 ms
encrypted 1MB of random data using AES-192-CFB128 (MBEDTLS_PADDING_PKCS7) in 223 ms
encrypted 1MB of random data using AES-192-CFB128 (MBEDTLS_PADDING_ONE_AND_ZEROS) in 223 ms
encrypted 1MB of random data using AES-192-CFB128 (MBEDTLS_PADDING_ZEROS_AND_LEN) in 223 ms
encrypted 1MB of random data using AES-192-CFB128 (MBEDTLS_PADDING_ZEROS) in 223 ms
encrypted 1MB of random data using AES-192-CFB128 (MBEDTLS_PADDING_NONE) in 222 ms
encrypted 1MB of random data using AES-256-CFB128 (MBEDTLS_PADDING_PKCS7) in 223 ms
encrypted 1MB of random data using AES-256-CFB128 (MBEDTLS_PADDING_ONE_AND_ZEROS) in 224 ms
encrypted 1MB of random data using AES-256-CFB128 (MBEDTLS_PADDING_ZEROS_AND_LEN) in 223 ms
encrypted 1MB of random data using AES-256-CFB128 (MBEDTLS_PADDING_ZEROS) in 224 ms
encrypted 1MB of random data using AES-256-CFB128 (MBEDTLS_PADDING_NONE) in 223 ms
encrypted 1MB of random data using AES-128-CTR (MBEDTLS_PADDING_PKCS7) in 232 ms
encrypted 1MB of random data using AES-128-CTR (MBEDTLS_PADDING_ONE_AND_ZEROS) in 233 ms
encrypted 1MB of random data using AES-128-CTR (MBEDTLS_PADDING_ZEROS_AND_LEN) in 232 ms
encrypted 1MB of random data using AES-128-CTR (MBEDTLS_PADDING_ZEROS) in 232 ms
encrypted 1MB of random data using AES-128-CTR (MBEDTLS_PADDING_NONE) in 233 ms
encrypted 1MB of random data using AES-192-CTR (MBEDTLS_PADDING_PKCS7) in 233 ms
encrypted 1MB of random data using AES-192-CTR (MBEDTLS_PADDING_ONE_AND_ZEROS) in 233 ms
encrypted 1MB of random data using AES-192-CTR (MBEDTLS_PADDING_ZEROS_AND_LEN) in 233 ms
encrypted 1MB of random data using AES-192-CTR (MBEDTLS_PADDING_ZEROS) in 232 ms
encrypted 1MB of random data using AES-192-CTR (MBEDTLS_PADDING_NONE) in 233 ms
encrypted 1MB of random data using AES-256-CTR (MBEDTLS_PADDING_PKCS7) in 233 ms
encrypted 1MB of random data using AES-256-CTR (MBEDTLS_PADDING_ONE_AND_ZEROS) in 234 ms
encrypted 1MB of random data using AES-256-CTR (MBEDTLS_PADDING_ZEROS_AND_LEN) in 233 ms
encrypted 1MB of random data using AES-256-CTR (MBEDTLS_PADDING_ZEROS) in 233 ms
encrypted 1MB of random data using AES-256-CTR (MBEDTLS_PADDING_NONE) in 233 ms
encrypted 1MB of random data using AES-128-GCM (MBEDTLS_PADDING_PKCS7) in 1161 ms
encrypted 1MB of random data using AES-128-GCM (MBEDTLS_PADDING_ONE_AND_ZEROS) in 1162 ms
encrypted 1MB of random data using AES-128-GCM (MBEDTLS_PADDING_ZEROS_AND_LEN) in 1162 ms
encrypted 1MB of random data using AES-128-GCM (MBEDTLS_PADDING_ZEROS) in 1162 ms
encrypted 1MB of random data using AES-128-GCM (MBEDTLS_PADDING_NONE) in 1162 ms
encrypted 1MB of random data using AES-192-GCM (MBEDTLS_PADDING_PKCS7) in 1188 ms
encrypted 1MB of random data using AES-192-GCM (MBEDTLS_PADDING_ONE_AND_ZEROS) in 1188 ms
encrypted 1MB of random data using AES-192-GCM (MBEDTLS_PADDING_ZEROS_AND_LEN) in 1188 ms
encrypted 1MB of random data using AES-192-GCM (MBEDTLS_PADDING_ZEROS) in 1188 ms
encrypted 1MB of random data using AES-192-GCM (MBEDTLS_PADDING_NONE) in 1188 ms
encrypted 1MB of random data using AES-256-GCM (MBEDTLS_PADDING_PKCS7) in 1214 ms
encrypted 1MB of random data using AES-256-GCM (MBEDTLS_PADDING_ONE_AND_ZEROS) in 1215 ms
encrypted 1MB of random data using AES-256-GCM (MBEDTLS_PADDING_ZEROS_AND_LEN) in 1215 ms
encrypted 1MB of random data using AES-256-GCM (MBEDTLS_PADDING_ZEROS) in 1215 ms
encrypted 1MB of random data using AES-256-GCM (MBEDTLS_PADDING_NONE) in 1214 ms
encrypted 1MB of random data using CAMELLIA-128-ECB (MBEDTLS_PADDING_PKCS7) in 1 ms
encrypted 1MB of random data using CAMELLIA-128-ECB (MBEDTLS_PADDING_ONE_AND_ZEROS) in 1 ms
encrypted 1MB of random data using CAMELLIA-128-ECB (MBEDTLS_PADDING_ZEROS_AND_LEN) in 1 ms
encrypted 1MB of random data using CAMELLIA-128-ECB (MBEDTLS_PADDING_ZEROS) in 1 ms
encrypted 1MB of random data using CAMELLIA-128-ECB (MBEDTLS_PADDING_NONE) in 0 ms
encrypted 1MB of random data using CAMELLIA-192-ECB (MBEDTLS_PADDING_PKCS7) in 1 ms
encrypted 1MB of random data using CAMELLIA-192-ECB (MBEDTLS_PADDING_ONE_AND_ZEROS) in 1 ms
encrypted 1MB of random data using CAMELLIA-192-ECB (MBEDTLS_PADDING_ZEROS_AND_LEN) in 1 ms
encrypted 1MB of random data using CAMELLIA-192-ECB (MBEDTLS_PADDING_ZEROS) in 1 ms
encrypted 1MB of random data using CAMELLIA-192-ECB (MBEDTLS_PADDING_NONE) in 1 ms
encrypted 1MB of random data using CAMELLIA-256-ECB (MBEDTLS_PADDING_PKCS7) in 1 ms
encrypted 1MB of random data using CAMELLIA-256-ECB (MBEDTLS_PADDING_ONE_AND_ZEROS) in 1 ms
encrypted 1MB of random data using CAMELLIA-256-ECB (MBEDTLS_PADDING_ZEROS_AND_LEN) in 0 ms
encrypted 1MB of random data using CAMELLIA-256-ECB (MBEDTLS_PADDING_ZEROS) in 0 ms
encrypted 1MB of random data using CAMELLIA-256-ECB (MBEDTLS_PADDING_NONE) in 1 ms
encrypted 1MB of random data using CAMELLIA-128-CBC (MBEDTLS_PADDING_PKCS7) in 736 ms
encrypted 1MB of random data using CAMELLIA-128-CBC (MBEDTLS_PADDING_ONE_AND_ZEROS) in 736 ms
encrypted 1MB of random data using CAMELLIA-128-CBC (MBEDTLS_PADDING_ZEROS_AND_LEN) in 736 ms
encrypted 1MB of random data using CAMELLIA-128-CBC (MBEDTLS_PADDING_ZEROS) in 735 ms
encrypted 1MB of random data using CAMELLIA-128-CBC (MBEDTLS_PADDING_NONE) in 735 ms
encrypted 1MB of random data using CAMELLIA-192-CBC (MBEDTLS_PADDING_PKCS7) in 941 ms
encrypted 1MB of random data using CAMELLIA-192-CBC (MBEDTLS_PADDING_ONE_AND_ZEROS) in 941 ms
encrypted 1MB of random data using CAMELLIA-192-CBC (MBEDTLS_PADDING_ZEROS_AND_LEN) in 942 ms
encrypted 1MB of random data using CAMELLIA-192-CBC (MBEDTLS_PADDING_ZEROS) in 942 ms
encrypted 1MB of random data using CAMELLIA-192-CBC (MBEDTLS_PADDING_NONE) in 942 ms
encrypted 1MB of random data using CAMELLIA-256-CBC (MBEDTLS_PADDING_PKCS7) in 941 ms
encrypted 1MB of random data using CAMELLIA-256-CBC (MBEDTLS_PADDING_ONE_AND_ZEROS) in 941 ms
encrypted 1MB of random data using CAMELLIA-256-CBC (MBEDTLS_PADDING_ZEROS_AND_LEN) in 941 ms
encrypted 1MB of random data using CAMELLIA-256-CBC (MBEDTLS_PADDING_ZEROS) in 942 ms
encrypted 1MB of random data using CAMELLIA-256-CBC (MBEDTLS_PADDING_NONE) in 942 ms
encrypted 1MB of random data using CAMELLIA-128-CFB128 (MBEDTLS_PADDING_PKCS7) in 777 ms
encrypted 1MB of random data using CAMELLIA-128-CFB128 (MBEDTLS_PADDING_ONE_AND_ZEROS) in 777 ms
encrypted 1MB of random data using CAMELLIA-128-CFB128 (MBEDTLS_PADDING_ZEROS_AND_LEN) in 778 ms
encrypted 1MB of random data using CAMELLIA-128-CFB128 (MBEDTLS_PADDING_ZEROS) in 777 ms
encrypted 1MB of random data using CAMELLIA-128-CFB128 (MBEDTLS_PADDING_NONE) in 777 ms
encrypted 1MB of random data using CAMELLIA-192-CFB128 (MBEDTLS_PADDING_PKCS7) in 983 ms
encrypted 1MB of random data using CAMELLIA-192-CFB128 (MBEDTLS_PADDING_ONE_AND_ZEROS) in 983 ms
encrypted 1MB of random data using CAMELLIA-192-CFB128 (MBEDTLS_PADDING_ZEROS_AND_LEN) in 984 ms
encrypted 1MB of random data using CAMELLIA-192-CFB128 (MBEDTLS_PADDING_ZEROS) in 983 ms
encrypted 1MB of random data using CAMELLIA-192-CFB128 (MBEDTLS_PADDING_NONE) in 983 ms
encrypted 1MB of random data using CAMELLIA-256-CFB128 (MBEDTLS_PADDING_PKCS7) in 983 ms
encrypted 1MB of random data using CAMELLIA-256-CFB128 (MBEDTLS_PADDING_ONE_AND_ZEROS) in 983 ms
encrypted 1MB of random data using CAMELLIA-256-CFB128 (MBEDTLS_PADDING_ZEROS_AND_LEN) in 983 ms
encrypted 1MB of random data using CAMELLIA-256-CFB128 (MBEDTLS_PADDING_ZEROS) in 983 ms
encrypted 1MB of random data using CAMELLIA-256-CFB128 (MBEDTLS_PADDING_NONE) in 984 ms
encrypted 1MB of random data using CAMELLIA-128-CTR (MBEDTLS_PADDING_PKCS7) in 791 ms
encrypted 1MB of random data using CAMELLIA-128-CTR (MBEDTLS_PADDING_ONE_AND_ZEROS) in 791 ms
encrypted 1MB of random data using CAMELLIA-128-CTR (MBEDTLS_PADDING_ZEROS_AND_LEN) in 792 ms
encrypted 1MB of random data using CAMELLIA-128-CTR (MBEDTLS_PADDING_ZEROS) in 791 ms
encrypted 1MB of random data using CAMELLIA-128-CTR (MBEDTLS_PADDING_NONE) in 791 ms
encrypted 1MB of random data using CAMELLIA-192-CTR (MBEDTLS_PADDING_PKCS7) in 998 ms
encrypted 1MB of random data using CAMELLIA-192-CTR (MBEDTLS_PADDING_ONE_AND_ZEROS) in 997 ms
encrypted 1MB of random data using CAMELLIA-192-CTR (MBEDTLS_PADDING_ZEROS_AND_LEN) in 997 ms
encrypted 1MB of random data using CAMELLIA-192-CTR (MBEDTLS_PADDING_ZEROS) in 998 ms
encrypted 1MB of random data using CAMELLIA-192-CTR (MBEDTLS_PADDING_NONE) in 997 ms
encrypted 1MB of random data using CAMELLIA-256-CTR (MBEDTLS_PADDING_PKCS7) in 997 ms
encrypted 1MB of random data using CAMELLIA-256-CTR (MBEDTLS_PADDING_ONE_AND_ZEROS) in 998 ms
encrypted 1MB of random data using CAMELLIA-256-CTR (MBEDTLS_PADDING_ZEROS_AND_LEN) in 997 ms
encrypted 1MB of random data using CAMELLIA-256-CTR (MBEDTLS_PADDING_ZEROS) in 997 ms
encrypted 1MB of random data using CAMELLIA-256-CTR (MBEDTLS_PADDING_NONE) in 998 ms
encrypted 1MB of random data using CAMELLIA-128-GCM (MBEDTLS_PADDING_PKCS7) in 1276 ms
encrypted 1MB of random data using CAMELLIA-128-GCM (MBEDTLS_PADDING_ONE_AND_ZEROS) in 1276 ms
encrypted 1MB of random data using CAMELLIA-128-GCM (MBEDTLS_PADDING_ZEROS_AND_LEN) in 1276 ms
encrypted 1MB of random data using CAMELLIA-128-GCM (MBEDTLS_PADDING_ZEROS) in 1275 ms
encrypted 1MB of random data using CAMELLIA-128-GCM (MBEDTLS_PADDING_NONE) in 1275 ms
encrypted 1MB of random data using CAMELLIA-192-GCM (MBEDTLS_PADDING_PKCS7) in 1481 ms
encrypted 1MB of random data using CAMELLIA-192-GCM (MBEDTLS_PADDING_ONE_AND_ZEROS) in 1481 ms
encrypted 1MB of random data using CAMELLIA-192-GCM (MBEDTLS_PADDING_ZEROS_AND_LEN) in 1482 ms
encrypted 1MB of random data using CAMELLIA-192-GCM (MBEDTLS_PADDING_ZEROS) in 1482 ms
encrypted 1MB of random data using CAMELLIA-192-GCM (MBEDTLS_PADDING_NONE) in 1482 ms
encrypted 1MB of random data using CAMELLIA-256-GCM (MBEDTLS_PADDING_PKCS7) in 1482 ms
encrypted 1MB of random data using CAMELLIA-256-GCM (MBEDTLS_PADDING_ONE_AND_ZEROS) in 1482 ms
encrypted 1MB of random data using CAMELLIA-256-GCM (MBEDTLS_PADDING_ZEROS_AND_LEN) in 1482 ms
encrypted 1MB of random data using CAMELLIA-256-GCM (MBEDTLS_PADDING_ZEROS) in 1482 ms
encrypted 1MB of random data using CAMELLIA-256-GCM (MBEDTLS_PADDING_NONE) in 1482 ms
encrypted 1MB of random data using AES-128-CCM (MBEDTLS_PADDING_PKCS7) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using AES-128-CCM (MBEDTLS_PADDING_ONE_AND_ZEROS) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using AES-128-CCM (MBEDTLS_PADDING_ZEROS_AND_LEN) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using AES-128-CCM (MBEDTLS_PADDING_ZEROS) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using AES-128-CCM (MBEDTLS_PADDING_NONE) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using AES-192-CCM (MBEDTLS_PADDING_PKCS7) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using AES-192-CCM (MBEDTLS_PADDING_ONE_AND_ZEROS) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using AES-192-CCM (MBEDTLS_PADDING_ZEROS_AND_LEN) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using AES-192-CCM (MBEDTLS_PADDING_ZEROS) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using AES-192-CCM (MBEDTLS_PADDING_NONE) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using AES-256-CCM (MBEDTLS_PADDING_PKCS7) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using AES-256-CCM (MBEDTLS_PADDING_ONE_AND_ZEROS) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using AES-256-CCM (MBEDTLS_PADDING_ZEROS_AND_LEN) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using AES-256-CCM (MBEDTLS_PADDING_ZEROS) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using AES-256-CCM (MBEDTLS_PADDING_NONE) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using CAMELLIA-128-CCM (MBEDTLS_PADDING_PKCS7) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using CAMELLIA-128-CCM (MBEDTLS_PADDING_ONE_AND_ZEROS) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using CAMELLIA-128-CCM (MBEDTLS_PADDING_ZEROS_AND_LEN) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using CAMELLIA-128-CCM (MBEDTLS_PADDING_ZEROS) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using CAMELLIA-128-CCM (MBEDTLS_PADDING_NONE) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using CAMELLIA-192-CCM (MBEDTLS_PADDING_PKCS7) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using CAMELLIA-192-CCM (MBEDTLS_PADDING_ONE_AND_ZEROS) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using CAMELLIA-192-CCM (MBEDTLS_PADDING_ZEROS_AND_LEN) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using CAMELLIA-192-CCM (MBEDTLS_PADDING_ZEROS) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using CAMELLIA-192-CCM (MBEDTLS_PADDING_NONE) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using CAMELLIA-256-CCM (MBEDTLS_PADDING_PKCS7) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using CAMELLIA-256-CCM (MBEDTLS_PADDING_ONE_AND_ZEROS) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using CAMELLIA-256-CCM (MBEDTLS_PADDING_ZEROS_AND_LEN) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using CAMELLIA-256-CCM (MBEDTLS_PADDING_ZEROS) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using CAMELLIA-256-CCM (MBEDTLS_PADDING_NONE) with failure: CIPHER - The selected feature is not available
encrypted 1MB of random data using AES-128-OFB (MBEDTLS_PADDING_PKCS7) in 231 ms
encrypted 1MB of random data using AES-128-OFB (MBEDTLS_PADDING_ONE_AND_ZEROS) in 231 ms
encrypted 1MB of random data using AES-128-OFB (MBEDTLS_PADDING_ZEROS_AND_LEN) in 231 ms
encrypted 1MB of random data using AES-128-OFB (MBEDTLS_PADDING_ZEROS) in 232 ms
encrypted 1MB of random data using AES-128-OFB (MBEDTLS_PADDING_NONE) in 231 ms
encrypted 1MB of random data using AES-192-OFB (MBEDTLS_PADDING_PKCS7) in 232 ms
encrypted 1MB of random data using AES-192-OFB (MBEDTLS_PADDING_ONE_AND_ZEROS) in 232 ms
encrypted 1MB of random data using AES-192-OFB (MBEDTLS_PADDING_ZEROS_AND_LEN) in 231 ms
encrypted 1MB of random data using AES-192-OFB (MBEDTLS_PADDING_ZEROS) in 231 ms
encrypted 1MB of random data using AES-192-OFB (MBEDTLS_PADDING_NONE) in 231 ms
encrypted 1MB of random data using AES-256-OFB (MBEDTLS_PADDING_PKCS7) in 232 ms
encrypted 1MB of random data using AES-256-OFB (MBEDTLS_PADDING_ONE_AND_ZEROS) in 232 ms
encrypted 1MB of random data using AES-256-OFB (MBEDTLS_PADDING_ZEROS_AND_LEN) in 232 ms
encrypted 1MB of random data using AES-256-OFB (MBEDTLS_PADDING_ZEROS) in 232 ms
encrypted 1MB of random data using AES-256-OFB (MBEDTLS_PADDING_NONE) in 232 ms
encrypted 1MB of random data using AES-128-XTS (MBEDTLS_PADDING_PKCS7) in 736 ms
encrypted 1MB of random data using AES-128-XTS (MBEDTLS_PADDING_ONE_AND_ZEROS) in 736 ms
encrypted 1MB of random data using AES-128-XTS (MBEDTLS_PADDING_ZEROS_AND_LEN) in 736 ms
encrypted 1MB of random data using AES-128-XTS (MBEDTLS_PADDING_ZEROS) in 736 ms
encrypted 1MB of random data using AES-128-XTS (MBEDTLS_PADDING_NONE) in 736 ms
encrypted 1MB of random data using AES-256-XTS (MBEDTLS_PADDING_PKCS7) in 790 ms
encrypted 1MB of random data using AES-256-XTS (MBEDTLS_PADDING_ONE_AND_ZEROS) in 790 ms
encrypted 1MB of random data using AES-256-XTS (MBEDTLS_PADDING_ZEROS_AND_LEN) in 790 ms
encrypted 1MB of random data using AES-256-XTS (MBEDTLS_PADDING_ZEROS) in 790 ms
encrypted 1MB of random data using AES-256-XTS (MBEDTLS_PADDING_NONE) in 790 ms
```