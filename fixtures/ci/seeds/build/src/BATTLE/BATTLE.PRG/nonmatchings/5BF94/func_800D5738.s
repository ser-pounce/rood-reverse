nonmatching func_800D5738, 0x48

glabel func_800D5738
    /* 6CF38 800D5738 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6CF3C 800D573C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6CF40 800D5740 21808000 */  addu       $s0, $a0, $zero
    /* 6CF44 800D5744 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6CF48 800D5748 06000286 */  lh         $v0, 0x6($s0)
    /* 6CF4C 800D574C 0000038E */  lw         $v1, 0x0($s0)
    /* 6CF50 800D5750 C0100200 */  sll        $v0, $v0, 3
    /* 6CF54 800D5754 21104300 */  addu       $v0, $v0, $v1
    /* 6CF58 800D5758 0400448C */  lw         $a0, 0x4($v0)
    /* 6CF5C 800D575C 00000000 */  nop
    /* 6CF60 800D5760 02210400 */  srl        $a0, $a0, 4
    /* 6CF64 800D5764 B644030C */  jal        func_800D12D8
    /* 6CF68 800D5768 1F008430 */   andi      $a0, $a0, 0x1F
    /* 6CF6C 800D576C 0A0002A6 */  sh         $v0, 0xA($s0)
    /* 6CF70 800D5770 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6CF74 800D5774 1000B08F */  lw         $s0, 0x10($sp)
    /* 6CF78 800D5778 0800E003 */  jr         $ra
    /* 6CF7C 800D577C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D5738
