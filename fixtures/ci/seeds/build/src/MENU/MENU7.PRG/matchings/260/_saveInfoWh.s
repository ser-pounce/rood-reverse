nonmatching _saveInfoWh

dlabel _saveInfoWh
    /* 7B0C 8010A30C 03000800 */ .word 0x00080003
    /* 7B10 8010A310 0D000800 */ .word 0x0008000D
    /* 7B14 8010A314 11000800 */ .word 0x00080011 /* invalid instruction */
    /* 7B18 8010A318 16000800 */ .word 0x00080016
    /* 7B1C 8010A31C 1A000800 */ .word 0x0008001A
    /* 7B20 8010A320 13000800 */ .word 0x00080013 /* invalid instruction */
    /* 7B24 8010A324 0A000A00 */ .word 0x000A000A
    /* 7B28 8010A328 10000900 */ .word 0x00090010 /* invalid instruction */
    /* 7B2C 8010A32C 12000900 */ .word 0x00090012 /* invalid instruction */
    /* 7B30 8010A330 05000700 */ .word 0x00070005 /* invalid instruction */
enddlabel _saveInfoWh
