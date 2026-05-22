nonmatching func_8006C250, 0x50

glabel func_8006C250
    /* 3A50 8006C250 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3A54 8006C254 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3A58 8006C258 21800000 */  addu       $s0, $zero, $zero
    /* 3A5C 8006C25C 1400BFAF */  sw         $ra, 0x14($sp)
  .L8006C260:
    /* 3A60 8006C260 F882020C */  jal        func_800A0BE0
    /* 3A64 8006C264 21200002 */   addu      $a0, $s0, $zero
    /* 3A68 8006C268 21284000 */  addu       $a1, $v0, $zero
    /* 3A6C 8006C26C 0400A230 */  andi       $v0, $a1, 0x4
    /* 3A70 8006C270 03004014 */  bnez       $v0, .L8006C280
    /* 3A74 8006C274 21200002 */   addu      $a0, $s0, $zero
    /* 3A78 8006C278 1F82020C */  jal        func_800A087C
    /* 3A7C 8006C27C 0400A534 */   ori       $a1, $a1, 0x4
  .L8006C280:
    /* 3A80 8006C280 01001026 */  addiu      $s0, $s0, 0x1
    /* 3A84 8006C284 1000022A */  slti       $v0, $s0, 0x10
    /* 3A88 8006C288 F5FF4014 */  bnez       $v0, .L8006C260
    /* 3A8C 8006C28C 00000000 */   nop
    /* 3A90 8006C290 1400BF8F */  lw         $ra, 0x14($sp)
    /* 3A94 8006C294 1000B08F */  lw         $s0, 0x10($sp)
    /* 3A98 8006C298 0800E003 */  jr         $ra
    /* 3A9C 8006C29C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006C250
