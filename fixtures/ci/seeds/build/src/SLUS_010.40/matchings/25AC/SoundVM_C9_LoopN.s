nonmatching SoundVM_C9_LoopN, 0x94

glabel SoundVM_C9_LoopN
    /* CEEC 8001C6EC 0000828C */  lw         $v0, 0x0($a0)
    /* CEF0 8001C6F0 00000000 */  nop
    /* CEF4 8001C6F4 00004590 */  lbu        $a1, 0x0($v0)
    /* CEF8 8001C6F8 01004224 */  addiu      $v0, $v0, 0x1
    /* CEFC 8001C6FC 0200A014 */  bnez       $a1, .L8001C708
    /* CF00 8001C700 000082AC */   sw        $v0, 0x0($a0)
    /* CF04 8001C704 00010524 */  addiu      $a1, $zero, 0x100
  .L8001C708:
    /* CF08 8001C708 D0008394 */  lhu        $v1, 0xD0($a0)
    /* CF0C 8001C70C 00000000 */  nop
    /* CF10 8001C710 40180300 */  sll        $v1, $v1, 1
    /* CF14 8001C714 21188300 */  addu       $v1, $a0, $v1
    /* CF18 8001C718 72006294 */  lhu        $v0, 0x72($v1)
    /* CF1C 8001C71C 00000000 */  nop
    /* CF20 8001C720 01004224 */  addiu      $v0, $v0, 0x1
    /* CF24 8001C724 720062A4 */  sh         $v0, 0x72($v1)
    /* CF28 8001C728 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* CF2C 8001C72C 0E004510 */  beq        $v0, $a1, .L8001C768
    /* CF30 8001C730 00000000 */   nop
    /* CF34 8001C734 D0008294 */  lhu        $v0, 0xD0($a0)
    /* CF38 8001C738 00000000 */  nop
    /* CF3C 8001C73C 80100200 */  sll        $v0, $v0, 2
    /* CF40 8001C740 21108200 */  addu       $v0, $a0, $v0
    /* CF44 8001C744 0400438C */  lw         $v1, 0x4($v0)
    /* CF48 8001C748 D0008294 */  lhu        $v0, 0xD0($a0)
    /* CF4C 8001C74C 00000000 */  nop
    /* CF50 8001C750 40100200 */  sll        $v0, $v0, 1
    /* CF54 8001C754 21108200 */  addu       $v0, $a0, $v0
    /* CF58 8001C758 000083AC */  sw         $v1, 0x0($a0)
    /* CF5C 8001C75C 7A004294 */  lhu        $v0, 0x7A($v0)
    /* CF60 8001C760 0800E003 */  jr         $ra
    /* CF64 8001C764 700082A4 */   sh        $v0, 0x70($a0)
  .L8001C768:
    /* CF68 8001C768 D0008294 */  lhu        $v0, 0xD0($a0)
    /* CF6C 8001C76C 00000000 */  nop
    /* CF70 8001C770 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* CF74 8001C774 03004230 */  andi       $v0, $v0, 0x3
    /* CF78 8001C778 0800E003 */  jr         $ra
    /* CF7C 8001C77C D00082A4 */   sh        $v0, 0xD0($a0)
endlabel SoundVM_C9_LoopN
