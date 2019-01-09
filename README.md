# BubbleBobblePasswordGenerator
Password generator for the NES game Bubble Bobble in C++

Run the executable from console and follow the prompts. Values are: level, super/regular bubble bobble, magic mirror collected

```
sleepy9090@darkstar64:~/workspace9090/Release$ ./bbpasgen 
Bubble Bobble password generator v 1.0

Coded by: sleepy
======================================

Enter level number (0..127): 99
Enter 0 for Regular Bubble Bobble or 1 for Super Bubble Bobble (0..1): 1
Enter for Crystal Ball collected or not collected (0..3): 1

======================================
Password data: 
  Level number: 99
  Level number (binary): 01100011
  Super Bubble Bobble Flag: 1
  Crystal Ball two digit Binary: 01

==============================
Pre-checksum calculation:
  data2 decimal: 1
  data2 binary: 00000001

==============================
Checksum calculation:
  Add data0Dec + data1Dec + data2Dec + data3Dec
    6 + 1 + 1 + 5
    00000110 + 00000001 + 00000001 + 00000101
  Checksum binary: 00001101
  Temp Data Binary (add with data 2): 0010
  Temp Data Decimal: 2

==============================
Pre-XORing:
  data0 Decimal: 6
  data0 Binary: 00000110
  data1 Decimal: 1
  data1 Binary: 00000001
  data2 Decimal: 3
  data2 Binary: 00000011
  data3 Decimal: 5
  data3 Binary: 00000101
  data4 Decimal: 5
  data4 Binary: 00000101

==============================
Post-XORing:
  data0 Decimal: 6
  data0 Binary: 00000110
  data1 Decimal: 7
  data1 Binary: 00000111
  data2 Decimal: 4
  data2 Binary: 00000100
  data3 Decimal: 1
  data3 Binary: 00000001
  data4 Decimal: 4
  data4 Binary: 00000100

==============================
Encoding using Cipher:
  Found match: G
  Found match: E
  Found match: J
  Found match: A
  Found match: J

==============================

Generated password: GEJAJ

==============================
```

Compiled and tested with:
gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.11) 



