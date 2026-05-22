nonmatching _memcardFileNumberFromFilename, 0x7C

glabel _memcardFileNumberFromFilename
    /* 5AC 80102DAC 21388000 */  addu       $a3, $a0, $zero
    /* 5B0 80102DB0 1180023C */  lui        $v0, %hi(_memcardFilenameTemplate)
    /* 5B4 80102DB4 B4A2428C */  lw         $v0, %lo(_memcardFilenameTemplate)($v0)
    /* 5B8 80102DB8 21280000 */  addu       $a1, $zero, $zero
    /* 5BC 80102DBC 05004624 */  addiu      $a2, $v0, 0x5
    /* 5C0 80102DC0 2110C500 */  addu       $v0, $a2, $a1
  .L80102DC4:
    /* 5C4 80102DC4 2118E500 */  addu       $v1, $a3, $a1
    /* 5C8 80102DC8 00004490 */  lbu        $a0, 0x0($v0)
    /* 5CC 80102DCC 00006290 */  lbu        $v0, 0x0($v1)
    /* 5D0 80102DD0 00000000 */  nop
    /* 5D4 80102DD4 10008214 */  bne        $a0, $v0, .L80102E18
    /* 5D8 80102DD8 0100A524 */   addiu     $a1, $a1, 0x1
    /* 5DC 80102DDC 0F00A228 */  slti       $v0, $a1, 0xF
    /* 5E0 80102DE0 F8FF4014 */  bnez       $v0, .L80102DC4
    /* 5E4 80102DE4 2110C500 */   addu      $v0, $a2, $a1
    /* 5E8 80102DE8 0F00E390 */  lbu        $v1, 0xF($a3)
    /* 5EC 80102DEC 00000000 */  nop
    /* 5F0 80102DF0 BFFF6524 */  addiu      $a1, $v1, -0x41
    /* 5F4 80102DF4 0500A22C */  sltiu      $v0, $a1, 0x5
    /* 5F8 80102DF8 04004010 */  beqz       $v0, .L80102E0C
    /* 5FC 80102DFC CFFF6524 */   addiu     $a1, $v1, -0x31
    /* 600 80102E00 C0FF6224 */  addiu      $v0, $v1, -0x40
    /* 604 80102E04 0800E003 */  jr         $ra
    /* 608 80102E08 23100200 */   negu      $v0, $v0
  .L80102E0C:
    /* 60C 80102E0C 0500A22C */  sltiu      $v0, $a1, 0x5
    /* 610 80102E10 03004014 */  bnez       $v0, .L80102E20
    /* 614 80102E14 00000000 */   nop
  .L80102E18:
    /* 618 80102E18 0800E003 */  jr         $ra
    /* 61C 80102E1C 21100000 */   addu      $v0, $zero, $zero
  .L80102E20:
    /* 620 80102E20 0800E003 */  jr         $ra
    /* 624 80102E24 D0FF6224 */   addiu     $v0, $v1, -0x30
endlabel _memcardFileNumberFromFilename
