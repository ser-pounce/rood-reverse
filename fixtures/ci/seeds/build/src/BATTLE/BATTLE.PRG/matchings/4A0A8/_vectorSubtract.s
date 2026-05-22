nonmatching _vectorSubtract, 0x44

glabel _vectorSubtract
    /* 55E6C 800BE66C 21108000 */  addu       $v0, $a0, $zero
    /* 55E70 800BE670 0000A38C */  lw         $v1, 0x0($a1)
    /* 55E74 800BE674 0000C48C */  lw         $a0, 0x0($a2)
    /* 55E78 800BE678 00000000 */  nop
    /* 55E7C 800BE67C 23186400 */  subu       $v1, $v1, $a0
    /* 55E80 800BE680 000043AC */  sw         $v1, 0x0($v0)
    /* 55E84 800BE684 0400A38C */  lw         $v1, 0x4($a1)
    /* 55E88 800BE688 0400C48C */  lw         $a0, 0x4($a2)
    /* 55E8C 800BE68C 00000000 */  nop
    /* 55E90 800BE690 23186400 */  subu       $v1, $v1, $a0
    /* 55E94 800BE694 040043AC */  sw         $v1, 0x4($v0)
    /* 55E98 800BE698 0800A38C */  lw         $v1, 0x8($a1)
    /* 55E9C 800BE69C 0800C48C */  lw         $a0, 0x8($a2)
    /* 55EA0 800BE6A0 00000000 */  nop
    /* 55EA4 800BE6A4 23186400 */  subu       $v1, $v1, $a0
    /* 55EA8 800BE6A8 0800E003 */  jr         $ra
    /* 55EAC 800BE6AC 080043AC */   sw        $v1, 0x8($v0)
endlabel _vectorSubtract
