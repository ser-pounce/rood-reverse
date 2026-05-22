nonmatching _computeSphericalOffset, 0xF0

glabel _computeSphericalOffset
    /* 121DC 8007A9DC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 121E0 8007A9E0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 121E4 8007A9E4 21888000 */  addu       $s1, $a0, $zero
    /* 121E8 8007A9E8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 121EC 8007A9EC 2190C000 */  addu       $s2, $a2, $zero
    /* 121F0 8007A9F0 2000BFAF */  sw         $ra, 0x20($sp)
    /* 121F4 8007A9F4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 121F8 8007A9F8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 121FC 8007A9FC 0000448E */  lw         $a0, 0x0($s2)
    /* 12200 8007AA00 CA03010C */  jal        rsin
    /* 12204 8007AA04 2198A000 */   addu      $s3, $a1, $zero
    /* 12208 8007AA08 000022AE */  sw         $v0, 0x0($s1)
    /* 1220C 8007AA0C 0000448E */  lw         $a0, 0x0($s2)
    /* 12210 8007AA10 C903010C */  jal        rcos
    /* 12214 8007AA14 00000000 */   nop
    /* 12218 8007AA18 080022AE */  sw         $v0, 0x8($s1)
    /* 1221C 8007AA1C 0400448E */  lw         $a0, 0x4($s2)
    /* 12220 8007AA20 CA03010C */  jal        rsin
    /* 12224 8007AA24 00000000 */   nop
    /* 12228 8007AA28 0400448E */  lw         $a0, 0x4($s2)
    /* 1222C 8007AA2C C903010C */  jal        rcos
    /* 12230 8007AA30 21804000 */   addu      $s0, $v0, $zero
    /* 12234 8007AA34 00831000 */  sll        $s0, $s0, 12
    /* 12238 8007AA38 1A000202 */  div        $zero, $s0, $v0
    /* 1223C 8007AA3C 12800000 */  mflo       $s0
    /* 12240 8007AA40 21202002 */  addu       $a0, $s1, $zero
    /* 12244 8007AA44 21282002 */  addu       $a1, $s1, $zero
    /* 12248 8007AA48 A506010C */  jal        VectorNormal
    /* 1224C 8007AA4C 040030AE */   sw        $s0, 0x4($s1)
    /* 12250 8007AA50 0000238E */  lw         $v1, 0x0($s1)
    /* 12254 8007AA54 0800428E */  lw         $v0, 0x8($s2)
    /* 12258 8007AA58 00000000 */  nop
    /* 1225C 8007AA5C 18006200 */  mult       $v1, $v0
    /* 12260 8007AA60 0000628E */  lw         $v0, 0x0($s3)
    /* 12264 8007AA64 12180000 */  mflo       $v1
    /* 12268 8007AA68 21106200 */  addu       $v0, $v1, $v0
    /* 1226C 8007AA6C 0800238E */  lw         $v1, 0x8($s1)
    /* 12270 8007AA70 000022AE */  sw         $v0, 0x0($s1)
    /* 12274 8007AA74 0800428E */  lw         $v0, 0x8($s2)
    /* 12278 8007AA78 00000000 */  nop
    /* 1227C 8007AA7C 18006200 */  mult       $v1, $v0
    /* 12280 8007AA80 0800628E */  lw         $v0, 0x8($s3)
    /* 12284 8007AA84 12180000 */  mflo       $v1
    /* 12288 8007AA88 21106200 */  addu       $v0, $v1, $v0
    /* 1228C 8007AA8C 0400238E */  lw         $v1, 0x4($s1)
    /* 12290 8007AA90 080022AE */  sw         $v0, 0x8($s1)
    /* 12294 8007AA94 0800428E */  lw         $v0, 0x8($s2)
    /* 12298 8007AA98 00000000 */  nop
    /* 1229C 8007AA9C 18006200 */  mult       $v1, $v0
    /* 122A0 8007AAA0 0400628E */  lw         $v0, 0x4($s3)
    /* 122A4 8007AAA4 12180000 */  mflo       $v1
    /* 122A8 8007AAA8 21106200 */  addu       $v0, $v1, $v0
    /* 122AC 8007AAAC 040022AE */  sw         $v0, 0x4($s1)
    /* 122B0 8007AAB0 2000BF8F */  lw         $ra, 0x20($sp)
    /* 122B4 8007AAB4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 122B8 8007AAB8 1800B28F */  lw         $s2, 0x18($sp)
    /* 122BC 8007AABC 1400B18F */  lw         $s1, 0x14($sp)
    /* 122C0 8007AAC0 1000B08F */  lw         $s0, 0x10($sp)
    /* 122C4 8007AAC4 0800E003 */  jr         $ra
    /* 122C8 8007AAC8 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _computeSphericalOffset
