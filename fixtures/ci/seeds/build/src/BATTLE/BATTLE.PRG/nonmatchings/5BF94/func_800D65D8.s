nonmatching func_800D65D8, 0x50

glabel func_800D65D8
    /* 6DDD8 800D65D8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6DDDC 800D65DC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6DDE0 800D65E0 280D8394 */  lhu        $v1, 0xD28($a0)
    /* 6DDE4 800D65E4 04000224 */  addiu      $v0, $zero, 0x4
    /* 6DDE8 800D65E8 0B006214 */  bne        $v1, $v0, .L800D6618
    /* 6DDEC 800D65EC FF00A630 */   andi      $a2, $a1, 0xFF
    /* 6DDF0 800D65F0 0400C010 */  beqz       $a2, .L800D6604
    /* 6DDF4 800D65F4 01000524 */   addiu     $a1, $zero, 0x1
    /* 6DDF8 800D65F8 2C0D8490 */  lbu        $a0, 0xD2C($a0)
    /* 6DDFC 800D65FC 84590308 */  j          .L800D6610
    /* 6DE00 800D6600 00000000 */   nop
  .L800D6604:
    /* 6DE04 800D6604 2C0D8490 */  lbu        $a0, 0xD2C($a0)
    /* 6DE08 800D6608 21280000 */  addu       $a1, $zero, $zero
    /* 6DE0C 800D660C 2130A000 */  addu       $a2, $a1, $zero
  .L800D6610:
    /* 6DE10 800D6610 267E020C */  jal        func_8009F898
    /* 6DE14 800D6614 00000000 */   nop
  .L800D6618:
    /* 6DE18 800D6618 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6DE1C 800D661C 00000000 */  nop
    /* 6DE20 800D6620 0800E003 */  jr         $ra
    /* 6DE24 800D6624 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D65D8
