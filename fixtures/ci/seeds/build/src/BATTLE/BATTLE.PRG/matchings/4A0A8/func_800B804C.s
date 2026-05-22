nonmatching func_800B804C, 0x68

glabel func_800B804C
    /* 4F84C 800B804C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4F850 800B8050 1800B0AF */  sw         $s0, 0x18($sp)
    /* 4F854 800B8054 21808000 */  addu       $s0, $a0, $zero
    /* 4F858 800B8058 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 4F85C 800B805C 80FF020C */  jal        vs_battle_getShort
    /* 4F860 800B8060 03000426 */   addiu     $a0, $s0, 0x3
    /* 4F864 800B8064 05000426 */  addiu      $a0, $s0, 0x5
    /* 4F868 800B8068 80FF020C */  jal        vs_battle_getShort
    /* 4F86C 800B806C 1000A2A7 */   sh        $v0, 0x10($sp)
    /* 4F870 800B8070 07000426 */  addiu      $a0, $s0, 0x7
    /* 4F874 800B8074 80FF020C */  jal        vs_battle_getShort
    /* 4F878 800B8078 1200A2A7 */   sh        $v0, 0x12($sp)
    /* 4F87C 800B807C 01000426 */  addiu      $a0, $s0, 0x1
    /* 4F880 800B8080 80FF020C */  jal        vs_battle_getShort
    /* 4F884 800B8084 1400A2A7 */   sh        $v0, 0x14($sp)
    /* 4F888 800B8088 94FF020C */  jal        func_800BFE50
    /* 4F88C 800B808C FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4F890 800B8090 21204000 */  addu       $a0, $v0, $zero
    /* 4F894 800B8094 09000692 */  lbu        $a2, 0x9($s0)
    /* 4F898 800B8098 F4AA020C */  jal        func_800AABD0
    /* 4F89C 800B809C 1000A527 */   addiu     $a1, $sp, 0x10
    /* 4F8A0 800B80A0 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 4F8A4 800B80A4 1800B08F */  lw         $s0, 0x18($sp)
    /* 4F8A8 800B80A8 21100000 */  addu       $v0, $zero, $zero
    /* 4F8AC 800B80AC 0800E003 */  jr         $ra
    /* 4F8B0 800B80B0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800B804C
