nonmatching func_80106780, 0x88

glabel func_80106780
    /* 3F80 80106780 21180000 */  addu       $v1, $zero, $zero
    /* 3F84 80106784 1180023C */  lui        $v0, %hi(_gazetteRows)
    /* 3F88 80106788 30A24624 */  addiu      $a2, $v0, %lo(_gazetteRows)
    /* 3F8C 8010678C 10000A24 */  addiu      $t2, $zero, 0x10
    /* 3F90 80106790 1180023C */  lui        $v0, %hi(_statHeaders)
    /* 3F94 80106794 DC8F4824 */  addiu      $t0, $v0, %lo(_statHeaders)
    /* 3F98 80106798 1180023C */  lui        $v0, %hi(_statDescriptions)
    /* 3F9C 8010679C 00924724 */  addiu      $a3, $v0, %lo(_statDescriptions)
    /* 3FA0 801067A0 01000924 */  addiu      $t1, $zero, 0x1
    /* 3FA4 801067A4 0100C524 */  addiu      $a1, $a2, 0x1
  .L801067A8:
    /* 3FA8 801067A8 40200300 */  sll        $a0, $v1, 1
    /* 3FAC 801067AC 21108800 */  addu       $v0, $a0, $t0
    /* 3FB0 801067B0 0300AAA4 */  sh         $t2, 0x3($a1)
    /* 3FB4 801067B4 00004294 */  lhu        $v0, 0x0($v0)
    /* 3FB8 801067B8 21208700 */  addu       $a0, $a0, $a3
    /* 3FBC 801067BC 40100200 */  sll        $v0, $v0, 1
    /* 3FC0 801067C0 21104800 */  addu       $v0, $v0, $t0
    /* 3FC4 801067C4 0700A2AC */  sw         $v0, 0x7($a1)
    /* 3FC8 801067C8 00008294 */  lhu        $v0, 0x0($a0)
    /* 3FCC 801067CC 01006324 */  addiu      $v1, $v1, 0x1
    /* 3FD0 801067D0 0100A0A0 */  sb         $zero, 0x1($a1)
    /* 3FD4 801067D4 0500A3A4 */  sh         $v1, 0x5($a1)
    /* 3FD8 801067D8 40100200 */  sll        $v0, $v0, 1
    /* 3FDC 801067DC 21104700 */  addu       $v0, $v0, $a3
    /* 3FE0 801067E0 0B00A2AC */  sw         $v0, 0xB($a1)
    /* 3FE4 801067E4 0000C0A0 */  sb         $zero, 0x0($a2)
    /* 3FE8 801067E8 0200A0A0 */  sb         $zero, 0x2($a1)
    /* 3FEC 801067EC 0000A9A0 */  sb         $t1, 0x0($a1)
    /* 3FF0 801067F0 1000A524 */  addiu      $a1, $a1, 0x10
    /* 3FF4 801067F4 17006228 */  slti       $v0, $v1, 0x17
    /* 3FF8 801067F8 EBFF4014 */  bnez       $v0, .L801067A8
    /* 3FFC 801067FC 1000C624 */   addiu     $a2, $a2, 0x10
    /* 4000 80106800 0800E003 */  jr         $ra
    /* 4004 80106804 00000000 */   nop
endlabel func_80106780
