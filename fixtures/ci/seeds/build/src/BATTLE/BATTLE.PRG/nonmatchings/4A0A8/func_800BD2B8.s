nonmatching func_800BD2B8, 0x18C

glabel func_800BD2B8
    /* 54AB8 800BD2B8 B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 54ABC 800BD2BC 3000B0AF */  sw         $s0, 0x30($sp)
    /* 54AC0 800BD2C0 21808000 */  addu       $s0, $a0, $zero
    /* 54AC4 800BD2C4 4C00BFAF */  sw         $ra, 0x4C($sp)
    /* 54AC8 800BD2C8 4800B6AF */  sw         $s6, 0x48($sp)
    /* 54ACC 800BD2CC 4400B5AF */  sw         $s5, 0x44($sp)
    /* 54AD0 800BD2D0 4000B4AF */  sw         $s4, 0x40($sp)
    /* 54AD4 800BD2D4 3C00B3AF */  sw         $s3, 0x3C($sp)
    /* 54AD8 800BD2D8 3800B2AF */  sw         $s2, 0x38($sp)
    /* 54ADC 800BD2DC 6605010C */  jal        SetRotMatrix
    /* 54AE0 800BD2E0 3400B1AF */   sw        $s1, 0x34($sp)
    /* 54AE4 800BD2E4 5E05010C */  jal        SetTransMatrix
    /* 54AE8 800BD2E8 21200002 */   addu      $a0, $s0, $zero
    /* 54AEC 800BD2EC 2000B327 */  addiu      $s3, $sp, 0x20
    /* 54AF0 800BD2F0 21206002 */  addu       $a0, $s3, $zero
    /* 54AF4 800BD2F4 1000A527 */  addiu      $a1, $sp, 0x10
    /* 54AF8 800BD2F8 2800B227 */  addiu      $s2, $sp, 0x28
    /* 54AFC 800BD2FC 21304002 */  addu       $a2, $s2, $zero
    /* 54B00 800BD300 50001424 */  addiu      $s4, $zero, 0x50
    /* 54B04 800BD304 96001624 */  addiu      $s6, $zero, 0x96
    /* 54B08 800BD308 2000B4A7 */  sh         $s4, 0x20($sp)
    /* 54B0C 800BD30C 2200B4A7 */  sh         $s4, 0x22($sp)
    /* 54B10 800BD310 FB05010C */  jal        RotTrans
    /* 54B14 800BD314 2400B6A7 */   sh        $s6, 0x24($sp)
    /* 54B18 800BD318 1000A48F */  lw         $a0, 0x10($sp)
    /* 54B1C 800BD31C 1800A58F */  lw         $a1, 0x18($sp)
    /* 54B20 800BD320 1F37020C */  jal        func_8008DC7C
    /* 54B24 800BD324 B0FF1524 */   addiu     $s5, $zero, -0x50
    /* 54B28 800BD328 21206002 */  addu       $a0, $s3, $zero
    /* 54B2C 800BD32C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 54B30 800BD330 21304002 */  addu       $a2, $s2, $zero
    /* 54B34 800BD334 40840200 */  sll        $s0, $v0, 17
    /* 54B38 800BD338 43841000 */  sra        $s0, $s0, 17
    /* 54B3C 800BD33C 38FF1026 */  addiu      $s0, $s0, -0xC8
    /* 54B40 800BD340 2000B5A7 */  sh         $s5, 0x20($sp)
    /* 54B44 800BD344 2200B4A7 */  sh         $s4, 0x22($sp)
    /* 54B48 800BD348 FB05010C */  jal        RotTrans
    /* 54B4C 800BD34C 2400B6A7 */   sh        $s6, 0x24($sp)
    /* 54B50 800BD350 1000A48F */  lw         $a0, 0x10($sp)
    /* 54B54 800BD354 1800A58F */  lw         $a1, 0x18($sp)
    /* 54B58 800BD358 1F37020C */  jal        func_8008DC7C
    /* 54B5C 800BD35C 21880002 */   addu      $s1, $s0, $zero
    /* 54B60 800BD360 40140200 */  sll        $v0, $v0, 17
    /* 54B64 800BD364 43140200 */  sra        $v0, $v0, 17
    /* 54B68 800BD368 38FF4224 */  addiu      $v0, $v0, -0xC8
    /* 54B6C 800BD36C 2A805000 */  slt        $s0, $v0, $s0
    /* 54B70 800BD370 02000012 */  beqz       $s0, .L800BD37C
    /* 54B74 800BD374 21206002 */   addu      $a0, $s3, $zero
    /* 54B78 800BD378 21884000 */  addu       $s1, $v0, $zero
  .L800BD37C:
    /* 54B7C 800BD37C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 54B80 800BD380 21304002 */  addu       $a2, $s2, $zero
    /* 54B84 800BD384 2000B4A7 */  sh         $s4, 0x20($sp)
    /* 54B88 800BD388 2200B5A7 */  sh         $s5, 0x22($sp)
    /* 54B8C 800BD38C FB05010C */  jal        RotTrans
    /* 54B90 800BD390 2400B6A7 */   sh        $s6, 0x24($sp)
    /* 54B94 800BD394 1000A48F */  lw         $a0, 0x10($sp)
    /* 54B98 800BD398 1800A58F */  lw         $a1, 0x18($sp)
    /* 54B9C 800BD39C 1F37020C */  jal        func_8008DC7C
    /* 54BA0 800BD3A0 00000000 */   nop
    /* 54BA4 800BD3A4 40140200 */  sll        $v0, $v0, 17
    /* 54BA8 800BD3A8 43140200 */  sra        $v0, $v0, 17
    /* 54BAC 800BD3AC 38FF4324 */  addiu      $v1, $v0, -0xC8
    /* 54BB0 800BD3B0 00141100 */  sll        $v0, $s1, 16
    /* 54BB4 800BD3B4 03140200 */  sra        $v0, $v0, 16
    /* 54BB8 800BD3B8 2A106200 */  slt        $v0, $v1, $v0
    /* 54BBC 800BD3BC 02004010 */  beqz       $v0, .L800BD3C8
    /* 54BC0 800BD3C0 21206002 */   addu      $a0, $s3, $zero
    /* 54BC4 800BD3C4 21886000 */  addu       $s1, $v1, $zero
  .L800BD3C8:
    /* 54BC8 800BD3C8 1000A527 */  addiu      $a1, $sp, 0x10
    /* 54BCC 800BD3CC 21304002 */  addu       $a2, $s2, $zero
    /* 54BD0 800BD3D0 2000B5A7 */  sh         $s5, 0x20($sp)
    /* 54BD4 800BD3D4 2200B5A7 */  sh         $s5, 0x22($sp)
    /* 54BD8 800BD3D8 FB05010C */  jal        RotTrans
    /* 54BDC 800BD3DC 2400B6A7 */   sh        $s6, 0x24($sp)
    /* 54BE0 800BD3E0 1000A48F */  lw         $a0, 0x10($sp)
    /* 54BE4 800BD3E4 1800A58F */  lw         $a1, 0x18($sp)
    /* 54BE8 800BD3E8 1F37020C */  jal        func_8008DC7C
    /* 54BEC 800BD3EC 00000000 */   nop
    /* 54BF0 800BD3F0 40140200 */  sll        $v0, $v0, 17
    /* 54BF4 800BD3F4 43140200 */  sra        $v0, $v0, 17
    /* 54BF8 800BD3F8 38FF4324 */  addiu      $v1, $v0, -0xC8
    /* 54BFC 800BD3FC 00141100 */  sll        $v0, $s1, 16
    /* 54C00 800BD400 03140200 */  sra        $v0, $v0, 16
    /* 54C04 800BD404 2A106200 */  slt        $v0, $v1, $v0
    /* 54C08 800BD408 03004010 */  beqz       $v0, .L800BD418
    /* 54C0C 800BD40C 00141100 */   sll       $v0, $s1, 16
    /* 54C10 800BD410 21886000 */  addu       $s1, $v1, $zero
    /* 54C14 800BD414 00141100 */  sll        $v0, $s1, 16
  .L800BD418:
    /* 54C18 800BD418 4C00BF8F */  lw         $ra, 0x4C($sp)
    /* 54C1C 800BD41C 4800B68F */  lw         $s6, 0x48($sp)
    /* 54C20 800BD420 4400B58F */  lw         $s5, 0x44($sp)
    /* 54C24 800BD424 4000B48F */  lw         $s4, 0x40($sp)
    /* 54C28 800BD428 3C00B38F */  lw         $s3, 0x3C($sp)
    /* 54C2C 800BD42C 3800B28F */  lw         $s2, 0x38($sp)
    /* 54C30 800BD430 3400B18F */  lw         $s1, 0x34($sp)
    /* 54C34 800BD434 3000B08F */  lw         $s0, 0x30($sp)
    /* 54C38 800BD438 03110200 */  sra        $v0, $v0, 4
    /* 54C3C 800BD43C 0800E003 */  jr         $ra
    /* 54C40 800BD440 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel func_800BD2B8
