nonmatching func_800FA238, 0x94

glabel func_800FA238
    /* A38 800FA238 8000CA24 */  addiu      $t2, $a2, 0x80
    /* A3C 800FA23C 21480000 */  addu       $t1, $zero, $zero
    /* A40 800FA240 0F80023C */  lui        $v0, %hi(D_800F45E0)
    /* A44 800FA244 E0454824 */  addiu      $t0, $v0, %lo(D_800F45E0)
  .L800FA248:
    /* A48 800FA248 0000038D */  lw         $v1, 0x0($t0)
    /* A4C 800FA24C 00000000 */  nop
    /* A50 800FA250 17006010 */  beqz       $v1, .L800FA2B0
    /* A54 800FA254 00000000 */   nop
    /* A58 800FA258 0800678C */  lw         $a3, 0x8($v1)
    /* A5C 800FA25C 00000000 */  nop
    /* A60 800FA260 0100E230 */  andi       $v0, $a3, 0x1
    /* A64 800FA264 12004014 */  bnez       $v0, .L800FA2B0
    /* A68 800FA268 000FE230 */   andi      $v0, $a3, 0xF00
    /* A6C 800FA26C 10004014 */  bnez       $v0, .L800FA2B0
    /* A70 800FA270 00000000 */   nop
    /* A74 800FA274 5C006290 */  lbu        $v0, 0x5C($v1)
    /* A78 800FA278 00000000 */  nop
    /* A7C 800FA27C 0C004414 */  bne        $v0, $a0, .L800FA2B0
    /* A80 800FA280 00000000 */   nop
    /* A84 800FA284 5E006290 */  lbu        $v0, 0x5E($v1)
    /* A88 800FA288 00000000 */  nop
    /* A8C 800FA28C 08004514 */  bne        $v0, $a1, .L800FA2B0
    /* A90 800FA290 00000000 */   nop
    /* A94 800FA294 1E006384 */  lh         $v1, 0x1E($v1)
    /* A98 800FA298 00000000 */  nop
    /* A9C 800FA29C 2A106600 */  slt        $v0, $v1, $a2
    /* AA0 800FA2A0 03004014 */  bnez       $v0, .L800FA2B0
    /* AA4 800FA2A4 2A104301 */   slt       $v0, $t2, $v1
    /* AA8 800FA2A8 06004010 */  beqz       $v0, .L800FA2C4
    /* AAC 800FA2AC 01000224 */   addiu     $v0, $zero, 0x1
  .L800FA2B0:
    /* AB0 800FA2B0 01002925 */  addiu      $t1, $t1, 0x1
    /* AB4 800FA2B4 10002229 */  slti       $v0, $t1, 0x10
    /* AB8 800FA2B8 E3FF4014 */  bnez       $v0, .L800FA248
    /* ABC 800FA2BC 04000825 */   addiu     $t0, $t0, 0x4
    /* AC0 800FA2C0 21100000 */  addu       $v0, $zero, $zero
  .L800FA2C4:
    /* AC4 800FA2C4 0800E003 */  jr         $ra
    /* AC8 800FA2C8 00000000 */   nop
endlabel func_800FA238
