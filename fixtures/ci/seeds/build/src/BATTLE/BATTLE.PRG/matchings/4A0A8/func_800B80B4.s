nonmatching func_800B80B4, 0x58

glabel func_800B80B4
    /* 4F8B4 800B80B4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 4F8B8 800B80B8 01008424 */  addiu      $a0, $a0, 0x1
    /* 4F8BC 800B80BC 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 4F8C0 800B80C0 80FF020C */  jal        vs_battle_getShort
    /* 4F8C4 800B80C4 2800B0AF */   sw        $s0, 0x28($sp)
    /* 4F8C8 800B80C8 FFFF4430 */  andi       $a0, $v0, 0xFFFF
    /* 4F8CC 800B80CC A3ED020C */  jal        func_800BB68C
    /* 4F8D0 800B80D0 1000A527 */   addiu     $a1, $sp, 0x10
    /* 4F8D4 800B80D4 01001024 */  addiu      $s0, $zero, 0x1
  .L800B80D8:
    /* 4F8D8 800B80D8 E2ED020C */  jal        func_800BB788
    /* 4F8DC 800B80DC 1000A427 */   addiu     $a0, $sp, 0x10
    /* 4F8E0 800B80E0 FFFF4430 */  andi       $a0, $v0, 0xFFFF
    /* 4F8E4 800B80E4 05009010 */  beq        $a0, $s0, .L800B80FC
    /* 4F8E8 800B80E8 21100000 */   addu      $v0, $zero, $zero
    /* 4F8EC 800B80EC D0F4010C */  jal        func_8007D340
    /* 4F8F0 800B80F0 00000000 */   nop
    /* 4F8F4 800B80F4 36E00208 */  j          .L800B80D8
    /* 4F8F8 800B80F8 00000000 */   nop
  .L800B80FC:
    /* 4F8FC 800B80FC 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 4F900 800B8100 2800B08F */  lw         $s0, 0x28($sp)
    /* 4F904 800B8104 0800E003 */  jr         $ra
    /* 4F908 800B8108 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800B80B4
