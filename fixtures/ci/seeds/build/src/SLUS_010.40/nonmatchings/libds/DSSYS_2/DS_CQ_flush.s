nonmatching DS_CQ_flush, 0x60

glabel DS_CQ_flush
    /* 13B00 80023300 21280000 */  addu       $a1, $zero, $zero
    /* 13B04 80023304 0480023C */  lui        $v0, %hi(D_80039DB8)
    /* 13B08 80023308 B89D4224 */  addiu      $v0, $v0, %lo(D_80039DB8)
    /* 13B0C 8002330C 38FF4424 */  addiu      $a0, $v0, -0xC8
    /* 13B10 80023310 000040AC */  sw         $zero, 0x0($v0)
    /* 13B14 80023314 FCFF40AC */  sw         $zero, -0x4($v0)
    /* 13B18 80023318 F8FF40AC */  sw         $zero, -0x8($v0)
  .L8002331C:
    /* 13B1C 8002331C 03000324 */  addiu      $v1, $zero, 0x3
    /* 13B20 80023320 03008224 */  addiu      $v0, $a0, 0x3
    /* 13B24 80023324 000080AC */  sw         $zero, 0x0($a0)
    /* 13B28 80023328 040080A0 */  sb         $zero, 0x4($a0)
  .L8002332C:
    /* 13B2C 8002332C 050040A0 */  sb         $zero, 0x5($v0)
    /* 13B30 80023330 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 13B34 80023334 FDFF6104 */  bgez       $v1, .L8002332C
    /* 13B38 80023338 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 13B3C 8002333C 0C0080AC */  sw         $zero, 0xC($a0)
    /* 13B40 80023340 100080AC */  sw         $zero, 0x10($a0)
    /* 13B44 80023344 140080AC */  sw         $zero, 0x14($a0)
    /* 13B48 80023348 0100A524 */  addiu      $a1, $a1, 0x1
    /* 13B4C 8002334C 0800A228 */  slti       $v0, $a1, 0x8
    /* 13B50 80023350 F2FF4014 */  bnez       $v0, .L8002331C
    /* 13B54 80023354 18008424 */   addiu     $a0, $a0, 0x18
    /* 13B58 80023358 0800E003 */  jr         $ra
    /* 13B5C 8002335C 00000000 */   nop
endlabel DS_CQ_flush
