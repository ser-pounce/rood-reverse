nonmatching func_800D47F4, 0x88

glabel func_800D47F4
    /* 6BFF4 800D47F4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6BFF8 800D47F8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6BFFC 800D47FC 21888000 */  addu       $s1, $a0, $zero
    /* 6C000 800D4800 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 6C004 800D4804 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6C008 800D4808 5C54030C */  jal        func_800D5170
    /* 6C00C 800D480C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 6C010 800D4810 21202002 */  addu       $a0, $s1, $zero
    /* 6C014 800D4814 6654030C */  jal        func_800D5198
    /* 6C018 800D4818 FF005230 */   andi      $s2, $v0, 0xFF
    /* 6C01C 800D481C FFFF5030 */  andi       $s0, $v0, 0xFFFF
    /* 6C020 800D4820 6654030C */  jal        func_800D5198
    /* 6C024 800D4824 21202002 */   addu      $a0, $s1, $zero
    /* 6C028 800D4828 00140200 */  sll        $v0, $v0, 16
    /* 6C02C 800D482C 580D238E */  lw         $v1, 0xD58($s1)
    /* 6C030 800D4830 00000000 */  nop
    /* 6C034 800D4834 02006010 */  beqz       $v1, .L800D4840
    /* 6C038 800D4838 21800202 */   addu      $s0, $s0, $v0
    /* 6C03C 800D483C 21806000 */  addu       $s0, $v1, $zero
  .L800D4840:
    /* 6C040 800D4840 21202002 */  addu       $a0, $s1, $zero
    /* 6C044 800D4844 0F80033C */  lui        $v1, %hi(D_800EC324)
    /* 6C048 800D4848 24C36324 */  addiu      $v1, $v1, %lo(D_800EC324)
    /* 6C04C 800D484C 80101200 */  sll        $v0, $s2, 2
    /* 6C050 800D4850 21104300 */  addu       $v0, $v0, $v1
    /* 6C054 800D4854 0000458C */  lw         $a1, 0x0($v0)
    /* 6C058 800D4858 A53D030C */  jal        func_800CF694
    /* 6C05C 800D485C 21300002 */   addu      $a2, $s0, $zero
    /* 6C060 800D4860 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6C064 800D4864 1800B28F */  lw         $s2, 0x18($sp)
    /* 6C068 800D4868 1400B18F */  lw         $s1, 0x14($sp)
    /* 6C06C 800D486C 1000B08F */  lw         $s0, 0x10($sp)
    /* 6C070 800D4870 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C074 800D4874 0800E003 */  jr         $ra
    /* 6C078 800D4878 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800D47F4
