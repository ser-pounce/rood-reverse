nonmatching func_80094AF8, 0x14

glabel func_80094AF8
    /* 2C2F8 80094AF8 06008294 */  lhu        $v0, 0x6($a0)
    /* 2C2FC 80094AFC 0B0080A0 */  sb         $zero, 0xB($a0)
    /* 2C300 80094B00 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 2C304 80094B04 0800E003 */  jr         $ra
    /* 2C308 80094B08 060082A4 */   sh        $v0, 0x6($a0)
endlabel func_80094AF8
