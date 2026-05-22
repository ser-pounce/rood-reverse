nonmatching func_8008BEBC, 0x8C

glabel func_8008BEBC
    /* 236BC 8008BEBC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 236C0 8008BEC0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 236C4 8008BEC4 21808000 */  addu       $s0, $a0, $zero
    /* 236C8 8008BEC8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 236CC 8008BECC 12000292 */  lbu        $v0, 0x12($s0)
    /* 236D0 8008BED0 00000000 */  nop
    /* 236D4 8008BED4 18004014 */  bnez       $v0, .L8008BF38
    /* 236D8 8008BED8 21100000 */   addu      $v0, $zero, $zero
    /* 236DC 8008BEDC 0C000496 */  lhu        $a0, 0xC($s0)
    /* 236E0 8008BEE0 01000224 */  addiu      $v0, $zero, 0x1
    /* 236E4 8008BEE4 120002A2 */  sb         $v0, 0x12($s0)
    /* 236E8 8008BEE8 36FE8224 */  addiu      $v0, $a0, -0x1CA
    /* 236EC 8008BEEC 0700422C */  sltiu      $v0, $v0, 0x7
    /* 236F0 8008BEF0 04004010 */  beqz       $v0, .L8008BF04
    /* 236F4 8008BEF4 00240400 */   sll       $a0, $a0, 16
    /* 236F8 8008BEF8 03240400 */  sra        $a0, $a0, 16
    /* 236FC 8008BEFC B739020C */  jal        func_8008E6DC
    /* 23700 8008BF00 36FE8424 */   addiu     $a0, $a0, -0x1CA
  .L8008BF04:
    /* 23704 8008BF04 0E000286 */  lh         $v0, 0xE($s0)
    /* 23708 8008BF08 00000000 */  nop
    /* 2370C 8008BF0C 07004014 */  bnez       $v0, .L8008BF2C
    /* 23710 8008BF10 08000224 */   addiu     $v0, $zero, 0x8
    /* 23714 8008BF14 130002A2 */  sb         $v0, 0x13($s0)
    /* 23718 8008BF18 03000424 */  addiu      $a0, $zero, 0x3
    /* 2371C 8008BF1C 1C30020C */  jal        func_8008C070
    /* 23720 8008BF20 21280002 */   addu      $a1, $s0, $zero
    /* 23724 8008BF24 CE2F0208 */  j          .L8008BF38
    /* 23728 8008BF28 01000224 */   addiu     $v0, $zero, 0x1
  .L8008BF2C:
    /* 2372C 8008BF2C D22F020C */  jal        func_8008BF48
    /* 23730 8008BF30 21200002 */   addu      $a0, $s0, $zero
    /* 23734 8008BF34 01000224 */  addiu      $v0, $zero, 0x1
  .L8008BF38:
    /* 23738 8008BF38 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2373C 8008BF3C 1000B08F */  lw         $s0, 0x10($sp)
    /* 23740 8008BF40 0800E003 */  jr         $ra
    /* 23744 8008BF44 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008BEBC
