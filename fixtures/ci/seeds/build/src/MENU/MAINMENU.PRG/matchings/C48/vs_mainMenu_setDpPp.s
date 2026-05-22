nonmatching vs_mainMenu_setDpPp, 0x60

glabel vs_mainMenu_setDpPp
    /* 2A08 800FC208 EB51023C */  lui        $v0, (0x51EB851F >> 16)
    /* 2A0C 800FC20C 1F854234 */  ori        $v0, $v0, (0x51EB851F & 0xFFFF)
    /* 2A10 800FC210 63008424 */  addiu      $a0, $a0, 0x63
    /* 2A14 800FC214 18008200 */  mult       $a0, $v0
    /* 2A18 800FC218 10500000 */  mfhi       $t2
    /* 2A1C 800FC21C 6300A524 */  addiu      $a1, $a1, 0x63
    /* 2A20 800FC220 00000000 */  nop
    /* 2A24 800FC224 1800A200 */  mult       $a1, $v0
    /* 2A28 800FC228 1080033C */  lui        $v1, %hi(_currentDp)
    /* 2A2C 800FC22C C3270400 */  sra        $a0, $a0, 31
    /* 2A30 800FC230 1080023C */  lui        $v0, %hi(_currentPp)
    /* 2A34 800FC234 382146A4 */  sh         $a2, %lo(_currentPp)($v0)
    /* 2A38 800FC238 1080023C */  lui        $v0, %hi(_maxPp)
    /* 2A3C 800FC23C 3A2147A4 */  sh         $a3, %lo(_maxPp)($v0)
    /* 2A40 800FC240 43110A00 */  sra        $v0, $t2, 5
    /* 2A44 800FC244 23104400 */  subu       $v0, $v0, $a0
    /* 2A48 800FC248 342162A4 */  sh         $v0, %lo(_currentDp)($v1)
    /* 2A4C 800FC24C 1080033C */  lui        $v1, %hi(_maxDp)
    /* 2A50 800FC250 C32F0500 */  sra        $a1, $a1, 31
    /* 2A54 800FC254 10400000 */  mfhi       $t0
    /* 2A58 800FC258 43110800 */  sra        $v0, $t0, 5
    /* 2A5C 800FC25C 23104500 */  subu       $v0, $v0, $a1
    /* 2A60 800FC260 0800E003 */  jr         $ra
    /* 2A64 800FC264 362162A4 */   sh        $v0, %lo(_maxDp)($v1)
endlabel vs_mainMenu_setDpPp
