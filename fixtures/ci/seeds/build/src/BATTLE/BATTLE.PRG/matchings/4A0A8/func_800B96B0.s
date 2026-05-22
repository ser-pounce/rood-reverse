nonmatching func_800B96B0, 0x74

glabel func_800B96B0
    /* 50EB0 800B96B0 0F80023C */  lui        $v0, %hi(D_800F4C58)
    /* 50EB4 800B96B4 584C4224 */  addiu      $v0, $v0, %lo(D_800F4C58)
    /* 50EB8 800B96B8 002C0500 */  sll        $a1, $a1, 16
    /* 50EBC 800B96BC C32B0500 */  sra        $a1, $a1, 15
    /* 50EC0 800B96C0 2128A200 */  addu       $a1, $a1, $v0
    /* 50EC4 800B96C4 0000A284 */  lh         $v0, 0x0($a1)
    /* 50EC8 800B96C8 0000A694 */  lhu        $a2, 0x0($a1)
    /* 50ECC 800B96CC 05004014 */  bnez       $v0, .L800B96E4
    /* 50ED0 800B96D0 0680073C */   lui       $a3, %hi(vs_main_buttonsPressed)
    /* 50ED4 800B96D4 02008390 */  lbu        $v1, 0x2($a0)
    /* 50ED8 800B96D8 01000224 */  addiu      $v0, $zero, 0x1
    /* 50EDC 800B96DC 0800E003 */  jr         $ra
    /* 50EE0 800B96E0 0000A3A4 */   sh        $v1, 0x0($a1)
  .L800B96E4:
    /* 50EE4 800B96E4 01008390 */  lbu        $v1, 0x1($a0)
    /* 50EE8 800B96E8 D0E1E28C */  lw         $v0, %lo(vs_main_buttonsPressed)($a3)
    /* 50EEC 800B96EC 00000000 */  nop
    /* 50EF0 800B96F0 24104300 */  and        $v0, $v0, $v1
    /* 50EF4 800B96F4 06004014 */  bnez       $v0, .L800B9710
    /* 50EF8 800B96F8 21100000 */   addu      $v0, $zero, $zero
    /* 50EFC 800B96FC FFFFC224 */  addiu      $v0, $a2, -0x1
    /* 50F00 800B9700 0000A2A4 */  sh         $v0, 0x0($a1)
    /* 50F04 800B9704 00140200 */  sll        $v0, $v0, 16
    /* 50F08 800B9708 0400401C */  bgtz       $v0, .L800B971C
    /* 50F0C 800B970C 21100000 */   addu      $v0, $zero, $zero
  .L800B9710:
    /* 50F10 800B9710 0000A0A4 */  sh         $zero, 0x0($a1)
    /* 50F14 800B9714 0800E003 */  jr         $ra
    /* 50F18 800B9718 D0E1E0AC */   sw        $zero, %lo(vs_main_buttonsPressed)($a3)
  .L800B971C:
    /* 50F1C 800B971C 0800E003 */  jr         $ra
    /* 50F20 800B9720 01000224 */   addiu     $v0, $zero, 0x1
endlabel func_800B96B0
