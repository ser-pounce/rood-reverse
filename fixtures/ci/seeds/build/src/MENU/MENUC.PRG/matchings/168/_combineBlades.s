nonmatching _combineBlades, 0x2E4

glabel _combineBlades
    /* 8AB4 8010B2B4 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 8AB8 8010B2B8 2800B4AF */  sw         $s4, 0x28($sp)
    /* 8ABC 8010B2BC 21A08000 */  addu       $s4, $a0, $zero
    /* 8AC0 8010B2C0 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 8AC4 8010B2C4 21A8A000 */  addu       $s5, $a1, $zero
    /* 8AC8 8010B2C8 2400B3AF */  sw         $s3, 0x24($sp)
    /* 8ACC 8010B2CC 2198C000 */  addu       $s3, $a2, $zero
    /* 8AD0 8010B2D0 21206002 */  addu       $a0, $s3, $zero
    /* 8AD4 8010B2D4 21288002 */  addu       $a1, $s4, $zero
    /* 8AD8 8010B2D8 2C000624 */  addiu      $a2, $zero, 0x2C
    /* 8ADC 8010B2DC 3000BFAF */  sw         $ra, 0x30($sp)
    /* 8AE0 8010B2E0 2000B2AF */  sw         $s2, 0x20($sp)
    /* 8AE4 8010B2E4 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 8AE8 8010B2E8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 8AEC 8010B2EC 0000E28C */  lw         $v0, 0x0($a3)
    /* 8AF0 8010B2F0 1180123C */  lui        $s2, %hi(_combinationResults)
    /* 8AF4 8010B2F4 2110E200 */  addu       $v0, $a3, $v0
    /* 8AF8 8010B2F8 80BD42AE */  sw         $v0, %lo(_combinationResults)($s2)
    /* 8AFC 8010B2FC 0400E28C */  lw         $v0, 0x4($a3)
    /* 8B00 8010B300 1180103C */  lui        $s0, %hi(_materialResults)
    /* 8B04 8010B304 2110E200 */  addu       $v0, $a3, $v0
    /* 8B08 8010B308 84BD02AE */  sw         $v0, %lo(_materialResults)($s0)
    /* 8B0C 8010B30C 0800E28C */  lw         $v0, 0x8($a3)
    /* 8B10 8010B310 1180113C */  lui        $s1, %hi(_bladeCombinationInitData)
    /* 8B14 8010B314 2138E200 */  addu       $a3, $a3, $v0
    /* 8B18 8010B318 2C24010C */  jal        vs_main_memcpy
    /* 8B1C 8010B31C 88BD27AE */   sw        $a3, %lo(_bladeCombinationInitData)($s1)
    /* 8B20 8010B320 03008292 */  lbu        $v0, 0x3($s4)
    /* 8B24 8010B324 28008496 */  lhu        $a0, 0x28($s4)
    /* 8B28 8010B328 40180200 */  sll        $v1, $v0, 1
    /* 8B2C 8010B32C 21186200 */  addu       $v1, $v1, $v0
    /* 8B30 8010B330 C0180300 */  sll        $v1, $v1, 3
    /* 8B34 8010B334 21186200 */  addu       $v1, $v1, $v0
    /* 8B38 8010B338 40180300 */  sll        $v1, $v1, 1
    /* 8B3C 8010B33C 40110400 */  sll        $v0, $a0, 5
    /* 8B40 8010B340 23104400 */  subu       $v0, $v0, $a0
    /* 8B44 8010B344 80100200 */  sll        $v0, $v0, 2
    /* 8B48 8010B348 21104400 */  addu       $v0, $v0, $a0
    /* 8B4C 8010B34C 80100200 */  sll        $v0, $v0, 2
    /* 8B50 8010B350 2800A496 */  lhu        $a0, 0x28($s5)
    /* 8B54 8010B354 21186200 */  addu       $v1, $v1, $v0
    /* 8B58 8010B358 80100400 */  sll        $v0, $a0, 2
    /* 8B5C 8010B35C 21104400 */  addu       $v0, $v0, $a0
    /* 8B60 8010B360 40100200 */  sll        $v0, $v0, 1
    /* 8B64 8010B364 21186200 */  addu       $v1, $v1, $v0
    /* 8B68 8010B368 0300A292 */  lbu        $v0, 0x3($s5)
    /* 8B6C 8010B36C 84BD048E */  lw         $a0, %lo(_materialResults)($s0)
    /* 8B70 8010B370 21186200 */  addu       $v1, $v1, $v0
    /* 8B74 8010B374 21186400 */  addu       $v1, $v1, $a0
    /* 8B78 8010B378 06FA6290 */  lbu        $v0, -0x5FA($v1)
    /* 8B7C 8010B37C 00000000 */  nop
    /* 8B80 8010B380 280062A6 */  sh         $v0, 0x28($s3)
    /* 8B84 8010B384 00008392 */  lbu        $v1, 0x0($s4)
    /* 8B88 8010B388 0000A492 */  lbu        $a0, 0x0($s5)
    /* 8B8C 8010B38C 40100300 */  sll        $v0, $v1, 1
    /* 8B90 8010B390 21104300 */  addu       $v0, $v0, $v1
    /* 8B94 8010B394 40110200 */  sll        $v0, $v0, 5
    /* 8B98 8010B398 80BD438E */  lw         $v1, %lo(_combinationResults)($s2)
    /* 8B9C 8010B39C 21104400 */  addu       $v0, $v0, $a0
    /* 8BA0 8010B3A0 21186200 */  addu       $v1, $v1, $v0
    /* 8BA4 8010B3A4 00006290 */  lbu        $v0, 0x0($v1)
    /* 8BA8 8010B3A8 00000000 */  nop
    /* 8BAC 8010B3AC 010062A2 */  sb         $v0, 0x1($s3)
    /* 8BB0 8010B3B0 000062A2 */  sb         $v0, 0x0($s3)
    /* 8BB4 8010B3B4 FF004230 */  andi       $v0, $v0, 0xFF
    /* 8BB8 8010B3B8 88BD248E */  lw         $a0, %lo(_bladeCombinationInitData)($s1)
    /* 8BBC 8010B3BC 00110200 */  sll        $v0, $v0, 4
    /* 8BC0 8010B3C0 21208200 */  addu       $a0, $a0, $v0
    /* 8BC4 8010B3C4 01008290 */  lbu        $v0, 0x1($a0)
    /* 8BC8 8010B3C8 00000000 */  nop
    /* 8BCC 8010B3CC 020062A2 */  sb         $v0, 0x2($s3)
    /* 8BD0 8010B3D0 02008290 */  lbu        $v0, 0x2($a0)
    /* 8BD4 8010B3D4 00000000 */  nop
    /* 8BD8 8010B3D8 030062A2 */  sb         $v0, 0x3($s3)
    /* 8BDC 8010B3DC 05008290 */  lbu        $v0, 0x5($a0)
    /* 8BE0 8010B3E0 00000000 */  nop
    /* 8BE4 8010B3E4 0F0062A2 */  sb         $v0, 0xF($s3)
    /* 8BE8 8010B3E8 03008390 */  lbu        $v1, 0x3($a0)
    /* 8BEC 8010B3EC 10006296 */  lhu        $v0, 0x10($s3)
    /* 8BF0 8010B3F0 03006330 */  andi       $v1, $v1, 0x3
    /* 8BF4 8010B3F4 FCFF4230 */  andi       $v0, $v0, 0xFFFC
    /* 8BF8 8010B3F8 25104300 */  or         $v0, $v0, $v1
    /* 8BFC 8010B3FC 100062A6 */  sh         $v0, 0x10($s3)
    /* 8C00 8010B400 04008390 */  lbu        $v1, 0x4($a0)
    /* 8C04 8010B404 E3FF4230 */  andi       $v0, $v0, 0xFFE3
    /* 8C08 8010B408 07006330 */  andi       $v1, $v1, 0x7
    /* 8C0C 8010B40C 80180300 */  sll        $v1, $v1, 2
    /* 8C10 8010B410 25104300 */  or         $v0, $v0, $v1
    /* 8C14 8010B414 100062A6 */  sh         $v0, 0x10($s3)
    /* 8C18 8010B418 06008290 */  lbu        $v0, 0x6($a0)
    /* 8C1C 8010B41C 0580063C */  lui        $a2, %hi(vs_main_materialModifiers)
    /* 8C20 8010B420 120062A6 */  sh         $v0, 0x12($s3)
    /* 8C24 8010B424 0F008888 */  lwl        $t0, 0xF($a0)
    /* 8C28 8010B428 0C008898 */  lwr        $t0, 0xC($a0)
    /* 8C2C 8010B42C 00000000 */  nop
    /* 8C30 8010B430 170068AA */  swl        $t0, 0x17($s3)
    /* 8C34 8010B434 140068BA */  swr        $t0, 0x14($s3)
    /* 8C38 8010B438 28006396 */  lhu        $v1, 0x28($s3)
    /* 8C3C 8010B43C DCEDC624 */  addiu      $a2, $a2, %lo(vs_main_materialModifiers)
    /* 8C40 8010B440 00110300 */  sll        $v0, $v1, 4
    /* 8C44 8010B444 23104300 */  subu       $v0, $v0, $v1
    /* 8C48 8010B448 40100200 */  sll        $v0, $v0, 1
    /* 8C4C 8010B44C 21104600 */  addu       $v0, $v0, $a2
    /* 8C50 8010B450 08008390 */  lbu        $v1, 0x8($a0)
    /* 8C54 8010B454 18004290 */  lbu        $v0, 0x18($v0)
    /* 8C58 8010B458 00000000 */  nop
    /* 8C5C 8010B45C 21186200 */  addu       $v1, $v1, $v0
    /* 8C60 8010B460 0C0063A2 */  sb         $v1, 0xC($s3)
    /* 8C64 8010B464 28006396 */  lhu        $v1, 0x28($s3)
    /* 8C68 8010B468 00000000 */  nop
    /* 8C6C 8010B46C 00110300 */  sll        $v0, $v1, 4
    /* 8C70 8010B470 23104300 */  subu       $v0, $v0, $v1
    /* 8C74 8010B474 40100200 */  sll        $v0, $v0, 1
    /* 8C78 8010B478 21104600 */  addu       $v0, $v0, $a2
    /* 8C7C 8010B47C 09008390 */  lbu        $v1, 0x9($a0)
    /* 8C80 8010B480 1A004290 */  lbu        $v0, 0x1A($v0)
    /* 8C84 8010B484 28006596 */  lhu        $a1, 0x28($s3)
    /* 8C88 8010B488 21186200 */  addu       $v1, $v1, $v0
    /* 8C8C 8010B48C 00110500 */  sll        $v0, $a1, 4
    /* 8C90 8010B490 23104500 */  subu       $v0, $v0, $a1
    /* 8C94 8010B494 40100200 */  sll        $v0, $v0, 1
    /* 8C98 8010B498 21104600 */  addu       $v0, $v0, $a2
    /* 8C9C 8010B49C 0D0063A2 */  sb         $v1, 0xD($s3)
    /* 8CA0 8010B4A0 0A008390 */  lbu        $v1, 0xA($a0)
    /* 8CA4 8010B4A4 1C004290 */  lbu        $v0, 0x1C($v0)
    /* 8CA8 8010B4A8 00000000 */  nop
    /* 8CAC 8010B4AC 21186200 */  addu       $v1, $v1, $v0
    /* 8CB0 8010B4B0 0E0063A2 */  sb         $v1, 0xE($s3)
    /* 8CB4 8010B4B4 04008296 */  lhu        $v0, 0x4($s4)
    /* 8CB8 8010B4B8 0400A396 */  lhu        $v1, 0x4($s5)
    /* 8CBC 8010B4BC 00000000 */  nop
    /* 8CC0 8010B4C0 21104300 */  addu       $v0, $v0, $v1
    /* 8CC4 8010B4C4 43100200 */  sra        $v0, $v0, 1
    /* 8CC8 8010B4C8 080062A6 */  sh         $v0, 0x8($s3)
    /* 8CCC 8010B4CC 040062A6 */  sh         $v0, 0x4($s3)
    /* 8CD0 8010B4D0 06008296 */  lhu        $v0, 0x6($s4)
    /* 8CD4 8010B4D4 0600A396 */  lhu        $v1, 0x6($s5)
    /* 8CD8 8010B4D8 00000000 */  nop
    /* 8CDC 8010B4DC 21104300 */  addu       $v0, $v0, $v1
    /* 8CE0 8010B4E0 43100200 */  sra        $v0, $v0, 1
    /* 8CE4 8010B4E4 060062A6 */  sh         $v0, 0x6($s3)
    /* 8CE8 8010B4E8 0A008296 */  lhu        $v0, 0xA($s4)
    /* 8CEC 8010B4EC 0A00A396 */  lhu        $v1, 0xA($s5)
    /* 8CF0 8010B4F0 00000000 */  nop
    /* 8CF4 8010B4F4 21104300 */  addu       $v0, $v0, $v1
    /* 8CF8 8010B4F8 43100200 */  sra        $v0, $v0, 1
    /* 8CFC 8010B4FC 0A0062A6 */  sh         $v0, 0xA($s3)
    /* 8D00 8010B500 28008396 */  lhu        $v1, 0x28($s4)
    /* 8D04 8010B504 2800A296 */  lhu        $v0, 0x28($s5)
    /* 8D08 8010B508 00000000 */  nop
    /* 8D0C 8010B50C 0C006214 */  bne        $v1, $v0, .L8010B540
    /* 8D10 8010B510 18008426 */   addiu     $a0, $s4, 0x18
    /* 8D14 8010B514 1800A526 */  addiu      $a1, $s5, 0x18
    /* 8D18 8010B518 18006626 */  addiu      $a2, $s3, 0x18
    /* 8D1C 8010B51C 21380000 */  addu       $a3, $zero, $zero
    /* 8D20 8010B520 8E2B040C */  jal        _setClassAffinities
    /* 8D24 8010B524 1000A0AF */   sw        $zero, 0x10($sp)
    /* 8D28 8010B528 20008426 */  addiu      $a0, $s4, 0x20
    /* 8D2C 8010B52C 2000A526 */  addiu      $a1, $s5, 0x20
    /* 8D30 8010B530 20006626 */  addiu      $a2, $s3, 0x20
    /* 8D34 8010B534 21380000 */  addu       $a3, $zero, $zero
    /* 8D38 8010B538 5A2D0408 */  j          .L8010B568
    /* 8D3C 8010B53C 01000224 */   addiu     $v0, $zero, 0x1
  .L8010B540:
    /* 8D40 8010B540 1800A526 */  addiu      $a1, $s5, 0x18
    /* 8D44 8010B544 18006626 */  addiu      $a2, $s3, 0x18
    /* 8D48 8010B548 01000724 */  addiu      $a3, $zero, 0x1
    /* 8D4C 8010B54C 8E2B040C */  jal        _setClassAffinities
    /* 8D50 8010B550 1000A0AF */   sw        $zero, 0x10($sp)
    /* 8D54 8010B554 20008426 */  addiu      $a0, $s4, 0x20
    /* 8D58 8010B558 2000A526 */  addiu      $a1, $s5, 0x20
    /* 8D5C 8010B55C 20006626 */  addiu      $a2, $s3, 0x20
    /* 8D60 8010B560 01000724 */  addiu      $a3, $zero, 0x1
    /* 8D64 8010B564 2110E000 */  addu       $v0, $a3, $zero
  .L8010B568:
    /* 8D68 8010B568 8E2B040C */  jal        _setClassAffinities
    /* 8D6C 8010B56C 1000A2AF */   sw        $v0, 0x10($sp)
    /* 8D70 8010B570 21106002 */  addu       $v0, $s3, $zero
    /* 8D74 8010B574 3000BF8F */  lw         $ra, 0x30($sp)
    /* 8D78 8010B578 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 8D7C 8010B57C 2800B48F */  lw         $s4, 0x28($sp)
    /* 8D80 8010B580 2400B38F */  lw         $s3, 0x24($sp)
    /* 8D84 8010B584 2000B28F */  lw         $s2, 0x20($sp)
    /* 8D88 8010B588 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 8D8C 8010B58C 1800B08F */  lw         $s0, 0x18($sp)
    /* 8D90 8010B590 0800E003 */  jr         $ra
    /* 8D94 8010B594 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel _combineBlades
