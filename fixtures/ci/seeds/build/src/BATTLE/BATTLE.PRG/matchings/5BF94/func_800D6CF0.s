nonmatching func_800D6CF0, 0x34

glabel func_800D6CF0
    /* 6E4F0 800D6CF0 0F80023C */  lui        $v0, %hi(D_800F569C)
    /* 6E4F4 800D6CF4 160085A0 */  sb         $a1, 0x16($a0)
    /* 6E4F8 800D6CF8 9C56428C */  lw         $v0, %lo(D_800F569C)($v0)
    /* 6E4FC 800D6CFC 00000000 */  nop
    /* 6E500 800D6D00 B000428C */  lw         $v0, 0xB0($v0)
    /* 6E504 800D6D04 40300600 */  sll        $a2, $a2, 1
    /* 6E508 800D6D08 2130C200 */  addu       $a2, $a2, $v0
    /* 6E50C 800D6D0C 0400C394 */  lhu        $v1, 0x4($a2)
    /* 6E510 800D6D10 0E0080A4 */  sh         $zero, 0xE($a0)
    /* 6E514 800D6D14 060080A0 */  sb         $zero, 0x6($a0)
    /* 6E518 800D6D18 21104300 */  addu       $v0, $v0, $v1
    /* 6E51C 800D6D1C 0800E003 */  jr         $ra
    /* 6E520 800D6D20 180082AC */   sw        $v0, 0x18($a0)
endlabel func_800D6CF0
