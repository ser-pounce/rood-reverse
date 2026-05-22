nonmatching func_8006AAA0, 0xA4

glabel func_8006AAA0
    /* 22A0 8006AAA0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 22A4 8006AAA4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 22A8 8006AAA8 21980000 */  addu       $s3, $zero, $zero
    /* 22AC 8006AAAC 0E80023C */  lui        $v0, %hi(D_800DBB88)
    /* 22B0 8006AAB0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 22B4 8006AAB4 88BB5024 */  addiu      $s0, $v0, %lo(D_800DBB88)
    /* 22B8 8006AAB8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 22BC 8006AABC 21906002 */  addu       $s2, $s3, $zero
    /* 22C0 8006AAC0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 22C4 8006AAC4 08001126 */  addiu      $s1, $s0, 0x8
    /* 22C8 8006AAC8 2000BFAF */  sw         $ra, 0x20($sp)
  .L8006AACC:
    /* 22CC 8006AACC 00002286 */  lh         $v0, 0x0($s1)
    /* 22D0 8006AAD0 00000000 */  nop
    /* 22D4 8006AAD4 03004104 */  bgez       $v0, .L8006AAE4
    /* 22D8 8006AAD8 00000000 */   nop
    /* 22DC 8006AADC C0AA0108 */  j          .L8006AB00
    /* 22E0 8006AAE0 000020A6 */   sh        $zero, 0x0($s1)
  .L8006AAE4:
    /* 22E4 8006AAE4 07004018 */  blez       $v0, .L8006AB04
    /* 22E8 8006AAE8 01004226 */   addiu     $v0, $s2, 0x1
    /* 22EC 8006AAEC 01007326 */  addiu      $s3, $s3, 0x1
    /* 22F0 8006AAF0 0000028E */  lw         $v0, 0x0($s0)
    /* 22F4 8006AAF4 00000000 */  nop
    /* 22F8 8006AAF8 09F84000 */  jalr       $v0
    /* 22FC 8006AAFC 21200002 */   addu      $a0, $s0, $zero
  .L8006AB00:
    /* 2300 8006AB00 01004226 */  addiu      $v0, $s2, 0x1
  .L8006AB04:
    /* 2304 8006AB04 21904000 */  addu       $s2, $v0, $zero
    /* 2308 8006AB08 30003126 */  addiu      $s1, $s1, 0x30
    /* 230C 8006AB0C 00140200 */  sll        $v0, $v0, 16
    /* 2310 8006AB10 03140200 */  sra        $v0, $v0, 16
    /* 2314 8006AB14 20004228 */  slti       $v0, $v0, 0x20
    /* 2318 8006AB18 ECFF4014 */  bnez       $v0, .L8006AACC
    /* 231C 8006AB1C 30001026 */   addiu     $s0, $s0, 0x30
    /* 2320 8006AB20 00141300 */  sll        $v0, $s3, 16
    /* 2324 8006AB24 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2328 8006AB28 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 232C 8006AB2C 1800B28F */  lw         $s2, 0x18($sp)
    /* 2330 8006AB30 1400B18F */  lw         $s1, 0x14($sp)
    /* 2334 8006AB34 1000B08F */  lw         $s0, 0x10($sp)
    /* 2338 8006AB38 03140200 */  sra        $v0, $v0, 16
    /* 233C 8006AB3C 0800E003 */  jr         $ra
    /* 2340 8006AB40 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8006AAA0
