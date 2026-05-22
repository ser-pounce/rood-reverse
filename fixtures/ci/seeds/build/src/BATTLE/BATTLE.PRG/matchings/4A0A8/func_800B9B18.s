nonmatching func_800B9B18, 0xE0

glabel func_800B9B18
    /* 51318 800B9B18 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5131C 800B9B1C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 51320 800B9B20 21808000 */  addu       $s0, $a0, $zero
    /* 51324 800B9B24 1400BFAF */  sw         $ra, 0x14($sp)
    /* 51328 800B9B28 01000292 */  lbu        $v0, 0x1($s0)
    /* 5132C 800B9B2C 00000000 */  nop
    /* 51330 800B9B30 03004330 */  andi       $v1, $v0, 0x3
    /* 51334 800B9B34 05006010 */  beqz       $v1, .L800B9B4C
    /* 51338 800B9B38 01000224 */   addiu     $v0, $zero, 0x1
    /* 5133C 800B9B3C 07006210 */  beq        $v1, $v0, .L800B9B5C
    /* 51340 800B9B40 00000000 */   nop
    /* 51344 800B9B44 D9E60208 */  j          .L800B9B64
    /* 51348 800B9B48 00000000 */   nop
  .L800B9B4C:
    /* 5134C 800B9B4C 09F1010C */  jal        func_8007C424
    /* 51350 800B9B50 00000000 */   nop
    /* 51354 800B9B54 D9E60208 */  j          .L800B9B64
    /* 51358 800B9B58 00000000 */   nop
  .L800B9B5C:
    /* 5135C 800B9B5C 01F1010C */  jal        func_8007C404
    /* 51360 800B9B60 00000000 */   nop
  .L800B9B64:
    /* 51364 800B9B64 01000292 */  lbu        $v0, 0x1($s0)
    /* 51368 800B9B68 00000000 */  nop
    /* 5136C 800B9B6C 82100200 */  srl        $v0, $v0, 2
    /* 51370 800B9B70 03004330 */  andi       $v1, $v0, 0x3
    /* 51374 800B9B74 05006010 */  beqz       $v1, .L800B9B8C
    /* 51378 800B9B78 01000224 */   addiu     $v0, $zero, 0x1
    /* 5137C 800B9B7C 07006210 */  beq        $v1, $v0, .L800B9B9C
    /* 51380 800B9B80 00000000 */   nop
    /* 51384 800B9B84 E9E60208 */  j          .L800B9BA4
    /* 51388 800B9B88 00000000 */   nop
  .L800B9B8C:
    /* 5138C 800B9B8C D3EF010C */  jal        func_8007BF4C
    /* 51390 800B9B90 00000000 */   nop
    /* 51394 800B9B94 E9E60208 */  j          .L800B9BA4
    /* 51398 800B9B98 00000000 */   nop
  .L800B9B9C:
    /* 5139C 800B9B9C CBEF010C */  jal        func_8007BF2C
    /* 513A0 800B9BA0 00000000 */   nop
  .L800B9BA4:
    /* 513A4 800B9BA4 01000292 */  lbu        $v0, 0x1($s0)
    /* 513A8 800B9BA8 00000000 */  nop
    /* 513AC 800B9BAC 02110200 */  srl        $v0, $v0, 4
    /* 513B0 800B9BB0 03004330 */  andi       $v1, $v0, 0x3
    /* 513B4 800B9BB4 05006010 */  beqz       $v1, .L800B9BCC
    /* 513B8 800B9BB8 01000224 */   addiu     $v0, $zero, 0x1
    /* 513BC 800B9BBC 07006210 */  beq        $v1, $v0, .L800B9BDC
    /* 513C0 800B9BC0 00000000 */   nop
    /* 513C4 800B9BC4 F9E60208 */  j          .L800B9BE4
    /* 513C8 800B9BC8 00000000 */   nop
  .L800B9BCC:
    /* 513CC 800B9BCC 14F0010C */  jal        func_8007C050
    /* 513D0 800B9BD0 00000000 */   nop
    /* 513D4 800B9BD4 F9E60208 */  j          .L800B9BE4
    /* 513D8 800B9BD8 00000000 */   nop
  .L800B9BDC:
    /* 513DC 800B9BDC F0EF010C */  jal        func_8007BFC0
    /* 513E0 800B9BE0 00000000 */   nop
  .L800B9BE4:
    /* 513E4 800B9BE4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 513E8 800B9BE8 1000B08F */  lw         $s0, 0x10($sp)
    /* 513EC 800B9BEC 21100000 */  addu       $v0, $zero, $zero
    /* 513F0 800B9BF0 0800E003 */  jr         $ra
    /* 513F4 800B9BF4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B9B18
