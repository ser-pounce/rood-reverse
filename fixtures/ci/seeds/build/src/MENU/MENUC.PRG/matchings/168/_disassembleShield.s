nonmatching _disassembleShield, 0x70

glabel _disassembleShield
    /* ACC 801032CC 40100400 */  sll        $v0, $a0, 1
    /* AD0 801032D0 21104400 */  addu       $v0, $v0, $a0
    /* AD4 801032D4 00110200 */  sll        $v0, $v0, 4
    /* AD8 801032D8 0680033C */  lui        $v1, %hi(D_80060268)
    /* ADC 801032DC 68026324 */  addiu      $v1, $v1, %lo(D_80060268)
    /* AE0 801032E0 21384300 */  addu       $a3, $v0, $v1
    /* AE4 801032E4 1000E690 */  lbu        $a2, 0x10($a3)
    /* AE8 801032E8 00000000 */  nop
    /* AEC 801032EC 1100C010 */  beqz       $a2, .L80103334
    /* AF0 801032F0 21200000 */   addu      $a0, $zero, $zero
    /* AF4 801032F4 00FF6824 */  addiu      $t0, $v1, -0x100
    /* AF8 801032F8 2128E400 */  addu       $a1, $a3, $a0
  .L801032FC:
    /* AFC 801032FC 2C00A390 */  lbu        $v1, 0x2C($a1)
    /* B00 80103300 00000000 */  nop
    /* B04 80103304 07006010 */  beqz       $v1, .L80103324
    /* B08 80103308 FFFF6324 */   addiu     $v1, $v1, -0x1
    /* B0C 8010330C C0100300 */  sll        $v0, $v1, 3
    /* B10 80103310 23104300 */  subu       $v0, $v0, $v1
    /* B14 80103314 80100200 */  sll        $v0, $v0, 2
    /* B18 80103318 21104800 */  addu       $v0, $v0, $t0
    /* B1C 8010331C D80840A4 */  sh         $zero, 0x8D8($v0)
    /* B20 80103320 2C00A0A0 */  sb         $zero, 0x2C($a1)
  .L80103324:
    /* B24 80103324 01008424 */  addiu      $a0, $a0, 0x1
    /* B28 80103328 2A108600 */  slt        $v0, $a0, $a2
    /* B2C 8010332C F3FF4014 */  bnez       $v0, .L801032FC
    /* B30 80103330 2128E400 */   addu      $a1, $a3, $a0
  .L80103334:
    /* B34 80103334 0800E003 */  jr         $ra
    /* B38 80103338 00000000 */   nop
endlabel _disassembleShield
