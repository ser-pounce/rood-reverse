nonmatching func_80091998, 0x40

glabel func_80091998
    /* 29198 80091998 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2919C 8009199C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 291A0 800919A0 5746020C */  jal        func_8009195C
    /* 291A4 800919A4 00000000 */   nop
    /* 291A8 800919A8 21284000 */  addu       $a1, $v0, $zero
    /* 291AC 800919AC 0600A010 */  beqz       $a1, .L800919C8
    /* 291B0 800919B0 21100000 */   addu      $v0, $zero, $zero
    /* 291B4 800919B4 01000224 */  addiu      $v0, $zero, 0x1
    /* 291B8 800919B8 0000A38C */  lw         $v1, 0x0($a1)
    /* 291BC 800919BC FFFE0424 */  addiu      $a0, $zero, -0x101
    /* 291C0 800919C0 24186400 */  and        $v1, $v1, $a0
    /* 291C4 800919C4 0000A3AC */  sw         $v1, 0x0($a1)
  .L800919C8:
    /* 291C8 800919C8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 291CC 800919CC 00000000 */  nop
    /* 291D0 800919D0 0800E003 */  jr         $ra
    /* 291D4 800919D4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80091998
