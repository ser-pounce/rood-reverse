nonmatching func_800D1778, 0x30

glabel func_800D1778
    /* 68F78 800D1778 40130700 */  sll        $v0, $a3, 13
    /* 68F7C 800D177C 1A004600 */  div        $zero, $v0, $a2
    /* 68F80 800D1780 12100000 */  mflo       $v0
    /* 68F84 800D1784 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 68F88 800D1788 2800A78F */  lw         $a3, 0x28($sp)
    /* 68F8C 800D178C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 68F90 800D1790 A745030C */  jal        func_800D169C
    /* 68F94 800D1794 21304000 */   addu      $a2, $v0, $zero
    /* 68F98 800D1798 1000BF8F */  lw         $ra, 0x10($sp)
    /* 68F9C 800D179C 00000000 */  nop
    /* 68FA0 800D17A0 0800E003 */  jr         $ra
    /* 68FA4 800D17A4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D1778
