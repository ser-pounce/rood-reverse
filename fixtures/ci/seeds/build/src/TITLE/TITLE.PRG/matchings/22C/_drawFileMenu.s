nonmatching _drawFileMenu, 0x49C

glabel _drawFileMenu
    /* 3478 8006BC78 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 347C 8006BC7C 0E80023C */  lui        $v0, %hi(_fileMenuElements)
    /* 3480 8006BC80 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 3484 8006BC84 18EB5124 */  addiu      $s1, $v0, %lo(_fileMenuElements)
    /* 3488 8006BC88 3400B7AF */  sw         $s7, 0x34($sp)
    /* 348C 8006BC8C 21B80000 */  addu       $s7, $zero, $zero
    /* 3490 8006BC90 3800BFAF */  sw         $ra, 0x38($sp)
    /* 3494 8006BC94 3000B6AF */  sw         $s6, 0x30($sp)
    /* 3498 8006BC98 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 349C 8006BC9C 2800B4AF */  sw         $s4, 0x28($sp)
    /* 34A0 8006BCA0 2400B3AF */  sw         $s3, 0x24($sp)
    /* 34A4 8006BCA4 2000B2AF */  sw         $s2, 0x20($sp)
    /* 34A8 8006BCA8 02008010 */  beqz       $a0, .L8006BCB4
    /* 34AC 8006BCAC 1800B0AF */   sw        $s0, 0x18($sp)
    /* 34B0 8006BCB0 40011724 */  addiu      $s7, $zero, 0x140
  .L8006BCB4:
    /* 34B4 8006BCB4 B000043C */  lui        $a0, (0xB00100 >> 16)
    /* 34B8 8006BCB8 00018434 */  ori        $a0, $a0, (0xB00100 & 0xFFFF)
    /* 34BC 8006BCBC F038053C */  lui        $a1, (0x38F0B000 >> 16)
    /* 34C0 8006BCC0 00B0A534 */  ori        $a1, $a1, (0x38F0B000 & 0xFFFF)
    /* 34C4 8006BCC4 4000063C */  lui        $a2, (0x400040 >> 16)
    /* 34C8 8006BCC8 4000C634 */  ori        $a2, $a2, (0x400040 & 0xFFFF)
    /* 34CC 8006BCCC DEA9010C */  jal        _drawSprt
    /* 34D0 8006BCD0 9C000724 */   addiu     $a3, $zero, 0x9C
    /* 34D4 8006BCD4 B000043C */  lui        $a0, (0xB00000 >> 16)
    /* 34D8 8006BCD8 F038053C */  lui        $a1, (0x38F0B000 >> 16)
    /* 34DC 8006BCDC 00B0A534 */  ori        $a1, $a1, (0x38F0B000 & 0xFFFF)
    /* 34E0 8006BCE0 4000063C */  lui        $a2, (0x400100 >> 16)
    /* 34E4 8006BCE4 0001C634 */  ori        $a2, $a2, (0x400100 & 0xFFFF)
    /* 34E8 8006BCE8 DEA9010C */  jal        _drawSprt
    /* 34EC 8006BCEC 9A000724 */   addiu     $a3, $zero, 0x9A
    /* 34F0 8006BCF0 21980000 */  addu       $s3, $zero, $zero
    /* 34F4 8006BCF4 01001424 */  addiu      $s4, $zero, 0x1
    /* 34F8 8006BCF8 0780023C */  lui        $v0, %hi(_menuElementStops)
    /* 34FC 8006BCFC 9C285224 */  addiu      $s2, $v0, %lo(_menuElementStops)
    /* 3500 8006BD00 0C003026 */  addiu      $s0, $s1, 0xC
  .L8006BD04:
    /* 3504 8006BD04 00002892 */  lbu        $t0, 0x0($s1)
    /* 3508 8006BD08 02000224 */  addiu      $v0, $zero, 0x2
    /* 350C 8006BD0C 33000215 */  bne        $t0, $v0, .L8006BDDC
    /* 3510 8006BD10 03000224 */   addiu     $v0, $zero, 0x3
    /* 3514 8006BD14 00000686 */  lh         $a2, 0x0($s0)
    /* 3518 8006BD18 FCFF0586 */  lh         $a1, -0x4($s0)
    /* 351C 8006BD1C 00000496 */  lhu        $a0, 0x0($s0)
    /* 3520 8006BD20 FCFF0396 */  lhu        $v1, -0x4($s0)
    /* 3524 8006BD24 2A10C500 */  slt        $v0, $a2, $a1
    /* 3528 8006BD28 0B004010 */  beqz       $v0, .L8006BD58
    /* 352C 8006BD2C 20008224 */   addiu     $v0, $a0, 0x20
    /* 3530 8006BD30 000002A6 */  sh         $v0, 0x0($s0)
    /* 3534 8006BD34 00140200 */  sll        $v0, $v0, 16
    /* 3538 8006BD38 2118A000 */  addu       $v1, $a1, $zero
    /* 353C 8006BD3C 03140200 */  sra        $v0, $v0, 16
    /* 3540 8006BD40 2A104300 */  slt        $v0, $v0, $v1
    /* 3544 8006BD44 FCFF0396 */  lhu        $v1, -0x4($s0)
    /* 3548 8006BD48 24004014 */  bnez       $v0, .L8006BDDC
    /* 354C 8006BD4C 03000224 */   addiu     $v0, $zero, 0x3
    /* 3550 8006BD50 75AF0108 */  j          .L8006BDD4
    /* 3554 8006BD54 000003A6 */   sh        $v1, 0x0($s0)
  .L8006BD58:
    /* 3558 8006BD58 01000424 */  addiu      $a0, $zero, 0x1
    /* 355C 8006BD5C 2138A000 */  addu       $a3, $a1, $zero
    /* 3560 8006BD60 2128C000 */  addu       $a1, $a2, $zero
    /* 3564 8006BD64 21109200 */  addu       $v0, $a0, $s2
  .L8006BD68:
    /* 3568 8006BD68 00004290 */  lbu        $v0, 0x0($v0)
    /* 356C 8006BD6C 00000000 */  nop
    /* 3570 8006BD70 2110E200 */  addu       $v0, $a3, $v0
    /* 3574 8006BD74 2A104500 */  slt        $v0, $v0, $a1
    /* 3578 8006BD78 05004010 */  beqz       $v0, .L8006BD90
    /* 357C 8006BD7C 21109200 */   addu      $v0, $a0, $s2
    /* 3580 8006BD80 01008424 */  addiu      $a0, $a0, 0x1
    /* 3584 8006BD84 10008228 */  slti       $v0, $a0, 0x10
    /* 3588 8006BD88 F7FF4014 */  bnez       $v0, .L8006BD68
    /* 358C 8006BD8C 21109200 */   addu      $v0, $a0, $s2
  .L8006BD90:
    /* 3590 8006BD90 FFFF4290 */  lbu        $v0, -0x1($v0)
    /* 3594 8006BD94 40010524 */  addiu      $a1, $zero, 0x140
    /* 3598 8006BD98 21206200 */  addu       $a0, $v1, $v0
    /* 359C 8006BD9C 001C0400 */  sll        $v1, $a0, 16
    /* 35A0 8006BDA0 031C0300 */  sra        $v1, $v1, 16
    /* 35A4 8006BDA4 04000286 */  lh         $v0, 0x4($s0)
    /* 35A8 8006BDA8 2318A300 */  subu       $v1, $a1, $v1
    /* 35AC 8006BDAC 2A104300 */  slt        $v0, $v0, $v1
    /* 35B0 8006BDB0 03004010 */  beqz       $v0, .L8006BDC0
    /* 35B4 8006BDB4 000004A6 */   sh        $a0, 0x0($s0)
    /* 35B8 8006BDB8 2310A400 */  subu       $v0, $a1, $a0
    /* 35BC 8006BDBC 040002A6 */  sh         $v0, 0x4($s0)
  .L8006BDC0:
    /* 35C0 8006BDC0 00000386 */  lh         $v1, 0x0($s0)
    /* 35C4 8006BDC4 FCFF0286 */  lh         $v0, -0x4($s0)
    /* 35C8 8006BDC8 00000000 */  nop
    /* 35CC 8006BDCC 03006214 */  bne        $v1, $v0, .L8006BDDC
    /* 35D0 8006BDD0 03000224 */   addiu     $v0, $zero, 0x3
  .L8006BDD4:
    /* 35D4 8006BDD4 000034A2 */  sb         $s4, 0x0($s1)
    /* 35D8 8006BDD8 03000224 */  addiu      $v0, $zero, 0x3
  .L8006BDDC:
    /* 35DC 8006BDDC 1E000215 */  bne        $t0, $v0, .L8006BE58
    /* 35E0 8006BDE0 04000224 */   addiu     $v0, $zero, 0x4
    /* 35E4 8006BDE4 02000686 */  lh         $a2, 0x2($s0)
    /* 35E8 8006BDE8 FCFF0586 */  lh         $a1, -0x4($s0)
    /* 35EC 8006BDEC FCFF0396 */  lhu        $v1, -0x4($s0)
    /* 35F0 8006BDF0 2A10A600 */  slt        $v0, $a1, $a2
    /* 35F4 8006BDF4 12004010 */  beqz       $v0, .L8006BE40
    /* 35F8 8006BDF8 01000424 */   addiu     $a0, $zero, 0x1
    /* 35FC 8006BDFC 21386000 */  addu       $a3, $v1, $zero
    /* 3600 8006BE00 2118C000 */  addu       $v1, $a2, $zero
    /* 3604 8006BE04 21109200 */  addu       $v0, $a0, $s2
  .L8006BE08:
    /* 3608 8006BE08 00004290 */  lbu        $v0, 0x0($v0)
    /* 360C 8006BE0C 00000000 */  nop
    /* 3610 8006BE10 2110A200 */  addu       $v0, $a1, $v0
    /* 3614 8006BE14 2A104300 */  slt        $v0, $v0, $v1
    /* 3618 8006BE18 05004010 */  beqz       $v0, .L8006BE30
    /* 361C 8006BE1C 21109200 */   addu      $v0, $a0, $s2
    /* 3620 8006BE20 01008424 */  addiu      $a0, $a0, 0x1
    /* 3624 8006BE24 10008228 */  slti       $v0, $a0, 0x10
    /* 3628 8006BE28 F7FF4014 */  bnez       $v0, .L8006BE08
    /* 362C 8006BE2C 21109200 */   addu      $v0, $a0, $s2
  .L8006BE30:
    /* 3630 8006BE30 FFFF4290 */  lbu        $v0, -0x1($v0)
    /* 3634 8006BE34 00000000 */  nop
    /* 3638 8006BE38 2110E200 */  addu       $v0, $a3, $v0
    /* 363C 8006BE3C 020002A6 */  sh         $v0, 0x2($s0)
  .L8006BE40:
    /* 3640 8006BE40 02000386 */  lh         $v1, 0x2($s0)
    /* 3644 8006BE44 FCFF0286 */  lh         $v0, -0x4($s0)
    /* 3648 8006BE48 00000000 */  nop
    /* 364C 8006BE4C 02006214 */  bne        $v1, $v0, .L8006BE58
    /* 3650 8006BE50 04000224 */   addiu     $v0, $zero, 0x4
    /* 3654 8006BE54 000034A2 */  sb         $s4, 0x0($s1)
  .L8006BE58:
    /* 3658 8006BE58 25000215 */  bne        $t0, $v0, .L8006BEF0
    /* 365C 8006BE5C 00000000 */   nop
    /* 3660 8006BE60 00000586 */  lh         $a1, 0x0($s0)
    /* 3664 8006BE64 FCFF0286 */  lh         $v0, -0x4($s0)
    /* 3668 8006BE68 00000396 */  lhu        $v1, 0x0($s0)
    /* 366C 8006BE6C 2A10A200 */  slt        $v0, $a1, $v0
    /* 3670 8006BE70 14004010 */  beqz       $v0, .L8006BEC4
    /* 3674 8006BE74 01000424 */   addiu     $a0, $zero, 0x1
    /* 3678 8006BE78 2118A000 */  addu       $v1, $a1, $zero
    /* 367C 8006BE7C 21109200 */  addu       $v0, $a0, $s2
  .L8006BE80:
    /* 3680 8006BE80 00004290 */  lbu        $v0, 0x0($v0)
    /* 3684 8006BE84 00000000 */  nop
    /* 3688 8006BE88 23100200 */  negu       $v0, $v0
    /* 368C 8006BE8C 2A106200 */  slt        $v0, $v1, $v0
    /* 3690 8006BE90 05004010 */  beqz       $v0, .L8006BEA8
    /* 3694 8006BE94 21109200 */   addu      $v0, $a0, $s2
    /* 3698 8006BE98 01008424 */  addiu      $a0, $a0, 0x1
    /* 369C 8006BE9C 10008228 */  slti       $v0, $a0, 0x10
    /* 36A0 8006BEA0 F7FF4014 */  bnez       $v0, .L8006BE80
    /* 36A4 8006BEA4 21109200 */   addu      $v0, $a0, $s2
  .L8006BEA8:
    /* 36A8 8006BEA8 FFFF4290 */  lbu        $v0, -0x1($v0)
    /* 36AC 8006BEAC 00000000 */  nop
    /* 36B0 8006BEB0 23100200 */  negu       $v0, $v0
    /* 36B4 8006BEB4 0E004014 */  bnez       $v0, .L8006BEF0
    /* 36B8 8006BEB8 000002A6 */   sh        $v0, 0x0($s0)
    /* 36BC 8006BEBC BCAF0108 */  j          .L8006BEF0
    /* 36C0 8006BEC0 000034A2 */   sb        $s4, 0x0($s1)
  .L8006BEC4:
    /* 36C4 8006BEC4 E0FF6224 */  addiu      $v0, $v1, -0x20
    /* 36C8 8006BEC8 000002A6 */  sh         $v0, 0x0($s0)
    /* 36CC 8006BECC 00140200 */  sll        $v0, $v0, 16
    /* 36D0 8006BED0 FCFF0386 */  lh         $v1, -0x4($s0)
    /* 36D4 8006BED4 03140200 */  sra        $v0, $v0, 16
    /* 36D8 8006BED8 2A186200 */  slt        $v1, $v1, $v0
    /* 36DC 8006BEDC FCFF0296 */  lhu        $v0, -0x4($s0)
    /* 36E0 8006BEE0 03006014 */  bnez       $v1, .L8006BEF0
    /* 36E4 8006BEE4 00000000 */   nop
    /* 36E8 8006BEE8 000002A6 */  sh         $v0, 0x0($s0)
    /* 36EC 8006BEEC 000034A2 */  sb         $s4, 0x0($s1)
  .L8006BEF0:
    /* 36F0 8006BEF0 03000011 */  beqz       $t0, .L8006BF00
    /* 36F4 8006BEF4 00000000 */   nop
    /* 36F8 8006BEF8 68AD010C */  jal        _drawFileMenuElement
    /* 36FC 8006BEFC 21202002 */   addu      $a0, $s1, $zero
  .L8006BF00:
    /* 3700 8006BF00 01007326 */  addiu      $s3, $s3, 0x1
    /* 3704 8006BF04 34001026 */  addiu      $s0, $s0, 0x34
    /* 3708 8006BF08 0A00622A */  slti       $v0, $s3, 0xA
    /* 370C 8006BF0C 7DFF4014 */  bnez       $v0, .L8006BD04
    /* 3710 8006BF10 34003126 */   addiu     $s1, $s1, 0x34
    /* 3714 8006BF14 01001324 */  addiu      $s3, $zero, 0x1
    /* 3718 8006BF18 BB001624 */  addiu      $s6, $zero, 0xBB
    /* 371C 8006BF1C 82A91700 */  srl        $s5, $s7, 6
    /* 3720 8006BF20 0001E226 */  addiu      $v0, $s7, 0x100
    /* 3724 8006BF24 83A10200 */  sra        $s4, $v0, 6
  .L8006BF28:
    /* 3728 8006BF28 2388D302 */  subu       $s1, $s6, $s3
    /* 372C 8006BF2C 00941100 */  sll        $s2, $s1, 16
    /* 3730 8006BF30 21204002 */  addu       $a0, $s2, $zero
    /* 3734 8006BF34 008A1100 */  sll        $s1, $s1, 8
    /* 3738 8006BF38 21282002 */  addu       $a1, $s1, $zero
    /* 373C 8006BF3C 0100063C */  lui        $a2, (0x10100 >> 16)
    /* 3740 8006BF40 0001C634 */  ori        $a2, $a2, (0x10100 & 0xFFFF)
    /* 3744 8006BF44 04001024 */  addiu      $s0, $zero, 0x4
    /* 3748 8006BF48 23801302 */  subu       $s0, $s0, $s3
    /* 374C 8006BF4C 40851000 */  sll        $s0, $s0, 21
    /* 3750 8006BF50 00011036 */  ori        $s0, $s0, 0x100
    /* 3754 8006BF54 DEA9010C */  jal        _drawSprt
    /* 3758 8006BF58 2538B002 */   or        $a3, $s5, $s0
    /* 375C 8006BF5C 00014436 */  ori        $a0, $s2, 0x100
    /* 3760 8006BF60 21282002 */  addu       $a1, $s1, $zero
    /* 3764 8006BF64 0100063C */  lui        $a2, (0x10040 >> 16)
    /* 3768 8006BF68 4000C634 */  ori        $a2, $a2, (0x10040 & 0xFFFF)
    /* 376C 8006BF6C DEA9010C */  jal        _drawSprt
    /* 3770 8006BF70 25389002 */   or        $a3, $s4, $s0
    /* 3774 8006BF74 01007326 */  addiu      $s3, $s3, 0x1
    /* 3778 8006BF78 0400622A */  slti       $v0, $s3, 0x4
    /* 377C 8006BF7C EAFF4014 */  bnez       $v0, .L8006BF28
    /* 3780 8006BF80 B500043C */   lui       $a0, (0xB5000A >> 16)
    /* 3784 8006BF84 0A008434 */  ori        $a0, $a0, (0xB5000A & 0xFFFF)
    /* 3788 8006BF88 F537053C */  lui        $a1, (0x37F59140 >> 16)
    /* 378C 8006BF8C 4091A534 */  ori        $a1, $a1, (0x37F59140 & 0xFFFF)
    /* 3790 8006BF90 0700063C */  lui        $a2, (0x70021 >> 16)
    /* 3794 8006BF94 2100C634 */  ori        $a2, $a2, (0x70021 & 0xFFFF)
    /* 3798 8006BF98 DEA9010C */  jal        _drawSprt
    /* 379C 8006BF9C 0C000724 */   addiu     $a3, $zero, 0xC
    /* 37A0 8006BFA0 94A1000C */  jal        DrawSync
    /* 37A4 8006BFA4 21200000 */   addu      $a0, $zero, $zero
    /* 37A8 8006BFA8 3400053C */  lui        $a1, (0x340140 >> 16)
    /* 37AC 8006BFAC 4001A534 */  ori        $a1, $a1, (0x340140 & 0xFFFF)
    /* 37B0 8006BFB0 0E80033C */  lui        $v1, %hi(_primBuf)
    /* 37B4 8006BFB4 28ED6424 */  addiu      $a0, $v1, %lo(_primBuf)
    /* 37B8 8006BFB8 0003023C */  lui        $v0, (0x3000000 >> 16)
    /* 37BC 8006BFBC 28ED62AC */  sw         $v0, %lo(_primBuf)($v1)
    /* 37C0 8006BFC0 0060023C */  lui        $v0, (0x60000000 >> 16)
    /* 37C4 8006BFC4 040082AC */  sw         $v0, 0x4($a0)
    /* 37C8 8006BFC8 BB00023C */  lui        $v0, (0xBB0000 >> 16)
    /* 37CC 8006BFCC 080082AC */  sw         $v0, 0x8($a0)
    /* 37D0 8006BFD0 FAA2000C */  jal        DrawPrim
    /* 37D4 8006BFD4 0C0085AC */   sw        $a1, 0xC($a0)
    /* 37D8 8006BFD8 0E80023C */  lui        $v0, %hi(_selectCursorXy)
    /* 37DC 8006BFDC 68ED448C */  lw         $a0, %lo(_selectCursorXy)($v0)
    /* 37E0 8006BFE0 00000000 */  nop
    /* 37E4 8006BFE4 1A008010 */  beqz       $a0, .L8006C050
    /* 37E8 8006BFE8 F837053C */   lui       $a1, (0x37F83020 >> 16)
    /* 37EC 8006BFEC 2030A534 */  ori        $a1, $a1, (0x37F83020 & 0xFFFF)
    /* 37F0 8006BFF0 1000063C */  lui        $a2, (0x100010 >> 16)
    /* 37F4 8006BFF4 0780033C */  lui        $v1, %hi(_cursorFileOpSaturation)
    /* 37F8 8006BFF8 0E80103C */  lui        $s0, %hi(_selectCursorColor)
    /* 37FC 8006BFFC 71ED0292 */  lbu        $v0, %lo(_selectCursorColor)($s0)
    /* 3800 8006C000 B0286324 */  addiu      $v1, $v1, %lo(_cursorFileOpSaturation)
    /* 3804 8006C004 21104300 */  addu       $v0, $v0, $v1
    /* 3808 8006C008 00004780 */  lb         $a3, 0x0($v0)
    /* 380C 8006C00C 1000C634 */  ori        $a2, $a2, (0x100010 & 0xFFFF)
    /* 3810 8006C010 003C0700 */  sll        $a3, $a3, 16
    /* 3814 8006C014 DEA9010C */  jal        _drawSprt
    /* 3818 8006C018 0C00E734 */   ori       $a3, $a3, 0xC
    /* 381C 8006C01C 0680033C */  lui        $v1, %hi(vs_main_buttonsPressed)
    /* 3820 8006C020 71ED0292 */  lbu        $v0, %lo(_selectCursorColor)($s0)
    /* 3824 8006C024 D0E1638C */  lw         $v1, %lo(vs_main_buttonsPressed)($v1)
    /* 3828 8006C028 01004224 */  addiu      $v0, $v0, 0x1
    /* 382C 8006C02C 0F004230 */  andi       $v0, $v0, 0xF
    /* 3830 8006C030 10006330 */  andi       $v1, $v1, 0x10
    /* 3834 8006C034 08006010 */  beqz       $v1, .L8006C058
    /* 3838 8006C038 71ED02A2 */   sb        $v0, %lo(_selectCursorColor)($s0)
    /* 383C 8006C03C 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 3840 8006C040 6216010C */  jal        vs_main_playSfxDefault
    /* 3844 8006C044 07000524 */   addiu     $a1, $zero, 0x7
    /* 3848 8006C048 17B00108 */  j          .L8006C05C
    /* 384C 8006C04C 0E80023C */   lui       $v0, %hi(_selectSaveMemoryCardMessage)
  .L8006C050:
    /* 3850 8006C050 0E80023C */  lui        $v0, %hi(_selectCursorColor)
    /* 3854 8006C054 71ED40A0 */  sb         $zero, %lo(_selectCursorColor)($v0)
  .L8006C058:
    /* 3858 8006C058 0E80023C */  lui        $v0, %hi(_selectSaveMemoryCardMessage)
  .L8006C05C:
    /* 385C 8006C05C 6CED448C */  lw         $a0, %lo(_selectSaveMemoryCardMessage)($v0)
    /* 3860 8006C060 00000000 */  nop
    /* 3864 8006C064 04008010 */  beqz       $a0, .L8006C078
    /* 3868 8006C068 10000524 */   addiu     $a1, $zero, 0x10
    /* 386C 8006C06C C0000624 */  addiu      $a2, $zero, 0xC0
    /* 3870 8006C070 D9AC010C */  jal        _printString
    /* 3874 8006C074 21380000 */   addu      $a3, $zero, $zero
  .L8006C078:
    /* 3878 8006C078 0E80103C */  lui        $s0, %hi(_fileMenuScreenFade)
    /* 387C 8006C07C 72ED0292 */  lbu        $v0, %lo(_fileMenuScreenFade)($s0)
    /* 3880 8006C080 00000000 */  nop
    /* 3884 8006C084 18004010 */  beqz       $v0, .L8006C0E8
    /* 3888 8006C088 00000000 */   nop
    /* 388C 8006C08C 94A1000C */  jal        DrawSync
    /* 3890 8006C090 21200000 */   addu      $a0, $zero, $zero
    /* 3894 8006C094 00E1063C */  lui        $a2, (0xE1000140 >> 16)
    /* 3898 8006C098 4001C634 */  ori        $a2, $a2, (0xE1000140 & 0xFFFF)
    /* 389C 8006C09C E000073C */  lui        $a3, (0xE00140 >> 16)
    /* 38A0 8006C0A0 4001E734 */  ori        $a3, $a3, (0xE00140 & 0xFFFF)
    /* 38A4 8006C0A4 0E80053C */  lui        $a1, %hi(_primBuf)
    /* 38A8 8006C0A8 28EDA424 */  addiu      $a0, $a1, %lo(_primBuf)
    /* 38AC 8006C0AC 72ED0392 */  lbu        $v1, %lo(_fileMenuScreenFade)($s0)
    /* 38B0 8006C0B0 0004023C */  lui        $v0, (0x4000000 >> 16)
    /* 38B4 8006C0B4 28EDA2AC */  sw         $v0, %lo(_primBuf)($a1)
    /* 38B8 8006C0B8 040086AC */  sw         $a2, 0x4($a0)
    /* 38BC 8006C0BC 0C0080AC */  sw         $zero, 0xC($a0)
    /* 38C0 8006C0C0 100087AC */  sw         $a3, 0x10($a0)
    /* 38C4 8006C0C4 00120300 */  sll        $v0, $v1, 8
    /* 38C8 8006C0C8 21104300 */  addu       $v0, $v0, $v1
    /* 38CC 8006C0CC 00120200 */  sll        $v0, $v0, 8
    /* 38D0 8006C0D0 21104300 */  addu       $v0, $v0, $v1
    /* 38D4 8006C0D4 C0100200 */  sll        $v0, $v0, 3
    /* 38D8 8006C0D8 0062033C */  lui        $v1, (0x62000000 >> 16)
    /* 38DC 8006C0DC 25104300 */  or         $v0, $v0, $v1
    /* 38E0 8006C0E0 FAA2000C */  jal        DrawPrim
    /* 38E4 8006C0E4 080082AC */   sw        $v0, 0x8($a0)
  .L8006C0E8:
    /* 38E8 8006C0E8 3800BF8F */  lw         $ra, 0x38($sp)
    /* 38EC 8006C0EC 3400B78F */  lw         $s7, 0x34($sp)
    /* 38F0 8006C0F0 3000B68F */  lw         $s6, 0x30($sp)
    /* 38F4 8006C0F4 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 38F8 8006C0F8 2800B48F */  lw         $s4, 0x28($sp)
    /* 38FC 8006C0FC 2400B38F */  lw         $s3, 0x24($sp)
    /* 3900 8006C100 2000B28F */  lw         $s2, 0x20($sp)
    /* 3904 8006C104 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 3908 8006C108 1800B08F */  lw         $s0, 0x18($sp)
    /* 390C 8006C10C 0800E003 */  jr         $ra
    /* 3910 8006C110 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel _drawFileMenu
