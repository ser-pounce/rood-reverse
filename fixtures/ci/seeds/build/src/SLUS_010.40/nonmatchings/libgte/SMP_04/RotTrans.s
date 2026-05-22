/* Handwritten function */
nonmatching RotTrans, 0x28

glabel RotTrans
    /* 31FEC 800417EC 000080C8 */  lwc2       $0, 0x0($a0)
    /* 31FF0 800417F0 040081C8 */  lwc2       $1, 0x4($a0)
    /* 31FF4 800417F4 00000000 */  nop
    /* 31FF8 800417F8 1200484A */  mvmva      1, 0, 0, 0, 0
    /* 31FFC 800417FC 0000B9E8 */  swc2       $25, 0x0($a1)
    /* 32000 80041800 0400BAE8 */  swc2       $26, 0x4($a1) /* handwritten instruction */
    /* 32004 80041804 0800BBE8 */  swc2       $27, 0x8($a1) /* handwritten instruction */
    /* 32008 80041808 00F84248 */  cfc2       $v0, $31 /* handwritten instruction */
    /* 3200C 8004180C 0800E003 */  jr         $ra
    /* 32010 80041810 0000C2AC */   sw        $v0, 0x0($a2)
endlabel RotTrans
