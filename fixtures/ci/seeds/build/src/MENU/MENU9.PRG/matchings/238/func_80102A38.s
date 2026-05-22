nonmatching func_80102A38, 0x44

glabel func_80102A38
    /* 238 80102A38 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 23C 80102A3C 06008010 */  beqz       $a0, .L80102A58
    /* 240 80102A40 1000BFAF */   sw        $ra, 0x10($sp)
    /* 244 80102A44 A2FE030C */  jal        func_800FFA88
    /* 248 80102A48 02000424 */   addiu     $a0, $zero, 0x2
    /* 24C 80102A4C 1080023C */  lui        $v0, %hi(D_801022D6)
    /* 250 80102A50 9B0A0408 */  j          .L80102A6C
    /* 254 80102A54 D62240A0 */   sb        $zero, %lo(D_801022D6)($v0)
  .L80102A58:
    /* 258 80102A58 A2FE030C */  jal        func_800FFA88
    /* 25C 80102A5C 21200000 */   addu      $a0, $zero, $zero
    /* 260 80102A60 1080033C */  lui        $v1, %hi(D_801022D6)
    /* 264 80102A64 01000224 */  addiu      $v0, $zero, 0x1
    /* 268 80102A68 D62262A0 */  sb         $v0, %lo(D_801022D6)($v1)
  .L80102A6C:
    /* 26C 80102A6C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 270 80102A70 00000000 */  nop
    /* 274 80102A74 0800E003 */  jr         $ra
    /* 278 80102A78 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80102A38
