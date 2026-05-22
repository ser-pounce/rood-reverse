nonmatching _sydSizes, 0x1C

glabel _sydSizes
    /* 9368 8010BB68 00380000 */  sll        $a3, $zero, 0
    /* 936C 8010BB6C 00080000 */  sll        $at, $zero, 0
    /* 9370 8010BB70 00180000 */  sll        $v1, $zero, 0
  alabel D_8010BB74
    /* 9374 8010BB74 00000000 */  nop
  alabel D_8010BB78
    /* 9378 8010BB78 147F1080 */  lb         $s0, 0x7F14($zero)
    /* 937C 8010BB7C C48E1080 */  lb         $s0, -0x713C($zero)
    /* 9380 8010BB80 EC9D1080 */  lb         $s0, -0x6214($zero)
endlabel _sydSizes
