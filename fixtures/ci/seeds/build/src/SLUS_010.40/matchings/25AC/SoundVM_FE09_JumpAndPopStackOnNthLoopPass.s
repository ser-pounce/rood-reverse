nonmatching SoundVM_FE09_JumpAndPopStackOnNthLoopPass, 0x7C

glabel SoundVM_FE09_JumpAndPopStackOnNthLoopPass
    /* CFEC 8001C7EC 0000858C */  lw         $a1, 0x0($a0)
    /* CFF0 8001C7F0 00000000 */  nop
    /* CFF4 8001C7F4 0000A390 */  lbu        $v1, 0x0($a1)
    /* CFF8 8001C7F8 0100A524 */  addiu      $a1, $a1, 0x1
    /* CFFC 8001C7FC 02006014 */  bnez       $v1, .L8001C808
    /* D000 8001C800 000085AC */   sw        $a1, 0x0($a0)
    /* D004 8001C804 00010324 */  addiu      $v1, $zero, 0x100
  .L8001C808:
    /* D008 8001C808 D0008294 */  lhu        $v0, 0xD0($a0)
    /* D00C 8001C80C 00000000 */  nop
    /* D010 8001C810 40100200 */  sll        $v0, $v0, 1
    /* D014 8001C814 21108200 */  addu       $v0, $a0, $v0
    /* D018 8001C818 72004294 */  lhu        $v0, 0x72($v0)
    /* D01C 8001C81C 00000000 */  nop
    /* D020 8001C820 01004224 */  addiu      $v0, $v0, 0x1
    /* D024 8001C824 03004310 */  beq        $v0, $v1, .L8001C834
    /* D028 8001C828 0200A224 */   addiu     $v0, $a1, 0x2
    /* D02C 8001C82C 0800E003 */  jr         $ra
    /* D030 8001C830 000082AC */   sw        $v0, 0x0($a0)
  .L8001C834:
    /* D034 8001C834 0100A290 */  lbu        $v0, 0x1($a1)
    /* D038 8001C838 0000A390 */  lbu        $v1, 0x0($a1)
    /* D03C 8001C83C 00120200 */  sll        $v0, $v0, 8
    /* D040 8001C840 25186200 */  or         $v1, $v1, $v0
    /* D044 8001C844 001C0300 */  sll        $v1, $v1, 16
    /* D048 8001C848 031C0300 */  sra        $v1, $v1, 16
    /* D04C 8001C84C D0008294 */  lhu        $v0, 0xD0($a0)
    /* D050 8001C850 2118A300 */  addu       $v1, $a1, $v1
    /* D054 8001C854 000083AC */  sw         $v1, 0x0($a0)
    /* D058 8001C858 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* D05C 8001C85C 03004230 */  andi       $v0, $v0, 0x3
    /* D060 8001C860 0800E003 */  jr         $ra
    /* D064 8001C864 D00082A4 */   sh        $v0, 0xD0($a0)
endlabel SoundVM_FE09_JumpAndPopStackOnNthLoopPass
