nonmatching _vectorAdd, 0x44

glabel _vectorAdd
    /* 55E28 800BE628 21108000 */  addu       $v0, $a0, $zero
    /* 55E2C 800BE62C 0000A38C */  lw         $v1, 0x0($a1)
    /* 55E30 800BE630 0000C48C */  lw         $a0, 0x0($a2)
    /* 55E34 800BE634 00000000 */  nop
    /* 55E38 800BE638 21186400 */  addu       $v1, $v1, $a0
    /* 55E3C 800BE63C 000043AC */  sw         $v1, 0x0($v0)
    /* 55E40 800BE640 0400A38C */  lw         $v1, 0x4($a1)
    /* 55E44 800BE644 0400C48C */  lw         $a0, 0x4($a2)
    /* 55E48 800BE648 00000000 */  nop
    /* 55E4C 800BE64C 21186400 */  addu       $v1, $v1, $a0
    /* 55E50 800BE650 040043AC */  sw         $v1, 0x4($v0)
    /* 55E54 800BE654 0800A38C */  lw         $v1, 0x8($a1)
    /* 55E58 800BE658 0800C48C */  lw         $a0, 0x8($a2)
    /* 55E5C 800BE65C 00000000 */  nop
    /* 55E60 800BE660 21186400 */  addu       $v1, $v1, $a0
    /* 55E64 800BE664 0800E003 */  jr         $ra
    /* 55E68 800BE668 080043AC */   sw        $v1, 0x8($v0)
endlabel _vectorAdd
