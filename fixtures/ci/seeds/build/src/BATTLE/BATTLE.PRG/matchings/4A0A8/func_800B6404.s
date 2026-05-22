nonmatching func_800B6404, 0x34

glabel func_800B6404
    /* 4DC04 800B6404 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 4DC08 800B6408 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 4DC0C 800B640C 80180400 */  sll        $v1, $a0, 2
    /* 4DC10 800B6410 21104300 */  addu       $v0, $v0, $v1
    /* 4DC14 800B6414 0000428C */  lw         $v0, 0x0($v0)
    /* 4DC18 800B6418 00000000 */  nop
    /* 4DC1C 800B641C 0A004380 */  lb         $v1, 0xA($v0)
    /* 4DC20 800B6420 00000000 */  nop
  .L800B6424:
    /* 4DC24 800B6424 9F006330 */  andi       $v1, $v1, 0x9F
    /* 4DC28 800B6428 40006334 */  ori        $v1, $v1, 0x40
    /* 4DC2C 800B642C 0A0043A0 */  sb         $v1, 0xA($v0)
    /* 4DC30 800B6430 FAD80208 */  j          .L800B63E8
    /* 4DC34 800B6434 00000000 */   nop
endlabel func_800B6404
