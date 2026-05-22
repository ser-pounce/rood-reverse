nonmatching func_800BB3BC, 0x60

glabel func_800BB3BC
    /* 52BBC 800BB3BC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 52BC0 800BB3C0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 52BC4 800BB3C4 01008390 */  lbu        $v1, 0x1($a0)
    /* 52BC8 800BB3C8 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 52BCC 800BB3CC 05006210 */  beq        $v1, $v0, .L800BB3E4
    /* 52BD0 800BB3D0 FFFF0324 */   addiu     $v1, $zero, -0x1
    /* 52BD4 800BB3D4 01008290 */  lbu        $v0, 0x1($a0)
    /* 52BD8 800BB3D8 00000000 */  nop
    /* 52BDC 800BB3DC 04004224 */  addiu      $v0, $v0, 0x4
    /* 52BE0 800BB3E0 07004330 */  andi       $v1, $v0, 0x7
  .L800BB3E4:
    /* 52BE4 800BB3E4 02008290 */  lbu        $v0, 0x2($a0)
    /* 52BE8 800BB3E8 00000000 */  nop
    /* 52BEC 800BB3EC 02004010 */  beqz       $v0, .L800BB3F8
    /* 52BF0 800BB3F0 FFFF0524 */   addiu     $a1, $zero, -0x1
    /* 52BF4 800BB3F4 21284000 */  addu       $a1, $v0, $zero
  .L800BB3F8:
    /* 52BF8 800BB3F8 73F0020C */  jal        func_800BC1CC
    /* 52BFC 800BB3FC 21206000 */   addu      $a0, $v1, $zero
    /* 52C00 800BB400 0F80033C */  lui        $v1, %hi(D_800F4BB6)
    /* 52C04 800BB404 1000BF8F */  lw         $ra, 0x10($sp)
    /* 52C08 800BB408 01000224 */  addiu      $v0, $zero, 0x1
    /* 52C0C 800BB40C B64B62A4 */  sh         $v0, %lo(D_800F4BB6)($v1)
    /* 52C10 800BB410 21100000 */  addu       $v0, $zero, $zero
    /* 52C14 800BB414 0800E003 */  jr         $ra
    /* 52C18 800BB418 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BB3BC
