nonmatching func_80091378, 0x44

glabel func_80091378
    /* 28B78 80091378 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 28B7C 8009137C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 28B80 80091380 0F80103C */  lui        $s0, %hi(D_800F1DD4)
    /* 28B84 80091384 D41D048E */  lw         $a0, %lo(D_800F1DD4)($s0)
    /* 28B88 80091388 0F80023C */  lui        $v0, %hi(D_800F1DC0)
    /* 28B8C 8009138C C01D40A4 */  sh         $zero, %lo(D_800F1DC0)($v0)
    /* 28B90 80091390 0F80023C */  lui        $v0, %hi(D_800F1DC2)
    /* 28B94 80091394 1400BFAF */  sw         $ra, 0x14($sp)
    /* 28B98 80091398 03008010 */  beqz       $a0, .L800913A8
    /* 28B9C 8009139C C21D40A4 */   sh        $zero, %lo(D_800F1DC2)($v0)
    /* 28BA0 800913A0 540F010C */  jal        vs_main_freeHeap
    /* 28BA4 800913A4 00000000 */   nop
  .L800913A8:
    /* 28BA8 800913A8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 28BAC 800913AC D41D00AE */  sw         $zero, %lo(D_800F1DD4)($s0)
    /* 28BB0 800913B0 1000B08F */  lw         $s0, 0x10($sp)
    /* 28BB4 800913B4 0800E003 */  jr         $ra
    /* 28BB8 800913B8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80091378
