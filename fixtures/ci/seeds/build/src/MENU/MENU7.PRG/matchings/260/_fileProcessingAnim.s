nonmatching _fileProcessingAnim, 0x120

glabel _fileProcessingAnim
    /* 2300 80104B00 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 2304 80104B04 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2308 80104B08 21888000 */  addu       $s1, $a0, $zero
    /* 230C 80104B0C 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 2310 80104B10 21B8A000 */  addu       $s7, $a1, $zero
    /* 2314 80104B14 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2318 80104B18 D0FF3326 */  addiu      $s3, $s1, -0x30
    /* 231C 80104B1C 4000622E */  sltiu      $v0, $s3, 0x40
    /* 2320 80104B20 3400BFAF */  sw         $ra, 0x34($sp)
    /* 2324 80104B24 3000BEAF */  sw         $fp, 0x30($sp)
    /* 2328 80104B28 2800B6AF */  sw         $s6, 0x28($sp)
    /* 232C 80104B2C 2400B5AF */  sw         $s5, 0x24($sp)
    /* 2330 80104B30 2000B4AF */  sw         $s4, 0x20($sp)
    /* 2334 80104B34 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2338 80104B38 02004010 */  beqz       $v0, .L80104B44
    /* 233C 80104B3C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2340 80104B40 40001324 */  addiu      $s3, $zero, 0x40
  .L80104B44:
    /* 2344 80104B44 21A00000 */  addu       $s4, $zero, $zero
    /* 2348 80104B48 1180023C */  lui        $v0, %hi(_isSaving)
    /* 234C 80104B4C A8B04290 */  lbu        $v0, %lo(_isSaving)($v0)
    /* 2350 80104B50 00000000 */  nop
    /* 2354 80104B54 03004010 */  beqz       $v0, .L80104B64
    /* 2358 80104B58 E0FF1234 */   ori       $s2, $zero, 0xFFE0
    /* 235C 80104B5C 7F00123C */  lui        $s2, (0x7F00FF >> 16)
    /* 2360 80104B60 FF005236 */  ori        $s2, $s2, (0x7F00FF & 0xFFFF)
  .L80104B64:
    /* 2364 80104B64 21A80000 */  addu       $s5, $zero, $zero
    /* 2368 80104B68 11801E3C */  lui        $fp, %hi(_primBuf)
    /* 236C 80104B6C 60B0D027 */  addiu      $s0, $fp, %lo(_primBuf)
    /* 2370 80104B70 2000023C */  lui        $v0, (0x200000 >> 16)
    /* 2374 80104B74 21B0E202 */  addu       $s6, $s7, $v0
  .L80104B78:
    /* 2378 80104B78 94A1000C */  jal        DrawSync
    /* 237C 80104B7C 21200000 */   addu      $a0, $zero, $zero
    /* 2380 80104B80 00E1033C */  lui        $v1, (0xE1000220 >> 16)
    /* 2384 80104B84 20026334 */  ori        $v1, $v1, (0xE1000220 & 0xFFFF)
    /* 2388 80104B88 21200002 */  addu       $a0, $s0, $zero
    /* 238C 80104B8C 0009023C */  lui        $v0, (0x9000000 >> 16)
    /* 2390 80104B90 60B0C2AF */  sw         $v0, %lo(_primBuf)($fp)
    /* 2394 80104B94 003A023C */  lui        $v0, (0x3A000000 >> 16)
    /* 2398 80104B98 25108202 */  or         $v0, $s4, $v0
    /* 239C 80104B9C 080002AE */  sw         $v0, 0x8($s0)
    /* 23A0 80104BA0 25107702 */  or         $v0, $s3, $s7
    /* 23A4 80104BA4 0C0002AE */  sw         $v0, 0xC($s0)
    /* 23A8 80104BA8 25103702 */  or         $v0, $s1, $s7
    /* 23AC 80104BAC 140002AE */  sw         $v0, 0x14($s0)
    /* 23B0 80104BB0 25107602 */  or         $v0, $s3, $s6
    /* 23B4 80104BB4 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 23B8 80104BB8 25103602 */  or         $v0, $s1, $s6
    /* 23BC 80104BBC 040003AE */  sw         $v1, 0x4($s0)
    /* 23C0 80104BC0 100012AE */  sw         $s2, 0x10($s0)
    /* 23C4 80104BC4 180014AE */  sw         $s4, 0x18($s0)
    /* 23C8 80104BC8 200012AE */  sw         $s2, 0x20($s0)
    /* 23CC 80104BCC FAA2000C */  jal        DrawPrim
    /* 23D0 80104BD0 240002AE */   sw        $v0, 0x24($s0)
    /* 23D4 80104BD4 21982002 */  addu       $s3, $s1, $zero
    /* 23D8 80104BD8 10003126 */  addiu      $s1, $s1, 0x10
    /* 23DC 80104BDC 21A04002 */  addu       $s4, $s2, $zero
    /* 23E0 80104BE0 0100B526 */  addiu      $s5, $s5, 0x1
    /* 23E4 80104BE4 0200A22E */  sltiu      $v0, $s5, 0x2
    /* 23E8 80104BE8 E3FF4014 */  bnez       $v0, .L80104B78
    /* 23EC 80104BEC 21900000 */   addu      $s2, $zero, $zero
    /* 23F0 80104BF0 3400BF8F */  lw         $ra, 0x34($sp)
    /* 23F4 80104BF4 3000BE8F */  lw         $fp, 0x30($sp)
    /* 23F8 80104BF8 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 23FC 80104BFC 2800B68F */  lw         $s6, 0x28($sp)
    /* 2400 80104C00 2400B58F */  lw         $s5, 0x24($sp)
    /* 2404 80104C04 2000B48F */  lw         $s4, 0x20($sp)
    /* 2408 80104C08 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 240C 80104C0C 1800B28F */  lw         $s2, 0x18($sp)
    /* 2410 80104C10 1400B18F */  lw         $s1, 0x14($sp)
    /* 2414 80104C14 1000B08F */  lw         $s0, 0x10($sp)
    /* 2418 80104C18 0800E003 */  jr         $ra
    /* 241C 80104C1C 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel _fileProcessingAnim
