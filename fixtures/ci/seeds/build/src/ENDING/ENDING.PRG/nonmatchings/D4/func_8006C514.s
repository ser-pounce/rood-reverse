nonmatching func_8006C514, 0xB4

glabel func_8006C514
    /* 3D14 8006C514 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 3D18 8006C518 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3D1C 8006C51C 21908000 */  addu       $s2, $a0, $zero
    /* 3D20 8006C520 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3D24 8006C524 2198A000 */  addu       $s3, $a1, $zero
    /* 3D28 8006C528 2120C000 */  addu       $a0, $a2, $zero
    /* 3D2C 8006C52C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 3D30 8006C530 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3D34 8006C534 02008104 */  bgez       $a0, .L8006C540
    /* 3D38 8006C538 1000B0AF */   sw        $s0, 0x10($sp)
    /* 3D3C 8006C53C 21200000 */  addu       $a0, $zero, $zero
  .L8006C540:
    /* 3D40 8006C540 41008228 */  slti       $v0, $a0, 0x41
    /* 3D44 8006C544 02004014 */  bnez       $v0, .L8006C550
    /* 3D48 8006C548 00000000 */   nop
    /* 3D4C 8006C54C 40000424 */  addiu      $a0, $zero, 0x40
  .L8006C550:
    /* 3D50 8006C550 16008018 */  blez       $a0, .L8006C5AC
    /* 3D54 8006C554 21286002 */   addu      $a1, $s3, $zero
    /* 3D58 8006C558 16000624 */  addiu      $a2, $zero, 0x16
    /* 3D5C 8006C55C 0E80113C */  lui        $s1, %hi(D_800DBA7C)
    /* 3D60 8006C560 7CBA3126 */  addiu      $s1, $s1, %lo(D_800DBA7C)
    /* 3D64 8006C564 0E80103C */  lui        $s0, %hi(D_800DB814)
    /* 3D68 8006C568 14B81026 */  addiu      $s0, $s0, %lo(D_800DB814)
    /* 3D6C 8006C56C B2000292 */  lbu        $v0, 0xB2($s0)
    /* 3D70 8006C570 BA000392 */  lbu        $v1, 0xBA($s0)
    /* 3D74 8006C574 21382002 */  addu       $a3, $s1, $zero
    /* 3D78 8006C578 030024A2 */  sb         $a0, 0x3($s1)
    /* 3D7C 8006C57C 070024A2 */  sb         $a0, 0x7($s1)
    /* 3D80 8006C580 21104300 */  addu       $v0, $v0, $v1
    /* 3D84 8006C584 43100200 */  sra        $v0, $v0, 1
    /* 3D88 8006C588 23904202 */  subu       $s2, $s2, $v0
    /* 3D8C 8006C58C D6B4010C */  jal        func_8006D358
    /* 3D90 8006C590 21204002 */   addu      $a0, $s2, $zero
    /* 3D94 8006C594 21286002 */  addu       $a1, $s3, $zero
    /* 3D98 8006C598 17000624 */  addiu      $a2, $zero, 0x17
    /* 3D9C 8006C59C B2000492 */  lbu        $a0, 0xB2($s0)
    /* 3DA0 8006C5A0 04002726 */  addiu      $a3, $s1, 0x4
    /* 3DA4 8006C5A4 D6B4010C */  jal        func_8006D358
    /* 3DA8 8006C5A8 21204402 */   addu      $a0, $s2, $a0
  .L8006C5AC:
    /* 3DAC 8006C5AC 2000BF8F */  lw         $ra, 0x20($sp)
    /* 3DB0 8006C5B0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3DB4 8006C5B4 1800B28F */  lw         $s2, 0x18($sp)
    /* 3DB8 8006C5B8 1400B18F */  lw         $s1, 0x14($sp)
    /* 3DBC 8006C5BC 1000B08F */  lw         $s0, 0x10($sp)
    /* 3DC0 8006C5C0 0800E003 */  jr         $ra
    /* 3DC4 8006C5C4 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8006C514
