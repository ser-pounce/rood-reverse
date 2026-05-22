nonmatching func_800C7EBC, 0x1E0

glabel func_800C7EBC
    /* 5F6BC 800C7EBC 88FFBD27 */  addiu      $sp, $sp, -0x78
    /* 5F6C0 800C7EC0 6C00B3AF */  sw         $s3, 0x6C($sp)
    /* 5F6C4 800C7EC4 21988000 */  addu       $s3, $a0, $zero
    /* 5F6C8 800C7EC8 1886033C */  lui        $v1, (0x86186187 >> 16)
    /* 5F6CC 800C7ECC 87616334 */  ori        $v1, $v1, (0x86186187 & 0xFFFF)
    /* 5F6D0 800C7ED0 1900A300 */  multu      $a1, $v1
    /* 5F6D4 800C7ED4 7000B4AF */  sw         $s4, 0x70($sp)
    /* 5F6D8 800C7ED8 21A0C000 */  addu       $s4, $a2, $zero
    /* 5F6DC 800C7EDC 6800B2AF */  sw         $s2, 0x68($sp)
    /* 5F6E0 800C7EE0 2190E000 */  addu       $s2, $a3, $zero
    /* 5F6E4 800C7EE4 1000A427 */  addiu      $a0, $sp, 0x10
    /* 5F6E8 800C7EE8 03000224 */  addiu      $v0, $zero, 0x3
    /* 5F6EC 800C7EEC 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 5F6F0 800C7EF0 0C000224 */  addiu      $v0, $zero, 0xC
    /* 5F6F4 800C7EF4 7400BFAF */  sw         $ra, 0x74($sp)
    /* 5F6F8 800C7EF8 6400B1AF */  sw         $s1, 0x64($sp)
    /* 5F6FC 800C7EFC 6000B0AF */  sw         $s0, 0x60($sp)
    /* 5F700 800C7F00 1600A2A7 */  sh         $v0, 0x16($sp)
    /* 5F704 800C7F04 10180000 */  mfhi       $v1
    /* 5F708 800C7F08 2310A300 */  subu       $v0, $a1, $v1
    /* 5F70C 800C7F0C 42100200 */  srl        $v0, $v0, 1
    /* 5F710 800C7F10 21186200 */  addu       $v1, $v1, $v0
    /* 5F714 800C7F14 02190300 */  srl        $v1, $v1, 4
    /* 5F718 800C7F18 80100300 */  sll        $v0, $v1, 2
    /* 5F71C 800C7F1C 21104300 */  addu       $v0, $v0, $v1
    /* 5F720 800C7F20 80100200 */  sll        $v0, $v0, 2
    /* 5F724 800C7F24 21104300 */  addu       $v0, $v0, $v1
    /* 5F728 800C7F28 2328A200 */  subu       $a1, $a1, $v0
    /* 5F72C 800C7F2C 40100500 */  sll        $v0, $a1, 1
    /* 5F730 800C7F30 21104500 */  addu       $v0, $v0, $a1
    /* 5F734 800C7F34 40034224 */  addiu      $v0, $v0, 0x340
    /* 5F738 800C7F38 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 5F73C 800C7F3C 40100300 */  sll        $v0, $v1, 1
    /* 5F740 800C7F40 21104300 */  addu       $v0, $v0, $v1
    /* 5F744 800C7F44 80100200 */  sll        $v0, $v0, 2
    /* 5F748 800C7F48 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 5F74C 800C7F4C 0100023C */  lui        $v0, (0x10000 >> 16)
    /* 5F750 800C7F50 23805200 */  subu       $s0, $v0, $s2
    /* 5F754 800C7F54 57A2000C */  jal        StoreImage
    /* 5F758 800C7F58 1800A527 */   addiu     $a1, $sp, 0x18
    /* 5F75C 800C7F5C 94A1000C */  jal        DrawSync
    /* 5F760 800C7F60 21200000 */   addu      $a0, $zero, $zero
    /* 5F764 800C7F64 21600000 */  addu       $t4, $zero, $zero
    /* 5F768 800C7F68 0F80023C */  lui        $v0, %hi(D_800EB98C)
    /* 5F76C 800C7F6C 8CB94D24 */  addiu      $t5, $v0, %lo(D_800EB98C)
    /* 5F770 800C7F70 21588001 */  addu       $t3, $t4, $zero
  .L800C7F74:
    /* 5F774 800C7F74 21280000 */  addu       $a1, $zero, $zero
    /* 5F778 800C7F78 21486002 */  addu       $t1, $s3, $zero
  .L800C7F7C:
    /* 5F77C 800C7F7C 0300A230 */  andi       $v0, $a1, 0x3
    /* 5F780 800C7F80 03004010 */  beqz       $v0, .L800C7F90
    /* 5F784 800C7F84 FFFF2232 */   andi      $v0, $s1, 0xFFFF
    /* 5F788 800C7F88 E91F0308 */  j          .L800C7FA4
    /* 5F78C 800C7F8C 02890200 */   srl       $s1, $v0, 4
  .L800C7F90:
    /* 5F790 800C7F90 83100500 */  sra        $v0, $a1, 2
    /* 5F794 800C7F94 21104B00 */  addu       $v0, $v0, $t3
    /* 5F798 800C7F98 40100200 */  sll        $v0, $v0, 1
    /* 5F79C 800C7F9C 2110A203 */  addu       $v0, $sp, $v0
    /* 5F7A0 800C7FA0 18005194 */  lhu        $s1, 0x18($v0)
  .L800C7FA4:
    /* 5F7A4 800C7FA4 00000000 */  nop
    /* 5F7A8 800C7FA8 0F002232 */  andi       $v0, $s1, 0xF
    /* 5F7AC 800C7FAC 29004010 */  beqz       $v0, .L800C8054
    /* 5F7B0 800C7FB0 21204000 */   addu      $a0, $v0, $zero
    /* 5F7B4 800C7FB4 00002395 */  lhu        $v1, 0x0($t1)
    /* 5F7B8 800C7FB8 00000000 */  nop
    /* 5F7BC 800C7FBC 1F006230 */  andi       $v0, $v1, 0x1F
    /* 5F7C0 800C7FC0 18005000 */  mult       $v0, $s0
    /* 5F7C4 800C7FC4 40100400 */  sll        $v0, $a0, 1
    /* 5F7C8 800C7FC8 21104D00 */  addu       $v0, $v0, $t5
    /* 5F7CC 800C7FCC 00004494 */  lhu        $a0, 0x0($v0)
    /* 5F7D0 800C7FD0 12500000 */  mflo       $t2
    /* 5F7D4 800C7FD4 1F008230 */  andi       $v0, $a0, 0x1F
    /* 5F7D8 800C7FD8 00000000 */  nop
    /* 5F7DC 800C7FDC 18005200 */  mult       $v0, $s2
    /* 5F7E0 800C7FE0 12300000 */  mflo       $a2
    /* 5F7E4 800C7FE4 E0036230 */  andi       $v0, $v1, 0x3E0
    /* 5F7E8 800C7FE8 00000000 */  nop
    /* 5F7EC 800C7FEC 18005000 */  mult       $v0, $s0
    /* 5F7F0 800C7FF0 12380000 */  mflo       $a3
    /* 5F7F4 800C7FF4 E0038230 */  andi       $v0, $a0, 0x3E0
    /* 5F7F8 800C7FF8 00000000 */  nop
    /* 5F7FC 800C7FFC 18005200 */  mult       $v0, $s2
    /* 5F800 800C8000 12780000 */  mflo       $t7
    /* 5F804 800C8004 007C6330 */  andi       $v1, $v1, 0x7C00
    /* 5F808 800C8008 00000000 */  nop
    /* 5F80C 800C800C 18007000 */  mult       $v1, $s0
    /* 5F810 800C8010 12400000 */  mflo       $t0
    /* 5F814 800C8014 007C8230 */  andi       $v0, $a0, 0x7C00
    /* 5F818 800C8018 00000000 */  nop
    /* 5F81C 800C801C 18005200 */  mult       $v0, $s2
    /* 5F820 800C8020 21184601 */  addu       $v1, $t2, $a2
    /* 5F824 800C8024 021C0300 */  srl        $v1, $v1, 16
    /* 5F828 800C8028 1F006330 */  andi       $v1, $v1, 0x1F
    /* 5F82C 800C802C 2110EF00 */  addu       $v0, $a3, $t7
    /* 5F830 800C8030 02140200 */  srl        $v0, $v0, 16
    /* 5F834 800C8034 E0034230 */  andi       $v0, $v0, 0x3E0
    /* 5F838 800C8038 25186200 */  or         $v1, $v1, $v0
    /* 5F83C 800C803C 12200000 */  mflo       $a0
    /* 5F840 800C8040 21100401 */  addu       $v0, $t0, $a0
    /* 5F844 800C8044 02140200 */  srl        $v0, $v0, 16
    /* 5F848 800C8048 007C4230 */  andi       $v0, $v0, 0x7C00
    /* 5F84C 800C804C 25186200 */  or         $v1, $v1, $v0
    /* 5F850 800C8050 000023A5 */  sh         $v1, 0x0($t1)
  .L800C8054:
    /* 5F854 800C8054 0100A524 */  addiu      $a1, $a1, 0x1
    /* 5F858 800C8058 0C00A228 */  slti       $v0, $a1, 0xC
    /* 5F85C 800C805C C7FF4014 */  bnez       $v0, .L800C7F7C
    /* 5F860 800C8060 02002925 */   addiu     $t1, $t1, 0x2
    /* 5F864 800C8064 01008C25 */  addiu      $t4, $t4, 0x1
    /* 5F868 800C8068 40101400 */  sll        $v0, $s4, 1
    /* 5F86C 800C806C 21986202 */  addu       $s3, $s3, $v0
    /* 5F870 800C8070 0C008229 */  slti       $v0, $t4, 0xC
    /* 5F874 800C8074 BFFF4014 */  bnez       $v0, .L800C7F74
    /* 5F878 800C8078 03006B25 */   addiu     $t3, $t3, 0x3
    /* 5F87C 800C807C 7400BF8F */  lw         $ra, 0x74($sp)
    /* 5F880 800C8080 7000B48F */  lw         $s4, 0x70($sp)
    /* 5F884 800C8084 6C00B38F */  lw         $s3, 0x6C($sp)
    /* 5F888 800C8088 6800B28F */  lw         $s2, 0x68($sp)
    /* 5F88C 800C808C 6400B18F */  lw         $s1, 0x64($sp)
    /* 5F890 800C8090 6000B08F */  lw         $s0, 0x60($sp)
    /* 5F894 800C8094 0800E003 */  jr         $ra
    /* 5F898 800C8098 7800BD27 */   addiu     $sp, $sp, 0x78
endlabel func_800C7EBC
