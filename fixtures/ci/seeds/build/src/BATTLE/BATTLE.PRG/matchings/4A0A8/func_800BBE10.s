nonmatching func_800BBE10, 0x84

glabel func_800BBE10
    /* 53610 800BBE10 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 53614 800BBE14 2400B1AF */  sw         $s1, 0x24($sp)
    /* 53618 800BBE18 21888000 */  addu       $s1, $a0, $zero
    /* 5361C 800BBE1C FFFF2332 */  andi       $v1, $s1, 0xFFFF
    /* 53620 800BBE20 00200224 */  addiu      $v0, $zero, 0x2000
    /* 53624 800BBE24 2800BFAF */  sw         $ra, 0x28($sp)
    /* 53628 800BBE28 11006214 */  bne        $v1, $v0, .L800BBE70
    /* 5362C 800BBE2C 2000B0AF */   sw        $s0, 0x20($sp)
    /* 53630 800BBE30 0F80103C */  lui        $s0, %hi(D_800F4BA4)
    /* 53634 800BBE34 A44B068E */  lw         $a2, %lo(D_800F4BA4)($s0)
    /* 53638 800BBE38 00000000 */  nop
    /* 5363C 800BBE3C E801C294 */  lhu        $v0, 0x1E8($a2)
    /* 53640 800BBE40 00000000 */  nop
    /* 53644 800BBE44 0A004310 */  beq        $v0, $v1, .L800BBE70
    /* 53648 800BBE48 4801C424 */   addiu     $a0, $a2, 0x148
    /* 5364C 800BBE4C 21288000 */  addu       $a1, $a0, $zero
    /* 53650 800BBE50 8AF9020C */  jal        _vectorAdd
    /* 53654 800BBE54 EC01C624 */   addiu     $a2, $a2, 0x1EC
    /* 53658 800BBE58 A44B068E */  lw         $a2, %lo(D_800F4BA4)($s0)
    /* 5365C 800BBE5C 00000000 */  nop
    /* 53660 800BBE60 9400C424 */  addiu      $a0, $a2, 0x94
    /* 53664 800BBE64 21288000 */  addu       $a1, $a0, $zero
    /* 53668 800BBE68 8AF9020C */  jal        _vectorAdd
    /* 5366C 800BBE6C EC01C624 */   addiu     $a2, $a2, 0x1EC
  .L800BBE70:
    /* 53670 800BBE70 0F80023C */  lui        $v0, %hi(D_800F4BA4)
    /* 53674 800BBE74 A44B428C */  lw         $v0, %lo(D_800F4BA4)($v0)
    /* 53678 800BBE78 A5EF020C */  jal        func_800BBE94
    /* 5367C 800BBE7C E80151A4 */   sh        $s1, 0x1E8($v0)
    /* 53680 800BBE80 2800BF8F */  lw         $ra, 0x28($sp)
    /* 53684 800BBE84 2400B18F */  lw         $s1, 0x24($sp)
    /* 53688 800BBE88 2000B08F */  lw         $s0, 0x20($sp)
    /* 5368C 800BBE8C 0800E003 */  jr         $ra
    /* 53690 800BBE90 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800BBE10
