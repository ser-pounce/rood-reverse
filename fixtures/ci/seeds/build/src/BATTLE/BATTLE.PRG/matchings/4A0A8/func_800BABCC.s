nonmatching func_800BABCC, 0x6C

glabel func_800BABCC
    /* 523CC 800BABCC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 523D0 800BABD0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 523D4 800BABD4 21808000 */  addu       $s0, $a0, $zero
    /* 523D8 800BABD8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 523DC 800BABDC 80FF020C */  jal        vs_battle_getShort
    /* 523E0 800BABE0 02000426 */   addiu     $a0, $s0, 0x2
    /* 523E4 800BABE4 94FF020C */  jal        func_800BFE50
    /* 523E8 800BABE8 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 523EC 800BABEC 01000392 */  lbu        $v1, 0x1($s0)
    /* 523F0 800BABF0 00000000 */  nop
    /* 523F4 800BABF4 07006010 */  beqz       $v1, .L800BAC14
    /* 523F8 800BABF8 00000000 */   nop
    /* 523FC 800BABFC 04000592 */  lbu        $a1, 0x4($s0)
    /* 52400 800BAC00 00240200 */  sll        $a0, $v0, 16
    /* 52404 800BAC04 20B1010C */  jal        func_8006C480
    /* 52408 800BAC08 03240400 */   sra       $a0, $a0, 16
    /* 5240C 800BAC0C 09EB0208 */  j          .L800BAC24
    /* 52410 800BAC10 00000000 */   nop
  .L800BAC14:
    /* 52414 800BAC14 04000592 */  lbu        $a1, 0x4($s0)
    /* 52418 800BAC18 00240200 */  sll        $a0, $v0, 16
    /* 5241C 800BAC1C 29B1010C */  jal        func_8006C4A4
    /* 52420 800BAC20 03240400 */   sra       $a0, $a0, 16
  .L800BAC24:
    /* 52424 800BAC24 1400BF8F */  lw         $ra, 0x14($sp)
    /* 52428 800BAC28 1000B08F */  lw         $s0, 0x10($sp)
    /* 5242C 800BAC2C 21100000 */  addu       $v0, $zero, $zero
    /* 52430 800BAC30 0800E003 */  jr         $ra
    /* 52434 800BAC34 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BABCC
