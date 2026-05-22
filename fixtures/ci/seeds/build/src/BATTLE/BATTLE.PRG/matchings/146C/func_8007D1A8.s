nonmatching func_8007D1A8, 0xB8

glabel func_8007D1A8
    /* 149A8 8007D1A8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 149AC 8007D1AC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 149B0 8007D1B0 21888000 */  addu       $s1, $a0, $zero
    /* 149B4 8007D1B4 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 149B8 8007D1B8 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 149BC 8007D1BC 80101100 */  sll        $v0, $s1, 2
    /* 149C0 8007D1C0 21104300 */  addu       $v0, $v0, $v1
    /* 149C4 8007D1C4 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 149C8 8007D1C8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 149CC 8007D1CC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 149D0 8007D1D0 0000448C */  lw         $a0, 0x0($v0)
    /* 149D4 8007D1D4 00000000 */  nop
    /* 149D8 8007D1D8 1B008010 */  beqz       $a0, .L8007D248
    /* 149DC 8007D1DC 2190A000 */   addu      $s2, $a1, $zero
    /* 149E0 8007D1E0 0D004012 */  beqz       $s2, .L8007D218
    /* 149E4 8007D1E4 00000000 */   nop
    /* 149E8 8007D1E8 71A8010C */  jal        _removeActor
    /* 149EC 8007D1EC 00000000 */   nop
    /* 149F0 8007D1F0 21804000 */  addu       $s0, $v0, $zero
    /* 149F4 8007D1F4 21202002 */  addu       $a0, $s1, $zero
    /* 149F8 8007D1F8 7682020C */  jal        func_800A09D8
    /* 149FC 8007D1FC 21284002 */   addu      $a1, $s2, $zero
    /* 14A00 8007D200 11000012 */  beqz       $s0, .L8007D248
    /* 14A04 8007D204 00000000 */   nop
    /* 14A08 8007D208 829D030C */  jal        func_800E7608
    /* 14A0C 8007D20C 21202002 */   addu      $a0, $s1, $zero
    /* 14A10 8007D210 90F40108 */  j          .L8007D240
    /* 14A14 8007D214 00000000 */   nop
  .L8007D218:
    /* 14A18 8007D218 47A8010C */  jal        _insertActor
    /* 14A1C 8007D21C 00000000 */   nop
    /* 14A20 8007D220 21804000 */  addu       $s0, $v0, $zero
    /* 14A24 8007D224 21202002 */  addu       $a0, $s1, $zero
    /* 14A28 8007D228 7682020C */  jal        func_800A09D8
    /* 14A2C 8007D22C 21280000 */   addu      $a1, $zero, $zero
    /* 14A30 8007D230 05000012 */  beqz       $s0, .L8007D248
    /* 14A34 8007D234 00000000 */   nop
    /* 14A38 8007D238 6696030C */  jal        func_800E5998
    /* 14A3C 8007D23C 00000000 */   nop
  .L8007D240:
    /* 14A40 8007D240 227B030C */  jal        func_800DEC88
    /* 14A44 8007D244 21200000 */   addu      $a0, $zero, $zero
  .L8007D248:
    /* 14A48 8007D248 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 14A4C 8007D24C 1800B28F */  lw         $s2, 0x18($sp)
    /* 14A50 8007D250 1400B18F */  lw         $s1, 0x14($sp)
    /* 14A54 8007D254 1000B08F */  lw         $s0, 0x10($sp)
    /* 14A58 8007D258 0800E003 */  jr         $ra
    /* 14A5C 8007D25C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007D1A8
