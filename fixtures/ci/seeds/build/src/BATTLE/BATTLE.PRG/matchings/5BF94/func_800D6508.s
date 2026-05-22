nonmatching func_800D6508, 0x30

glabel func_800D6508
    /* 6DD08 800D6508 FF00A530 */  andi       $a1, $a1, 0xFF
    /* 6DD0C 800D650C 40100500 */  sll        $v0, $a1, 1
    /* 6DD10 800D6510 21104500 */  addu       $v0, $v0, $a1
    /* 6DD14 800D6514 80100200 */  sll        $v0, $v0, 2
    /* 6DD18 800D6518 21104500 */  addu       $v0, $v0, $a1
    /* 6DD1C 800D651C 00110200 */  sll        $v0, $v0, 4
    /* 6DD20 800D6520 21208200 */  addu       $a0, $a0, $v0
    /* 6DD24 800D6524 22008294 */  lhu        $v0, 0x22($a0)
    /* 6DD28 800D6528 00000000 */  nop
    /* 6DD2C 800D652C 04004234 */  ori        $v0, $v0, 0x4
    /* 6DD30 800D6530 0800E003 */  jr         $ra
    /* 6DD34 800D6534 220082A4 */   sh        $v0, 0x22($a0)
endlabel func_800D6508
