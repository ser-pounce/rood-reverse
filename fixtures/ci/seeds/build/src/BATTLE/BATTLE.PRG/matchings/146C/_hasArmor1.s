nonmatching _hasArmor1, 0x9C

glabel _hasArmor1
    /* 17334 8007FB34 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 17338 8007FB38 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1733C 8007FB3C 2180A000 */  addu       $s0, $a1, $zero
    /* 17340 8007FB40 1400BFAF */  sw         $ra, 0x14($sp)
    /* 17344 8007FB44 2CFD010C */  jal        func_8007F4B0
    /* 17348 8007FB48 1A000424 */   addiu     $a0, $zero, 0x1A
    /* 1734C 8007FB4C 1C004014 */  bnez       $v0, .L8007FBC0
    /* 17350 8007FB50 21100000 */   addu      $v0, $zero, $zero
    /* 17354 8007FB54 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 17358 8007FB58 00000392 */  lbu        $v1, 0x0($s0)
    /* 1735C 8007FB5C 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* 17360 8007FB60 80180300 */  sll        $v1, $v1, 2
    /* 17364 8007FB64 21186200 */  addu       $v1, $v1, $v0
    /* 17368 8007FB68 0000628C */  lw         $v0, 0x0($v1)
    /* 1736C 8007FB6C 21280000 */  addu       $a1, $zero, $zero
    /* 17370 8007FB70 3C00468C */  lw         $a2, 0x3C($v0)
    /* 17374 8007FB74 2120A000 */  addu       $a0, $a1, $zero
    /* 17378 8007FB78 2118C000 */  addu       $v1, $a2, $zero
  .L8007FB7C:
    /* 1737C 8007FB7C B8036294 */  lhu        $v0, 0x3B8($v1)
    /* 17380 8007FB80 00000000 */  nop
    /* 17384 8007FB84 02004010 */  beqz       $v0, .L8007FB90
    /* 17388 8007FB88 00000000 */   nop
    /* 1738C 8007FB8C 01000524 */  addiu      $a1, $zero, 0x1
  .L8007FB90:
    /* 17390 8007FB90 01008424 */  addiu      $a0, $a0, 0x1
    /* 17394 8007FB94 06008228 */  slti       $v0, $a0, 0x6
    /* 17398 8007FB98 F8FF4014 */  bnez       $v0, .L8007FB7C
    /* 1739C 8007FB9C DC006324 */   addiu     $v1, $v1, 0xDC
    /* 173A0 8007FBA0 EC01C294 */  lhu        $v0, 0x1EC($a2)
    /* 173A4 8007FBA4 00000000 */  nop
    /* 173A8 8007FBA8 02004010 */  beqz       $v0, .L8007FBB4
    /* 173AC 8007FBAC 00000000 */   nop
    /* 173B0 8007FBB0 01000524 */  addiu      $a1, $zero, 0x1
  .L8007FBB4:
    /* 173B4 8007FBB4 0200A014 */  bnez       $a1, .L8007FBC0
    /* 173B8 8007FBB8 01000224 */   addiu     $v0, $zero, 0x1
    /* 173BC 8007FBBC 21100000 */  addu       $v0, $zero, $zero
  .L8007FBC0:
    /* 173C0 8007FBC0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 173C4 8007FBC4 1000B08F */  lw         $s0, 0x10($sp)
    /* 173C8 8007FBC8 0800E003 */  jr         $ra
    /* 173CC 8007FBCC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _hasArmor1
