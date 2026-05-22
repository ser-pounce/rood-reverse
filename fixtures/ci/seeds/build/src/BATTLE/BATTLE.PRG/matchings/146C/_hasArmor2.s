nonmatching _hasArmor2, 0x9C

glabel _hasArmor2
    /* 173D0 8007FBD0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 173D4 8007FBD4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 173D8 8007FBD8 2180A000 */  addu       $s0, $a1, $zero
    /* 173DC 8007FBDC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 173E0 8007FBE0 2CFD010C */  jal        func_8007F4B0
    /* 173E4 8007FBE4 1B000424 */   addiu     $a0, $zero, 0x1B
    /* 173E8 8007FBE8 1C004014 */  bnez       $v0, .L8007FC5C
    /* 173EC 8007FBEC 21100000 */   addu      $v0, $zero, $zero
    /* 173F0 8007FBF0 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 173F4 8007FBF4 00000392 */  lbu        $v1, 0x0($s0)
    /* 173F8 8007FBF8 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* 173FC 8007FBFC 80180300 */  sll        $v1, $v1, 2
    /* 17400 8007FC00 21186200 */  addu       $v1, $v1, $v0
    /* 17404 8007FC04 0000628C */  lw         $v0, 0x0($v1)
    /* 17408 8007FC08 21280000 */  addu       $a1, $zero, $zero
    /* 1740C 8007FC0C 3C00468C */  lw         $a2, 0x3C($v0)
    /* 17410 8007FC10 2120A000 */  addu       $a0, $a1, $zero
    /* 17414 8007FC14 2118C000 */  addu       $v1, $a2, $zero
  .L8007FC18:
    /* 17418 8007FC18 B8036294 */  lhu        $v0, 0x3B8($v1)
    /* 1741C 8007FC1C 00000000 */  nop
    /* 17420 8007FC20 02004010 */  beqz       $v0, .L8007FC2C
    /* 17424 8007FC24 00000000 */   nop
    /* 17428 8007FC28 01000524 */  addiu      $a1, $zero, 0x1
  .L8007FC2C:
    /* 1742C 8007FC2C 01008424 */  addiu      $a0, $a0, 0x1
    /* 17430 8007FC30 06008228 */  slti       $v0, $a0, 0x6
    /* 17434 8007FC34 F8FF4014 */  bnez       $v0, .L8007FC18
    /* 17438 8007FC38 DC006324 */   addiu     $v1, $v1, 0xDC
    /* 1743C 8007FC3C EC01C294 */  lhu        $v0, 0x1EC($a2)
    /* 17440 8007FC40 00000000 */  nop
    /* 17444 8007FC44 02004010 */  beqz       $v0, .L8007FC50
    /* 17448 8007FC48 00000000 */   nop
    /* 1744C 8007FC4C 01000524 */  addiu      $a1, $zero, 0x1
  .L8007FC50:
    /* 17450 8007FC50 0200A014 */  bnez       $a1, .L8007FC5C
    /* 17454 8007FC54 01000224 */   addiu     $v0, $zero, 0x1
    /* 17458 8007FC58 21100000 */  addu       $v0, $zero, $zero
  .L8007FC5C:
    /* 1745C 8007FC5C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 17460 8007FC60 1000B08F */  lw         $s0, 0x10($sp)
    /* 17464 8007FC64 0800E003 */  jr         $ra
    /* 17468 8007FC68 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _hasArmor2
