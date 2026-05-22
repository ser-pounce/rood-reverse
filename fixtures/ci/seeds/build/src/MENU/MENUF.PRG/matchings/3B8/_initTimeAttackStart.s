nonmatching _initTimeAttackStart, 0x218

glabel _initTimeAttackStart
    /* D30 80103530 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* D34 80103534 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* D38 80103538 0F80113C */  lui        $s1, %hi(_submenuState)
    /* D3C 8010353C D81C238E */  lw         $v1, %lo(_submenuState)($s1)
    /* D40 80103540 3800BFAF */  sw         $ra, 0x38($sp)
    /* D44 80103544 3400B3AF */  sw         $s3, 0x34($sp)
    /* D48 80103548 3000B2AF */  sw         $s2, 0x30($sp)
    /* D4C 8010354C 18006014 */  bnez       $v1, .L801035B0
    /* D50 80103550 2800B0AF */   sw        $s0, 0x28($sp)
    /* D54 80103554 1D000424 */  addiu      $a0, $zero, 0x1D
    /* D58 80103558 02000524 */  addiu      $a1, $zero, 0x2
    /* D5C 8010355C FCF7010C */  jal        func_8007DFF0
    /* D60 80103560 05000624 */   addiu     $a2, $zero, 0x5
    /* D64 80103564 1080103C */  lui        $s0, %hi(_disFiles)
    /* D68 80103568 E02A1026 */  addiu      $s0, $s0, %lo(_disFiles)
    /* D6C 8010356C 1400048E */  lw         $a0, 0x14($s0)
    /* D70 80103570 8F0F010C */  jal        vs_main_allocHeapR
    /* D74 80103574 00000000 */   nop
    /* D78 80103578 10000426 */  addiu      $a0, $s0, 0x10
    /* D7C 8010357C 1180103C */  lui        $s0, %hi(_attackDisData)
    /* D80 80103580 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* D84 80103584 609802AE */   sw        $v0, %lo(_attackDisData)($s0)
    /* D88 80103588 21204000 */  addu       $a0, $v0, $zero
    /* D8C 8010358C 6098058E */  lw         $a1, %lo(_attackDisData)($s0)
    /* D90 80103590 1180023C */  lui        $v0, %hi(_attackDisCdSlot)
    /* D94 80103594 F112010C */  jal        vs_main_cdEnqueue
    /* D98 80103598 5C9844AC */   sw        $a0, %lo(_attackDisCdSlot)($v0)
    /* D9C 8010359C D81C228E */  lw         $v0, %lo(_submenuState)($s1)
    /* DA0 801035A0 00000000 */  nop
    /* DA4 801035A4 01004224 */  addiu      $v0, $v0, 0x1
    /* DA8 801035A8 CA0D0408 */  j          .L80103728
    /* DAC 801035AC D81C22AE */   sw        $v0, %lo(_submenuState)($s1)
  .L801035B0:
    /* DB0 801035B0 01000224 */  addiu      $v0, $zero, 0x1
    /* DB4 801035B4 4A006214 */  bne        $v1, $v0, .L801036E0
    /* DB8 801035B8 1180023C */   lui       $v0, %hi(_attackDisData)
    /* DBC 801035BC 1180023C */  lui        $v0, %hi(_attackDisCdSlot)
    /* DC0 801035C0 5C98428C */  lw         $v0, %lo(_attackDisCdSlot)($v0)
    /* DC4 801035C4 00000000 */  nop
    /* DC8 801035C8 00004384 */  lh         $v1, 0x0($v0)
    /* DCC 801035CC 04000224 */  addiu      $v0, $zero, 0x4
    /* DD0 801035D0 56006214 */  bne        $v1, $v0, .L8010372C
    /* DD4 801035D4 21100000 */   addu      $v0, $zero, $zero
    /* DD8 801035D8 21800000 */  addu       $s0, $zero, $zero
    /* DDC 801035DC 1180133C */  lui        $s3, %hi(_attackDisData)
    /* DE0 801035E0 40031224 */  addiu      $s2, $zero, 0x340
    /* DE4 801035E4 21880002 */  addu       $s1, $s0, $zero
  .L801035E8:
    /* DE8 801035E8 6098648E */  lw         $a0, %lo(_attackDisData)($s3)
    /* DEC 801035EC 1000A527 */  addiu      $a1, $sp, 0x10
    /* DF0 801035F0 0836020C */  jal        vs_battle_setTimImage
    /* DF4 801035F4 21209100 */   addu      $a0, $a0, $s1
    /* DF8 801035F8 2000A28F */  lw         $v0, 0x20($sp)
    /* DFC 801035FC 00000000 */  nop
    /* E00 80103600 0E004010 */  beqz       $v0, .L8010363C
    /* E04 80103604 00000000 */   nop
    /* E08 80103608 1C00A28F */  lw         $v0, 0x1C($sp)
    /* E0C 8010360C 00000000 */  nop
    /* E10 80103610 000052A4 */  sh         $s2, 0x0($v0)
    /* E14 80103614 1C00A38F */  lw         $v1, 0x1C($sp)
    /* E18 80103618 00010224 */  addiu      $v0, $zero, 0x100
    /* E1C 8010361C 020062A4 */  sh         $v0, 0x2($v1)
    /* E20 80103620 1C00A38F */  lw         $v1, 0x1C($sp)
    /* E24 80103624 FF000224 */  addiu      $v0, $zero, 0xFF
    /* E28 80103628 060062A4 */  sh         $v0, 0x6($v1)
    /* E2C 8010362C 1C00A48F */  lw         $a0, 0x1C($sp)
    /* E30 80103630 2000A58F */  lw         $a1, 0x20($sp)
    /* E34 80103634 3FA2000C */  jal        LoadImage
    /* E38 80103638 00000000 */   nop
  .L8010363C:
    /* E3C 8010363C 19000016 */  bnez       $s0, .L801036A4
    /* E40 80103640 20820234 */   ori       $v0, $zero, 0x8220
    /* E44 80103644 1800A28F */  lw         $v0, 0x18($sp)
    /* E48 80103648 00000000 */  nop
    /* E4C 8010364C 14004010 */  beqz       $v0, .L801036A0
    /* E50 80103650 00030224 */   addiu     $v0, $zero, 0x300
    /* E54 80103654 1400A38F */  lw         $v1, 0x14($sp)
    /* E58 80103658 00000000 */  nop
    /* E5C 8010365C 000062A4 */  sh         $v0, 0x0($v1)
    /* E60 80103660 1400A38F */  lw         $v1, 0x14($sp)
    /* E64 80103664 FF010224 */  addiu      $v0, $zero, 0x1FF
    /* E68 80103668 020062A4 */  sh         $v0, 0x2($v1)
    /* E6C 8010366C 1400A38F */  lw         $v1, 0x14($sp)
    /* E70 80103670 A0000224 */  addiu      $v0, $zero, 0xA0
    /* E74 80103674 040062A4 */  sh         $v0, 0x4($v1)
    /* E78 80103678 1400A38F */  lw         $v1, 0x14($sp)
    /* E7C 8010367C 01000224 */  addiu      $v0, $zero, 0x1
    /* E80 80103680 060062A4 */  sh         $v0, 0x6($v1)
    /* E84 80103684 1800A28F */  lw         $v0, 0x18($sp)
    /* E88 80103688 00000000 */  nop
    /* E8C 8010368C 000040AC */  sw         $zero, 0x0($v0)
    /* E90 80103690 1400A48F */  lw         $a0, 0x14($sp)
    /* E94 80103694 1800A58F */  lw         $a1, 0x18($sp)
    /* E98 80103698 3FA2000C */  jal        LoadImage
    /* E9C 8010369C 00000000 */   nop
  .L801036A0:
    /* EA0 801036A0 20820234 */  ori        $v0, $zero, 0x8220
  .L801036A4:
    /* EA4 801036A4 21882202 */  addu       $s1, $s1, $v0
    /* EA8 801036A8 01001026 */  addiu      $s0, $s0, 0x1
    /* EAC 801036AC 0200022A */  slti       $v0, $s0, 0x2
    /* EB0 801036B0 CDFF4014 */  bnez       $v0, .L801035E8
    /* EB4 801036B4 40005226 */   addiu     $s2, $s2, 0x40
    /* EB8 801036B8 1180023C */  lui        $v0, %hi(_attackDisCdSlot)
    /* EBC 801036BC 5C98448C */  lw         $a0, %lo(_attackDisCdSlot)($v0)
    /* EC0 801036C0 E012010C */  jal        vs_main_freeCdQueueSlot
    /* EC4 801036C4 00000000 */   nop
    /* EC8 801036C8 0F80033C */  lui        $v1, %hi(_submenuState)
    /* ECC 801036CC D81C628C */  lw         $v0, %lo(_submenuState)($v1)
    /* ED0 801036D0 00000000 */  nop
    /* ED4 801036D4 01004224 */  addiu      $v0, $v0, 0x1
    /* ED8 801036D8 CA0D0408 */  j          .L80103728
    /* EDC 801036DC D81C62AC */   sw        $v0, %lo(_submenuState)($v1)
  .L801036E0:
    /* EE0 801036E0 6098448C */  lw         $a0, %lo(_attackDisData)($v0)
    /* EE4 801036E4 180F010C */  jal        vs_main_freeHeapR
    /* EE8 801036E8 00000000 */   nop
    /* EEC 801036EC 01000224 */  addiu      $v0, $zero, 0x1
    /* EF0 801036F0 1180033C */  lui        $v1, %hi(D_80109894)
    /* EF4 801036F4 949860AC */  sw         $zero, %lo(D_80109894)($v1)
    /* EF8 801036F8 1180033C */  lui        $v1, %hi(D_80109898)
    /* EFC 801036FC 989860AC */  sw         $zero, %lo(D_80109898)($v1)
    /* F00 80103700 1180033C */  lui        $v1, %hi(D_8010989C)
    /* F04 80103704 9C9860AC */  sw         $zero, %lo(D_8010989C)($v1)
    /* F08 80103708 1180033C */  lui        $v1, %hi(D_801098A0)
    /* F0C 8010370C A09860AC */  sw         $zero, %lo(D_801098A0)($v1)
    /* F10 80103710 1180033C */  lui        $v1, %hi(D_8010988C)
    /* F14 80103714 8C9860AC */  sw         $zero, %lo(D_8010988C)($v1)
    /* F18 80103718 1180033C */  lui        $v1, %hi(_buffReelSelection)
    /* F1C 8010371C 789860AC */  sw         $zero, %lo(_buffReelSelection)($v1)
    /* F20 80103720 CB0D0408 */  j          .L8010372C
    /* F24 80103724 D81C20AE */   sw        $zero, %lo(_submenuState)($s1)
  .L80103728:
    /* F28 80103728 21100000 */  addu       $v0, $zero, $zero
  .L8010372C:
    /* F2C 8010372C 3800BF8F */  lw         $ra, 0x38($sp)
    /* F30 80103730 3400B38F */  lw         $s3, 0x34($sp)
    /* F34 80103734 3000B28F */  lw         $s2, 0x30($sp)
    /* F38 80103738 2C00B18F */  lw         $s1, 0x2C($sp)
    /* F3C 8010373C 2800B08F */  lw         $s0, 0x28($sp)
    /* F40 80103740 0800E003 */  jr         $ra
    /* F44 80103744 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel _initTimeAttackStart
