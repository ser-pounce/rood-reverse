nonmatching Sound_MapInstrumentToAltSampleBank, 0x58

glabel Sound_MapInstrumentToAltSampleBank
    /* 62FC 80015AFC 40008430 */  andi       $a0, $a0, 0x40
    /* 6300 80015B00 11008010 */  beqz       $a0, .L80015B48
    /* 6304 80015B04 00000000 */   nop
    /* 6308 80015B08 6A00A394 */  lhu        $v1, 0x6A($a1)
    /* 630C 80015B0C 00000000 */  nop
    /* 6310 80015B10 4000622C */  sltiu      $v0, $v1, 0x40
    /* 6314 80015B14 0C004014 */  bnez       $v0, .L80015B48
    /* 6318 80015B18 6000622C */   sltiu     $v0, $v1, 0x60
    /* 631C 80015B1C 0A004010 */  beqz       $v0, .L80015B48
    /* 6320 80015B20 0200043C */   lui       $a0, (0x20000 >> 16)
    /* 6324 80015B24 FC00A28C */  lw         $v0, 0xFC($a1)
    /* 6328 80015B28 6A00A394 */  lhu        $v1, 0x6A($a1)
    /* 632C 80015B2C 21104400 */  addu       $v0, $v0, $a0
    /* 6330 80015B30 FC00A2AC */  sw         $v0, 0xFC($a1)
    /* 6334 80015B34 0001A28C */  lw         $v0, 0x100($a1)
    /* 6338 80015B38 20006324 */  addiu      $v1, $v1, 0x20
    /* 633C 80015B3C 6A00A3A4 */  sh         $v1, 0x6A($a1)
    /* 6340 80015B40 21104400 */  addu       $v0, $v0, $a0
    /* 6344 80015B44 0001A2AC */  sw         $v0, 0x100($a1)
  .L80015B48:
    /* 6348 80015B48 6A00A294 */  lhu        $v0, 0x6A($a1)
    /* 634C 80015B4C 0800E003 */  jr         $ra
    /* 6350 80015B50 00000000 */   nop
endlabel Sound_MapInstrumentToAltSampleBank
