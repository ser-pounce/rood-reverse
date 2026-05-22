nonmatching func_800D65A8, 0x30

glabel func_800D65A8
    /* 6DDA8 800D65A8 FF00A530 */  andi       $a1, $a1, 0xFF
    /* 6DDAC 800D65AC 40100500 */  sll        $v0, $a1, 1
    /* 6DDB0 800D65B0 21104500 */  addu       $v0, $v0, $a1
    /* 6DDB4 800D65B4 80100200 */  sll        $v0, $v0, 2
    /* 6DDB8 800D65B8 21104500 */  addu       $v0, $v0, $a1
    /* 6DDBC 800D65BC 00110200 */  sll        $v0, $v0, 4
    /* 6DDC0 800D65C0 21208200 */  addu       $a0, $a0, $v0
    /* 6DDC4 800D65C4 22008294 */  lhu        $v0, 0x22($a0)
    /* 6DDC8 800D65C8 00000000 */  nop
    /* 6DDCC 800D65CC FCFF4230 */  andi       $v0, $v0, 0xFFFC
    /* 6DDD0 800D65D0 0800E003 */  jr         $ra
    /* 6DDD4 800D65D4 220082A4 */   sh        $v0, 0x22($a0)
endlabel func_800D65A8
