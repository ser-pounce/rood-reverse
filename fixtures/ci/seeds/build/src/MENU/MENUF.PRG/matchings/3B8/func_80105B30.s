nonmatching func_80105B30, 0x104

glabel func_80105B30
    /* 3330 80105B30 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 3334 80105B34 2800B4AF */  sw         $s4, 0x28($sp)
    /* 3338 80105B38 21A08000 */  addu       $s4, $a0, $zero
    /* 333C 80105B3C 2000B2AF */  sw         $s2, 0x20($sp)
    /* 3340 80105B40 2190C000 */  addu       $s2, $a2, $zero
    /* 3344 80105B44 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 3348 80105B48 2188E000 */  addu       $s1, $a3, $zero
    /* 334C 80105B4C 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 3350 80105B50 2400B3AF */  sw         $s3, 0x24($sp)
    /* 3354 80105B54 02002106 */  bgez       $s1, .L80105B60
    /* 3358 80105B58 1800B0AF */   sw        $s0, 0x18($sp)
    /* 335C 80105B5C 21880000 */  addu       $s1, $zero, $zero
  .L80105B60:
    /* 3360 80105B60 4100222A */  slti       $v0, $s1, 0x41
    /* 3364 80105B64 02004014 */  bnez       $v0, .L80105B70
    /* 3368 80105B68 1180023C */   lui       $v0, %hi(D_801098A4)
    /* 336C 80105B6C 40001124 */  addiu      $s1, $zero, 0x40
  .L80105B70:
    /* 3370 80105B70 A498428C */  lw         $v0, %lo(D_801098A4)($v0)
    /* 3374 80105B74 00000000 */  nop
    /* 3378 80105B78 26105200 */  xor        $v0, $v0, $s2
    /* 337C 80105B7C 0100492C */  sltiu      $t1, $v0, 0x1
    /* 3380 80105B80 02002011 */  beqz       $t1, .L80105B8C
    /* 3384 80105B84 F27F1324 */   addiu     $s3, $zero, 0x7FF2
    /* 3388 80105B88 F87F1324 */  addiu      $s3, $zero, 0x7FF8
  .L80105B8C:
    /* 338C 80105B8C FF00083C */  lui        $t0, (0xFFFFFF >> 16)
    /* 3390 80105B90 FFFF0835 */  ori        $t0, $t0, (0xFFFFFF & 0xFFFF)
    /* 3394 80105B94 ACFF8426 */  addiu      $a0, $s4, -0x54
    /* 3398 80105B98 80181200 */  sll        $v1, $s2, 2
    /* 339C 80105B9C 21807200 */  addu       $s0, $v1, $s2
    /* 33A0 80105BA0 80801000 */  sll        $s0, $s0, 2
    /* 33A4 80105BA4 2180B000 */  addu       $s0, $a1, $s0
    /* 33A8 80105BA8 02000526 */  addiu      $a1, $s0, 0x2
    /* 33AC 80105BAC 0680063C */  lui        $a2, %hi(vs_main_scoredata)
    /* 33B0 80105BB0 0680023C */  lui        $v0, %hi(vs_main_stateFlags + 0xC4)
    /* 33B4 80105BB4 5C164790 */  lbu        $a3, %lo(vs_main_stateFlags + 0xC4)($v0)
    /* 33B8 80105BB8 A0FEC624 */  addiu      $a2, $a2, %lo(vs_main_scoredata)
    /* 33BC 80105BBC 40100700 */  sll        $v0, $a3, 1
    /* 33C0 80105BC0 21104700 */  addu       $v0, $v0, $a3
    /* 33C4 80105BC4 80100200 */  sll        $v0, $v0, 2
    /* 33C8 80105BC8 21186200 */  addu       $v1, $v1, $v0
    /* 33CC 80105BCC 21186600 */  addu       $v1, $v1, $a2
    /* 33D0 80105BD0 2800678C */  lw         $a3, 0x28($v1)
    /* 33D4 80105BD4 21302002 */  addu       $a2, $s1, $zero
    /* 33D8 80105BD8 1000A9AF */  sw         $t1, 0x10($sp)
    /* 33DC 80105BDC DB17040C */  jal        func_80105F6C
    /* 33E0 80105BE0 2438E800 */   and       $a3, $a3, $t0
    /* 33E4 80105BE4 21280002 */  addu       $a1, $s0, $zero
    /* 33E8 80105BE8 4B004626 */  addiu      $a2, $s2, 0x4B
    /* 33EC 80105BEC 1180033C */  lui        $v1, %hi(D_801091D8)
    /* 33F0 80105BF0 D8916324 */  addiu      $v1, $v1, %lo(D_801091D8)
    /* 33F4 80105BF4 C0100600 */  sll        $v0, $a2, 3
    /* 33F8 80105BF8 21104300 */  addu       $v0, $v0, $v1
    /* 33FC 80105BFC 02004490 */  lbu        $a0, 0x2($v0)
    /* 3400 80105C00 21382002 */  addu       $a3, $s1, $zero
    /* 3404 80105C04 1000B3AF */  sw         $s3, 0x10($sp)
    /* 3408 80105C08 23208402 */  subu       $a0, $s4, $a0
    /* 340C 80105C0C 7617040C */  jal        func_80105DD8
    /* 3410 80105C10 A8FF8424 */   addiu     $a0, $a0, -0x58
    /* 3414 80105C14 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 3418 80105C18 2800B48F */  lw         $s4, 0x28($sp)
    /* 341C 80105C1C 2400B38F */  lw         $s3, 0x24($sp)
    /* 3420 80105C20 2000B28F */  lw         $s2, 0x20($sp)
    /* 3424 80105C24 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 3428 80105C28 1800B08F */  lw         $s0, 0x18($sp)
    /* 342C 80105C2C 0800E003 */  jr         $ra
    /* 3430 80105C30 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_80105B30
