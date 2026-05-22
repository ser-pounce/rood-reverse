nonmatching func_800D5780, 0x7C

glabel func_800D5780
    /* 6CF80 800D5780 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6CF84 800D5784 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6CF88 800D5788 06008284 */  lh         $v0, 0x6($a0)
    /* 6CF8C 800D578C 05008390 */  lbu        $v1, 0x5($a0)
    /* 6CF90 800D5790 01004224 */  addiu      $v0, $v0, 0x1
    /* 6CF94 800D5794 2A104300 */  slt        $v0, $v0, $v1
    /* 6CF98 800D5798 06008394 */  lhu        $v1, 0x6($a0)
    /* 6CF9C 800D579C 03004014 */  bnez       $v0, .L800D57AC
    /* 6CFA0 800D57A0 01006224 */   addiu     $v0, $v1, 0x1
    /* 6CFA4 800D57A4 FB550308 */  j          .L800D57EC
    /* 6CFA8 800D57A8 21100000 */   addu      $v0, $zero, $zero
  .L800D57AC:
    /* 6CFAC 800D57AC 04008390 */  lbu        $v1, 0x4($a0)
    /* 6CFB0 800D57B0 060082A4 */  sh         $v0, 0x6($a0)
    /* 6CFB4 800D57B4 01000224 */  addiu      $v0, $zero, 0x1
    /* 6CFB8 800D57B8 05006210 */  beq        $v1, $v0, .L800D57D0
    /* 6CFBC 800D57BC 0D000224 */   addiu     $v0, $zero, 0xD
    /* 6CFC0 800D57C0 07006210 */  beq        $v1, $v0, .L800D57E0
    /* 6CFC4 800D57C4 01000224 */   addiu     $v0, $zero, 0x1
    /* 6CFC8 800D57C8 FB550308 */  j          .L800D57EC
    /* 6CFCC 800D57CC 00000000 */   nop
  .L800D57D0:
    /* 6CFD0 800D57D0 C055030C */  jal        func_800D5700
    /* 6CFD4 800D57D4 00000000 */   nop
    /* 6CFD8 800D57D8 FB550308 */  j          .L800D57EC
    /* 6CFDC 800D57DC 01000224 */   addiu     $v0, $zero, 0x1
  .L800D57E0:
    /* 6CFE0 800D57E0 CE55030C */  jal        func_800D5738
    /* 6CFE4 800D57E4 00000000 */   nop
    /* 6CFE8 800D57E8 01000224 */  addiu      $v0, $zero, 0x1
  .L800D57EC:
    /* 6CFEC 800D57EC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6CFF0 800D57F0 00000000 */  nop
    /* 6CFF4 800D57F4 0800E003 */  jr         $ra
    /* 6CFF8 800D57F8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D5780
