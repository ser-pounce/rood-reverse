nonmatching func_80104AEC, 0x4C

glabel func_80104AEC
    /* 22EC 80104AEC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 22F0 80104AF0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 22F4 80104AF4 21808000 */  addu       $s0, $a0, $zero
    /* 22F8 80104AF8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 22FC 80104AFC 28EA030C */  jal        vs_mainMenu_menuItemFlyoutRight
    /* 2300 80104B00 04000424 */   addiu     $a0, $zero, 0x4
    /* 2304 80104B04 9223030C */  jal        vs_battle_getMenuItem
    /* 2308 80104B08 0A000426 */   addiu     $a0, $s0, 0xA
    /* 230C 80104B0C 02000324 */  addiu      $v1, $zero, 0x2
    /* 2310 80104B10 000043A0 */  sb         $v1, 0x0($v0)
    /* 2314 80104B14 9B000324 */  addiu      $v1, $zero, 0x9B
    /* 2318 80104B18 180043A4 */  sh         $v1, 0x18($v0)
    /* 231C 80104B1C 01000324 */  addiu      $v1, $zero, 0x1
    /* 2320 80104B20 060043A0 */  sb         $v1, 0x6($v0)
    /* 2324 80104B24 3C0040AC */  sw         $zero, 0x3C($v0)
    /* 2328 80104B28 1400BF8F */  lw         $ra, 0x14($sp)
    /* 232C 80104B2C 1000B08F */  lw         $s0, 0x10($sp)
    /* 2330 80104B30 0800E003 */  jr         $ra
    /* 2334 80104B34 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80104AEC
