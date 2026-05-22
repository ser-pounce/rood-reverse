nonmatching _findCurrentSaveOnActiveMemcard, 0x98

glabel _findCurrentSaveOnActiveMemcard
    /* 5B4 80068DB4 21280000 */  addu       $a1, $zero, $zero
    /* 5B8 80068DB8 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 5BC 80068DBC 20004624 */  addiu      $a2, $v0, %lo(vs_main_settings)
    /* 5C0 80068DC0 0E80023C */  lui        $v0, %hi(_saveFileInfo)
    /* 5C4 80068DC4 08EB448C */  lw         $a0, %lo(_saveFileInfo)($v0)
  .L80068DC8:
    /* 5C8 80068DC8 00000000 */  nop
    /* 5CC 80068DCC 0400838C */  lw         $v1, 0x4($a0)
    /* 5D0 80068DD0 00000000 */  nop
    /* 5D4 80068DD4 0300622C */  sltiu      $v0, $v1, 0x3
    /* 5D8 80068DD8 14004014 */  bnez       $v0, .L80068E2C
    /* 5DC 80068DDC 00000000 */   nop
    /* 5E0 80068DE0 0400C28C */  lw         $v0, 0x4($a2)
    /* 5E4 80068DE4 00000000 */  nop
    /* 5E8 80068DE8 10006214 */  bne        $v1, $v0, .L80068E2C
    /* 5EC 80068DEC 00000000 */   nop
    /* 5F0 80068DF0 0000838C */  lw         $v1, 0x0($a0)
    /* 5F4 80068DF4 1400C28C */  lw         $v0, 0x14($a2)
    /* 5F8 80068DF8 00000000 */  nop
    /* 5FC 80068DFC 0B006214 */  bne        $v1, $v0, .L80068E2C
    /* 600 80068E00 00000000 */   nop
    /* 604 80068E04 14008394 */  lhu        $v1, 0x14($a0)
    /* 608 80068E08 1800C294 */  lhu        $v0, 0x18($a2)
    /* 60C 80068E0C 00000000 */  nop
    /* 610 80068E10 06006214 */  bne        $v1, $v0, .L80068E2C
    /* 614 80068E14 00000000 */   nop
    /* 618 80068E18 0800838C */  lw         $v1, 0x8($a0)
    /* 61C 80068E1C 1C00C28C */  lw         $v0, 0x1C($a2)
    /* 620 80068E20 00000000 */  nop
    /* 624 80068E24 07006210 */  beq        $v1, $v0, .L80068E44
    /* 628 80068E28 0100A224 */   addiu     $v0, $a1, 0x1
  .L80068E2C:
    /* 62C 80068E2C 0100A524 */  addiu      $a1, $a1, 0x1
    /* 630 80068E30 0500A228 */  slti       $v0, $a1, 0x5
    /* 634 80068E34 E4FF4014 */  bnez       $v0, .L80068DC8
    /* 638 80068E38 80008424 */   addiu     $a0, $a0, 0x80
    /* 63C 80068E3C 0800E003 */  jr         $ra
    /* 640 80068E40 21100000 */   addu      $v0, $zero, $zero
  .L80068E44:
    /* 644 80068E44 0800E003 */  jr         $ra
    /* 648 80068E48 00000000 */   nop
endlabel _findCurrentSaveOnActiveMemcard
