nonmatching _gameLoadScreen, 0x250

glabel _gameLoadScreen
    /* 5F38 8006E738 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 5F3C 8006E73C 00030424 */  addiu      $a0, $zero, 0x300
    /* 5F40 8006E740 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5F44 8006E744 0C80103C */  lui        $s0, %hi(D_800C2268)
    /* 5F48 8006E748 68221026 */  addiu      $s0, $s0, %lo(D_800C2268)
    /* 5F4C 8006E74C 21280002 */  addu       $a1, $s0, $zero
    /* 5F50 8006E750 E000063C */  lui        $a2, (0xE00040 >> 16)
    /* 5F54 8006E754 4000C634 */  ori        $a2, $a2, (0xE00040 & 0xFFFF)
    /* 5F58 8006E758 2800BFAF */  sw         $ra, 0x28($sp)
    /* 5F5C 8006E75C 2400B5AF */  sw         $s5, 0x24($sp)
    /* 5F60 8006E760 2000B4AF */  sw         $s4, 0x20($sp)
    /* 5F64 8006E764 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 5F68 8006E768 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5F6C 8006E76C F7A2010C */  jal        _drawImage
    /* 5F70 8006E770 1400B1AF */   sw        $s1, 0x14($sp)
    /* 5F74 8006E774 0001043C */  lui        $a0, (0x10001C0 >> 16)
    /* 5F78 8006E778 C0018434 */  ori        $a0, $a0, (0x10001C0 & 0xFFFF)
    /* 5F7C 8006E77C 00700526 */  addiu      $a1, $s0, 0x7000
    /* 5F80 8006E780 0001063C */  lui        $a2, (0x1000040 >> 16)
    /* 5F84 8006E784 F7A2010C */  jal        _drawImage
    /* 5F88 8006E788 4000C634 */   ori       $a2, $a2, (0x1000040 & 0xFFFF)
    /* 5F8C 8006E78C 40030424 */  addiu      $a0, $zero, 0x340
    /* 5F90 8006E790 0B80103C */  lui        $s0, %hi(D_800AF368)
    /* 5F94 8006E794 68F31026 */  addiu      $s0, $s0, %lo(D_800AF368)
    /* 5F98 8006E798 21280002 */  addu       $a1, $s0, $zero
    /* 5F9C 8006E79C E000063C */  lui        $a2, (0xE00040 >> 16)
    /* 5FA0 8006E7A0 F7A2010C */  jal        _drawImage
    /* 5FA4 8006E7A4 4000C634 */   ori       $a2, $a2, (0xE00040 & 0xFFFF)
    /* 5FA8 8006E7A8 80030424 */  addiu      $a0, $zero, 0x380
    /* 5FAC 8006E7AC 00700526 */  addiu      $a1, $s0, 0x7000
    /* 5FB0 8006E7B0 E000063C */  lui        $a2, (0xE00040 >> 16)
    /* 5FB4 8006E7B4 F7A2010C */  jal        _drawImage
    /* 5FB8 8006E7B8 4000C634 */   ori       $a2, $a2, (0xE00040 & 0xFFFF)
    /* 5FBC 8006E7BC 4200043C */  lui        $a0, (0x4203C0 >> 16)
    /* 5FC0 8006E7C0 C0038434 */  ori        $a0, $a0, (0x4203C0 & 0xFFFF)
    /* 5FC4 8006E7C4 0C80053C */  lui        $a1, %hi(D_800BD368)
    /* 5FC8 8006E7C8 68D3A524 */  addiu      $a1, $a1, %lo(D_800BD368)
    /* 5FCC 8006E7CC 9E00063C */  lui        $a2, (0x9E0040 >> 16)
    /* 5FD0 8006E7D0 F7A2010C */  jal        _drawImage
    /* 5FD4 8006E7D4 4000C634 */   ori       $a2, $a2, (0x9E0040 & 0xFFFF)
    /* 5FD8 8006E7D8 E300043C */  lui        $a0, (0xE30300 >> 16)
    /* 5FDC 8006E7DC 00038434 */  ori        $a0, $a0, (0xE30300 & 0xFFFF)
    /* 5FE0 8006E7E0 0D80123C */  lui        $s2, %hi(D_800D1268)
    /* 5FE4 8006E7E4 68125226 */  addiu      $s2, $s2, %lo(D_800D1268)
    /* 5FE8 8006E7E8 21284002 */  addu       $a1, $s2, $zero
    /* 5FEC 8006E7EC 0100063C */  lui        $a2, (0x10100 >> 16)
    /* 5FF0 8006E7F0 F7A2010C */  jal        _drawImage
    /* 5FF4 8006E7F4 0001C634 */   ori       $a2, $a2, (0x10100 & 0xFFFF)
    /* 5FF8 8006E7F8 0E80113C */  lui        $s1, %hi(_gameLoadRect)
    /* 5FFC 8006E7FC 28C93026 */  addiu      $s0, $s1, %lo(_gameLoadRect)
    /* 6000 8006E800 21200002 */  addu       $a0, $s0, $zero
    /* 6004 8006E804 21280000 */  addu       $a1, $zero, $zero
    /* 6008 8006E808 2130A000 */  addu       $a2, $a1, $zero
    /* 600C 8006E80C 2138A000 */  addu       $a3, $a1, $zero
    /* 6010 8006E810 80020224 */  addiu      $v0, $zero, 0x280
    /* 6014 8006E814 00011524 */  addiu      $s5, $zero, 0x100
    /* 6018 8006E818 20001424 */  addiu      $s4, $zero, 0x20
    /* 601C 8006E81C F0001324 */  addiu      $s3, $zero, 0xF0
    /* 6020 8006E820 28C922A6 */  sh         $v0, %lo(_gameLoadRect)($s1)
    /* 6024 8006E824 020015A6 */  sh         $s5, 0x2($s0)
    /* 6028 8006E828 040014A6 */  sh         $s4, 0x4($s0)
    /* 602C 8006E82C F5A1000C */  jal        ClearImage
    /* 6030 8006E830 060013A6 */   sh        $s3, 0x6($s0)
    /* 6034 8006E834 94A1000C */  jal        DrawSync
    /* 6038 8006E838 21200000 */   addu      $a0, $zero, $zero
    /* 603C 8006E83C 21200002 */  addu       $a0, $s0, $zero
    /* 6040 8006E840 21280000 */  addu       $a1, $zero, $zero
    /* 6044 8006E844 2130A000 */  addu       $a2, $a1, $zero
    /* 6048 8006E848 2138A000 */  addu       $a3, $a1, $zero
    /* 604C 8006E84C 00030224 */  addiu      $v0, $zero, 0x300
    /* 6050 8006E850 28C922A6 */  sh         $v0, %lo(_gameLoadRect)($s1)
    /* 6054 8006E854 020095A4 */  sh         $s5, 0x2($a0)
    /* 6058 8006E858 040094A4 */  sh         $s4, 0x4($a0)
    /* 605C 8006E85C F5A1000C */  jal        ClearImage
    /* 6060 8006E860 060093A4 */   sh        $s3, 0x6($a0)
    /* 6064 8006E864 0001043C */  lui        $a0, (0x10002A0 >> 16)
    /* 6068 8006E868 A0028434 */  ori        $a0, $a0, (0x10002A0 & 0xFFFF)
    /* 606C 8006E86C 00024526 */  addiu      $a1, $s2, 0x200
    /* 6070 8006E870 F000063C */  lui        $a2, (0xF00060 >> 16)
    /* 6074 8006E874 F7A2010C */  jal        _drawImage
    /* 6078 8006E878 6000C634 */   ori       $a2, $a2, (0xF00060 & 0xFFFF)
    /* 607C 8006E87C 74B9010C */  jal        _initSaveScreen
    /* 6080 8006E880 01001324 */   addiu     $s3, $zero, 0x1
    /* 6084 8006E884 0E80023C */  lui        $v0, %hi(_loadScreenMemcardState)
    /* 6088 8006E888 21884000 */  addu       $s1, $v0, $zero
    /* 608C 8006E88C 02001224 */  addiu      $s2, $zero, 0x2
    /* 6090 8006E890 30C920A2 */  sb         $zero, %lo(_loadScreenMemcardState)($s1)
  .L8006E894:
    /* 6094 8006E894 8709010C */  jal        vs_main_gametimeUpdate
    /* 6098 8006E898 02000424 */   addiu     $a0, $zero, 0x2
    /* 609C 8006E89C A3B9010C */  jal        _saveScreenSwapBuf
    /* 60A0 8006E8A0 00000000 */   nop
    /* 60A4 8006E8A4 500E010C */  jal        vs_main_processPadState
    /* 60A8 8006E8A8 00000000 */   nop
    /* 60AC 8006E8AC 30C92392 */  lbu        $v1, %lo(_loadScreenMemcardState)($s1)
    /* 60B0 8006E8B0 00000000 */  nop
    /* 60B4 8006E8B4 0F007310 */  beq        $v1, $s3, .L8006E8F4
    /* 60B8 8006E8B8 02006228 */   slti      $v0, $v1, 0x2
    /* 60BC 8006E8BC 05004010 */  beqz       $v0, .L8006E8D4
    /* 60C0 8006E8C0 00000000 */   nop
    /* 60C4 8006E8C4 07006010 */  beqz       $v1, .L8006E8E4
    /* 60C8 8006E8C8 00000000 */   nop
    /* 60CC 8006E8CC 25BA0108 */  j          .L8006E894
    /* 60D0 8006E8D0 00000000 */   nop
  .L8006E8D4:
    /* 60D4 8006E8D4 11007210 */  beq        $v1, $s2, .L8006E91C
    /* 60D8 8006E8D8 00000000 */   nop
    /* 60DC 8006E8DC 25BA0108 */  j          .L8006E894
    /* 60E0 8006E8E0 00000000 */   nop
  .L8006E8E4:
    /* 60E4 8006E8E4 27A9010C */  jal        _initMemcard
    /* 60E8 8006E8E8 01000424 */   addiu     $a0, $zero, 0x1
    /* 60EC 8006E8EC 25BA0108 */  j          .L8006E894
    /* 60F0 8006E8F0 30C933A2 */   sb        $s3, %lo(_loadScreenMemcardState)($s1)
  .L8006E8F4:
    /* 60F4 8006E8F4 27A9010C */  jal        _initMemcard
    /* 60F8 8006E8F8 21200000 */   addu      $a0, $zero, $zero
    /* 60FC 8006E8FC E5FF4010 */  beqz       $v0, .L8006E894
    /* 6100 8006E900 00000000 */   nop
    /* 6104 8006E904 84AB010C */  jal        _initFileMenu
    /* 6108 8006E908 00000000 */   nop
    /* 610C 8006E90C AFB2010C */  jal        _loadFileMenu
    /* 6110 8006E910 02000424 */   addiu     $a0, $zero, 0x2
    /* 6114 8006E914 25BA0108 */  j          .L8006E894
    /* 6118 8006E918 30C932A2 */   sb        $s2, %lo(_loadScreenMemcardState)($s1)
  .L8006E91C:
    /* 611C 8006E91C AFB2010C */  jal        _loadFileMenu
    /* 6120 8006E920 21200000 */   addu      $a0, $zero, $zero
    /* 6124 8006E924 21804000 */  addu       $s0, $v0, $zero
    /* 6128 8006E928 09000016 */  bnez       $s0, .L8006E950
    /* 612C 8006E92C 00000000 */   nop
    /* 6130 8006E930 45B0010C */  jal        _drawFileMenuBg
    /* 6134 8006E934 00000000 */   nop
    /* 6138 8006E938 0E80023C */  lui        $v0, %hi(_frameBuf)
    /* 613C 8006E93C 76ED4490 */  lbu        $a0, %lo(_frameBuf)($v0)
    /* 6140 8006E940 1EAF010C */  jal        _drawFileMenu
    /* 6144 8006E944 00000000 */   nop
    /* 6148 8006E948 25BA0108 */  j          .L8006E894
    /* 614C 8006E94C 00000000 */   nop
  .L8006E950:
    /* 6150 8006E950 B8A9010C */  jal        _shutdownMemcard
    /* 6154 8006E954 00000000 */   nop
    /* 6158 8006E958 6EA1000C */  jal        SetDispMask
    /* 615C 8006E95C 21200000 */   addu      $a0, $zero, $zero
    /* 6160 8006E960 21100002 */  addu       $v0, $s0, $zero
    /* 6164 8006E964 2800BF8F */  lw         $ra, 0x28($sp)
    /* 6168 8006E968 2400B58F */  lw         $s5, 0x24($sp)
    /* 616C 8006E96C 2000B48F */  lw         $s4, 0x20($sp)
    /* 6170 8006E970 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 6174 8006E974 1800B28F */  lw         $s2, 0x18($sp)
    /* 6178 8006E978 1400B18F */  lw         $s1, 0x14($sp)
    /* 617C 8006E97C 1000B08F */  lw         $s0, 0x10($sp)
    /* 6180 8006E980 0800E003 */  jr         $ra
    /* 6184 8006E984 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _gameLoadScreen
