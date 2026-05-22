nonmatching func_801049A0, 0x974

glabel func_801049A0
    /* 21A0 801049A0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 21A4 801049A4 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 21A8 801049A8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 21AC 801049AC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 21B0 801049B0 10008010 */  beqz       $a0, .L801049F4
    /* 21B4 801049B4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 21B8 801049B8 21100000 */  addu       $v0, $zero, $zero
    /* 21BC 801049BC 1080033C */  lui        $v1, %hi(_charTableColumn)
    /* 21C0 801049C0 2A5F60A0 */  sb         $zero, %lo(_charTableColumn)($v1)
    /* 21C4 801049C4 1080033C */  lui        $v1, %hi(_charTableRow)
    /* 21C8 801049C8 2B5F60A0 */  sb         $zero, %lo(_charTableRow)($v1)
    /* 21CC 801049CC 1080033C */  lui        $v1, %hi(D_80105F2C)
    /* 21D0 801049D0 2C5F60A0 */  sb         $zero, %lo(D_80105F2C)($v1)
    /* 21D4 801049D4 1080033C */  lui        $v1, %hi(D_80105F2D)
    /* 21D8 801049D8 1080043C */  lui        $a0, %hi(D_80105F29)
    /* 21DC 801049DC 2D5F60A0 */  sb         $zero, %lo(D_80105F2D)($v1)
    /* 21E0 801049E0 08000324 */  addiu      $v1, $zero, 0x8
    /* 21E4 801049E4 295F83A0 */  sb         $v1, %lo(D_80105F29)($a0)
    /* 21E8 801049E8 1080033C */  lui        $v1, %hi(D_80105F28)
    /* 21EC 801049EC BF140408 */  j          .L801052FC
    /* 21F0 801049F0 285F60A0 */   sb        $zero, %lo(D_80105F28)($v1)
  .L801049F4:
    /* 21F4 801049F4 1080023C */  lui        $v0, %hi(D_80105F28)
    /* 21F8 801049F8 285F4390 */  lbu        $v1, %lo(D_80105F28)($v0)
    /* 21FC 801049FC 00000000 */  nop
    /* 2200 80104A00 0700622C */  sltiu      $v0, $v1, 0x7
    /* 2204 80104A04 20024010 */  beqz       $v0, .L80105288
    /* 2208 80104A08 1080023C */   lui       $v0, %hi(jtbl_8010286C)
    /* 220C 80104A0C 6C284224 */  addiu      $v0, $v0, %lo(jtbl_8010286C)
    /* 2210 80104A10 80180300 */  sll        $v1, $v1, 2
    /* 2214 80104A14 21186200 */  addu       $v1, $v1, $v0
    /* 2218 80104A18 0000628C */  lw         $v0, 0x0($v1)
    /* 221C 80104A1C 00000000 */  nop
    /* 2220 80104A20 08004000 */  jr         $v0
    /* 2224 80104A24 00000000 */   nop
    /* 2228 80104A28 1080033C */  lui        $v1, %hi(D_80105F29)
    /* 222C 80104A2C 295F6290 */  lbu        $v0, %lo(D_80105F29)($v1)
    /* 2230 80104A30 00000000 */  nop
    /* 2234 80104A34 03004010 */  beqz       $v0, .L80104A44
    /* 2238 80104A38 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 223C 80104A3C A2140408 */  j          .L80105288
    /* 2240 80104A40 295F62A0 */   sb        $v0, %lo(D_80105F29)($v1)
  .L80104A44:
    /* 2244 80104A44 A0140408 */  j          .L80105280
    /* 2248 80104A48 1080033C */   lui       $v1, %hi(D_80105F28)
    /* 224C 80104A4C 1080103C */  lui        $s0, %hi(D_80105F2C)
    /* 2250 80104A50 2C5F0492 */  lbu        $a0, %lo(D_80105F2C)($s0)
    /* 2254 80104A54 620F040C */  jal        _insertDeleteHandler
    /* 2258 80104A58 00000000 */   nop
    /* 225C 80104A5C 0680033C */  lui        $v1, %hi(vs_main_buttonsPressed)
    /* 2260 80104A60 D0E1638C */  lw         $v1, %lo(vs_main_buttonsPressed)($v1)
    /* 2264 80104A64 00000000 */  nop
    /* 2268 80104A68 00086330 */  andi       $v1, $v1, 0x800
    /* 226C 80104A6C 08006010 */  beqz       $v1, .L80104A90
    /* 2270 80104A70 2C5F02A2 */   sb        $v0, %lo(D_80105F2C)($s0)
    /* 2274 80104A74 BC00030C */  jal        vs_battle_playMenuSelectSfx
    /* 2278 80104A78 00000000 */   nop
    /* 227C 80104A7C 4F12040C */  jal        func_8010493C
    /* 2280 80104A80 FF000424 */   addiu     $a0, $zero, 0xFF
    /* 2284 80104A84 1080033C */  lui        $v1, %hi(D_80105F28)
    /* 2288 80104A88 A1140408 */  j          .L80105284
    /* 228C 80104A8C 03000224 */   addiu     $v0, $zero, 0x3
  .L80104A90:
    /* 2290 80104A90 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 2294 80104A94 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 2298 80104A98 00000000 */  nop
    /* 229C 80104A9C 40004230 */  andi       $v0, $v0, 0x40
    /* 22A0 80104AA0 1A004010 */  beqz       $v0, .L80104B0C
    /* 22A4 80104AA4 1080023C */   lui       $v0, %hi(_charTableRow)
    /* 22A8 80104AA8 BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 22AC 80104AAC 00000000 */   nop
    /* 22B0 80104AB0 2C5F0292 */  lbu        $v0, %lo(D_80105F2C)($s0)
    /* 22B4 80104AB4 00000000 */  nop
    /* 22B8 80104AB8 13004010 */  beqz       $v0, .L80104B08
    /* 22BC 80104ABC FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 22C0 80104AC0 2C5F02A2 */  sb         $v0, %lo(D_80105F2C)($s0)
    /* 22C4 80104AC4 FF005130 */  andi       $s1, $v0, 0xFF
    /* 22C8 80104AC8 1300222A */  slti       $v0, $s1, 0x13
    /* 22CC 80104ACC 0B004010 */  beqz       $v0, .L80104AFC
    /* 22D0 80104AD0 1080023C */   lui       $v0, %hi(_stringBuf)
    /* 22D4 80104AD4 405F4524 */  addiu      $a1, $v0, %lo(_stringBuf)
    /* 22D8 80104AD8 21202502 */  addu       $a0, $s1, $a1
  .L80104ADC:
    /* 22DC 80104ADC 01002326 */  addiu      $v1, $s1, 0x1
    /* 22E0 80104AE0 21106500 */  addu       $v0, $v1, $a1
    /* 22E4 80104AE4 00004290 */  lbu        $v0, 0x0($v0)
    /* 22E8 80104AE8 21886000 */  addu       $s1, $v1, $zero
    /* 22EC 80104AEC 000082A0 */  sb         $v0, 0x0($a0)
    /* 22F0 80104AF0 1300222A */  slti       $v0, $s1, 0x13
    /* 22F4 80104AF4 F9FF4014 */  bnez       $v0, .L80104ADC
    /* 22F8 80104AF8 21202502 */   addu      $a0, $s1, $a1
  .L80104AFC:
    /* 22FC 80104AFC 1080033C */  lui        $v1, %hi(D_80105F53)
    /* 2300 80104B00 8F000224 */  addiu      $v0, $zero, 0x8F
    /* 2304 80104B04 535F62A0 */  sb         $v0, %lo(D_80105F53)($v1)
  .L80104B08:
    /* 2308 80104B08 1080023C */  lui        $v0, %hi(_charTableRow)
  .L80104B0C:
    /* 230C 80104B0C 0680033C */  lui        $v1, %hi(vs_main_buttonsPressed)
    /* 2310 80104B10 D0E1638C */  lw         $v1, %lo(vs_main_buttonsPressed)($v1)
    /* 2314 80104B14 2B5F5190 */  lbu        $s1, %lo(_charTableRow)($v0)
    /* 2318 80104B18 00206230 */  andi       $v0, $v1, 0x2000
    /* 231C 80104B1C 0D004010 */  beqz       $v0, .L80104B54
    /* 2320 80104B20 20006230 */   andi      $v0, $v1, 0x20
    /* 2324 80104B24 BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 2328 80104B28 00000000 */   nop
    /* 232C 80104B2C 4F12040C */  jal        func_8010493C
    /* 2330 80104B30 FF000424 */   addiu     $a0, $zero, 0xFF
    /* 2334 80104B34 03000224 */  addiu      $v0, $zero, 0x3
    /* 2338 80104B38 02002216 */  bne        $s1, $v0, .L80104B44
    /* 233C 80104B3C 21880000 */   addu      $s1, $zero, $zero
    /* 2340 80104B40 01001124 */  addiu      $s1, $zero, 0x1
  .L80104B44:
    /* 2344 80104B44 1080023C */  lui        $v0, %hi(_charTableRow)
    /* 2348 80104B48 1080033C */  lui        $v1, %hi(D_80105F28)
    /* 234C 80104B4C A0140408 */  j          .L80105280
    /* 2350 80104B50 2B5F51A0 */   sb        $s1, %lo(_charTableRow)($v0)
  .L80104B54:
    /* 2354 80104B54 60004010 */  beqz       $v0, .L80104CD8
    /* 2358 80104B58 01000224 */   addiu     $v0, $zero, 0x1
    /* 235C 80104B5C 15002212 */  beq        $s1, $v0, .L80104BB4
    /* 2360 80104B60 0200222A */   slti      $v0, $s1, 0x2
    /* 2364 80104B64 05004010 */  beqz       $v0, .L80104B7C
    /* 2368 80104B68 02000224 */   addiu     $v0, $zero, 0x2
    /* 236C 80104B6C 09002012 */  beqz       $s1, .L80104B94
    /* 2370 80104B70 1080023C */   lui       $v0, %hi(D_80105F28)
    /* 2374 80104B74 30130408 */  j          .L80104CC0
    /* 2378 80104B78 00000000 */   nop
  .L80104B7C:
    /* 237C 80104B7C 23002212 */  beq        $s1, $v0, .L80104C0C
    /* 2380 80104B80 03000224 */   addiu     $v0, $zero, 0x3
    /* 2384 80104B84 35002212 */  beq        $s1, $v0, .L80104C5C
    /* 2388 80104B88 1080023C */   lui       $v0, %hi(D_80105F28)
    /* 238C 80104B8C 30130408 */  j          .L80104CC0
    /* 2390 80104B90 00000000 */   nop
  .L80104B94:
    /* 2394 80104B94 BC00030C */  jal        vs_battle_playMenuSelectSfx
    /* 2398 80104B98 00000000 */   nop
    /* 239C 80104B9C 4F12040C */  jal        func_8010493C
    /* 23A0 80104BA0 FF000424 */   addiu     $a0, $zero, 0xFF
    /* 23A4 80104BA4 1080033C */  lui        $v1, %hi(D_80105F28)
    /* 23A8 80104BA8 03000224 */  addiu      $v0, $zero, 0x3
    /* 23AC 80104BAC 2F130408 */  j          .L80104CBC
    /* 23B0 80104BB0 285F62A0 */   sb        $v0, %lo(D_80105F28)($v1)
  .L80104BB4:
    /* 23B4 80104BB4 1080033C */  lui        $v1, %hi(D_80105F2C)
    /* 23B8 80104BB8 2C5F6290 */  lbu        $v0, %lo(D_80105F2C)($v1)
    /* 23BC 80104BBC 00000000 */  nop
    /* 23C0 80104BC0 3E004010 */  beqz       $v0, .L80104CBC
    /* 23C4 80104BC4 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 23C8 80104BC8 2C5F62A0 */  sb         $v0, %lo(D_80105F2C)($v1)
    /* 23CC 80104BCC FF004530 */  andi       $a1, $v0, 0xFF
    /* 23D0 80104BD0 1300A228 */  slti       $v0, $a1, 0x13
    /* 23D4 80104BD4 1D004010 */  beqz       $v0, .L80104C4C
    /* 23D8 80104BD8 1080023C */   lui       $v0, %hi(_stringBuf)
    /* 23DC 80104BDC 405F4624 */  addiu      $a2, $v0, %lo(_stringBuf)
    /* 23E0 80104BE0 2120A600 */  addu       $a0, $a1, $a2
  .L80104BE4:
    /* 23E4 80104BE4 0100A324 */  addiu      $v1, $a1, 0x1
    /* 23E8 80104BE8 21106600 */  addu       $v0, $v1, $a2
    /* 23EC 80104BEC 00004290 */  lbu        $v0, 0x0($v0)
    /* 23F0 80104BF0 21286000 */  addu       $a1, $v1, $zero
    /* 23F4 80104BF4 000082A0 */  sb         $v0, 0x0($a0)
    /* 23F8 80104BF8 1300A228 */  slti       $v0, $a1, 0x13
    /* 23FC 80104BFC F9FF4014 */  bnez       $v0, .L80104BE4
    /* 2400 80104C00 2120A600 */   addu      $a0, $a1, $a2
    /* 2404 80104C04 14130408 */  j          .L80104C50
    /* 2408 80104C08 1080033C */   lui       $v1, %hi(D_80105F53)
  .L80104C0C:
    /* 240C 80104C0C 1080023C */  lui        $v0, %hi(D_80105F2C)
    /* 2410 80104C10 2C5F4590 */  lbu        $a1, %lo(D_80105F2C)($v0)
    /* 2414 80104C14 00000000 */  nop
    /* 2418 80104C18 1300A228 */  slti       $v0, $a1, 0x13
    /* 241C 80104C1C 0B004010 */  beqz       $v0, .L80104C4C
    /* 2420 80104C20 1080023C */   lui       $v0, %hi(_stringBuf)
    /* 2424 80104C24 405F4624 */  addiu      $a2, $v0, %lo(_stringBuf)
    /* 2428 80104C28 2120A600 */  addu       $a0, $a1, $a2
  .L80104C2C:
    /* 242C 80104C2C 0100A324 */  addiu      $v1, $a1, 0x1
    /* 2430 80104C30 21106600 */  addu       $v0, $v1, $a2
    /* 2434 80104C34 00004290 */  lbu        $v0, 0x0($v0)
    /* 2438 80104C38 21286000 */  addu       $a1, $v1, $zero
    /* 243C 80104C3C 000082A0 */  sb         $v0, 0x0($a0)
    /* 2440 80104C40 1300A228 */  slti       $v0, $a1, 0x13
    /* 2444 80104C44 F9FF4014 */  bnez       $v0, .L80104C2C
    /* 2448 80104C48 2120A600 */   addu      $a0, $a1, $a2
  .L80104C4C:
    /* 244C 80104C4C 1080033C */  lui        $v1, %hi(D_80105F53)
  .L80104C50:
    /* 2450 80104C50 8F000224 */  addiu      $v0, $zero, 0x8F
    /* 2454 80104C54 2F130408 */  j          .L80104CBC
    /* 2458 80104C58 535F62A0 */   sb        $v0, %lo(D_80105F53)($v1)
  .L80104C5C:
    /* 245C 80104C5C 1080073C */  lui        $a3, %hi(D_80105F2C)
    /* 2460 80104C60 2C5FE290 */  lbu        $v0, %lo(D_80105F2C)($a3)
    /* 2464 80104C64 13000524 */  addiu      $a1, $zero, 0x13
    /* 2468 80104C68 2A104500 */  slt        $v0, $v0, $a1
    /* 246C 80104C6C 0C004010 */  beqz       $v0, .L80104CA0
    /* 2470 80104C70 1080023C */   lui       $v0, %hi(_stringBuf)
    /* 2474 80104C74 405F4624 */  addiu      $a2, $v0, %lo(_stringBuf)
    /* 2478 80104C78 FFFFA424 */  addiu      $a0, $a1, -0x1
  .L80104C7C:
    /* 247C 80104C7C 21108600 */  addu       $v0, $a0, $a2
    /* 2480 80104C80 00004390 */  lbu        $v1, 0x0($v0)
    /* 2484 80104C84 2110A600 */  addu       $v0, $a1, $a2
    /* 2488 80104C88 000043A0 */  sb         $v1, 0x0($v0)
    /* 248C 80104C8C 2C5FE290 */  lbu        $v0, %lo(D_80105F2C)($a3)
    /* 2490 80104C90 21288000 */  addu       $a1, $a0, $zero
    /* 2494 80104C94 2A104500 */  slt        $v0, $v0, $a1
    /* 2498 80104C98 F8FF4014 */  bnez       $v0, .L80104C7C
    /* 249C 80104C9C FFFFA424 */   addiu     $a0, $a1, -0x1
  .L80104CA0:
    /* 24A0 80104CA0 1080023C */  lui        $v0, %hi(_stringBuf)
    /* 24A4 80104CA4 1080033C */  lui        $v1, %hi(D_80105F2C)
    /* 24A8 80104CA8 2C5F6390 */  lbu        $v1, %lo(D_80105F2C)($v1)
    /* 24AC 80104CAC 405F4224 */  addiu      $v0, $v0, %lo(_stringBuf)
    /* 24B0 80104CB0 21186200 */  addu       $v1, $v1, $v0
    /* 24B4 80104CB4 8F000224 */  addiu      $v0, $zero, 0x8F
    /* 24B8 80104CB8 000062A0 */  sb         $v0, 0x0($v1)
  .L80104CBC:
    /* 24BC 80104CBC 1080023C */  lui        $v0, %hi(D_80105F28)
  .L80104CC0:
    /* 24C0 80104CC0 285F4390 */  lbu        $v1, %lo(D_80105F28)($v0)
    /* 24C4 80104CC4 01000224 */  addiu      $v0, $zero, 0x1
    /* 24C8 80104CC8 6F016214 */  bne        $v1, $v0, .L80105288
    /* 24CC 80104CCC 00000000 */   nop
    /* 24D0 80104CD0 BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 24D4 80104CD4 00000000 */   nop
  .L80104CD8:
    /* 24D8 80104CD8 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 24DC 80104CDC DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 24E0 80104CE0 00000000 */  nop
    /* 24E4 80104CE4 00104230 */  andi       $v0, $v0, 0x1000
    /* 24E8 80104CE8 0C004010 */  beqz       $v0, .L80104D1C
    /* 24EC 80104CEC 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 24F0 80104CF0 08002016 */  bnez       $s1, .L80104D14
    /* 24F4 80104CF4 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 24F8 80104CF8 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 24FC 80104CFC 00000000 */  nop
    /* 2500 80104D00 00104230 */  andi       $v0, $v0, 0x1000
    /* 2504 80104D04 05004010 */  beqz       $v0, .L80104D1C
    /* 2508 80104D08 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 250C 80104D0C 47130408 */  j          .L80104D1C
    /* 2510 80104D10 03001124 */   addiu     $s1, $zero, 0x3
  .L80104D14:
    /* 2514 80104D14 FFFF3126 */  addiu      $s1, $s1, -0x1
    /* 2518 80104D18 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
  .L80104D1C:
    /* 251C 80104D1C DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 2520 80104D20 00000000 */  nop
    /* 2524 80104D24 00404230 */  andi       $v0, $v0, 0x4000
    /* 2528 80104D28 0B004010 */  beqz       $v0, .L80104D58
    /* 252C 80104D2C 03000224 */   addiu     $v0, $zero, 0x3
    /* 2530 80104D30 08002216 */  bne        $s1, $v0, .L80104D54
    /* 2534 80104D34 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 2538 80104D38 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 253C 80104D3C 00000000 */  nop
    /* 2540 80104D40 00404230 */  andi       $v0, $v0, 0x4000
    /* 2544 80104D44 05004010 */  beqz       $v0, .L80104D5C
    /* 2548 80104D48 1080103C */   lui       $s0, %hi(_charTableRow)
    /* 254C 80104D4C 57130408 */  j          .L80104D5C
    /* 2550 80104D50 21880000 */   addu      $s1, $zero, $zero
  .L80104D54:
    /* 2554 80104D54 01003126 */  addiu      $s1, $s1, 0x1
  .L80104D58:
    /* 2558 80104D58 1080103C */  lui        $s0, %hi(_charTableRow)
  .L80104D5C:
    /* 255C 80104D5C 2B5F0292 */  lbu        $v0, %lo(_charTableRow)($s0)
    /* 2560 80104D60 00000000 */  nop
    /* 2564 80104D64 04002212 */  beq        $s1, $v0, .L80104D78
    /* 2568 80104D68 00000000 */   nop
    /* 256C 80104D6C BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 2570 80104D70 00000000 */   nop
    /* 2574 80104D74 2B5F11A2 */  sb         $s1, %lo(_charTableRow)($s0)
  .L80104D78:
    /* 2578 80104D78 4F12040C */  jal        func_8010493C
    /* 257C 80104D7C 21202002 */   addu      $a0, $s1, $zero
    /* 2580 80104D80 1080103C */  lui        $s0, %hi(D_80105F29)
    /* 2584 80104D84 00291100 */  sll        $a1, $s1, 4
    /* 2588 80104D88 1C00A524 */  addiu      $a1, $a1, 0x1C
    /* 258C 80104D8C 295F0492 */  lbu        $a0, %lo(D_80105F29)($s0)
    /* 2590 80104D90 37FF030C */  jal        func_800FFCDC
    /* 2594 80104D94 002C0500 */   sll       $a1, $a1, 16
    /* 2598 80104D98 A2140408 */  j          .L80105288
    /* 259C 80104D9C 295F02A2 */   sb        $v0, %lo(D_80105F29)($s0)
    /* 25A0 80104DA0 1080103C */  lui        $s0, %hi(D_80105F2C)
    /* 25A4 80104DA4 2C5F0492 */  lbu        $a0, %lo(D_80105F2C)($s0)
    /* 25A8 80104DA8 620F040C */  jal        _insertDeleteHandler
    /* 25AC 80104DAC 00000000 */   nop
    /* 25B0 80104DB0 0680033C */  lui        $v1, %hi(vs_main_buttonsPressed)
    /* 25B4 80104DB4 D0E1638C */  lw         $v1, %lo(vs_main_buttonsPressed)($v1)
    /* 25B8 80104DB8 2C5F02A2 */  sb         $v0, %lo(D_80105F2C)($s0)
    /* 25BC 80104DBC 00086230 */  andi       $v0, $v1, 0x800
    /* 25C0 80104DC0 06004010 */  beqz       $v0, .L80104DDC
    /* 25C4 80104DC4 20006230 */   andi      $v0, $v1, 0x20
    /* 25C8 80104DC8 BC00030C */  jal        vs_battle_playMenuSelectSfx
    /* 25CC 80104DCC 00000000 */   nop
    /* 25D0 80104DD0 1080033C */  lui        $v1, %hi(D_80105F28)
    /* 25D4 80104DD4 A1140408 */  j          .L80105284
    /* 25D8 80104DD8 03000224 */   addiu     $v0, $zero, 0x3
  .L80104DDC:
    /* 25DC 80104DDC 1A004010 */  beqz       $v0, .L80104E48
    /* 25E0 80104DE0 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 25E4 80104DE4 BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 25E8 80104DE8 00000000 */   nop
    /* 25EC 80104DEC 1080043C */  lui        $a0, %hi(_charTableColumn)
    /* 25F0 80104DF0 1080023C */  lui        $v0, %hi(_charTableRow)
    /* 25F4 80104DF4 1080053C */  lui        $a1, %hi(_charTable)
    /* 25F8 80104DF8 2B5F4290 */  lbu        $v0, %lo(_charTableRow)($v0)
    /* 25FC 80104DFC 2A5F8490 */  lbu        $a0, %lo(_charTableColumn)($a0)
    /* 2600 80104E00 00190200 */  sll        $v1, $v0, 4
    /* 2604 80104E04 23186200 */  subu       $v1, $v1, $v0
    /* 2608 80104E08 345FA28C */  lw         $v0, %lo(_charTable)($a1)
    /* 260C 80104E0C 21186400 */  addu       $v1, $v1, $a0
    /* 2610 80104E10 21104300 */  addu       $v0, $v0, $v1
    /* 2614 80104E14 00005190 */  lbu        $s1, 0x0($v0)
    /* 2618 80104E18 1080023C */  lui        $v0, %hi(_stringBuf)
    /* 261C 80104E1C 2C5F0392 */  lbu        $v1, %lo(D_80105F2C)($s0)
    /* 2620 80104E20 405F4224 */  addiu      $v0, $v0, %lo(_stringBuf)
    /* 2624 80104E24 21186200 */  addu       $v1, $v1, $v0
    /* 2628 80104E28 000071A0 */  sb         $s1, 0x0($v1)
    /* 262C 80104E2C 2C5F0392 */  lbu        $v1, %lo(D_80105F2C)($s0)
    /* 2630 80104E30 00000000 */  nop
    /* 2634 80104E34 1300622C */  sltiu      $v0, $v1, 0x13
    /* 2638 80104E38 02004010 */  beqz       $v0, .L80104E44
    /* 263C 80104E3C 01006224 */   addiu     $v0, $v1, 0x1
    /* 2640 80104E40 2C5F02A2 */  sb         $v0, %lo(D_80105F2C)($s0)
  .L80104E44:
    /* 2644 80104E44 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
  .L80104E48:
    /* 2648 80104E48 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 264C 80104E4C 00000000 */  nop
    /* 2650 80104E50 40004230 */  andi       $v0, $v0, 0x40
    /* 2654 80104E54 1B004010 */  beqz       $v0, .L80104EC4
    /* 2658 80104E58 1080073C */   lui       $a3, %hi(_charTableRow)
    /* 265C 80104E5C BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 2660 80104E60 00000000 */   nop
    /* 2664 80104E64 1080033C */  lui        $v1, %hi(D_80105F2C)
    /* 2668 80104E68 2C5F6290 */  lbu        $v0, %lo(D_80105F2C)($v1)
    /* 266C 80104E6C 00000000 */  nop
    /* 2670 80104E70 13004010 */  beqz       $v0, .L80104EC0
    /* 2674 80104E74 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 2678 80104E78 2C5F62A0 */  sb         $v0, %lo(D_80105F2C)($v1)
    /* 267C 80104E7C FF005130 */  andi       $s1, $v0, 0xFF
    /* 2680 80104E80 1300222A */  slti       $v0, $s1, 0x13
    /* 2684 80104E84 0B004010 */  beqz       $v0, .L80104EB4
    /* 2688 80104E88 1080023C */   lui       $v0, %hi(_stringBuf)
    /* 268C 80104E8C 405F4524 */  addiu      $a1, $v0, %lo(_stringBuf)
    /* 2690 80104E90 21202502 */  addu       $a0, $s1, $a1
  .L80104E94:
    /* 2694 80104E94 01002326 */  addiu      $v1, $s1, 0x1
    /* 2698 80104E98 21106500 */  addu       $v0, $v1, $a1
    /* 269C 80104E9C 00004290 */  lbu        $v0, 0x0($v0)
    /* 26A0 80104EA0 21886000 */  addu       $s1, $v1, $zero
    /* 26A4 80104EA4 000082A0 */  sb         $v0, 0x0($a0)
    /* 26A8 80104EA8 1300222A */  slti       $v0, $s1, 0x13
    /* 26AC 80104EAC F9FF4014 */  bnez       $v0, .L80104E94
    /* 26B0 80104EB0 21202502 */   addu      $a0, $s1, $a1
  .L80104EB4:
    /* 26B4 80104EB4 1080033C */  lui        $v1, %hi(D_80105F53)
    /* 26B8 80104EB8 8F000224 */  addiu      $v0, $zero, 0x8F
    /* 26BC 80104EBC 535F62A0 */  sb         $v0, %lo(D_80105F53)($v1)
  .L80104EC0:
    /* 26C0 80104EC0 1080073C */  lui        $a3, %hi(_charTableRow)
  .L80104EC4:
    /* 26C4 80104EC4 1080043C */  lui        $a0, %hi(_charTableColumn)
    /* 26C8 80104EC8 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 26CC 80104ECC 2B5FE690 */  lbu        $a2, %lo(_charTableRow)($a3)
    /* 26D0 80104ED0 2A5F8490 */  lbu        $a0, %lo(_charTableColumn)($a0)
    /* 26D4 80104ED4 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 26D8 80104ED8 C0180600 */  sll        $v1, $a2, 3
    /* 26DC 80104EDC 23186600 */  subu       $v1, $v1, $a2
    /* 26E0 80104EE0 40180300 */  sll        $v1, $v1, 1
    /* 26E4 80104EE4 00104230 */  andi       $v0, $v0, 0x1000
    /* 26E8 80104EE8 0A004010 */  beqz       $v0, .L80104F14
    /* 26EC 80104EEC 21288300 */   addu      $a1, $a0, $v1
    /* 26F0 80104EF0 0700C014 */  bnez       $a2, .L80104F10
    /* 26F4 80104EF4 FFFFC224 */   addiu     $v0, $a2, -0x1
    /* 26F8 80104EF8 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 26FC 80104EFC D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 2700 80104F00 00000000 */  nop
    /* 2704 80104F04 00104230 */  andi       $v0, $v0, 0x1000
    /* 2708 80104F08 02004010 */  beqz       $v0, .L80104F14
    /* 270C 80104F0C 08000224 */   addiu     $v0, $zero, 0x8
  .L80104F10:
    /* 2710 80104F10 2B5FE2A0 */  sb         $v0, %lo(_charTableRow)($a3)
  .L80104F14:
    /* 2714 80104F14 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 2718 80104F18 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 271C 80104F1C 00000000 */  nop
    /* 2720 80104F20 00404230 */  andi       $v0, $v0, 0x4000
    /* 2724 80104F24 10004010 */  beqz       $v0, .L80104F68
    /* 2728 80104F28 1080043C */   lui       $a0, %hi(_charTableRow)
    /* 272C 80104F2C 2B5F8390 */  lbu        $v1, %lo(_charTableRow)($a0)
    /* 2730 80104F30 08000224 */  addiu      $v0, $zero, 0x8
    /* 2734 80104F34 0B006214 */  bne        $v1, $v0, .L80104F64
    /* 2738 80104F38 01006224 */   addiu     $v0, $v1, 0x1
    /* 273C 80104F3C 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 2740 80104F40 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 2744 80104F44 00000000 */  nop
    /* 2748 80104F48 00404230 */  andi       $v0, $v0, 0x4000
    /* 274C 80104F4C 06004010 */  beqz       $v0, .L80104F68
    /* 2750 80104F50 1080023C */   lui       $v0, %hi(D_80105F28)
    /* 2754 80104F54 285F4290 */  lbu        $v0, %lo(D_80105F28)($v0)
    /* 2758 80104F58 00000000 */  nop
    /* 275C 80104F5C 02004238 */  xori       $v0, $v0, 0x2
    /* 2760 80104F60 2B100200 */  sltu       $v0, $zero, $v0
  .L80104F64:
    /* 2764 80104F64 2B5F82A0 */  sb         $v0, %lo(_charTableRow)($a0)
  .L80104F68:
    /* 2768 80104F68 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 276C 80104F6C DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 2770 80104F70 00000000 */  nop
    /* 2774 80104F74 00804230 */  andi       $v0, $v0, 0x8000
    /* 2778 80104F78 1A004010 */  beqz       $v0, .L80104FE4
    /* 277C 80104F7C 1080033C */   lui       $v1, %hi(_charTableColumn)
    /* 2780 80104F80 2A5F6290 */  lbu        $v0, %lo(_charTableColumn)($v1)
    /* 2784 80104F84 00000000 */  nop
    /* 2788 80104F88 15004014 */  bnez       $v0, .L80104FE0
    /* 278C 80104F8C FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 2790 80104F90 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 2794 80104F94 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 2798 80104F98 00000000 */  nop
    /* 279C 80104F9C 00804230 */  andi       $v0, $v0, 0x8000
    /* 27A0 80104FA0 11004010 */  beqz       $v0, .L80104FE8
    /* 27A4 80104FA4 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 27A8 80104FA8 BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 27AC 80104FAC 00000000 */   nop
    /* 27B0 80104FB0 1080033C */  lui        $v1, %hi(_charTableRow)
    /* 27B4 80104FB4 2B5F6290 */  lbu        $v0, %lo(_charTableRow)($v1)
    /* 27B8 80104FB8 00000000 */  nop
    /* 27BC 80104FBC 03004014 */  bnez       $v0, .L80104FCC
    /* 27C0 80104FC0 00000000 */   nop
    /* 27C4 80104FC4 F4130408 */  j          .L80104FD0
    /* 27C8 80104FC8 02000224 */   addiu     $v0, $zero, 0x2
  .L80104FCC:
    /* 27CC 80104FCC 03000224 */  addiu      $v0, $zero, 0x3
  .L80104FD0:
    /* 27D0 80104FD0 2B5F62A0 */  sb         $v0, %lo(_charTableRow)($v1)
    /* 27D4 80104FD4 1080033C */  lui        $v1, %hi(D_80105F28)
    /* 27D8 80104FD8 A1140408 */  j          .L80105284
    /* 27DC 80104FDC 01000224 */   addiu     $v0, $zero, 0x1
  .L80104FE0:
    /* 27E0 80104FE0 2A5F62A0 */  sb         $v0, %lo(_charTableColumn)($v1)
  .L80104FE4:
    /* 27E4 80104FE4 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
  .L80104FE8:
    /* 27E8 80104FE8 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 27EC 80104FEC 00000000 */  nop
    /* 27F0 80104FF0 00204230 */  andi       $v0, $v0, 0x2000
    /* 27F4 80104FF4 0E004010 */  beqz       $v0, .L80105030
    /* 27F8 80104FF8 1080043C */   lui       $a0, %hi(_charTableColumn)
    /* 27FC 80104FFC 2A5F8390 */  lbu        $v1, %lo(_charTableColumn)($a0)
    /* 2800 80105000 0D000224 */  addiu      $v0, $zero, 0xD
    /* 2804 80105004 09006214 */  bne        $v1, $v0, .L8010502C
    /* 2808 80105008 01006224 */   addiu     $v0, $v1, 0x1
    /* 280C 8010500C 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 2810 80105010 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 2814 80105014 00000000 */  nop
    /* 2818 80105018 00204230 */  andi       $v0, $v0, 0x2000
    /* 281C 8010501C 05004010 */  beqz       $v0, .L80105034
    /* 2820 80105020 1080023C */   lui       $v0, %hi(_charTableRow)
    /* 2824 80105024 0D140408 */  j          .L80105034
    /* 2828 80105028 2A5F80A0 */   sb        $zero, %lo(_charTableColumn)($a0)
  .L8010502C:
    /* 282C 8010502C 2A5F82A0 */  sb         $v0, %lo(_charTableColumn)($a0)
  .L80105030:
    /* 2830 80105030 1080023C */  lui        $v0, %hi(_charTableRow)
  .L80105034:
    /* 2834 80105034 2B5F4390 */  lbu        $v1, %lo(_charTableRow)($v0)
    /* 2838 80105038 1080043C */  lui        $a0, %hi(_charTableColumn)
    /* 283C 8010503C C0100300 */  sll        $v0, $v1, 3
    /* 2840 80105040 23104300 */  subu       $v0, $v0, $v1
    /* 2844 80105044 2A5F8390 */  lbu        $v1, %lo(_charTableColumn)($a0)
    /* 2848 80105048 40100200 */  sll        $v0, $v0, 1
    /* 284C 8010504C 21186200 */  addu       $v1, $v1, $v0
    /* 2850 80105050 8E00A310 */  beq        $a1, $v1, .L8010528C
    /* 2854 80105054 1080113C */   lui       $s1, %hi(D_80105F28)
    /* 2858 80105058 BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 285C 8010505C 00000000 */   nop
    /* 2860 80105060 A3140408 */  j          .L8010528C
    /* 2864 80105064 00000000 */   nop
    /* 2868 80105068 4F12040C */  jal        func_8010493C
    /* 286C 8010506C 21200000 */   addu      $a0, $zero, $zero
    /* 2870 80105070 1080023C */  lui        $v0, %hi(D_80105F30)
    /* 2874 80105074 1080033C */  lui        $v1, %hi(D_80105F28)
    /* 2878 80105078 305F40A0 */  sb         $zero, %lo(D_80105F30)($v0)
    /* 287C 8010507C A1140408 */  j          .L80105284
    /* 2880 80105080 04000224 */   addiu     $v0, $zero, 0x4
    /* 2884 80105084 1080023C */  lui        $v0, %hi(_animStep)
    /* 2888 80105088 315F4390 */  lbu        $v1, %lo(_animStep)($v0)
    /* 288C 8010508C 0A000224 */  addiu      $v0, $zero, 0xA
    /* 2890 80105090 7E006214 */  bne        $v1, $v0, .L8010528C
    /* 2894 80105094 1080113C */   lui       $s1, %hi(D_80105F28)
    /* 2898 80105098 1080023C */  lui        $v0, %hi(D_80105F10)
    /* 289C 8010509C 105F5124 */  addiu      $s1, $v0, %lo(D_80105F10)
    /* 28A0 801050A0 C70F040C */  jal        _copyNormalizedString
    /* 28A4 801050A4 21202002 */   addu      $a0, $s1, $zero
    /* 28A8 801050A8 18004010 */  beqz       $v0, .L8010510C
    /* 28AC 801050AC 21202002 */   addu      $a0, $s1, $zero
    /* 28B0 801050B0 0680053C */  lui        $a1, %hi(vs_battle_inventory)
    /* 28B4 801050B4 1080023C */  lui        $v0, %hi(D_80105F2E)
    /* 28B8 801050B8 2E5F4290 */  lbu        $v0, %lo(D_80105F2E)($v0)
    /* 28BC 801050BC 6801A524 */  addiu      $a1, $a1, %lo(vs_battle_inventory)
    /* 28C0 801050C0 40110200 */  sll        $v0, $v0, 5
    /* 28C4 801050C4 21104500 */  addu       $v0, $v0, $a1
    /* 28C8 801050C8 01004390 */  lbu        $v1, 0x1($v0)
    /* 28CC 801050CC 18000624 */  addiu      $a2, $zero, 0x18
    /* 28D0 801050D0 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 28D4 801050D4 40100300 */  sll        $v0, $v1, 1
    /* 28D8 801050D8 21104300 */  addu       $v0, $v0, $v1
    /* 28DC 801050DC 80100200 */  sll        $v0, $v0, 2
    /* 28E0 801050E0 23104300 */  subu       $v0, $v0, $v1
    /* 28E4 801050E4 80100200 */  sll        $v0, $v0, 2
    /* 28E8 801050E8 21104500 */  addu       $v0, $v0, $a1
    /* 28EC 801050EC 80024290 */  lbu        $v0, 0x280($v0)
    /* 28F0 801050F0 1080033C */  lui        $v1, %hi(vs_mainMenu_itemNames)
    /* 28F4 801050F4 40280200 */  sll        $a1, $v0, 1
    /* 28F8 801050F8 2128A200 */  addu       $a1, $a1, $v0
    /* 28FC 801050FC 9C22628C */  lw         $v0, %lo(vs_mainMenu_itemNames)($v1)
    /* 2900 80105100 C0280500 */  sll        $a1, $a1, 3
    /* 2904 80105104 0D33030C */  jal        vs_battle_rMemcpy
    /* 2908 80105108 21284500 */   addu      $a1, $v0, $a1
  .L8010510C:
    /* 290C 8010510C 8123030C */  jal        func_800C8E04
    /* 2910 80105110 01000424 */   addiu     $a0, $zero, 0x1
    /* 2914 80105114 1080053C */  lui        $a1, %hi(D_80105DDA)
    /* 2918 80105118 DA5DA524 */  addiu      $a1, $a1, %lo(D_80105DDA)
    /* 291C 8010511C 0F80103C */  lui        $s0, %hi(vs_battle_stringBuf)
    /* 2920 80105120 8C4E048E */  lw         $a0, %lo(vs_battle_stringBuf)($s0)
    /* 2924 80105124 0F80023C */  lui        $v0, %hi(vs_battle_stringContext + 0x28)
    /* 2928 80105128 171A030C */  jal        vs_battle_printf
    /* 292C 8010512C 905151AC */   sw        $s1, %lo(vs_battle_stringContext + 0x28)($v0)
    /* 2930 80105130 8C4E048E */  lw         $a0, %lo(vs_battle_stringBuf)($s0)
    /* 2934 80105134 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 2938 80105138 00000000 */   nop
    /* 293C 8010513C D711040C */  jal        _confirmScreen
    /* 2940 80105140 01000424 */   addiu     $a0, $zero, 0x1
    /* 2944 80105144 1080033C */  lui        $v1, %hi(D_80105F28)
    /* 2948 80105148 A1140408 */  j          .L80105284
    /* 294C 8010514C 05000224 */   addiu     $v0, $zero, 0x5
    /* 2950 80105150 D711040C */  jal        _confirmScreen
    /* 2954 80105154 21200000 */   addu      $a0, $zero, $zero
    /* 2958 80105158 21884000 */  addu       $s1, $v0, $zero
    /* 295C 8010515C 4A002012 */  beqz       $s1, .L80105288
    /* 2960 80105160 00000000 */   nop
    /* 2964 80105164 1934030C */  jal        vs_battle_dismissTextBox
    /* 2968 80105168 07000424 */   addiu     $a0, $zero, 0x7
    /* 296C 8010516C 02000224 */  addiu      $v0, $zero, 0x2
    /* 2970 80105170 09002216 */  bne        $s1, $v0, .L80105198
    /* 2974 80105174 0680033C */   lui       $v1, %hi(vs_battle_inventory)
    /* 2978 80105178 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 297C 8010517C 00000000 */   nop
    /* 2980 80105180 1080033C */  lui        $v1, %hi(D_80105F30)
    /* 2984 80105184 01000224 */  addiu      $v0, $zero, 0x1
    /* 2988 80105188 305F62A0 */  sb         $v0, %lo(D_80105F30)($v1)
    /* 298C 8010518C 1080033C */  lui        $v1, %hi(D_80105F28)
    /* 2990 80105190 A1140408 */  j          .L80105284
    /* 2994 80105194 06000224 */   addiu     $v0, $zero, 0x6
  .L80105198:
    /* 2998 80105198 1080023C */  lui        $v0, %hi(D_80105F2E)
    /* 299C 8010519C 2E5F4290 */  lbu        $v0, %lo(D_80105F2E)($v0)
    /* 29A0 801051A0 68017224 */  addiu      $s2, $v1, %lo(vs_battle_inventory)
    /* 29A4 801051A4 40110200 */  sll        $v0, $v0, 5
    /* 29A8 801051A8 21805200 */  addu       $s0, $v0, $s2
    /* 29AC 801051AC 01000224 */  addiu      $v0, $zero, 0x1
    /* 29B0 801051B0 10002216 */  bne        $s1, $v0, .L801051F4
    /* 29B4 801051B4 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 29B8 801051B8 6216010C */  jal        vs_main_playSfxDefault
    /* 29BC 801051BC 0D000524 */   addiu     $a1, $zero, 0xD
    /* 29C0 801051C0 08000426 */  addiu      $a0, $s0, 0x8
    /* 29C4 801051C4 1080053C */  lui        $a1, %hi(D_80105F10)
    /* 29C8 801051C8 105FA524 */  addiu      $a1, $a1, %lo(D_80105F10)
    /* 29CC 801051CC 0D33030C */  jal        vs_battle_rMemcpy
    /* 29D0 801051D0 18000624 */   addiu     $a2, $zero, 0x18
    /* 29D4 801051D4 03000292 */  lbu        $v0, 0x3($s0)
    /* 29D8 801051D8 00000000 */  nop
    /* 29DC 801051DC 47004010 */  beqz       $v0, .L801052FC
    /* 29E0 801051E0 01000224 */   addiu     $v0, $zero, 0x1
    /* 29E4 801051E4 CEAC010C */  jal        vs_battle_equipWeapon
    /* 29E8 801051E8 21200002 */   addu      $a0, $s0, $zero
    /* 29EC 801051EC BF140408 */  j          .L801052FC
    /* 29F0 801051F0 01000224 */   addiu     $v0, $zero, 0x1
  .L801051F4:
    /* 29F4 801051F4 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 29F8 801051F8 00000000 */   nop
    /* 29FC 801051FC 08000392 */  lbu        $v1, 0x8($s0)
    /* 2A00 80105200 E7000224 */  addiu      $v0, $zero, 0xE7
    /* 2A04 80105204 12006214 */  bne        $v1, $v0, .L80105250
    /* 2A08 80105208 08000426 */   addiu     $a0, $s0, 0x8
    /* 2A0C 8010520C 01000392 */  lbu        $v1, 0x1($s0)
    /* 2A10 80105210 18000624 */  addiu      $a2, $zero, 0x18
    /* 2A14 80105214 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 2A18 80105218 40100300 */  sll        $v0, $v1, 1
    /* 2A1C 8010521C 21104300 */  addu       $v0, $v0, $v1
    /* 2A20 80105220 80100200 */  sll        $v0, $v0, 2
    /* 2A24 80105224 23104300 */  subu       $v0, $v0, $v1
    /* 2A28 80105228 80100200 */  sll        $v0, $v0, 2
    /* 2A2C 8010522C 21105200 */  addu       $v0, $v0, $s2
    /* 2A30 80105230 80024290 */  lbu        $v0, 0x280($v0)
    /* 2A34 80105234 1080033C */  lui        $v1, %hi(vs_mainMenu_itemNames)
    /* 2A38 80105238 40280200 */  sll        $a1, $v0, 1
    /* 2A3C 8010523C 2128A200 */  addu       $a1, $a1, $v0
    /* 2A40 80105240 9C22628C */  lw         $v0, %lo(vs_mainMenu_itemNames)($v1)
    /* 2A44 80105244 C0280500 */  sll        $a1, $a1, 3
    /* 2A48 80105248 0D33030C */  jal        vs_battle_rMemcpy
    /* 2A4C 8010524C 21284500 */   addu      $a1, $v0, $a1
  .L80105250:
    /* 2A50 80105250 BF140408 */  j          .L801052FC
    /* 2A54 80105254 01000224 */   addiu     $v0, $zero, 0x1
    /* 2A58 80105258 1080023C */  lui        $v0, %hi(_animStep)
    /* 2A5C 8010525C 315F4290 */  lbu        $v0, %lo(_animStep)($v0)
    /* 2A60 80105260 00000000 */  nop
    /* 2A64 80105264 09004014 */  bnez       $v0, .L8010528C
    /* 2A68 80105268 1080113C */   lui       $s1, %hi(D_80105F28)
    /* 2A6C 8010526C 1080023C */  lui        $v0, %hi(_charTableColumn)
    /* 2A70 80105270 2A5F40A0 */  sb         $zero, %lo(_charTableColumn)($v0)
    /* 2A74 80105274 1080023C */  lui        $v0, %hi(_charTableRow)
    /* 2A78 80105278 1080033C */  lui        $v1, %hi(D_80105F28)
    /* 2A7C 8010527C 2B5F40A0 */  sb         $zero, %lo(_charTableRow)($v0)
  .L80105280:
    /* 2A80 80105280 02000224 */  addiu      $v0, $zero, 0x2
  .L80105284:
    /* 2A84 80105284 285F62A0 */  sb         $v0, %lo(D_80105F28)($v1)
  .L80105288:
    /* 2A88 80105288 1080113C */  lui        $s1, %hi(D_80105F28)
  .L8010528C:
    /* 2A8C 8010528C 285F2392 */  lbu        $v1, %lo(D_80105F28)($s1)
    /* 2A90 80105290 02000224 */  addiu      $v0, $zero, 0x2
    /* 2A94 80105294 09006214 */  bne        $v1, $v0, .L801052BC
    /* 2A98 80105298 1080103C */   lui       $s0, %hi(D_80105F29)
    /* 2A9C 8010529C 1080023C */  lui        $v0, %hi(_charTableColumn)
    /* 2AA0 801052A0 2A5F4590 */  lbu        $a1, %lo(_charTableColumn)($v0)
    /* 2AA4 801052A4 1080023C */  lui        $v0, %hi(_charTableRow)
    /* 2AA8 801052A8 295F0492 */  lbu        $a0, %lo(D_80105F29)($s0)
    /* 2AAC 801052AC 2B5F4690 */  lbu        $a2, %lo(_charTableRow)($v0)
    /* 2AB0 801052B0 BC11040C */  jal        _highlightCharSelection
    /* 2AB4 801052B4 00000000 */   nop
    /* 2AB8 801052B8 295F02A2 */  sb         $v0, %lo(D_80105F29)($s0)
  .L801052BC:
    /* 2ABC 801052BC 285F2292 */  lbu        $v0, %lo(D_80105F28)($s1)
    /* 2AC0 801052C0 00000000 */  nop
    /* 2AC4 801052C4 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 2AC8 801052C8 0200422C */  sltiu      $v0, $v0, 0x2
    /* 2ACC 801052CC 0A004010 */  beqz       $v0, .L801052F8
    /* 2AD0 801052D0 30000524 */   addiu     $a1, $zero, 0x30
    /* 2AD4 801052D4 1080023C */  lui        $v0, %hi(D_80105F2C)
    /* 2AD8 801052D8 2C5F4290 */  lbu        $v0, %lo(D_80105F2C)($v0)
    /* 2ADC 801052DC 08000624 */  addiu      $a2, $zero, 0x8
    /* 2AE0 801052E0 0C000724 */  addiu      $a3, $zero, 0xC
    /* 2AE4 801052E4 40200200 */  sll        $a0, $v0, 1
    /* 2AE8 801052E8 21208200 */  addu       $a0, $a0, $v0
    /* 2AEC 801052EC 40200400 */  sll        $a0, $a0, 1
    /* 2AF0 801052F0 9411040C */  jal        _highlightSelection
    /* 2AF4 801052F4 A1008424 */   addiu     $a0, $a0, 0xA1
  .L801052F8:
    /* 2AF8 801052F8 21100000 */  addu       $v0, $zero, $zero
  .L801052FC:
    /* 2AFC 801052FC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 2B00 80105300 1800B28F */  lw         $s2, 0x18($sp)
    /* 2B04 80105304 1400B18F */  lw         $s1, 0x14($sp)
    /* 2B08 80105308 1000B08F */  lw         $s0, 0x10($sp)
    /* 2B0C 8010530C 0800E003 */  jr         $ra
    /* 2B10 80105310 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_801049A0
