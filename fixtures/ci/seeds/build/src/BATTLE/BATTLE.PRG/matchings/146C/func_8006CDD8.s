nonmatching func_8006CDD8, 0x78

glabel func_8006CDD8
    /* 45D8 8006CDD8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 45DC 8006CDDC 21288000 */  addu       $a1, $a0, $zero
    /* 45E0 8006CDE0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 45E4 8006CDE4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 45E8 8006CDE8 0000A484 */  lh         $a0, 0x0($a1)
    /* 45EC 8006CDEC 00000000 */  nop
    /* 45F0 8006CDF0 02008104 */  bgez       $a0, .L8006CDFC
    /* 45F4 8006CDF4 00000000 */   nop
    /* 45F8 8006CDF8 7F008424 */  addiu      $a0, $a0, 0x7F
  .L8006CDFC:
    /* 45FC 8006CDFC 0400A584 */  lh         $a1, 0x4($a1)
    /* 4600 8006CE00 00000000 */  nop
    /* 4604 8006CE04 0200A104 */  bgez       $a1, .L8006CE10
    /* 4608 8006CE08 C3210400 */   sra       $a0, $a0, 7
    /* 460C 8006CE0C 7F00A524 */  addiu      $a1, $a1, 0x7F
  .L8006CE10:
    /* 4610 8006CE10 C3290500 */  sra        $a1, $a1, 7
    /* 4614 8006CE14 0E35020C */  jal        func_8008D438
    /* 4618 8006CE18 21300000 */   addu      $a2, $zero, $zero
    /* 461C 8006CE1C 21804000 */  addu       $s0, $v0, $zero
    /* 4620 8006CE20 07000012 */  beqz       $s0, .L8006CE40
    /* 4624 8006CE24 21200002 */   addu      $a0, $s0, $zero
    /* 4628 8006CE28 AB37020C */  jal        func_8008DEAC
    /* 462C 8006CE2C 01000524 */   addiu     $a1, $zero, 0x1
    /* 4630 8006CE30 00000486 */  lh         $a0, 0x0($s0)
    /* 4634 8006CE34 02000586 */  lh         $a1, 0x2($s0)
    /* 4638 8006CE38 3B9A030C */  jal        func_800E68EC
    /* 463C 8006CE3C 00000000 */   nop
  .L8006CE40:
    /* 4640 8006CE40 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4644 8006CE44 1000B08F */  lw         $s0, 0x10($sp)
    /* 4648 8006CE48 0800E003 */  jr         $ra
    /* 464C 8006CE4C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006CDD8
