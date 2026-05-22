nonmatching func_800C1664, 0x78

glabel func_800C1664
    /* 58E64 800C1664 0F80073C */  lui        $a3, %hi(D_800EB9B8)
    /* 58E68 800C1668 B8B9E38C */  lw         $v1, %lo(D_800EB9B8)($a3)
    /* 58E6C 800C166C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 58E70 800C1670 16006010 */  beqz       $v1, .L800C16CC
    /* 58E74 800C1674 1000BFAF */   sw        $ra, 0x10($sp)
    /* 58E78 800C1678 19008228 */  slti       $v0, $a0, 0x19
    /* 58E7C 800C167C 02004014 */  bnez       $v0, .L800C1688
    /* 58E80 800C1680 00000000 */   nop
    /* 58E84 800C1684 18000424 */  addiu      $a0, $zero, 0x18
  .L800C1688:
    /* 58E88 800C1688 2C0064A0 */  sb         $a0, 0x2C($v1)
    /* 58E8C 800C168C B8B9E38C */  lw         $v1, %lo(D_800EB9B8)($a3)
    /* 58E90 800C1690 00000000 */  nop
    /* 58E94 800C1694 2D006290 */  lbu        $v0, 0x2D($v1)
    /* 58E98 800C1698 00000000 */  nop
    /* 58E9C 800C169C 2A104400 */  slt        $v0, $v0, $a0
    /* 58EA0 800C16A0 05004014 */  bnez       $v0, .L800C16B8
    /* 58EA4 800C16A4 400065AC */   sw        $a1, 0x40($v1)
    /* 58EA8 800C16A8 02008014 */  bnez       $a0, .L800C16B4
    /* 58EAC 800C16AC 21100000 */   addu      $v0, $zero, $zero
    /* 58EB0 800C16B0 FF000224 */  addiu      $v0, $zero, 0xFF
  .L800C16B4:
    /* 58EB4 800C16B4 2D0062A0 */  sb         $v0, 0x2D($v1)
  .L800C16B8:
    /* 58EB8 800C16B8 0F80023C */  lui        $v0, %hi(D_800EB9B8)
    /* 58EBC 800C16BC B8B9428C */  lw         $v0, %lo(D_800EB9B8)($v0)
    /* 58EC0 800C16C0 21200000 */  addu       $a0, $zero, $zero
    /* 58EC4 800C16C4 3E16030C */  jal        func_800C58F8
    /* 58EC8 800C16C8 310046A0 */   sb        $a2, 0x31($v0)
  .L800C16CC:
    /* 58ECC 800C16CC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 58ED0 800C16D0 00000000 */  nop
    /* 58ED4 800C16D4 0800E003 */  jr         $ra
    /* 58ED8 800C16D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800C1664
