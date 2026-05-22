nonmatching func_8008E3B8, 0x48

glabel func_8008E3B8
    /* 25BB8 8008E3B8 0F80023C */  lui        $v0, %hi(vs_battle_roomData)
    /* 25BBC 8008E3BC F81B4524 */  addiu      $a1, $v0, %lo(vs_battle_roomData)
    /* 25BC0 8008E3C0 8800A28C */  lw         $v0, 0x88($a1)
    /* 25BC4 8008E3C4 00000000 */  nop
    /* 25BC8 8008E3C8 03004014 */  bnez       $v0, .L8008E3D8
    /* 25BCC 8008E3CC 21100000 */   addu      $v0, $zero, $zero
    /* 25BD0 8008E3D0 0800E003 */  jr         $ra
    /* 25BD4 8008E3D4 000080AC */   sw        $zero, 0x0($a0)
  .L8008E3D8:
    /* 25BD8 8008E3D8 2800A38C */  lw         $v1, 0x28($a1)
    /* 25BDC 8008E3DC CCCC023C */  lui        $v0, (0xCCCCCCCD >> 16)
    /* 25BE0 8008E3E0 CDCC4234 */  ori        $v0, $v0, (0xCCCCCCCD & 0xFFFF)
    /* 25BE4 8008E3E4 19006200 */  multu      $v1, $v0
    /* 25BE8 8008E3E8 10300000 */  mfhi       $a2
    /* 25BEC 8008E3EC 02110600 */  srl        $v0, $a2, 4
    /* 25BF0 8008E3F0 000082AC */  sw         $v0, 0x0($a0)
    /* 25BF4 8008E3F4 8800A28C */  lw         $v0, 0x88($a1)
    /* 25BF8 8008E3F8 0800E003 */  jr         $ra
    /* 25BFC 8008E3FC 00000000 */   nop
endlabel func_8008E3B8
