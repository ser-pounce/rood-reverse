nonmatching func_8009E480, 0x30

glabel func_8009E480
    /* 35C80 8009E480 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 35C84 8009E484 3845428C */  lw         $v0, %lo(D_800F4538)($v0)
    /* 35C88 8009E488 00000000 */  nop
    /* 35C8C 8009E48C B8054390 */  lbu        $v1, 0x5B8($v0)
    /* 35C90 8009E490 63000224 */  addiu      $v0, $zero, 0x63
    /* 35C94 8009E494 03006210 */  beq        $v1, $v0, .L8009E4A4
    /* 35C98 8009E498 C7006238 */   xori      $v0, $v1, 0xC7
    /* 35C9C 8009E49C 2A790208 */  j          .L8009E4A8
    /* 35CA0 8009E4A0 0100422C */   sltiu     $v0, $v0, 0x1
  .L8009E4A4:
    /* 35CA4 8009E4A4 01000224 */  addiu      $v0, $zero, 0x1
  .L8009E4A8:
    /* 35CA8 8009E4A8 0800E003 */  jr         $ra
    /* 35CAC 8009E4AC 00000000 */   nop
endlabel func_8009E480
