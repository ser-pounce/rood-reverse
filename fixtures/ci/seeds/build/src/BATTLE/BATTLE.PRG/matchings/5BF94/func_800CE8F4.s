nonmatching func_800CE8F4, 0xBC

glabel func_800CE8F4
    /* 660F4 800CE8F4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 660F8 800CE8F8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 660FC 800CE8FC 21908000 */  addu       $s2, $a0, $zero
    /* 66100 800CE900 0F80043C */  lui        $a0, %hi(D_800F53B8)
    /* 66104 800CE904 B853838C */  lw         $v1, %lo(D_800F53B8)($a0)
    /* 66108 800CE908 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 6610C 800CE90C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 66110 800CE910 0A007214 */  bne        $v1, $s2, .L800CE93C
    /* 66114 800CE914 1000B0AF */   sw        $s0, 0x10($sp)
    /* 66118 800CE918 0000428E */  lw         $v0, 0x0($s2)
    /* 6611C 800CE91C 533A0308 */  j          .L800CE94C
    /* 66120 800CE920 B85382AC */   sw        $v0, %lo(D_800F53B8)($a0)
  .L800CE924:
    /* 66124 800CE924 0000428E */  lw         $v0, 0x0($s2)
    /* 66128 800CE928 533A0308 */  j          .L800CE94C
    /* 6612C 800CE92C 000062AC */   sw        $v0, 0x0($v1)
  .L800CE930:
    /* 66130 800CE930 FCFF5210 */  beq        $v0, $s2, .L800CE924
    /* 66134 800CE934 00000000 */   nop
    /* 66138 800CE938 21184000 */  addu       $v1, $v0, $zero
  .L800CE93C:
    /* 6613C 800CE93C 0000628C */  lw         $v0, 0x0($v1)
    /* 66140 800CE940 00000000 */  nop
    /* 66144 800CE944 FAFF4014 */  bnez       $v0, .L800CE930
    /* 66148 800CE948 00000000 */   nop
  .L800CE94C:
    /* 6614C 800CE94C 414A030C */  jal        func_800D2904
    /* 66150 800CE950 21204002 */   addu      $a0, $s2, $zero
    /* 66154 800CE954 500D518E */  lw         $s1, 0xD50($s2)
    /* 66158 800CE958 00000000 */  nop
    /* 6615C 800CE95C 0C002012 */  beqz       $s1, .L800CE990
    /* 66160 800CE960 21202002 */   addu      $a0, $s1, $zero
  .L800CE964:
    /* 66164 800CE964 04000524 */  addiu      $a1, $zero, 0x4
    /* 66168 800CE968 0400228E */  lw         $v0, 0x4($s1)
    /* 6616C 800CE96C 0000308E */  lw         $s0, 0x0($s1)
    /* 66170 800CE970 09F84000 */  jalr       $v0
    /* 66174 800CE974 21300000 */   addu      $a2, $zero, $zero
    /* 66178 800CE978 21204002 */  addu       $a0, $s2, $zero
    /* 6617C 800CE97C C33D030C */  jal        func_800CF70C
    /* 66180 800CE980 21282002 */   addu      $a1, $s1, $zero
    /* 66184 800CE984 21880002 */  addu       $s1, $s0, $zero
    /* 66188 800CE988 F6FF2016 */  bnez       $s1, .L800CE964
    /* 6618C 800CE98C 21202002 */   addu      $a0, $s1, $zero
  .L800CE990:
    /* 66190 800CE990 180F010C */  jal        vs_main_freeHeapR
    /* 66194 800CE994 21204002 */   addu      $a0, $s2, $zero
    /* 66198 800CE998 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6619C 800CE99C 1800B28F */  lw         $s2, 0x18($sp)
    /* 661A0 800CE9A0 1400B18F */  lw         $s1, 0x14($sp)
    /* 661A4 800CE9A4 1000B08F */  lw         $s0, 0x10($sp)
    /* 661A8 800CE9A8 0800E003 */  jr         $ra
    /* 661AC 800CE9AC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800CE8F4
