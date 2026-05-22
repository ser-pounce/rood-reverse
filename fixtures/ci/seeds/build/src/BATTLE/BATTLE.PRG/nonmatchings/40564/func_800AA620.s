nonmatching func_800AA620, 0x78

glabel func_800AA620
    /* 41E20 800AA620 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 41E24 800AA624 0F80033C */  lui        $v1, %hi(D_800F4538)
    /* 41E28 800AA628 38456324 */  addiu      $v1, $v1, %lo(D_800F4538)
    /* 41E2C 800AA62C 80100400 */  sll        $v0, $a0, 2
    /* 41E30 800AA630 21104300 */  addu       $v0, $v0, $v1
    /* 41E34 800AA634 1800BFAF */  sw         $ra, 0x18($sp)
    /* 41E38 800AA638 0000478C */  lw         $a3, 0x0($v0)
    /* 41E3C 800AA63C 00000000 */  nop
    /* 41E40 800AA640 1100E010 */  beqz       $a3, .L800AA688
    /* 41E44 800AA644 00000000 */   nop
    /* 41E48 800AA648 0000A294 */  lhu        $v0, 0x0($a1)
    /* 41E4C 800AA64C 1C00E394 */  lhu        $v1, 0x1C($a3)
    /* 41E50 800AA650 00000000 */  nop
    /* 41E54 800AA654 23104300 */  subu       $v0, $v0, $v1
    /* 41E58 800AA658 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 41E5C 800AA65C 0200A294 */  lhu        $v0, 0x2($a1)
    /* 41E60 800AA660 1E00E394 */  lhu        $v1, 0x1E($a3)
    /* 41E64 800AA664 00000000 */  nop
    /* 41E68 800AA668 23104300 */  subu       $v0, $v0, $v1
    /* 41E6C 800AA66C 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 41E70 800AA670 0400A294 */  lhu        $v0, 0x4($a1)
    /* 41E74 800AA674 2000E394 */  lhu        $v1, 0x20($a3)
    /* 41E78 800AA678 1000A527 */  addiu      $a1, $sp, 0x10
    /* 41E7C 800AA67C 23104300 */  subu       $v0, $v0, $v1
    /* 41E80 800AA680 A6A9020C */  jal        func_800AA698
    /* 41E84 800AA684 1400A2A7 */   sh        $v0, 0x14($sp)
  .L800AA688:
    /* 41E88 800AA688 1800BF8F */  lw         $ra, 0x18($sp)
    /* 41E8C 800AA68C 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 41E90 800AA690 0800E003 */  jr         $ra
    /* 41E94 800AA694 00000000 */   nop
endlabel func_800AA620
