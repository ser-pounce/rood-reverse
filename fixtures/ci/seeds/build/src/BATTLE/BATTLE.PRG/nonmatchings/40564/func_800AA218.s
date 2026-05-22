nonmatching func_800AA218, 0x78

glabel func_800AA218
    /* 41A18 800AA218 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 41A1C 800AA21C 0F80033C */  lui        $v1, %hi(D_800F4538)
    /* 41A20 800AA220 38456324 */  addiu      $v1, $v1, %lo(D_800F4538)
    /* 41A24 800AA224 80100400 */  sll        $v0, $a0, 2
    /* 41A28 800AA228 21104300 */  addu       $v0, $v0, $v1
    /* 41A2C 800AA22C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 41A30 800AA230 1400B1AF */  sw         $s1, 0x14($sp)
    /* 41A34 800AA234 1000B0AF */  sw         $s0, 0x10($sp)
    /* 41A38 800AA238 0000508C */  lw         $s0, 0x0($v0)
    /* 41A3C 800AA23C 00000000 */  nop
    /* 41A40 800AA240 0D000012 */  beqz       $s0, .L800AA278
    /* 41A44 800AA244 2188A000 */   addu      $s1, $a1, $zero
    /* 41A48 800AA248 C2050796 */  lhu        $a3, 0x5C2($s0)
    /* 41A4C 800AA24C A4A8020C */  jal        func_800AA290
    /* 41A50 800AA250 00000000 */   nop
    /* 41A54 800AA254 00002292 */  lbu        $v0, 0x0($s1)
    /* 41A58 800AA258 00000000 */  nop
    /* 41A5C 800AA25C 5C0002A2 */  sb         $v0, 0x5C($s0)
    /* 41A60 800AA260 01002292 */  lbu        $v0, 0x1($s1)
    /* 41A64 800AA264 00000000 */  nop
    /* 41A68 800AA268 5D0002A2 */  sb         $v0, 0x5D($s0)
    /* 41A6C 800AA26C 02002292 */  lbu        $v0, 0x2($s1)
    /* 41A70 800AA270 00000000 */  nop
    /* 41A74 800AA274 5E0002A2 */  sb         $v0, 0x5E($s0)
  .L800AA278:
    /* 41A78 800AA278 1800BF8F */  lw         $ra, 0x18($sp)
    /* 41A7C 800AA27C 1400B18F */  lw         $s1, 0x14($sp)
    /* 41A80 800AA280 1000B08F */  lw         $s0, 0x10($sp)
    /* 41A84 800AA284 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 41A88 800AA288 0800E003 */  jr         $ra
    /* 41A8C 800AA28C 00000000 */   nop
endlabel func_800AA218
