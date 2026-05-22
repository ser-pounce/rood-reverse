nonmatching _getContainerIndicesOffset, 0x38

glabel _getContainerIndicesOffset
    /* 6A8C 8010928C 21300000 */  addu       $a2, $zero, $zero
    /* 6A90 80109290 09008018 */  blez       $a0, .L801092B8
    /* 6A94 80109294 2138C000 */   addu      $a3, $a2, $zero
    /* 6A98 80109298 1180023C */  lui        $v0, %hi(_containerItemCapacities)
    /* 6A9C 8010929C 2CAA4324 */  addiu      $v1, $v0, %lo(_containerItemCapacities)
  .L801092A0:
    /* 6AA0 801092A0 00006294 */  lhu        $v0, 0x0($v1)
    /* 6AA4 801092A4 0100C624 */  addiu      $a2, $a2, 0x1
    /* 6AA8 801092A8 2138E200 */  addu       $a3, $a3, $v0
    /* 6AAC 801092AC 2A10C400 */  slt        $v0, $a2, $a0
    /* 6AB0 801092B0 FBFF4014 */  bnez       $v0, .L801092A0
    /* 6AB4 801092B4 02006324 */   addiu     $v1, $v1, 0x2
  .L801092B8:
    /* 6AB8 801092B8 40100700 */  sll        $v0, $a3, 1
    /* 6ABC 801092BC 0800E003 */  jr         $ra
    /* 6AC0 801092C0 2110A200 */   addu      $v0, $a1, $v0
endlabel _getContainerIndicesOffset
