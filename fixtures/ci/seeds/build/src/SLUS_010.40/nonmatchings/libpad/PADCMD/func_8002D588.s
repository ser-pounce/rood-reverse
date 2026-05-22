nonmatching func_8002D588, 0x60

glabel func_8002D588
    /* 1DD88 8002D588 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1DD8C 8002D58C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1DD90 8002D590 53008290 */  lbu        $v0, 0x53($a0)
    /* 1DD94 8002D594 00000000 */  nop
    /* 1DD98 8002D598 09004010 */  beqz       $v0, .L8002D5C0
    /* 1DD9C 8002D59C 02000224 */   addiu     $v0, $zero, 0x2
    /* 1DDA0 8002D5A0 46008390 */  lbu        $v1, 0x46($a0)
    /* 1DDA4 8002D5A4 00000000 */  nop
    /* 1DDA8 8002D5A8 03006214 */  bne        $v1, $v0, .L8002D5B8
    /* 1DDAC 8002D5AC FE000224 */   addiu     $v0, $zero, 0xFE
    /* 1DDB0 8002D5B0 76B50008 */  j          .L8002D5D8
    /* 1DDB4 8002D5B4 01000224 */   addiu     $v0, $zero, 0x1
  .L8002D5B8:
    /* 1DDB8 8002D5B8 75B50008 */  j          .L8002D5D4
    /* 1DDBC 8002D5BC 460082A0 */   sb        $v0, 0x46($a0)
  .L8002D5C0:
    /* 1DDC0 8002D5C0 0380023C */  lui        $v0, %hi(D_800335A0)
    /* 1DDC4 8002D5C4 A035428C */  lw         $v0, %lo(D_800335A0)($v0)
    /* 1DDC8 8002D5C8 00000000 */  nop
    /* 1DDCC 8002D5CC 09F84000 */  jalr       $v0
    /* 1DDD0 8002D5D0 00000000 */   nop
  .L8002D5D4:
    /* 1DDD4 8002D5D4 21100000 */  addu       $v0, $zero, $zero
  .L8002D5D8:
    /* 1DDD8 8002D5D8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1DDDC 8002D5DC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1DDE0 8002D5E0 0800E003 */  jr         $ra
    /* 1DDE4 8002D5E4 00000000 */   nop
endlabel func_8002D588
