nonmatching func_80106A50, 0x214

glabel func_80106A50
    /* 4250 80106A50 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 4254 80106A54 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4258 80106A58 21800000 */  addu       $s0, $zero, $zero
    /* 425C 80106A5C 1080023C */  lui        $v0, %hi(vs_menu_inventoryStorage)
    /* 4260 80106A60 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 4264 80106A64 21984000 */  addu       $s3, $v0, $zero
    /* 4268 80106A68 2000B4AF */  sw         $s4, 0x20($sp)
    /* 426C 80106A6C B0871434 */  ori        $s4, $zero, 0x87B0
    /* 4270 80106A70 5C24638E */  lw         $v1, %lo(vs_menu_inventoryStorage)($s3)
    /* 4274 80106A74 B0C30234 */  ori        $v0, $zero, 0xC3B0
    /* 4278 80106A78 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 427C 80106A7C 2800B6AF */  sw         $s6, 0x28($sp)
    /* 4280 80106A80 2400B5AF */  sw         $s5, 0x24($sp)
    /* 4284 80106A84 1800B2AF */  sw         $s2, 0x18($sp)
    /* 4288 80106A88 1400B1AF */  sw         $s1, 0x14($sp)
    /* 428C 80106A8C 21906200 */  addu       $s2, $v1, $v0
    /* 4290 80106A90 21884002 */  addu       $s1, $s2, $zero
  .L80106A94:
    /* 4294 80106A94 00002596 */  lhu        $a1, 0x0($s1)
    /* 4298 80106A98 00000000 */  nop
    /* 429C 80106A9C 0900A010 */  beqz       $a1, .L80106AC4
    /* 42A0 80106AA0 02220500 */   srl       $a0, $a1, 8
    /* 42A4 80106AA4 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 42A8 80106AA8 5C24668E */  lw         $a2, %lo(vs_menu_inventoryStorage)($s3)
    /* 42AC 80106AAC FF00A530 */  andi       $a1, $a1, 0xFF
    /* 42B0 80106AB0 E20B040C */  jal        _getContainerItemId
    /* 42B4 80106AB4 2130D400 */   addu      $a2, $a2, $s4
    /* 42B8 80106AB8 02004014 */  bnez       $v0, .L80106AC4
    /* 42BC 80106ABC 00000000 */   nop
    /* 42C0 80106AC0 000020A6 */  sh         $zero, 0x0($s1)
  .L80106AC4:
    /* 42C4 80106AC4 01001026 */  addiu      $s0, $s0, 0x1
    /* 42C8 80106AC8 4000022A */  slti       $v0, $s0, 0x40
    /* 42CC 80106ACC F1FF4014 */  bnez       $v0, .L80106A94
    /* 42D0 80106AD0 02003126 */   addiu     $s1, $s1, 0x2
    /* 42D4 80106AD4 21800000 */  addu       $s0, $zero, $zero
    /* 42D8 80106AD8 21384002 */  addu       $a3, $s2, $zero
  .L80106ADC:
    /* 42DC 80106ADC 0000E294 */  lhu        $v0, 0x0($a3)
    /* 42E0 80106AE0 00000000 */  nop
    /* 42E4 80106AE4 06004010 */  beqz       $v0, .L80106B00
    /* 42E8 80106AE8 3F000224 */   addiu     $v0, $zero, 0x3F
    /* 42EC 80106AEC 01001026 */  addiu      $s0, $s0, 0x1
    /* 42F0 80106AF0 2E000212 */  beq        $s0, $v0, .L80106BAC
    /* 42F4 80106AF4 0200E724 */   addiu     $a3, $a3, 0x2
    /* 42F8 80106AF8 B71A0408 */  j          .L80106ADC
    /* 42FC 80106AFC 00000000 */   nop
  .L80106B00:
    /* 4300 80106B00 01000526 */  addiu      $a1, $s0, 0x1
    /* 4304 80106B04 4000A228 */  slti       $v0, $a1, 0x40
    /* 4308 80106B08 0A004010 */  beqz       $v0, .L80106B34
    /* 430C 80106B0C 40100500 */   sll       $v0, $a1, 1
    /* 4310 80106B10 21185200 */  addu       $v1, $v0, $s2
  .L80106B14:
    /* 4314 80106B14 00006294 */  lhu        $v0, 0x0($v1)
    /* 4318 80106B18 00000000 */  nop
    /* 431C 80106B1C 06004014 */  bnez       $v0, .L80106B38
    /* 4320 80106B20 40000224 */   addiu     $v0, $zero, 0x40
    /* 4324 80106B24 0100A524 */  addiu      $a1, $a1, 0x1
    /* 4328 80106B28 4000A228 */  slti       $v0, $a1, 0x40
    /* 432C 80106B2C F9FF4014 */  bnez       $v0, .L80106B14
    /* 4330 80106B30 02006324 */   addiu     $v1, $v1, 0x2
  .L80106B34:
    /* 4334 80106B34 40000224 */  addiu      $v0, $zero, 0x40
  .L80106B38:
    /* 4338 80106B38 1C00A210 */  beq        $a1, $v0, .L80106BAC
    /* 433C 80106B3C 2120A000 */   addu      $a0, $a1, $zero
    /* 4340 80106B40 2A108200 */  slt        $v0, $a0, $v0
    /* 4344 80106B44 0C004010 */  beqz       $v0, .L80106B78
    /* 4348 80106B48 40100400 */   sll       $v0, $a0, 1
    /* 434C 80106B4C 21305200 */  addu       $a2, $v0, $s2
  .L80106B50:
    /* 4350 80106B50 0000C294 */  lhu        $v0, 0x0($a2)
    /* 4354 80106B54 21189000 */  addu       $v1, $a0, $s0
    /* 4358 80106B58 01008424 */  addiu      $a0, $a0, 0x1
    /* 435C 80106B5C 23186500 */  subu       $v1, $v1, $a1
    /* 4360 80106B60 40180300 */  sll        $v1, $v1, 1
    /* 4364 80106B64 21187200 */  addu       $v1, $v1, $s2
    /* 4368 80106B68 000062A4 */  sh         $v0, 0x0($v1)
    /* 436C 80106B6C 40008228 */  slti       $v0, $a0, 0x40
    /* 4370 80106B70 F7FF4014 */  bnez       $v0, .L80106B50
    /* 4374 80106B74 0200C624 */   addiu     $a2, $a2, 0x2
  .L80106B78:
    /* 4378 80106B78 23100502 */  subu       $v0, $s0, $a1
    /* 437C 80106B7C 21208200 */  addu       $a0, $a0, $v0
    /* 4380 80106B80 40008228 */  slti       $v0, $a0, 0x40
    /* 4384 80106B84 D5FF4010 */  beqz       $v0, .L80106ADC
    /* 4388 80106B88 40100400 */   sll       $v0, $a0, 1
    /* 438C 80106B8C 21185200 */  addu       $v1, $v0, $s2
  .L80106B90:
    /* 4390 80106B90 000060A4 */  sh         $zero, 0x0($v1)
    /* 4394 80106B94 01008424 */  addiu      $a0, $a0, 0x1
    /* 4398 80106B98 40008228 */  slti       $v0, $a0, 0x40
    /* 439C 80106B9C FCFF4014 */  bnez       $v0, .L80106B90
    /* 43A0 80106BA0 02006324 */   addiu     $v1, $v1, 0x2
    /* 43A4 80106BA4 B71A0408 */  j          .L80106ADC
    /* 43A8 80106BA8 00000000 */   nop
  .L80106BAC:
    /* 43AC 80106BAC 21880000 */  addu       $s1, $zero, $zero
    /* 43B0 80106BB0 1080163C */  lui        $s6, %hi(vs_menu_inventoryStorage)
    /* 43B4 80106BB4 B0871534 */  ori        $s5, $zero, 0x87B0
    /* 43B8 80106BB8 21A02002 */  addu       $s4, $s1, $zero
    /* 43BC 80106BBC 1180023C */  lui        $v0, %hi(_containerItemCapacities)
    /* 43C0 80106BC0 44995324 */  addiu      $s3, $v0, %lo(_containerItemCapacities)
  .L80106BC4:
    /* 43C4 80106BC4 00006296 */  lhu        $v0, 0x0($s3)
    /* 43C8 80106BC8 00000000 */  nop
    /* 43CC 80106BCC 16004010 */  beqz       $v0, .L80106C28
    /* 43D0 80106BD0 21800000 */   addu      $s0, $zero, $zero
    /* 43D4 80106BD4 1180023C */  lui        $v0, %hi(_containerItemCapacities)
    /* 43D8 80106BD8 44994224 */  addiu      $v0, $v0, %lo(_containerItemCapacities)
    /* 43DC 80106BDC 21908202 */  addu       $s2, $s4, $v0
    /* 43E0 80106BE0 21202002 */  addu       $a0, $s1, $zero
  .L80106BE4:
    /* 43E4 80106BE4 5C24C68E */  lw         $a2, %lo(vs_menu_inventoryStorage)($s6)
    /* 43E8 80106BE8 21280002 */  addu       $a1, $s0, $zero
    /* 43EC 80106BEC E20B040C */  jal        _getContainerItemId
    /* 43F0 80106BF0 2130D500 */   addu      $a2, $a2, $s5
    /* 43F4 80106BF4 07004010 */  beqz       $v0, .L80106C14
    /* 43F8 80106BF8 21202002 */   addu      $a0, $s1, $zero
    /* 43FC 80106BFC 6C1A040C */  jal        func_801069B0
    /* 4400 80106C00 21280002 */   addu      $a1, $s0, $zero
    /* 4404 80106C04 03004014 */  bnez       $v0, .L80106C14
    /* 4408 80106C08 21202002 */   addu      $a0, $s1, $zero
    /* 440C 80106C0C 811A040C */  jal        func_80106A04
    /* 4410 80106C10 21280002 */   addu      $a1, $s0, $zero
  .L80106C14:
    /* 4414 80106C14 00004296 */  lhu        $v0, 0x0($s2)
    /* 4418 80106C18 01001026 */  addiu      $s0, $s0, 0x1
    /* 441C 80106C1C 2A100202 */  slt        $v0, $s0, $v0
    /* 4420 80106C20 F0FF4014 */  bnez       $v0, .L80106BE4
    /* 4424 80106C24 21202002 */   addu      $a0, $s1, $zero
  .L80106C28:
    /* 4428 80106C28 02009426 */  addiu      $s4, $s4, 0x2
    /* 442C 80106C2C 01003126 */  addiu      $s1, $s1, 0x1
    /* 4430 80106C30 0700222A */  slti       $v0, $s1, 0x7
    /* 4434 80106C34 E3FF4014 */  bnez       $v0, .L80106BC4
    /* 4438 80106C38 02007326 */   addiu     $s3, $s3, 0x2
    /* 443C 80106C3C 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 4440 80106C40 2800B68F */  lw         $s6, 0x28($sp)
    /* 4444 80106C44 2400B58F */  lw         $s5, 0x24($sp)
    /* 4448 80106C48 2000B48F */  lw         $s4, 0x20($sp)
    /* 444C 80106C4C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 4450 80106C50 1800B28F */  lw         $s2, 0x18($sp)
    /* 4454 80106C54 1400B18F */  lw         $s1, 0x14($sp)
    /* 4458 80106C58 1000B08F */  lw         $s0, 0x10($sp)
    /* 445C 80106C5C 0800E003 */  jr         $ra
    /* 4460 80106C60 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_80106A50
