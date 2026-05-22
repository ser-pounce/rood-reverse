nonmatching _hasArmor0, 0x9C

glabel _hasArmor0
    /* 17298 8007FA98 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1729C 8007FA9C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 172A0 8007FAA0 2180A000 */  addu       $s0, $a1, $zero
    /* 172A4 8007FAA4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 172A8 8007FAA8 2CFD010C */  jal        func_8007F4B0
    /* 172AC 8007FAAC 19000424 */   addiu     $a0, $zero, 0x19
    /* 172B0 8007FAB0 1C004014 */  bnez       $v0, .L8007FB24
    /* 172B4 8007FAB4 21100000 */   addu      $v0, $zero, $zero
    /* 172B8 8007FAB8 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 172BC 8007FABC 00000392 */  lbu        $v1, 0x0($s0)
    /* 172C0 8007FAC0 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* 172C4 8007FAC4 80180300 */  sll        $v1, $v1, 2
    /* 172C8 8007FAC8 21186200 */  addu       $v1, $v1, $v0
    /* 172CC 8007FACC 0000628C */  lw         $v0, 0x0($v1)
    /* 172D0 8007FAD0 21280000 */  addu       $a1, $zero, $zero
    /* 172D4 8007FAD4 3C00468C */  lw         $a2, 0x3C($v0)
    /* 172D8 8007FAD8 2120A000 */  addu       $a0, $a1, $zero
    /* 172DC 8007FADC 2118C000 */  addu       $v1, $a2, $zero
  .L8007FAE0:
    /* 172E0 8007FAE0 B8036294 */  lhu        $v0, 0x3B8($v1)
    /* 172E4 8007FAE4 00000000 */  nop
    /* 172E8 8007FAE8 02004010 */  beqz       $v0, .L8007FAF4
    /* 172EC 8007FAEC 00000000 */   nop
    /* 172F0 8007FAF0 01000524 */  addiu      $a1, $zero, 0x1
  .L8007FAF4:
    /* 172F4 8007FAF4 01008424 */  addiu      $a0, $a0, 0x1
    /* 172F8 8007FAF8 06008228 */  slti       $v0, $a0, 0x6
    /* 172FC 8007FAFC F8FF4014 */  bnez       $v0, .L8007FAE0
    /* 17300 8007FB00 DC006324 */   addiu     $v1, $v1, 0xDC
    /* 17304 8007FB04 EC01C294 */  lhu        $v0, 0x1EC($a2)
    /* 17308 8007FB08 00000000 */  nop
    /* 1730C 8007FB0C 02004010 */  beqz       $v0, .L8007FB18
    /* 17310 8007FB10 00000000 */   nop
    /* 17314 8007FB14 01000524 */  addiu      $a1, $zero, 0x1
  .L8007FB18:
    /* 17318 8007FB18 0200A014 */  bnez       $a1, .L8007FB24
    /* 1731C 8007FB1C 01000224 */   addiu     $v0, $zero, 0x1
    /* 17320 8007FB20 21100000 */  addu       $v0, $zero, $zero
  .L8007FB24:
    /* 17324 8007FB24 1400BF8F */  lw         $ra, 0x14($sp)
    /* 17328 8007FB28 1000B08F */  lw         $s0, 0x10($sp)
    /* 1732C 8007FB2C 0800E003 */  jr         $ra
    /* 17330 8007FB30 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _hasArmor0
