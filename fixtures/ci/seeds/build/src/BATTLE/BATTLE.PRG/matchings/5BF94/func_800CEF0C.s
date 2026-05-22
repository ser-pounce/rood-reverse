nonmatching func_800CEF0C, 0x2C

glabel func_800CEF0C
    /* 6670C 800CEF0C 0F80023C */  lui        $v0, %hi(D_800F531C)
    /* 66710 800CEF10 1C53428C */  lw         $v0, %lo(D_800F531C)($v0)
    /* 66714 800CEF14 00000000 */  nop
    /* 66718 800CEF18 FCFF4224 */  addiu      $v0, $v0, -0x4
    /* 6671C 800CEF1C 0200422C */  sltiu      $v0, $v0, 0x2
    /* 66720 800CEF20 03004010 */  beqz       $v0, .L800CEF30
    /* 66724 800CEF24 21180000 */   addu      $v1, $zero, $zero
    /* 66728 800CEF28 0F80023C */  lui        $v0, %hi(D_800F5224)
    /* 6672C 800CEF2C 2452438C */  lw         $v1, %lo(D_800F5224)($v0)
  .L800CEF30:
    /* 66730 800CEF30 0800E003 */  jr         $ra
    /* 66734 800CEF34 21106000 */   addu      $v0, $v1, $zero
endlabel func_800CEF0C
