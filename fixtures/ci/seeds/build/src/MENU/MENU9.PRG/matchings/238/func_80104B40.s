nonmatching func_80104B40, 0x90

glabel func_80104B40
    /* 2340 80104B40 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2344 80104B44 1180023C */  lui        $v0, %hi(D_8010A450)
    /* 2348 80104B48 50A44384 */  lh         $v1, %lo(D_8010A450)($v0)
    /* 234C 80104B4C 1180043C */  lui        $a0, %hi(_monBinData)
    /* 2350 80104B50 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2354 80104B54 40280300 */  sll        $a1, $v1, 1
    /* 2358 80104B58 2110A300 */  addu       $v0, $a1, $v1
    /* 235C 80104B5C 80100200 */  sll        $v0, $v0, 2
    /* 2360 80104B60 23104300 */  subu       $v0, $v0, $v1
    /* 2364 80104B64 70A4838C */  lw         $v1, %lo(_monBinData)($a0)
    /* 2368 80104B68 80100200 */  sll        $v0, $v0, 2
    /* 236C 80104B6C 21104300 */  addu       $v0, $v0, $v1
    /* 2370 80104B70 0C004290 */  lbu        $v0, 0xC($v0)
    /* 2374 80104B74 00000000 */  nop
    /* 2378 80104B78 09004010 */  beqz       $v0, .L80104BA0
    /* 237C 80104B7C 1180023C */   lui       $v0, %hi(_enemyDescriptions)
    /* 2380 80104B80 74A4438C */  lw         $v1, %lo(_enemyDescriptions)($v0)
    /* 2384 80104B84 00000000 */  nop
    /* 2388 80104B88 2110A300 */  addu       $v0, $a1, $v1
    /* 238C 80104B8C 00004494 */  lhu        $a0, 0x0($v0)
    /* 2390 80104B90 00000000 */  nop
    /* 2394 80104B94 40200400 */  sll        $a0, $a0, 1
    /* 2398 80104B98 EE120408 */  j          .L80104BB8
    /* 239C 80104B9C 21206400 */   addu      $a0, $v1, $a0
  .L80104BA0:
    /* 23A0 80104BA0 1180023C */  lui        $v0, %hi(_miscInfo)
    /* 23A4 80104BA4 DC974224 */  addiu      $v0, $v0, %lo(_miscInfo)
    /* 23A8 80104BA8 04004494 */  lhu        $a0, 0x4($v0)
    /* 23AC 80104BAC 00000000 */  nop
    /* 23B0 80104BB0 40200400 */  sll        $a0, $a0, 1
    /* 23B4 80104BB4 21208200 */  addu       $a0, $a0, $v0
  .L80104BB8:
    /* 23B8 80104BB8 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 23BC 80104BBC 00000000 */   nop
    /* 23C0 80104BC0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 23C4 80104BC4 00000000 */  nop
    /* 23C8 80104BC8 0800E003 */  jr         $ra
    /* 23CC 80104BCC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80104B40
