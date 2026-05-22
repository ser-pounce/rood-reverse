nonmatching func_8006F5CC, 0x30

glabel func_8006F5CC
    /* 6DCC 8006F5CC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6DD0 8006F5D0 0F80023C */  lui        $v0, %hi(D_800F196C)
    /* 6DD4 8006F5D4 01000324 */  addiu      $v1, $zero, 0x1
    /* 6DD8 8006F5D8 6C1943AC */  sw         $v1, %lo(D_800F196C)($v0)
    /* 6DDC 8006F5DC 0F80023C */  lui        $v0, %hi(_cameraMode)
    /* 6DE0 8006F5E0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6DE4 8006F5E4 4FBD010C */  jal        _setRoomSeen
    /* 6DE8 8006F5E8 F01840AC */   sw        $zero, %lo(_cameraMode)($v0)
    /* 6DEC 8006F5EC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6DF0 8006F5F0 00000000 */  nop
    /* 6DF4 8006F5F4 0800E003 */  jr         $ra
    /* 6DF8 8006F5F8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006F5CC
