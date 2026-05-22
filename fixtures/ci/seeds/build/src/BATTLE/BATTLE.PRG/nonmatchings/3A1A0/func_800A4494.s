nonmatching func_800A4494, 0x210

glabel func_800A4494
    /* 3BC94 800A4494 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 3BC98 800A4498 2800B6AF */  sw         $s6, 0x28($sp)
    /* 3BC9C 800A449C 21B08000 */  addu       $s6, $a0, $zero
    /* 3BCA0 800A44A0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3BCA4 800A44A4 2198A000 */  addu       $s3, $a1, $zero
    /* 3BCA8 800A44A8 2400B5AF */  sw         $s5, 0x24($sp)
    /* 3BCAC 800A44AC 21A80000 */  addu       $s5, $zero, $zero
    /* 3BCB0 800A44B0 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 3BCB4 800A44B4 2000B4AF */  sw         $s4, 0x20($sp)
    /* 3BCB8 800A44B8 38455424 */  addiu      $s4, $v0, %lo(D_800F4538)
    /* 3BCBC 800A44BC 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 3BCC0 800A44C0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3BCC4 800A44C4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3BCC8 800A44C8 1000B0AF */  sw         $s0, 0x10($sp)
  .L800A44CC:
    /* 3BCCC 800A44CC 0000928E */  lw         $s2, 0x0($s4)
    /* 3BCD0 800A44D0 00000000 */  nop
    /* 3BCD4 800A44D4 63004012 */  beqz       $s2, .L800A4664
    /* 3BCD8 800A44D8 00000000 */   nop
    /* 3BCDC 800A44DC 0800478E */  lw         $a3, 0x8($s2)
    /* 3BCE0 800A44E0 00000000 */  nop
    /* 3BCE4 800A44E4 0100E230 */  andi       $v0, $a3, 0x1
    /* 3BCE8 800A44E8 5E004014 */  bnez       $v0, .L800A4664
    /* 3BCEC 800A44EC 00000000 */   nop
    /* 3BCF0 800A44F0 0C004292 */  lbu        $v0, 0xC($s2)
    /* 3BCF4 800A44F4 00000000 */  nop
    /* 3BCF8 800A44F8 0F004230 */  andi       $v0, $v0, 0xF
    /* 3BCFC 800A44FC 34005614 */  bne        $v0, $s6, .L800A45D0
    /* 3BD00 800A4500 1800023C */   lui       $v0, (0x180000 >> 16)
    /* 3BD04 800A4504 2410E200 */  and        $v0, $a3, $v0
    /* 3BD08 800A4508 1000033C */  lui        $v1, (0x100000 >> 16)
    /* 3BD0C 800A450C 55004314 */  bne        $v0, $v1, .L800A4664
    /* 3BD10 800A4510 21204002 */   addu      $a0, $s2, $zero
    /* 3BD14 800A4514 00007186 */  lh         $s1, 0x0($s3)
    /* 3BD18 800A4518 EC174286 */  lh         $v0, 0x17EC($s2)
    /* 3BD1C 800A451C 04007086 */  lh         $s0, 0x4($s3)
    /* 3BD20 800A4520 23882202 */  subu       $s1, $s1, $v0
    /* 3BD24 800A4524 1C004296 */  lhu        $v0, 0x1C($s2)
    /* 3BD28 800A4528 F0174386 */  lh         $v1, 0x17F0($s2)
    /* 3BD2C 800A452C 21105100 */  addu       $v0, $v0, $s1
    /* 3BD30 800A4530 1C0042A6 */  sh         $v0, 0x1C($s2)
    /* 3BD34 800A4534 20004296 */  lhu        $v0, 0x20($s2)
    /* 3BD38 800A4538 23800302 */  subu       $s0, $s0, $v1
    /* 3BD3C 800A453C 21105000 */  addu       $v0, $v0, $s0
    /* 3BD40 800A4540 A991020C */  jal        func_800A46A4
    /* 3BD44 800A4544 200042A6 */   sh        $v0, 0x20($s2)
    /* 3BD48 800A4548 1C004396 */  lhu        $v1, 0x1C($s2)
    /* 3BD4C 800A454C 20004496 */  lhu        $a0, 0x20($s2)
    /* 3BD50 800A4550 23187100 */  subu       $v1, $v1, $s1
    /* 3BD54 800A4554 23209000 */  subu       $a0, $a0, $s0
    /* 3BD58 800A4558 1C0043A6 */  sh         $v1, 0x1C($s2)
    /* 3BD5C 800A455C 41004010 */  beqz       $v0, .L800A4664
    /* 3BD60 800A4560 200044A6 */   sh        $a0, 0x20($s2)
    /* 3BD64 800A4564 F8FF053C */  lui        $a1, (0xFFF8FFFF >> 16)
  .L800A4568:
    /* 3BD68 800A4568 FFFFA534 */  ori        $a1, $a1, (0xFFF8FFFF & 0xFFFF)
    /* 3BD6C 800A456C E7FF063C */  lui        $a2, (0xFFE7FFFF >> 16)
    /* 3BD70 800A4570 FFFFC634 */  ori        $a2, $a2, (0xFFE7FFFF & 0xFFFF)
    /* 3BD74 800A4574 21204002 */  addu       $a0, $s2, $zero
    /* 3BD78 800A4578 0800838C */  lw         $v1, 0x8($a0)
    /* 3BD7C 800A457C 03000224 */  addiu      $v0, $zero, 0x3
    /* 3BD80 800A4580 360082A4 */  sh         $v0, 0x36($a0)
    /* 3BD84 800A4584 0300023C */  lui        $v0, (0x30000 >> 16)
    /* 3BD88 800A4588 340080A4 */  sh         $zero, 0x34($a0)
    /* 3BD8C 800A458C 380080A4 */  sh         $zero, 0x38($a0)
    /* 3BD90 800A4590 EE0680A0 */  sb         $zero, 0x6EE($a0)
    /* 3BD94 800A4594 EF0680A0 */  sb         $zero, 0x6EF($a0)
    /* 3BD98 800A4598 24186500 */  and        $v1, $v1, $a1
    /* 3BD9C 800A459C 25186200 */  or         $v1, $v1, $v0
    /* 3BDA0 800A45A0 24186600 */  and        $v1, $v1, $a2
    /* 3BDA4 800A45A4 FFBF0224 */  addiu      $v0, $zero, -0x4001
    /* 3BDA8 800A45A8 24186200 */  and        $v1, $v1, $v0
    /* 3BDAC 800A45AC 080083AC */  sw         $v1, 0x8($a0)
    /* 3BDB0 800A45B0 F0FF0324 */  addiu      $v1, $zero, -0x10
    /* 3BDB4 800A45B4 0C00828C */  lw         $v0, 0xC($a0)
    /* 3BDB8 800A45B8 02000524 */  addiu      $a1, $zero, 0x2
    /* 3BDBC 800A45BC 24104300 */  and        $v0, $v0, $v1
    /* 3BDC0 800A45C0 A292020C */  jal        func_800A4A88
    /* 3BDC4 800A45C4 0C0082AC */   sw        $v0, 0xC($a0)
    /* 3BDC8 800A45C8 9E910208 */  j          .L800A4678
    /* 3BDCC 800A45CC 01000224 */   addiu     $v0, $zero, 0x1
  .L800A45D0:
    /* 3BDD0 800A45D0 3C064696 */  lhu        $a2, 0x63C($s2)
    /* 3BDD4 800A45D4 00006486 */  lh         $a0, 0x0($s3)
    /* 3BDD8 800A45D8 1C004586 */  lh         $a1, 0x1C($s2)
    /* 3BDDC 800A45DC 40008224 */  addiu      $v0, $a0, 0x40
    /* 3BDE0 800A45E0 2318A600 */  subu       $v1, $a1, $a2
    /* 3BDE4 800A45E4 2A104300 */  slt        $v0, $v0, $v1
    /* 3BDE8 800A45E8 1E004014 */  bnez       $v0, .L800A4664
    /* 3BDEC 800A45EC C0FF8324 */   addiu     $v1, $a0, -0x40
    /* 3BDF0 800A45F0 2110A600 */  addu       $v0, $a1, $a2
    /* 3BDF4 800A45F4 2A104300 */  slt        $v0, $v0, $v1
    /* 3BDF8 800A45F8 1A004014 */  bnez       $v0, .L800A4664
    /* 3BDFC 800A45FC 00000000 */   nop
    /* 3BE00 800A4600 04006486 */  lh         $a0, 0x4($s3)
    /* 3BE04 800A4604 20004586 */  lh         $a1, 0x20($s2)
    /* 3BE08 800A4608 40008224 */  addiu      $v0, $a0, 0x40
    /* 3BE0C 800A460C 2318A600 */  subu       $v1, $a1, $a2
    /* 3BE10 800A4610 2A104300 */  slt        $v0, $v0, $v1
    /* 3BE14 800A4614 13004014 */  bnez       $v0, .L800A4664
    /* 3BE18 800A4618 C0FF8324 */   addiu     $v1, $a0, -0x40
    /* 3BE1C 800A461C 2110A600 */  addu       $v0, $a1, $a2
    /* 3BE20 800A4620 2A104300 */  slt        $v0, $v0, $v1
    /* 3BE24 800A4624 0F004014 */  bnez       $v0, .L800A4664
    /* 3BE28 800A4628 00000000 */   nop
    /* 3BE2C 800A462C 1E004486 */  lh         $a0, 0x1E($s2)
    /* 3BE30 800A4630 02006386 */  lh         $v1, 0x2($s3)
    /* 3BE34 800A4634 E0FE8224 */  addiu      $v0, $a0, -0x120
    /* 3BE38 800A4638 2A106200 */  slt        $v0, $v1, $v0
    /* 3BE3C 800A463C 09004014 */  bnez       $v0, .L800A4664
    /* 3BE40 800A4640 2A106400 */   slt       $v0, $v1, $a0
    /* 3BE44 800A4644 07004010 */  beqz       $v0, .L800A4664
    /* 3BE48 800A4648 1800023C */   lui       $v0, (0x180000 >> 16)
    /* 3BE4C 800A464C 2410E200 */  and        $v0, $a3, $v0
    /* 3BE50 800A4650 1000033C */  lui        $v1, (0x100000 >> 16)
    /* 3BE54 800A4654 C4FF4310 */  beq        $v0, $v1, .L800A4568
    /* 3BE58 800A4658 F8FF053C */   lui       $a1, (0xFFF8FFFF >> 16)
    /* 3BE5C 800A465C 9E910208 */  j          .L800A4678
    /* 3BE60 800A4660 01000224 */   addiu     $v0, $zero, 0x1
  .L800A4664:
    /* 3BE64 800A4664 0100B526 */  addiu      $s5, $s5, 0x1
    /* 3BE68 800A4668 1100A22A */  slti       $v0, $s5, 0x11
    /* 3BE6C 800A466C 97FF4014 */  bnez       $v0, .L800A44CC
    /* 3BE70 800A4670 04009426 */   addiu     $s4, $s4, 0x4
    /* 3BE74 800A4674 21100000 */  addu       $v0, $zero, $zero
  .L800A4678:
    /* 3BE78 800A4678 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 3BE7C 800A467C 2800B68F */  lw         $s6, 0x28($sp)
    /* 3BE80 800A4680 2400B58F */  lw         $s5, 0x24($sp)
    /* 3BE84 800A4684 2000B48F */  lw         $s4, 0x20($sp)
    /* 3BE88 800A4688 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3BE8C 800A468C 1800B28F */  lw         $s2, 0x18($sp)
    /* 3BE90 800A4690 1400B18F */  lw         $s1, 0x14($sp)
    /* 3BE94 800A4694 1000B08F */  lw         $s0, 0x10($sp)
    /* 3BE98 800A4698 3000BD27 */  addiu      $sp, $sp, 0x30
    /* 3BE9C 800A469C 0800E003 */  jr         $ra
    /* 3BEA0 800A46A0 00000000 */   nop
endlabel func_800A4494
