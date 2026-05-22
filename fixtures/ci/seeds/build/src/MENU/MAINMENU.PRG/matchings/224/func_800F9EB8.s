nonmatching func_800F9EB8, 0x2D0

glabel func_800F9EB8
    /* 6B8 800F9EB8 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 6BC 800F9EBC 0F80023C */  lui        $v0, %hi(D_800F453C)
    /* 6C0 800F9EC0 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 6C4 800F9EC4 3C45518C */  lw         $s1, %lo(D_800F453C)($v0)
    /* 6C8 800F9EC8 2000B2AF */  sw         $s2, 0x20($sp)
    /* 6CC 800F9ECC 21908000 */  addu       $s2, $a0, $zero
    /* 6D0 800F9ED0 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 6D4 800F9ED4 2800B4AF */  sw         $s4, 0x28($sp)
    /* 6D8 800F9ED8 2400B3AF */  sw         $s3, 0x24($sp)
    /* 6DC 800F9EDC 1800B0AF */  sw         $s0, 0x18($sp)
    /* 6E0 800F9EE0 A0002012 */  beqz       $s1, .L800FA164
    /* 6E4 800F9EE4 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 6E8 800F9EE8 00002292 */  lbu        $v0, 0x0($s1)
    /* 6EC 800F9EEC 00000000 */  nop
    /* 6F0 800F9EF0 9C004010 */  beqz       $v0, .L800FA164
    /* 6F4 800F9EF4 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 6F8 800F9EF8 0800228E */  lw         $v0, 0x8($s1)
    /* 6FC 800F9EFC 00000000 */  nop
    /* 700 800F9F00 01004230 */  andi       $v0, $v0, 0x1
    /* 704 800F9F04 97004014 */  bnez       $v0, .L800FA164
    /* 708 800F9F08 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 70C 800F9F0C 28BB020C */  jal        func_800AECA0
    /* 710 800F9F10 21204002 */   addu      $a0, $s2, $zero
    /* 714 800F9F14 0680023C */  lui        $v0, %hi(vs_gametime_tickspeed)
    /* 718 800F9F18 4CE2428C */  lw         $v0, %lo(vs_gametime_tickspeed)($v0)
    /* 71C 800F9F1C 00000000 */  nop
    /* 720 800F9F20 C21F0200 */  srl        $v1, $v0, 31
    /* 724 800F9F24 21104300 */  addu       $v0, $v0, $v1
    /* 728 800F9F28 0800238E */  lw         $v1, 0x8($s1)
    /* 72C 800F9F2C 43100200 */  sra        $v0, $v0, 1
    /* 730 800F9F30 04006330 */  andi       $v1, $v1, 0x4
    /* 734 800F9F34 07006010 */  beqz       $v1, .L800F9F54
    /* 738 800F9F38 B20522A2 */   sb        $v0, 0x5B2($s1)
    /* 73C 800F9F3C 3CAD020C */  jal        func_800AB4F0
    /* 740 800F9F40 21202002 */   addu      $a0, $s1, $zero
    /* 744 800F9F44 BABD020C */  jal        func_800AF6E8
    /* 748 800F9F48 21202002 */   addu      $a0, $s1, $zero
    /* 74C 800F9F4C D8E70308 */  j          .L800F9F60
    /* 750 800F9F50 21202002 */   addu      $a0, $s1, $zero
  .L800F9F54:
    /* 754 800F9F54 BABA020C */  jal        func_800AEAE8
    /* 758 800F9F58 21202002 */   addu      $a0, $s1, $zero
    /* 75C 800F9F5C 21202002 */  addu       $a0, $s1, $zero
  .L800F9F60:
    /* 760 800F9F60 21284002 */  addu       $a1, $s2, $zero
    /* 764 800F9F64 2ACA020C */  jal        func_800B28A8
    /* 768 800F9F68 21300000 */   addu      $a2, $zero, $zero
    /* 76C 800F9F6C FD172292 */  lbu        $v0, 0x17FD($s1)
    /* 770 800F9F70 00000000 */  nop
    /* 774 800F9F74 0200422C */  sltiu      $v0, $v0, 0x2
    /* 778 800F9F78 04004014 */  bnez       $v0, .L800F9F8C
    /* 77C 800F9F7C 0F80023C */   lui       $v0, %hi(D_800F4578)
    /* 780 800F9F80 7845448C */  lw         $a0, %lo(D_800F4578)($v0)
    /* 784 800F9F84 3CAD020C */  jal        func_800AB4F0
    /* 788 800F9F88 00000000 */   nop
  .L800F9F8C:
    /* 78C 800F9F8C FD172292 */  lbu        $v0, 0x17FD($s1)
    /* 790 800F9F90 00000000 */  nop
    /* 794 800F9F94 38004010 */  beqz       $v0, .L800FA078
    /* 798 800F9F98 21202002 */   addu      $a0, $s1, $zero
    /* 79C 800F9F9C 801F103C */  lui        $s0, (0x1F800004 >> 16)
    /* 7A0 800F9FA0 F7062392 */  lbu        $v1, 0x6F7($s1)
    /* 7A4 800F9FA4 0400028E */  lw         $v0, (0x1F800004 & 0xFFFF)($s0)
    /* 7A8 800F9FA8 80180300 */  sll        $v1, $v1, 2
    /* 7AC 800F9FAC C0006324 */  addiu      $v1, $v1, 0xC0
    /* 7B0 800F9FB0 21104300 */  addu       $v0, $v0, $v1
    /* 7B4 800F9FB4 040002AE */  sw         $v0, (0x1F800004 & 0xFFFF)($s0)
    /* 7B8 800F9FB8 F4062392 */  lbu        $v1, 0x6F4($s1)
    /* 7BC 800F9FBC FD172592 */  lbu        $a1, 0x17FD($s1)
    /* 7C0 800F9FC0 F5062792 */  lbu        $a3, 0x6F5($s1)
    /* 7C4 800F9FC4 F6062692 */  lbu        $a2, 0x6F6($s1)
    /* 7C8 800F9FC8 1C002296 */  lhu        $v0, 0x1C($s1)
    /* 7CC 800F9FCC 001E0300 */  sll        $v1, $v1, 24
    /* 7D0 800F9FD0 031E0300 */  sra        $v1, $v1, 24
    /* 7D4 800F9FD4 003E0700 */  sll        $a3, $a3, 24
    /* 7D8 800F9FD8 033E0700 */  sra        $a3, $a3, 24
    /* 7DC 800F9FDC 00360600 */  sll        $a2, $a2, 24
    /* 7E0 800F9FE0 03360600 */  sra        $a2, $a2, 24
    /* 7E4 800F9FE4 21104300 */  addu       $v0, $v0, $v1
    /* 7E8 800F9FE8 1C0022A6 */  sh         $v0, 0x1C($s1)
    /* 7EC 800F9FEC 1E002296 */  lhu        $v0, 0x1E($s1)
    /* 7F0 800F9FF0 20002396 */  lhu        $v1, 0x20($s1)
    /* 7F4 800F9FF4 21104700 */  addu       $v0, $v0, $a3
    /* 7F8 800F9FF8 21186600 */  addu       $v1, $v1, $a2
    /* 7FC 800F9FFC 1E0022A6 */  sh         $v0, 0x1E($s1)
    /* 800 800FA000 0BC0020C */  jal        func_800B002C
    /* 804 800FA004 200023A6 */   sh        $v1, 0x20($s1)
    /* 808 800FA008 21202002 */  addu       $a0, $s1, $zero
    /* 80C 800FA00C FD172692 */  lbu        $a2, 0x17FD($s1)
    /* 810 800FA010 2ACA020C */  jal        func_800B28A8
    /* 814 800FA014 21284002 */   addu      $a1, $s2, $zero
    /* 818 800FA018 F7062292 */  lbu        $v0, 0x6F7($s1)
    /* 81C 800FA01C 0400038E */  lw         $v1, (0x1F800004 & 0xFFFF)($s0)
    /* 820 800FA020 80100200 */  sll        $v0, $v0, 2
    /* 824 800FA024 C0004224 */  addiu      $v0, $v0, 0xC0
    /* 828 800FA028 23186200 */  subu       $v1, $v1, $v0
    /* 82C 800FA02C 040003AE */  sw         $v1, (0x1F800004 & 0xFFFF)($s0)
    /* 830 800FA030 F4062392 */  lbu        $v1, 0x6F4($s1)
    /* 834 800FA034 F5062592 */  lbu        $a1, 0x6F5($s1)
    /* 838 800FA038 F6062492 */  lbu        $a0, 0x6F6($s1)
    /* 83C 800FA03C 1C002296 */  lhu        $v0, 0x1C($s1)
    /* 840 800FA040 001E0300 */  sll        $v1, $v1, 24
    /* 844 800FA044 031E0300 */  sra        $v1, $v1, 24
    /* 848 800FA048 002E0500 */  sll        $a1, $a1, 24
    /* 84C 800FA04C 032E0500 */  sra        $a1, $a1, 24
    /* 850 800FA050 00260400 */  sll        $a0, $a0, 24
    /* 854 800FA054 03260400 */  sra        $a0, $a0, 24
    /* 858 800FA058 23104300 */  subu       $v0, $v0, $v1
    /* 85C 800FA05C 1C0022A6 */  sh         $v0, 0x1C($s1)
    /* 860 800FA060 1E002296 */  lhu        $v0, 0x1E($s1)
    /* 864 800FA064 20002396 */  lhu        $v1, 0x20($s1)
    /* 868 800FA068 23104500 */  subu       $v0, $v0, $a1
    /* 86C 800FA06C 23186400 */  subu       $v1, $v1, $a0
    /* 870 800FA070 1E0022A6 */  sh         $v0, 0x1E($s1)
    /* 874 800FA074 200023A6 */  sh         $v1, 0x20($s1)
  .L800FA078:
    /* 878 800FA078 0800228E */  lw         $v0, 0x8($s1)
    /* 87C 800FA07C 00000000 */  nop
    /* 880 800FA080 00104230 */  andi       $v0, $v0, 0x1000
    /* 884 800FA084 37004014 */  bnez       $v0, .L800FA164
    /* 888 800FA088 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 88C 800FA08C 21980000 */  addu       $s3, $zero, $zero
    /* 890 800FA090 0F80023C */  lui        $v0, %hi(D_800F4588)
    /* 894 800FA094 88455424 */  addiu      $s4, $v0, %lo(D_800F4588)
    /* 898 800FA098 08001224 */  addiu      $s2, $zero, 0x8
  .L800FA09C:
    /* 89C 800FA09C 21105402 */  addu       $v0, $s2, $s4
    /* 8A0 800FA0A0 0000448C */  lw         $a0, 0x0($v0)
    /* 8A4 800FA0A4 00000000 */  nop
    /* 8A8 800FA0A8 29008010 */  beqz       $a0, .L800FA150
    /* 8AC 800FA0AC 00000000 */   nop
    /* 8B0 800FA0B0 0800828C */  lw         $v0, 0x8($a0)
    /* 8B4 800FA0B4 00000000 */  nop
    /* 8B8 800FA0B8 10004230 */  andi       $v0, $v0, 0x10
    /* 8BC 800FA0BC 24004010 */  beqz       $v0, .L800FA150
    /* 8C0 800FA0C0 00000000 */   nop
    /* 8C4 800FA0C4 0D009090 */  lbu        $s0, 0xD($a0)
    /* 8C8 800FA0C8 F4062382 */  lb         $v1, 0x6F4($s1)
    /* 8CC 800FA0CC 40811000 */  sll        $s0, $s0, 5
    /* 8D0 800FA0D0 6C001026 */  addiu      $s0, $s0, 0x6C
    /* 8D4 800FA0D4 21803002 */  addu       $s0, $s1, $s0
    /* 8D8 800FA0D8 1400028E */  lw         $v0, 0x14($s0)
    /* 8DC 800FA0DC 00000000 */  nop
    /* 8E0 800FA0E0 23104300 */  subu       $v0, $v0, $v1
    /* 8E4 800FA0E4 140002AE */  sw         $v0, 0x14($s0)
    /* 8E8 800FA0E8 F5062382 */  lb         $v1, 0x6F5($s1)
    /* 8EC 800FA0EC 1800028E */  lw         $v0, 0x18($s0)
    /* 8F0 800FA0F0 00000000 */  nop
    /* 8F4 800FA0F4 23104300 */  subu       $v0, $v0, $v1
    /* 8F8 800FA0F8 180002AE */  sw         $v0, 0x18($s0)
    /* 8FC 800FA0FC F6062382 */  lb         $v1, 0x6F6($s1)
    /* 900 800FA100 1C00028E */  lw         $v0, 0x1C($s0)
    /* 904 800FA104 21280002 */  addu       $a1, $s0, $zero
    /* 908 800FA108 23104300 */  subu       $v0, $v0, $v1
    /* 90C 800FA10C 5FC8020C */  jal        func_800B217C
    /* 910 800FA110 1C0002AE */   sw        $v0, 0x1C($s0)
    /* 914 800FA114 F4062382 */  lb         $v1, 0x6F4($s1)
    /* 918 800FA118 1400028E */  lw         $v0, 0x14($s0)
    /* 91C 800FA11C 00000000 */  nop
    /* 920 800FA120 21104300 */  addu       $v0, $v0, $v1
    /* 924 800FA124 140002AE */  sw         $v0, 0x14($s0)
    /* 928 800FA128 F5062382 */  lb         $v1, 0x6F5($s1)
    /* 92C 800FA12C 1800028E */  lw         $v0, 0x18($s0)
    /* 930 800FA130 00000000 */  nop
    /* 934 800FA134 21104300 */  addu       $v0, $v0, $v1
    /* 938 800FA138 180002AE */  sw         $v0, 0x18($s0)
    /* 93C 800FA13C F6062382 */  lb         $v1, 0x6F6($s1)
    /* 940 800FA140 1C00028E */  lw         $v0, 0x1C($s0)
    /* 944 800FA144 00000000 */  nop
    /* 948 800FA148 21104300 */  addu       $v0, $v0, $v1
    /* 94C 800FA14C 1C0002AE */  sw         $v0, 0x1C($s0)
  .L800FA150:
    /* 950 800FA150 01007326 */  addiu      $s3, $s3, 0x1
    /* 954 800FA154 0200622A */  slti       $v0, $s3, 0x2
    /* 958 800FA158 D0FF4014 */  bnez       $v0, .L800FA09C
    /* 95C 800FA15C 04005226 */   addiu     $s2, $s2, 0x4
    /* 960 800FA160 21100000 */  addu       $v0, $zero, $zero
  .L800FA164:
    /* 964 800FA164 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 968 800FA168 2800B48F */  lw         $s4, 0x28($sp)
    /* 96C 800FA16C 2400B38F */  lw         $s3, 0x24($sp)
    /* 970 800FA170 2000B28F */  lw         $s2, 0x20($sp)
    /* 974 800FA174 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 978 800FA178 1800B08F */  lw         $s0, 0x18($sp)
    /* 97C 800FA17C 3000BD27 */  addiu      $sp, $sp, 0x30
    /* 980 800FA180 0800E003 */  jr         $ra
    /* 984 800FA184 00000000 */   nop
endlabel func_800F9EB8
