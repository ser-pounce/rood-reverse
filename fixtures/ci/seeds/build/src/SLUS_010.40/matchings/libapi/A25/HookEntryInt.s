nonmatching HookEntryInt, 0xC

glabel HookEntryInt
    /* 17154 80026954 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 17158 80026958 08004001 */  jr         $t2
    /* 1715C 8002695C 19000924 */   addiu     $t1, $zero, 0x19
endlabel HookEntryInt
    /* 17160 80026960 00000000 */  nop
