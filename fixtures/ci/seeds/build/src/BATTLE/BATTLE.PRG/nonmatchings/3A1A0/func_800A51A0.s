nonmatching func_800A51A0, 0xBC

glabel func_800A51A0
    /* 3C9A0 800A51A0 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 3C9A4 800A51A4 3400B1AF */  sw         $s1, 0x34($sp)
    /* 3C9A8 800A51A8 2188A000 */  addu       $s1, $a1, $zero
    /* 3C9AC 800A51AC 3000B0AF */  sw         $s0, 0x30($sp)
    /* 3C9B0 800A51B0 FEFF9024 */  addiu      $s0, $a0, -0x2
    /* 3C9B4 800A51B4 3800BFAF */  sw         $ra, 0x38($sp)
    /* 3C9B8 800A51B8 B034020C */  jal        func_8008D2C0
    /* 3C9BC 800A51BC 1000A427 */   addiu     $a0, $sp, 0x10
    /* 3C9C0 800A51C0 21304000 */  addu       $a2, $v0, $zero
    /* 3C9C4 800A51C4 0A00C018 */  blez       $a2, .L800A51F0
    /* 3C9C8 800A51C8 21200000 */   addu      $a0, $zero, $zero
    /* 3C9CC 800A51CC 1000A527 */  addiu      $a1, $sp, 0x10
  .L800A51D0:
    /* 3C9D0 800A51D0 2118A000 */  addu       $v1, $a1, $zero
    /* 3C9D4 800A51D4 06006284 */  lh         $v0, 0x6($v1)
    /* 3C9D8 800A51D8 00000000 */  nop
    /* 3C9DC 800A51DC 05005010 */  beq        $v0, $s0, .L800A51F4
    /* 3C9E0 800A51E0 01008424 */   addiu     $a0, $a0, 0x1
    /* 3C9E4 800A51E4 2A108600 */  slt        $v0, $a0, $a2
    /* 3C9E8 800A51E8 F9FF4014 */  bnez       $v0, .L800A51D0
    /* 3C9EC 800A51EC 08006524 */   addiu     $a1, $v1, 0x8
  .L800A51F0:
    /* 3C9F0 800A51F0 21180000 */  addu       $v1, $zero, $zero
  .L800A51F4:
    /* 3C9F4 800A51F4 00006484 */  lh         $a0, 0x0($v1)
    /* 3C9F8 800A51F8 00002586 */  lh         $a1, 0x0($s1)
    /* 3C9FC 800A51FC 40008224 */  addiu      $v0, $a0, 0x40
    /* 3CA00 800A5200 2A104500 */  slt        $v0, $v0, $a1
    /* 3CA04 800A5204 0F004014 */  bnez       $v0, .L800A5244
    /* 3CA08 800A5208 21100000 */   addu      $v0, $zero, $zero
    /* 3CA0C 800A520C C0FF8224 */  addiu      $v0, $a0, -0x40
    /* 3CA10 800A5210 2A10A200 */  slt        $v0, $a1, $v0
    /* 3CA14 800A5214 0B004014 */  bnez       $v0, .L800A5244
    /* 3CA18 800A5218 21100000 */   addu      $v0, $zero, $zero
    /* 3CA1C 800A521C 04006384 */  lh         $v1, 0x4($v1)
    /* 3CA20 800A5220 04002586 */  lh         $a1, 0x4($s1)
    /* 3CA24 800A5224 40006224 */  addiu      $v0, $v1, 0x40
    /* 3CA28 800A5228 2A104500 */  slt        $v0, $v0, $a1
    /* 3CA2C 800A522C 04004014 */  bnez       $v0, .L800A5240
    /* 3CA30 800A5230 C0FF6224 */   addiu     $v0, $v1, -0x40
    /* 3CA34 800A5234 2A10A200 */  slt        $v0, $a1, $v0
    /* 3CA38 800A5238 91940208 */  j          .L800A5244
    /* 3CA3C 800A523C 01004238 */   xori      $v0, $v0, 0x1
  .L800A5240:
    /* 3CA40 800A5240 21100000 */  addu       $v0, $zero, $zero
  .L800A5244:
    /* 3CA44 800A5244 3800BF8F */  lw         $ra, 0x38($sp)
    /* 3CA48 800A5248 3400B18F */  lw         $s1, 0x34($sp)
    /* 3CA4C 800A524C 3000B08F */  lw         $s0, 0x30($sp)
    /* 3CA50 800A5250 4000BD27 */  addiu      $sp, $sp, 0x40
    /* 3CA54 800A5254 0800E003 */  jr         $ra
    /* 3CA58 800A5258 00000000 */   nop
endlabel func_800A51A0
