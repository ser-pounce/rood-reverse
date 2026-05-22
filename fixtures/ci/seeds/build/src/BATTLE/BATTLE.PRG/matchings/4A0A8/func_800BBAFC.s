nonmatching func_800BBAFC, 0xEC

glabel func_800BBAFC
    /* 532FC 800BBAFC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 53300 800BBB00 0F80023C */  lui        $v0, %hi(D_800F4B88)
    /* 53304 800BBB04 1000B0AF */  sw         $s0, 0x10($sp)
    /* 53308 800BBB08 884B5024 */  addiu      $s0, $v0, %lo(D_800F4B88)
    /* 5330C 800BBB0C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 53310 800BBB10 03000292 */  lbu        $v0, 0x3($s0)
    /* 53314 800BBB14 00000000 */  nop
    /* 53318 800BBB18 2F004010 */  beqz       $v0, .L800BBBD8
    /* 5331C 800BBB1C 00000000 */   nop
    /* 53320 800BBB20 02000492 */  lbu        $a0, 0x2($s0)
    /* 53324 800BBB24 03000392 */  lbu        $v1, 0x3($s0)
    /* 53328 800BBB28 01008424 */  addiu      $a0, $a0, 0x1
    /* 5332C 800BBB2C FF008230 */  andi       $v0, $a0, 0xFF
    /* 53330 800BBB30 00130200 */  sll        $v0, $v0, 12
    /* 53334 800BBB34 1A004300 */  div        $zero, $v0, $v1
    /* 53338 800BBB38 12100000 */  mflo       $v0
    /* 5333C 800BBB3C 08000386 */  lh         $v1, 0x8($s0)
    /* 53340 800BBB40 00140200 */  sll        $v0, $v0, 16
    /* 53344 800BBB44 03140200 */  sra        $v0, $v0, 16
    /* 53348 800BBB48 18006200 */  mult       $v1, $v0
    /* 5334C 800BBB4C 12400000 */  mflo       $t0
    /* 53350 800BBB50 0E000386 */  lh         $v1, 0xE($s0)
    /* 53354 800BBB54 00000000 */  nop
    /* 53358 800BBB58 18006200 */  mult       $v1, $v0
    /* 5335C 800BBB5C 0C000596 */  lhu        $a1, 0xC($s0)
    /* 53360 800BBB60 14000386 */  lh         $v1, 0x14($s0)
    /* 53364 800BBB64 12300000 */  mflo       $a2
    /* 53368 800BBB68 020004A2 */  sb         $a0, 0x2($s0)
    /* 5336C 800BBB6C 00000000 */  nop
    /* 53370 800BBB70 18006200 */  mult       $v1, $v0
    /* 53374 800BBB74 06000496 */  lhu        $a0, 0x6($s0)
    /* 53378 800BBB78 03130800 */  sra        $v0, $t0, 12
    /* 5337C 800BBB7C 21208200 */  addu       $a0, $a0, $v0
    /* 53380 800BBB80 FF0F8430 */  andi       $a0, $a0, 0xFFF
    /* 53384 800BBB84 03130600 */  sra        $v0, $a2, 12
    /* 53388 800BBB88 2128A200 */  addu       $a1, $a1, $v0
    /* 5338C 800BBB8C 0A0005A6 */  sh         $a1, 0xA($s0)
    /* 53390 800BBB90 002C0500 */  sll        $a1, $a1, 16
    /* 53394 800BBB94 12000296 */  lhu        $v0, 0x12($s0)
    /* 53398 800BBB98 032C0500 */  sra        $a1, $a1, 16
    /* 5339C 800BBB9C 040004A6 */  sh         $a0, 0x4($s0)
    /* 533A0 800BBBA0 12180000 */  mflo       $v1
    /* 533A4 800BBBA4 031B0300 */  sra        $v1, $v1, 12
    /* 533A8 800BBBA8 21104300 */  addu       $v0, $v0, $v1
    /* 533AC 800BBBAC D344020C */  jal        func_8009134C
    /* 533B0 800BBBB0 100002A6 */   sh        $v0, 0x10($s0)
    /* 533B4 800BBBB4 10000486 */  lh         $a0, 0x10($s0)
    /* 533B8 800BBBB8 C844020C */  jal        func_80091320
    /* 533BC 800BBBBC 00000000 */   nop
    /* 533C0 800BBBC0 02000392 */  lbu        $v1, 0x2($s0)
    /* 533C4 800BBBC4 03000292 */  lbu        $v0, 0x3($s0)
    /* 533C8 800BBBC8 00000000 */  nop
    /* 533CC 800BBBCC 02006214 */  bne        $v1, $v0, .L800BBBD8
    /* 533D0 800BBBD0 00000000 */   nop
    /* 533D4 800BBBD4 030000A2 */  sb         $zero, 0x3($s0)
  .L800BBBD8:
    /* 533D8 800BBBD8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 533DC 800BBBDC 1000B08F */  lw         $s0, 0x10($sp)
    /* 533E0 800BBBE0 0800E003 */  jr         $ra
    /* 533E4 800BBBE4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BBAFC
