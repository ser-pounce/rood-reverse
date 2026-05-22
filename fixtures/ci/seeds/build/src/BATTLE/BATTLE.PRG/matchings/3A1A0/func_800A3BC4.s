nonmatching func_800A3BC4, 0x3C

glabel func_800A3BC4
    /* 3B3C4 800A3BC4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3B3C8 800A3BC8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3B3CC 800A3BCC 4337020C */  jal        func_8008DD0C
    /* 3B3D0 800A3BD0 00000000 */   nop
    /* 3B3D4 800A3BD4 00140200 */  sll        $v0, $v0, 16
    /* 3B3D8 800A3BD8 03140200 */  sra        $v0, $v0, 16
    /* 3B3DC 800A3BDC 03004010 */  beqz       $v0, .L800A3BEC
    /* 3B3E0 800A3BE0 40140200 */   sll       $v0, $v0, 17
    /* 3B3E4 800A3BE4 FC8E0208 */  j          .L800A3BF0
    /* 3B3E8 800A3BE8 43140200 */   sra       $v0, $v0, 17
  .L800A3BEC:
    /* 3B3EC 800A3BEC 21100000 */  addu       $v0, $zero, $zero
  .L800A3BF0:
    /* 3B3F0 800A3BF0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3B3F4 800A3BF4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 3B3F8 800A3BF8 0800E003 */  jr         $ra
    /* 3B3FC 800A3BFC 00000000 */   nop
endlabel func_800A3BC4
