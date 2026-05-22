nonmatching _dropMisc, 0x50

glabel _dropMisc
    /* 35A0 8006BDA0 21300000 */  addu       $a2, $zero, $zero
    /* 35A4 8006BDA4 2118C000 */  addu       $v1, $a2, $zero
    /* 35A8 8006BDA8 03000724 */  addiu      $a3, $zero, 0x3
  .L8006BDAC:
    /* 35AC 8006BDAC 0000A294 */  lhu        $v0, 0x0($a1)
    /* 35B0 8006BDB0 00000000 */  nop
    /* 35B4 8006BDB4 140282A4 */  sh         $v0, 0x214($a0)
    /* 35B8 8006BDB8 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 35BC 8006BDBC 05004010 */  beqz       $v0, .L8006BDD4
    /* 35C0 8006BDC0 00000000 */   nop
    /* 35C4 8006BDC4 0200A290 */  lbu        $v0, 0x2($a1)
    /* 35C8 8006BDC8 01000624 */  addiu      $a2, $zero, 0x1
    /* 35CC 8006BDCC 160287A0 */  sb         $a3, 0x216($a0)
    /* 35D0 8006BDD0 170282A0 */  sb         $v0, 0x217($a0)
  .L8006BDD4:
    /* 35D4 8006BDD4 0400A524 */  addiu      $a1, $a1, 0x4
    /* 35D8 8006BDD8 01006324 */  addiu      $v1, $v1, 0x1
    /* 35DC 8006BDDC 02006228 */  slti       $v0, $v1, 0x2
    /* 35E0 8006BDE0 F2FF4014 */  bnez       $v0, .L8006BDAC
    /* 35E4 8006BDE4 04008424 */   addiu     $a0, $a0, 0x4
    /* 35E8 8006BDE8 0800E003 */  jr         $ra
    /* 35EC 8006BDEC 2110C000 */   addu      $v0, $a2, $zero
endlabel _dropMisc
