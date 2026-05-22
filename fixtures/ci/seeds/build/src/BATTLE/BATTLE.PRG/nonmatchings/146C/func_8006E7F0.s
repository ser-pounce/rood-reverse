nonmatching func_8006E7F0, 0x408

glabel func_8006E7F0
    /* 5FF0 8006E7F0 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 5FF4 8006E7F4 21200000 */  addu       $a0, $zero, $zero
    /* 5FF8 8006E7F8 1000A527 */  addiu      $a1, $sp, 0x10
    /* 5FFC 8006E7FC 4000BFAF */  sw         $ra, 0x40($sp)
    /* 6000 8006E800 3C00B1AF */  sw         $s1, 0x3C($sp)
    /* 6004 8006E804 4284020C */  jal        func_800A1108
    /* 6008 8006E808 3800B0AF */   sw        $s0, 0x38($sp)
    /* 600C 8006E80C 21200000 */  addu       $a0, $zero, $zero
    /* 6010 8006E810 C5D2010C */  jal        func_80074B14
    /* 6014 8006E814 1000A527 */   addiu     $a1, $sp, 0x10
    /* 6018 8006E818 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 601C 8006E81C FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 6020 8006E820 00000000 */  nop
    /* 6024 8006E824 3C00508C */  lw         $s0, 0x3C($v0)
    /* 6028 8006E828 F882020C */  jal        func_800A0BE0
    /* 602C 8006E82C 21200000 */   addu      $a0, $zero, $zero
    /* 6030 8006E830 0F80033C */  lui        $v1, %hi(vs_battle_screenTransitionStep)
    /* 6034 8006E834 481A638C */  lw         $v1, %lo(vs_battle_screenTransitionStep)($v1)
    /* 6038 8006E838 21884000 */  addu       $s1, $v0, $zero
    /* 603C 8006E83C FFFF6224 */  addiu      $v0, $v1, -0x1
    /* 6040 8006E840 0200422C */  sltiu      $v0, $v0, 0x2
    /* 6044 8006E844 04004014 */  bnez       $v0, .L8006E858
    /* 6048 8006E848 0F80023C */   lui       $v0, %hi(D_800F1AB0)
    /* 604C 8006E84C 04000224 */  addiu      $v0, $zero, 0x4
    /* 6050 8006E850 0F006214 */  bne        $v1, $v0, .L8006E890
    /* 6054 8006E854 0F80023C */   lui       $v0, %hi(D_800F1AB0)
  .L8006E858:
    /* 6058 8006E858 B01A4324 */  addiu      $v1, $v0, %lo(D_800F1AB0)
    /* 605C 8006E85C 06006294 */  lhu        $v0, 0x6($v1)
    /* 6060 8006E860 00000000 */  nop
    /* 6064 8006E864 00804230 */  andi       $v0, $v0, 0x8000
    /* 6068 8006E868 07004010 */  beqz       $v0, .L8006E888
    /* 606C 8006E86C 21200000 */   addu      $a0, $zero, $zero
    /* 6070 8006E870 04006594 */  lhu        $a1, 0x4($v1)
    /* 6074 8006E874 31000692 */  lbu        $a2, 0x31($s0)
    /* 6078 8006E878 C2280500 */  srl        $a1, $a1, 3
    /* 607C 8006E87C 000CA530 */  andi       $a1, $a1, 0xC00
    /* 6080 8006E880 F6BA0108 */  j          .L8006EBD8
    /* 6084 8006E884 C0320600 */   sll       $a2, $a2, 11
  .L8006E888:
    /* 6088 8006E888 F5BA0108 */  j          .L8006EBD4
    /* 608C 8006E88C 21288000 */   addu      $a1, $a0, $zero
  .L8006E890:
    /* 6090 8006E890 56B8010C */  jal        func_8006E158
    /* 6094 8006E894 00000000 */   nop
    /* 6098 8006E898 0F80023C */  lui        $v0, %hi(D_800F1A50)
    /* 609C 8006E89C 501A4224 */  addiu      $v0, $v0, %lo(D_800F1A50)
    /* 60A0 8006E8A0 0C0040AC */  sw         $zero, 0xC($v0)
    /* 60A4 8006E8A4 040040AC */  sw         $zero, 0x4($v0)
    /* 60A8 8006E8A8 0580023C */  lui        $v0, %hi(_portInfo)
    /* 60AC 8006E8AC 90014424 */  addiu      $a0, $v0, %lo(_portInfo)
    /* 60B0 8006E8B0 90014390 */  lbu        $v1, %lo(_portInfo)($v0)
    /* 60B4 8006E8B4 07000224 */  addiu      $v0, $zero, 0x7
    /* 60B8 8006E8B8 25006214 */  bne        $v1, $v0, .L8006E950
    /* 60BC 8006E8BC 0F80023C */   lui       $v0, %hi(D_800F1A50)
    /* 60C0 8006E8C0 03008290 */  lbu        $v0, 0x3($a0)
    /* 60C4 8006E8C4 04008390 */  lbu        $v1, 0x4($a0)
    /* 60C8 8006E8C8 80FF4524 */  addiu      $a1, $v0, -0x80
    /* 60CC 8006E8CC C0FF4224 */  addiu      $v0, $v0, -0x40
    /* 60D0 8006E8D0 8100422C */  sltiu      $v0, $v0, 0x81
    /* 60D4 8006E8D4 07004010 */  beqz       $v0, .L8006E8F4
    /* 60D8 8006E8D8 80FF6424 */   addiu     $a0, $v1, -0x80
    /* 60DC 8006E8DC C0FF8228 */  slti       $v0, $a0, -0x40
    /* 60E0 8006E8E0 05004014 */  bnez       $v0, .L8006E8F8
    /* 60E4 8006E8E4 4100A228 */   slti      $v0, $a1, 0x41
    /* 60E8 8006E8E8 41008228 */  slti       $v0, $a0, 0x41
    /* 60EC 8006E8EC 18004014 */  bnez       $v0, .L8006E950
    /* 60F0 8006E8F0 0F80023C */   lui       $v0, %hi(D_800F1A50)
  .L8006E8F4:
    /* 60F4 8006E8F4 4100A228 */  slti       $v0, $a1, 0x41
  .L8006E8F8:
    /* 60F8 8006E8F8 03004014 */  bnez       $v0, .L8006E908
    /* 60FC 8006E8FC C0FFA228 */   slti      $v0, $a1, -0x40
    /* 6100 8006E900 45BA0108 */  j          .L8006E914
    /* 6104 8006E904 C0FFA524 */   addiu     $a1, $a1, -0x40
  .L8006E908:
    /* 6108 8006E908 02004014 */  bnez       $v0, .L8006E914
    /* 610C 8006E90C 4000A524 */   addiu     $a1, $a1, 0x40
    /* 6110 8006E910 21280000 */  addu       $a1, $zero, $zero
  .L8006E914:
    /* 6114 8006E914 41008228 */  slti       $v0, $a0, 0x41
    /* 6118 8006E918 03004014 */  bnez       $v0, .L8006E928
    /* 611C 8006E91C C0FF8228 */   slti      $v0, $a0, -0x40
    /* 6120 8006E920 4DBA0108 */  j          .L8006E934
    /* 6124 8006E924 C0FF8424 */   addiu     $a0, $a0, -0x40
  .L8006E928:
    /* 6128 8006E928 02004014 */  bnez       $v0, .L8006E934
    /* 612C 8006E92C 40008424 */   addiu     $a0, $a0, 0x40
    /* 6130 8006E930 21200000 */  addu       $a0, $zero, $zero
  .L8006E934:
    /* 6134 8006E934 0F80023C */  lui        $v0, %hi(D_800F1A50)
    /* 6138 8006E938 501A4224 */  addiu      $v0, $v0, %lo(D_800F1A50)
    /* 613C 8006E93C 23180500 */  negu       $v1, $a1
    /* 6140 8006E940 0C0040AC */  sw         $zero, 0xC($v0)
    /* 6144 8006E944 040043AC */  sw         $v1, 0x4($v0)
    /* 6148 8006E948 0C0044AC */  sw         $a0, 0xC($v0)
    /* 614C 8006E94C 0F80023C */  lui        $v0, %hi(D_800F1A50)
  .L8006E950:
    /* 6150 8006E950 501A4424 */  addiu      $a0, $v0, %lo(D_800F1A50)
    /* 6154 8006E954 0400828C */  lw         $v0, 0x4($a0)
    /* 6158 8006E958 00000000 */  nop
    /* 615C 8006E95C 23004014 */  bnez       $v0, .L8006E9EC
    /* 6160 8006E960 0F80023C */   lui       $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 6164 8006E964 0C00828C */  lw         $v0, 0xC($a0)
    /* 6168 8006E968 00000000 */  nop
    /* 616C 8006E96C 1F004014 */  bnez       $v0, .L8006E9EC
    /* 6170 8006E970 0F80023C */   lui       $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 6174 8006E974 0680023C */  lui        $v0, %hi(vs_main_buttonsPreviousState)
    /* 6178 8006E978 C0E1458C */  lw         $a1, %lo(vs_main_buttonsPreviousState)($v0)
    /* 617C 8006E97C 00000000 */  nop
    /* 6180 8006E980 0040A230 */  andi       $v0, $a1, 0x4000
    /* 6184 8006E984 03004010 */  beqz       $v0, .L8006E994
    /* 6188 8006E988 10000224 */   addiu     $v0, $zero, 0x10
    /* 618C 8006E98C 040080AC */  sw         $zero, 0x4($a0)
    /* 6190 8006E990 0C0082AC */  sw         $v0, 0xC($a0)
  .L8006E994:
    /* 6194 8006E994 0010A230 */  andi       $v0, $a1, 0x1000
    /* 6198 8006E998 06004010 */  beqz       $v0, .L8006E9B4
    /* 619C 8006E99C 0080A230 */   andi      $v0, $a1, 0x8000
    /* 61A0 8006E9A0 0C00828C */  lw         $v0, 0xC($a0)
    /* 61A4 8006E9A4 0400838C */  lw         $v1, 0x4($a0)
    /* 61A8 8006E9A8 F0FF4224 */  addiu      $v0, $v0, -0x10
    /* 61AC 8006E9AC 0C0082AC */  sw         $v0, 0xC($a0)
    /* 61B0 8006E9B0 0080A230 */  andi       $v0, $a1, 0x8000
  .L8006E9B4:
    /* 61B4 8006E9B4 06004010 */  beqz       $v0, .L8006E9D0
    /* 61B8 8006E9B8 0020A230 */   andi      $v0, $a1, 0x2000
    /* 61BC 8006E9BC 0400828C */  lw         $v0, 0x4($a0)
    /* 61C0 8006E9C0 0C00838C */  lw         $v1, 0xC($a0)
    /* 61C4 8006E9C4 10004224 */  addiu      $v0, $v0, 0x10
    /* 61C8 8006E9C8 040082AC */  sw         $v0, 0x4($a0)
    /* 61CC 8006E9CC 0020A230 */  andi       $v0, $a1, 0x2000
  .L8006E9D0:
    /* 61D0 8006E9D0 06004010 */  beqz       $v0, .L8006E9EC
    /* 61D4 8006E9D4 0F80023C */   lui       $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 61D8 8006E9D8 0400828C */  lw         $v0, 0x4($a0)
    /* 61DC 8006E9DC 0C00838C */  lw         $v1, 0xC($a0)
    /* 61E0 8006E9E0 F0FF4224 */  addiu      $v0, $v0, -0x10
    /* 61E4 8006E9E4 040082AC */  sw         $v0, 0x4($a0)
    /* 61E8 8006E9E8 0F80023C */  lui        $v0, %hi(vs_battle_cameraCurrentSpherical)
  .L8006E9EC:
    /* 61EC 8006E9EC D0194424 */  addiu      $a0, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* 61F0 8006E9F0 0800838C */  lw         $v1, 0x8($a0)
    /* 61F4 8006E9F4 00000000 */  nop
    /* 61F8 8006E9F8 01096228 */  slti       $v0, $v1, 0x901
    /* 61FC 8006E9FC 03004014 */  bnez       $v0, .L8006EA0C
    /* 6200 8006EA00 00066228 */   slti      $v0, $v1, 0x600
    /* 6204 8006EA04 85BA0108 */  j          .L8006EA14
    /* 6208 8006EA08 00090224 */   addiu     $v0, $zero, 0x900
  .L8006EA0C:
    /* 620C 8006EA0C 02004010 */  beqz       $v0, .L8006EA18
    /* 6210 8006EA10 00060224 */   addiu     $v0, $zero, 0x600
  .L8006EA14:
    /* 6214 8006EA14 080082AC */  sw         $v0, 0x8($a0)
  .L8006EA18:
    /* 6218 8006EA18 0F80023C */  lui        $v0, %hi(D_800F1A50)
    /* 621C 8006EA1C 501A4324 */  addiu      $v1, $v0, %lo(D_800F1A50)
    /* 6220 8006EA20 0400648C */  lw         $a0, 0x4($v1)
    /* 6224 8006EA24 00000000 */  nop
    /* 6228 8006EA28 05008014 */  bnez       $a0, .L8006EA40
    /* 622C 8006EA2C 0800023C */   lui       $v0, (0x80000 >> 16)
    /* 6230 8006EA30 0C00628C */  lw         $v0, 0xC($v1)
    /* 6234 8006EA34 00000000 */  nop
    /* 6238 8006EA38 4D004010 */  beqz       $v0, .L8006EB70
    /* 623C 8006EA3C 0800023C */   lui       $v0, (0x80000 >> 16)
  .L8006EA40:
    /* 6240 8006EA40 24102202 */  and        $v0, $s1, $v0
    /* 6244 8006EA44 0D004010 */  beqz       $v0, .L8006EA7C
    /* 6248 8006EA48 0680023C */   lui       $v0, %hi(vs_main_buttonsPreviousState)
    /* 624C 8006EA4C 0C00658C */  lw         $a1, 0xC($v1)
    /* 6250 8006EA50 DF04010C */  jal        ratan2
    /* 6254 8006EA54 00000000 */   nop
    /* 6258 8006EA58 0F80033C */  lui        $v1, %hi(vs_battle_cameraCurrentSpherical)
    /* 625C 8006EA5C 21200000 */  addu       $a0, $zero, $zero
    /* 6260 8006EA60 D019638C */  lw         $v1, %lo(vs_battle_cameraCurrentSpherical)($v1)
    /* 6264 8006EA64 31000692 */  lbu        $a2, 0x31($s0)
    /* 6268 8006EA68 21104300 */  addu       $v0, $v0, $v1
    /* 626C 8006EA6C 00084224 */  addiu      $v0, $v0, 0x800
    /* 6270 8006EA70 FF0F4530 */  andi       $a1, $v0, 0xFFF
    /* 6274 8006EA74 F6BA0108 */  j          .L8006EBD8
    /* 6278 8006EA78 00330600 */   sll       $a2, $a2, 12
  .L8006EA7C:
    /* 627C 8006EA7C C0E1428C */  lw         $v0, %lo(vs_main_buttonsPreviousState)($v0)
    /* 6280 8006EA80 00000000 */  nop
    /* 6284 8006EA84 02004230 */  andi       $v0, $v0, 0x2
    /* 6288 8006EA88 1A004010 */  beqz       $v0, .L8006EAF4
    /* 628C 8006EA8C 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 6290 8006EA90 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 6294 8006EA94 00000000 */  nop
    /* 6298 8006EA98 80004230 */  andi       $v0, $v0, 0x80
    /* 629C 8006EA9C 09004010 */  beqz       $v0, .L8006EAC4
    /* 62A0 8006EAA0 00000000 */   nop
    /* 62A4 8006EAA4 0C00658C */  lw         $a1, 0xC($v1)
    /* 62A8 8006EAA8 DF04010C */  jal        ratan2
    /* 62AC 8006EAAC 00000000 */   nop
    /* 62B0 8006EAB0 0F80033C */  lui        $v1, %hi(vs_battle_cameraCurrentSpherical)
    /* 62B4 8006EAB4 D019638C */  lw         $v1, %lo(vs_battle_cameraCurrentSpherical)($v1)
    /* 62B8 8006EAB8 31000692 */  lbu        $a2, 0x31($s0)
    /* 62BC 8006EABC C9BA0108 */  j          .L8006EB24
    /* 62C0 8006EAC0 21200000 */   addu      $a0, $zero, $zero
  .L8006EAC4:
    /* 62C4 8006EAC4 0C00658C */  lw         $a1, 0xC($v1)
    /* 62C8 8006EAC8 DF04010C */  jal        ratan2
    /* 62CC 8006EACC 00000000 */   nop
    /* 62D0 8006EAD0 0F80033C */  lui        $v1, %hi(vs_battle_cameraCurrentSpherical)
    /* 62D4 8006EAD4 21200000 */  addu       $a0, $zero, $zero
    /* 62D8 8006EAD8 D019638C */  lw         $v1, %lo(vs_battle_cameraCurrentSpherical)($v1)
    /* 62DC 8006EADC 31000692 */  lbu        $a2, 0x31($s0)
    /* 62E0 8006EAE0 21104300 */  addu       $v0, $v0, $v1
    /* 62E4 8006EAE4 00084224 */  addiu      $v0, $v0, 0x800
    /* 62E8 8006EAE8 FF0F4530 */  andi       $a1, $v0, 0xFFF
    /* 62EC 8006EAEC F6BA0108 */  j          .L8006EBD8
    /* 62F0 8006EAF0 00330600 */   sll       $a2, $a2, 12
  .L8006EAF4:
    /* 62F4 8006EAF4 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 62F8 8006EAF8 00000000 */  nop
    /* 62FC 8006EAFC 80004230 */  andi       $v0, $v0, 0x80
    /* 6300 8006EB00 0F004010 */  beqz       $v0, .L8006EB40
    /* 6304 8006EB04 00000000 */   nop
    /* 6308 8006EB08 0C00658C */  lw         $a1, 0xC($v1)
    /* 630C 8006EB0C DF04010C */  jal        ratan2
    /* 6310 8006EB10 00000000 */   nop
    /* 6314 8006EB14 0F80033C */  lui        $v1, %hi(vs_battle_cameraCurrentSpherical)
    /* 6318 8006EB18 21200000 */  addu       $a0, $zero, $zero
    /* 631C 8006EB1C D019638C */  lw         $v1, %lo(vs_battle_cameraCurrentSpherical)($v1)
    /* 6320 8006EB20 33000692 */  lbu        $a2, 0x33($s0)
  .L8006EB24:
    /* 6324 8006EB24 21104300 */  addu       $v0, $v0, $v1
    /* 6328 8006EB28 00084224 */  addiu      $v0, $v0, 0x800
    /* 632C 8006EB2C FF0F4530 */  andi       $a1, $v0, 0xFFF
    /* 6330 8006EB30 3392020C */  jal        func_800A48CC
    /* 6334 8006EB34 00330600 */   sll       $a2, $a2, 12
    /* 6338 8006EB38 F8BA0108 */  j          .L8006EBE0
    /* 633C 8006EB3C 00000000 */   nop
  .L8006EB40:
    /* 6340 8006EB40 0C00658C */  lw         $a1, 0xC($v1)
    /* 6344 8006EB44 DF04010C */  jal        ratan2
    /* 6348 8006EB48 00000000 */   nop
    /* 634C 8006EB4C 0F80033C */  lui        $v1, %hi(vs_battle_cameraCurrentSpherical)
    /* 6350 8006EB50 21200000 */  addu       $a0, $zero, $zero
    /* 6354 8006EB54 D019638C */  lw         $v1, %lo(vs_battle_cameraCurrentSpherical)($v1)
    /* 6358 8006EB58 33000692 */  lbu        $a2, 0x33($s0)
    /* 635C 8006EB5C 21104300 */  addu       $v0, $v0, $v1
    /* 6360 8006EB60 00084224 */  addiu      $v0, $v0, 0x800
    /* 6364 8006EB64 FF0F4530 */  andi       $a1, $v0, 0xFFF
    /* 6368 8006EB68 F6BA0108 */  j          .L8006EBD8
    /* 636C 8006EB6C 00330600 */   sll       $a2, $a2, 12
  .L8006EB70:
    /* 6370 8006EB70 24102202 */  and        $v0, $s1, $v0
    /* 6374 8006EB74 13004014 */  bnez       $v0, .L8006EBC4
    /* 6378 8006EB78 21200000 */   addu      $a0, $zero, $zero
    /* 637C 8006EB7C 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 6380 8006EB80 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 6384 8006EB84 00000000 */  nop
    /* 6388 8006EB88 80004230 */  andi       $v0, $v0, 0x80
    /* 638C 8006EB8C 0D004010 */  beqz       $v0, .L8006EBC4
    /* 6390 8006EB90 00000000 */   nop
    /* 6394 8006EB94 DF04010C */  jal        ratan2
    /* 6398 8006EB98 21288000 */   addu      $a1, $a0, $zero
    /* 639C 8006EB9C 21200000 */  addu       $a0, $zero, $zero
    /* 63A0 8006EBA0 0F80033C */  lui        $v1, %hi(vs_battle_cameraCurrentSpherical)
    /* 63A4 8006EBA4 D019638C */  lw         $v1, %lo(vs_battle_cameraCurrentSpherical)($v1)
    /* 63A8 8006EBA8 21308000 */  addu       $a2, $a0, $zero
    /* 63AC 8006EBAC 21104300 */  addu       $v0, $v0, $v1
    /* 63B0 8006EBB0 00084224 */  addiu      $v0, $v0, 0x800
    /* 63B4 8006EBB4 3392020C */  jal        func_800A48CC
    /* 63B8 8006EBB8 FF0F4530 */   andi      $a1, $v0, 0xFFF
    /* 63BC 8006EBBC F8BA0108 */  j          .L8006EBE0
    /* 63C0 8006EBC0 00000000 */   nop
  .L8006EBC4:
    /* 63C4 8006EBC4 DF04010C */  jal        ratan2
    /* 63C8 8006EBC8 21288000 */   addu      $a1, $a0, $zero
    /* 63CC 8006EBCC 21200000 */  addu       $a0, $zero, $zero
    /* 63D0 8006EBD0 FF0F4530 */  andi       $a1, $v0, 0xFFF
  .L8006EBD4:
    /* 63D4 8006EBD4 21308000 */  addu       $a2, $a0, $zero
  .L8006EBD8:
    /* 63D8 8006EBD8 2AD9020C */  jal        func_800B64A8
    /* 63DC 8006EBDC 00000000 */   nop
  .L8006EBE0:
    /* 63E0 8006EBE0 4000BF8F */  lw         $ra, 0x40($sp)
    /* 63E4 8006EBE4 3C00B18F */  lw         $s1, 0x3C($sp)
    /* 63E8 8006EBE8 3800B08F */  lw         $s0, 0x38($sp)
    /* 63EC 8006EBEC 21100000 */  addu       $v0, $zero, $zero
    /* 63F0 8006EBF0 0800E003 */  jr         $ra
    /* 63F4 8006EBF4 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_8006E7F0
