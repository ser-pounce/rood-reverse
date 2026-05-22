nonmatching func_80102B70, 0x13C

glabel func_80102B70
    /* 370 80102B70 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 374 80102B74 1400B1AF */  sw         $s1, 0x14($sp)
    /* 378 80102B78 21888000 */  addu       $s1, $a0, $zero
    /* 37C 80102B7C 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentSubtype)
    /* 380 80102B80 10000324 */  addiu      $v1, $zero, 0x10
    /* 384 80102B84 1800BFAF */  sw         $ra, 0x18($sp)
    /* 388 80102B88 1000B0AF */  sw         $s0, 0x10($sp)
    /* 38C 80102B8C 88F4030C */  jal        vs_mainMenu_resetStats
    /* 390 80102B90 452543A0 */   sb        $v1, %lo(vs_mainMenu_equipmentSubtype)($v0)
    /* 394 80102B94 00002296 */  lhu        $v0, 0x0($s1)
    /* 398 80102B98 00000000 */  nop
    /* 39C 80102B9C 3C004010 */  beqz       $v0, .L80102C90
    /* 3A0 80102BA0 1080103C */   lui       $s0, %hi(vs_mainMenu_equipmentStats)
    /* 3A4 80102BA4 C0241026 */  addiu      $s0, $s0, %lo(vs_mainMenu_equipmentStats)
    /* 3A8 80102BA8 21200002 */  addu       $a0, $s0, $zero
    /* 3AC 80102BAC 48002526 */  addiu      $a1, $s1, 0x48
    /* 3B0 80102BB0 7800030C */  jal        vs_battle_memcpy
    /* 3B4 80102BB4 40000624 */   addiu     $a2, $zero, 0x40
    /* 3B8 80102BB8 60000426 */  addiu      $a0, $s0, 0x60
    /* 3BC 80102BBC 9C002526 */  addiu      $a1, $s1, 0x9C
    /* 3C0 80102BC0 7800030C */  jal        vs_battle_memcpy
    /* 3C4 80102BC4 20000624 */   addiu     $a2, $zero, 0x20
    /* 3C8 80102BC8 21300000 */  addu       $a2, $zero, $zero
    /* 3CC 80102BCC 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 3D0 80102BD0 FC19458C */  lw         $a1, %lo(vs_battle_characterState)($v0)
    /* 3D4 80102BD4 98030424 */  addiu      $a0, $zero, 0x398
    /* 3D8 80102BD8 7E0000A6 */  sh         $zero, 0x7E($s0)
  .L80102BDC:
    /* 3DC 80102BDC 0100C624 */  addiu      $a2, $a2, 0x1
    /* 3E0 80102BE0 3C00A28C */  lw         $v0, 0x3C($a1)
    /* 3E4 80102BE4 7E000386 */  lh         $v1, 0x7E($s0)
    /* 3E8 80102BE8 21104400 */  addu       $v0, $v0, $a0
    /* 3EC 80102BEC DC008424 */  addiu      $a0, $a0, 0xDC
    /* 3F0 80102BF0 20004224 */  addiu      $v0, $v0, 0x20
    /* 3F4 80102BF4 26102202 */  xor        $v0, $s1, $v0
    /* 3F8 80102BF8 0100422C */  sltiu      $v0, $v0, 0x1
    /* 3FC 80102BFC 25186200 */  or         $v1, $v1, $v0
    /* 400 80102C00 0500C228 */  slti       $v0, $a2, 0x5
    /* 404 80102C04 F5FF4014 */  bnez       $v0, .L80102BDC
    /* 408 80102C08 7E0003A6 */   sh        $v1, 0x7E($s0)
    /* 40C 80102C0C 21300000 */  addu       $a2, $zero, $zero
    /* 410 80102C10 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentStats)
    /* 414 80102C14 C0244724 */  addiu      $a3, $v0, %lo(vs_mainMenu_equipmentStats)
    /* 418 80102C18 21282002 */  addu       $a1, $s1, $zero
    /* 41C 80102C1C 40000424 */  addiu      $a0, $zero, 0x40
  .L80102C20:
    /* 420 80102C20 4000A394 */  lhu        $v1, 0x40($a1)
    /* 424 80102C24 0200A524 */  addiu      $a1, $a1, 0x2
    /* 428 80102C28 21108700 */  addu       $v0, $a0, $a3
    /* 42C 80102C2C 0100C624 */  addiu      $a2, $a2, 0x1
    /* 430 80102C30 000043A4 */  sh         $v1, 0x0($v0)
    /* 434 80102C34 0400C228 */  slti       $v0, $a2, 0x4
    /* 438 80102C38 F9FF4014 */  bnez       $v0, .L80102C20
    /* 43C 80102C3C 02008424 */   addiu     $a0, $a0, 0x2
    /* 440 80102C40 21300000 */  addu       $a2, $zero, $zero
    /* 444 80102C44 30002496 */  lhu        $a0, 0x30($s1)
    /* 448 80102C48 32002596 */  lhu        $a1, 0x32($s1)
    /* 44C 80102C4C 82F0030C */  jal        vs_mainMenu_setDpPp
    /* 450 80102C50 2138C000 */   addu      $a3, $a2, $zero
    /* 454 80102C54 34002486 */  lh         $a0, 0x34($s1)
    /* 458 80102C58 38002586 */  lh         $a1, 0x38($s1)
    /* 45C 80102C5C 3C002686 */  lh         $a2, 0x3C($s1)
    /* 460 80102C60 4AEF030C */  jal        vs_mainMenu_setStrIntAgi
    /* 464 80102C64 01000724 */   addiu     $a3, $zero, 0x1
    /* 468 80102C68 1080033C */  lui        $v1, %hi(vs_mainMenu_strIntAgi)
    /* 46C 80102C6C 36002296 */  lhu        $v0, 0x36($s1)
    /* 470 80102C70 A8246324 */  addiu      $v1, $v1, %lo(vs_mainMenu_strIntAgi)
    /* 474 80102C74 080062A4 */  sh         $v0, 0x8($v1)
    /* 478 80102C78 3A002296 */  lhu        $v0, 0x3A($s1)
    /* 47C 80102C7C 00000000 */  nop
    /* 480 80102C80 0A0062A4 */  sh         $v0, 0xA($v1)
    /* 484 80102C84 3E002296 */  lhu        $v0, 0x3E($s1)
    /* 488 80102C88 00000000 */  nop
    /* 48C 80102C8C 0C0062A4 */  sh         $v0, 0xC($v1)
  .L80102C90:
    /* 490 80102C90 E3EE030C */  jal        func_800FBB8C
    /* 494 80102C94 07000424 */   addiu     $a0, $zero, 0x7
    /* 498 80102C98 1800BF8F */  lw         $ra, 0x18($sp)
    /* 49C 80102C9C 1400B18F */  lw         $s1, 0x14($sp)
    /* 4A0 80102CA0 1000B08F */  lw         $s0, 0x10($sp)
    /* 4A4 80102CA4 0800E003 */  jr         $ra
    /* 4A8 80102CA8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80102B70
