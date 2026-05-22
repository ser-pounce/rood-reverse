nonmatching func_80074050, 0xD0

glabel func_80074050
    /* B850 80074050 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* B854 80074054 2400B3AF */  sw         $s3, 0x24($sp)
    /* B858 80074058 21988000 */  addu       $s3, $a0, $zero
    /* B85C 8007405C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* B860 80074060 2188A000 */  addu       $s1, $a1, $zero
    /* B864 80074064 0F80033C */  lui        $v1, %hi(D_800F196C)
    /* B868 80074068 09000224 */  addiu      $v0, $zero, 0x9
    /* B86C 8007406C 6C1962AC */  sw         $v0, %lo(D_800F196C)($v1)
    /* B870 80074070 0F80033C */  lui        $v1, %hi(_cameraMode)
    /* B874 80074074 01000224 */  addiu      $v0, $zero, 0x1
    /* B878 80074078 2800BFAF */  sw         $ra, 0x28($sp)
    /* B87C 8007407C 2000B2AF */  sw         $s2, 0x20($sp)
    /* B880 80074080 1800B0AF */  sw         $s0, 0x18($sp)
    /* B884 80074084 C4BB010C */  jal        func_8006EF10
    /* B888 80074088 F01862AC */   sw        $v0, %lo(_cameraMode)($v1)
    /* B88C 8007408C 21202002 */  addu       $a0, $s1, $zero
    /* B890 80074090 0F80023C */  lui        $v0, %hi(D_800F1910)
    /* B894 80074094 10195024 */  addiu      $s0, $v0, %lo(D_800F1910)
    /* B898 80074098 04000526 */  addiu      $a1, $s0, 0x4
    /* B89C 8007409C 4284020C */  jal        func_800A1108
    /* B8A0 800740A0 101953AC */   sw        $s3, %lo(D_800F1910)($v0)
    /* B8A4 800740A4 21900000 */  addu       $s2, $zero, $zero
    /* B8A8 800740A8 100011AE */  sw         $s1, 0x10($s0)
  .L800740AC:
    /* B8AC 800740AC 7179020C */  jal        func_8009E5C4
    /* B8B0 800740B0 21204002 */   addu      $a0, $s2, $zero
    /* B8B4 800740B4 01005226 */  addiu      $s2, $s2, 0x1
    /* B8B8 800740B8 1000422A */  slti       $v0, $s2, 0x10
    /* B8BC 800740BC FBFF4014 */  bnez       $v0, .L800740AC
    /* B8C0 800740C0 21200000 */   addu      $a0, $zero, $zero
    /* B8C4 800740C4 00006286 */  lh         $v0, 0x0($s3)
    /* B8C8 800740C8 1000A527 */  addiu      $a1, $sp, 0x10
    /* B8CC 800740CC C0110200 */  sll        $v0, $v0, 7
    /* B8D0 800740D0 40004224 */  addiu      $v0, $v0, 0x40
    /* B8D4 800740D4 1000A2A7 */  sh         $v0, 0x10($sp)
    /* B8D8 800740D8 02006286 */  lh         $v0, 0x2($s3)
    /* B8DC 800740DC 01000624 */  addiu      $a2, $zero, 0x1
    /* B8E0 800740E0 C0110200 */  sll        $v0, $v0, 7
    /* B8E4 800740E4 40004224 */  addiu      $v0, $v0, 0x40
    /* B8E8 800740E8 1C78020C */  jal        func_8009E070
    /* B8EC 800740EC 1400A2A7 */   sh        $v0, 0x14($sp)
    /* B8F0 800740F0 0F80023C */  lui        $v0, %hi(D_800F19CC)
    /* B8F4 800740F4 CC19428C */  lw         $v0, %lo(D_800F19CC)($v0)
    /* B8F8 800740F8 00000000 */  nop
    /* B8FC 800740FC 040040AC */  sw         $zero, 0x4($v0)
    /* B900 80074100 080040A4 */  sh         $zero, 0x8($v0)
    /* B904 80074104 2800BF8F */  lw         $ra, 0x28($sp)
    /* B908 80074108 2400B38F */  lw         $s3, 0x24($sp)
    /* B90C 8007410C 2000B28F */  lw         $s2, 0x20($sp)
    /* B910 80074110 1C00B18F */  lw         $s1, 0x1C($sp)
    /* B914 80074114 1800B08F */  lw         $s0, 0x18($sp)
    /* B918 80074118 0800E003 */  jr         $ra
    /* B91C 8007411C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_80074050
