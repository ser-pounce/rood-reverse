nonmatching _memcardMaskedHandler, 0xDC

glabel _memcardMaskedHandler
    /* 29F4 801051F4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 29F8 801051F8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 29FC 801051FC 21808000 */  addu       $s0, $a0, $zero
    /* 2A00 80105200 07000012 */  beqz       $s0, .L80105220
    /* 2A04 80105204 1400BFAF */   sw        $ra, 0x14($sp)
    /* 2A08 80105208 F70C040C */  jal        _memcardEventHandler
    /* 2A0C 8010520C 03000432 */   andi      $a0, $s0, 0x3
    /* 2A10 80105210 1180033C */  lui        $v1, %hi(_memcardMask)
    /* 2A14 80105214 03111000 */  sra        $v0, $s0, 4
    /* 2A18 80105218 AF140408 */  j          .L801052BC
    /* 2A1C 8010521C A6AA62A0 */   sb        $v0, %lo(_memcardMask)($v1)
  .L80105220:
    /* 2A20 80105220 F70C040C */  jal        _memcardEventHandler
    /* 2A24 80105224 21200000 */   addu      $a0, $zero, $zero
    /* 2A28 80105228 21184000 */  addu       $v1, $v0, $zero
    /* 2A2C 8010522C 23006010 */  beqz       $v1, .L801052BC
    /* 2A30 80105230 1180023C */   lui       $v0, %hi(_memcardMask)
    /* 2A34 80105234 A6AA4290 */  lbu        $v0, %lo(_memcardMask)($v0)
    /* 2A38 80105238 00000000 */  nop
    /* 2A3C 8010523C 24186200 */  and        $v1, $v1, $v0
    /* 2A40 80105240 02000224 */  addiu      $v0, $zero, 0x2
    /* 2A44 80105244 0F006210 */  beq        $v1, $v0, .L80105284
    /* 2A48 80105248 1180023C */   lui       $v0, %hi(_textTable)
    /* 2A4C 8010524C 03006228 */  slti       $v0, $v1, 0x3
    /* 2A50 80105250 05004010 */  beqz       $v0, .L80105268
    /* 2A54 80105254 01000224 */   addiu     $v0, $zero, 0x1
    /* 2A58 80105258 08006210 */  beq        $v1, $v0, .L8010527C
    /* 2A5C 8010525C 1180023C */   lui       $v0, %hi(_textTable)
    /* 2A60 80105260 A9140408 */  j          .L801052A4
    /* 2A64 80105264 00000000 */   nop
  .L80105268:
    /* 2A68 80105268 03000224 */  addiu      $v0, $zero, 0x3
    /* 2A6C 8010526C 09006210 */  beq        $v1, $v0, .L80105294
    /* 2A70 80105270 1180033C */   lui       $v1, %hi(_memoryCardMessage)
    /* 2A74 80105274 A9140408 */  j          .L801052A4
    /* 2A78 80105278 1180023C */   lui       $v0, %hi(_textTable)
  .L8010527C:
    /* 2A7C 8010527C B0140408 */  j          .L801052C0
    /* 2A80 80105280 01000224 */   addiu     $v0, $zero, 0x1
  .L80105284:
    /* 2A84 80105284 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 2A88 80105288 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 2A8C 8010528C AC140408 */  j          .L801052B0
    /* 2A90 80105290 C6014224 */   addiu     $v0, $v0, 0x1C6
  .L80105294:
    /* 2A94 80105294 1180023C */  lui        $v0, %hi(_textTable)
    /* 2A98 80105298 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 2A9C 8010529C AC140408 */  j          .L801052B0
    /* 2AA0 801052A0 C4054224 */   addiu     $v0, $v0, 0x5C4
  .L801052A4:
    /* 2AA4 801052A4 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 2AA8 801052A8 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 2AAC 801052AC BC034224 */  addiu      $v0, $v0, 0x3BC
  .L801052B0:
    /* 2AB0 801052B0 A4B062AC */  sw         $v0, %lo(_memoryCardMessage)($v1)
    /* 2AB4 801052B4 B0140408 */  j          .L801052C0
    /* 2AB8 801052B8 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L801052BC:
    /* 2ABC 801052BC 21100000 */  addu       $v0, $zero, $zero
  .L801052C0:
    /* 2AC0 801052C0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2AC4 801052C4 1000B08F */  lw         $s0, 0x10($sp)
    /* 2AC8 801052C8 0800E003 */  jr         $ra
    /* 2ACC 801052CC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _memcardMaskedHandler
