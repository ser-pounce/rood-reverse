nonmatching func_800C0FA8, 0x8C

glabel func_800C0FA8
    /* 587A8 800C0FA8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 587AC 800C0FAC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 587B0 800C0FB0 21400000 */  addu       $t0, $zero, $zero
    /* 587B4 800C0FB4 00800A34 */  ori        $t2, $zero, 0x8000
    /* 587B8 800C0FB8 21488000 */  addu       $t1, $a0, $zero
    /* 587BC 800C0FBC 2138A000 */  addu       $a3, $a1, $zero
  .L800C0FC0:
    /* 587C0 800C0FC0 08002295 */  lhu        $v0, 0x8($t1)
    /* 587C4 800C0FC4 00000000 */  nop
    /* 587C8 800C0FC8 1000E2A4 */  sh         $v0, 0x10($a3)
    /* 587CC 800C0FCC 21100401 */  addu       $v0, $t0, $a0
    /* 587D0 800C0FD0 04004290 */  lbu        $v0, 0x4($v0)
    /* 587D4 800C0FD4 00000000 */  nop
    /* 587D8 800C0FD8 1A004201 */  div        $zero, $t2, $v0
    /* 587DC 800C0FDC 12100000 */  mflo       $v0
    /* 587E0 800C0FE0 02002925 */  addiu      $t1, $t1, 0x2
    /* 587E4 800C0FE4 01000825 */  addiu      $t0, $t0, 0x1
    /* 587E8 800C0FE8 1800E2A4 */  sh         $v0, 0x18($a3)
    /* 587EC 800C0FEC 03000229 */  slti       $v0, $t0, 0x3
    /* 587F0 800C0FF0 F3FF4014 */  bnez       $v0, .L800C0FC0
    /* 587F4 800C0FF4 0200E724 */   addiu     $a3, $a3, 0x2
    /* 587F8 800C0FF8 07008290 */  lbu        $v0, 0x7($a0)
    /* 587FC 800C0FFC 00000000 */  nop
    /* 58800 800C1000 00110200 */  sll        $v0, $v0, 4
    /* 58804 800C1004 0000A2A4 */  sh         $v0, 0x0($a1)
    /* 58808 800C1008 02008294 */  lhu        $v0, 0x2($a0)
    /* 5880C 800C100C 2120A000 */  addu       $a0, $a1, $zero
    /* 58810 800C1010 0400A0A4 */  sh         $zero, 0x4($a1)
    /* 58814 800C1014 23100200 */  negu       $v0, $v0
    /* 58818 800C1018 0200A2A4 */  sh         $v0, 0x2($a1)
    /* 5881C 800C101C 8004010C */  jal        RotMatrix_gte
    /* 58820 800C1020 2128C000 */   addu      $a1, $a2, $zero
    /* 58824 800C1024 1000BF8F */  lw         $ra, 0x10($sp)
    /* 58828 800C1028 00000000 */  nop
    /* 5882C 800C102C 0800E003 */  jr         $ra
    /* 58830 800C1030 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800C0FA8
