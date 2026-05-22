nonmatching func_800FA7B0, 0x2FC

glabel func_800FA7B0
    /* FB0 800FA7B0 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* FB4 800FA7B4 0F80023C */  lui        $v0, %hi(D_800E8FC0)
    /* FB8 800FA7B8 2400B1AF */  sw         $s1, 0x24($sp)
    /* FBC 800FA7BC 0F001124 */  addiu      $s1, $zero, 0xF
    /* FC0 800FA7C0 C08F40A0 */  sb         $zero, %lo(D_800E8FC0)($v0)
    /* FC4 800FA7C4 0F80023C */  lui        $v0, %hi(vs_battle_objectDataSlots)
    /* FC8 800FA7C8 10234224 */  addiu      $v0, $v0, %lo(vs_battle_objectDataSlots)
    /* FCC 800FA7CC 2C014224 */  addiu      $v0, $v0, 0x12C
    /* FD0 800FA7D0 3000BFAF */  sw         $ra, 0x30($sp)
    /* FD4 800FA7D4 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* FD8 800FA7D8 2800B2AF */  sw         $s2, 0x28($sp)
    /* FDC 800FA7DC 2000B0AF */  sw         $s0, 0x20($sp)
  .L800FA7E0:
    /* FE0 800FA7E0 000040A0 */  sb         $zero, 0x0($v0)
    /* FE4 800FA7E4 FFFF3126 */  addiu      $s1, $s1, -0x1
    /* FE8 800FA7E8 FDFF2106 */  bgez       $s1, .L800FA7E0
    /* FEC 800FA7EC ECFF4224 */   addiu     $v0, $v0, -0x14
    /* FF0 800FA7F0 21880000 */  addu       $s1, $zero, $zero
    /* FF4 800FA7F4 0F80023C */  lui        $v0, %hi(D_800F46A8)
    /* FF8 800FA7F8 A8465024 */  addiu      $s0, $v0, %lo(D_800F46A8)
    /* FFC 800FA7FC 0F80023C */  lui        $v0, %hi(D_800E8F30)
    /* 1000 800FA800 308F4224 */  addiu      $v0, $v0, %lo(D_800E8F30)
    /* 1004 800FA804 02005324 */  addiu      $s3, $v0, 0x2
    /* 1008 800FA808 21904000 */  addu       $s2, $v0, $zero
  .L800FA80C:
    /* 100C 800FA80C 21200000 */  addu       $a0, $zero, $zero
    /* 1010 800FA810 21288000 */  addu       $a1, $a0, $zero
    /* 1014 800FA814 00006786 */  lh         $a3, 0x0($s3)
    /* 1018 800FA818 04007326 */  addiu      $s3, $s3, 0x4
    /* 101C 800FA81C 00004686 */  lh         $a2, 0x0($s2)
    /* 1020 800FA820 04005226 */  addiu      $s2, $s2, 0x4
    /* 1024 800FA824 80310600 */  sll        $a2, $a2, 6
    /* 1028 800FA828 1DAD000C */  jal        GetTPage
    /* 102C 800FA82C 003A0700 */   sll       $a3, $a3, 8
    /* 1030 800FA830 00030424 */  addiu      $a0, $zero, 0x300
    /* 1034 800FA834 E4002526 */  addiu      $a1, $s1, 0xE4
    /* 1038 800FA838 2DAD000C */  jal        GetClut
    /* 103C 800FA83C 000002A6 */   sh        $v0, 0x0($s0)
    /* 1040 800FA840 00030424 */  addiu      $a0, $zero, 0x300
    /* 1044 800FA844 F6002526 */  addiu      $a1, $s1, 0xF6
    /* 1048 800FA848 2DAD000C */  jal        GetClut
    /* 104C 800FA84C 020002A6 */   sh        $v0, 0x2($s0)
    /* 1050 800FA850 040002A6 */  sh         $v0, 0x4($s0)
    /* 1054 800FA854 060000A2 */  sb         $zero, 0x6($s0)
    /* 1058 800FA858 01003126 */  addiu      $s1, $s1, 0x1
    /* 105C 800FA85C 0C00222A */  slti       $v0, $s1, 0xC
    /* 1060 800FA860 EAFF4014 */  bnez       $v0, .L800FA80C
    /* 1064 800FA864 08001026 */   addiu     $s0, $s0, 0x8
    /* 1068 800FA868 1800222A */  slti       $v0, $s1, 0x18
    /* 106C 800FA86C 21004010 */  beqz       $v0, .L800FA8F4
    /* 1070 800FA870 C0181100 */   sll       $v1, $s1, 3
    /* 1074 800FA874 0F80023C */  lui        $v0, %hi(D_800F46A8)
    /* 1078 800FA878 A8464224 */  addiu      $v0, $v0, %lo(D_800F46A8)
    /* 107C 800FA87C 21806200 */  addu       $s0, $v1, $v0
    /* 1080 800FA880 0F80023C */  lui        $v0, %hi(D_800E8F30)
    /* 1084 800FA884 308F4224 */  addiu      $v0, $v0, %lo(D_800E8F30)
    /* 1088 800FA888 02004424 */  addiu      $a0, $v0, 0x2
    /* 108C 800FA88C 80181100 */  sll        $v1, $s1, 2
    /* 1090 800FA890 21986400 */  addu       $s3, $v1, $a0
    /* 1094 800FA894 21906200 */  addu       $s2, $v1, $v0
  .L800FA898:
    /* 1098 800FA898 21200000 */  addu       $a0, $zero, $zero
    /* 109C 800FA89C 21288000 */  addu       $a1, $a0, $zero
    /* 10A0 800FA8A0 00006786 */  lh         $a3, 0x0($s3)
    /* 10A4 800FA8A4 04007326 */  addiu      $s3, $s3, 0x4
    /* 10A8 800FA8A8 00004686 */  lh         $a2, 0x0($s2)
    /* 10AC 800FA8AC 04005226 */  addiu      $s2, $s2, 0x4
    /* 10B0 800FA8B0 01003126 */  addiu      $s1, $s1, 0x1
    /* 10B4 800FA8B4 80310600 */  sll        $a2, $a2, 6
    /* 10B8 800FA8B8 1DAD000C */  jal        GetTPage
    /* 10BC 800FA8BC 003A0700 */   sll       $a3, $a3, 8
    /* 10C0 800FA8C0 00030424 */  addiu      $a0, $zero, 0x300
    /* 10C4 800FA8C4 E5000524 */  addiu      $a1, $zero, 0xE5
    /* 10C8 800FA8C8 2DAD000C */  jal        GetClut
    /* 10CC 800FA8CC 000002A6 */   sh        $v0, 0x0($s0)
    /* 10D0 800FA8D0 00030424 */  addiu      $a0, $zero, 0x300
    /* 10D4 800FA8D4 F7000524 */  addiu      $a1, $zero, 0xF7
    /* 10D8 800FA8D8 2DAD000C */  jal        GetClut
    /* 10DC 800FA8DC 020002A6 */   sh        $v0, 0x2($s0)
    /* 10E0 800FA8E0 040002A6 */  sh         $v0, 0x4($s0)
    /* 10E4 800FA8E4 060000A2 */  sb         $zero, 0x6($s0)
    /* 10E8 800FA8E8 1800222A */  slti       $v0, $s1, 0x18
    /* 10EC 800FA8EC EAFF4014 */  bnez       $v0, .L800FA898
    /* 10F0 800FA8F0 08001026 */   addiu     $s0, $s0, 0x8
  .L800FA8F4:
    /* 10F4 800FA8F4 10001124 */  addiu      $s1, $zero, 0x10
    /* 10F8 800FA8F8 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 10FC 800FA8FC 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 1100 800FA900 40004224 */  addiu      $v0, $v0, 0x40
  .L800FA904:
    /* 1104 800FA904 000040AC */  sw         $zero, 0x0($v0)
    /* 1108 800FA908 FFFF3126 */  addiu      $s1, $s1, -0x1
    /* 110C 800FA90C FDFF2106 */  bgez       $s1, .L800FA904
    /* 1110 800FA910 FCFF4224 */   addiu     $v0, $v0, -0x4
    /* 1114 800FA914 B10F010C */  jal        vs_main_allocHeap
    /* 1118 800FA918 00780424 */   addiu     $a0, $zero, 0x7800
    /* 111C 800FA91C 00480424 */  addiu      $a0, $zero, 0x4800
    /* 1120 800FA920 0F80033C */  lui        $v1, %hi(D_800F4930)
    /* 1124 800FA924 B10F010C */  jal        vs_main_allocHeap
    /* 1128 800FA928 304962AC */   sw        $v0, %lo(D_800F4930)($v1)
    /* 112C 800FA92C 21880000 */  addu       $s1, $zero, $zero
    /* 1130 800FA930 0F80033C */  lui        $v1, %hi(D_800F4770)
    /* 1134 800FA934 70477224 */  addiu      $s2, $v1, %lo(D_800F4770)
    /* 1138 800FA938 0F80033C */  lui        $v1, %hi(D_800F4768)
    /* 113C 800FA93C 684762AC */  sw         $v0, %lo(D_800F4768)($v1)
  .L800FA940:
    /* 1140 800FA940 01000424 */  addiu      $a0, $zero, 0x1
    /* 1144 800FA944 21280000 */  addu       $a1, $zero, $zero
    /* 1148 800FA948 C2871100 */  srl        $s0, $s1, 31
    /* 114C 800FA94C 21803002 */  addu       $s0, $s1, $s0
    /* 1150 800FA950 43801000 */  sra        $s0, $s0, 1
    /* 1154 800FA954 80311000 */  sll        $a2, $s0, 6
    /* 1158 800FA958 1DAD000C */  jal        GetTPage
    /* 115C 800FA95C 2138A000 */   addu      $a3, $a1, $zero
    /* 1160 800FA960 01002332 */  andi       $v1, $s1, 0x1
    /* 1164 800FA964 40200300 */  sll        $a0, $v1, 1
    /* 1168 800FA968 21208300 */  addu       $a0, $a0, $v1
    /* 116C 800FA96C 00210400 */  sll        $a0, $a0, 4
    /* 1170 800FA970 A0038424 */  addiu      $a0, $a0, 0x3A0
    /* 1174 800FA974 E4000526 */  addiu      $a1, $s0, 0xE4
    /* 1178 800FA978 2DAD000C */  jal        GetClut
    /* 117C 800FA97C 000042A6 */   sh        $v0, 0x0($s2)
    /* 1180 800FA980 020042A6 */  sh         $v0, 0x2($s2)
    /* 1184 800FA984 060040A2 */  sb         $zero, 0x6($s2)
    /* 1188 800FA988 01003126 */  addiu      $s1, $s1, 0x1
    /* 118C 800FA98C 1400222A */  slti       $v0, $s1, 0x14
    /* 1190 800FA990 EBFF4014 */  bnez       $v0, .L800FA940
    /* 1194 800FA994 08005226 */   addiu     $s2, $s2, 0x8
    /* 1198 800FA998 13001124 */  addiu      $s1, $zero, 0x13
    /* 119C 800FA99C 0F80023C */  lui        $v0, %hi(D_800F4588)
    /* 11A0 800FA9A0 88454224 */  addiu      $v0, $v0, %lo(D_800F4588)
    /* 11A4 800FA9A4 4C004224 */  addiu      $v0, $v0, 0x4C
  .L800FA9A8:
    /* 11A8 800FA9A8 000040AC */  sw         $zero, 0x0($v0)
    /* 11AC 800FA9AC FFFF3126 */  addiu      $s1, $s1, -0x1
    /* 11B0 800FA9B0 FDFF2106 */  bgez       $s1, .L800FA9A8
    /* 11B4 800FA9B4 FCFF4224 */   addiu     $v0, $v0, -0x4
    /* 11B8 800FA9B8 21880000 */  addu       $s1, $zero, $zero
    /* 11BC 800FA9BC 0F80023C */  lui        $v0, %hi(D_800F4620)
    /* 11C0 800FA9C0 20465024 */  addiu      $s0, $v0, %lo(D_800F4620)
  .L800FA9C4:
    /* 11C4 800FA9C4 B10F010C */  jal        vs_main_allocHeap
    /* 11C8 800FA9C8 00080424 */   addiu     $a0, $zero, 0x800
    /* 11CC 800FA9CC 000002AE */  sw         $v0, 0x0($s0)
    /* 11D0 800FA9D0 01003126 */  addiu      $s1, $s1, 0x1
    /* 11D4 800FA9D4 0200222A */  slti       $v0, $s1, 0x2
    /* 11D8 800FA9D8 FAFF4014 */  bnez       $v0, .L800FA9C4
    /* 11DC 800FA9DC 04001026 */   addiu     $s0, $s0, 0x4
    /* 11E0 800FA9E0 0F001124 */  addiu      $s1, $zero, 0xF
    /* 11E4 800FA9E4 0F80023C */  lui        $v0, %hi(D_800F45E0)
    /* 11E8 800FA9E8 E0454224 */  addiu      $v0, $v0, %lo(D_800F45E0)
    /* 11EC 800FA9EC 3C004224 */  addiu      $v0, $v0, 0x3C
  .L800FA9F0:
    /* 11F0 800FA9F0 000040AC */  sw         $zero, 0x0($v0)
    /* 11F4 800FA9F4 FFFF3126 */  addiu      $s1, $s1, -0x1
    /* 11F8 800FA9F8 FDFF2106 */  bgez       $s1, .L800FA9F0
    /* 11FC 800FA9FC FCFF4224 */   addiu     $v0, $v0, -0x4
    /* 1200 800FAA00 1000A427 */  addiu      $a0, $sp, 0x10
    /* 1204 800FAA04 0F80033C */  lui        $v1, %hi(D_800E8F2C)
    /* 1208 800FAA08 0F80023C */  lui        $v0, %hi(D_800F2450)
    /* 120C 800FAA0C 502440A0 */  sb         $zero, %lo(D_800F2450)($v0)
    /* 1210 800FAA10 50244224 */  addiu      $v0, $v0, %lo(D_800F2450)
    /* 1214 800FAA14 2C8F60A0 */  sb         $zero, %lo(D_800E8F2C)($v1)
    /* 1218 800FAA18 010040A0 */  sb         $zero, 0x1($v0)
    /* 121C 800FAA1C 020040A0 */  sb         $zero, 0x2($v0)
    /* 1220 800FAA20 0F80023C */  lui        $v0, %hi(D_800F4528)
    /* 1224 800FAA24 284540AC */  sw         $zero, %lo(D_800F4528)($v0)
    /* 1228 800FAA28 28454224 */  addiu      $v0, $v0, %lo(D_800F4528)
    /* 122C 800FAA2C 040040AC */  sw         $zero, 0x4($v0)
    /* 1230 800FAA30 080040AC */  sw         $zero, 0x8($v0)
    /* 1234 800FAA34 0F80023C */  lui        $v0, %hi(D_800E8F2B)
    /* 1238 800FAA38 2B8F40A0 */  sb         $zero, %lo(D_800E8F2B)($v0)
    /* 123C 800FAA3C 0F80023C */  lui        $v0, %hi(D_800E8F2D)
    /* 1240 800FAA40 2D8F40A0 */  sb         $zero, %lo(D_800E8F2D)($v0)
    /* 1244 800FAA44 0F80023C */  lui        $v0, %hi(D_800E8FC0)
    /* 1248 800FAA48 C08F40A0 */  sb         $zero, %lo(D_800E8FC0)($v0)
    /* 124C 800FAA4C 0F80023C */  lui        $v0, %hi(D_800E8F29)
    /* 1250 800FAA50 298F40A0 */  sb         $zero, %lo(D_800E8F29)($v0)
    /* 1254 800FAA54 0F80023C */  lui        $v0, %hi(D_800E8F28)
    /* 1258 800FAA58 288F40A0 */  sb         $zero, %lo(D_800E8F28)($v0)
    /* 125C 800FAA5C 0F80023C */  lui        $v0, %hi(D_800E8F2A)
    /* 1260 800FAA60 2A8F40A0 */  sb         $zero, %lo(D_800E8F2A)($v0)
    /* 1264 800FAA64 00100224 */  addiu      $v0, $zero, 0x1000
    /* 1268 800FAA68 2C8F60A0 */  sb         $zero, %lo(D_800E8F2C)($v1)
    /* 126C 800FAA6C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1270 800FAA70 1400A2AF */  sw         $v0, 0x14($sp)
    /* 1274 800FAA74 D97E020C */  jal        func_8009FB64
    /* 1278 800FAA78 1800A2AF */   sw        $v0, 0x18($sp)
    /* 127C 800FAA7C 0F80023C */  lui        $v0, %hi(D_800F4B19)
    /* 1280 800FAA80 194B40A0 */  sb         $zero, %lo(D_800F4B19)($v0)
    /* 1284 800FAA84 0F80023C */  lui        $v0, %hi(D_800F4B18)
    /* 1288 800FAA88 184B40A0 */  sb         $zero, %lo(D_800F4B18)($v0)
    /* 128C 800FAA8C 3000BF8F */  lw         $ra, 0x30($sp)
    /* 1290 800FAA90 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 1294 800FAA94 2800B28F */  lw         $s2, 0x28($sp)
    /* 1298 800FAA98 2400B18F */  lw         $s1, 0x24($sp)
    /* 129C 800FAA9C 2000B08F */  lw         $s0, 0x20($sp)
    /* 12A0 800FAAA0 3800BD27 */  addiu      $sp, $sp, 0x38
    /* 12A4 800FAAA4 0800E003 */  jr         $ra
    /* 12A8 800FAAA8 00000000 */   nop
endlabel func_800FA7B0
