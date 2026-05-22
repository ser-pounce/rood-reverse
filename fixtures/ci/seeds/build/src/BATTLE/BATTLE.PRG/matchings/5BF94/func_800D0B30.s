nonmatching func_800D0B30, 0x130

glabel func_800D0B30
    /* 68330 800D0B30 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 68334 800D0B34 2000B4AF */  sw         $s4, 0x20($sp)
    /* 68338 800D0B38 21A08000 */  addu       $s4, $a0, $zero
    /* 6833C 800D0B3C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 68340 800D0B40 2180A000 */  addu       $s0, $a1, $zero
    /* 68344 800D0B44 2400BFAF */  sw         $ra, 0x24($sp)
    /* 68348 800D0B48 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 6834C 800D0B4C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 68350 800D0B50 1400B1AF */  sw         $s1, 0x14($sp)
    /* 68354 800D0B54 00008296 */  lhu        $v0, 0x0($s4)
    /* 68358 800D0B58 00000000 */  nop
    /* 6835C 800D0B5C 01004230 */  andi       $v0, $v0, 0x1
    /* 68360 800D0B60 32004010 */  beqz       $v0, .L800D0C2C
    /* 68364 800D0B64 2198C000 */   addu      $s3, $a2, $zero
    /* 68368 800D0B68 14008426 */  addiu      $a0, $s4, 0x14
    /* 6836C 800D0B6C 0F80113C */  lui        $s1, %hi(D_800F5330)
    /* 68370 800D0B70 06008292 */  lbu        $v0, 0x6($s4)
    /* 68374 800D0B74 30533126 */  addiu      $s1, $s1, %lo(D_800F5330)
    /* 68378 800D0B78 80100200 */  sll        $v0, $v0, 2
    /* 6837C 800D0B7C 21105100 */  addu       $v0, $v0, $s1
    /* 68380 800D0B80 0000458C */  lw         $a1, 0x0($v0)
    /* 68384 800D0B84 583F030C */  jal        _lerpSvector
    /* 68388 800D0B88 08006626 */   addiu     $a2, $s3, 0x8
    /* 6838C 800D0B8C 00000296 */  lhu        $v0, 0x0($s0)
    /* 68390 800D0B90 08006396 */  lhu        $v1, 0x8($s3)
    /* 68394 800D0B94 21200002 */  addu       $a0, $s0, $zero
    /* 68398 800D0B98 21104300 */  addu       $v0, $v0, $v1
    /* 6839C 800D0B9C 000002A6 */  sh         $v0, 0x0($s0)
    /* 683A0 800D0BA0 02000296 */  lhu        $v0, 0x2($s0)
    /* 683A4 800D0BA4 0A006396 */  lhu        $v1, 0xA($s3)
    /* 683A8 800D0BA8 48007226 */  addiu      $s2, $s3, 0x48
    /* 683AC 800D0BAC 21104300 */  addu       $v0, $v0, $v1
    /* 683B0 800D0BB0 020082A4 */  sh         $v0, 0x2($a0)
    /* 683B4 800D0BB4 04008294 */  lhu        $v0, 0x4($a0)
    /* 683B8 800D0BB8 0C006396 */  lhu        $v1, 0xC($s3)
    /* 683BC 800D0BBC 21284002 */  addu       $a1, $s2, $zero
    /* 683C0 800D0BC0 21104300 */  addu       $v0, $v0, $v1
    /* 683C4 800D0BC4 8004010C */  jal        RotMatrix_gte
    /* 683C8 800D0BC8 040082A4 */   sh        $v0, 0x4($a0)
    /* 683CC 800D0BCC 20008426 */  addiu      $a0, $s4, 0x20
    /* 683D0 800D0BD0 04008292 */  lbu        $v0, 0x4($s4)
    /* 683D4 800D0BD4 10007026 */  addiu      $s0, $s3, 0x10
    /* 683D8 800D0BD8 80100200 */  sll        $v0, $v0, 2
    /* 683DC 800D0BDC 21105100 */  addu       $v0, $v0, $s1
    /* 683E0 800D0BE0 0000458C */  lw         $a1, 0x0($v0)
    /* 683E4 800D0BE4 3C3F030C */  jal        _lerpVector
    /* 683E8 800D0BE8 21300002 */   addu      $a2, $s0, $zero
    /* 683EC 800D0BEC 21204002 */  addu       $a0, $s2, $zero
    /* 683F0 800D0BF0 2F06010C */  jal        TransMatrix
    /* 683F4 800D0BF4 21280002 */   addu      $a1, $s0, $zero
    /* 683F8 800D0BF8 2C008426 */  addiu      $a0, $s4, 0x2C
    /* 683FC 800D0BFC 07008292 */  lbu        $v0, 0x7($s4)
    /* 68400 800D0C00 20007026 */  addiu      $s0, $s3, 0x20
    /* 68404 800D0C04 80100200 */  sll        $v0, $v0, 2
    /* 68408 800D0C08 21105100 */  addu       $v0, $v0, $s1
    /* 6840C 800D0C0C 0000458C */  lw         $a1, 0x0($v0)
    /* 68410 800D0C10 3C3F030C */  jal        _lerpVector
    /* 68414 800D0C14 21300002 */   addu      $a2, $s0, $zero
    /* 68418 800D0C18 21204002 */  addu       $a0, $s2, $zero
    /* 6841C 800D0C1C 0305010C */  jal        func_8004140C
    /* 68420 800D0C20 21280002 */   addu      $a1, $s0, $zero
    /* 68424 800D0C24 10430308 */  j          .L800D0C40
    /* 68428 800D0C28 00000000 */   nop
  .L800D0C2C:
    /* 6842C 800D0C2C 9F3F030C */  jal        func_800CFE7C
    /* 68430 800D0C30 48006426 */   addiu     $a0, $s3, 0x48
    /* 68434 800D0C34 640060AE */  sw         $zero, 0x64($s3)
    /* 68438 800D0C38 600060AE */  sw         $zero, 0x60($s3)
    /* 6843C 800D0C3C 5C0060AE */  sw         $zero, 0x5C($s3)
  .L800D0C40:
    /* 68440 800D0C40 2400BF8F */  lw         $ra, 0x24($sp)
    /* 68444 800D0C44 2000B48F */  lw         $s4, 0x20($sp)
    /* 68448 800D0C48 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 6844C 800D0C4C 1800B28F */  lw         $s2, 0x18($sp)
    /* 68450 800D0C50 1400B18F */  lw         $s1, 0x14($sp)
    /* 68454 800D0C54 1000B08F */  lw         $s0, 0x10($sp)
    /* 68458 800D0C58 0800E003 */  jr         $ra
    /* 6845C 800D0C5C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800D0B30
