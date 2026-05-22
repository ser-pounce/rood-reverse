nonmatching _drawFileMenuElement, 0x6D8

glabel _drawFileMenuElement
    /* 2DA0 8006B5A0 C8FDBD27 */  addiu      $sp, $sp, -0x238
    /* 2DA4 8006B5A4 2402B3AF */  sw         $s3, 0x224($sp)
    /* 2DA8 8006B5A8 21988000 */  addu       $s3, $a0, $zero
    /* 2DAC 8006B5AC 3002BFAF */  sw         $ra, 0x230($sp)
    /* 2DB0 8006B5B0 2C02B5AF */  sw         $s5, 0x22C($sp)
    /* 2DB4 8006B5B4 2802B4AF */  sw         $s4, 0x228($sp)
    /* 2DB8 8006B5B8 2002B2AF */  sw         $s2, 0x220($sp)
    /* 2DBC 8006B5BC 1C02B1AF */  sw         $s1, 0x21C($sp)
    /* 2DC0 8006B5C0 1802B0AF */  sw         $s0, 0x218($sp)
    /* 2DC4 8006B5C4 04006292 */  lbu        $v0, 0x4($s3)
    /* 2DC8 8006B5C8 00000000 */  nop
    /* 2DCC 8006B5CC 05004014 */  bnez       $v0, .L8006B5E4
    /* 2DD0 8006B5D0 08000224 */   addiu     $v0, $zero, 0x8
    /* 2DD4 8006B5D4 02006292 */  lbu        $v0, 0x2($s3)
    /* 2DD8 8006B5D8 00000000 */  nop
    /* 2DDC 8006B5DC 02004010 */  beqz       $v0, .L8006B5E8
    /* 2DE0 8006B5E0 FFFF4224 */   addiu     $v0, $v0, -0x1
  .L8006B5E4:
    /* 2DE4 8006B5E4 020062A2 */  sb         $v0, 0x2($s3)
  .L8006B5E8:
    /* 2DE8 8006B5E8 05006292 */  lbu        $v0, 0x5($s3)
    /* 2DEC 8006B5EC 00000000 */  nop
    /* 2DF0 8006B5F0 02004010 */  beqz       $v0, .L8006B5FC
    /* 2DF4 8006B5F4 00000000 */   nop
    /* 2DF8 8006B5F8 020060A2 */  sb         $zero, 0x2($s3)
  .L8006B5FC:
    /* 2DFC 8006B5FC 01006292 */  lbu        $v0, 0x1($s3)
    /* 2E00 8006B600 00000000 */  nop
    /* 2E04 8006B604 0500422C */  sltiu      $v0, $v0, 0x5
    /* 2E08 8006B608 07004010 */  beqz       $v0, .L8006B628
    /* 2E0C 8006B60C 08000424 */   addiu     $a0, $zero, 0x8
    /* 2E10 8006B610 0E006286 */  lh         $v0, 0xE($s3)
    /* 2E14 8006B614 00000000 */  nop
    /* 2E18 8006B618 B8FF4224 */  addiu      $v0, $v0, -0x48
    /* 2E1C 8006B61C 5100422C */  sltiu      $v0, $v0, 0x51
    /* 2E20 8006B620 8C014010 */  beqz       $v0, .L8006BC54
    /* 2E24 8006B624 00000000 */   nop
  .L8006B628:
    /* 2E28 8006B628 02006292 */  lbu        $v0, 0x2($s3)
    /* 2E2C 8006B62C 03007292 */  lbu        $s2, 0x3($s3)
    /* 2E30 8006B630 23208200 */  subu       $a0, $a0, $v0
    /* 2E34 8006B634 3BAD010C */  jal        _intepolateMenuItemBgColour
    /* 2E38 8006B638 21284002 */   addu      $a1, $s2, $zero
    /* 2E3C 8006B63C 21804000 */  addu       $s0, $v0, $zero
    /* 2E40 8006B640 02006492 */  lbu        $a0, 0x2($s3)
    /* 2E44 8006B644 3BAD010C */  jal        _intepolateMenuItemBgColour
    /* 2E48 8006B648 21284002 */   addu      $a1, $s2, $zero
    /* 2E4C 8006B64C 21A04000 */  addu       $s4, $v0, $zero
    /* 2E50 8006B650 07004232 */  andi       $v0, $s2, 0x7
    /* 2E54 8006B654 02004010 */  beqz       $v0, .L8006B660
    /* 2E58 8006B658 01004226 */   addiu     $v0, $s2, 0x1
    /* 2E5C 8006B65C 030062A2 */  sb         $v0, 0x3($s3)
  .L8006B660:
    /* 2E60 8006B660 0E006286 */  lh         $v0, 0xE($s3)
    /* 2E64 8006B664 21200000 */  addu       $a0, $zero, $zero
    /* 2E68 8006B668 94A1000C */  jal        DrawSync
    /* 2E6C 8006B66C 00940200 */   sll       $s2, $v0, 16
    /* 2E70 8006B670 00E1033C */  lui        $v1, (0xE1000200 >> 16)
    /* 2E74 8006B674 00026334 */  ori        $v1, $v1, (0xE1000200 & 0xFFFF)
    /* 2E78 8006B678 0E80043C */  lui        $a0, %hi(_primBuf)
    /* 2E7C 8006B67C 000C023C */  lui        $v0, (0xC000000 >> 16)
    /* 2E80 8006B680 28ED82AC */  sw         $v0, %lo(_primBuf)($a0)
    /* 2E84 8006B684 28ED8424 */  addiu      $a0, $a0, %lo(_primBuf)
    /* 2E88 8006B688 0060023C */  lui        $v0, (0x60000000 >> 16)
    /* 2E8C 8006B68C 040083AC */  sw         $v1, 0x4($a0)
    /* 2E90 8006B690 080082AC */  sw         $v0, 0x8($a0)
    /* 2E94 8006B694 0C006286 */  lh         $v0, 0xC($s3)
    /* 2E98 8006B698 0E006386 */  lh         $v1, 0xE($s3)
    /* 2E9C 8006B69C 02004224 */  addiu      $v0, $v0, 0x2
    /* 2EA0 8006B6A0 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 2EA4 8006B6A4 02006324 */  addiu      $v1, $v1, 0x2
    /* 2EA8 8006B6A8 001C0300 */  sll        $v1, $v1, 16
    /* 2EAC 8006B6AC 25104300 */  or         $v0, $v0, $v1
    /* 2EB0 8006B6B0 0C0082AC */  sw         $v0, 0xC($a0)
    /* 2EB4 8006B6B4 0038023C */  lui        $v0, (0x38000000 >> 16)
    /* 2EB8 8006B6B8 10006586 */  lh         $a1, 0x10($s3)
    /* 2EBC 8006B6BC 12006386 */  lh         $v1, 0x12($s3)
    /* 2EC0 8006B6C0 25100202 */  or         $v0, $s0, $v0
    /* 2EC4 8006B6C4 140082AC */  sw         $v0, 0x14($a0)
    /* 2EC8 8006B6C8 001C0300 */  sll        $v1, $v1, 16
    /* 2ECC 8006B6CC 2528A300 */  or         $a1, $a1, $v1
    /* 2ED0 8006B6D0 100085AC */  sw         $a1, 0x10($a0)
    /* 2ED4 8006B6D4 0C006296 */  lhu        $v0, 0xC($s3)
    /* 2ED8 8006B6D8 1C0094AC */  sw         $s4, 0x1C($a0)
    /* 2EDC 8006B6DC 25105200 */  or         $v0, $v0, $s2
    /* 2EE0 8006B6E0 180082AC */  sw         $v0, 0x18($a0)
    /* 2EE4 8006B6E4 0C006286 */  lh         $v0, 0xC($s3)
    /* 2EE8 8006B6E8 10006386 */  lh         $v1, 0x10($s3)
    /* 2EEC 8006B6EC FA001524 */  addiu      $s5, $zero, 0xFA
    /* 2EF0 8006B6F0 240090AC */  sw         $s0, 0x24($a0)
    /* 2EF4 8006B6F4 21104300 */  addu       $v0, $v0, $v1
    /* 2EF8 8006B6F8 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 2EFC 8006B6FC 25105200 */  or         $v0, $v0, $s2
    /* 2F00 8006B700 200082AC */  sw         $v0, 0x20($a0)
    /* 2F04 8006B704 0C006396 */  lhu        $v1, 0xC($s3)
    /* 2F08 8006B708 0E006286 */  lh         $v0, 0xE($s3)
    /* 2F0C 8006B70C 12006586 */  lh         $a1, 0x12($s3)
    /* 2F10 8006B710 FF001124 */  addiu      $s1, $zero, 0xFF
    /* 2F14 8006B714 2C0094AC */  sw         $s4, 0x2C($a0)
    /* 2F18 8006B718 21104500 */  addu       $v0, $v0, $a1
    /* 2F1C 8006B71C 00140200 */  sll        $v0, $v0, 16
    /* 2F20 8006B720 25186200 */  or         $v1, $v1, $v0
    /* 2F24 8006B724 280083AC */  sw         $v1, 0x28($a0)
    /* 2F28 8006B728 0C006286 */  lh         $v0, 0xC($s3)
    /* 2F2C 8006B72C 10006386 */  lh         $v1, 0x10($s3)
    /* 2F30 8006B730 12006586 */  lh         $a1, 0x12($s3)
    /* 2F34 8006B734 21104300 */  addu       $v0, $v0, $v1
    /* 2F38 8006B738 0E006386 */  lh         $v1, 0xE($s3)
    /* 2F3C 8006B73C FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 2F40 8006B740 21186500 */  addu       $v1, $v1, $a1
    /* 2F44 8006B744 001C0300 */  sll        $v1, $v1, 16
    /* 2F48 8006B748 25104300 */  or         $v0, $v0, $v1
    /* 2F4C 8006B74C FAA2000C */  jal        DrawPrim
    /* 2F50 8006B750 300082AC */   sw        $v0, 0x30($a0)
    /* 2F54 8006B754 0C006286 */  lh         $v0, 0xC($s3)
    /* 2F58 8006B758 21800000 */  addu       $s0, $zero, $zero
    /* 2F5C 8006B75C 06004524 */  addiu      $a1, $v0, 0x6
    /* 2F60 8006B760 21107002 */  addu       $v0, $s3, $s0
  .L8006B764:
    /* 2F64 8006B764 14005490 */  lbu        $s4, 0x14($v0)
    /* 2F68 8006B768 00000000 */  nop
    /* 2F6C 8006B76C 06009516 */  bne        $s4, $s5, .L8006B788
    /* 2F70 8006B770 00000000 */   nop
    /* 2F74 8006B774 01001026 */  addiu      $s0, $s0, 0x1
    /* 2F78 8006B778 21107002 */  addu       $v0, $s3, $s0
    /* 2F7C 8006B77C 14004290 */  lbu        $v0, 0x14($v0)
    /* 2F80 8006B780 E8AD0108 */  j          .L8006B7A0
    /* 2F84 8006B784 2128A200 */   addu      $a1, $a1, $v0
  .L8006B788:
    /* 2F88 8006B788 09009112 */  beq        $s4, $s1, .L8006B7B0
    /* 2F8C 8006B78C 21208002 */   addu      $a0, $s4, $zero
    /* 2F90 8006B790 0E006686 */  lh         $a2, 0xE($s3)
    /* 2F94 8006B794 FEAB010C */  jal        _printCharacter
    /* 2F98 8006B798 21380000 */   addu      $a3, $zero, $zero
    /* 2F9C 8006B79C 21284000 */  addu       $a1, $v0, $zero
  .L8006B7A0:
    /* 2FA0 8006B7A0 01001026 */  addiu      $s0, $s0, 0x1
    /* 2FA4 8006B7A4 2000022A */  slti       $v0, $s0, 0x20
    /* 2FA8 8006B7A8 EEFF4014 */  bnez       $v0, .L8006B764
    /* 2FAC 8006B7AC 21107002 */   addu      $v0, $s3, $s0
  .L8006B7B0:
    /* 2FB0 8006B7B0 01007492 */  lbu        $s4, 0x1($s3)
    /* 2FB4 8006B7B4 00000000 */  nop
    /* 2FB8 8006B7B8 0500822A */  slti       $v0, $s4, 0x5
    /* 2FBC 8006B7BC 25014010 */  beqz       $v0, .L8006BC54
    /* 2FC0 8006B7C0 1000A527 */   addiu     $a1, $sp, 0x10
    /* 2FC4 8006B7C4 E300043C */  lui        $a0, (0xE30300 >> 16)
    /* 2FC8 8006B7C8 00038434 */  ori        $a0, $a0, (0xE30300 & 0xFFFF)
    /* 2FCC 8006B7CC 0100063C */  lui        $a2, (0x10100 >> 16)
    /* 2FD0 8006B7D0 03A3010C */  jal        _readImage
    /* 2FD4 8006B7D4 0001C634 */   ori       $a2, $a2, (0x10100 & 0xFFFF)
    /* 2FD8 8006B7D8 0E80023C */  lui        $v0, %hi(_saveFileInfo)
    /* 2FDC 8006B7DC 08EB438C */  lw         $v1, %lo(_saveFileInfo)($v0)
    /* 2FE0 8006B7E0 C0111400 */  sll        $v0, $s4, 7
    /* 2FE4 8006B7E4 21A86200 */  addu       $s5, $v1, $v0
    /* 2FE8 8006B7E8 06006292 */  lbu        $v0, 0x6($s3)
    /* 2FEC 8006B7EC 0400B08E */  lw         $s0, 0x4($s5)
    /* 2FF0 8006B7F0 FFFF5124 */  addiu      $s1, $v0, -0x1
    /* 2FF4 8006B7F4 0300022E */  sltiu      $v0, $s0, 0x3
    /* 2FF8 8006B7F8 0F004010 */  beqz       $v0, .L8006B838
    /* 2FFC 8006B7FC 3000222A */   slti      $v0, $s1, 0x30
    /* 3000 8006B800 03000016 */  bnez       $s0, .L8006B810
    /* 3004 8006B804 02000224 */   addiu     $v0, $zero, 0x2
    /* 3008 8006B808 11AE0108 */  j          .L8006B844
    /* 300C 8006B80C FEFF1124 */   addiu     $s1, $zero, -0x2
  .L8006B810:
    /* 3010 8006B810 03000216 */  bne        $s0, $v0, .L8006B820
    /* 3014 8006B814 0E80023C */   lui       $v0, %hi(_isSaving)
    /* 3018 8006B818 11AE0108 */  j          .L8006B844
    /* 301C 8006B81C FCFF1124 */   addiu     $s1, $zero, -0x4
  .L8006B820:
    /* 3020 8006B820 70ED4290 */  lbu        $v0, %lo(_isSaving)($v0)
    /* 3024 8006B824 00000000 */  nop
    /* 3028 8006B828 06004010 */  beqz       $v0, .L8006B844
    /* 302C 8006B82C FBFF1124 */   addiu     $s1, $zero, -0x5
    /* 3030 8006B830 11AE0108 */  j          .L8006B844
    /* 3034 8006B834 FFFF1124 */   addiu     $s1, $zero, -0x1
  .L8006B838:
    /* 3038 8006B838 03004014 */  bnez       $v0, .L8006B848
    /* 303C 8006B83C 2000222E */   sltiu     $v0, $s1, 0x20
    /* 3040 8006B840 FDFF1124 */  addiu      $s1, $zero, -0x3
  .L8006B844:
    /* 3044 8006B844 2000222E */  sltiu      $v0, $s1, 0x20
  .L8006B848:
    /* 3048 8006B848 04004014 */  bnez       $v0, .L8006B85C
    /* 304C 8006B84C 0E80023C */   lui       $v0, %hi(_mcData)
    /* 3050 8006B850 BCEA428C */  lw         $v0, %lo(_mcData)($v0)
    /* 3054 8006B854 18AE0108 */  j          .L8006B860
    /* 3058 8006B858 00024524 */   addiu     $a1, $v0, 0x200
  .L8006B85C:
    /* 305C 8006B85C BCEA458C */  lw         $a1, %lo(_mcData)($v0)
  .L8006B860:
    /* 3060 8006B860 E300043C */  lui        $a0, (0xE30300 >> 16)
    /* 3064 8006B864 00038434 */  ori        $a0, $a0, (0xE30300 & 0xFFFF)
    /* 3068 8006B868 0100063C */  lui        $a2, (0x10100 >> 16)
    /* 306C 8006B86C F7A2010C */  jal        _drawImage
    /* 3070 8006B870 0001C634 */   ori       $a2, $a2, (0x10100 & 0xFFFF)
    /* 3074 8006B874 11002106 */  bgez       $s1, .L8006B8BC
    /* 3078 8006B878 08002532 */   andi      $a1, $s1, 0x8
    /* 307C 8006B87C F038023C */  lui        $v0, (0x38F00040 >> 16)
    /* 3080 8006B880 40004234 */  ori        $v0, $v0, (0x38F00040 & 0xFFFF)
    /* 3084 8006B884 27281100 */  nor        $a1, $zero, $s1
    /* 3088 8006B888 402B0500 */  sll        $a1, $a1, 13
    /* 308C 8006B88C 2528A200 */  or         $a1, $a1, $v0
    /* 3090 8006B890 2000063C */  lui        $a2, (0x200040 >> 16)
    /* 3094 8006B894 4000C634 */  ori        $a2, $a2, (0x200040 & 0xFFFF)
    /* 3098 8006B898 08000724 */  addiu      $a3, $zero, 0x8
    /* 309C 8006B89C 0C006486 */  lh         $a0, 0xC($s3)
    /* 30A0 8006B8A0 02006292 */  lbu        $v0, 0x2($s3)
    /* 30A4 8006B8A4 C0FF8424 */  addiu      $a0, $a0, -0x40
    /* 30A8 8006B8A8 25209200 */  or         $a0, $a0, $s2
    /* 30AC 8006B8AC 2338E200 */  subu       $a3, $a3, $v0
    /* 30B0 8006B8B0 C03C0700 */  sll        $a3, $a3, 19
    /* 30B4 8006B8B4 45AE0108 */  j          .L8006B914
    /* 30B8 8006B8B8 9C00E734 */   ori       $a3, $a3, 0x9C
  .L8006B8BC:
    /* 30BC 8006B8BC C0280500 */  sll        $a1, $a1, 3
    /* 30C0 8006B8C0 07002232 */  andi       $v0, $s1, 0x7
    /* 30C4 8006B8C4 40130200 */  sll        $v0, $v0, 13
    /* 30C8 8006B8C8 2528A200 */  or         $a1, $a1, $v0
    /* 30CC 8006B8CC F038023C */  lui        $v0, (0x38F00000 >> 16)
    /* 30D0 8006B8D0 2528A200 */  or         $a1, $a1, $v0
    /* 30D4 8006B8D4 2000063C */  lui        $a2, (0x200040 >> 16)
    /* 30D8 8006B8D8 4000C634 */  ori        $a2, $a2, (0x200040 & 0xFFFF)
    /* 30DC 8006B8DC 30002232 */  andi       $v0, $s1, 0x30
    /* 30E0 8006B8E0 80100200 */  sll        $v0, $v0, 2
    /* 30E4 8006B8E4 40034224 */  addiu      $v0, $v0, 0x340
    /* 30E8 8006B8E8 FF034230 */  andi       $v0, $v0, 0x3FF
    /* 30EC 8006B8EC 83110200 */  sra        $v0, $v0, 6
    /* 30F0 8006B8F0 08000724 */  addiu      $a3, $zero, 0x8
    /* 30F4 8006B8F4 0C006486 */  lh         $a0, 0xC($s3)
    /* 30F8 8006B8F8 02006392 */  lbu        $v1, 0x2($s3)
    /* 30FC 8006B8FC C0FF8424 */  addiu      $a0, $a0, -0x40
    /* 3100 8006B900 25209200 */  or         $a0, $a0, $s2
    /* 3104 8006B904 2338E300 */  subu       $a3, $a3, $v1
    /* 3108 8006B908 C03C0700 */  sll        $a3, $a3, 19
    /* 310C 8006B90C 9000E734 */  ori        $a3, $a3, 0x90
    /* 3110 8006B910 25384700 */  or         $a3, $v0, $a3
  .L8006B914:
    /* 3114 8006B914 DEA9010C */  jal        _drawSprt
    /* 3118 8006B918 00000000 */   nop
    /* 311C 8006B91C E300043C */  lui        $a0, (0xE30300 >> 16)
    /* 3120 8006B920 00038434 */  ori        $a0, $a0, (0xE30300 & 0xFFFF)
    /* 3124 8006B924 1000A527 */  addiu      $a1, $sp, 0x10
    /* 3128 8006B928 0100063C */  lui        $a2, (0x10100 >> 16)
    /* 312C 8006B92C F7A2010C */  jal        _drawImage
    /* 3130 8006B930 0001C634 */   ori       $a2, $a2, (0x10100 & 0xFFFF)
    /* 3134 8006B934 0C006486 */  lh         $a0, 0xC($s3)
    /* 3138 8006B938 01000524 */  addiu      $a1, $zero, 0x1
    /* 313C 8006B93C EAFF8424 */  addiu      $a0, $a0, -0x16
    /* 3140 8006B940 07AA010C */  jal        _drawSaveInfoUI
    /* 3144 8006B944 25209200 */   or        $a0, $a0, $s2
    /* 3148 8006B948 01008526 */  addiu      $a1, $s4, 0x1
    /* 314C 8006B94C 0C006486 */  lh         $a0, 0xC($s3)
    /* 3150 8006B950 0A000624 */  addiu      $a2, $zero, 0xA
    /* 3154 8006B954 F7FF8424 */  addiu      $a0, $a0, -0x9
    /* 3158 8006B958 18AA010C */  jal        _drawInteger
    /* 315C 8006B95C 25209200 */   or        $a0, $a0, $s2
    /* 3160 8006B960 0400A38E */  lw         $v1, 0x4($s5)
    /* 3164 8006B964 00000000 */  nop
    /* 3168 8006B968 08006014 */  bnez       $v1, .L8006B98C
    /* 316C 8006B96C 01000224 */   addiu     $v0, $zero, 0x1
    /* 3170 8006B970 0E80023C */  lui        $v0, %hi(_textTable)
    /* 3174 8006B974 03000724 */  addiu      $a3, $zero, 0x3
    /* 3178 8006B978 C0EA448C */  lw         $a0, %lo(_textTable)($v0)
    /* 317C 8006B97C 0C006586 */  lh         $a1, 0xC($s3)
    /* 3180 8006B980 0E006686 */  lh         $a2, 0xE($s3)
    /* 3184 8006B984 75AE0108 */  j          .L8006B9D4
    /* 3188 8006B988 72038424 */   addiu     $a0, $a0, 0x372
  .L8006B98C:
    /* 318C 8006B98C 16006214 */  bne        $v1, $v0, .L8006B9E8
    /* 3190 8006B990 0400023C */   lui       $v0, (0x40107 >> 16)
    /* 3194 8006B994 0E80023C */  lui        $v0, %hi(_isSaving)
    /* 3198 8006B998 70ED4290 */  lbu        $v0, %lo(_isSaving)($v0)
    /* 319C 8006B99C 00000000 */  nop
    /* 31A0 8006B9A0 07004014 */  bnez       $v0, .L8006B9C0
    /* 31A4 8006B9A4 0E80023C */   lui       $v0, %hi(_textTable)
    /* 31A8 8006B9A8 03000724 */  addiu      $a3, $zero, 0x3
    /* 31AC 8006B9AC C0EA448C */  lw         $a0, %lo(_textTable)($v0)
    /* 31B0 8006B9B0 0C006586 */  lh         $a1, 0xC($s3)
    /* 31B4 8006B9B4 0E006686 */  lh         $a2, 0xE($s3)
    /* 31B8 8006B9B8 75AE0108 */  j          .L8006B9D4
    /* 31BC 8006B9BC 8A038424 */   addiu     $a0, $a0, 0x38A
  .L8006B9C0:
    /* 31C0 8006B9C0 21380000 */  addu       $a3, $zero, $zero
    /* 31C4 8006B9C4 C0EA448C */  lw         $a0, %lo(_textTable)($v0)
    /* 31C8 8006B9C8 0C006586 */  lh         $a1, 0xC($s3)
    /* 31CC 8006B9CC 0E006686 */  lh         $a2, 0xE($s3)
    /* 31D0 8006B9D0 A0038424 */  addiu      $a0, $a0, 0x3A0
  .L8006B9D4:
    /* 31D4 8006B9D4 0600A524 */  addiu      $a1, $a1, 0x6
    /* 31D8 8006B9D8 D9AC010C */  jal        _printString
    /* 31DC 8006B9DC 0A00C624 */   addiu     $a2, $a2, 0xA
    /* 31E0 8006B9E0 EBAE0108 */  j          .L8006BBAC
    /* 31E4 8006B9E4 00000000 */   nop
  .L8006B9E8:
    /* 31E8 8006B9E8 21904202 */  addu       $s2, $s2, $v0
    /* 31EC 8006B9EC 21380000 */  addu       $a3, $zero, $zero
    /* 31F0 8006B9F0 0E80033C */  lui        $v1, %hi(_textTable)
    /* 31F4 8006B9F4 0C006586 */  lh         $a1, 0xC($s3)
    /* 31F8 8006B9F8 06006292 */  lbu        $v0, 0x6($s3)
    /* 31FC 8006B9FC C0EA638C */  lw         $v1, %lo(_textTable)($v1)
    /* 3200 8006BA00 0E006686 */  lh         $a2, 0xE($s3)
    /* 3204 8006BA04 0600A524 */  addiu      $a1, $a1, 0x6
    /* 3208 8006BA08 40100200 */  sll        $v0, $v0, 1
    /* 320C 8006BA0C 21104300 */  addu       $v0, $v0, $v1
    /* 3210 8006BA10 52004494 */  lhu        $a0, 0x52($v0)
    /* 3214 8006BA14 0400C624 */  addiu      $a2, $a2, 0x4
    /* 3218 8006BA18 40200400 */  sll        $a0, $a0, 1
    /* 321C 8006BA1C D9AC010C */  jal        _printString
    /* 3220 8006BA20 21206400 */   addu      $a0, $v1, $a0
    /* 3224 8006BA24 AC004436 */  ori        $a0, $s2, (0x400AC & 0xFFFF)
    /* 3228 8006BA28 07AA010C */  jal        _drawSaveInfoUI
    /* 322C 8006BA2C 02000524 */   addiu     $a1, $zero, 0x2
    /* 3230 8006BA30 BD004436 */  ori        $a0, $s2, (0x400BD & 0xFFFF)
    /* 3234 8006BA34 07AA010C */  jal        _drawSaveInfoUI
    /* 3238 8006BA38 21280000 */   addu      $a1, $zero, $zero
    /* 323C 8006BA3C 1E00B092 */  lbu        $s0, 0x1E($s5)
    /* 3240 8006BA40 64000224 */  addiu      $v0, $zero, 0x64
    /* 3244 8006BA44 08000216 */  bne        $s0, $v0, .L8006BA68
    /* 3248 8006BA48 C0004436 */   ori       $a0, $s2, (0x400C0 & 0xFFFF)
    /* 324C 8006BA4C 21284000 */  addu       $a1, $v0, $zero
    /* 3250 8006BA50 18AA010C */  jal        _drawInteger
    /* 3254 8006BA54 21304000 */   addu      $a2, $v0, $zero
    /* 3258 8006BA58 FFFF043C */  lui        $a0, (0xFFFF00CF >> 16)
    /* 325C 8006BA5C 21204402 */  addu       $a0, $s2, $a0
    /* 3260 8006BA60 A0AE0108 */  j          .L8006BA80
    /* 3264 8006BA64 CF008434 */   ori       $a0, $a0, (0xFFFF00CF & 0xFFFF)
  .L8006BA68:
    /* 3268 8006BA68 21280002 */  addu       $a1, $s0, $zero
    /* 326C 8006BA6C 18AA010C */  jal        _drawInteger
    /* 3270 8006BA70 0A000624 */   addiu     $a2, $zero, 0xA
    /* 3274 8006BA74 FFFF043C */  lui        $a0, (0xFFFF00CA >> 16)
    /* 3278 8006BA78 21204402 */  addu       $a0, $s2, $a0
    /* 327C 8006BA7C CA008434 */  ori        $a0, $a0, (0xFFFF00CA & 0xFFFF)
  .L8006BA80:
    /* 3280 8006BA80 07AA010C */  jal        _drawSaveInfoUI
    /* 3284 8006BA84 06000524 */   addiu     $a1, $zero, 0x6
    /* 3288 8006BA88 D9004436 */  ori        $a0, $s2, (0x400D9 & 0xFFFF)
    /* 328C 8006BA8C 07AA010C */  jal        _drawSaveInfoUI
    /* 3290 8006BA90 03000524 */   addiu     $a1, $zero, 0x3
    /* 3294 8006BA94 EF004436 */  ori        $a0, $s2, (0x400EF & 0xFFFF)
    /* 3298 8006BA98 07AA010C */  jal        _drawSaveInfoUI
    /* 329C 8006BA9C 21280000 */   addu      $a1, $zero, $zero
    /* 32A0 8006BAA0 F2004436 */  ori        $a0, $s2, (0x400F2 & 0xFFFF)
    /* 32A4 8006BAA4 1400A596 */  lhu        $a1, 0x14($s5)
    /* 32A8 8006BAA8 18AA010C */  jal        _drawInteger
    /* 32AC 8006BAAC E8030624 */   addiu     $a2, $zero, 0x3E8
    /* 32B0 8006BAB0 0B014436 */  ori        $a0, $s2, (0x4010B & 0xFFFF)
    /* 32B4 8006BAB4 07AA010C */  jal        _drawSaveInfoUI
    /* 32B8 8006BAB8 04000524 */   addiu     $a1, $zero, 0x4
    /* 32BC 8006BABC 25014436 */  ori        $a0, $s2, (0x40125 & 0xFFFF)
    /* 32C0 8006BAC0 07AA010C */  jal        _drawSaveInfoUI
    /* 32C4 8006BAC4 21280000 */   addu      $a1, $zero, $zero
    /* 32C8 8006BAC8 28014436 */  ori        $a0, $s2, (0x40128 & 0xFFFF)
    /* 32CC 8006BACC 1D00A592 */  lbu        $a1, 0x1D($s5)
    /* 32D0 8006BAD0 18AA010C */  jal        _drawInteger
    /* 32D4 8006BAD4 0A000624 */   addiu     $a2, $zero, 0xA
    /* 32D8 8006BAD8 0D00023C */  lui        $v0, (0xD0107 >> 16)
    /* 32DC 8006BADC 1D00A392 */  lbu        $v1, 0x1D($s5)
    /* 32E0 8006BAE0 00000000 */  nop
    /* 32E4 8006BAE4 08006010 */  beqz       $v1, .L8006BB08
    /* 32E8 8006BAE8 21904202 */   addu      $s2, $s2, $v0
    /* 32EC 8006BAEC 45004436 */  ori        $a0, $s2, (0xD0045 & 0xFFFF)
    /* 32F0 8006BAF0 F937053C */  lui        $a1, (0x37F910F0 >> 16)
    /* 32F4 8006BAF4 F010A534 */  ori        $a1, $a1, (0x37F910F0 & 0xFFFF)
    /* 32F8 8006BAF8 1000063C */  lui        $a2, (0x100010 >> 16)
    /* 32FC 8006BAFC 1000C634 */  ori        $a2, $a2, (0x100010 & 0xFFFF)
    /* 3300 8006BB00 DEA9010C */  jal        _drawSprt
    /* 3304 8006BB04 0C000724 */   addiu     $a3, $zero, 0xC
  .L8006BB08:
    /* 3308 8006BB08 F0004436 */  ori        $a0, $s2, (0xD00F0 & 0xFFFF)
    /* 330C 8006BB0C 07AA010C */  jal        _drawSaveInfoUI
    /* 3310 8006BB10 05000524 */   addiu     $a1, $zero, 0x5
    /* 3314 8006BB14 1300B082 */  lb         $s0, 0x13($s5)
    /* 3318 8006BB18 64000224 */  addiu      $v0, $zero, 0x64
    /* 331C 8006BB1C 05000216 */  bne        $s0, $v0, .L8006BB34
    /* 3320 8006BB20 0C014436 */   ori       $a0, $s2, (0xD010C & 0xFFFF)
    /* 3324 8006BB24 07014436 */  ori        $a0, $s2, (0xD0107 & 0xFFFF)
    /* 3328 8006BB28 21284000 */  addu       $a1, $v0, $zero
    /* 332C 8006BB2C CFAE0108 */  j          .L8006BB3C
    /* 3330 8006BB30 21304000 */   addu      $a2, $v0, $zero
  .L8006BB34:
    /* 3334 8006BB34 21280002 */  addu       $a1, $s0, $zero
    /* 3338 8006BB38 0A000624 */  addiu      $a2, $zero, 0xA
  .L8006BB3C:
    /* 333C 8006BB3C 18AA010C */  jal        _drawInteger
    /* 3340 8006BB40 00000000 */   nop
    /* 3344 8006BB44 17014436 */  ori        $a0, $s2, (0x40117 & 0xFFFF)
    /* 3348 8006BB48 07AA010C */  jal        _drawSaveInfoUI
    /* 334C 8006BB4C 21280000 */   addu      $a1, $zero, $zero
    /* 3350 8006BB50 1A014436 */  ori        $a0, $s2, (0x4011A & 0xFFFF)
    /* 3354 8006BB54 1200A582 */  lb         $a1, 0x12($s5)
    /* 3358 8006BB58 18AA010C */  jal        _drawInteger
    /* 335C 8006BB5C 0A000624 */   addiu     $a2, $zero, 0xA
    /* 3360 8006BB60 25014436 */  ori        $a0, $s2, (0x40125 & 0xFFFF)
    /* 3364 8006BB64 07AA010C */  jal        _drawSaveInfoUI
    /* 3368 8006BB68 21280000 */   addu      $a1, $zero, $zero
    /* 336C 8006BB6C 28014436 */  ori        $a0, $s2, (0x40128 & 0xFFFF)
    /* 3370 8006BB70 1100A582 */  lb         $a1, 0x11($s5)
    /* 3374 8006BB74 18AA010C */  jal        _drawInteger
    /* 3378 8006BB78 0A000624 */   addiu     $a2, $zero, 0xA
    /* 337C 8006BB7C 58004436 */  ori        $a0, $s2, (0x40058 & 0xFFFF)
    /* 3380 8006BB80 1800A696 */  lhu        $a2, 0x18($s5)
    /* 3384 8006BB84 1A00A796 */  lhu        $a3, 0x1A($s5)
    /* 3388 8006BB88 4AAA010C */  jal        _drawHPMP
    /* 338C 8006BB8C 21280000 */   addu      $a1, $zero, $zero
    /* 3390 8006BB90 9E004436 */  ori        $a0, $s2, (0x4009E & 0xFFFF)
    /* 3394 8006BB94 2000A696 */  lhu        $a2, 0x20($s5)
    /* 3398 8006BB98 2200A796 */  lhu        $a3, 0x22($s5)
    /* 339C 8006BB9C 4AAA010C */  jal        _drawHPMP
    /* 33A0 8006BBA0 01000524 */   addiu     $a1, $zero, 0x1
    /* 33A4 8006BBA4 EFFF023C */  lui        $v0, (0xFFEF0000 >> 16)
    /* 33A8 8006BBA8 21904202 */  addu       $s2, $s2, $v0
  .L8006BBAC:
    /* 33AC 8006BBAC 04006292 */  lbu        $v0, 0x4($s3)
    /* 33B0 8006BBB0 00000000 */  nop
    /* 33B4 8006BBB4 27004010 */  beqz       $v0, .L8006BC54
    /* 33B8 8006BBB8 0E80033C */   lui       $v1, %hi(_fileProgressCounter)
    /* 33BC 8006BBBC 14EB668C */  lw         $a2, %lo(_fileProgressCounter)($v1)
    /* 33C0 8006BBC0 00000000 */  nop
    /* 33C4 8006BBC4 2300C010 */  beqz       $a2, .L8006BC54
    /* 33C8 8006BBC8 00000000 */   nop
    /* 33CC 8006BBCC 0C00C104 */  bgez       $a2, .L8006BC00
    /* 33D0 8006BBD0 0E80053C */   lui       $a1, %hi(_fileProgressPosition)
    /* 33D4 8006BBD4 0100C224 */  addiu      $v0, $a2, 0x1
    /* 33D8 8006BBD8 14EB62AC */  sw         $v0, %lo(_fileProgressCounter)($v1)
    /* 33DC 8006BBDC 0780023C */  lui        $v0, %hi(_cursorFileOpSaturation)
    /* 33E0 8006BBE0 B0284224 */  addiu      $v0, $v0, %lo(_cursorFileOpSaturation)
    /* 33E4 8006BBE4 2110C200 */  addu       $v0, $a2, $v0
    /* 33E8 8006BBE8 11004480 */  lb         $a0, 0x11($v0)
    /* 33EC 8006BBEC 21284002 */  addu       $a1, $s2, $zero
    /* 33F0 8006BBF0 36AB010C */  jal        _fileProcessingCompleteAnim
    /* 33F4 8006BBF4 23200400 */   negu      $a0, $a0
    /* 33F8 8006BBF8 15AF0108 */  j          .L8006BC54
    /* 33FC 8006BBFC 00000000 */   nop
  .L8006BC00:
    /* 3400 8006BC00 0E80023C */  lui        $v0, %hi(_filePreviousProgressCounter)
    /* 3404 8006BC04 0E80033C */  lui        $v1, %hi(_loadSaveDataErrorOffset)
    /* 3408 8006BC08 10EB4494 */  lhu        $a0, %lo(_filePreviousProgressCounter)($v0)
    /* 340C 8006BC0C 0CEB6390 */  lbu        $v1, %lo(_loadSaveDataErrorOffset)($v1)
    /* 3410 8006BC10 2320C400 */  subu       $a0, $a2, $a0
    /* 3414 8006BC14 80100300 */  sll        $v0, $v1, 2
    /* 3418 8006BC18 21104300 */  addu       $v0, $v0, $v1
    /* 341C 8006BC1C 12EBA694 */  lhu        $a2, %lo(_fileProgressPosition)($a1)
    /* 3420 8006BC20 80100200 */  sll        $v0, $v0, 2
    /* 3424 8006BC24 C0FEC324 */  addiu      $v1, $a2, -0x140
    /* 3428 8006BC28 23104300 */  subu       $v0, $v0, $v1
    /* 342C 8006BC2C 18008200 */  mult       $a0, $v0
    /* 3430 8006BC30 0E80023C */  lui        $v0, %hi(_fileProgressTarget)
    /* 3434 8006BC34 12180000 */  mflo       $v1
    /* 3438 8006BC38 0EEB4494 */  lhu        $a0, %lo(_fileProgressTarget)($v0)
    /* 343C 8006BC3C 00000000 */  nop
    /* 3440 8006BC40 1A006400 */  div        $zero, $v1, $a0
    /* 3444 8006BC44 12200000 */  mflo       $a0
    /* 3448 8006BC48 21284002 */  addu       $a1, $s2, $zero
    /* 344C 8006BC4C EEAA010C */  jal        _fileProcessingAnim
    /* 3450 8006BC50 2120C400 */   addu      $a0, $a2, $a0
  .L8006BC54:
    /* 3454 8006BC54 3002BF8F */  lw         $ra, 0x230($sp)
    /* 3458 8006BC58 2C02B58F */  lw         $s5, 0x22C($sp)
    /* 345C 8006BC5C 2802B48F */  lw         $s4, 0x228($sp)
    /* 3460 8006BC60 2402B38F */  lw         $s3, 0x224($sp)
    /* 3464 8006BC64 2002B28F */  lw         $s2, 0x220($sp)
    /* 3468 8006BC68 1C02B18F */  lw         $s1, 0x21C($sp)
    /* 346C 8006BC6C 1802B08F */  lw         $s0, 0x218($sp)
    /* 3470 8006BC70 0800E003 */  jr         $ra
    /* 3474 8006BC74 3802BD27 */   addiu     $sp, $sp, 0x238
endlabel _drawFileMenuElement
