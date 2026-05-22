nonmatching func_8007B63C, 0x128

glabel func_8007B63C
    /* 12E3C 8007B63C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 12E40 8007B640 1000B0AF */  sw         $s0, 0x10($sp)
    /* 12E44 8007B644 0F80103C */  lui        $s0, %hi(D_800F19CC)
    /* 12E48 8007B648 CC19048E */  lw         $a0, %lo(D_800F19CC)($s0)
    /* 12E4C 8007B64C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 12E50 8007B650 1400B1AF */  sw         $s1, 0x14($sp)
    /* 12E54 8007B654 08008294 */  lhu        $v0, 0x8($a0)
    /* 12E58 8007B658 00000000 */  nop
    /* 12E5C 8007B65C 32004010 */  beqz       $v0, .L8007B728
    /* 12E60 8007B660 0580023C */   lui       $v0, %hi(vs_main_skills)
    /* 12E64 8007B664 08008394 */  lhu        $v1, 0x8($a0)
    /* 12E68 8007B668 DCB95124 */  addiu      $s1, $v0, %lo(vs_main_skills)
    /* 12E6C 8007B66C 40100300 */  sll        $v0, $v1, 1
    /* 12E70 8007B670 21104300 */  addu       $v0, $v0, $v1
    /* 12E74 8007B674 80100200 */  sll        $v0, $v0, 2
    /* 12E78 8007B678 21104300 */  addu       $v0, $v0, $v1
    /* 12E7C 8007B67C 80100200 */  sll        $v0, $v0, 2
    /* 12E80 8007B680 21105100 */  addu       $v0, $v0, $s1
    /* 12E84 8007B684 0C00428C */  lw         $v0, 0xC($v0)
    /* 12E88 8007B688 00000000 */  nop
    /* 12E8C 8007B68C C2130200 */  srl        $v0, $v0, 15
    /* 12E90 8007B690 01004230 */  andi       $v0, $v0, 0x1
    /* 12E94 8007B694 24004014 */  bnez       $v0, .L8007B728
    /* 12E98 8007B698 00000000 */   nop
    /* 12E9C 8007B69C 4C00828C */  lw         $v0, 0x4C($a0)
    /* 12EA0 8007B6A0 00000000 */  nop
    /* 12EA4 8007B6A4 20004014 */  bnez       $v0, .L8007B728
    /* 12EA8 8007B6A8 00000000 */   nop
    /* 12EAC 8007B6AC 072C8290 */  lbu        $v0, 0x2C07($a0)
    /* 12EB0 8007B6B0 00000000 */  nop
    /* 12EB4 8007B6B4 1C004014 */  bnez       $v0, .L8007B728
    /* 12EB8 8007B6B8 00000000 */   nop
    /* 12EBC 8007B6BC 0C008290 */  lbu        $v0, 0xC($a0)
    /* 12EC0 8007B6C0 00000000 */  nop
    /* 12EC4 8007B6C4 18004014 */  bnez       $v0, .L8007B728
    /* 12EC8 8007B6C8 0F80033C */   lui       $v1, %hi(_cameraMode)
    /* 12ECC 8007B6CC 06000224 */  addiu      $v0, $zero, 0x6
    /* 12ED0 8007B6D0 04ED010C */  jal        func_8007B410
    /* 12ED4 8007B6D4 F01862AC */   sw        $v0, %lo(_cameraMode)($v1)
    /* 12ED8 8007B6D8 CC19028E */  lw         $v0, %lo(D_800F19CC)($s0)
    /* 12EDC 8007B6DC 0C000424 */  addiu      $a0, $zero, 0xC
    /* 12EE0 8007B6E0 08004594 */  lhu        $a1, 0x8($v0)
    /* 12EE4 8007B6E4 AE2C030C */  jal        vs_battle_displaySceneMessage
    /* 12EE8 8007B6E8 01000624 */   addiu     $a2, $zero, 0x1
    /* 12EEC 8007B6EC CC19028E */  lw         $v0, %lo(D_800F19CC)($s0)
    /* 12EF0 8007B6F0 00000000 */  nop
    /* 12EF4 8007B6F4 08004394 */  lhu        $v1, 0x8($v0)
    /* 12EF8 8007B6F8 00000000 */  nop
    /* 12EFC 8007B6FC 40100300 */  sll        $v0, $v1, 1
    /* 12F00 8007B700 21104300 */  addu       $v0, $v0, $v1
    /* 12F04 8007B704 80100200 */  sll        $v0, $v0, 2
    /* 12F08 8007B708 21104300 */  addu       $v0, $v0, $v1
    /* 12F0C 8007B70C 80100200 */  sll        $v0, $v0, 2
    /* 12F10 8007B710 21105100 */  addu       $v0, $v0, $s1
    /* 12F14 8007B714 0C00438C */  lw         $v1, 0xC($v0)
    /* 12F18 8007B718 00000000 */  nop
    /* 12F1C 8007B71C 00806334 */  ori        $v1, $v1, 0x8000
    /* 12F20 8007B720 D4ED0108 */  j          .L8007B750
    /* 12F24 8007B724 0C0043AC */   sw        $v1, 0xC($v0)
  .L8007B728:
    /* 12F28 8007B728 D8BD010C */  jal        _isArtOrAbilityUnlocked
    /* 12F2C 8007B72C 00000000 */   nop
    /* 12F30 8007B730 0F80033C */  lui        $v1, %hi(_cameraMode)
    /* 12F34 8007B734 06000424 */  addiu      $a0, $zero, 0x6
    /* 12F38 8007B738 F01864AC */  sw         $a0, %lo(_cameraMode)($v1)
    /* 12F3C 8007B73C 04ED010C */  jal        func_8007B410
    /* 12F40 8007B740 21804000 */   addu      $s0, $v0, $zero
    /* 12F44 8007B744 02241000 */  srl        $a0, $s0, 16
    /* 12F48 8007B748 822C030C */  jal        func_800CB208
    /* 12F4C 8007B74C FFFF0532 */   andi      $a1, $s0, 0xFFFF
  .L8007B750:
    /* 12F50 8007B750 1800BF8F */  lw         $ra, 0x18($sp)
    /* 12F54 8007B754 1400B18F */  lw         $s1, 0x14($sp)
    /* 12F58 8007B758 1000B08F */  lw         $s0, 0x10($sp)
    /* 12F5C 8007B75C 0800E003 */  jr         $ra
    /* 12F60 8007B760 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007B63C
