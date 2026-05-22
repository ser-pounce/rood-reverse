nonmatching _interpolateRGB, 0x5C

glabel _interpolateRGB
    /* 2C90 8006B490 21180000 */  addu       $v1, $zero, $zero
    /* 2C94 8006B494 21406000 */  addu       $t0, $v1, $zero
    /* 2C98 8006B498 08000224 */  addiu      $v0, $zero, 0x8
    /* 2C9C 8006B49C 23484600 */  subu       $t1, $v0, $a2
  .L8006B4A0:
    /* 2CA0 8006B4A0 02140400 */  srl        $v0, $a0, 16
    /* 2CA4 8006B4A4 FF004230 */  andi       $v0, $v0, 0xFF
    /* 2CA8 8006B4A8 18004900 */  mult       $v0, $t1
    /* 2CAC 8006B4AC 12380000 */  mflo       $a3
    /* 2CB0 8006B4B0 02140500 */  srl        $v0, $a1, 16
    /* 2CB4 8006B4B4 FF004230 */  andi       $v0, $v0, 0xFF
    /* 2CB8 8006B4B8 18004600 */  mult       $v0, $a2
    /* 2CBC 8006B4BC 00220400 */  sll        $a0, $a0, 8
    /* 2CC0 8006B4C0 01000825 */  addiu      $t0, $t0, 0x1
    /* 2CC4 8006B4C4 001A0300 */  sll        $v1, $v1, 8
    /* 2CC8 8006B4C8 12580000 */  mflo       $t3
    /* 2CCC 8006B4CC 2110EB00 */  addu       $v0, $a3, $t3
    /* 2CD0 8006B4D0 C2100200 */  srl        $v0, $v0, 3
    /* 2CD4 8006B4D4 21186200 */  addu       $v1, $v1, $v0
    /* 2CD8 8006B4D8 0300022D */  sltiu      $v0, $t0, 0x3
    /* 2CDC 8006B4DC F0FF4014 */  bnez       $v0, .L8006B4A0
    /* 2CE0 8006B4E0 002A0500 */   sll       $a1, $a1, 8
    /* 2CE4 8006B4E4 0800E003 */  jr         $ra
    /* 2CE8 8006B4E8 21106000 */   addu      $v0, $v1, $zero
endlabel _interpolateRGB
