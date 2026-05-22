nonmatching _padGetActSize, 0x38

glabel _padGetActSize
    /* 1D5A4 8002CDA4 E3008290 */  lbu        $v0, 0xE3($a0)
    /* 1D5A8 8002CDA8 E9008590 */  lbu        $a1, 0xE9($a0)
    /* 1D5AC 8002CDAC EC008494 */  lhu        $a0, 0xEC($a0)
    /* 1D5B0 8002CDB0 01004224 */  addiu      $v0, $v0, 0x1
    /* 1D5B4 8002CDB4 43100200 */  sra        $v0, $v0, 1
    /* 1D5B8 8002CDB8 80100200 */  sll        $v0, $v0, 2
    /* 1D5BC 8002CDBC 80180500 */  sll        $v1, $a1, 2
    /* 1D5C0 8002CDC0 21186500 */  addu       $v1, $v1, $a1
    /* 1D5C4 8002CDC4 03006324 */  addiu      $v1, $v1, 0x3
    /* 1D5C8 8002CDC8 FC0F6330 */  andi       $v1, $v1, 0xFFC
    /* 1D5CC 8002CDCC 04006324 */  addiu      $v1, $v1, 0x4
    /* 1D5D0 8002CDD0 21104300 */  addu       $v0, $v0, $v1
    /* 1D5D4 8002CDD4 0800E003 */  jr         $ra
    /* 1D5D8 8002CDD8 21104400 */   addu      $v0, $v0, $a0
endlabel _padGetActSize
