nonmatching func_800A41D0, 0x2C4

glabel func_800A41D0
    /* 3B9D0 800A41D0 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 3B9D4 800A41D4 2400B1AF */  sw         $s1, 0x24($sp)
    /* 3B9D8 800A41D8 0F80023C */  lui        $v0, %hi(D_800E90A8)
    /* 3B9DC 800A41DC 0F80033C */  lui        $v1, %hi(D_800F45E0)
    /* 3B9E0 800A41E0 A890428C */  lw         $v0, %lo(D_800E90A8)($v0)
    /* 3B9E4 800A41E4 E0456324 */  addiu      $v1, $v1, %lo(D_800F45E0)
    /* 3B9E8 800A41E8 2800BFAF */  sw         $ra, 0x28($sp)
    /* 3B9EC 800A41EC 2000B0AF */  sw         $s0, 0x20($sp)
    /* 3B9F0 800A41F0 80100200 */  sll        $v0, $v0, 2
    /* 3B9F4 800A41F4 21104300 */  addu       $v0, $v0, $v1
    /* 3B9F8 800A41F8 02000324 */  addiu      $v1, $zero, 0x2
    /* 3B9FC 800A41FC 0000508C */  lw         $s0, 0x0($v0)
    /* 3BA00 800A4200 1700A314 */  bne        $a1, $v1, .L800A4260
    /* 3BA04 800A4204 21888000 */   addu      $s1, $a0, $zero
    /* 3BA08 800A4208 6C010292 */  lbu        $v0, 0x16C($s0)
    /* 3BA0C 800A420C 00000000 */  nop
    /* 3BA10 800A4210 07004330 */  andi       $v1, $v0, 0x7
    /* 3BA14 800A4214 0B006510 */  beq        $v1, $a1, .L800A4244
    /* 3BA18 800A4218 03006228 */   slti      $v0, $v1, 0x3
    /* 3BA1C 800A421C 05004014 */  bnez       $v0, .L800A4234
    /* 3BA20 800A4220 03000224 */   addiu     $v0, $zero, 0x3
    /* 3BA24 800A4224 08006210 */  beq        $v1, $v0, .L800A4248
    /* 3BA28 800A4228 FE000224 */   addiu     $v0, $zero, 0xFE
    /* 3BA2C 800A422C 94900208 */  j          .L800A4250
    /* 3BA30 800A4230 700100A2 */   sb        $zero, 0x170($s0)
  .L800A4234:
    /* 3BA34 800A4234 05006004 */  bltz       $v1, .L800A424C
    /* 3BA38 800A4238 F9000224 */   addiu     $v0, $zero, 0xF9
    /* 3BA3C 800A423C 93900208 */  j          .L800A424C
    /* 3BA40 800A4240 1A0002A6 */   sh        $v0, 0x1A($s0)
  .L800A4244:
    /* 3BA44 800A4244 FF000224 */  addiu      $v0, $zero, 0xFF
  .L800A4248:
    /* 3BA48 800A4248 1A0002A6 */  sh         $v0, 0x1A($s0)
  .L800A424C:
    /* 3BA4C 800A424C 700100A2 */  sb         $zero, 0x170($s0)
  .L800A4250:
    /* 3BA50 800A4250 289A030C */  jal        func_800E68A0
    /* 3BA54 800A4254 21200002 */   addu      $a0, $s0, $zero
    /* 3BA58 800A4258 1F910208 */  j          .L800A447C
    /* 3BA5C 800A425C 00000000 */   nop
  .L800A4260:
    /* 3BA60 800A4260 01000224 */  addiu      $v0, $zero, 0x1
    /* 3BA64 800A4264 3900A214 */  bne        $a1, $v0, .L800A434C
    /* 3BA68 800A4268 21184000 */   addu      $v1, $v0, $zero
    /* 3BA6C 800A426C 0F80023C */  lui        $v0, %hi(D_800F49E8)
    /* 3BA70 800A4270 5C002892 */  lbu        $t0, 0x5C($s1)
    /* 3BA74 800A4274 E849448C */  lw         $a0, %lo(D_800F49E8)($v0)
    /* 3BA78 800A4278 5E002992 */  lbu        $t1, 0x5E($s1)
    /* 3BA7C 800A427C 02008228 */  slti       $v0, $a0, 0x2
    /* 3BA80 800A4280 02004010 */  beqz       $v0, .L800A428C
    /* 3BA84 800A4284 01008230 */   andi      $v0, $a0, 0x1
    /* 3BA88 800A4288 FFFF0324 */  addiu      $v1, $zero, -0x1
  .L800A428C:
    /* 3BA8C 800A428C 03004010 */  beqz       $v0, .L800A429C
    /* 3BA90 800A4290 00000000 */   nop
    /* 3BA94 800A4294 A8900208 */  j          .L800A42A0
    /* 3BA98 800A4298 21400301 */   addu      $t0, $t0, $v1
  .L800A429C:
    /* 3BA9C 800A429C 21482301 */  addu       $t1, $t1, $v1
  .L800A42A0:
    /* 3BAA0 800A42A0 F0000524 */  addiu      $a1, $zero, 0xF0
    /* 3BAA4 800A42A4 1000A627 */  addiu      $a2, $sp, 0x10
    /* 3BAA8 800A42A8 0F80023C */  lui        $v0, %hi(D_800F49E8)
    /* 3BAAC 800A42AC E849438C */  lw         $v1, %lo(D_800F49E8)($v0)
    /* 3BAB0 800A42B0 C0110800 */  sll        $v0, $t0, 7
    /* 3BAB4 800A42B4 40004224 */  addiu      $v0, $v0, 0x40
    /* 3BAB8 800A42B8 1C0002A6 */  sh         $v0, 0x1C($s0)
    /* 3BABC 800A42BC C0110900 */  sll        $v0, $t1, 7
    /* 3BAC0 800A42C0 12000492 */  lbu        $a0, 0x12($s0)
    /* 3BAC4 800A42C4 40004224 */  addiu      $v0, $v0, 0x40
    /* 3BAC8 800A42C8 200002A6 */  sh         $v0, 0x20($s0)
    /* 3BACC 800A42CC 26000296 */  lhu        $v0, 0x26($s0)
    /* 3BAD0 800A42D0 01000724 */  addiu      $a3, $zero, 0x1
    /* 3BAD4 800A42D4 5C0008A2 */  sb         $t0, 0x5C($s0)
    /* 3BAD8 800A42D8 5E0009A2 */  sb         $t1, 0x5E($s0)
    /* 3BADC 800A42DC 801A0300 */  sll        $v1, $v1, 10
    /* 3BAE0 800A42E0 21104300 */  addu       $v0, $v0, $v1
    /* 3BAE4 800A42E4 FF0F4230 */  andi       $v0, $v0, 0xFFF
    /* 3BAE8 800A42E8 4386020C */  jal        func_800A190C
    /* 3BAEC 800A42EC 260002A6 */   sh        $v0, 0x26($s0)
    /* 3BAF0 800A42F0 F1000524 */  addiu      $a1, $zero, 0xF1
    /* 3BAF4 800A42F4 1800A627 */  addiu      $a2, $sp, 0x18
    /* 3BAF8 800A42F8 12000492 */  lbu        $a0, 0x12($s0)
    /* 3BAFC 800A42FC 4386020C */  jal        func_800A190C
    /* 3BB00 800A4300 01000724 */   addiu     $a3, $zero, 0x1
    /* 3BB04 800A4304 1200A287 */  lh         $v0, 0x12($sp)
    /* 3BB08 800A4308 1A00A487 */  lh         $a0, 0x1A($sp)
    /* 3BB0C 800A430C FC000324 */  addiu      $v1, $zero, 0xFC
    /* 3BB10 800A4310 1A0003A6 */  sh         $v1, 0x1A($s0)
    /* 3BB14 800A4314 18000324 */  addiu      $v1, $zero, 0x18
    /* 3BB18 800A4318 360003A6 */  sh         $v1, 0x36($s0)
    /* 3BB1C 800A431C FF000324 */  addiu      $v1, $zero, 0xFF
    /* 3BB20 800A4320 120003A2 */  sb         $v1, 0x12($s0)
    /* 3BB24 800A4324 21104400 */  addu       $v0, $v0, $a0
    /* 3BB28 800A4328 C21F0200 */  srl        $v1, $v0, 31
    /* 3BB2C 800A432C 21104300 */  addu       $v0, $v0, $v1
    /* 3BB30 800A4330 43100200 */  sra        $v0, $v0, 1
    /* 3BB34 800A4334 3C004224 */  addiu      $v0, $v0, 0x3C
    /* 3BB38 800A4338 1E0002A6 */  sh         $v0, 0x1E($s0)
    /* 3BB3C 800A433C AC05228E */  lw         $v0, 0x5AC($s1)
    /* 3BB40 800A4340 F7FF0324 */  addiu      $v1, $zero, -0x9
    /* 3BB44 800A4344 1E910208 */  j          .L800A4478
    /* 3BB48 800A4348 24104300 */   and       $v0, $v0, $v1
  .L800A434C:
    /* 3BB4C 800A434C 06000012 */  beqz       $s0, .L800A4368
    /* 3BB50 800A4350 00000000 */   nop
    /* 3BB54 800A4354 0800028E */  lw         $v0, 0x8($s0)
    /* 3BB58 800A4358 00000000 */  nop
    /* 3BB5C 800A435C 000F4230 */  andi       $v0, $v0, 0xF00
    /* 3BB60 800A4360 08004010 */  beqz       $v0, .L800A4384
    /* 3BB64 800A4364 00000000 */   nop
  .L800A4368:
    /* 3BB68 800A4368 0F002492 */  lbu        $a0, 0xF($s1)
    /* 3BB6C 800A436C 01000524 */  addiu      $a1, $zero, 0x1
    /* 3BB70 800A4370 21300000 */  addu       $a2, $zero, $zero
    /* 3BB74 800A4374 8180020C */  jal        func_800A0204
    /* 3BB78 800A4378 08000724 */   addiu     $a3, $zero, 0x8
    /* 3BB7C 800A437C 1F910208 */  j          .L800A447C
    /* 3BB80 800A4380 00000000 */   nop
  .L800A4384:
    /* 3BB84 800A4384 5C000492 */  lbu        $a0, 0x5C($s0)
    /* 3BB88 800A4388 5E000592 */  lbu        $a1, 0x5E($s0)
    /* 3BB8C 800A438C 0A93030C */  jal        func_800E4C28
    /* 3BB90 800A4390 00000000 */   nop
    /* 3BB94 800A4394 289A030C */  jal        func_800E68A0
    /* 3BB98 800A4398 21200002 */   addu      $a0, $s0, $zero
    /* 3BB9C 800A439C 6C01028E */  lw         $v0, 0x16C($s0)
    /* 3BBA0 800A43A0 20000324 */  addiu      $v1, $zero, 0x20
    /* 3BBA4 800A43A4 30004230 */  andi       $v0, $v0, 0x30
    /* 3BBA8 800A43A8 04004314 */  bne        $v0, $v1, .L800A43BC
    /* 3BBAC 800A43AC 0F80023C */   lui       $v0, %hi(D_800F49E8)
    /* 3BBB0 800A43B0 289A030C */  jal        func_800E68A0
    /* 3BBB4 800A43B4 21200002 */   addu      $a0, $s0, $zero
    /* 3BBB8 800A43B8 0F80023C */  lui        $v0, %hi(D_800F49E8)
  .L800A43BC:
    /* 3BBBC 800A43BC E849448C */  lw         $a0, %lo(D_800F49E8)($v0)
    /* 3BBC0 800A43C0 00000000 */  nop
    /* 3BBC4 800A43C4 02008228 */  slti       $v0, $a0, 0x2
    /* 3BBC8 800A43C8 02004010 */  beqz       $v0, .L800A43D4
    /* 3BBCC 800A43CC 80FF0324 */   addiu     $v1, $zero, -0x80
    /* 3BBD0 800A43D0 80000324 */  addiu      $v1, $zero, 0x80
  .L800A43D4:
    /* 3BBD4 800A43D4 01008230 */  andi       $v0, $a0, 0x1
    /* 3BBD8 800A43D8 06004010 */  beqz       $v0, .L800A43F4
    /* 3BBDC 800A43DC 00000000 */   nop
    /* 3BBE0 800A43E0 34000296 */  lhu        $v0, 0x34($s0)
    /* 3BBE4 800A43E4 00000000 */  nop
    /* 3BBE8 800A43E8 21104300 */  addu       $v0, $v0, $v1
    /* 3BBEC 800A43EC 01910208 */  j          .L800A4404
    /* 3BBF0 800A43F0 340002A6 */   sh        $v0, 0x34($s0)
  .L800A43F4:
    /* 3BBF4 800A43F4 38000296 */  lhu        $v0, 0x38($s0)
    /* 3BBF8 800A43F8 00000000 */  nop
    /* 3BBFC 800A43FC 21104300 */  addu       $v0, $v0, $v1
    /* 3BC00 800A4400 380002A6 */  sh         $v0, 0x38($s0)
  .L800A4404:
    /* 3BC04 800A4404 0F80023C */  lui        $v0, %hi(D_800F49E8)
    /* 3BC08 800A4408 E849438C */  lw         $v1, %lo(D_800F49E8)($v0)
    /* 3BC0C 800A440C 04000224 */  addiu      $v0, $zero, 0x4
    /* 3BC10 800A4410 23104300 */  subu       $v0, $v0, $v1
    /* 3BC14 800A4414 26000396 */  lhu        $v1, 0x26($s0)
    /* 3BC18 800A4418 80120200 */  sll        $v0, $v0, 10
    /* 3BC1C 800A441C 21186200 */  addu       $v1, $v1, $v0
    /* 3BC20 800A4420 FF0F6330 */  andi       $v1, $v1, 0xFFF
    /* 3BC24 800A4424 00026424 */  addiu      $a0, $v1, 0x200
    /* 3BC28 800A4428 FF0F8430 */  andi       $a0, $a0, 0xFFF
    /* 3BC2C 800A442C 21108000 */  addu       $v0, $a0, $zero
    /* 3BC30 800A4430 02008104 */  bgez       $a0, .L800A443C
    /* 3BC34 800A4434 260003A6 */   sh        $v1, 0x26($s0)
    /* 3BC38 800A4438 FF038224 */  addiu      $v0, $a0, 0x3FF
  .L800A443C:
    /* 3BC3C 800A443C 001C4230 */  andi       $v0, $v0, 0x1C00
    /* 3BC40 800A4440 260002A6 */  sh         $v0, 0x26($s0)
    /* 3BC44 800A4444 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 3BC48 800A4448 5C0002A2 */  sb         $v0, 0x5C($s0)
    /* 3BC4C 800A444C 08000224 */  addiu      $v0, $zero, 0x8
    /* 3BC50 800A4450 1A0002A6 */  sh         $v0, 0x1A($s0)
    /* 3BC54 800A4454 0F002292 */  lbu        $v0, 0xF($s1)
    /* 3BC58 800A4458 00000000 */  nop
    /* 3BC5C 800A445C 120002A2 */  sb         $v0, 0x12($s0)
    /* 3BC60 800A4460 0F80023C */  lui        $v0, %hi(D_800E90A8)
    /* 3BC64 800A4464 A8904390 */  lbu        $v1, %lo(D_800E90A8)($v0)
    /* 3BC68 800A4468 AC05228E */  lw         $v0, 0x5AC($s1)
    /* 3BC6C 800A446C 00000000 */  nop
    /* 3BC70 800A4470 08004234 */  ori        $v0, $v0, 0x8
    /* 3BC74 800A4474 130023A2 */  sb         $v1, 0x13($s1)
  .L800A4478:
    /* 3BC78 800A4478 AC0522AE */  sw         $v0, 0x5AC($s1)
  .L800A447C:
    /* 3BC7C 800A447C 2800BF8F */  lw         $ra, 0x28($sp)
    /* 3BC80 800A4480 2400B18F */  lw         $s1, 0x24($sp)
    /* 3BC84 800A4484 2000B08F */  lw         $s0, 0x20($sp)
    /* 3BC88 800A4488 3000BD27 */  addiu      $sp, $sp, 0x30
    /* 3BC8C 800A448C 0800E003 */  jr         $ra
    /* 3BC90 800A4490 00000000 */   nop
endlabel func_800A41D0
