nonmatching _getContainerIndicesOffset, 0x3C

glabel _getContainerIndicesOffset
    /* 494 80102C94 21300000 */  addu       $a2, $zero, $zero
    /* 498 80102C98 09008018 */  blez       $a0, .L80102CC0
    /* 49C 80102C9C 2138C000 */   addu      $a3, $a2, $zero
    /* 4A0 80102CA0 1180023C */  lui        $v0, %hi(_containerItemCapacities)
    /* 4A4 80102CA4 44994324 */  addiu      $v1, $v0, %lo(_containerItemCapacities)
  .L80102CA8:
    /* 4A8 80102CA8 00006294 */  lhu        $v0, 0x0($v1)
    /* 4AC 80102CAC 0100C624 */  addiu      $a2, $a2, 0x1
    /* 4B0 80102CB0 2138E200 */  addu       $a3, $a3, $v0
    /* 4B4 80102CB4 2A10C400 */  slt        $v0, $a2, $a0
    /* 4B8 80102CB8 FBFF4014 */  bnez       $v0, .L80102CA8
    /* 4BC 80102CBC 02006324 */   addiu     $v1, $v1, 0x2
  .L80102CC0:
    /* 4C0 80102CC0 40100700 */  sll        $v0, $a3, 1
    /* 4C4 80102CC4 003C4224 */  addiu      $v0, $v0, 0x3C00
    /* 4C8 80102CC8 0800E003 */  jr         $ra
    /* 4CC 80102CCC 2110A200 */   addu      $v0, $a1, $v0
endlabel _getContainerIndicesOffset
