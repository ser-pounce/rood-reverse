/* Handwritten function */
nonmatching RotTransPers, 0x2C

glabel RotTransPers
    /* 32014 80041814 000080C8 */  lwc2       $0, 0x0($a0)
    /* 32018 80041818 040081C8 */  lwc2       $1, 0x4($a0)
    /* 3201C 8004181C 00000000 */  nop
    /* 32020 80041820 0100184A */  rtps
    /* 32024 80041824 0000AEE8 */  swc2       $14, 0x0($a1)
    /* 32028 80041828 0000C8E8 */  swc2       $8, 0x0($a2)
    /* 3202C 8004182C 00F84348 */  cfc2       $v1, $31 /* handwritten instruction */
    /* 32030 80041830 00980248 */  mfc2       $v0, $19 /* handwritten instruction */
    /* 32034 80041834 0000E3AC */  sw         $v1, 0x0($a3)
    /* 32038 80041838 0800E003 */  jr         $ra
    /* 3203C 8004183C 83100200 */   sra       $v0, $v0, 2
endlabel RotTransPers
