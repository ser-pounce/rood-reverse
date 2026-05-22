nonmatching vs_battle_mapStickDeadZone, 0x2C

glabel vs_battle_mapStickDeadZone
    /* 5BF08 800C4708 40008228 */  slti       $v0, $a0, 0x40
    /* 5BF0C 800C470C 03004010 */  beqz       $v0, .L800C471C
    /* 5BF10 800C4710 C0008228 */   slti      $v0, $a0, 0xC0
    /* 5BF14 800C4714 0800E003 */  jr         $ra
    /* 5BF18 800C4718 C0FF8224 */   addiu     $v0, $a0, -0x40
  .L800C471C:
    /* 5BF1C 800C471C 03004014 */  bnez       $v0, .L800C472C
    /* 5BF20 800C4720 21100000 */   addu      $v0, $zero, $zero
    /* 5BF24 800C4724 0800E003 */  jr         $ra
    /* 5BF28 800C4728 40FF8224 */   addiu     $v0, $a0, -0xC0
  .L800C472C:
    /* 5BF2C 800C472C 0800E003 */  jr         $ra
    /* 5BF30 800C4730 00000000 */   nop
endlabel vs_battle_mapStickDeadZone
