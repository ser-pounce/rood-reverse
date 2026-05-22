nonmatching func_80102CD8, 0x44

glabel func_80102CD8
    /* 4D8 80102CD8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4DC 80102CDC 06008010 */  beqz       $a0, .L80102CF8
    /* 4E0 80102CE0 1000BFAF */   sw        $ra, 0x10($sp)
    /* 4E4 80102CE4 A2FE030C */  jal        func_800FFA88
    /* 4E8 80102CE8 02000424 */   addiu     $a0, $zero, 0x2
    /* 4EC 80102CEC 1080023C */  lui        $v0, %hi(D_801022D6)
    /* 4F0 80102CF0 430B0408 */  j          .L80102D0C
    /* 4F4 80102CF4 D62240A0 */   sb        $zero, %lo(D_801022D6)($v0)
  .L80102CF8:
    /* 4F8 80102CF8 A2FE030C */  jal        func_800FFA88
    /* 4FC 80102CFC 21200000 */   addu      $a0, $zero, $zero
    /* 500 80102D00 1080033C */  lui        $v1, %hi(D_801022D6)
    /* 504 80102D04 01000224 */  addiu      $v0, $zero, 0x1
    /* 508 80102D08 D62262A0 */  sb         $v0, %lo(D_801022D6)($v1)
  .L80102D0C:
    /* 50C 80102D0C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 510 80102D10 00000000 */  nop
    /* 514 80102D14 0800E003 */  jr         $ra
    /* 518 80102D18 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80102CD8
