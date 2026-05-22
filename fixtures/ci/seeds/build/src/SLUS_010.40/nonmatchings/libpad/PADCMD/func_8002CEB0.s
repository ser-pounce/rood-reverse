nonmatching func_8002CEB0, 0xA8

glabel func_8002CEB0
    /* 1D6B0 8002CEB0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1D6B4 8002CEB4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1D6B8 8002CEB8 46008390 */  lbu        $v1, 0x46($a0)
    /* 1D6BC 8002CEBC 03000224 */  addiu      $v0, $zero, 0x3
    /* 1D6C0 8002CEC0 11006210 */  beq        $v1, $v0, .L8002CF08
    /* 1D6C4 8002CEC4 04006228 */   slti      $v0, $v1, 0x4
    /* 1D6C8 8002CEC8 05004010 */  beqz       $v0, .L8002CEE0
    /* 1D6CC 8002CECC 02000224 */   addiu     $v0, $zero, 0x2
    /* 1D6D0 8002CED0 08006210 */  beq        $v1, $v0, .L8002CEF4
    /* 1D6D4 8002CED4 00000000 */   nop
    /* 1D6D8 8002CED8 D2B30008 */  j          .L8002CF48
    /* 1D6DC 8002CEDC 00000000 */   nop
  .L8002CEE0:
    /* 1D6E0 8002CEE0 04000224 */  addiu      $v0, $zero, 0x4
    /* 1D6E4 8002CEE4 0D006210 */  beq        $v1, $v0, .L8002CF1C
    /* 1D6E8 8002CEE8 00000000 */   nop
    /* 1D6EC 8002CEEC D2B30008 */  j          .L8002CF48
    /* 1D6F0 8002CEF0 00000000 */   nop
  .L8002CEF4:
    /* 1D6F4 8002CEF4 47008590 */  lbu        $a1, 0x47($a0)
    /* 1D6F8 8002CEF8 87B5000C */  jal        func_8002D61C
    /* 1D6FC 8002CEFC 00000000 */   nop
    /* 1D700 8002CF00 D2B30008 */  j          .L8002CF48
    /* 1D704 8002CF04 00000000 */   nop
  .L8002CF08:
    /* 1D708 8002CF08 47008590 */  lbu        $a1, 0x47($a0)
    /* 1D70C 8002CF0C 8FB5000C */  jal        func_8002D63C
    /* 1D710 8002CF10 00000000 */   nop
    /* 1D714 8002CF14 D2B30008 */  j          .L8002CF48
    /* 1D718 8002CF18 00000000 */   nop
  .L8002CF1C:
    /* 1D71C 8002CF1C 48008290 */  lbu        $v0, 0x48($a0)
    /* 1D720 8002CF20 00000000 */  nop
    /* 1D724 8002CF24 06004014 */  bnez       $v0, .L8002CF40
    /* 1D728 8002CF28 00000000 */   nop
    /* 1D72C 8002CF2C 47008590 */  lbu        $a1, 0x47($a0)
    /* 1D730 8002CF30 97B5000C */  jal        func_8002D65C
    /* 1D734 8002CF34 00000000 */   nop
    /* 1D738 8002CF38 D2B30008 */  j          .L8002CF48
    /* 1D73C 8002CF3C 00000000 */   nop
  .L8002CF40:
    /* 1D740 8002CF40 9FB5000C */  jal        func_8002D67C
    /* 1D744 8002CF44 00000000 */   nop
  .L8002CF48:
    /* 1D748 8002CF48 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1D74C 8002CF4C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1D750 8002CF50 0800E003 */  jr         $ra
    /* 1D754 8002CF54 00000000 */   nop
endlabel func_8002CEB0
