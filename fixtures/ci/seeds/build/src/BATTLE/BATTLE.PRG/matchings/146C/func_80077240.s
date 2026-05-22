nonmatching func_80077240, 0x17C

glabel func_80077240
    /* EA40 80077240 B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* EA44 80077244 3400B1AF */  sw         $s1, 0x34($sp)
    /* EA48 80077248 21888000 */  addu       $s1, $a0, $zero
    /* EA4C 8007724C 3C00B3AF */  sw         $s3, 0x3C($sp)
    /* EA50 80077250 2198A000 */  addu       $s3, $a1, $zero
    /* EA54 80077254 3800B2AF */  sw         $s2, 0x38($sp)
    /* EA58 80077258 2190C000 */  addu       $s2, $a2, $zero
    /* EA5C 8007725C 4400B5AF */  sw         $s5, 0x44($sp)
    /* EA60 80077260 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* EA64 80077264 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* EA68 80077268 80181100 */  sll        $v1, $s1, 2
    /* EA6C 8007726C 21186200 */  addu       $v1, $v1, $v0
    /* EA70 80077270 4800BFAF */  sw         $ra, 0x48($sp)
    /* EA74 80077274 4000B4AF */  sw         $s4, 0x40($sp)
    /* EA78 80077278 3000B0AF */  sw         $s0, 0x30($sp)
    /* EA7C 8007727C 0000628C */  lw         $v0, 0x0($v1)
    /* EA80 80077280 6C00B48F */  lw         $s4, 0x6C($sp)
    /* EA84 80077284 43004014 */  bnez       $v0, .L80077394
    /* EA88 80077288 21A8E000 */   addu      $s5, $a3, $zero
    /* EA8C 8007728C 0A00222A */  slti       $v0, $s1, 0xA
    /* EA90 80077290 41004010 */  beqz       $v0, .L80077398
    /* EA94 80077294 21100000 */   addu      $v0, $zero, $zero
    /* EA98 80077298 B10F010C */  jal        vs_main_allocHeap
    /* EA9C 8007729C 842E0424 */   addiu     $a0, $zero, 0x2E84
    /* EAA0 800772A0 21804000 */  addu       $s0, $v0, $zero
    /* EAA4 800772A4 21200002 */  addu       $a0, $s0, $zero
    /* EAA8 800772A8 4424010C */  jal        vs_main_bzero
    /* EAAC 800772AC B4090524 */   addiu     $a1, $zero, 0x9B4
    /* EAB0 800772B0 0A000324 */  addiu      $v1, $zero, 0xA
    /* EAB4 800772B4 50000226 */  addiu      $v0, $s0, 0x50
    /* EAB8 800772B8 3C0002AE */  sw         $v0, 0x3C($s0)
    /* EABC 800772BC 01000224 */  addiu      $v0, $zero, 0x1
    /* EAC0 800772C0 400002AE */  sw         $v0, 0x40($s0)
    /* EAC4 800772C4 B4090226 */  addiu      $v0, $s0, 0x9B4
    /* EAC8 800772C8 440002AE */  sw         $v0, 0x44($s0)
    /* EACC 800772CC B4220226 */  addiu      $v0, $s0, 0x22B4
    /* EAD0 800772D0 480002AE */  sw         $v0, 0x48($s0)
    /* EAD4 800772D4 9C280226 */  addiu      $v0, $s0, 0x289C
    /* EAD8 800772D8 0E004012 */  beqz       $s2, .L80077314
    /* EADC 800772DC 4C0002AE */   sw        $v0, 0x4C($s0)
    /* EAE0 800772E0 01000324 */  addiu      $v1, $zero, 0x1
    /* EAE4 800772E4 0F80023C */  lui        $v0, %hi(_wepIdCategories)
    /* EAE8 800772E8 E4814424 */  addiu      $a0, $v0, %lo(_wepIdCategories)
    /* EAEC 800772EC 21106400 */  addu       $v0, $v1, $a0
  .L800772F0:
    /* EAF0 800772F0 00004290 */  lbu        $v0, 0x0($v0)
    /* EAF4 800772F4 00000000 */  nop
    /* EAF8 800772F8 2A105200 */  slt        $v0, $v0, $s2
    /* EAFC 800772FC 05004010 */  beqz       $v0, .L80077314
    /* EB00 80077300 00000000 */   nop
    /* EB04 80077304 01006324 */  addiu      $v1, $v1, 0x1
    /* EB08 80077308 0B006228 */  slti       $v0, $v1, 0xB
    /* EB0C 8007730C F8FF4014 */  bnez       $v0, .L800772F0
    /* EB10 80077310 21106400 */   addu      $v0, $v1, $a0
  .L80077314:
    /* EB14 80077314 21200002 */  addu       $a0, $s0, $zero
    /* EB18 80077318 21282002 */  addu       $a1, $s1, $zero
    /* EB1C 8007731C 6800A78F */  lw         $a3, 0x68($sp)
    /* EB20 80077320 21306002 */  addu       $a2, $s3, $zero
    /* EB24 80077324 250003A2 */  sb         $v1, 0x25($s0)
    /* EB28 80077328 1EDC010C */  jal        func_80077078
    /* EB2C 8007732C 1000B4AF */   sw        $s4, 0x10($sp)
    /* EB30 80077330 7F000224 */  addiu      $v0, $zero, 0x7F
    /* EB34 80077334 15006212 */  beq        $s3, $v0, .L8007738C
    /* EB38 80077338 21200002 */   addu      $a0, $s0, $zero
    /* EB3C 8007733C 3FDC010C */  jal        func_800770FC
    /* EB40 80077340 21282002 */   addu      $a1, $s1, $zero
    /* EB44 80077344 21200002 */  addu       $a0, $s0, $zero
    /* EB48 80077348 21282002 */  addu       $a1, $s1, $zero
    /* EB4C 8007734C 21304002 */  addu       $a2, $s2, $zero
    /* EB50 80077350 21380000 */  addu       $a3, $zero, $zero
    /* EB54 80077354 4CDC010C */  jal        func_80077130
    /* EB58 80077358 1000B5AF */   sw        $s5, 0x10($sp)
    /* EB5C 8007735C 21200002 */  addu       $a0, $s0, $zero
    /* EB60 80077360 21282002 */  addu       $a1, $s1, $zero
    /* EB64 80077364 6000A68F */  lw         $a2, 0x60($sp)
    /* EB68 80077368 6400A28F */  lw         $v0, 0x64($sp)
    /* EB6C 8007736C 01000724 */  addiu      $a3, $zero, 0x1
    /* EB70 80077370 4CDC010C */  jal        func_80077130
    /* EB74 80077374 1000A2AF */   sw        $v0, 0x10($sp)
    /* EB78 80077378 21200002 */  addu       $a0, $s0, $zero
    /* EB7C 8007737C 21282002 */  addu       $a1, $s1, $zero
    /* EB80 80077380 25000692 */  lbu        $a2, 0x25($s0)
    /* EB84 80077384 78DC010C */  jal        func_800771E0
    /* EB88 80077388 21388002 */   addu      $a3, $s4, $zero
  .L8007738C:
    /* EB8C 8007738C E6DC0108 */  j          .L80077398
    /* EB90 80077390 21100002 */   addu      $v0, $s0, $zero
  .L80077394:
    /* EB94 80077394 21100000 */  addu       $v0, $zero, $zero
  .L80077398:
    /* EB98 80077398 4800BF8F */  lw         $ra, 0x48($sp)
    /* EB9C 8007739C 4400B58F */  lw         $s5, 0x44($sp)
    /* EBA0 800773A0 4000B48F */  lw         $s4, 0x40($sp)
    /* EBA4 800773A4 3C00B38F */  lw         $s3, 0x3C($sp)
    /* EBA8 800773A8 3800B28F */  lw         $s2, 0x38($sp)
    /* EBAC 800773AC 3400B18F */  lw         $s1, 0x34($sp)
    /* EBB0 800773B0 3000B08F */  lw         $s0, 0x30($sp)
    /* EBB4 800773B4 0800E003 */  jr         $ra
    /* EBB8 800773B8 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel func_80077240
