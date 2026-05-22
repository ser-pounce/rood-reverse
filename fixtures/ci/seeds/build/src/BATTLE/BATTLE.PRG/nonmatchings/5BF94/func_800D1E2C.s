nonmatching func_800D1E2C, 0x4C

glabel func_800D1E2C
    /* 6962C 800D1E2C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 69630 800D1E30 21188000 */  addu       $v1, $a0, $zero
    /* 69634 800D1E34 1000BFAF */  sw         $ra, 0x10($sp)
    /* 69638 800D1E38 01006290 */  lbu        $v0, 0x1($v1)
    /* 6963C 800D1E3C 00000000 */  nop
    /* 69640 800D1E40 20004230 */  andi       $v0, $v0, 0x20
    /* 69644 800D1E44 07004010 */  beqz       $v0, .L800D1E64
    /* 69648 800D1E48 00000000 */   nop
    /* 6964C 800D1E4C 02006490 */  lbu        $a0, 0x2($v1)
    /* 69650 800D1E50 00006590 */  lbu        $a1, 0x0($v1)
    /* 69654 800D1E54 6344030C */  jal        func_800D118C
    /* 69658 800D1E58 00000000 */   nop
    /* 6965C 800D1E5C 9A470308 */  j          .L800D1E68
    /* 69660 800D1E60 00000000 */   nop
  .L800D1E64:
    /* 69664 800D1E64 02006290 */  lbu        $v0, 0x2($v1)
  .L800D1E68:
    /* 69668 800D1E68 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6966C 800D1E6C FF004230 */  andi       $v0, $v0, 0xFF
    /* 69670 800D1E70 0800E003 */  jr         $ra
    /* 69674 800D1E74 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D1E2C
