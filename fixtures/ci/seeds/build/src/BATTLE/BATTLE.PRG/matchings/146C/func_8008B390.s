nonmatching func_8008B390, 0xA0

glabel func_8008B390
    /* 22B90 8008B390 2160A000 */  addu       $t4, $a1, $zero
    /* 22B94 8008B394 0000AB8C */  lw         $t3, 0x0($a1)
    /* 22B98 8008B398 0400A524 */  addiu      $a1, $a1, 0x4
    /* 22B9C 8008B39C 22006019 */  blez       $t3, .L8008B428
    /* 22BA0 8008B3A0 21480000 */   addu      $t1, $zero, $zero
  .L8008B3A4:
    /* 22BA4 8008B3A4 1C00A28C */  lw         $v0, 0x1C($a1)
    /* 22BA8 8008B3A8 21380000 */  addu       $a3, $zero, $zero
    /* 22BAC 8008B3AC 83100200 */  sra        $v0, $v0, 2
    /* 22BB0 8008B3B0 80100200 */  sll        $v0, $v0, 2
    /* 22BB4 8008B3B4 21188201 */  addu       $v1, $t4, $v0
    /* 22BB8 8008B3B8 0000688C */  lw         $t0, 0x0($v1)
    /* 22BBC 8008B3BC 04006324 */  addiu      $v1, $v1, 0x4
    /* 22BC0 8008B3C0 00006A8C */  lw         $t2, 0x0($v1)
    /* 22BC4 8008B3C4 0A000019 */  blez       $t0, .L8008B3F0
    /* 22BC8 8008B3C8 04006324 */   addiu     $v1, $v1, 0x4
    /* 22BCC 8008B3CC 1E006624 */  addiu      $a2, $v1, 0x1E
  .L8008B3D0:
    /* 22BD0 8008B3D0 0100E724 */  addiu      $a3, $a3, 0x1
    /* 22BD4 8008B3D4 0000C294 */  lhu        $v0, 0x0($a2)
    /* 22BD8 8008B3D8 20006324 */  addiu      $v1, $v1, 0x20
    /* 22BDC 8008B3DC 21104400 */  addu       $v0, $v0, $a0
    /* 22BE0 8008B3E0 0000C2A4 */  sh         $v0, 0x0($a2)
    /* 22BE4 8008B3E4 2A10E800 */  slt        $v0, $a3, $t0
    /* 22BE8 8008B3E8 F9FF4014 */  bnez       $v0, .L8008B3D0
    /* 22BEC 8008B3EC 2000C624 */   addiu     $a2, $a2, 0x20
  .L8008B3F0:
    /* 22BF0 8008B3F0 09004019 */  blez       $t2, .L8008B418
    /* 22BF4 8008B3F4 21380000 */   addu      $a3, $zero, $zero
    /* 22BF8 8008B3F8 1E006324 */  addiu      $v1, $v1, 0x1E
  .L8008B3FC:
    /* 22BFC 8008B3FC 00006294 */  lhu        $v0, 0x0($v1)
    /* 22C00 8008B400 0100E724 */  addiu      $a3, $a3, 0x1
    /* 22C04 8008B404 21104400 */  addu       $v0, $v0, $a0
    /* 22C08 8008B408 000062A4 */  sh         $v0, 0x0($v1)
    /* 22C0C 8008B40C 2A10EA00 */  slt        $v0, $a3, $t2
    /* 22C10 8008B410 FAFF4014 */  bnez       $v0, .L8008B3FC
    /* 22C14 8008B414 28006324 */   addiu     $v1, $v1, 0x28
  .L8008B418:
    /* 22C18 8008B418 01002925 */  addiu      $t1, $t1, 0x1
    /* 22C1C 8008B41C 2A102B01 */  slt        $v0, $t1, $t3
    /* 22C20 8008B420 E0FF4014 */  bnez       $v0, .L8008B3A4
    /* 22C24 8008B424 4000A524 */   addiu     $a1, $a1, 0x40
  .L8008B428:
    /* 22C28 8008B428 0800E003 */  jr         $ra
    /* 22C2C 8008B42C 00000000 */   nop
endlabel func_8008B390
