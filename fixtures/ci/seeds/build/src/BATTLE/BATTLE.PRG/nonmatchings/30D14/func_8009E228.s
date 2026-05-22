nonmatching func_8009E228, 0xB8

glabel func_8009E228
    /* 35A28 8009E228 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 35A2C 8009E22C 2000B2AF */  sw         $s2, 0x20($sp)
    /* 35A30 8009E230 21908000 */  addu       $s2, $a0, $zero
    /* 35A34 8009E234 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 35A38 8009E238 2188A000 */  addu       $s1, $a1, $zero
    /* 35A3C 8009E23C 2400BFAF */  sw         $ra, 0x24($sp)
    /* 35A40 8009E240 03002016 */  bnez       $s1, .L8009E250
    /* 35A44 8009E244 1800B0AF */   sw        $s0, 0x18($sp)
    /* 35A48 8009E248 B1780208 */  j          .L8009E2C4
    /* 35A4C 8009E24C 21100000 */   addu      $v0, $zero, $zero
  .L8009E250:
    /* 35A50 8009E250 00002386 */  lh         $v1, 0x0($s1)
    /* 35A54 8009E254 1C004286 */  lh         $v0, 0x1C($s2)
    /* 35A58 8009E258 00000000 */  nop
    /* 35A5C 8009E25C 23806200 */  subu       $s0, $v1, $v0
    /* 35A60 8009E260 18001002 */  mult       $s0, $s0
    /* 35A64 8009E264 04002386 */  lh         $v1, 0x4($s1)
    /* 35A68 8009E268 20004286 */  lh         $v0, 0x20($s2)
    /* 35A6C 8009E26C 12800000 */  mflo       $s0
    /* 35A70 8009E270 02000106 */  bgez       $s0, .L8009E27C
    /* 35A74 8009E274 23186200 */   subu      $v1, $v1, $v0
    /* 35A78 8009E278 23801000 */  negu       $s0, $s0
  .L8009E27C:
    /* 35A7C 8009E27C 18006300 */  mult       $v1, $v1
    /* 35A80 8009E280 12180000 */  mflo       $v1
    /* 35A84 8009E284 02006104 */  bgez       $v1, .L8009E290
    /* 35A88 8009E288 00000000 */   nop
    /* 35A8C 8009E28C 23180300 */  negu       $v1, $v1
  .L8009E290:
    /* 35A90 8009E290 E506010C */  jal        vs_gte_rsqrt
    /* 35A94 8009E294 21200302 */   addu      $a0, $s0, $v1
    /* 35A98 8009E298 21804000 */  addu       $s0, $v0, $zero
    /* 35A9C 8009E29C 21280000 */  addu       $a1, $zero, $zero
    /* 35AA0 8009E2A0 1000A627 */  addiu      $a2, $sp, 0x10
    /* 35AA4 8009E2A4 0F004492 */  lbu        $a0, 0xF($s2)
    /* 35AA8 8009E2A8 BE86020C */  jal        func_800A1AF8
    /* 35AAC 8009E2AC 2138A000 */   addu      $a3, $a1, $zero
    /* 35AB0 8009E2B0 02002286 */  lh         $v0, 0x2($s1)
    /* 35AB4 8009E2B4 1200A487 */  lh         $a0, 0x12($sp)
    /* 35AB8 8009E2B8 21280002 */  addu       $a1, $s0, $zero
    /* 35ABC 8009E2BC DF04010C */  jal        ratan2
    /* 35AC0 8009E2C0 23204400 */   subu      $a0, $v0, $a0
  .L8009E2C4:
    /* 35AC4 8009E2C4 2400BF8F */  lw         $ra, 0x24($sp)
    /* 35AC8 8009E2C8 2000B28F */  lw         $s2, 0x20($sp)
    /* 35ACC 8009E2CC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 35AD0 8009E2D0 1800B08F */  lw         $s0, 0x18($sp)
    /* 35AD4 8009E2D4 2800BD27 */  addiu      $sp, $sp, 0x28
    /* 35AD8 8009E2D8 0800E003 */  jr         $ra
    /* 35ADC 8009E2DC 00000000 */   nop
endlabel func_8009E228
