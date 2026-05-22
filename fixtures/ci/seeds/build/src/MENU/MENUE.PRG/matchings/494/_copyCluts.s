nonmatching _copyCluts, 0x94

glabel _copyCluts
    /* 12D8 80103AD8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 12DC 80103ADC 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 12E0 80103AE0 21888000 */  addu       $s1, $a0, $zero
    /* 12E4 80103AE4 2000B2AF */  sw         $s2, 0x20($sp)
    /* 12E8 80103AE8 2190A000 */  addu       $s2, $a1, $zero
    /* 12EC 80103AEC 1800B0AF */  sw         $s0, 0x18($sp)
    /* 12F0 80103AF0 21800000 */  addu       $s0, $zero, $zero
    /* 12F4 80103AF4 10000224 */  addiu      $v0, $zero, 0x10
    /* 12F8 80103AF8 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 12FC 80103AFC 01000224 */  addiu      $v0, $zero, 0x1
    /* 1300 80103B00 2400BFAF */  sw         $ra, 0x24($sp)
    /* 1304 80103B04 1300401A */  blez       $s2, .L80103B54
    /* 1308 80103B08 1600A2A7 */   sh        $v0, 0x16($sp)
  .L80103B0C:
    /* 130C 80103B0C 02000106 */  bgez       $s0, .L80103B18
    /* 1310 80103B10 21100002 */   addu      $v0, $s0, $zero
    /* 1314 80103B14 0F000226 */  addiu      $v0, $s0, 0xF
  .L80103B18:
    /* 1318 80103B18 03110200 */  sra        $v0, $v0, 4
    /* 131C 80103B1C 00190200 */  sll        $v1, $v0, 4
    /* 1320 80103B20 23180302 */  subu       $v1, $s0, $v1
    /* 1324 80103B24 00190300 */  sll        $v1, $v1, 4
    /* 1328 80103B28 00036324 */  addiu      $v1, $v1, 0x300
    /* 132C 80103B2C F0014224 */  addiu      $v0, $v0, 0x1F0
    /* 1330 80103B30 1000A427 */  addiu      $a0, $sp, 0x10
    /* 1334 80103B34 21282002 */  addu       $a1, $s1, $zero
    /* 1338 80103B38 1000A3A7 */  sh         $v1, 0x10($sp)
    /* 133C 80103B3C 67AB000C */  jal        LoadImage2
    /* 1340 80103B40 1200A2A7 */   sh        $v0, 0x12($sp)
    /* 1344 80103B44 01001026 */  addiu      $s0, $s0, 0x1
    /* 1348 80103B48 2A101202 */  slt        $v0, $s0, $s2
    /* 134C 80103B4C EFFF4014 */  bnez       $v0, .L80103B0C
    /* 1350 80103B50 20003126 */   addiu     $s1, $s1, 0x20
  .L80103B54:
    /* 1354 80103B54 2400BF8F */  lw         $ra, 0x24($sp)
    /* 1358 80103B58 2000B28F */  lw         $s2, 0x20($sp)
    /* 135C 80103B5C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1360 80103B60 1800B08F */  lw         $s0, 0x18($sp)
    /* 1364 80103B64 0800E003 */  jr         $ra
    /* 1368 80103B68 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _copyCluts
