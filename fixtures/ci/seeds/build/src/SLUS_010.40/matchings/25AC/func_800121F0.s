nonmatching func_800121F0, 0x98

glabel func_800121F0
    /* 29F0 800121F0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 29F4 800121F4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 29F8 800121F8 21888000 */  addu       $s1, $a0, $zero
    /* 29FC 800121FC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2A00 80012200 2190A000 */  addu       $s2, $a1, $zero
    /* 2A04 80012204 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2A08 80012208 2198C000 */  addu       $s3, $a2, $zero
    /* 2A0C 8001220C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 2A10 80012210 21A0E000 */  addu       $s4, $a3, $zero
    /* 2A14 80012214 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2A18 80012218 2400BFAF */  sw         $ra, 0x24($sp)
    /* 2A1C 8001221C 1A4D000C */  jal        Sound_IsNotAkaoFile
    /* 2A20 80012220 FFFF1024 */   addiu     $s0, $zero, -0x1
    /* 2A24 80012224 10004014 */  bnez       $v0, .L80012268
    /* 2A28 80012228 21100002 */   addu      $v0, $s0, $zero
    /* 2A2C 8001222C FF00023C */  lui        $v0, (0xFFFFFF >> 16)
    /* 2A30 80012230 FFFF4234 */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* 2A34 80012234 24000424 */  addiu      $a0, $zero, 0x24
    /* 2A38 80012238 0380033C */  lui        $v1, %hi(D_800378C0)
    /* 2A3C 8001223C C07871AC */  sw         $s1, %lo(D_800378C0)($v1)
    /* 2A40 80012240 C0786324 */  addiu      $v1, $v1, %lo(D_800378C0)
    /* 2A44 80012244 24104202 */  and        $v0, $s2, $v0
    /* 2A48 80012248 040062AC */  sw         $v0, 0x4($v1)
    /* 2A4C 8001224C FF006232 */  andi       $v0, $s3, 0xFF
    /* 2A50 80012250 080062AC */  sw         $v0, 0x8($v1)
    /* 2A54 80012254 7F008232 */  andi       $v0, $s4, 0x7F
    /* 2A58 80012258 0C63000C */  jal        func_80018C30
    /* 2A5C 8001225C 0C0062AC */   sw        $v0, 0xC($v1)
    /* 2A60 80012260 21802002 */  addu       $s0, $s1, $zero
    /* 2A64 80012264 21100002 */  addu       $v0, $s0, $zero
  .L80012268:
    /* 2A68 80012268 2400BF8F */  lw         $ra, 0x24($sp)
    /* 2A6C 8001226C 2000B48F */  lw         $s4, 0x20($sp)
    /* 2A70 80012270 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2A74 80012274 1800B28F */  lw         $s2, 0x18($sp)
    /* 2A78 80012278 1400B18F */  lw         $s1, 0x14($sp)
    /* 2A7C 8001227C 1000B08F */  lw         $s0, 0x10($sp)
    /* 2A80 80012280 0800E003 */  jr         $ra
    /* 2A84 80012284 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800121F0
