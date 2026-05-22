nonmatching SoundVM_C8_LoopPoint, 0x50

glabel SoundVM_C8_LoopPoint
    /* CE9C 8001C69C D0008294 */  lhu        $v0, 0xD0($a0)
    /* CEA0 8001C6A0 0000838C */  lw         $v1, 0x0($a0)
    /* CEA4 8001C6A4 01004224 */  addiu      $v0, $v0, 0x1
    /* CEA8 8001C6A8 03004230 */  andi       $v0, $v0, 0x3
    /* CEAC 8001C6AC D00082A4 */  sh         $v0, 0xD0($a0)
    /* CEB0 8001C6B0 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* CEB4 8001C6B4 80100200 */  sll        $v0, $v0, 2
    /* CEB8 8001C6B8 21108200 */  addu       $v0, $a0, $v0
    /* CEBC 8001C6BC 040043AC */  sw         $v1, 0x4($v0)
    /* CEC0 8001C6C0 D0008294 */  lhu        $v0, 0xD0($a0)
    /* CEC4 8001C6C4 00000000 */  nop
    /* CEC8 8001C6C8 40100200 */  sll        $v0, $v0, 1
    /* CECC 8001C6CC 21108200 */  addu       $v0, $a0, $v0
    /* CED0 8001C6D0 720040A4 */  sh         $zero, 0x72($v0)
    /* CED4 8001C6D4 D0008294 */  lhu        $v0, 0xD0($a0)
    /* CED8 8001C6D8 70008394 */  lhu        $v1, 0x70($a0)
    /* CEDC 8001C6DC 40100200 */  sll        $v0, $v0, 1
    /* CEE0 8001C6E0 21208200 */  addu       $a0, $a0, $v0
    /* CEE4 8001C6E4 0800E003 */  jr         $ra
    /* CEE8 8001C6E8 7A0083A4 */   sh        $v1, 0x7A($a0)
endlabel SoundVM_C8_LoopPoint
