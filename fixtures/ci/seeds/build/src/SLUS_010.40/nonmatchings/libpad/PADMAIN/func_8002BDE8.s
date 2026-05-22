nonmatching func_8002BDE8, 0x68

glabel func_8002BDE8
    /* 1C5E8 8002BDE8 0380033C */  lui        $v1, %hi(D_800335FC)
    /* 1C5EC 8002BDEC FC35638C */  lw         $v1, %lo(D_800335FC)($v1)
    /* 1C5F0 8002BDF0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1C5F4 8002BDF4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1C5F8 8002BDF8 0400628C */  lw         $v0, 0x4($v1)
    /* 1C5FC 8002BDFC 00000000 */  nop
    /* 1C600 8002BE00 01004230 */  andi       $v0, $v0, 0x1
    /* 1C604 8002BE04 0E004010 */  beqz       $v0, .L8002BE40
    /* 1C608 8002BE08 21100000 */   addu      $v0, $zero, $zero
    /* 1C60C 8002BE0C 0000628C */  lw         $v0, 0x0($v1)
    /* 1C610 8002BE10 00000000 */  nop
    /* 1C614 8002BE14 01004230 */  andi       $v0, $v0, 0x1
    /* 1C618 8002BE18 09004010 */  beqz       $v0, .L8002BE40
    /* 1C61C 8002BE1C 21100000 */   addu      $v0, $zero, $zero
    /* 1C620 8002BE20 0380023C */  lui        $v0, %hi(D_800335C4)
    /* 1C624 8002BE24 C435428C */  lw         $v0, %lo(D_800335C4)($v0)
    /* 1C628 8002BE28 00000000 */  nop
    /* 1C62C 8002BE2C 03004010 */  beqz       $v0, .L8002BE3C
    /* 1C630 8002BE30 00000000 */   nop
    /* 1C634 8002BE34 09F84000 */  jalr       $v0
    /* 1C638 8002BE38 00000000 */   nop
  .L8002BE3C:
    /* 1C63C 8002BE3C 01000224 */  addiu      $v0, $zero, 0x1
  .L8002BE40:
    /* 1C640 8002BE40 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1C644 8002BE44 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1C648 8002BE48 0800E003 */  jr         $ra
    /* 1C64C 8002BE4C 00000000 */   nop
endlabel func_8002BDE8
