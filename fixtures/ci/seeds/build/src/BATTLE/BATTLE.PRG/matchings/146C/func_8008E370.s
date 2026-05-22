nonmatching func_8008E370, 0x48

glabel func_8008E370
    /* 25B70 8008E370 0F80023C */  lui        $v0, %hi(vs_battle_roomData)
    /* 25B74 8008E374 F81B4524 */  addiu      $a1, $v0, %lo(vs_battle_roomData)
    /* 25B78 8008E378 AC00A28C */  lw         $v0, 0xAC($a1)
    /* 25B7C 8008E37C 00000000 */  nop
    /* 25B80 8008E380 04004014 */  bnez       $v0, .L8008E394
    /* 25B84 8008E384 193A033C */   lui       $v1, (0x3A196B1F >> 16)
    /* 25B88 8008E388 000080AC */  sw         $zero, 0x0($a0)
    /* 25B8C 8008E38C 0800E003 */  jr         $ra
    /* 25B90 8008E390 21100000 */   addu      $v0, $zero, $zero
  .L8008E394:
    /* 25B94 8008E394 4C00A28C */  lw         $v0, 0x4C($a1)
    /* 25B98 8008E398 1F6B6334 */  ori        $v1, $v1, (0x3A196B1F & 0xFFFF)
    /* 25B9C 8008E39C 19004300 */  multu      $v0, $v1
    /* 25BA0 8008E3A0 10300000 */  mfhi       $a2
    /* 25BA4 8008E3A4 C2110600 */  srl        $v0, $a2, 7
    /* 25BA8 8008E3A8 000082AC */  sw         $v0, 0x0($a0)
    /* 25BAC 8008E3AC AC00A28C */  lw         $v0, 0xAC($a1)
    /* 25BB0 8008E3B0 0800E003 */  jr         $ra
    /* 25BB4 8008E3B4 00000000 */   nop
endlabel func_8008E370
