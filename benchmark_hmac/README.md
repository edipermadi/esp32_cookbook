# ESP32 hmac benchmark using mbedtls

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
hmac 1MB of random byte using MBEDTLS_MD_MD5 in 59 ms
hmac 1MB of random byte using MBEDTLS_MD_SHA1 in 109 ms
hmac 1MB of random byte using MBEDTLS_MD_SHA224 in 286 ms
hmac 1MB of random byte using MBEDTLS_MD_SHA256 in 108 ms
hmac 1MB of random byte using MBEDTLS_MD_SHA384 in 78 ms
hmac 1MB of random byte using MBEDTLS_MD_SHA512 in 78 ms
```
