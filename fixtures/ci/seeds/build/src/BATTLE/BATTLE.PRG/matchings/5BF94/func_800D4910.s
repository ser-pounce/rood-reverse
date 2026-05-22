nonmatching func_800D4910, 0x74

glabel func_800D4910
    /* 6C110 800D4910 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6C114 800D4914 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6C118 800D4918 21908000 */  addu       $s2, $a0, $zero
    /* 6C11C 800D491C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 6C120 800D4920 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6C124 800D4924 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6C128 800D4928 500D508E */  lw         $s0, 0xD50($s2)
    /* 6C12C 800D492C 00000000 */  nop
    /* 6C130 800D4930 0D000012 */  beqz       $s0, .L800D4968
    /* 6C134 800D4934 21200002 */   addu      $a0, $s0, $zero
  .L800D4938:
    /* 6C138 800D4938 02000524 */  addiu      $a1, $zero, 0x2
    /* 6C13C 800D493C 0400028E */  lw         $v0, 0x4($s0)
    /* 6C140 800D4940 0000118E */  lw         $s1, 0x0($s0)
    /* 6C144 800D4944 09F84000 */  jalr       $v0
    /* 6C148 800D4948 21300000 */   addu      $a2, $zero, $zero
    /* 6C14C 800D494C 03004014 */  bnez       $v0, .L800D495C
    /* 6C150 800D4950 21204002 */   addu      $a0, $s2, $zero
    /* 6C154 800D4954 C33D030C */  jal        func_800CF70C
    /* 6C158 800D4958 21280002 */   addu      $a1, $s0, $zero
  .L800D495C:
    /* 6C15C 800D495C 21802002 */  addu       $s0, $s1, $zero
    /* 6C160 800D4960 F5FF0016 */  bnez       $s0, .L800D4938
    /* 6C164 800D4964 21200002 */   addu      $a0, $s0, $zero
  .L800D4968:
    /* 6C168 800D4968 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6C16C 800D496C 1800B28F */  lw         $s2, 0x18($sp)
    /* 6C170 800D4970 1400B18F */  lw         $s1, 0x14($sp)
    /* 6C174 800D4974 1000B08F */  lw         $s0, 0x10($sp)
    /* 6C178 800D4978 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C17C 800D497C 0800E003 */  jr         $ra
    /* 6C180 800D4980 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800D4910
