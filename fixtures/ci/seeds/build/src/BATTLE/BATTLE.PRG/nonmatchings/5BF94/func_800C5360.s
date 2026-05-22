nonmatching func_800C5360, 0x1DC

glabel func_800C5360
    /* 5CB60 800C5360 21408000 */  addu       $t0, $a0, $zero
    /* 5CB64 800C5364 0F80073C */  lui        $a3, %hi(D_800F4CB1)
    /* 5CB68 800C5368 0F80053C */  lui        $a1, %hi(D_800F4CB0)
    /* 5CB6C 800C536C B14CE390 */  lbu        $v1, %lo(D_800F4CB1)($a3)
    /* 5CB70 800C5370 B04CA290 */  lbu        $v0, %lo(D_800F4CB0)($a1)
    /* 5CB74 800C5374 00000000 */  nop
    /* 5CB78 800C5378 2B104300 */  sltu       $v0, $v0, $v1
    /* 5CB7C 800C537C 37004010 */  beqz       $v0, .L800C545C
    /* 5CB80 800C5380 21300000 */   addu      $a2, $zero, $zero
    /* 5CB84 800C5384 0F80033C */  lui        $v1, %hi(D_800EB9B8)
    /* 5CB88 800C5388 B8B9628C */  lw         $v0, %lo(D_800EB9B8)($v1)
    /* 5CB8C 800C538C 00000000 */  nop
    /* 5CB90 800C5390 2C004290 */  lbu        $v0, 0x2C($v0)
    /* 5CB94 800C5394 00000000 */  nop
    /* 5CB98 800C5398 2A10C200 */  slt        $v0, $a2, $v0
    /* 5CB9C 800C539C 21004010 */  beqz       $v0, .L800C5424
    /* 5CBA0 800C53A0 2120C000 */   addu      $a0, $a2, $zero
    /* 5CBA4 800C53A4 21506000 */  addu       $t2, $v1, $zero
    /* 5CBA8 800C53A8 0F80023C */  lui        $v0, %hi(D_800F4C70)
    /* 5CBAC 800C53AC 704C4924 */  addiu      $t1, $v0, %lo(D_800F4C70)
    /* 5CBB0 800C53B0 2138A000 */  addu       $a3, $a1, $zero
    /* 5CBB4 800C53B4 2128C000 */  addu       $a1, $a2, $zero
  .L800C53B8:
    /* 5CBB8 800C53B8 B8B9428D */  lw         $v0, %lo(D_800EB9B8)($t2)
    /* 5CBBC 800C53BC 00000000 */  nop
    /* 5CBC0 800C53C0 4000428C */  lw         $v0, 0x40($v0)
    /* 5CBC4 800C53C4 00000000 */  nop
    /* 5CBC8 800C53C8 2110A200 */  addu       $v0, $a1, $v0
    /* 5CBCC 800C53CC 09004290 */  lbu        $v0, 0x9($v0)
    /* 5CBD0 800C53D0 00000000 */  nop
    /* 5CBD4 800C53D4 0C004814 */  bne        $v0, $t0, .L800C5408
    /* 5CBD8 800C53D8 0F80033C */   lui       $v1, %hi(D_800EB9B8)
    /* 5CBDC 800C53DC 0200C014 */  bnez       $a2, .L800C53E8
    /* 5CBE0 800C53E0 00000000 */   nop
    /* 5CBE4 800C53E4 01008624 */  addiu      $a2, $a0, 0x1
  .L800C53E8:
    /* 5CBE8 800C53E8 B04CE290 */  lbu        $v0, %lo(D_800F4CB0)($a3)
    /* 5CBEC 800C53EC 00000000 */  nop
    /* 5CBF0 800C53F0 01004324 */  addiu      $v1, $v0, 0x1
    /* 5CBF4 800C53F4 FF004230 */  andi       $v0, $v0, 0xFF
    /* 5CBF8 800C53F8 21104900 */  addu       $v0, $v0, $t1
    /* 5CBFC 800C53FC B04CE3A0 */  sb         $v1, %lo(D_800F4CB0)($a3)
    /* 5CC00 800C5400 100044A0 */  sb         $a0, 0x10($v0)
    /* 5CC04 800C5404 0F80033C */  lui        $v1, %hi(D_800EB9B8)
  .L800C5408:
    /* 5CC08 800C5408 B8B9628C */  lw         $v0, %lo(D_800EB9B8)($v1)
    /* 5CC0C 800C540C 00000000 */  nop
    /* 5CC10 800C5410 2C004290 */  lbu        $v0, 0x2C($v0)
    /* 5CC14 800C5414 01008424 */  addiu      $a0, $a0, 0x1
    /* 5CC18 800C5418 2A108200 */  slt        $v0, $a0, $v0
    /* 5CC1C 800C541C E6FF4014 */  bnez       $v0, .L800C53B8
    /* 5CC20 800C5420 1800A524 */   addiu     $a1, $a1, 0x18
  .L800C5424:
    /* 5CC24 800C5424 0F80023C */  lui        $v0, %hi(D_800F4CA0)
    /* 5CC28 800C5428 0F80043C */  lui        $a0, %hi(D_800F4CB2)
    /* 5CC2C 800C542C B24C8390 */  lbu        $v1, %lo(D_800F4CB2)($a0)
    /* 5CC30 800C5430 A04C4224 */  addiu      $v0, $v0, %lo(D_800F4CA0)
    /* 5CC34 800C5434 21186200 */  addu       $v1, $v1, $v0
    /* 5CC38 800C5438 FFFFC224 */  addiu      $v0, $a2, -0x1
    /* 5CC3C 800C543C 000062A0 */  sb         $v0, 0x0($v1)
    /* 5CC40 800C5440 B24C8390 */  lbu        $v1, %lo(D_800F4CB2)($a0)
    /* 5CC44 800C5444 00000000 */  nop
    /* 5CC48 800C5448 01006224 */  addiu      $v0, $v1, 0x1
    /* 5CC4C 800C544C B24C82A0 */  sb         $v0, %lo(D_800F4CB2)($a0)
    /* 5CC50 800C5450 0F80023C */  lui        $v0, %hi(D_800F4C90)
    /* 5CC54 800C5454 4B150308 */  j          .L800C552C
    /* 5CC58 800C5458 904C4224 */   addiu     $v0, $v0, %lo(D_800F4C90)
  .L800C545C:
    /* 5CC5C 800C545C 0F80033C */  lui        $v1, %hi(D_800EB9B8)
    /* 5CC60 800C5460 B8B9628C */  lw         $v0, %lo(D_800EB9B8)($v1)
    /* 5CC64 800C5464 00000000 */  nop
    /* 5CC68 800C5468 2C004290 */  lbu        $v0, 0x2C($v0)
    /* 5CC6C 800C546C 00000000 */  nop
    /* 5CC70 800C5470 2A10C200 */  slt        $v0, $a2, $v0
    /* 5CC74 800C5474 20004010 */  beqz       $v0, .L800C54F8
    /* 5CC78 800C5478 21200000 */   addu      $a0, $zero, $zero
    /* 5CC7C 800C547C 21506000 */  addu       $t2, $v1, $zero
    /* 5CC80 800C5480 0F80023C */  lui        $v0, %hi(D_800F4C70)
    /* 5CC84 800C5484 704C4924 */  addiu      $t1, $v0, %lo(D_800F4C70)
    /* 5CC88 800C5488 21288000 */  addu       $a1, $a0, $zero
  .L800C548C:
    /* 5CC8C 800C548C B8B9428D */  lw         $v0, %lo(D_800EB9B8)($t2)
    /* 5CC90 800C5490 00000000 */  nop
    /* 5CC94 800C5494 4000428C */  lw         $v0, 0x40($v0)
    /* 5CC98 800C5498 00000000 */  nop
    /* 5CC9C 800C549C 2110A200 */  addu       $v0, $a1, $v0
    /* 5CCA0 800C54A0 09004290 */  lbu        $v0, 0x9($v0)
    /* 5CCA4 800C54A4 00000000 */  nop
    /* 5CCA8 800C54A8 0C004814 */  bne        $v0, $t0, .L800C54DC
    /* 5CCAC 800C54AC 0F80033C */   lui       $v1, %hi(D_800EB9B8)
    /* 5CCB0 800C54B0 0200C014 */  bnez       $a2, .L800C54BC
    /* 5CCB4 800C54B4 00000000 */   nop
    /* 5CCB8 800C54B8 01008624 */  addiu      $a2, $a0, 0x1
  .L800C54BC:
    /* 5CCBC 800C54BC B14CE290 */  lbu        $v0, %lo(D_800F4CB1)($a3)
    /* 5CCC0 800C54C0 00000000 */  nop
    /* 5CCC4 800C54C4 01004324 */  addiu      $v1, $v0, 0x1
    /* 5CCC8 800C54C8 FF004230 */  andi       $v0, $v0, 0xFF
    /* 5CCCC 800C54CC 21104900 */  addu       $v0, $v0, $t1
    /* 5CCD0 800C54D0 B14CE3A0 */  sb         $v1, %lo(D_800F4CB1)($a3)
    /* 5CCD4 800C54D4 000044A0 */  sb         $a0, 0x0($v0)
    /* 5CCD8 800C54D8 0F80033C */  lui        $v1, %hi(D_800EB9B8)
  .L800C54DC:
    /* 5CCDC 800C54DC B8B9628C */  lw         $v0, %lo(D_800EB9B8)($v1)
    /* 5CCE0 800C54E0 00000000 */  nop
    /* 5CCE4 800C54E4 2C004290 */  lbu        $v0, 0x2C($v0)
    /* 5CCE8 800C54E8 01008424 */  addiu      $a0, $a0, 0x1
    /* 5CCEC 800C54EC 2A108200 */  slt        $v0, $a0, $v0
    /* 5CCF0 800C54F0 E6FF4014 */  bnez       $v0, .L800C548C
    /* 5CCF4 800C54F4 1800A524 */   addiu     $a1, $a1, 0x18
  .L800C54F8:
    /* 5CCF8 800C54F8 0F80023C */  lui        $v0, %hi(D_800F4CA8)
    /* 5CCFC 800C54FC 0F80043C */  lui        $a0, %hi(D_800F4CB3)
    /* 5CD00 800C5500 B34C8390 */  lbu        $v1, %lo(D_800F4CB3)($a0)
    /* 5CD04 800C5504 A84C4224 */  addiu      $v0, $v0, %lo(D_800F4CA8)
    /* 5CD08 800C5508 21186200 */  addu       $v1, $v1, $v0
    /* 5CD0C 800C550C FFFFC224 */  addiu      $v0, $a2, -0x1
    /* 5CD10 800C5510 000062A0 */  sb         $v0, 0x0($v1)
    /* 5CD14 800C5514 B34C8390 */  lbu        $v1, %lo(D_800F4CB3)($a0)
    /* 5CD18 800C5518 00000000 */  nop
    /* 5CD1C 800C551C 01006224 */  addiu      $v0, $v1, 0x1
    /* 5CD20 800C5520 B34C82A0 */  sb         $v0, %lo(D_800F4CB3)($a0)
    /* 5CD24 800C5524 0F80023C */  lui        $v0, %hi(D_800F4C98)
    /* 5CD28 800C5528 984C4224 */  addiu      $v0, $v0, %lo(D_800F4C98)
  .L800C552C:
    /* 5CD2C 800C552C FF006330 */  andi       $v1, $v1, 0xFF
    /* 5CD30 800C5530 21186200 */  addu       $v1, $v1, $v0
    /* 5CD34 800C5534 0800E003 */  jr         $ra
    /* 5CD38 800C5538 000068A0 */   sb        $t0, 0x0($v1)
endlabel func_800C5360
