nonmatching func_800A30A0, 0x270

glabel func_800A30A0
    /* 3A8A0 800A30A0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 3A8A4 800A30A4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3A8A8 800A30A8 21988000 */  addu       $s3, $a0, $zero
    /* 3A8AC 800A30AC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3A8B0 800A30B0 2190A000 */  addu       $s2, $a1, $zero
    /* 3A8B4 800A30B4 0F80033C */  lui        $v1, %hi(D_800F4538)
    /* 3A8B8 800A30B8 38456324 */  addiu      $v1, $v1, %lo(D_800F4538)
    /* 3A8BC 800A30BC 80101300 */  sll        $v0, $s3, 2
    /* 3A8C0 800A30C0 21104300 */  addu       $v0, $v0, $v1
    /* 3A8C4 800A30C4 2400BFAF */  sw         $ra, 0x24($sp)
    /* 3A8C8 800A30C8 2000B4AF */  sw         $s4, 0x20($sp)
    /* 3A8CC 800A30CC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3A8D0 800A30D0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3A8D4 800A30D4 0000508C */  lw         $s0, 0x0($v0)
    /* 3A8D8 800A30D8 0000428E */  lw         $v0, 0x0($s2)
    /* 3A8DC 800A30DC 21A0C000 */  addu       $s4, $a2, $zero
    /* 3A8E0 800A30E0 5C0002AE */  sw         $v0, 0x5C($s0)
    /* 3A8E4 800A30E4 00004292 */  lbu        $v0, 0x0($s2)
    /* 3A8E8 800A30E8 2188E000 */  addu       $s1, $a3, $zero
    /* 3A8EC 800A30EC C0110200 */  sll        $v0, $v0, 7
    /* 3A8F0 800A30F0 40004224 */  addiu      $v0, $v0, 0x40
    /* 3A8F4 800A30F4 1C0002A6 */  sh         $v0, 0x1C($s0)
    /* 3A8F8 800A30F8 02004292 */  lbu        $v0, 0x2($s2)
    /* 3A8FC 800A30FC 1C000486 */  lh         $a0, 0x1C($s0)
    /* 3A900 800A3100 C0110200 */  sll        $v0, $v0, 7
    /* 3A904 800A3104 40004224 */  addiu      $v0, $v0, 0x40
    /* 3A908 800A3108 002C0200 */  sll        $a1, $v0, 16
    /* 3A90C 800A310C 032C0500 */  sra        $a1, $a1, 16
    /* 3A910 800A3110 408D020C */  jal        func_800A3500
    /* 3A914 800A3114 200002A6 */   sh        $v0, 0x20($s0)
    /* 3A918 800A3118 1E0002A6 */  sh         $v0, 0x1E($s0)
    /* 3A91C 800A311C 10000224 */  addiu      $v0, $zero, 0x10
    /* 3A920 800A3120 03002212 */  beq        $s1, $v0, .L800A3130
    /* 3A924 800A3124 20000224 */   addiu     $v0, $zero, 0x20
    /* 3A928 800A3128 24002216 */  bne        $s1, $v0, .L800A31BC
    /* 3A92C 800A312C 40000224 */   addiu     $v0, $zero, 0x40
  .L800A3130:
    /* 3A930 800A3130 7B9D030C */  jal        func_800E75EC
    /* 3A934 800A3134 00000000 */   nop
    /* 3A938 800A3138 21184000 */  addu       $v1, $v0, $zero
    /* 3A93C 800A313C 03006014 */  bnez       $v1, .L800A314C
    /* 3A940 800A3140 00000000 */   nop
    /* 3A944 800A3144 5A8C0208 */  j          .L800A3168
    /* 3A948 800A3148 80FE0324 */   addiu     $v1, $zero, -0x180
  .L800A314C:
    /* 3A94C 800A314C 1E000286 */  lh         $v0, 0x1E($s0)
    /* 3A950 800A3150 00000000 */  nop
    /* 3A954 800A3154 23186200 */  subu       $v1, $v1, $v0
    /* 3A958 800A3158 81FF6228 */  slti       $v0, $v1, -0x7F
    /* 3A95C 800A315C 03004014 */  bnez       $v0, .L800A316C
    /* 3A960 800A3160 21206002 */   addu      $a0, $s3, $zero
    /* 3A964 800A3164 80FF0324 */  addiu      $v1, $zero, -0x80
  .L800A3168:
    /* 3A968 800A3168 21206002 */  addu       $a0, $s3, $zero
  .L800A316C:
    /* 3A96C 800A316C 1C001126 */  addiu      $s1, $s0, 0x1C
    /* 3A970 800A3170 1E000296 */  lhu        $v0, 0x1E($s0)
    /* 3A974 800A3174 21282002 */  addu       $a1, $s1, $zero
    /* 3A978 800A3178 21104300 */  addu       $v0, $v0, $v1
    /* 3A97C 800A317C C48C020C */  jal        func_800A3310
    /* 3A980 800A3180 1E0002A6 */   sh        $v0, 0x1E($s0)
    /* 3A984 800A3184 04004010 */  beqz       $v0, .L800A3198
    /* 3A988 800A3188 00000000 */   nop
    /* 3A98C 800A318C 21206002 */  addu       $a0, $s3, $zero
    /* 3A990 800A3190 E58C020C */  jal        func_800A3394
    /* 3A994 800A3194 21282002 */   addu      $a1, $s1, $zero
  .L800A3198:
    /* 3A998 800A3198 21206002 */  addu       $a0, $s3, $zero
    /* 3A99C 800A319C 08000524 */  addiu      $a1, $zero, 0x8
    /* 3A9A0 800A31A0 21300000 */  addu       $a2, $zero, $zero
    /* 3A9A4 800A31A4 2138C000 */  addu       $a3, $a2, $zero
    /* 3A9A8 800A31A8 0800028E */  lw         $v0, 0x8($s0)
    /* 3A9AC 800A31AC 2000033C */  lui        $v1, (0x200000 >> 16)
    /* 3A9B0 800A31B0 25104300 */  or         $v0, $v0, $v1
    /* 3A9B4 800A31B4 AA8C0208 */  j          .L800A32A8
    /* 3A9B8 800A31B8 080002AE */   sw        $v0, 0x8($s0)
  .L800A31BC:
    /* 3A9BC 800A31BC 03002212 */  beq        $s1, $v0, .L800A31CC
    /* 3A9C0 800A31C0 80000224 */   addiu     $v0, $zero, 0x80
    /* 3A9C4 800A31C4 05002216 */  bne        $s1, $v0, .L800A31DC
    /* 3A9C8 800A31C8 00000000 */   nop
  .L800A31CC:
    /* 3A9CC 800A31CC 0800028E */  lw         $v0, 0x8($s0)
    /* 3A9D0 800A31D0 4000033C */  lui        $v1, (0x400000 >> 16)
    /* 3A9D4 800A31D4 25104300 */  or         $v0, $v0, $v1
    /* 3A9D8 800A31D8 080002AE */  sw         $v0, 0x8($s0)
  .L800A31DC:
    /* 3A9DC 800A31DC 01004392 */  lbu        $v1, 0x1($s2)
    /* 3A9E0 800A31E0 07000224 */  addiu      $v0, $zero, 0x7
    /* 3A9E4 800A31E4 0C006214 */  bne        $v1, $v0, .L800A3218
    /* 3A9E8 800A31E8 0200622C */   sltiu     $v0, $v1, 0x2
    /* 3A9EC 800A31EC F8FF023C */  lui        $v0, (0xFFF8FFFF >> 16)
    /* 3A9F0 800A31F0 0800038E */  lw         $v1, 0x8($s0)
    /* 3A9F4 800A31F4 FFFF4234 */  ori        $v0, $v0, (0xFFF8FFFF & 0xFFFF)
    /* 3A9F8 800A31F8 5D0000A2 */  sb         $zero, 0x5D($s0)
    /* 3A9FC 800A31FC 1E0014A6 */  sh         $s4, 0x1E($s0)
    /* 3AA00 800A3200 360000A6 */  sh         $zero, 0x36($s0)
    /* 3AA04 800A3204 24186200 */  and        $v1, $v1, $v0
    /* 3AA08 800A3208 0300023C */  lui        $v0, (0x30000 >> 16)
    /* 3AA0C 800A320C 25186200 */  or         $v1, $v1, $v0
    /* 3AA10 800A3210 AC8C0208 */  j          .L800A32B0
    /* 3AA14 800A3214 080003AE */   sw        $v1, 0x8($s0)
  .L800A3218:
    /* 3AA18 800A3218 1F004014 */  bnez       $v0, .L800A3298
    /* 3AA1C 800A321C 00000000 */   nop
    /* 3AA20 800A3220 01004492 */  lbu        $a0, 0x1($s2)
    /* 3AA24 800A3224 8992020C */  jal        func_800A4A24
    /* 3AA28 800A3228 00000000 */   nop
    /* 3AA2C 800A322C 0000438C */  lw         $v1, 0x0($v0)
    /* 3AA30 800A3230 00000000 */  nop
    /* 3AA34 800A3234 1C0003AE */  sw         $v1, 0x1C($s0)
    /* 3AA38 800A3238 0400438C */  lw         $v1, 0x4($v0)
    /* 3AA3C 800A323C 00000000 */  nop
    /* 3AA40 800A3240 200003AE */  sw         $v1, 0x20($s0)
    /* 3AA44 800A3244 0000438C */  lw         $v1, 0x0($v0)
    /* 3AA48 800A3248 00000000 */  nop
    /* 3AA4C 800A324C EC1703AE */  sw         $v1, 0x17EC($s0)
    /* 3AA50 800A3250 0400428C */  lw         $v0, 0x4($v0)
    /* 3AA54 800A3254 0C00038E */  lw         $v1, 0xC($s0)
    /* 3AA58 800A3258 F0FF0424 */  addiu      $a0, $zero, -0x10
    /* 3AA5C 800A325C F01702AE */  sw         $v0, 0x17F0($s0)
    /* 3AA60 800A3260 01004292 */  lbu        $v0, 0x1($s2)
    /* 3AA64 800A3264 24186400 */  and        $v1, $v1, $a0
    /* 3AA68 800A3268 F21702A6 */  sh         $v0, 0x17F2($s0)
    /* 3AA6C 800A326C 01004292 */  lbu        $v0, 0x1($s2)
    /* 3AA70 800A3270 0FFF0424 */  addiu      $a0, $zero, -0xF1
    /* 3AA74 800A3274 0F004230 */  andi       $v0, $v0, 0xF
    /* 3AA78 800A3278 25186200 */  or         $v1, $v1, $v0
    /* 3AA7C 800A327C 0C0003AE */  sw         $v1, 0xC($s0)
    /* 3AA80 800A3280 01004292 */  lbu        $v0, 0x1($s2)
    /* 3AA84 800A3284 24186400 */  and        $v1, $v1, $a0
    /* 3AA88 800A3288 0F004230 */  andi       $v0, $v0, 0xF
    /* 3AA8C 800A328C 00110200 */  sll        $v0, $v0, 4
    /* 3AA90 800A3290 25186200 */  or         $v1, $v1, $v0
    /* 3AA94 800A3294 0C0003AE */  sw         $v1, 0xC($s0)
  .L800A3298:
    /* 3AA98 800A3298 21206002 */  addu       $a0, $s3, $zero
    /* 3AA9C 800A329C 01000524 */  addiu      $a1, $zero, 0x1
    /* 3AAA0 800A32A0 21300000 */  addu       $a2, $zero, $zero
    /* 3AAA4 800A32A4 2138C000 */  addu       $a3, $a2, $zero
  .L800A32A8:
    /* 3AAA8 800A32A8 8180020C */  jal        func_800A0204
    /* 3AAAC 800A32AC 00000000 */   nop
  .L800A32B0:
    /* 3AAB0 800A32B0 D5B3020C */  jal        func_800ACF54
    /* 3AAB4 800A32B4 21200002 */   addu      $a0, $s0, $zero
    /* 3AAB8 800A32B8 1A0000A6 */  sh         $zero, 0x1A($s0)
    /* 3AABC 800A32BC 03004392 */  lbu        $v1, 0x3($s2)
    /* 3AAC0 800A32C0 21206002 */  addu       $a0, $s3, $zero
    /* 3AAC4 800A32C4 3E0000A6 */  sh         $zero, 0x3E($s0)
    /* 3AAC8 800A32C8 180000A6 */  sh         $zero, 0x18($s0)
    /* 3AACC 800A32CC D21800A6 */  sh         $zero, 0x18D2($s0)
    /* 3AAD0 800A32D0 D41800A6 */  sh         $zero, 0x18D4($s0)
    /* 3AAD4 800A32D4 D61800A6 */  sh         $zero, 0x18D6($s0)
    /* 3AAD8 800A32D8 D81800A6 */  sh         $zero, 0x18D8($s0)
    /* 3AADC 800A32DC 00190300 */  sll        $v1, $v1, 4
    /* 3AAE0 800A32E0 AF82020C */  jal        func_800A0ABC
    /* 3AAE4 800A32E4 260003A6 */   sh        $v1, 0x26($s0)
    /* 3AAE8 800A32E8 E40600A2 */  sb         $zero, 0x6E4($s0)
    /* 3AAEC 800A32EC 2400BF8F */  lw         $ra, 0x24($sp)
    /* 3AAF0 800A32F0 2000B48F */  lw         $s4, 0x20($sp)
    /* 3AAF4 800A32F4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3AAF8 800A32F8 1800B28F */  lw         $s2, 0x18($sp)
    /* 3AAFC 800A32FC 1400B18F */  lw         $s1, 0x14($sp)
    /* 3AB00 800A3300 1000B08F */  lw         $s0, 0x10($sp)
    /* 3AB04 800A3304 2800BD27 */  addiu      $sp, $sp, 0x28
    /* 3AB08 800A3308 0800E003 */  jr         $ra
    /* 3AB0C 800A330C 00000000 */   nop
endlabel func_800A30A0
