nonmatching func_80104B8C, 0xB4

glabel func_80104B8C
    /* 238C 80104B8C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2390 80104B90 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2394 80104B94 21908000 */  addu       $s2, $a0, $zero
    /* 2398 80104B98 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 239C 80104B9C 2198A000 */  addu       $s3, $a1, $zero
    /* 23A0 80104BA0 2120C000 */  addu       $a0, $a2, $zero
    /* 23A4 80104BA4 2000BFAF */  sw         $ra, 0x20($sp)
    /* 23A8 80104BA8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 23AC 80104BAC 02008104 */  bgez       $a0, .L80104BB8
    /* 23B0 80104BB0 1000B0AF */   sw        $s0, 0x10($sp)
    /* 23B4 80104BB4 21200000 */  addu       $a0, $zero, $zero
  .L80104BB8:
    /* 23B8 80104BB8 41008228 */  slti       $v0, $a0, 0x41
    /* 23BC 80104BBC 02004014 */  bnez       $v0, .L80104BC8
    /* 23C0 80104BC0 00000000 */   nop
    /* 23C4 80104BC4 40000424 */  addiu      $a0, $zero, 0x40
  .L80104BC8:
    /* 23C8 80104BC8 16008018 */  blez       $a0, .L80104C24
    /* 23CC 80104BCC 21286002 */   addu      $a1, $s3, $zero
    /* 23D0 80104BD0 16000624 */  addiu      $a2, $zero, 0x16
    /* 23D4 80104BD4 1180113C */  lui        $s1, %hi(D_80109738)
    /* 23D8 80104BD8 38973126 */  addiu      $s1, $s1, %lo(D_80109738)
    /* 23DC 80104BDC 1180103C */  lui        $s0, %hi(D_801091D8)
    /* 23E0 80104BE0 D8911026 */  addiu      $s0, $s0, %lo(D_801091D8)
    /* 23E4 80104BE4 B2000292 */  lbu        $v0, 0xB2($s0)
    /* 23E8 80104BE8 BA000392 */  lbu        $v1, 0xBA($s0)
    /* 23EC 80104BEC 21382002 */  addu       $a3, $s1, $zero
    /* 23F0 80104BF0 030024A2 */  sb         $a0, 0x3($s1)
    /* 23F4 80104BF4 070024A2 */  sb         $a0, 0x7($s1)
    /* 23F8 80104BF8 21104300 */  addu       $v0, $v0, $v1
    /* 23FC 80104BFC 43100200 */  sra        $v0, $v0, 1
    /* 2400 80104C00 23904202 */  subu       $s2, $s2, $v0
    /* 2404 80104C04 A01A040C */  jal        func_80106A80
    /* 2408 80104C08 21204002 */   addu      $a0, $s2, $zero
    /* 240C 80104C0C 21286002 */  addu       $a1, $s3, $zero
    /* 2410 80104C10 17000624 */  addiu      $a2, $zero, 0x17
    /* 2414 80104C14 B2000492 */  lbu        $a0, 0xB2($s0)
    /* 2418 80104C18 04002726 */  addiu      $a3, $s1, 0x4
    /* 241C 80104C1C A01A040C */  jal        func_80106A80
    /* 2420 80104C20 21204402 */   addu      $a0, $s2, $a0
  .L80104C24:
    /* 2424 80104C24 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2428 80104C28 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 242C 80104C2C 1800B28F */  lw         $s2, 0x18($sp)
    /* 2430 80104C30 1400B18F */  lw         $s1, 0x14($sp)
    /* 2434 80104C34 1000B08F */  lw         $s0, 0x10($sp)
    /* 2438 80104C38 0800E003 */  jr         $ra
    /* 243C 80104C3C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80104B8C
