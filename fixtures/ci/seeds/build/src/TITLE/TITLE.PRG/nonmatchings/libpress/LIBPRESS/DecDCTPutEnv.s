nonmatching DecDCTPutEnv, 0x98

glabel DecDCTPutEnv
    /* 965C 80071E5C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 9660 80071E60 1000B0AF */  sw         $s0, 0x10($sp)
    /* 9664 80071E64 21808000 */  addu       $s0, $a0, $zero
    /* 9668 80071E68 0780053C */  lui        $a1, %hi(D_80075B48)
    /* 966C 80071E6C 485BA524 */  addiu      $a1, $a1, %lo(D_80075B48)
    /* 9670 80071E70 0F000324 */  addiu      $v1, $zero, 0xF
    /* 9674 80071E74 FFFF0624 */  addiu      $a2, $zero, -0x1
    /* 9678 80071E78 1400BFAF */  sw         $ra, 0x14($sp)
  .L80071E7C:
    /* 967C 80071E7C 0000828C */  lw         $v0, 0x0($a0)
    /* 9680 80071E80 04008424 */  addiu      $a0, $a0, 0x4
    /* 9684 80071E84 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 9688 80071E88 0000A2AC */  sw         $v0, 0x0($a1)
    /* 968C 80071E8C FBFF6614 */  bne        $v1, $a2, .L80071E7C
    /* 9690 80071E90 0400A524 */   addiu     $a1, $a1, 0x4
    /* 9694 80071E94 0780053C */  lui        $a1, %hi(D_80075B88)
    /* 9698 80071E98 885BA524 */  addiu      $a1, $a1, %lo(D_80075B88)
    /* 969C 80071E9C 40000426 */  addiu      $a0, $s0, 0x40
    /* 96A0 80071EA0 0F000324 */  addiu      $v1, $zero, 0xF
    /* 96A4 80071EA4 FFFF0624 */  addiu      $a2, $zero, -0x1
  .L80071EA8:
    /* 96A8 80071EA8 0000828C */  lw         $v0, 0x0($a0)
    /* 96AC 80071EAC 04008424 */  addiu      $a0, $a0, 0x4
    /* 96B0 80071EB0 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 96B4 80071EB4 0000A2AC */  sw         $v0, 0x0($a1)
    /* 96B8 80071EB8 FBFF6614 */  bne        $v1, $a2, .L80071EA8
    /* 96BC 80071EBC 0400A524 */   addiu     $a1, $a1, 0x4
    /* 96C0 80071EC0 0780043C */  lui        $a0, %hi(D_80075B44)
    /* 96C4 80071EC4 445B8424 */  addiu      $a0, $a0, %lo(D_80075B44)
    /* 96C8 80071EC8 50C8010C */  jal        func_80072140
    /* 96CC 80071ECC 20000524 */   addiu     $a1, $zero, 0x20
    /* 96D0 80071ED0 0780043C */  lui        $a0, %hi(D_80075BC8)
    /* 96D4 80071ED4 C85B8424 */  addiu      $a0, $a0, %lo(D_80075BC8)
    /* 96D8 80071ED8 50C8010C */  jal        func_80072140
    /* 96DC 80071EDC 20000524 */   addiu     $a1, $zero, 0x20
    /* 96E0 80071EE0 21100002 */  addu       $v0, $s0, $zero
    /* 96E4 80071EE4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 96E8 80071EE8 1000B08F */  lw         $s0, 0x10($sp)
    /* 96EC 80071EEC 0800E003 */  jr         $ra
    /* 96F0 80071EF0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel DecDCTPutEnv
