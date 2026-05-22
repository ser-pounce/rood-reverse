nonmatching func_800A4A24, 0x64

glabel func_800A4A24
    /* 3C224 800A4A24 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 3C228 800A4A28 3000B0AF */  sw         $s0, 0x30($sp)
    /* 3C22C 800A4A2C FEFF9024 */  addiu      $s0, $a0, -0x2
    /* 3C230 800A4A30 3400BFAF */  sw         $ra, 0x34($sp)
    /* 3C234 800A4A34 B034020C */  jal        func_8008D2C0
    /* 3C238 800A4A38 1000A427 */   addiu     $a0, $sp, 0x10
    /* 3C23C 800A4A3C 21284000 */  addu       $a1, $v0, $zero
    /* 3C240 800A4A40 0B00A018 */  blez       $a1, .L800A4A70
    /* 3C244 800A4A44 21200000 */   addu      $a0, $zero, $zero
    /* 3C248 800A4A48 1000A327 */  addiu      $v1, $sp, 0x10
  .L800A4A4C:
    /* 3C24C 800A4A4C 06006284 */  lh         $v0, 0x6($v1)
    /* 3C250 800A4A50 00000000 */  nop
    /* 3C254 800A4A54 03005014 */  bne        $v0, $s0, .L800A4A64
    /* 3C258 800A4A58 01008424 */   addiu     $a0, $a0, 0x1
    /* 3C25C 800A4A5C 9D920208 */  j          .L800A4A74
    /* 3C260 800A4A60 21106000 */   addu      $v0, $v1, $zero
  .L800A4A64:
    /* 3C264 800A4A64 2A108500 */  slt        $v0, $a0, $a1
    /* 3C268 800A4A68 F8FF4014 */  bnez       $v0, .L800A4A4C
    /* 3C26C 800A4A6C 08006324 */   addiu     $v1, $v1, 0x8
  .L800A4A70:
    /* 3C270 800A4A70 21100000 */  addu       $v0, $zero, $zero
  .L800A4A74:
    /* 3C274 800A4A74 3400BF8F */  lw         $ra, 0x34($sp)
    /* 3C278 800A4A78 3000B08F */  lw         $s0, 0x30($sp)
    /* 3C27C 800A4A7C 3800BD27 */  addiu      $sp, $sp, 0x38
    /* 3C280 800A4A80 0800E003 */  jr         $ra
    /* 3C284 800A4A84 00000000 */   nop
endlabel func_800A4A24
