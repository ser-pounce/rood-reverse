nonmatching func_800CFE1C, 0x24

glabel func_800CFE1C
    /* 6761C 800CFE1C 00008384 */  lh         $v1, 0x0($a0)
    /* 67620 800CFE20 02008284 */  lh         $v0, 0x2($a0)
    /* 67624 800CFE24 00000000 */  nop
    /* 67628 800CFE28 23104300 */  subu       $v0, $v0, $v1
    /* 6762C 800CFE2C 18004500 */  mult       $v0, $a1
    /* 67630 800CFE30 12300000 */  mflo       $a2
    /* 67634 800CFE34 C3110600 */  sra        $v0, $a2, 7
    /* 67638 800CFE38 0800E003 */  jr         $ra
    /* 6763C 800CFE3C 21104300 */   addu      $v0, $v0, $v1
endlabel func_800CFE1C
