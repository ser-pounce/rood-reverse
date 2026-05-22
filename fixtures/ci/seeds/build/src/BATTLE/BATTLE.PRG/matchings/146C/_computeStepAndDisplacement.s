nonmatching _computeStepAndDisplacement, 0x364

glabel _computeStepAndDisplacement
    /* 5398 8006DB98 A0FFBD27 */  addiu      $sp, $sp, -0x60
    /* 539C 8006DB9C 5000B2AF */  sw         $s2, 0x50($sp)
    /* 53A0 8006DBA0 2190A000 */  addu       $s2, $a1, $zero
    /* 53A4 8006DBA4 5C00BFAF */  sw         $ra, 0x5C($sp)
    /* 53A8 8006DBA8 5800B4AF */  sw         $s4, 0x58($sp)
    /* 53AC 8006DBAC 5400B3AF */  sw         $s3, 0x54($sp)
    /* 53B0 8006DBB0 4C00B1AF */  sw         $s1, 0x4C($sp)
    /* 53B4 8006DBB4 4800B0AF */  sw         $s0, 0x48($sp)
    /* 53B8 8006DBB8 00008284 */  lh         $v0, 0x0($a0)
    /* 53BC 8006DBBC 7000B48F */  lw         $s4, 0x70($sp)
    /* 53C0 8006DBC0 00130200 */  sll        $v0, $v0, 12
    /* 53C4 8006DBC4 1800A2AF */  sw         $v0, 0x18($sp)
    /* 53C8 8006DBC8 04008284 */  lh         $v0, 0x4($a0)
    /* 53CC 8006DBCC 2188C000 */  addu       $s1, $a2, $zero
    /* 53D0 8006DBD0 00130200 */  sll        $v0, $v0, 12
    /* 53D4 8006DBD4 2000A2AF */  sw         $v0, 0x20($sp)
    /* 53D8 8006DBD8 02008284 */  lh         $v0, 0x2($a0)
    /* 53DC 8006DBDC 2198E000 */  addu       $s3, $a3, $zero
    /* 53E0 8006DBE0 00130200 */  sll        $v0, $v0, 12
    /* 53E4 8006DBE4 04006012 */  beqz       $s3, .L8006DBF8
    /* 53E8 8006DBE8 1C00A2AF */   sw        $v0, 0x1C($sp)
    /* 53EC 8006DBEC 1800A427 */  addiu      $a0, $sp, 0x18
    /* 53F0 8006DBF0 7FB6010C */  jal        _clampPositionToZoneBounds
    /* 53F4 8006DBF4 21288000 */   addu      $a1, $a0, $zero
  .L8006DBF8:
    /* 53F8 8006DBF8 1800A28F */  lw         $v0, 0x18($sp)
    /* 53FC 8006DBFC 00000000 */  nop
    /* 5400 8006DC00 02004104 */  bgez       $v0, .L8006DC0C
    /* 5404 8006DC04 00000000 */   nop
    /* 5408 8006DC08 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006DC0C:
    /* 540C 8006DC0C 2000A48F */  lw         $a0, 0x20($sp)
    /* 5410 8006DC10 03130200 */  sra        $v0, $v0, 12
    /* 5414 8006DC14 02008104 */  bgez       $a0, .L8006DC20
    /* 5418 8006DC18 1000A2A7 */   sh        $v0, 0x10($sp)
    /* 541C 8006DC1C FF0F8424 */  addiu      $a0, $a0, 0xFFF
  .L8006DC20:
    /* 5420 8006DC20 1C00A38F */  lw         $v1, 0x1C($sp)
    /* 5424 8006DC24 03130400 */  sra        $v0, $a0, 12
    /* 5428 8006DC28 02006104 */  bgez       $v1, .L8006DC34
    /* 542C 8006DC2C 1400A2A7 */   sh        $v0, 0x14($sp)
    /* 5430 8006DC30 FF0F6324 */  addiu      $v1, $v1, 0xFFF
  .L8006DC34:
    /* 5434 8006DC34 03130300 */  sra        $v0, $v1, 12
    /* 5438 8006DC38 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 543C 8006DC3C 801F103C */  lui        $s0, %hi(D_1F800014_mat)
    /* 5440 8006DC40 14001026 */  addiu      $s0, $s0, %lo(D_1F800014_mat)
    /* 5444 8006DC44 6605010C */  jal        SetRotMatrix
    /* 5448 8006DC48 21200002 */   addu      $a0, $s0, $zero
    /* 544C 8006DC4C 5E05010C */  jal        SetTransMatrix
    /* 5450 8006DC50 21200002 */   addu      $a0, $s0, $zero
    /* 5454 8006DC54 1000A427 */  addiu      $a0, $sp, 0x10
    /* 5458 8006DC58 3800A527 */  addiu      $a1, $sp, 0x38
    /* 545C 8006DC5C 3C00A627 */  addiu      $a2, $sp, 0x3C
    /* 5460 8006DC60 0506010C */  jal        RotTransPers
    /* 5464 8006DC64 4000A727 */   addiu     $a3, $sp, 0x40
    /* 5468 8006DC68 16006016 */  bnez       $s3, .L8006DCC4
    /* 546C 8006DC6C 01000224 */   addiu     $v0, $zero, 0x1
    /* 5470 8006DC70 3800A38F */  lw         $v1, 0x38($sp)
    /* 5474 8006DC74 00000000 */  nop
    /* 5478 8006DC78 03006104 */  bgez       $v1, .L8006DC88
    /* 547C 8006DC7C 21106000 */   addu      $v0, $v1, $zero
    /* 5480 8006DC80 FFFF0234 */  ori        $v0, $zero, 0xFFFF
    /* 5484 8006DC84 21106200 */  addu       $v0, $v1, $v0
  .L8006DC88:
    /* 5488 8006DC88 03240200 */  sra        $a0, $v0, 16
    /* 548C 8006DC8C 00140400 */  sll        $v0, $a0, 16
    /* 5490 8006DC90 23106200 */  subu       $v0, $v1, $v0
    /* 5494 8006DC94 C3FF4224 */  addiu      $v0, $v0, -0x3D
    /* 5498 8006DC98 C700422C */  sltiu      $v0, $v0, 0xC7
    /* 549C 8006DC9C 08004010 */  beqz       $v0, .L8006DCC0
    /* 54A0 8006DCA0 3D008228 */   slti      $v0, $a0, 0x3D
    /* 54A4 8006DCA4 07004014 */  bnez       $v0, .L8006DCC4
    /* 54A8 8006DCA8 01000224 */   addiu     $v0, $zero, 0x1
    /* 54AC 8006DCAC B4008228 */  slti       $v0, $a0, 0xB4
    /* 54B0 8006DCB0 04004010 */  beqz       $v0, .L8006DCC4
    /* 54B4 8006DCB4 01000224 */   addiu     $v0, $zero, 0x1
    /* 54B8 8006DCB8 32B70108 */  j          .L8006DCC8
    /* 54BC 8006DCBC 4000A0AF */   sw        $zero, 0x40($sp)
  .L8006DCC0:
    /* 54C0 8006DCC0 01000224 */  addiu      $v0, $zero, 0x1
  .L8006DCC4:
    /* 54C4 8006DCC4 4000A2AF */  sw         $v0, 0x40($sp)
  .L8006DCC8:
    /* 54C8 8006DCC8 801F023C */  lui        $v0, %hi(D_1F800000)
    /* 54CC 8006DCCC 00004424 */  addiu      $a0, $v0, %lo(D_1F800000)
    /* 54D0 8006DCD0 1000A287 */  lh         $v0, 0x10($sp)
    /* 54D4 8006DCD4 4400838C */  lw         $v1, 0x44($a0)
    /* 54D8 8006DCD8 00130200 */  sll        $v0, $v0, 12
    /* 54DC 8006DCDC 23104300 */  subu       $v0, $v0, $v1
    /* 54E0 8006DCE0 02004104 */  bgez       $v0, .L8006DCEC
    /* 54E4 8006DCE4 000022AE */   sw        $v0, 0x0($s1)
    /* 54E8 8006DCE8 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006DCEC:
    /* 54EC 8006DCEC 03130200 */  sra        $v0, $v0, 12
    /* 54F0 8006DCF0 1800A2AF */  sw         $v0, 0x18($sp)
    /* 54F4 8006DCF4 1400A287 */  lh         $v0, 0x14($sp)
    /* 54F8 8006DCF8 4C00838C */  lw         $v1, 0x4C($a0)
    /* 54FC 8006DCFC 00130200 */  sll        $v0, $v0, 12
    /* 5500 8006DD00 23104300 */  subu       $v0, $v0, $v1
    /* 5504 8006DD04 02004104 */  bgez       $v0, .L8006DD10
    /* 5508 8006DD08 080022AE */   sw        $v0, 0x8($s1)
    /* 550C 8006DD0C FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006DD10:
    /* 5510 8006DD10 03130200 */  sra        $v0, $v0, 12
    /* 5514 8006DD14 2000A2AF */  sw         $v0, 0x20($sp)
    /* 5518 8006DD18 1200A287 */  lh         $v0, 0x12($sp)
    /* 551C 8006DD1C 4800838C */  lw         $v1, 0x48($a0)
    /* 5520 8006DD20 00130200 */  sll        $v0, $v0, 12
    /* 5524 8006DD24 23104300 */  subu       $v0, $v0, $v1
    /* 5528 8006DD28 02004104 */  bgez       $v0, .L8006DD34
    /* 552C 8006DD2C 040022AE */   sw        $v0, 0x4($s1)
    /* 5530 8006DD30 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006DD34:
    /* 5534 8006DD34 1800A427 */  addiu      $a0, $sp, 0x18
    /* 5538 8006DD38 2800A527 */  addiu      $a1, $sp, 0x28
    /* 553C 8006DD3C 03130200 */  sra        $v0, $v0, 12
    /* 5540 8006DD40 A506010C */  jal        VectorNormal
    /* 5544 8006DD44 1C00A2AF */   sw        $v0, 0x1C($sp)
    /* 5548 8006DD48 4000A28F */  lw         $v0, 0x40($sp)
    /* 554C 8006DD4C 00000000 */  nop
    /* 5550 8006DD50 48004010 */  beqz       $v0, .L8006DE74
    /* 5554 8006DD54 0F80023C */   lui       $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 5558 8006DD58 2800A38F */  lw         $v1, 0x28($sp)
    /* 555C 8006DD5C 00000000 */  nop
    /* 5560 8006DD60 07006010 */  beqz       $v1, .L8006DD80
    /* 5564 8006DD64 00000000 */   nop
    /* 5568 8006DD68 0000228E */  lw         $v0, 0x0($s1)
    /* 556C 8006DD6C 00000000 */  nop
    /* 5570 8006DD70 1A004300 */  div        $zero, $v0, $v1
    /* 5574 8006DD74 12180000 */  mflo       $v1
    /* 5578 8006DD78 76B70108 */  j          .L8006DDD8
    /* 557C 8006DD7C 29006228 */   slti      $v0, $v1, 0x29
  .L8006DD80:
    /* 5580 8006DD80 3000A38F */  lw         $v1, 0x30($sp)
    /* 5584 8006DD84 00000000 */  nop
    /* 5588 8006DD88 07006010 */  beqz       $v1, .L8006DDA8
    /* 558C 8006DD8C 00000000 */   nop
    /* 5590 8006DD90 0800228E */  lw         $v0, 0x8($s1)
    /* 5594 8006DD94 00000000 */  nop
    /* 5598 8006DD98 1A004300 */  div        $zero, $v0, $v1
    /* 559C 8006DD9C 12180000 */  mflo       $v1
    /* 55A0 8006DDA0 76B70108 */  j          .L8006DDD8
    /* 55A4 8006DDA4 29006228 */   slti      $v0, $v1, 0x29
  .L8006DDA8:
    /* 55A8 8006DDA8 2C00A38F */  lw         $v1, 0x2C($sp)
    /* 55AC 8006DDAC 00000000 */  nop
    /* 55B0 8006DDB0 07006010 */  beqz       $v1, .L8006DDD0
    /* 55B4 8006DDB4 00000000 */   nop
    /* 55B8 8006DDB8 0400228E */  lw         $v0, 0x4($s1)
    /* 55BC 8006DDBC 00000000 */  nop
    /* 55C0 8006DDC0 1A004300 */  div        $zero, $v0, $v1
    /* 55C4 8006DDC4 12180000 */  mflo       $v1
    /* 55C8 8006DDC8 76B70108 */  j          .L8006DDD8
    /* 55CC 8006DDCC 29006228 */   slti      $v0, $v1, 0x29
  .L8006DDD0:
    /* 55D0 8006DDD0 01000324 */  addiu      $v1, $zero, 0x1
    /* 55D4 8006DDD4 29006228 */  slti       $v0, $v1, 0x29
  .L8006DDD8:
    /* 55D8 8006DDD8 0B004014 */  bnez       $v0, .L8006DE08
    /* 55DC 8006DDDC 0F80023C */   lui       $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 55E0 8006DDE0 D0194324 */  addiu      $v1, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* 55E4 8006DDE4 2800628C */  lw         $v0, 0x28($v1)
    /* 55E8 8006DDE8 00000000 */  nop
    /* 55EC 8006DDEC 08004224 */  addiu      $v0, $v0, 0x8
    /* 55F0 8006DDF0 280062AC */  sw         $v0, 0x28($v1)
    /* 55F4 8006DDF4 2A108202 */  slt        $v0, $s4, $v0
    /* 55F8 8006DDF8 0C004010 */  beqz       $v0, .L8006DE2C
    /* 55FC 8006DDFC 00000000 */   nop
    /* 5600 8006DE00 8BB70108 */  j          .L8006DE2C
    /* 5604 8006DE04 280074AC */   sw        $s4, 0x28($v1)
  .L8006DE08:
    /* 5608 8006DE08 D0194324 */  addiu      $v1, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* 560C 8006DE0C 2800628C */  lw         $v0, 0x28($v1)
    /* 5610 8006DE10 00000000 */  nop
    /* 5614 8006DE14 F8FF4224 */  addiu      $v0, $v0, -0x8
    /* 5618 8006DE18 280062AC */  sw         $v0, 0x28($v1)
    /* 561C 8006DE1C 08004228 */  slti       $v0, $v0, 0x8
    /* 5620 8006DE20 02004010 */  beqz       $v0, .L8006DE2C
    /* 5624 8006DE24 08000224 */   addiu     $v0, $zero, 0x8
    /* 5628 8006DE28 280062AC */  sw         $v0, 0x28($v1)
  .L8006DE2C:
    /* 562C 8006DE2C 0F80033C */  lui        $v1, %hi(vs_battle_cameraCurrentSpherical)
    /* 5630 8006DE30 D0196324 */  addiu      $v1, $v1, %lo(vs_battle_cameraCurrentSpherical)
    /* 5634 8006DE34 2800A48F */  lw         $a0, 0x28($sp)
    /* 5638 8006DE38 2800628C */  lw         $v0, 0x28($v1)
    /* 563C 8006DE3C 00000000 */  nop
    /* 5640 8006DE40 18008200 */  mult       $a0, $v0
    /* 5644 8006DE44 12400000 */  mflo       $t0
    /* 5648 8006DE48 000048AE */  sw         $t0, 0x0($s2)
    /* 564C 8006DE4C 3000A48F */  lw         $a0, 0x30($sp)
    /* 5650 8006DE50 2800628C */  lw         $v0, 0x28($v1)
    /* 5654 8006DE54 00000000 */  nop
    /* 5658 8006DE58 18008200 */  mult       $a0, $v0
    /* 565C 8006DE5C 12400000 */  mflo       $t0
    /* 5660 8006DE60 080048AE */  sw         $t0, 0x8($s2)
    /* 5664 8006DE64 2C00A48F */  lw         $a0, 0x2C($sp)
    /* 5668 8006DE68 2800628C */  lw         $v0, 0x28($v1)
    /* 566C 8006DE6C B4B70108 */  j          .L8006DED0
    /* 5670 8006DE70 18008200 */   mult      $a0, $v0
  .L8006DE74:
    /* 5674 8006DE74 D0194424 */  addiu      $a0, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* 5678 8006DE78 2800828C */  lw         $v0, 0x28($a0)
    /* 567C 8006DE7C 00000000 */  nop
    /* 5680 8006DE80 F8FF4224 */  addiu      $v0, $v0, -0x8
    /* 5684 8006DE84 02004104 */  bgez       $v0, .L8006DE90
    /* 5688 8006DE88 280082AC */   sw        $v0, 0x28($a0)
    /* 568C 8006DE8C 280080AC */  sw         $zero, 0x28($a0)
  .L8006DE90:
    /* 5690 8006DE90 2800A38F */  lw         $v1, 0x28($sp)
    /* 5694 8006DE94 2800828C */  lw         $v0, 0x28($a0)
    /* 5698 8006DE98 00000000 */  nop
    /* 569C 8006DE9C 18006200 */  mult       $v1, $v0
    /* 56A0 8006DEA0 12400000 */  mflo       $t0
    /* 56A4 8006DEA4 000048AE */  sw         $t0, 0x0($s2)
    /* 56A8 8006DEA8 3000A38F */  lw         $v1, 0x30($sp)
    /* 56AC 8006DEAC 2800828C */  lw         $v0, 0x28($a0)
    /* 56B0 8006DEB0 00000000 */  nop
    /* 56B4 8006DEB4 18006200 */  mult       $v1, $v0
    /* 56B8 8006DEB8 12400000 */  mflo       $t0
    /* 56BC 8006DEBC 080048AE */  sw         $t0, 0x8($s2)
    /* 56C0 8006DEC0 2C00A38F */  lw         $v1, 0x2C($sp)
    /* 56C4 8006DEC4 2800828C */  lw         $v0, 0x28($a0)
    /* 56C8 8006DEC8 00000000 */  nop
    /* 56CC 8006DECC 18006200 */  mult       $v1, $v0
  .L8006DED0:
    /* 56D0 8006DED0 12400000 */  mflo       $t0
    /* 56D4 8006DED4 040048AE */  sw         $t0, 0x4($s2)
    /* 56D8 8006DED8 4000A28F */  lw         $v0, 0x40($sp)
    /* 56DC 8006DEDC 5C00BF8F */  lw         $ra, 0x5C($sp)
    /* 56E0 8006DEE0 5800B48F */  lw         $s4, 0x58($sp)
    /* 56E4 8006DEE4 5400B38F */  lw         $s3, 0x54($sp)
    /* 56E8 8006DEE8 5000B28F */  lw         $s2, 0x50($sp)
    /* 56EC 8006DEEC 4C00B18F */  lw         $s1, 0x4C($sp)
    /* 56F0 8006DEF0 4800B08F */  lw         $s0, 0x48($sp)
    /* 56F4 8006DEF4 0800E003 */  jr         $ra
    /* 56F8 8006DEF8 6000BD27 */   addiu     $sp, $sp, 0x60
endlabel _computeStepAndDisplacement
