nonmatching vs_battle_getHitLocationStatus, 0x5C

glabel vs_battle_getHitLocationStatus
    /* 6165C 800C9E5C 00008384 */  lh         $v1, 0x0($a0)
    /* 61660 800C9E60 02008484 */  lh         $a0, 0x2($a0)
    /* 61664 800C9E64 02006228 */  slti       $v0, $v1, 0x2
    /* 61668 800C9E68 03004010 */  beqz       $v0, .L800C9E78
    /* 6166C 800C9E6C 80280300 */   sll       $a1, $v1, 2
    /* 61670 800C9E70 0800E003 */  jr         $ra
    /* 61674 800C9E74 21100000 */   addu      $v0, $zero, $zero
  .L800C9E78:
    /* 61678 800C9E78 2A10A400 */  slt        $v0, $a1, $a0
    /* 6167C 800C9E7C 03004010 */  beqz       $v0, .L800C9E8C
    /* 61680 800C9E80 40100400 */   sll       $v0, $a0, 1
    /* 61684 800C9E84 0800E003 */  jr         $ra
    /* 61688 800C9E88 01000224 */   addiu     $v0, $zero, 0x1
  .L800C9E8C:
    /* 6168C 800C9E8C 21104400 */  addu       $v0, $v0, $a0
    /* 61690 800C9E90 2A10A200 */  slt        $v0, $a1, $v0
    /* 61694 800C9E94 06004014 */  bnez       $v0, .L800C9EB0
    /* 61698 800C9E98 02000224 */   addiu     $v0, $zero, 0x2
    /* 6169C 800C9E9C 2A186400 */  slt        $v1, $v1, $a0
    /* 616A0 800C9EA0 03006014 */  bnez       $v1, .L800C9EB0
    /* 616A4 800C9EA4 03000224 */   addiu     $v0, $zero, 0x3
    /* 616A8 800C9EA8 0800E003 */  jr         $ra
    /* 616AC 800C9EAC 04000224 */   addiu     $v0, $zero, 0x4
  .L800C9EB0:
    /* 616B0 800C9EB0 0800E003 */  jr         $ra
    /* 616B4 800C9EB4 00000000 */   nop
endlabel vs_battle_getHitLocationStatus
