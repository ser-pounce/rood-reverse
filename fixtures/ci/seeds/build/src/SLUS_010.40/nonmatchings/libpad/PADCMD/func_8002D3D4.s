nonmatching func_8002D3D4, 0xC8

glabel func_8002D3D4
    /* 1DBD4 8002D3D4 E9008290 */  lbu        $v0, 0xE9($a0)
    /* 1DBD8 8002D3D8 00000000 */  nop
    /* 1DBDC 8002D3DC 2B004010 */  beqz       $v0, .L8002D48C
    /* 1DBE0 8002D3E0 21400000 */   addu      $t0, $zero, $zero
    /* 1DBE4 8002D3E4 FF000B24 */  addiu      $t3, $zero, 0xFF
    /* 1DBE8 8002D3E8 21500000 */  addu       $t2, $zero, $zero
  .L8002D3EC:
    /* 1DBEC 8002D3EC 2000858C */  lw         $a1, 0x20($a0)
    /* 1DBF0 8002D3F0 21380000 */  addu       $a3, $zero, $zero
    /* 1DBF4 8002D3F4 05000324 */  addiu      $v1, $zero, 0x5
  .L8002D3F8:
    /* 1DBF8 8002D3F8 0000A290 */  lbu        $v0, 0x0($a1)
    /* 1DBFC 8002D3FC 00000000 */  nop
    /* 1DC00 8002D400 02004814 */  bne        $v0, $t0, .L8002D40C
    /* 1DC04 8002D404 0100A524 */   addiu     $a1, $a1, 0x1
    /* 1DC08 8002D408 0100E724 */  addiu      $a3, $a3, 0x1
  .L8002D40C:
    /* 1DC0C 8002D40C FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 1DC10 8002D410 F9FF6104 */  bgez       $v1, .L8002D3F8
    /* 1DC14 8002D414 00000000 */   nop
    /* 1DC18 8002D418 0400828C */  lw         $v0, 0x4($a0)
    /* 1DC1C 8002D41C 00000000 */  nop
    /* 1DC20 8002D420 21104201 */  addu       $v0, $t2, $v0
    /* 1DC24 8002D424 02004990 */  lbu        $t1, 0x2($v0)
    /* 1DC28 8002D428 2000858C */  lw         $a1, 0x20($a0)
    /* 1DC2C 8002D42C 02002015 */  bnez       $t1, .L8002D438
    /* 1DC30 8002D430 21180000 */   addu      $v1, $zero, $zero
    /* 1DC34 8002D434 01000924 */  addiu      $t1, $zero, 0x1
  .L8002D438:
    /* 1DC38 8002D438 21308000 */  addu       $a2, $a0, $zero
  .L8002D43C:
    /* 1DC3C 8002D43C 0000A290 */  lbu        $v0, 0x0($a1)
    /* 1DC40 8002D440 00000000 */  nop
    /* 1DC44 8002D444 08004814 */  bne        $v0, $t0, .L8002D468
    /* 1DC48 8002D448 0100A524 */   addiu     $a1, $a1, 0x1
    /* 1DC4C 8002D44C 2A10E900 */  slt        $v0, $a3, $t1
    /* 1DC50 8002D450 04004010 */  beqz       $v0, .L8002D464
    /* 1DC54 8002D454 00000000 */   nop
    /* 1DC58 8002D458 5D00CBA0 */  sb         $t3, 0x5D($a2)
    /* 1DC5C 8002D45C 1AB50008 */  j          .L8002D468
    /* 1DC60 8002D460 FFFFE724 */   addiu     $a3, $a3, -0x1
  .L8002D464:
    /* 1DC64 8002D464 5D00C8A0 */  sb         $t0, 0x5D($a2)
  .L8002D468:
    /* 1DC68 8002D468 01006324 */  addiu      $v1, $v1, 0x1
    /* 1DC6C 8002D46C 06006228 */  slti       $v0, $v1, 0x6
    /* 1DC70 8002D470 F2FF4014 */  bnez       $v0, .L8002D43C
    /* 1DC74 8002D474 0100C624 */   addiu     $a2, $a2, 0x1
    /* 1DC78 8002D478 E9008290 */  lbu        $v0, 0xE9($a0)
    /* 1DC7C 8002D47C 01000825 */  addiu      $t0, $t0, 0x1
    /* 1DC80 8002D480 2A100201 */  slt        $v0, $t0, $v0
    /* 1DC84 8002D484 D9FF4014 */  bnez       $v0, .L8002D3EC
    /* 1DC88 8002D488 05004A25 */   addiu     $t2, $t2, 0x5
  .L8002D48C:
    /* 1DC8C 8002D48C FE000224 */  addiu      $v0, $zero, 0xFE
    /* 1DC90 8002D490 460082A0 */  sb         $v0, 0x46($a0)
    /* 1DC94 8002D494 0800E003 */  jr         $ra
    /* 1DC98 8002D498 21100000 */   addu      $v0, $zero, $zero
endlabel func_8002D3D4
