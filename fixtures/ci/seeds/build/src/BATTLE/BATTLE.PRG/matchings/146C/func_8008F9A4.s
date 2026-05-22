nonmatching func_8008F9A4, 0x70

glabel func_8008F9A4
    /* 271A4 8008F9A4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 271A8 8008F9A8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 271AC 8008F9AC 21908000 */  addu       $s2, $a0, $zero
    /* 271B0 8008F9B0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 271B4 8008F9B4 21800000 */  addu       $s0, $zero, $zero
    /* 271B8 8008F9B8 0F80023C */  lui        $v0, %hi(D_800F1DD4)
    /* 271BC 8008F9BC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 271C0 8008F9C0 D41D518C */  lw         $s1, %lo(D_800F1DD4)($v0)
    /* 271C4 8008F9C4 0F80023C */  lui        $v0, %hi(D_800F1DCA)
    /* 271C8 8008F9C8 CA1D45A0 */  sb         $a1, %lo(D_800F1DCA)($v0)
    /* 271CC 8008F9CC 0F80023C */  lui        $v0, %hi(D_800F1DC2)
    /* 271D0 8008F9D0 C21D52A4 */  sh         $s2, %lo(D_800F1DC2)($v0)
    /* 271D4 8008F9D4 0F80023C */  lui        $v0, %hi(D_800F1DC0)
    /* 271D8 8008F9D8 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 271DC 8008F9DC 0700401A */  blez       $s2, .L8008F9FC
    /* 271E0 8008F9E0 C01D52A4 */   sh        $s2, %lo(D_800F1DC0)($v0)
  .L8008F9E4:
    /* 271E4 8008F9E4 853E020C */  jal        func_8008FA14
    /* 271E8 8008F9E8 21202002 */   addu      $a0, $s1, $zero
    /* 271EC 8008F9EC 01001026 */  addiu      $s0, $s0, 0x1
    /* 271F0 8008F9F0 2A101202 */  slt        $v0, $s0, $s2
    /* 271F4 8008F9F4 FBFF4014 */  bnez       $v0, .L8008F9E4
    /* 271F8 8008F9F8 10003126 */   addiu     $s1, $s1, 0x10
  .L8008F9FC:
    /* 271FC 8008F9FC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 27200 8008FA00 1800B28F */  lw         $s2, 0x18($sp)
    /* 27204 8008FA04 1400B18F */  lw         $s1, 0x14($sp)
    /* 27208 8008FA08 1000B08F */  lw         $s0, 0x10($sp)
    /* 2720C 8008FA0C 0800E003 */  jr         $ra
    /* 27210 8008FA10 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8008F9A4
