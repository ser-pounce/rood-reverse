nonmatching func_800B66F4, 0x30

glabel func_800B66F4
    /* 4DEF4 800B66F4 0F80023C */  lui        $v0, %hi(D_800F4BBC)
    /* 4DEF8 800B66F8 BC4B438C */  lw         $v1, %lo(D_800F4BBC)($v0)
    /* 4DEFC 800B66FC 00000000 */  nop
    /* 4DF00 800B6700 06006010 */  beqz       $v1, .L800B671C
    /* 4DF04 800B6704 21100000 */   addu      $v0, $zero, $zero
    /* 4DF08 800B6708 00006484 */  lh         $a0, 0x0($v1)
    /* 4DF0C 800B670C 04000324 */  addiu      $v1, $zero, 0x4
    /* 4DF10 800B6710 02008314 */  bne        $a0, $v1, .L800B671C
    /* 4DF14 800B6714 01000224 */   addiu     $v0, $zero, 0x1
    /* 4DF18 800B6718 21100000 */  addu       $v0, $zero, $zero
  .L800B671C:
    /* 4DF1C 800B671C 0800E003 */  jr         $ra
    /* 4DF20 800B6720 00000000 */   nop
endlabel func_800B66F4
