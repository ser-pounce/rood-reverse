nonmatching func_800CF830, 0x8C

glabel func_800CF830
    /* 67030 800CF830 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 67034 800CF834 0F80023C */  lui        $v0, %hi(D_800F54B0)
    /* 67038 800CF838 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6703C 800CF83C B054518C */  lw         $s1, %lo(D_800F54B0)($v0)
    /* 67040 800CF840 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 67044 800CF844 1800B2AF */  sw         $s2, 0x18($sp)
    /* 67048 800CF848 16002012 */  beqz       $s1, .L800CF8A4
    /* 6704C 800CF84C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 67050 800CF850 0D80023C */  lui        $v0, %hi(func_800CE174)
    /* 67054 800CF854 74E15224 */  addiu      $s2, $v0, %lo(func_800CE174)
  .L800CF858:
    /* 67058 800CF858 500D308E */  lw         $s0, 0xD50($s1)
    /* 6705C 800CF85C 00000000 */  nop
    /* 67060 800CF860 0C000012 */  beqz       $s0, .L800CF894
    /* 67064 800CF864 00000000 */   nop
  .L800CF868:
    /* 67068 800CF868 0400028E */  lw         $v0, 0x4($s0)
    /* 6706C 800CF86C 00000000 */  nop
    /* 67070 800CF870 04005214 */  bne        $v0, $s2, .L800CF884
    /* 67074 800CF874 21200002 */   addu      $a0, $s0, $zero
    /* 67078 800CF878 03000524 */  addiu      $a1, $zero, 0x3
    /* 6707C 800CF87C 09F84000 */  jalr       $v0
    /* 67080 800CF880 21300000 */   addu      $a2, $zero, $zero
  .L800CF884:
    /* 67084 800CF884 0000108E */  lw         $s0, 0x0($s0)
    /* 67088 800CF888 00000000 */  nop
    /* 6708C 800CF88C F6FF0016 */  bnez       $s0, .L800CF868
    /* 67090 800CF890 00000000 */   nop
  .L800CF894:
    /* 67094 800CF894 0000318E */  lw         $s1, 0x0($s1)
    /* 67098 800CF898 00000000 */  nop
    /* 6709C 800CF89C EEFF2016 */  bnez       $s1, .L800CF858
    /* 670A0 800CF8A0 00000000 */   nop
  .L800CF8A4:
    /* 670A4 800CF8A4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 670A8 800CF8A8 1800B28F */  lw         $s2, 0x18($sp)
    /* 670AC 800CF8AC 1400B18F */  lw         $s1, 0x14($sp)
    /* 670B0 800CF8B0 1000B08F */  lw         $s0, 0x10($sp)
    /* 670B4 800CF8B4 0800E003 */  jr         $ra
    /* 670B8 800CF8B8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800CF830
