nonmatching func_800BFE50, 0x6C

glabel func_800BFE50
    /* 57650 800BFE50 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 57654 800BFE54 FFFF8530 */  andi       $a1, $a0, 0xFFFF
    /* 57658 800BFE58 021B0500 */  srl        $v1, $a1, 12
    /* 5765C 800BFE5C 01000224 */  addiu      $v0, $zero, 0x1
    /* 57660 800BFE60 11006210 */  beq        $v1, $v0, .L800BFEA8
    /* 57664 800BFE64 1000BFAF */   sw        $ra, 0x10($sp)
    /* 57668 800BFE68 02006228 */  slti       $v0, $v1, 0x2
    /* 5766C 800BFE6C 05004010 */  beqz       $v0, .L800BFE84
    /* 57670 800BFE70 00000000 */   nop
    /* 57674 800BFE74 08006010 */  beqz       $v1, .L800BFE98
    /* 57678 800BFE78 00000000 */   nop
    /* 5767C 800BFE7C ABFF0208 */  j          .L800BFEAC
    /* 57680 800BFE80 00000000 */   nop
  .L800BFE84:
    /* 57684 800BFE84 02000224 */  addiu      $v0, $zero, 0x2
    /* 57688 800BFE88 08006210 */  beq        $v1, $v0, .L800BFEAC
    /* 5768C 800BFE8C 2110A000 */   addu      $v0, $a1, $zero
    /* 57690 800BFE90 ABFF0208 */  j          .L800BFEAC
    /* 57694 800BFE94 00000000 */   nop
  .L800BFE98:
    /* 57698 800BFE98 C6F3010C */  jal        func_8007CF18
    /* 5769C 800BFE9C FF0F8430 */   andi      $a0, $a0, 0xFFF
    /* 576A0 800BFEA0 ABFF0208 */  j          .L800BFEAC
    /* 576A4 800BFEA4 00000000 */   nop
  .L800BFEA8:
    /* 576A8 800BFEA8 1F008230 */  andi       $v0, $a0, 0x1F
  .L800BFEAC:
    /* 576AC 800BFEAC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 576B0 800BFEB0 00000000 */  nop
    /* 576B4 800BFEB4 0800E003 */  jr         $ra
    /* 576B8 800BFEB8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BFE50
