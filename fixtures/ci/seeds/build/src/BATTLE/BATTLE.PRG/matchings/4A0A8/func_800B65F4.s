nonmatching func_800B65F4, 0x40

glabel func_800B65F4
    /* 4DDF4 800B65F4 40000934 */  ori        $t1, $zero, 0x40
  .L800B65F8:
    /* 4DDF8 800B65F8 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 4DDFC 800B65FC 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 4DE00 800B6600 80180400 */  sll        $v1, $a0, 2
    /* 4DE04 800B6604 21104300 */  addu       $v0, $v0, $v1
    /* 4DE08 800B6608 0000428C */  lw         $v0, 0x0($v0)
    /* 4DE0C 800B660C 0000AA8C */  lw         $t2, 0x0($a1)
    /* 4DE10 800B6610 0400AB8C */  lw         $t3, 0x4($a1)
    /* 4DE14 800B6614 0B004C80 */  lb         $t4, 0xB($v0)
    /* 4DE18 800B6618 EC054AAC */  sw         $t2, 0x5EC($v0)
    /* 4DE1C 800B661C F0054BAC */  sw         $t3, 0x5F0($v0)
    /* 4DE20 800B6620 F20546A4 */  sh         $a2, 0x5F2($v0)
    /* 4DE24 800B6624 8F008C31 */  andi       $t4, $t4, 0x8F
    /* 4DE28 800B6628 25488901 */  or         $t1, $t4, $t1
    /* 4DE2C 800B662C 0B0049A0 */  sb         $t1, 0xB($v0)
    /* 4DE30 800B6630 0800E003 */  jr         $ra
endlabel func_800B65F4
