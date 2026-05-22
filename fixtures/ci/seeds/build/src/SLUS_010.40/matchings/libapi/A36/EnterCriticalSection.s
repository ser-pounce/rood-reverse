/* Handwritten function */
nonmatching EnterCriticalSection, 0x10

glabel EnterCriticalSection
    /* 17174 80026974 01000424 */  addiu      $a0, $zero, 0x1
    /* 17178 80026978 0C000000 */  syscall    0 /* handwritten instruction */
    /* 1717C 8002697C 0800E003 */  jr         $ra
    /* 17180 80026980 00000000 */   nop
endlabel EnterCriticalSection
