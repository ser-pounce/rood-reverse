nonmatching vs_mainMenu_findItem, 0x68

glabel vs_mainMenu_findItem
    /* 4FE0 800FE7E0 1080023C */  lui        $v0, %hi(vs_mainMenu_inventoryIndices)
    /* 4FE4 800FE7E4 A8224224 */  addiu      $v0, $v0, %lo(vs_mainMenu_inventoryIndices)
    /* 4FE8 800FE7E8 80180400 */  sll        $v1, $a0, 2
    /* 4FEC 800FE7EC 21186200 */  addu       $v1, $v1, $v0
    /* 4FF0 800FE7F0 1080023C */  lui        $v0, %hi(vs_mainMenu_inventoryItemCapacities)
    /* 4FF4 800FE7F4 A0224224 */  addiu      $v0, $v0, %lo(vs_mainMenu_inventoryItemCapacities)
    /* 4FF8 800FE7F8 21208200 */  addu       $a0, $a0, $v0
    /* 4FFC 800FE7FC 00008290 */  lbu        $v0, 0x0($a0)
    /* 5000 800FE800 0000638C */  lw         $v1, 0x0($v1)
    /* 5004 800FE804 0C004010 */  beqz       $v0, .L800FE838
    /* 5008 800FE808 21300000 */   addu      $a2, $zero, $zero
    /* 500C 800FE80C 0100A524 */  addiu      $a1, $a1, 0x1
    /* 5010 800FE810 21204000 */  addu       $a0, $v0, $zero
    /* 5014 800FE814 21106600 */  addu       $v0, $v1, $a2
  .L800FE818:
    /* 5018 800FE818 00004290 */  lbu        $v0, 0x0($v0)
    /* 501C 800FE81C 00000000 */  nop
    /* 5020 800FE820 07004510 */  beq        $v0, $a1, .L800FE840
    /* 5024 800FE824 0100C224 */   addiu     $v0, $a2, 0x1
    /* 5028 800FE828 0100C624 */  addiu      $a2, $a2, 0x1
    /* 502C 800FE82C 2A10C400 */  slt        $v0, $a2, $a0
    /* 5030 800FE830 F9FF4014 */  bnez       $v0, .L800FE818
    /* 5034 800FE834 21106600 */   addu      $v0, $v1, $a2
  .L800FE838:
    /* 5038 800FE838 0800E003 */  jr         $ra
    /* 503C 800FE83C 21100000 */   addu      $v0, $zero, $zero
  .L800FE840:
    /* 5040 800FE840 0800E003 */  jr         $ra
    /* 5044 800FE844 00000000 */   nop
endlabel vs_mainMenu_findItem
