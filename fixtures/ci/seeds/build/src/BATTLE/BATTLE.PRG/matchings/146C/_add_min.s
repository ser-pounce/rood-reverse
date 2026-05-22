nonmatching _add_min, 0x38

glabel _add_min
    /* 51C4 8006D9C4 0600C104 */  bgez       $a2, .L8006D9E0
    /* 51C8 8006D9C8 2A10C500 */   slt       $v0, $a2, $a1
    /* 51CC 8006D9CC 2A10A600 */  slt        $v0, $a1, $a2
    /* 51D0 8006D9D0 05004014 */  bnez       $v0, .L8006D9E8
    /* 51D4 8006D9D4 00000000 */   nop
    /* 51D8 8006D9D8 7DB60108 */  j          .L8006D9F4
    /* 51DC 8006D9DC 21208500 */   addu      $a0, $a0, $a1
  .L8006D9E0:
    /* 51E0 8006D9E0 03004010 */  beqz       $v0, .L8006D9F0
    /* 51E4 8006D9E4 00000000 */   nop
  .L8006D9E8:
    /* 51E8 8006D9E8 7DB60108 */  j          .L8006D9F4
    /* 51EC 8006D9EC 21208600 */   addu      $a0, $a0, $a2
  .L8006D9F0:
    /* 51F0 8006D9F0 21208500 */  addu       $a0, $a0, $a1
  .L8006D9F4:
    /* 51F4 8006D9F4 0800E003 */  jr         $ra
    /* 51F8 8006D9F8 21108000 */   addu      $v0, $a0, $zero
endlabel _add_min
