nonmatching func_800B653C, 0x44

glabel func_800B653C
    /* 4DD3C 800B653C 03000C34 */  ori        $t4, $zero, 0x3
  .L800B6540:
    /* 4DD40 800B6540 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 4DD44 800B6544 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 4DD48 800B6548 80180400 */  sll        $v1, $a0, 2
    /* 4DD4C 800B654C 21104300 */  addu       $v0, $v0, $v1
    /* 4DD50 800B6550 0000428C */  lw         $v0, 0x0($v0)
    /* 4DD54 800B6554 0000AA8C */  lw         $t2, 0x0($a1)
    /* 4DD58 800B6558 0400AB8C */  lw         $t3, 0x4($a1)
    /* 4DD5C 800B655C 501846AC */  sw         $a2, 0x1850($v0)
    /* 4DD60 800B6560 0A004980 */  lb         $t1, 0xA($v0)
    /* 4DD64 800B6564 4E1847A4 */  sh         $a3, 0x184E($v0)
    /* 4DD68 800B6568 58184AAC */  sw         $t2, 0x1858($v0)
    /* 4DD6C 800B656C 5C184BAC */  sw         $t3, 0x185C($v0)
    /* 4DD70 800B6570 20002935 */  ori        $t1, $t1, 0x20
    /* 4DD74 800B6574 0A0049A0 */  sb         $t1, 0xA($v0)
    /* 4DD78 800B6578 48184CAC */  sw         $t4, 0x1848($v0)
    /* 4DD7C 800B657C 0800E003 */  jr         $ra
endlabel func_800B653C
