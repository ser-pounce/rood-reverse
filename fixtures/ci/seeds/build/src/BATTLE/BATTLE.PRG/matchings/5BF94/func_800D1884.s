nonmatching func_800D1884, 0x30

glabel func_800D1884
    /* 69084 800D1884 40130700 */  sll        $v0, $a3, 13
    /* 69088 800D1888 1A004600 */  div        $zero, $v0, $a2
    /* 6908C 800D188C 12100000 */  mflo       $v0
    /* 69090 800D1890 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 69094 800D1894 2800A78F */  lw         $a3, 0x28($sp)
    /* 69098 800D1898 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6909C 800D189C EA45030C */  jal        func_800D17A8
    /* 690A0 800D18A0 21304000 */   addu      $a2, $v0, $zero
    /* 690A4 800D18A4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 690A8 800D18A8 00000000 */  nop
    /* 690AC 800D18AC 0800E003 */  jr         $ra
    /* 690B0 800D18B0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D1884
