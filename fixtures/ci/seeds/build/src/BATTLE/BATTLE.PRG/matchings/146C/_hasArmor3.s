nonmatching _hasArmor3, 0x9C

glabel _hasArmor3
    /* 1746C 8007FC6C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 17470 8007FC70 1000B0AF */  sw         $s0, 0x10($sp)
    /* 17474 8007FC74 2180A000 */  addu       $s0, $a1, $zero
    /* 17478 8007FC78 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1747C 8007FC7C 2CFD010C */  jal        func_8007F4B0
    /* 17480 8007FC80 1C000424 */   addiu     $a0, $zero, 0x1C
    /* 17484 8007FC84 1C004014 */  bnez       $v0, .L8007FCF8
    /* 17488 8007FC88 21100000 */   addu      $v0, $zero, $zero
    /* 1748C 8007FC8C 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 17490 8007FC90 00000392 */  lbu        $v1, 0x0($s0)
    /* 17494 8007FC94 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* 17498 8007FC98 80180300 */  sll        $v1, $v1, 2
    /* 1749C 8007FC9C 21186200 */  addu       $v1, $v1, $v0
    /* 174A0 8007FCA0 0000628C */  lw         $v0, 0x0($v1)
    /* 174A4 8007FCA4 21280000 */  addu       $a1, $zero, $zero
    /* 174A8 8007FCA8 3C00468C */  lw         $a2, 0x3C($v0)
    /* 174AC 8007FCAC 2120A000 */  addu       $a0, $a1, $zero
    /* 174B0 8007FCB0 2118C000 */  addu       $v1, $a2, $zero
  .L8007FCB4:
    /* 174B4 8007FCB4 B8036294 */  lhu        $v0, 0x3B8($v1)
    /* 174B8 8007FCB8 00000000 */  nop
    /* 174BC 8007FCBC 02004010 */  beqz       $v0, .L8007FCC8
    /* 174C0 8007FCC0 00000000 */   nop
    /* 174C4 8007FCC4 01000524 */  addiu      $a1, $zero, 0x1
  .L8007FCC8:
    /* 174C8 8007FCC8 01008424 */  addiu      $a0, $a0, 0x1
    /* 174CC 8007FCCC 06008228 */  slti       $v0, $a0, 0x6
    /* 174D0 8007FCD0 F8FF4014 */  bnez       $v0, .L8007FCB4
    /* 174D4 8007FCD4 DC006324 */   addiu     $v1, $v1, 0xDC
    /* 174D8 8007FCD8 EC01C294 */  lhu        $v0, 0x1EC($a2)
    /* 174DC 8007FCDC 00000000 */  nop
    /* 174E0 8007FCE0 02004010 */  beqz       $v0, .L8007FCEC
    /* 174E4 8007FCE4 00000000 */   nop
    /* 174E8 8007FCE8 01000524 */  addiu      $a1, $zero, 0x1
  .L8007FCEC:
    /* 174EC 8007FCEC 0200A014 */  bnez       $a1, .L8007FCF8
    /* 174F0 8007FCF0 01000224 */   addiu     $v0, $zero, 0x1
    /* 174F4 8007FCF4 21100000 */  addu       $v0, $zero, $zero
  .L8007FCF8:
    /* 174F8 8007FCF8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 174FC 8007FCFC 1000B08F */  lw         $s0, 0x10($sp)
    /* 17500 8007FD00 0800E003 */  jr         $ra
    /* 17504 8007FD04 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _hasArmor3
