nonmatching func_8008C49C, 0x7C

glabel func_8008C49C
    /* 23C9C 8008C49C 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0xA8)
    /* 23CA0 8008C4A0 A01C428C */  lw         $v0, %lo(vs_battle_roomData + 0xA8)($v0)
    /* 23CA4 8008C4A4 00000000 */  nop
    /* 23CA8 8008C4A8 19004010 */  beqz       $v0, .L8008C510
    /* 23CAC 8008C4AC 21308000 */   addu      $a2, $a0, $zero
    /* 23CB0 8008C4B0 40180600 */  sll        $v1, $a2, 1
    /* 23CB4 8008C4B4 21186600 */  addu       $v1, $v1, $a2
    /* 23CB8 8008C4B8 C0180300 */  sll        $v1, $v1, 3
    /* 23CBC 8008C4BC 23186600 */  subu       $v1, $v1, $a2
    /* 23CC0 8008C4C0 C0180300 */  sll        $v1, $v1, 3
    /* 23CC4 8008C4C4 21186200 */  addu       $v1, $v1, $v0
    /* 23CC8 8008C4C8 0400648C */  lw         $a0, 0x4($v1)
    /* 23CCC 8008C4CC 01FF0224 */  addiu      $v0, $zero, -0xFF
    /* 23CD0 8008C4D0 24208200 */  and        $a0, $a0, $v0
    /* 23CD4 8008C4D4 7F00A230 */  andi       $v0, $a1, 0x7F
    /* 23CD8 8008C4D8 40100200 */  sll        $v0, $v0, 1
    /* 23CDC 8008C4DC 25208200 */  or         $a0, $a0, $v0
    /* 23CE0 8008C4E0 0900A004 */  bltz       $a1, .L8008C508
    /* 23CE4 8008C4E4 040064AC */   sw        $a0, 0x4($v1)
    /* 23CE8 8008C4E8 0F80023C */  lui        $v0, %hi(D_800F1D68)
    /* 23CEC 8008C4EC 681D4284 */  lh         $v0, %lo(D_800F1D68)($v0)
    /* 23CF0 8008C4F0 00000000 */  nop
    /* 23CF4 8008C4F4 04004014 */  bnez       $v0, .L8008C508
    /* 23CF8 8008C4F8 0F80023C */   lui       $v0, %hi(D_800F1D70)
    /* 23CFC 8008C4FC 701D4224 */  addiu      $v0, $v0, %lo(D_800F1D70)
    /* 23D00 8008C500 2110C200 */  addu       $v0, $a2, $v0
    /* 23D04 8008C504 000040A0 */  sb         $zero, 0x0($v0)
  .L8008C508:
    /* 23D08 8008C508 0800E003 */  jr         $ra
    /* 23D0C 8008C50C 01000224 */   addiu     $v0, $zero, 0x1
  .L8008C510:
    /* 23D10 8008C510 0800E003 */  jr         $ra
    /* 23D14 8008C514 21100000 */   addu      $v0, $zero, $zero
endlabel func_8008C49C
