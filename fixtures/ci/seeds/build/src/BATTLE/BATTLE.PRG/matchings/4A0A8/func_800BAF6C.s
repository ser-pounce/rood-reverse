nonmatching func_800BAF6C, 0xBC

glabel func_800BAF6C
    /* 5276C 800BAF6C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 52770 800BAF70 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 52774 800BAF74 21988000 */  addu       $s3, $a0, $zero
    /* 52778 800BAF78 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5277C 800BAF7C 01001124 */  addiu      $s1, $zero, 0x1
    /* 52780 800BAF80 00240400 */  sll        $a0, $a0, 16
    /* 52784 800BAF84 1800B2AF */  sw         $s2, 0x18($sp)
    /* 52788 800BAF88 03940400 */  sra        $s2, $a0, 16
    /* 5278C 800BAF8C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 52790 800BAF90 1000B0AF */  sw         $s0, 0x10($sp)
    /* 52794 800BAF94 00141100 */  sll        $v0, $s1, 16
  .L800BAF98:
    /* 52798 800BAF98 03840200 */  sra        $s0, $v0, 16
    /* 5279C 800BAF9C D9F3010C */  jal        func_8007CF64
    /* 527A0 800BAFA0 21200002 */   addu      $a0, $s0, $zero
    /* 527A4 800BAFA4 10004010 */  beqz       $v0, .L800BAFE8
    /* 527A8 800BAFA8 01002226 */   addiu     $v0, $s1, 0x1
    /* 527AC 800BAFAC 06004012 */  beqz       $s2, .L800BAFC8
    /* 527B0 800BAFB0 00000000 */   nop
    /* 527B4 800BAFB4 F882020C */  jal        func_800A0BE0
    /* 527B8 800BAFB8 21200002 */   addu      $a0, $s0, $zero
    /* 527BC 800BAFBC 21200002 */  addu       $a0, $s0, $zero
    /* 527C0 800BAFC0 F7EB0208 */  j          .L800BAFDC
    /* 527C4 800BAFC4 01004534 */   ori       $a1, $v0, 0x1
  .L800BAFC8:
    /* 527C8 800BAFC8 F882020C */  jal        func_800A0BE0
    /* 527CC 800BAFCC 21200002 */   addu      $a0, $s0, $zero
    /* 527D0 800BAFD0 21200002 */  addu       $a0, $s0, $zero
    /* 527D4 800BAFD4 FEFF0524 */  addiu      $a1, $zero, -0x2
    /* 527D8 800BAFD8 24284500 */  and        $a1, $v0, $a1
  .L800BAFDC:
    /* 527DC 800BAFDC 1F82020C */  jal        func_800A087C
    /* 527E0 800BAFE0 00000000 */   nop
    /* 527E4 800BAFE4 01002226 */  addiu      $v0, $s1, 0x1
  .L800BAFE8:
    /* 527E8 800BAFE8 21884000 */  addu       $s1, $v0, $zero
    /* 527EC 800BAFEC 00140200 */  sll        $v0, $v0, 16
    /* 527F0 800BAFF0 03140200 */  sra        $v0, $v0, 16
    /* 527F4 800BAFF4 11004228 */  slti       $v0, $v0, 0x11
    /* 527F8 800BAFF8 E7FF4014 */  bnez       $v0, .L800BAF98
    /* 527FC 800BAFFC 00141100 */   sll       $v0, $s1, 16
    /* 52800 800BB000 00241300 */  sll        $a0, $s3, 16
    /* 52804 800BB004 57F4010C */  jal        func_8007D15C
    /* 52808 800BB008 03240400 */   sra       $a0, $a0, 16
    /* 5280C 800BB00C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 52810 800BB010 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 52814 800BB014 1800B28F */  lw         $s2, 0x18($sp)
    /* 52818 800BB018 1400B18F */  lw         $s1, 0x14($sp)
    /* 5281C 800BB01C 1000B08F */  lw         $s0, 0x10($sp)
    /* 52820 800BB020 0800E003 */  jr         $ra
    /* 52824 800BB024 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800BAF6C
