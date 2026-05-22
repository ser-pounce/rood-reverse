nonmatching func_80102C94, 0x44

glabel func_80102C94
    /* 494 80102C94 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 498 80102C98 06008010 */  beqz       $a0, .L80102CB4
    /* 49C 80102C9C 1000BFAF */   sw        $ra, 0x10($sp)
    /* 4A0 80102CA0 A2FE030C */  jal        func_800FFA88
    /* 4A4 80102CA4 02000424 */   addiu     $a0, $zero, 0x2
    /* 4A8 80102CA8 1080023C */  lui        $v0, %hi(D_801022D6)
    /* 4AC 80102CAC 320B0408 */  j          .L80102CC8
    /* 4B0 80102CB0 D62240A0 */   sb        $zero, %lo(D_801022D6)($v0)
  .L80102CB4:
    /* 4B4 80102CB4 A2FE030C */  jal        func_800FFA88
    /* 4B8 80102CB8 21200000 */   addu      $a0, $zero, $zero
    /* 4BC 80102CBC 1080033C */  lui        $v1, %hi(D_801022D6)
    /* 4C0 80102CC0 01000224 */  addiu      $v0, $zero, 0x1
    /* 4C4 80102CC4 D62262A0 */  sb         $v0, %lo(D_801022D6)($v1)
  .L80102CC8:
    /* 4C8 80102CC8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4CC 80102CCC 00000000 */  nop
    /* 4D0 80102CD0 0800E003 */  jr         $ra
    /* 4D4 80102CD4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80102C94
