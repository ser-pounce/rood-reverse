nonmatching func_80012A40, 0x2C

glabel func_80012A40
    /* 3240 80012A40 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3244 80012A44 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 3248 80012A48 FF008430 */  andi       $a0, $a0, 0xFF
    /* 324C 80012A4C C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 3250 80012A50 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3254 80012A54 0C63000C */  jal        func_80018C30
    /* 3258 80012A58 D4000424 */   addiu     $a0, $zero, 0xD4
    /* 325C 80012A5C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3260 80012A60 00000000 */  nop
    /* 3264 80012A64 0800E003 */  jr         $ra
    /* 3268 80012A68 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012A40
