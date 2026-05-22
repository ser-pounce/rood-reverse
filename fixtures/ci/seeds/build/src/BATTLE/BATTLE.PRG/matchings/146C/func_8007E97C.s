nonmatching func_8007E97C, 0x20

glabel func_8007E97C
    /* 1617C 8007E97C 0F80023C */  lui        $v0, %hi(D_800F1A04)
    /* 16180 8007E980 041A428C */  lw         $v0, %lo(D_800F1A04)($v0)
    /* 16184 8007E984 00000000 */  nop
    /* 16188 8007E988 02004010 */  beqz       $v0, .L8007E994
    /* 1618C 8007E98C FF000324 */   addiu     $v1, $zero, 0xFF
    /* 16190 8007E990 64000324 */  addiu      $v1, $zero, 0x64
  .L8007E994:
    /* 16194 8007E994 0800E003 */  jr         $ra
    /* 16198 8007E998 21106000 */   addu      $v0, $v1, $zero
endlabel func_8007E97C
