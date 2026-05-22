nonmatching func_80106308, 0xF0

glabel func_80106308
    /* 3B08 80106308 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3B0C 8010630C 0F80053C */  lui        $a1, %hi(vs_battle_actors)
    /* 3B10 80106310 1180023C */  lui        $v0, %hi(D_801080A8)
    /* 3B14 80106314 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3B18 80106318 1180123C */  lui        $s2, %hi(D_801081ED)
    /* 3B1C 8010631C A880438C */  lw         $v1, %lo(D_801080A8)($v0)
    /* 3B20 80106320 ED814492 */  lbu        $a0, %lo(D_801081ED)($s2)
    /* 3B24 80106324 2819A524 */  addiu      $a1, $a1, %lo(vs_battle_actors)
    /* 3B28 80106328 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3B2C 8010632C 0F80103C */  lui        $s0, %hi(vs_battle_stringContext)
    /* 3B30 80106330 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 3B34 80106334 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3B38 80106338 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 3B3C 8010633C 80180300 */  sll        $v1, $v1, 2
    /* 3B40 80106340 21186500 */  addu       $v1, $v1, $a1
    /* 3B44 80106344 C0100400 */  sll        $v0, $a0, 3
    /* 3B48 80106348 23104400 */  subu       $v0, $v0, $a0
    /* 3B4C 8010634C C0100200 */  sll        $v0, $v0, 3
    /* 3B50 80106350 23104400 */  subu       $v0, $v0, $a0
    /* 3B54 80106354 80100200 */  sll        $v0, $v0, 2
    /* 3B58 80106358 0000638C */  lw         $v1, 0x0($v1)
    /* 3B5C 8010635C 98034224 */  addiu      $v0, $v0, 0x398
    /* 3B60 80106360 3C00648C */  lw         $a0, 0x3C($v1)
    /* 3B64 80106364 0F80033C */  lui        $v1, %hi(D_800EA868)
    /* 3B68 80106368 21208200 */  addu       $a0, $a0, $v0
    /* 3B6C 8010636C 06008290 */  lbu        $v0, 0x6($a0)
    /* 3B70 80106370 68A86324 */  addiu      $v1, $v1, %lo(D_800EA868)
    /* 3B74 80106374 40100200 */  sll        $v0, $v0, 1
    /* 3B78 80106378 21104300 */  addu       $v0, $v0, $v1
    /* 3B7C 8010637C 00004294 */  lhu        $v0, 0x0($v0)
    /* 3B80 80106380 68511026 */  addiu      $s0, $s0, %lo(vs_battle_stringContext)
    /* 3B84 80106384 40100200 */  sll        $v0, $v0, 1
    /* 3B88 80106388 21104300 */  addu       $v0, $v0, $v1
    /* 3B8C 8010638C 9727030C */  jal        vs_battle_getHitLocationStatus
    /* 3B90 80106390 280002AE */   sw        $v0, 0x28($s0)
    /* 3B94 80106394 1080053C */  lui        $a1, %hi(D_80107448)
    /* 3B98 80106398 4874A524 */  addiu      $a1, $a1, %lo(D_80107448)
    /* 3B9C 8010639C 0D004224 */  addiu      $v0, $v0, 0xD
    /* 3BA0 801063A0 40100200 */  sll        $v0, $v0, 1
    /* 3BA4 801063A4 21104500 */  addu       $v0, $v0, $a1
    /* 3BA8 801063A8 0F80113C */  lui        $s1, %hi(vs_battle_stringBuf)
    /* 3BAC 801063AC 00004294 */  lhu        $v0, 0x0($v0)
    /* 3BB0 801063B0 8C4E248E */  lw         $a0, %lo(vs_battle_stringBuf)($s1)
    /* 3BB4 801063B4 40100200 */  sll        $v0, $v0, 1
    /* 3BB8 801063B8 21104500 */  addu       $v0, $v0, $a1
    /* 3BBC 801063BC FA01A524 */  addiu      $a1, $a1, 0x1FA
    /* 3BC0 801063C0 171A030C */  jal        vs_battle_printf
    /* 3BC4 801063C4 2C0002AE */   sw        $v0, 0x2C($s0)
    /* 3BC8 801063C8 8C4E248E */  lw         $a0, %lo(vs_battle_stringBuf)($s1)
    /* 3BCC 801063CC 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 3BD0 801063D0 00000000 */   nop
    /* 3BD4 801063D4 ED814492 */  lbu        $a0, %lo(D_801081ED)($s2)
    /* 3BD8 801063D8 6E11040C */  jal        _drawHitLocationStatuses
    /* 3BDC 801063DC 01008424 */   addiu     $a0, $a0, 0x1
    /* 3BE0 801063E0 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 3BE4 801063E4 1800B28F */  lw         $s2, 0x18($sp)
    /* 3BE8 801063E8 1400B18F */  lw         $s1, 0x14($sp)
    /* 3BEC 801063EC 1000B08F */  lw         $s0, 0x10($sp)
    /* 3BF0 801063F0 0800E003 */  jr         $ra
    /* 3BF4 801063F4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80106308
