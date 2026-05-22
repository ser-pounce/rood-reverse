nonmatching func_8007CBDC, 0x3C

glabel func_8007CBDC
    /* 143DC 8007CBDC D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 143E0 8007CBE0 07000224 */  addiu      $v0, $zero, 0x7
    /* 143E4 8007CBE4 1000A2A3 */  sb         $v0, 0x10($sp)
    /* 143E8 8007CBE8 02000224 */  addiu      $v0, $zero, 0x2
    /* 143EC 8007CBEC 1100A4A3 */  sb         $a0, 0x11($sp)
    /* 143F0 8007CBF0 1000A427 */  addiu      $a0, $sp, 0x10
    /* 143F4 8007CBF4 2800BFAF */  sw         $ra, 0x28($sp)
    /* 143F8 8007CBF8 1200A5A7 */  sh         $a1, 0x12($sp)
    /* 143FC 8007CBFC 2000A2A3 */  sb         $v0, 0x20($sp)
    /* 14400 8007CC00 7A65020C */  jal        vs_battle_populateDataSlot
    /* 14404 8007CC04 2100A6A3 */   sb        $a2, 0x21($sp)
    /* 14408 8007CC08 2800BF8F */  lw         $ra, 0x28($sp)
    /* 1440C 8007CC0C 00000000 */  nop
    /* 14410 8007CC10 0800E003 */  jr         $ra
    /* 14414 8007CC14 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8007CBDC
