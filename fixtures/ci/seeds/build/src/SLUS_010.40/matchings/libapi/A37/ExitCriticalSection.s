/* Handwritten function */
nonmatching ExitCriticalSection, 0x10

glabel ExitCriticalSection
    /* 17184 80026984 02000424 */  addiu      $a0, $zero, 0x2
    /* 17188 80026988 0C000000 */  syscall    0 /* handwritten instruction */
    /* 1718C 8002698C 0800E003 */  jr         $ra
    /* 17190 80026990 00000000 */   nop
endlabel ExitCriticalSection
