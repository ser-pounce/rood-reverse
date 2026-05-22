nonmatching func_800FFF38, 0x84

glabel func_800FFF38
    /* 6738 800FFF38 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 673C 800FFF3C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6740 800FFF40 21808000 */  addu       $s0, $a0, $zero
    /* 6744 800FFF44 0700043C */  lui        $a0, (0x70007 >> 16)
    /* 6748 800FFF48 1400BFAF */  sw         $ra, 0x14($sp)
    /* 674C 800FFF4C 8500030C */  jal        func_800C0214
    /* 6750 800FFF50 07008434 */   ori       $a0, $a0, (0x70007 & 0xFFFF)
    /* 6754 800FFF54 5555033C */  lui        $v1, (0x55555556 >> 16)
    /* 6758 800FFF58 56556334 */  ori        $v1, $v1, (0x55555556 & 0xFFFF)
    /* 675C 800FFF5C 18000302 */  mult       $s0, $v1
    /* 6760 800FFF60 21284000 */  addu       $a1, $v0, $zero
    /* 6764 800FFF64 C31F1000 */  sra        $v1, $s0, 31
    /* 6768 800FFF68 10300000 */  mfhi       $a2
    /* 676C 800FFF6C 2318C300 */  subu       $v1, $a2, $v1
    /* 6770 800FFF70 C0200300 */  sll        $a0, $v1, 3
    /* 6774 800FFF74 D8008424 */  addiu      $a0, $a0, 0xD8
    /* 6778 800FFF78 40100300 */  sll        $v0, $v1, 1
    /* 677C 800FFF7C 21104300 */  addu       $v0, $v0, $v1
    /* 6780 800FFF80 23100202 */  subu       $v0, $s0, $v0
    /* 6784 800FFF84 C0100200 */  sll        $v0, $v0, 3
    /* 6788 800FFF88 C8004224 */  addiu      $v0, $v0, 0xC8
    /* 678C 800FFF8C 00120200 */  sll        $v0, $v0, 8
    /* 6790 800FFF90 25208200 */  or         $a0, $a0, $v0
    /* 6794 800FFF94 02000224 */  addiu      $v0, $zero, 0x2
    /* 6798 800FFF98 02000216 */  bne        $s0, $v0, .L800FFFA4
    /* 679C 800FFF9C F937023C */   lui       $v0, (0x37F90000 >> 16)
    /* 67A0 800FFFA0 FA37023C */  lui        $v0, (0x37FA0000 >> 16)
  .L800FFFA4:
    /* 67A4 800FFFA4 25108200 */  or         $v0, $a0, $v0
    /* 67A8 800FFFA8 1000A2AC */  sw         $v0, 0x10($a1)
    /* 67AC 800FFFAC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 67B0 800FFFB0 1000B08F */  lw         $s0, 0x10($sp)
    /* 67B4 800FFFB4 0800E003 */  jr         $ra
    /* 67B8 800FFFB8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800FFF38
