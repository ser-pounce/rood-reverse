nonmatching func_800B6500, 0x30

glabel func_800B6500
    /* 4DD00 800B6500 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 4DD04 800B6504 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 4DD08 800B6508 80180400 */  sll        $v1, $a0, 2
    /* 4DD0C 800B650C 21104300 */  addu       $v0, $v0, $v1
    /* 4DD10 800B6510 0000428C */  lw         $v0, 0x0($v0)
    /* 4DD14 800B6514 0000AA8C */  lw         $t2, 0x0($a1)
    /* 4DD18 800B6518 0400AB8C */  lw         $t3, 0x4($a1)
    /* 4DD1C 800B651C 58184AAC */  sw         $t2, 0x1858($v0)
    /* 4DD20 800B6520 5C184BAC */  sw         $t3, 0x185C($v0)
    /* 4DD24 800B6524 0A004980 */  lb         $t1, 0xA($v0)
    /* 4DD28 800B6528 3DD90208 */  j          .L800B64F4
    /* 4DD2C 800B652C 02000334 */   ori       $v1, $zero, 0x2
endlabel func_800B6500
