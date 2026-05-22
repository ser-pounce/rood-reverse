nonmatching _padSendAtLoadInfo, 0x84

glabel _padSendAtLoadInfo
    /* 1D2B0 8002CAB0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1D2B4 8002CAB4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1D2B8 8002CAB8 46008390 */  lbu        $v1, 0x46($a0)
    /* 1D2BC 8002CABC 03000224 */  addiu      $v0, $zero, 0x3
    /* 1D2C0 8002CAC0 10006210 */  beq        $v1, $v0, .L8002CB04
    /* 1D2C4 8002CAC4 04006228 */   slti      $v0, $v1, 0x4
    /* 1D2C8 8002CAC8 05004010 */  beqz       $v0, .L8002CAE0
    /* 1D2CC 8002CACC 02000224 */   addiu     $v0, $zero, 0x2
    /* 1D2D0 8002CAD0 08006210 */  beq        $v1, $v0, .L8002CAF4
    /* 1D2D4 8002CAD4 00000000 */   nop
    /* 1D2D8 8002CAD8 C9B20008 */  j          .L8002CB24
    /* 1D2DC 8002CADC 00000000 */   nop
  .L8002CAE0:
    /* 1D2E0 8002CAE0 04000224 */  addiu      $v0, $zero, 0x4
    /* 1D2E4 8002CAE4 0C006210 */  beq        $v1, $v0, .L8002CB18
    /* 1D2E8 8002CAE8 00000000 */   nop
    /* 1D2EC 8002CAEC C9B20008 */  j          .L8002CB24
    /* 1D2F0 8002CAF0 00000000 */   nop
  .L8002CAF4:
    /* 1D2F4 8002CAF4 82B5000C */  jal        func_8002D608
    /* 1D2F8 8002CAF8 00000000 */   nop
    /* 1D2FC 8002CAFC C9B20008 */  j          .L8002CB24
    /* 1D300 8002CB00 00000000 */   nop
  .L8002CB04:
    /* 1D304 8002CB04 E4008590 */  lbu        $a1, 0xE4($a0)
    /* 1D308 8002CB08 87B5000C */  jal        func_8002D61C
    /* 1D30C 8002CB0C 00000000 */   nop
    /* 1D310 8002CB10 C9B20008 */  j          .L8002CB24
    /* 1D314 8002CB14 00000000 */   nop
  .L8002CB18:
    /* 1D318 8002CB18 47008590 */  lbu        $a1, 0x47($a0)
    /* 1D31C 8002CB1C 97B5000C */  jal        func_8002D65C
    /* 1D320 8002CB20 00000000 */   nop
  .L8002CB24:
    /* 1D324 8002CB24 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1D328 8002CB28 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1D32C 8002CB2C 0800E003 */  jr         $ra
    /* 1D330 8002CB30 00000000 */   nop
endlabel _padSendAtLoadInfo
