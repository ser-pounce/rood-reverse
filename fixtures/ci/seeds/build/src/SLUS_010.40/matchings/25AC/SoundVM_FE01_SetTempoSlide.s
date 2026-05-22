nonmatching SoundVM_FE01_SetTempoSlide, 0xA0

glabel SoundVM_FE01_SetTempoSlide
    /* BA94 8001B294 21288000 */  addu       $a1, $a0, $zero
    /* BA98 8001B298 0380063C */  lui        $a2, %hi(g_pActiveMusicConfig)
    /* BA9C 8001B29C 0000A28C */  lw         $v0, 0x0($a1)
    /* BAA0 8001B2A0 2078C48C */  lw         $a0, %lo(g_pActiveMusicConfig)($a2)
    /* BAA4 8001B2A4 00004390 */  lbu        $v1, 0x0($v0)
    /* BAA8 8001B2A8 01004224 */  addiu      $v0, $v0, 0x1
    /* BAAC 8001B2AC 6C0083A4 */  sh         $v1, 0x6C($a0)
    /* BAB0 8001B2B0 03006014 */  bnez       $v1, .L8001B2C0
    /* BAB4 8001B2B4 0000A2AC */   sw        $v0, 0x0($a1)
    /* BAB8 8001B2B8 00010224 */  addiu      $v0, $zero, 0x100
    /* BABC 8001B2BC 6C0082A4 */  sh         $v0, 0x6C($a0)
  .L8001B2C0:
    /* BAC0 8001B2C0 0000A28C */  lw         $v0, 0x0($a1)
    /* BAC4 8001B2C4 00000000 */  nop
    /* BAC8 8001B2C8 00004390 */  lbu        $v1, 0x0($v0)
    /* BACC 8001B2CC 01004490 */  lbu        $a0, 0x1($v0)
    /* BAD0 8001B2D0 02004224 */  addiu      $v0, $v0, 0x2
    /* BAD4 8001B2D4 0000A2AC */  sw         $v0, 0x0($a1)
    /* BAD8 8001B2D8 2078C58C */  lw         $a1, %lo(g_pActiveMusicConfig)($a2)
    /* BADC 8001B2DC 001C0300 */  sll        $v1, $v1, 16
    /* BAE0 8001B2E0 00260400 */  sll        $a0, $a0, 24
    /* BAE4 8001B2E4 25186400 */  or         $v1, $v1, $a0
    /* BAE8 8001B2E8 2000A48C */  lw         $a0, 0x20($a1)
    /* BAEC 8001B2EC FFFF023C */  lui        $v0, (0xFFFF0000 >> 16)
    /* BAF0 8001B2F0 24208200 */  and        $a0, $a0, $v0
    /* BAF4 8001B2F4 6C00A294 */  lhu        $v0, 0x6C($a1)
    /* BAF8 8001B2F8 23186400 */  subu       $v1, $v1, $a0
    /* BAFC 8001B2FC 1A006200 */  div        $zero, $v1, $v0
    /* BB00 8001B300 02004014 */  bnez       $v0, .L8001B30C
    /* BB04 8001B304 00000000 */   nop
    /* BB08 8001B308 0D000700 */  break      7
  .L8001B30C:
    /* BB0C 8001B30C FFFF0124 */  addiu      $at, $zero, -0x1
    /* BB10 8001B310 04004114 */  bne        $v0, $at, .L8001B324
    /* BB14 8001B314 0080013C */   lui       $at, (0x80000000 >> 16)
    /* BB18 8001B318 02006114 */  bne        $v1, $at, .L8001B324
    /* BB1C 8001B31C 00000000 */   nop
    /* BB20 8001B320 0D000600 */  break      6
  .L8001B324:
    /* BB24 8001B324 12180000 */  mflo       $v1
    /* BB28 8001B328 2000A4AC */  sw         $a0, 0x20($a1)
    /* BB2C 8001B32C 0800E003 */  jr         $ra
    /* BB30 8001B330 2400A3AC */   sw        $v1, 0x24($a1)
endlabel SoundVM_FE01_SetTempoSlide
