nonmatching func_80102CAC, 0xB8

glabel func_80102CAC
    /* 4AC 80102CAC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4B0 80102CB0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4B4 80102CB4 21808000 */  addu       $s0, $a0, $zero
    /* 4B8 80102CB8 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentSubtype)
    /* 4BC 80102CBC 20000324 */  addiu      $v1, $zero, 0x20
    /* 4C0 80102CC0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4C4 80102CC4 88F4030C */  jal        vs_mainMenu_resetStats
    /* 4C8 80102CC8 452543A0 */   sb        $v1, %lo(vs_mainMenu_equipmentSubtype)($v0)
    /* 4CC 80102CCC 00000296 */  lhu        $v0, 0x0($s0)
    /* 4D0 80102CD0 00000000 */  nop
    /* 4D4 80102CD4 1D004010 */  beqz       $v0, .L80102D4C
    /* 4D8 80102CD8 21300000 */   addu      $a2, $zero, $zero
    /* 4DC 80102CDC 40000924 */  addiu      $t1, $zero, 0x40
    /* 4E0 80102CE0 20000824 */  addiu      $t0, $zero, 0x20
    /* 4E4 80102CE4 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentStats)
    /* 4E8 80102CE8 C0244A24 */  addiu      $t2, $v0, %lo(vs_mainMenu_equipmentStats)
    /* 4EC 80102CEC 21384001 */  addu       $a3, $t2, $zero
  .L80102CF0:
    /* 4F0 80102CF0 21282A01 */  addu       $a1, $t1, $t2
    /* 4F4 80102CF4 02002925 */  addiu      $t1, $t1, 0x2
    /* 4F8 80102CF8 0700C230 */  andi       $v0, $a2, 0x7
    /* 4FC 80102CFC 40100200 */  sll        $v0, $v0, 1
    /* 500 80102D00 21100202 */  addu       $v0, $s0, $v0
    /* 504 80102D04 21200A01 */  addu       $a0, $t0, $t2
    /* 508 80102D08 40004394 */  lhu        $v1, 0x40($v0)
    /* 50C 80102D0C 02000825 */  addiu      $t0, $t0, 0x2
    /* 510 80102D10 0000E3A4 */  sh         $v1, 0x0($a3)
    /* 514 80102D14 50004394 */  lhu        $v1, 0x50($v0)
    /* 518 80102D18 0100C624 */  addiu      $a2, $a2, 0x1
    /* 51C 80102D1C 000083A4 */  sh         $v1, 0x0($a0)
    /* 520 80102D20 38004294 */  lhu        $v0, 0x38($v0)
    /* 524 80102D24 00000000 */  nop
    /* 528 80102D28 0000A2A4 */  sh         $v0, 0x0($a1)
    /* 52C 80102D2C 1000C228 */  slti       $v0, $a2, 0x10
    /* 530 80102D30 EFFF4014 */  bnez       $v0, .L80102CF0
    /* 534 80102D34 0200E724 */   addiu     $a3, $a3, 0x2
    /* 538 80102D38 30000486 */  lh         $a0, 0x30($s0)
    /* 53C 80102D3C 32000586 */  lh         $a1, 0x32($s0)
    /* 540 80102D40 34000686 */  lh         $a2, 0x34($s0)
    /* 544 80102D44 4AEF030C */  jal        vs_mainMenu_setStrIntAgi
    /* 548 80102D48 02000724 */   addiu     $a3, $zero, 0x2
  .L80102D4C:
    /* 54C 80102D4C E3EE030C */  jal        func_800FBB8C
    /* 550 80102D50 07000424 */   addiu     $a0, $zero, 0x7
    /* 554 80102D54 1400BF8F */  lw         $ra, 0x14($sp)
    /* 558 80102D58 1000B08F */  lw         $s0, 0x10($sp)
    /* 55C 80102D5C 0800E003 */  jr         $ra
    /* 560 80102D60 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80102CAC
