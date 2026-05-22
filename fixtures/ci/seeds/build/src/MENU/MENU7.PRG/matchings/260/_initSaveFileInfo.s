nonmatching _initSaveFileInfo, 0x248

glabel _initSaveFileInfo
    /* 934 80103134 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 938 80103138 2800B6AF */  sw         $s6, 0x28($sp)
    /* 93C 8010313C 21B08000 */  addu       $s6, $a0, $zero
    /* 940 80103140 2000B4AF */  sw         $s4, 0x20($sp)
    /* 944 80103144 0F001424 */  addiu      $s4, $zero, 0xF
    /* 948 80103148 1400B1AF */  sw         $s1, 0x14($sp)
    /* 94C 8010314C 0E001124 */  addiu      $s1, $zero, 0xE
    /* 950 80103150 1180023C */  lui        $v0, %hi(_memcardFiles)
    /* 954 80103154 00AE4224 */  addiu      $v0, $v0, %lo(_memcardFiles)
    /* 958 80103158 38004224 */  addiu      $v0, $v0, 0x38
    /* 95C 8010315C 3000BFAF */  sw         $ra, 0x30($sp)
    /* 960 80103160 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 964 80103164 2400B5AF */  sw         $s5, 0x24($sp)
    /* 968 80103168 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 96C 8010316C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 970 80103170 1000B0AF */  sw         $s0, 0x10($sp)
  .L80103174:
    /* 974 80103174 000040AC */  sw         $zero, 0x0($v0)
    /* 978 80103178 FFFF3126 */  addiu      $s1, $s1, -0x1
    /* 97C 8010317C FDFF2106 */  bgez       $s1, .L80103174
    /* 980 80103180 FCFF4224 */   addiu     $v0, $v0, -0x4
    /* 984 80103184 01000224 */  addiu      $v0, $zero, 0x1
    /* 988 80103188 0400C216 */  bne        $s6, $v0, .L8010319C
    /* 98C 8010318C 1080023C */   lui       $v0, %hi(D_80102820)
    /* 990 80103190 1080023C */  lui        $v0, %hi(D_80102818)
    /* 994 80103194 680C0408 */  j          .L801031A0
    /* 998 80103198 18284424 */   addiu     $a0, $v0, %lo(D_80102818)
  .L8010319C:
    /* 99C 8010319C 20284424 */  addiu      $a0, $v0, %lo(D_80102820)
  .L801031A0:
    /* 9A0 801031A0 01001124 */  addiu      $s1, $zero, 0x1
    /* 9A4 801031A4 1180023C */  lui        $v0, %hi(_dirEntBuf)
    /* 9A8 801031A8 21A84000 */  addu       $s5, $v0, $zero
    /* 9AC 801031AC 3CAEA58E */  lw         $a1, %lo(_dirEntBuf)($s5)
    /* 9B0 801031B0 E59A000C */  jal        firstfile
    /* 9B4 801031B4 28001324 */   addiu     $s3, $zero, 0x28
    /* 9B8 801031B8 21804000 */  addu       $s0, $v0, $zero
    /* 9BC 801031BC 1180033C */  lui        $v1, %hi(_memcardFiles)
    /* 9C0 801031C0 00AE6224 */  addiu      $v0, $v1, %lo(_memcardFiles)
    /* 9C4 801031C4 04005224 */  addiu      $s2, $v0, 0x4
    /* 9C8 801031C8 00AE70AC */  sw         $s0, %lo(_memcardFiles)($v1)
  .L801031CC:
    /* 9CC 801031CC 0A000012 */  beqz       $s0, .L801031F8
    /* 9D0 801031D0 01003126 */   addiu     $s1, $s1, 0x1
    /* 9D4 801031D4 3CAEA48E */  lw         $a0, %lo(_dirEntBuf)($s5)
    /* 9D8 801031D8 759A000C */  jal        nextfile
    /* 9DC 801031DC 21209300 */   addu      $a0, $a0, $s3
    /* 9E0 801031E0 21804000 */  addu       $s0, $v0, $zero
    /* 9E4 801031E4 000050AE */  sw         $s0, 0x0($s2)
    /* 9E8 801031E8 04005226 */  addiu      $s2, $s2, 0x4
    /* 9EC 801031EC 0F00222A */  slti       $v0, $s1, 0xF
    /* 9F0 801031F0 F6FF4014 */  bnez       $v0, .L801031CC
    /* 9F4 801031F4 28007326 */   addiu     $s3, $s3, 0x28
  .L801031F8:
    /* 9F8 801031F8 1180123C */  lui        $s2, %hi(_saveFileInfo)
    /* 9FC 801031FC 40AE448E */  lw         $a0, %lo(_saveFileInfo)($s2)
    /* A00 80103200 21280000 */  addu       $a1, $zero, $zero
    /* A04 80103204 AD9B000C */  jal        memset
    /* A08 80103208 80020624 */   addiu     $a2, $zero, 0x280
    /* A0C 8010320C FFFFD026 */  addiu      $s0, $s6, -0x1
    /* A10 80103210 270C040C */  jal        _deleteRedundantTempFiles
    /* A14 80103214 00211000 */   sll       $a0, $s0, 4
    /* A18 80103218 21A84000 */  addu       $s5, $v0, $zero
    /* A1C 8010321C 8000A232 */  andi       $v0, $s5, 0x80
    /* A20 80103220 4B004014 */  bnez       $v0, .L80103350
    /* A24 80103224 01000224 */   addiu     $v0, $zero, 0x1
    /* A28 80103228 21880000 */  addu       $s1, $zero, $zero
    /* A2C 8010322C 21B04002 */  addu       $s6, $s2, $zero
    /* A30 80103230 00BC1000 */  sll        $s7, $s0, 16
    /* A34 80103234 1180023C */  lui        $v0, %hi(_memcardFiles)
    /* A38 80103238 00AE5324 */  addiu      $s3, $v0, %lo(_memcardFiles)
  .L8010323C:
    /* A3C 8010323C 0000728E */  lw         $s2, 0x0($s3)
    /* A40 80103240 00000000 */  nop
    /* A44 80103244 28004012 */  beqz       $s2, .L801032E8
    /* A48 80103248 00000000 */   nop
    /* A4C 8010324C 6B0B040C */  jal        _memcardFileNumberFromFilename
    /* A50 80103250 21204002 */   addu      $a0, $s2, $zero
    /* A54 80103254 21804000 */  addu       $s0, $v0, $zero
    /* A58 80103258 1E000012 */  beqz       $s0, .L801032D4
    /* A5C 8010325C 00000000 */   nop
    /* A60 80103260 13000106 */  bgez       $s0, .L801032B0
    /* A64 80103264 00000000 */   nop
    /* A68 80103268 23801000 */  negu       $s0, $s0
    /* A6C 8010326C FFFF0226 */  addiu      $v0, $s0, -0x1
    /* A70 80103270 07105500 */  srav       $v0, $s5, $v0
    /* A74 80103274 01004230 */  andi       $v0, $v0, 0x1
    /* A78 80103278 1B004014 */  bnez       $v0, .L801032E8
    /* A7C 8010327C 21280000 */   addu      $a1, $zero, $zero
    /* A80 80103280 80000624 */  addiu      $a2, $zero, 0x80
    /* A84 80103284 C0811000 */  sll        $s0, $s0, 7
    /* A88 80103288 40AEC28E */  lw         $v0, %lo(_saveFileInfo)($s6)
    /* A8C 8010328C 80FF0426 */  addiu      $a0, $s0, -0x80
    /* A90 80103290 AD9B000C */  jal        memset
    /* A94 80103294 21204400 */   addu      $a0, $v0, $a0
    /* A98 80103298 40AEC28E */  lw         $v0, %lo(_saveFileInfo)($s6)
    /* A9C 8010329C 00000000 */  nop
    /* AA0 801032A0 21800202 */  addu       $s0, $s0, $v0
    /* AA4 801032A4 02000224 */  addiu      $v0, $zero, 0x2
    /* AA8 801032A8 B50C0408 */  j          .L801032D4
    /* AAC 801032AC 84FF02AE */   sw        $v0, -0x7C($s0)
  .L801032B0:
    /* AB0 801032B0 BD0B040C */  jal        _readSaveFileInfo
    /* AB4 801032B4 2520F002 */   or        $a0, $s7, $s0
    /* AB8 801032B8 06004010 */  beqz       $v0, .L801032D4
    /* ABC 801032BC 00000000 */   nop
    /* AC0 801032C0 1800428E */  lw         $v0, 0x18($s2)
    /* AC4 801032C4 00000000 */  nop
    /* AC8 801032C8 FF1F4224 */  addiu      $v0, $v0, 0x1FFF
    /* ACC 801032CC 43130200 */  sra        $v0, $v0, 13
    /* AD0 801032D0 21A08202 */  addu       $s4, $s4, $v0
  .L801032D4:
    /* AD4 801032D4 1800428E */  lw         $v0, 0x18($s2)
    /* AD8 801032D8 00000000 */  nop
    /* ADC 801032DC FF1F4224 */  addiu      $v0, $v0, 0x1FFF
    /* AE0 801032E0 43130200 */  sra        $v0, $v0, 13
    /* AE4 801032E4 23A08202 */  subu       $s4, $s4, $v0
  .L801032E8:
    /* AE8 801032E8 01003126 */  addiu      $s1, $s1, 0x1
    /* AEC 801032EC 0F00222A */  slti       $v0, $s1, 0xF
    /* AF0 801032F0 D2FF4014 */  bnez       $v0, .L8010323C
    /* AF4 801032F4 04007326 */   addiu     $s3, $s3, 0x4
    /* AF8 801032F8 0300822A */  slti       $v0, $s4, 0x3
    /* AFC 801032FC 14004014 */  bnez       $v0, .L80103350
    /* B00 80103300 21100000 */   addu      $v0, $zero, $zero
    /* B04 80103304 1180023C */  lui        $v0, %hi(_saveFileInfo)
    /* B08 80103308 40AE458C */  lw         $a1, %lo(_saveFileInfo)($v0)
    /* B0C 8010330C 01000424 */  addiu      $a0, $zero, 0x1
    /* B10 80103310 21880000 */  addu       $s1, $zero, $zero
  .L80103314:
    /* B14 80103314 2118A000 */  addu       $v1, $a1, $zero
  .L80103318:
    /* B18 80103318 0400628C */  lw         $v0, 0x4($v1)
    /* B1C 8010331C 00000000 */  nop
    /* B20 80103320 03004014 */  bnez       $v0, .L80103330
    /* B24 80103324 01003126 */   addiu     $s1, $s1, 0x1
    /* B28 80103328 CF0C0408 */  j          .L8010333C
    /* B2C 8010332C 040064AC */   sw        $a0, 0x4($v1)
  .L80103330:
    /* B30 80103330 0500222A */  slti       $v0, $s1, 0x5
    /* B34 80103334 F8FF4014 */  bnez       $v0, .L80103318
    /* B38 80103338 80006324 */   addiu     $v1, $v1, 0x80
  .L8010333C:
    /* B3C 8010333C FDFF9426 */  addiu      $s4, $s4, -0x3
    /* B40 80103340 0300822A */  slti       $v0, $s4, 0x3
    /* B44 80103344 F3FF4010 */  beqz       $v0, .L80103314
    /* B48 80103348 21880000 */   addu      $s1, $zero, $zero
    /* B4C 8010334C 21100000 */  addu       $v0, $zero, $zero
  .L80103350:
    /* B50 80103350 3000BF8F */  lw         $ra, 0x30($sp)
    /* B54 80103354 2C00B78F */  lw         $s7, 0x2C($sp)
    /* B58 80103358 2800B68F */  lw         $s6, 0x28($sp)
    /* B5C 8010335C 2400B58F */  lw         $s5, 0x24($sp)
    /* B60 80103360 2000B48F */  lw         $s4, 0x20($sp)
    /* B64 80103364 1C00B38F */  lw         $s3, 0x1C($sp)
    /* B68 80103368 1800B28F */  lw         $s2, 0x18($sp)
    /* B6C 8010336C 1400B18F */  lw         $s1, 0x14($sp)
    /* B70 80103370 1000B08F */  lw         $s0, 0x10($sp)
    /* B74 80103374 0800E003 */  jr         $ra
    /* B78 80103378 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel _initSaveFileInfo
