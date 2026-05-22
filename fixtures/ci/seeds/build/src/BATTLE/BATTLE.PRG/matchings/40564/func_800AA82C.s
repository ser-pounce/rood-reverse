nonmatching func_800AA82C, 0x24

glabel func_800AA82C
    /* 4202C 800AA82C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 42030 800AA830 1000BFAF */  sw         $ra, 0x10($sp)
    /* 42034 800AA834 002C0500 */  sll        $a1, $a1, 16
    /* 42038 800AA838 61AA020C */  jal        func_800AA984
    /* 4203C 800AA83C 032C0500 */   sra       $a1, $a1, 16
    /* 42040 800AA840 1000BF8F */  lw         $ra, 0x10($sp)
    /* 42044 800AA844 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 42048 800AA848 0800E003 */  jr         $ra
    /* 4204C 800AA84C 00000000 */   nop
endlabel func_800AA82C
