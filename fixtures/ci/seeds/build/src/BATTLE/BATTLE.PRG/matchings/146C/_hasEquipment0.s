nonmatching _hasEquipment0, 0xB0

glabel _hasEquipment0
    /* 16E28 8007F628 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16E2C 8007F62C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 16E30 8007F630 2180A000 */  addu       $s0, $a1, $zero
    /* 16E34 8007F634 1400BFAF */  sw         $ra, 0x14($sp)
    /* 16E38 8007F638 2CFD010C */  jal        func_8007F4B0
    /* 16E3C 8007F63C 13000424 */   addiu     $a0, $zero, 0x13
    /* 16E40 8007F640 21004014 */  bnez       $v0, .L8007F6C8
    /* 16E44 8007F644 21100000 */   addu      $v0, $zero, $zero
    /* 16E48 8007F648 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 16E4C 8007F64C 00000392 */  lbu        $v1, 0x0($s0)
    /* 16E50 8007F650 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* 16E54 8007F654 80180300 */  sll        $v1, $v1, 2
    /* 16E58 8007F658 21186200 */  addu       $v1, $v1, $v0
    /* 16E5C 8007F65C 0000628C */  lw         $v0, 0x0($v1)
    /* 16E60 8007F660 21280000 */  addu       $a1, $zero, $zero
    /* 16E64 8007F664 3C00468C */  lw         $a2, 0x3C($v0)
    /* 16E68 8007F668 2120A000 */  addu       $a0, $a1, $zero
    /* 16E6C 8007F66C 2118C000 */  addu       $v1, $a2, $zero
  .L8007F670:
    /* 16E70 8007F670 B8036294 */  lhu        $v0, 0x3B8($v1)
    /* 16E74 8007F674 00000000 */  nop
    /* 16E78 8007F678 02004010 */  beqz       $v0, .L8007F684
    /* 16E7C 8007F67C 00000000 */   nop
    /* 16E80 8007F680 01000524 */  addiu      $a1, $zero, 0x1
  .L8007F684:
    /* 16E84 8007F684 01008424 */  addiu      $a0, $a0, 0x1
    /* 16E88 8007F688 06008228 */  slti       $v0, $a0, 0x6
    /* 16E8C 8007F68C F8FF4014 */  bnez       $v0, .L8007F670
    /* 16E90 8007F690 DC006324 */   addiu     $v1, $v1, 0xDC
    /* 16E94 8007F694 EC01C294 */  lhu        $v0, 0x1EC($a2)
    /* 16E98 8007F698 00000000 */  nop
    /* 16E9C 8007F69C 02004010 */  beqz       $v0, .L8007F6A8
    /* 16EA0 8007F6A0 00000000 */   nop
    /* 16EA4 8007F6A4 01000524 */  addiu      $a1, $zero, 0x1
  .L8007F6A8:
    /* 16EA8 8007F6A8 5400C294 */  lhu        $v0, 0x54($a2)
    /* 16EAC 8007F6AC 00000000 */  nop
    /* 16EB0 8007F6B0 02004010 */  beqz       $v0, .L8007F6BC
    /* 16EB4 8007F6B4 00000000 */   nop
    /* 16EB8 8007F6B8 01000524 */  addiu      $a1, $zero, 0x1
  .L8007F6BC:
    /* 16EBC 8007F6BC 0200A014 */  bnez       $a1, .L8007F6C8
    /* 16EC0 8007F6C0 01000224 */   addiu     $v0, $zero, 0x1
    /* 16EC4 8007F6C4 21100000 */  addu       $v0, $zero, $zero
  .L8007F6C8:
    /* 16EC8 8007F6C8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 16ECC 8007F6CC 1000B08F */  lw         $s0, 0x10($sp)
    /* 16ED0 8007F6D0 0800E003 */  jr         $ra
    /* 16ED4 8007F6D4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _hasEquipment0
