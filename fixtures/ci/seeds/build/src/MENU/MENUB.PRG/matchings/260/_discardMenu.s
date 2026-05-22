nonmatching _discardMenu, 0x738

glabel _discardMenu
    /* 2060 80104860 A0FFBD27 */  addiu      $sp, $sp, -0x60
    /* 2064 80104864 21288000 */  addu       $a1, $a0, $zero
    /* 2068 80104868 5800BFAF */  sw         $ra, 0x58($sp)
    /* 206C 8010486C 5400B3AF */  sw         $s3, 0x54($sp)
    /* 2070 80104870 5000B2AF */  sw         $s2, 0x50($sp)
    /* 2074 80104874 4C00B1AF */  sw         $s1, 0x4C($sp)
    /* 2078 80104878 1900A010 */  beqz       $a1, .L801048E0
    /* 207C 8010487C 4800B0AF */   sw        $s0, 0x48($sp)
    /* 2080 80104880 01000424 */  addiu      $a0, $zero, 0x1
    /* 2084 80104884 1180103C */  lui        $s0, %hi(D_8010A60D)
    /* 2088 80104888 03140500 */  sra        $v0, $a1, 16
    /* 208C 8010488C 1180033C */  lui        $v1, %hi(D_8010A60B)
    /* 2090 80104890 0DA602A2 */  sb         $v0, %lo(D_8010A60D)($s0)
    /* 2094 80104894 03120500 */  sra        $v0, $a1, 8
    /* 2098 80104898 0BA662A0 */  sb         $v0, %lo(D_8010A60B)($v1)
    /* 209C 8010489C 1180023C */  lui        $v0, %hi(D_8010A60C)
    /* 20A0 801048A0 8123030C */  jal        func_800C8E04
    /* 20A4 801048A4 0CA645A0 */   sb        $a1, %lo(D_8010A60C)($v0)
    /* 20A8 801048A8 1080033C */  lui        $v1, %hi(vs_mainMenu_itemHelp)
    /* 20AC 801048AC 0DA60292 */  lbu        $v0, %lo(D_8010A60D)($s0)
    /* 20B0 801048B0 4025638C */  lw         $v1, %lo(vs_mainMenu_itemHelp)($v1)
    /* 20B4 801048B4 40100200 */  sll        $v0, $v0, 1
    /* 20B8 801048B8 21104300 */  addu       $v0, $v0, $v1
    /* 20BC 801048BC 54044494 */  lhu        $a0, 0x454($v0)
    /* 20C0 801048C0 00000000 */  nop
    /* 20C4 801048C4 40200400 */  sll        $a0, $a0, 1
    /* 20C8 801048C8 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 20CC 801048CC 21206400 */   addu      $a0, $v1, $a0
    /* 20D0 801048D0 21100000 */  addu       $v0, $zero, $zero
    /* 20D4 801048D4 1180033C */  lui        $v1, %hi(D_8010A60A)
    /* 20D8 801048D8 DF130408 */  j          .L80104F7C
    /* 20DC 801048DC 0AA660A0 */   sb        $zero, %lo(D_8010A60A)($v1)
  .L801048E0:
    /* 20E0 801048E0 1180023C */  lui        $v0, %hi(D_8010A60A)
    /* 20E4 801048E4 0AA64390 */  lbu        $v1, %lo(D_8010A60A)($v0)
    /* 20E8 801048E8 00000000 */  nop
    /* 20EC 801048EC 0800622C */  sltiu      $v0, $v1, 0x8
    /* 20F0 801048F0 A1014010 */  beqz       $v0, .L80104F78
    /* 20F4 801048F4 1080023C */   lui       $v0, %hi(jtbl_80102890)
    /* 20F8 801048F8 90284224 */  addiu      $v0, $v0, %lo(jtbl_80102890)
    /* 20FC 801048FC 80180300 */  sll        $v1, $v1, 2
    /* 2100 80104900 21186200 */  addu       $v1, $v1, $v0
    /* 2104 80104904 0000628C */  lw         $v0, 0x0($v1)
    /* 2108 80104908 00000000 */  nop
    /* 210C 8010490C 08004000 */  jr         $v0
    /* 2110 80104910 00000000 */   nop
    /* 2114 80104914 0F80023C */  lui        $v0, %hi(D_800F5130)
    /* 2118 80104918 3051428C */  lw         $v0, %lo(D_800F5130)($v0)
    /* 211C 8010491C 00000000 */  nop
    /* 2120 80104920 82170200 */  srl        $v0, $v0, 30
    /* 2124 80104924 01004230 */  andi       $v0, $v0, 0x1
    /* 2128 80104928 94014010 */  beqz       $v0, .L80104F7C
    /* 212C 8010492C 21100000 */   addu      $v0, $zero, $zero
    /* 2130 80104930 74EA030C */  jal        vs_mainmenu_ready
    /* 2134 80104934 00000000 */   nop
    /* 2138 80104938 8F014010 */  beqz       $v0, .L80104F78
    /* 213C 8010493C 1180023C */   lui       $v0, %hi(D_8010A60D)
    /* 2140 80104940 0DA64290 */  lbu        $v0, %lo(D_8010A60D)($v0)
    /* 2144 80104944 1180033C */  lui        $v1, %hi(D_8010A60A)
    /* 2148 80104948 01004230 */  andi       $v0, $v0, 0x1
    /* 214C 8010494C 01004224 */  addiu      $v0, $v0, 0x1
    /* 2150 80104950 DE130408 */  j          .L80104F78
    /* 2154 80104954 0AA662A0 */   sb        $v0, %lo(D_8010A60A)($v1)
    /* 2158 80104958 21880000 */  addu       $s1, $zero, $zero
    /* 215C 8010495C 2800A827 */  addiu      $t0, $sp, 0x28
    /* 2160 80104960 04000724 */  addiu      $a3, $zero, 0x4
    /* 2164 80104964 1800A927 */  addiu      $t1, $sp, 0x18
    /* 2168 80104968 21302001 */  addu       $a2, $t1, $zero
    /* 216C 8010496C 1080033C */  lui        $v1, %hi(vs_mainMenu_itemHelp)
    /* 2170 80104970 1180023C */  lui        $v0, %hi(D_8010A60D)
    /* 2174 80104974 0DA64290 */  lbu        $v0, %lo(D_8010A60D)($v0)
    /* 2178 80104978 4025658C */  lw         $a1, %lo(vs_mainMenu_itemHelp)($v1)
    /* 217C 8010497C 40100200 */  sll        $v0, $v0, 1
    /* 2180 80104980 21504500 */  addu       $t2, $v0, $a1
    /* 2184 80104984 2120A000 */  addu       $a0, $a1, $zero
  .L80104988:
    /* 2188 80104988 21182701 */  addu       $v1, $t1, $a3
    /* 218C 8010498C 0800E724 */  addiu      $a3, $a3, 0x8
    /* 2190 80104990 50048294 */  lhu        $v0, 0x450($a0)
    /* 2194 80104994 02008424 */  addiu      $a0, $a0, 0x2
    /* 2198 80104998 01003126 */  addiu      $s1, $s1, 0x1
    /* 219C 8010499C 40100200 */  sll        $v0, $v0, 1
    /* 21A0 801049A0 2110A200 */  addu       $v0, $a1, $v0
    /* 21A4 801049A4 0000C2AC */  sw         $v0, 0x0($a2)
    /* 21A8 801049A8 54044295 */  lhu        $v0, 0x454($t2)
    /* 21AC 801049AC 0800C624 */  addiu      $a2, $a2, 0x8
    /* 21B0 801049B0 40100200 */  sll        $v0, $v0, 1
    /* 21B4 801049B4 2110A200 */  addu       $v0, $a1, $v0
    /* 21B8 801049B8 000062AC */  sw         $v0, 0x0($v1)
    /* 21BC 801049BC 000000AD */  sw         $zero, 0x0($t0)
    /* 21C0 801049C0 0200222A */  slti       $v0, $s1, 0x2
    /* 21C4 801049C4 F0FF4014 */  bnez       $v0, .L80104988
    /* 21C8 801049C8 04000825 */   addiu     $t0, $t0, 0x4
    /* 21CC 801049CC 02000424 */  addiu      $a0, $zero, 0x2
    /* 21D0 801049D0 04000524 */  addiu      $a1, $zero, 0x4
    /* 21D4 801049D4 1800A627 */  addiu      $a2, $sp, 0x18
    /* 21D8 801049D8 3BFC030C */  jal        vs_mainMenu_initSortUi
    /* 21DC 801049DC 2800A727 */   addiu     $a3, $sp, 0x28
    /* 21E0 801049E0 1180033C */  lui        $v1, %hi(D_8010A60A)
    /* 21E4 801049E4 03000224 */  addiu      $v0, $zero, 0x3
    /* 21E8 801049E8 DE130408 */  j          .L80104F78
    /* 21EC 801049EC 0AA662A0 */   sb        $v0, %lo(D_8010A60A)($v1)
    /* 21F0 801049F0 0680033C */  lui        $v1, %hi(vs_battle_inventory)
    /* 21F4 801049F4 1180023C */  lui        $v0, %hi(D_8010A60C)
    /* 21F8 801049F8 0CA64290 */  lbu        $v0, %lo(D_8010A60C)($v0)
    /* 21FC 801049FC 68016324 */  addiu      $v1, $v1, %lo(vs_battle_inventory)
    /* 2200 80104A00 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 2204 80104A04 80100200 */  sll        $v0, $v0, 2
    /* 2208 80104A08 21104300 */  addu       $v0, $v0, $v1
    /* 220C 80104A0C 020E4390 */  lbu        $v1, 0xE02($v0)
    /* 2210 80104A10 1180023C */  lui        $v0, %hi(D_8010A610)
    /* 2214 80104A14 10A643A0 */  sb         $v1, %lo(D_8010A610)($v0)
    /* 2218 80104A18 1533030C */  jal        vs_battle_toBCD
    /* 221C 80104A1C FF006430 */   andi      $a0, $v1, 0xFF
    /* 2220 80104A20 21884000 */  addu       $s1, $v0, $zero
    /* 2224 80104A24 03211100 */  sra        $a0, $s1, 4
    /* 2228 80104A28 1180103C */  lui        $s0, %hi(D_8010A5B4)
    /* 222C 80104A2C B4A51026 */  addiu      $s0, $s0, %lo(D_8010A5B4)
    /* 2230 80104A30 0F002232 */  andi       $v0, $s1, 0xF
    /* 2234 80104A34 1533030C */  jal        vs_battle_toBCD
    /* 2238 80104A38 080002A2 */   sb        $v0, 0x8($s0)
    /* 223C 80104A3C 21884000 */  addu       $s1, $v0, $zero
    /* 2240 80104A40 0F002232 */  andi       $v0, $s1, 0xF
    /* 2244 80104A44 03191100 */  sra        $v1, $s1, 4
    /* 2248 80104A48 02001124 */  addiu      $s1, $zero, 0x2
    /* 224C 80104A4C 070002A2 */  sb         $v0, 0x7($s0)
    /* 2250 80104A50 060003A2 */  sb         $v1, 0x6($s0)
    /* 2254 80104A54 21103002 */  addu       $v0, $s1, $s0
  .L80104A58:
    /* 2258 80104A58 000040A0 */  sb         $zero, 0x0($v0)
    /* 225C 80104A5C 01003126 */  addiu      $s1, $s1, 0x1
    /* 2260 80104A60 0500222A */  slti       $v0, $s1, 0x5
    /* 2264 80104A64 FCFF4014 */  bnez       $v0, .L80104A58
    /* 2268 80104A68 21103002 */   addu      $v0, $s1, $s0
    /* 226C 80104A6C 22000424 */  addiu      $a0, $zero, 0x22
    /* 2270 80104A70 82FF0524 */  addiu      $a1, $zero, -0x7E
    /* 2274 80104A74 82000624 */  addiu      $a2, $zero, 0x82
    /* 2278 80104A78 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 227C 80104A7C 1180023C */  lui        $v0, %hi(D_8010A5B4)
    /* 2280 80104A80 B4A54224 */  addiu      $v0, $v0, %lo(D_8010A5B4)
    /* 2284 80104A84 1000A0AF */  sw         $zero, 0x10($sp)
    /* 2288 80104A88 9723030C */  jal        vs_battle_setMenuItem
    /* 228C 80104A8C 1400A2AF */   sw        $v0, 0x14($sp)
    /* 2290 80104A90 05000324 */  addiu      $v1, $zero, 0x5
    /* 2294 80104A94 000043A0 */  sb         $v1, 0x0($v0)
    /* 2298 80104A98 180040A4 */  sh         $zero, 0x18($v0)
    /* 229C 80104A9C 1180023C */  lui        $v0, %hi(D_8010A60E)
    /* 22A0 80104AA0 0EA640A0 */  sb         $zero, %lo(D_8010A60E)($v0)
    /* 22A4 80104AA4 1180023C */  lui        $v0, %hi(D_8010A60F)
    /* 22A8 80104AA8 1180033C */  lui        $v1, %hi(D_8010A60A)
    /* 22AC 80104AAC 0FA640A0 */  sb         $zero, %lo(D_8010A60F)($v0)
    /* 22B0 80104AB0 04000224 */  addiu      $v0, $zero, 0x4
    /* 22B4 80104AB4 DE130408 */  j          .L80104F78
    /* 22B8 80104AB8 0AA662A0 */   sb        $v0, %lo(D_8010A60A)($v1)
    /* 22BC 80104ABC 0FFD030C */  jal        vs_mainMenu_processItemActionMenu
    /* 22C0 80104AC0 00000000 */   nop
    /* 22C4 80104AC4 D8FC030C */  jal        vs_mainMenu_getSelectedItemAction
    /* 22C8 80104AC8 00000000 */   nop
    /* 22CC 80104ACC 01005124 */  addiu      $s1, $v0, 0x1
    /* 22D0 80104AD0 29012012 */  beqz       $s1, .L80104F78
    /* 22D4 80104AD4 01000224 */   addiu     $v0, $zero, 0x1
    /* 22D8 80104AD8 23012216 */  bne        $s1, $v0, .L80104F68
    /* 22DC 80104ADC 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 22E0 80104AE0 6216010C */  jal        vs_main_playSfxDefault
    /* 22E4 80104AE4 1C000524 */   addiu     $a1, $zero, 0x1C
    /* 22E8 80104AE8 1180023C */  lui        $v0, %hi(D_8010A60B)
    /* 22EC 80104AEC 0BA64490 */  lbu        $a0, %lo(D_8010A60B)($v0)
    /* 22F0 80104AF0 1180023C */  lui        $v0, %hi(D_8010A60C)
    /* 22F4 80104AF4 0CA64590 */  lbu        $a1, %lo(D_8010A60C)($v0)
    /* 22F8 80104AF8 F8F8030C */  jal        vs_mainMenu_initItem
    /* 22FC 80104AFC 00000000 */   nop
    /* 2300 80104B00 DF130408 */  j          .L80104F7C
    /* 2304 80104B04 21102002 */   addu      $v0, $s1, $zero
    /* 2308 80104B08 74EA030C */  jal        vs_mainmenu_ready
    /* 230C 80104B0C 00000000 */   nop
    /* 2310 80104B10 19014010 */  beqz       $v0, .L80104F78
    /* 2314 80104B14 02001124 */   addiu     $s1, $zero, 0x2
    /* 2318 80104B18 1180023C */  lui        $v0, %hi(D_8010A5B4)
    /* 231C 80104B1C B4A54424 */  addiu      $a0, $v0, %lo(D_8010A5B4)
    /* 2320 80104B20 8F000324 */  addiu      $v1, $zero, 0x8F
    /* 2324 80104B24 21102402 */  addu       $v0, $s1, $a0
  .L80104B28:
    /* 2328 80104B28 000043A0 */  sb         $v1, 0x0($v0)
    /* 232C 80104B2C 01003126 */  addiu      $s1, $s1, 0x1
    /* 2330 80104B30 0500222A */  slti       $v0, $s1, 0x5
    /* 2334 80104B34 FCFF4014 */  bnez       $v0, .L80104B28
    /* 2338 80104B38 21102402 */   addu      $v0, $s1, $a0
    /* 233C 80104B3C 22000424 */  addiu      $a0, $zero, 0x22
    /* 2340 80104B40 21280000 */  addu       $a1, $zero, $zero
    /* 2344 80104B44 82000624 */  addiu      $a2, $zero, 0x82
    /* 2348 80104B48 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 234C 80104B4C 1180023C */  lui        $v0, %hi(D_8010A5B4)
    /* 2350 80104B50 B4A54224 */  addiu      $v0, $v0, %lo(D_8010A5B4)
    /* 2354 80104B54 1000A0AF */  sw         $zero, 0x10($sp)
    /* 2358 80104B58 9723030C */  jal        vs_battle_setMenuItem
    /* 235C 80104B5C 1400A2AF */   sw        $v0, 0x14($sp)
    /* 2360 80104B60 1180033C */  lui        $v1, %hi(D_8010A60A)
    /* 2364 80104B64 05000224 */  addiu      $v0, $zero, 0x5
    /* 2368 80104B68 0AA662A0 */  sb         $v0, %lo(D_8010A60A)($v1)
    /* 236C 80104B6C 0680123C */  lui        $s2, %hi(vs_main_buttonsPressed)
    /* 2370 80104B70 D0E1428E */  lw         $v0, %lo(vs_main_buttonsPressed)($s2)
    /* 2374 80104B74 00000000 */  nop
    /* 2378 80104B78 70004230 */  andi       $v0, $v0, 0x70
    /* 237C 80104B7C 32004010 */  beqz       $v0, .L80104C48
    /* 2380 80104B80 1180133C */   lui       $s3, %hi(D_8010A60F)
    /* 2384 80104B84 0FA66492 */  lbu        $a0, %lo(D_8010A60F)($s3)
    /* 2388 80104B88 1533030C */  jal        vs_battle_toBCD
    /* 238C 80104B8C 1180103C */   lui       $s0, %hi(D_8010A5B4)
    /* 2390 80104B90 21884000 */  addu       $s1, $v0, $zero
    /* 2394 80104B94 03211100 */  sra        $a0, $s1, 4
    /* 2398 80104B98 B4A51026 */  addiu      $s0, $s0, %lo(D_8010A5B4)
    /* 239C 80104B9C 0F002232 */  andi       $v0, $s1, 0xF
    /* 23A0 80104BA0 1533030C */  jal        vs_battle_toBCD
    /* 23A4 80104BA4 040002A2 */   sb        $v0, 0x4($s0)
    /* 23A8 80104BA8 21884000 */  addu       $s1, $v0, $zero
    /* 23AC 80104BAC 22000424 */  addiu      $a0, $zero, 0x22
    /* 23B0 80104BB0 21280000 */  addu       $a1, $zero, $zero
    /* 23B4 80104BB4 82000624 */  addiu      $a2, $zero, 0x82
    /* 23B8 80104BB8 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 23BC 80104BBC 0F002232 */  andi       $v0, $s1, 0xF
    /* 23C0 80104BC0 030002A2 */  sb         $v0, 0x3($s0)
    /* 23C4 80104BC4 03111100 */  sra        $v0, $s1, 4
    /* 23C8 80104BC8 020002A2 */  sb         $v0, 0x2($s0)
    /* 23CC 80104BCC 1000A0AF */  sw         $zero, 0x10($sp)
    /* 23D0 80104BD0 9723030C */  jal        vs_battle_setMenuItem
    /* 23D4 80104BD4 1400B0AF */   sw        $s0, 0x14($sp)
    /* 23D8 80104BD8 D0E1428E */  lw         $v0, %lo(vs_main_buttonsPressed)($s2)
    /* 23DC 80104BDC 00000000 */  nop
    /* 23E0 80104BE0 50004230 */  andi       $v0, $v0, 0x50
    /* 23E4 80104BE4 0A004010 */  beqz       $v0, .L80104C10
    /* 23E8 80104BE8 00000000 */   nop
    /* 23EC 80104BEC BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 23F0 80104BF0 00000000 */   nop
    /* 23F4 80104BF4 D0E1438E */  lw         $v1, %lo(vs_main_buttonsPressed)($s2)
    /* 23F8 80104BF8 00000000 */  nop
    /* 23FC 80104BFC 10006330 */  andi       $v1, $v1, 0x10
    /* 2400 80104C00 DE006014 */  bnez       $v1, .L80104F7C
    /* 2404 80104C04 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 2408 80104C08 DF130408 */  j          .L80104F7C
    /* 240C 80104C0C FFFF0224 */   addiu     $v0, $zero, -0x1
  .L80104C10:
    /* 2410 80104C10 0FA66292 */  lbu        $v0, %lo(D_8010A60F)($s3)
    /* 2414 80104C14 00000000 */  nop
    /* 2418 80104C18 05004014 */  bnez       $v0, .L80104C30
    /* 241C 80104C1C 00000000 */   nop
    /* 2420 80104C20 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 2424 80104C24 00000000 */   nop
    /* 2428 80104C28 DF130408 */  j          .L80104F7C
    /* 242C 80104C2C FFFF0224 */   addiu     $v0, $zero, -0x1
  .L80104C30:
    /* 2430 80104C30 BC00030C */  jal        vs_battle_playMenuSelectSfx
    /* 2434 80104C34 00000000 */   nop
    /* 2438 80104C38 1180033C */  lui        $v1, %hi(D_8010A60A)
    /* 243C 80104C3C 06000224 */  addiu      $v0, $zero, 0x6
    /* 2440 80104C40 DE130408 */  j          .L80104F78
    /* 2444 80104C44 0AA662A0 */   sb        $v0, %lo(D_8010A60A)($v1)
  .L80104C48:
    /* 2448 80104C48 1180023C */  lui        $v0, %hi(D_8010A60F)
    /* 244C 80104C4C 0680033C */  lui        $v1, %hi(vs_main_buttonRepeat)
    /* 2450 80104C50 0FA64690 */  lbu        $a2, %lo(D_8010A60F)($v0)
    /* 2454 80104C54 DCDF628C */  lw         $v0, %lo(vs_main_buttonRepeat)($v1)
    /* 2458 80104C58 2120C000 */  addu       $a0, $a2, $zero
    /* 245C 80104C5C 00104330 */  andi       $v1, $v0, 0x1000
    /* 2460 80104C60 00404230 */  andi       $v0, $v0, 0x4000
    /* 2464 80104C64 02004010 */  beqz       $v0, .L80104C70
    /* 2468 80104C68 2B880300 */   sltu      $s1, $zero, $v1
    /* 246C 80104C6C FFFF3126 */  addiu      $s1, $s1, -0x1
  .L80104C70:
    /* 2470 80104C70 01000224 */  addiu      $v0, $zero, 0x1
    /* 2474 80104C74 09002216 */  bne        $s1, $v0, .L80104C9C
    /* 2478 80104C78 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 247C 80104C7C 1180033C */  lui        $v1, %hi(D_8010A5C0)
    /* 2480 80104C80 1180023C */  lui        $v0, %hi(D_8010A60E)
    /* 2484 80104C84 0EA64290 */  lbu        $v0, %lo(D_8010A60E)($v0)
    /* 2488 80104C88 C0A56324 */  addiu      $v1, $v1, %lo(D_8010A5C0)
    /* 248C 80104C8C 21104300 */  addu       $v0, $v0, $v1
    /* 2490 80104C90 00004290 */  lbu        $v0, 0x0($v0)
    /* 2494 80104C94 30130408 */  j          .L80104CC0
    /* 2498 80104C98 2120C200 */   addu      $a0, $a2, $v0
  .L80104C9C:
    /* 249C 80104C9C 08002216 */  bne        $s1, $v0, .L80104CC0
    /* 24A0 80104CA0 1180033C */   lui       $v1, %hi(D_8010A5C0)
    /* 24A4 80104CA4 1180023C */  lui        $v0, %hi(D_8010A60E)
    /* 24A8 80104CA8 0EA64290 */  lbu        $v0, %lo(D_8010A60E)($v0)
    /* 24AC 80104CAC C0A56324 */  addiu      $v1, $v1, %lo(D_8010A5C0)
    /* 24B0 80104CB0 21104300 */  addu       $v0, $v0, $v1
    /* 24B4 80104CB4 00004290 */  lbu        $v0, 0x0($v0)
    /* 24B8 80104CB8 00000000 */  nop
    /* 24BC 80104CBC 2320C200 */  subu       $a0, $a2, $v0
  .L80104CC0:
    /* 24C0 80104CC0 08008004 */  bltz       $a0, .L80104CE4
    /* 24C4 80104CC4 1180023C */   lui       $v0, %hi(D_8010A610)
    /* 24C8 80104CC8 10A64290 */  lbu        $v0, %lo(D_8010A610)($v0)
    /* 24CC 80104CCC 00000000 */  nop
    /* 24D0 80104CD0 2A104400 */  slt        $v0, $v0, $a0
    /* 24D4 80104CD4 04004014 */  bnez       $v0, .L80104CE8
    /* 24D8 80104CD8 1180053C */   lui       $a1, %hi(D_8010A60E)
    /* 24DC 80104CDC 1180023C */  lui        $v0, %hi(D_8010A60F)
    /* 24E0 80104CE0 0FA644A0 */  sb         $a0, %lo(D_8010A60F)($v0)
  .L80104CE4:
    /* 24E4 80104CE4 1180053C */  lui        $a1, %hi(D_8010A60E)
  .L80104CE8:
    /* 24E8 80104CE8 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 24EC 80104CEC DCDF438C */  lw         $v1, %lo(vs_main_buttonRepeat)($v0)
    /* 24F0 80104CF0 0EA6A490 */  lbu        $a0, %lo(D_8010A60E)($a1)
    /* 24F4 80104CF4 00206230 */  andi       $v0, $v1, 0x2000
    /* 24F8 80104CF8 02004010 */  beqz       $v0, .L80104D04
    /* 24FC 80104CFC 21880000 */   addu      $s1, $zero, $zero
    /* 2500 80104D00 FFFF1124 */  addiu      $s1, $zero, -0x1
  .L80104D04:
    /* 2504 80104D04 00806230 */  andi       $v0, $v1, 0x8000
    /* 2508 80104D08 02004010 */  beqz       $v0, .L80104D14
    /* 250C 80104D0C 01000224 */   addiu     $v0, $zero, 0x1
    /* 2510 80104D10 01003126 */  addiu      $s1, $s1, 0x1
  .L80104D14:
    /* 2514 80104D14 0E002216 */  bne        $s1, $v0, .L80104D50
    /* 2518 80104D18 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 251C 80104D1C FF008330 */  andi       $v1, $a0, 0xFF
    /* 2520 80104D20 02000224 */  addiu      $v0, $zero, 0x2
    /* 2524 80104D24 16006214 */  bne        $v1, $v0, .L80104D80
    /* 2528 80104D28 01008224 */   addiu     $v0, $a0, 0x1
    /* 252C 80104D2C 1180053C */  lui        $a1, %hi(D_8010A60F)
    /* 2530 80104D30 1180023C */  lui        $v0, %hi(D_8010A610)
    /* 2534 80104D34 10A64390 */  lbu        $v1, %lo(D_8010A610)($v0)
    /* 2538 80104D38 0FA6A290 */  lbu        $v0, %lo(D_8010A60F)($a1)
    /* 253C 80104D3C 00000000 */  nop
    /* 2540 80104D40 11004310 */  beq        $v0, $v1, .L80104D88
    /* 2544 80104D44 1180023C */   lui       $v0, %hi(D_8010A60E)
    /* 2548 80104D48 62130408 */  j          .L80104D88
    /* 254C 80104D4C 0FA6A3A0 */   sb        $v1, %lo(D_8010A60F)($a1)
  .L80104D50:
    /* 2550 80104D50 0D002216 */  bne        $s1, $v0, .L80104D88
    /* 2554 80104D54 1180023C */   lui       $v0, %hi(D_8010A60E)
    /* 2558 80104D58 FF008230 */  andi       $v0, $a0, 0xFF
    /* 255C 80104D5C 08004014 */  bnez       $v0, .L80104D80
    /* 2560 80104D60 FFFF8224 */   addiu     $v0, $a0, -0x1
    /* 2564 80104D64 1180033C */  lui        $v1, %hi(D_8010A60F)
    /* 2568 80104D68 0FA66290 */  lbu        $v0, %lo(D_8010A60F)($v1)
    /* 256C 80104D6C 00000000 */  nop
    /* 2570 80104D70 05004010 */  beqz       $v0, .L80104D88
    /* 2574 80104D74 1180023C */   lui       $v0, %hi(D_8010A60E)
    /* 2578 80104D78 62130408 */  j          .L80104D88
    /* 257C 80104D7C 0FA660A0 */   sb        $zero, %lo(D_8010A60F)($v1)
  .L80104D80:
    /* 2580 80104D80 0EA6A2A0 */  sb         $v0, %lo(D_8010A60E)($a1)
    /* 2584 80104D84 1180023C */  lui        $v0, %hi(D_8010A60E)
  .L80104D88:
    /* 2588 80104D88 0EA64290 */  lbu        $v0, %lo(D_8010A60E)($v0)
    /* 258C 80104D8C 00000000 */  nop
    /* 2590 80104D90 05008214 */  bne        $a0, $v0, .L80104DA8
    /* 2594 80104D94 1180023C */   lui       $v0, %hi(D_8010A60F)
    /* 2598 80104D98 0FA64290 */  lbu        $v0, %lo(D_8010A60F)($v0)
    /* 259C 80104D9C 00000000 */  nop
    /* 25A0 80104DA0 0300C210 */  beq        $a2, $v0, .L80104DB0
    /* 25A4 80104DA4 00000000 */   nop
  .L80104DA8:
    /* 25A8 80104DA8 BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 25AC 80104DAC 00000000 */   nop
  .L80104DB0:
    /* 25B0 80104DB0 841C030C */  jal        func_800C7210
    /* 25B4 80104DB4 05000424 */   addiu     $a0, $zero, 0x5
    /* 25B8 80104DB8 1180023C */  lui        $v0, %hi(D_8010A60F)
    /* 25BC 80104DBC 0FA64490 */  lbu        $a0, %lo(D_8010A60F)($v0)
    /* 25C0 80104DC0 1533030C */  jal        vs_battle_toBCD
    /* 25C4 80104DC4 801F103C */   lui       $s0, %hi(D_1F800000)
    /* 25C8 80104DC8 21884000 */  addu       $s1, $v0, $zero
    /* 25CC 80104DCC 0F002432 */  andi       $a0, $s1, 0xF
    /* 25D0 80104DD0 42000524 */  addiu      $a1, $zero, 0x42
    /* 25D4 80104DD4 00001026 */  addiu      $s0, $s0, %lo(D_1F800000)
    /* 25D8 80104DD8 0800078E */  lw         $a3, 0x8($s0)
    /* 25DC 80104DDC 82000624 */  addiu      $a2, $zero, 0x82
    /* 25E0 80104DE0 3E1C030C */  jal        vs_battle_printVariableWidthFontChar
    /* 25E4 80104DE4 F4FFE724 */   addiu     $a3, $a3, -0xC
    /* 25E8 80104DE8 1533030C */  jal        vs_battle_toBCD
    /* 25EC 80104DEC 03211100 */   sra       $a0, $s1, 4
    /* 25F0 80104DF0 21884000 */  addu       $s1, $v0, $zero
    /* 25F4 80104DF4 0F002432 */  andi       $a0, $s1, 0xF
    /* 25F8 80104DF8 3C000524 */  addiu      $a1, $zero, 0x3C
    /* 25FC 80104DFC 0800078E */  lw         $a3, 0x8($s0)
    /* 2600 80104E00 82000624 */  addiu      $a2, $zero, 0x82
    /* 2604 80104E04 3E1C030C */  jal        vs_battle_printVariableWidthFontChar
    /* 2608 80104E08 F4FFE724 */   addiu     $a3, $a3, -0xC
    /* 260C 80104E0C 03211100 */  sra        $a0, $s1, 4
    /* 2610 80104E10 36000524 */  addiu      $a1, $zero, 0x36
    /* 2614 80104E14 0800078E */  lw         $a3, 0x8($s0)
    /* 2618 80104E18 82000624 */  addiu      $a2, $zero, 0x82
    /* 261C 80104E1C 3E1C030C */  jal        vs_battle_printVariableWidthFontChar
    /* 2620 80104E20 F4FFE724 */   addiu     $a3, $a3, -0xC
    /* 2624 80104E24 1180103C */  lui        $s0, %hi(D_8010A5C3)
    /* 2628 80104E28 1180023C */  lui        $v0, %hi(D_8010A60E)
    /* 262C 80104E2C 36000524 */  addiu      $a1, $zero, 0x36
    /* 2630 80104E30 0EA64390 */  lbu        $v1, %lo(D_8010A60E)($v0)
    /* 2634 80104E34 C3A50492 */  lbu        $a0, %lo(D_8010A5C3)($s0)
    /* 2638 80104E38 40100300 */  sll        $v0, $v1, 1
    /* 263C 80104E3C 21104300 */  addu       $v0, $v0, $v1
    /* 2640 80104E40 40100200 */  sll        $v0, $v0, 1
    /* 2644 80104E44 2328A200 */  subu       $a1, $a1, $v0
    /* 2648 80104E48 7200023C */  lui        $v0, (0x720000 >> 16)
    /* 264C 80104E4C 37FF030C */  jal        func_800FFCDC
    /* 2650 80104E50 2528A200 */   or        $a1, $a1, $v0
    /* 2654 80104E54 DE130408 */  j          .L80104F78
    /* 2658 80104E58 C3A502A2 */   sb        $v0, %lo(D_8010A5C3)($s0)
    /* 265C 80104E5C 74EA030C */  jal        vs_mainmenu_ready
    /* 2660 80104E60 00000000 */   nop
    /* 2664 80104E64 44004010 */  beqz       $v0, .L80104F78
    /* 2668 80104E68 21880000 */   addu      $s1, $zero, $zero
    /* 266C 80104E6C 4000A727 */  addiu      $a3, $sp, 0x40
    /* 2670 80104E70 04000624 */  addiu      $a2, $zero, 0x4
    /* 2674 80104E74 3000A927 */  addiu      $t1, $sp, 0x30
    /* 2678 80104E78 1080023C */  lui        $v0, %hi(vs_mainMenu_itemHelp)
    /* 267C 80104E7C 4025488C */  lw         $t0, %lo(vs_mainMenu_itemHelp)($v0)
    /* 2680 80104E80 21282001 */  addu       $a1, $t1, $zero
    /* 2684 80104E84 925C0A25 */  addiu      $t2, $t0, 0x5C92
    /* 2688 80104E88 21200001 */  addu       $a0, $t0, $zero
  .L80104E8C:
    /* 268C 80104E8C 21182601 */  addu       $v1, $t1, $a2
    /* 2690 80104E90 0800C624 */  addiu      $a2, $a2, 0x8
    /* 2694 80104E94 50048294 */  lhu        $v0, 0x450($a0)
    /* 2698 80104E98 02008424 */  addiu      $a0, $a0, 0x2
    /* 269C 80104E9C 01003126 */  addiu      $s1, $s1, 0x1
    /* 26A0 80104EA0 40100200 */  sll        $v0, $v0, 1
    /* 26A4 80104EA4 21100201 */  addu       $v0, $t0, $v0
    /* 26A8 80104EA8 0000A2AC */  sw         $v0, 0x0($a1)
    /* 26AC 80104EAC 00006AAC */  sw         $t2, 0x0($v1)
    /* 26B0 80104EB0 0000E0AC */  sw         $zero, 0x0($a3)
    /* 26B4 80104EB4 0400E724 */  addiu      $a3, $a3, 0x4
    /* 26B8 80104EB8 0200222A */  slti       $v0, $s1, 0x2
    /* 26BC 80104EBC F3FF4014 */  bnez       $v0, .L80104E8C
    /* 26C0 80104EC0 0800A524 */   addiu     $a1, $a1, 0x8
    /* 26C4 80104EC4 02000424 */  addiu      $a0, $zero, 0x2
    /* 26C8 80104EC8 04000524 */  addiu      $a1, $zero, 0x4
    /* 26CC 80104ECC 3000A627 */  addiu      $a2, $sp, 0x30
    /* 26D0 80104ED0 3BFC030C */  jal        vs_mainMenu_initSortUi
    /* 26D4 80104ED4 4000A727 */   addiu     $a3, $sp, 0x40
    /* 26D8 80104ED8 1180033C */  lui        $v1, %hi(D_8010A60A)
    /* 26DC 80104EDC 07000224 */  addiu      $v0, $zero, 0x7
    /* 26E0 80104EE0 DE130408 */  j          .L80104F78
    /* 26E4 80104EE4 0AA662A0 */   sb        $v0, %lo(D_8010A60A)($v1)
    /* 26E8 80104EE8 0FFD030C */  jal        vs_mainMenu_processItemActionMenu
    /* 26EC 80104EEC 00000000 */   nop
    /* 26F0 80104EF0 D8FC030C */  jal        vs_mainMenu_getSelectedItemAction
    /* 26F4 80104EF4 00000000 */   nop
    /* 26F8 80104EF8 01005124 */  addiu      $s1, $v0, 0x1
    /* 26FC 80104EFC 1E002012 */  beqz       $s1, .L80104F78
    /* 2700 80104F00 01000224 */   addiu     $v0, $zero, 0x1
    /* 2704 80104F04 18002216 */  bne        $s1, $v0, .L80104F68
    /* 2708 80104F08 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 270C 80104F0C 6216010C */  jal        vs_main_playSfxDefault
    /* 2710 80104F10 1C000524 */   addiu     $a1, $zero, 0x1C
    /* 2714 80104F14 0680033C */  lui        $v1, %hi(vs_battle_inventory)
    /* 2718 80104F18 1180023C */  lui        $v0, %hi(D_8010A60C)
    /* 271C 80104F1C 0CA64590 */  lbu        $a1, %lo(D_8010A60C)($v0)
    /* 2720 80104F20 68016324 */  addiu      $v1, $v1, %lo(vs_battle_inventory)
    /* 2724 80104F24 FFFFA224 */  addiu      $v0, $a1, -0x1
    /* 2728 80104F28 80100200 */  sll        $v0, $v0, 2
    /* 272C 80104F2C 21204300 */  addu       $a0, $v0, $v1
    /* 2730 80104F30 1180023C */  lui        $v0, %hi(D_8010A60F)
    /* 2734 80104F34 020E8390 */  lbu        $v1, 0xE02($a0)
    /* 2738 80104F38 0FA64290 */  lbu        $v0, %lo(D_8010A60F)($v0)
    /* 273C 80104F3C 00000000 */  nop
    /* 2740 80104F40 07006214 */  bne        $v1, $v0, .L80104F60
    /* 2744 80104F44 23106200 */   subu      $v0, $v1, $v0
    /* 2748 80104F48 1180023C */  lui        $v0, %hi(D_8010A60B)
    /* 274C 80104F4C 0BA64490 */  lbu        $a0, %lo(D_8010A60B)($v0)
    /* 2750 80104F50 F8F8030C */  jal        vs_mainMenu_initItem
    /* 2754 80104F54 00000000 */   nop
    /* 2758 80104F58 DF130408 */  j          .L80104F7C
    /* 275C 80104F5C 21102002 */   addu      $v0, $s1, $zero
  .L80104F60:
    /* 2760 80104F60 DC130408 */  j          .L80104F70
    /* 2764 80104F64 020E82A0 */   sb        $v0, 0xE02($a0)
  .L80104F68:
    /* 2768 80104F68 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 276C 80104F6C 00000000 */   nop
  .L80104F70:
    /* 2770 80104F70 DF130408 */  j          .L80104F7C
    /* 2774 80104F74 21102002 */   addu      $v0, $s1, $zero
  .L80104F78:
    /* 2778 80104F78 21100000 */  addu       $v0, $zero, $zero
  .L80104F7C:
    /* 277C 80104F7C 5800BF8F */  lw         $ra, 0x58($sp)
    /* 2780 80104F80 5400B38F */  lw         $s3, 0x54($sp)
    /* 2784 80104F84 5000B28F */  lw         $s2, 0x50($sp)
    /* 2788 80104F88 4C00B18F */  lw         $s1, 0x4C($sp)
    /* 278C 80104F8C 4800B08F */  lw         $s0, 0x48($sp)
    /* 2790 80104F90 0800E003 */  jr         $ra
    /* 2794 80104F94 6000BD27 */   addiu     $sp, $sp, 0x60
endlabel _discardMenu
