nonmatching vs_battle_loadGim, 0x120

glabel vs_battle_loadGim
    /* 5FC30 800C8430 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 5FC34 800C8434 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 5FC38 800C8438 0F80113C */  lui        $s1, %hi(D_800EB9BC)
    /* 5FC3C 800C843C BCB9228E */  lw         $v0, %lo(D_800EB9BC)($s1)
    /* 5FC40 800C8440 2000B2AF */  sw         $s2, 0x20($sp)
    /* 5FC44 800C8444 21908000 */  addu       $s2, $a0, $zero
    /* 5FC48 800C8448 2400B3AF */  sw         $s3, 0x24($sp)
    /* 5FC4C 800C844C 2198A000 */  addu       $s3, $a1, $zero
    /* 5FC50 800C8450 2800BFAF */  sw         $ra, 0x28($sp)
    /* 5FC54 800C8454 37004014 */  bnez       $v0, .L800C8534
    /* 5FC58 800C8458 1800B0AF */   sw        $s0, 0x18($sp)
    /* 5FC5C 800C845C 8F0F010C */  jal        vs_main_allocHeapR
    /* 5FC60 800C8460 E80B0424 */   addiu     $a0, $zero, 0xBE8
    /* 5FC64 800C8464 21804000 */  addu       $s0, $v0, $zero
    /* 5FC68 800C8468 0F80023C */  lui        $v0, %hi(_gimLbas)
    /* 5FC6C 800C846C 08B64224 */  addiu      $v0, $v0, %lo(_gimLbas)
    /* 5FC70 800C8470 80181200 */  sll        $v1, $s2, 2
    /* 5FC74 800C8474 21186200 */  addu       $v1, $v1, $v0
    /* 5FC78 800C8478 BCB930AE */  sw         $s0, %lo(D_800EB9BC)($s1)
    /* 5FC7C 800C847C 00006490 */  lbu        $a0, 0x0($v1)
    /* 5FC80 800C8480 8F0F010C */  jal        vs_main_allocHeapR
    /* 5FC84 800C8484 C0220400 */   sll       $a0, $a0, 11
    /* 5FC88 800C8488 21200000 */  addu       $a0, $zero, $zero
    /* 5FC8C 800C848C 3FFE0724 */  addiu      $a3, $zero, -0x1C1
    /* 5FC90 800C8490 80000624 */  addiu      $a2, $zero, 0x80
    /* 5FC94 800C8494 00100524 */  addiu      $a1, $zero, 0x1000
    /* 5FC98 800C8498 0C000326 */  addiu      $v1, $s0, 0xC
    /* 5FC9C 800C849C 100002AE */  sw         $v0, 0x10($s0)
  .L800C84A0:
    /* 5FCA0 800C84A0 000000A6 */  sh         $zero, 0x0($s0)
    /* 5FCA4 800C84A4 0000028E */  lw         $v0, 0x0($s0)
    /* 5FCA8 800C84A8 01008424 */  addiu      $a0, $a0, 0x1
    /* 5FCAC 800C84AC 02004234 */  ori        $v0, $v0, 0x2
    /* 5FCB0 800C84B0 24104700 */  and        $v0, $v0, $a3
    /* 5FCB4 800C84B4 40004234 */  ori        $v0, $v0, 0x40
    /* 5FCB8 800C84B8 000002AE */  sw         $v0, 0x0($s0)
    /* 5FCBC 800C84BC F6FF73A0 */  sb         $s3, -0xA($v1)
    /* 5FCC0 800C84C0 F7FF66A0 */  sb         $a2, -0x9($v1)
    /* 5FCC4 800C84C4 FAFF72A4 */  sh         $s2, -0x6($v1)
    /* 5FCC8 800C84C8 FCFF60A4 */  sh         $zero, -0x4($v1)
    /* 5FCCC 800C84CC FEFF60A4 */  sh         $zero, -0x2($v1)
    /* 5FCD0 800C84D0 000065A4 */  sh         $a1, 0x0($v1)
    /* 5FCD4 800C84D4 F8036324 */  addiu      $v1, $v1, 0x3F8
    /* 5FCD8 800C84D8 03008228 */  slti       $v0, $a0, 0x3
    /* 5FCDC 800C84DC F0FF4014 */  bnez       $v0, .L800C84A0
    /* 5FCE0 800C84E0 F8031026 */   addiu     $s0, $s0, 0x3F8
    /* 5FCE4 800C84E4 0F80023C */  lui        $v0, %hi(_gimLbas)
    /* 5FCE8 800C84E8 08B64224 */  addiu      $v0, $v0, %lo(_gimLbas)
    /* 5FCEC 800C84EC 80181200 */  sll        $v1, $s2, 2
    /* 5FCF0 800C84F0 21186200 */  addu       $v1, $v1, $v0
    /* 5FCF4 800C84F4 0000628C */  lw         $v0, 0x0($v1)
    /* 5FCF8 800C84F8 00000000 */  nop
    /* 5FCFC 800C84FC 02120200 */  srl        $v0, $v0, 8
    /* 5FD00 800C8500 1000A2AF */  sw         $v0, 0x10($sp)
    /* 5FD04 800C8504 00006290 */  lbu        $v0, 0x0($v1)
    /* 5FD08 800C8508 1000A427 */  addiu      $a0, $sp, 0x10
    /* 5FD0C 800C850C C0120200 */  sll        $v0, $v0, 11
    /* 5FD10 800C8510 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 5FD14 800C8514 1400A2AF */   sw        $v0, 0x14($sp)
    /* 5FD18 800C8518 0F80033C */  lui        $v1, %hi(D_800EB9BC)
    /* 5FD1C 800C851C BCB9638C */  lw         $v1, %lo(D_800EB9BC)($v1)
    /* 5FD20 800C8520 00000000 */  nop
    /* 5FD24 800C8524 1000658C */  lw         $a1, 0x10($v1)
    /* 5FD28 800C8528 21204000 */  addu       $a0, $v0, $zero
    /* 5FD2C 800C852C F112010C */  jal        vs_main_cdEnqueue
    /* 5FD30 800C8530 140064AC */   sw        $a0, 0x14($v1)
  .L800C8534:
    /* 5FD34 800C8534 2800BF8F */  lw         $ra, 0x28($sp)
    /* 5FD38 800C8538 2400B38F */  lw         $s3, 0x24($sp)
    /* 5FD3C 800C853C 2000B28F */  lw         $s2, 0x20($sp)
    /* 5FD40 800C8540 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 5FD44 800C8544 1800B08F */  lw         $s0, 0x18($sp)
    /* 5FD48 800C8548 0800E003 */  jr         $ra
    /* 5FD4C 800C854C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel vs_battle_loadGim
