nonmatching func_800D6418, 0x30

glabel func_800D6418
    /* 6DC18 800D6418 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6DC1C 800D641C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6DC20 800D6420 340D8394 */  lhu        $v1, 0xD34($a0)
    /* 6DC24 800D6424 05000224 */  addiu      $v0, $zero, 0x5
    /* 6DC28 800D6428 03006214 */  bne        $v1, $v0, .L800D6438
    /* 6DC2C 800D642C 00000000 */   nop
    /* 6DC30 800D6430 76B3010C */  jal        func_8006CDD8
    /* 6DC34 800D6434 380D8424 */   addiu     $a0, $a0, 0xD38
  .L800D6438:
    /* 6DC38 800D6438 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6DC3C 800D643C 00000000 */  nop
    /* 6DC40 800D6440 0800E003 */  jr         $ra
    /* 6DC44 800D6444 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D6418
