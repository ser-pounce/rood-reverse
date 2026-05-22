nonmatching bzero, 0xC

glabel bzero
    /* 1EB24 8002E324 A0000A24 */  addiu      $t2, $zero, 0xA0
    /* 1EB28 8002E328 08004001 */  jr         $t2
    /* 1EB2C 8002E32C 28000924 */   addiu     $t1, $zero, 0x28
endlabel bzero
    /* 1EB30 8002E330 00000000 */  nop
