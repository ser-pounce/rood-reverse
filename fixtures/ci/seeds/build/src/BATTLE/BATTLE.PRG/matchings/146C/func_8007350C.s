nonmatching func_8007350C, 0x20

glabel func_8007350C
    /* AD0C 8007350C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* AD10 80073510 1000BFAF */  sw         $ra, 0x10($sp)
    /* AD14 80073514 73BD010C */  jal        func_8006F5CC
    /* AD18 80073518 00000000 */   nop
    /* AD1C 8007351C 1000BF8F */  lw         $ra, 0x10($sp)
    /* AD20 80073520 00000000 */  nop
    /* AD24 80073524 0800E003 */  jr         $ra
    /* AD28 80073528 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007350C
