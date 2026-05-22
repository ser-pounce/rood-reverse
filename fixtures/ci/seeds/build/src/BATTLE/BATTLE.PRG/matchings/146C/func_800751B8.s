nonmatching func_800751B8, 0x240

glabel func_800751B8
    /* C9B8 800751B8 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* C9BC 800751BC 3800B6AF */  sw         $s6, 0x38($sp)
    /* C9C0 800751C0 21B08000 */  addu       $s6, $a0, $zero
    /* C9C4 800751C4 3400B5AF */  sw         $s5, 0x34($sp)
    /* C9C8 800751C8 21A8A000 */  addu       $s5, $a1, $zero
    /* C9CC 800751CC 2800B2AF */  sw         $s2, 0x28($sp)
    /* C9D0 800751D0 2190A002 */  addu       $s2, $s5, $zero
    /* C9D4 800751D4 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* C9D8 800751D8 3000B4AF */  sw         $s4, 0x30($sp)
    /* C9DC 800751DC 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* C9E0 800751E0 2400B1AF */  sw         $s1, 0x24($sp)
    /* C9E4 800751E4 F882020C */  jal        func_800A0BE0
    /* C9E8 800751E8 2000B0AF */   sw        $s0, 0x20($sp)
    /* C9EC 800751EC 21884000 */  addu       $s1, $v0, $zero
    /* C9F0 800751F0 829B1100 */  srl        $s3, $s1, 14
    /* C9F4 800751F4 0700023C */  lui        $v0, (0x70000 >> 16)
    /* C9F8 800751F8 24302202 */  and        $a2, $s1, $v0
    /* C9FC 800751FC 0500C010 */  beqz       $a2, .L80075214
    /* CA00 80075200 01007332 */   andi      $s3, $s3, 0x1
    /* CA04 80075204 21200000 */  addu       $a0, $zero, $zero
    /* CA08 80075208 21288000 */  addu       $a1, $a0, $zero
    /* CA0C 8007520C 88D40108 */  j          .L80075220
    /* CA10 80075210 02340600 */   srl       $a2, $a2, 16
  .L80075214:
    /* CA14 80075214 0000A492 */  lbu        $a0, 0x0($s5)
    /* CA18 80075218 0200A592 */  lbu        $a1, 0x2($s5)
    /* CA1C 8007521C 0100A692 */  lbu        $a2, 0x1($s5)
  .L80075220:
    /* CA20 80075220 D92D020C */  jal        func_8008B764
    /* CA24 80075224 00000000 */   nop
    /* CA28 80075228 21A04000 */  addu       $s4, $v0, $zero
    /* CA2C 8007522C 0F80023C */  lui        $v0, %hi(vs_battle_screenTransitionStep)
    /* CA30 80075230 481A428C */  lw         $v0, %lo(vs_battle_screenTransitionStep)($v0)
    /* CA34 80075234 00000000 */  nop
    /* CA38 80075238 65004014 */  bnez       $v0, .L800753D0
    /* CA3C 8007523C 21100000 */   addu      $v0, $zero, $zero
    /* CA40 80075240 0001023C */  lui        $v0, (0x1000000 >> 16)
    /* CA44 80075244 24102202 */  and        $v0, $s1, $v0
    /* CA48 80075248 61004014 */  bnez       $v0, .L800753D0
    /* CA4C 8007524C 21100000 */   addu      $v0, $zero, $zero
    /* CA50 80075250 FF00043C */  lui        $a0, (0xFFFFFF >> 16)
    /* CA54 80075254 FFFF8434 */  ori        $a0, $a0, (0xFFFFFF & 0xFFFF)
    /* CA58 80075258 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* CA5C 8007525C 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* CA60 80075260 80101600 */  sll        $v0, $s6, 2
    /* CA64 80075264 21104300 */  addu       $v0, $v0, $v1
    /* CA68 80075268 0000508C */  lw         $s0, 0x0($v0)
    /* CA6C 8007526C 0000438E */  lw         $v1, 0x0($s2)
    /* CA70 80075270 2C00028E */  lw         $v0, 0x2C($s0)
    /* CA74 80075274 24186400 */  and        $v1, $v1, $a0
    /* CA78 80075278 24104400 */  and        $v0, $v0, $a0
    /* CA7C 8007527C 09006214 */  bne        $v1, $v0, .L800752A4
    /* CA80 80075280 0F80023C */   lui       $v0, %hi(D_800F196C)
    /* CA84 80075284 2F000292 */  lbu        $v0, 0x2F($s0)
    /* CA88 80075288 00000000 */  nop
    /* CA8C 8007528C 05006216 */  bne        $s3, $v0, .L800752A4
    /* CA90 80075290 0F80023C */   lui       $v0, %hi(D_800F196C)
    /* CA94 80075294 0700023C */  lui        $v0, (0x70000 >> 16)
    /* CA98 80075298 24102202 */  and        $v0, $s1, $v0
    /* CA9C 8007529C 2A004010 */  beqz       $v0, .L80075348
    /* CAA0 800752A0 0F80023C */   lui       $v0, %hi(D_800F196C)
  .L800752A4:
    /* CAA4 800752A4 6C19438C */  lw         $v1, %lo(D_800F196C)($v0)
    /* CAA8 800752A8 03000224 */  addiu      $v0, $zero, 0x3
    /* CAAC 800752AC 1E006210 */  beq        $v1, $v0, .L80075328
    /* CAB0 800752B0 5000023C */   lui       $v0, (0x504000 >> 16)
    /* CAB4 800752B4 02008296 */  lhu        $v0, 0x2($s4)
    /* CAB8 800752B8 00000000 */  nop
    /* CABC 800752BC 01004230 */  andi       $v0, $v0, 0x1
    /* CAC0 800752C0 18004010 */  beqz       $v0, .L80075324
    /* CAC4 800752C4 7016023C */   lui       $v0, (0x16704000 >> 16)
    /* CAC8 800752C8 00404234 */  ori        $v0, $v0, (0x16704000 & 0xFFFF)
    /* CACC 800752CC 24102202 */  and        $v0, $s1, $v0
    /* CAD0 800752D0 15004014 */  bnez       $v0, .L80075328
    /* CAD4 800752D4 5000023C */   lui       $v0, (0x504000 >> 16)
    /* CAD8 800752D8 00004492 */  lbu        $a0, 0x0($s2)
    /* CADC 800752DC 02004592 */  lbu        $a1, 0x2($s2)
    /* CAE0 800752E0 01004692 */  lbu        $a2, 0x1($s2)
    /* CAE4 800752E4 0E35020C */  jal        func_8008D438
    /* CAE8 800752E8 00000000 */   nop
    /* CAEC 800752EC 21204000 */  addu       $a0, $v0, $zero
    /* CAF0 800752F0 0C008010 */  beqz       $a0, .L80075324
    /* CAF4 800752F4 10000224 */   addiu     $v0, $zero, 0x10
    /* CAF8 800752F8 06008384 */  lh         $v1, 0x6($a0)
    /* CAFC 800752FC 00000000 */  nop
    /* CB00 80075300 08006210 */  beq        $v1, $v0, .L80075324
    /* CB04 80075304 2128A002 */   addu      $a1, $s5, $zero
    /* CB08 80075308 DFCF010C */  jal        func_80073F7C
    /* CB0C 8007530C 2130C002 */   addu      $a2, $s6, $zero
    /* CB10 80075310 0000438E */  lw         $v1, 0x0($s2)
    /* CB14 80075314 03000224 */  addiu      $v0, $zero, 0x3
    /* CB18 80075318 2C0003AE */  sw         $v1, 0x2C($s0)
    /* CB1C 8007531C F4D40108 */  j          .L800753D0
    /* CB20 80075320 2F0013A2 */   sb        $s3, 0x2F($s0)
  .L80075324:
    /* CB24 80075324 5000023C */  lui        $v0, (0x504000 >> 16)
  .L80075328:
    /* CB28 80075328 00404234 */  ori        $v0, $v0, (0x504000 & 0xFFFF)
    /* CB2C 8007532C 24102202 */  and        $v0, $s1, $v0
    /* CB30 80075330 04004014 */  bnez       $v0, .L80075344
    /* CB34 80075334 00000000 */   nop
    /* CB38 80075338 0000428E */  lw         $v0, 0x0($s2)
    /* CB3C 8007533C 00000000 */  nop
    /* CB40 80075340 2C0002AE */  sw         $v0, 0x2C($s0)
  .L80075344:
    /* CB44 80075344 2F0013A2 */  sb         $s3, 0x2F($s0)
  .L80075348:
    /* CB48 80075348 0000828E */  lw         $v0, 0x0($s4)
    /* CB4C 8007534C 00000000 */  nop
    /* CB50 80075350 42140200 */  srl        $v0, $v0, 17
    /* CB54 80075354 01004230 */  andi       $v0, $v0, 0x1
    /* CB58 80075358 1D004010 */  beqz       $v0, .L800753D0
    /* CB5C 8007535C 21100000 */   addu      $v0, $zero, $zero
    /* CB60 80075360 0600A286 */  lh         $v0, 0x6($s5)
    /* CB64 80075364 00000000 */  nop
    /* CB68 80075368 11004228 */  slti       $v0, $v0, 0x11
    /* CB6C 8007536C 18004014 */  bnez       $v0, .L800753D0
    /* CB70 80075370 21100000 */   addu      $v0, $zero, $zero
    /* CB74 80075374 21200000 */  addu       $a0, $zero, $zero
    /* CB78 80075378 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* CB7C 8007537C 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* CB80 80075380 80101600 */  sll        $v0, $s6, 2
    /* CB84 80075384 21104300 */  addu       $v0, $v0, $v1
    /* CB88 80075388 0000428C */  lw         $v0, 0x0($v0)
    /* CB8C 8007538C 2128C002 */  addu       $a1, $s6, $zero
    /* CB90 80075390 3C00428C */  lw         $v0, 0x3C($v0)
    /* CB94 80075394 21308000 */  addu       $a2, $a0, $zero
    /* CB98 80075398 B9E4010C */  jal        func_800792E4
    /* CB9C 8007539C 180040A4 */   sh        $zero, 0x18($v0)
    /* CBA0 800753A0 0C000424 */  addiu      $a0, $zero, 0xC
    /* CBA4 800753A4 21280000 */  addu       $a1, $zero, $zero
    /* CBA8 800753A8 2130A000 */  addu       $a2, $a1, $zero
    /* CBAC 800753AC 16FB020C */  jal        func_800BEC58
    /* CBB0 800753B0 2138A000 */   addu      $a3, $a1, $zero
    /* CBB4 800753B4 001C0200 */  sll        $v1, $v0, 16
    /* CBB8 800753B8 01000224 */  addiu      $v0, $zero, 0x1
    /* CBBC 800753BC 031C0300 */  sra        $v1, $v1, 16
    /* CBC0 800753C0 21204000 */  addu       $a0, $v0, $zero
    /* CBC4 800753C4 02006410 */  beq        $v1, $a0, .L800753D0
    /* CBC8 800753C8 00000000 */   nop
    /* CBCC 800753CC 02000224 */  addiu      $v0, $zero, 0x2
  .L800753D0:
    /* CBD0 800753D0 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* CBD4 800753D4 3800B68F */  lw         $s6, 0x38($sp)
    /* CBD8 800753D8 3400B58F */  lw         $s5, 0x34($sp)
    /* CBDC 800753DC 3000B48F */  lw         $s4, 0x30($sp)
    /* CBE0 800753E0 2C00B38F */  lw         $s3, 0x2C($sp)
    /* CBE4 800753E4 2800B28F */  lw         $s2, 0x28($sp)
    /* CBE8 800753E8 2400B18F */  lw         $s1, 0x24($sp)
    /* CBEC 800753EC 2000B08F */  lw         $s0, 0x20($sp)
    /* CBF0 800753F0 0800E003 */  jr         $ra
    /* CBF4 800753F4 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_800751B8
