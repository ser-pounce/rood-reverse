nonmatching _showMenu, 0x80C

glabel _showMenu
    /* 910 80103110 1080023C */  lui        $v0, %hi(_showMenuState)
    /* 914 80103114 4052438C */  lw         $v1, %lo(_showMenuState)($v0)
    /* 918 80103118 88FFBD27 */  addiu      $sp, $sp, -0x78
    /* 91C 8010311C 7400BFAF */  sw         $ra, 0x74($sp)
    /* 920 80103120 7000B4AF */  sw         $s4, 0x70($sp)
    /* 924 80103124 6C00B3AF */  sw         $s3, 0x6C($sp)
    /* 928 80103128 6800B2AF */  sw         $s2, 0x68($sp)
    /* 92C 8010312C 6400B1AF */  sw         $s1, 0x64($sp)
    /* 930 80103130 0800622C */  sltiu      $v0, $v1, 0x8
    /* 934 80103134 F0014010 */  beqz       $v0, .L801038F8
    /* 938 80103138 6000B0AF */   sw        $s0, 0x60($sp)
    /* 93C 8010313C 1080023C */  lui        $v0, %hi(jtbl_80102C28)
    /* 940 80103140 282C4224 */  addiu      $v0, $v0, %lo(jtbl_80102C28)
    /* 944 80103144 80180300 */  sll        $v1, $v1, 2
    /* 948 80103148 21186200 */  addu       $v1, $v1, $v0
    /* 94C 8010314C 0000628C */  lw         $v0, 0x0($v1)
    /* 950 80103150 00000000 */  nop
    /* 954 80103154 08004000 */  jr         $v0
    /* 958 80103158 00000000 */   nop
    /* 95C 8010315C FE070424 */  addiu      $a0, $zero, 0x7FE
    /* 960 80103160 0501040C */  jal        func_80100414
    /* 964 80103164 80000524 */   addiu     $a1, $zero, 0x80
    /* 968 80103168 610C0408 */  j          .L80103184
    /* 96C 8010316C 1080033C */   lui       $v1, %hi(_showMenuState)
    /* 970 80103170 F2FE030C */  jal        func_800FFBC8
    /* 974 80103174 00000000 */   nop
    /* 978 80103178 470E040C */  jal        _topMenu
    /* 97C 8010317C 01000424 */   addiu     $a0, $zero, 0x1
    /* 980 80103180 1080033C */  lui        $v1, %hi(_showMenuState)
  .L80103184:
    /* 984 80103184 4052628C */  lw         $v0, %lo(_showMenuState)($v1)
    /* 988 80103188 00000000 */  nop
    /* 98C 8010318C 01004224 */  addiu      $v0, $v0, 0x1
    /* 990 80103190 3E0E0408 */  j          .L801038F8
    /* 994 80103194 405262AC */   sw        $v0, %lo(_showMenuState)($v1)
    /* 998 80103198 470E040C */  jal        _topMenu
    /* 99C 8010319C 21200000 */   addu      $a0, $zero, $zero
    /* 9A0 801031A0 21904000 */  addu       $s2, $v0, $zero
    /* 9A4 801031A4 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 9A8 801031A8 D4014212 */  beq        $s2, $v0, .L801038FC
    /* 9AC 801031AC 21100000 */   addu      $v0, $zero, $zero
    /* 9B0 801031B0 0A004106 */  bgez       $s2, .L801031DC
    /* 9B4 801031B4 1080033C */   lui       $v1, %hi(_showMenuState)
    /* 9B8 801031B8 FDFF0224 */  addiu      $v0, $zero, -0x3
    /* 9BC 801031BC 05004216 */  bne        $s2, $v0, .L801031D4
    /* 9C0 801031C0 06000224 */   addiu     $v0, $zero, 0x6
    /* 9C4 801031C4 1080033C */  lui        $v1, %hi(_showMenuState)
    /* 9C8 801031C8 07000224 */  addiu      $v0, $zero, 0x7
    /* 9CC 801031CC A00C0408 */  j          .L80103280
    /* 9D0 801031D0 405262AC */   sw        $v0, %lo(_showMenuState)($v1)
  .L801031D4:
    /* 9D4 801031D4 A00C0408 */  j          .L80103280
    /* 9D8 801031D8 405262AC */   sw        $v0, %lo(_showMenuState)($v1)
  .L801031DC:
    /* 9DC 801031DC 1080143C */  lui        $s4, %hi(_helpText)
    /* 9E0 801031E0 5452848E */  lw         $a0, %lo(_helpText)($s4)
    /* 9E4 801031E4 03000224 */  addiu      $v0, $zero, 0x3
    /* 9E8 801031E8 03008010 */  beqz       $a0, .L801031F8
    /* 9EC 801031EC 405262AC */   sw        $v0, %lo(_showMenuState)($v1)
    /* 9F0 801031F0 180F010C */  jal        vs_main_freeHeapR
    /* 9F4 801031F4 00000000 */   nop
  .L801031F8:
    /* 9F8 801031F8 1080133C */  lui        $s3, %hi(_helpAssets)
    /* 9FC 801031FC 5852648E */  lw         $a0, %lo(_helpAssets)($s3)
    /* A00 80103200 00000000 */  nop
    /* A04 80103204 03008010 */  beqz       $a0, .L80103214
    /* A08 80103208 1080103C */   lui       $s0, %hi(_helpFileCdFiles)
    /* A0C 8010320C 180F010C */  jal        vs_main_freeHeapR
    /* A10 80103210 00000000 */   nop
  .L80103214:
    /* A14 80103214 F82A1026 */  addiu      $s0, $s0, %lo(_helpFileCdFiles)
    /* A18 80103218 00111200 */  sll        $v0, $s2, 4
    /* A1C 8010321C 08004234 */  ori        $v0, $v0, 0x8
    /* A20 80103220 21105000 */  addu       $v0, $v0, $s0
    /* A24 80103224 0400448C */  lw         $a0, 0x4($v0)
    /* A28 80103228 8F0F010C */  jal        vs_main_allocHeapR
    /* A2C 8010322C 00911200 */   sll       $s2, $s2, 4
    /* A30 80103230 21885002 */  addu       $s1, $s2, $s0
    /* A34 80103234 0400248E */  lw         $a0, 0x4($s1)
    /* A38 80103238 8F0F010C */  jal        vs_main_allocHeapR
    /* A3C 8010323C 545282AE */   sw        $v0, %lo(_helpText)($s4)
    /* A40 80103240 21202002 */  addu       $a0, $s1, $zero
    /* A44 80103244 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* A48 80103248 585262AE */   sw        $v0, %lo(_helpAssets)($s3)
    /* A4C 8010324C 21204000 */  addu       $a0, $v0, $zero
    /* A50 80103250 5852658E */  lw         $a1, %lo(_helpAssets)($s3)
    /* A54 80103254 1080023C */  lui        $v0, %hi(_helpAssetsCdQueue)
    /* A58 80103258 F112010C */  jal        vs_main_cdEnqueue
    /* A5C 8010325C 3C5244AC */   sw        $a0, %lo(_helpAssetsCdQueue)($v0)
    /* A60 80103260 08001026 */  addiu      $s0, $s0, 0x8
    /* A64 80103264 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* A68 80103268 21205002 */   addu      $a0, $s2, $s0
    /* A6C 8010326C 21204000 */  addu       $a0, $v0, $zero
    /* A70 80103270 5452858E */  lw         $a1, %lo(_helpText)($s4)
    /* A74 80103274 1080023C */  lui        $v0, %hi(_helpTextCdQueue)
    /* A78 80103278 F112010C */  jal        vs_main_cdEnqueue
    /* A7C 8010327C 385244AC */   sw        $a0, %lo(_helpTextCdQueue)($v0)
  .L80103280:
    /* A80 80103280 0F80023C */  lui        $v0, %hi(D_800F4EE8)
    /* A84 80103284 E84E4224 */  addiu      $v0, $v0, %lo(D_800F4EE8)
    /* A88 80103288 04004390 */  lbu        $v1, 0x4($v0)
    /* A8C 8010328C 05004290 */  lbu        $v0, 0x5($v0)
    /* A90 80103290 0F80043C */  lui        $a0, %hi(vs_battle_manualDisplayState)
    /* A94 80103294 21186200 */  addu       $v1, $v1, $v0
    /* A98 80103298 EAFE030C */  jal        func_800FFBA8
    /* A9C 8010329C C81B83A4 */   sh        $v1, %lo(vs_battle_manualDisplayState)($a0)
    /* AA0 801032A0 3F0E0408 */  j          .L801038FC
    /* AA4 801032A4 21100000 */   addu      $v0, $zero, $zero
    /* AA8 801032A8 1080023C */  lui        $v0, %hi(_helpAssetsCdQueue)
    /* AAC 801032AC 3C52448C */  lw         $a0, %lo(_helpAssetsCdQueue)($v0)
    /* AB0 801032B0 00000000 */  nop
    /* AB4 801032B4 00009184 */  lh         $s1, 0x0($a0)
    /* AB8 801032B8 04000224 */  addiu      $v0, $zero, 0x4
    /* ABC 801032BC 8F012216 */  bne        $s1, $v0, .L801038FC
    /* AC0 801032C0 21100000 */   addu      $v0, $zero, $zero
    /* AC4 801032C4 E012010C */  jal        vs_main_freeCdQueueSlot
    /* AC8 801032C8 1080103C */   lui       $s0, %hi(_helpAssets)
    /* ACC 801032CC 5852048E */  lw         $a0, %lo(_helpAssets)($s0)
    /* AD0 801032D0 00000000 */  nop
    /* AD4 801032D4 0000858C */  lw         $a1, 0x0($a0)
    /* AD8 801032D8 890E040C */  jal        _copySprites
    /* ADC 801032DC 08008424 */   addiu     $a0, $a0, 0x8
    /* AE0 801032E0 5852028E */  lw         $v0, %lo(_helpAssets)($s0)
    /* AE4 801032E4 00000000 */  nop
    /* AE8 801032E8 0000448C */  lw         $a0, 0x0($v0)
    /* AEC 801032EC 0400458C */  lw         $a1, 0x4($v0)
    /* AF0 801032F0 C0210400 */  sll        $a0, $a0, 7
    /* AF4 801032F4 08008424 */  addiu      $a0, $a0, 0x8
    /* AF8 801032F8 B60E040C */  jal        _copyCluts
    /* AFC 801032FC 21204400 */   addu      $a0, $v0, $a0
    /* B00 80103300 5852048E */  lw         $a0, %lo(_helpAssets)($s0)
    /* B04 80103304 00000000 */  nop
    /* B08 80103308 04008010 */  beqz       $a0, .L8010331C
    /* B0C 8010330C 1080023C */   lui       $v0, %hi(_showMenuState)
    /* B10 80103310 180F010C */  jal        vs_main_freeHeapR
    /* B14 80103314 00000000 */   nop
    /* B18 80103318 1080023C */  lui        $v0, %hi(_showMenuState)
  .L8010331C:
    /* B1C 8010331C 585200AE */  sw         $zero, %lo(_helpAssets)($s0)
    /* B20 80103320 3E0E0408 */  j          .L801038F8
    /* B24 80103324 405251AC */   sw        $s1, %lo(_showMenuState)($v0)
    /* B28 80103328 1080023C */  lui        $v0, %hi(_helpTextCdQueue)
    /* B2C 8010332C 3852448C */  lw         $a0, %lo(_helpTextCdQueue)($v0)
    /* B30 80103330 00000000 */  nop
    /* B34 80103334 00008384 */  lh         $v1, 0x0($a0)
    /* B38 80103338 04000224 */  addiu      $v0, $zero, 0x4
    /* B3C 8010333C 6F016214 */  bne        $v1, $v0, .L801038FC
    /* B40 80103340 21100000 */   addu      $v0, $zero, $zero
    /* B44 80103344 E012010C */  jal        vs_main_freeCdQueueSlot
    /* B48 80103348 00000000 */   nop
    /* B4C 8010334C 21200000 */  addu       $a0, $zero, $zero
    /* B50 80103350 21288000 */  addu       $a1, $a0, $zero
    /* B54 80103354 08000624 */  addiu      $a2, $zero, 0x8
    /* B58 80103358 34000724 */  addiu      $a3, $zero, 0x34
    /* B5C 8010335C 19000224 */  addiu      $v0, $zero, 0x19
    /* B60 80103360 1000A2AF */  sw         $v0, 0x10($sp)
    /* B64 80103364 0A000224 */  addiu      $v0, $zero, 0xA
    /* B68 80103368 1400A2AF */  sw         $v0, 0x14($sp)
    /* B6C 8010336C 2110C000 */  addu       $v0, $a2, $zero
    /* B70 80103370 1800A2AF */  sw         $v0, 0x18($sp)
    /* B74 80103374 2110E000 */  addu       $v0, $a3, $zero
    /* B78 80103378 C233030C */  jal        vs_battle_initTextBox
    /* B7C 8010337C 1C00A2AF */   sw        $v0, 0x1C($sp)
    /* B80 80103380 0F80033C */  lui        $v1, %hi(vs_battle_manualDisplayState)
    /* B84 80103384 C81B6294 */  lhu        $v0, %lo(vs_battle_manualDisplayState)($v1)
    /* B88 80103388 C81B6324 */  addiu      $v1, $v1, %lo(vs_battle_manualDisplayState)
    /* B8C 8010338C 40100200 */  sll        $v0, $v0, 1
    /* B90 80103390 21104300 */  addu       $v0, $v0, $v1
    /* B94 80103394 04004394 */  lhu        $v1, 0x4($v0)
    /* B98 80103398 1080023C */  lui        $v0, %hi(_scrollPosition)
    /* B9C 8010339C DB0E040C */  jal        _getRoundedLineCount
    /* BA0 801033A0 445243AC */   sw        $v1, %lo(_scrollPosition)($v0)
    /* BA4 801033A4 1080033C */  lui        $v1, %hi(_lineCount)
    /* BA8 801033A8 485262AC */  sw         $v0, %lo(_lineCount)($v1)
    /* BAC 801033AC 1080033C */  lui        $v1, %hi(_showMenuState)
    /* BB0 801033B0 05000224 */  addiu      $v0, $zero, 0x5
    /* BB4 801033B4 405262AC */  sw         $v0, %lo(_showMenuState)($v1)
    /* BB8 801033B8 1080023C */  lui        $v0, %hi(_helpPageLoadCounter)
    /* BBC 801033BC 3E0E0408 */  j          .L801038F8
    /* BC0 801033C0 505240AC */   sw        $zero, %lo(_helpPageLoadCounter)($v0)
    /* BC4 801033C4 6666033C */  lui        $v1, (0x66666667 >> 16)
    /* BC8 801033C8 1080083C */  lui        $t0, %hi(_scrollPosition)
    /* BCC 801033CC 4452078D */  lw         $a3, %lo(_scrollPosition)($t0)
    /* BD0 801033D0 67666334 */  ori        $v1, $v1, (0x66666667 & 0xFFFF)
    /* BD4 801033D4 1800E300 */  mult       $a3, $v1
    /* BD8 801033D8 1080023C */  lui        $v0, %hi(_lineCount)
    /* BDC 801033DC 10500000 */  mfhi       $t2
    /* BE0 801033E0 4852468C */  lw         $a2, %lo(_lineCount)($v0)
    /* BE4 801033E4 00000000 */  nop
    /* BE8 801033E8 1800C300 */  mult       $a2, $v1
    /* BEC 801033EC C3170700 */  sra        $v0, $a3, 31
    /* BF0 801033F0 83180A00 */  sra        $v1, $t2, 2
    /* BF4 801033F4 23886200 */  subu       $s1, $v1, $v0
    /* BF8 801033F8 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* BFC 801033FC D0E1458C */  lw         $a1, %lo(vs_main_buttonsPressed)($v0)
    /* C00 80103400 C31F0600 */  sra        $v1, $a2, 31
    /* C04 80103404 6000A230 */  andi       $v0, $a1, 0x60
    /* C08 80103408 10200000 */  mfhi       $a0
    /* C0C 8010340C 83200400 */  sra        $a0, $a0, 2
    /* C10 80103410 04004010 */  beqz       $v0, .L80103424
    /* C14 80103414 23908300 */   subu      $s2, $a0, $v1
    /* C18 80103418 1080033C */  lui        $v1, %hi(_showMenuState)
    /* C1C 8010341C 01000224 */  addiu      $v0, $zero, 0x1
    /* C20 80103420 405262AC */  sw         $v0, %lo(_showMenuState)($v1)
  .L80103424:
    /* C24 80103424 2120A000 */  addu       $a0, $a1, $zero
    /* C28 80103428 10008230 */  andi       $v0, $a0, 0x10
    /* C2C 8010342C 03004010 */  beqz       $v0, .L8010343C
    /* C30 80103430 1080033C */   lui       $v1, %hi(_showMenuState)
    /* C34 80103434 07000224 */  addiu      $v0, $zero, 0x7
    /* C38 80103438 405262AC */  sw         $v0, %lo(_showMenuState)($v1)
  .L8010343C:
    /* C3C 8010343C 00088230 */  andi       $v0, $a0, 0x800
    /* C40 80103440 04004010 */  beqz       $v0, .L80103454
    /* C44 80103444 0680023C */   lui       $v0, %hi(vs_main_buttonsPreviousState)
    /* C48 80103448 21880000 */  addu       $s1, $zero, $zero
    /* C4C 8010344C 820D0408 */  j          .L80103608
    /* C50 80103450 445200AD */   sw        $zero, %lo(_scrollPosition)($t0)
  .L80103454:
    /* C54 80103454 C0E1428C */  lw         $v0, %lo(vs_main_buttonsPreviousState)($v0)
    /* C58 80103458 00000000 */  nop
    /* C5C 8010345C 80004230 */  andi       $v0, $v0, 0x80
    /* C60 80103460 34004010 */  beqz       $v0, .L80103534
    /* C64 80103464 00108230 */   andi      $v0, $a0, 0x1000
    /* C68 80103468 0B004010 */  beqz       $v0, .L80103498
    /* C6C 8010346C 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* C70 80103470 09002016 */  bnez       $s1, .L80103498
    /* C74 80103474 00000000 */   nop
    /* C78 80103478 0600401A */  blez       $s2, .L80103494
    /* C7C 8010347C 80101200 */   sll       $v0, $s2, 2
    /* C80 80103480 21884002 */  addu       $s1, $s2, $zero
    /* C84 80103484 21105200 */  addu       $v0, $v0, $s2
    /* C88 80103488 40100200 */  sll        $v0, $v0, 1
    /* C8C 8010348C 7F0D0408 */  j          .L801035FC
    /* C90 80103490 445202AD */   sw        $v0, %lo(_scrollPosition)($t0)
  .L80103494:
    /* C94 80103494 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
  .L80103498:
    /* C98 80103498 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* C9C 8010349C 00000000 */  nop
    /* CA0 801034A0 00404230 */  andi       $v0, $v0, 0x4000
    /* CA4 801034A4 09004010 */  beqz       $v0, .L801034CC
    /* CA8 801034A8 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* CAC 801034AC 07003216 */  bne        $s1, $s2, .L801034CC
    /* CB0 801034B0 00000000 */   nop
    /* CB4 801034B4 0400401A */  blez       $s2, .L801034C8
    /* CB8 801034B8 1080023C */   lui       $v0, %hi(_scrollPosition)
    /* CBC 801034BC 21880000 */  addu       $s1, $zero, $zero
    /* CC0 801034C0 7F0D0408 */  j          .L801035FC
    /* CC4 801034C4 445240AC */   sw        $zero, %lo(_scrollPosition)($v0)
  .L801034C8:
    /* CC8 801034C8 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
  .L801034CC:
    /* CCC 801034CC DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* CD0 801034D0 00000000 */  nop
    /* CD4 801034D4 00104230 */  andi       $v0, $v0, 0x1000
    /* CD8 801034D8 09004010 */  beqz       $v0, .L80103500
    /* CDC 801034DC 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* CE0 801034E0 0700201A */  blez       $s1, .L80103500
    /* CE4 801034E4 1080033C */   lui       $v1, %hi(_scrollPosition)
    /* CE8 801034E8 FFFF3126 */  addiu      $s1, $s1, -0x1
    /* CEC 801034EC 80101100 */  sll        $v0, $s1, 2
    /* CF0 801034F0 21105100 */  addu       $v0, $v0, $s1
    /* CF4 801034F4 40100200 */  sll        $v0, $v0, 1
    /* CF8 801034F8 7F0D0408 */  j          .L801035FC
    /* CFC 801034FC 445262AC */   sw        $v0, %lo(_scrollPosition)($v1)
  .L80103500:
    /* D00 80103500 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* D04 80103504 00000000 */  nop
    /* D08 80103508 00404230 */  andi       $v0, $v0, 0x4000
    /* D0C 8010350C 3E004010 */  beqz       $v0, .L80103608
    /* D10 80103510 2A103202 */   slt       $v0, $s1, $s2
    /* D14 80103514 3C004010 */  beqz       $v0, .L80103608
    /* D18 80103518 1080033C */   lui       $v1, %hi(_scrollPosition)
    /* D1C 8010351C 01003126 */  addiu      $s1, $s1, 0x1
    /* D20 80103520 80101100 */  sll        $v0, $s1, 2
    /* D24 80103524 21105100 */  addu       $v0, $v0, $s1
    /* D28 80103528 40100200 */  sll        $v0, $v0, 1
    /* D2C 8010352C 7F0D0408 */  j          .L801035FC
    /* D30 80103530 445262AC */   sw        $v0, %lo(_scrollPosition)($v1)
  .L80103534:
    /* D34 80103534 0010A230 */  andi       $v0, $a1, 0x1000
    /* D38 80103538 07004010 */  beqz       $v0, .L80103558
    /* D3C 8010353C 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* D40 80103540 0500E014 */  bnez       $a3, .L80103558
    /* D44 80103544 00000000 */   nop
    /* D48 80103548 0300C018 */  blez       $a2, .L80103558
    /* D4C 8010354C 00000000 */   nop
    /* D50 80103550 7F0D0408 */  j          .L801035FC
    /* D54 80103554 445206AD */   sw        $a2, %lo(_scrollPosition)($t0)
  .L80103558:
    /* D58 80103558 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* D5C 8010355C 00000000 */  nop
    /* D60 80103560 00404230 */  andi       $v0, $v0, 0x4000
    /* D64 80103564 0B004010 */  beqz       $v0, .L80103594
    /* D68 80103568 1080043C */   lui       $a0, %hi(_scrollPosition)
    /* D6C 8010356C 1080023C */  lui        $v0, %hi(_lineCount)
    /* D70 80103570 4452838C */  lw         $v1, %lo(_scrollPosition)($a0)
    /* D74 80103574 4852428C */  lw         $v0, %lo(_lineCount)($v0)
    /* D78 80103578 00000000 */  nop
    /* D7C 8010357C 06006214 */  bne        $v1, $v0, .L80103598
    /* D80 80103580 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* D84 80103584 04006018 */  blez       $v1, .L80103598
    /* D88 80103588 00000000 */   nop
    /* D8C 8010358C 7F0D0408 */  j          .L801035FC
    /* D90 80103590 445280AC */   sw        $zero, %lo(_scrollPosition)($a0)
  .L80103594:
    /* D94 80103594 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
  .L80103598:
    /* D98 80103598 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* D9C 8010359C 00000000 */  nop
    /* DA0 801035A0 00104230 */  andi       $v0, $v0, 0x1000
    /* DA4 801035A4 07004010 */  beqz       $v0, .L801035C4
    /* DA8 801035A8 1080033C */   lui       $v1, %hi(_scrollPosition)
    /* DAC 801035AC 4452628C */  lw         $v0, %lo(_scrollPosition)($v1)
    /* DB0 801035B0 00000000 */  nop
    /* DB4 801035B4 03004018 */  blez       $v0, .L801035C4
    /* DB8 801035B8 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* DBC 801035BC 7F0D0408 */  j          .L801035FC
    /* DC0 801035C0 445262AC */   sw        $v0, %lo(_scrollPosition)($v1)
  .L801035C4:
    /* DC4 801035C4 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* DC8 801035C8 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* DCC 801035CC 00000000 */  nop
    /* DD0 801035D0 00404230 */  andi       $v0, $v0, 0x4000
    /* DD4 801035D4 0C004010 */  beqz       $v0, .L80103608
    /* DD8 801035D8 1080043C */   lui       $a0, %hi(_scrollPosition)
    /* DDC 801035DC 1080023C */  lui        $v0, %hi(_lineCount)
    /* DE0 801035E0 4452838C */  lw         $v1, %lo(_scrollPosition)($a0)
    /* DE4 801035E4 4852428C */  lw         $v0, %lo(_lineCount)($v0)
    /* DE8 801035E8 00000000 */  nop
    /* DEC 801035EC 2A106200 */  slt        $v0, $v1, $v0
    /* DF0 801035F0 05004010 */  beqz       $v0, .L80103608
    /* DF4 801035F4 01006224 */   addiu     $v0, $v1, 0x1
    /* DF8 801035F8 445282AC */  sw         $v0, %lo(_scrollPosition)($a0)
  .L801035FC:
    /* DFC 801035FC 7E000424 */  addiu      $a0, $zero, 0x7E
    /* E00 80103600 6216010C */  jal        vs_main_playSfxDefault
    /* E04 80103604 04000524 */   addiu     $a1, $zero, 0x4
  .L80103608:
    /* E08 80103608 01000424 */  addiu      $a0, $zero, 0x1
    /* E0C 8010360C 08000524 */  addiu      $a1, $zero, 0x8
    /* E10 80103610 801F103C */  lui        $s0, (0x1F800004 >> 16)
    /* E14 80103614 0400078E */  lw         $a3, (0x1F800004 & 0xFFFF)($s0)
    /* E18 80103618 10000624 */  addiu      $a2, $zero, 0x10
    /* E1C 8010361C 1AFF030C */  jal        vs_mainmenu_drawButton
    /* E20 80103620 1800E724 */   addiu     $a3, $a3, 0x18
    /* E24 80103624 1080043C */  lui        $a0, %hi(D_80102BF8)
    /* E28 80103628 F82B8424 */  addiu      $a0, $a0, %lo(D_80102BF8)
    /* E2C 8010362C 1200053C */  lui        $a1, (0x12001C >> 16)
    /* E30 80103630 1C00A534 */  ori        $a1, $a1, (0x12001C & 0xFFFF)
    /* E34 80103634 8000063C */  lui        $a2, (0x808080 >> 16)
    /* E38 80103638 0400078E */  lw         $a3, (0x1F800004 & 0xFFFF)($s0)
    /* E3C 8010363C 8080C634 */  ori        $a2, $a2, (0x808080 & 0xFFFF)
    /* E40 80103640 5019030C */  jal        vs_battle_renderTextRawColor
    /* E44 80103644 1800E724 */   addiu     $a3, $a3, 0x18
    /* E48 80103648 10000424 */  addiu      $a0, $zero, 0x10
    /* E4C 8010364C 12000524 */  addiu      $a1, $zero, 0x12
    /* E50 80103650 60000624 */  addiu      $a2, $zero, 0x60
    /* E54 80103654 3113040C */  jal        _drawControlsBg
    /* E58 80103658 0C000724 */   addiu     $a3, $zero, 0xC
    /* E5C 8010365C 02000424 */  addiu      $a0, $zero, 0x2
    /* E60 80103660 08000524 */  addiu      $a1, $zero, 0x8
    /* E64 80103664 0400078E */  lw         $a3, (0x1F800004 & 0xFFFF)($s0)
    /* E68 80103668 22000624 */  addiu      $a2, $zero, 0x22
    /* E6C 8010366C 1AFF030C */  jal        vs_mainmenu_drawButton
    /* E70 80103670 1800E724 */   addiu     $a3, $a3, 0x18
    /* E74 80103674 1080043C */  lui        $a0, %hi(D_80102C08)
    /* E78 80103678 082C8424 */  addiu      $a0, $a0, %lo(D_80102C08)
    /* E7C 8010367C 2400053C */  lui        $a1, (0x24001C >> 16)
    /* E80 80103680 1C00A534 */  ori        $a1, $a1, (0x24001C & 0xFFFF)
    /* E84 80103684 8000063C */  lui        $a2, (0x808080 >> 16)
    /* E88 80103688 0400078E */  lw         $a3, (0x1F800004 & 0xFFFF)($s0)
    /* E8C 8010368C 8080C634 */  ori        $a2, $a2, (0x808080 & 0xFFFF)
    /* E90 80103690 5019030C */  jal        vs_battle_renderTextRawColor
    /* E94 80103694 1800E724 */   addiu     $a3, $a3, 0x18
    /* E98 80103698 10000424 */  addiu      $a0, $zero, 0x10
    /* E9C 8010369C 24000524 */  addiu      $a1, $zero, 0x24
    /* EA0 801036A0 40000624 */  addiu      $a2, $zero, 0x40
    /* EA4 801036A4 3113040C */  jal        _drawControlsBg
    /* EA8 801036A8 0C000724 */   addiu     $a3, $zero, 0xC
    /* EAC 801036AC 1080043C */  lui        $a0, %hi(D_80102C10)
    /* EB0 801036B0 102C8424 */  addiu      $a0, $a0, %lo(D_80102C10)
    /* EB4 801036B4 C400053C */  lui        $a1, (0xC400D8 >> 16)
    /* EB8 801036B8 D800A534 */  ori        $a1, $a1, (0xC400D8 & 0xFFFF)
    /* EBC 801036BC 8000063C */  lui        $a2, (0x808080 >> 16)
    /* EC0 801036C0 0400078E */  lw         $a3, (0x1F800004 & 0xFFFF)($s0)
    /* EC4 801036C4 8080C634 */  ori        $a2, $a2, (0x808080 & 0xFFFF)
    /* EC8 801036C8 5019030C */  jal        vs_battle_renderTextRawColor
    /* ECC 801036CC 1C00E724 */   addiu     $a3, $a3, 0x1C
    /* ED0 801036D0 2000A427 */  addiu      $a0, $sp, 0x20
    /* ED4 801036D4 1080053C */  lui        $a1, %hi(D_80102C18)
    /* ED8 801036D8 182CA524 */  addiu      $a1, $a1, %lo(D_80102C18)
    /* EDC 801036DC BD9B000C */  jal        sprintf
    /* EE0 801036E0 01002626 */   addiu     $a2, $s1, 0x1
    /* EE4 801036E4 2000A427 */  addiu      $a0, $sp, 0x20
    /* EE8 801036E8 C400053C */  lui        $a1, (0xC40118 >> 16)
    /* EEC 801036EC 1801A534 */  ori        $a1, $a1, (0xC40118 & 0xFFFF)
    /* EF0 801036F0 8000063C */  lui        $a2, (0x808080 >> 16)
    /* EF4 801036F4 0400078E */  lw         $a3, (0x1F800004 & 0xFFFF)($s0)
    /* EF8 801036F8 8080C634 */  ori        $a2, $a2, (0x808080 & 0xFFFF)
    /* EFC 801036FC 5019030C */  jal        vs_battle_renderTextRawColor
    /* F00 80103700 1C00E724 */   addiu     $a3, $a3, 0x1C
    /* F04 80103704 2000A427 */  addiu      $a0, $sp, 0x20
    /* F08 80103708 1080053C */  lui        $a1, %hi(D_80102C20)
    /* F0C 8010370C 202CA524 */  addiu      $a1, $a1, %lo(D_80102C20)
    /* F10 80103710 BD9B000C */  jal        sprintf
    /* F14 80103714 01004626 */   addiu     $a2, $s2, 0x1
    /* F18 80103718 2000A427 */  addiu      $a0, $sp, 0x20
    /* F1C 8010371C C400053C */  lui        $a1, (0xC40130 >> 16)
    /* F20 80103720 3001A534 */  ori        $a1, $a1, (0xC40130 & 0xFFFF)
    /* F24 80103724 8000063C */  lui        $a2, (0x808080 >> 16)
    /* F28 80103728 0400078E */  lw         $a3, (0x1F800004 & 0xFFFF)($s0)
    /* F2C 8010372C 8080C634 */  ori        $a2, $a2, (0x808080 & 0xFFFF)
    /* F30 80103730 5019030C */  jal        vs_battle_renderTextRawColor
    /* F34 80103734 1C00E724 */   addiu     $a3, $a3, 0x1C
    /* F38 80103738 0F80033C */  lui        $v1, %hi(vs_battle_manualDisplayState)
    /* F3C 8010373C C81B6294 */  lhu        $v0, %lo(vs_battle_manualDisplayState)($v1)
    /* F40 80103740 C81B6324 */  addiu      $v1, $v1, %lo(vs_battle_manualDisplayState)
    /* F44 80103744 1080103C */  lui        $s0, %hi(_scrollPosition)
    /* F48 80103748 44520496 */  lhu        $a0, %lo(_scrollPosition)($s0)
    /* F4C 8010374C 40100200 */  sll        $v0, $v0, 1
    /* F50 80103750 21104300 */  addu       $v0, $v0, $v1
    /* F54 80103754 040044A4 */  sh         $a0, 0x4($v0)
    /* F58 80103758 1080023C */  lui        $v0, %hi(_showMenuState)
    /* F5C 8010375C 4052438C */  lw         $v1, %lo(_showMenuState)($v0)
    /* F60 80103760 05000224 */  addiu      $v0, $zero, 0x5
    /* F64 80103764 16006210 */  beq        $v1, $v0, .L801037C0
    /* F68 80103768 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* F6C 8010376C D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* F70 80103770 00000000 */  nop
    /* F74 80103774 20004230 */  andi       $v0, $v0, 0x20
    /* F78 80103778 03004010 */  beqz       $v0, .L80103788
    /* F7C 8010377C 05000524 */   addiu     $a1, $zero, 0x5
    /* F80 80103780 E40D0408 */  j          .L80103790
    /* F84 80103784 7E000424 */   addiu     $a0, $zero, 0x7E
  .L80103788:
    /* F88 80103788 7E000424 */  addiu      $a0, $zero, 0x7E
    /* F8C 8010378C 06000524 */  addiu      $a1, $zero, 0x6
  .L80103790:
    /* F90 80103790 6216010C */  jal        vs_main_playSfxDefault
    /* F94 80103794 1080103C */   lui       $s0, %hi(_helpText)
    /* F98 80103798 7D33030C */  jal        vs_battle_getTextBox
    /* F9C 8010379C 21200000 */   addu      $a0, $zero, $zero
    /* FA0 801037A0 5452048E */  lw         $a0, %lo(_helpText)($s0)
    /* FA4 801037A4 00000000 */  nop
    /* FA8 801037A8 03008010 */  beqz       $a0, .L801037B8
    /* FAC 801037AC 1C0040A4 */   sh        $zero, 0x1C($v0)
    /* FB0 801037B0 180F010C */  jal        vs_main_freeHeapR
    /* FB4 801037B4 00000000 */   nop
  .L801037B8:
    /* FB8 801037B8 3E0E0408 */  j          .L801038F8
    /* FBC 801037BC 545200AE */   sw        $zero, %lo(_helpText)($s0)
  .L801037C0:
    /* FC0 801037C0 08000424 */  addiu      $a0, $zero, 0x8
    /* FC4 801037C4 34000524 */  addiu      $a1, $zero, 0x34
    /* FC8 801037C8 36010624 */  addiu      $a2, $zero, 0x136
    /* FCC 801037CC 88000724 */  addiu      $a3, $zero, 0x88
    /* FD0 801037D0 8110040C */  jal        _setPageBg
    /* FD4 801037D4 1000A0AF */   sw        $zero, 0x10($sp)
    /* FD8 801037D8 1080023C */  lui        $v0, %hi(_pageArrowAnimState)
    /* FDC 801037DC 4C52438C */  lw         $v1, %lo(_pageArrowAnimState)($v0)
    /* FE0 801037E0 4452048E */  lw         $a0, %lo(_scrollPosition)($s0)
    /* FE4 801037E4 01006324 */  addiu      $v1, $v1, 0x1
    /* FE8 801037E8 0F006330 */  andi       $v1, $v1, 0xF
    /* FEC 801037EC 03008018 */  blez       $a0, .L801037FC
    /* FF0 801037F0 4C5243AC */   sw        $v1, %lo(_pageArrowAnimState)($v0)
    /* FF4 801037F4 D710040C */  jal        _fadeMenuUpper
    /* FF8 801037F8 00000000 */   nop
  .L801037FC:
    /* FFC 801037FC 1080023C */  lui        $v0, %hi(_lineCount)
    /* 1000 80103800 4452038E */  lw         $v1, %lo(_scrollPosition)($s0)
    /* 1004 80103804 4852428C */  lw         $v0, %lo(_lineCount)($v0)
    /* 1008 80103808 00000000 */  nop
    /* 100C 8010380C 2A186200 */  slt        $v1, $v1, $v0
    /* 1010 80103810 04006010 */  beqz       $v1, .L80103824
    /* 1014 80103814 1080043C */   lui       $a0, %hi(_helpPageLoadCounter)
    /* 1018 80103818 8811040C */  jal        _fadeMenuLower
    /* 101C 8010381C 00000000 */   nop
    /* 1020 80103820 1080043C */  lui        $a0, %hi(_helpPageLoadCounter)
  .L80103824:
    /* 1024 80103824 5052838C */  lw         $v1, %lo(_helpPageLoadCounter)($a0)
    /* 1028 80103828 00000000 */  nop
    /* 102C 8010382C 08006228 */  slti       $v0, $v1, 0x8
    /* 1030 80103830 03004010 */  beqz       $v0, .L80103840
    /* 1034 80103834 01006224 */   addiu     $v0, $v1, 0x1
    /* 1038 80103838 120E0408 */  j          .L80103848
    /* 103C 8010383C 505282AC */   sw        $v0, %lo(_helpPageLoadCounter)($a0)
  .L80103840:
    /* 1040 80103840 3C0F040C */  jal        _drawContent
    /* 1044 80103844 00000000 */   nop
  .L80103848:
    /* 1048 80103848 F20E040C */  jal        _copyNextPageText
    /* 104C 8010384C 00000000 */   nop
    /* 1050 80103850 3F0E0408 */  j          .L801038FC
    /* 1054 80103854 21100000 */   addu      $v0, $zero, $zero
    /* 1058 80103858 1080023C */  lui        $v0, %hi(_helpText)
    /* 105C 8010385C 5452448C */  lw         $a0, %lo(_helpText)($v0)
    /* 1060 80103860 00000000 */  nop
    /* 1064 80103864 04008010 */  beqz       $a0, .L80103878
    /* 1068 80103868 1080023C */   lui       $v0, %hi(_helpAssets)
    /* 106C 8010386C 180F010C */  jal        vs_main_freeHeapR
    /* 1070 80103870 00000000 */   nop
    /* 1074 80103874 1080023C */  lui        $v0, %hi(_helpAssets)
  .L80103878:
    /* 1078 80103878 5852448C */  lw         $a0, %lo(_helpAssets)($v0)
    /* 107C 8010387C 00000000 */  nop
    /* 1080 80103880 03008010 */  beqz       $a0, .L80103890
    /* 1084 80103884 00000000 */   nop
    /* 1088 80103888 180F010C */  jal        vs_main_freeHeapR
    /* 108C 8010388C 00000000 */   nop
  .L80103890:
    /* 1090 80103890 1D000424 */  addiu      $a0, $zero, 0x1D
    /* 1094 80103894 03000524 */  addiu      $a1, $zero, 0x3
    /* 1098 80103898 2AF8010C */  jal        func_8007E0A8
    /* 109C 8010389C 05000624 */   addiu     $a2, $zero, 0x5
    /* 10A0 801038A0 3F0E0408 */  j          .L801038FC
    /* 10A4 801038A4 01000224 */   addiu     $v0, $zero, 0x1
    /* 10A8 801038A8 1080023C */  lui        $v0, %hi(_helpText)
    /* 10AC 801038AC 5452448C */  lw         $a0, %lo(_helpText)($v0)
    /* 10B0 801038B0 00000000 */  nop
    /* 10B4 801038B4 04008010 */  beqz       $a0, .L801038C8
    /* 10B8 801038B8 1080023C */   lui       $v0, %hi(_helpAssets)
    /* 10BC 801038BC 180F010C */  jal        vs_main_freeHeapR
    /* 10C0 801038C0 00000000 */   nop
    /* 10C4 801038C4 1080023C */  lui        $v0, %hi(_helpAssets)
  .L801038C8:
    /* 10C8 801038C8 5852448C */  lw         $a0, %lo(_helpAssets)($v0)
    /* 10CC 801038CC 00000000 */  nop
    /* 10D0 801038D0 03008010 */  beqz       $a0, .L801038E0
    /* 10D4 801038D4 00000000 */   nop
    /* 10D8 801038D8 180F010C */  jal        vs_main_freeHeapR
    /* 10DC 801038DC 00000000 */   nop
  .L801038E0:
    /* 10E0 801038E0 1D000424 */  addiu      $a0, $zero, 0x1D
    /* 10E4 801038E4 03000524 */  addiu      $a1, $zero, 0x3
    /* 10E8 801038E8 2AF8010C */  jal        func_8007E0A8
    /* 10EC 801038EC 05000624 */   addiu     $a2, $zero, 0x5
    /* 10F0 801038F0 3F0E0408 */  j          .L801038FC
    /* 10F4 801038F4 02000224 */   addiu     $v0, $zero, 0x2
  .L801038F8:
    /* 10F8 801038F8 21100000 */  addu       $v0, $zero, $zero
  .L801038FC:
    /* 10FC 801038FC 7400BF8F */  lw         $ra, 0x74($sp)
    /* 1100 80103900 7000B48F */  lw         $s4, 0x70($sp)
    /* 1104 80103904 6C00B38F */  lw         $s3, 0x6C($sp)
    /* 1108 80103908 6800B28F */  lw         $s2, 0x68($sp)
    /* 110C 8010390C 6400B18F */  lw         $s1, 0x64($sp)
    /* 1110 80103910 6000B08F */  lw         $s0, 0x60($sp)
    /* 1114 80103914 0800E003 */  jr         $ra
    /* 1118 80103918 7800BD27 */   addiu     $sp, $sp, 0x78
endlabel _showMenu
