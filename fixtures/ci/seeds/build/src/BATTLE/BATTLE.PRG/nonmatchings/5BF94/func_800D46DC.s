nonmatching func_800D46DC, 0x44

glabel func_800D46DC
    /* 6BEDC 800D46DC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6BEE0 800D46E0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6BEE4 800D46E4 2180A000 */  addu       $s0, $a1, $zero
    /* 6BEE8 800D46E8 05008010 */  beqz       $a0, .L800D4700
    /* 6BEEC 800D46EC 1400BFAF */   sw        $ra, 0x14($sp)
    /* 6BEF0 800D46F0 6654030C */  jal        func_800D5198
    /* 6BEF4 800D46F4 21200002 */   addu      $a0, $s0, $zero
    /* 6BEF8 800D46F8 C4510308 */  j          .L800D4710
    /* 6BEFC 800D46FC 0A0002A6 */   sh        $v0, 0xA($s0)
  .L800D4700:
    /* 6BF00 800D4700 0A000296 */  lhu        $v0, 0xA($s0)
    /* 6BF04 800D4704 00000000 */  nop
    /* 6BF08 800D4708 02004224 */  addiu      $v0, $v0, 0x2
    /* 6BF0C 800D470C 0A0002A6 */  sh         $v0, 0xA($s0)
  .L800D4710:
    /* 6BF10 800D4710 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6BF14 800D4714 1000B08F */  lw         $s0, 0x10($sp)
    /* 6BF18 800D4718 0800E003 */  jr         $ra
    /* 6BF1C 800D471C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D46DC
