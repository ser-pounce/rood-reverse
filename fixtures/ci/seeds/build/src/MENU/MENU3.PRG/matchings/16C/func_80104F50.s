nonmatching func_80104F50, 0x44

glabel func_80104F50
    /* 2750 80104F50 05000224 */  addiu      $v0, $zero, 0x5
    /* 2754 80104F54 0D008214 */  bne        $a0, $v0, .L80104F8C
    /* 2758 80104F58 21180000 */   addu      $v1, $zero, $zero
    /* 275C 80104F5C 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 2760 80104F60 68014224 */  addiu      $v0, $v0, %lo(vs_battle_inventory)
    /* 2764 80104F64 C0180500 */  sll        $v1, $a1, 3
    /* 2768 80104F68 23186500 */  subu       $v1, $v1, $a1
    /* 276C 80104F6C 80180300 */  sll        $v1, $v1, 2
    /* 2770 80104F70 21186200 */  addu       $v1, $v1, $v0
    /* 2774 80104F74 D8086394 */  lhu        $v1, 0x8D8($v1)
    /* 2778 80104F78 00000000 */  nop
    /* 277C 80104F7C 80006230 */  andi       $v0, $v1, 0x80
    /* 2780 80104F80 02004014 */  bnez       $v0, .L80104F8C
    /* 2784 80104F84 00000000 */   nop
    /* 2788 80104F88 21180000 */  addu       $v1, $zero, $zero
  .L80104F8C:
    /* 278C 80104F8C 0800E003 */  jr         $ra
    /* 2790 80104F90 7F006230 */   andi      $v0, $v1, 0x7F
endlabel func_80104F50
