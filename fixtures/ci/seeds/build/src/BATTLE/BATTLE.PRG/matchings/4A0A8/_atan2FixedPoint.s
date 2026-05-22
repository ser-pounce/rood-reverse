nonmatching _atan2FixedPoint, 0x24

glabel _atan2FixedPoint
    /* 56078 800BE878 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5607C 800BE87C 83210400 */  sra        $a0, $a0, 6
    /* 56080 800BE880 1000BFAF */  sw         $ra, 0x10($sp)
    /* 56084 800BE884 DF04010C */  jal        ratan2
    /* 56088 800BE888 83290500 */   sra       $a1, $a1, 6
    /* 5608C 800BE88C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 56090 800BE890 00000000 */  nop
    /* 56094 800BE894 0800E003 */  jr         $ra
    /* 56098 800BE898 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _atan2FixedPoint
