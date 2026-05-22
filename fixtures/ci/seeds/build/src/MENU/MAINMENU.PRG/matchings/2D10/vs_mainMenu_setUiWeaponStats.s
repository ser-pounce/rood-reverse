nonmatching vs_mainMenu_setUiWeaponStats, 0x194

glabel vs_mainMenu_setUiWeaponStats
    /* 3A70 800FD270 48FEBD27 */  addiu      $sp, $sp, -0x1B8
    /* 3A74 800FD274 B001B2AF */  sw         $s2, 0x1B0($sp)
    /* 3A78 800FD278 21908000 */  addu       $s2, $a0, $zero
    /* 3A7C 800FD27C AC01B1AF */  sw         $s1, 0x1AC($sp)
    /* 3A80 800FD280 1000B127 */  addiu      $s1, $sp, 0x10
    /* 3A84 800FD284 B401BFAF */  sw         $ra, 0x1B4($sp)
    /* 3A88 800FD288 88F4030C */  jal        vs_mainMenu_resetStats
    /* 3A8C 800FD28C A801B0AF */   sw        $s0, 0x1A8($sp)
    /* 3A90 800FD290 21200000 */  addu       $a0, $zero, $zero
    /* 3A94 800FD294 21288000 */  addu       $a1, $a0, $zero
    /* 3A98 800FD298 21308000 */  addu       $a2, $a0, $zero
    /* 3A9C 800FD29C 43EF030C */  jal        vs_mainMenu_setRangeRisk
    /* 3AA0 800FD2A0 01000724 */   addiu     $a3, $zero, 0x1
    /* 3AA4 800FD2A4 4A004012 */  beqz       $s2, .L800FD3D0
    /* 3AA8 800FD2A8 1080023C */   lui       $v0, %hi(vs_mainMenu_weapons)
    /* 3AAC 800FD2AC 7024438C */  lw         $v1, %lo(vs_mainMenu_weapons)($v0)
    /* 3AB0 800FD2B0 40291200 */  sll        $a1, $s2, 5
    /* 3AB4 800FD2B4 2110A300 */  addu       $v0, $a1, $v1
    /* 3AB8 800FD2B8 E3FF4290 */  lbu        $v0, -0x1D($v0)
    /* 3ABC 800FD2BC 00000000 */  nop
    /* 3AC0 800FD2C0 06004010 */  beqz       $v0, .L800FD2DC
    /* 3AC4 800FD2C4 0F80023C */   lui       $v0, %hi(vs_battle_characterState)
    /* 3AC8 800FD2C8 FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 3ACC 800FD2CC 00000000 */  nop
    /* 3AD0 800FD2D0 3C00428C */  lw         $v0, 0x3C($v0)
    /* 3AD4 800FD2D4 C5F40308 */  j          .L800FD314
    /* 3AD8 800FD2D8 3C005124 */   addiu     $s1, $v0, 0x3C
  .L800FD2DC:
    /* 3ADC 800FD2DC 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 3AE0 800FD2E0 68014224 */  addiu      $v0, $v0, %lo(vs_battle_inventory)
    /* 3AE4 800FD2E4 06006214 */  bne        $v1, $v0, .L800FD300
    /* 3AE8 800FD2E8 21202002 */   addu      $a0, $s1, $zero
    /* 3AEC 800FD2EC E0FFA524 */  addiu      $a1, $a1, -0x20
    /* 3AF0 800FD2F0 ABAB010C */  jal        vs_battle_applyWeapon
    /* 3AF4 800FD2F4 2128A300 */   addu      $a1, $a1, $v1
    /* 3AF8 800FD2F8 C6F40308 */  j          .L800FD318
    /* 3AFC 800FD2FC 1080103C */   lui       $s0, %hi(vs_mainMenu_equipmentStats)
  .L800FD300:
    /* 3B00 800FD300 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 3B04 800FD304 8C9A468C */  lw         $a2, %lo(vs_menuD_containerData)($v0)
    /* 3B08 800FD308 E0FFA524 */  addiu      $a1, $a1, -0x20
    /* 3B0C 800FD30C 8D0A040C */  jal        vs_menuD_initUiWeapon
    /* 3B10 800FD310 21286500 */   addu      $a1, $v1, $a1
  .L800FD314:
    /* 3B14 800FD314 1080103C */  lui        $s0, %hi(vs_mainMenu_equipmentStats)
  .L800FD318:
    /* 3B18 800FD318 C0241026 */  addiu      $s0, $s0, %lo(vs_mainMenu_equipmentStats)
    /* 3B1C 800FD31C 21200002 */  addu       $a0, $s0, $zero
    /* 3B20 800FD320 28012526 */  addiu      $a1, $s1, 0x128
    /* 3B24 800FD324 7800030C */  jal        vs_battle_memcpy
    /* 3B28 800FD328 40000624 */   addiu     $a2, $zero, 0x40
    /* 3B2C 800FD32C 21200000 */  addu       $a0, $zero, $zero
    /* 3B30 800FD330 40000524 */  addiu      $a1, $zero, 0x40
  .L800FD334:
    /* 3B34 800FD334 2118B000 */  addu       $v1, $a1, $s0
    /* 3B38 800FD338 21102402 */  addu       $v0, $s1, $a0
    /* 3B3C 800FD33C 64004290 */  lbu        $v0, 0x64($v0)
    /* 3B40 800FD340 01008424 */  addiu      $a0, $a0, 0x1
    /* 3B44 800FD344 00160200 */  sll        $v0, $v0, 24
    /* 3B48 800FD348 03160200 */  sra        $v0, $v0, 24
    /* 3B4C 800FD34C 000062A4 */  sh         $v0, 0x0($v1)
    /* 3B50 800FD350 04008228 */  slti       $v0, $a0, 0x4
    /* 3B54 800FD354 F7FF4014 */  bnez       $v0, .L800FD334
    /* 3B58 800FD358 0200A524 */   addiu     $a1, $a1, 0x2
    /* 3B5C 800FD35C 0E012392 */  lbu        $v1, 0x10E($s1)
    /* 3B60 800FD360 1080023C */  lui        $v0, %hi(D_80102508)
    /* 3B64 800FD364 082543A4 */  sh         $v1, %lo(D_80102508)($v0)
    /* 3B68 800FD368 14012496 */  lhu        $a0, 0x114($s1)
    /* 3B6C 800FD36C 16012596 */  lhu        $a1, 0x116($s1)
    /* 3B70 800FD370 10012696 */  lhu        $a2, 0x110($s1)
    /* 3B74 800FD374 12012796 */  lhu        $a3, 0x112($s1)
    /* 3B78 800FD378 82F0030C */  jal        vs_mainMenu_setDpPp
    /* 3B7C 800FD37C 00000000 */   nop
    /* 3B80 800FD380 18012486 */  lh         $a0, 0x118($s1)
    /* 3B84 800FD384 1C012586 */  lh         $a1, 0x11C($s1)
    /* 3B88 800FD388 20012686 */  lh         $a2, 0x120($s1)
    /* 3B8C 800FD38C 4AEF030C */  jal        vs_mainMenu_setStrIntAgi
    /* 3B90 800FD390 01000724 */   addiu     $a3, $zero, 0x1
    /* 3B94 800FD394 21300000 */  addu       $a2, $zero, $zero
    /* 3B98 800FD398 24012492 */  lbu        $a0, 0x124($s1)
    /* 3B9C 800FD39C 0A012592 */  lbu        $a1, 0x10A($s1)
    /* 3BA0 800FD3A0 43EF030C */  jal        vs_mainMenu_setRangeRisk
    /* 3BA4 800FD3A4 01000724 */   addiu     $a3, $zero, 0x1
    /* 3BA8 800FD3A8 1080033C */  lui        $v1, %hi(vs_mainMenu_strIntAgi)
    /* 3BAC 800FD3AC 1A012296 */  lhu        $v0, 0x11A($s1)
    /* 3BB0 800FD3B0 A8246324 */  addiu      $v1, $v1, %lo(vs_mainMenu_strIntAgi)
    /* 3BB4 800FD3B4 080062A4 */  sh         $v0, 0x8($v1)
    /* 3BB8 800FD3B8 1E012296 */  lhu        $v0, 0x11E($s1)
    /* 3BBC 800FD3BC 00000000 */  nop
    /* 3BC0 800FD3C0 0A0062A4 */  sh         $v0, 0xA($v1)
    /* 3BC4 800FD3C4 22012296 */  lhu        $v0, 0x122($s1)
    /* 3BC8 800FD3C8 00000000 */  nop
    /* 3BCC 800FD3CC 0C0062A4 */  sh         $v0, 0xC($v1)
  .L800FD3D0:
    /* 3BD0 800FD3D0 07000424 */  addiu      $a0, $zero, 0x7
    /* 3BD4 800FD3D4 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentSubtype)
    /* 3BD8 800FD3D8 01000324 */  addiu      $v1, $zero, 0x1
    /* 3BDC 800FD3DC 452543A0 */  sb         $v1, %lo(vs_mainMenu_equipmentSubtype)($v0)
    /* 3BE0 800FD3E0 1080023C */  lui        $v0, %hi(D_801024A1)
    /* 3BE4 800FD3E4 E3EE030C */  jal        func_800FBB8C
    /* 3BE8 800FD3E8 A12452A0 */   sb        $s2, %lo(D_801024A1)($v0)
    /* 3BEC 800FD3EC B401BF8F */  lw         $ra, 0x1B4($sp)
    /* 3BF0 800FD3F0 B001B28F */  lw         $s2, 0x1B0($sp)
    /* 3BF4 800FD3F4 AC01B18F */  lw         $s1, 0x1AC($sp)
    /* 3BF8 800FD3F8 A801B08F */  lw         $s0, 0x1A8($sp)
    /* 3BFC 800FD3FC 0800E003 */  jr         $ra
    /* 3C00 800FD400 B801BD27 */   addiu     $sp, $sp, 0x1B8
endlabel vs_mainMenu_setUiWeaponStats
