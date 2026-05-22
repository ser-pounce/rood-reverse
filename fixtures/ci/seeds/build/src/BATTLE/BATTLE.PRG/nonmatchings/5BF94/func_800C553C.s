nonmatching func_800C553C, 0x184

glabel func_800C553C
    /* 5CD3C 800C553C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 5CD40 800C5540 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5CD44 800C5544 06001224 */  addiu      $s2, $zero, 0x6
    /* 5CD48 800C5548 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 5CD4C 800C554C 0F80133C */  lui        $s3, %hi(D_800EB9B8)
    /* 5CD50 800C5550 0F80023C */  lui        $v0, %hi(D_800F4CB0)
    /* 5CD54 800C5554 B04C40A0 */  sb         $zero, %lo(D_800F4CB0)($v0)
    /* 5CD58 800C5558 0F80023C */  lui        $v0, %hi(D_800F4CB1)
    /* 5CD5C 800C555C B14C40A0 */  sb         $zero, %lo(D_800F4CB1)($v0)
    /* 5CD60 800C5560 0F80023C */  lui        $v0, %hi(D_800F4CB2)
    /* 5CD64 800C5564 B24C40A0 */  sb         $zero, %lo(D_800F4CB2)($v0)
    /* 5CD68 800C5568 0F80023C */  lui        $v0, %hi(D_800F4CB3)
    /* 5CD6C 800C556C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 5CD70 800C5570 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5CD74 800C5574 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5CD78 800C5578 B34C40A0 */  sb         $zero, %lo(D_800F4CB3)($v0)
  .L800C557C:
    /* 5CD7C 800C557C 21800000 */  addu       $s0, $zero, $zero
  .L800C5580:
    /* 5CD80 800C5580 B8B9638E */  lw         $v1, %lo(D_800EB9B8)($s3)
    /* 5CD84 800C5584 21200000 */  addu       $a0, $zero, $zero
    /* 5CD88 800C5588 2C006290 */  lbu        $v0, 0x2C($v1)
    /* 5CD8C 800C558C 00000000 */  nop
    /* 5CD90 800C5590 0D004010 */  beqz       $v0, .L800C55C8
    /* 5CD94 800C5594 21888000 */   addu      $s1, $a0, $zero
    /* 5CD98 800C5598 21284000 */  addu       $a1, $v0, $zero
    /* 5CD9C 800C559C 4000638C */  lw         $v1, 0x40($v1)
  .L800C55A0:
    /* 5CDA0 800C55A0 00000000 */  nop
    /* 5CDA4 800C55A4 09006290 */  lbu        $v0, 0x9($v1)
    /* 5CDA8 800C55A8 00000000 */  nop
    /* 5CDAC 800C55AC 02005014 */  bne        $v0, $s0, .L800C55B8
    /* 5CDB0 800C55B0 00000000 */   nop
    /* 5CDB4 800C55B4 01008424 */  addiu      $a0, $a0, 0x1
  .L800C55B8:
    /* 5CDB8 800C55B8 01003126 */  addiu      $s1, $s1, 0x1
    /* 5CDBC 800C55BC 2A102502 */  slt        $v0, $s1, $a1
    /* 5CDC0 800C55C0 F7FF4014 */  bnez       $v0, .L800C55A0
    /* 5CDC4 800C55C4 18006324 */   addiu     $v1, $v1, 0x18
  .L800C55C8:
    /* 5CDC8 800C55C8 03009214 */  bne        $a0, $s2, .L800C55D8
    /* 5CDCC 800C55CC 00000000 */   nop
    /* 5CDD0 800C55D0 D814030C */  jal        func_800C5360
    /* 5CDD4 800C55D4 21200002 */   addu      $a0, $s0, $zero
  .L800C55D8:
    /* 5CDD8 800C55D8 01001026 */  addiu      $s0, $s0, 0x1
    /* 5CDDC 800C55DC 1000022A */  slti       $v0, $s0, 0x10
    /* 5CDE0 800C55E0 E7FF4014 */  bnez       $v0, .L800C5580
    /* 5CDE4 800C55E4 00000000 */   nop
    /* 5CDE8 800C55E8 FFFF5226 */  addiu      $s2, $s2, -0x1
    /* 5CDEC 800C55EC E3FF401E */  bgtz       $s2, .L800C557C
    /* 5CDF0 800C55F0 0F80033C */   lui       $v1, %hi(D_800EB9B8)
    /* 5CDF4 800C55F4 B8B9628C */  lw         $v0, %lo(D_800EB9B8)($v1)
    /* 5CDF8 800C55F8 00000000 */  nop
    /* 5CDFC 800C55FC 2C004290 */  lbu        $v0, 0x2C($v0)
    /* 5CE00 800C5600 00000000 */  nop
    /* 5CE04 800C5604 16004010 */  beqz       $v0, .L800C5660
    /* 5CE08 800C5608 21880000 */   addu      $s1, $zero, $zero
    /* 5CE0C 800C560C 21986000 */  addu       $s3, $v1, $zero
    /* 5CE10 800C5610 21902002 */  addu       $s2, $s1, $zero
  .L800C5614:
    /* 5CE14 800C5614 B8B9628E */  lw         $v0, %lo(D_800EB9B8)($s3)
    /* 5CE18 800C5618 00000000 */  nop
    /* 5CE1C 800C561C 4000428C */  lw         $v0, 0x40($v0)
    /* 5CE20 800C5620 00000000 */  nop
    /* 5CE24 800C5624 21104202 */  addu       $v0, $s2, $v0
    /* 5CE28 800C5628 09005090 */  lbu        $s0, 0x9($v0)
    /* 5CE2C 800C562C 00000000 */  nop
    /* 5CE30 800C5630 03111000 */  sra        $v0, $s0, 4
    /* 5CE34 800C5634 03004010 */  beqz       $v0, .L800C5644
    /* 5CE38 800C5638 00000000 */   nop
    /* 5CE3C 800C563C D814030C */  jal        func_800C5360
    /* 5CE40 800C5640 21200002 */   addu      $a0, $s0, $zero
  .L800C5644:
    /* 5CE44 800C5644 B8B9628E */  lw         $v0, %lo(D_800EB9B8)($s3)
    /* 5CE48 800C5648 00000000 */  nop
    /* 5CE4C 800C564C 2C004290 */  lbu        $v0, 0x2C($v0)
    /* 5CE50 800C5650 01003126 */  addiu      $s1, $s1, 0x1
    /* 5CE54 800C5654 2A102202 */  slt        $v0, $s1, $v0
    /* 5CE58 800C5658 EEFF4014 */  bnez       $v0, .L800C5614
    /* 5CE5C 800C565C 18005226 */   addiu     $s2, $s2, 0x18
  .L800C5660:
    /* 5CE60 800C5660 0F80023C */  lui        $v0, %hi(D_800F4CB1)
    /* 5CE64 800C5664 B14C5190 */  lbu        $s1, %lo(D_800F4CB1)($v0)
    /* 5CE68 800C5668 0F80023C */  lui        $v0, %hi(D_800F4CB0)
    /* 5CE6C 800C566C B04C4390 */  lbu        $v1, %lo(D_800F4CB0)($v0)
    /* 5CE70 800C5670 00000000 */  nop
    /* 5CE74 800C5674 2A102302 */  slt        $v0, $s1, $v1
    /* 5CE78 800C5678 02004010 */  beqz       $v0, .L800C5684
    /* 5CE7C 800C567C 0F80043C */   lui       $a0, %hi(D_800F4CB4)
    /* 5CE80 800C5680 21886000 */  addu       $s1, $v1, $zero
  .L800C5684:
    /* 5CE84 800C5684 10000324 */  addiu      $v1, $zero, 0x10
    /* 5CE88 800C5688 23187100 */  subu       $v1, $v1, $s1
    /* 5CE8C 800C568C 40100300 */  sll        $v0, $v1, 1
    /* 5CE90 800C5690 21104300 */  addu       $v0, $v0, $v1
    /* 5CE94 800C5694 80100200 */  sll        $v0, $v0, 2
    /* 5CE98 800C5698 23104300 */  subu       $v0, $v0, $v1
    /* 5CE9C 800C569C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 5CEA0 800C56A0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 5CEA4 800C56A4 1800B28F */  lw         $s2, 0x18($sp)
    /* 5CEA8 800C56A8 1400B18F */  lw         $s1, 0x14($sp)
    /* 5CEAC 800C56AC 1000B08F */  lw         $s0, 0x10($sp)
    /* 5CEB0 800C56B0 43100200 */  sra        $v0, $v0, 1
    /* 5CEB4 800C56B4 B44C82A0 */  sb         $v0, %lo(D_800F4CB4)($a0)
    /* 5CEB8 800C56B8 0800E003 */  jr         $ra
    /* 5CEBC 800C56BC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800C553C
