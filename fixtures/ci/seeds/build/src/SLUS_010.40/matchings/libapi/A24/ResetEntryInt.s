nonmatching ResetEntryInt, 0xC

glabel ResetEntryInt
    /* 17144 80026944 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 17148 80026948 08004001 */  jr         $t2
    /* 1714C 8002694C 18000924 */   addiu     $t1, $zero, 0x18
endlabel ResetEntryInt
    /* 17150 80026950 00000000 */  nop
