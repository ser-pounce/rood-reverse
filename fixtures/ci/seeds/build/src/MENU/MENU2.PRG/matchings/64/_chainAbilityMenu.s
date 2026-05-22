nonmatching _chainAbilityMenu, 0x174

glabel _chainAbilityMenu
    /* CFC 801034FC 78FFBD27 */  addiu      $sp, $sp, -0x88
    /* D00 80103500 07008010 */  beqz       $a0, .L80103520
    /* D04 80103504 8000BFAF */   sw        $ra, 0x80($sp)
    /* D08 80103508 21200000 */  addu       $a0, $zero, $zero
    /* D0C 8010350C 4BEA030C */  jal        func_800FA92C
    /* D10 80103510 01000524 */   addiu     $a1, $zero, 0x1
    /* D14 80103514 1080023C */  lui        $v0, %hi(D_80104EC8)
    /* D18 80103518 970D0408 */  j          .L8010365C
    /* D1C 8010351C C84E40AC */   sw        $zero, %lo(D_80104EC8)($v0)
  .L80103520:
    /* D20 80103520 1080023C */  lui        $v0, %hi(D_80104EC8)
    /* D24 80103524 C84E438C */  lw         $v1, %lo(D_80104EC8)($v0)
    /* D28 80103528 00000000 */  nop
    /* D2C 8010352C 05006010 */  beqz       $v1, .L80103544
    /* D30 80103530 01000224 */   addiu     $v0, $zero, 0x1
    /* D34 80103534 41006210 */  beq        $v1, $v0, .L8010363C
    /* D38 80103538 21100000 */   addu      $v0, $zero, $zero
    /* D3C 8010353C 980D0408 */  j          .L80103660
    /* D40 80103540 00000000 */   nop
  .L80103544:
    /* D44 80103544 0F80023C */  lui        $v0, %hi(vs_battle_shortcutInvoked)
    /* D48 80103548 6A4E4290 */  lbu        $v0, %lo(vs_battle_shortcutInvoked)($v0)
    /* D4C 8010354C 00000000 */  nop
    /* D50 80103550 05004014 */  bnez       $v0, .L80103568
    /* D54 80103554 21380000 */   addu      $a3, $zero, $zero
    /* D58 80103558 74EA030C */  jal        vs_mainmenu_ready
    /* D5C 8010355C 00000000 */   nop
    /* D60 80103560 3E004010 */  beqz       $v0, .L8010365C
    /* D64 80103564 21380000 */   addu      $a3, $zero, $zero
  .L80103568:
    /* D68 80103568 2130E000 */  addu       $a2, $a3, $zero
    /* D6C 8010356C 0F80023C */  lui        $v0, %hi(vs_battle_chainAbilityOffsets)
    /* D70 80103570 BCBD5824 */  addiu      $t8, $v0, %lo(vs_battle_chainAbilityOffsets)
    /* D74 80103574 0580023C */  lui        $v0, %hi(vs_main_skills)
    /* D78 80103578 DCB94D24 */  addiu      $t5, $v0, %lo(vs_main_skills)
    /* D7C 8010357C 1C00AF25 */  addiu      $t7, $t5, 0x1C
    /* D80 80103580 1080023C */  lui        $v0, %hi(_battleAbilityStrings)
    /* D84 80103584 90464C24 */  addiu      $t4, $v0, %lo(_battleAbilityStrings)
    /* D88 80103588 1080023C */  lui        $v0, %hi(_unlockedChainAbilities)
    /* D8C 8010358C D0504E24 */  addiu      $t6, $v0, %lo(_unlockedChainAbilities)
    /* D90 80103590 0C000A24 */  addiu      $t2, $zero, 0xC
    /* D94 80103594 04000924 */  addiu      $t1, $zero, 0x4
    /* D98 80103598 1000AB27 */  addiu      $t3, $sp, 0x10
    /* D9C 8010359C 21406001 */  addu       $t0, $t3, $zero
  .L801035A0:
    /* DA0 801035A0 2110D800 */  addu       $v0, $a2, $t8
    /* DA4 801035A4 00004590 */  lbu        $a1, 0x0($v0)
    /* DA8 801035A8 00000000 */  nop
    /* DAC 801035AC 40100500 */  sll        $v0, $a1, 1
    /* DB0 801035B0 21104500 */  addu       $v0, $v0, $a1
    /* DB4 801035B4 80100200 */  sll        $v0, $v0, 2
    /* DB8 801035B8 21104500 */  addu       $v0, $v0, $a1
    /* DBC 801035BC 80180200 */  sll        $v1, $v0, 2
    /* DC0 801035C0 21106D00 */  addu       $v0, $v1, $t5
    /* DC4 801035C4 0C00428C */  lw         $v0, 0xC($v0)
    /* DC8 801035C8 00000000 */  nop
    /* DCC 801035CC C2130200 */  srl        $v0, $v0, 15
    /* DD0 801035D0 01004230 */  andi       $v0, $v0, 0x1
    /* DD4 801035D4 0D004010 */  beqz       $v0, .L8010360C
    /* DD8 801035D8 21206901 */   addu      $a0, $t3, $t1
    /* DDC 801035DC 08002925 */  addiu      $t1, $t1, 0x8
    /* DE0 801035E0 21106F00 */  addu       $v0, $v1, $t7
    /* DE4 801035E4 000002AD */  sw         $v0, 0x0($t0)
    /* DE8 801035E8 08000825 */  addiu      $t0, $t0, 0x8
    /* DEC 801035EC 21104C01 */  addu       $v0, $t2, $t4
    /* DF0 801035F0 2118EE00 */  addu       $v1, $a3, $t6
    /* DF4 801035F4 00004294 */  lhu        $v0, 0x0($v0)
    /* DF8 801035F8 0100E724 */  addiu      $a3, $a3, 0x1
    /* DFC 801035FC 40100200 */  sll        $v0, $v0, 1
    /* E00 80103600 21104C00 */  addu       $v0, $v0, $t4
    /* E04 80103604 000082AC */  sw         $v0, 0x0($a0)
    /* E08 80103608 000065A0 */  sb         $a1, 0x0($v1)
  .L8010360C:
    /* E0C 8010360C 0100C624 */  addiu      $a2, $a2, 0x1
    /* E10 80103610 0E00C228 */  slti       $v0, $a2, 0xE
    /* E14 80103614 E2FF4014 */  bnez       $v0, .L801035A0
    /* E18 80103618 02004A25 */   addiu     $t2, $t2, 0x2
    /* E1C 8010361C 2120E000 */  addu       $a0, $a3, $zero
    /* E20 80103620 18000524 */  addiu      $a1, $zero, 0x18
    /* E24 80103624 4A0A040C */  jal        _initAbilityMenu
    /* E28 80103628 1000A627 */   addiu     $a2, $sp, 0x10
    /* E2C 8010362C 1080033C */  lui        $v1, %hi(D_80104EC8)
    /* E30 80103630 01000224 */  addiu      $v0, $zero, 0x1
    /* E34 80103634 970D0408 */  j          .L8010365C
    /* E38 80103638 C84E62AC */   sw        $v0, %lo(D_80104EC8)($v1)
  .L8010363C:
    /* E3C 8010363C 2B0B040C */  jal        _abilityMenu
    /* E40 80103640 00000000 */   nop
    /* E44 80103644 06004010 */  beqz       $v0, .L80103660
    /* E48 80103648 21100000 */   addu      $v0, $zero, $zero
    /* E4C 8010364C 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* E50 80103650 02000424 */   addiu     $a0, $zero, 0x2
    /* E54 80103654 980D0408 */  j          .L80103660
    /* E58 80103658 01000224 */   addiu     $v0, $zero, 0x1
  .L8010365C:
    /* E5C 8010365C 21100000 */  addu       $v0, $zero, $zero
  .L80103660:
    /* E60 80103660 8000BF8F */  lw         $ra, 0x80($sp)
    /* E64 80103664 00000000 */  nop
    /* E68 80103668 0800E003 */  jr         $ra
    /* E6C 8010366C 8800BD27 */   addiu     $sp, $sp, 0x88
endlabel _chainAbilityMenu
