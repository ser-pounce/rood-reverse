nonmatching SoundVM_FE12_VolumeBalanceSlide, 0x84

glabel SoundVM_FE12_VolumeBalanceSlide
    /* BD14 8001B514 21308000 */  addu       $a2, $a0, $zero
    /* BD18 8001B518 0000C28C */  lw         $v0, 0x0($a2)
    /* BD1C 8001B51C 00000000 */  nop
    /* BD20 8001B520 00004390 */  lbu        $v1, 0x0($v0)
    /* BD24 8001B524 01004224 */  addiu      $v0, $v0, 0x1
    /* BD28 8001B528 0000C2AC */  sw         $v0, 0x0($a2)
    /* BD2C 8001B52C 03006014 */  bnez       $v1, .L8001B53C
    /* BD30 8001B530 8400C3A4 */   sh        $v1, 0x84($a2)
    /* BD34 8001B534 00010224 */  addiu      $v0, $zero, 0x100
    /* BD38 8001B538 8400C2A4 */  sh         $v0, 0x84($a2)
  .L8001B53C:
    /* BD3C 8001B53C 0000C58C */  lw         $a1, 0x0($a2)
    /* BD40 8001B540 8200C494 */  lhu        $a0, 0x82($a2)
    /* BD44 8001B544 8400C394 */  lhu        $v1, 0x84($a2)
    /* BD48 8001B548 0000A290 */  lbu        $v0, 0x0($a1)
    /* BD4C 8001B54C 007F8430 */  andi       $a0, $a0, 0x7F00
    /* BD50 8001B550 00120200 */  sll        $v0, $v0, 8
    /* BD54 8001B554 23104400 */  subu       $v0, $v0, $a0
    /* BD58 8001B558 1A004300 */  div        $zero, $v0, $v1
    /* BD5C 8001B55C 02006014 */  bnez       $v1, .L8001B568
    /* BD60 8001B560 00000000 */   nop
    /* BD64 8001B564 0D000700 */  break      7
  .L8001B568:
    /* BD68 8001B568 FFFF0124 */  addiu      $at, $zero, -0x1
    /* BD6C 8001B56C 04006114 */  bne        $v1, $at, .L8001B580
    /* BD70 8001B570 0080013C */   lui       $at, (0x80000000 >> 16)
    /* BD74 8001B574 02004114 */  bne        $v0, $at, .L8001B580
    /* BD78 8001B578 00000000 */   nop
    /* BD7C 8001B57C 0D000600 */  break      6
  .L8001B580:
    /* BD80 8001B580 12100000 */  mflo       $v0
    /* BD84 8001B584 0100A524 */  addiu      $a1, $a1, 0x1
    /* BD88 8001B588 0000C5AC */  sw         $a1, 0x0($a2)
    /* BD8C 8001B58C 8200C4A4 */  sh         $a0, 0x82($a2)
    /* BD90 8001B590 0800E003 */  jr         $ra
    /* BD94 8001B594 D800C2A4 */   sh        $v0, 0xD8($a2)
endlabel SoundVM_FE12_VolumeBalanceSlide
