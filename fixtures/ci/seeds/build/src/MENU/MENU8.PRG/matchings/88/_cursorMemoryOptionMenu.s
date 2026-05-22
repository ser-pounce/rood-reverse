nonmatching _cursorMemoryOptionMenu, 0x1A8

glabel _cursorMemoryOptionMenu
    /* 768 80102F68 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 76C 80102F6C 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 770 80102F70 04008010 */  beqz       $a0, .L80102F84
    /* 774 80102F74 2800B0AF */   sw        $s0, 0x28($sp)
    /* 778 80102F78 1080023C */  lui        $v0, %hi(D_80105D88)
    /* 77C 80102F7C 3F0C0408 */  j          .L801030FC
    /* 780 80102F80 885D40AC */   sw        $zero, %lo(D_80105D88)($v0)
  .L80102F84:
    /* 784 80102F84 1080023C */  lui        $v0, %hi(D_80105D88)
    /* 788 80102F88 885D438C */  lw         $v1, %lo(D_80105D88)($v0)
    /* 78C 80102F8C 01000224 */  addiu      $v0, $zero, 0x1
    /* 790 80102F90 3C006210 */  beq        $v1, $v0, .L80103084
    /* 794 80102F94 02006228 */   slti      $v0, $v1, 0x2
    /* 798 80102F98 05004010 */  beqz       $v0, .L80102FB0
    /* 79C 80102F9C 02000224 */   addiu     $v0, $zero, 0x2
    /* 7A0 80102FA0 07006010 */  beqz       $v1, .L80102FC0
    /* 7A4 80102FA4 21100000 */   addu      $v0, $zero, $zero
    /* 7A8 80102FA8 400C0408 */  j          .L80103100
    /* 7AC 80102FAC 00000000 */   nop
  .L80102FB0:
    /* 7B0 80102FB0 4B006210 */  beq        $v1, $v0, .L801030E0
    /* 7B4 80102FB4 21100000 */   addu      $v0, $zero, $zero
    /* 7B8 80102FB8 400C0408 */  j          .L80103100
    /* 7BC 80102FBC 00000000 */   nop
  .L80102FC0:
    /* 7C0 80102FC0 74EA030C */  jal        vs_mainmenu_ready
    /* 7C4 80102FC4 00000000 */   nop
    /* 7C8 80102FC8 4C004010 */  beqz       $v0, .L801030FC
    /* 7CC 80102FCC 21280000 */   addu      $a1, $zero, $zero
    /* 7D0 80102FD0 1080023C */  lui        $v0, %hi(_menuStrings)
    /* 7D4 80102FD4 58554B24 */  addiu      $t3, $v0, %lo(_menuStrings)
    /* 7D8 80102FD8 2000AA27 */  addiu      $t2, $sp, 0x20
    /* 7DC 80102FDC 4E000924 */  addiu      $t1, $zero, 0x4E
    /* 7E0 80102FE0 04000824 */  addiu      $t0, $zero, 0x4
    /* 7E4 80102FE4 1000AC27 */  addiu      $t4, $sp, 0x10
    /* 7E8 80102FE8 21388001 */  addu       $a3, $t4, $zero
    /* 7EC 80102FEC 4C000624 */  addiu      $a2, $zero, 0x4C
  .L80102FF0:
    /* 7F0 80102FF0 21182B01 */  addu       $v1, $t1, $t3
    /* 7F4 80102FF4 04002925 */  addiu      $t1, $t1, 0x4
    /* 7F8 80102FF8 21208801 */  addu       $a0, $t4, $t0
    /* 7FC 80102FFC 08000825 */  addiu      $t0, $t0, 0x8
    /* 800 80103000 2110CB00 */  addu       $v0, $a2, $t3
    /* 804 80103004 0400C624 */  addiu      $a2, $a2, 0x4
    /* 808 80103008 00004294 */  lhu        $v0, 0x0($v0)
    /* 80C 8010300C 0100A524 */  addiu      $a1, $a1, 0x1
    /* 810 80103010 40100200 */  sll        $v0, $v0, 1
    /* 814 80103014 21104B00 */  addu       $v0, $v0, $t3
    /* 818 80103018 0000E2AC */  sw         $v0, 0x0($a3)
    /* 81C 8010301C 00006294 */  lhu        $v0, 0x0($v1)
    /* 820 80103020 0800E724 */  addiu      $a3, $a3, 0x8
    /* 824 80103024 40100200 */  sll        $v0, $v0, 1
    /* 828 80103028 21104B00 */  addu       $v0, $v0, $t3
    /* 82C 8010302C 000082AC */  sw         $v0, 0x0($a0)
    /* 830 80103030 000040AD */  sw         $zero, 0x0($t2)
    /* 834 80103034 0200A228 */  slti       $v0, $a1, 0x2
    /* 838 80103038 EDFF4014 */  bnez       $v0, .L80102FF0
    /* 83C 8010303C 04004A25 */   addiu     $t2, $t2, 0x4
    /* 840 80103040 0680023C */  lui        $v0, %hi(D_80060021)
    /* 844 80103044 01001024 */  addiu      $s0, $zero, 0x1
    /* 848 80103048 2000A727 */  addiu      $a3, $sp, 0x20
    /* 84C 8010304C 02000424 */  addiu      $a0, $zero, 0x2
    /* 850 80103050 21004290 */  lbu        $v0, %lo(D_80060021)($v0)
    /* 854 80103054 1000A627 */  addiu      $a2, $sp, 0x10
    /* 858 80103058 23280202 */  subu       $a1, $s0, $v0
    /* 85C 8010305C 80180500 */  sll        $v1, $a1, 2
    /* 860 80103060 2118E300 */  addu       $v1, $a3, $v1
    /* 864 80103064 0000628C */  lw         $v0, 0x0($v1)
    /* 868 80103068 4A020524 */  addiu      $a1, $zero, 0x24A
    /* 86C 8010306C 04004234 */  ori        $v0, $v0, 0x4
    /* 870 80103070 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 874 80103074 000062AC */   sw        $v0, 0x0($v1)
    /* 878 80103078 1080023C */  lui        $v0, %hi(D_80105D88)
    /* 87C 8010307C 3F0C0408 */  j          .L801030FC
    /* 880 80103080 885D50AC */   sw        $s0, %lo(D_80105D88)($v0)
  .L80103084:
    /* 884 80103084 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 888 80103088 00000000 */   nop
    /* 88C 8010308C 1080033C */  lui        $v1, %hi(D_80105D8C)
    /* 890 80103090 01004424 */  addiu      $a0, $v0, 0x1
    /* 894 80103094 19008010 */  beqz       $a0, .L801030FC
    /* 898 80103098 8C5D64AC */   sw        $a0, %lo(D_80105D8C)($v1)
    /* 89C 8010309C FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 8A0 801030A0 09008214 */  bne        $a0, $v0, .L801030C8
    /* 8A4 801030A4 00000000 */   nop
    /* 8A8 801030A8 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 8AC 801030AC 28000424 */   addiu     $a0, $zero, 0x28
    /* 8B0 801030B0 EAFE030C */  jal        func_800FFBA8
    /* 8B4 801030B4 00000000 */   nop
    /* 8B8 801030B8 A2FE030C */  jal        func_800FFA88
    /* 8BC 801030BC 21200000 */   addu      $a0, $zero, $zero
    /* 8C0 801030C0 350C0408 */  j          .L801030D4
    /* 8C4 801030C4 1080033C */   lui       $v1, %hi(D_80105D88)
  .L801030C8:
    /* 8C8 801030C8 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 8CC 801030CC 07000424 */   addiu     $a0, $zero, 0x7
    /* 8D0 801030D0 1080033C */  lui        $v1, %hi(D_80105D88)
  .L801030D4:
    /* 8D4 801030D4 02000224 */  addiu      $v0, $zero, 0x2
    /* 8D8 801030D8 3F0C0408 */  j          .L801030FC
    /* 8DC 801030DC 885D62AC */   sw        $v0, %lo(D_80105D88)($v1)
  .L801030E0:
    /* 8E0 801030E0 74EA030C */  jal        vs_mainmenu_ready
    /* 8E4 801030E4 00000000 */   nop
    /* 8E8 801030E8 04004010 */  beqz       $v0, .L801030FC
    /* 8EC 801030EC 1080023C */   lui       $v0, %hi(D_80105D8C)
    /* 8F0 801030F0 8C5D428C */  lw         $v0, %lo(D_80105D8C)($v0)
    /* 8F4 801030F4 400C0408 */  j          .L80103100
    /* 8F8 801030F8 00000000 */   nop
  .L801030FC:
    /* 8FC 801030FC 21100000 */  addu       $v0, $zero, $zero
  .L80103100:
    /* 900 80103100 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 904 80103104 2800B08F */  lw         $s0, 0x28($sp)
    /* 908 80103108 0800E003 */  jr         $ra
    /* 90C 8010310C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _cursorMemoryOptionMenu
