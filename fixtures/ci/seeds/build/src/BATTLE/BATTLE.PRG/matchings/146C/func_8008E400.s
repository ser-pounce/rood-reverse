nonmatching func_8008E400, 0x70

glabel func_8008E400
    /* 25C00 8008E400 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* 25C04 8008E404 98154324 */  addiu      $v1, $v0, %lo(vs_main_stateFlags)
    /* 25C08 8008E408 20006290 */  lbu        $v0, 0x20($v1)
    /* 25C0C 8008E40C 00000000 */  nop
    /* 25C10 8008E410 05004014 */  bnez       $v0, .L8008E428
    /* 25C14 8008E414 00000000 */   nop
    /* 25C18 8008E418 40006290 */  lbu        $v0, 0x40($v1)
    /* 25C1C 8008E41C 00000000 */  nop
    /* 25C20 8008E420 04004010 */  beqz       $v0, .L8008E434
    /* 25C24 8008E424 0F80023C */   lui       $v0, %hi(vs_battle_roomData)
  .L8008E428:
    /* 25C28 8008E428 000080AC */  sw         $zero, 0x0($a0)
    /* 25C2C 8008E42C 0800E003 */  jr         $ra
    /* 25C30 8008E430 21100000 */   addu      $v0, $zero, $zero
  .L8008E434:
    /* 25C34 8008E434 F81B4524 */  addiu      $a1, $v0, %lo(vs_battle_roomData)
    /* 25C38 8008E438 8400A28C */  lw         $v0, 0x84($a1)
    /* 25C3C 8008E43C 00000000 */  nop
    /* 25C40 8008E440 F9FF4010 */  beqz       $v0, .L8008E428
    /* 25C44 8008E444 00000000 */   nop
    /* 25C48 8008E448 2400A38C */  lw         $v1, 0x24($a1)
    /* 25C4C 8008E44C AAAA023C */  lui        $v0, (0xAAAAAAAB >> 16)
    /* 25C50 8008E450 ABAA4234 */  ori        $v0, $v0, (0xAAAAAAAB & 0xFFFF)
    /* 25C54 8008E454 19006200 */  multu      $v1, $v0
    /* 25C58 8008E458 10300000 */  mfhi       $a2
    /* 25C5C 8008E45C C2100600 */  srl        $v0, $a2, 3
    /* 25C60 8008E460 000082AC */  sw         $v0, 0x0($a0)
    /* 25C64 8008E464 8400A28C */  lw         $v0, 0x84($a1)
    /* 25C68 8008E468 0800E003 */  jr         $ra
    /* 25C6C 8008E46C 00000000 */   nop
endlabel func_8008E400
