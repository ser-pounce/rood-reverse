nonmatching func_8007C8F8, 0x30

glabel func_8007C8F8
    /* 140F8 8007C8F8 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 140FC 8007C8FC 01000224 */  addiu      $v0, $zero, 0x1
    /* 14100 8007C900 1200A4A7 */  sh         $a0, 0x12($sp)
    /* 14104 8007C904 1000A427 */  addiu      $a0, $sp, 0x10
    /* 14108 8007C908 2800BFAF */  sw         $ra, 0x28($sp)
    /* 1410C 8007C90C 1000A2A3 */  sb         $v0, 0x10($sp)
    /* 14110 8007C910 7A65020C */  jal        vs_battle_populateDataSlot
    /* 14114 8007C914 1100A0A3 */   sb        $zero, 0x11($sp)
    /* 14118 8007C918 2800BF8F */  lw         $ra, 0x28($sp)
    /* 1411C 8007C91C 01004224 */  addiu      $v0, $v0, 0x1
    /* 14120 8007C920 0800E003 */  jr         $ra
    /* 14124 8007C924 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8007C8F8
