nonmatching func_800D4D64, 0x34

glabel func_800D4D64
    /* 6C564 800D4D64 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C568 800D4D68 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6C56C 800D4D6C 1C0D8394 */  lhu        $v1, 0xD1C($a0)
    /* 6C570 800D4D70 04000224 */  addiu      $v0, $zero, 0x4
    /* 6C574 800D4D74 04006214 */  bne        $v1, $v0, .L800D4D88
    /* 6C578 800D4D78 00000000 */   nop
    /* 6C57C 800D4D7C 200D8490 */  lbu        $a0, 0xD20($a0)
    /* 6C580 800D4D80 6EB3010C */  jal        func_8006CDB8
    /* 6C584 800D4D84 00000000 */   nop
  .L800D4D88:
    /* 6C588 800D4D88 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6C58C 800D4D8C 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C590 800D4D90 0800E003 */  jr         $ra
    /* 6C594 800D4D94 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D4D64
