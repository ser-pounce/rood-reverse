nonmatching vs_battle_getStatusFlags, 0x54

glabel vs_battle_getStatusFlags
    /* 61608 800C9E08 21280000 */  addu       $a1, $zero, $zero
    /* 6160C 800C9E0C 4809838C */  lw         $v1, 0x948($a0)
    /* 61610 800C9E10 0F80023C */  lui        $v0, %hi(D_800EBC68)
    /* 61614 800C9E14 68BC4424 */  addiu      $a0, $v0, %lo(D_800EBC68)
    /* 61618 800C9E18 42190300 */  srl        $v1, $v1, 5
    /* 6161C 800C9E1C FFFF6630 */  andi       $a2, $v1, 0xFFFF
    /* 61620 800C9E20 031C0300 */  sra        $v1, $v1, 16
  .L800C9E24:
    /* 61624 800C9E24 0710A300 */  srav       $v0, $v1, $a1
    /* 61628 800C9E28 01004230 */  andi       $v0, $v0, 0x1
    /* 6162C 800C9E2C 05004010 */  beqz       $v0, .L800C9E44
    /* 61630 800C9E30 00000000 */   nop
    /* 61634 800C9E34 00008294 */  lhu        $v0, 0x0($a0)
    /* 61638 800C9E38 00000000 */  nop
    /* 6163C 800C9E3C 00140200 */  sll        $v0, $v0, 16
    /* 61640 800C9E40 2530C200 */  or         $a2, $a2, $v0
  .L800C9E44:
    /* 61644 800C9E44 0100A524 */  addiu      $a1, $a1, 0x1
    /* 61648 800C9E48 0800A228 */  slti       $v0, $a1, 0x8
    /* 6164C 800C9E4C F5FF4014 */  bnez       $v0, .L800C9E24
    /* 61650 800C9E50 02008424 */   addiu     $a0, $a0, 0x2
    /* 61654 800C9E54 0800E003 */  jr         $ra
    /* 61658 800C9E58 2110C000 */   addu      $v0, $a2, $zero
endlabel vs_battle_getStatusFlags
