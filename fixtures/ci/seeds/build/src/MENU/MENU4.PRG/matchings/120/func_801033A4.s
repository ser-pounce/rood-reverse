nonmatching func_801033A4, 0x30

glabel func_801033A4
    /* BA4 801033A4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* BA8 801033A8 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* BAC 801033AC 1000A527 */  addiu      $a1, $sp, 0x10
    /* BB0 801033B0 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* BB4 801033B4 2000BFAF */  sw         $ra, 0x20($sp)
    /* BB8 801033B8 B3F3030C */  jal        vs_mainMenu_setUiArmor
    /* BBC 801033BC 1800A627 */   addiu     $a2, $sp, 0x18
    /* BC0 801033C0 1400A28F */  lw         $v0, 0x14($sp)
    /* BC4 801033C4 2000BF8F */  lw         $ra, 0x20($sp)
    /* BC8 801033C8 00000000 */  nop
    /* BCC 801033CC 0800E003 */  jr         $ra
    /* BD0 801033D0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_801033A4
