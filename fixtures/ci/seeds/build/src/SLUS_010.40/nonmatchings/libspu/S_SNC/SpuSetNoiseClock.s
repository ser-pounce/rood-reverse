nonmatching SpuSetNoiseClock, 0x48

glabel SpuSetNoiseClock
    /* EEE4 8001E6E4 21108000 */  addu       $v0, $a0, $zero
    /* EEE8 8001E6E8 06004004 */  bltz       $v0, .L8001E704
    /* EEEC 8001E6EC 21280000 */   addu      $a1, $zero, $zero
    /* EEF0 8001E6F0 21284000 */  addu       $a1, $v0, $zero
    /* EEF4 8001E6F4 4000A228 */  slti       $v0, $a1, 0x40
    /* EEF8 8001E6F8 02004014 */  bnez       $v0, .L8001E704
    /* EEFC 8001E6FC 00000000 */   nop
    /* EF00 8001E700 3F000524 */  addiu      $a1, $zero, 0x3F
  .L8001E704:
    /* EF04 8001E704 0380043C */  lui        $a0, %hi(D_80030860)
    /* EF08 8001E708 6008848C */  lw         $a0, %lo(D_80030860)($a0)
    /* EF0C 8001E70C 3F00A230 */  andi       $v0, $a1, 0x3F
    /* EF10 8001E710 AA018394 */  lhu        $v1, 0x1AA($a0)
    /* EF14 8001E714 00120200 */  sll        $v0, $v0, 8
    /* EF18 8001E718 FFC06330 */  andi       $v1, $v1, 0xC0FF
    /* EF1C 8001E71C 25186200 */  or         $v1, $v1, $v0
    /* EF20 8001E720 2110A000 */  addu       $v0, $a1, $zero
    /* EF24 8001E724 0800E003 */  jr         $ra
    /* EF28 8001E728 AA0183A4 */   sh        $v1, 0x1AA($a0)
endlabel SpuSetNoiseClock
    /* EF2C 8001E72C 00000000 */  nop
    /* EF30 8001E730 00000000 */  nop
