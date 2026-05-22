nonmatching func_801063F8, 0xDC

glabel func_801063F8
    /* 3BF8 801063F8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3BFC 801063FC 21300000 */  addu       $a2, $zero, $zero
    /* 3C00 80106400 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentStats)
    /* 3C04 80106404 C0244824 */  addiu      $t0, $v0, %lo(vs_mainMenu_equipmentStats)
    /* 3C08 80106408 20000724 */  addiu      $a3, $zero, 0x20
    /* 3C0C 8010640C 0F80053C */  lui        $a1, %hi(vs_battle_actors)
    /* 3C10 80106410 1180023C */  lui        $v0, %hi(D_801080A8)
    /* 3C14 80106414 A880438C */  lw         $v1, %lo(D_801080A8)($v0)
    /* 3C18 80106418 1180023C */  lui        $v0, %hi(D_801081ED)
    /* 3C1C 8010641C ED814490 */  lbu        $a0, %lo(D_801081ED)($v0)
    /* 3C20 80106420 2819A524 */  addiu      $a1, $a1, %lo(vs_battle_actors)
    /* 3C24 80106424 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3C28 80106428 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 3C2C 8010642C 80180300 */  sll        $v1, $v1, 2
    /* 3C30 80106430 21186500 */  addu       $v1, $v1, $a1
    /* 3C34 80106434 C0100400 */  sll        $v0, $a0, 3
    /* 3C38 80106438 23104400 */  subu       $v0, $v0, $a0
    /* 3C3C 8010643C C0100200 */  sll        $v0, $v0, 3
    /* 3C40 80106440 23104400 */  subu       $v0, $v0, $a0
    /* 3C44 80106444 0000638C */  lw         $v1, 0x0($v1)
    /* 3C48 80106448 80100200 */  sll        $v0, $v0, 2
    /* 3C4C 8010644C 3C00638C */  lw         $v1, 0x3C($v1)
    /* 3C50 80106450 98034224 */  addiu      $v0, $v0, 0x398
    /* 3C54 80106454 21206200 */  addu       $a0, $v1, $v0
  .L80106458:
    /* 3C58 80106458 2118E800 */  addu       $v1, $a3, $t0
    /* 3C5C 8010645C 0700C230 */  andi       $v0, $a2, 0x7
    /* 3C60 80106460 40100200 */  sll        $v0, $v0, 1
    /* 3C64 80106464 21108200 */  addu       $v0, $a0, $v0
    /* 3C68 80106468 10004294 */  lhu        $v0, 0x10($v0)
    /* 3C6C 8010646C 0100C624 */  addiu      $a2, $a2, 0x1
    /* 3C70 80106470 000062A4 */  sh         $v0, 0x0($v1)
    /* 3C74 80106474 1000C228 */  slti       $v0, $a2, 0x10
    /* 3C78 80106478 F7FF4014 */  bnez       $v0, .L80106458
    /* 3C7C 8010647C 0200E724 */   addiu     $a3, $a3, 0x2
    /* 3C80 80106480 21300000 */  addu       $a2, $zero, $zero
    /* 3C84 80106484 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentStats)
    /* 3C88 80106488 C0244724 */  addiu      $a3, $v0, %lo(vs_mainMenu_equipmentStats)
    /* 3C8C 8010648C 21288000 */  addu       $a1, $a0, $zero
    /* 3C90 80106490 40000424 */  addiu      $a0, $zero, 0x40
  .L80106494:
    /* 3C94 80106494 0800A394 */  lhu        $v1, 0x8($a1)
    /* 3C98 80106498 0200A524 */  addiu      $a1, $a1, 0x2
    /* 3C9C 8010649C 21108700 */  addu       $v0, $a0, $a3
    /* 3CA0 801064A0 0100C624 */  addiu      $a2, $a2, 0x1
    /* 3CA4 801064A4 000043A4 */  sh         $v1, 0x0($v0)
    /* 3CA8 801064A8 0400C228 */  slti       $v0, $a2, 0x4
    /* 3CAC 801064AC F9FF4014 */  bnez       $v0, .L80106494
    /* 3CB0 801064B0 02008424 */   addiu     $a0, $a0, 0x2
    /* 3CB4 801064B4 1180023C */  lui        $v0, %hi(D_801081ED)
    /* 3CB8 801064B8 ED814490 */  lbu        $a0, %lo(D_801081ED)($v0)
    /* 3CBC 801064BC 6E11040C */  jal        _drawHitLocationStatuses
    /* 3CC0 801064C0 81008424 */   addiu     $a0, $a0, 0x81
    /* 3CC4 801064C4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3CC8 801064C8 00000000 */  nop
    /* 3CCC 801064CC 0800E003 */  jr         $ra
    /* 3CD0 801064D0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_801063F8
