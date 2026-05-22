nonmatching func_800A07B4, 0x48

glabel func_800A07B4
    /* 37FB4 800A07B4 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 37FB8 800A07B8 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 37FBC 800A07BC 80200400 */  sll        $a0, $a0, 2
    /* 37FC0 800A07C0 21208200 */  addu       $a0, $a0, $v0
    /* 37FC4 800A07C4 0000868C */  lw         $a2, 0x0($a0)
    /* 37FC8 800A07C8 00000000 */  nop
    /* 37FCC 800A07CC 0800C010 */  beqz       $a2, .L800A07F0
    /* 37FD0 800A07D0 2138A000 */   addu      $a3, $a1, $zero
    /* 37FD4 800A07D4 5B00C288 */  lwl        $v0, 0x5B($a2)
    /* 37FD8 800A07D8 5800C298 */  lwr        $v0, 0x58($a2)
    /* 37FDC 800A07DC 00000000 */  nop
    /* 37FE0 800A07E0 0300E2A8 */  swl        $v0, 0x3($a3)
    /* 37FE4 800A07E4 0000E2B8 */  swr        $v0, 0x0($a3)
    /* 37FE8 800A07E8 FD810208 */  j          .L800A07F4
    /* 37FEC 800A07EC 21100000 */   addu      $v0, $zero, $zero
  .L800A07F0:
    /* 37FF0 800A07F0 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L800A07F4:
    /* 37FF4 800A07F4 0800E003 */  jr         $ra
    /* 37FF8 800A07F8 00000000 */   nop
endlabel func_800A07B4
