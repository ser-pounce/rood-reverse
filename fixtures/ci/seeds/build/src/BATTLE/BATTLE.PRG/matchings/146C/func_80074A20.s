nonmatching func_80074A20, 0xF4

glabel func_80074A20
    /* C220 80074A20 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* C224 80074A24 1400B1AF */  sw         $s1, 0x14($sp)
    /* C228 80074A28 21888000 */  addu       $s1, $a0, $zero
    /* C22C 80074A2C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* C230 80074A30 1800B2AF */  sw         $s2, 0x18($sp)
    /* C234 80074A34 C099030C */  jal        func_800E6700
    /* C238 80074A38 1000B0AF */   sw        $s0, 0x10($sp)
    /* C23C 80074A3C 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* C240 80074A40 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* C244 80074A44 80181100 */  sll        $v1, $s1, 2
    /* C248 80074A48 21806200 */  addu       $s0, $v1, $v0
    /* C24C 80074A4C 0000028E */  lw         $v0, 0x0($s0)
    /* C250 80074A50 00000000 */  nop
    /* C254 80074A54 28004010 */  beqz       $v0, .L80074AF8
    /* C258 80074A58 21900000 */   addu      $s2, $zero, $zero
    /* C25C 80074A5C 080040A0 */  sb         $zero, 0x8($v0)
    /* C260 80074A60 0000028E */  lw         $v0, 0x0($s0)
    /* C264 80074A64 00000000 */  nop
    /* C268 80074A68 3C00428C */  lw         $v0, 0x3C($v0)
    /* C26C 80074A6C 00000000 */  nop
    /* C270 80074A70 18004284 */  lh         $v0, 0x18($v0)
    /* C274 80074A74 00000000 */  nop
    /* C278 80074A78 20004014 */  bnez       $v0, .L80074AFC
    /* C27C 80074A7C 21104002 */   addu      $v0, $s2, $zero
    /* C280 80074A80 21202002 */  addu       $a0, $s1, $zero
    /* C284 80074A84 DF56020C */  jal        func_80095B7C
    /* C288 80074A88 21284002 */   addu      $a1, $s2, $zero
    /* C28C 80074A8C 0000038E */  lw         $v1, 0x0($s0)
    /* C290 80074A90 20000224 */  addiu      $v0, $zero, 0x20
    /* C294 80074A94 080062A0 */  sb         $v0, 0x8($v1)
    /* C298 80074A98 0000028E */  lw         $v0, 0x0($s0)
    /* C29C 80074A9C 00000000 */  nop
    /* C2A0 80074AA0 26004290 */  lbu        $v0, 0x26($v0)
    /* C2A4 80074AA4 00000000 */  nop
    /* C2A8 80074AA8 14004014 */  bnez       $v0, .L80074AFC
    /* C2AC 80074AAC 21104002 */   addu      $v0, $s2, $zero
    /* C2B0 80074AB0 0F80023C */  lui        $v0, %hi(D_800F19CC)
    /* C2B4 80074AB4 21202002 */  addu       $a0, $s1, $zero
    /* C2B8 80074AB8 CC19458C */  lw         $a1, %lo(D_800F19CC)($v0)
    /* C2BC 80074ABC 01000624 */  addiu      $a2, $zero, 0x1
    /* C2C0 80074AC0 C57C020C */  jal        func_8009F314
    /* C2C4 80074AC4 A829A524 */   addiu     $a1, $a1, 0x29A8
    /* C2C8 80074AC8 21202002 */  addu       $a0, $s1, $zero
    /* C2CC 80074ACC 7682020C */  jal        func_800A09D8
    /* C2D0 80074AD0 01000524 */   addiu     $a1, $zero, 0x1
    /* C2D4 80074AD4 0000028E */  lw         $v0, 0x0($s0)
    /* C2D8 80074AD8 00000000 */  nop
    /* C2DC 80074ADC 27004390 */  lbu        $v1, 0x27($v0)
    /* C2E0 80074AE0 80000224 */  addiu      $v0, $zero, 0x80
    /* C2E4 80074AE4 03006214 */  bne        $v1, $v0, .L80074AF4
    /* C2E8 80074AE8 00000000 */   nop
    /* C2EC 80074AEC 03002016 */  bnez       $s1, .L80074AFC
    /* C2F0 80074AF0 21104002 */   addu      $v0, $s2, $zero
  .L80074AF4:
    /* C2F4 80074AF4 01001224 */  addiu      $s2, $zero, 0x1
  .L80074AF8:
    /* C2F8 80074AF8 21104002 */  addu       $v0, $s2, $zero
  .L80074AFC:
    /* C2FC 80074AFC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* C300 80074B00 1800B28F */  lw         $s2, 0x18($sp)
    /* C304 80074B04 1400B18F */  lw         $s1, 0x14($sp)
    /* C308 80074B08 1000B08F */  lw         $s0, 0x10($sp)
    /* C30C 80074B0C 0800E003 */  jr         $ra
    /* C310 80074B10 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80074A20
