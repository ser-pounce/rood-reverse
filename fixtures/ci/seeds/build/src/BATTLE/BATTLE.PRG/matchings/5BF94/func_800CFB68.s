nonmatching func_800CFB68, 0x18

glabel func_800CFB68
    /* 67368 800CFB68 2328A400 */  subu       $a1, $a1, $a0
    /* 6736C 800CFB6C 1800A600 */  mult       $a1, $a2
    /* 67370 800CFB70 12180000 */  mflo       $v1
    /* 67374 800CFB74 C3110300 */  sra        $v0, $v1, 7
    /* 67378 800CFB78 0800E003 */  jr         $ra
    /* 6737C 800CFB7C 21104400 */   addu      $v0, $v0, $a0
endlabel func_800CFB68
