nonmatching func_8008A4DC, 0x20

glabel func_8008A4DC
    /* 21CDC 8008A4DC 05008010 */  beqz       $a0, .L8008A4F4
    /* 21CE0 8008A4E0 0F80023C */   lui       $v0, %hi(D_800F190C)
    /* 21CE4 8008A4E4 0F80033C */  lui        $v1, %hi(D_800F190C)
    /* 21CE8 8008A4E8 01000224 */  addiu      $v0, $zero, 0x1
    /* 21CEC 8008A4EC 0800E003 */  jr         $ra
    /* 21CF0 8008A4F0 0C1962AC */   sw        $v0, %lo(D_800F190C)($v1)
  .L8008A4F4:
    /* 21CF4 8008A4F4 0800E003 */  jr         $ra
    /* 21CF8 8008A4F8 0C1940AC */   sw        $zero, %lo(D_800F190C)($v0)
endlabel func_8008A4DC
