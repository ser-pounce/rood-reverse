nonmatching vs_main_setCurrentSfx, 0x3C

glabel vs_main_setCurrentSfx
    /* 36884 80046084 FFFF8324 */  addiu      $v1, $a0, -0x1
    /* 36888 80046088 0300622C */  sltiu      $v0, $v1, 0x3
    /* 3688C 8004608C 0A004010 */  beqz       $v0, .L800460B8
    /* 36890 80046090 0680023C */   lui       $v0, %hi(vs_main_soundData)
    /* 36894 80046094 38E04524 */  addiu      $a1, $v0, %lo(vs_main_soundData)
    /* 36898 80046098 80100300 */  sll        $v0, $v1, 2
    /* 3689C 8004609C 21104500 */  addu       $v0, $v0, $a1
    /* 368A0 800460A0 4C00428C */  lw         $v0, 0x4C($v0)
    /* 368A4 800460A4 00000000 */  nop
    /* 368A8 800460A8 03004010 */  beqz       $v0, .L800460B8
    /* 368AC 800460AC 01000224 */   addiu     $v0, $zero, 0x1
    /* 368B0 800460B0 0800E003 */  jr         $ra
    /* 368B4 800460B4 4400A4AC */   sw        $a0, 0x44($a1)
  .L800460B8:
    /* 368B8 800460B8 0800E003 */  jr         $ra
    /* 368BC 800460BC 21100000 */   addu      $v0, $zero, $zero
endlabel vs_main_setCurrentSfx
