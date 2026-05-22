nonmatching func_80045C74, 0x78

glabel func_80045C74
    /* 36474 80045C74 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 36478 80045C78 21108000 */  addu       $v0, $a0, $zero
    /* 3647C 80045C7C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 36480 80045C80 2180A000 */  addu       $s0, $a1, $zero
    /* 36484 80045C84 1800B2AF */  sw         $s2, 0x18($sp)
    /* 36488 80045C88 2190C000 */  addu       $s2, $a2, $zero
    /* 3648C 80045C8C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 36490 80045C90 2188E000 */  addu       $s1, $a3, $zero
    /* 36494 80045C94 0A000012 */  beqz       $s0, .L80045CC0
    /* 36498 80045C98 1C00BFAF */   sw        $ra, 0x1C($sp)
    /* 3649C 80045C9C CA16010C */  jal        func_80045B28
    /* 364A0 80045CA0 00000000 */   nop
    /* 364A4 80045CA4 03004010 */  beqz       $v0, .L80045CB4
    /* 364A8 80045CA8 21204000 */   addu      $a0, $v0, $zero
    /* 364AC 80045CAC 32170108 */  j          .L80045CC8
    /* 364B0 80045CB0 21280000 */   addu      $a1, $zero, $zero
  .L80045CB4:
    /* 364B4 80045CB4 21200002 */  addu       $a0, $s0, $zero
    /* 364B8 80045CB8 32170108 */  j          .L80045CC8
    /* 364BC 80045CBC 21280000 */   addu      $a1, $zero, $zero
  .L80045CC0:
    /* 364C0 80045CC0 21200000 */  addu       $a0, $zero, $zero
    /* 364C4 80045CC4 21284000 */  addu       $a1, $v0, $zero
  .L80045CC8:
    /* 364C8 80045CC8 FF002632 */  andi       $a2, $s1, 0xFF
    /* 364CC 80045CCC 094A000C */  jal        func_80012824
    /* 364D0 80045CD0 21384002 */   addu      $a3, $s2, $zero
    /* 364D4 80045CD4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 364D8 80045CD8 1800B28F */  lw         $s2, 0x18($sp)
    /* 364DC 80045CDC 1400B18F */  lw         $s1, 0x14($sp)
    /* 364E0 80045CE0 1000B08F */  lw         $s0, 0x10($sp)
    /* 364E4 80045CE4 0800E003 */  jr         $ra
    /* 364E8 80045CE8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80045C74
