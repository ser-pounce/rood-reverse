nonmatching _spu_Fw1ts, 0x5C

glabel _spu_Fw1ts
    /* ED2C 8001E52C F8FFBD27 */  addiu      $sp, $sp, -0x8
    /* ED30 8001E530 0D000224 */  addiu      $v0, $zero, 0xD
    /* ED34 8001E534 0400A2AF */  sw         $v0, 0x4($sp)
    /* ED38 8001E538 5B790008 */  j          .L8001E56C
    /* ED3C 8001E53C 0000A0AF */   sw        $zero, 0x0($sp)
  .L8001E540:
    /* ED40 8001E540 0400A38F */  lw         $v1, 0x4($sp)
    /* ED44 8001E544 00000000 */  nop
    /* ED48 8001E548 40100300 */  sll        $v0, $v1, 1
    /* ED4C 8001E54C 21104300 */  addu       $v0, $v0, $v1
    /* ED50 8001E550 80100200 */  sll        $v0, $v0, 2
    /* ED54 8001E554 21104300 */  addu       $v0, $v0, $v1
    /* ED58 8001E558 0400A2AF */  sw         $v0, 0x4($sp)
    /* ED5C 8001E55C 0000A28F */  lw         $v0, 0x0($sp)
    /* ED60 8001E560 00000000 */  nop
    /* ED64 8001E564 01004224 */  addiu      $v0, $v0, 0x1
    /* ED68 8001E568 0000A2AF */  sw         $v0, 0x0($sp)
  .L8001E56C:
    /* ED6C 8001E56C 0000A28F */  lw         $v0, 0x0($sp)
    /* ED70 8001E570 00000000 */  nop
    /* ED74 8001E574 3C004228 */  slti       $v0, $v0, 0x3C
    /* ED78 8001E578 F1FF4014 */  bnez       $v0, .L8001E540
    /* ED7C 8001E57C 00000000 */   nop
    /* ED80 8001E580 0800E003 */  jr         $ra
    /* ED84 8001E584 0800BD27 */   addiu     $sp, $sp, 0x8
endlabel _spu_Fw1ts
    /* ED88 8001E588 00000000 */  nop
    /* ED8C 8001E58C 00000000 */  nop
    /* ED90 8001E590 00000000 */  nop
