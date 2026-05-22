nonmatching func_80091468, 0x14

glabel func_80091468
    /* 28C68 80091468 0F80023C */  lui        $v0, %hi(D_800F1DB4)
    /* 28C6C 8009146C B41D44A4 */  sh         $a0, %lo(D_800F1DB4)($v0)
    /* 28C70 80091470 0F80023C */  lui        $v0, %hi(D_800F1DB6)
    /* 28C74 80091474 0800E003 */  jr         $ra
    /* 28C78 80091478 B61D45A4 */   sh        $a1, %lo(D_800F1DB6)($v0)
endlabel func_80091468
