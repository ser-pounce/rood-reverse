nonmatching Sound_MapInstrumentToBaseSampleBank, 0x58

glabel Sound_MapInstrumentToBaseSampleBank
    /* 6354 80015B54 40008430 */  andi       $a0, $a0, 0x40
    /* 6358 80015B58 11008010 */  beqz       $a0, .L80015BA0
    /* 635C 80015B5C 00000000 */   nop
    /* 6360 80015B60 6A00A394 */  lhu        $v1, 0x6A($a1)
    /* 6364 80015B64 00000000 */  nop
    /* 6368 80015B68 6000622C */  sltiu      $v0, $v1, 0x60
    /* 636C 80015B6C 0C004014 */  bnez       $v0, .L80015BA0
    /* 6370 80015B70 8000622C */   sltiu     $v0, $v1, 0x80
    /* 6374 80015B74 0A004010 */  beqz       $v0, .L80015BA0
    /* 6378 80015B78 FEFF043C */   lui       $a0, (0xFFFE0000 >> 16)
    /* 637C 80015B7C FC00A28C */  lw         $v0, 0xFC($a1)
    /* 6380 80015B80 6A00A394 */  lhu        $v1, 0x6A($a1)
    /* 6384 80015B84 21104400 */  addu       $v0, $v0, $a0
    /* 6388 80015B88 FC00A2AC */  sw         $v0, 0xFC($a1)
    /* 638C 80015B8C 0001A28C */  lw         $v0, 0x100($a1)
    /* 6390 80015B90 E0FF6324 */  addiu      $v1, $v1, -0x20
    /* 6394 80015B94 6A00A3A4 */  sh         $v1, 0x6A($a1)
    /* 6398 80015B98 21104400 */  addu       $v0, $v0, $a0
    /* 639C 80015B9C 0001A2AC */  sw         $v0, 0x100($a1)
  .L80015BA0:
    /* 63A0 80015BA0 6A00A294 */  lhu        $v0, 0x6A($a1)
    /* 63A4 80015BA4 0800E003 */  jr         $ra
    /* 63A8 80015BA8 00000000 */   nop
endlabel Sound_MapInstrumentToBaseSampleBank
