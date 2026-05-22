nonmatching SoundVM_FE08_JumpOnNthLoopPass, 0x6C

glabel SoundVM_FE08_JumpOnNthLoopPass
    /* CF80 8001C780 0000858C */  lw         $a1, 0x0($a0)
    /* CF84 8001C784 00000000 */  nop
    /* CF88 8001C788 0000A390 */  lbu        $v1, 0x0($a1)
    /* CF8C 8001C78C 0100A524 */  addiu      $a1, $a1, 0x1
    /* CF90 8001C790 02006014 */  bnez       $v1, .L8001C79C
    /* CF94 8001C794 000085AC */   sw        $a1, 0x0($a0)
    /* CF98 8001C798 00010324 */  addiu      $v1, $zero, 0x100
  .L8001C79C:
    /* CF9C 8001C79C D0008294 */  lhu        $v0, 0xD0($a0)
    /* CFA0 8001C7A0 00000000 */  nop
    /* CFA4 8001C7A4 40100200 */  sll        $v0, $v0, 1
    /* CFA8 8001C7A8 21108200 */  addu       $v0, $a0, $v0
    /* CFAC 8001C7AC 72004294 */  lhu        $v0, 0x72($v0)
    /* CFB0 8001C7B0 00000000 */  nop
    /* CFB4 8001C7B4 01004224 */  addiu      $v0, $v0, 0x1
    /* CFB8 8001C7B8 03004310 */  beq        $v0, $v1, .L8001C7C8
    /* CFBC 8001C7BC 0200A224 */   addiu     $v0, $a1, 0x2
    /* CFC0 8001C7C0 0800E003 */  jr         $ra
    /* CFC4 8001C7C4 000082AC */   sw        $v0, 0x0($a0)
  .L8001C7C8:
    /* CFC8 8001C7C8 0100A390 */  lbu        $v1, 0x1($a1)
    /* CFCC 8001C7CC 0000A290 */  lbu        $v0, 0x0($a1)
    /* CFD0 8001C7D0 001A0300 */  sll        $v1, $v1, 8
    /* CFD4 8001C7D4 25104300 */  or         $v0, $v0, $v1
    /* CFD8 8001C7D8 00140200 */  sll        $v0, $v0, 16
    /* CFDC 8001C7DC 03140200 */  sra        $v0, $v0, 16
    /* CFE0 8001C7E0 2110A200 */  addu       $v0, $a1, $v0
    /* CFE4 8001C7E4 0800E003 */  jr         $ra
    /* CFE8 8001C7E8 000082AC */   sw        $v0, 0x0($a0)
endlabel SoundVM_FE08_JumpOnNthLoopPass
