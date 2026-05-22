nonmatching _shieldNavigation, 0x270

glabel _shieldNavigation
    /* 216C 8010496C C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 2170 80104970 21288000 */  addu       $a1, $a0, $zero
    /* 2174 80104974 3800BFAF */  sw         $ra, 0x38($sp)
    /* 2178 80104978 3400B3AF */  sw         $s3, 0x34($sp)
    /* 217C 8010497C 3000B2AF */  sw         $s2, 0x30($sp)
    /* 2180 80104980 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 2184 80104984 1100A010 */  beqz       $a1, .L801049CC
    /* 2188 80104988 2800B0AF */   sw        $s0, 0x28($sp)
    /* 218C 8010498C 1180033C */  lui        $v1, %hi(D_80109A40)
    /* 2190 80104990 03120500 */  sra        $v0, $a1, 8
    /* 2194 80104994 409A62A0 */  sb         $v0, %lo(D_80109A40)($v1)
    /* 2198 80104998 FF004430 */  andi       $a0, $v0, 0xFF
    /* 219C 8010499C 1180033C */  lui        $v1, %hi(D_80109A41)
    /* 21A0 801049A0 FFFFA224 */  addiu      $v0, $a1, -0x1
    /* 21A4 801049A4 D90F040C */  jal        func_80103F64
    /* 21A8 801049A8 419A62A0 */   sb        $v0, %lo(D_80109A41)($v1)
    /* 21AC 801049AC 21100000 */  addu       $v0, $zero, $zero
    /* 21B0 801049B0 1180033C */  lui        $v1, %hi(D_80109A42)
    /* 21B4 801049B4 429A60A0 */  sb         $zero, %lo(D_80109A42)($v1)
    /* 21B8 801049B8 1180033C */  lui        $v1, %hi(D_80109A3F)
    /* 21BC 801049BC 3F9A60A0 */  sb         $zero, %lo(D_80109A3F)($v1)
    /* 21C0 801049C0 1180033C */  lui        $v1, %hi(D_80109A3E)
    /* 21C4 801049C4 F0120408 */  j          .L80104BC0
    /* 21C8 801049C8 3E9A60A0 */   sb        $zero, %lo(D_80109A3E)($v1)
  .L801049CC:
    /* 21CC 801049CC 1180103C */  lui        $s0, %hi(D_80109A3E)
    /* 21D0 801049D0 3E9A0392 */  lbu        $v1, %lo(D_80109A3E)($s0)
    /* 21D4 801049D4 01001124 */  addiu      $s1, $zero, 0x1
    /* 21D8 801049D8 21007110 */  beq        $v1, $s1, .L80104A60
    /* 21DC 801049DC 02006228 */   slti      $v0, $v1, 0x2
    /* 21E0 801049E0 05004010 */  beqz       $v0, .L801049F8
    /* 21E4 801049E4 02000224 */   addiu     $v0, $zero, 0x2
    /* 21E8 801049E8 09006010 */  beqz       $v1, .L80104A10
    /* 21EC 801049EC 21100000 */   addu      $v0, $zero, $zero
    /* 21F0 801049F0 F0120408 */  j          .L80104BC0
    /* 21F4 801049F4 00000000 */   nop
  .L801049F8:
    /* 21F8 801049F8 35006210 */  beq        $v1, $v0, .L80104AD0
    /* 21FC 801049FC 03000224 */   addiu     $v0, $zero, 0x3
    /* 2200 80104A00 6A006210 */  beq        $v1, $v0, .L80104BAC
    /* 2204 80104A04 21100000 */   addu      $v0, $zero, $zero
    /* 2208 80104A08 F0120408 */  j          .L80104BC0
    /* 220C 80104A0C 00000000 */   nop
  .L80104A10:
    /* 2210 80104A10 74EA030C */  jal        vs_mainmenu_ready
    /* 2214 80104A14 00000000 */   nop
    /* 2218 80104A18 68004010 */  beqz       $v0, .L80104BBC
    /* 221C 80104A1C 1180023C */   lui       $v0, %hi(D_80109A40)
    /* 2220 80104A20 409A4490 */  lbu        $a0, %lo(D_80109A40)($v0)
    /* 2224 80104A24 0D10040C */  jal        func_80104034
    /* 2228 80104A28 07000524 */   addiu     $a1, $zero, 0x7
    /* 222C 80104A2C 1180033C */  lui        $v1, %hi(vs_menuD_containerData)
    /* 2230 80104A30 1180023C */  lui        $v0, %hi(D_80109A41)
    /* 2234 80104A34 419A4290 */  lbu        $v0, %lo(D_80109A41)($v0)
    /* 2238 80104A38 8C9A638C */  lw         $v1, %lo(vs_menuD_containerData)($v1)
    /* 223C 80104A3C 40100200 */  sll        $v0, $v0, 1
    /* 2240 80104A40 21186200 */  addu       $v1, $v1, $v0
    /* 2244 80104A44 403D6494 */  lhu        $a0, 0x3D40($v1)
    /* 2248 80104A48 68F5030C */  jal        vs_mainMenu_setShieldStats
    /* 224C 80104A4C 00000000 */   nop
    /* 2250 80104A50 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 2254 80104A54 03000424 */   addiu     $a0, $zero, 0x3
    /* 2258 80104A58 EF120408 */  j          .L80104BBC
    /* 225C 80104A5C 3E9A11A2 */   sb        $s1, %lo(D_80109A3E)($s0)
  .L80104A60:
    /* 2260 80104A60 1180043C */  lui        $a0, %hi(D_80109A3F)
    /* 2264 80104A64 3F9A8390 */  lbu        $v1, %lo(D_80109A3F)($a0)
    /* 2268 80104A68 00000000 */  nop
    /* 226C 80104A6C 0A00622C */  sltiu      $v0, $v1, 0xA
    /* 2270 80104A70 11004010 */  beqz       $v0, .L80104AB8
    /* 2274 80104A74 01006224 */   addiu     $v0, $v1, 0x1
    /* 2278 80104A78 3F9A82A0 */  sb         $v0, %lo(D_80109A3F)($a0)
    /* 227C 80104A7C FF004230 */  andi       $v0, $v0, 0xFF
    /* 2280 80104A80 0400422C */  sltiu      $v0, $v0, 0x4
    /* 2284 80104A84 4D004010 */  beqz       $v0, .L80104BBC
    /* 2288 80104A88 1180033C */   lui       $v1, %hi(vs_menuD_containerData)
    /* 228C 80104A8C 1180023C */  lui        $v0, %hi(D_80109A41)
    /* 2290 80104A90 3F9A8490 */  lbu        $a0, %lo(D_80109A3F)($a0)
    /* 2294 80104A94 419A4290 */  lbu        $v0, %lo(D_80109A41)($v0)
    /* 2298 80104A98 8C9A638C */  lw         $v1, %lo(vs_menuD_containerData)($v1)
    /* 229C 80104A9C 40100200 */  sll        $v0, $v0, 1
    /* 22A0 80104AA0 21186200 */  addu       $v1, $v1, $v0
    /* 22A4 80104AA4 403D6594 */  lhu        $a1, 0x3D40($v1)
    /* 22A8 80104AA8 C1F1030C */  jal        vs_mainMenu_initSetShieldGemMenu
    /* 22AC 80104AAC 01000624 */   addiu     $a2, $zero, 0x1
    /* 22B0 80104AB0 F0120408 */  j          .L80104BC0
    /* 22B4 80104AB4 21100000 */   addu      $v0, $zero, $zero
  .L80104AB8:
    /* 22B8 80104AB8 74EA030C */  jal        vs_mainmenu_ready
    /* 22BC 80104ABC 00000000 */   nop
    /* 22C0 80104AC0 3E004010 */  beqz       $v0, .L80104BBC
    /* 22C4 80104AC4 02000224 */   addiu     $v0, $zero, 0x2
    /* 22C8 80104AC8 EF120408 */  j          .L80104BBC
    /* 22CC 80104ACC 3E9A02A2 */   sb        $v0, %lo(D_80109A3E)($s0)
  .L80104AD0:
    /* 22D0 80104AD0 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 22D4 80104AD4 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 22D8 80104AD8 00000000 */  nop
    /* 22DC 80104ADC 50004230 */  andi       $v0, $v0, 0x50
    /* 22E0 80104AE0 06004010 */  beqz       $v0, .L80104AFC
    /* 22E4 80104AE4 00000000 */   nop
    /* 22E8 80104AE8 5C10040C */  jal        func_80104170
    /* 22EC 80104AEC 01000424 */   addiu     $a0, $zero, 0x1
    /* 22F0 80104AF0 03000224 */  addiu      $v0, $zero, 0x3
    /* 22F4 80104AF4 EF120408 */  j          .L80104BBC
    /* 22F8 80104AF8 3E9A02A2 */   sb        $v0, %lo(D_80109A3E)($s0)
  .L80104AFC:
    /* 22FC 80104AFC 1180103C */  lui        $s0, %hi(D_80109A41)
    /* 2300 80104B00 419A0592 */  lbu        $a1, %lo(D_80109A41)($s0)
    /* 2304 80104B04 5B0F040C */  jal        _pollItemNavigation
    /* 2308 80104B08 03000424 */   addiu     $a0, $zero, 0x3
    /* 230C 80104B0C 419A0392 */  lbu        $v1, %lo(D_80109A41)($s0)
    /* 2310 80104B10 21884000 */  addu       $s1, $v0, $zero
    /* 2314 80104B14 29002312 */  beq        $s1, $v1, .L80104BBC
    /* 2318 80104B18 03000424 */   addiu     $a0, $zero, 0x3
    /* 231C 80104B1C 21282002 */  addu       $a1, $s1, $zero
    /* 2320 80104B20 4510040C */  jal        func_80104114
    /* 2324 80104B24 419A11A2 */   sb        $s1, %lo(D_80109A41)($s0)
    /* 2328 80104B28 21804000 */  addu       $s0, $v0, $zero
    /* 232C 80104B2C 1800A527 */  addiu      $a1, $sp, 0x18
    /* 2330 80104B30 2000A627 */  addiu      $a2, $sp, 0x20
    /* 2334 80104B34 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 2338 80104B38 21904000 */  addu       $s2, $v0, $zero
    /* 233C 80104B3C 40981100 */  sll        $s3, $s1, 1
    /* 2340 80104B40 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 2344 80104B44 8C9A448E */  lw         $a0, %lo(vs_menuD_containerData)($s2)
    /* 2348 80104B48 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 234C 80104B4C FFFF0226 */  addiu      $v0, $s0, -0x1
    /* 2350 80104B50 9710040C */  jal        _setShieldUi
    /* 2354 80104B54 1000A2AF */   sw        $v0, 0x10($sp)
    /* 2358 80104B58 68F5030C */  jal        vs_mainMenu_setShieldStats
    /* 235C 80104B5C 21200002 */   addu      $a0, $s0, $zero
    /* 2360 80104B60 1800A527 */  addiu      $a1, $sp, 0x18
    /* 2364 80104B64 21382002 */  addu       $a3, $s1, $zero
    /* 2368 80104B68 1180023C */  lui        $v0, %hi(D_80109A40)
    /* 236C 80104B6C 409A4490 */  lbu        $a0, %lo(D_80109A40)($v0)
    /* 2370 80104B70 2000A68F */  lw         $a2, 0x20($sp)
    /* 2374 80104B74 1E10040C */  jal        func_80104078
    /* 2378 80104B78 01001024 */   addiu     $s0, $zero, 0x1
    /* 237C 80104B7C 21200002 */  addu       $a0, $s0, $zero
  .L80104B80:
    /* 2380 80104B80 8C9A428E */  lw         $v0, %lo(vs_menuD_containerData)($s2)
    /* 2384 80104B84 21300000 */  addu       $a2, $zero, $zero
    /* 2388 80104B88 21105300 */  addu       $v0, $v0, $s3
    /* 238C 80104B8C 403D4594 */  lhu        $a1, 0x3D40($v0)
    /* 2390 80104B90 C1F1030C */  jal        vs_mainMenu_initSetShieldGemMenu
    /* 2394 80104B94 01001026 */   addiu     $s0, $s0, 0x1
    /* 2398 80104B98 0400022A */  slti       $v0, $s0, 0x4
    /* 239C 80104B9C F8FF4014 */  bnez       $v0, .L80104B80
    /* 23A0 80104BA0 21200002 */   addu      $a0, $s0, $zero
    /* 23A4 80104BA4 F0120408 */  j          .L80104BC0
    /* 23A8 80104BA8 21100000 */   addu      $v0, $zero, $zero
  .L80104BAC:
    /* 23AC 80104BAC 74EA030C */  jal        vs_mainmenu_ready
    /* 23B0 80104BB0 00000000 */   nop
    /* 23B4 80104BB4 F0120408 */  j          .L80104BC0
    /* 23B8 80104BB8 00000000 */   nop
  .L80104BBC:
    /* 23BC 80104BBC 21100000 */  addu       $v0, $zero, $zero
  .L80104BC0:
    /* 23C0 80104BC0 3800BF8F */  lw         $ra, 0x38($sp)
    /* 23C4 80104BC4 3400B38F */  lw         $s3, 0x34($sp)
    /* 23C8 80104BC8 3000B28F */  lw         $s2, 0x30($sp)
    /* 23CC 80104BCC 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 23D0 80104BD0 2800B08F */  lw         $s0, 0x28($sp)
    /* 23D4 80104BD4 0800E003 */  jr         $ra
    /* 23D8 80104BD8 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel _shieldNavigation
