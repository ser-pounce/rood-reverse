nonmatching func_801069B0, 0x54

glabel func_801069B0
    /* 41B0 801069B0 21180000 */  addu       $v1, $zero, $zero
    /* 41B4 801069B4 00800634 */  ori        $a2, $zero, 0x8000
    /* 41B8 801069B8 00220400 */  sll        $a0, $a0, 8
    /* 41BC 801069BC 0100A524 */  addiu      $a1, $a1, 0x1
    /* 41C0 801069C0 25208500 */  or         $a0, $a0, $a1
    /* 41C4 801069C4 1080023C */  lui        $v0, %hi(vs_menu_inventoryStorage)
    /* 41C8 801069C8 5C24458C */  lw         $a1, %lo(vs_menu_inventoryStorage)($v0)
  .L801069CC:
    /* 41CC 801069CC 00000000 */  nop
    /* 41D0 801069D0 2110A600 */  addu       $v0, $a1, $a2
    /* 41D4 801069D4 B0434294 */  lhu        $v0, 0x43B0($v0)
    /* 41D8 801069D8 00000000 */  nop
    /* 41DC 801069DC 07004410 */  beq        $v0, $a0, .L801069FC
    /* 41E0 801069E0 01006224 */   addiu     $v0, $v1, 0x1
    /* 41E4 801069E4 01006324 */  addiu      $v1, $v1, 0x1
    /* 41E8 801069E8 40006228 */  slti       $v0, $v1, 0x40
    /* 41EC 801069EC F7FF4014 */  bnez       $v0, .L801069CC
    /* 41F0 801069F0 0200A524 */   addiu     $a1, $a1, 0x2
    /* 41F4 801069F4 0800E003 */  jr         $ra
    /* 41F8 801069F8 21100000 */   addu      $v0, $zero, $zero
  .L801069FC:
    /* 41FC 801069FC 0800E003 */  jr         $ra
    /* 4200 80106A00 00000000 */   nop
endlabel func_801069B0
