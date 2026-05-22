nonmatching vs_battle_toBCD, 0x38

glabel vs_battle_toBCD
    /* 64454 800CCC54 6666023C */  lui        $v0, (0x66666667 >> 16)
    /* 64458 800CCC58 67664234 */  ori        $v0, $v0, (0x66666667 & 0xFFFF)
    /* 6445C 800CCC5C 18008200 */  mult       $a0, $v0
    /* 64460 800CCC60 C31F0400 */  sra        $v1, $a0, 31
    /* 64464 800CCC64 10280000 */  mfhi       $a1
    /* 64468 800CCC68 83100500 */  sra        $v0, $a1, 2
    /* 6446C 800CCC6C 23104300 */  subu       $v0, $v0, $v1
    /* 64470 800CCC70 80180200 */  sll        $v1, $v0, 2
    /* 64474 800CCC74 21186200 */  addu       $v1, $v1, $v0
    /* 64478 800CCC78 40180300 */  sll        $v1, $v1, 1
    /* 6447C 800CCC7C 23208300 */  subu       $a0, $a0, $v1
    /* 64480 800CCC80 00110200 */  sll        $v0, $v0, 4
    /* 64484 800CCC84 0800E003 */  jr         $ra
    /* 64488 800CCC88 25108200 */   or        $v0, $a0, $v0
endlabel vs_battle_toBCD
