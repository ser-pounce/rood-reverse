nonmatching func_800C64D0, 0x70

glabel func_800C64D0
    /* 5DCD0 800C64D0 21308000 */  addu       $a2, $a0, $zero
    /* 5DCD4 800C64D4 FF00073C */  lui        $a3, (0xFFFFFF >> 16)
    /* 5DCD8 800C64D8 FFFFE734 */  ori        $a3, $a3, (0xFFFFFF & 0xFFFF)
    /* 5DCDC 800C64DC 0000C38C */  lw         $v1, 0x0($a2)
    /* 5DCE0 800C64E0 FCFFC224 */  addiu      $v0, $a2, -0x4
    /* 5DCE4 800C64E4 24404700 */  and        $t0, $v0, $a3
    /* 5DCE8 800C64E8 24106700 */  and        $v0, $v1, $a3
    /* 5DCEC 800C64EC 08004810 */  beq        $v0, $t0, .L800C6510
    /* 5DCF0 800C64F0 0080043C */   lui       $a0, %hi(D_80000000)
    /* 5DCF4 800C64F4 24106700 */  and        $v0, $v1, $a3
  .L800C64F8:
    /* 5DCF8 800C64F8 25304400 */  or         $a2, $v0, $a0
    /* 5DCFC 800C64FC 0000C38C */  lw         $v1, %lo(D_80000000)($a2)
    /* 5DD00 800C6500 00000000 */  nop
    /* 5DD04 800C6504 24106700 */  and        $v0, $v1, $a3
    /* 5DD08 800C6508 FBFF4814 */  bne        $v0, $t0, .L800C64F8
    /* 5DD0C 800C650C 00000000 */   nop
  .L800C6510:
    /* 5DD10 800C6510 00FF043C */  lui        $a0, (0xFF000000 >> 16)
    /* 5DD14 800C6514 0000C28C */  lw         $v0, %lo(D_80000000)($a2)
    /* 5DD18 800C6518 2418A700 */  and        $v1, $a1, $a3
    /* 5DD1C 800C651C 24104400 */  and        $v0, $v0, $a0
    /* 5DD20 800C6520 25104300 */  or         $v0, $v0, $v1
    /* 5DD24 800C6524 0000C2AC */  sw         $v0, %lo(D_80000000)($a2)
    /* 5DD28 800C6528 0000A28C */  lw         $v0, 0x0($a1)
    /* 5DD2C 800C652C 00000000 */  nop
    /* 5DD30 800C6530 24104400 */  and        $v0, $v0, $a0
    /* 5DD34 800C6534 25104800 */  or         $v0, $v0, $t0
    /* 5DD38 800C6538 0800E003 */  jr         $ra
    /* 5DD3C 800C653C 0000A2AC */   sw        $v0, 0x0($a1)
endlabel func_800C64D0
