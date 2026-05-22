nonmatching vs_battle_lerpRatio, 0x34

glabel vs_battle_lerpRatio
    /* 68B5C 800D135C 00330600 */  sll        $a2, $a2, 12
    /* 68B60 800D1360 1A00C700 */  div        $zero, $a2, $a3
    /* 68B64 800D1364 12300000 */  mflo       $a2
    /* 68B68 800D1368 2328A400 */  subu       $a1, $a1, $a0
    /* 68B6C 800D136C 00000000 */  nop
    /* 68B70 800D1370 1800A600 */  mult       $a1, $a2
    /* 68B74 800D1374 12100000 */  mflo       $v0
    /* 68B78 800D1378 02004104 */  bgez       $v0, .L800D1384
    /* 68B7C 800D137C 00000000 */   nop
    /* 68B80 800D1380 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L800D1384:
    /* 68B84 800D1384 03130200 */  sra        $v0, $v0, 12
    /* 68B88 800D1388 0800E003 */  jr         $ra
    /* 68B8C 800D138C 21108200 */   addu      $v0, $a0, $v0
endlabel vs_battle_lerpRatio
