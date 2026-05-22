nonmatching func_801033D4, 0x48

glabel func_801033D4
    /* BD4 801033D4 B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* BD8 801033D8 21288000 */  addu       $a1, $a0, $zero
    /* BDC 801033DC 4800B0AF */  sw         $s0, 0x48($sp)
    /* BE0 801033E0 1800B027 */  addiu      $s0, $sp, 0x18
    /* BE4 801033E4 4C00BFAF */  sw         $ra, 0x4C($sp)
    /* BE8 801033E8 B7AE010C */  jal        vs_battle_copyUiAccessoryStats
    /* BEC 801033EC 21200002 */   addu      $a0, $s0, $zero
    /* BF0 801033F0 21200002 */  addu       $a0, $s0, $zero
    /* BF4 801033F4 1000A527 */  addiu      $a1, $sp, 0x10
    /* BF8 801033F8 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* BFC 801033FC 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* C00 80103400 21F4030C */  jal        vs_mainMenu_initUiArmor
    /* C04 80103404 4000A627 */   addiu     $a2, $sp, 0x40
    /* C08 80103408 1400A28F */  lw         $v0, 0x14($sp)
    /* C0C 8010340C 4C00BF8F */  lw         $ra, 0x4C($sp)
    /* C10 80103410 4800B08F */  lw         $s0, 0x48($sp)
    /* C14 80103414 0800E003 */  jr         $ra
    /* C18 80103418 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel func_801033D4
