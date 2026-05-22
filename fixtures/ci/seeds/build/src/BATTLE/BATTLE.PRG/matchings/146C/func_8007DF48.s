nonmatching func_8007DF48, 0x50

glabel func_8007DF48
    /* 15748 8007DF48 1F000324 */  addiu      $v1, $zero, 0x1F
    /* 1574C 8007DF4C 0F80023C */  lui        $v0, %hi(D_800F19A8)
    /* 15750 8007DF50 A8194224 */  addiu      $v0, $v0, %lo(D_800F19A8)
    /* 15754 8007DF54 21104300 */  addu       $v0, $v0, $v1
  .L8007DF58:
    /* 15758 8007DF58 000040A0 */  sb         $zero, 0x0($v0)
    /* 1575C 8007DF5C FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 15760 8007DF60 FDFF6104 */  bgez       $v1, .L8007DF58
    /* 15764 8007DF64 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 15768 8007DF68 FF000424 */  addiu      $a0, $zero, 0xFF
    /* 1576C 8007DF6C 18000324 */  addiu      $v1, $zero, 0x18
    /* 15770 8007DF70 0F80023C */  lui        $v0, %hi(D_800F19A8)
    /* 15774 8007DF74 A8194224 */  addiu      $v0, $v0, %lo(D_800F19A8)
    /* 15778 8007DF78 21104300 */  addu       $v0, $v0, $v1
  .L8007DF7C:
    /* 1577C 8007DF7C 000044A0 */  sb         $a0, 0x0($v0)
    /* 15780 8007DF80 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 15784 8007DF84 FDFF6104 */  bgez       $v1, .L8007DF7C
    /* 15788 8007DF88 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 1578C 8007DF8C 0F80023C */  lui        $v0, %hi(D_800F18F8)
    /* 15790 8007DF90 0800E003 */  jr         $ra
    /* 15794 8007DF94 F81840A0 */   sb        $zero, %lo(D_800F18F8)($v0)
endlabel func_8007DF48
