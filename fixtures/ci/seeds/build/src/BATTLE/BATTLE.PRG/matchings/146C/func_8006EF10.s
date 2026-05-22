nonmatching func_8006EF10, 0x4C

glabel func_8006EF10
    /* 6710 8006EF10 0F80023C */  lui        $v0, %hi(D_800F19EC)
    /* 6714 8006EF14 EC19438C */  lw         $v1, %lo(D_800F19EC)($v0)
    /* 6718 8006EF18 00000000 */  nop
    /* 671C 8006EF1C 0D006004 */  bltz       $v1, .L8006EF54
    /* 6720 8006EF20 02006228 */   slti      $v0, $v1, 0x2
    /* 6724 8006EF24 06004010 */  beqz       $v0, .L8006EF40
    /* 6728 8006EF28 04006228 */   slti      $v0, $v1, 0x4
    /* 672C 8006EF2C 0F80023C */  lui        $v0, %hi(D_800F19CC)
    /* 6730 8006EF30 CC19438C */  lw         $v1, %lo(D_800F19CC)($v0)
    /* 6734 8006EF34 00060224 */  addiu      $v0, $zero, 0x600
    /* 6738 8006EF38 0800E003 */  jr         $ra
    /* 673C 8006EF3C 0C2C62A4 */   sh        $v0, 0x2C0C($v1)
  .L8006EF40:
    /* 6740 8006EF40 04004010 */  beqz       $v0, .L8006EF54
    /* 6744 8006EF44 0F80023C */   lui       $v0, %hi(D_800F19CC)
    /* 6748 8006EF48 CC19438C */  lw         $v1, %lo(D_800F19CC)($v0)
    /* 674C 8006EF4C 00090224 */  addiu      $v0, $zero, 0x900
    /* 6750 8006EF50 0C2C62A4 */  sh         $v0, 0x2C0C($v1)
  .L8006EF54:
    /* 6754 8006EF54 0800E003 */  jr         $ra
    /* 6758 8006EF58 00000000 */   nop
endlabel func_8006EF10
