nonmatching SoundVM_unused1, 0x44

glabel SoundVM_unused1
    /* BF34 8001B734 0000828C */  lw         $v0, 0x0($a0)
    /* BF38 8001B738 00000000 */  nop
    /* BF3C 8001B73C 00004390 */  lbu        $v1, 0x0($v0)
    /* BF40 8001B740 01004224 */  addiu      $v0, $v0, 0x1
    /* BF44 8001B744 000082AC */  sw         $v0, 0x0($a0)
    /* BF48 8001B748 3400828C */  lw         $v0, 0x34($a0)
    /* BF4C 8001B74C 8C0080A4 */  sh         $zero, 0x8C($a0)
    /* BF50 8001B750 001A0300 */  sll        $v1, $v1, 8
    /* BF54 8001B754 00014230 */  andi       $v0, $v0, 0x100
    /* BF58 8001B758 05004010 */  beqz       $v0, .L8001B770
    /* BF5C 8001B75C DC0083A4 */   sh        $v1, 0xDC($a0)
    /* BF60 8001B760 F800828C */  lw         $v0, 0xF8($a0)
    /* BF64 8001B764 00000000 */  nop
    /* BF68 8001B768 03004234 */  ori        $v0, $v0, 0x3
    /* BF6C 8001B76C F80082AC */  sw         $v0, 0xF8($a0)
  .L8001B770:
    /* BF70 8001B770 0800E003 */  jr         $ra
    /* BF74 8001B774 00000000 */   nop
endlabel SoundVM_unused1
