/* Handwritten function */
nonmatching func_800B516C, 0xAC4

glabel func_800B516C
    /* 4C96C 800B516C 801F083C */  lui        $t0, (0x1F800390 >> 16)
    /* 4C970 800B5170 580310AD */  sw         $s0, (0x1F800358 & 0xFFFF)($t0)
    /* 4C974 800B5174 5C0311AD */  sw         $s1, (0x1F80035C & 0xFFFF)($t0)
    /* 4C978 800B5178 600312AD */  sw         $s2, (0x1F800360 & 0xFFFF)($t0)
    /* 4C97C 800B517C 640313AD */  sw         $s3, (0x1F800364 & 0xFFFF)($t0)
    /* 4C980 800B5180 680314AD */  sw         $s4, (0x1F800368 & 0xFFFF)($t0)
    /* 4C984 800B5184 6C0315AD */  sw         $s5, (0x1F80036C & 0xFFFF)($t0)
    /* 4C988 800B5188 700316AD */  sw         $s6, (0x1F800370 & 0xFFFF)($t0)
    /* 4C98C 800B518C 740317AD */  sw         $s7, (0x1F800374 & 0xFFFF)($t0)
    /* 4C990 800B5190 78031FAD */  sw         $ra, (0x1F800378 & 0xFFFF)($t0)
    /* 4C994 800B5194 7C031CAD */  sw         $gp, (0x1F80037C & 0xFFFF)($t0)
    /* 4C998 800B5198 80031EAD */  sw         $fp, (0x1F800380 & 0xFFFF)($t0)
    /* 4C99C 800B519C 90031C8D */  lw         $gp, (0x1F800390 & 0xFFFF)($t0)
    /* 4C9A0 800B51A0 FF00143C */  lui        $s4, (0xFFFFFF >> 16)
    /* 4C9A4 800B51A4 FFFF9436 */  ori        $s4, $s4, (0xFFFFFF & 0xFFFF)
    /* 4C9A8 800B51A8 00FC1C00 */  sll        $ra, $gp, 16
    /* 4C9AC 800B51AC 02E41C00 */  srl        $gp, $gp, 16
    /* 4C9B0 800B51B0 00E41C00 */  sll        $gp, $gp, 16
    /* 4C9B4 800B51B4 00FF153C */  lui        $s5, (0xFF000000 >> 16)
    /* 4C9B8 800B51B8 801F103C */  lui        $s0, (0x1F800392 >> 16)
    /* 4C9BC 800B51BC 0200B394 */  lhu        $s3, 0x2($a1)
    /* 4C9C0 800B51C0 3C00F28C */  lw         $s2, 0x3C($a3)
    /* 4C9C4 800B51C4 000C9E24 */  addiu      $fp, $a0, 0xC00
    /* 4C9C8 800B51C8 0000118E */  lw         $s1, (0x1F800000 & 0xFFFF)($s0)
    /* 4C9CC 800B51CC 0400178E */  lw         $s7, (0x1F800004 & 0xFFFF)($s0)
    /* 4C9D0 800B51D0 0000C68C */  lw         $a2, 0x0($a2)
    /* 4C9D4 800B51D4 FCFFF722 */  addi       $s7, $s7, -0x4 /* handwritten instruction */
    /* 4C9D8 800B51D8 6400B690 */  lbu        $s6, 0x64($a1)
    /* 4C9DC 800B51DC 0900A390 */  lbu        $v1, 0x9($a1)
    /* 4C9E0 800B51E0 2430D400 */  and        $a2, $a2, $s4
    /* 4C9E4 800B51E4 0F006330 */  andi       $v1, $v1, 0xF
    /* 4C9E8 800B51E8 05006010 */  beqz       $v1, .L800B5200
    /* 4C9EC 800B51EC 25C80000 */   or        $t9, $zero, $zero
    /* 4C9F0 800B51F0 07006328 */  slti       $v1, $v1, 0x7
    /* 4C9F4 800B51F4 02006014 */  bnez       $v1, .L800B5200
    /* 4C9F8 800B51F8 4000193C */   lui       $t9, (0x400000 >> 16)
    /* 4C9FC 800B51FC 2000193C */  lui        $t9, (0x200000 >> 16)
  .L800B5200:
    /* 4CA00 800B5200 09000834 */  ori        $t0, $zero, 0x9
    /* 4CA04 800B5204 9C0308AE */  sw         $t0, (0x1F80039C & 0xFFFF)($s0)
    /* 4CA08 800B5208 62006012 */  beqz       $s3, .L800B5394
    /* 4CA0C 800B520C 1000E724 */   addiu     $a3, $a3, 0x10
    /* 4CA10 800B5210 F0FFE724 */  addiu      $a3, $a3, -0x10
    /* 4CA14 800B5214 0007183C */  lui        $t8, (0x7000000 >> 16)
  .L800B5218:
    /* 4CA18 800B5218 9C03088E */  lw         $t0, (0x1F80039C & 0xFFFF)($s0)
    /* 4CA1C 800B521C 00000000 */  nop
    /* 4CA20 800B5220 024C0800 */  srl        $t1, $t0, 16
    /* 4CA24 800B5224 FFFF0831 */  andi       $t0, $t0, 0xFFFF
  .L800B5228:
    /* 4CA28 800B5228 FFFF0821 */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* 4CA2C 800B522C 59000005 */  bltz       $t0, .L800B5394
    /* 4CA30 800B5230 9C0308A6 */   sh        $t0, (0x1F80039C & 0xFFFF)($s0)
    /* 4CA34 800B5234 0E000011 */  beqz       $t0, .L800B5270
    /* 4CA38 800B5238 FFFF0B21 */   addi      $t3, $t0, -0x1 /* handwritten instruction */
    /* 4CA3C 800B523C 0000F384 */  lh         $s3, 0x0($a3)
    /* 4CA40 800B5240 0200E724 */  addiu      $a3, $a3, 0x2
    /* 4CA44 800B5244 20483301 */  add        $t1, $t1, $s3 /* handwritten instruction */
    /* 4CA48 800B5248 F7FF6012 */  beqz       $s3, .L800B5228
    /* 4CA4C 800B524C 9E0309A6 */   sh        $t1, (0x1F80039E & 0xFFFF)($s0)
    /* 4CA50 800B5250 06507601 */  srlv       $t2, $s6, $t3
    /* 4CA54 800B5254 01004A31 */  andi       $t2, $t2, 0x1
    /* 4CA58 800B5258 92031C86 */  lh         $gp, (0x1F800392 & 0xFFFF)($s0)
    /* 4CA5C 800B525C 08004011 */  beqz       $t2, .L800B5280
    /* 4CA60 800B5260 00000000 */   nop
    /* 4CA64 800B5264 80049C27 */  addiu      $gp, $gp, 0x480
    /* 4CA68 800B5268 A1D40208 */  j          .L800B5284
    /* 4CA6C 800B526C 00E41C00 */   sll       $gp, $gp, 16
  .L800B5270:
    /* 4CA70 800B5270 0200B394 */  lhu        $s3, 0x2($a1)
    /* 4CA74 800B5274 92031C86 */  lh         $gp, (0x1F800392 & 0xFFFF)($s0)
    /* 4CA78 800B5278 22986902 */  sub        $s3, $s3, $t1 /* handwritten instruction */
    /* 4CA7C 800B527C 45006012 */  beqz       $s3, .L800B5394
  .L800B5280:
    /* 4CA80 800B5280 00E41C00 */   sll       $gp, $gp, 16
  .L800B5284:
    /* 4CA84 800B5284 04004B8E */  lw         $t3, 0x4($s2)
  .L800B5288:
    /* 4CA88 800B5288 08004F8E */  lw         $t7, 0x8($s2)
    /* 4CA8C 800B528C FFFF6831 */  andi       $t0, $t3, 0xFFFF
    /* 4CA90 800B5290 024C0B00 */  srl        $t1, $t3, 16
    /* 4CA94 800B5294 FFFFEA31 */  andi       $t2, $t7, 0xFFFF
    /* 4CA98 800B5298 20600401 */  add        $t4, $t0, $a0 /* handwritten instruction */
    /* 4CA9C 800B529C 00008C8D */  lw         $t4, 0x0($t4)
    /* 4CAA0 800B52A0 20682401 */  add        $t5, $t1, $a0 /* handwritten instruction */
    /* 4CAA4 800B52A4 0000AD8D */  lw         $t5, 0x0($t5)
    /* 4CAA8 800B52A8 20704401 */  add        $t6, $t2, $a0 /* handwritten instruction */
    /* 4CAAC 800B52AC 0000CE8D */  lw         $t6, 0x0($t6)
    /* 4CAB0 800B52B0 00608C48 */  mtc2       $t4, $12 /* handwritten instruction */
    /* 4CAB4 800B52B4 00688D48 */  mtc2       $t5, $13 /* handwritten instruction */
    /* 4CAB8 800B52B8 00708E48 */  mtc2       $t6, $14 /* handwritten instruction */
    /* 4CABC 800B52BC 027C0F00 */  srl        $t7, $t7, 16
    /* 4CAC0 800B52C0 20401E01 */  add        $t0, $t0, $fp /* handwritten instruction */
    /* 4CAC4 800B52C4 0600404B */  nclip
    /* 4CAC8 800B52C8 0000088D */  lw         $t0, 0x0($t0)
    /* 4CACC 800B52CC 20483E01 */  add        $t1, $t1, $fp /* handwritten instruction */
    /* 4CAD0 800B52D0 00C00248 */  mfc2       $v0, $24 /* handwritten instruction */
    /* 4CAD4 800B52D4 20505E01 */  add        $t2, $t2, $fp /* handwritten instruction */
    /* 4CAD8 800B52D8 0500401C */  bgtz       $v0, .L800B52F0
    /* 4CADC 800B52DC FFFF7326 */   addiu     $s3, $s3, -0x1
    /* 4CAE0 800B52E0 CDFF6012 */  beqz       $s3, .L800B5218
    /* 4CAE4 800B52E4 10005226 */   addiu     $s2, $s2, 0x10
    /* 4CAE8 800B52E8 A2D40208 */  j          .L800B5288
    /* 4CAEC 800B52EC 04004B8E */   lw        $t3, 0x4($s2)
  .L800B52F0:
    /* 4CAF0 800B52F0 02002013 */  beqz       $t9, .L800B52FC
    /* 4CAF4 800B52F4 0024033C */   lui       $v1, (0x24000000 >> 16)
    /* 4CAF8 800B52F8 0026033C */  lui        $v1, (0x26000000 >> 16)
  .L800B52FC:
    /* 4CAFC 800B52FC 25186600 */  or         $v1, $v1, $a2
    /* 4CB00 800B5300 0000298D */  lw         $t1, 0x0($t1)
    /* 4CB04 800B5304 00004A8D */  lw         $t2, 0x0($t2)
    /* 4CB08 800B5308 00888848 */  mtc2       $t0, $17 /* handwritten instruction */
    /* 4CB0C 800B530C 00908948 */  mtc2       $t1, $18 /* handwritten instruction */
    /* 4CB10 800B5310 00988A48 */  mtc2       $t2, $19 /* handwritten instruction */
    /* 4CB14 800B5314 0C004B8E */  lw         $t3, 0xC($s2)
    /* 4CB18 800B5318 040023AE */  sw         $v1, 0x4($s1)
    /* 4CB1C 800B531C 2D00584B */  avsz3
    /* 4CB20 800B5320 08002CAE */  sw         $t4, 0x8($s1)
    /* 4CB24 800B5324 024C0B00 */  srl        $t1, $t3, 16
    /* 4CB28 800B5328 25483F01 */  or         $t1, $t1, $ra
    /* 4CB2C 800B532C 25483901 */  or         $t1, $t1, $t9
    /* 4CB30 800B5330 FFFF6831 */  andi       $t0, $t3, 0xFFFF
    /* 4CB34 800B5334 25401C01 */  or         $t0, $t0, $gp
    /* 4CB38 800B5338 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 4CB3C 800B533C 0C0028AE */  sw         $t0, 0xC($s1)
    /* 4CB40 800B5340 C007482C */  sltiu      $t0, $v0, 0x7C0
    /* 4CB44 800B5344 0F000011 */  beqz       $t0, .L800B5384
    /* 4CB48 800B5348 10002DAE */   sw        $t5, 0x10($s1)
    /* 4CB4C 800B534C 140029AE */  sw         $t1, 0x14($s1)
    /* 4CB50 800B5350 80100200 */  sll        $v0, $v0, 2
    /* 4CB54 800B5354 18002EAE */  sw         $t6, 0x18($s1)
    /* 4CB58 800B5358 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4CB5C 800B535C 1C002FAE */  sw         $t7, 0x1C($s1)
    /* 4CB60 800B5360 00004A8C */  lw         $t2, 0x0($v0)
    /* 4CB64 800B5364 24483402 */  and        $t1, $s1, $s4
    /* 4CB68 800B5368 24405401 */  and        $t0, $t2, $s4
    /* 4CB6C 800B536C 25401801 */  or         $t0, $t0, $t8
    /* 4CB70 800B5370 000028AE */  sw         $t0, 0x0($s1)
    /* 4CB74 800B5374 24405501 */  and        $t0, $t2, $s5
    /* 4CB78 800B5378 25400901 */  or         $t0, $t0, $t1
    /* 4CB7C 800B537C 000048AC */  sw         $t0, 0x0($v0)
    /* 4CB80 800B5380 20003126 */  addiu      $s1, $s1, 0x20
  .L800B5384:
    /* 4CB84 800B5384 A4FF6012 */  beqz       $s3, .L800B5218
    /* 4CB88 800B5388 10005226 */   addiu     $s2, $s2, 0x10
    /* 4CB8C 800B538C A2D40208 */  j          .L800B5288
    /* 4CB90 800B5390 04004B8E */   lw        $t3, 0x4($s2)
  .L800B5394:
    /* 4CB94 800B5394 09000834 */  ori        $t0, $zero, 0x9
    /* 4CB98 800B5398 9C0308AE */  sw         $t0, (0x1F80039C & 0xFFFF)($s0)
    /* 4CB9C 800B539C 0400B394 */  lhu        $s3, 0x4($a1)
    /* 4CBA0 800B53A0 0009183C */  lui        $t8, (0x9000000 >> 16)
    /* 4CBA4 800B53A4 68006012 */  beqz       $s3, .L800B5548
    /* 4CBA8 800B53A8 1000E724 */   addiu     $a3, $a3, 0x10
    /* 4CBAC 800B53AC F0FFE724 */  addiu      $a3, $a3, -0x10
  .L800B53B0:
    /* 4CBB0 800B53B0 9C03088E */  lw         $t0, (0x1F80039C & 0xFFFF)($s0)
    /* 4CBB4 800B53B4 00000000 */  nop
    /* 4CBB8 800B53B8 024C0800 */  srl        $t1, $t0, 16
    /* 4CBBC 800B53BC FFFF0831 */  andi       $t0, $t0, 0xFFFF
  .L800B53C0:
    /* 4CBC0 800B53C0 FFFF0821 */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* 4CBC4 800B53C4 60000005 */  bltz       $t0, .L800B5548
    /* 4CBC8 800B53C8 9C0308A6 */   sh        $t0, (0x1F80039C & 0xFFFF)($s0)
    /* 4CBCC 800B53CC 0E000011 */  beqz       $t0, .L800B5408
    /* 4CBD0 800B53D0 FFFF0B21 */   addi      $t3, $t0, -0x1 /* handwritten instruction */
    /* 4CBD4 800B53D4 0000F384 */  lh         $s3, 0x0($a3)
    /* 4CBD8 800B53D8 0200E724 */  addiu      $a3, $a3, 0x2
    /* 4CBDC 800B53DC 20483301 */  add        $t1, $t1, $s3 /* handwritten instruction */
    /* 4CBE0 800B53E0 F7FF6012 */  beqz       $s3, .L800B53C0
    /* 4CBE4 800B53E4 9E0309A6 */   sh        $t1, (0x1F80039E & 0xFFFF)($s0)
    /* 4CBE8 800B53E8 06507601 */  srlv       $t2, $s6, $t3
    /* 4CBEC 800B53EC 01004A31 */  andi       $t2, $t2, 0x1
    /* 4CBF0 800B53F0 92031C86 */  lh         $gp, (0x1F800392 & 0xFFFF)($s0)
    /* 4CBF4 800B53F4 08004011 */  beqz       $t2, .L800B5418
    /* 4CBF8 800B53F8 00000000 */   nop
    /* 4CBFC 800B53FC 80049C27 */  addiu      $gp, $gp, 0x480
    /* 4CC00 800B5400 07D50208 */  j          .L800B541C
    /* 4CC04 800B5404 00E41C00 */   sll       $gp, $gp, 16
  .L800B5408:
    /* 4CC08 800B5408 0400B394 */  lhu        $s3, 0x4($a1)
    /* 4CC0C 800B540C 92031C86 */  lh         $gp, (0x1F800392 & 0xFFFF)($s0)
    /* 4CC10 800B5410 22986902 */  sub        $s3, $s3, $t1 /* handwritten instruction */
    /* 4CC14 800B5414 4C006012 */  beqz       $s3, .L800B5548
  .L800B5418:
    /* 4CC18 800B5418 00E41C00 */   sll       $gp, $gp, 16
  .L800B541C:
    /* 4CC1C 800B541C 04004B8E */  lw         $t3, 0x4($s2)
  .L800B5420:
    /* 4CC20 800B5420 08004F8E */  lw         $t7, 0x8($s2)
    /* 4CC24 800B5424 FFFF6831 */  andi       $t0, $t3, 0xFFFF
    /* 4CC28 800B5428 024C0B00 */  srl        $t1, $t3, 16
    /* 4CC2C 800B542C FFFFEA31 */  andi       $t2, $t7, 0xFFFF
    /* 4CC30 800B5430 20600401 */  add        $t4, $t0, $a0 /* handwritten instruction */
    /* 4CC34 800B5434 00008C8D */  lw         $t4, 0x0($t4)
    /* 4CC38 800B5438 20682401 */  add        $t5, $t1, $a0 /* handwritten instruction */
    /* 4CC3C 800B543C 0000AD8D */  lw         $t5, 0x0($t5)
    /* 4CC40 800B5440 20704401 */  add        $t6, $t2, $a0 /* handwritten instruction */
    /* 4CC44 800B5444 0000CE8D */  lw         $t6, 0x0($t6)
    /* 4CC48 800B5448 00608C48 */  mtc2       $t4, $12 /* handwritten instruction */
    /* 4CC4C 800B544C 00688D48 */  mtc2       $t5, $13 /* handwritten instruction */
    /* 4CC50 800B5450 00708E48 */  mtc2       $t6, $14 /* handwritten instruction */
    /* 4CC54 800B5454 025C0F00 */  srl        $t3, $t7, 16
    /* 4CC58 800B5458 20788B00 */  add        $t7, $a0, $t3 /* handwritten instruction */
    /* 4CC5C 800B545C 0600404B */  nclip
    /* 4CC60 800B5460 20401E01 */  add        $t0, $t0, $fp /* handwritten instruction */
    /* 4CC64 800B5464 20483E01 */  add        $t1, $t1, $fp /* handwritten instruction */
    /* 4CC68 800B5468 20505E01 */  add        $t2, $t2, $fp /* handwritten instruction */
    /* 4CC6C 800B546C 0000088D */  lw         $t0, 0x0($t0)
    /* 4CC70 800B5470 00C00248 */  mfc2       $v0, $24 /* handwritten instruction */
    /* 4CC74 800B5474 20587E01 */  add        $t3, $t3, $fp /* handwritten instruction */
    /* 4CC78 800B5478 0500401C */  bgtz       $v0, .L800B5490
    /* 4CC7C 800B547C FFFF7326 */   addiu     $s3, $s3, -0x1
    /* 4CC80 800B5480 CBFF6012 */  beqz       $s3, .L800B53B0
    /* 4CC84 800B5484 14005226 */   addiu     $s2, $s2, 0x14
    /* 4CC88 800B5488 08D50208 */  j          .L800B5420
    /* 4CC8C 800B548C 04004B8E */   lw        $t3, 0x4($s2)
  .L800B5490:
    /* 4CC90 800B5490 02002013 */  beqz       $t9, .L800B549C
    /* 4CC94 800B5494 002C033C */   lui       $v1, (0x2C000000 >> 16)
    /* 4CC98 800B5498 002E033C */  lui        $v1, (0x2E000000 >> 16)
  .L800B549C:
    /* 4CC9C 800B549C 25186600 */  or         $v1, $v1, $a2
    /* 4CCA0 800B54A0 0000298D */  lw         $t1, 0x0($t1)
    /* 4CCA4 800B54A4 00004A8D */  lw         $t2, 0x0($t2)
    /* 4CCA8 800B54A8 20100901 */  add        $v0, $t0, $t1 /* handwritten instruction */
    /* 4CCAC 800B54AC 00006B8D */  lw         $t3, 0x0($t3)
    /* 4CCB0 800B54B0 20104A00 */  add        $v0, $v0, $t2 /* handwritten instruction */
    /* 4CCB4 800B54B4 20104B00 */  add        $v0, $v0, $t3 /* handwritten instruction */
    /* 4CCB8 800B54B8 02110200 */  srl        $v0, $v0, 4
    /* 4CCBC 800B54BC C007492C */  sltiu      $t1, $v0, 0x7C0
    /* 4CCC0 800B54C0 1D002011 */  beqz       $t1, .L800B5538
    /* 4CCC4 800B54C4 0000EF8D */   lw        $t7, 0x0($t7)
    /* 4CCC8 800B54C8 0C00488E */  lw         $t0, 0xC($s2)
    /* 4CCCC 800B54CC 10004A8E */  lw         $t2, 0x10($s2)
    /* 4CCD0 800B54D0 024C0800 */  srl        $t1, $t0, 16
    /* 4CCD4 800B54D4 25483F01 */  or         $t1, $t1, $ra
    /* 4CCD8 800B54D8 25483901 */  or         $t1, $t1, $t9
    /* 4CCDC 800B54DC FFFF0831 */  andi       $t0, $t0, 0xFFFF
    /* 4CCE0 800B54E0 25401C01 */  or         $t0, $t0, $gp
    /* 4CCE4 800B54E4 040023AE */  sw         $v1, 0x4($s1)
    /* 4CCE8 800B54E8 08002CAE */  sw         $t4, 0x8($s1)
    /* 4CCEC 800B54EC 0C0028AE */  sw         $t0, 0xC($s1)
    /* 4CCF0 800B54F0 10002DAE */  sw         $t5, 0x10($s1)
    /* 4CCF4 800B54F4 140029AE */  sw         $t1, 0x14($s1)
    /* 4CCF8 800B54F8 025C0A00 */  srl        $t3, $t2, 16
    /* 4CCFC 800B54FC 18002EAE */  sw         $t6, 0x18($s1)
    /* 4CD00 800B5500 1C002AAE */  sw         $t2, 0x1C($s1)
    /* 4CD04 800B5504 80100200 */  sll        $v0, $v0, 2
    /* 4CD08 800B5508 20002FAE */  sw         $t7, 0x20($s1)
    /* 4CD0C 800B550C 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4CD10 800B5510 24002BAE */  sw         $t3, 0x24($s1)
    /* 4CD14 800B5514 00004A8C */  lw         $t2, 0x0($v0)
    /* 4CD18 800B5518 24483402 */  and        $t1, $s1, $s4
    /* 4CD1C 800B551C 24405401 */  and        $t0, $t2, $s4
    /* 4CD20 800B5520 25401801 */  or         $t0, $t0, $t8
    /* 4CD24 800B5524 000028AE */  sw         $t0, 0x0($s1)
    /* 4CD28 800B5528 24405501 */  and        $t0, $t2, $s5
    /* 4CD2C 800B552C 25400901 */  or         $t0, $t0, $t1
    /* 4CD30 800B5530 000048AC */  sw         $t0, 0x0($v0)
    /* 4CD34 800B5534 28003126 */  addiu      $s1, $s1, 0x28
  .L800B5538:
    /* 4CD38 800B5538 9DFF6012 */  beqz       $s3, .L800B53B0
    /* 4CD3C 800B553C 14005226 */   addiu     $s2, $s2, 0x14
    /* 4CD40 800B5540 08D50208 */  j          .L800B5420
    /* 4CD44 800B5544 04004B8E */   lw        $t3, 0x4($s2)
  .L800B5548:
    /* 4CD48 800B5548 09000834 */  ori        $t0, $zero, 0x9
    /* 4CD4C 800B554C 9C0308AE */  sw         $t0, (0x1F80039C & 0xFFFF)($s0)
    /* 4CD50 800B5550 A00305AE */  sw         $a1, (0x1F8003A0 & 0xFFFF)($s0)
    /* 4CD54 800B5554 0600B394 */  lhu        $s3, 0x6($a1)
    /* 4CD58 800B5558 F0FFF722 */  addi       $s7, $s7, -0x10 /* handwritten instruction */
    /* 4CD5C 800B555C A6016012 */  beqz       $s3, .L800B5BF8
    /* 4CD60 800B5560 2528C003 */   or        $a1, $fp, $zero
  .L800B5564:
    /* 4CD64 800B5564 801F103C */  lui        $s0, (0x1F800392 >> 16)
    /* 4CD68 800B5568 9C03088E */  lw         $t0, (0x1F80039C & 0xFFFF)($s0)
    /* 4CD6C 800B556C A0030C8E */  lw         $t4, (0x1F8003A0 & 0xFFFF)($s0)
    /* 4CD70 800B5570 024C0800 */  srl        $t1, $t0, 16
    /* 4CD74 800B5574 FFFF0831 */  andi       $t0, $t0, 0xFFFF
  .L800B5578:
    /* 4CD78 800B5578 FFFF0821 */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* 4CD7C 800B557C 9E010005 */  bltz       $t0, .L800B5BF8
    /* 4CD80 800B5580 9C0308A6 */   sh        $t0, (0x1F80039C & 0xFFFF)($s0)
    /* 4CD84 800B5584 10000011 */  beqz       $t0, .L800B55C8
    /* 4CD88 800B5588 FFFF0B21 */   addi      $t3, $t0, -0x1 /* handwritten instruction */
    /* 4CD8C 800B558C 0000F394 */  lhu        $s3, 0x0($a3)
    /* 4CD90 800B5590 0200E724 */  addiu      $a3, $a3, 0x2
    /* 4CD94 800B5594 20483301 */  add        $t1, $t1, $s3 /* handwritten instruction */
    /* 4CD98 800B5598 F7FF6012 */  beqz       $s3, .L800B5578
    /* 4CD9C 800B559C 9E0309A6 */   sh        $t1, (0x1F80039E & 0xFFFF)($s0)
    /* 4CDA0 800B55A0 64009691 */  lbu        $s6, 0x64($t4)
    /* 4CDA4 800B55A4 00000000 */  nop
    /* 4CDA8 800B55A8 06507601 */  srlv       $t2, $s6, $t3
    /* 4CDAC 800B55AC 01004A31 */  andi       $t2, $t2, 0x1
    /* 4CDB0 800B55B0 92031C96 */  lhu        $gp, (0x1F800392 & 0xFFFF)($s0)
    /* 4CDB4 800B55B4 08004011 */  beqz       $t2, .L800B55D8
    /* 4CDB8 800B55B8 00000000 */   nop
    /* 4CDBC 800B55BC 80049C27 */  addiu      $gp, $gp, 0x480
    /* 4CDC0 800B55C0 77D50208 */  j          .L800B55DC
    /* 4CDC4 800B55C4 00E41C00 */   sll       $gp, $gp, 16
  .L800B55C8:
    /* 4CDC8 800B55C8 06009395 */  lhu        $s3, 0x6($t4)
    /* 4CDCC 800B55CC 92031C96 */  lhu        $gp, (0x1F800392 & 0xFFFF)($s0)
    /* 4CDD0 800B55D0 22986902 */  sub        $s3, $s3, $t1 /* handwritten instruction */
    /* 4CDD4 800B55D4 88016012 */  beqz       $s3, .L800B5BF8
  .L800B55D8:
    /* 4CDD8 800B55D8 00E41C00 */   sll       $gp, $gp, 16
  .L800B55DC:
    /* 4CDDC 800B55DC 00005E8E */  lw         $fp, 0x0($s2)
  .L800B55E0:
    /* 4CDE0 800B55E0 04004B8E */  lw         $t3, 0x4($s2)
    /* 4CDE4 800B55E4 021C1E00 */  srl        $v1, $fp, 16
    /* 4CDE8 800B55E8 01006230 */  andi       $v0, $v1, 0x1
    /* 4CDEC 800B55EC 08004F8E */  lw         $t7, 0x8($s2)
    /* 4CDF0 800B55F0 FFFF6831 */  andi       $t0, $t3, 0xFFFF
    /* 4CDF4 800B55F4 024C0B00 */  srl        $t1, $t3, 16
    /* 4CDF8 800B55F8 FFFFEA31 */  andi       $t2, $t7, 0xFFFF
    /* 4CDFC 800B55FC 20600401 */  add        $t4, $t0, $a0 /* handwritten instruction */
    /* 4CE00 800B5600 00008C8D */  lw         $t4, 0x0($t4)
    /* 4CE04 800B5604 20682401 */  add        $t5, $t1, $a0 /* handwritten instruction */
    /* 4CE08 800B5608 0000AD8D */  lw         $t5, 0x0($t5)
    /* 4CE0C 800B560C 20704401 */  add        $t6, $t2, $a0 /* handwritten instruction */
    /* 4CE10 800B5610 16004014 */  bnez       $v0, .L800B566C
    /* 4CE14 800B5614 0000CE8D */   lw        $t6, 0x0($t6)
    /* 4CE18 800B5618 00608C48 */  mtc2       $t4, $12 /* handwritten instruction */
    /* 4CE1C 800B561C 00688D48 */  mtc2       $t5, $13 /* handwritten instruction */
    /* 4CE20 800B5620 00708E48 */  mtc2       $t6, $14 /* handwritten instruction */
    /* 4CE24 800B5624 025C0F00 */  srl        $t3, $t7, 16
    /* 4CE28 800B5628 25806001 */  or         $s0, $t3, $zero
    /* 4CE2C 800B562C 0600404B */  nclip
    /* 4CE30 800B5630 20788B00 */  add        $t7, $a0, $t3 /* handwritten instruction */
    /* 4CE34 800B5634 20400501 */  add        $t0, $t0, $a1 /* handwritten instruction */
    /* 4CE38 800B5638 20482501 */  add        $t1, $t1, $a1 /* handwritten instruction */
    /* 4CE3C 800B563C 20504501 */  add        $t2, $t2, $a1 /* handwritten instruction */
    /* 4CE40 800B5640 20586501 */  add        $t3, $t3, $a1 /* handwritten instruction */
    /* 4CE44 800B5644 FF00D833 */  andi       $t8, $fp, 0xFF
    /* 4CE48 800B5648 021A1E00 */  srl        $v1, $fp, 8
    /* 4CE4C 800B564C 00C00248 */  mfc2       $v0, $24 /* handwritten instruction */
    /* 4CE50 800B5650 FF006330 */  andi       $v1, $v1, 0xFF
    /* 4CE54 800B5654 1000401C */  bgtz       $v0, .L800B5698
    /* 4CE58 800B5658 FFFF7326 */   addiu     $s3, $s3, -0x1
    /* 4CE5C 800B565C C1FF6012 */  beqz       $s3, .L800B5564
    /* 4CE60 800B5660 20904302 */   add       $s2, $s2, $v1 /* handwritten instruction */
    /* 4CE64 800B5664 78D50208 */  j          .L800B55E0
    /* 4CE68 800B5668 00005E8E */   lw        $fp, 0x0($s2)
  .L800B566C:
    /* 4CE6C 800B566C FFFF7326 */  addiu      $s3, $s3, -0x1
    /* 4CE70 800B5670 025C0F00 */  srl        $t3, $t7, 16
    /* 4CE74 800B5674 25806001 */  or         $s0, $t3, $zero
    /* 4CE78 800B5678 20788B00 */  add        $t7, $a0, $t3 /* handwritten instruction */
    /* 4CE7C 800B567C 20400501 */  add        $t0, $t0, $a1 /* handwritten instruction */
    /* 4CE80 800B5680 20482501 */  add        $t1, $t1, $a1 /* handwritten instruction */
    /* 4CE84 800B5684 20504501 */  add        $t2, $t2, $a1 /* handwritten instruction */
    /* 4CE88 800B5688 20586501 */  add        $t3, $t3, $a1 /* handwritten instruction */
    /* 4CE8C 800B568C 02006330 */  andi       $v1, $v1, 0x2
    /* 4CE90 800B5690 7B006014 */  bnez       $v1, .L800B5880
    /* 4CE94 800B5694 FF00D833 */   andi      $t8, $fp, 0xFF
  .L800B5698:
    /* 4CE98 800B5698 0000088D */  lw         $t0, 0x0($t0)
    /* 4CE9C 800B569C 2C000234 */  ori        $v0, $zero, 0x2C
    /* 4CEA0 800B56A0 0000298D */  lw         $t1, 0x0($t1)
    /* 4CEA4 800B56A4 39000213 */  beq        $t8, $v0, .L800B578C
    /* 4CEA8 800B56A8 00004A8D */   lw        $t2, 0x0($t2)
    /* 4CEAC 800B56AC 06002013 */  beqz       $t9, .L800B56C8
    /* 4CEB0 800B56B0 0FFF033C */   lui       $v1, (0xFF0FFFFF >> 16)
    /* 4CEB4 800B56B4 FFFF6334 */  ori        $v1, $v1, (0xFF0FFFFF & 0xFFFF)
    /* 4CEB8 800B56B8 24F0C303 */  and        $fp, $fp, $v1
    /* 4CEBC 800B56BC 1000033C */  lui        $v1, (0x100000 >> 16)
    /* 4CEC0 800B56C0 25F0C303 */  or         $fp, $fp, $v1
    /* 4CEC4 800B56C4 25F0D903 */  or         $fp, $fp, $t9
  .L800B56C8:
    /* 4CEC8 800B56C8 00888848 */  mtc2       $t0, $17 /* handwritten instruction */
    /* 4CECC 800B56CC 00908948 */  mtc2       $t1, $18 /* handwritten instruction */
    /* 4CED0 800B56D0 00988A48 */  mtc2       $t2, $19 /* handwritten instruction */
    /* 4CED4 800B56D4 02551E00 */  srl        $t2, $fp, 20
    /* 4CED8 800B56D8 01004A31 */  andi       $t2, $t2, 0x1
    /* 4CEDC 800B56DC 40560A00 */  sll        $t2, $t2, 25
    /* 4CEE0 800B56E0 0024033C */  lui        $v1, (0x24000000 >> 16)
    /* 4CEE4 800B56E4 25186A00 */  or         $v1, $v1, $t2
    /* 4CEE8 800B56E8 25186600 */  or         $v1, $v1, $a2
    /* 4CEEC 800B56EC 2D00584B */  avsz3
    /* 4CEF0 800B56F0 02541E00 */  srl        $t2, $fp, 16
    /* 4CEF4 800B56F4 60004A31 */  andi       $t2, $t2, 0x60
    /* 4CEF8 800B56F8 00540A00 */  sll        $t2, $t2, 16
    /* 4CEFC 800B56FC 0C00488E */  lw         $t0, 0xC($s2)
    /* 4CF00 800B5700 040023AE */  sw         $v1, 0x4($s1)
    /* 4CF04 800B5704 024C0800 */  srl        $t1, $t0, 16
    /* 4CF08 800B5708 25483F01 */  or         $t1, $t1, $ra
    /* 4CF0C 800B570C 25482A01 */  or         $t1, $t1, $t2
    /* 4CF10 800B5710 FFFF0831 */  andi       $t0, $t0, 0xFFFF
    /* 4CF14 800B5714 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 4CF18 800B5718 25401C01 */  or         $t0, $t0, $gp
    /* 4CF1C 800B571C C007582C */  sltiu      $t8, $v0, 0x7C0
    /* 4CF20 800B5720 16000013 */  beqz       $t8, .L800B577C
    /* 4CF24 800B5724 08002CAE */   sw        $t4, 0x8($s1)
    /* 4CF28 800B5728 0C0028AE */  sw         $t0, 0xC($s1)
    /* 4CF2C 800B572C 10002DAE */  sw         $t5, 0x10($s1)
    /* 4CF30 800B5730 821C1E00 */  srl        $v1, $fp, 18
    /* 4CF34 800B5734 140029AE */  sw         $t1, 0x14($s1)
    /* 4CF38 800B5738 03006330 */  andi       $v1, $v1, 0x3
    /* 4CF3C 800B573C 18002EAE */  sw         $t6, 0x18($s1)
    /* 4CF40 800B5740 80180300 */  sll        $v1, $v1, 2
    /* 4CF44 800B5744 1C0030AE */  sw         $s0, 0x1C($s1)
    /* 4CF48 800B5748 20104300 */  add        $v0, $v0, $v1 /* handwritten instruction */
    /* 4CF4C 800B574C 80100200 */  sll        $v0, $v0, 2
    /* 4CF50 800B5750 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4CF54 800B5754 0000438C */  lw         $v1, 0x0($v0)
    /* 4CF58 800B5758 0007183C */  lui        $t8, (0x7000000 >> 16)
    /* 4CF5C 800B575C 24407400 */  and        $t0, $v1, $s4
    /* 4CF60 800B5760 25401801 */  or         $t0, $t0, $t8
    /* 4CF64 800B5764 000028AE */  sw         $t0, 0x0($s1)
    /* 4CF68 800B5768 24483402 */  and        $t1, $s1, $s4
    /* 4CF6C 800B576C 24407500 */  and        $t0, $v1, $s5
    /* 4CF70 800B5770 25400901 */  or         $t0, $t0, $t1
    /* 4CF74 800B5774 000048AC */  sw         $t0, 0x0($v0)
    /* 4CF78 800B5778 20003126 */  addiu      $s1, $s1, 0x20
  .L800B577C:
    /* 4CF7C 800B577C 79FF6012 */  beqz       $s3, .L800B5564
    /* 4CF80 800B5780 10005226 */   addiu     $s2, $s2, 0x10
    /* 4CF84 800B5784 78D50208 */  j          .L800B55E0
    /* 4CF88 800B5788 00005E8E */   lw        $fp, 0x0($s2)
  .L800B578C:
    /* 4CF8C 800B578C 06002013 */  beqz       $t9, .L800B57A8
    /* 4CF90 800B5790 0FFF033C */   lui       $v1, (0xFF0FFFFF >> 16)
    /* 4CF94 800B5794 FFFF6334 */  ori        $v1, $v1, (0xFF0FFFFF & 0xFFFF)
    /* 4CF98 800B5798 24F0C303 */  and        $fp, $fp, $v1
    /* 4CF9C 800B579C 1000033C */  lui        $v1, (0x100000 >> 16)
    /* 4CFA0 800B57A0 25F0C303 */  or         $fp, $fp, $v1
    /* 4CFA4 800B57A4 25F0D903 */  or         $fp, $fp, $t9
  .L800B57A8:
    /* 4CFA8 800B57A8 00006B8D */  lw         $t3, 0x0($t3)
    /* 4CFAC 800B57AC 20100901 */  add        $v0, $t0, $t1 /* handwritten instruction */
    /* 4CFB0 800B57B0 0000EF8D */  lw         $t7, 0x0($t7)
    /* 4CFB4 800B57B4 20104A00 */  add        $v0, $v0, $t2 /* handwritten instruction */
    /* 4CFB8 800B57B8 20104B00 */  add        $v0, $v0, $t3 /* handwritten instruction */
    /* 4CFBC 800B57BC 02110200 */  srl        $v0, $v0, 4
    /* 4CFC0 800B57C0 C007582C */  sltiu      $t8, $v0, 0x7C0
    /* 4CFC4 800B57C4 2A000013 */  beqz       $t8, .L800B5870
    /* 4CFC8 800B57C8 0C00488E */   lw        $t0, 0xC($s2)
    /* 4CFCC 800B57CC 10004A8E */  lw         $t2, 0x10($s2)
    /* 4CFD0 800B57D0 024C0800 */  srl        $t1, $t0, 16
    /* 4CFD4 800B57D4 25483F01 */  or         $t1, $t1, $ra
    /* 4CFD8 800B57D8 02C51E00 */  srl        $t8, $fp, 20
    /* 4CFDC 800B57DC 01001833 */  andi       $t8, $t8, 0x1
    /* 4CFE0 800B57E0 40C61800 */  sll        $t8, $t8, 25
    /* 4CFE4 800B57E4 002C033C */  lui        $v1, (0x2C000000 >> 16)
    /* 4CFE8 800B57E8 25187800 */  or         $v1, $v1, $t8
    /* 4CFEC 800B57EC 25186600 */  or         $v1, $v1, $a2
    /* 4CFF0 800B57F0 040023AE */  sw         $v1, 0x4($s1)
    /* 4CFF4 800B57F4 FFFF0831 */  andi       $t0, $t0, 0xFFFF
    /* 4CFF8 800B57F8 08002CAE */  sw         $t4, 0x8($s1)
    /* 4CFFC 800B57FC 25401C01 */  or         $t0, $t0, $gp
    /* 4D000 800B5800 0C0028AE */  sw         $t0, 0xC($s1)
    /* 4D004 800B5804 02C41E00 */  srl        $t8, $fp, 16
    /* 4D008 800B5808 60001833 */  andi       $t8, $t8, 0x60
    /* 4D00C 800B580C 00C41800 */  sll        $t8, $t8, 16
    /* 4D010 800B5810 10002DAE */  sw         $t5, 0x10($s1)
    /* 4D014 800B5814 25483801 */  or         $t1, $t1, $t8
    /* 4D018 800B5818 140029AE */  sw         $t1, 0x14($s1)
    /* 4D01C 800B581C 025C0A00 */  srl        $t3, $t2, 16
    /* 4D020 800B5820 18002EAE */  sw         $t6, 0x18($s1)
    /* 4D024 800B5824 1C002AAE */  sw         $t2, 0x1C($s1)
    /* 4D028 800B5828 821C1E00 */  srl        $v1, $fp, 18
    /* 4D02C 800B582C 20002FAE */  sw         $t7, 0x20($s1)
    /* 4D030 800B5830 03006330 */  andi       $v1, $v1, 0x3
    /* 4D034 800B5834 24002BAE */  sw         $t3, 0x24($s1)
    /* 4D038 800B5838 80180300 */  sll        $v1, $v1, 2
    /* 4D03C 800B583C 20104300 */  add        $v0, $v0, $v1 /* handwritten instruction */
    /* 4D040 800B5840 80100200 */  sll        $v0, $v0, 2
    /* 4D044 800B5844 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4D048 800B5848 0000438C */  lw         $v1, 0x0($v0)
    /* 4D04C 800B584C 0009183C */  lui        $t8, (0x9000000 >> 16)
    /* 4D050 800B5850 24407400 */  and        $t0, $v1, $s4
    /* 4D054 800B5854 25401801 */  or         $t0, $t0, $t8
    /* 4D058 800B5858 000028AE */  sw         $t0, 0x0($s1)
    /* 4D05C 800B585C 24483402 */  and        $t1, $s1, $s4
    /* 4D060 800B5860 24407500 */  and        $t0, $v1, $s5
    /* 4D064 800B5864 25400901 */  or         $t0, $t0, $t1
    /* 4D068 800B5868 000048AC */  sw         $t0, 0x0($v0)
    /* 4D06C 800B586C 28003126 */  addiu      $s1, $s1, 0x28
  .L800B5870:
    /* 4D070 800B5870 3CFF6012 */  beqz       $s3, .L800B5564
    /* 4D074 800B5874 14005226 */   addiu     $s2, $s2, 0x14
    /* 4D078 800B5878 78D50208 */  j          .L800B55E0
    /* 4D07C 800B587C 00005E8E */   lw        $fp, 0x0($s2)
  .L800B5880:
    /* 4D080 800B5880 0000088D */  lw         $t0, 0x0($t0)
    /* 4D084 800B5884 0000298D */  lw         $t1, 0x0($t1)
    /* 4D088 800B5888 00004A8D */  lw         $t2, 0x0($t2)
    /* 4D08C 800B588C 00140C00 */  sll        $v0, $t4, 16
    /* 4D090 800B5890 001C0E00 */  sll        $v1, $t6, 16
    /* 4D094 800B5894 03140200 */  sra        $v0, $v0, 16
    /* 4D098 800B5898 031C0300 */  sra        $v1, $v1, 16
    /* 4D09C 800B589C 23C06200 */  subu       $t8, $v1, $v0
    /* 4D0A0 800B58A0 0000D848 */  ctc2       $t8, $0 /* handwritten instruction */
    /* 4D0A4 800B58A4 03840C00 */  sra        $s0, $t4, 16
    /* 4D0A8 800B58A8 031C0E00 */  sra        $v1, $t6, 16
    /* 4D0AC 800B58AC 23C07000 */  subu       $t8, $v1, $s0
    /* 4D0B0 800B58B0 0010D848 */  ctc2       $t8, $2 /* handwritten instruction */
    /* 4D0B4 800B58B4 23804801 */  subu       $s0, $t2, $t0
    /* 4D0B8 800B58B8 0020D048 */  ctc2       $s0, $4 /* handwritten instruction */
    /* 4D0BC 800B58BC 23802801 */  subu       $s0, $t1, $t0
    /* 4D0C0 800B58C0 00589048 */  mtc2       $s0, $11 /* handwritten instruction */
    /* 4D0C4 800B58C4 001C0D00 */  sll        $v1, $t5, 16
    /* 4D0C8 800B58C8 031C0300 */  sra        $v1, $v1, 16
    /* 4D0CC 800B58CC 23C06200 */  subu       $t8, $v1, $v0
    /* 4D0D0 800B58D0 00489848 */  mtc2       $t8, $9 /* handwritten instruction */
    /* 4D0D4 800B58D4 03840C00 */  sra        $s0, $t4, 16
    /* 4D0D8 800B58D8 031C0D00 */  sra        $v1, $t5, 16
    /* 4D0DC 800B58DC 23C07000 */  subu       $t8, $v1, $s0
    /* 4D0E0 800B58E0 00509848 */  mtc2       $t8, $10 /* handwritten instruction */
    /* 4D0E4 800B58E4 00000000 */  nop
    /* 4D0E8 800B58E8 0C00704B */  op         0
    /* 4D0EC 800B58EC 0000EF8D */  lw         $t7, 0x0($t7)
    /* 4D0F0 800B58F0 00C81648 */  mfc2       $s6, $25 /* handwritten instruction */
    /* 4D0F4 800B58F4 001C0F00 */  sll        $v1, $t7, 16
    /* 4D0F8 800B58F8 031C0300 */  sra        $v1, $v1, 16
    /* 4D0FC 800B58FC 23C06200 */  subu       $t8, $v1, $v0
    /* 4D100 800B5900 19001603 */  multu      $t8, $s6
    /* 4D104 800B5904 031C0F00 */  sra        $v1, $t7, 16
    /* 4D108 800B5908 12C00000 */  mflo       $t8
    /* 4D10C 800B590C 00D00248 */  mfc2       $v0, $26 /* handwritten instruction */
    /* 4D110 800B5910 23B07000 */  subu       $s6, $v1, $s0
    /* 4D114 800B5914 1900C202 */  multu      $s6, $v0
    /* 4D118 800B5918 00006B8D */  lw         $t3, 0x0($t3)
    /* 4D11C 800B591C 12B00000 */  mflo       $s6
    /* 4D120 800B5920 00D80248 */  mfc2       $v0, $27 /* handwritten instruction */
    /* 4D124 800B5924 23186801 */  subu       $v1, $t3, $t0
    /* 4D128 800B5928 19004300 */  multu      $v0, $v1
    /* 4D12C 800B592C 20C01603 */  add        $t8, $t8, $s6 /* handwritten instruction */
    /* 4D130 800B5930 00608C48 */  mtc2       $t4, $12 /* handwritten instruction */
    /* 4D134 800B5934 00688D48 */  mtc2       $t5, $13 /* handwritten instruction */
    /* 4D138 800B5938 12100000 */  mflo       $v0
    /* 4D13C 800B593C 20100203 */  add        $v0, $t8, $v0 /* handwritten instruction */
    /* 4D140 800B5940 23100200 */  negu       $v0, $v0
    /* 4D144 800B5944 5600401C */  bgtz       $v0, .L800B5AA0
    /* 4D148 800B5948 00000000 */   nop
    /* 4D14C 800B594C 00708F48 */  mtc2       $t7, $14 /* handwritten instruction */
    /* 4D150 800B5950 00888848 */  mtc2       $t0, $17 /* handwritten instruction */
    /* 4D154 800B5954 00908948 */  mtc2       $t1, $18 /* handwritten instruction */
    /* 4D158 800B5958 0600404B */  nclip
    /* 4D15C 800B595C 00988B48 */  mtc2       $t3, $19 /* handwritten instruction */
    /* 4D160 800B5960 0C00488E */  lw         $t0, 0xC($s2)
    /* 4D164 800B5964 1000568E */  lw         $s6, 0x10($s2)
    /* 4D168 800B5968 024C0800 */  srl        $t1, $t0, 16
    /* 4D16C 800B596C 00C00248 */  mfc2       $v0, $24 /* handwritten instruction */
    /* 4D170 800B5970 FFFF0831 */  andi       $t0, $t0, 0xFFFF
    /* 4D174 800B5974 20004018 */  blez       $v0, .L800B59F8
    /* 4D178 800B5978 25401C01 */   or        $t0, $t0, $gp
    /* 4D17C 800B597C 2D00584B */  avsz3
    /* 4D180 800B5980 02002013 */  beqz       $t9, .L800B598C
    /* 4D184 800B5984 0024033C */   lui       $v1, (0x24000000 >> 16)
    /* 4D188 800B5988 0026033C */  lui        $v1, (0x26000000 >> 16)
  .L800B598C:
    /* 4D18C 800B598C 25186600 */  or         $v1, $v1, $a2
    /* 4D190 800B5990 040023AE */  sw         $v1, 0x4($s1)
    /* 4D194 800B5994 08002CAE */  sw         $t4, 0x8($s1)
    /* 4D198 800B5998 0C0028AE */  sw         $t0, 0xC($s1)
    /* 4D19C 800B599C 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 4D1A0 800B59A0 10002DAE */  sw         $t5, 0x10($s1)
    /* 4D1A4 800B59A4 C007582C */  sltiu      $t8, $v0, 0x7C0
    /* 4D1A8 800B59A8 13000013 */  beqz       $t8, .L800B59F8
    /* 4D1AC 800B59AC 25483F01 */   or        $t1, $t1, $ra
    /* 4D1B0 800B59B0 25483901 */  or         $t1, $t1, $t9
    /* 4D1B4 800B59B4 140029AE */  sw         $t1, 0x14($s1)
    /* 4D1B8 800B59B8 025C1600 */  srl        $t3, $s6, 16
    /* 4D1BC 800B59BC 18002FAE */  sw         $t7, 0x18($s1)
    /* 4D1C0 800B59C0 1C002BAE */  sw         $t3, 0x1C($s1)
    /* 4D1C4 800B59C4 04004224 */  addiu      $v0, $v0, 0x4
    /* 4D1C8 800B59C8 80100200 */  sll        $v0, $v0, 2
    /* 4D1CC 800B59CC 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4D1D0 800B59D0 0000438C */  lw         $v1, 0x0($v0)
    /* 4D1D4 800B59D4 0007183C */  lui        $t8, (0x7000000 >> 16)
    /* 4D1D8 800B59D8 24807400 */  and        $s0, $v1, $s4
    /* 4D1DC 800B59DC 25801802 */  or         $s0, $s0, $t8
    /* 4D1E0 800B59E0 000030AE */  sw         $s0, 0x0($s1)
    /* 4D1E4 800B59E4 24483402 */  and        $t1, $s1, $s4
    /* 4D1E8 800B59E8 24807500 */  and        $s0, $v1, $s5
    /* 4D1EC 800B59EC 25800902 */  or         $s0, $s0, $t1
    /* 4D1F0 800B59F0 000050AC */  sw         $s0, 0x0($v0)
    /* 4D1F4 800B59F4 20003126 */  addiu      $s1, $s1, 0x20
  .L800B59F8:
    /* 4D1F8 800B59F8 00688F48 */  mtc2       $t7, $13 /* handwritten instruction */
    /* 4D1FC 800B59FC 00708E48 */  mtc2       $t6, $14 /* handwritten instruction */
    /* 4D200 800B5A00 00908A48 */  mtc2       $t2, $18 /* handwritten instruction */
    /* 4D204 800B5A04 0024033C */  lui        $v1, (0x24000000 >> 16)
    /* 4D208 800B5A08 0600404B */  nclip
    /* 4D20C 800B5A0C 02002013 */  beqz       $t9, .L800B5A18
    /* 4D210 800B5A10 0024033C */   lui       $v1, (0x24000000 >> 16)
    /* 4D214 800B5A14 0026033C */  lui        $v1, (0x26000000 >> 16)
  .L800B5A18:
    /* 4D218 800B5A18 25186600 */  or         $v1, $v1, $a2
    /* 4D21C 800B5A1C 025C1600 */  srl        $t3, $s6, 16
    /* 4D220 800B5A20 25587F01 */  or         $t3, $t3, $ra
    /* 4D224 800B5A24 25587901 */  or         $t3, $t3, $t9
    /* 4D228 800B5A28 040023AE */  sw         $v1, 0x4($s1)
    /* 4D22C 800B5A2C 00C00248 */  mfc2       $v0, $24 /* handwritten instruction */
    /* 4D230 800B5A30 08002CAE */  sw         $t4, 0x8($s1)
    /* 4D234 800B5A34 15004018 */  blez       $v0, .L800B5A8C
    /* 4D238 800B5A38 0C0028AE */   sw        $t0, 0xC($s1)
    /* 4D23C 800B5A3C 2D00584B */  avsz3
    /* 4D240 800B5A40 10002FAE */  sw         $t7, 0x10($s1)
    /* 4D244 800B5A44 14002BAE */  sw         $t3, 0x14($s1)
    /* 4D248 800B5A48 18002EAE */  sw         $t6, 0x18($s1)
    /* 4D24C 800B5A4C 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 4D250 800B5A50 1C0036AE */  sw         $s6, 0x1C($s1)
    /* 4D254 800B5A54 C007582C */  sltiu      $t8, $v0, 0x7C0
    /* 4D258 800B5A58 0D000013 */  beqz       $t8, .L800B5A90
    /* 4D25C 800B5A5C 04004224 */   addiu     $v0, $v0, 0x4
    /* 4D260 800B5A60 80100200 */  sll        $v0, $v0, 2
    /* 4D264 800B5A64 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4D268 800B5A68 0000438C */  lw         $v1, 0x0($v0)
    /* 4D26C 800B5A6C 0007183C */  lui        $t8, (0x7000000 >> 16)
    /* 4D270 800B5A70 24407400 */  and        $t0, $v1, $s4
    /* 4D274 800B5A74 25401801 */  or         $t0, $t0, $t8
    /* 4D278 800B5A78 000028AE */  sw         $t0, 0x0($s1)
    /* 4D27C 800B5A7C 24483402 */  and        $t1, $s1, $s4
    /* 4D280 800B5A80 24407500 */  and        $t0, $v1, $s5
    /* 4D284 800B5A84 25400901 */  or         $t0, $t0, $t1
    /* 4D288 800B5A88 000048AC */  sw         $t0, 0x0($v0)
  .L800B5A8C:
    /* 4D28C 800B5A8C 20003126 */  addiu      $s1, $s1, 0x20
  .L800B5A90:
    /* 4D290 800B5A90 B4FE6012 */  beqz       $s3, .L800B5564
    /* 4D294 800B5A94 14005226 */   addiu     $s2, $s2, 0x14
    /* 4D298 800B5A98 78D50208 */  j          .L800B55E0
    /* 4D29C 800B5A9C 00005E8E */   lw        $fp, 0x0($s2)
  .L800B5AA0:
    /* 4D2A0 800B5AA0 00708E48 */  mtc2       $t6, $14 /* handwritten instruction */
    /* 4D2A4 800B5AA4 00888848 */  mtc2       $t0, $17 /* handwritten instruction */
    /* 4D2A8 800B5AA8 00908948 */  mtc2       $t1, $18 /* handwritten instruction */
    /* 4D2AC 800B5AAC 0600404B */  nclip
    /* 4D2B0 800B5AB0 00988A48 */  mtc2       $t2, $19 /* handwritten instruction */
    /* 4D2B4 800B5AB4 0C00488E */  lw         $t0, 0xC($s2)
    /* 4D2B8 800B5AB8 1000568E */  lw         $s6, 0x10($s2)
    /* 4D2BC 800B5ABC 024C0800 */  srl        $t1, $t0, 16
    /* 4D2C0 800B5AC0 00C00248 */  mfc2       $v0, $24 /* handwritten instruction */
    /* 4D2C4 800B5AC4 02002013 */  beqz       $t9, .L800B5AD0
    /* 4D2C8 800B5AC8 0024033C */   lui       $v1, (0x24000000 >> 16)
    /* 4D2CC 800B5ACC 0026033C */  lui        $v1, (0x26000000 >> 16)
  .L800B5AD0:
    /* 4D2D0 800B5AD0 1D004018 */  blez       $v0, .L800B5B48
    /* 4D2D4 800B5AD4 25186600 */   or        $v1, $v1, $a2
    /* 4D2D8 800B5AD8 2D00584B */  avsz3
    /* 4D2DC 800B5ADC 040023AE */  sw         $v1, 0x4($s1)
    /* 4D2E0 800B5AE0 08002CAE */  sw         $t4, 0x8($s1)
    /* 4D2E4 800B5AE4 FFFF0831 */  andi       $t0, $t0, 0xFFFF
    /* 4D2E8 800B5AE8 25401C01 */  or         $t0, $t0, $gp
    /* 4D2EC 800B5AEC 0C0028AE */  sw         $t0, 0xC($s1)
    /* 4D2F0 800B5AF0 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 4D2F4 800B5AF4 10002DAE */  sw         $t5, 0x10($s1)
    /* 4D2F8 800B5AF8 C007582C */  sltiu      $t8, $v0, 0x7C0
    /* 4D2FC 800B5AFC 12000013 */  beqz       $t8, .L800B5B48
    /* 4D300 800B5B00 25483F01 */   or        $t1, $t1, $ra
    /* 4D304 800B5B04 25483901 */  or         $t1, $t1, $t9
    /* 4D308 800B5B08 140029AE */  sw         $t1, 0x14($s1)
    /* 4D30C 800B5B0C 04004224 */  addiu      $v0, $v0, 0x4
    /* 4D310 800B5B10 18002EAE */  sw         $t6, 0x18($s1)
    /* 4D314 800B5B14 80100200 */  sll        $v0, $v0, 2
    /* 4D318 800B5B18 1C0036AE */  sw         $s6, 0x1C($s1)
    /* 4D31C 800B5B1C 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4D320 800B5B20 0000438C */  lw         $v1, 0x0($v0)
    /* 4D324 800B5B24 0007183C */  lui        $t8, (0x7000000 >> 16)
    /* 4D328 800B5B28 24807400 */  and        $s0, $v1, $s4
    /* 4D32C 800B5B2C 25801802 */  or         $s0, $s0, $t8
    /* 4D330 800B5B30 000030AE */  sw         $s0, 0x0($s1)
    /* 4D334 800B5B34 24403402 */  and        $t0, $s1, $s4
    /* 4D338 800B5B38 24807500 */  and        $s0, $v1, $s5
    /* 4D33C 800B5B3C 25800802 */  or         $s0, $s0, $t0
    /* 4D340 800B5B40 000050AC */  sw         $s0, 0x0($v0)
    /* 4D344 800B5B44 20003126 */  addiu      $s1, $s1, 0x20
  .L800B5B48:
    /* 4D348 800B5B48 00608D48 */  mtc2       $t5, $12 /* handwritten instruction */
    /* 4D34C 800B5B4C 00688F48 */  mtc2       $t7, $13 /* handwritten instruction */
    /* 4D350 800B5B50 00708E48 */  mtc2       $t6, $14 /* handwritten instruction */
    /* 4D354 800B5B54 00888B48 */  mtc2       $t3, $17 /* handwritten instruction */
    /* 4D358 800B5B58 02002013 */  beqz       $t9, .L800B5B64
    /* 4D35C 800B5B5C 0024033C */   lui       $v1, (0x24000000 >> 16)
    /* 4D360 800B5B60 0026033C */  lui        $v1, (0x26000000 >> 16)
  .L800B5B64:
    /* 4D364 800B5B64 0600404B */  nclip
    /* 4D368 800B5B68 25186600 */  or         $v1, $v1, $a2
    /* 4D36C 800B5B6C 040023AE */  sw         $v1, 0x4($s1)
    /* 4D370 800B5B70 FFFF2931 */  andi       $t1, $t1, 0xFFFF
    /* 4D374 800B5B74 25483C01 */  or         $t1, $t1, $gp
    /* 4D378 800B5B78 00C00248 */  mfc2       $v0, $24 /* handwritten instruction */
    /* 4D37C 800B5B7C 025C1600 */  srl        $t3, $s6, 16
    /* 4D380 800B5B80 19004018 */  blez       $v0, .L800B5BE8
    /* 4D384 800B5B84 25587F01 */   or        $t3, $t3, $ra
    /* 4D388 800B5B88 25587901 */  or         $t3, $t3, $t9
    /* 4D38C 800B5B8C 2D00584B */  avsz3
    /* 4D390 800B5B90 08002DAE */  sw         $t5, 0x8($s1)
    /* 4D394 800B5B94 0C0029AE */  sw         $t1, 0xC($s1)
    /* 4D398 800B5B98 10002FAE */  sw         $t7, 0x10($s1)
    /* 4D39C 800B5B9C 14002BAE */  sw         $t3, 0x14($s1)
    /* 4D3A0 800B5BA0 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 4D3A4 800B5BA4 18002EAE */  sw         $t6, 0x18($s1)
    /* 4D3A8 800B5BA8 C007582C */  sltiu      $t8, $v0, 0x7C0
    /* 4D3AC 800B5BAC 0E000013 */  beqz       $t8, .L800B5BE8
    /* 4D3B0 800B5BB0 04004224 */   addiu     $v0, $v0, 0x4
    /* 4D3B4 800B5BB4 1C0036AE */  sw         $s6, 0x1C($s1)
    /* 4D3B8 800B5BB8 80100200 */  sll        $v0, $v0, 2
    /* 4D3BC 800B5BBC 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4D3C0 800B5BC0 0000438C */  lw         $v1, 0x0($v0)
    /* 4D3C4 800B5BC4 0007183C */  lui        $t8, (0x7000000 >> 16)
    /* 4D3C8 800B5BC8 24407400 */  and        $t0, $v1, $s4
    /* 4D3CC 800B5BCC 25401801 */  or         $t0, $t0, $t8
    /* 4D3D0 800B5BD0 000028AE */  sw         $t0, 0x0($s1)
    /* 4D3D4 800B5BD4 24483402 */  and        $t1, $s1, $s4
    /* 4D3D8 800B5BD8 24407500 */  and        $t0, $v1, $s5
    /* 4D3DC 800B5BDC 25400901 */  or         $t0, $t0, $t1
    /* 4D3E0 800B5BE0 000048AC */  sw         $t0, 0x0($v0)
    /* 4D3E4 800B5BE4 20003126 */  addiu      $s1, $s1, 0x20
  .L800B5BE8:
    /* 4D3E8 800B5BE8 5EFE6012 */  beqz       $s3, .L800B5564
    /* 4D3EC 800B5BEC 14005226 */   addiu     $s2, $s2, 0x14
    /* 4D3F0 800B5BF0 78D50208 */  j          .L800B55E0
    /* 4D3F4 800B5BF4 00005E8E */   lw        $fp, 0x0($s2)
  .L800B5BF8:
    /* 4D3F8 800B5BF8 801F083C */  lui        $t0, (0x1F800380 >> 16)
    /* 4D3FC 800B5BFC 000011AD */  sw         $s1, (0x1F800000 & 0xFFFF)($t0)
    /* 4D400 800B5C00 5803108D */  lw         $s0, (0x1F800358 & 0xFFFF)($t0)
    /* 4D404 800B5C04 5C03118D */  lw         $s1, (0x1F80035C & 0xFFFF)($t0)
    /* 4D408 800B5C08 6003128D */  lw         $s2, (0x1F800360 & 0xFFFF)($t0)
    /* 4D40C 800B5C0C 6403138D */  lw         $s3, (0x1F800364 & 0xFFFF)($t0)
    /* 4D410 800B5C10 6803148D */  lw         $s4, (0x1F800368 & 0xFFFF)($t0)
    /* 4D414 800B5C14 6C03158D */  lw         $s5, (0x1F80036C & 0xFFFF)($t0)
    /* 4D418 800B5C18 7003168D */  lw         $s6, (0x1F800370 & 0xFFFF)($t0)
    /* 4D41C 800B5C1C 7403178D */  lw         $s7, (0x1F800374 & 0xFFFF)($t0)
    /* 4D420 800B5C20 78031F8D */  lw         $ra, (0x1F800378 & 0xFFFF)($t0)
    /* 4D424 800B5C24 7C031C8D */  lw         $gp, (0x1F80037C & 0xFFFF)($t0)
    /* 4D428 800B5C28 0800E003 */  jr         $ra
    /* 4D42C 800B5C2C 80031E8D */   lw        $fp, (0x1F800380 & 0xFFFF)($t0)
endlabel func_800B516C
