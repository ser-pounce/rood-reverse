nonmatching _addMinDelta, 0x48

glabel _addMinDelta
    /* 517C 8006D97C 0800C104 */  bgez       $a2, .L8006D9A0
    /* 5180 8006D980 2A10C500 */   slt       $v0, $a2, $a1
    /* 5184 8006D984 2A10A600 */  slt        $v0, $a1, $a2
    /* 5188 8006D988 0B004014 */  bnez       $v0, .L8006D9B8
    /* 518C 8006D98C 00000000 */   nop
    /* 5190 8006D990 0700A014 */  bnez       $a1, .L8006D9B0
    /* 5194 8006D994 00000000 */   nop
    /* 5198 8006D998 6FB60108 */  j          .L8006D9BC
    /* 519C 8006D99C 21208600 */   addu      $a0, $a0, $a2
  .L8006D9A0:
    /* 51A0 8006D9A0 05004014 */  bnez       $v0, .L8006D9B8
    /* 51A4 8006D9A4 00000000 */   nop
    /* 51A8 8006D9A8 0300A010 */  beqz       $a1, .L8006D9B8
    /* 51AC 8006D9AC 00000000 */   nop
  .L8006D9B0:
    /* 51B0 8006D9B0 6FB60108 */  j          .L8006D9BC
    /* 51B4 8006D9B4 21208500 */   addu      $a0, $a0, $a1
  .L8006D9B8:
    /* 51B8 8006D9B8 21208600 */  addu       $a0, $a0, $a2
  .L8006D9BC:
    /* 51BC 8006D9BC 0800E003 */  jr         $ra
    /* 51C0 8006D9C0 21108000 */   addu      $v0, $a0, $zero
endlabel _addMinDelta
