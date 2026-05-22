nonmatching func_8006C5C8, 0x17C

glabel func_8006C5C8
    /* 3DC8 8006C5C8 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 3DCC 8006C5CC 2000B0AF */  sw         $s0, 0x20($sp)
    /* 3DD0 8006C5D0 21808000 */  addu       $s0, $a0, $zero
    /* 3DD4 8006C5D4 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 3DD8 8006C5D8 2198A000 */  addu       $s3, $a1, $zero
    /* 3DDC 8006C5DC 2118C000 */  addu       $v1, $a2, $zero
    /* 3DE0 8006C5E0 3400BFAF */  sw         $ra, 0x34($sp)
    /* 3DE4 8006C5E4 3000B4AF */  sw         $s4, 0x30($sp)
    /* 3DE8 8006C5E8 2800B2AF */  sw         $s2, 0x28($sp)
    /* 3DEC 8006C5EC 02006104 */  bgez       $v1, .L8006C5F8
    /* 3DF0 8006C5F0 2400B1AF */   sw        $s1, 0x24($sp)
    /* 3DF4 8006C5F4 21180000 */  addu       $v1, $zero, $zero
  .L8006C5F8:
    /* 3DF8 8006C5F8 41006228 */  slti       $v0, $v1, 0x41
    /* 3DFC 8006C5FC 02004014 */  bnez       $v0, .L8006C608
    /* 3E00 8006C600 00000000 */   nop
    /* 3E04 8006C604 40000324 */  addiu      $v1, $zero, 0x40
  .L8006C608:
    /* 3E08 8006C608 46006018 */  blez       $v1, .L8006C724
    /* 3E0C 8006C60C 1000A427 */   addiu     $a0, $sp, 0x10
    /* 3E10 8006C610 0780053C */  lui        $a1, %hi(D_800688A4)
    /* 3E14 8006C614 A488A524 */  addiu      $a1, $a1, %lo(D_800688A4)
    /* 3E18 8006C618 21880000 */  addu       $s1, $zero, $zero
    /* 3E1C 8006C61C 0E80023C */  lui        $v0, %hi(D_800DC1F8)
    /* 3E20 8006C620 F8C1468C */  lw         $a2, %lo(D_800DC1F8)($v0)
    /* 3E24 8006C624 0E80023C */  lui        $v0, %hi(D_800DBA88)
    /* 3E28 8006C628 88BA4224 */  addiu      $v0, $v0, %lo(D_800DBA88)
    /* 3E2C 8006C62C 21904000 */  addu       $s2, $v0, $zero
    /* 3E30 8006C630 BD9B000C */  jal        sprintf
    /* 3E34 8006C634 030043A2 */   sb        $v1, 0x3($s2)
    /* 3E38 8006C638 21286002 */  addu       $a1, $s3, $zero
    /* 3E3C 8006C63C 12000624 */  addiu      $a2, $zero, 0x12
    /* 3E40 8006C640 21384002 */  addu       $a3, $s2, $zero
    /* 3E44 8006C644 0E80023C */  lui        $v0, %hi(D_800DB814)
    /* 3E48 8006C648 14B84224 */  addiu      $v0, $v0, %lo(D_800DB814)
    /* 3E4C 8006C64C 21A04000 */  addu       $s4, $v0, $zero
    /* 3E50 8006C650 92004390 */  lbu        $v1, 0x92($v0)
    /* 3E54 8006C654 D2004490 */  lbu        $a0, 0xD2($v0)
    /* 3E58 8006C658 52008292 */  lbu        $v0, 0x52($s4)
    /* 3E5C 8006C65C 21186400 */  addu       $v1, $v1, $a0
    /* 3E60 8006C660 A2008492 */  lbu        $a0, 0xA2($s4)
    /* 3E64 8006C664 40100200 */  sll        $v0, $v0, 1
    /* 3E68 8006C668 21186400 */  addu       $v1, $v1, $a0
    /* 3E6C 8006C66C 21104300 */  addu       $v0, $v0, $v1
    /* 3E70 8006C670 74004224 */  addiu      $v0, $v0, 0x74
    /* 3E74 8006C674 43100200 */  sra        $v0, $v0, 1
    /* 3E78 8006C678 23800202 */  subu       $s0, $s0, $v0
    /* 3E7C 8006C67C C9B3010C */  jal        func_8006CF24
    /* 3E80 8006C680 21200002 */   addu      $a0, $s0, $zero
    /* 3E84 8006C684 07006526 */  addiu      $a1, $s3, 0x7
    /* 3E88 8006C688 1A000624 */  addiu      $a2, $zero, 0x1A
    /* 3E8C 8006C68C 92008292 */  lbu        $v0, 0x92($s4)
    /* 3E90 8006C690 21384002 */  addu       $a3, $s2, $zero
    /* 3E94 8006C694 21800202 */  addu       $s0, $s0, $v0
    /* 3E98 8006C698 C9B3010C */  jal        func_8006CF24
    /* 3E9C 8006C69C 21200002 */   addu      $a0, $s0, $zero
    /* 3EA0 8006C6A0 D2008392 */  lbu        $v1, 0xD2($s4)
    /* 3EA4 8006C6A4 02000226 */  addiu      $v0, $s0, 0x2
    /* 3EA8 8006C6A8 21804300 */  addu       $s0, $v0, $v1
    /* 3EAC 8006C6AC 21200002 */  addu       $a0, $s0, $zero
  .L8006C6B0:
    /* 3EB0 8006C6B0 03006526 */  addiu      $a1, $s3, 0x3
    /* 3EB4 8006C6B4 2110B103 */  addu       $v0, $sp, $s1
    /* 3EB8 8006C6B8 10004690 */  lbu        $a2, 0x10($v0)
    /* 3EBC 8006C6BC 21384002 */  addu       $a3, $s2, $zero
    /* 3EC0 8006C6C0 C9B3010C */  jal        func_8006CF24
    /* 3EC4 8006C6C4 D0FFC624 */   addiu     $a2, $a2, -0x30
    /* 3EC8 8006C6C8 02000224 */  addiu      $v0, $zero, 0x2
    /* 3ECC 8006C6CC 04002212 */  beq        $s1, $v0, .L8006C6E0
    /* 3ED0 8006C6D0 0C001026 */   addiu     $s0, $s0, 0xC
    /* 3ED4 8006C6D4 05000224 */  addiu      $v0, $zero, 0x5
    /* 3ED8 8006C6D8 09002216 */  bne        $s1, $v0, .L8006C700
    /* 3EDC 8006C6DC 00000000 */   nop
  .L8006C6E0:
    /* 3EE0 8006C6E0 21200002 */  addu       $a0, $s0, $zero
    /* 3EE4 8006C6E4 0E006526 */  addiu      $a1, $s3, 0xE
    /* 3EE8 8006C6E8 0A000624 */  addiu      $a2, $zero, 0xA
    /* 3EEC 8006C6EC C9B3010C */  jal        func_8006CF24
    /* 3EF0 8006C6F0 21384002 */   addu      $a3, $s2, $zero
    /* 3EF4 8006C6F4 52008392 */  lbu        $v1, 0x52($s4)
    /* 3EF8 8006C6F8 03000226 */  addiu      $v0, $s0, 0x3
    /* 3EFC 8006C6FC 21804300 */  addu       $s0, $v0, $v1
  .L8006C700:
    /* 3F00 8006C700 01003126 */  addiu      $s1, $s1, 0x1
    /* 3F04 8006C704 0900222A */  slti       $v0, $s1, 0x9
    /* 3F08 8006C708 E9FF4014 */  bnez       $v0, .L8006C6B0
    /* 3F0C 8006C70C 21200002 */   addu      $a0, $s0, $zero
    /* 3F10 8006C710 08006526 */  addiu      $a1, $s3, 0x8
    /* 3F14 8006C714 14000624 */  addiu      $a2, $zero, 0x14
    /* 3F18 8006C718 0E80073C */  lui        $a3, %hi(D_800DBA88)
    /* 3F1C 8006C71C C9B3010C */  jal        func_8006CF24
    /* 3F20 8006C720 88BAE724 */   addiu     $a3, $a3, %lo(D_800DBA88)
  .L8006C724:
    /* 3F24 8006C724 3400BF8F */  lw         $ra, 0x34($sp)
    /* 3F28 8006C728 3000B48F */  lw         $s4, 0x30($sp)
    /* 3F2C 8006C72C 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 3F30 8006C730 2800B28F */  lw         $s2, 0x28($sp)
    /* 3F34 8006C734 2400B18F */  lw         $s1, 0x24($sp)
    /* 3F38 8006C738 2000B08F */  lw         $s0, 0x20($sp)
    /* 3F3C 8006C73C 0800E003 */  jr         $ra
    /* 3F40 8006C740 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8006C5C8
