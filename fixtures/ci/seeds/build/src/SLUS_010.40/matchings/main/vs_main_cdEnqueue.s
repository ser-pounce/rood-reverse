nonmatching vs_main_cdEnqueue, 0x30

glabel vs_main_cdEnqueue
    /* 353C4 80044BC4 03000224 */  addiu      $v0, $zero, 0x3
    /* 353C8 80044BC8 000082A4 */  sh         $v0, 0x0($a0)
    /* 353CC 80044BCC 0580023C */  lui        $v0, %hi(_cdQueueCount)
    /* 353D0 80044BD0 60044224 */  addiu      $v0, $v0, %lo(_cdQueueCount)
    /* 353D4 80044BD4 100085AC */  sw         $a1, 0x10($a0)
    /* 353D8 80044BD8 0C0080AC */  sw         $zero, 0xC($a0)
    /* 353DC 80044BDC 02004594 */  lhu        $a1, 0x2($v0)
    /* 353E0 80044BE0 00000000 */  nop
    /* 353E4 80044BE4 0100A324 */  addiu      $v1, $a1, 0x1
    /* 353E8 80044BE8 020043A4 */  sh         $v1, 0x2($v0)
    /* 353EC 80044BEC 0800E003 */  jr         $ra
    /* 353F0 80044BF0 020085A4 */   sh        $a1, 0x2($a0)
endlabel vs_main_cdEnqueue
