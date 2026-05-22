nonmatching _padSioRW, 0x210

glabel _padSioRW
    /* 1CD28 8002C528 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1CD2C 8002C52C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1CD30 8002C530 21808000 */  addu       $s0, $a0, $zero
    /* 1CD34 8002C534 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1CD38 8002C538 2198A000 */  addu       $s3, $a1, $zero
    /* 1CD3C 8002C53C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1CD40 8002C540 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1CD44 8002C544 22006106 */  bgez       $s3, .L8002C5D0
    /* 1CD48 8002C548 1400B1AF */   sw        $s1, 0x14($sp)
    /* 1CD4C 8002C54C 0380023C */  lui        $v0, %hi(D_80033600)
    /* 1CD50 8002C550 0036428C */  lw         $v0, %lo(D_80033600)($v0)
    /* 1CD54 8002C554 4000038E */  lw         $v1, 0x40($s0)
    /* 1CD58 8002C558 00004490 */  lbu        $a0, 0x0($v0)
    /* 1CD5C 8002C55C FF000224 */  addiu      $v0, $zero, 0xFF
    /* 1CD60 8002C560 440002A2 */  sb         $v0, 0x44($s0)
    /* 1CD64 8002C564 01000224 */  addiu      $v0, $zero, 0x1
    /* 1CD68 8002C568 450002A2 */  sb         $v0, 0x45($s0)
    /* 1CD6C 8002C56C 27101300 */  nor        $v0, $zero, $s3
    /* 1CD70 8002C570 000062A0 */  sb         $v0, 0x0($v1)
    /* 1CD74 8002C574 0380033C */  lui        $v1, %hi(D_80033600)
    /* 1CD78 8002C578 0036638C */  lw         $v1, %lo(D_80033600)($v1)
    /* 1CD7C 8002C57C 00000000 */  nop
    /* 1CD80 8002C580 04006294 */  lhu        $v0, 0x4($v1)
    /* 1CD84 8002C584 00000000 */  nop
    /* 1CD88 8002C588 01004230 */  andi       $v0, $v0, 0x1
    /* 1CD8C 8002C58C 06004014 */  bnez       $v0, .L8002C5A8
    /* 1CD90 8002C590 FF009230 */   andi      $s2, $a0, 0xFF
  .L8002C594:
    /* 1CD94 8002C594 04006294 */  lhu        $v0, 0x4($v1)
    /* 1CD98 8002C598 00000000 */  nop
    /* 1CD9C 8002C59C 01004230 */  andi       $v0, $v0, 0x1
    /* 1CDA0 8002C5A0 FCFF4010 */  beqz       $v0, .L8002C594
    /* 1CDA4 8002C5A4 00000000 */   nop
  .L8002C5A8:
    /* 1CDA8 8002C5A8 05BA000C */  jal        chkRC2wait
    /* 1CDAC 8002C5AC 00000000 */   nop
    /* 1CDB0 8002C5B0 FDFF4010 */  beqz       $v0, .L8002C5A8
    /* 1CDB4 8002C5B4 27101300 */   nor       $v0, $zero, $s3
    /* 1CDB8 8002C5B8 0380033C */  lui        $v1, %hi(D_80033600)
    /* 1CDBC 8002C5BC 0036638C */  lw         $v1, %lo(D_80033600)($v1)
    /* 1CDC0 8002C5C0 00000000 */  nop
    /* 1CDC4 8002C5C4 000062A0 */  sb         $v0, 0x0($v1)
    /* 1CDC8 8002C5C8 C7B10008 */  j          .L8002C71C
    /* 1CDCC 8002C5CC 21104002 */   addu      $v0, $s2, $zero
  .L8002C5D0:
    /* 1CDD0 8002C5D0 3C00028E */  lw         $v0, 0x3C($s0)
    /* 1CDD4 8002C5D4 00000000 */  nop
    /* 1CDD8 8002C5D8 00004290 */  lbu        $v0, 0x0($v0)
    /* 1CDDC 8002C5DC 08000324 */  addiu      $v1, $zero, 0x8
    /* 1CDE0 8002C5E0 03110200 */  sra        $v0, $v0, 4
    /* 1CDE4 8002C5E4 07004314 */  bne        $v0, $v1, .L8002C604
    /* 1CDE8 8002C5E8 88001124 */   addiu     $s1, $zero, 0x88
    /* 1CDEC 8002C5EC 44000292 */  lbu        $v0, 0x44($s0)
    /* 1CDF0 8002C5F0 00000000 */  nop
    /* 1CDF4 8002C5F4 0900422C */  sltiu      $v0, $v0, 0x9
    /* 1CDF8 8002C5F8 03004014 */  bnez       $v0, .L8002C608
    /* 1CDFC 8002C5FC 801F023C */   lui       $v0, (0x1F801120 >> 16)
    /* 1CE00 8002C600 22001124 */  addiu      $s1, $zero, 0x22
  .L8002C604:
    /* 1CE04 8002C604 801F023C */  lui        $v0, (0x1F801120 >> 16)
  .L8002C608:
    /* 1CE08 8002C608 20114234 */  ori        $v0, $v0, (0x1F801120 & 0xFFFF)
    /* 1CE0C 8002C60C 0380053C */  lui        $a1, %hi(D_80033600)
    /* 1CE10 8002C610 0036A58C */  lw         $a1, %lo(D_80033600)($a1)
    /* 1CE14 8002C614 00004494 */  lhu        $a0, 0x0($v0)
    /* 1CE18 8002C618 0400A394 */  lhu        $v1, 0x4($a1)
    /* 1CE1C 8002C61C AE010224 */  addiu      $v0, $zero, 0x1AE
    /* 1CE20 8002C620 0480013C */  lui        $at, %hi(D_8003FEA4)
    /* 1CE24 8002C624 A4FE22AC */  sw         $v0, %lo(D_8003FEA4)($at)
    /* 1CE28 8002C628 0480013C */  lui        $at, %hi(D_8003FEA0)
    /* 1CE2C 8002C62C A0FE24AC */  sw         $a0, %lo(D_8003FEA0)($at)
    /* 1CE30 8002C630 02006330 */  andi       $v1, $v1, 0x2
    /* 1CE34 8002C634 06006014 */  bnez       $v1, .L8002C650
    /* 1CE38 8002C638 2118A000 */   addu      $v1, $a1, $zero
  .L8002C63C:
    /* 1CE3C 8002C63C 04006294 */  lhu        $v0, 0x4($v1)
    /* 1CE40 8002C640 00000000 */  nop
    /* 1CE44 8002C644 02004230 */  andi       $v0, $v0, 0x2
    /* 1CE48 8002C648 FCFF4010 */  beqz       $v0, .L8002C63C
    /* 1CE4C 8002C64C 00000000 */   nop
  .L8002C650:
    /* 1CE50 8002C650 0380023C */  lui        $v0, %hi(D_80033600)
    /* 1CE54 8002C654 0036428C */  lw         $v0, %lo(D_80033600)($v0)
    /* 1CE58 8002C658 0380033C */  lui        $v1, %hi(D_800335FC)
    /* 1CE5C 8002C65C FC35638C */  lw         $v1, %lo(D_800335FC)($v1)
    /* 1CE60 8002C660 00004490 */  lbu        $a0, 0x0($v0)
    /* 1CE64 8002C664 0E0051A4 */  sh         $s1, 0xE($v0)
    /* 1CE68 8002C668 0000628C */  lw         $v0, 0x0($v1)
    /* 1CE6C 8002C66C 00000000 */  nop
    /* 1CE70 8002C670 80004230 */  andi       $v0, $v0, 0x80
    /* 1CE74 8002C674 0D004014 */  bnez       $v0, .L8002C6AC
    /* 1CE78 8002C678 FF009230 */   andi      $s2, $a0, 0xFF
  .L8002C67C:
    /* 1CE7C 8002C67C 05BA000C */  jal        chkRC2wait
    /* 1CE80 8002C680 00000000 */   nop
    /* 1CE84 8002C684 25004014 */  bnez       $v0, .L8002C71C
    /* 1CE88 8002C688 ECFF0224 */   addiu     $v0, $zero, -0x14
    /* 1CE8C 8002C68C 0380023C */  lui        $v0, %hi(D_800335FC)
    /* 1CE90 8002C690 FC35428C */  lw         $v0, %lo(D_800335FC)($v0)
    /* 1CE94 8002C694 00000000 */  nop
    /* 1CE98 8002C698 0000428C */  lw         $v0, 0x0($v0)
    /* 1CE9C 8002C69C 00000000 */  nop
    /* 1CEA0 8002C6A0 80004230 */  andi       $v0, $v0, 0x80
    /* 1CEA4 8002C6A4 F5FF4010 */  beqz       $v0, .L8002C67C
    /* 1CEA8 8002C6A8 00000000 */   nop
  .L8002C6AC:
    /* 1CEAC 8002C6AC 0380023C */  lui        $v0, %hi(D_80033600)
    /* 1CEB0 8002C6B0 0036428C */  lw         $v0, %lo(D_80033600)($v0)
    /* 1CEB4 8002C6B4 00000000 */  nop
    /* 1CEB8 8002C6B8 000053A0 */  sb         $s3, 0x0($v0)
    /* 1CEBC 8002C6BC 22000224 */  addiu      $v0, $zero, 0x22
    /* 1CEC0 8002C6C0 0A002216 */  bne        $s1, $v0, .L8002C6EC
    /* 1CEC4 8002C6C4 7FFF0224 */   addiu     $v0, $zero, -0x81
    /* 1CEC8 8002C6C8 0380033C */  lui        $v1, %hi(D_800335FC)
    /* 1CECC 8002C6CC FC35638C */  lw         $v1, %lo(D_800335FC)($v1)
    /* 1CED0 8002C6D0 0380043C */  lui        $a0, %hi(D_80033600)
    /* 1CED4 8002C6D4 0036848C */  lw         $a0, %lo(D_80033600)($a0)
    /* 1CED8 8002C6D8 000062AC */  sw         $v0, 0x0($v1)
    /* 1CEDC 8002C6DC 0A008294 */  lhu        $v0, 0xA($a0)
    /* 1CEE0 8002C6E0 00000000 */  nop
    /* 1CEE4 8002C6E4 10004234 */  ori        $v0, $v0, 0x10
    /* 1CEE8 8002C6E8 0A0082A4 */  sh         $v0, 0xA($a0)
  .L8002C6EC:
    /* 1CEEC 8002C6EC 45000292 */  lbu        $v0, 0x45($s0)
    /* 1CEF0 8002C6F0 44000492 */  lbu        $a0, 0x44($s0)
    /* 1CEF4 8002C6F4 3C00038E */  lw         $v1, 0x3C($s0)
    /* 1CEF8 8002C6F8 01004224 */  addiu      $v0, $v0, 0x1
    /* 1CEFC 8002C6FC 21186400 */  addu       $v1, $v1, $a0
    /* 1CF00 8002C700 450002A2 */  sb         $v0, 0x45($s0)
    /* 1CF04 8002C704 000072A0 */  sb         $s2, 0x0($v1)
    /* 1CF08 8002C708 44000292 */  lbu        $v0, 0x44($s0)
    /* 1CF0C 8002C70C 00000000 */  nop
    /* 1CF10 8002C710 01004224 */  addiu      $v0, $v0, 0x1
    /* 1CF14 8002C714 440002A2 */  sb         $v0, 0x44($s0)
    /* 1CF18 8002C718 21104002 */  addu       $v0, $s2, $zero
  .L8002C71C:
    /* 1CF1C 8002C71C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1CF20 8002C720 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1CF24 8002C724 1800B28F */  lw         $s2, 0x18($sp)
    /* 1CF28 8002C728 1400B18F */  lw         $s1, 0x14($sp)
    /* 1CF2C 8002C72C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1CF30 8002C730 0800E003 */  jr         $ra
    /* 1CF34 8002C734 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _padSioRW
