nonmatching func_8009DF3C, 0x134

glabel func_8009DF3C
    /* 3573C 8009DF3C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 35740 8009DF40 2800B4AF */  sw         $s4, 0x28($sp)
    /* 35744 8009DF44 21A08000 */  addu       $s4, $a0, $zero
    /* 35748 8009DF48 2400B3AF */  sw         $s3, 0x24($sp)
    /* 3574C 8009DF4C 2198A000 */  addu       $s3, $a1, $zero
    /* 35750 8009DF50 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 35754 8009DF54 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 35758 8009DF58 80181400 */  sll        $v1, $s4, 2
    /* 3575C 8009DF5C 21186200 */  addu       $v1, $v1, $v0
    /* 35760 8009DF60 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 35764 8009DF64 2000B2AF */  sw         $s2, 0x20($sp)
    /* 35768 8009DF68 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 3576C 8009DF6C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 35770 8009DF70 0000728C */  lw         $s2, 0x0($v1)
    /* 35774 8009DF74 21800000 */  addu       $s0, $zero, $zero
    /* 35778 8009DF78 0F004292 */  lbu        $v0, 0xF($s2)
    /* 3577C 8009DF7C 00000000 */  nop
    /* 35780 8009DF80 32004010 */  beqz       $v0, .L8009E04C
    /* 35784 8009DF84 21880002 */   addu      $s1, $s0, $zero
    /* 35788 8009DF88 01000224 */  addiu      $v0, $zero, 0x1
    /* 3578C 8009DF8C 0F006212 */  beq        $s3, $v0, .L8009DFCC
    /* 35790 8009DF90 0200622A */   slti      $v0, $s3, 0x2
    /* 35794 8009DF94 05004010 */  beqz       $v0, .L8009DFAC
    /* 35798 8009DF98 02000224 */   addiu     $v0, $zero, 0x2
    /* 3579C 8009DF9C 09006012 */  beqz       $s3, .L8009DFC4
    /* 357A0 8009DFA0 21208002 */   addu      $a0, $s4, $zero
    /* 357A4 8009DFA4 0A780208 */  j          .L8009E028
    /* 357A8 8009DFA8 21280002 */   addu      $a1, $s0, $zero
  .L8009DFAC:
    /* 357AC 8009DFAC 09006212 */  beq        $s3, $v0, .L8009DFD4
    /* 357B0 8009DFB0 03000224 */   addiu     $v0, $zero, 0x3
    /* 357B4 8009DFB4 09006212 */  beq        $s3, $v0, .L8009DFDC
    /* 357B8 8009DFB8 21208002 */   addu      $a0, $s4, $zero
    /* 357BC 8009DFBC 0A780208 */  j          .L8009E028
    /* 357C0 8009DFC0 21280002 */   addu      $a1, $s0, $zero
  .L8009DFC4:
    /* 357C4 8009DFC4 08780208 */  j          .L8009E020
    /* 357C8 8009DFC8 06001024 */   addiu     $s0, $zero, 0x6
  .L8009DFCC:
    /* 357CC 8009DFCC 08780208 */  j          .L8009E020
    /* 357D0 8009DFD0 C6001024 */   addiu     $s0, $zero, 0xC6
  .L8009DFD4:
    /* 357D4 8009DFD4 08780208 */  j          .L8009E020
    /* 357D8 8009DFD8 C8001024 */   addiu     $s0, $zero, 0xC8
  .L8009DFDC:
    /* 357DC 8009DFDC B8055092 */  lbu        $s0, 0x5B8($s2)
    /* 357E0 8009DFE0 C6000224 */  addiu      $v0, $zero, 0xC6
    /* 357E4 8009DFE4 03000212 */  beq        $s0, $v0, .L8009DFF4
    /* 357E8 8009DFE8 C8000224 */   addiu     $v0, $zero, 0xC8
    /* 357EC 8009DFEC 17000216 */  bne        $s0, $v0, .L8009E04C
    /* 357F0 8009DFF0 00000000 */   nop
  .L8009DFF4:
    /* 357F4 8009DFF4 01001026 */  addiu      $s0, $s0, 0x1
    /* 357F8 8009DFF8 21204002 */  addu       $a0, $s2, $zero
    /* 357FC 8009DFFC 21280002 */  addu       $a1, $s0, $zero
    /* 35800 8009E000 25B5020C */  jal        func_800AD494
    /* 35804 8009E004 1000A627 */   addiu     $a2, $sp, 0x10
    /* 35808 8009E008 1000A28F */  lw         $v0, 0x10($sp)
    /* 3580C 8009E00C 00000000 */  nop
    /* 35810 8009E010 03004014 */  bnez       $v0, .L8009E020
    /* 35814 8009E014 08001124 */   addiu     $s1, $zero, 0x8
    /* 35818 8009E018 06001024 */  addiu      $s0, $zero, 0x6
    /* 3581C 8009E01C 10001124 */  addiu      $s1, $zero, 0x10
  .L8009E020:
    /* 35820 8009E020 21208002 */  addu       $a0, $s4, $zero
    /* 35824 8009E024 21280002 */  addu       $a1, $s0, $zero
  .L8009E028:
    /* 35828 8009E028 21300000 */  addu       $a2, $zero, $zero
    /* 3582C 8009E02C 8180020C */  jal        func_800A0204
    /* 35830 8009E030 21382002 */   addu      $a3, $s1, $zero
    /* 35834 8009E034 0300622A */  slti       $v0, $s3, 0x3
    /* 35838 8009E038 04004010 */  beqz       $v0, .L8009E04C
    /* 3583C 8009E03C 04074426 */   addiu     $a0, $s2, 0x704
    /* 35840 8009E040 540C4526 */  addiu      $a1, $s2, 0xC54
    /* 35844 8009E044 2C24010C */  jal        vs_main_memcpy
    /* 35848 8009E048 50050624 */   addiu     $a2, $zero, 0x550
  .L8009E04C:
    /* 3584C 8009E04C 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 35850 8009E050 2800B48F */  lw         $s4, 0x28($sp)
    /* 35854 8009E054 2400B38F */  lw         $s3, 0x24($sp)
    /* 35858 8009E058 2000B28F */  lw         $s2, 0x20($sp)
    /* 3585C 8009E05C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 35860 8009E060 1800B08F */  lw         $s0, 0x18($sp)
    /* 35864 8009E064 3000BD27 */  addiu      $sp, $sp, 0x30
    /* 35868 8009E068 0800E003 */  jr         $ra
    /* 3586C 8009E06C 00000000 */   nop
endlabel func_8009DF3C
