nonmatching func_800774FC, 0xC4

glabel func_800774FC
    /* ECFC 800774FC C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* ED00 80077500 2800B2AF */  sw         $s2, 0x28($sp)
    /* ED04 80077504 21908000 */  addu       $s2, $a0, $zero
    /* ED08 80077508 3000B4AF */  sw         $s4, 0x30($sp)
    /* ED0C 8007750C 21A0A000 */  addu       $s4, $a1, $zero
    /* ED10 80077510 3400B5AF */  sw         $s5, 0x34($sp)
    /* ED14 80077514 21A8C000 */  addu       $s5, $a2, $zero
    /* ED18 80077518 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* ED1C 8007751C 5000B38F */  lw         $s3, 0x50($sp)
    /* ED20 80077520 5400A28F */  lw         $v0, 0x54($sp)
    /* ED24 80077524 5800A38F */  lw         $v1, 0x58($sp)
    /* ED28 80077528 2400B1AF */  sw         $s1, 0x24($sp)
    /* ED2C 8007752C 5C00B18F */  lw         $s1, 0x5C($sp)
    /* ED30 80077530 3800BFAF */  sw         $ra, 0x38($sp)
    /* ED34 80077534 2000B0AF */  sw         $s0, 0x20($sp)
    /* ED38 80077538 1000B3AF */  sw         $s3, 0x10($sp)
    /* ED3C 8007753C 1400A2AF */  sw         $v0, 0x14($sp)
    /* ED40 80077540 1800A3AF */  sw         $v1, 0x18($sp)
    /* ED44 80077544 90DC010C */  jal        func_80077240
    /* ED48 80077548 1C00B1AF */   sw        $s1, 0x1C($sp)
    /* ED4C 8007754C 21804000 */  addu       $s0, $v0, $zero
    /* ED50 80077550 12000012 */  beqz       $s0, .L8007759C
    /* ED54 80077554 21100000 */   addu      $v0, $zero, $zero
  .L80077558:
    /* ED58 80077558 6C65020C */  jal        vs_battle_getEmptyObjectDataSlot
    /* ED5C 8007755C 00000000 */   nop
    /* ED60 80077560 07004010 */  beqz       $v0, .L80077580
    /* ED64 80077564 21200002 */   addu      $a0, $s0, $zero
    /* ED68 80077568 9F65020C */  jal        vs_battle_processObjectDataQueue
    /* ED6C 8007756C 00000000 */   nop
    /* ED70 80077570 8709010C */  jal        vs_main_gametimeUpdate
    /* ED74 80077574 21200000 */   addu      $a0, $zero, $zero
    /* ED78 80077578 56DD0108 */  j          .L80077558
    /* ED7C 8007757C 00000000 */   nop
  .L80077580:
    /* ED80 80077580 21284002 */  addu       $a1, $s2, $zero
    /* ED84 80077584 21308002 */  addu       $a2, $s4, $zero
    /* ED88 80077588 2138A002 */  addu       $a3, $s5, $zero
    /* ED8C 8007758C 1000B3AF */  sw         $s3, 0x10($sp)
    /* ED90 80077590 EFDC010C */  jal        func_800773BC
    /* ED94 80077594 1400B1AF */   sw        $s1, 0x14($sp)
    /* ED98 80077598 21100002 */  addu       $v0, $s0, $zero
  .L8007759C:
    /* ED9C 8007759C 3800BF8F */  lw         $ra, 0x38($sp)
    /* EDA0 800775A0 3400B58F */  lw         $s5, 0x34($sp)
    /* EDA4 800775A4 3000B48F */  lw         $s4, 0x30($sp)
    /* EDA8 800775A8 2C00B38F */  lw         $s3, 0x2C($sp)
    /* EDAC 800775AC 2800B28F */  lw         $s2, 0x28($sp)
    /* EDB0 800775B0 2400B18F */  lw         $s1, 0x24($sp)
    /* EDB4 800775B4 2000B08F */  lw         $s0, 0x20($sp)
    /* EDB8 800775B8 0800E003 */  jr         $ra
    /* EDBC 800775BC 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_800774FC
