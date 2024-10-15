# Encoding ASN.1 using MBEDTLS

```
{
	int id
	[]byte data
}
```

```
encoded: 300e020200aa04080123456789abcdef

30 0e // 14 bytes if sequence
02 02 00aa // an integer
04 08 0123456789abcdef // 8 bytes of octet string

```
