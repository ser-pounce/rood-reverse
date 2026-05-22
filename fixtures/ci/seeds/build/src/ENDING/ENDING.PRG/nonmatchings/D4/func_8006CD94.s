nonmatching func_8006CD94, 0x190

glabel func_8006CD94
    /* 4594 8006CD94 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 4598 8006CD98 1400B1AF */  sw         $s1, 0x14($sp)
    /* 459C 8006CD9C 21888000 */  addu       $s1, $a0, $zero
    /* 45A0 8006CDA0 2400B5AF */  sw         $s5, 0x24($sp)
    /* 45A4 8006CDA4 21A8A000 */  addu       $s5, $a1, $zero
    /* 45A8 8006CDA8 2800BFAF */  sw         $ra, 0x28($sp)
    /* 45AC 8006CDAC 2000B4AF */  sw         $s4, 0x20($sp)
    /* 45B0 8006CDB0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 45B4 8006CDB4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 45B8 8006CDB8 0200C104 */  bgez       $a2, .L8006CDC4
    /* 45BC 8006CDBC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 45C0 8006CDC0 21300000 */  addu       $a2, $zero, $zero
  .L8006CDC4:
    /* 45C4 8006CDC4 4100C228 */  slti       $v0, $a2, 0x41
    /* 45C8 8006CDC8 02004014 */  bnez       $v0, .L8006CDD4
    /* 45CC 8006CDCC 00000000 */   nop
    /* 45D0 8006CDD0 40000624 */  addiu      $a2, $zero, 0x40
  .L8006CDD4:
    /* 45D4 8006CDD4 4A00C018 */  blez       $a2, .L8006CF00
    /* 45D8 8006CDD8 21200000 */   addu      $a0, $zero, $zero
    /* 45DC 8006CDDC 0E80023C */  lui        $v0, %hi(D_800DBAB3)
    /* 45E0 8006CDE0 0E80033C */  lui        $v1, %hi(D_800DBA3C)
    /* 45E4 8006CDE4 B3BA46A0 */  sb         $a2, %lo(D_800DBAB3)($v0)
    /* 45E8 8006CDE8 0E80023C */  lui        $v0, %hi(D_800DC1F0)
    /* 45EC 8006CDEC F0C1428C */  lw         $v0, %lo(D_800DC1F0)($v0)
    /* 45F0 8006CDF0 3CBA6324 */  addiu      $v1, $v1, %lo(D_800DBA3C)
    /* 45F4 8006CDF4 80300200 */  sll        $a2, $v0, 2
    /* 45F8 8006CDF8 2110C300 */  addu       $v0, $a2, $v1
    /* 45FC 8006CDFC 00004590 */  lbu        $a1, 0x0($v0)
    /* 4600 8006CE00 00000000 */  nop
    /* 4604 8006CE04 1000A010 */  beqz       $a1, .L8006CE48
    /* 4608 8006CE08 21808000 */   addu      $s0, $a0, $zero
    /* 460C 8006CE0C 0E80023C */  lui        $v0, %hi(D_800DB814)
    /* 4610 8006CE10 14B84724 */  addiu      $a3, $v0, %lo(D_800DB814)
    /* 4614 8006CE14 0100C624 */  addiu      $a2, $a2, 0x1
    /* 4618 8006CE18 21100602 */  addu       $v0, $s0, $a2
  .L8006CE1C:
    /* 461C 8006CE1C 21104300 */  addu       $v0, $v0, $v1
    /* 4620 8006CE20 00004290 */  lbu        $v0, 0x0($v0)
    /* 4624 8006CE24 00000000 */  nop
    /* 4628 8006CE28 C0100200 */  sll        $v0, $v0, 3
    /* 462C 8006CE2C 21104700 */  addu       $v0, $v0, $a3
    /* 4630 8006CE30 02004290 */  lbu        $v0, 0x2($v0)
    /* 4634 8006CE34 01001026 */  addiu      $s0, $s0, 0x1
    /* 4638 8006CE38 21208200 */  addu       $a0, $a0, $v0
    /* 463C 8006CE3C 2A100502 */  slt        $v0, $s0, $a1
    /* 4640 8006CE40 F6FF4014 */  bnez       $v0, .L8006CE1C
    /* 4644 8006CE44 21100602 */   addu      $v0, $s0, $a2
  .L8006CE48:
    /* 4648 8006CE48 C2170400 */  srl        $v0, $a0, 31
    /* 464C 8006CE4C 21108200 */  addu       $v0, $a0, $v0
    /* 4650 8006CE50 43200200 */  sra        $a0, $v0, 1
    /* 4654 8006CE54 23882402 */  subu       $s1, $s1, $a0
    /* 4658 8006CE58 0E80033C */  lui        $v1, %hi(D_800DBA3C)
    /* 465C 8006CE5C 0E80043C */  lui        $a0, %hi(D_800DC1F0)
    /* 4660 8006CE60 F0C1828C */  lw         $v0, %lo(D_800DC1F0)($a0)
    /* 4664 8006CE64 3CBA6324 */  addiu      $v1, $v1, %lo(D_800DBA3C)
    /* 4668 8006CE68 80100200 */  sll        $v0, $v0, 2
    /* 466C 8006CE6C 21104300 */  addu       $v0, $v0, $v1
    /* 4670 8006CE70 00004290 */  lbu        $v0, 0x0($v0)
    /* 4674 8006CE74 00000000 */  nop
    /* 4678 8006CE78 21004010 */  beqz       $v0, .L8006CF00
    /* 467C 8006CE7C 21800000 */   addu      $s0, $zero, $zero
    /* 4680 8006CE80 21906000 */  addu       $s2, $v1, $zero
    /* 4684 8006CE84 21988000 */  addu       $s3, $a0, $zero
    /* 4688 8006CE88 0E80023C */  lui        $v0, %hi(D_800DB814)
    /* 468C 8006CE8C 14B85424 */  addiu      $s4, $v0, %lo(D_800DB814)
  .L8006CE90:
    /* 4690 8006CE90 0E80073C */  lui        $a3, %hi(D_800DBAB0)
    /* 4694 8006CE94 21202002 */  addu       $a0, $s1, $zero
    /* 4698 8006CE98 F0C1628E */  lw         $v0, %lo(D_800DC1F0)($s3)
    /* 469C 8006CE9C 2128A002 */  addu       $a1, $s5, $zero
    /* 46A0 8006CEA0 80100200 */  sll        $v0, $v0, 2
    /* 46A4 8006CEA4 01004224 */  addiu      $v0, $v0, 0x1
    /* 46A8 8006CEA8 21100202 */  addu       $v0, $s0, $v0
    /* 46AC 8006CEAC 21105200 */  addu       $v0, $v0, $s2
    /* 46B0 8006CEB0 00004690 */  lbu        $a2, 0x0($v0)
    /* 46B4 8006CEB4 D6B4010C */  jal        func_8006D358
    /* 46B8 8006CEB8 B0BAE724 */   addiu     $a3, $a3, %lo(D_800DBAB0)
    /* 46BC 8006CEBC F0C1648E */  lw         $a0, %lo(D_800DC1F0)($s3)
    /* 46C0 8006CEC0 00000000 */  nop
    /* 46C4 8006CEC4 80200400 */  sll        $a0, $a0, 2
    /* 46C8 8006CEC8 01008224 */  addiu      $v0, $a0, 0x1
    /* 46CC 8006CECC 21100202 */  addu       $v0, $s0, $v0
    /* 46D0 8006CED0 21105200 */  addu       $v0, $v0, $s2
    /* 46D4 8006CED4 01001026 */  addiu      $s0, $s0, 0x1
    /* 46D8 8006CED8 00004290 */  lbu        $v0, 0x0($v0)
    /* 46DC 8006CEDC 21209200 */  addu       $a0, $a0, $s2
    /* 46E0 8006CEE0 C0100200 */  sll        $v0, $v0, 3
    /* 46E4 8006CEE4 21105400 */  addu       $v0, $v0, $s4
    /* 46E8 8006CEE8 02004390 */  lbu        $v1, 0x2($v0)
    /* 46EC 8006CEEC 00008290 */  lbu        $v0, 0x0($a0)
    /* 46F0 8006CEF0 00000000 */  nop
    /* 46F4 8006CEF4 2A100202 */  slt        $v0, $s0, $v0
    /* 46F8 8006CEF8 E5FF4014 */  bnez       $v0, .L8006CE90
    /* 46FC 8006CEFC 21882302 */   addu      $s1, $s1, $v1
  .L8006CF00:
    /* 4700 8006CF00 2800BF8F */  lw         $ra, 0x28($sp)
    /* 4704 8006CF04 2400B58F */  lw         $s5, 0x24($sp)
    /* 4708 8006CF08 2000B48F */  lw         $s4, 0x20($sp)
    /* 470C 8006CF0C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 4710 8006CF10 1800B28F */  lw         $s2, 0x18($sp)
    /* 4714 8006CF14 1400B18F */  lw         $s1, 0x14($sp)
    /* 4718 8006CF18 1000B08F */  lw         $s0, 0x10($sp)
    /* 471C 8006CF1C 0800E003 */  jr         $ra
    /* 4720 8006CF20 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8006CD94
