nonmatching _loadSystemDat, 0x214

glabel _loadSystemDat
    /* 9C 800F989C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* A0 800F98A0 0200043C */  lui        $a0, (0x2E000 >> 16)
    /* A4 800F98A4 00E08434 */  ori        $a0, $a0, (0x2E000 & 0xFFFF)
    /* A8 800F98A8 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* AC 800F98AC 8F0F010C */  jal        vs_main_allocHeapR
    /* B0 800F98B0 1800B0AF */   sw        $s0, 0x18($sp)
    /* B4 800F98B4 6B050424 */  addiu      $a0, $zero, 0x56B
    /* B8 800F98B8 0200053C */  lui        $a1, (0x2E000 >> 16)
    /* BC 800F98BC 00E0A534 */  ori        $a1, $a1, (0x2E000 & 0xFFFF)
    /* C0 800F98C0 21804000 */  addu       $s0, $v0, $zero
    /* C4 800F98C4 4F12010C */  jal        vs_main_diskLoadFile
    /* C8 800F98C8 21300002 */   addu      $a2, $s0, $zero
    /* CC 800F98CC 0000028E */  lw         $v0, 0x0($s0)
    /* D0 800F98D0 00000000 */  nop
    /* D4 800F98D4 21180202 */  addu       $v1, $s0, $v0
    /* D8 800F98D8 00006294 */  lhu        $v0, 0x0($v1)
    /* DC 800F98DC 00000000 */  nop
    /* E0 800F98E0 1000A2A7 */  sh         $v0, 0x10($sp)
    /* E4 800F98E4 02006294 */  lhu        $v0, 0x2($v1)
    /* E8 800F98E8 00000000 */  nop
    /* EC 800F98EC 1200A2A7 */  sh         $v0, 0x12($sp)
    /* F0 800F98F0 04006294 */  lhu        $v0, 0x4($v1)
    /* F4 800F98F4 1000A427 */  addiu      $a0, $sp, 0x10
    /* F8 800F98F8 1400A2A7 */  sh         $v0, 0x14($sp)
    /* FC 800F98FC 06006294 */  lhu        $v0, 0x6($v1)
    /* 100 800F9900 08006524 */  addiu      $a1, $v1, 0x8
    /* 104 800F9904 3FA2000C */  jal        LoadImage
    /* 108 800F9908 1600A2A7 */   sh        $v0, 0x16($sp)
    /* 10C 800F990C 94A1000C */  jal        DrawSync
    /* 110 800F9910 21200000 */   addu      $a0, $zero, $zero
    /* 114 800F9914 0400028E */  lw         $v0, 0x4($s0)
    /* 118 800F9918 00000000 */  nop
    /* 11C 800F991C 21180202 */  addu       $v1, $s0, $v0
    /* 120 800F9920 00006294 */  lhu        $v0, 0x0($v1)
    /* 124 800F9924 00000000 */  nop
    /* 128 800F9928 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 12C 800F992C 02006294 */  lhu        $v0, 0x2($v1)
    /* 130 800F9930 00000000 */  nop
    /* 134 800F9934 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 138 800F9938 04006294 */  lhu        $v0, 0x4($v1)
    /* 13C 800F993C 1000A427 */  addiu      $a0, $sp, 0x10
    /* 140 800F9940 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 144 800F9944 06006294 */  lhu        $v0, 0x6($v1)
    /* 148 800F9948 08006524 */  addiu      $a1, $v1, 0x8
    /* 14C 800F994C 3FA2000C */  jal        LoadImage
    /* 150 800F9950 1600A2A7 */   sh        $v0, 0x16($sp)
    /* 154 800F9954 94A1000C */  jal        DrawSync
    /* 158 800F9958 21200000 */   addu      $a0, $zero, $zero
    /* 15C 800F995C 0F000524 */  addiu      $a1, $zero, 0xF
    /* 160 800F9960 0800028E */  lw         $v0, 0x8($s0)
    /* 164 800F9964 21300000 */  addu       $a2, $zero, $zero
    /* 168 800F9968 21180202 */  addu       $v1, $s0, $v0
    /* 16C 800F996C 00006784 */  lh         $a3, 0x0($v1)
    /* 170 800F9970 9922010C */  jal        vs_main_loadClut
    /* 174 800F9974 04006424 */   addiu     $a0, $v1, 0x4
    /* 178 800F9978 0C00028E */  lw         $v0, 0xC($s0)
    /* 17C 800F997C 00000000 */  nop
    /* 180 800F9980 21180202 */  addu       $v1, $s0, $v0
    /* 184 800F9984 00006294 */  lhu        $v0, 0x0($v1)
    /* 188 800F9988 00000000 */  nop
    /* 18C 800F998C 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 190 800F9990 02006294 */  lhu        $v0, 0x2($v1)
    /* 194 800F9994 00000000 */  nop
    /* 198 800F9998 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 19C 800F999C 04006294 */  lhu        $v0, 0x4($v1)
    /* 1A0 800F99A0 1000A427 */  addiu      $a0, $sp, 0x10
    /* 1A4 800F99A4 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 1A8 800F99A8 06006294 */  lhu        $v0, 0x6($v1)
    /* 1AC 800F99AC 08006524 */  addiu      $a1, $v1, 0x8
    /* 1B0 800F99B0 3FA2000C */  jal        LoadImage
    /* 1B4 800F99B4 1600A2A7 */   sh        $v0, 0x16($sp)
    /* 1B8 800F99B8 94A1000C */  jal        DrawSync
    /* 1BC 800F99BC 21200000 */   addu      $a0, $zero, $zero
    /* 1C0 800F99C0 1000028E */  lw         $v0, 0x10($s0)
    /* 1C4 800F99C4 00000000 */  nop
    /* 1C8 800F99C8 21180202 */  addu       $v1, $s0, $v0
    /* 1CC 800F99CC 00006294 */  lhu        $v0, 0x0($v1)
    /* 1D0 800F99D0 00000000 */  nop
    /* 1D4 800F99D4 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 1D8 800F99D8 02006294 */  lhu        $v0, 0x2($v1)
    /* 1DC 800F99DC 00000000 */  nop
    /* 1E0 800F99E0 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 1E4 800F99E4 04006294 */  lhu        $v0, 0x4($v1)
    /* 1E8 800F99E8 1000A427 */  addiu      $a0, $sp, 0x10
    /* 1EC 800F99EC 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 1F0 800F99F0 06006294 */  lhu        $v0, 0x6($v1)
    /* 1F4 800F99F4 08006524 */  addiu      $a1, $v1, 0x8
    /* 1F8 800F99F8 3FA2000C */  jal        LoadImage
    /* 1FC 800F99FC 1600A2A7 */   sh        $v0, 0x16($sp)
    /* 200 800F9A00 94A1000C */  jal        DrawSync
    /* 204 800F9A04 21200000 */   addu      $a0, $zero, $zero
    /* 208 800F9A08 1400028E */  lw         $v0, 0x14($s0)
    /* 20C 800F9A0C 00000000 */  nop
    /* 210 800F9A10 21180202 */  addu       $v1, $s0, $v0
    /* 214 800F9A14 00006294 */  lhu        $v0, 0x0($v1)
    /* 218 800F9A18 00000000 */  nop
    /* 21C 800F9A1C 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 220 800F9A20 02006294 */  lhu        $v0, 0x2($v1)
    /* 224 800F9A24 00000000 */  nop
    /* 228 800F9A28 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 22C 800F9A2C 04006294 */  lhu        $v0, 0x4($v1)
    /* 230 800F9A30 1000A427 */  addiu      $a0, $sp, 0x10
    /* 234 800F9A34 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 238 800F9A38 06006294 */  lhu        $v0, 0x6($v1)
    /* 23C 800F9A3C 08006524 */  addiu      $a1, $v1, 0x8
    /* 240 800F9A40 3FA2000C */  jal        LoadImage
    /* 244 800F9A44 1600A2A7 */   sh        $v0, 0x16($sp)
    /* 248 800F9A48 94A1000C */  jal        DrawSync
    /* 24C 800F9A4C 21200000 */   addu      $a0, $zero, $zero
    /* 250 800F9A50 1800038E */  lw         $v1, 0x18($s0)
    /* 254 800F9A54 00030224 */  addiu      $v0, $zero, 0x300
    /* 258 800F9A58 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 25C 800F9A5C F0000224 */  addiu      $v0, $zero, 0xF0
    /* 260 800F9A60 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 264 800F9A64 21180302 */  addu       $v1, $s0, $v1
    /* 268 800F9A68 00006294 */  lhu        $v0, 0x0($v1)
    /* 26C 800F9A6C 1000A427 */  addiu      $a0, $sp, 0x10
    /* 270 800F9A70 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 274 800F9A74 02006294 */  lhu        $v0, 0x2($v1)
    /* 278 800F9A78 04006524 */  addiu      $a1, $v1, 0x4
    /* 27C 800F9A7C 3FA2000C */  jal        LoadImage
    /* 280 800F9A80 1600A2A7 */   sh        $v0, 0x16($sp)
    /* 284 800F9A84 94A1000C */  jal        DrawSync
    /* 288 800F9A88 21200000 */   addu      $a0, $zero, $zero
    /* 28C 800F9A8C 1C00048E */  lw         $a0, 0x1C($s0)
    /* 290 800F9A90 702A030C */  jal        func_800CA9C0
    /* 294 800F9A94 21200402 */   addu      $a0, $s0, $a0
    /* 298 800F9A98 180F010C */  jal        vs_main_freeHeapR
    /* 29C 800F9A9C 21200002 */   addu      $a0, $s0, $zero
    /* 2A0 800F9AA0 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 2A4 800F9AA4 1800B08F */  lw         $s0, 0x18($sp)
    /* 2A8 800F9AA8 0800E003 */  jr         $ra
    /* 2AC 800F9AAC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _loadSystemDat
