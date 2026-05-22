nonmatching vs_battle_lerp, 0x24

glabel vs_battle_lerp
    /* 68E78 800D1678 2328A400 */  subu       $a1, $a1, $a0
    /* 68E7C 800D167C 1800A600 */  mult       $a1, $a2
    /* 68E80 800D1680 12100000 */  mflo       $v0
    /* 68E84 800D1684 02004104 */  bgez       $v0, .L800D1690
    /* 68E88 800D1688 00000000 */   nop
    /* 68E8C 800D168C FF1F4224 */  addiu      $v0, $v0, 0x1FFF
  .L800D1690:
    /* 68E90 800D1690 43130200 */  sra        $v0, $v0, 13
    /* 68E94 800D1694 0800E003 */  jr         $ra
    /* 68E98 800D1698 21108200 */   addu      $v0, $a0, $v0
endlabel vs_battle_lerp
