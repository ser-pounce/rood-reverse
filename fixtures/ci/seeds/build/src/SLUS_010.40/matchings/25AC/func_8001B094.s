nonmatching func_8001B094, 0x38

glabel func_8001B094
    /* B894 8001B094 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* B898 8001B098 1000BFAF */  sw         $ra, 0x10($sp)
    /* B89C 8001B09C 6A0085A4 */  sh         $a1, 0x6A($a0)
    /* B8A0 8001B0A0 00290500 */  sll        $a1, $a1, 4
    /* B8A4 8001B0A4 0380023C */  lui        $v0, %hi(g_InstrumentInfo)
    /* B8A8 8001B0A8 88674224 */  addiu      $v0, $v0, %lo(g_InstrumentInfo)
    /* B8AC 8001B0AC 2128A200 */  addu       $a1, $a1, $v0
    /* B8B0 8001B0B0 0000A68C */  lw         $a2, 0x0($a1)
    /* B8B4 8001B0B4 186C000C */  jal        Sound_CopyInstrumentInfoToChannel
    /* B8B8 8001B0B8 00000000 */   nop
    /* B8BC 8001B0BC 1000BF8F */  lw         $ra, 0x10($sp)
    /* B8C0 8001B0C0 00000000 */  nop
    /* B8C4 8001B0C4 0800E003 */  jr         $ra
    /* B8C8 8001B0C8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001B094
