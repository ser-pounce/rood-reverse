nonmatching func_800D487C, 0x28

glabel func_800D487C
    /* 6C07C 800D487C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C080 800D4880 21288000 */  addu       $a1, $a0, $zero
    /* 6C084 800D4884 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6C088 800D4888 500DA48C */  lw         $a0, 0xD50($a1)
    /* 6C08C 800D488C B751030C */  jal        func_800D46DC
    /* 6C090 800D4890 0100842C */   sltiu     $a0, $a0, 0x1
    /* 6C094 800D4894 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6C098 800D4898 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C09C 800D489C 0800E003 */  jr         $ra
    /* 6C0A0 800D48A0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D487C
