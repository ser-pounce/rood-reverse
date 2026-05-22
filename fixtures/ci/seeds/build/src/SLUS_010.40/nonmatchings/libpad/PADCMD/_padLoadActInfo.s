nonmatching _padLoadActInfo, 0xD4

glabel _padLoadActInfo
    /* 1D5DC 8002CDDC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1D5E0 8002CDE0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1D5E4 8002CDE4 21808000 */  addu       $s0, $a0, $zero
    /* 1D5E8 8002CDE8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1D5EC 8002CDEC 2188A000 */  addu       $s1, $a1, $zero
    /* 1D5F0 8002CDF0 0C002012 */  beqz       $s1, .L8002CE24
    /* 1D5F4 8002CDF4 1800BFAF */   sw        $ra, 0x18($sp)
    /* 1D5F8 8002CDF8 0400028E */  lw         $v0, 0x4($s0)
    /* 1D5FC 8002CDFC 00000000 */  nop
    /* 1D600 8002CE00 26004014 */  bnez       $v0, .L8002CE9C
    /* 1D604 8002CE04 21100000 */   addu      $v0, $zero, $zero
    /* 1D608 8002CE08 0380023C */  lui        $v0, %hi(D_800335B8)
    /* 1D60C 8002CE0C B835428C */  lw         $v0, %lo(D_800335B8)($v0)
    /* 1D610 8002CE10 00000000 */  nop
    /* 1D614 8002CE14 09F84000 */  jalr       $v0
    /* 1D618 8002CE18 00000000 */   nop
    /* 1D61C 8002CE1C 03004010 */  beqz       $v0, .L8002CE2C
    /* 1D620 8002CE20 01000224 */   addiu     $v0, $zero, 0x1
  .L8002CE24:
    /* 1D624 8002CE24 A7B30008 */  j          .L8002CE9C
    /* 1D628 8002CE28 21100000 */   addu      $v0, $zero, $zero
  .L8002CE2C:
    /* 1D62C 8002CE2C 04000324 */  addiu      $v1, $zero, 0x4
    /* 1D630 8002CE30 03002526 */  addiu      $a1, $s1, 0x3
    /* 1D634 8002CE34 83280500 */  sra        $a1, $a1, 2
    /* 1D638 8002CE38 490003A2 */  sb         $v1, 0x49($s0)
    /* 1D63C 8002CE3C 01000324 */  addiu      $v1, $zero, 0x1
    /* 1D640 8002CE40 460003A2 */  sb         $v1, 0x46($s0)
    /* 1D644 8002CE44 0380033C */  lui        $v1, %hi(func_8002CEB0)
    /* 1D648 8002CE48 B0CE6324 */  addiu      $v1, $v1, %lo(func_8002CEB0)
    /* 1D64C 8002CE4C 140003AE */  sw         $v1, 0x14($s0)
    /* 1D650 8002CE50 E3000392 */  lbu        $v1, 0xE3($s0)
    /* 1D654 8002CE54 0380043C */  lui        $a0, %hi(func_8002CF58)
    /* 1D658 8002CE58 58CF8424 */  addiu      $a0, $a0, %lo(func_8002CF58)
    /* 1D65C 8002CE5C 180004AE */  sw         $a0, 0x18($s0)
    /* 1D660 8002CE60 E9000492 */  lbu        $a0, 0xE9($s0)
    /* 1D664 8002CE64 80280500 */  sll        $a1, $a1, 2
    /* 1D668 8002CE68 000005AE */  sw         $a1, 0x0($s0)
    /* 1D66C 8002CE6C 470000A2 */  sb         $zero, 0x47($s0)
    /* 1D670 8002CE70 01006324 */  addiu      $v1, $v1, 0x1
    /* 1D674 8002CE74 43180300 */  sra        $v1, $v1, 1
    /* 1D678 8002CE78 80180300 */  sll        $v1, $v1, 2
    /* 1D67C 8002CE7C 2128A300 */  addu       $a1, $a1, $v1
    /* 1D680 8002CE80 80180400 */  sll        $v1, $a0, 2
    /* 1D684 8002CE84 21186400 */  addu       $v1, $v1, $a0
    /* 1D688 8002CE88 03006324 */  addiu      $v1, $v1, 0x3
    /* 1D68C 8002CE8C FC0F6330 */  andi       $v1, $v1, 0xFFC
    /* 1D690 8002CE90 040005AE */  sw         $a1, 0x4($s0)
    /* 1D694 8002CE94 2128A300 */  addu       $a1, $a1, $v1
    /* 1D698 8002CE98 080005AE */  sw         $a1, 0x8($s0)
  .L8002CE9C:
    /* 1D69C 8002CE9C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1D6A0 8002CEA0 1400B18F */  lw         $s1, 0x14($sp)
    /* 1D6A4 8002CEA4 1000B08F */  lw         $s0, 0x10($sp)
    /* 1D6A8 8002CEA8 0800E003 */  jr         $ra
    /* 1D6AC 8002CEAC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _padLoadActInfo
