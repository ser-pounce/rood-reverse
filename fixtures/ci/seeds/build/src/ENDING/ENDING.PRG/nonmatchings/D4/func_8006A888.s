nonmatching func_8006A888, 0xD0

glabel func_8006A888
    /* 2088 8006A888 0E80023C */  lui        $v0, %hi(D_800DC188)
    /* 208C 8006A88C 88C14290 */  lbu        $v0, %lo(D_800DC188)($v0)
    /* 2090 8006A890 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2094 8006A894 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 2098 8006A898 1800B2AF */  sw         $s2, 0x18($sp)
    /* 209C 8006A89C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 20A0 8006A8A0 27004014 */  bnez       $v0, .L8006A940
    /* 20A4 8006A8A4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 20A8 8006A8A8 0E80123C */  lui        $s2, %hi(D_800DC19A)
    /* 20AC 8006A8AC 0E80113C */  lui        $s1, %hi(D_800DC18A)
    /* 20B0 8006A8B0 0E80103C */  lui        $s0, %hi(D_800DC18C)
  .L8006A8B4:
    /* 20B4 8006A8B4 B17D000C */  jal        VSync
    /* 20B8 8006A8B8 01000424 */   addiu     $a0, $zero, 0x1
    /* 20BC 8006A8BC 4CAE010C */  jal        func_8006B930
    /* 20C0 8006A8C0 9AC142A6 */   sh        $v0, %lo(D_800DC19A)($s2)
    /* 20C4 8006A8C4 FCAA010C */  jal        func_8006ABF0
    /* 20C8 8006A8C8 00000000 */   nop
    /* 20CC 8006A8CC A8AA010C */  jal        func_8006AAA0
    /* 20D0 8006A8D0 00000000 */   nop
    /* 20D4 8006A8D4 D9AB010C */  jal        func_8006AF64
    /* 20D8 8006A8D8 00000000 */   nop
    /* 20DC 8006A8DC 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 20E0 8006A8E0 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 20E4 8006A8E4 00000000 */  nop
    /* 20E8 8006A8E8 00084230 */  andi       $v0, $v0, 0x800
    /* 20EC 8006A8EC 0A004010 */  beqz       $v0, .L8006A918
    /* 20F0 8006A8F0 00000000 */   nop
    /* 20F4 8006A8F4 8AC12292 */  lbu        $v0, %lo(D_800DC18A)($s1)
    /* 20F8 8006A8F8 00000000 */  nop
    /* 20FC 8006A8FC 06004014 */  bnez       $v0, .L8006A918
    /* 2100 8006A900 00000000 */   nop
    /* 2104 8006A904 0780043C */  lui        $a0, %hi(func_8006A4D8)
    /* 2108 8006A908 D1AA010C */  jal        func_8006AB44
    /* 210C 8006A90C D8A48424 */   addiu     $a0, $a0, %lo(func_8006A4D8)
    /* 2110 8006A910 01000224 */  addiu      $v0, $zero, 0x1
    /* 2114 8006A914 8AC122A2 */  sb         $v0, %lo(D_800DC18A)($s1)
  .L8006A918:
    /* 2118 8006A918 801F043C */  lui        $a0, (0x1F800004 >> 16)
    /* 211C 8006A91C 0400848C */  lw         $a0, (0x1F800004 & 0xFFFF)($a0)
    /* 2120 8006A920 A9AD010C */  jal        func_8006B6A4
    /* 2124 8006A924 FC1F8424 */   addiu     $a0, $a0, 0x1FFC
    /* 2128 8006A928 0E80033C */  lui        $v1, %hi(D_800DC188)
    /* 212C 8006A92C 8CC1028E */  lw         $v0, %lo(D_800DC18C)($s0)
    /* 2130 8006A930 88C16390 */  lbu        $v1, %lo(D_800DC188)($v1)
    /* 2134 8006A934 01004224 */  addiu      $v0, $v0, 0x1
    /* 2138 8006A938 DEFF6010 */  beqz       $v1, .L8006A8B4
    /* 213C 8006A93C 8CC102AE */   sw        $v0, %lo(D_800DC18C)($s0)
  .L8006A940:
    /* 2140 8006A940 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 2144 8006A944 1800B28F */  lw         $s2, 0x18($sp)
    /* 2148 8006A948 1400B18F */  lw         $s1, 0x14($sp)
    /* 214C 8006A94C 1000B08F */  lw         $s0, 0x10($sp)
    /* 2150 8006A950 0800E003 */  jr         $ra
    /* 2154 8006A954 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006A888
