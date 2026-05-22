nonmatching func_800B6580, 0x68

glabel func_800B6580
    /* 4DD80 800B6580 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 4DD84 800B6584 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 4DD88 800B6588 80180400 */  sll        $v1, $a0, 2
    /* 4DD8C 800B658C 21104300 */  addu       $v0, $v0, $v1
    /* 4DD90 800B6590 0000428C */  lw         $v0, 0x0($v0)
    /* 4DD94 800B6594 0000AA8C */  lw         $t2, 0x0($a1)
    /* 4DD98 800B6598 0B004980 */  lb         $t1, 0xB($v0)
    /* 4DD9C 800B659C 00440600 */  sll        $t0, $a2, 16
    /* 4DDA0 800B65A0 0F002931 */  andi       $t1, $t1, 0xF
    /* 4DDA4 800B65A4 0F002015 */  bnez       $t1, .L800B65E4
    /* 4DDA8 800B65A8 01002935 */   ori       $t1, $t1, 0x1
    /* 4DDAC 800B65AC FD174490 */  lbu        $a0, 0x17FD($v0)
    /* 4DDB0 800B65B0 1A0040A4 */  sh         $zero, 0x1A($v0)
    /* 4DDB4 800B65B4 EC054AAC */  sw         $t2, 0x5EC($v0)
    /* 4DDB8 800B65B8 F00548AC */  sw         $t0, 0x5F0($v0)
    /* 4DDBC 800B65BC 0B0049A0 */  sb         $t1, 0xB($v0)
    /* 4DDC0 800B65C0 02008B28 */  slti       $t3, $a0, 0x2
    /* 4DDC4 800B65C4 07006015 */  bnez       $t3, .L800B65E4
    /* 4DDC8 800B65C8 00000000 */   nop
    /* 4DDCC 800B65CC FCFFBD27 */  addiu      $sp, $sp, -0x4
    /* 4DDD0 800B65D0 0000BFAF */  sw         $ra, 0x0($sp)
    /* 4DDD4 800B65D4 60D9020C */  jal        func_800B6580
    /* 4DDD8 800B65D8 00000000 */   nop
    /* 4DDDC 800B65DC 0000BF8F */  lw         $ra, 0x0($sp)
    /* 4DDE0 800B65E0 0400BD27 */  addiu      $sp, $sp, 0x4
  .L800B65E4:
    /* 4DDE4 800B65E4 0800E003 */  jr         $ra
endlabel func_800B6580
