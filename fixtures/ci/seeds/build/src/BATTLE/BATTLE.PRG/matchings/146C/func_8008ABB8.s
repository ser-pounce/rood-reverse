nonmatching func_8008ABB8, 0x38

glabel func_8008ABB8
    /* 223B8 8008ABB8 0F80023C */  lui        $v0, %hi(vs_battle_roomData)
    /* 223BC 8008ABBC F81B4524 */  addiu      $a1, $v0, %lo(vs_battle_roomData)
    /* 223C0 8008ABC0 F81B4390 */  lbu        $v1, %lo(vs_battle_roomData)($v0)
    /* 223C4 8008ABC4 01000224 */  addiu      $v0, $zero, 0x1
    /* 223C8 8008ABC8 07006214 */  bne        $v1, $v0, .L8008ABE8
    /* 223CC 8008ABCC 00000000 */   nop
    /* 223D0 8008ABD0 0200A284 */  lh         $v0, 0x2($a1)
    /* 223D4 8008ABD4 00000000 */  nop
    /* 223D8 8008ABD8 03004414 */  bne        $v0, $a0, .L8008ABE8
    /* 223DC 8008ABDC 01000224 */   addiu     $v0, $zero, 0x1
    /* 223E0 8008ABE0 0800E003 */  jr         $ra
    /* 223E4 8008ABE4 0100A0A0 */   sb        $zero, 0x1($a1)
  .L8008ABE8:
    /* 223E8 8008ABE8 0800E003 */  jr         $ra
    /* 223EC 8008ABEC 21100000 */   addu      $v0, $zero, $zero
endlabel func_8008ABB8
