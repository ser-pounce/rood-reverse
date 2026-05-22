nonmatching func_800CCD00, 0x40

glabel func_800CCD00
    /* 64500 800CCD00 FF00033C */  lui        $v1, (0xFFFFFF >> 16)
    /* 64504 800CCD04 FFFF6334 */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* 64508 800CCD08 801F073C */  lui        $a3, (0x1F800000 >> 16)
    /* 6450C 800CCD0C 0000A28C */  lw         $v0, 0x0($a1)
    /* 64510 800CCD10 0001063C */  lui        $a2, (0x1000000 >> 16)
    /* 64514 800CCD14 24104300 */  and        $v0, $v0, $v1
    /* 64518 800CCD18 0000E38C */  lw         $v1, (0x1F800000 & 0xFFFF)($a3)
    /* 6451C 800CCD1C 25104600 */  or         $v0, $v0, $a2
    /* 64520 800CCD20 000062AC */  sw         $v0, 0x0($v1)
    /* 64524 800CCD24 00120300 */  sll        $v0, $v1, 8
    /* 64528 800CCD28 02120200 */  srl        $v0, $v0, 8
    /* 6452C 800CCD2C 040064AC */  sw         $a0, 0x4($v1)
    /* 64530 800CCD30 08006324 */  addiu      $v1, $v1, 0x8
    /* 64534 800CCD34 0000A2AC */  sw         $v0, 0x0($a1)
    /* 64538 800CCD38 0800E003 */  jr         $ra
    /* 6453C 800CCD3C 0000E3AC */   sw        $v1, (0x1F800000 & 0xFFFF)($a3)
endlabel func_800CCD00
