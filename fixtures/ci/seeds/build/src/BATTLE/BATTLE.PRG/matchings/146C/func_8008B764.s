nonmatching func_8008B764, 0xA4

glabel func_8008B764
    /* 22F64 8008B764 0F80023C */  lui        $v0, %hi(vs_battle_roomData)
    /* 22F68 8008B768 F81B4324 */  addiu      $v1, $v0, %lo(vs_battle_roomData)
    /* 22F6C 8008B76C 6C00678C */  lw         $a3, 0x6C($v1)
    /* 22F70 8008B770 00000000 */  nop
    /* 22F74 8008B774 2200E010 */  beqz       $a3, .L8008B800
    /* 22F78 8008B778 2140A000 */   addu      $t0, $a1, $zero
    /* 22F7C 8008B77C 0200C228 */  slti       $v0, $a2, 0x2
    /* 22F80 8008B780 0E004014 */  bnez       $v0, .L8008B7BC
    /* 22F84 8008B784 00000000 */   nop
    /* 22F88 8008B788 A800638C */  lw         $v1, 0xA8($v1)
    /* 22F8C 8008B78C 00000000 */  nop
    /* 22F90 8008B790 08006010 */  beqz       $v1, .L8008B7B4
    /* 22F94 8008B794 40100600 */   sll       $v0, $a2, 1
    /* 22F98 8008B798 21104600 */  addu       $v0, $v0, $a2
    /* 22F9C 8008B79C C0100200 */  sll        $v0, $v0, 3
    /* 22FA0 8008B7A0 23104600 */  subu       $v0, $v0, $a2
    /* 22FA4 8008B7A4 C0100200 */  sll        $v0, $v0, 3
    /* 22FA8 8008B7A8 21104300 */  addu       $v0, $v0, $v1
    /* 22FAC 8008B7AC 0800E003 */  jr         $ra
    /* 22FB0 8008B7B0 44FF4224 */   addiu     $v0, $v0, -0xBC
  .L8008B7B4:
    /* 22FB4 8008B7B4 0800E003 */  jr         $ra
    /* 22FB8 8008B7B8 21100000 */   addu      $v0, $zero, $zero
  .L8008B7BC:
    /* 22FBC 8008B7BC 6800638C */  lw         $v1, 0x68($v1)
    /* 22FC0 8008B7C0 00000000 */  nop
    /* 22FC4 8008B7C4 00006584 */  lh         $a1, 0x0($v1)
    /* 22FC8 8008B7C8 00000000 */  nop
    /* 22FCC 8008B7CC 2B108500 */  sltu       $v0, $a0, $a1
    /* 22FD0 8008B7D0 0B004010 */  beqz       $v0, .L8008B800
    /* 22FD4 8008B7D4 00000000 */   nop
    /* 22FD8 8008B7D8 02006284 */  lh         $v0, 0x2($v1)
    /* 22FDC 8008B7DC 00000000 */  nop
    /* 22FE0 8008B7E0 2B100201 */  sltu       $v0, $t0, $v0
    /* 22FE4 8008B7E4 06004010 */  beqz       $v0, .L8008B800
    /* 22FE8 8008B7E8 18000501 */   mult      $t0, $a1
    /* 22FEC 8008B7EC 12480000 */  mflo       $t1
    /* 22FF0 8008B7F0 21102401 */  addu       $v0, $t1, $a0
    /* 22FF4 8008B7F4 80100200 */  sll        $v0, $v0, 2
    /* 22FF8 8008B7F8 0800E003 */  jr         $ra
    /* 22FFC 8008B7FC 2110E200 */   addu      $v0, $a3, $v0
  .L8008B800:
    /* 23000 8008B800 0800E003 */  jr         $ra
    /* 23004 8008B804 21100000 */   addu      $v0, $zero, $zero
endlabel func_8008B764
