nonmatching func_80084D44, 0x64

glabel func_80084D44
    /* 1C544 80084D44 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 1C548 80084D48 0000C290 */  lbu        $v0, 0x0($a2)
    /* 1C54C 80084D4C 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 1C550 80084D50 80100200 */  sll        $v0, $v0, 2
    /* 1C554 80084D54 21104300 */  addu       $v0, $v0, $v1
    /* 1C558 80084D58 0000428C */  lw         $v0, 0x0($v0)
    /* 1C55C 80084D5C 00000000 */  nop
    /* 1C560 80084D60 3C00458C */  lw         $a1, 0x3C($v0)
    /* 1C564 80084D64 00000000 */  nop
    /* 1C568 80084D68 5400A294 */  lhu        $v0, 0x54($a1)
    /* 1C56C 80084D6C 00000000 */  nop
    /* 1C570 80084D70 0B004010 */  beqz       $v0, .L80084DA0
    /* 1C574 80084D74 1000043C */   lui       $a0, (0x100000 >> 16)
    /* 1C578 80084D78 CFFF023C */  lui        $v0, (0xFFCFFFFF >> 16)
    /* 1C57C 80084D7C FFFF4234 */  ori        $v0, $v0, (0xFFCFFFFF & 0xFFFF)
    /* 1C580 80084D80 1C00C38C */  lw         $v1, 0x1C($a2)
    /* 1C584 80084D84 4C01A594 */  lhu        $a1, 0x14C($a1)
    /* 1C588 80084D88 24186200 */  and        $v1, $v1, $v0
    /* 1C58C 80084D8C 3A00C294 */  lhu        $v0, 0x3A($a2)
    /* 1C590 80084D90 25186400 */  or         $v1, $v1, $a0
    /* 1C594 80084D94 1C00C3AC */  sw         $v1, 0x1C($a2)
    /* 1C598 80084D98 21104500 */  addu       $v0, $v0, $a1
    /* 1C59C 80084D9C 3A00C2A4 */  sh         $v0, 0x3A($a2)
  .L80084DA0:
    /* 1C5A0 80084DA0 0800E003 */  jr         $ra
    /* 1C5A4 80084DA4 00000000 */   nop
endlabel func_80084D44
