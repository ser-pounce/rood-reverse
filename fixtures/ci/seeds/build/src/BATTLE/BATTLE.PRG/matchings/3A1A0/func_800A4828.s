nonmatching func_800A4828, 0xA4

glabel func_800A4828
    /* 3C028 800A4828 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 3C02C 800A482C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3C030 800A4830 2198A000 */  addu       $s3, $a1, $zero
    /* 3C034 800A4834 80180400 */  sll        $v1, $a0, 2
    /* 3C038 800A4838 21206002 */  addu       $a0, $s3, $zero
    /* 3C03C 800A483C 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 3C040 800A4840 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 3C044 800A4844 21186200 */  addu       $v1, $v1, $v0
    /* 3C048 800A4848 2000BFAF */  sw         $ra, 0x20($sp)
    /* 3C04C 800A484C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3C050 800A4850 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3C054 800A4854 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3C058 800A4858 0000718C */  lw         $s1, 0x0($v1)
    /* 3C05C 800A485C 01000224 */  addiu      $v0, $zero, 0x1
    /* 3C060 800A4860 0800308E */  lw         $s0, 0x8($s1)
    /* 3C064 800A4864 FDFF1224 */  addiu      $s2, $zero, -0x3
    /* 3C068 800A4868 B20522A2 */  sb         $v0, 0x5B2($s1)
    /* 3C06C 800A486C 24101202 */  and        $v0, $s0, $s2
    /* 3C070 800A4870 42801000 */  srl        $s0, $s0, 1
    /* 3C074 800A4874 01001032 */  andi       $s0, $s0, 0x1
    /* 3C078 800A4878 28BB020C */  jal        func_800AECA0
    /* 3C07C 800A487C 080022AE */   sw        $v0, 0x8($s1)
    /* 3C080 800A4880 BABA020C */  jal        func_800AEAE8
    /* 3C084 800A4884 21202002 */   addu      $a0, $s1, $zero
    /* 3C088 800A4888 21202002 */  addu       $a0, $s1, $zero
    /* 3C08C 800A488C 21286002 */  addu       $a1, $s3, $zero
    /* 3C090 800A4890 2ACA020C */  jal        func_800B28A8
    /* 3C094 800A4894 21300000 */   addu      $a2, $zero, $zero
    /* 3C098 800A4898 0800228E */  lw         $v0, 0x8($s1)
    /* 3C09C 800A489C 40801000 */  sll        $s0, $s0, 1
    /* 3C0A0 800A48A0 24105200 */  and        $v0, $v0, $s2
    /* 3C0A4 800A48A4 25105000 */  or         $v0, $v0, $s0
    /* 3C0A8 800A48A8 080022AE */  sw         $v0, 0x8($s1)
    /* 3C0AC 800A48AC 2000BF8F */  lw         $ra, 0x20($sp)
    /* 3C0B0 800A48B0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3C0B4 800A48B4 1800B28F */  lw         $s2, 0x18($sp)
    /* 3C0B8 800A48B8 1400B18F */  lw         $s1, 0x14($sp)
    /* 3C0BC 800A48BC 1000B08F */  lw         $s0, 0x10($sp)
    /* 3C0C0 800A48C0 2800BD27 */  addiu      $sp, $sp, 0x28
    /* 3C0C4 800A48C4 0800E003 */  jr         $ra
    /* 3C0C8 800A48C8 00000000 */   nop
endlabel func_800A4828
