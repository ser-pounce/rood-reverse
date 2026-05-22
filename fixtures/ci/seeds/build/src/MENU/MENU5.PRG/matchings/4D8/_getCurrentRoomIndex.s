nonmatching _getCurrentRoomIndex, 0xA8

glabel _getCurrentRoomIndex
    /* 3D70 80106570 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0x9C)
    /* 3D74 80106574 941C428C */  lw         $v0, %lo(vs_battle_roomData + 0x9C)($v0)
    /* 3D78 80106578 0000868C */  lw         $a2, 0x0($a0)
    /* 3D7C 8010657C 04004524 */  addiu      $a1, $v0, 0x4
    /* 3D80 80106580 0800A884 */  lh         $t0, 0x8($a1)
    /* 3D84 80106584 0A00A784 */  lh         $a3, 0xA($a1)
    /* 3D88 80106588 1100C018 */  blez       $a2, .L801065D0
    /* 3D8C 8010658C 21180000 */   addu      $v1, $zero, $zero
    /* 3D90 80106590 1180093C */  lui        $t1, %hi(_isCurrentScene)
    /* 3D94 80106594 0E008524 */  addiu      $a1, $a0, 0xE
  .L80106598:
    /* 3D98 80106598 FEFFA284 */  lh         $v0, -0x2($a1)
    /* 3D9C 8010659C 00000000 */  nop
    /* 3DA0 801065A0 07004814 */  bne        $v0, $t0, .L801065C0
    /* 3DA4 801065A4 00000000 */   nop
    /* 3DA8 801065A8 0000A284 */  lh         $v0, 0x0($a1)
    /* 3DAC 801065AC 00000000 */  nop
    /* 3DB0 801065B0 03004714 */  bne        $v0, $a3, .L801065C0
    /* 3DB4 801065B4 21106000 */   addu      $v0, $v1, $zero
    /* 3DB8 801065B8 0800E003 */  jr         $ra
    /* 3DBC 801065BC 788D23AD */   sw        $v1, %lo(_isCurrentScene)($t1)
  .L801065C0:
    /* 3DC0 801065C0 01006324 */  addiu      $v1, $v1, 0x1
    /* 3DC4 801065C4 2A106600 */  slt        $v0, $v1, $a2
    /* 3DC8 801065C8 F3FF4014 */  bnez       $v0, .L80106598
    /* 3DCC 801065CC 0C00A524 */   addiu     $a1, $a1, 0xC
  .L801065D0:
    /* 3DD0 801065D0 04008524 */  addiu      $a1, $a0, 0x4
    /* 3DD4 801065D4 1180033C */  lui        $v1, %hi(_isCurrentScene)
    /* 3DD8 801065D8 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 3DDC 801065DC 788D62AC */  sw         $v0, %lo(_isCurrentScene)($v1)
    /* 3DE0 801065E0 0900C018 */  blez       $a2, .L80106608
    /* 3DE4 801065E4 21180000 */   addu      $v1, $zero, $zero
  .L801065E8:
    /* 3DE8 801065E8 0000A28C */  lw         $v0, 0x0($a1)
    /* 3DEC 801065EC 00000000 */  nop
    /* 3DF0 801065F0 07004014 */  bnez       $v0, .L80106610
    /* 3DF4 801065F4 21106000 */   addu      $v0, $v1, $zero
    /* 3DF8 801065F8 01006324 */  addiu      $v1, $v1, 0x1
    /* 3DFC 801065FC 2A106600 */  slt        $v0, $v1, $a2
    /* 3E00 80106600 F9FF4014 */  bnez       $v0, .L801065E8
    /* 3E04 80106604 0C00A524 */   addiu     $a1, $a1, 0xC
  .L80106608:
    /* 3E08 80106608 0800E003 */  jr         $ra
    /* 3E0C 8010660C 21100000 */   addu      $v0, $zero, $zero
  .L80106610:
    /* 3E10 80106610 0800E003 */  jr         $ra
    /* 3E14 80106614 00000000 */   nop
endlabel _getCurrentRoomIndex
