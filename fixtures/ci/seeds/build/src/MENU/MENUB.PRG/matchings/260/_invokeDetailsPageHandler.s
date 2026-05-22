nonmatching _invokeDetailsPageHandler, 0x114

glabel _invokeDetailsPageHandler
    /* 13A8 80103BA8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 13AC 80103BAC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 13B0 80103BB0 21800000 */  addu       $s0, $zero, $zero
    /* 13B4 80103BB4 11008010 */  beqz       $a0, .L80103BFC
    /* 13B8 80103BB8 1400BFAF */   sw        $ra, 0x14($sp)
    /* 13BC 80103BBC 03810400 */  sra        $s0, $a0, 4
    /* 13C0 80103BC0 1180033C */  lui        $v1, %hi(D_8010A607)
    /* 13C4 80103BC4 0F008230 */  andi       $v0, $a0, 0xF
    /* 13C8 80103BC8 07A662A0 */  sb         $v0, %lo(D_8010A607)($v1)
    /* 13CC 80103BCC 1180033C */  lui        $v1, %hi(D_8010A6BF)
    /* 13D0 80103BD0 01000224 */  addiu      $v0, $zero, 0x1
    /* 13D4 80103BD4 BFA662A0 */  sb         $v0, %lo(D_8010A6BF)($v1)
    /* 13D8 80103BD8 1180023C */  lui        $v0, %hi(_exitToBattle)
    /* 13DC 80103BDC 5EF7030C */  jal        func_800FDD78
    /* 13E0 80103BE0 C0A640AC */   sw        $zero, %lo(_exitToBattle)($v0)
    /* 13E4 80103BE4 9223030C */  jal        vs_battle_getMenuItem
    /* 13E8 80103BE8 1F000424 */   addiu     $a0, $zero, 0x1F
    /* 13EC 80103BEC 21200000 */  addu       $a0, $zero, $zero
    /* 13F0 80103BF0 FF000332 */  andi       $v1, $s0, 0xFF
    /* 13F4 80103BF4 A2FE030C */  jal        func_800FFA88
    /* 13F8 80103BF8 0E0043A4 */   sh        $v1, 0xE($v0)
  .L80103BFC:
    /* 13FC 80103BFC 1180033C */  lui        $v1, %hi(D_8010A514)
    /* 1400 80103C00 1180023C */  lui        $v0, %hi(D_8010A607)
    /* 1404 80103C04 07A64290 */  lbu        $v0, %lo(D_8010A607)($v0)
    /* 1408 80103C08 14A56324 */  addiu      $v1, $v1, %lo(D_8010A514)
    /* 140C 80103C0C 80100200 */  sll        $v0, $v0, 2
    /* 1410 80103C10 21104300 */  addu       $v0, $v0, $v1
    /* 1414 80103C14 0000428C */  lw         $v0, 0x0($v0)
    /* 1418 80103C18 00000000 */  nop
    /* 141C 80103C1C 09F84000 */  jalr       $v0
    /* 1420 80103C20 21200002 */   addu      $a0, $s0, $zero
    /* 1424 80103C24 21804000 */  addu       $s0, $v0, $zero
    /* 1428 80103C28 12000012 */  beqz       $s0, .L80103C74
    /* 142C 80103C2C 1180023C */   lui       $v0, %hi(_exitToBattle)
    /* 1430 80103C30 C0A6428C */  lw         $v0, %lo(_exitToBattle)($v0)
    /* 1434 80103C34 00000000 */  nop
    /* 1438 80103C38 1C004014 */  bnez       $v0, .L80103CAC
    /* 143C 80103C3C FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 1440 80103C40 02000424 */  addiu      $a0, $zero, 0x2
    /* 1444 80103C44 1180023C */  lui        $v0, %hi(D_8010A6BA)
    /* 1448 80103C48 01000324 */  addiu      $v1, $zero, 0x1
    /* 144C 80103C4C BAA643A0 */  sb         $v1, %lo(D_8010A6BA)($v0)
    /* 1450 80103C50 1180023C */  lui        $v0, %hi(D_8010A6BF)
    /* 1454 80103C54 BFA640A0 */  sb         $zero, %lo(D_8010A6BF)($v0)
    /* 1458 80103C58 1180023C */  lui        $v0, %hi(D_8010A6BB)
    /* 145C 80103C5C BBA643A0 */  sb         $v1, %lo(D_8010A6BB)($v0)
    /* 1460 80103C60 1180023C */  lui        $v0, %hi(D_8010A50C)
    /* 1464 80103C64 A2FE030C */  jal        func_800FFA88
    /* 1468 80103C68 0CA540AC */   sw        $zero, %lo(D_8010A50C)($v0)
    /* 146C 80103C6C 2B0F0408 */  j          .L80103CAC
    /* 1470 80103C70 21100002 */   addu      $v0, $s0, $zero
  .L80103C74:
    /* 1474 80103C74 74EA030C */  jal        vs_mainmenu_ready
    /* 1478 80103C78 00000000 */   nop
    /* 147C 80103C7C 0A004010 */  beqz       $v0, .L80103CA8
    /* 1480 80103C80 01000424 */   addiu     $a0, $zero, 0x1
    /* 1484 80103C84 1080023C */  lui        $v0, %hi(D_801024B8)
    /* 1488 80103C88 B8244290 */  lbu        $v0, %lo(D_801024B8)($v0)
    /* 148C 80103C8C 1080033C */  lui        $v1, %hi(D_801022D5)
    /* 1490 80103C90 09004238 */  xori       $v0, $v0, 0x9
    /* 1494 80103C94 2B100200 */  sltu       $v0, $zero, $v0
    /* 1498 80103C98 FE04040C */  jal        func_801013F8
    /* 149C 80103C9C D52262A0 */   sb        $v0, %lo(D_801022D5)($v1)
    /* 14A0 80103CA0 AFF7030C */  jal        func_800FDEBC
    /* 14A4 80103CA4 00000000 */   nop
  .L80103CA8:
    /* 14A8 80103CA8 21100002 */  addu       $v0, $s0, $zero
  .L80103CAC:
    /* 14AC 80103CAC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 14B0 80103CB0 1000B08F */  lw         $s0, 0x10($sp)
    /* 14B4 80103CB4 0800E003 */  jr         $ra
    /* 14B8 80103CB8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _invokeDetailsPageHandler
