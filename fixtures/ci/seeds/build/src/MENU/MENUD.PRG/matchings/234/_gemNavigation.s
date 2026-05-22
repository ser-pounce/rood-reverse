nonmatching _gemNavigation, 0x1F4

glabel _gemNavigation
    /* 2614 80104E14 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 2618 80104E18 21288000 */  addu       $a1, $a0, $zero
    /* 261C 80104E1C 2800BFAF */  sw         $ra, 0x28($sp)
    /* 2620 80104E20 2400B1AF */  sw         $s1, 0x24($sp)
    /* 2624 80104E24 1000A010 */  beqz       $a1, .L80104E68
    /* 2628 80104E28 2000B0AF */   sw        $s0, 0x20($sp)
    /* 262C 80104E2C 1180033C */  lui        $v1, %hi(D_80109A49)
    /* 2630 80104E30 03120500 */  sra        $v0, $a1, 8
    /* 2634 80104E34 499A62A0 */  sb         $v0, %lo(D_80109A49)($v1)
    /* 2638 80104E38 FF004430 */  andi       $a0, $v0, 0xFF
    /* 263C 80104E3C 1180033C */  lui        $v1, %hi(D_80109A4A)
    /* 2640 80104E40 FFFFA224 */  addiu      $v0, $a1, -0x1
    /* 2644 80104E44 D90F040C */  jal        func_80103F64
    /* 2648 80104E48 4A9A62A0 */   sb        $v0, %lo(D_80109A4A)($v1)
    /* 264C 80104E4C 21100000 */  addu       $v0, $zero, $zero
    /* 2650 80104E50 1180043C */  lui        $a0, %hi(D_80109A48)
    /* 2654 80104E54 0A000324 */  addiu      $v1, $zero, 0xA
    /* 2658 80104E58 489A83A0 */  sb         $v1, %lo(D_80109A48)($a0)
    /* 265C 80104E5C 1180033C */  lui        $v1, %hi(D_80109A47)
    /* 2660 80104E60 FD130408 */  j          .L80104FF4
    /* 2664 80104E64 479A60A0 */   sb        $zero, %lo(D_80109A47)($v1)
  .L80104E68:
    /* 2668 80104E68 1180113C */  lui        $s1, %hi(D_80109A47)
    /* 266C 80104E6C 479A2392 */  lbu        $v1, %lo(D_80109A47)($s1)
    /* 2670 80104E70 01001024 */  addiu      $s0, $zero, 0x1
    /* 2674 80104E74 1F007010 */  beq        $v1, $s0, .L80104EF4
    /* 2678 80104E78 02006228 */   slti      $v0, $v1, 0x2
    /* 267C 80104E7C 05004010 */  beqz       $v0, .L80104E94
    /* 2680 80104E80 02000224 */   addiu     $v0, $zero, 0x2
    /* 2684 80104E84 09006010 */  beqz       $v1, .L80104EAC
    /* 2688 80104E88 21100000 */   addu      $v0, $zero, $zero
    /* 268C 80104E8C FD130408 */  j          .L80104FF4
    /* 2690 80104E90 00000000 */   nop
  .L80104E94:
    /* 2694 80104E94 21006210 */  beq        $v1, $v0, .L80104F1C
    /* 2698 80104E98 03000224 */   addiu     $v0, $zero, 0x3
    /* 269C 80104E9C 50006210 */  beq        $v1, $v0, .L80104FE0
    /* 26A0 80104EA0 21100000 */   addu      $v0, $zero, $zero
    /* 26A4 80104EA4 FD130408 */  j          .L80104FF4
    /* 26A8 80104EA8 00000000 */   nop
  .L80104EAC:
    /* 26AC 80104EAC 74EA030C */  jal        vs_mainmenu_ready
    /* 26B0 80104EB0 00000000 */   nop
    /* 26B4 80104EB4 4E004010 */  beqz       $v0, .L80104FF0
    /* 26B8 80104EB8 1180023C */   lui       $v0, %hi(D_80109A49)
    /* 26BC 80104EBC 499A4490 */  lbu        $a0, %lo(D_80109A49)($v0)
    /* 26C0 80104EC0 0D10040C */  jal        func_80104034
    /* 26C4 80104EC4 03000524 */   addiu     $a1, $zero, 0x3
    /* 26C8 80104EC8 1180033C */  lui        $v1, %hi(vs_menuD_containerData)
    /* 26CC 80104ECC 1180023C */  lui        $v0, %hi(D_80109A4A)
    /* 26D0 80104ED0 4A9A4290 */  lbu        $v0, %lo(D_80109A4A)($v0)
    /* 26D4 80104ED4 8C9A638C */  lw         $v1, %lo(vs_menuD_containerData)($v1)
    /* 26D8 80104ED8 40100200 */  sll        $v0, $v0, 1
    /* 26DC 80104EDC 21186200 */  addu       $v1, $v1, $v0
    /* 26E0 80104EE0 003E6494 */  lhu        $a0, 0x3E00($v1)
    /* 26E4 80104EE4 1EF6030C */  jal        vs_mainMenu_setGemStats
    /* 26E8 80104EE8 00000000 */   nop
    /* 26EC 80104EEC FC130408 */  j          .L80104FF0
    /* 26F0 80104EF0 479A30A2 */   sb        $s0, %lo(D_80109A47)($s1)
  .L80104EF4:
    /* 26F4 80104EF4 1180033C */  lui        $v1, %hi(D_80109A48)
    /* 26F8 80104EF8 489A6290 */  lbu        $v0, %lo(D_80109A48)($v1)
    /* 26FC 80104EFC 00000000 */  nop
    /* 2700 80104F00 03004010 */  beqz       $v0, .L80104F10
    /* 2704 80104F04 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 2708 80104F08 FC130408 */  j          .L80104FF0
    /* 270C 80104F0C 489A62A0 */   sb        $v0, %lo(D_80109A48)($v1)
  .L80104F10:
    /* 2710 80104F10 02000224 */  addiu      $v0, $zero, 0x2
    /* 2714 80104F14 FC130408 */  j          .L80104FF0
    /* 2718 80104F18 479A22A2 */   sb        $v0, %lo(D_80109A47)($s1)
  .L80104F1C:
    /* 271C 80104F1C 0680103C */  lui        $s0, %hi(vs_main_buttonsPressed)
    /* 2720 80104F20 D0E1028E */  lw         $v0, %lo(vs_main_buttonsPressed)($s0)
    /* 2724 80104F24 00000000 */  nop
    /* 2728 80104F28 50004230 */  andi       $v0, $v0, 0x50
    /* 272C 80104F2C 0A004010 */  beqz       $v0, .L80104F58
    /* 2730 80104F30 00000000 */   nop
    /* 2734 80104F34 5C10040C */  jal        func_80104170
    /* 2738 80104F38 21200000 */   addu      $a0, $zero, $zero
    /* 273C 80104F3C 03000224 */  addiu      $v0, $zero, 0x3
    /* 2740 80104F40 479A22A2 */  sb         $v0, %lo(D_80109A47)($s1)
    /* 2744 80104F44 D0E1028E */  lw         $v0, %lo(vs_main_buttonsPressed)($s0)
    /* 2748 80104F48 1180033C */  lui        $v1, %hi(D_80109A84)
    /* 274C 80104F4C 10004230 */  andi       $v0, $v0, 0x10
    /* 2750 80104F50 FC130408 */  j          .L80104FF0
    /* 2754 80104F54 849A62AC */   sw        $v0, %lo(D_80109A84)($v1)
  .L80104F58:
    /* 2758 80104F58 1180103C */  lui        $s0, %hi(D_80109A4A)
    /* 275C 80104F5C 4A9A0592 */  lbu        $a1, %lo(D_80109A4A)($s0)
    /* 2760 80104F60 5B0F040C */  jal        _pollItemNavigation
    /* 2764 80104F64 05000424 */   addiu     $a0, $zero, 0x5
    /* 2768 80104F68 4A9A0392 */  lbu        $v1, %lo(D_80109A4A)($s0)
    /* 276C 80104F6C 21884000 */  addu       $s1, $v0, $zero
    /* 2770 80104F70 1F002312 */  beq        $s1, $v1, .L80104FF0
    /* 2774 80104F74 05000424 */   addiu     $a0, $zero, 0x5
    /* 2778 80104F78 21282002 */  addu       $a1, $s1, $zero
    /* 277C 80104F7C 4510040C */  jal        func_80104114
    /* 2780 80104F80 4A9A11A2 */   sb        $s1, %lo(D_80109A4A)($s0)
    /* 2784 80104F84 1000A527 */  addiu      $a1, $sp, 0x10
    /* 2788 80104F88 1800A627 */  addiu      $a2, $sp, 0x18
    /* 278C 80104F8C 0F80033C */  lui        $v1, %hi(vs_battle_stringBuf)
    /* 2790 80104F90 21804000 */  addu       $s0, $v0, $zero
    /* 2794 80104F94 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 2798 80104F98 C0201000 */  sll        $a0, $s0, 3
    /* 279C 80104F9C 23209000 */  subu       $a0, $a0, $s0
    /* 27A0 80104FA0 80200400 */  sll        $a0, $a0, 2
    /* 27A4 80104FA4 E4228424 */  addiu      $a0, $a0, 0x22E4
    /* 27A8 80104FA8 8C9A428C */  lw         $v0, %lo(vs_menuD_containerData)($v0)
    /* 27AC 80104FAC 8C4E678C */  lw         $a3, %lo(vs_battle_stringBuf)($v1)
    /* 27B0 80104FB0 38F4030C */  jal        vs_mainMenu_setUiGem
    /* 27B4 80104FB4 21204400 */   addu      $a0, $v0, $a0
    /* 27B8 80104FB8 1EF6030C */  jal        vs_mainMenu_setGemStats
    /* 27BC 80104FBC 21200002 */   addu      $a0, $s0, $zero
    /* 27C0 80104FC0 1000A527 */  addiu      $a1, $sp, 0x10
    /* 27C4 80104FC4 1180023C */  lui        $v0, %hi(D_80109A49)
    /* 27C8 80104FC8 499A4490 */  lbu        $a0, %lo(D_80109A49)($v0)
    /* 27CC 80104FCC 1800A68F */  lw         $a2, 0x18($sp)
    /* 27D0 80104FD0 1E10040C */  jal        func_80104078
    /* 27D4 80104FD4 21382002 */   addu      $a3, $s1, $zero
    /* 27D8 80104FD8 FD130408 */  j          .L80104FF4
    /* 27DC 80104FDC 21100000 */   addu      $v0, $zero, $zero
  .L80104FE0:
    /* 27E0 80104FE0 74EA030C */  jal        vs_mainmenu_ready
    /* 27E4 80104FE4 00000000 */   nop
    /* 27E8 80104FE8 FD130408 */  j          .L80104FF4
    /* 27EC 80104FEC 00000000 */   nop
  .L80104FF0:
    /* 27F0 80104FF0 21100000 */  addu       $v0, $zero, $zero
  .L80104FF4:
    /* 27F4 80104FF4 2800BF8F */  lw         $ra, 0x28($sp)
    /* 27F8 80104FF8 2400B18F */  lw         $s1, 0x24($sp)
    /* 27FC 80104FFC 2000B08F */  lw         $s0, 0x20($sp)
    /* 2800 80105000 0800E003 */  jr         $ra
    /* 2804 80105004 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _gemNavigation
