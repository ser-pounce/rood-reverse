nonmatching _memcardFileNumberFromFilename, 0x7C

glabel _memcardFileNumberFromFilename
    /* 64C 80068E4C 21388000 */  addu       $a3, $a0, $zero
    /* 650 80068E50 0780023C */  lui        $v0, %hi(_memcardFilenameTemplate)
    /* 654 80068E54 8C28428C */  lw         $v0, %lo(_memcardFilenameTemplate)($v0)
    /* 658 80068E58 21280000 */  addu       $a1, $zero, $zero
    /* 65C 80068E5C 05004624 */  addiu      $a2, $v0, 0x5
    /* 660 80068E60 2110C500 */  addu       $v0, $a2, $a1
  .L80068E64:
    /* 664 80068E64 2118E500 */  addu       $v1, $a3, $a1
    /* 668 80068E68 00004490 */  lbu        $a0, 0x0($v0)
    /* 66C 80068E6C 00006290 */  lbu        $v0, 0x0($v1)
    /* 670 80068E70 00000000 */  nop
    /* 674 80068E74 10008214 */  bne        $a0, $v0, .L80068EB8
    /* 678 80068E78 0100A524 */   addiu     $a1, $a1, 0x1
    /* 67C 80068E7C 0F00A228 */  slti       $v0, $a1, 0xF
    /* 680 80068E80 F8FF4014 */  bnez       $v0, .L80068E64
    /* 684 80068E84 2110C500 */   addu      $v0, $a2, $a1
    /* 688 80068E88 0F00E390 */  lbu        $v1, 0xF($a3)
    /* 68C 80068E8C 00000000 */  nop
    /* 690 80068E90 BFFF6524 */  addiu      $a1, $v1, -0x41
    /* 694 80068E94 0500A22C */  sltiu      $v0, $a1, 0x5
    /* 698 80068E98 04004010 */  beqz       $v0, .L80068EAC
    /* 69C 80068E9C CFFF6524 */   addiu     $a1, $v1, -0x31
    /* 6A0 80068EA0 C0FF6224 */  addiu      $v0, $v1, -0x40
    /* 6A4 80068EA4 0800E003 */  jr         $ra
    /* 6A8 80068EA8 23100200 */   negu      $v0, $v0
  .L80068EAC:
    /* 6AC 80068EAC 0500A22C */  sltiu      $v0, $a1, 0x5
    /* 6B0 80068EB0 03004014 */  bnez       $v0, .L80068EC0
    /* 6B4 80068EB4 00000000 */   nop
  .L80068EB8:
    /* 6B8 80068EB8 0800E003 */  jr         $ra
    /* 6BC 80068EBC 21100000 */   addu      $v0, $zero, $zero
  .L80068EC0:
    /* 6C0 80068EC0 0800E003 */  jr         $ra
    /* 6C4 80068EC4 D0FF6224 */   addiu     $v0, $v1, -0x30
endlabel _memcardFileNumberFromFilename
