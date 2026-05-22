nonmatching func_800CF694, 0x78

glabel func_800CF694
    /* 66E94 800CF694 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 66E98 800CF698 1400B1AF */  sw         $s1, 0x14($sp)
    /* 66E9C 800CF69C 21888000 */  addu       $s1, $a0, $zero
    /* 66EA0 800CF6A0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 66EA4 800CF6A4 2190A000 */  addu       $s2, $a1, $zero
    /* 66EA8 800CF6A8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 66EAC 800CF6AC 2198C000 */  addu       $s3, $a2, $zero
    /* 66EB0 800CF6B0 0C000424 */  addiu      $a0, $zero, 0xC
    /* 66EB4 800CF6B4 2000BFAF */  sw         $ra, 0x20($sp)
    /* 66EB8 800CF6B8 8F0F010C */  jal        vs_main_allocHeapR
    /* 66EBC 800CF6BC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 66EC0 800CF6C0 21804000 */  addu       $s0, $v0, $zero
    /* 66EC4 800CF6C4 21200002 */  addu       $a0, $s0, $zero
    /* 66EC8 800CF6C8 01000524 */  addiu      $a1, $zero, 0x1
    /* 66ECC 800CF6CC 500D228E */  lw         $v0, 0xD50($s1)
    /* 66ED0 800CF6D0 21306002 */  addu       $a2, $s3, $zero
    /* 66ED4 800CF6D4 000002AE */  sw         $v0, 0x0($s0)
    /* 66ED8 800CF6D8 500D30AE */  sw         $s0, 0xD50($s1)
    /* 66EDC 800CF6DC 040012AE */  sw         $s2, 0x4($s0)
    /* 66EE0 800CF6E0 21104002 */  addu       $v0, $s2, $zero
    /* 66EE4 800CF6E4 09F84000 */  jalr       $v0
    /* 66EE8 800CF6E8 080000AE */   sw        $zero, 0x8($s0)
    /* 66EEC 800CF6EC 21100002 */  addu       $v0, $s0, $zero
    /* 66EF0 800CF6F0 2000BF8F */  lw         $ra, 0x20($sp)
    /* 66EF4 800CF6F4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 66EF8 800CF6F8 1800B28F */  lw         $s2, 0x18($sp)
    /* 66EFC 800CF6FC 1400B18F */  lw         $s1, 0x14($sp)
    /* 66F00 800CF700 1000B08F */  lw         $s0, 0x10($sp)
    /* 66F04 800CF704 0800E003 */  jr         $ra
    /* 66F08 800CF708 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800CF694
