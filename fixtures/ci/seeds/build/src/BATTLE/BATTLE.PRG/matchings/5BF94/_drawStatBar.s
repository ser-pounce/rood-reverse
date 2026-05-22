nonmatching _drawStatBar, 0x17C

glabel _drawStatBar
    /* 61338 800C9B38 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 6133C 800C9B3C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 61340 800C9B40 21988000 */  addu       $s3, $a0, $zero
    /* 61344 800C9B44 1800B2AF */  sw         $s2, 0x18($sp)
    /* 61348 800C9B48 2190A000 */  addu       $s2, $a1, $zero
    /* 6134C 800C9B4C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 61350 800C9B50 2188C000 */  addu       $s1, $a2, $zero
    /* 61354 800C9B54 801F053C */  lui        $a1, (0x1F800004 >> 16)
    /* 61358 800C9B58 0F80023C */  lui        $v0, %hi(D_800EBBDC)
    /* 6135C 800C9B5C DCBB4224 */  addiu      $v0, $v0, %lo(D_800EBBDC)
    /* 61360 800C9B60 80181300 */  sll        $v1, $s3, 2
    /* 61364 800C9B64 21186200 */  addu       $v1, $v1, $v0
    /* 61368 800C9B68 0F80023C */  lui        $v0, %hi(D_800EB9B0)
    /* 6136C 800C9B6C 2400BFAF */  sw         $ra, 0x24($sp)
    /* 61370 800C9B70 2000B4AF */  sw         $s4, 0x20($sp)
    /* 61374 800C9B74 1000B0AF */  sw         $s0, 0x10($sp)
    /* 61378 800C9B78 0000648C */  lw         $a0, 0x0($v1)
    /* 6137C 800C9B7C B0B9428C */  lw         $v0, %lo(D_800EB9B0)($v0)
    /* 61380 800C9B80 0400A38C */  lw         $v1, (0x1F800004 & 0xFFFF)($a1)
    /* 61384 800C9B84 23808200 */  subu       $s0, $a0, $v0
    /* 61388 800C9B88 42002012 */  beqz       $s1, .L800C9C94
    /* 6138C 800C9B8C F4FF7424 */   addiu     $s4, $v1, -0xC
    /* 61390 800C9B90 80291200 */  sll        $a1, $s2, 6
    /* 61394 800C9B94 2128B100 */  addu       $a1, $a1, $s1
    /* 61398 800C9B98 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 6139C 800C9B9C 1A00B100 */  div        $zero, $a1, $s1
    /* 613A0 800C9BA0 12280000 */  mflo       $a1
    /* 613A4 800C9BA4 21206002 */  addu       $a0, $s3, $zero
    /* 613A8 800C9BA8 21308002 */  addu       $a2, $s4, $zero
    /* 613AC 800C9BAC 7726030C */  jal        vs_battle_drawStatBar
    /* 613B0 800C9BB0 21380002 */   addu      $a3, $s0, $zero
    /* 613B4 800C9BB4 02006232 */  andi       $v0, $s3, 0x2
    /* 613B8 800C9BB8 09004010 */  beqz       $v0, .L800C9BE0
    /* 613BC 800C9BBC 0300023C */   lui       $v0, (0x30036 >> 16)
    /* 613C0 800C9BC0 36004234 */  ori        $v0, $v0, (0x30036 & 0xFFFF)
    /* 613C4 800C9BC4 21800202 */  addu       $s0, $s0, $v0
    /* 613C8 800C9BC8 03000224 */  addiu      $v0, $zero, 0x3
    /* 613CC 800C9BCC 15006216 */  bne        $s3, $v0, .L800C9C24
    /* 613D0 800C9BD0 01000424 */   addiu     $a0, $zero, 0x1
    /* 613D4 800C9BD4 FF004226 */  addiu      $v0, $s2, 0xFF
    /* 613D8 800C9BD8 09270308 */  j          .L800C9C24
    /* 613DC 800C9BDC 03920200 */   sra       $s2, $v0, 8
  .L800C9BE0:
    /* 613E0 800C9BE0 F8FF053C */  lui        $a1, (0xFFF80038 >> 16)
    /* 613E4 800C9BE4 3800A534 */  ori        $a1, $a1, (0xFFF80038 & 0xFFFF)
    /* 613E8 800C9BE8 21200000 */  addu       $a0, $zero, $zero
    /* 613EC 800C9BEC 21280502 */  addu       $a1, $s0, $a1
    /* 613F0 800C9BF0 21302002 */  addu       $a2, $s1, $zero
    /* 613F4 800C9BF4 5426030C */  jal        vs_battle_renderValue
    /* 613F8 800C9BF8 21388000 */   addu      $a3, $a0, $zero
    /* 613FC 800C9BFC 21804000 */  addu       $s0, $v0, $zero
    /* 61400 800C9C00 02000424 */  addiu      $a0, $zero, 0x2
    /* 61404 800C9C04 21280002 */  addu       $a1, $s0, $zero
    /* 61408 800C9C08 21300000 */  addu       $a2, $zero, $zero
    /* 6140C 800C9C0C 3026030C */  jal        _renderDigit
    /* 61410 800C9C10 21388002 */   addu      $a3, $s4, $zero
    /* 61414 800C9C14 FEFF023C */  lui        $v0, (0xFFFEFFF9 >> 16)
    /* 61418 800C9C18 F9FF4234 */  ori        $v0, $v0, (0xFFFEFFF9 & 0xFFFF)
    /* 6141C 800C9C1C 21800202 */  addu       $s0, $s0, $v0
    /* 61420 800C9C20 01000424 */  addiu      $a0, $zero, 0x1
  .L800C9C24:
    /* 61424 800C9C24 21280002 */  addu       $a1, $s0, $zero
    /* 61428 800C9C28 21304002 */  addu       $a2, $s2, $zero
    /* 6142C 800C9C2C 5426030C */  jal        vs_battle_renderValue
    /* 61430 800C9C30 21380000 */   addu      $a3, $zero, $zero
    /* 61434 800C9C34 80010424 */  addiu      $a0, $zero, 0x180
    /* 61438 800C9C38 0F80023C */  lui        $v0, %hi(D_800EBBEC)
    /* 6143C 800C9C3C ECBB4224 */  addiu      $v0, $v0, %lo(D_800EBBEC)
    /* 61440 800C9C40 80181300 */  sll        $v1, $s3, 2
    /* 61444 800C9C44 21186200 */  addu       $v1, $v1, $v0
    /* 61448 800C9C48 0F80023C */  lui        $v0, %hi(D_800EB9B0)
    /* 6144C 800C9C4C 21388002 */  addu       $a3, $s4, $zero
    /* 61450 800C9C50 B0B9458C */  lw         $a1, %lo(D_800EB9B0)($v0)
    /* 61454 800C9C54 0F80023C */  lui        $v0, %hi(D_800EBBFC)
    /* 61458 800C9C58 FCBB4224 */  addiu      $v0, $v0, %lo(D_800EBBFC)
    /* 6145C 800C9C5C 21106202 */  addu       $v0, $s3, $v0
    /* 61460 800C9C60 0900063C */  lui        $a2, (0x90000 >> 16)
    /* 61464 800C9C64 0000638C */  lw         $v1, 0x0($v1)
    /* 61468 800C9C68 00004290 */  lbu        $v0, 0x0($v0)
    /* 6146C 800C9C6C 23286500 */  subu       $a1, $v1, $a1
    /* 61470 800C9C70 8900030C */  jal        func_800C0224
    /* 61474 800C9C74 25304600 */   or        $a2, $v0, $a2
    /* 61478 800C9C78 0F80033C */  lui        $v1, %hi(D_800EBC00)
    /* 6147C 800C9C7C 00BC6324 */  addiu      $v1, $v1, %lo(D_800EBC00)
    /* 61480 800C9C80 21186302 */  addu       $v1, $s3, $v1
    /* 61484 800C9C84 00006390 */  lbu        $v1, 0x0($v1)
    /* 61488 800C9C88 F637043C */  lui        $a0, (0x37F60000 >> 16)
    /* 6148C 800C9C8C 25186400 */  or         $v1, $v1, $a0
    /* 61490 800C9C90 100043AC */  sw         $v1, 0x10($v0)
  .L800C9C94:
    /* 61494 800C9C94 2400BF8F */  lw         $ra, 0x24($sp)
    /* 61498 800C9C98 2000B48F */  lw         $s4, 0x20($sp)
    /* 6149C 800C9C9C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 614A0 800C9CA0 1800B28F */  lw         $s2, 0x18($sp)
    /* 614A4 800C9CA4 1400B18F */  lw         $s1, 0x14($sp)
    /* 614A8 800C9CA8 1000B08F */  lw         $s0, 0x10($sp)
    /* 614AC 800C9CAC 0800E003 */  jr         $ra
    /* 614B0 800C9CB0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _drawStatBar
