nonmatching memset, 0xC

glabel memset
    /* 176B4 80026EB4 A0000A24 */  addiu      $t2, $zero, 0xA0
    /* 176B8 80026EB8 08004001 */  jr         $t2
    /* 176BC 80026EBC 2B000924 */   addiu     $t1, $zero, 0x2B
endlabel memset
    /* 176C0 80026EC0 00000000 */  nop
