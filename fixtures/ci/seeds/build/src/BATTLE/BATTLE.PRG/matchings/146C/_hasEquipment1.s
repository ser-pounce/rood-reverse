nonmatching _hasEquipment1, 0xB0

glabel _hasEquipment1
    /* 16F58 8007F758 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16F5C 8007F75C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 16F60 8007F760 2180A000 */  addu       $s0, $a1, $zero
    /* 16F64 8007F764 1400BFAF */  sw         $ra, 0x14($sp)
    /* 16F68 8007F768 2CFD010C */  jal        func_8007F4B0
    /* 16F6C 8007F76C 14000424 */   addiu     $a0, $zero, 0x14
    /* 16F70 8007F770 21004014 */  bnez       $v0, .L8007F7F8
    /* 16F74 8007F774 21100000 */   addu      $v0, $zero, $zero
    /* 16F78 8007F778 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 16F7C 8007F77C 00000392 */  lbu        $v1, 0x0($s0)
    /* 16F80 8007F780 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* 16F84 8007F784 80180300 */  sll        $v1, $v1, 2
    /* 16F88 8007F788 21186200 */  addu       $v1, $v1, $v0
    /* 16F8C 8007F78C 0000628C */  lw         $v0, 0x0($v1)
    /* 16F90 8007F790 21280000 */  addu       $a1, $zero, $zero
    /* 16F94 8007F794 3C00468C */  lw         $a2, 0x3C($v0)
    /* 16F98 8007F798 2120A000 */  addu       $a0, $a1, $zero
    /* 16F9C 8007F79C 2118C000 */  addu       $v1, $a2, $zero
  .L8007F7A0:
    /* 16FA0 8007F7A0 B8036294 */  lhu        $v0, 0x3B8($v1)
    /* 16FA4 8007F7A4 00000000 */  nop
    /* 16FA8 8007F7A8 02004010 */  beqz       $v0, .L8007F7B4
    /* 16FAC 8007F7AC 00000000 */   nop
    /* 16FB0 8007F7B0 01000524 */  addiu      $a1, $zero, 0x1
  .L8007F7B4:
    /* 16FB4 8007F7B4 01008424 */  addiu      $a0, $a0, 0x1
    /* 16FB8 8007F7B8 06008228 */  slti       $v0, $a0, 0x6
    /* 16FBC 8007F7BC F8FF4014 */  bnez       $v0, .L8007F7A0
    /* 16FC0 8007F7C0 DC006324 */   addiu     $v1, $v1, 0xDC
    /* 16FC4 8007F7C4 EC01C294 */  lhu        $v0, 0x1EC($a2)
    /* 16FC8 8007F7C8 00000000 */  nop
    /* 16FCC 8007F7CC 02004010 */  beqz       $v0, .L8007F7D8
    /* 16FD0 8007F7D0 00000000 */   nop
    /* 16FD4 8007F7D4 01000524 */  addiu      $a1, $zero, 0x1
  .L8007F7D8:
    /* 16FD8 8007F7D8 5400C294 */  lhu        $v0, 0x54($a2)
    /* 16FDC 8007F7DC 00000000 */  nop
    /* 16FE0 8007F7E0 02004010 */  beqz       $v0, .L8007F7EC
    /* 16FE4 8007F7E4 00000000 */   nop
    /* 16FE8 8007F7E8 01000524 */  addiu      $a1, $zero, 0x1
  .L8007F7EC:
    /* 16FEC 8007F7EC 0200A014 */  bnez       $a1, .L8007F7F8
    /* 16FF0 8007F7F0 01000224 */   addiu     $v0, $zero, 0x1
    /* 16FF4 8007F7F4 21100000 */  addu       $v0, $zero, $zero
  .L8007F7F8:
    /* 16FF8 8007F7F8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 16FFC 8007F7FC 1000B08F */  lw         $s0, 0x10($sp)
    /* 17000 8007F800 0800E003 */  jr         $ra
    /* 17004 8007F804 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _hasEquipment1
