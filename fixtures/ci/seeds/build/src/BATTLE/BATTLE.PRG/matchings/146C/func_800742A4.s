nonmatching func_800742A4, 0x70

glabel func_800742A4
    /* BAA4 800742A4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* BAA8 800742A8 0F80023C */  lui        $v0, %hi(D_800F1910)
    /* BAAC 800742AC 0F80043C */  lui        $a0, %hi(_cameraMode)
    /* BAB0 800742B0 04000324 */  addiu      $v1, $zero, 0x4
    /* BAB4 800742B4 F01883AC */  sw         $v1, %lo(_cameraMode)($a0)
    /* BAB8 800742B8 0680043C */  lui        $a0, %hi(vs_gametime_tickspeed)
    /* BABC 800742BC 1019458C */  lw         $a1, %lo(D_800F1910)($v0)
    /* BAC0 800742C0 02000324 */  addiu      $v1, $zero, 0x2
    /* BAC4 800742C4 4CE283AC */  sw         $v1, %lo(vs_gametime_tickspeed)($a0)
    /* BAC8 800742C8 21200000 */  addu       $a0, $zero, $zero
    /* BACC 800742CC 1800BFAF */  sw         $ra, 0x18($sp)
    /* BAD0 800742D0 0000A284 */  lh         $v0, 0x0($a1)
    /* BAD4 800742D4 04000624 */  addiu      $a2, $zero, 0x4
    /* BAD8 800742D8 C0110200 */  sll        $v0, $v0, 7
    /* BADC 800742DC 40004224 */  addiu      $v0, $v0, 0x40
    /* BAE0 800742E0 1000A2A7 */  sh         $v0, 0x10($sp)
    /* BAE4 800742E4 0200A284 */  lh         $v0, 0x2($a1)
    /* BAE8 800742E8 1000A527 */  addiu      $a1, $sp, 0x10
    /* BAEC 800742EC C0110200 */  sll        $v0, $v0, 7
    /* BAF0 800742F0 40004224 */  addiu      $v0, $v0, 0x40
    /* BAF4 800742F4 1C78020C */  jal        func_8009E070
    /* BAF8 800742F8 1400A2A7 */   sh        $v0, 0x14($sp)
    /* BAFC 800742FC 432D030C */  jal        func_800CB50C
    /* BB00 80074300 00000000 */   nop
    /* BB04 80074304 1800BF8F */  lw         $ra, 0x18($sp)
    /* BB08 80074308 00000000 */  nop
    /* BB0C 8007430C 0800E003 */  jr         $ra
    /* BB10 80074310 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800742A4
