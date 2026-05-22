nonmatching func_8008F29C, 0x70

glabel func_8008F29C
    /* 26A9C 8008F29C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 26AA0 8008F2A0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 26AA4 8008F2A4 21908000 */  addu       $s2, $a0, $zero
    /* 26AA8 8008F2A8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 26AAC 8008F2AC 21800000 */  addu       $s0, $zero, $zero
    /* 26AB0 8008F2B0 0F80023C */  lui        $v0, %hi(D_800F1DD4)
    /* 26AB4 8008F2B4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 26AB8 8008F2B8 D41D518C */  lw         $s1, %lo(D_800F1DD4)($v0)
    /* 26ABC 8008F2BC 0F80023C */  lui        $v0, %hi(D_800F1DCA)
    /* 26AC0 8008F2C0 CA1D45A0 */  sb         $a1, %lo(D_800F1DCA)($v0)
    /* 26AC4 8008F2C4 0F80023C */  lui        $v0, %hi(D_800F1DC2)
    /* 26AC8 8008F2C8 C21D52A4 */  sh         $s2, %lo(D_800F1DC2)($v0)
    /* 26ACC 8008F2CC 0F80023C */  lui        $v0, %hi(D_800F1DC0)
    /* 26AD0 8008F2D0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 26AD4 8008F2D4 0700401A */  blez       $s2, .L8008F2F4
    /* 26AD8 8008F2D8 C01D52A4 */   sh        $s2, %lo(D_800F1DC0)($v0)
  .L8008F2DC:
    /* 26ADC 8008F2DC 8742020C */  jal        func_80090A1C
    /* 26AE0 8008F2E0 21202002 */   addu      $a0, $s1, $zero
    /* 26AE4 8008F2E4 01001026 */  addiu      $s0, $s0, 0x1
    /* 26AE8 8008F2E8 2A101202 */  slt        $v0, $s0, $s2
    /* 26AEC 8008F2EC FBFF4014 */  bnez       $v0, .L8008F2DC
    /* 26AF0 8008F2F0 10003126 */   addiu     $s1, $s1, 0x10
  .L8008F2F4:
    /* 26AF4 8008F2F4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 26AF8 8008F2F8 1800B28F */  lw         $s2, 0x18($sp)
    /* 26AFC 8008F2FC 1400B18F */  lw         $s1, 0x14($sp)
    /* 26B00 8008F300 1000B08F */  lw         $s0, 0x10($sp)
    /* 26B04 8008F304 0800E003 */  jr         $ra
    /* 26B08 8008F308 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8008F29C
