nonmatching func_800AFA28, 0x3C0

glabel func_800AFA28
    /* 47228 800AFA28 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 4722C 800AFA2C 2800B4AF */  sw         $s4, 0x28($sp)
    /* 47230 800AFA30 21A08000 */  addu       $s4, $a0, $zero
    /* 47234 800AFA34 2000B2AF */  sw         $s2, 0x20($sp)
    /* 47238 800AFA38 2190A000 */  addu       $s2, $a1, $zero
    /* 4723C 800AFA3C 3000B6AF */  sw         $s6, 0x30($sp)
    /* 47240 800AFA40 21B0C000 */  addu       $s6, $a2, $zero
    /* 47244 800AFA44 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 47248 800AFA48 801F153C */  lui        $s5, (0x1F8003EC >> 16)
    /* 4724C 800AFA4C EC03B536 */  ori        $s5, $s5, (0x1F8003EC & 0xFFFF)
    /* 47250 800AFA50 FDFF023C */  lui        $v0, (0xFFFDFFFF >> 16)
    /* 47254 800AFA54 FFFF4234 */  ori        $v0, $v0, (0xFFFDFFFF & 0xFFFF)
    /* 47258 800AFA58 3400BFAF */  sw         $ra, 0x34($sp)
    /* 4725C 800AFA5C 2400B3AF */  sw         $s3, 0x24($sp)
    /* 47260 800AFA60 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 47264 800AFA64 1800B0AF */  sw         $s0, 0x18($sp)
    /* 47268 800AFA68 4805438E */  lw         $v1, 0x548($s2)
    /* 4726C 800AFA6C 00000000 */  nop
    /* 47270 800AFA70 24186200 */  and        $v1, $v1, $v0
    /* 47274 800AFA74 480543AE */  sw         $v1, 0x548($s2)
    /* 47278 800AFA78 B2058292 */  lbu        $v0, 0x5B2($s4)
    /* 4727C 800AFA7C 40055386 */  lh         $s3, 0x540($s2)
    /* 47280 800AFA80 68004010 */  beqz       $v0, .L800AFC24
    /* 47284 800AFA84 21880000 */   addu      $s1, $zero, $zero
    /* 47288 800AFA88 64189026 */  addiu      $s0, $s4, 0x1864
  .L800AFA8C:
    /* 4728C 800AFA8C 04000292 */  lbu        $v0, 0x4($s0)
    /* 47290 800AFA90 00000000 */  nop
    /* 47294 800AFA94 0F004010 */  beqz       $v0, .L800AFAD4
    /* 47298 800AFA98 00000000 */   nop
    /* 4729C 800AFA9C 0A000386 */  lh         $v1, 0xA($s0)
    /* 472A0 800AFAA0 00000000 */  nop
    /* 472A4 800AFAA4 1A006200 */  div        $zero, $v1, $v0
    /* 472A8 800AFAA8 12300000 */  mflo       $a2
    /* 472AC 800AFAAC 04000292 */  lbu        $v0, 0x4($s0)
    /* 472B0 800AFAB0 00000000 */  nop
    /* 472B4 800AFAB4 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 472B8 800AFAB8 040002A2 */  sb         $v0, 0x4($s0)
    /* 472BC 800AFABC 0A000296 */  lhu        $v0, 0xA($s0)
    /* 472C0 800AFAC0 08000396 */  lhu        $v1, 0x8($s0)
    /* 472C4 800AFAC4 23104600 */  subu       $v0, $v0, $a2
    /* 472C8 800AFAC8 21186600 */  addu       $v1, $v1, $a2
    /* 472CC 800AFACC 0A0002A6 */  sh         $v0, 0xA($s0)
    /* 472D0 800AFAD0 080003A6 */  sh         $v1, 0x8($s0)
  .L800AFAD4:
    /* 472D4 800AFAD4 08000296 */  lhu        $v0, 0x8($s0)
    /* 472D8 800AFAD8 05000392 */  lbu        $v1, 0x5($s0)
    /* 472DC 800AFADC FF0F4230 */  andi       $v0, $v0, 0xFFF
    /* 472E0 800AFAE0 19006010 */  beqz       $v1, .L800AFB48
    /* 472E4 800AFAE4 080002A6 */   sh        $v0, 0x8($s0)
    /* 472E8 800AFAE8 10000386 */  lh         $v1, 0x10($s0)
    /* 472EC 800AFAEC 05000292 */  lbu        $v0, 0x5($s0)
    /* 472F0 800AFAF0 00000000 */  nop
    /* 472F4 800AFAF4 1A006200 */  div        $zero, $v1, $v0
    /* 472F8 800AFAF8 12300000 */  mflo       $a2
    /* 472FC 800AFAFC 10000496 */  lhu        $a0, 0x10($s0)
    /* 47300 800AFB00 0C000596 */  lhu        $a1, 0xC($s0)
    /* 47304 800AFB04 12000386 */  lh         $v1, 0x12($s0)
    /* 47308 800AFB08 05000292 */  lbu        $v0, 0x5($s0)
    /* 4730C 800AFB0C 23208600 */  subu       $a0, $a0, $a2
    /* 47310 800AFB10 2128A600 */  addu       $a1, $a1, $a2
    /* 47314 800AFB14 1A006200 */  div        $zero, $v1, $v0
    /* 47318 800AFB18 12300000 */  mflo       $a2
    /* 4731C 800AFB1C 05000292 */  lbu        $v0, 0x5($s0)
    /* 47320 800AFB20 0E000396 */  lhu        $v1, 0xE($s0)
    /* 47324 800AFB24 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 47328 800AFB28 050002A2 */  sb         $v0, 0x5($s0)
    /* 4732C 800AFB2C 12000296 */  lhu        $v0, 0x12($s0)
    /* 47330 800AFB30 100004A6 */  sh         $a0, 0x10($s0)
    /* 47334 800AFB34 0C0005A6 */  sh         $a1, 0xC($s0)
    /* 47338 800AFB38 23104600 */  subu       $v0, $v0, $a2
    /* 4733C 800AFB3C 21186600 */  addu       $v1, $v1, $a2
    /* 47340 800AFB40 120002A6 */  sh         $v0, 0x12($s0)
    /* 47344 800AFB44 0E0003A6 */  sh         $v1, 0xE($s0)
  .L800AFB48:
    /* 47348 800AFB48 40054286 */  lh         $v0, 0x540($s2)
    /* 4734C 800AFB4C BC058396 */  lhu        $v1, 0x5BC($s4)
    /* 47350 800AFB50 00000000 */  nop
    /* 47354 800AFB54 2A104300 */  slt        $v0, $v0, $v1
    /* 47358 800AFB58 10004014 */  bnez       $v0, .L800AFB9C
    /* 4735C 800AFB5C 0200033C */   lui       $v1, (0x20000 >> 16)
    /* 47360 800AFB60 4805428E */  lw         $v0, 0x548($s2)
    /* 47364 800AFB64 00000000 */  nop
    /* 47368 800AFB68 25104300 */  or         $v0, $v0, $v1
    /* 4736C 800AFB6C 480542AE */  sw         $v0, 0x548($s2)
    /* 47370 800AFB70 E0068292 */  lbu        $v0, 0x6E0($s4)
    /* 47374 800AFB74 00000000 */  nop
    /* 47378 800AFB78 08004010 */  beqz       $v0, .L800AFB9C
    /* 4737C 800AFB7C 00000000 */   nop
    /* 47380 800AFB80 0F008492 */  lbu        $a0, 0xF($s4)
    /* 47384 800AFB84 E1068692 */  lbu        $a2, 0x6E1($s4)
    /* 47388 800AFB88 E2068792 */  lbu        $a3, 0x6E2($s4)
    /* 4738C 800AFB8C 8681020C */  jal        func_800A0618
    /* 47390 800AFB90 21284000 */   addu      $a1, $v0, $zero
    /* 47394 800AFB94 6FBF0208 */  j          .L800AFDBC
    /* 47398 800AFB98 E00680A2 */   sb        $zero, 0x6E0($s4)
  .L800AFB9C:
    /* 4739C 800AFB9C 0800828E */  lw         $v0, 0x8($s4)
    /* 473A0 800AFBA0 00000000 */  nop
    /* 473A4 800AFBA4 04004230 */  andi       $v0, $v0, 0x4
    /* 473A8 800AFBA8 09004010 */  beqz       $v0, .L800AFBD0
    /* 473AC 800AFBAC 00000000 */   nop
    /* 473B0 800AFBB0 42054396 */  lhu        $v1, 0x542($s2)
    /* 473B4 800AFBB4 40054286 */  lh         $v0, 0x540($s2)
    /* 473B8 800AFBB8 00000000 */  nop
    /* 473BC 800AFBBC 05006214 */  bne        $v1, $v0, .L800AFBD4
    /* 473C0 800AFBC0 21208002 */   addu      $a0, $s4, $zero
    /* 473C4 800AFBC4 21284002 */  addu       $a1, $s2, $zero
    /* 473C8 800AFBC8 C5B5020C */  jal        func_800AD714
    /* 473CC 800AFBCC 2130C002 */   addu      $a2, $s6, $zero
  .L800AFBD0:
    /* 473D0 800AFBD0 40054286 */  lh         $v0, 0x540($s2)
  .L800AFBD4:
    /* 473D4 800AFBD4 BC058396 */  lhu        $v1, 0x5BC($s4)
    /* 473D8 800AFBD8 00000000 */  nop
    /* 473DC 800AFBDC 2A104300 */  slt        $v0, $v0, $v1
    /* 473E0 800AFBE0 40054396 */  lhu        $v1, 0x540($s2)
    /* 473E4 800AFBE4 06004014 */  bnez       $v0, .L800AFC00
    /* 473E8 800AFBE8 FFFF6224 */   addiu     $v0, $v1, -0x1
    /* 473EC 800AFBEC 400542A6 */  sh         $v0, 0x540($s2)
    /* 473F0 800AFBF0 4805428E */  lw         $v0, 0x548($s2)
    /* 473F4 800AFBF4 0100033C */  lui        $v1, (0x10000 >> 16)
    /* 473F8 800AFBF8 25104300 */  or         $v0, $v0, $v1
    /* 473FC 800AFBFC 480542AE */  sw         $v0, 0x548($s2)
  .L800AFC00:
    /* 47400 800AFC00 40054296 */  lhu        $v0, 0x540($s2)
    /* 47404 800AFC04 00000000 */  nop
    /* 47408 800AFC08 01004224 */  addiu      $v0, $v0, 0x1
    /* 4740C 800AFC0C 400542A6 */  sh         $v0, 0x540($s2)
    /* 47410 800AFC10 B2058292 */  lbu        $v0, 0x5B2($s4)
    /* 47414 800AFC14 01003126 */  addiu      $s1, $s1, 0x1
    /* 47418 800AFC18 2A102202 */  slt        $v0, $s1, $v0
    /* 4741C 800AFC1C 9BFF4014 */  bnez       $v0, .L800AFA8C
    /* 47420 800AFC20 00000000 */   nop
  .L800AFC24:
    /* 47424 800AFC24 40054486 */  lh         $a0, 0x540($s2)
    /* 47428 800AFC28 01000224 */  addiu      $v0, $zero, 0x1
    /* 4742C 800AFC2C 63008210 */  beq        $a0, $v0, .L800AFDBC
    /* 47430 800AFC30 0100033C */   lui       $v1, (0x10000 >> 16)
    /* 47434 800AFC34 4805428E */  lw         $v0, 0x548($s2)
    /* 47438 800AFC38 00000000 */  nop
    /* 4743C 800AFC3C 24104300 */  and        $v0, $v0, $v1
    /* 47440 800AFC40 5E004014 */  bnez       $v0, .L800AFDBC
    /* 47444 800AFC44 00000000 */   nop
    /* 47448 800AFC48 49054292 */  lbu        $v0, 0x549($s2)
    /* 4744C 800AFC4C 00000000 */  nop
    /* 47450 800AFC50 5A004014 */  bnez       $v0, .L800AFDBC
    /* 47454 800AFC54 FFFF9024 */   addiu     $s0, $a0, -0x1
    /* 47458 800AFC58 2A101302 */  slt        $v0, $s0, $s3
    /* 4745C 800AFC5C 02004010 */  beqz       $v0, .L800AFC68
    /* 47460 800AFC60 00000000 */   nop
    /* 47464 800AFC64 01001324 */  addiu      $s3, $zero, 0x1
  .L800AFC68:
    /* 47468 800AFC68 02006016 */  bnez       $s3, .L800AFC74
    /* 4746C 800AFC6C 21208002 */   addu      $a0, $s4, $zero
    /* 47470 800AFC70 01001324 */  addiu      $s3, $zero, 0x1
  .L800AFC74:
    /* 47474 800AFC74 B8058592 */  lbu        $a1, 0x5B8($s4)
    /* 47478 800AFC78 25B5020C */  jal        func_800AD494
    /* 4747C 800AFC7C 1000A627 */   addiu     $a2, $sp, 0x10
    /* 47480 800AFC80 21184000 */  addu       $v1, $v0, $zero
    /* 47484 800AFC84 4D006010 */  beqz       $v1, .L800AFDBC
    /* 47488 800AFC88 00000000 */   nop
    /* 4748C 800AFC8C 1000A28F */  lw         $v0, 0x10($sp)
    /* 47490 800AFC90 0800B3AE */  sw         $s3, 0x8($s5)
    /* 47494 800AFC94 0C00B0AE */  sw         $s0, 0xC($s5)
    /* 47498 800AFC98 1000A3AE */  sw         $v1, 0x10($s5)
    /* 4749C 800AFC9C 08004494 */  lhu        $a0, 0x8($v0)
    /* 474A0 800AFCA0 00000000 */  nop
    /* 474A4 800AFCA4 1E008010 */  beqz       $a0, .L800AFD20
    /* 474A8 800AFCA8 98024526 */   addiu     $a1, $s2, 0x298
    /* 474AC 800AFCAC 7ABF020C */  jal        func_800AFDE8
    /* 474B0 800AFCB0 21300000 */   addu      $a2, $zero, $zero
    /* 474B4 800AFCB4 98024386 */  lh         $v1, 0x298($s2)
    /* 474B8 800AFCB8 00000000 */  nop
    /* 474BC 800AFCBC 02006104 */  bgez       $v1, .L800AFCC8
    /* 474C0 800AFCC0 00000000 */   nop
    /* 474C4 800AFCC4 03006324 */  addiu      $v1, $v1, 0x3
  .L800AFCC8:
    /* 474C8 800AFCC8 1C008296 */  lhu        $v0, 0x1C($s4)
    /* 474CC 800AFCCC 83180300 */  sra        $v1, $v1, 2
    /* 474D0 800AFCD0 21104300 */  addu       $v0, $v0, $v1
    /* 474D4 800AFCD4 1C0082A6 */  sh         $v0, 0x1C($s4)
    /* 474D8 800AFCD8 9A024386 */  lh         $v1, 0x29A($s2)
    /* 474DC 800AFCDC 00000000 */  nop
    /* 474E0 800AFCE0 02006104 */  bgez       $v1, .L800AFCEC
    /* 474E4 800AFCE4 00000000 */   nop
    /* 474E8 800AFCE8 03006324 */  addiu      $v1, $v1, 0x3
  .L800AFCEC:
    /* 474EC 800AFCEC 1E008296 */  lhu        $v0, 0x1E($s4)
    /* 474F0 800AFCF0 83180300 */  sra        $v1, $v1, 2
    /* 474F4 800AFCF4 21104300 */  addu       $v0, $v0, $v1
    /* 474F8 800AFCF8 1E0082A6 */  sh         $v0, 0x1E($s4)
    /* 474FC 800AFCFC 9C024386 */  lh         $v1, 0x29C($s2)
    /* 47500 800AFD00 00000000 */  nop
    /* 47504 800AFD04 02006104 */  bgez       $v1, .L800AFD10
    /* 47508 800AFD08 00000000 */   nop
    /* 4750C 800AFD0C 03006324 */  addiu      $v1, $v1, 0x3
  .L800AFD10:
    /* 47510 800AFD10 20008296 */  lhu        $v0, 0x20($s4)
    /* 47514 800AFD14 83180300 */  sra        $v1, $v1, 2
    /* 47518 800AFD18 21104300 */  addu       $v0, $v0, $v1
    /* 4751C 800AFD1C 200082A6 */  sh         $v0, 0x20($s4)
  .L800AFD20:
    /* 47520 800AFD20 1000A28F */  lw         $v0, 0x10($sp)
    /* 47524 800AFD24 48014526 */  addiu      $a1, $s2, 0x148
    /* 47528 800AFD28 06004494 */  lhu        $a0, 0x6($v0)
    /* 4752C 800AFD2C 7ABF020C */  jal        func_800AFDE8
    /* 47530 800AFD30 21300000 */   addu      $a2, $zero, $zero
    /* 47534 800AFD34 00008292 */  lbu        $v0, 0x0($s4)
    /* 47538 800AFD38 00000000 */  nop
    /* 4753C 800AFD3C 1F004010 */  beqz       $v0, .L800AFDBC
    /* 47540 800AFD40 21880000 */   addu      $s1, $zero, $zero
    /* 47544 800AFD44 50011324 */  addiu      $s3, $zero, 0x150
    /* 47548 800AFD48 21804002 */  addu       $s0, $s2, $zero
  .L800AFD4C:
    /* 4754C 800AFD4C 21280002 */  addu       $a1, $s0, $zero
    /* 47550 800AFD50 1000A28F */  lw         $v0, 0x10($sp)
    /* 47554 800AFD54 40181100 */  sll        $v1, $s1, 1
    /* 47558 800AFD58 21186200 */  addu       $v1, $v1, $v0
    /* 4755C 800AFD5C 0A006494 */  lhu        $a0, 0xA($v1)
    /* 47560 800AFD60 7ABF020C */  jal        func_800AFDE8
    /* 47564 800AFD64 01000624 */   addiu     $a2, $zero, 0x1
    /* 47568 800AFD68 1000A38F */  lw         $v1, 0x10($sp)
    /* 4756C 800AFD6C 00000000 */  nop
    /* 47570 800AFD70 03006290 */  lbu        $v0, 0x3($v1)
    /* 47574 800AFD74 00000000 */  nop
    /* 47578 800AFD78 02004230 */  andi       $v0, $v0, 0x2
    /* 4757C 800AFD7C 09004010 */  beqz       $v0, .L800AFDA4
    /* 47580 800AFD80 21285302 */   addu      $a1, $s2, $s3
    /* 47584 800AFD84 00008292 */  lbu        $v0, 0x0($s4)
    /* 47588 800AFD88 00000000 */  nop
    /* 4758C 800AFD8C 21102202 */  addu       $v0, $s1, $v0
    /* 47590 800AFD90 40100200 */  sll        $v0, $v0, 1
    /* 47594 800AFD94 21104300 */  addu       $v0, $v0, $v1
    /* 47598 800AFD98 0A004494 */  lhu        $a0, 0xA($v0)
    /* 4759C 800AFD9C 7ABF020C */  jal        func_800AFDE8
    /* 475A0 800AFDA0 21300000 */   addu      $a2, $zero, $zero
  .L800AFDA4:
    /* 475A4 800AFDA4 08007326 */  addiu      $s3, $s3, 0x8
    /* 475A8 800AFDA8 00008292 */  lbu        $v0, 0x0($s4)
    /* 475AC 800AFDAC 01003126 */  addiu      $s1, $s1, 0x1
    /* 475B0 800AFDB0 2A102202 */  slt        $v0, $s1, $v0
    /* 475B4 800AFDB4 E5FF4014 */  bnez       $v0, .L800AFD4C
    /* 475B8 800AFDB8 08001026 */   addiu     $s0, $s0, 0x8
  .L800AFDBC:
    /* 475BC 800AFDBC 3400BF8F */  lw         $ra, 0x34($sp)
    /* 475C0 800AFDC0 3000B68F */  lw         $s6, 0x30($sp)
    /* 475C4 800AFDC4 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 475C8 800AFDC8 2800B48F */  lw         $s4, 0x28($sp)
    /* 475CC 800AFDCC 2400B38F */  lw         $s3, 0x24($sp)
    /* 475D0 800AFDD0 2000B28F */  lw         $s2, 0x20($sp)
    /* 475D4 800AFDD4 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 475D8 800AFDD8 1800B08F */  lw         $s0, 0x18($sp)
    /* 475DC 800AFDDC 3800BD27 */  addiu      $sp, $sp, 0x38
    /* 475E0 800AFDE0 0800E003 */  jr         $ra
    /* 475E4 800AFDE4 00000000 */   nop
endlabel func_800AFA28
