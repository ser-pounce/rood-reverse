nonmatching func_800C2368, 0x1D4

glabel func_800C2368
    /* 59B68 800C2368 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 59B6C 800C236C 3800BEAF */  sw         $fp, 0x38($sp)
    /* 59B70 800C2370 21F0C000 */  addu       $fp, $a2, $zero
    /* 59B74 800C2374 801F073C */  lui        $a3, (0x1F800398 >> 16)
    /* 59B78 800C2378 9803E734 */  ori        $a3, $a3, (0x1F800398 & 0xFFFF)
    /* 59B7C 800C237C 3400B7AF */  sw         $s7, 0x34($sp)
    /* 59B80 800C2380 21B80000 */  addu       $s7, $zero, $zero
    /* 59B84 800C2384 0F80023C */  lui        $v0, %hi(D_800EB9B8)
    /* 59B88 800C2388 C0181E00 */  sll        $v1, $fp, 3
    /* 59B8C 800C238C B8B9428C */  lw         $v0, %lo(D_800EB9B8)($v0)
    /* 59B90 800C2390 48006324 */  addiu      $v1, $v1, 0x48
    /* 59B94 800C2394 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 59B98 800C2398 3000B6AF */  sw         $s6, 0x30($sp)
    /* 59B9C 800C239C 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 59BA0 800C23A0 2800B4AF */  sw         $s4, 0x28($sp)
    /* 59BA4 800C23A4 2400B3AF */  sw         $s3, 0x24($sp)
    /* 59BA8 800C23A8 2000B2AF */  sw         $s2, 0x20($sp)
    /* 59BAC 800C23AC 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 59BB0 800C23B0 1800B0AF */  sw         $s0, 0x18($sp)
    /* 59BB4 800C23B4 4000A4AF */  sw         $a0, 0x40($sp)
    /* 59BB8 800C23B8 4400A5AF */  sw         $a1, 0x44($sp)
    /* 59BBC 800C23BC 1000A7AF */  sw         $a3, 0x10($sp)
    /* 59BC0 800C23C0 21B04300 */  addu       $s6, $v0, $v1
  .L800C23C4:
    /* 59BC4 800C23C4 21A80000 */  addu       $s5, $zero, $zero
    /* 59BC8 800C23C8 21A0A002 */  addu       $s4, $s5, $zero
    /* 59BCC 800C23CC 2198A002 */  addu       $s3, $s5, $zero
    /* 59BD0 800C23D0 2188A002 */  addu       $s1, $s5, $zero
    /* 59BD4 800C23D4 4000A88F */  lw         $t0, 0x40($sp)
    /* 59BD8 800C23D8 4400A78F */  lw         $a3, 0x44($sp)
    /* 59BDC 800C23DC 80100800 */  sll        $v0, $t0, 2
    /* 59BE0 800C23E0 1E00E004 */  bltz       $a3, .L800C245C
    /* 59BE4 800C23E4 2390E202 */   subu      $s2, $s7, $v0
    /* 59BE8 800C23E8 0600D026 */  addiu      $s0, $s6, 0x6
  .L800C23EC:
    /* 59BEC 800C23EC C903010C */  jal        rcos
    /* 59BF0 800C23F0 21204002 */   addu      $a0, $s2, $zero
    /* 59BF4 800C23F4 1800A202 */  mult       $s5, $v0
    /* 59BF8 800C23F8 21204002 */  addu       $a0, $s2, $zero
    /* 59BFC 800C23FC 12380000 */  mflo       $a3
    /* 59C00 800C2400 03130700 */  sra        $v0, $a3, 12
    /* 59C04 800C2404 0000C2A6 */  sh         $v0, 0x0($s6)
    /* 59C08 800C2408 CA03010C */  jal        rsin
    /* 59C0C 800C240C FCFF14A6 */   sh        $s4, -0x4($s0)
    /* 59C10 800C2410 18006202 */  mult       $s3, $v0
    /* 59C14 800C2414 0002B526 */  addiu      $s5, $s5, 0x200
    /* 59C18 800C2418 2B181100 */  sltu       $v1, $zero, $s1
    /* 59C1C 800C241C 00FE9426 */  addiu      $s4, $s4, -0x200
    /* 59C20 800C2420 00027326 */  addiu      $s3, $s3, 0x200
    /* 59C24 800C2424 0100DE27 */  addiu      $fp, $fp, 0x1
    /* 59C28 800C2428 01003126 */  addiu      $s1, $s1, 0x1
    /* 59C2C 800C242C 4000A78F */  lw         $a3, 0x40($sp)
    /* 59C30 800C2430 0800D626 */  addiu      $s6, $s6, 0x8
    /* 59C34 800C2434 000003A6 */  sh         $v1, 0x0($s0)
    /* 59C38 800C2438 21904702 */  addu       $s2, $s2, $a3
    /* 59C3C 800C243C 12400000 */  mflo       $t0
    /* 59C40 800C2440 03130800 */  sra        $v0, $t0, 12
    /* 59C44 800C2444 FEFF02A6 */  sh         $v0, -0x2($s0)
    /* 59C48 800C2448 4400A78F */  lw         $a3, 0x44($sp)
    /* 59C4C 800C244C 00000000 */  nop
    /* 59C50 800C2450 2A10F100 */  slt        $v0, $a3, $s1
    /* 59C54 800C2454 E5FF4010 */  beqz       $v0, .L800C23EC
    /* 59C58 800C2458 08001026 */   addiu     $s0, $s0, 0x8
  .L800C245C:
    /* 59C5C 800C245C 0004F726 */  addiu      $s7, $s7, 0x400
    /* 59C60 800C2460 0010E22A */  slti       $v0, $s7, 0x1000
    /* 59C64 800C2464 D7FF4014 */  bnez       $v0, .L800C23C4
    /* 59C68 800C2468 08000324 */   addiu     $v1, $zero, 0x8
    /* 59C6C 800C246C 4400A88F */  lw         $t0, 0x44($sp)
    /* 59C70 800C2470 1000A78F */  lw         $a3, 0x10($sp)
    /* 59C74 800C2474 40420800 */  sll        $t0, $t0, 9
    /* 59C78 800C2478 1000E224 */  addiu      $v0, $a3, 0x10
    /* 59C7C 800C247C 4400A8AF */  sw         $t0, 0x44($sp)
  .L800C2480:
    /* 59C80 800C2480 000040A4 */  sh         $zero, 0x0($v0)
    /* 59C84 800C2484 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 59C88 800C2488 FDFF6104 */  bgez       $v1, .L800C2480
    /* 59C8C 800C248C FEFF4224 */   addiu     $v0, $v0, -0x2
    /* 59C90 800C2490 2128C003 */  addu       $a1, $fp, $zero
    /* 59C94 800C2494 4000A88F */  lw         $t0, 0x40($sp)
    /* 59C98 800C2498 4400A78F */  lw         $a3, 0x44($sp)
    /* 59C9C 800C249C C0200800 */  sll        $a0, $t0, 3
    /* 59CA0 800C24A0 23208800 */  subu       $a0, $a0, $t0
    /* 59CA4 800C24A4 1000A88F */  lw         $t0, 0x10($sp)
    /* 59CA8 800C24A8 23100700 */  negu       $v0, $a3
    /* 59CAC 800C24AC 020002A5 */  sh         $v0, 0x2($t0)
    /* 59CB0 800C24B0 4400A797 */  lhu        $a3, 0x44($sp)
    /* 59CB4 800C24B4 00000000 */  nop
    /* 59CB8 800C24B8 060007A5 */  sh         $a3, 0x6($t0)
    /* 59CBC 800C24BC 4400A797 */  lhu        $a3, 0x44($sp)
    /* 59CC0 800C24C0 9508030C */  jal        func_800C2254
    /* 59CC4 800C24C4 100007A5 */   sh        $a3, 0x10($t0)
    /* 59CC8 800C24C8 4400A88F */  lw         $t0, 0x44($sp)
    /* 59CCC 800C24CC 21F04000 */  addu       $fp, $v0, $zero
    /* 59CD0 800C24D0 05000229 */  slti       $v0, $t0, 0x5
    /* 59CD4 800C24D4 0D004014 */  bnez       $v0, .L800C250C
    /* 59CD8 800C24D8 2110C003 */   addu      $v0, $fp, $zero
    /* 59CDC 800C24DC 2128C003 */  addu       $a1, $fp, $zero
    /* 59CE0 800C24E0 00F80224 */  addiu      $v0, $zero, -0x800
    /* 59CE4 800C24E4 4000A78F */  lw         $a3, 0x40($sp)
    /* 59CE8 800C24E8 1000A88F */  lw         $t0, 0x10($sp)
    /* 59CEC 800C24EC 80200700 */  sll        $a0, $a3, 2
    /* 59CF0 800C24F0 020002A5 */  sh         $v0, 0x2($t0)
    /* 59CF4 800C24F4 00080224 */  addiu      $v0, $zero, 0x800
    /* 59CF8 800C24F8 060002A5 */  sh         $v0, 0x6($t0)
    /* 59CFC 800C24FC 9508030C */  jal        func_800C2254
    /* 59D00 800C2500 100002A5 */   sh        $v0, 0x10($t0)
    /* 59D04 800C2504 21F04000 */  addu       $fp, $v0, $zero
    /* 59D08 800C2508 2110C003 */  addu       $v0, $fp, $zero
  .L800C250C:
    /* 59D0C 800C250C 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 59D10 800C2510 3800BE8F */  lw         $fp, 0x38($sp)
    /* 59D14 800C2514 3400B78F */  lw         $s7, 0x34($sp)
    /* 59D18 800C2518 3000B68F */  lw         $s6, 0x30($sp)
    /* 59D1C 800C251C 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 59D20 800C2520 2800B48F */  lw         $s4, 0x28($sp)
    /* 59D24 800C2524 2400B38F */  lw         $s3, 0x24($sp)
    /* 59D28 800C2528 2000B28F */  lw         $s2, 0x20($sp)
    /* 59D2C 800C252C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 59D30 800C2530 1800B08F */  lw         $s0, 0x18($sp)
    /* 59D34 800C2534 0800E003 */  jr         $ra
    /* 59D38 800C2538 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_800C2368
