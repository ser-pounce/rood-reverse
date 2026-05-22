nonmatching func_800BB474, 0x58

glabel func_800BB474
    /* 52C74 800BB474 0F80023C */  lui        $v0, %hi(D_800F4C58)
    /* 52C78 800BB478 584C4224 */  addiu      $v0, $v0, %lo(D_800F4C58)
    /* 52C7C 800BB47C 002C0500 */  sll        $a1, $a1, 16
    /* 52C80 800BB480 C32B0500 */  sra        $a1, $a1, 15
    /* 52C84 800BB484 2128A200 */  addu       $a1, $a1, $v0
    /* 52C88 800BB488 0000A284 */  lh         $v0, 0x0($a1)
    /* 52C8C 800BB48C 0000A394 */  lhu        $v1, 0x0($a1)
    /* 52C90 800BB490 05004014 */  bnez       $v0, .L800BB4A8
    /* 52C94 800BB494 FFFF6224 */   addiu     $v0, $v1, -0x1
    /* 52C98 800BB498 01008390 */  lbu        $v1, 0x1($a0)
    /* 52C9C 800BB49C 01000224 */  addiu      $v0, $zero, 0x1
    /* 52CA0 800BB4A0 0800E003 */  jr         $ra
    /* 52CA4 800BB4A4 0000A3A4 */   sh        $v1, 0x0($a1)
  .L800BB4A8:
    /* 52CA8 800BB4A8 0000A2A4 */  sh         $v0, 0x0($a1)
    /* 52CAC 800BB4AC 00140200 */  sll        $v0, $v0, 16
    /* 52CB0 800BB4B0 0400401C */  bgtz       $v0, .L800BB4C4
    /* 52CB4 800BB4B4 01000224 */   addiu     $v0, $zero, 0x1
    /* 52CB8 800BB4B8 0000A0A4 */  sh         $zero, 0x0($a1)
    /* 52CBC 800BB4BC 0800E003 */  jr         $ra
    /* 52CC0 800BB4C0 21100000 */   addu      $v0, $zero, $zero
  .L800BB4C4:
    /* 52CC4 800BB4C4 0800E003 */  jr         $ra
    /* 52CC8 800BB4C8 00000000 */   nop
endlabel func_800BB474
