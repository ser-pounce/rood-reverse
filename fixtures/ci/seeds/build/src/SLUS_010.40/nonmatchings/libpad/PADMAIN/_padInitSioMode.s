nonmatching _padInitSioMode, 0x334

glabel _padInitSioMode
    /* 1C904 8002C104 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1C908 8002C108 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1C90C 8002C10C 21808000 */  addu       $s0, $a0, $zero
    /* 1C910 8002C110 0380033C */  lui        $v1, %hi(D_80033600)
    /* 1C914 8002C114 0036638C */  lw         $v1, %lo(D_80033600)($v1)
    /* 1C918 8002C118 40000224 */  addiu      $v0, $zero, 0x40
    /* 1C91C 8002C11C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1C920 8002C120 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1C924 8002C124 0A0062A4 */  sh         $v0, 0xA($v1)
    /* 1C928 8002C128 0D000224 */  addiu      $v0, $zero, 0xD
    /* 1C92C 8002C12C 0A0060A4 */  sh         $zero, 0xA($v1)
    /* 1C930 8002C130 080062A4 */  sh         $v0, 0x8($v1)
    /* 1C934 8002C134 88000224 */  addiu      $v0, $zero, 0x88
    /* 1C938 8002C138 0E0062A4 */  sh         $v0, 0xE($v1)
    /* 1C93C 8002C13C E8000392 */  lbu        $v1, 0xE8($s0)
    /* 1C940 8002C140 08000224 */  addiu      $v0, $zero, 0x8
    /* 1C944 8002C144 02006214 */  bne        $v1, $v0, .L8002C150
    /* 1C948 8002C148 91000424 */   addiu     $a0, $zero, 0x91
    /* 1C94C 8002C14C 50000424 */  addiu      $a0, $zero, 0x50
  .L8002C150:
    /* 1C950 8002C150 FDB9000C */  jal        setRC2wait
    /* 1C954 8002C154 00000000 */   nop
    /* 1C958 8002C158 0380023C */  lui        $v0, %hi(D_800335DC)
    /* 1C95C 8002C15C DC35428C */  lw         $v0, %lo(D_800335DC)($v0)
    /* 1C960 8002C160 0380043C */  lui        $a0, %hi(D_80033600)
    /* 1C964 8002C164 0036848C */  lw         $a0, %lo(D_80033600)($a0)
    /* 1C968 8002C168 02004010 */  beqz       $v0, .L8002C174
    /* 1C96C 8002C16C 03100324 */   addiu     $v1, $zero, 0x1003
    /* 1C970 8002C170 03300324 */  addiu      $v1, $zero, 0x3003
  .L8002C174:
    /* 1C974 8002C174 80100200 */  sll        $v0, $v0, 2
    /* 1C978 8002C178 0A0083A4 */  sh         $v1, 0xA($a0)
    /* 1C97C 8002C17C 0380013C */  lui        $at, %hi(D_800335F4)
    /* 1C980 8002C180 21082200 */  addu       $at, $at, $v0
    /* 1C984 8002C184 F435228C */  lw         $v0, %lo(D_800335F4)($at)
    /* 1C988 8002C188 0380033C */  lui        $v1, %hi(D_800335F4)
    /* 1C98C 8002C18C 34004004 */  bltz       $v0, .L8002C260
    /* 1C990 8002C190 F4356324 */   addiu     $v1, $v1, %lo(D_800335F4)
    /* 1C994 8002C194 1D004018 */  blez       $v0, .L8002C20C
    /* 1C998 8002C198 00000000 */   nop
    /* 1C99C 8002C19C 21886000 */  addu       $s1, $v1, $zero
  .L8002C1A0:
    /* 1C9A0 8002C1A0 0380033C */  lui        $v1, %hi(D_800335DC)
    /* 1C9A4 8002C1A4 DC35638C */  lw         $v1, %lo(D_800335DC)($v1)
    /* 1C9A8 8002C1A8 00000000 */  nop
    /* 1C9AC 8002C1AC 80180300 */  sll        $v1, $v1, 2
    /* 1C9B0 8002C1B0 21187100 */  addu       $v1, $v1, $s1
    /* 1C9B4 8002C1B4 0000628C */  lw         $v0, 0x0($v1)
    /* 1C9B8 8002C1B8 00000000 */  nop
    /* 1C9BC 8002C1BC FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 1C9C0 8002C1C0 00210200 */  sll        $a0, $v0, 4
    /* 1C9C4 8002C1C4 23208200 */  subu       $a0, $a0, $v0
    /* 1C9C8 8002C1C8 00210400 */  sll        $a0, $a0, 4
    /* 1C9CC 8002C1CC 000062AC */  sw         $v0, 0x0($v1)
    /* 1C9D0 8002C1D0 0C00028E */  lw         $v0, 0xC($s0)
    /* 1C9D4 8002C1D4 0380033C */  lui        $v1, %hi(D_800335BC)
    /* 1C9D8 8002C1D8 BC35638C */  lw         $v1, %lo(D_800335BC)($v1)
    /* 1C9DC 8002C1DC 00000000 */  nop
    /* 1C9E0 8002C1E0 09F86000 */  jalr       $v1
    /* 1C9E4 8002C1E4 21204400 */   addu      $a0, $v0, $a0
    /* 1C9E8 8002C1E8 0380023C */  lui        $v0, %hi(D_800335DC)
    /* 1C9EC 8002C1EC DC35428C */  lw         $v0, %lo(D_800335DC)($v0)
    /* 1C9F0 8002C1F0 00000000 */  nop
    /* 1C9F4 8002C1F4 80100200 */  sll        $v0, $v0, 2
    /* 1C9F8 8002C1F8 21105100 */  addu       $v0, $v0, $s1
    /* 1C9FC 8002C1FC 0000428C */  lw         $v0, 0x0($v0)
    /* 1CA00 8002C200 00000000 */  nop
    /* 1CA04 8002C204 E6FF401C */  bgtz       $v0, .L8002C1A0
    /* 1CA08 8002C208 00000000 */   nop
  .L8002C20C:
    /* 1CA0C 8002C20C 0380023C */  lui        $v0, %hi(D_800335DC)
    /* 1CA10 8002C210 DC35428C */  lw         $v0, %lo(D_800335DC)($v0)
    /* 1CA14 8002C214 0380033C */  lui        $v1, %hi(D_800335F4)
    /* 1CA18 8002C218 F4356324 */  addiu      $v1, $v1, %lo(D_800335F4)
    /* 1CA1C 8002C21C 80100200 */  sll        $v0, $v0, 2
    /* 1CA20 8002C220 21284300 */  addu       $a1, $v0, $v1
    /* 1CA24 8002C224 0000A28C */  lw         $v0, 0x0($a1)
    /* 1CA28 8002C228 00000000 */  nop
    /* 1CA2C 8002C22C 0C004014 */  bnez       $v0, .L8002C260
    /* 1CA30 8002C230 FFFF0324 */   addiu     $v1, $zero, -0x1
    /* 1CA34 8002C234 21200002 */  addu       $a0, $s0, $zero
    /* 1CA38 8002C238 0380023C */  lui        $v0, %hi(D_800335BC)
    /* 1CA3C 8002C23C BC35428C */  lw         $v0, %lo(D_800335BC)($v0)
    /* 1CA40 8002C240 00000000 */  nop
    /* 1CA44 8002C244 09F84000 */  jalr       $v0
    /* 1CA48 8002C248 0000A3AC */   sw        $v1, 0x0($a1)
    /* 1CA4C 8002C24C 0380023C */  lui        $v0, %hi(D_800335C0)
    /* 1CA50 8002C250 C035428C */  lw         $v0, %lo(D_800335C0)($v0)
    /* 1CA54 8002C254 00000000 */  nop
    /* 1CA58 8002C258 09F84000 */  jalr       $v0
    /* 1CA5C 8002C25C 21200002 */   addu      $a0, $s0, $zero
  .L8002C260:
    /* 1CA60 8002C260 0380033C */  lui        $v1, %hi(D_80033600)
    /* 1CA64 8002C264 0036638C */  lw         $v1, %lo(D_80033600)($v1)
    /* 1CA68 8002C268 00000000 */  nop
    /* 1CA6C 8002C26C 04006294 */  lhu        $v0, 0x4($v1)
    /* 1CA70 8002C270 00000000 */  nop
    /* 1CA74 8002C274 00024230 */  andi       $v0, $v0, 0x200
    /* 1CA78 8002C278 61004010 */  beqz       $v0, .L8002C400
    /* 1CA7C 8002C27C 00000000 */   nop
    /* 1CA80 8002C280 0A006294 */  lhu        $v0, 0xA($v1)
    /* 1CA84 8002C284 00000000 */  nop
    /* 1CA88 8002C288 10004234 */  ori        $v0, $v0, 0x10
    /* 1CA8C 8002C28C 0A0062A4 */  sh         $v0, 0xA($v1)
    /* 1CA90 8002C290 04006294 */  lhu        $v0, 0x4($v1)
    /* 1CA94 8002C294 00000000 */  nop
    /* 1CA98 8002C298 00024230 */  andi       $v0, $v0, 0x200
    /* 1CA9C 8002C29C 54004010 */  beqz       $v0, .L8002C3F0
    /* 1CAA0 8002C2A0 7FFF0224 */   addiu     $v0, $zero, -0x81
  .L8002C2A4:
    /* 1CAA4 8002C2A4 05BA000C */  jal        chkRC2wait
    /* 1CAA8 8002C2A8 00000000 */   nop
    /* 1CAAC 8002C2AC FDFF4010 */  beqz       $v0, .L8002C2A4
    /* 1CAB0 8002C2B0 D0070424 */   addiu     $a0, $zero, 0x7D0
    /* 1CAB4 8002C2B4 0380033C */  lui        $v1, %hi(D_80033600)
    /* 1CAB8 8002C2B8 0036638C */  lw         $v1, %lo(D_80033600)($v1)
    /* 1CABC 8002C2BC 01000224 */  addiu      $v0, $zero, 0x1
    /* 1CAC0 8002C2C0 FDB9000C */  jal        setRC2wait
    /* 1CAC4 8002C2C4 000062A0 */   sb        $v0, 0x0($v1)
    /* 1CAC8 8002C2C8 6CB2000C */  jal        _padClrIntSio0
    /* 1CACC 8002C2CC 00000000 */   nop
    /* 1CAD0 8002C2D0 54004010 */  beqz       $v0, .L8002C424
    /* 1CAD4 8002C2D4 21100000 */   addu      $v0, $zero, $zero
    /* 1CAD8 8002C2D8 90B2000C */  jal        _padWaitRXready
    /* 1CADC 8002C2DC 00000000 */   nop
    /* 1CAE0 8002C2E0 0380023C */  lui        $v0, %hi(D_80033600)
    /* 1CAE4 8002C2E4 0036428C */  lw         $v0, %lo(D_80033600)($v0)
    /* 1CAE8 8002C2E8 AE010424 */  addiu      $a0, $zero, 0x1AE
    /* 1CAEC 8002C2EC 00004290 */  lbu        $v0, 0x0($v0)
    /* 1CAF0 8002C2F0 FDB9000C */  jal        setRC2wait
    /* 1CAF4 8002C2F4 00000000 */   nop
    /* 1CAF8 8002C2F8 C4B00008 */  j          .L8002C310
    /* 1CAFC 8002C2FC 00000000 */   nop
  .L8002C300:
    /* 1CB00 8002C300 05BA000C */  jal        chkRC2wait
    /* 1CB04 8002C304 00000000 */   nop
    /* 1CB08 8002C308 46004014 */  bnez       $v0, .L8002C424
    /* 1CB0C 8002C30C 21100000 */   addu      $v0, $zero, $zero
  .L8002C310:
    /* 1CB10 8002C310 0380023C */  lui        $v0, %hi(D_800335FC)
    /* 1CB14 8002C314 FC35428C */  lw         $v0, %lo(D_800335FC)($v0)
    /* 1CB18 8002C318 00000000 */  nop
    /* 1CB1C 8002C31C 0000428C */  lw         $v0, 0x0($v0)
    /* 1CB20 8002C320 00000000 */  nop
    /* 1CB24 8002C324 80004230 */  andi       $v0, $v0, 0x80
    /* 1CB28 8002C328 F5FF4010 */  beqz       $v0, .L8002C300
    /* 1CB2C 8002C32C 3C000424 */   addiu     $a0, $zero, 0x3C
    /* 1CB30 8002C330 0380033C */  lui        $v1, %hi(D_80033600)
    /* 1CB34 8002C334 0036638C */  lw         $v1, %lo(D_80033600)($v1)
    /* 1CB38 8002C338 42000224 */  addiu      $v0, $zero, 0x42
    /* 1CB3C 8002C33C FDB9000C */  jal        setRC2wait
    /* 1CB40 8002C340 000062A0 */   sb        $v0, 0x0($v1)
    /* 1CB44 8002C344 6CB2000C */  jal        _padClrIntSio0
    /* 1CB48 8002C348 00000000 */   nop
    /* 1CB4C 8002C34C 35004010 */  beqz       $v0, .L8002C424
    /* 1CB50 8002C350 21100000 */   addu      $v0, $zero, $zero
    /* 1CB54 8002C354 90B2000C */  jal        _padWaitRXready
    /* 1CB58 8002C358 00000000 */   nop
    /* 1CB5C 8002C35C 0380023C */  lui        $v0, %hi(D_80033600)
    /* 1CB60 8002C360 0036428C */  lw         $v0, %lo(D_80033600)($v0)
    /* 1CB64 8002C364 AE010424 */  addiu      $a0, $zero, 0x1AE
    /* 1CB68 8002C368 00004290 */  lbu        $v0, 0x0($v0)
    /* 1CB6C 8002C36C FDB9000C */  jal        setRC2wait
    /* 1CB70 8002C370 00000000 */   nop
    /* 1CB74 8002C374 E3B00008 */  j          .L8002C38C
    /* 1CB78 8002C378 00000000 */   nop
  .L8002C37C:
    /* 1CB7C 8002C37C 05BA000C */  jal        chkRC2wait
    /* 1CB80 8002C380 00000000 */   nop
    /* 1CB84 8002C384 27004014 */  bnez       $v0, .L8002C424
    /* 1CB88 8002C388 21100000 */   addu      $v0, $zero, $zero
  .L8002C38C:
    /* 1CB8C 8002C38C 0380023C */  lui        $v0, %hi(D_800335FC)
    /* 1CB90 8002C390 FC35428C */  lw         $v0, %lo(D_800335FC)($v0)
    /* 1CB94 8002C394 00000000 */  nop
    /* 1CB98 8002C398 0000428C */  lw         $v0, 0x0($v0)
    /* 1CB9C 8002C39C 00000000 */  nop
    /* 1CBA0 8002C3A0 80004230 */  andi       $v0, $v0, 0x80
    /* 1CBA4 8002C3A4 F5FF4010 */  beqz       $v0, .L8002C37C
    /* 1CBA8 8002C3A8 3C000424 */   addiu     $a0, $zero, 0x3C
    /* 1CBAC 8002C3AC 0380033C */  lui        $v1, %hi(D_80033600)
    /* 1CBB0 8002C3B0 0036638C */  lw         $v1, %lo(D_80033600)($v1)
    /* 1CBB4 8002C3B4 01000224 */  addiu      $v0, $zero, 0x1
    /* 1CBB8 8002C3B8 FDB9000C */  jal        setRC2wait
    /* 1CBBC 8002C3BC 000062A0 */   sb        $v0, 0x0($v1)
    /* 1CBC0 8002C3C0 6CB2000C */  jal        _padClrIntSio0
    /* 1CBC4 8002C3C4 00000000 */   nop
    /* 1CBC8 8002C3C8 16004010 */  beqz       $v0, .L8002C424
    /* 1CBCC 8002C3CC 21100000 */   addu      $v0, $zero, $zero
    /* 1CBD0 8002C3D0 90B2000C */  jal        _padWaitRXready
    /* 1CBD4 8002C3D4 00000000 */   nop
    /* 1CBD8 8002C3D8 0380033C */  lui        $v1, %hi(D_80033600)
    /* 1CBDC 8002C3DC 0036638C */  lw         $v1, %lo(D_80033600)($v1)
    /* 1CBE0 8002C3E0 21100000 */  addu       $v0, $zero, $zero
    /* 1CBE4 8002C3E4 00006390 */  lbu        $v1, 0x0($v1)
    /* 1CBE8 8002C3E8 09B10008 */  j          .L8002C424
    /* 1CBEC 8002C3EC 00000000 */   nop
  .L8002C3F0:
    /* 1CBF0 8002C3F0 0380033C */  lui        $v1, %hi(D_800335FC)
    /* 1CBF4 8002C3F4 FC35638C */  lw         $v1, %lo(D_800335FC)($v1)
    /* 1CBF8 8002C3F8 00000000 */  nop
    /* 1CBFC 8002C3FC 000062AC */  sw         $v0, 0x0($v1)
  .L8002C400:
    /* 1CC00 8002C400 50000292 */  lbu        $v0, 0x50($s0)
    /* 1CC04 8002C404 00000000 */  nop
    /* 1CC08 8002C408 06004010 */  beqz       $v0, .L8002C424
    /* 1CC0C 8002C40C 01000224 */   addiu     $v0, $zero, 0x1
    /* 1CC10 8002C410 37000392 */  lbu        $v1, 0x37($s0)
    /* 1CC14 8002C414 00000000 */  nop
    /* 1CC18 8002C418 02006014 */  bnez       $v1, .L8002C424
    /* 1CC1C 8002C41C 21100000 */   addu      $v0, $zero, $zero
    /* 1CC20 8002C420 01000224 */  addiu      $v0, $zero, 0x1
  .L8002C424:
    /* 1CC24 8002C424 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1CC28 8002C428 1400B18F */  lw         $s1, 0x14($sp)
    /* 1CC2C 8002C42C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1CC30 8002C430 0800E003 */  jr         $ra
    /* 1CC34 8002C434 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _padInitSioMode
