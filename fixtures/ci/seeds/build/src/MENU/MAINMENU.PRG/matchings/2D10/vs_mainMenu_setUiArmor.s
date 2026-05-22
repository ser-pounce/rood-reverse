nonmatching vs_mainMenu_setUiArmor, 0x1B8

glabel vs_mainMenu_setUiArmor
    /* 36CC 800FCECC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 36D0 800FCED0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 36D4 800FCED4 2190A000 */  addu       $s2, $a1, $zero
    /* 36D8 800FCED8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 36DC 800FCEDC 21888000 */  addu       $s1, $a0, $zero
    /* 36E0 800FCEE0 1080043C */  lui        $a0, %hi(vs_mainMenu_itemNames)
    /* 36E4 800FCEE4 2000BFAF */  sw         $ra, 0x20($sp)
    /* 36E8 800FCEE8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 36EC 800FCEEC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 36F0 800FCEF0 00002396 */  lhu        $v1, 0x0($s1)
    /* 36F4 800FCEF4 00000000 */  nop
    /* 36F8 800FCEF8 40100300 */  sll        $v0, $v1, 1
    /* 36FC 800FCEFC 21104300 */  addu       $v0, $v0, $v1
    /* 3700 800FCF00 9C22838C */  lw         $v1, %lo(vs_mainMenu_itemNames)($a0)
    /* 3704 800FCF04 C0100200 */  sll        $v0, $v0, 3
    /* 3708 800FCF08 21186200 */  addu       $v1, $v1, $v0
    /* 370C 800FCF0C 000043AE */  sw         $v1, 0x0($s2)
    /* 3710 800FCF10 04002292 */  lbu        $v0, 0x4($s1)
    /* 3714 800FCF14 13002392 */  lbu        $v1, 0x13($s1)
    /* 3718 800FCF18 0E004224 */  addiu      $v0, $v0, 0xE
    /* 371C 800FCF1C 80160200 */  sll        $v0, $v0, 26
    /* 3720 800FCF20 001C0300 */  sll        $v1, $v1, 16
    /* 3724 800FCF24 21104300 */  addu       $v0, $v0, $v1
    /* 3728 800FCF28 0000C2AC */  sw         $v0, 0x0($a2)
    /* 372C 800FCF2C 04002392 */  lbu        $v1, 0x4($s1)
    /* 3730 800FCF30 07000224 */  addiu      $v0, $zero, 0x7
    /* 3734 800FCF34 0C006214 */  bne        $v1, $v0, .L800FCF68
    /* 3738 800FCF38 2198E000 */   addu      $s3, $a3, $zero
    /* 373C 800FCF3C 1080033C */  lui        $v1, %hi(vs_mainMenu_itemHelp)
    /* 3740 800FCF40 00002296 */  lhu        $v0, 0x0($s1)
    /* 3744 800FCF44 4025638C */  lw         $v1, %lo(vs_mainMenu_itemHelp)($v1)
    /* 3748 800FCF48 40100200 */  sll        $v0, $v0, 1
    /* 374C 800FCF4C 21104300 */  addu       $v0, $v0, $v1
    /* 3750 800FCF50 06034294 */  lhu        $v0, 0x306($v0)
    /* 3754 800FCF54 00000000 */  nop
    /* 3758 800FCF58 40100200 */  sll        $v0, $v0, 1
    /* 375C 800FCF5C 21186200 */  addu       $v1, $v1, $v0
    /* 3760 800FCF60 1AF40308 */  j          .L800FD068
    /* 3764 800FCF64 040043AE */   sw        $v1, 0x4($s2)
  .L800FCF68:
    /* 3768 800FCF68 21202002 */  addu       $a0, $s1, $zero
    /* 376C 800FCF6C 66E9030C */  jal        vs_mainMenu_getEquipmentMaxStats
    /* 3770 800FCF70 02000524 */   addiu     $a1, $zero, 0x2
    /* 3774 800FCF74 21304000 */  addu       $a2, $v0, $zero
    /* 3778 800FCF78 0F80043C */  lui        $a0, %hi(vs_battle_stringContext)
    /* 377C 800FCF7C 1080033C */  lui        $v1, %hi(vs_mainMenu_itemHelp)
    /* 3780 800FCF80 FF00C230 */  andi       $v0, $a2, 0xFF
    /* 3784 800FCF84 40100200 */  sll        $v0, $v0, 1
    /* 3788 800FCF88 4025658C */  lw         $a1, %lo(vs_mainMenu_itemHelp)($v1)
    /* 378C 800FCF8C 68518424 */  addiu      $a0, $a0, %lo(vs_battle_stringContext)
    /* 3790 800FCF90 21104500 */  addu       $v0, $v0, $a1
    /* 3794 800FCF94 E8024294 */  lhu        $v0, 0x2E8($v0)
    /* 3798 800FCF98 00000000 */  nop
    /* 379C 800FCF9C 40100200 */  sll        $v0, $v0, 1
    /* 37A0 800FCFA0 2110A200 */  addu       $v0, $a1, $v0
    /* 37A4 800FCFA4 280082AC */  sw         $v0, 0x28($a0)
    /* 37A8 800FCFA8 03120600 */  sra        $v0, $a2, 8
    /* 37AC 800FCFAC FF004330 */  andi       $v1, $v0, 0xFF
    /* 37B0 800FCFB0 08006010 */  beqz       $v1, .L800FCFD4
    /* 37B4 800FCFB4 21388000 */   addu      $a3, $a0, $zero
    /* 37B8 800FCFB8 C3130600 */  sra        $v0, $a2, 15
    /* 37BC 800FCFBC 21106200 */  addu       $v0, $v1, $v0
    /* 37C0 800FCFC0 40100200 */  sll        $v0, $v0, 1
    /* 37C4 800FCFC4 21104500 */  addu       $v0, $v0, $a1
    /* 37C8 800FCFC8 8E044294 */  lhu        $v0, 0x48E($v0)
    /* 37CC 800FCFCC FCF30308 */  j          .L800FCFF0
    /* 37D0 800FCFD0 40100200 */   sll       $v0, $v0, 1
  .L800FCFD4:
    /* 37D4 800FCFD4 04002292 */  lbu        $v0, 0x4($s1)
    /* 37D8 800FCFD8 00000000 */  nop
    /* 37DC 800FCFDC 40100200 */  sll        $v0, $v0, 1
    /* 37E0 800FCFE0 21104500 */  addu       $v0, $v0, $a1
    /* 37E4 800FCFE4 0E034294 */  lhu        $v0, 0x30E($v0)
    /* 37E8 800FCFE8 00000000 */  nop
    /* 37EC 800FCFEC 40100200 */  sll        $v0, $v0, 1
  .L800FCFF0:
    /* 37F0 800FCFF0 2110A200 */  addu       $v0, $a1, $v0
    /* 37F4 800FCFF4 1080103C */  lui        $s0, %hi(vs_mainMenu_itemHelp)
    /* 37F8 800FCFF8 21206002 */  addu       $a0, $s3, $zero
    /* 37FC 800FCFFC 0F80063C */  lui        $a2, %hi(vs_battle_stringContext)
    /* 3800 800FD000 6851C624 */  addiu      $a2, $a2, %lo(vs_battle_stringContext)
    /* 3804 800FD004 2C00E2AC */  sw         $v0, 0x2C($a3)
    /* 3808 800FD008 04002292 */  lbu        $v0, 0x4($s1)
    /* 380C 800FD00C 4025038E */  lw         $v1, %lo(vs_mainMenu_itemHelp)($s0)
    /* 3810 800FD010 40100200 */  sll        $v0, $v0, 1
    /* 3814 800FD014 21104300 */  addu       $v0, $v0, $v1
    /* 3818 800FD018 08054294 */  lhu        $v0, 0x508($v0)
    /* 381C 800FD01C EA676524 */  addiu      $a1, $v1, 0x67EA
    /* 3820 800FD020 40100200 */  sll        $v0, $v0, 1
    /* 3824 800FD024 21186200 */  addu       $v1, $v1, $v0
    /* 3828 800FD028 4800C3AC */  sw         $v1, 0x48($a2)
    /* 382C 800FD02C 13002392 */  lbu        $v1, 0x13($s1)
    /* 3830 800FD030 1080073C */  lui        $a3, %hi(vs_mainMenu_itemNames)
    /* 3834 800FD034 40100300 */  sll        $v0, $v1, 1
    /* 3838 800FD038 21104300 */  addu       $v0, $v0, $v1
    /* 383C 800FD03C C0100200 */  sll        $v0, $v0, 3
    /* 3840 800FD040 9C22E38C */  lw         $v1, %lo(vs_mainMenu_itemNames)($a3)
    /* 3844 800FD044 B8174224 */  addiu      $v0, $v0, 0x17B8
    /* 3848 800FD048 21186200 */  addu       $v1, $v1, $v0
    /* 384C 800FD04C 171A030C */  jal        vs_battle_printf
    /* 3850 800FD050 4C00C3AC */   sw        $v1, 0x4C($a2)
    /* 3854 800FD054 4025058E */  lw         $a1, %lo(vs_mainMenu_itemHelp)($s0)
    /* 3858 800FD058 21204000 */  addu       $a0, $v0, $zero
    /* 385C 800FD05C 171A030C */  jal        vs_battle_printf
    /* 3860 800FD060 0E68A524 */   addiu     $a1, $a1, 0x680E
    /* 3864 800FD064 040053AE */  sw         $s3, 0x4($s2)
  .L800FD068:
    /* 3868 800FD068 2000BF8F */  lw         $ra, 0x20($sp)
    /* 386C 800FD06C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3870 800FD070 1800B28F */  lw         $s2, 0x18($sp)
    /* 3874 800FD074 1400B18F */  lw         $s1, 0x14($sp)
    /* 3878 800FD078 1000B08F */  lw         $s0, 0x10($sp)
    /* 387C 800FD07C 0800E003 */  jr         $ra
    /* 3880 800FD080 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel vs_mainMenu_setUiArmor
