nonmatching func_8006C9A8, 0x14C

glabel func_8006C9A8
    /* 41A8 8006C9A8 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 41AC 8006C9AC 2000B2AF */  sw         $s2, 0x20($sp)
    /* 41B0 8006C9B0 21908000 */  addu       $s2, $a0, $zero
    /* 41B4 8006C9B4 2800B4AF */  sw         $s4, 0x28($sp)
    /* 41B8 8006C9B8 21A0A000 */  addu       $s4, $a1, $zero
    /* 41BC 8006C9BC 2118C000 */  addu       $v1, $a2, $zero
    /* 41C0 8006C9C0 3400BFAF */  sw         $ra, 0x34($sp)
    /* 41C4 8006C9C4 3000B6AF */  sw         $s6, 0x30($sp)
    /* 41C8 8006C9C8 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 41CC 8006C9CC 2400B3AF */  sw         $s3, 0x24($sp)
    /* 41D0 8006C9D0 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 41D4 8006C9D4 02006104 */  bgez       $v1, .L8006C9E0
    /* 41D8 8006C9D8 1800B0AF */   sw        $s0, 0x18($sp)
    /* 41DC 8006C9DC 21180000 */  addu       $v1, $zero, $zero
  .L8006C9E0:
    /* 41E0 8006C9E0 41006228 */  slti       $v0, $v1, 0x41
    /* 41E4 8006C9E4 02004014 */  bnez       $v0, .L8006C9F0
    /* 41E8 8006C9E8 00000000 */   nop
    /* 41EC 8006C9EC 40000324 */  addiu      $v1, $zero, 0x40
  .L8006C9F0:
    /* 41F0 8006C9F0 36006018 */  blez       $v1, .L8006CACC
    /* 41F4 8006C9F4 1000A427 */   addiu     $a0, $sp, 0x10
    /* 41F8 8006C9F8 0780053C */  lui        $a1, %hi(D_800688AC)
    /* 41FC 8006C9FC AC88A524 */  addiu      $a1, $a1, %lo(D_800688AC)
    /* 4200 8006CA00 21980000 */  addu       $s3, $zero, $zero
    /* 4204 8006CA04 21B08000 */  addu       $s6, $a0, $zero
    /* 4208 8006CA08 0E80023C */  lui        $v0, %hi(D_800DBA98)
    /* 420C 8006CA0C 21A84000 */  addu       $s5, $v0, $zero
    /* 4210 8006CA10 0E80023C */  lui        $v0, %hi(D_800DC1FC)
    /* 4214 8006CA14 FCC1468C */  lw         $a2, %lo(D_800DC1FC)($v0)
    /* 4218 8006CA18 98BAB126 */  addiu      $s1, $s5, %lo(D_800DBA98)
    /* 421C 8006CA1C BD9B000C */  jal        sprintf
    /* 4220 8006CA20 030023A2 */   sb        $v1, 0x3($s1)
    /* 4224 8006CA24 21288002 */  addu       $a1, $s4, $zero
    /* 4228 8006CA28 15000624 */  addiu      $a2, $zero, 0x15
    /* 422C 8006CA2C 21382002 */  addu       $a3, $s1, $zero
    /* 4230 8006CA30 0E80103C */  lui        $s0, %hi(D_800DB814)
    /* 4234 8006CA34 14B81026 */  addiu      $s0, $s0, %lo(D_800DB814)
    /* 4238 8006CA38 AA000292 */  lbu        $v0, 0xAA($s0)
    /* 423C 8006CA3C D2000392 */  lbu        $v1, 0xD2($s0)
    /* 4240 8006CA40 9A000492 */  lbu        $a0, 0x9A($s0)
    /* 4244 8006CA44 21104300 */  addu       $v0, $v0, $v1
    /* 4248 8006CA48 21104400 */  addu       $v0, $v0, $a0
    /* 424C 8006CA4C 26004224 */  addiu      $v0, $v0, 0x26
    /* 4250 8006CA50 43100200 */  sra        $v0, $v0, 1
    /* 4254 8006CA54 23904202 */  subu       $s2, $s2, $v0
    /* 4258 8006CA58 C9B3010C */  jal        func_8006CF24
    /* 425C 8006CA5C 21204002 */   addu      $a0, $s2, $zero
    /* 4260 8006CA60 07008526 */  addiu      $a1, $s4, 0x7
    /* 4264 8006CA64 1A000624 */  addiu      $a2, $zero, 0x1A
    /* 4268 8006CA68 AA000292 */  lbu        $v0, 0xAA($s0)
    /* 426C 8006CA6C 21382002 */  addu       $a3, $s1, $zero
    /* 4270 8006CA70 21904202 */  addu       $s2, $s2, $v0
    /* 4274 8006CA74 C9B3010C */  jal        func_8006CF24
    /* 4278 8006CA78 21204002 */   addu      $a0, $s2, $zero
    /* 427C 8006CA7C D2000392 */  lbu        $v1, 0xD2($s0)
    /* 4280 8006CA80 02004226 */  addiu      $v0, $s2, 0x2
    /* 4284 8006CA84 21904300 */  addu       $s2, $v0, $v1
  .L8006CA88:
    /* 4288 8006CA88 21204002 */  addu       $a0, $s2, $zero
    /* 428C 8006CA8C 03008526 */  addiu      $a1, $s4, 0x3
    /* 4290 8006CA90 98BAA726 */  addiu      $a3, $s5, %lo(D_800DBA98)
    /* 4294 8006CA94 2110D302 */  addu       $v0, $s6, $s3
    /* 4298 8006CA98 00004690 */  lbu        $a2, 0x0($v0)
    /* 429C 8006CA9C 01007326 */  addiu      $s3, $s3, 0x1
    /* 42A0 8006CAA0 C9B3010C */  jal        func_8006CF24
    /* 42A4 8006CAA4 D0FFC624 */   addiu     $a2, $a2, -0x30
    /* 42A8 8006CAA8 0300622A */  slti       $v0, $s3, 0x3
    /* 42AC 8006CAAC F6FF4014 */  bnez       $v0, .L8006CA88
    /* 42B0 8006CAB0 0C005226 */   addiu     $s2, $s2, 0xC
    /* 42B4 8006CAB4 21204002 */  addu       $a0, $s2, $zero
    /* 42B8 8006CAB8 08008526 */  addiu      $a1, $s4, 0x8
    /* 42BC 8006CABC 13000624 */  addiu      $a2, $zero, 0x13
    /* 42C0 8006CAC0 0E80073C */  lui        $a3, %hi(D_800DBA98)
    /* 42C4 8006CAC4 C9B3010C */  jal        func_8006CF24
    /* 42C8 8006CAC8 98BAE724 */   addiu     $a3, $a3, %lo(D_800DBA98)
  .L8006CACC:
    /* 42CC 8006CACC 3400BF8F */  lw         $ra, 0x34($sp)
    /* 42D0 8006CAD0 3000B68F */  lw         $s6, 0x30($sp)
    /* 42D4 8006CAD4 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 42D8 8006CAD8 2800B48F */  lw         $s4, 0x28($sp)
    /* 42DC 8006CADC 2400B38F */  lw         $s3, 0x24($sp)
    /* 42E0 8006CAE0 2000B28F */  lw         $s2, 0x20($sp)
    /* 42E4 8006CAE4 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 42E8 8006CAE8 1800B08F */  lw         $s0, 0x18($sp)
    /* 42EC 8006CAEC 0800E003 */  jr         $ra
    /* 42F0 8006CAF0 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8006C9A8
