nonmatching func_800C28AC, 0x260

glabel func_800C28AC
    /* 5A0AC 800C28AC C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 5A0B0 800C28B0 2000B2AF */  sw         $s2, 0x20($sp)
    /* 5A0B4 800C28B4 801F123C */  lui        $s2, (0x1F800000 >> 16)
    /* 5A0B8 800C28B8 00004226 */  addiu      $v0, $s2, %lo(D_1F800000)
    /* 5A0BC 800C28BC 3800BFAF */  sw         $ra, 0x38($sp)
    /* 5A0C0 800C28C0 3400B7AF */  sw         $s7, 0x34($sp)
    /* 5A0C4 800C28C4 3000B6AF */  sw         $s6, 0x30($sp)
    /* 5A0C8 800C28C8 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 5A0CC 800C28CC 2800B4AF */  sw         $s4, 0x28($sp)
    /* 5A0D0 800C28D0 2400B3AF */  sw         $s3, 0x24($sp)
    /* 5A0D4 800C28D4 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 5A0D8 800C28D8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 5A0DC 800C28DC 0400598C */  lw         $t9, 0x4($v0)
    /* 5A0E0 800C28E0 21B0A000 */  addu       $s6, $a1, $zero
    /* 5A0E4 800C28E4 FCFF3727 */  addiu      $s7, $t9, -0x4
    /* 5A0E8 800C28E8 000080C8 */  lwc2       $0, 0x0($a0)
    /* 5A0EC 800C28EC 040081C8 */  lwc2       $1, 0x4($a0)
    /* 5A0F0 800C28F0 00000000 */  nop
    /* 5A0F4 800C28F4 00000000 */  nop
    /* 5A0F8 800C28F8 0100184A */  rtps
    /* 5A0FC 800C28FC 1000A227 */  addiu      $v0, $sp, 0x10
    /* 5A100 800C2900 00004EE8 */  swc2       $14, 0x0($v0)
    /* 5A104 800C2904 0F80033C */  lui        $v1, %hi(D_800EA6AC)
    /* 5A108 800C2908 ACA66290 */  lbu        $v0, %lo(D_800EA6AC)($v1)
    /* 5A10C 800C290C 00000000 */  nop
    /* 5A110 800C2910 01004224 */  addiu      $v0, $v0, 0x1
    /* 5A114 800C2914 0F004230 */  andi       $v0, $v0, 0xF
    /* 5A118 800C2918 4C00C016 */  bnez       $s6, .L800C2A4C
    /* 5A11C 800C291C ACA662A0 */   sb        $v0, %lo(D_800EA6AC)($v1)
    /* 5A120 800C2920 FF00103C */  lui        $s0, (0xFFFFFF >> 16)
    /* 5A124 800C2924 FFFF1036 */  ori        $s0, $s0, (0xFFFFFF & 0xFFFF)
    /* 5A128 800C2928 802C0D3C */  lui        $t5, (0x2C808080 >> 16)
    /* 5A12C 800C292C 8080AD35 */  ori        $t5, $t5, (0x2C808080 & 0xFFFF)
    /* 5A130 800C2930 F7FF063C */  lui        $a2, (0xFFF7FFF3 >> 16)
    /* 5A134 800C2934 F3FFC634 */  ori        $a2, $a2, (0xFFF7FFF3 & 0xFFFF)
    /* 5A138 800C2938 FD370B3C */  lui        $t3, (0x37FD38F1 >> 16)
    /* 5A13C 800C293C F1386B35 */  ori        $t3, $t3, (0x37FD38F1 & 0xFFFF)
    /* 5A140 800C2940 F7FF053C */  lui        $a1, (0xFFF7FFFD >> 16)
    /* 5A144 800C2944 FDFFA534 */  ori        $a1, $a1, (0xFFF7FFFD & 0xFFFF)
    /* 5A148 800C2948 0C00033C */  lui        $v1, (0xC38E7 >> 16)
    /* 5A14C 800C294C E7386334 */  ori        $v1, $v1, (0xC38E7 & 0xFFFF)
    /* 5A150 800C2950 FEFF043C */  lui        $a0, (0xFFFEFFF3 >> 16)
    /* 5A154 800C2954 F3FF8434 */  ori        $a0, $a0, (0xFFFEFFF3 & 0xFFFF)
    /* 5A158 800C2958 FEFF0E3C */  lui        $t6, (0xFFFEFFFD >> 16)
    /* 5A15C 800C295C FDFFCE35 */  ori        $t6, $t6, (0xFFFEFFFD & 0xFFFF)
    /* 5A160 800C2960 0100093C */  lui        $t1, (0x1FFF3 >> 16)
    /* 5A164 800C2964 F3FF2935 */  ori        $t1, $t1, (0x1FFF3 & 0xFFFF)
    /* 5A168 800C2968 FD370F3C */  lui        $t7, (0x37FD40F1 >> 16)
    /* 5A16C 800C296C F140EF35 */  ori        $t7, $t7, (0x37FD40F1 & 0xFFFF)
    /* 5A170 800C2970 0100083C */  lui        $t0, (0x1FFFD >> 16)
    /* 5A174 800C2974 FDFF0835 */  ori        $t0, $t0, (0x1FFFD & 0xFFFF)
    /* 5A178 800C2978 0C000C3C */  lui        $t4, (0xC40E7 >> 16)
    /* 5A17C 800C297C E7408C35 */  ori        $t4, $t4, (0xC40E7 & 0xFFFF)
    /* 5A180 800C2980 0800073C */  lui        $a3, (0x8FFF3 >> 16)
    /* 5A184 800C2984 F3FFE734 */  ori        $a3, $a3, (0x8FFF3 & 0xFFFF)
    /* 5A188 800C2988 0800113C */  lui        $s1, (0x8FFFD >> 16)
    /* 5A18C 800C298C FDFF3136 */  ori        $s1, $s1, (0x8FFFD & 0xFFFF)
    /* 5A190 800C2990 00090A3C */  lui        $t2, (0x9000000 >> 16)
    /* 5A194 800C2994 FCFF228F */  lw         $v0, -0x4($t9)
    /* 5A198 800C2998 0000588E */  lw         $t8, (0x1F800000 & 0xFFFF)($s2)
    /* 5A19C 800C299C 24105000 */  and        $v0, $v0, $s0
    /* 5A1A0 800C29A0 25104A00 */  or         $v0, $v0, $t2
    /* 5A1A4 800C29A4 000002AF */  sw         $v0, 0x0($t8)
    /* 5A1A8 800C29A8 F13F0224 */  addiu      $v0, $zero, 0x3FF1
    /* 5A1AC 800C29AC 04000DAF */  sw         $t5, 0x4($t8)
    /* 5A1B0 800C29B0 0C000BAF */  sw         $t3, 0xC($t8)
    /* 5A1B4 800C29B4 140003AF */  sw         $v1, 0x14($t8)
    /* 5A1B8 800C29B8 1C0002AF */  sw         $v0, 0x1C($t8)
    /* 5A1BC 800C29BC 1000A38F */  lw         $v1, 0x10($sp)
    /* 5A1C0 800C29C0 E73F0224 */  addiu      $v0, $zero, 0x3FE7
    /* 5A1C4 800C29C4 240002AF */  sw         $v0, 0x24($t8)
    /* 5A1C8 800C29C8 F1470224 */  addiu      $v0, $zero, 0x47F1
    /* 5A1CC 800C29CC 21306600 */  addu       $a2, $v1, $a2
    /* 5A1D0 800C29D0 21286500 */  addu       $a1, $v1, $a1
    /* 5A1D4 800C29D4 21206400 */  addu       $a0, $v1, $a0
    /* 5A1D8 800C29D8 21186E00 */  addu       $v1, $v1, $t6
    /* 5A1DC 800C29DC 080006AF */  sw         $a2, 0x8($t8)
    /* 5A1E0 800C29E0 100005AF */  sw         $a1, 0x10($t8)
    /* 5A1E4 800C29E4 180004AF */  sw         $a0, 0x18($t8)
    /* 5A1E8 800C29E8 200003AF */  sw         $v1, 0x20($t8)
    /* 5A1EC 800C29EC FCFF38AF */  sw         $t8, -0x4($t9)
    /* 5A1F0 800C29F0 21180003 */  addu       $v1, $t8, $zero
    /* 5A1F4 800C29F4 28001827 */  addiu      $t8, $t8, 0x28
    /* 5A1F8 800C29F8 24187000 */  and        $v1, $v1, $s0
    /* 5A1FC 800C29FC 25186A00 */  or         $v1, $v1, $t2
    /* 5A200 800C2A00 04000DAF */  sw         $t5, 0x4($t8)
    /* 5A204 800C2A04 0C000FAF */  sw         $t7, 0xC($t8)
    /* 5A208 800C2A08 14000CAF */  sw         $t4, 0x14($t8)
    /* 5A20C 800C2A0C 1C0002AF */  sw         $v0, 0x1C($t8)
    /* 5A210 800C2A10 000003AF */  sw         $v1, 0x0($t8)
    /* 5A214 800C2A14 1000A38F */  lw         $v1, 0x10($sp)
    /* 5A218 800C2A18 E7470224 */  addiu      $v0, $zero, 0x47E7
    /* 5A21C 800C2A1C 240002AF */  sw         $v0, 0x24($t8)
    /* 5A220 800C2A20 21486900 */  addu       $t1, $v1, $t1
    /* 5A224 800C2A24 21406800 */  addu       $t0, $v1, $t0
    /* 5A228 800C2A28 21386700 */  addu       $a3, $v1, $a3
    /* 5A22C 800C2A2C 21187100 */  addu       $v1, $v1, $s1
    /* 5A230 800C2A30 080009AF */  sw         $t1, 0x8($t8)
    /* 5A234 800C2A34 100008AF */  sw         $t0, 0x10($t8)
    /* 5A238 800C2A38 180007AF */  sw         $a3, 0x18($t8)
    /* 5A23C 800C2A3C 200003AF */  sw         $v1, 0x20($t8)
    /* 5A240 800C2A40 FCFF38AF */  sw         $t8, -0x4($t9)
    /* 5A244 800C2A44 28001827 */  addiu      $t8, $t8, 0x28
    /* 5A248 800C2A48 000058AE */  sw         $t8, (0x1F800000 & 0xFFFF)($s2)
  .L800C2A4C:
    /* 5A24C 800C2A4C 21880000 */  addu       $s1, $zero, $zero
    /* 5A250 800C2A50 0F80023C */  lui        $v0, %hi(D_800EC270)
    /* 5A254 800C2A54 70C25524 */  addiu      $s5, $v0, %lo(D_800EC270)
    /* 5A258 800C2A58 0F80023C */  lui        $v0, %hi(D_800EA670)
    /* 5A25C 800C2A5C 70A65424 */  addiu      $s4, $v0, %lo(D_800EA670)
    /* 5A260 800C2A60 0F80023C */  lui        $v0, %hi(D_800EA684)
    /* 5A264 800C2A64 84A65324 */  addiu      $s3, $v0, %lo(D_800EA684)
    /* 5A268 800C2A68 0F80023C */  lui        $v0, %hi(D_800EA698)
    /* 5A26C 800C2A6C 98A65224 */  addiu      $s2, $v0, %lo(D_800EA698)
  .L800C2A70:
    /* 5A270 800C2A70 40101600 */  sll        $v0, $s6, 1
    /* 5A274 800C2A74 21802202 */  addu       $s0, $s1, $v0
    /* 5A278 800C2A78 02000224 */  addiu      $v0, $zero, 0x2
    /* 5A27C 800C2A7C 08000216 */  bne        $s0, $v0, .L800C2AA0
    /* 5A280 800C2A80 80000424 */   addiu     $a0, $zero, 0x80
    /* 5A284 800C2A84 0F80023C */  lui        $v0, %hi(D_800EA6AC)
    /* 5A288 800C2A88 ACA64290 */  lbu        $v0, %lo(D_800EA6AC)($v0)
    /* 5A28C 800C2A8C 00000000 */  nop
    /* 5A290 800C2A90 21105500 */  addu       $v0, $v0, $s5
    /* 5A294 800C2A94 00004490 */  lbu        $a0, 0x0($v0)
    /* 5A298 800C2A98 A90A0308 */  j          .L800C2AA4
    /* 5A29C 800C2A9C 80801000 */   sll       $s0, $s0, 2
  .L800C2AA0:
    /* 5A2A0 800C2AA0 80801000 */  sll        $s0, $s0, 2
  .L800C2AA4:
    /* 5A2A4 800C2AA4 21101402 */  addu       $v0, $s0, $s4
    /* 5A2A8 800C2AA8 21301302 */  addu       $a2, $s0, $s3
    /* 5A2AC 800C2AAC 2138E002 */  addu       $a3, $s7, $zero
    /* 5A2B0 800C2AB0 1000A38F */  lw         $v1, 0x10($sp)
    /* 5A2B4 800C2AB4 0000458C */  lw         $a1, 0x0($v0)
    /* 5A2B8 800C2AB8 0000C68C */  lw         $a2, 0x0($a2)
    /* 5A2BC 800C2ABC 8900030C */  jal        func_800C0224
    /* 5A2C0 800C2AC0 21286500 */   addu      $a1, $v1, $a1
    /* 5A2C4 800C2AC4 21801202 */  addu       $s0, $s0, $s2
    /* 5A2C8 800C2AC8 0000038E */  lw         $v1, 0x0($s0)
    /* 5A2CC 800C2ACC 01003126 */  addiu      $s1, $s1, 0x1
    /* 5A2D0 800C2AD0 100043AC */  sw         $v1, 0x10($v0)
    /* 5A2D4 800C2AD4 0300222A */  slti       $v0, $s1, 0x3
    /* 5A2D8 800C2AD8 E5FF4014 */  bnez       $v0, .L800C2A70
    /* 5A2DC 800C2ADC 00000000 */   nop
    /* 5A2E0 800C2AE0 3800BF8F */  lw         $ra, 0x38($sp)
    /* 5A2E4 800C2AE4 3400B78F */  lw         $s7, 0x34($sp)
    /* 5A2E8 800C2AE8 3000B68F */  lw         $s6, 0x30($sp)
    /* 5A2EC 800C2AEC 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 5A2F0 800C2AF0 2800B48F */  lw         $s4, 0x28($sp)
    /* 5A2F4 800C2AF4 2400B38F */  lw         $s3, 0x24($sp)
    /* 5A2F8 800C2AF8 2000B28F */  lw         $s2, 0x20($sp)
    /* 5A2FC 800C2AFC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 5A300 800C2B00 1800B08F */  lw         $s0, 0x18($sp)
    /* 5A304 800C2B04 0800E003 */  jr         $ra
    /* 5A308 800C2B08 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_800C28AC
