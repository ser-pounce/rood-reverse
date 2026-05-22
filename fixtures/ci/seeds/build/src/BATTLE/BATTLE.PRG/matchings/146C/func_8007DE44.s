nonmatching func_8007DE44, 0x18

glabel func_8007DE44
    /* 15644 8007DE44 0008822C */  sltiu      $v0, $a0, 0x800
    /* 15648 8007DE48 02004010 */  beqz       $v0, .L8007DE54
    /* 1564C 8007DE4C 0F80023C */   lui       $v0, %hi(D_800F1A44)
    /* 15650 8007DE50 441A44AC */  sw         $a0, %lo(D_800F1A44)($v0)
  .L8007DE54:
    /* 15654 8007DE54 0800E003 */  jr         $ra
    /* 15658 8007DE58 00000000 */   nop
endlabel func_8007DE44
