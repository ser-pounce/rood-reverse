nonmatching SetDrawTPage, 0x2C

glabel SetDrawTPage
    /* 1BE84 8002B684 01000224 */  addiu      $v0, $zero, 0x1
    /* 1BE88 8002B688 030082A0 */  sb         $v0, 0x3($a0)
    /* 1BE8C 8002B68C 0200C010 */  beqz       $a2, .L8002B698
    /* 1BE90 8002B690 00E1033C */   lui       $v1, (0xE1000200 >> 16)
    /* 1BE94 8002B694 00026334 */  ori        $v1, $v1, (0xE1000200 & 0xFFFF)
  .L8002B698:
    /* 1BE98 8002B698 0200A010 */  beqz       $a1, .L8002B6A4
    /* 1BE9C 8002B69C FF09E230 */   andi      $v0, $a3, 0x9FF
    /* 1BEA0 8002B6A0 00044234 */  ori        $v0, $v0, 0x400
  .L8002B6A4:
    /* 1BEA4 8002B6A4 25106200 */  or         $v0, $v1, $v0
    /* 1BEA8 8002B6A8 0800E003 */  jr         $ra
    /* 1BEAC 8002B6AC 040082AC */   sw        $v0, 0x4($a0)
endlabel SetDrawTPage
    /* 1BEB0 8002B6B0 00000000 */  nop
