nonmatching func_800CB7DC, 0x60

glabel func_800CB7DC
    /* 62FDC 800CB7DC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 62FE0 800CB7E0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 62FE4 800CB7E4 0F80103C */  lui        $s0, %hi(D_800EB9B4)
    /* 62FE8 800CB7E8 B4B9028E */  lw         $v0, %lo(D_800EB9B4)($s0)
    /* 62FEC 800CB7EC 00000000 */  nop
    /* 62FF0 800CB7F0 0E004010 */  beqz       $v0, .L800CB82C
    /* 62FF4 800CB7F4 1400BFAF */   sw        $ra, 0x14($sp)
    /* 62FF8 800CB7F8 70F8010C */  jal        func_8007E1C0
    /* 62FFC 800CB7FC 06000424 */   addiu     $a0, $zero, 0x6
    /* 63000 800CB800 B4B9028E */  lw         $v0, %lo(D_800EB9B4)($s0)
    /* 63004 800CB804 00000000 */  nop
    /* 63008 800CB808 01004390 */  lbu        $v1, 0x1($v0)
    /* 6300C 800CB80C 01000224 */  addiu      $v0, $zero, 0x1
    /* 63010 800CB810 04006214 */  bne        $v1, $v0, .L800CB824
    /* 63014 800CB814 1B000424 */   addiu     $a0, $zero, 0x1B
    /* 63018 800CB818 05000524 */  addiu      $a1, $zero, 0x5
    /* 6301C 800CB81C 2AF8010C */  jal        func_8007E0A8
    /* 63020 800CB820 06000624 */   addiu     $a2, $zero, 0x6
  .L800CB824:
    /* 63024 800CB824 5F2A030C */  jal        func_800CA97C
    /* 63028 800CB828 00000000 */   nop
  .L800CB82C:
    /* 6302C 800CB82C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 63030 800CB830 1000B08F */  lw         $s0, 0x10($sp)
    /* 63034 800CB834 0800E003 */  jr         $ra
    /* 63038 800CB838 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800CB7DC
