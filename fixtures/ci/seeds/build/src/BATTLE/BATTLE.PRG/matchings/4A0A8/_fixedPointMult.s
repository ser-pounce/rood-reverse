nonmatching _fixedPointMult, 0x20

glabel _fixedPointMult
    /* 56058 800BE858 18008500 */  mult       $a0, $a1
    /* 5605C 800BE85C 12400000 */  mflo       $t0
    /* 56060 800BE860 10480000 */  mfhi       $t1
    /* 56064 800BE864 02430800 */  srl        $t0, $t0, 12
    /* 56068 800BE868 004D0900 */  sll        $t1, $t1, 20
    /* 5606C 800BE86C 25100901 */  or         $v0, $t0, $t1
    /* 56070 800BE870 0800E003 */  jr         $ra
    /* 56074 800BE874 00000000 */   nop
endlabel _fixedPointMult
