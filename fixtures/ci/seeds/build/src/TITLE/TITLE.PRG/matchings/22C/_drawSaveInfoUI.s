nonmatching _drawSaveInfoUI, 0x44

glabel _drawSaveInfoUI
    /* 201C 8006A81C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2020 8006A820 0780023C */  lui        $v0, %hi(_saveInfoUVClut)
    /* 2024 8006A824 C0284224 */  addiu      $v0, $v0, %lo(_saveInfoUVClut)
    /* 2028 8006A828 80300500 */  sll        $a2, $a1, 2
    /* 202C 8006A82C 2110C200 */  addu       $v0, $a2, $v0
    /* 2030 8006A830 0780033C */  lui        $v1, %hi(_saveInfoWh)
    /* 2034 8006A834 E8286324 */  addiu      $v1, $v1, %lo(_saveInfoWh)
    /* 2038 8006A838 2130C300 */  addu       $a2, $a2, $v1
    /* 203C 8006A83C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2040 8006A840 0000458C */  lw         $a1, 0x0($v0)
    /* 2044 8006A844 0000C68C */  lw         $a2, 0x0($a2)
    /* 2048 8006A848 DEA9010C */  jal        _drawSprt
    /* 204C 8006A84C 0C000724 */   addiu     $a3, $zero, 0xC
    /* 2050 8006A850 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2054 8006A854 00000000 */  nop
    /* 2058 8006A858 0800E003 */  jr         $ra
    /* 205C 8006A85C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _drawSaveInfoUI
