nonmatching func_800AA108, 0x110

glabel func_800AA108
    /* 41908 800AA108 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4190C 800AA10C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 41910 800AA110 21888000 */  addu       $s1, $a0, $zero
    /* 41914 800AA114 1800B2AF */  sw         $s2, 0x18($sp)
    /* 41918 800AA118 2190A000 */  addu       $s2, $a1, $zero
    /* 4191C 800AA11C 0F80033C */  lui        $v1, %hi(D_800F4538)
    /* 41920 800AA120 38456324 */  addiu      $v1, $v1, %lo(D_800F4538)
    /* 41924 800AA124 80101100 */  sll        $v0, $s1, 2
    /* 41928 800AA128 21104300 */  addu       $v0, $v0, $v1
    /* 4192C 800AA12C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 41930 800AA130 1000B0AF */  sw         $s0, 0x10($sp)
    /* 41934 800AA134 0000508C */  lw         $s0, 0x0($v0)
    /* 41938 800AA138 00000000 */  nop
    /* 4193C 800AA13C 2F000012 */  beqz       $s0, .L800AA1FC
    /* 41940 800AA140 2140E000 */   addu      $t0, $a3, $zero
    /* 41944 800AA144 1800C014 */  bnez       $a2, .L800AA1A8
    /* 41948 800AA148 C40506A6 */   sh        $a2, 0x5C4($s0)
    /* 4194C 800AA14C 16000015 */  bnez       $t0, .L800AA1A8
    /* 41950 800AA150 FFFF0624 */   addiu     $a2, $zero, -0x1
    /* 41954 800AA154 A4A8020C */  jal        func_800AA290
    /* 41958 800AA158 21380000 */   addu      $a3, $zero, $zero
    /* 4195C 800AA15C 03004592 */  lbu        $a1, 0x3($s2)
    /* 41960 800AA160 00000000 */  nop
    /* 41964 800AA164 00290500 */  sll        $a1, $a1, 4
    /* 41968 800AA168 0200A104 */  bgez       $a1, .L800AA174
    /* 4196C 800AA16C 2110A000 */   addu      $v0, $a1, $zero
    /* 41970 800AA170 FF0FA224 */  addiu      $v0, $a1, 0xFFF
  .L800AA174:
    /* 41974 800AA174 00104230 */  andi       $v0, $v0, 0x1000
    /* 41978 800AA178 2328A200 */  subu       $a1, $a1, $v0
    /* 4197C 800AA17C 21202002 */  addu       $a0, $s1, $zero
    /* 41980 800AA180 26000286 */  lh         $v0, 0x26($s0)
    /* 41984 800AA184 21300000 */  addu       $a2, $zero, $zero
    /* 41988 800AA188 2328A200 */  subu       $a1, $a1, $v0
    /* 4198C 800AA18C 002C0500 */  sll        $a1, $a1, 16
    /* 41990 800AA190 61AA020C */  jal        func_800AA984
    /* 41994 800AA194 032C0500 */   sra       $a1, $a1, 16
    /* 41998 800AA198 AC05028E */  lw         $v0, 0x5AC($s0)
    /* 4199C 800AA19C FCFF0324 */  addiu      $v1, $zero, -0x4
    /* 419A0 800AA1A0 73A80208 */  j          .L800AA1CC
    /* 419A4 800AA1A4 24104300 */   and       $v0, $v0, $v1
  .L800AA1A8:
    /* 419A8 800AA1A8 21202002 */  addu       $a0, $s1, $zero
    /* 419AC 800AA1AC 21284002 */  addu       $a1, $s2, $zero
    /* 419B0 800AA1B0 C0050796 */  lhu        $a3, 0x5C0($s0)
    /* 419B4 800AA1B4 24A9020C */  jal        func_800AA490
    /* 419B8 800AA1B8 21300001 */   addu      $a2, $t0, $zero
    /* 419BC 800AA1BC AC05028E */  lw         $v0, 0x5AC($s0)
    /* 419C0 800AA1C0 FCFF0324 */  addiu      $v1, $zero, -0x4
    /* 419C4 800AA1C4 24104300 */  and        $v0, $v0, $v1
    /* 419C8 800AA1C8 01004234 */  ori        $v0, $v0, 0x1
  .L800AA1CC:
    /* 419CC 800AA1CC AC0502AE */  sw         $v0, 0x5AC($s0)
    /* 419D0 800AA1D0 00004292 */  lbu        $v0, 0x0($s2)
    /* 419D4 800AA1D4 00000000 */  nop
    /* 419D8 800AA1D8 5C0002A2 */  sb         $v0, 0x5C($s0)
    /* 419DC 800AA1DC 01004292 */  lbu        $v0, 0x1($s2)
    /* 419E0 800AA1E0 00000000 */  nop
    /* 419E4 800AA1E4 5D0002A2 */  sb         $v0, 0x5D($s0)
    /* 419E8 800AA1E8 AC05028E */  lw         $v0, 0x5AC($s0)
    /* 419EC 800AA1EC 02004392 */  lbu        $v1, 0x2($s2)
    /* 419F0 800AA1F0 04004234 */  ori        $v0, $v0, 0x4
    /* 419F4 800AA1F4 AC0502AE */  sw         $v0, 0x5AC($s0)
    /* 419F8 800AA1F8 5E0003A2 */  sb         $v1, 0x5E($s0)
  .L800AA1FC:
    /* 419FC 800AA1FC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 41A00 800AA200 1800B28F */  lw         $s2, 0x18($sp)
    /* 41A04 800AA204 1400B18F */  lw         $s1, 0x14($sp)
    /* 41A08 800AA208 1000B08F */  lw         $s0, 0x10($sp)
    /* 41A0C 800AA20C 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 41A10 800AA210 0800E003 */  jr         $ra
    /* 41A14 800AA214 00000000 */   nop
endlabel func_800AA108
