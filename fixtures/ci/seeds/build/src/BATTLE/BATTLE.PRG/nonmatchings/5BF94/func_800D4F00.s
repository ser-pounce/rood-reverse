nonmatching func_800D4F00, 0xB4

glabel func_800D4F00
    /* 6C700 800D4F00 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6C704 800D4F04 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6C708 800D4F08 21808000 */  addu       $s0, $a0, $zero
    /* 6C70C 800D4F0C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6C710 800D4F10 5C54030C */  jal        func_800D5170
    /* 6C714 800D4F14 1400B1AF */   sw        $s1, 0x14($sp)
    /* 6C718 800D4F18 21200002 */  addu       $a0, $s0, $zero
    /* 6C71C 800D4F1C 5C54030C */  jal        func_800D5170
    /* 6C720 800D4F20 21884000 */   addu      $s1, $v0, $zero
    /* 6C724 800D4F24 21200002 */  addu       $a0, $s0, $zero
    /* 6C728 800D4F28 5C54030C */  jal        func_800D5170
    /* 6C72C 800D4F2C 21804000 */   addu      $s0, $v0, $zero
    /* 6C730 800D4F30 21284000 */  addu       $a1, $v0, $zero
    /* 6C734 800D4F34 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C738 800D4F38 0F80063C */  lui        $a2, %hi(D_800F569C)
    /* 6C73C 800D4F3C 3F002432 */  andi       $a0, $s1, 0x3F
    /* 6C740 800D4F40 04184400 */  sllv       $v1, $a0, $v0
    /* 6C744 800D4F44 21186400 */  addu       $v1, $v1, $a0
    /* 6C748 800D4F48 00210300 */  sll        $a0, $v1, 4
    /* 6C74C 800D4F4C 21186400 */  addu       $v1, $v1, $a0
    /* 6C750 800D4F50 80180300 */  sll        $v1, $v1, 2
    /* 6C754 800D4F54 04006324 */  addiu      $v1, $v1, 0x4
    /* 6C758 800D4F58 9C56C48C */  lw         $a0, %lo(D_800F569C)($a2)
    /* 6C75C 800D4F5C FF003132 */  andi       $s1, $s1, 0xFF
    /* 6C760 800D4F60 0800848C */  lw         $a0, 0x8($a0)
    /* 6C764 800D4F64 82891100 */  srl        $s1, $s1, 6
    /* 6C768 800D4F68 21208300 */  addu       $a0, $a0, $v1
    /* 6C76C 800D4F6C 0F000332 */  andi       $v1, $s0, 0xF
    /* 6C770 800D4F70 80180300 */  sll        $v1, $v1, 2
    /* 6C774 800D4F74 21882302 */  addu       $s1, $s1, $v1
    /* 6C778 800D4F78 FF001032 */  andi       $s0, $s0, 0xFF
    /* 6C77C 800D4F7C 02811000 */  srl        $s0, $s0, 4
    /* 6C780 800D4F80 0300A330 */  andi       $v1, $a1, 0x3
    /* 6C784 800D4F84 00190300 */  sll        $v1, $v1, 4
    /* 6C788 800D4F88 21800302 */  addu       $s0, $s0, $v1
    /* 6C78C 800D4F8C FF00A530 */  andi       $a1, $a1, 0xFF
    /* 6C790 800D4F90 82280500 */  srl        $a1, $a1, 2
    /* 6C794 800D4F94 C40091A0 */  sb         $s1, 0xC4($a0)
    /* 6C798 800D4F98 C50090A0 */  sb         $s0, 0xC5($a0)
    /* 6C79C 800D4F9C C60085A0 */  sb         $a1, 0xC6($a0)
    /* 6C7A0 800D4FA0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6C7A4 800D4FA4 1400B18F */  lw         $s1, 0x14($sp)
    /* 6C7A8 800D4FA8 1000B08F */  lw         $s0, 0x10($sp)
    /* 6C7AC 800D4FAC 0800E003 */  jr         $ra
    /* 6C7B0 800D4FB0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800D4F00
