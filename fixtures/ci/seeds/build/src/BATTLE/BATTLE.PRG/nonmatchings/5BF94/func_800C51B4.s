nonmatching func_800C51B4, 0x1AC

glabel func_800C51B4
    /* 5C9B4 800C51B4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 5C9B8 800C51B8 2000B4AF */  sw         $s4, 0x20($sp)
    /* 5C9BC 800C51BC 21A08000 */  addu       $s4, $a0, $zero
    /* 5C9C0 800C51C0 0F80043C */  lui        $a0, %hi(D_800EB9B8)
    /* 5C9C4 800C51C4 B8B9838C */  lw         $v1, %lo(D_800EB9B8)($a0)
    /* 5C9C8 800C51C8 2800BFAF */  sw         $ra, 0x28($sp)
    /* 5C9CC 800C51CC 2400B5AF */  sw         $s5, 0x24($sp)
    /* 5C9D0 800C51D0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 5C9D4 800C51D4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5C9D8 800C51D8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5C9DC 800C51DC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5C9E0 800C51E0 31006290 */  lbu        $v0, 0x31($v1)
    /* 5C9E4 800C51E4 4000758C */  lw         $s5, 0x40($v1)
    /* 5C9E8 800C51E8 26004010 */  beqz       $v0, .L800C5284
    /* 5C9EC 800C51EC 03000224 */   addiu     $v0, $zero, 0x3
    /* 5C9F0 800C51F0 52008212 */  beq        $s4, $v0, .L800C533C
    /* 5C9F4 800C51F4 00000000 */   nop
    /* 5C9F8 800C51F8 2C006290 */  lbu        $v0, 0x2C($v1)
    /* 5C9FC 800C51FC 00000000 */  nop
    /* 5CA00 800C5200 4E004010 */  beqz       $v0, .L800C533C
    /* 5CA04 800C5204 21900000 */   addu      $s2, $zero, $zero
    /* 5CA08 800C5208 21988000 */  addu       $s3, $a0, $zero
    /* 5CA0C 800C520C 2188A002 */  addu       $s1, $s5, $zero
  .L800C5210:
    /* 5CA10 800C5210 09003092 */  lbu        $s0, 0x9($s1)
    /* 5CA14 800C5214 00000000 */  nop
    /* 5CA18 800C5218 03111000 */  sra        $v0, $s0, 4
    /* 5CA1C 800C521C 10004014 */  bnez       $v0, .L800C5260
    /* 5CA20 800C5220 01000224 */   addiu     $v0, $zero, 0x1
    /* 5CA24 800C5224 06008216 */  bne        $s4, $v0, .L800C5240
    /* 5CA28 800C5228 21200002 */   addu      $a0, $s0, $zero
    /* 5CA2C 800C522C 0A002582 */  lb         $a1, 0xA($s1)
    /* 5CA30 800C5230 4F14030C */  jal        func_800C513C
    /* 5CA34 800C5234 21200002 */   addu      $a0, $s0, $zero
    /* 5CA38 800C5238 96140308 */  j          .L800C5258
    /* 5CA3C 800C523C 21280000 */   addu      $a1, $zero, $zero
  .L800C5240:
    /* 5CA40 800C5240 0A002682 */  lb         $a2, 0xA($s1)
    /* 5CA44 800C5244 5914030C */  jal        func_800C5164
    /* 5CA48 800C5248 21280000 */   addu      $a1, $zero, $zero
    /* 5CA4C 800C524C B8B9628E */  lw         $v0, %lo(D_800EB9B8)($s3)
    /* 5CA50 800C5250 00000000 */  nop
    /* 5CA54 800C5254 34004524 */  addiu      $a1, $v0, 0x34
  .L800C5258:
    /* 5CA58 800C5258 6314030C */  jal        func_800C518C
    /* 5CA5C 800C525C 21200002 */   addu      $a0, $s0, $zero
  .L800C5260:
    /* 5CA60 800C5260 B8B9628E */  lw         $v0, %lo(D_800EB9B8)($s3)
    /* 5CA64 800C5264 00000000 */  nop
    /* 5CA68 800C5268 2C004290 */  lbu        $v0, 0x2C($v0)
    /* 5CA6C 800C526C 01005226 */  addiu      $s2, $s2, 0x1
    /* 5CA70 800C5270 2A104202 */  slt        $v0, $s2, $v0
    /* 5CA74 800C5274 E6FF4014 */  bnez       $v0, .L800C5210
    /* 5CA78 800C5278 18003126 */   addiu     $s1, $s1, 0x18
    /* 5CA7C 800C527C CF140308 */  j          .L800C533C
    /* 5CA80 800C5280 00000000 */   nop
  .L800C5284:
    /* 5CA84 800C5284 2D007290 */  lbu        $s2, 0x2D($v1)
    /* 5CA88 800C5288 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 5CA8C 800C528C 2B004212 */  beq        $s2, $v0, .L800C533C
    /* 5CA90 800C5290 01008232 */   andi      $v0, $s4, 0x1
    /* 5CA94 800C5294 0D004010 */  beqz       $v0, .L800C52CC
    /* 5CA98 800C5298 02008232 */   andi      $v0, $s4, 0x2
    /* 5CA9C 800C529C 2F007090 */  lbu        $s0, 0x2F($v1)
    /* 5CAA0 800C52A0 00000000 */  nop
    /* 5CAA4 800C52A4 03111000 */  sra        $v0, $s0, 4
    /* 5CAA8 800C52A8 08004014 */  bnez       $v0, .L800C52CC
    /* 5CAAC 800C52AC 02008232 */   andi      $v0, $s4, 0x2
    /* 5CAB0 800C52B0 30006580 */  lb         $a1, 0x30($v1)
    /* 5CAB4 800C52B4 4F14030C */  jal        func_800C513C
    /* 5CAB8 800C52B8 21200002 */   addu      $a0, $s0, $zero
    /* 5CABC 800C52BC 21200002 */  addu       $a0, $s0, $zero
    /* 5CAC0 800C52C0 6314030C */  jal        func_800C518C
    /* 5CAC4 800C52C4 21280000 */   addu      $a1, $zero, $zero
    /* 5CAC8 800C52C8 02008232 */  andi       $v0, $s4, 0x2
  .L800C52CC:
    /* 5CACC 800C52CC 1B004010 */  beqz       $v0, .L800C533C
    /* 5CAD0 800C52D0 0F80113C */   lui       $s1, %hi(D_800EB9B8)
    /* 5CAD4 800C52D4 40101200 */  sll        $v0, $s2, 1
    /* 5CAD8 800C52D8 21105200 */  addu       $v0, $v0, $s2
    /* 5CADC 800C52DC C0100200 */  sll        $v0, $v0, 3
    /* 5CAE0 800C52E0 21105500 */  addu       $v0, $v0, $s5
    /* 5CAE4 800C52E4 B8B9248E */  lw         $a0, %lo(D_800EB9B8)($s1)
    /* 5CAE8 800C52E8 09004390 */  lbu        $v1, 0x9($v0)
    /* 5CAEC 800C52EC 00000000 */  nop
    /* 5CAF0 800C52F0 2F0083A0 */  sb         $v1, 0x2F($a0)
    /* 5CAF4 800C52F4 B8B9238E */  lw         $v1, %lo(D_800EB9B8)($s1)
    /* 5CAF8 800C52F8 0A004290 */  lbu        $v0, 0xA($v0)
    /* 5CAFC 800C52FC 00000000 */  nop
    /* 5CB00 800C5300 300062A0 */  sb         $v0, 0x30($v1)
    /* 5CB04 800C5304 B8B9238E */  lw         $v1, %lo(D_800EB9B8)($s1)
    /* 5CB08 800C5308 00000000 */  nop
    /* 5CB0C 800C530C 2F007090 */  lbu        $s0, 0x2F($v1)
    /* 5CB10 800C5310 00000000 */  nop
    /* 5CB14 800C5314 03111000 */  sra        $v0, $s0, 4
    /* 5CB18 800C5318 08004014 */  bnez       $v0, .L800C533C
    /* 5CB1C 800C531C 21200002 */   addu      $a0, $s0, $zero
    /* 5CB20 800C5320 30006680 */  lb         $a2, 0x30($v1)
    /* 5CB24 800C5324 5914030C */  jal        func_800C5164
    /* 5CB28 800C5328 21280000 */   addu      $a1, $zero, $zero
    /* 5CB2C 800C532C B8B9258E */  lw         $a1, %lo(D_800EB9B8)($s1)
    /* 5CB30 800C5330 21200002 */  addu       $a0, $s0, $zero
    /* 5CB34 800C5334 6314030C */  jal        func_800C518C
    /* 5CB38 800C5338 3400A524 */   addiu     $a1, $a1, 0x34
  .L800C533C:
    /* 5CB3C 800C533C 2800BF8F */  lw         $ra, 0x28($sp)
    /* 5CB40 800C5340 2400B58F */  lw         $s5, 0x24($sp)
    /* 5CB44 800C5344 2000B48F */  lw         $s4, 0x20($sp)
    /* 5CB48 800C5348 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 5CB4C 800C534C 1800B28F */  lw         $s2, 0x18($sp)
    /* 5CB50 800C5350 1400B18F */  lw         $s1, 0x14($sp)
    /* 5CB54 800C5354 1000B08F */  lw         $s0, 0x10($sp)
    /* 5CB58 800C5358 0800E003 */  jr         $ra
    /* 5CB5C 800C535C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800C51B4
