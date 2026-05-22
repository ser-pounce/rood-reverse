nonmatching func_800A5280, 0x13E0

glabel func_800A5280
    /* 3CA80 800A5280 B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 3CA84 800A5284 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* 3CA88 800A5288 21A88000 */  addu       $s5, $a0, $zero
    /* 3CA8C 800A528C 4400B7AF */  sw         $s7, 0x44($sp)
    /* 3CA90 800A5290 21B8A000 */  addu       $s7, $a1, $zero
    /* 3CA94 800A5294 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 3CA98 800A5298 2188C000 */  addu       $s1, $a2, $zero
    /* 3CA9C 800A529C 4000B6AF */  sw         $s6, 0x40($sp)
    /* 3CAA0 800A52A0 21B0E000 */  addu       $s6, $a3, $zero
    /* 3CAA4 800A52A4 4800BEAF */  sw         $fp, 0x48($sp)
    /* 3CAA8 800A52A8 21F00000 */  addu       $fp, $zero, $zero
    /* 3CAAC 800A52AC 1100A22A */  slti       $v0, $s5, 0x11
    /* 3CAB0 800A52B0 4C00BFAF */  sw         $ra, 0x4C($sp)
    /* 3CAB4 800A52B4 3800B4AF */  sw         $s4, 0x38($sp)
    /* 3CAB8 800A52B8 3400B3AF */  sw         $s3, 0x34($sp)
    /* 3CABC 800A52BC 3000B2AF */  sw         $s2, 0x30($sp)
    /* 3CAC0 800A52C0 17004010 */  beqz       $v0, .L800A5320
    /* 3CAC4 800A52C4 2800B0AF */   sw        $s0, 0x28($sp)
    /* 3CAC8 800A52C8 0F80033C */  lui        $v1, %hi(D_800F4538)
    /* 3CACC 800A52CC 38456324 */  addiu      $v1, $v1, %lo(D_800F4538)
    /* 3CAD0 800A52D0 80101500 */  sll        $v0, $s5, 2
    /* 3CAD4 800A52D4 21104300 */  addu       $v0, $v0, $v1
    /* 3CAD8 800A52D8 0000508C */  lw         $s0, 0x0($v0)
    /* 3CADC 800A52DC 00000000 */  nop
    /* 3CAE0 800A52E0 D2040012 */  beqz       $s0, .L800A662C
    /* 3CAE4 800A52E4 03000224 */   addiu     $v0, $zero, 0x3
    /* 3CAE8 800A52E8 AC05038E */  lw         $v1, 0x5AC($s0)
    /* 3CAEC 800A52EC 00000000 */  nop
    /* 3CAF0 800A52F0 03006230 */  andi       $v0, $v1, 0x3
    /* 3CAF4 800A52F4 CD044014 */  bnez       $v0, .L800A662C
    /* 3CAF8 800A52F8 03000224 */   addiu     $v0, $zero, 0x3
    /* 3CAFC 800A52FC 0800088E */  lw         $t0, 0x8($s0)
    /* 3CB00 800A5300 000F023C */  lui        $v0, (0xF000000 >> 16)
    /* 3CB04 800A5304 24100201 */  and        $v0, $t0, $v0
    /* 3CB08 800A5308 C8044014 */  bnez       $v0, .L800A662C
    /* 3CB0C 800A530C 03000224 */   addiu     $v0, $zero, 0x3
    /* 3CB10 800A5310 1000043C */  lui        $a0, (0x100000 >> 16)
    /* 3CB14 800A5314 24106400 */  and        $v0, $v1, $a0
    /* 3CB18 800A5318 03004010 */  beqz       $v0, .L800A5328
    /* 3CB1C 800A531C 00000000 */   nop
  .L800A5320:
    /* 3CB20 800A5320 8B990208 */  j          .L800A662C
    /* 3CB24 800A5324 03000224 */   addiu     $v0, $zero, 0x3
  .L800A5328:
    /* 3CB28 800A5328 11000282 */  lb         $v0, 0x11($s0)
    /* 3CB2C 800A532C 00000000 */  nop
    /* 3CB30 800A5330 BE04401C */  bgtz       $v0, .L800A662C
    /* 3CB34 800A5334 03000224 */   addiu     $v0, $zero, 0x3
    /* 3CB38 800A5338 1800023C */  lui        $v0, (0x180000 >> 16)
    /* 3CB3C 800A533C 24100201 */  and        $v0, $t0, $v0
    /* 3CB40 800A5340 4C004414 */  bne        $v0, $a0, .L800A5474
    /* 3CB44 800A5344 00000000 */   nop
    /* 3CB48 800A5348 0C00028E */  lw         $v0, 0xC($s0)
    /* 3CB4C 800A534C 00000000 */  nop
    /* 3CB50 800A5350 0F004230 */  andi       $v0, $v0, 0xF
    /* 3CB54 800A5354 30004010 */  beqz       $v0, .L800A5418
    /* 3CB58 800A5358 00000000 */   nop
    /* 3CB5C 800A535C D5B3020C */  jal        func_800ACF54
    /* 3CB60 800A5360 21200002 */   addu      $a0, $s0, $zero
    /* 3CB64 800A5364 0F80023C */  lui        $v0, %hi(D_800F1D6E)
    /* 3CB68 800A5368 0C000392 */  lbu        $v1, 0xC($s0)
    /* 3CB6C 800A536C 6E1D4224 */  addiu      $v0, $v0, %lo(D_800F1D6E)
    /* 3CB70 800A5370 0F006330 */  andi       $v1, $v1, 0xF
    /* 3CB74 800A5374 21186200 */  addu       $v1, $v1, $v0
    /* 3CB78 800A5378 00006390 */  lbu        $v1, 0x0($v1)
    /* 3CB7C 800A537C 07000224 */  addiu      $v0, $zero, 0x7
    /* 3CB80 800A5380 25006214 */  bne        $v1, $v0, .L800A5418
    /* 3CB84 800A5384 1C000426 */   addiu     $a0, $s0, 0x1C
    /* 3CB88 800A5388 21280000 */  addu       $a1, $zero, $zero
    /* 3CB8C 800A538C 2130A000 */  addu       $a2, $a1, $zero
    /* 3CB90 800A5390 BA9B020C */  jal        func_800A6EE8
    /* 3CB94 800A5394 01000724 */   addiu     $a3, $zero, 0x1
    /* 3CB98 800A5398 1E000386 */  lh         $v1, 0x1E($s0)
    /* 3CB9C 800A539C 00000000 */  nop
    /* 3CBA0 800A53A0 2A186200 */  slt        $v1, $v1, $v0
    /* 3CBA4 800A53A4 1C006014 */  bnez       $v1, .L800A5418
    /* 3CBA8 800A53A8 00000000 */   nop
  .L800A53AC:
    /* 3CBAC 800A53AC F8FF053C */  lui        $a1, (0xFFF8FFFF >> 16)
    /* 3CBB0 800A53B0 FFFFA534 */  ori        $a1, $a1, (0xFFF8FFFF & 0xFFFF)
    /* 3CBB4 800A53B4 E7FF063C */  lui        $a2, (0xFFE7FFFF >> 16)
    /* 3CBB8 800A53B8 FFFFC634 */  ori        $a2, $a2, (0xFFE7FFFF & 0xFFFF)
    /* 3CBBC 800A53BC FF0F073C */  lui        $a3, (0xFFFFFFF >> 16)
    /* 3CBC0 800A53C0 FFFFE734 */  ori        $a3, $a3, (0xFFFFFFF & 0xFFFF)
    /* 3CBC4 800A53C4 03000224 */  addiu      $v0, $zero, 0x3
    /* 3CBC8 800A53C8 21184000 */  addu       $v1, $v0, $zero
    /* 3CBCC 800A53CC 360003A6 */  sh         $v1, 0x36($s0)
    /* 3CBD0 800A53D0 0800038E */  lw         $v1, 0x8($s0)
    /* 3CBD4 800A53D4 FF000424 */  addiu      $a0, $zero, 0xFF
    /* 3CBD8 800A53D8 E30604A2 */  sb         $a0, 0x6E3($s0)
    /* 3CBDC 800A53DC 0300043C */  lui        $a0, (0x30000 >> 16)
    /* 3CBE0 800A53E0 24186500 */  and        $v1, $v1, $a1
    /* 3CBE4 800A53E4 25186400 */  or         $v1, $v1, $a0
    /* 3CBE8 800A53E8 24186600 */  and        $v1, $v1, $a2
    /* 3CBEC 800A53EC FFBF0424 */  addiu      $a0, $zero, -0x4001
    /* 3CBF0 800A53F0 24186400 */  and        $v1, $v1, $a0
    /* 3CBF4 800A53F4 F0FF0524 */  addiu      $a1, $zero, -0x10
    /* 3CBF8 800A53F8 080003AE */  sw         $v1, 0x8($s0)
    /* 3CBFC 800A53FC 0C00038E */  lw         $v1, 0xC($s0)
    /* 3CC00 800A5400 AC05048E */  lw         $a0, 0x5AC($s0)
    /* 3CC04 800A5404 24186500 */  and        $v1, $v1, $a1
    /* 3CC08 800A5408 24208700 */  and        $a0, $a0, $a3
    /* 3CC0C 800A540C 0C0003AE */  sw         $v1, 0xC($s0)
    /* 3CC10 800A5410 8B990208 */  j          .L800A662C
    /* 3CC14 800A5414 AC0504AE */   sw        $a0, 0x5AC($s0)
  .L800A5418:
    /* 3CC18 800A5418 84042012 */  beqz       $s1, .L800A662C
    /* 3CC1C 800A541C 03000224 */   addiu     $v0, $zero, 0x3
    /* 3CC20 800A5420 00180396 */  lhu        $v1, 0x1800($s0)
    /* 3CC24 800A5424 00000000 */  nop
    /* 3CC28 800A5428 2310E302 */  subu       $v0, $s7, $v1
    /* 3CC2C 800A542C FF0F4530 */  andi       $a1, $v0, 0xFFF
    /* 3CC30 800A5430 00FCA224 */  addiu      $v0, $a1, -0x400
    /* 3CC34 800A5434 0108422C */  sltiu      $v0, $v0, 0x801
    /* 3CC38 800A5438 DCFF4014 */  bnez       $v0, .L800A53AC
    /* 3CC3C 800A543C 00000000 */   nop
    /* 3CC40 800A5440 1A000296 */  lhu        $v0, 0x1A($s0)
    /* 3CC44 800A5444 00000000 */  nop
    /* 3CC48 800A5448 78044014 */  bnez       $v0, .L800A662C
    /* 3CC4C 800A544C 03000224 */   addiu     $v0, $zero, 0x3
    /* 3CC50 800A5450 B9050292 */  lbu        $v0, 0x5B9($s0)
    /* 3CC54 800A5454 00000000 */  nop
    /* 3CC58 800A5458 00130200 */  sll        $v0, $v0, 12
    /* 3CC5C 800A545C 2A102202 */  slt        $v0, $s1, $v0
    /* 3CC60 800A5460 22004014 */  bnez       $v0, .L800A54EC
    /* 3CC64 800A5464 21B86000 */   addu      $s7, $v1, $zero
    /* 3CC68 800A5468 BA050292 */  lbu        $v0, 0x5BA($s0)
    /* 3CC6C 800A546C 3B950208 */  j          .L800A54EC
    /* 3CC70 800A5470 008B0200 */   sll       $s1, $v0, 12
  .L800A5474:
    /* 3CC74 800A5474 1D004010 */  beqz       $v0, .L800A54EC
    /* 3CC78 800A5478 00000000 */   nop
    /* 3CC7C 800A547C 00180296 */  lhu        $v0, 0x1800($s0)
    /* 3CC80 800A5480 00000000 */  nop
    /* 3CC84 800A5484 2310E202 */  subu       $v0, $s7, $v0
    /* 3CC88 800A5488 FF0F4530 */  andi       $a1, $v0, 0xFFF
    /* 3CC8C 800A548C 67042012 */  beqz       $s1, .L800A662C
    /* 3CC90 800A5490 03000224 */   addiu     $v0, $zero, 0x3
    /* 3CC94 800A5494 0104A228 */  slti       $v0, $a1, 0x401
    /* 3CC98 800A5498 64044014 */  bnez       $v0, .L800A662C
    /* 3CC9C 800A549C 03000224 */   addiu     $v0, $zero, 0x3
    /* 3CCA0 800A54A0 000CA228 */  slti       $v0, $a1, 0xC00
    /* 3CCA4 800A54A4 9EFF4010 */  beqz       $v0, .L800A5320
    /* 3CCA8 800A54A8 01001E24 */   addiu     $fp, $zero, 0x1
    /* 3CCAC 800A54AC E7FF033C */  lui        $v1, (0xFFE7FFFF >> 16)
    /* 3CCB0 800A54B0 FFFF6334 */  ori        $v1, $v1, (0xFFE7FFFF & 0xFFFF)
    /* 3CCB4 800A54B4 2120A002 */  addu       $a0, $s5, $zero
    /* 3CCB8 800A54B8 2128C003 */  addu       $a1, $fp, $zero
    /* 3CCBC 800A54BC 21300000 */  addu       $a2, $zero, $zero
    /* 3CCC0 800A54C0 0A000724 */  addiu      $a3, $zero, 0xA
    /* 3CCC4 800A54C4 24180301 */  and        $v1, $t0, $v1
    /* 3CCC8 800A54C8 FFBF0224 */  addiu      $v0, $zero, -0x4001
    /* 3CCCC 800A54CC 24186200 */  and        $v1, $v1, $v0
    /* 3CCD0 800A54D0 080003AE */  sw         $v1, 0x8($s0)
    /* 3CCD4 800A54D4 1A0000A6 */  sh         $zero, 0x1A($s0)
    /* 3CCD8 800A54D8 340000A6 */  sh         $zero, 0x34($s0)
    /* 3CCDC 800A54DC 360000A6 */  sh         $zero, 0x36($s0)
    /* 3CCE0 800A54E0 380000A6 */  sh         $zero, 0x38($s0)
    /* 3CCE4 800A54E4 8180020C */  jal        func_800A0204
    /* 3CCE8 800A54E8 EC0600A6 */   sh        $zero, 0x6EC($s0)
  .L800A54EC:
    /* 3CCEC 800A54EC 0800028E */  lw         $v0, 0x8($s0)
    /* 3CCF0 800A54F0 0700033C */  lui        $v1, (0x70000 >> 16)
    /* 3CCF4 800A54F4 24104300 */  and        $v0, $v0, $v1
    /* 3CCF8 800A54F8 24004010 */  beqz       $v0, .L800A558C
    /* 3CCFC 800A54FC 00000000 */   nop
    /* 3CD00 800A5500 4A04A016 */  bnez       $s5, .L800A662C
    /* 3CD04 800A5504 03000224 */   addiu     $v0, $zero, 0x3
    /* 3CD08 800A5508 02002106 */  bgez       $s1, .L800A5514
    /* 3CD0C 800A550C 21102002 */   addu      $v0, $s1, $zero
    /* 3CD10 800A5510 FF0F2226 */  addiu      $v0, $s1, 0xFFF
  .L800A5514:
    /* 3CD14 800A5514 B9050392 */  lbu        $v1, 0x5B9($s0)
    /* 3CD18 800A5518 03130200 */  sra        $v0, $v0, 12
    /* 3CD1C 800A551C 2A104300 */  slt        $v0, $v0, $v1
    /* 3CD20 800A5520 09004014 */  bnez       $v0, .L800A5548
    /* 3CD24 800A5524 FBFF0324 */   addiu     $v1, $zero, -0x5
    /* 3CD28 800A5528 B005028E */  lw         $v0, 0x5B0($s0)
    /* 3CD2C 800A552C 00000000 */  nop
    /* 3CD30 800A5530 04004230 */  andi       $v0, $v0, 0x4
    /* 3CD34 800A5534 08004014 */  bnez       $v0, .L800A5558
    /* 3CD38 800A5538 00000000 */   nop
    /* 3CD3C 800A553C BA050292 */  lbu        $v0, 0x5BA($s0)
    /* 3CD40 800A5540 56950208 */  j          .L800A5558
    /* 3CD44 800A5544 008B0200 */   sll       $s1, $v0, 12
  .L800A5548:
    /* 3CD48 800A5548 B005028E */  lw         $v0, 0x5B0($s0)
    /* 3CD4C 800A554C 00000000 */  nop
    /* 3CD50 800A5550 24104300 */  and        $v0, $v0, $v1
    /* 3CD54 800A5554 B00502AE */  sw         $v0, 0x5B0($s0)
  .L800A5558:
    /* 3CD58 800A5558 0A000296 */  lhu        $v0, 0xA($s0)
    /* 3CD5C 800A555C 00000000 */  nop
    /* 3CD60 800A5560 07004330 */  andi       $v1, $v0, 0x7
    /* 3CD64 800A5564 09006010 */  beqz       $v1, .L800A558C
    /* 3CD68 800A5568 04006228 */   slti      $v0, $v1, 0x4
    /* 3CD6C 800A556C 05004014 */  bnez       $v0, .L800A5584
    /* 3CD70 800A5570 04000224 */   addiu     $v0, $zero, 0x4
    /* 3CD74 800A5574 06006214 */  bne        $v1, $v0, .L800A5590
    /* 3CD78 800A5578 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 3CD7C 800A557C 8B990208 */  j          .L800A662C
    /* 3CD80 800A5580 03000224 */   addiu     $v0, $zero, 0x3
  .L800A5584:
    /* 3CD84 800A5584 76002012 */  beqz       $s1, .L800A5760
    /* 3CD88 800A5588 00000000 */   nop
  .L800A558C:
    /* 3CD8C 800A558C FFFF0224 */  addiu      $v0, $zero, -0x1
  .L800A5590:
    /* 3CD90 800A5590 1D002216 */  bne        $s1, $v0, .L800A5608
    /* 3CD94 800A5594 00000000 */   nop
    /* 3CD98 800A5598 0000C286 */  lh         $v0, 0x0($s6)
    /* 3CD9C 800A559C 00000000 */  nop
    /* 3CDA0 800A55A0 10004014 */  bnez       $v0, .L800A55E4
    /* 3CDA4 800A55A4 00000000 */   nop
    /* 3CDA8 800A55A8 0400C286 */  lh         $v0, 0x4($s6)
    /* 3CDAC 800A55AC 00000000 */  nop
    /* 3CDB0 800A55B0 0C004014 */  bnez       $v0, .L800A55E4
    /* 3CDB4 800A55B4 00000000 */   nop
    /* 3CDB8 800A55B8 B8050392 */  lbu        $v1, 0x5B8($s0)
    /* 3CDBC 800A55BC 00000000 */  nop
    /* 3CDC0 800A55C0 64006228 */  slti       $v0, $v1, 0x64
    /* 3CDC4 800A55C4 02004014 */  bnez       $v0, .L800A55D0
    /* 3CDC8 800A55C8 01000224 */   addiu     $v0, $zero, 0x1
    /* 3CDCC 800A55CC 9CFF6324 */  addiu      $v1, $v1, -0x64
  .L800A55D0:
    /* 3CDD0 800A55D0 62006210 */  beq        $v1, $v0, .L800A575C
    /* 3CDD4 800A55D4 F3FF6224 */   addiu     $v0, $v1, -0xD
    /* 3CDD8 800A55D8 0E00422C */  sltiu      $v0, $v0, 0xE
    /* 3CDDC 800A55DC 13044010 */  beqz       $v0, .L800A662C
    /* 3CDE0 800A55E0 03000224 */   addiu     $v0, $zero, 0x3
  .L800A55E4:
    /* 3CDE4 800A55E4 0000C296 */  lhu        $v0, 0x0($s6)
    /* 3CDE8 800A55E8 00000000 */  nop
    /* 3CDEC 800A55EC 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 3CDF0 800A55F0 0400C296 */  lhu        $v0, 0x4($s6)
    /* 3CDF4 800A55F4 00000000 */  nop
    /* 3CDF8 800A55F8 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 3CDFC 800A55FC BA050292 */  lbu        $v0, 0x5BA($s0)
    /* 3CE00 800A5600 41960208 */  j          .L800A5904
    /* 3CE04 800A5604 009B0200 */   sll       $s3, $v0, 12
  .L800A5608:
    /* 3CE08 800A5608 5A002016 */  bnez       $s1, .L800A5774
    /* 3CE0C 800A560C FFFF033C */   lui       $v1, (0xFFFF7FFF >> 16)
    /* 3CE10 800A5610 AC05028E */  lw         $v0, 0x5AC($s0)
    /* 3CE14 800A5614 00000000 */  nop
    /* 3CE18 800A5618 00804230 */  andi       $v0, $v0, 0x8000
    /* 3CE1C 800A561C 13004010 */  beqz       $v0, .L800A566C
    /* 3CE20 800A5620 00000000 */   nop
    /* 3CE24 800A5624 0600C286 */  lh         $v0, 0x6($s6)
    /* 3CE28 800A5628 00000000 */  nop
    /* 3CE2C 800A562C 0F004014 */  bnez       $v0, .L800A566C
    /* 3CE30 800A5630 0680023C */   lui       $v0, %hi(vs_gametime_tickspeed)
  .L800A5634:
    /* 3CE34 800A5634 40181186 */  lh         $s1, 0x1840($s0)
    /* 3CE38 800A5638 4CE2428C */  lw         $v0, %lo(vs_gametime_tickspeed)($v0)
    /* 3CE3C 800A563C 42181786 */  lh         $s7, 0x1842($s0)
    /* 3CE40 800A5640 23882202 */  subu       $s1, $s1, $v0
    /* 3CE44 800A5644 0700201E */  bgtz       $s1, .L800A5664
    /* 3CE48 800A5648 401811A6 */   sh        $s1, 0x1840($s0)
    /* 3CE4C 800A564C FFFF033C */  lui        $v1, (0xFFFF7FFF >> 16)
    /* 3CE50 800A5650 FF7F6334 */  ori        $v1, $v1, (0xFFFF7FFF & 0xFFFF)
    /* 3CE54 800A5654 AC05028E */  lw         $v0, 0x5AC($s0)
    /* 3CE58 800A5658 21880000 */  addu       $s1, $zero, $zero
    /* 3CE5C 800A565C 24104300 */  and        $v0, $v0, $v1
    /* 3CE60 800A5660 AC0502AE */  sw         $v0, 0x5AC($s0)
  .L800A5664:
    /* 3CE64 800A5664 14960208 */  j          .L800A5850
    /* 3CE68 800A5668 008B1100 */   sll       $s1, $s1, 12
  .L800A566C:
    /* 3CE6C 800A566C 40180286 */  lh         $v0, 0x1840($s0)
    /* 3CE70 800A5670 B9050392 */  lbu        $v1, 0x5B9($s0)
    /* 3CE74 800A5674 00000000 */  nop
    /* 3CE78 800A5678 2A104300 */  slt        $v0, $v0, $v1
    /* 3CE7C 800A567C 16004014 */  bnez       $v0, .L800A56D8
    /* 3CE80 800A5680 00000000 */   nop
    /* 3CE84 800A5684 46180292 */  lbu        $v0, 0x1846($s0)
    /* 3CE88 800A5688 00000000 */  nop
    /* 3CE8C 800A568C 1400422C */  sltiu      $v0, $v0, 0x14
    /* 3CE90 800A5690 10004014 */  bnez       $v0, .L800A56D4
    /* 3CE94 800A5694 00000000 */   nop
    /* 3CE98 800A5698 47180292 */  lbu        $v0, 0x1847($s0)
    /* 3CE9C 800A569C 00000000 */  nop
    /* 3CEA0 800A56A0 0900422C */  sltiu      $v0, $v0, 0x9
    /* 3CEA4 800A56A4 0B004010 */  beqz       $v0, .L800A56D4
    /* 3CEA8 800A56A8 00000000 */   nop
    /* 3CEAC 800A56AC AC05028E */  lw         $v0, 0x5AC($s0)
    /* 3CEB0 800A56B0 461800A2 */  sb         $zero, 0x1846($s0)
    /* 3CEB4 800A56B4 00804234 */  ori        $v0, $v0, 0x8000
    /* 3CEB8 800A56B8 AC0502AE */  sw         $v0, 0x5AC($s0)
    /* 3CEBC 800A56BC 0600C286 */  lh         $v0, 0x6($s6)
    /* 3CEC0 800A56C0 00000000 */  nop
    /* 3CEC4 800A56C4 DBFF4010 */  beqz       $v0, .L800A5634
    /* 3CEC8 800A56C8 0680023C */   lui       $v0, %hi(vs_gametime_tickspeed)
    /* 3CECC 800A56CC 81990208 */  j          .L800A6604
    /* 3CED0 800A56D0 00000000 */   nop
  .L800A56D4:
    /* 3CED4 800A56D4 461800A2 */  sb         $zero, 0x1846($s0)
  .L800A56D8:
    /* 3CED8 800A56D8 E4060292 */  lbu        $v0, 0x6E4($s0)
    /* 3CEDC 800A56DC 00000000 */  nop
    /* 3CEE0 800A56E0 1F004014 */  bnez       $v0, .L800A5760
    /* 3CEE4 800A56E4 21980000 */   addu      $s3, $zero, $zero
    /* 3CEE8 800A56E8 40180286 */  lh         $v0, 0x1840($s0)
    /* 3CEEC 800A56EC 00000000 */  nop
    /* 3CEF0 800A56F0 06004014 */  bnez       $v0, .L800A570C
    /* 3CEF4 800A56F4 00000000 */   nop
    /* 3CEF8 800A56F8 0C00028E */  lw         $v0, 0xC($s0)
    /* 3CEFC 800A56FC 00000000 */  nop
    /* 3CF00 800A5700 0F004230 */  andi       $v0, $v0, 0xF
    /* 3CF04 800A5704 03004010 */  beqz       $v0, .L800A5714
    /* 3CF08 800A5708 00000000 */   nop
  .L800A570C:
    /* 3CF0C 800A570C D7950208 */  j          .L800A575C
    /* 3CF10 800A5710 401800A6 */   sh        $zero, 0x1840($s0)
  .L800A5714:
    /* 3CF14 800A5714 AC05028E */  lw         $v0, 0x5AC($s0)
    /* 3CF18 800A5718 00000000 */  nop
    /* 3CF1C 800A571C 00104230 */  andi       $v0, $v0, 0x1000
    /* 3CF20 800A5720 0F004014 */  bnez       $v0, .L800A5760
    /* 3CF24 800A5724 21980000 */   addu      $s3, $zero, $zero
    /* 3CF28 800A5728 B8050392 */  lbu        $v1, 0x5B8($s0)
    /* 3CF2C 800A572C 00000000 */  nop
    /* 3CF30 800A5730 64006228 */  slti       $v0, $v1, 0x64
    /* 3CF34 800A5734 02004014 */  bnez       $v0, .L800A5740
    /* 3CF38 800A5738 54000224 */   addiu     $v0, $zero, 0x54
    /* 3CF3C 800A573C 9CFF6324 */  addiu      $v1, $v1, -0x64
  .L800A5740:
    /* 3CF40 800A5740 06006210 */  beq        $v1, $v0, .L800A575C
    /* 3CF44 800A5744 01000224 */   addiu     $v0, $zero, 0x1
    /* 3CF48 800A5748 F5FE6210 */  beq        $v1, $v0, .L800A5320
    /* 3CF4C 800A574C F3FF6224 */   addiu     $v0, $v1, -0xD
    /* 3CF50 800A5750 0E00422C */  sltiu      $v0, $v0, 0xE
    /* 3CF54 800A5754 B5034010 */  beqz       $v0, .L800A662C
    /* 3CF58 800A5758 03000224 */   addiu     $v0, $zero, 0x3
  .L800A575C:
    /* 3CF5C 800A575C 21980000 */  addu       $s3, $zero, $zero
  .L800A5760:
    /* 3CF60 800A5760 340000A6 */  sh         $zero, 0x34($s0)
    /* 3CF64 800A5764 380000A6 */  sh         $zero, 0x38($s0)
    /* 3CF68 800A5768 1000A0A7 */  sh         $zero, 0x10($sp)
    /* 3CF6C 800A576C 41960208 */  j          .L800A5904
    /* 3CF70 800A5770 1400A0A7 */   sh        $zero, 0x14($sp)
  .L800A5774:
    /* 3CF74 800A5774 FF7F6334 */  ori        $v1, $v1, (0xFFFF7FFF & 0xFFFF)
    /* 3CF78 800A5778 AC05028E */  lw         $v0, 0x5AC($s0)
    /* 3CF7C 800A577C 21202002 */  addu       $a0, $s1, $zero
    /* 3CF80 800A5780 24104300 */  and        $v0, $v0, $v1
    /* 3CF84 800A5784 02002106 */  bgez       $s1, .L800A5790
    /* 3CF88 800A5788 AC0502AE */   sw        $v0, 0x5AC($s0)
    /* 3CF8C 800A578C FF0F2426 */  addiu      $a0, $s1, 0xFFF
  .L800A5790:
    /* 3CF90 800A5790 B9050292 */  lbu        $v0, 0x5B9($s0)
    /* 3CF94 800A5794 031B0400 */  sra        $v1, $a0, 12
    /* 3CF98 800A5798 00130200 */  sll        $v0, $v0, 12
    /* 3CF9C 800A579C 2A102202 */  slt        $v0, $s1, $v0
    /* 3CFA0 800A57A0 10004014 */  bnez       $v0, .L800A57E4
    /* 3CFA4 800A57A4 401803A6 */   sh        $v1, 0x1840($s0)
    /* 3CFA8 800A57A8 0680023C */  lui        $v0, %hi(vs_gametime_tickspeed)
    /* 3CFAC 800A57AC 46180592 */  lbu        $a1, 0x1846($s0)
    /* 3CFB0 800A57B0 4CE2428C */  lw         $v0, %lo(vs_gametime_tickspeed)($v0)
    /* 3CFB4 800A57B4 00000000 */  nop
    /* 3CFB8 800A57B8 C21F0200 */  srl        $v1, $v0, 31
    /* 3CFBC 800A57BC 21104300 */  addu       $v0, $v0, $v1
    /* 3CFC0 800A57C0 43100200 */  sra        $v0, $v0, 1
    /* 3CFC4 800A57C4 2128A200 */  addu       $a1, $a1, $v0
    /* 3CFC8 800A57C8 0001A228 */  slti       $v0, $a1, 0x100
    /* 3CFCC 800A57CC 02004014 */  bnez       $v0, .L800A57D8
    /* 3CFD0 800A57D0 421817A6 */   sh        $s7, 0x1842($s0)
    /* 3CFD4 800A57D4 FF000524 */  addiu      $a1, $zero, 0xFF
  .L800A57D8:
    /* 3CFD8 800A57D8 461805A2 */  sb         $a1, 0x1846($s0)
    /* 3CFDC 800A57DC 05960208 */  j          .L800A5814
    /* 3CFE0 800A57E0 471800A2 */   sb        $zero, 0x1847($s0)
  .L800A57E4:
    /* 3CFE4 800A57E4 0680023C */  lui        $v0, %hi(vs_gametime_tickspeed)
    /* 3CFE8 800A57E8 4CE2428C */  lw         $v0, %lo(vs_gametime_tickspeed)($v0)
    /* 3CFEC 800A57EC 47180592 */  lbu        $a1, 0x1847($s0)
    /* 3CFF0 800A57F0 C21F0200 */  srl        $v1, $v0, 31
    /* 3CFF4 800A57F4 21104300 */  addu       $v0, $v0, $v1
    /* 3CFF8 800A57F8 43100200 */  sra        $v0, $v0, 1
    /* 3CFFC 800A57FC 2128A200 */  addu       $a1, $a1, $v0
    /* 3D000 800A5800 0001A228 */  slti       $v0, $a1, 0x100
    /* 3D004 800A5804 02004014 */  bnez       $v0, .L800A5810
    /* 3D008 800A5808 00000000 */   nop
    /* 3D00C 800A580C FF000524 */  addiu      $a1, $zero, 0xFF
  .L800A5810:
    /* 3D010 800A5810 471805A2 */  sb         $a1, 0x1847($s0)
  .L800A5814:
    /* 3D014 800A5814 0600C386 */  lh         $v1, 0x6($s6)
    /* 3D018 800A5818 01000224 */  addiu      $v0, $zero, 0x1
    /* 3D01C 800A581C 02006214 */  bne        $v1, $v0, .L800A5828
    /* 3D020 800A5820 21A0E002 */   addu      $s4, $s7, $zero
    /* 3D024 800A5824 0000D486 */  lh         $s4, 0x0($s6)
  .L800A5828:
    /* 3D028 800A5828 09002012 */  beqz       $s1, .L800A5850
    /* 3D02C 800A582C FF0F9432 */   andi      $s4, $s4, 0xFFF
    /* 3D030 800A5830 0800028E */  lw         $v0, 0x8($s0)
    /* 3D034 800A5834 1800033C */  lui        $v1, (0x180000 >> 16)
    /* 3D038 800A5838 24104300 */  and        $v0, $v0, $v1
    /* 3D03C 800A583C 04004014 */  bnez       $v0, .L800A5850
    /* 3D040 800A5840 21200002 */   addu      $a0, $s0, $zero
    /* 3D044 800A5844 21288002 */  addu       $a1, $s4, $zero
    /* 3D048 800A5848 9899020C */  jal        func_800A6660
    /* 3D04C 800A584C 2130C002 */   addu      $a2, $s6, $zero
  .L800A5850:
    /* 3D050 800A5850 BE050386 */  lh         $v1, 0x5BE($s0)
    /* 3D054 800A5854 04000224 */  addiu      $v0, $zero, 0x4
    /* 3D058 800A5858 11006210 */  beq        $v1, $v0, .L800A58A0
    /* 3D05C 800A585C 21982002 */   addu      $s3, $s1, $zero
    /* 3D060 800A5860 18002302 */  mult       $s1, $v1
    /* 3D064 800A5864 12180000 */  mflo       $v1
    /* 3D068 800A5868 02006104 */  bgez       $v1, .L800A5874
    /* 3D06C 800A586C 00000000 */   nop
    /* 3D070 800A5870 03006324 */  addiu      $v1, $v1, 0x3
  .L800A5874:
    /* 3D074 800A5874 0600C286 */  lh         $v0, 0x6($s6)
    /* 3D078 800A5878 00000000 */  nop
    /* 3D07C 800A587C 08004014 */  bnez       $v0, .L800A58A0
    /* 3D080 800A5880 83980300 */   sra       $s3, $v1, 2
    /* 3D084 800A5884 0100023C */  lui        $v0, (0x1EFFF >> 16)
    /* 3D088 800A5888 FFEF4234 */  ori        $v0, $v0, (0x1EFFF & 0xFFFF)
    /* 3D08C 800A588C 2A105300 */  slt        $v0, $v0, $s3
    /* 3D090 800A5890 03004010 */  beqz       $v0, .L800A58A0
    /* 3D094 800A5894 00000000 */   nop
    /* 3D098 800A5898 0100133C */  lui        $s3, (0x1F000 >> 16)
    /* 3D09C 800A589C 00F07336 */  ori        $s3, $s3, (0x1F000 & 0xFFFF)
  .L800A58A0:
    /* 3D0A0 800A58A0 5803601A */  blez       $s3, .L800A6604
    /* 3D0A4 800A58A4 000C0224 */   addiu     $v0, $zero, 0xC00
    /* 3D0A8 800A58A8 23905700 */  subu       $s2, $v0, $s7
    /* 3D0AC 800A58AC C903010C */  jal        rcos
    /* 3D0B0 800A58B0 21204002 */   addu      $a0, $s2, $zero
    /* 3D0B4 800A58B4 18005300 */  mult       $v0, $s3
    /* 3D0B8 800A58B8 12180000 */  mflo       $v1
    /* 3D0BC 800A58BC 05006104 */  bgez       $v1, .L800A58D4
    /* 3D0C0 800A58C0 03160300 */   sra       $v0, $v1, 24
    /* 3D0C4 800A58C4 FF00023C */  lui        $v0, (0xFFFFFF >> 16)
    /* 3D0C8 800A58C8 FFFF4234 */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* 3D0CC 800A58CC 21186200 */  addu       $v1, $v1, $v0
    /* 3D0D0 800A58D0 03160300 */  sra        $v0, $v1, 24
  .L800A58D4:
    /* 3D0D4 800A58D4 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 3D0D8 800A58D8 CA03010C */  jal        rsin
    /* 3D0DC 800A58DC 21204002 */   addu      $a0, $s2, $zero
    /* 3D0E0 800A58E0 18005300 */  mult       $v0, $s3
    /* 3D0E4 800A58E4 12180000 */  mflo       $v1
    /* 3D0E8 800A58E8 05006104 */  bgez       $v1, .L800A5900
    /* 3D0EC 800A58EC 03160300 */   sra       $v0, $v1, 24
    /* 3D0F0 800A58F0 FF00023C */  lui        $v0, (0xFFFFFF >> 16)
    /* 3D0F4 800A58F4 FFFF4234 */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* 3D0F8 800A58F8 21186200 */  addu       $v1, $v1, $v0
    /* 3D0FC 800A58FC 03160300 */  sra        $v0, $v1, 24
  .L800A5900:
    /* 3D100 800A5900 1400A2A7 */  sh         $v0, 0x14($sp)
  .L800A5904:
    /* 3D104 800A5904 0800028E */  lw         $v0, 0x8($s0)
    /* 3D108 800A5908 0700033C */  lui        $v1, (0x70000 >> 16)
    /* 3D10C 800A590C 24104300 */  and        $v0, $v0, $v1
    /* 3D110 800A5910 0300033C */  lui        $v1, (0x30000 >> 16)
    /* 3D114 800A5914 13004314 */  bne        $v0, $v1, .L800A5964
    /* 3D118 800A5918 00000000 */   nop
    /* 3D11C 800A591C 1E000286 */  lh         $v0, 0x1E($s0)
    /* 3D120 800A5920 00000000 */  nop
    /* 3D124 800A5924 03004018 */  blez       $v0, .L800A5934
    /* 3D128 800A5928 00000000 */   nop
    /* 3D12C 800A592C EE0600A2 */  sb         $zero, 0x6EE($s0)
    /* 3D130 800A5930 EF0600A2 */  sb         $zero, 0x6EF($s0)
  .L800A5934:
    /* 3D134 800A5934 EE060292 */  lbu        $v0, 0x6EE($s0)
    /* 3D138 800A5938 1000A397 */  lhu        $v1, 0x10($sp)
    /* 3D13C 800A593C 00160200 */  sll        $v0, $v0, 24
    /* 3D140 800A5940 03160200 */  sra        $v0, $v0, 24
    /* 3D144 800A5944 21186200 */  addu       $v1, $v1, $v0
    /* 3D148 800A5948 1000A3A7 */  sh         $v1, 0x10($sp)
    /* 3D14C 800A594C EF060292 */  lbu        $v0, 0x6EF($s0)
    /* 3D150 800A5950 1400A397 */  lhu        $v1, 0x14($sp)
    /* 3D154 800A5954 00160200 */  sll        $v0, $v0, 24
    /* 3D158 800A5958 03160200 */  sra        $v0, $v0, 24
    /* 3D15C 800A595C 21186200 */  addu       $v1, $v1, $v0
    /* 3D160 800A5960 1400A3A7 */  sh         $v1, 0x14($sp)
  .L800A5964:
    /* 3D164 800A5964 AC05028E */  lw         $v0, 0x5AC($s0)
    /* 3D168 800A5968 00000000 */  nop
    /* 3D16C 800A596C 00104230 */  andi       $v0, $v0, 0x1000
    /* 3D170 800A5970 0D004010 */  beqz       $v0, .L800A59A8
    /* 3D174 800A5974 00000000 */   nop
    /* 3D178 800A5978 1000A287 */  lh         $v0, 0x10($sp)
    /* 3D17C 800A597C 00000000 */  nop
    /* 3D180 800A5980 02004104 */  bgez       $v0, .L800A598C
    /* 3D184 800A5984 00000000 */   nop
    /* 3D188 800A5988 03004224 */  addiu      $v0, $v0, 0x3
  .L800A598C:
    /* 3D18C 800A598C 1400A387 */  lh         $v1, 0x14($sp)
    /* 3D190 800A5990 83100200 */  sra        $v0, $v0, 2
    /* 3D194 800A5994 02006104 */  bgez       $v1, .L800A59A0
    /* 3D198 800A5998 1000A2A7 */   sh        $v0, 0x10($sp)
    /* 3D19C 800A599C 03006324 */  addiu      $v1, $v1, 0x3
  .L800A59A0:
    /* 3D1A0 800A59A0 83100300 */  sra        $v0, $v1, 2
    /* 3D1A4 800A59A4 1400A2A7 */  sh         $v0, 0x14($sp)
  .L800A59A8:
    /* 3D1A8 800A59A8 21200002 */  addu       $a0, $s0, $zero
    /* 3D1AC 800A59AC 1000A527 */  addiu      $a1, $sp, 0x10
    /* 3D1B0 800A59B0 2000A627 */  addiu      $a2, $sp, 0x20
    /* 3D1B4 800A59B4 0600C786 */  lh         $a3, 0x6($s6)
    /* 3D1B8 800A59B8 0F80023C */  lui        $v0, %hi(D_800E90BC)
    /* 3D1BC 800A59BC AF9D020C */  jal        func_800A76BC
    /* 3D1C0 800A59C0 BC9040AC */   sw        $zero, %lo(D_800E90BC)($v0)
    /* 3D1C4 800A59C4 21904000 */  addu       $s2, $v0, $zero
    /* 3D1C8 800A59C8 01000224 */  addiu      $v0, $zero, 0x1
    /* 3D1CC 800A59CC 13004212 */  beq        $s2, $v0, .L800A5A1C
    /* 3D1D0 800A59D0 0200422A */   slti      $v0, $s2, 0x2
    /* 3D1D4 800A59D4 05004010 */  beqz       $v0, .L800A59EC
    /* 3D1D8 800A59D8 00000000 */   nop
    /* 3D1DC 800A59DC 0A004012 */  beqz       $s2, .L800A5A08
    /* 3D1E0 800A59E0 1C000426 */   addiu     $a0, $s0, 0x1C
    /* 3D1E4 800A59E4 B7960208 */  j          .L800A5ADC
    /* 3D1E8 800A59E8 00000000 */   nop
  .L800A59EC:
    /* 3D1EC 800A59EC 02000224 */  addiu      $v0, $zero, 0x2
    /* 3D1F0 800A59F0 0D004212 */  beq        $s2, $v0, .L800A5A28
    /* 3D1F4 800A59F4 03000224 */   addiu     $v0, $zero, 0x3
    /* 3D1F8 800A59F8 11004212 */  beq        $s2, $v0, .L800A5A40
    /* 3D1FC 800A59FC 1C000426 */   addiu     $a0, $s0, 0x1C
    /* 3D200 800A5A00 B7960208 */  j          .L800A5ADC
    /* 3D204 800A5A04 00000000 */   nop
  .L800A5A08:
    /* 3D208 800A5A08 02006106 */  bgez       $s3, .L800A5A14
    /* 3D20C 800A5A0C 21106002 */   addu      $v0, $s3, $zero
    /* 3D210 800A5A10 FF0F6226 */  addiu      $v0, $s3, 0xFFF
  .L800A5A14:
    /* 3D214 800A5A14 B6960208 */  j          .L800A5AD8
    /* 3D218 800A5A18 038B0200 */   sra       $s1, $v0, 12
  .L800A5A1C:
    /* 3D21C 800A5A1C 1000B187 */  lh         $s1, 0x10($sp)
    /* 3D220 800A5A20 8B960208 */  j          .L800A5A2C
    /* 3D224 800A5A24 00000000 */   nop
  .L800A5A28:
    /* 3D228 800A5A28 1400B187 */  lh         $s1, 0x14($sp)
  .L800A5A2C:
    /* 3D22C 800A5A2C 00000000 */  nop
    /* 3D230 800A5A30 2A002106 */  bgez       $s1, .L800A5ADC
    /* 3D234 800A5A34 1C000426 */   addiu     $a0, $s0, 0x1C
    /* 3D238 800A5A38 B7960208 */  j          .L800A5ADC
    /* 3D23C 800A5A3C 23881100 */   negu      $s1, $s1
  .L800A5A40:
    /* 3D240 800A5A40 0800048E */  lw         $a0, 0x8($s0)
    /* 3D244 800A5A44 1800023C */  lui        $v0, (0x180000 >> 16)
    /* 3D248 800A5A48 1000033C */  lui        $v1, (0x100000 >> 16)
    /* 3D24C 800A5A4C 24108200 */  and        $v0, $a0, $v0
    /* 3D250 800A5A50 33FE4310 */  beq        $v0, $v1, .L800A5320
    /* 3D254 800A5A54 21880000 */   addu      $s1, $zero, $zero
    /* 3D258 800A5A58 0600C013 */  beqz       $fp, .L800A5A74
    /* 3D25C 800A5A5C F8FF023C */   lui       $v0, (0xFFF8FFFF >> 16)
    /* 3D260 800A5A60 FFFF4234 */  ori        $v0, $v0, (0xFFF8FFFF & 0xFFFF)
    /* 3D264 800A5A64 24108200 */  and        $v0, $a0, $v0
    /* 3D268 800A5A68 0300033C */  lui        $v1, (0x30000 >> 16)
    /* 3D26C 800A5A6C 25104300 */  or         $v0, $v0, $v1
    /* 3D270 800A5A70 080002AE */  sw         $v0, 0x8($s0)
  .L800A5A74:
    /* 3D274 800A5A74 0800028E */  lw         $v0, 0x8($s0)
    /* 3D278 800A5A78 0700043C */  lui        $a0, (0x70000 >> 16)
    /* 3D27C 800A5A7C 24104400 */  and        $v0, $v0, $a0
    /* 3D280 800A5A80 13004010 */  beqz       $v0, .L800A5AD0
    /* 3D284 800A5A84 0100023C */   lui       $v0, (0x10000 >> 16)
    /* 3D288 800A5A88 0800038E */  lw         $v1, 0x8($s0)
    /* 3D28C 800A5A8C 340000A6 */  sh         $zero, 0x34($s0)
    /* 3D290 800A5A90 24186400 */  and        $v1, $v1, $a0
    /* 3D294 800A5A94 22FE6214 */  bne        $v1, $v0, .L800A5320
    /* 3D298 800A5A98 380000A6 */   sh        $zero, 0x38($s0)
    /* 3D29C 800A5A9C 2120A002 */  addu       $a0, $s5, $zero
    /* 3D2A0 800A5AA0 30000524 */  addiu      $a1, $zero, 0x30
    /* 3D2A4 800A5AA4 21300000 */  addu       $a2, $zero, $zero
    /* 3D2A8 800A5AA8 8180020C */  jal        func_800A0204
    /* 3D2AC 800A5AAC 02000724 */   addiu     $a3, $zero, 0x2
    /* 3D2B0 800A5AB0 F8FF023C */  lui        $v0, (0xFFF8FFFF >> 16)
    /* 3D2B4 800A5AB4 0800038E */  lw         $v1, 0x8($s0)
    /* 3D2B8 800A5AB8 FFFF4234 */  ori        $v0, $v0, (0xFFF8FFFF & 0xFFFF)
    /* 3D2BC 800A5ABC 24186200 */  and        $v1, $v1, $v0
    /* 3D2C0 800A5AC0 0200023C */  lui        $v0, (0x20000 >> 16)
    /* 3D2C4 800A5AC4 25186200 */  or         $v1, $v1, $v0
    /* 3D2C8 800A5AC8 C8940208 */  j          .L800A5320
    /* 3D2CC 800A5ACC 080003AE */   sw        $v1, 0x8($s0)
  .L800A5AD0:
    /* 3D2D0 800A5AD0 1000A0A7 */  sh         $zero, 0x10($sp)
    /* 3D2D4 800A5AD4 1400A0A7 */  sh         $zero, 0x14($sp)
  .L800A5AD8:
    /* 3D2D8 800A5AD8 1C000426 */  addiu      $a0, $s0, 0x1C
  .L800A5ADC:
    /* 3D2DC 800A5ADC 1000A587 */  lh         $a1, 0x10($sp)
    /* 3D2E0 800A5AE0 1400A687 */  lh         $a2, 0x14($sp)
    /* 3D2E4 800A5AE4 BA9B020C */  jal        func_800A6EE8
    /* 3D2E8 800A5AE8 01000724 */   addiu     $a3, $zero, 0x1
    /* 3D2EC 800A5AEC 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 3D2F0 800A5AF0 1E000396 */  lhu        $v1, 0x1E($s0)
    /* 3D2F4 800A5AF4 00000000 */  nop
    /* 3D2F8 800A5AF8 23104300 */  subu       $v0, $v0, $v1
    /* 3D2FC 800A5AFC 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 3D300 800A5B00 0800028E */  lw         $v0, 0x8($s0)
    /* 3D304 800A5B04 1F00033C */  lui        $v1, (0x1F0000 >> 16)
    /* 3D308 800A5B08 24104300 */  and        $v0, $v0, $v1
    /* 3D30C 800A5B0C 13004014 */  bnez       $v0, .L800A5B5C
    /* 3D310 800A5B10 FF0F033C */   lui       $v1, (0xFFFFFFF >> 16)
    /* 3D314 800A5B14 FFFF6334 */  ori        $v1, $v1, (0xFFFFFFF & 0xFFFF)
    /* 3D318 800A5B18 0F80023C */  lui        $v0, %hi(D_800F49F8)
    /* 3D31C 800A5B1C AC05048E */  lw         $a0, 0x5AC($s0)
    /* 3D320 800A5B20 F8494290 */  lbu        $v0, %lo(D_800F49F8)($v0)
    /* 3D324 800A5B24 024F0400 */  srl        $t1, $a0, 28
    /* 3D328 800A5B28 24208300 */  and        $a0, $a0, $v1
    /* 3D32C 800A5B2C 00170200 */  sll        $v0, $v0, 28
    /* 3D330 800A5B30 25208200 */  or         $a0, $a0, $v0
    /* 3D334 800A5B34 0F80023C */  lui        $v0, %hi(D_800F49F4)
    /* 3D338 800A5B38 2400A9AF */  sw         $t1, 0x24($sp)
    /* 3D33C 800A5B3C 0C00038E */  lw         $v1, 0xC($s0)
    /* 3D340 800A5B40 F4494290 */  lbu        $v0, %lo(D_800F49F4)($v0)
    /* 3D344 800A5B44 F0FF0524 */  addiu      $a1, $zero, -0x10
    /* 3D348 800A5B48 AC0504AE */  sw         $a0, 0x5AC($s0)
    /* 3D34C 800A5B4C 24186500 */  and        $v1, $v1, $a1
    /* 3D350 800A5B50 0F004230 */  andi       $v0, $v0, 0xF
    /* 3D354 800A5B54 25186200 */  or         $v1, $v1, $v0
    /* 3D358 800A5B58 0C0003AE */  sw         $v1, 0xC($s0)
  .L800A5B5C:
    /* 3D35C 800A5B5C 0600C286 */  lh         $v0, 0x6($s6)
    /* 3D360 800A5B60 00000000 */  nop
    /* 3D364 800A5B64 3E004014 */  bnez       $v0, .L800A5C60
    /* 3D368 800A5B68 00000000 */   nop
    /* 3D36C 800A5B6C 1200A387 */  lh         $v1, 0x12($sp)
    /* 3D370 800A5B70 1200A497 */  lhu        $a0, 0x12($sp)
    /* 3D374 800A5B74 E0FF6228 */  slti       $v0, $v1, -0x20
    /* 3D378 800A5B78 05004014 */  bnez       $v0, .L800A5B90
    /* 3D37C 800A5B7C 21106000 */   addu      $v0, $v1, $zero
    /* 3D380 800A5B80 03000524 */  addiu      $a1, $zero, 0x3
    /* 3D384 800A5B84 12004516 */  bne        $s2, $a1, .L800A5BD0
    /* 3D388 800A5B88 04000224 */   addiu     $v0, $zero, 0x4
    /* 3D38C 800A5B8C 21106000 */  addu       $v0, $v1, $zero
  .L800A5B90:
    /* 3D390 800A5B90 02004104 */  bgez       $v0, .L800A5B9C
    /* 3D394 800A5B94 00000000 */   nop
    /* 3D398 800A5B98 3F004224 */  addiu      $v0, $v0, 0x3F
  .L800A5B9C:
    /* 3D39C 800A5B9C 83110200 */  sra        $v0, $v0, 6
    /* 3D3A0 800A5BA0 23280200 */  negu       $a1, $v0
    /* 3D3A4 800A5BA4 3F008230 */  andi       $v0, $a0, 0x3F
    /* 3D3A8 800A5BA8 02004010 */  beqz       $v0, .L800A5BB4
    /* 3D3AC 800A5BAC 00000000 */   nop
    /* 3D3B0 800A5BB0 0100A524 */  addiu      $a1, $a1, 0x1
  .L800A5BB4:
    /* 3D3B4 800A5BB4 2000A28F */  lw         $v0, 0x20($sp)
    /* 3D3B8 800A5BB8 00000000 */  nop
    /* 3D3BC 800A5BBC 2A104500 */  slt        $v0, $v0, $a1
    /* 3D3C0 800A5BC0 20004010 */  beqz       $v0, .L800A5C44
    /* 3D3C4 800A5BC4 03000224 */   addiu     $v0, $zero, 0x3
    /* 3D3C8 800A5BC8 11970208 */  j          .L800A5C44
    /* 3D3CC 800A5BCC 2000A5AF */   sw        $a1, 0x20($sp)
  .L800A5BD0:
    /* 3D3D0 800A5BD0 2000A38F */  lw         $v1, 0x20($sp)
    /* 3D3D4 800A5BD4 00000000 */  nop
    /* 3D3D8 800A5BD8 0E006214 */  bne        $v1, $v0, .L800A5C14
    /* 3D3DC 800A5BDC 0F80023C */   lui       $v0, %hi(D_800F4B0A)
    /* 3D3E0 800A5BE0 1E000396 */  lhu        $v1, 0x1E($s0)
    /* 3D3E4 800A5BE4 0A4B4294 */  lhu        $v0, %lo(D_800F4B0A)($v0)
    /* 3D3E8 800A5BE8 21188300 */  addu       $v1, $a0, $v1
    /* 3D3EC 800A5BEC 23104300 */  subu       $v0, $v0, $v1
    /* 3D3F0 800A5BF0 1200A3A7 */  sh         $v1, 0x12($sp)
    /* 3D3F4 800A5BF4 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 3D3F8 800A5BF8 00140200 */  sll        $v0, $v0, 16
    /* 3D3FC 800A5BFC 03140200 */  sra        $v0, $v0, 16
    /* 3D400 800A5C00 14FF4228 */  slti       $v0, $v0, -0xEC
    /* 3D404 800A5C04 0F004014 */  bnez       $v0, .L800A5C44
    /* 3D408 800A5C08 03000224 */   addiu     $v0, $zero, 0x3
    /* 3D40C 800A5C0C 11970208 */  j          .L800A5C44
    /* 3D410 800A5C10 2000A5AF */   sw        $a1, 0x20($sp)
  .L800A5C14:
    /* 3D414 800A5C14 0A4B4284 */  lh         $v0, %lo(D_800F4B0A)($v0)
    /* 3D418 800A5C18 1E000386 */  lh         $v1, 0x1E($s0)
    /* 3D41C 800A5C1C 00000000 */  nop
    /* 3D420 800A5C20 23104300 */  subu       $v0, $v0, $v1
    /* 3D424 800A5C24 A1FF4228 */  slti       $v0, $v0, -0x5F
    /* 3D428 800A5C28 06004010 */  beqz       $v0, .L800A5C44
    /* 3D42C 800A5C2C 03000224 */   addiu     $v0, $zero, 0x3
    /* 3D430 800A5C30 04006104 */  bgez       $v1, .L800A5C44
    /* 3D434 800A5C34 00000000 */   nop
    /* 3D438 800A5C38 02000224 */  addiu      $v0, $zero, 0x2
    /* 3D43C 800A5C3C 2000A2AF */  sw         $v0, 0x20($sp)
    /* 3D440 800A5C40 03000224 */  addiu      $v0, $zero, 0x3
  .L800A5C44:
    /* 3D444 800A5C44 06004216 */  bne        $s2, $v0, .L800A5C60
    /* 3D448 800A5C48 00000000 */   nop
    /* 3D44C 800A5C4C 2000A28F */  lw         $v0, 0x20($sp)
    /* 3D450 800A5C50 00000000 */  nop
    /* 3D454 800A5C54 02004004 */  bltz       $v0, .L800A5C60
    /* 3D458 800A5C58 05000224 */   addiu     $v0, $zero, 0x5
    /* 3D45C 800A5C5C 2000A2AF */  sw         $v0, 0x20($sp)
  .L800A5C60:
    /* 3D460 800A5C60 AC05028E */  lw         $v0, 0x5AC($s0)
    /* 3D464 800A5C64 00000000 */  nop
    /* 3D468 800A5C68 00104230 */  andi       $v0, $v0, 0x1000
    /* 3D46C 800A5C6C 20004010 */  beqz       $v0, .L800A5CF0
    /* 3D470 800A5C70 00000000 */   nop
    /* 3D474 800A5C74 1E006016 */  bnez       $s3, .L800A5CF0
    /* 3D478 800A5C78 00000000 */   nop
    /* 3D47C 800A5C7C 1C000286 */  lh         $v0, 0x1C($s0)
    /* 3D480 800A5C80 1000A387 */  lh         $v1, 0x10($sp)
    /* 3D484 800A5C84 D6180496 */  lhu        $a0, 0x18D6($s0)
    /* 3D488 800A5C88 21104300 */  addu       $v0, $v0, $v1
    /* 3D48C 800A5C8C 09008214 */  bne        $a0, $v0, .L800A5CB4
    /* 3D490 800A5C90 00000000 */   nop
    /* 3D494 800A5C94 20000286 */  lh         $v0, 0x20($s0)
    /* 3D498 800A5C98 1400A387 */  lh         $v1, 0x14($sp)
    /* 3D49C 800A5C9C D8180496 */  lhu        $a0, 0x18D8($s0)
    /* 3D4A0 800A5CA0 21104300 */  addu       $v0, $v0, $v1
    /* 3D4A4 800A5CA4 03008214 */  bne        $a0, $v0, .L800A5CB4
    /* 3D4A8 800A5CA8 00000000 */   nop
    /* 3D4AC 800A5CAC 81990208 */  j          .L800A6604
    /* 3D4B0 800A5CB0 21880000 */   addu      $s1, $zero, $zero
  .L800A5CB4:
    /* 3D4B4 800A5CB4 D2180296 */  lhu        $v0, 0x18D2($s0)
    /* 3D4B8 800A5CB8 D4180396 */  lhu        $v1, 0x18D4($s0)
    /* 3D4BC 800A5CBC D61802A6 */  sh         $v0, 0x18D6($s0)
    /* 3D4C0 800A5CC0 1C000296 */  lhu        $v0, 0x1C($s0)
    /* 3D4C4 800A5CC4 D81803A6 */  sh         $v1, 0x18D8($s0)
    /* 3D4C8 800A5CC8 1000A397 */  lhu        $v1, 0x10($sp)
    /* 3D4CC 800A5CCC 00000000 */  nop
    /* 3D4D0 800A5CD0 21104300 */  addu       $v0, $v0, $v1
    /* 3D4D4 800A5CD4 D21802A6 */  sh         $v0, 0x18D2($s0)
    /* 3D4D8 800A5CD8 20000296 */  lhu        $v0, 0x20($s0)
    /* 3D4DC 800A5CDC 1400A397 */  lhu        $v1, 0x14($sp)
    /* 3D4E0 800A5CE0 00000000 */  nop
    /* 3D4E4 800A5CE4 21104300 */  addu       $v0, $v0, $v1
    /* 3D4E8 800A5CE8 42970208 */  j          .L800A5D08
    /* 3D4EC 800A5CEC D41802A6 */   sh        $v0, 0x18D4($s0)
  .L800A5CF0:
    /* 3D4F0 800A5CF0 D2180296 */  lhu        $v0, 0x18D2($s0)
    /* 3D4F4 800A5CF4 D4180396 */  lhu        $v1, 0x18D4($s0)
    /* 3D4F8 800A5CF8 D21800A6 */  sh         $zero, 0x18D2($s0)
    /* 3D4FC 800A5CFC D41800A6 */  sh         $zero, 0x18D4($s0)
    /* 3D500 800A5D00 D61802A6 */  sh         $v0, 0x18D6($s0)
    /* 3D504 800A5D04 D81803A6 */  sh         $v1, 0x18D8($s0)
  .L800A5D08:
    /* 3D508 800A5D08 0800038E */  lw         $v1, 0x8($s0)
    /* 3D50C 800A5D0C 04000224 */  addiu      $v0, $zero, 0x4
    /* 3D510 800A5D10 BE0502A6 */  sh         $v0, 0x5BE($s0)
    /* 3D514 800A5D14 0700023C */  lui        $v0, (0x70000 >> 16)
    /* 3D518 800A5D18 24186200 */  and        $v1, $v1, $v0
    /* 3D51C 800A5D1C 2D006010 */  beqz       $v1, .L800A5DD4
    /* 3D520 800A5D20 0100023C */   lui       $v0, (0x10000 >> 16)
    /* 3D524 800A5D24 12006214 */  bne        $v1, $v0, .L800A5D70
    /* 3D528 800A5D28 2120A002 */   addu      $a0, $s5, $zero
    /* 3D52C 800A5D2C 30000524 */  addiu      $a1, $zero, 0x30
    /* 3D530 800A5D30 1000A297 */  lhu        $v0, 0x10($sp)
    /* 3D534 800A5D34 21300000 */  addu       $a2, $zero, $zero
    /* 3D538 800A5D38 340002A6 */  sh         $v0, 0x34($s0)
    /* 3D53C 800A5D3C 1400A297 */  lhu        $v0, 0x14($sp)
    /* 3D540 800A5D40 04000724 */  addiu      $a3, $zero, 0x4
    /* 3D544 800A5D44 8180020C */  jal        func_800A0204
    /* 3D548 800A5D48 380002A6 */   sh        $v0, 0x38($s0)
    /* 3D54C 800A5D4C F8FF043C */  lui        $a0, (0xFFF8FFFF >> 16)
    /* 3D550 800A5D50 FFFF8434 */  ori        $a0, $a0, (0xFFF8FFFF & 0xFFFF)
    /* 3D554 800A5D54 0800038E */  lw         $v1, 0x8($s0)
    /* 3D558 800A5D58 03000224 */  addiu      $v0, $zero, 0x3
    /* 3D55C 800A5D5C 24186400 */  and        $v1, $v1, $a0
    /* 3D560 800A5D60 0200043C */  lui        $a0, (0x20000 >> 16)
    /* 3D564 800A5D64 25186400 */  or         $v1, $v1, $a0
    /* 3D568 800A5D68 8B990208 */  j          .L800A662C
    /* 3D56C 800A5D6C 080003AE */   sw        $v1, 0x8($s0)
  .L800A5D70:
    /* 3D570 800A5D70 2000A38F */  lw         $v1, 0x20($sp)
    /* 3D574 800A5D74 00000000 */  nop
    /* 3D578 800A5D78 02006228 */  slti       $v0, $v1, 0x2
    /* 3D57C 800A5D7C 0C004010 */  beqz       $v0, .L800A5DB0
    /* 3D580 800A5D80 02000224 */   addiu     $v0, $zero, 0x2
    /* 3D584 800A5D84 1200A287 */  lh         $v0, 0x12($sp)
    /* 3D588 800A5D88 00000000 */  nop
    /* 3D58C 800A5D8C 0E004018 */  blez       $v0, .L800A5DC8
    /* 3D590 800A5D90 03000224 */   addiu     $v0, $zero, 0x3
    /* 3D594 800A5D94 1000A297 */  lhu        $v0, 0x10($sp)
    /* 3D598 800A5D98 00000000 */  nop
    /* 3D59C 800A5D9C 340002A6 */  sh         $v0, 0x34($s0)
    /* 3D5A0 800A5DA0 1400A397 */  lhu        $v1, 0x14($sp)
    /* 3D5A4 800A5DA4 03000224 */  addiu      $v0, $zero, 0x3
    /* 3D5A8 800A5DA8 8B990208 */  j          .L800A662C
    /* 3D5AC 800A5DAC 380003A6 */   sh        $v1, 0x38($s0)
  .L800A5DB0:
    /* 3D5B0 800A5DB0 08006210 */  beq        $v1, $v0, .L800A5DD4
    /* 3D5B4 800A5DB4 03000224 */   addiu     $v0, $zero, 0x3
    /* 3D5B8 800A5DB8 06006210 */  beq        $v1, $v0, .L800A5DD4
    /* 3D5BC 800A5DBC 04000224 */   addiu     $v0, $zero, 0x4
    /* 3D5C0 800A5DC0 04006210 */  beq        $v1, $v0, .L800A5DD4
    /* 3D5C4 800A5DC4 03000224 */   addiu     $v0, $zero, 0x3
  .L800A5DC8:
    /* 3D5C8 800A5DC8 340000A6 */  sh         $zero, 0x34($s0)
    /* 3D5CC 800A5DCC 8B990208 */  j          .L800A662C
    /* 3D5D0 800A5DD0 380000A6 */   sh        $zero, 0x38($s0)
  .L800A5DD4:
    /* 3D5D4 800A5DD4 2000A38F */  lw         $v1, 0x20($sp)
    /* 3D5D8 800A5DD8 00000000 */  nop
    /* 3D5DC 800A5DDC 8C016018 */  blez       $v1, .L800A6410
    /* 3D5E0 800A5DE0 0F80023C */   lui       $v0, %hi(D_800F49F0)
    /* 3D5E4 800A5DE4 F049428C */  lw         $v0, %lo(D_800F49F0)($v0)
    /* 3D5E8 800A5DE8 00000000 */  nop
    /* 3D5EC 800A5DEC 0000428C */  lw         $v0, 0x0($v0)
    /* 3D5F0 800A5DF0 00000000 */  nop
    /* 3D5F4 800A5DF4 42110200 */  srl        $v0, $v0, 5
    /* 3D5F8 800A5DF8 01004230 */  andi       $v0, $v0, 0x1
    /* 3D5FC 800A5DFC 05004010 */  beqz       $v0, .L800A5E14
    /* 3D600 800A5E00 01000224 */   addiu     $v0, $zero, 0x1
    /* 3D604 800A5E04 03006214 */  bne        $v1, $v0, .L800A5E14
    /* 3D608 800A5E08 02000224 */   addiu     $v0, $zero, 0x2
    /* 3D60C 800A5E0C 7D990208 */  j          .L800A65F4
    /* 3D610 800A5E10 BE0502A6 */   sh        $v0, 0x5BE($s0)
  .L800A5E14:
    /* 3D614 800A5E14 2000A48F */  lw         $a0, 0x20($sp)
    /* 3D618 800A5E18 00000000 */  nop
    /* 3D61C 800A5E1C 05008228 */  slti       $v0, $a0, 0x5
    /* 3D620 800A5E20 26004014 */  bnez       $v0, .L800A5EBC
    /* 3D624 800A5E24 02008228 */   slti      $v0, $a0, 0x2
    /* 3D628 800A5E28 FF1700A2 */  sb         $zero, 0x17FF($s0)
  .L800A5E2C:
    /* 3D62C 800A5E2C 0800028E */  lw         $v0, 0x8($s0)
    /* 3D630 800A5E30 1800033C */  lui        $v1, (0x180000 >> 16)
    /* 3D634 800A5E34 24104300 */  and        $v0, $v0, $v1
    /* 3D638 800A5E38 FC014014 */  bnez       $v0, .L800A662C
    /* 3D63C 800A5E3C 03000224 */   addiu     $v0, $zero, 0x3
  .L800A5E40:
    /* 3D640 800A5E40 340000A6 */  sh         $zero, 0x34($s0)
    /* 3D644 800A5E44 0B00C013 */  beqz       $fp, .L800A5E74
    /* 3D648 800A5E48 380000A6 */   sh        $zero, 0x38($s0)
    /* 3D64C 800A5E4C F8FF033C */  lui        $v1, (0xFFF8FFFF >> 16)
    /* 3D650 800A5E50 FFFF6334 */  ori        $v1, $v1, (0xFFF8FFFF & 0xFFFF)
    /* 3D654 800A5E54 0800048E */  lw         $a0, 0x8($s0)
    /* 3D658 800A5E58 03000224 */  addiu      $v0, $zero, 0x3
    /* 3D65C 800A5E5C 360000A6 */  sh         $zero, 0x36($s0)
    /* 3D660 800A5E60 24208300 */  and        $a0, $a0, $v1
    /* 3D664 800A5E64 0300033C */  lui        $v1, (0x30000 >> 16)
    /* 3D668 800A5E68 25208300 */  or         $a0, $a0, $v1
    /* 3D66C 800A5E6C 8B990208 */  j          .L800A662C
    /* 3D670 800A5E70 080004AE */   sw        $a0, 0x8($s0)
  .L800A5E74:
    /* 3D674 800A5E74 FF0F053C */  lui        $a1, (0xFFFFFFF >> 16)
    /* 3D678 800A5E78 FFFFA534 */  ori        $a1, $a1, (0xFFFFFFF & 0xFFFF)
    /* 3D67C 800A5E7C 21880000 */  addu       $s1, $zero, $zero
    /* 3D680 800A5E80 03001224 */  addiu      $s2, $zero, 0x3
    /* 3D684 800A5E84 F0FF0424 */  addiu      $a0, $zero, -0x10
    /* 3D688 800A5E88 0C00028E */  lw         $v0, 0xC($s0)
    /* 3D68C 800A5E8C AC05038E */  lw         $v1, 0x5AC($s0)
    /* 3D690 800A5E90 2400A98F */  lw         $t1, 0x24($sp)
    /* 3D694 800A5E94 24204400 */  and        $a0, $v0, $a0
    /* 3D698 800A5E98 02110200 */  srl        $v0, $v0, 4
    /* 3D69C 800A5E9C 0F004230 */  andi       $v0, $v0, 0xF
    /* 3D6A0 800A5EA0 25208200 */  or         $a0, $a0, $v0
    /* 3D6A4 800A5EA4 24186500 */  and        $v1, $v1, $a1
    /* 3D6A8 800A5EA8 00170900 */  sll        $v0, $t1, 28
    /* 3D6AC 800A5EAC 25186200 */  or         $v1, $v1, $v0
    /* 3D6B0 800A5EB0 0C0004AE */  sw         $a0, 0xC($s0)
    /* 3D6B4 800A5EB4 81990208 */  j          .L800A6604
    /* 3D6B8 800A5EB8 AC0503AE */   sw        $v1, 0x5AC($s0)
  .L800A5EBC:
    /* 3D6BC 800A5EBC 0B004014 */  bnez       $v0, .L800A5EEC
    /* 3D6C0 800A5EC0 8000033C */   lui       $v1, (0x800000 >> 16)
    /* 3D6C4 800A5EC4 0800028E */  lw         $v0, 0x8($s0)
    /* 3D6C8 800A5EC8 00000000 */  nop
    /* 3D6CC 800A5ECC 24104300 */  and        $v0, $v0, $v1
    /* 3D6D0 800A5ED0 D6FF4014 */  bnez       $v0, .L800A5E2C
    /* 3D6D4 800A5ED4 00000000 */   nop
    /* 3D6D8 800A5ED8 AC05028E */  lw         $v0, 0x5AC($s0)
    /* 3D6DC 800A5EDC 00000000 */  nop
    /* 3D6E0 800A5EE0 08004230 */  andi       $v0, $v0, 0x8
    /* 3D6E4 800A5EE4 D1FF4014 */  bnez       $v0, .L800A5E2C
    /* 3D6E8 800A5EE8 00000000 */   nop
  .L800A5EEC:
    /* 3D6EC 800A5EEC 0800028E */  lw         $v0, 0x8($s0)
    /* 3D6F0 800A5EF0 0700033C */  lui        $v1, (0x70000 >> 16)
    /* 3D6F4 800A5EF4 24104300 */  and        $v0, $v0, $v1
    /* 3D6F8 800A5EF8 15004014 */  bnez       $v0, .L800A5F50
    /* 3D6FC 800A5EFC 00000000 */   nop
    /* 3D700 800A5F00 0600C286 */  lh         $v0, 0x6($s6)
    /* 3D704 800A5F04 00000000 */  nop
    /* 3D708 800A5F08 11004014 */  bnez       $v0, .L800A5F50
    /* 3D70C 800A5F0C 01000224 */   addiu     $v0, $zero, 0x1
    /* 3D710 800A5F10 0F008210 */  beq        $a0, $v0, .L800A5F50
    /* 3D714 800A5F14 00000000 */   nop
    /* 3D718 800A5F18 FF170392 */  lbu        $v1, 0x17FF($s0)
    /* 3D71C 800A5F1C 00000000 */  nop
    /* 3D720 800A5F20 0800622C */  sltiu      $v0, $v1, 0x8
    /* 3D724 800A5F24 0A004010 */  beqz       $v0, .L800A5F50
    /* 3D728 800A5F28 01006224 */   addiu     $v0, $v1, 0x1
    /* 3D72C 800A5F2C FF1702A2 */  sb         $v0, 0x17FF($s0)
    /* 3D730 800A5F30 0800028E */  lw         $v0, 0x8($s0)
    /* 3D734 800A5F34 1800033C */  lui        $v1, (0x180000 >> 16)
    /* 3D738 800A5F38 24104300 */  and        $v0, $v0, $v1
    /* 3D73C 800A5F3C 1000033C */  lui        $v1, (0x100000 >> 16)
    /* 3D740 800A5F40 BAFF4314 */  bne        $v0, $v1, .L800A5E2C
    /* 3D744 800A5F44 03000224 */   addiu     $v0, $zero, 0x3
    /* 3D748 800A5F48 8B990208 */  j          .L800A662C
    /* 3D74C 800A5F4C 00000000 */   nop
  .L800A5F50:
    /* 3D750 800A5F50 1000A28F */  lw         $v0, 0x10($sp)
    /* 3D754 800A5F54 1400A38F */  lw         $v1, 0x14($sp)
    /* 3D758 800A5F58 1800A2AF */  sw         $v0, 0x18($sp)
    /* 3D75C 800A5F5C 1C00A3AF */  sw         $v1, 0x1C($sp)
    /* 3D760 800A5F60 0F80043C */  lui        $a0, %hi(D_800F4B08)
    /* 3D764 800A5F64 084B9224 */  addiu      $s2, $a0, %lo(D_800F4B08)
    /* 3D768 800A5F68 084B8294 */  lhu        $v0, %lo(D_800F4B08)($a0)
    /* 3D76C 800A5F6C 1C000396 */  lhu        $v1, 0x1C($s0)
    /* 3D770 800A5F70 F0FF0424 */  addiu      $a0, $zero, -0x10
    /* 3D774 800A5F74 23104300 */  subu       $v0, $v0, $v1
    /* 3D778 800A5F78 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 3D77C 800A5F7C 02004296 */  lhu        $v0, 0x2($s2)
    /* 3D780 800A5F80 1E000396 */  lhu        $v1, 0x1E($s0)
    /* 3D784 800A5F84 1800A627 */  addiu      $a2, $sp, 0x18
    /* 3D788 800A5F88 23104300 */  subu       $v0, $v0, $v1
    /* 3D78C 800A5F8C 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 3D790 800A5F90 04004296 */  lhu        $v0, 0x4($s2)
    /* 3D794 800A5F94 20000396 */  lhu        $v1, 0x20($s0)
    /* 3D798 800A5F98 00000000 */  nop
    /* 3D79C 800A5F9C 23104300 */  subu       $v0, $v0, $v1
    /* 3D7A0 800A5FA0 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 3D7A4 800A5FA4 0C00038E */  lw         $v1, 0xC($s0)
    /* 3D7A8 800A5FA8 06004292 */  lbu        $v0, 0x6($s2)
    /* 3D7AC 800A5FAC 24186400 */  and        $v1, $v1, $a0
    /* 3D7B0 800A5FB0 0F004230 */  andi       $v0, $v0, 0xF
    /* 3D7B4 800A5FB4 25186200 */  or         $v1, $v1, $v0
    /* 3D7B8 800A5FB8 0C0003AE */  sw         $v1, 0xC($s0)
    /* 3D7BC 800A5FBC 2000A48F */  lw         $a0, 0x20($sp)
    /* 3D7C0 800A5FC0 04000224 */  addiu      $v0, $zero, 0x4
    /* 3D7C4 800A5FC4 75008214 */  bne        $a0, $v0, .L800A619C
    /* 3D7C8 800A5FC8 1000A527 */   addiu     $a1, $sp, 0x10
    /* 3D7CC 800A5FCC 0800028E */  lw         $v0, 0x8($s0)
    /* 3D7D0 800A5FD0 1800033C */  lui        $v1, (0x180000 >> 16)
    /* 3D7D4 800A5FD4 24104300 */  and        $v0, $v0, $v1
    /* 3D7D8 800A5FD8 1000033C */  lui        $v1, (0x100000 >> 16)
    /* 3D7DC 800A5FDC 75004310 */  beq        $v0, $v1, .L800A61B4
    /* 3D7E0 800A5FE0 00000000 */   nop
    /* 3D7E4 800A5FE4 E699020C */  jal        func_800A6798
    /* 3D7E8 800A5FE8 21200002 */   addu      $a0, $s0, $zero
    /* 3D7EC 800A5FEC 94FF4010 */  beqz       $v0, .L800A5E40
    /* 3D7F0 800A5FF0 FF0F043C */   lui       $a0, (0xFFFFFFF >> 16)
    /* 3D7F4 800A5FF4 FFFF8434 */  ori        $a0, $a0, (0xFFFFFFF & 0xFFFF)
    /* 3D7F8 800A5FF8 AC05038E */  lw         $v1, 0x5AC($s0)
    /* 3D7FC 800A5FFC 06004296 */  lhu        $v0, 0x6($s2)
    /* 3D800 800A6000 24186400 */  and        $v1, $v1, $a0
    /* 3D804 800A6004 02120200 */  srl        $v0, $v0, 8
    /* 3D808 800A6008 00170200 */  sll        $v0, $v0, 28
    /* 3D80C 800A600C 25186200 */  or         $v1, $v1, $v0
    /* 3D810 800A6010 AC0503AE */  sw         $v1, 0x5AC($s0)
    /* 3D814 800A6014 02004296 */  lhu        $v0, 0x2($s2)
    /* 3D818 800A6018 00000000 */  nop
    /* 3D81C 800A601C EC0602A6 */  sh         $v0, 0x6EC($s0)
    /* 3D820 800A6020 00F0023C */  lui        $v0, (0xF0000000 >> 16)
    /* 3D824 800A6024 24106200 */  and        $v0, $v1, $v0
    /* 3D828 800A6028 22004010 */  beqz       $v0, .L800A60B4
    /* 3D82C 800A602C 021F0300 */   srl       $v1, $v1, 28
    /* 3D830 800A6030 0F80023C */  lui        $v0, %hi(D_800F45E0)
    /* 3D834 800A6034 E0454224 */  addiu      $v0, $v0, %lo(D_800F45E0)
    /* 3D838 800A6038 80180300 */  sll        $v1, $v1, 2
    /* 3D83C 800A603C 21186200 */  addu       $v1, $v1, $v0
    /* 3D840 800A6040 0000648C */  lw         $a0, 0x0($v1)
    /* 3D844 800A6044 00000000 */  nop
    /* 3D848 800A6048 1A008384 */  lh         $v1, 0x1A($a0)
    /* 3D84C 800A604C FD000224 */  addiu      $v0, $zero, 0xFD
    /* 3D850 800A6050 18006214 */  bne        $v1, $v0, .L800A60B4
    /* 3D854 800A6054 00000000 */   nop
    /* 3D858 800A6058 70018590 */  lbu        $a1, 0x170($a0)
    /* 3D85C 800A605C 00000000 */  nop
    /* 3D860 800A6060 0F00A228 */  slti       $v0, $a1, 0xF
    /* 3D864 800A6064 13004010 */  beqz       $v0, .L800A60B4
    /* 3D868 800A6068 0F80023C */   lui       $v0, %hi(D_800E91AC)
    /* 3D86C 800A606C AC914624 */  addiu      $a2, $v0, %lo(D_800E91AC)
    /* 3D870 800A6070 2120A600 */  addu       $a0, $a1, $a2
  .L800A6074:
    /* 3D874 800A6074 0100A524 */  addiu      $a1, $a1, 0x1
    /* 3D878 800A6078 00008290 */  lbu        $v0, 0x0($a0)
    /* 3D87C 800A607C 1200A397 */  lhu        $v1, 0x12($sp)
    /* 3D880 800A6080 00160200 */  sll        $v0, $v0, 24
    /* 3D884 800A6084 03160200 */  sra        $v0, $v0, 24
    /* 3D888 800A6088 21186200 */  addu       $v1, $v1, $v0
    /* 3D88C 800A608C 1200A3A7 */  sh         $v1, 0x12($sp)
    /* 3D890 800A6090 00008390 */  lbu        $v1, 0x0($a0)
    /* 3D894 800A6094 EC060296 */  lhu        $v0, 0x6EC($s0)
    /* 3D898 800A6098 001E0300 */  sll        $v1, $v1, 24
    /* 3D89C 800A609C 031E0300 */  sra        $v1, $v1, 24
    /* 3D8A0 800A60A0 21104300 */  addu       $v0, $v0, $v1
    /* 3D8A4 800A60A4 EC0602A6 */  sh         $v0, 0x6EC($s0)
    /* 3D8A8 800A60A8 0F00A228 */  slti       $v0, $a1, 0xF
    /* 3D8AC 800A60AC F1FF4014 */  bnez       $v0, .L800A6074
    /* 3D8B0 800A60B0 2120A600 */   addu      $a0, $a1, $a2
  .L800A60B4:
    /* 3D8B4 800A60B4 21200002 */  addu       $a0, $s0, $zero
    /* 3D8B8 800A60B8 4CA5020C */  jal        func_800A9530
    /* 3D8BC 800A60BC 1000A527 */   addiu     $a1, $sp, 0x10
    /* 3D8C0 800A60C0 5FFF4010 */  beqz       $v0, .L800A5E40
    /* 3D8C4 800A60C4 2120A002 */   addu      $a0, $s5, $zero
    /* 3D8C8 800A60C8 1000A527 */  addiu      $a1, $sp, 0x10
    /* 3D8CC 800A60CC 80A9020C */  jal        func_800AA600
    /* 3D8D0 800A60D0 04000624 */   addiu     $a2, $zero, 0x4
    /* 3D8D4 800A60D4 2120A002 */  addu       $a0, $s5, $zero
    /* 3D8D8 800A60D8 0F80023C */  lui        $v0, %hi(D_800F49F9)
    /* 3D8DC 800A60DC F9494590 */  lbu        $a1, %lo(D_800F49F9)($v0)
    /* 3D8E0 800A60E0 04000624 */  addiu      $a2, $zero, 0x4
    /* 3D8E4 800A60E4 402E0500 */  sll        $a1, $a1, 25
    /* 3D8E8 800A60E8 14AA020C */  jal        func_800AA850
    /* 3D8EC 800A60EC 032C0500 */   sra       $a1, $a1, 16
    /* 3D8F0 800A60F0 1C000286 */  lh         $v0, 0x1C($s0)
    /* 3D8F4 800A60F4 00000000 */  nop
    /* 3D8F8 800A60F8 02004104 */  bgez       $v0, .L800A6104
    /* 3D8FC 800A60FC FF1700A2 */   sb        $zero, 0x17FF($s0)
    /* 3D900 800A6100 7F004224 */  addiu      $v0, $v0, 0x7F
  .L800A6104:
    /* 3D904 800A6104 20000386 */  lh         $v1, 0x20($s0)
    /* 3D908 800A6108 C3110200 */  sra        $v0, $v0, 7
    /* 3D90C 800A610C 02006104 */  bgez       $v1, .L800A6118
    /* 3D910 800A6110 5C0002A2 */   sb        $v0, 0x5C($s0)
    /* 3D914 800A6114 7F006324 */  addiu      $v1, $v1, 0x7F
  .L800A6118:
    /* 3D918 800A6118 FF00043C */  lui        $a0, (0xFF00FF >> 16)
    /* 3D91C 800A611C C3110300 */  sra        $v0, $v1, 7
    /* 3D920 800A6120 6000038E */  lw         $v1, 0x60($s0)
    /* 3D924 800A6124 FF008434 */  ori        $a0, $a0, (0xFF00FF & 0xFFFF)
    /* 3D928 800A6128 5E0002A2 */  sb         $v0, 0x5E($s0)
    /* 3D92C 800A612C 5C00028E */  lw         $v0, 0x5C($s0)
    /* 3D930 800A6130 24186400 */  and        $v1, $v1, $a0
    /* 3D934 800A6134 24104400 */  and        $v0, $v0, $a0
    /* 3D938 800A6138 06006214 */  bne        $v1, $v0, .L800A6154
    /* 3D93C 800A613C 0F80023C */   lui       $v0, %hi(D_800F4B08)
    /* 3D940 800A6140 0C000292 */  lbu        $v0, 0xC($s0)
    /* 3D944 800A6144 61000392 */  lbu        $v1, 0x61($s0)
    /* 3D948 800A6148 0F004230 */  andi       $v0, $v0, 0xF
    /* 3D94C 800A614C 45006210 */  beq        $v1, $v0, .L800A6264
    /* 3D950 800A6150 0F80023C */   lui       $v0, %hi(D_800F4B08)
  .L800A6154:
    /* 3D954 800A6154 084B4484 */  lh         $a0, %lo(D_800F4B08)($v0)
    /* 3D958 800A6158 00000000 */  nop
    /* 3D95C 800A615C 02008104 */  bgez       $a0, .L800A6168
    /* 3D960 800A6160 084B4324 */   addiu     $v1, $v0, %lo(D_800F4B08)
    /* 3D964 800A6164 7F008424 */  addiu      $a0, $a0, 0x7F
  .L800A6168:
    /* 3D968 800A6168 C3110400 */  sra        $v0, $a0, 7
    /* 3D96C 800A616C 600002A2 */  sb         $v0, 0x60($s0)
    /* 3D970 800A6170 04006384 */  lh         $v1, 0x4($v1)
    /* 3D974 800A6174 00000000 */  nop
    /* 3D978 800A6178 02006104 */  bgez       $v1, .L800A6184
    /* 3D97C 800A617C 00000000 */   nop
    /* 3D980 800A6180 7F006324 */  addiu      $v1, $v1, 0x7F
  .L800A6184:
    /* 3D984 800A6184 0C000292 */  lbu        $v0, 0xC($s0)
    /* 3D988 800A6188 C3190300 */  sra        $v1, $v1, 7
    /* 3D98C 800A618C 620003A2 */  sb         $v1, 0x62($s0)
    /* 3D990 800A6190 0F004230 */  andi       $v0, $v0, 0xF
    /* 3D994 800A6194 99980208 */  j          .L800A6264
    /* 3D998 800A6198 610002A2 */   sb        $v0, 0x61($s0)
  .L800A619C:
    /* 3D99C 800A619C 0800058E */  lw         $a1, 0x8($s0)
    /* 3D9A0 800A61A0 1800023C */  lui        $v0, (0x180000 >> 16)
    /* 3D9A4 800A61A4 1000033C */  lui        $v1, (0x100000 >> 16)
    /* 3D9A8 800A61A8 2410A200 */  and        $v0, $a1, $v0
    /* 3D9AC 800A61AC 0D004314 */  bne        $v0, $v1, .L800A61E4
    /* 3D9B0 800A61B0 00000000 */   nop
  .L800A61B4:
    /* 3D9B4 800A61B4 AC05028E */  lw         $v0, 0x5AC($s0)
    /* 3D9B8 800A61B8 00000000 */  nop
    /* 3D9BC 800A61BC 00104230 */  andi       $v0, $v0, 0x1000
    /* 3D9C0 800A61C0 03004010 */  beqz       $v0, .L800A61D0
    /* 3D9C4 800A61C4 2120A002 */   addu      $a0, $s5, $zero
    /* 3D9C8 800A61C8 1000A0A7 */  sh         $zero, 0x10($sp)
    /* 3D9CC 800A61CC 1400A0A7 */  sh         $zero, 0x14($sp)
  .L800A61D0:
    /* 3D9D0 800A61D0 1000A527 */  addiu      $a1, $sp, 0x10
    /* 3D9D4 800A61D4 80A9020C */  jal        func_800AA600
    /* 3D9D8 800A61D8 18000624 */   addiu     $a2, $zero, 0x18
    /* 3D9DC 800A61DC 99980208 */  j          .L800A6264
    /* 3D9E0 800A61E0 EC0600A6 */   sh        $zero, 0x6EC($s0)
  .L800A61E4:
    /* 3D9E4 800A61E4 0600C286 */  lh         $v0, 0x6($s6)
    /* 3D9E8 800A61E8 00000000 */  nop
    /* 3D9EC 800A61EC 0A004014 */  bnez       $v0, .L800A6218
    /* 3D9F0 800A61F0 02008228 */   slti      $v0, $a0, 0x2
    /* 3D9F4 800A61F4 1200A297 */  lhu        $v0, 0x12($sp)
    /* 3D9F8 800A61F8 00000000 */  nop
    /* 3D9FC 800A61FC FF004224 */  addiu      $v0, $v0, 0xFF
    /* 3DA00 800A6200 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 3DA04 800A6204 0001422C */  sltiu      $v0, $v0, 0x100
    /* 3DA08 800A6208 08FF4010 */  beqz       $v0, .L800A5E2C
    /* 3DA0C 800A620C 00000000 */   nop
    /* 3DA10 800A6210 06FF2012 */  beqz       $s1, .L800A5E2C
    /* 3DA14 800A6214 02008228 */   slti      $v0, $a0, 0x2
  .L800A6218:
    /* 3DA18 800A6218 0D004014 */  bnez       $v0, .L800A6250
    /* 3DA1C 800A621C 0700023C */   lui       $v0, (0x70000 >> 16)
    /* 3DA20 800A6220 2410A200 */  and        $v0, $a1, $v0
    /* 3DA24 800A6224 06004010 */  beqz       $v0, .L800A6240
    /* 3DA28 800A6228 00000000 */   nop
    /* 3DA2C 800A622C AC05028E */  lw         $v0, 0x5AC($s0)
    /* 3DA30 800A6230 00000000 */  nop
    /* 3DA34 800A6234 00104230 */  andi       $v0, $v0, 0x1000
    /* 3DA38 800A6238 01FF4014 */  bnez       $v0, .L800A5E40
    /* 3DA3C 800A623C 00000000 */   nop
  .L800A6240:
    /* 3DA40 800A6240 6D9A020C */  jal        func_800A69B4
    /* 3DA44 800A6244 21200002 */   addu      $a0, $s0, $zero
    /* 3DA48 800A6248 FDFE4010 */  beqz       $v0, .L800A5E40
    /* 3DA4C 800A624C 00000000 */   nop
  .L800A6250:
    /* 3DA50 800A6250 2120A002 */  addu       $a0, $s5, $zero
    /* 3DA54 800A6254 2000A68F */  lw         $a2, 0x20($sp)
    /* 3DA58 800A6258 1000A527 */  addiu      $a1, $sp, 0x10
    /* 3DA5C 800A625C 80A9020C */  jal        func_800AA600
    /* 3DA60 800A6260 C0300600 */   sll       $a2, $a2, 3
  .L800A6264:
    /* 3DA64 800A6264 2000A38F */  lw         $v1, 0x20($sp)
    /* 3DA68 800A6268 01000224 */  addiu      $v0, $zero, 0x1
    /* 3DA6C 800A626C 25006214 */  bne        $v1, $v0, .L800A6304
    /* 3DA70 800A6270 1800023C */   lui       $v0, (0x180000 >> 16)
    /* 3DA74 800A6274 B8050392 */  lbu        $v1, 0x5B8($s0)
    /* 3DA78 800A6278 00000000 */  nop
    /* 3DA7C 800A627C 64006228 */  slti       $v0, $v1, 0x64
    /* 3DA80 800A6280 03004014 */  bnez       $v0, .L800A6290
    /* 3DA84 800A6284 F3FF6224 */   addiu     $v0, $v1, -0xD
    /* 3DA88 800A6288 9CFF6324 */  addiu      $v1, $v1, -0x64
    /* 3DA8C 800A628C F3FF6224 */  addiu      $v0, $v1, -0xD
  .L800A6290:
    /* 3DA90 800A6290 0200422C */  sltiu      $v0, $v0, 0x2
    /* 3DA94 800A6294 0C004014 */  bnez       $v0, .L800A62C8
    /* 3DA98 800A6298 13000224 */   addiu     $v0, $zero, 0x13
    /* 3DA9C 800A629C 0A006210 */  beq        $v1, $v0, .L800A62C8
    /* 3DAA0 800A62A0 14000224 */   addiu     $v0, $zero, 0x14
    /* 3DAA4 800A62A4 08006210 */  beq        $v1, $v0, .L800A62C8
    /* 3DAA8 800A62A8 54000224 */   addiu     $v0, $zero, 0x54
    /* 3DAAC 800A62AC 06006210 */  beq        $v1, $v0, .L800A62C8
    /* 3DAB0 800A62B0 2120A002 */   addu      $a0, $s5, $zero
    /* 3DAB4 800A62B4 0F80023C */  lui        $v0, %hi(D_800E90C4)
    /* 3DAB8 800A62B8 C4904590 */  lbu        $a1, %lo(D_800E90C4)($v0)
    /* 3DABC 800A62BC 21300000 */  addu       $a2, $zero, $zero
    /* 3DAC0 800A62C0 8180020C */  jal        func_800A0204
    /* 3DAC4 800A62C4 04000724 */   addiu     $a3, $zero, 0x4
  .L800A62C8:
    /* 3DAC8 800A62C8 E7FF033C */  lui        $v1, (0xFFE7FFFF >> 16)
    /* 3DACC 800A62CC FFFF6334 */  ori        $v1, $v1, (0xFFE7FFFF & 0xFFFF)
    /* 3DAD0 800A62D0 0800043C */  lui        $a0, (0x84000 >> 16)
    /* 3DAD4 800A62D4 0800028E */  lw         $v0, 0x8($s0)
    /* 3DAD8 800A62D8 3E000596 */  lhu        $a1, 0x3E($s0)
    /* 3DADC 800A62DC 24104300 */  and        $v0, $v0, $v1
    /* 3DAE0 800A62E0 26000396 */  lhu        $v1, 0x26($s0)
    /* 3DAE4 800A62E4 25104400 */  or         $v0, $v0, $a0
    /* 3DAE8 800A62E8 080002AE */  sw         $v0, 0x8($s0)
    /* 3DAEC 800A62EC 00404234 */  ori        $v0, $v0, (0x84000 & 0xFFFF)
    /* 3DAF0 800A62F0 080002AE */  sw         $v0, 0x8($s0)
    /* 3DAF4 800A62F4 21186500 */  addu       $v1, $v1, $a1
    /* 3DAF8 800A62F8 FF0F6330 */  andi       $v1, $v1, 0xFFF
    /* 3DAFC 800A62FC FA980208 */  j          .L800A63E8
    /* 3DB00 800A6300 001803A6 */   sh        $v1, 0x1800($s0)
  .L800A6304:
    /* 3DB04 800A6304 0800048E */  lw         $a0, 0x8($s0)
    /* 3DB08 800A6308 1000053C */  lui        $a1, (0x100000 >> 16)
    /* 3DB0C 800A630C 24108200 */  and        $v0, $a0, $v0
    /* 3DB10 800A6310 16004514 */  bne        $v0, $a1, .L800A636C
    /* 3DB14 800A6314 04000224 */   addiu     $v0, $zero, 0x4
    /* 3DB18 800A6318 2120A002 */  addu       $a0, $s5, $zero
    /* 3DB1C 800A631C 0F80023C */  lui        $v0, %hi(D_800E90C6)
    /* 3DB20 800A6320 C6904590 */  lbu        $a1, %lo(D_800E90C6)($v0)
    /* 3DB24 800A6324 21300000 */  addu       $a2, $zero, $zero
    /* 3DB28 800A6328 8180020C */  jal        func_800A0204
    /* 3DB2C 800A632C 04000724 */   addiu     $a3, $zero, 0x4
    /* 3DB30 800A6330 0600A016 */  bnez       $s5, .L800A634C
    /* 3DB34 800A6334 21200002 */   addu      $a0, $s0, $zero
    /* 3DB38 800A6338 2A000524 */  addiu      $a1, $zero, 0x2A
    /* 3DB3C 800A633C B0B9020C */  jal        func_800AE6C0
    /* 3DB40 800A6340 2B000624 */   addiu     $a2, $zero, 0x2B
    /* 3DB44 800A6344 D6980208 */  j          .L800A6358
    /* 3DB48 800A6348 21200002 */   addu      $a0, $s0, $zero
  .L800A634C:
    /* 3DB4C 800A634C 3FB9020C */  jal        func_800AE4FC
    /* 3DB50 800A6350 0C000524 */   addiu     $a1, $zero, 0xC
    /* 3DB54 800A6354 21200002 */  addu       $a0, $s0, $zero
  .L800A6358:
    /* 3DB58 800A6358 21288002 */  addu       $a1, $s4, $zero
    /* 3DB5C 800A635C 9899020C */  jal        func_800A6660
    /* 3DB60 800A6360 2130C002 */   addu      $a2, $s6, $zero
    /* 3DB64 800A6364 FB980208 */  j          .L800A63EC
    /* 3DB68 800A6368 F8FF043C */   lui       $a0, (0xFFF8FFFF >> 16)
  .L800A636C:
    /* 3DB6C 800A636C 05006214 */  bne        $v1, $v0, .L800A6384
    /* 3DB70 800A6370 E7FF023C */   lui       $v0, (0xFFE7FFFF >> 16)
    /* 3DB74 800A6374 FFFF4234 */  ori        $v0, $v0, (0xFFE7FFFF & 0xFFFF)
    /* 3DB78 800A6378 24108200 */  and        $v0, $a0, $v0
    /* 3DB7C 800A637C 25104500 */  or         $v0, $v0, $a1
    /* 3DB80 800A6380 080002AE */  sw         $v0, 0x8($s0)
  .L800A6384:
    /* 3DB84 800A6384 2120A002 */  addu       $a0, $s5, $zero
    /* 3DB88 800A6388 21300000 */  addu       $a2, $zero, $zero
    /* 3DB8C 800A638C 0F80023C */  lui        $v0, %hi(D_800E90C3)
    /* 3DB90 800A6390 2000A38F */  lw         $v1, 0x20($sp)
    /* 3DB94 800A6394 C3904224 */  addiu      $v0, $v0, %lo(D_800E90C3)
    /* 3DB98 800A6398 21186200 */  addu       $v1, $v1, $v0
    /* 3DB9C 800A639C 00006590 */  lbu        $a1, 0x0($v1)
    /* 3DBA0 800A63A0 8180020C */  jal        func_800A0204
    /* 3DBA4 800A63A4 04000724 */   addiu     $a3, $zero, 0x4
    /* 3DBA8 800A63A8 26000296 */  lhu        $v0, 0x26($s0)
    /* 3DBAC 800A63AC 3E000396 */  lhu        $v1, 0x3E($s0)
    /* 3DBB0 800A63B0 00000000 */  nop
    /* 3DBB4 800A63B4 21104300 */  addu       $v0, $v0, $v1
    /* 3DBB8 800A63B8 FF0F4230 */  andi       $v0, $v0, 0xFFF
    /* 3DBBC 800A63BC 0700A016 */  bnez       $s5, .L800A63DC
    /* 3DBC0 800A63C0 001802A6 */   sh        $v0, 0x1800($s0)
    /* 3DBC4 800A63C4 21200002 */  addu       $a0, $s0, $zero
    /* 3DBC8 800A63C8 29000524 */  addiu      $a1, $zero, 0x29
    /* 3DBCC 800A63CC B0B9020C */  jal        func_800AE6C0
    /* 3DBD0 800A63D0 21300000 */   addu      $a2, $zero, $zero
    /* 3DBD4 800A63D4 FB980208 */  j          .L800A63EC
    /* 3DBD8 800A63D8 F8FF043C */   lui       $a0, (0xFFF8FFFF >> 16)
  .L800A63DC:
    /* 3DBDC 800A63DC 21200002 */  addu       $a0, $s0, $zero
    /* 3DBE0 800A63E0 3FB9020C */  jal        func_800AE4FC
    /* 3DBE4 800A63E4 0C000524 */   addiu     $a1, $zero, 0xC
  .L800A63E8:
    /* 3DBE8 800A63E8 F8FF043C */  lui        $a0, (0xFFF8FFFF >> 16)
  .L800A63EC:
    /* 3DBEC 800A63EC FFFF8434 */  ori        $a0, $a0, (0xFFF8FFFF & 0xFFFF)
    /* 3DBF0 800A63F0 0800038E */  lw         $v1, 0x8($s0)
    /* 3DBF4 800A63F4 03000224 */  addiu      $v0, $zero, 0x3
    /* 3DBF8 800A63F8 110000A2 */  sb         $zero, 0x11($s0)
    /* 3DBFC 800A63FC EE0600A2 */  sb         $zero, 0x6EE($s0)
    /* 3DC00 800A6400 EF0600A2 */  sb         $zero, 0x6EF($s0)
    /* 3DC04 800A6404 24186400 */  and        $v1, $v1, $a0
    /* 3DC08 800A6408 8B990208 */  j          .L800A662C
    /* 3DC0C 800A640C 080003AE */   sw        $v1, 0x8($s0)
  .L800A6410:
    /* 3DC10 800A6410 1200A287 */  lh         $v0, 0x12($sp)
    /* 3DC14 800A6414 00000000 */  nop
    /* 3DC18 800A6418 67004018 */  blez       $v0, .L800A65B8
    /* 3DC1C 800A641C 1800143C */   lui       $s4, (0x180000 >> 16)
    /* 3DC20 800A6420 0800028E */  lw         $v0, 0x8($s0)
    /* 3DC24 800A6424 1000133C */  lui        $s3, (0x100000 >> 16)
    /* 3DC28 800A6428 24105400 */  and        $v0, $v0, $s4
    /* 3DC2C 800A642C 04005314 */  bne        $v0, $s3, .L800A6440
    /* 3DC30 800A6430 00000000 */   nop
    /* 3DC34 800A6434 1000A0A7 */  sh         $zero, 0x10($sp)
    /* 3DC38 800A6438 EB940208 */  j          .L800A53AC
    /* 3DC3C 800A643C 1400A0A7 */   sh        $zero, 0x14($sp)
  .L800A6440:
    /* 3DC40 800A6440 0C00028E */  lw         $v0, 0xC($s0)
    /* 3DC44 800A6444 00000000 */  nop
    /* 3DC48 800A6448 0F004230 */  andi       $v0, $v0, 0xF
    /* 3DC4C 800A644C 0E004010 */  beqz       $v0, .L800A6488
    /* 3DC50 800A6450 00000000 */   nop
    /* 3DC54 800A6454 1C000486 */  lh         $a0, 0x1C($s0)
    /* 3DC58 800A6458 1E000586 */  lh         $a1, 0x1E($s0)
    /* 3DC5C 800A645C 20000686 */  lh         $a2, 0x20($s0)
    /* 3DC60 800A6460 DEA4020C */  jal        func_800A9378
    /* 3DC64 800A6464 21380000 */   addu      $a3, $zero, $zero
    /* 3DC68 800A6468 0F80023C */  lui        $v0, %hi(D_800F49F4)
    /* 3DC6C 800A646C F0FF0424 */  addiu      $a0, $zero, -0x10
    /* 3DC70 800A6470 0C00038E */  lw         $v1, 0xC($s0)
    /* 3DC74 800A6474 F4494290 */  lbu        $v0, %lo(D_800F49F4)($v0)
    /* 3DC78 800A6478 24186400 */  and        $v1, $v1, $a0
    /* 3DC7C 800A647C 0F004230 */  andi       $v0, $v0, 0xF
    /* 3DC80 800A6480 25186200 */  or         $v1, $v1, $v0
    /* 3DC84 800A6484 0C0003AE */  sw         $v1, 0xC($s0)
  .L800A6488:
    /* 3DC88 800A6488 1200A387 */  lh         $v1, 0x12($sp)
    /* 3DC8C 800A648C 00000000 */  nop
    /* 3DC90 800A6490 40006228 */  slti       $v0, $v1, 0x40
    /* 3DC94 800A6494 3C004014 */  bnez       $v0, .L800A6588
    /* 3DC98 800A6498 0F80023C */   lui       $v0, %hi(D_800F49F0)
    /* 3DC9C 800A649C 0600C286 */  lh         $v0, 0x6($s6)
    /* 3DCA0 800A64A0 00000000 */  nop
    /* 3DCA4 800A64A4 12004014 */  bnez       $v0, .L800A64F0
    /* 3DCA8 800A64A8 21200002 */   addu      $a0, $s0, $zero
    /* 3DCAC 800A64AC 00016228 */  slti       $v0, $v1, 0x100
    /* 3DCB0 800A64B0 12004014 */  bnez       $v0, .L800A64FC
    /* 3DCB4 800A64B4 2120A002 */   addu      $a0, $s5, $zero
    /* 3DCB8 800A64B8 0800028E */  lw         $v0, 0x8($s0)
    /* 3DCBC 800A64BC 00000000 */  nop
    /* 3DCC0 800A64C0 24105400 */  and        $v0, $v0, $s4
    /* 3DCC4 800A64C4 08005310 */  beq        $v0, $s3, .L800A64E8
    /* 3DCC8 800A64C8 00000000 */   nop
    /* 3DCCC 800A64CC FF170392 */  lbu        $v1, 0x17FF($s0)
    /* 3DCD0 800A64D0 00000000 */  nop
    /* 3DCD4 800A64D4 0800622C */  sltiu      $v0, $v1, 0x8
    /* 3DCD8 800A64D8 03004010 */  beqz       $v0, .L800A64E8
    /* 3DCDC 800A64DC 01006224 */   addiu     $v0, $v1, 0x1
    /* 3DCE0 800A64E0 8B970208 */  j          .L800A5E2C
    /* 3DCE4 800A64E4 FF1702A2 */   sb        $v0, 0x17FF($s0)
  .L800A64E8:
    /* 3DCE8 800A64E8 3E990208 */  j          .L800A64F8
    /* 3DCEC 800A64EC 110000A2 */   sb        $zero, 0x11($s0)
  .L800A64F0:
    /* 3DCF0 800A64F0 158C020C */  jal        func_800A3054
    /* 3DCF4 800A64F4 1000A527 */   addiu     $a1, $sp, 0x10
  .L800A64F8:
    /* 3DCF8 800A64F8 2120A002 */  addu       $a0, $s5, $zero
  .L800A64FC:
    /* 3DCFC 800A64FC 2F000524 */  addiu      $a1, $zero, 0x2F
    /* 3DD00 800A6500 1000A297 */  lhu        $v0, 0x10($sp)
    /* 3DD04 800A6504 21300000 */  addu       $a2, $zero, $zero
    /* 3DD08 800A6508 340002A6 */  sh         $v0, 0x34($s0)
    /* 3DD0C 800A650C 1400A297 */  lhu        $v0, 0x14($sp)
    /* 3DD10 800A6510 04000724 */  addiu      $a3, $zero, 0x4
    /* 3DD14 800A6514 360000A6 */  sh         $zero, 0x36($s0)
    /* 3DD18 800A6518 8180020C */  jal        func_800A0204
    /* 3DD1C 800A651C 380002A6 */   sh        $v0, 0x38($s0)
    /* 3DD20 800A6520 F8FF023C */  lui        $v0, (0xFFF8FFFF >> 16)
    /* 3DD24 800A6524 FFFF4234 */  ori        $v0, $v0, (0xFFF8FFFF & 0xFFFF)
    /* 3DD28 800A6528 0800048E */  lw         $a0, 0x8($s0)
    /* 3DD2C 800A652C FBFF0324 */  addiu      $v1, $zero, -0x5
    /* 3DD30 800A6530 24208200 */  and        $a0, $a0, $v0
    /* 3DD34 800A6534 0300023C */  lui        $v0, (0x30000 >> 16)
    /* 3DD38 800A6538 25208200 */  or         $a0, $a0, $v0
    /* 3DD3C 800A653C B005028E */  lw         $v0, 0x5B0($s0)
    /* 3DD40 800A6540 FCFF0524 */  addiu      $a1, $zero, -0x4
    /* 3DD44 800A6544 080004AE */  sw         $a0, 0x8($s0)
    /* 3DD48 800A6548 24104300 */  and        $v0, $v0, $v1
    /* 3DD4C 800A654C 24184500 */  and        $v1, $v0, $a1
    /* 3DD50 800A6550 B9050292 */  lbu        $v0, 0x5B9($s0)
    /* 3DD54 800A6554 01006334 */  ori        $v1, $v1, 0x1
    /* 3DD58 800A6558 2A102202 */  slt        $v0, $s1, $v0
    /* 3DD5C 800A655C 04004014 */  bnez       $v0, .L800A6570
    /* 3DD60 800A6560 B00503AE */   sw        $v1, 0x5B0($s0)
    /* 3DD64 800A6564 24106500 */  and        $v0, $v1, $a1
    /* 3DD68 800A6568 06004234 */  ori        $v0, $v0, 0x6
    /* 3DD6C 800A656C B00502AE */  sw         $v0, 0x5B0($s0)
  .L800A6570:
    /* 3DD70 800A6570 03000224 */  addiu      $v0, $zero, 0x3
    /* 3DD74 800A6574 0C00038E */  lw         $v1, 0xC($s0)
    /* 3DD78 800A6578 F0FF0424 */  addiu      $a0, $zero, -0x10
    /* 3DD7C 800A657C 24186400 */  and        $v1, $v1, $a0
    /* 3DD80 800A6580 8B990208 */  j          .L800A662C
    /* 3DD84 800A6584 0C0003AE */   sw        $v1, 0xC($s0)
  .L800A6588:
    /* 3DD88 800A6588 FF1700A2 */  sb         $zero, 0x17FF($s0)
    /* 3DD8C 800A658C F049428C */  lw         $v0, %lo(D_800F49F0)($v0)
    /* 3DD90 800A6590 00000000 */  nop
    /* 3DD94 800A6594 0000428C */  lw         $v0, 0x0($v0)
    /* 3DD98 800A6598 00000000 */  nop
    /* 3DD9C 800A659C 42110200 */  srl        $v0, $v0, 5
    /* 3DDA0 800A65A0 01004230 */  andi       $v0, $v0, 0x1
    /* 3DDA4 800A65A4 14004014 */  bnez       $v0, .L800A65F8
    /* 3DDA8 800A65A8 2120A002 */   addu      $a0, $s5, $zero
    /* 3DDAC 800A65AC 05000224 */  addiu      $v0, $zero, 0x5
    /* 3DDB0 800A65B0 7E990208 */  j          .L800A65F8
    /* 3DDB4 800A65B4 BE0502A6 */   sh        $v0, 0x5BE($s0)
  .L800A65B8:
    /* 3DDB8 800A65B8 E7FF033C */  lui        $v1, (0xFFE7FFFF >> 16)
    /* 3DDBC 800A65BC 0800028E */  lw         $v0, 0x8($s0)
    /* 3DDC0 800A65C0 FFFF6334 */  ori        $v1, $v1, (0xFFE7FFFF & 0xFFFF)
    /* 3DDC4 800A65C4 EC0600A6 */  sh         $zero, 0x6EC($s0)
    /* 3DDC8 800A65C8 24104300 */  and        $v0, $v0, $v1
    /* 3DDCC 800A65CC FFBF0324 */  addiu      $v1, $zero, -0x4001
    /* 3DDD0 800A65D0 24104300 */  and        $v0, $v0, $v1
    /* 3DDD4 800A65D4 080002AE */  sw         $v0, 0x8($s0)
    /* 3DDD8 800A65D8 1200A287 */  lh         $v0, 0x12($sp)
    /* 3DDDC 800A65DC 00000000 */  nop
    /* 3DDE0 800A65E0 FEFF4228 */  slti       $v0, $v0, -0x2
    /* 3DDE4 800A65E4 02004010 */  beqz       $v0, .L800A65F0
    /* 3DDE8 800A65E8 02000224 */   addiu     $v0, $zero, 0x2
    /* 3DDEC 800A65EC BE0502A6 */  sh         $v0, 0x5BE($s0)
  .L800A65F0:
    /* 3DDF0 800A65F0 FF1700A2 */  sb         $zero, 0x17FF($s0)
  .L800A65F4:
    /* 3DDF4 800A65F4 2120A002 */  addu       $a0, $s5, $zero
  .L800A65F8:
    /* 3DDF8 800A65F8 1000A527 */  addiu      $a1, $sp, 0x10
    /* 3DDFC 800A65FC A6A9020C */  jal        func_800AA698
    /* 3DE00 800A6600 21300000 */   addu      $a2, $zero, $zero
  .L800A6604:
    /* 3DE04 800A6604 0800028E */  lw         $v0, 0x8($s0)
    /* 3DE08 800A6608 0700033C */  lui        $v1, (0x70000 >> 16)
    /* 3DE0C 800A660C 24104300 */  and        $v0, $v0, $v1
    /* 3DE10 800A6610 06004014 */  bnez       $v0, .L800A662C
    /* 3DE14 800A6614 21104002 */   addu      $v0, $s2, $zero
    /* 3DE18 800A6618 21200002 */  addu       $a0, $s0, $zero
    /* 3DE1C 800A661C 21282002 */  addu       $a1, $s1, $zero
    /* 3DE20 800A6620 A89A020C */  jal        func_800A6AA0
    /* 3DE24 800A6624 2130E002 */   addu      $a2, $s7, $zero
    /* 3DE28 800A6628 21104002 */  addu       $v0, $s2, $zero
  .L800A662C:
    /* 3DE2C 800A662C 4C00BF8F */  lw         $ra, 0x4C($sp)
    /* 3DE30 800A6630 4800BE8F */  lw         $fp, 0x48($sp)
    /* 3DE34 800A6634 4400B78F */  lw         $s7, 0x44($sp)
    /* 3DE38 800A6638 4000B68F */  lw         $s6, 0x40($sp)
    /* 3DE3C 800A663C 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 3DE40 800A6640 3800B48F */  lw         $s4, 0x38($sp)
    /* 3DE44 800A6644 3400B38F */  lw         $s3, 0x34($sp)
    /* 3DE48 800A6648 3000B28F */  lw         $s2, 0x30($sp)
    /* 3DE4C 800A664C 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 3DE50 800A6650 2800B08F */  lw         $s0, 0x28($sp)
    /* 3DE54 800A6654 5000BD27 */  addiu      $sp, $sp, 0x50
    /* 3DE58 800A6658 0800E003 */  jr         $ra
    /* 3DE5C 800A665C 00000000 */   nop
endlabel func_800A5280
