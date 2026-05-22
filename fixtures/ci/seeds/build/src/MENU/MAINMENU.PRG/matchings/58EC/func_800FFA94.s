nonmatching func_800FFA94, 0xD4

glabel func_800FFA94
    /* 6294 800FFA94 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6298 800FFA98 1080043C */  lui        $a0, %hi(D_801022E2)
    /* 629C 800FFA9C 1080033C */  lui        $v1, %hi(D_801022E4)
    /* 62A0 800FFAA0 1080023C */  lui        $v0, %hi(D_801022E3)
    /* 62A4 800FFAA4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 62A8 800FFAA8 E2229090 */  lbu        $s0, %lo(D_801022E2)($a0)
    /* 62AC 800FFAAC E3224290 */  lbu        $v0, %lo(D_801022E3)($v0)
    /* 62B0 800FFAB0 E422658C */  lw         $a1, %lo(D_801022E4)($v1)
    /* 62B4 800FFAB4 07000212 */  beq        $s0, $v0, .L800FFAD4
    /* 62B8 800FFAB8 1400BFAF */   sw        $ra, 0x14($sp)
    /* 62BC 800FFABC 0300A014 */  bnez       $a1, .L800FFACC
    /* 62C0 800FFAC0 00000000 */   nop
    /* 62C4 800FFAC4 D6FE0308 */  j          .L800FFB58
    /* 62C8 800FFAC8 E22282A0 */   sb        $v0, %lo(D_801022E2)($a0)
  .L800FFACC:
    /* 62CC 800FFACC B9FE0308 */  j          .L800FFAE4
    /* 62D0 800FFAD0 FEFFA524 */   addiu     $a1, $a1, -0x2
  .L800FFAD4:
    /* 62D4 800FFAD4 0C00A228 */  slti       $v0, $a1, 0xC
    /* 62D8 800FFAD8 03004010 */  beqz       $v0, .L800FFAE8
    /* 62DC 800FFADC 1080023C */   lui       $v0, %hi(D_801022E4)
    /* 62E0 800FFAE0 0200A524 */  addiu      $a1, $a1, 0x2
  .L800FFAE4:
    /* 62E4 800FFAE4 1080023C */  lui        $v0, %hi(D_801022E4)
  .L800FFAE8:
    /* 62E8 800FFAE8 1B000012 */  beqz       $s0, .L800FFB58
    /* 62EC 800FFAEC E42245AC */   sw        $a1, %lo(D_801022E4)($v0)
    /* 62F0 800FFAF0 1080033C */  lui        $v1, %hi(D_801022F8)
    /* 62F4 800FFAF4 F8226324 */  addiu      $v1, $v1, %lo(D_801022F8)
    /* 62F8 800FFAF8 80101000 */  sll        $v0, $s0, 2
    /* 62FC 800FFAFC 21104300 */  addu       $v0, $v0, $v1
    /* 6300 800FFB00 0000468C */  lw         $a2, 0x0($v0)
    /* 6304 800FFB04 38010224 */  addiu      $v0, $zero, 0x138
    /* 6308 800FFB08 FCFFA524 */  addiu      $a1, $a1, -0x4
    /* 630C 800FFB0C 002C0500 */  sll        $a1, $a1, 16
    /* 6310 800FFB10 80010424 */  addiu      $a0, $zero, 0x180
    /* 6314 800FFB14 FF00C330 */  andi       $v1, $a2, 0xFF
    /* 6318 800FFB18 23104300 */  subu       $v0, $v0, $v1
    /* 631C 800FFB1C 801F033C */  lui        $v1, (0x1F800008 >> 16)
    /* 6320 800FFB20 0800678C */  lw         $a3, (0x1F800008 & 0xFFFF)($v1)
    /* 6324 800FFB24 8C00030C */  jal        vs_battle_setSprite
    /* 6328 800FFB28 25284500 */   or        $a1, $v0, $a1
    /* 632C 800FFB2C 00E1033C */  lui        $v1, (0xE100002C >> 16)
    /* 6330 800FFB30 2C006334 */  ori        $v1, $v1, (0xE100002C & 0xFFFF)
    /* 6334 800FFB34 1080043C */  lui        $a0, %hi(D_801022E8)
    /* 6338 800FFB38 E8228424 */  addiu      $a0, $a0, %lo(D_801022E8)
    /* 633C 800FFB3C 040043AC */  sw         $v1, 0x4($v0)
    /* 6340 800FFB40 40181000 */  sll        $v1, $s0, 1
    /* 6344 800FFB44 21186400 */  addu       $v1, $v1, $a0
    /* 6348 800FFB48 00006394 */  lhu        $v1, 0x0($v1)
    /* 634C 800FFB4C F537043C */  lui        $a0, (0x37F50000 >> 16)
    /* 6350 800FFB50 25186400 */  or         $v1, $v1, $a0
    /* 6354 800FFB54 100043AC */  sw         $v1, 0x10($v0)
  .L800FFB58:
    /* 6358 800FFB58 1400BF8F */  lw         $ra, 0x14($sp)
    /* 635C 800FFB5C 1000B08F */  lw         $s0, 0x10($sp)
    /* 6360 800FFB60 0800E003 */  jr         $ra
    /* 6364 800FFB64 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800FFA94
