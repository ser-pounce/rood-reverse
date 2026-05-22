nonmatching func_800D18B4, 0x50

glabel func_800D18B4
    /* 690B4 800D18B4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 690B8 800D18B8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 690BC 800D18BC 21808000 */  addu       $s0, $a0, $zero
    /* 690C0 800D18C0 C0220700 */  sll        $a0, $a3, 11
    /* 690C4 800D18C4 1A008600 */  div        $zero, $a0, $a2
    /* 690C8 800D18C8 12200000 */  mflo       $a0
    /* 690CC 800D18CC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 690D0 800D18D0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 690D4 800D18D4 C903010C */  jal        rcos
    /* 690D8 800D18D8 2188A000 */   addu      $s1, $a1, $zero
    /* 690DC 800D18DC 21200002 */  addu       $a0, $s0, $zero
    /* 690E0 800D18E0 00100624 */  addiu      $a2, $zero, 0x1000
    /* 690E4 800D18E4 21282002 */  addu       $a1, $s1, $zero
    /* 690E8 800D18E8 9E45030C */  jal        vs_battle_lerp
    /* 690EC 800D18EC 2330C200 */   subu      $a2, $a2, $v0
    /* 690F0 800D18F0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 690F4 800D18F4 1400B18F */  lw         $s1, 0x14($sp)
    /* 690F8 800D18F8 1000B08F */  lw         $s0, 0x10($sp)
    /* 690FC 800D18FC 0800E003 */  jr         $ra
    /* 69100 800D1900 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800D18B4
