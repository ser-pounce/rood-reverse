nonmatching func_800B9C18, 0x40

glabel func_800B9C18
    /* 51418 800B9C18 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5141C 800B9C1C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51420 800B9C20 01008290 */  lbu        $v0, 0x1($a0)
    /* 51424 800B9C24 00000000 */  nop
    /* 51428 800B9C28 05004010 */  beqz       $v0, .L800B9C40
    /* 5142C 800B9C2C 00000000 */   nop
    /* 51430 800B9C30 41EC010C */  jal        func_8007B104
    /* 51434 800B9C34 00000000 */   nop
    /* 51438 800B9C38 12E70208 */  j          .L800B9C48
    /* 5143C 800B9C3C 00000000 */   nop
  .L800B9C40:
    /* 51440 800B9C40 3FEC010C */  jal        func_8007B0FC
    /* 51444 800B9C44 00000000 */   nop
  .L800B9C48:
    /* 51448 800B9C48 1000BF8F */  lw         $ra, 0x10($sp)
    /* 5144C 800B9C4C 21100000 */  addu       $v0, $zero, $zero
    /* 51450 800B9C50 0800E003 */  jr         $ra
    /* 51454 800B9C54 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B9C18
