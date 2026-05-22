nonmatching func_8008E2D4, 0x4C

glabel func_8008E2D4
    /* 25AD4 8008E2D4 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0xA8)
    /* 25AD8 8008E2D8 A01C438C */  lw         $v1, %lo(vs_battle_roomData + 0xA8)($v0)
    /* 25ADC 8008E2DC 00000000 */  nop
    /* 25AE0 8008E2E0 03006014 */  bnez       $v1, .L8008E2F0
    /* 25AE4 8008E2E4 40100400 */   sll       $v0, $a0, 1
    /* 25AE8 8008E2E8 0800E003 */  jr         $ra
    /* 25AEC 8008E2EC 21100000 */   addu      $v0, $zero, $zero
  .L8008E2F0:
    /* 25AF0 8008E2F0 21104400 */  addu       $v0, $v0, $a0
    /* 25AF4 8008E2F4 C0100200 */  sll        $v0, $v0, 3
    /* 25AF8 8008E2F8 23104400 */  subu       $v0, $v0, $a0
    /* 25AFC 8008E2FC C0100200 */  sll        $v0, $v0, 3
    /* 25B00 8008E300 21186200 */  addu       $v1, $v1, $v0
    /* 25B04 8008E304 0000628C */  lw         $v0, 0x0($v1)
    /* 25B08 8008E308 00000000 */  nop
    /* 25B0C 8008E30C C2150200 */  srl        $v0, $v0, 23
    /* 25B10 8008E310 30004230 */  andi       $v0, $v0, 0x30
    /* 25B14 8008E314 08004224 */  addiu      $v0, $v0, 0x8
    /* 25B18 8008E318 0800E003 */  jr         $ra
    /* 25B1C 8008E31C 21106200 */   addu      $v0, $v1, $v0
endlabel func_8008E2D4
