nonmatching func_80073AFC, 0x234

glabel func_80073AFC
    /* B2FC 80073AFC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* B300 80073B00 1800B0AF */  sw         $s0, 0x18($sp)
    /* B304 80073B04 21808000 */  addu       $s0, $a0, $zero
    /* B308 80073B08 2400BFAF */  sw         $ra, 0x24($sp)
    /* B30C 80073B0C 2000B2AF */  sw         $s2, 0x20($sp)
    /* B310 80073B10 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* B314 80073B14 0E000286 */  lh         $v0, 0xE($s0)
    /* B318 80073B18 00000000 */  nop
    /* B31C 80073B1C 7E004014 */  bnez       $v0, .L80073D18
    /* B320 80073B20 01000224 */   addiu     $v0, $zero, 0x1
    /* B324 80073B24 12000292 */  lbu        $v0, 0x12($s0)
    /* B328 80073B28 00000000 */  nop
    /* B32C 80073B2C 7A004014 */  bnez       $v0, .L80073D18
    /* B330 80073B30 01000224 */   addiu     $v0, $zero, 0x1
    /* B334 80073B34 00000286 */  lh         $v0, 0x0($s0)
    /* B338 80073B38 00000000 */  nop
    /* B33C 80073B3C C0110200 */  sll        $v0, $v0, 7
    /* B340 80073B40 40004224 */  addiu      $v0, $v0, 0x40
    /* B344 80073B44 1000A2A7 */  sh         $v0, 0x10($sp)
    /* B348 80073B48 02000286 */  lh         $v0, 0x2($s0)
    /* B34C 80073B4C 00000000 */  nop
    /* B350 80073B50 C0110200 */  sll        $v0, $v0, 7
    /* B354 80073B54 40004224 */  addiu      $v0, $v0, 0x40
    /* B358 80073B58 1400A2A7 */  sh         $v0, 0x14($sp)
    /* B35C 80073B5C 08000392 */  lbu        $v1, 0x8($s0)
    /* B360 80073B60 01000224 */  addiu      $v0, $zero, 0x1
    /* B364 80073B64 0F006210 */  beq        $v1, $v0, .L80073BA4
    /* B368 80073B68 21880000 */   addu      $s1, $zero, $zero
    /* B36C 80073B6C 02006228 */  slti       $v0, $v1, 0x2
    /* B370 80073B70 05004010 */  beqz       $v0, .L80073B88
    /* B374 80073B74 00000000 */   nop
    /* B378 80073B78 08006010 */  beqz       $v1, .L80073B9C
    /* B37C 80073B7C 00000000 */   nop
    /* B380 80073B80 08CF0108 */  j          .L80073C20
    /* B384 80073B84 00000000 */   nop
  .L80073B88:
    /* B388 80073B88 03000224 */  addiu      $v0, $zero, 0x3
    /* B38C 80073B8C 05006210 */  beq        $v1, $v0, .L80073BA4
    /* B390 80073B90 00000000 */   nop
    /* B394 80073B94 08CF0108 */  j          .L80073C20
    /* B398 80073B98 00000000 */   nop
  .L80073B9C:
    /* B39C 80073B9C 08CF0108 */  j          .L80073C20
    /* B3A0 80073BA0 01001124 */   addiu     $s1, $zero, 0x1
  .L80073BA4:
    /* B3A4 80073BA4 0C000486 */  lh         $a0, 0xC($s0)
    /* B3A8 80073BA8 15F9010C */  jal        vs_battle_itemIdIsInInventory
    /* B3AC 80073BAC 00000000 */   nop
    /* B3B0 80073BB0 10004010 */  beqz       $v0, .L80073BF4
    /* B3B4 80073BB4 00000000 */   nop
    /* B3B8 80073BB8 0C000286 */  lh         $v0, 0xC($s0)
    /* B3BC 80073BBC 0C000496 */  lhu        $a0, 0xC($s0)
    /* B3C0 80073BC0 D2014228 */  slti       $v0, $v0, 0x1D2
    /* B3C4 80073BC4 08004014 */  bnez       $v0, .L80073BE8
    /* B3C8 80073BC8 B6018424 */   addiu     $a0, $a0, 0x1B6
    /* B3CC 80073BCC 00240400 */  sll        $a0, $a0, 16
    /* B3D0 80073BD0 03240400 */  sra        $a0, $a0, 16
    /* B3D4 80073BD4 05FB020C */  jal        vs_battle_setStateFlag
    /* B3D8 80073BD8 02000524 */   addiu     $a1, $zero, 0x2
    /* B3DC 80073BDC 0C000486 */  lh         $a0, 0xC($s0)
    /* B3E0 80073BE0 E732030C */  jal        vs_battle_decreaseMiscCount
    /* B3E4 80073BE4 00000000 */   nop
  .L80073BE8:
    /* B3E8 80073BE8 080000A2 */  sb         $zero, 0x8($s0)
    /* B3EC 80073BEC 08CF0108 */  j          .L80073C20
    /* B3F0 80073BF0 02001124 */   addiu     $s1, $zero, 0x2
  .L80073BF4:
    /* B3F4 80073BF4 0C000496 */  lhu        $a0, 0xC($s0)
    /* B3F8 80073BF8 00000000 */  nop
    /* B3FC 80073BFC B6018424 */  addiu      $a0, $a0, 0x1B6
    /* B400 80073C00 00240400 */  sll        $a0, $a0, 16
    /* B404 80073C04 FDFA020C */  jal        vs_battle_getStateFlag
    /* B408 80073C08 03240400 */   sra       $a0, $a0, 16
    /* B40C 80073C0C FF004230 */  andi       $v0, $v0, 0xFF
    /* B410 80073C10 03004010 */  beqz       $v0, .L80073C20
    /* B414 80073C14 00000000 */   nop
    /* B418 80073C18 080000A2 */  sb         $zero, 0x8($s0)
    /* B41C 80073C1C 03001124 */  addiu      $s1, $zero, 0x3
  .L80073C20:
    /* B420 80073C20 14002012 */  beqz       $s1, .L80073C74
    /* B424 80073C24 02000224 */   addiu     $v0, $zero, 0x2
    /* B428 80073C28 0A002216 */  bne        $s1, $v0, .L80073C54
    /* B42C 80073C2C 00000000 */   nop
    /* B430 80073C30 0C000586 */  lh         $a1, 0xC($s0)
    /* B434 80073C34 00000000 */  nop
    /* B438 80073C38 D201A228 */  slti       $v0, $a1, 0x1D2
    /* B43C 80073C3C 02004014 */  bnez       $v0, .L80073C48
    /* B440 80073C40 07001224 */   addiu     $s2, $zero, 0x7
    /* B444 80073C44 09001224 */  addiu      $s2, $zero, 0x9
  .L80073C48:
    /* B448 80073C48 21204002 */  addu       $a0, $s2, $zero
    /* B44C 80073C4C AE2C030C */  jal        vs_battle_displaySceneMessage
    /* B450 80073C50 01000624 */   addiu     $a2, $zero, 0x1
  .L80073C54:
    /* B454 80073C54 21200000 */  addu       $a0, $zero, $zero
    /* B458 80073C58 1000A527 */  addiu      $a1, $sp, 0x10
    /* B45C 80073C5C 1C78020C */  jal        func_8009E070
    /* B460 80073C60 05000624 */   addiu     $a2, $zero, 0x5
    /* B464 80073C64 AF2F020C */  jal        func_8008BEBC
    /* B468 80073C68 21200002 */   addu      $a0, $s0, $zero
    /* B46C 80073C6C 46CF0108 */  j          .L80073D18
    /* B470 80073C70 21100000 */   addu      $v0, $zero, $zero
  .L80073C74:
    /* B474 80073C74 08000292 */  lbu        $v0, 0x8($s0)
    /* B478 80073C78 00000000 */  nop
    /* B47C 80073C7C 1D004010 */  beqz       $v0, .L80073CF4
    /* B480 80073C80 21184000 */   addu      $v1, $v0, $zero
    /* B484 80073C84 02000224 */  addiu      $v0, $zero, 0x2
    /* B488 80073C88 13006210 */  beq        $v1, $v0, .L80073CD8
    /* B48C 80073C8C 03006228 */   slti      $v0, $v1, 0x3
    /* B490 80073C90 05004010 */  beqz       $v0, .L80073CA8
    /* B494 80073C94 01000224 */   addiu     $v0, $zero, 0x1
    /* B498 80073C98 08006210 */  beq        $v1, $v0, .L80073CBC
    /* B49C 80073C9C 21204002 */   addu      $a0, $s2, $zero
    /* B4A0 80073CA0 3ACF0108 */  j          .L80073CE8
    /* B4A4 80073CA4 00000000 */   nop
  .L80073CA8:
    /* B4A8 80073CA8 03000224 */  addiu      $v0, $zero, 0x3
    /* B4AC 80073CAC 0C006210 */  beq        $v1, $v0, .L80073CE0
    /* B4B0 80073CB0 21204002 */   addu      $a0, $s2, $zero
    /* B4B4 80073CB4 3ACF0108 */  j          .L80073CE8
    /* B4B8 80073CB8 00000000 */   nop
  .L80073CBC:
    /* B4BC 80073CBC 0C000286 */  lh         $v0, 0xC($s0)
    /* B4C0 80073CC0 00000000 */  nop
    /* B4C4 80073CC4 D2014228 */  slti       $v0, $v0, 0x1D2
    /* B4C8 80073CC8 06004014 */  bnez       $v0, .L80073CE4
    /* B4CC 80073CCC 06001224 */   addiu     $s2, $zero, 0x6
    /* B4D0 80073CD0 39CF0108 */  j          .L80073CE4
    /* B4D4 80073CD4 08001224 */   addiu     $s2, $zero, 0x8
  .L80073CD8:
    /* B4D8 80073CD8 39CF0108 */  j          .L80073CE4
    /* B4DC 80073CDC 05001224 */   addiu     $s2, $zero, 0x5
  .L80073CE0:
    /* B4E0 80073CE0 0A001224 */  addiu      $s2, $zero, 0xA
  .L80073CE4:
    /* B4E4 80073CE4 21204002 */  addu       $a0, $s2, $zero
  .L80073CE8:
    /* B4E8 80073CE8 0C000586 */  lh         $a1, 0xC($s0)
    /* B4EC 80073CEC AE2C030C */  jal        vs_battle_displaySceneMessage
    /* B4F0 80073CF0 01000624 */   addiu     $a2, $zero, 0x1
  .L80073CF4:
    /* B4F4 80073CF4 7E000424 */  addiu      $a0, $zero, 0x7E
    /* B4F8 80073CF8 6216010C */  jal        vs_main_playSfxDefault
    /* B4FC 80073CFC 65000524 */   addiu     $a1, $zero, 0x65
    /* B500 80073D00 7E000424 */  addiu      $a0, $zero, 0x7E
    /* B504 80073D04 6216010C */  jal        vs_main_playSfxDefault
    /* B508 80073D08 66000524 */   addiu     $a1, $zero, 0x66
    /* B50C 80073D0C 7179020C */  jal        func_8009E5C4
    /* B510 80073D10 21200000 */   addu      $a0, $zero, $zero
    /* B514 80073D14 21100000 */  addu       $v0, $zero, $zero
  .L80073D18:
    /* B518 80073D18 2400BF8F */  lw         $ra, 0x24($sp)
    /* B51C 80073D1C 2000B28F */  lw         $s2, 0x20($sp)
    /* B520 80073D20 1C00B18F */  lw         $s1, 0x1C($sp)
    /* B524 80073D24 1800B08F */  lw         $s0, 0x18($sp)
    /* B528 80073D28 0800E003 */  jr         $ra
    /* B52C 80073D2C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80073AFC
