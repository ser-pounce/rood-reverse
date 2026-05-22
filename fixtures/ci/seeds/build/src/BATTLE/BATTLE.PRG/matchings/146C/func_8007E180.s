nonmatching func_8007E180, 0x40

glabel func_8007E180
    /* 15980 8007E180 0F80033C */  lui        $v1, %hi(D_800F18F8)
    /* 15984 8007E184 F8186290 */  lbu        $v0, %lo(D_800F18F8)($v1)
    /* 15988 8007E188 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1598C 8007E18C 06004010 */  beqz       $v0, .L8007E1A8
    /* 15990 8007E190 1000BFAF */   sw        $ra, 0x10($sp)
    /* 15994 8007E194 66000424 */  addiu      $a0, $zero, 0x66
    /* 15998 8007E198 2624010C */  jal        vs_main_nop9
    /* 1599C 8007E19C 21280000 */   addu      $a1, $zero, $zero
    /* 159A0 8007E1A0 6CF80108 */  j          .L8007E1B0
    /* 159A4 8007E1A4 21100000 */   addu      $v0, $zero, $zero
  .L8007E1A8:
    /* 159A8 8007E1A8 F81864A0 */  sb         $a0, %lo(D_800F18F8)($v1)
    /* 159AC 8007E1AC 01000224 */  addiu      $v0, $zero, 0x1
  .L8007E1B0:
    /* 159B0 8007E1B0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 159B4 8007E1B4 00000000 */  nop
    /* 159B8 8007E1B8 0800E003 */  jr         $ra
    /* 159BC 8007E1BC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007E180
