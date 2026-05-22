nonmatching vs_battle_uiGradientStop, 0xCC

glabel vs_battle_uiGradientStop
    /* 607AC 800C8FAC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 607B0 800C8FB0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 607B4 800C8FB4 21988000 */  addu       $s3, $a0, $zero
    /* 607B8 800C8FB8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 607BC 800C8FBC 2180A000 */  addu       $s0, $a1, $zero
    /* 607C0 800C8FC0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 607C4 800C8FC4 2190C000 */  addu       $s2, $a2, $zero
    /* 607C8 800C8FC8 0900022E */  sltiu      $v0, $s0, 0x9
    /* 607CC 800C8FCC 2000BFAF */  sw         $ra, 0x20($sp)
    /* 607D0 800C8FD0 12004010 */  beqz       $v0, .L800C901C
    /* 607D4 800C8FD4 1400B1AF */   sw        $s1, 0x14($sp)
    /* 607D8 800C8FD8 6B00043C */  lui        $a0, (0x6B4100 >> 16)
    /* 607DC 800C8FDC 00418434 */  ori        $a0, $a0, (0x6B4100 & 0xFFFF)
    /* 607E0 800C8FE0 6C00053C */  lui        $a1, (0x6C8219 >> 16)
    /* 607E4 800C8FE4 1982A534 */  ori        $a1, $a1, (0x6C8219 & 0xFFFF)
    /* 607E8 800C8FE8 80000624 */  addiu      $a2, $zero, 0x80
    /* 607EC 800C8FEC D123030C */  jal        _lerpColor
    /* 607F0 800C8FF0 21380002 */   addu      $a3, $s0, $zero
    /* 607F4 800C8FF4 21884000 */  addu       $s1, $v0, $zero
    /* 607F8 800C8FF8 3300043C */  lui        $a0, (0x330500 >> 16)
    /* 607FC 800C8FFC 00058434 */  ori        $a0, $a0, (0x330500 & 0xFFFF)
    /* 60800 800C9000 2600053C */  lui        $a1, (0x262801 >> 16)
    /* 60804 800C9004 0128A534 */  ori        $a1, $a1, (0x262801 & 0xFFFF)
    /* 60808 800C9008 80000624 */  addiu      $a2, $zero, 0x80
    /* 6080C 800C900C D123030C */  jal        _lerpColor
    /* 60810 800C9010 21380002 */   addu      $a3, $s0, $zero
    /* 60814 800C9014 13240308 */  j          .L800C904C
    /* 60818 800C9018 21202002 */   addu      $a0, $s1, $zero
  .L800C901C:
    /* 6081C 800C901C 0F80023C */  lui        $v0, %hi(D_800EBBB8)
    /* 60820 800C9020 B8BB4224 */  addiu      $v0, $v0, %lo(D_800EBBB8)
    /* 60824 800C9024 C2181000 */  srl        $v1, $s0, 3
    /* 60828 800C9028 FEFF6324 */  addiu      $v1, $v1, -0x2
    /* 6082C 800C902C 80180300 */  sll        $v1, $v1, 2
    /* 60830 800C9030 21106200 */  addu       $v0, $v1, $v0
    /* 60834 800C9034 0000518C */  lw         $s1, 0x0($v0)
    /* 60838 800C9038 0F80023C */  lui        $v0, %hi(D_800EBBC0)
    /* 6083C 800C903C C0BB4224 */  addiu      $v0, $v0, %lo(D_800EBBC0)
    /* 60840 800C9040 21186200 */  addu       $v1, $v1, $v0
    /* 60844 800C9044 0000628C */  lw         $v0, 0x0($v1)
    /* 60848 800C9048 21202002 */  addu       $a0, $s1, $zero
  .L800C904C:
    /* 6084C 800C904C 21284000 */  addu       $a1, $v0, $zero
    /* 60850 800C9050 21304002 */  addu       $a2, $s2, $zero
    /* 60854 800C9054 D123030C */  jal        _lerpColor
    /* 60858 800C9058 21386002 */   addu      $a3, $s3, $zero
    /* 6085C 800C905C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 60860 800C9060 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 60864 800C9064 1800B28F */  lw         $s2, 0x18($sp)
    /* 60868 800C9068 1400B18F */  lw         $s1, 0x14($sp)
    /* 6086C 800C906C 1000B08F */  lw         $s0, 0x10($sp)
    /* 60870 800C9070 0800E003 */  jr         $ra
    /* 60874 800C9074 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel vs_battle_uiGradientStop
