nonmatching func_80074860, 0x58

glabel func_80074860
    /* C060 80074860 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* C064 80074864 1000A527 */  addiu      $a1, $sp, 0x10
    /* C068 80074868 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* C06C 8007486C 4284020C */  jal        func_800A1108
    /* C070 80074870 2800B0AF */   sw        $s0, 0x28($sp)
    /* C074 80074874 1000A427 */  addiu      $a0, $sp, 0x10
    /* C078 80074878 2000B027 */  addiu      $s0, $sp, 0x20
    /* C07C 8007487C E6D1010C */  jal        func_80074798
    /* C080 80074880 21280002 */   addu      $a1, $s0, $zero
    /* C084 80074884 04000424 */  addiu      $a0, $zero, 0x4
    /* C088 80074888 21280000 */  addu       $a1, $zero, $zero
    /* C08C 8007488C 21300002 */  addu       $a2, $s0, $zero
    /* C090 80074890 16FB020C */  jal        func_800BEC58
    /* C094 80074894 01000724 */   addiu     $a3, $zero, 0x1
    /* C098 80074898 00140200 */  sll        $v0, $v0, 16
    /* C09C 8007489C 03140200 */  sra        $v0, $v0, 16
    /* C0A0 800748A0 01004238 */  xori       $v0, $v0, 0x1
    /* C0A4 800748A4 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* C0A8 800748A8 2800B08F */  lw         $s0, 0x28($sp)
    /* C0AC 800748AC 0100422C */  sltiu      $v0, $v0, 0x1
    /* C0B0 800748B0 0800E003 */  jr         $ra
    /* C0B4 800748B4 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_80074860
