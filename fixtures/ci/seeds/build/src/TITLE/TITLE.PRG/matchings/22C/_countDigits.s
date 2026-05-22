nonmatching _countDigits, 0x30

glabel _countDigits
    /* 20F8 8006A8F8 21280000 */  addu       $a1, $zero, $zero
    /* 20FC 8006A8FC 6666063C */  lui        $a2, (0x66666667 >> 16)
    /* 2100 8006A900 6766C634 */  ori        $a2, $a2, (0x66666667 & 0xFFFF)
  .L8006A904:
    /* 2104 8006A904 18008600 */  mult       $a0, $a2
    /* 2108 8006A908 C3170400 */  sra        $v0, $a0, 31
    /* 210C 8006A90C 10380000 */  mfhi       $a3
    /* 2110 8006A910 83180700 */  sra        $v1, $a3, 2
    /* 2114 8006A914 23206200 */  subu       $a0, $v1, $v0
    /* 2118 8006A918 FAFF8014 */  bnez       $a0, .L8006A904
    /* 211C 8006A91C 0100A524 */   addiu     $a1, $a1, 0x1
    /* 2120 8006A920 0800E003 */  jr         $ra
    /* 2124 8006A924 2110A000 */   addu      $v0, $a1, $zero
endlabel _countDigits
