nonmatching func_80102D64, 0xD8

glabel func_80102D64
    /* 564 80102D64 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 568 80102D68 21488000 */  addu       $t1, $a0, $zero
    /* 56C 80102D6C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 570 80102D70 18003025 */  addiu      $s0, $t1, 0x18
    /* 574 80102D74 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentSubtype)
    /* 578 80102D78 02000324 */  addiu      $v1, $zero, 0x2
    /* 57C 80102D7C 21280000 */  addu       $a1, $zero, $zero
    /* 580 80102D80 20000724 */  addiu      $a3, $zero, 0x20
    /* 584 80102D84 452543A0 */  sb         $v1, %lo(vs_mainMenu_equipmentSubtype)($v0)
    /* 588 80102D88 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentStats)
    /* 58C 80102D8C C0244824 */  addiu      $t0, $v0, %lo(vs_mainMenu_equipmentStats)
    /* 590 80102D90 21300001 */  addu       $a2, $t0, $zero
    /* 594 80102D94 1400BFAF */  sw         $ra, 0x14($sp)
  .L80102D98:
    /* 598 80102D98 2120E800 */  addu       $a0, $a3, $t0
    /* 59C 80102D9C 0200E724 */  addiu      $a3, $a3, 0x2
    /* 5A0 80102DA0 0700A330 */  andi       $v1, $a1, 0x7
    /* 5A4 80102DA4 21180302 */  addu       $v1, $s0, $v1
    /* 5A8 80102DA8 20006290 */  lbu        $v0, 0x20($v1)
    /* 5AC 80102DAC 0100A524 */  addiu      $a1, $a1, 0x1
    /* 5B0 80102DB0 00160200 */  sll        $v0, $v0, 24
    /* 5B4 80102DB4 03160200 */  sra        $v0, $v0, 24
    /* 5B8 80102DB8 0000C2A4 */  sh         $v0, 0x0($a2)
    /* 5BC 80102DBC 28006290 */  lbu        $v0, 0x28($v1)
    /* 5C0 80102DC0 00000000 */  nop
    /* 5C4 80102DC4 00160200 */  sll        $v0, $v0, 24
    /* 5C8 80102DC8 03160200 */  sra        $v0, $v0, 24
    /* 5CC 80102DCC 000082A4 */  sh         $v0, 0x0($a0)
    /* 5D0 80102DD0 1000A228 */  slti       $v0, $a1, 0x10
    /* 5D4 80102DD4 F0FF4014 */  bnez       $v0, .L80102D98
    /* 5D8 80102DD8 0200C624 */   addiu     $a2, $a2, 0x2
    /* 5DC 80102DDC 08000496 */  lhu        $a0, 0x8($s0)
    /* 5E0 80102DE0 0A000596 */  lhu        $a1, 0xA($s0)
    /* 5E4 80102DE4 10012695 */  lhu        $a2, 0x110($t1)
    /* 5E8 80102DE8 12012795 */  lhu        $a3, 0x112($t1)
    /* 5EC 80102DEC 82F0030C */  jal        vs_mainMenu_setDpPp
    /* 5F0 80102DF0 00000000 */   nop
    /* 5F4 80102DF4 05000482 */  lb         $a0, 0x5($s0)
    /* 5F8 80102DF8 06000582 */  lb         $a1, 0x6($s0)
    /* 5FC 80102DFC 07000682 */  lb         $a2, 0x7($s0)
    /* 600 80102E00 4AEF030C */  jal        vs_mainMenu_setStrIntAgi
    /* 604 80102E04 01000724 */   addiu     $a3, $zero, 0x1
    /* 608 80102E08 21300000 */  addu       $a2, $zero, $zero
    /* 60C 80102E0C 18000492 */  lbu        $a0, 0x18($s0)
    /* 610 80102E10 12000592 */  lbu        $a1, 0x12($s0)
    /* 614 80102E14 43EF030C */  jal        vs_mainMenu_setRangeRisk
    /* 618 80102E18 01000724 */   addiu     $a3, $zero, 0x1
    /* 61C 80102E1C E3EE030C */  jal        func_800FBB8C
    /* 620 80102E20 03000424 */   addiu     $a0, $zero, 0x3
    /* 624 80102E24 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 628 80102E28 0B000424 */   addiu     $a0, $zero, 0xB
    /* 62C 80102E2C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 630 80102E30 1000B08F */  lw         $s0, 0x10($sp)
    /* 634 80102E34 0800E003 */  jr         $ra
    /* 638 80102E38 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80102D64
