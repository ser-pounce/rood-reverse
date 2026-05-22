nonmatching func_80086EA4, 0x50

glabel func_80086EA4
    /* 1E6A4 80086EA4 21408000 */  addu       $t0, $a0, $zero
    /* 1E6A8 80086EA8 54000295 */  lhu        $v0, 0x54($t0)
    /* 1E6AC 80086EAC 00000000 */  nop
    /* 1E6B0 80086EB0 0E004010 */  beqz       $v0, .L80086EEC
    /* 1E6B4 80086EB4 40200500 */   sll       $a0, $a1, 1
    /* 1E6B8 80086EB8 21200401 */  addu       $a0, $t0, $a0
    /* 1E6BC 80086EBC 40180600 */  sll        $v1, $a2, 1
    /* 1E6C0 80086EC0 84018294 */  lhu        $v0, 0x184($a0)
    /* 1E6C4 80086EC4 21180301 */  addu       $v1, $t0, $v1
    /* 1E6C8 80086EC8 21104700 */  addu       $v0, $v0, $a3
    /* 1E6CC 80086ECC 840182A4 */  sh         $v0, 0x184($a0)
    /* 1E6D0 80086ED0 84016294 */  lhu        $v0, 0x184($v1)
    /* 1E6D4 80086ED4 00000000 */  nop
    /* 1E6D8 80086ED8 23104700 */  subu       $v0, $v0, $a3
    /* 1E6DC 80086EDC 840162A4 */  sh         $v0, 0x184($v1)
    /* 1E6E0 80086EE0 23100700 */  negu       $v0, $a3
    /* 1E6E4 80086EE4 A40187A4 */  sh         $a3, 0x1A4($a0)
    /* 1E6E8 80086EE8 A40162A4 */  sh         $v0, 0x1A4($v1)
  .L80086EEC:
    /* 1E6EC 80086EEC 0800E003 */  jr         $ra
    /* 1E6F0 80086EF0 00000000 */   nop
endlabel func_80086EA4
