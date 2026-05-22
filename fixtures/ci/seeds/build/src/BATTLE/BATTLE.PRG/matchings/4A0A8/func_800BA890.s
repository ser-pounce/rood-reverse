nonmatching func_800BA890, 0x2C

glabel func_800BA890
    /* 52090 800BA890 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 52094 800BA894 1000BFAF */  sw         $ra, 0x10($sp)
    /* 52098 800BA898 01008490 */  lbu        $a0, 0x1($a0)
    /* 5209C 800BA89C 0F80023C */  lui        $v0, %hi(D_800F4C69)
    /* 520A0 800BA8A0 694C44A0 */  sb         $a0, %lo(D_800F4C69)($v0)
    /* 520A4 800BA8A4 B213010C */  jal        func_80044EC8
    /* 520A8 800BA8A8 FF008430 */   andi      $a0, $a0, 0xFF
    /* 520AC 800BA8AC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 520B0 800BA8B0 21100000 */  addu       $v0, $zero, $zero
    /* 520B4 800BA8B4 0800E003 */  jr         $ra
    /* 520B8 800BA8B8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA890
