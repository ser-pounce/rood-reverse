nonmatching memzero, 0x24

glabel memzero
    /* 10770 8001FF70 0600A010 */  beqz       $a1, .L8001FF8C
    /* 10774 8001FF74 FFFFA224 */   addiu     $v0, $a1, -0x1
    /* 10778 8001FF78 FFFF0324 */  addiu      $v1, $zero, -0x1
  .L8001FF7C:
    /* 1077C 8001FF7C 000080AC */  sw         $zero, 0x0($a0)
    /* 10780 8001FF80 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 10784 8001FF84 FDFF4314 */  bne        $v0, $v1, .L8001FF7C
    /* 10788 8001FF88 04008424 */   addiu     $a0, $a0, 0x4
  .L8001FF8C:
    /* 1078C 8001FF8C 0800E003 */  jr         $ra
    /* 10790 8001FF90 00000000 */   nop
endlabel memzero
