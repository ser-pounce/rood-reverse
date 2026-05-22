nonmatching _setItemIndex, 0x68

glabel _setItemIndex
    /* 5048 800FE848 1080023C */  lui        $v0, %hi(vs_mainMenu_inventoryIndices)
    /* 504C 800FE84C A8224224 */  addiu      $v0, $v0, %lo(vs_mainMenu_inventoryIndices)
    /* 5050 800FE850 80180400 */  sll        $v1, $a0, 2
    /* 5054 800FE854 21186200 */  addu       $v1, $v1, $v0
    /* 5058 800FE858 1080023C */  lui        $v0, %hi(vs_mainMenu_inventoryItemCapacities)
    /* 505C 800FE85C A0224224 */  addiu      $v0, $v0, %lo(vs_mainMenu_inventoryItemCapacities)
    /* 5060 800FE860 21208200 */  addu       $a0, $a0, $v0
    /* 5064 800FE864 00008290 */  lbu        $v0, 0x0($a0)
    /* 5068 800FE868 0000638C */  lw         $v1, 0x0($v1)
    /* 506C 800FE86C 0E004010 */  beqz       $v0, .L800FE8A8
    /* 5070 800FE870 21380000 */   addu      $a3, $zero, $zero
    /* 5074 800FE874 0100A524 */  addiu      $a1, $a1, 0x1
    /* 5078 800FE878 21306700 */  addu       $a2, $v1, $a3
  .L800FE87C:
    /* 507C 800FE87C 0000C290 */  lbu        $v0, 0x0($a2)
    /* 5080 800FE880 00000000 */  nop
    /* 5084 800FE884 03004014 */  bnez       $v0, .L800FE894
    /* 5088 800FE888 0100E724 */   addiu     $a3, $a3, 0x1
    /* 508C 800FE88C 0800E003 */  jr         $ra
    /* 5090 800FE890 0000C5A0 */   sb        $a1, 0x0($a2)
  .L800FE894:
    /* 5094 800FE894 00008290 */  lbu        $v0, 0x0($a0)
    /* 5098 800FE898 00000000 */  nop
    /* 509C 800FE89C 2A10E200 */  slt        $v0, $a3, $v0
    /* 50A0 800FE8A0 F6FF4014 */  bnez       $v0, .L800FE87C
    /* 50A4 800FE8A4 21306700 */   addu      $a2, $v1, $a3
  .L800FE8A8:
    /* 50A8 800FE8A8 0800E003 */  jr         $ra
    /* 50AC 800FE8AC 00000000 */   nop
endlabel _setItemIndex
