nonmatching Sound_IsNotAkaoFile, 0x14

glabel Sound_IsNotAkaoFile
    /* 3C68 80013468 BEB0033C */  lui        $v1, (0xB0BEB4BF >> 16)
    /* 3C6C 8001346C 0000828C */  lw         $v0, 0x0($a0)
    /* 3C70 80013470 BFB46334 */  ori        $v1, $v1, (0xB0BEB4BF & 0xFFFF)
    /* 3C74 80013474 0800E003 */  jr         $ra
    /* 3C78 80013478 21104300 */   addu      $v0, $v0, $v1
endlabel Sound_IsNotAkaoFile
