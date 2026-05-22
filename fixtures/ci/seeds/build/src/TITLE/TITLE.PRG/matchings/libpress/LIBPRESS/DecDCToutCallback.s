nonmatching DecDCToutCallback, 0x24

glabel DecDCToutCallback
    /* 982C 8007202C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 9830 80072030 1000BFAF */  sw         $ra, 0x10($sp)
    /* 9834 80072034 21288000 */  addu       $a1, $a0, $zero
    /* 9838 80072038 4D7E000C */  jal        DMACallback
    /* 983C 8007203C 01000424 */   addiu     $a0, $zero, 0x1
    /* 9840 80072040 1000BF8F */  lw         $ra, 0x10($sp)
    /* 9844 80072044 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 9848 80072048 0800E003 */  jr         $ra
    /* 984C 8007204C 00000000 */   nop
endlabel DecDCToutCallback
