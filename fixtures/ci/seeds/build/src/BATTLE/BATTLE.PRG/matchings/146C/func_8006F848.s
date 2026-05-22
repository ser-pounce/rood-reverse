nonmatching func_8006F848, 0x54

glabel func_8006F848
    /* 7048 8006F848 00FFBD27 */  addiu      $sp, $sp, -0x100
    /* 704C 8006F84C 14000224 */  addiu      $v0, $zero, 0x14
    /* 7050 8006F850 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 7054 8006F854 01000224 */  addiu      $v0, $zero, 0x1
    /* 7058 8006F858 1200A2A3 */  sb         $v0, 0x12($sp)
    /* 705C 8006F85C 05000224 */  addiu      $v0, $zero, 0x5
    /* 7060 8006F860 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 7064 8006F864 04000224 */  addiu      $v0, $zero, 0x4
    /* 7068 8006F868 2000A2A7 */  sh         $v0, 0x20($sp)
    /* 706C 8006F86C FD000224 */  addiu      $v0, $zero, 0xFD
    /* 7070 8006F870 1000A427 */  addiu      $a0, $sp, 0x10
    /* 7074 8006F874 21280000 */  addu       $a1, $zero, $zero
    /* 7078 8006F878 F800BFAF */  sw         $ra, 0xF8($sp)
    /* 707C 8006F87C 1300A0A3 */  sb         $zero, 0x13($sp)
    /* 7080 8006F880 2400A0A3 */  sb         $zero, 0x24($sp)
    /* 7084 8006F884 FE3C030C */  jal        func_800CF3F8
    /* 7088 8006F888 2600A2A3 */   sb        $v0, 0x26($sp)
    /* 708C 8006F88C F800BF8F */  lw         $ra, 0xF8($sp)
    /* 7090 8006F890 00000000 */  nop
    /* 7094 8006F894 0800E003 */  jr         $ra
    /* 7098 8006F898 0001BD27 */   addiu     $sp, $sp, 0x100
endlabel func_8006F848
