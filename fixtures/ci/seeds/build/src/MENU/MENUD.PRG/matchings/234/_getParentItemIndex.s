nonmatching _getParentItemIndex, 0x78

glabel _getParentItemIndex
    /* 149C 80103C9C 01000224 */  addiu      $v0, $zero, 0x1
    /* 14A0 80103CA0 08008214 */  bne        $a0, $v0, .L80103CC4
    /* 14A4 80103CA4 21180000 */   addu      $v1, $zero, $zero
    /* 14A8 80103CA8 04104500 */  sllv       $v0, $a1, $v0
    /* 14AC 80103CAC 21104500 */  addu       $v0, $v0, $a1
    /* 14B0 80103CB0 80100200 */  sll        $v0, $v0, 2
    /* 14B4 80103CB4 23104500 */  subu       $v0, $v0, $a1
    /* 14B8 80103CB8 80100200 */  sll        $v0, $v0, 2
    /* 14BC 80103CBC 2110C200 */  addu       $v0, $a2, $v0
    /* 14C0 80103CC0 2A0A4390 */  lbu        $v1, 0xA2A($v0)
  .L80103CC4:
    /* 14C4 80103CC4 02000224 */  addiu      $v0, $zero, 0x2
    /* 14C8 80103CC8 05008214 */  bne        $a0, $v0, .L80103CE0
    /* 14CC 80103CCC 05000224 */   addiu     $v0, $zero, 0x5
    /* 14D0 80103CD0 00110500 */  sll        $v0, $a1, 4
    /* 14D4 80103CD4 2110C200 */  addu       $v0, $a2, $v0
    /* 14D8 80103CD8 0C154394 */  lhu        $v1, 0x150C($v0)
    /* 14DC 80103CDC 05000224 */  addiu      $v0, $zero, 0x5
  .L80103CE0:
    /* 14E0 80103CE0 0A008214 */  bne        $a0, $v0, .L80103D0C
    /* 14E4 80103CE4 C0100500 */   sll       $v0, $a1, 3
    /* 14E8 80103CE8 23104500 */  subu       $v0, $v0, $a1
    /* 14EC 80103CEC 80100200 */  sll        $v0, $v0, 2
    /* 14F0 80103CF0 2110C200 */  addu       $v0, $a2, $v0
    /* 14F4 80103CF4 18234394 */  lhu        $v1, 0x2318($v0)
    /* 14F8 80103CF8 00000000 */  nop
    /* 14FC 80103CFC 80006230 */  andi       $v0, $v1, 0x80
    /* 1500 80103D00 02004010 */  beqz       $v0, .L80103D0C
    /* 1504 80103D04 00000000 */   nop
    /* 1508 80103D08 21180000 */  addu       $v1, $zero, $zero
  .L80103D0C:
    /* 150C 80103D0C 0800E003 */  jr         $ra
    /* 1510 80103D10 21106000 */   addu      $v0, $v1, $zero
endlabel _getParentItemIndex
