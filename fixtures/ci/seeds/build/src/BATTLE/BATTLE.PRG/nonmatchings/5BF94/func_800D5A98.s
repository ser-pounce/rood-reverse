nonmatching func_800D5A98, 0x2DC

glabel func_800D5A98
    /* 6D298 800D5A98 A8FFBD27 */  addiu      $sp, $sp, -0x58
    /* 6D29C 800D5A9C 4000B2AF */  sw         $s2, 0x40($sp)
    /* 6D2A0 800D5AA0 21908000 */  addu       $s2, $a0, $zero
    /* 6D2A4 800D5AA4 3800B0AF */  sw         $s0, 0x38($sp)
    /* 6D2A8 800D5AA8 2180A000 */  addu       $s0, $a1, $zero
    /* 6D2AC 800D5AAC 4800B4AF */  sw         $s4, 0x48($sp)
    /* 6D2B0 800D5AB0 21A0C000 */  addu       $s4, $a2, $zero
    /* 6D2B4 800D5AB4 5000BFAF */  sw         $ra, 0x50($sp)
    /* 6D2B8 800D5AB8 4C00B5AF */  sw         $s5, 0x4C($sp)
    /* 6D2BC 800D5ABC 4400B3AF */  sw         $s3, 0x44($sp)
    /* 6D2C0 800D5AC0 3C00B1AF */  sw         $s1, 0x3C($sp)
    /* 6D2C4 800D5AC4 0000118E */  lw         $s1, 0x0($s0)
    /* 6D2C8 800D5AC8 4C0D428E */  lw         $v0, 0xD4C($s2)
    /* 6D2CC 800D5ACC 07002392 */  lbu        $v1, 0x7($s1)
    /* 6D2D0 800D5AD0 02004284 */  lh         $v0, 0x2($v0)
    /* 6D2D4 800D5AD4 00000000 */  nop
    /* 6D2D8 800D5AD8 2A104300 */  slt        $v0, $v0, $v1
    /* 6D2DC 800D5ADC 9B004014 */  bnez       $v0, .L800D5D4C
    /* 6D2E0 800D5AE0 01001524 */   addiu     $s5, $zero, 0x1
    /* 6D2E4 800D5AE4 0F80063C */  lui        $a2, %hi(D_800F569C)
    /* 6D2E8 800D5AE8 9C56C58C */  lw         $a1, %lo(D_800F569C)($a2)
    /* 6D2EC 800D5AEC 00000000 */  nop
    /* 6D2F0 800D5AF0 D000A28C */  lw         $v0, 0xD0($a1)
    /* 6D2F4 800D5AF4 0E000486 */  lh         $a0, 0xE($s0)
    /* 6D2F8 800D5AF8 02004390 */  lbu        $v1, 0x2($v0)
    /* 6D2FC 800D5AFC 00000000 */  nop
    /* 6D300 800D5B00 2A108300 */  slt        $v0, $a0, $v1
    /* 6D304 800D5B04 5E004010 */  beqz       $v0, .L800D5C80
    /* 6D308 800D5B08 00000000 */   nop
    /* 6D30C 800D5B0C 0C000286 */  lh         $v0, 0xC($s0)
    /* 6D310 800D5B10 00000000 */  nop
    /* 6D314 800D5B14 55004014 */  bnez       $v0, .L800D5C6C
    /* 6D318 800D5B18 2198C000 */   addu      $s3, $a2, $zero
  .L800D5B1C:
    /* 6D31C 800D5B1C 9C56658E */  lw         $a1, %lo(D_800F569C)($s3)
    /* 6D320 800D5B20 00000000 */  nop
    /* 6D324 800D5B24 9000A28C */  lw         $v0, 0x90($a1)
    /* 6D328 800D5B28 2800B4AF */  sw         $s4, 0x28($sp)
    /* 6D32C 800D5B2C 2000A0AF */  sw         $zero, 0x20($sp)
    /* 6D330 800D5B30 2400A2AF */  sw         $v0, 0x24($sp)
    /* 6D334 800D5B34 D000A28C */  lw         $v0, 0xD0($a1)
    /* 6D338 800D5B38 00000000 */  nop
    /* 6D33C 800D5B3C 04004224 */  addiu      $v0, $v0, 0x4
    /* 6D340 800D5B40 1000A2AF */  sw         $v0, 0x10($sp)
    /* 6D344 800D5B44 D000A28C */  lw         $v0, 0xD0($a1)
    /* 6D348 800D5B48 00000000 */  nop
    /* 6D34C 800D5B4C 04004224 */  addiu      $v0, $v0, 0x4
    /* 6D350 800D5B50 1400A2AF */  sw         $v0, 0x14($sp)
    /* 6D354 800D5B54 0E000386 */  lh         $v1, 0xE($s0)
    /* 6D358 800D5B58 00000000 */  nop
    /* 6D35C 800D5B5C 40100300 */  sll        $v0, $v1, 1
    /* 6D360 800D5B60 21104300 */  addu       $v0, $v0, $v1
    /* 6D364 800D5B64 80100200 */  sll        $v0, $v0, 2
    /* 6D368 800D5B68 D000A38C */  lw         $v1, 0xD0($a1)
    /* 6D36C 800D5B6C 10004224 */  addiu      $v0, $v0, 0x10
    /* 6D370 800D5B70 21186200 */  addu       $v1, $v1, $v0
    /* 6D374 800D5B74 1800A3AF */  sw         $v1, 0x18($sp)
    /* 6D378 800D5B78 0E000486 */  lh         $a0, 0xE($s0)
    /* 6D37C 800D5B7C D000A38C */  lw         $v1, 0xD0($a1)
    /* 6D380 800D5B80 2C00B2AF */  sw         $s2, 0x2C($sp)
    /* 6D384 800D5B84 40100400 */  sll        $v0, $a0, 1
    /* 6D388 800D5B88 21104400 */  addu       $v0, $v0, $a0
    /* 6D38C 800D5B8C 80100200 */  sll        $v0, $v0, 2
    /* 6D390 800D5B90 10004224 */  addiu      $v0, $v0, 0x10
    /* 6D394 800D5B94 21186200 */  addu       $v1, $v1, $v0
    /* 6D398 800D5B98 1C00A3AF */  sw         $v1, 0x1C($sp)
    /* 6D39C 800D5B9C 14004292 */  lbu        $v0, 0x14($s2)
    /* 6D3A0 800D5BA0 1000A427 */  addiu      $a0, $sp, 0x10
    /* 6D3A4 800D5BA4 0F3A030C */  jal        func_800CE83C
    /* 6D3A8 800D5BA8 3000A2A3 */   sb        $v0, 0x30($sp)
    /* 6D3AC 800D5BAC FFFF043C */  lui        $a0, (0xFFFF07FF >> 16)
    /* 6D3B0 800D5BB0 1400438E */  lw         $v1, 0x14($s2)
    /* 6D3B4 800D5BB4 FF078434 */  ori        $a0, $a0, (0xFFFF07FF & 0xFFFF)
    /* 6D3B8 800D5BB8 24206400 */  and        $a0, $v1, $a0
    /* 6D3BC 800D5BBC C21A0300 */  srl        $v1, $v1, 11
    /* 6D3C0 800D5BC0 1F006330 */  andi       $v1, $v1, 0x1F
    /* 6D3C4 800D5BC4 01006324 */  addiu      $v1, $v1, 0x1
    /* 6D3C8 800D5BC8 1F006330 */  andi       $v1, $v1, 0x1F
    /* 6D3CC 800D5BCC C01A0300 */  sll        $v1, $v1, 11
    /* 6D3D0 800D5BD0 25208300 */  or         $a0, $a0, $v1
    /* 6D3D4 800D5BD4 140044AE */  sw         $a0, 0x14($s2)
    /* 6D3D8 800D5BD8 1800A58F */  lw         $a1, 0x18($sp)
    /* 6D3DC 800D5BDC 21204000 */  addu       $a0, $v0, $zero
    /* 6D3E0 800D5BE0 0000A394 */  lhu        $v1, 0x0($a1)
    /* 6D3E4 800D5BE4 04000224 */  addiu      $v0, $zero, 0x4
    /* 6D3E8 800D5BE8 07006214 */  bne        $v1, $v0, .L800D5C08
    /* 6D3EC 800D5BEC 00000000 */   nop
    /* 6D3F0 800D5BF0 0500A290 */  lbu        $v0, 0x5($a1)
    /* 6D3F4 800D5BF4 00000000 */  nop
    /* 6D3F8 800D5BF8 21102202 */  addu       $v0, $s1, $v0
    /* 6D3FC 800D5BFC 00004290 */  lbu        $v0, 0x0($v0)
    /* 6D400 800D5C00 05570308 */  j          .L800D5C14
    /* 6D404 800D5C04 110082A0 */   sb        $v0, 0x11($a0)
  .L800D5C08:
    /* 6D408 800D5C08 00002292 */  lbu        $v0, 0x0($s1)
    /* 6D40C 800D5C0C 00000000 */  nop
    /* 6D410 800D5C10 110082A0 */  sb         $v0, 0x11($a0)
  .L800D5C14:
    /* 6D414 800D5C14 0E000296 */  lhu        $v0, 0xE($s0)
    /* 6D418 800D5C18 9C56638E */  lw         $v1, %lo(D_800F569C)($s3)
    /* 6D41C 800D5C1C 01004224 */  addiu      $v0, $v0, 0x1
    /* 6D420 800D5C20 0E0002A6 */  sh         $v0, 0xE($s0)
    /* 6D424 800D5C24 D000638C */  lw         $v1, 0xD0($v1)
    /* 6D428 800D5C28 00140200 */  sll        $v0, $v0, 16
    /* 6D42C 800D5C2C 02006390 */  lbu        $v1, 0x2($v1)
    /* 6D430 800D5C30 03140200 */  sra        $v0, $v0, 16
    /* 6D434 800D5C34 09004310 */  beq        $v0, $v1, .L800D5C5C
    /* 6D438 800D5C38 00000000 */   nop
    /* 6D43C 800D5C3C 08002392 */  lbu        $v1, 0x8($s1)
    /* 6D440 800D5C40 0C000296 */  lhu        $v0, 0xC($s0)
    /* 6D444 800D5C44 00000000 */  nop
    /* 6D448 800D5C48 21104300 */  addu       $v0, $v0, $v1
    /* 6D44C 800D5C4C 0C0002A6 */  sh         $v0, 0xC($s0)
    /* 6D450 800D5C50 00140200 */  sll        $v0, $v0, 16
    /* 6D454 800D5C54 B1FF4010 */  beqz       $v0, .L800D5B1C
    /* 6D458 800D5C58 00000000 */   nop
  .L800D5C5C:
    /* 6D45C 800D5C5C 0C000286 */  lh         $v0, 0xC($s0)
    /* 6D460 800D5C60 00000000 */  nop
    /* 6D464 800D5C64 3A004010 */  beqz       $v0, .L800D5D50
    /* 6D468 800D5C68 2110A002 */   addu      $v0, $s5, $zero
  .L800D5C6C:
    /* 6D46C 800D5C6C 0C000296 */  lhu        $v0, 0xC($s0)
    /* 6D470 800D5C70 00000000 */  nop
    /* 6D474 800D5C74 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 6D478 800D5C78 53570308 */  j          .L800D5D4C
    /* 6D47C 800D5C7C 0C0002A6 */   sh        $v0, 0xC($s0)
  .L800D5C80:
    /* 6D480 800D5C80 31008314 */  bne        $a0, $v1, .L800D5D48
    /* 6D484 800D5C84 00000000 */   nop
    /* 6D488 800D5C88 1400428E */  lw         $v0, 0x14($s2)
    /* 6D48C 800D5C8C 00000000 */  nop
    /* 6D490 800D5C90 00F84230 */  andi       $v0, $v0, 0xF800
    /* 6D494 800D5C94 2E004014 */  bnez       $v0, .L800D5D50
    /* 6D498 800D5C98 2110A002 */   addu      $v0, $s5, $zero
    /* 6D49C 800D5C9C 9000A28C */  lw         $v0, 0x90($a1)
    /* 6D4A0 800D5CA0 2800B4AF */  sw         $s4, 0x28($sp)
    /* 6D4A4 800D5CA4 2000A0AF */  sw         $zero, 0x20($sp)
    /* 6D4A8 800D5CA8 2400A2AF */  sw         $v0, 0x24($sp)
    /* 6D4AC 800D5CAC D000A28C */  lw         $v0, 0xD0($a1)
    /* 6D4B0 800D5CB0 00000000 */  nop
    /* 6D4B4 800D5CB4 04004224 */  addiu      $v0, $v0, 0x4
    /* 6D4B8 800D5CB8 1000A2AF */  sw         $v0, 0x10($sp)
    /* 6D4BC 800D5CBC D000A28C */  lw         $v0, 0xD0($a1)
    /* 6D4C0 800D5CC0 00000000 */  nop
    /* 6D4C4 800D5CC4 04004224 */  addiu      $v0, $v0, 0x4
    /* 6D4C8 800D5CC8 1400A2AF */  sw         $v0, 0x14($sp)
    /* 6D4CC 800D5CCC D000A28C */  lw         $v0, 0xD0($a1)
    /* 6D4D0 800D5CD0 00000000 */  nop
    /* 6D4D4 800D5CD4 10004224 */  addiu      $v0, $v0, 0x10
    /* 6D4D8 800D5CD8 1800A2AF */  sw         $v0, 0x18($sp)
    /* 6D4DC 800D5CDC D000A28C */  lw         $v0, 0xD0($a1)
    /* 6D4E0 800D5CE0 2C00B2AF */  sw         $s2, 0x2C($sp)
    /* 6D4E4 800D5CE4 10004224 */  addiu      $v0, $v0, 0x10
    /* 6D4E8 800D5CE8 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 6D4EC 800D5CEC 14004292 */  lbu        $v0, 0x14($s2)
    /* 6D4F0 800D5CF0 1000A427 */  addiu      $a0, $sp, 0x10
    /* 6D4F4 800D5CF4 0F3A030C */  jal        func_800CE83C
    /* 6D4F8 800D5CF8 3000A2A3 */   sb        $v0, 0x30($sp)
    /* 6D4FC 800D5CFC FFFF043C */  lui        $a0, (0xFFFF07FF >> 16)
    /* 6D500 800D5D00 1400438E */  lw         $v1, 0x14($s2)
    /* 6D504 800D5D04 FF078434 */  ori        $a0, $a0, (0xFFFF07FF & 0xFFFF)
    /* 6D508 800D5D08 24206400 */  and        $a0, $v1, $a0
    /* 6D50C 800D5D0C C21A0300 */  srl        $v1, $v1, 11
    /* 6D510 800D5D10 1F006330 */  andi       $v1, $v1, 0x1F
    /* 6D514 800D5D14 01006324 */  addiu      $v1, $v1, 0x1
    /* 6D518 800D5D18 1F006330 */  andi       $v1, $v1, 0x1F
    /* 6D51C 800D5D1C C01A0300 */  sll        $v1, $v1, 11
    /* 6D520 800D5D20 25208300 */  or         $a0, $a0, $v1
    /* 6D524 800D5D24 140044AE */  sw         $a0, 0x14($s2)
    /* 6D528 800D5D28 06002392 */  lbu        $v1, 0x6($s1)
    /* 6D52C 800D5D2C 00000000 */  nop
    /* 6D530 800D5D30 110043A0 */  sb         $v1, 0x11($v0)
    /* 6D534 800D5D34 0E000296 */  lhu        $v0, 0xE($s0)
    /* 6D538 800D5D38 00000000 */  nop
    /* 6D53C 800D5D3C 01004224 */  addiu      $v0, $v0, 0x1
    /* 6D540 800D5D40 53570308 */  j          .L800D5D4C
    /* 6D544 800D5D44 0E0002A6 */   sh        $v0, 0xE($s0)
  .L800D5D48:
    /* 6D548 800D5D48 21A80000 */  addu       $s5, $zero, $zero
  .L800D5D4C:
    /* 6D54C 800D5D4C 2110A002 */  addu       $v0, $s5, $zero
  .L800D5D50:
    /* 6D550 800D5D50 5000BF8F */  lw         $ra, 0x50($sp)
    /* 6D554 800D5D54 4C00B58F */  lw         $s5, 0x4C($sp)
    /* 6D558 800D5D58 4800B48F */  lw         $s4, 0x48($sp)
    /* 6D55C 800D5D5C 4400B38F */  lw         $s3, 0x44($sp)
    /* 6D560 800D5D60 4000B28F */  lw         $s2, 0x40($sp)
    /* 6D564 800D5D64 3C00B18F */  lw         $s1, 0x3C($sp)
    /* 6D568 800D5D68 3800B08F */  lw         $s0, 0x38($sp)
    /* 6D56C 800D5D6C 0800E003 */  jr         $ra
    /* 6D570 800D5D70 5800BD27 */   addiu     $sp, $sp, 0x58
endlabel func_800D5A98
