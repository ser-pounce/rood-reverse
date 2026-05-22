nonmatching SpuRead, 0x5C

glabel SpuRead
    /* F304 8001EB04 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F308 8001EB08 1000B0AF */  sw         $s0, 0x10($sp)
    /* F30C 8001EB0C 2180A000 */  addu       $s0, $a1, $zero
    /* F310 8001EB10 0700023C */  lui        $v0, (0x7EFF0 >> 16)
    /* F314 8001EB14 F0EF4234 */  ori        $v0, $v0, (0x7EFF0 & 0xFFFF)
    /* F318 8001EB18 2B105000 */  sltu       $v0, $v0, $s0
    /* F31C 8001EB1C 03004010 */  beqz       $v0, .L8001EB2C
    /* F320 8001EB20 1400BFAF */   sw        $ra, 0x14($sp)
    /* F324 8001EB24 0700103C */  lui        $s0, (0x7EFF0 >> 16)
    /* F328 8001EB28 F0EF1036 */  ori        $s0, $s0, (0x7EFF0 & 0xFFFF)
  .L8001EB2C:
    /* F32C 8001EB2C BF78000C */  jal        _spu_Fr
    /* F330 8001EB30 21280002 */   addu      $a1, $s0, $zero
    /* F334 8001EB34 0380023C */  lui        $v0, %hi(D_80030898)
    /* F338 8001EB38 9808428C */  lw         $v0, %lo(D_80030898)($v0)
    /* F33C 8001EB3C 00000000 */  nop
    /* F340 8001EB40 03004014 */  bnez       $v0, .L8001EB50
    /* F344 8001EB44 21100002 */   addu      $v0, $s0, $zero
    /* F348 8001EB48 0380013C */  lui        $at, %hi(D_80030894)
    /* F34C 8001EB4C 940820AC */  sw         $zero, %lo(D_80030894)($at)
  .L8001EB50:
    /* F350 8001EB50 1400BF8F */  lw         $ra, 0x14($sp)
    /* F354 8001EB54 1000B08F */  lw         $s0, 0x10($sp)
    /* F358 8001EB58 0800E003 */  jr         $ra
    /* F35C 8001EB5C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel SpuRead
    /* F360 8001EB60 00000000 */  nop
