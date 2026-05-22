nonmatching vs_mainMenu_setUiShield, 0x158

glabel vs_mainMenu_setUiShield
    /* 34E8 800FCCE8 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 34EC 800FCCEC 2000B4AF */  sw         $s4, 0x20($sp)
    /* 34F0 800FCCF0 21A0A000 */  addu       $s4, $a1, $zero
    /* 34F4 800FCCF4 2400B5AF */  sw         $s5, 0x24($sp)
    /* 34F8 800FCCF8 21A8C000 */  addu       $s5, $a2, $zero
    /* 34FC 800FCCFC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3500 800FCD00 2198E000 */  addu       $s3, $a3, $zero
    /* 3504 800FCD04 01000524 */  addiu      $a1, $zero, 0x1
    /* 3508 800FCD08 1800B2AF */  sw         $s2, 0x18($sp)
    /* 350C 800FCD0C 18009224 */  addiu      $s2, $a0, 0x18
    /* 3510 800FCD10 2800BFAF */  sw         $ra, 0x28($sp)
    /* 3514 800FCD14 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3518 800FCD18 66E9030C */  jal        vs_mainMenu_getEquipmentMaxStats
    /* 351C 800FCD1C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 3520 800FCD20 21304000 */  addu       $a2, $v0, $zero
    /* 3524 800FCD24 0F80043C */  lui        $a0, %hi(vs_battle_stringContext)
    /* 3528 800FCD28 1080033C */  lui        $v1, %hi(vs_mainMenu_itemHelp)
    /* 352C 800FCD2C FF00C230 */  andi       $v0, $a2, 0xFF
    /* 3530 800FCD30 40100200 */  sll        $v0, $v0, 1
    /* 3534 800FCD34 4025658C */  lw         $a1, %lo(vs_mainMenu_itemHelp)($v1)
    /* 3538 800FCD38 68518424 */  addiu      $a0, $a0, %lo(vs_battle_stringContext)
    /* 353C 800FCD3C 21104500 */  addu       $v0, $v0, $a1
    /* 3540 800FCD40 E8024294 */  lhu        $v0, 0x2E8($v0)
    /* 3544 800FCD44 00000000 */  nop
    /* 3548 800FCD48 40100200 */  sll        $v0, $v0, 1
    /* 354C 800FCD4C 2110A200 */  addu       $v0, $a1, $v0
    /* 3550 800FCD50 280082AC */  sw         $v0, 0x28($a0)
    /* 3554 800FCD54 03120600 */  sra        $v0, $a2, 8
    /* 3558 800FCD58 FF004330 */  andi       $v1, $v0, 0xFF
    /* 355C 800FCD5C 0A006010 */  beqz       $v1, .L800FCD88
    /* 3560 800FCD60 21388000 */   addu      $a3, $a0, $zero
    /* 3564 800FCD64 C3130600 */  sra        $v0, $a2, 15
    /* 3568 800FCD68 21106200 */  addu       $v0, $v1, $v0
    /* 356C 800FCD6C 40100200 */  sll        $v0, $v0, 1
    /* 3570 800FCD70 21104500 */  addu       $v0, $v0, $a1
    /* 3574 800FCD74 8E044294 */  lhu        $v0, 0x48E($v0)
    /* 3578 800FCD78 00000000 */  nop
    /* 357C 800FCD7C 40100200 */  sll        $v0, $v0, 1
    /* 3580 800FCD80 63F30308 */  j          .L800FCD8C
    /* 3584 800FCD84 2118A200 */   addu      $v1, $a1, $v0
  .L800FCD88:
    /* 3588 800FCD88 F24CA324 */  addiu      $v1, $a1, 0x4CF2
  .L800FCD8C:
    /* 358C 800FCD8C 1080113C */  lui        $s1, %hi(vs_mainMenu_itemHelp)
    /* 3590 800FCD90 21206002 */  addu       $a0, $s3, $zero
    /* 3594 800FCD94 0F80063C */  lui        $a2, %hi(vs_battle_stringContext)
    /* 3598 800FCD98 4025228E */  lw         $v0, %lo(vs_mainMenu_itemHelp)($s1)
    /* 359C 800FCD9C 6851C624 */  addiu      $a2, $a2, %lo(vs_battle_stringContext)
    /* 35A0 800FCDA0 2C00E3AC */  sw         $v1, 0x2C($a3)
    /* 35A4 800FCDA4 EA674524 */  addiu      $a1, $v0, 0x67EA
    /* 35A8 800FCDA8 9A674224 */  addiu      $v0, $v0, 0x679A
    /* 35AC 800FCDAC 4800C2AC */  sw         $v0, 0x48($a2)
    /* 35B0 800FCDB0 13004392 */  lbu        $v1, 0x13($s2)
    /* 35B4 800FCDB4 1080103C */  lui        $s0, %hi(vs_mainMenu_itemNames)
    /* 35B8 800FCDB8 40100300 */  sll        $v0, $v1, 1
    /* 35BC 800FCDBC 21104300 */  addu       $v0, $v0, $v1
    /* 35C0 800FCDC0 C0100200 */  sll        $v0, $v0, 3
    /* 35C4 800FCDC4 9C22038E */  lw         $v1, %lo(vs_mainMenu_itemNames)($s0)
    /* 35C8 800FCDC8 B8174224 */  addiu      $v0, $v0, 0x17B8
    /* 35CC 800FCDCC 21186200 */  addu       $v1, $v1, $v0
    /* 35D0 800FCDD0 171A030C */  jal        vs_battle_printf
    /* 35D4 800FCDD4 4C00C3AC */   sw        $v1, 0x4C($a2)
    /* 35D8 800FCDD8 4025258E */  lw         $a1, %lo(vs_mainMenu_itemHelp)($s1)
    /* 35DC 800FCDDC 21204000 */  addu       $a0, $v0, $zero
    /* 35E0 800FCDE0 171A030C */  jal        vs_battle_printf
    /* 35E4 800FCDE4 0E68A524 */   addiu     $a1, $a1, 0x680E
    /* 35E8 800FCDE8 00004396 */  lhu        $v1, 0x0($s2)
    /* 35EC 800FCDEC 040093AE */  sw         $s3, 0x4($s4)
    /* 35F0 800FCDF0 40100300 */  sll        $v0, $v1, 1
    /* 35F4 800FCDF4 21104300 */  addu       $v0, $v0, $v1
    /* 35F8 800FCDF8 9C22038E */  lw         $v1, %lo(vs_mainMenu_itemNames)($s0)
    /* 35FC 800FCDFC C0100200 */  sll        $v0, $v0, 3
    /* 3600 800FCE00 21186200 */  addu       $v1, $v1, $v0
    /* 3604 800FCE04 000083AE */  sw         $v1, 0x0($s4)
    /* 3608 800FCE08 13004292 */  lbu        $v0, 0x13($s2)
    /* 360C 800FCE0C 003C033C */  lui        $v1, (0x3C000000 >> 16)
    /* 3610 800FCE10 00140200 */  sll        $v0, $v0, 16
    /* 3614 800FCE14 21104300 */  addu       $v0, $v0, $v1
    /* 3618 800FCE18 0000A2AE */  sw         $v0, 0x0($s5)
    /* 361C 800FCE1C 2800BF8F */  lw         $ra, 0x28($sp)
    /* 3620 800FCE20 2400B58F */  lw         $s5, 0x24($sp)
    /* 3624 800FCE24 2000B48F */  lw         $s4, 0x20($sp)
    /* 3628 800FCE28 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 362C 800FCE2C 1800B28F */  lw         $s2, 0x18($sp)
    /* 3630 800FCE30 1400B18F */  lw         $s1, 0x14($sp)
    /* 3634 800FCE34 1000B08F */  lw         $s0, 0x10($sp)
    /* 3638 800FCE38 0800E003 */  jr         $ra
    /* 363C 800FCE3C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel vs_mainMenu_setUiShield
