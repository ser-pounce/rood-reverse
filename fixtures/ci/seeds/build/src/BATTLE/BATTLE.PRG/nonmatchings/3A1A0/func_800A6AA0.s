nonmatching func_800A6AA0, 0x448

glabel func_800A6AA0
    /* 3E2A0 800A6AA0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 3E2A4 800A6AA4 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 3E2A8 800A6AA8 21888000 */  addu       $s1, $a0, $zero
    /* 3E2AC 800A6AAC 2000BFAF */  sw         $ra, 0x20($sp)
    /* 3E2B0 800A6AB0 1800B0AF */  sw         $s0, 0x18($sp)
    /* 3E2B4 800A6AB4 B8052492 */  lbu        $a0, 0x5B8($s1)
    /* 3E2B8 800A6AB8 00000000 */  nop
    /* 3E2BC 800A6ABC 64008228 */  slti       $v0, $a0, 0x64
    /* 3E2C0 800A6AC0 02004014 */  bnez       $v0, .L800A6ACC
    /* 3E2C4 800A6AC4 00000000 */   nop
    /* 3E2C8 800A6AC8 9CFF8424 */  addiu      $a0, $a0, -0x64
  .L800A6ACC:
    /* 3E2CC 800A6ACC 48182392 */  lbu        $v1, 0x1848($s1)
    /* 3E2D0 800A6AD0 01000224 */  addiu      $v0, $zero, 0x1
    /* 3E2D4 800A6AD4 0B006214 */  bne        $v1, $v0, .L800A6B04
    /* 3E2D8 800A6AD8 21300000 */   addu      $a2, $zero, $zero
    /* 3E2DC 800A6ADC 4E182286 */  lh         $v0, 0x184E($s1)
    /* 3E2E0 800A6AE0 4C182386 */  lh         $v1, 0x184C($s1)
    /* 3E2E4 800A6AE4 00000000 */  nop
    /* 3E2E8 800A6AE8 23104300 */  subu       $v0, $v0, $v1
    /* 3E2EC 800A6AEC 00024624 */  addiu      $a2, $v0, 0x200
    /* 3E2F0 800A6AF0 FF0FC630 */  andi       $a2, $a2, 0xFFF
    /* 3E2F4 800A6AF4 0200C104 */  bgez       $a2, .L800A6B00
    /* 3E2F8 800A6AF8 2110C000 */   addu      $v0, $a2, $zero
    /* 3E2FC 800A6AFC FF03C224 */  addiu      $v0, $a2, 0x3FF
  .L800A6B00:
    /* 3E300 800A6B00 83320200 */  sra        $a2, $v0, 10
  .L800A6B04:
    /* 3E304 800A6B04 AC05278E */  lw         $a3, 0x5AC($s1)
    /* 3E308 800A6B08 00000000 */  nop
    /* 3E30C 800A6B0C 0800E230 */  andi       $v0, $a3, 0x8
    /* 3E310 800A6B10 0C004010 */  beqz       $v0, .L800A6B44
    /* 3E314 800A6B14 4000033C */   lui       $v1, (0x400000 >> 16)
    /* 3E318 800A6B18 0300A018 */  blez       $a1, .L800A6B28
    /* 3E31C 800A6B1C 54001024 */   addiu     $s0, $zero, 0x54
    /* 3E320 800A6B20 CC9A0208 */  j          .L800A6B30
    /* 3E324 800A6B24 04000724 */   addiu     $a3, $zero, 0x4
  .L800A6B28:
    /* 3E328 800A6B28 4B001024 */  addiu      $s0, $zero, 0x4B
    /* 3E32C 800A6B2C 0A000724 */  addiu      $a3, $zero, 0xA
  .L800A6B30:
    /* 3E330 800A6B30 5F000224 */  addiu      $v0, $zero, 0x5F
    /* 3E334 800A6B34 E6008210 */  beq        $a0, $v0, .L800A6ED0
    /* 3E338 800A6B38 00000000 */   nop
    /* 3E33C 800A6B3C E69A0208 */  j          .L800A6B98
    /* 3E340 800A6B40 00000000 */   nop
  .L800A6B44:
    /* 3E344 800A6B44 0800228E */  lw         $v0, 0x8($s1)
    /* 3E348 800A6B48 00000000 */  nop
    /* 3E34C 800A6B4C 24104300 */  and        $v0, $v0, $v1
    /* 3E350 800A6B50 17004010 */  beqz       $v0, .L800A6BB0
    /* 3E354 800A6B54 0080E230 */   andi      $v0, $a3, 0x8000
    /* 3E358 800A6B58 B9052292 */  lbu        $v0, 0x5B9($s1)
    /* 3E35C 800A6B5C 00000000 */  nop
    /* 3E360 800A6B60 2A10A200 */  slt        $v0, $a1, $v0
    /* 3E364 800A6B64 03004014 */  bnez       $v0, .L800A6B74
    /* 3E368 800A6B68 0F80023C */   lui       $v0, %hi(D_800E90D0)
    /* 3E36C 800A6B6C E09A0208 */  j          .L800A6B80
    /* 3E370 800A6B70 D0904224 */   addiu     $v0, $v0, %lo(D_800E90D0)
  .L800A6B74:
    /* 3E374 800A6B74 0600A018 */  blez       $a1, .L800A6B90
    /* 3E378 800A6B78 0F80023C */   lui       $v0, %hi(D_800E90CC)
    /* 3E37C 800A6B7C CC904224 */  addiu      $v0, $v0, %lo(D_800E90CC)
  .L800A6B80:
    /* 3E380 800A6B80 2110C200 */  addu       $v0, $a2, $v0
    /* 3E384 800A6B84 00005090 */  lbu        $s0, 0x0($v0)
    /* 3E388 800A6B88 E69A0208 */  j          .L800A6B98
    /* 3E38C 800A6B8C 14000724 */   addiu     $a3, $zero, 0x14
  .L800A6B90:
    /* 3E390 800A6B90 01001024 */  addiu      $s0, $zero, 0x1
    /* 3E394 800A6B94 0A000724 */  addiu      $a3, $zero, 0xA
  .L800A6B98:
    /* 3E398 800A6B98 0F002492 */  lbu        $a0, 0xF($s1)
    /* 3E39C 800A6B9C 21280002 */  addu       $a1, $s0, $zero
    /* 3E3A0 800A6BA0 8180020C */  jal        func_800A0204
    /* 3E3A4 800A6BA4 21300000 */   addu      $a2, $zero, $zero
    /* 3E3A8 800A6BA8 B49B0208 */  j          .L800A6ED0
    /* 3E3AC 800A6BAC 00000000 */   nop
  .L800A6BB0:
    /* 3E3B0 800A6BB0 23004010 */  beqz       $v0, .L800A6C40
    /* 3E3B4 800A6BB4 E7FF8224 */   addiu     $v0, $a0, -0x19
    /* 3E3B8 800A6BB8 0200422C */  sltiu      $v0, $v0, 0x2
    /* 3E3BC 800A6BBC C4004014 */  bnez       $v0, .L800A6ED0
    /* 3E3C0 800A6BC0 00000000 */   nop
    /* 3E3C4 800A6BC4 EEFF8224 */  addiu      $v0, $a0, -0x12
    /* 3E3C8 800A6BC8 0200422C */  sltiu      $v0, $v0, 0x2
    /* 3E3CC 800A6BCC 0C004014 */  bnez       $v0, .L800A6C00
    /* 3E3D0 800A6BD0 1A001024 */   addiu     $s0, $zero, 0x1A
    /* 3E3D4 800A6BD4 14000224 */  addiu      $v0, $zero, 0x14
    /* 3E3D8 800A6BD8 03008210 */  beq        $a0, $v0, .L800A6BE8
    /* 3E3DC 800A6BDC 11000224 */   addiu     $v0, $zero, 0x11
    /* 3E3E0 800A6BE0 03008214 */  bne        $a0, $v0, .L800A6BF0
    /* 3E3E4 800A6BE4 FFFF023C */   lui       $v0, (0xFFFF7FFF >> 16)
  .L800A6BE8:
    /* 3E3E8 800A6BE8 009B0208 */  j          .L800A6C00
    /* 3E3EC 800A6BEC 19001024 */   addiu     $s0, $zero, 0x19
  .L800A6BF0:
    /* 3E3F0 800A6BF0 FF7F4234 */  ori        $v0, $v0, (0xFFFF7FFF & 0xFFFF)
    /* 3E3F4 800A6BF4 2410E200 */  and        $v0, $a3, $v0
    /* 3E3F8 800A6BF8 B49B0208 */  j          .L800A6ED0
    /* 3E3FC 800A6BFC AC0522AE */   sw        $v0, 0x5AC($s1)
  .L800A6C00:
    /* 3E400 800A6C00 21202002 */  addu       $a0, $s1, $zero
    /* 3E404 800A6C04 21280002 */  addu       $a1, $s0, $zero
    /* 3E408 800A6C08 25B5020C */  jal        func_800AD494
    /* 3E40C 800A6C0C 1000A627 */   addiu     $a2, $sp, 0x10
    /* 3E410 800A6C10 1000A28F */  lw         $v0, 0x10($sp)
    /* 3E414 800A6C14 00000000 */  nop
    /* 3E418 800A6C18 02004014 */  bnez       $v0, .L800A6C24
    /* 3E41C 800A6C1C 00000000 */   nop
    /* 3E420 800A6C20 06001024 */  addiu      $s0, $zero, 0x6
  .L800A6C24:
    /* 3E424 800A6C24 0F002492 */  lbu        $a0, 0xF($s1)
    /* 3E428 800A6C28 21280002 */  addu       $a1, $s0, $zero
    /* 3E42C 800A6C2C 21300000 */  addu       $a2, $zero, $zero
    /* 3E430 800A6C30 8180020C */  jal        func_800A0204
    /* 3E434 800A6C34 08000724 */   addiu     $a3, $zero, 0x8
    /* 3E438 800A6C38 B49B0208 */  j          .L800A6ED0
    /* 3E43C 800A6C3C 00000000 */   nop
  .L800A6C40:
    /* 3E440 800A6C40 B9052292 */  lbu        $v0, 0x5B9($s1)
    /* 3E444 800A6C44 00000000 */  nop
    /* 3E448 800A6C48 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 3E44C 800A6C4C 2A10A200 */  slt        $v0, $a1, $v0
    /* 3E450 800A6C50 2F004014 */  bnez       $v0, .L800A6D10
    /* 3E454 800A6C54 EDFF8224 */   addiu     $v0, $a0, -0x13
    /* 3E458 800A6C58 0200422C */  sltiu      $v0, $v0, 0x2
    /* 3E45C 800A6C5C 9C004014 */  bnez       $v0, .L800A6ED0
    /* 3E460 800A6C60 00000000 */   nop
    /* 3E464 800A6C64 F1FF8224 */  addiu      $v0, $a0, -0xF
    /* 3E468 800A6C68 0400422C */  sltiu      $v0, $v0, 0x4
    /* 3E46C 800A6C6C 0E004014 */  bnez       $v0, .L800A6CA8
    /* 3E470 800A6C70 FFFD033C */   lui       $v1, (0xFDFFFFFF >> 16)
    /* 3E474 800A6C74 D2FF8224 */  addiu      $v0, $a0, -0x2E
    /* 3E478 800A6C78 0B00422C */  sltiu      $v0, $v0, 0xB
    /* 3E47C 800A6C7C 0B004014 */  bnez       $v0, .L800A6CAC
    /* 3E480 800A6C80 FFFF6334 */   ori       $v1, $v1, (0xFDFFFFFF & 0xFFFF)
    /* 3E484 800A6C84 F7FF8224 */  addiu      $v0, $a0, -0x9
    /* 3E488 800A6C88 0400422C */  sltiu      $v0, $v0, 0x4
    /* 3E48C 800A6C8C 05004014 */  bnez       $v0, .L800A6CA4
    /* 3E490 800A6C90 01000224 */   addiu     $v0, $zero, 0x1
    /* 3E494 800A6C94 03008210 */  beq        $a0, $v0, .L800A6CA4
    /* 3E498 800A6C98 06000224 */   addiu     $v0, $zero, 0x6
    /* 3E49C 800A6C9C 12008214 */  bne        $a0, $v0, .L800A6CE8
    /* 3E4A0 800A6CA0 0D000224 */   addiu     $v0, $zero, 0xD
  .L800A6CA4:
    /* 3E4A4 800A6CA4 FFFD033C */  lui        $v1, (0xFDFFFFFF >> 16)
  .L800A6CA8:
    /* 3E4A8 800A6CA8 FFFF6334 */  ori        $v1, $v1, (0xFDFFFFFF & 0xFFFF)
  .L800A6CAC:
    /* 3E4AC 800A6CAC 21300000 */  addu       $a2, $zero, $zero
    /* 3E4B0 800A6CB0 06000724 */  addiu      $a3, $zero, 0x6
    /* 3E4B4 800A6CB4 AC05258E */  lw         $a1, 0x5AC($s1)
    /* 3E4B8 800A6CB8 0F002492 */  lbu        $a0, 0xF($s1)
    /* 3E4BC 800A6CBC 2418A300 */  and        $v1, $a1, $v1
    /* 3E4C0 800A6CC0 422E0500 */  srl        $a1, $a1, 25
    /* 3E4C4 800A6CC4 0100A530 */  andi       $a1, $a1, 0x1
    /* 3E4C8 800A6CC8 0100A238 */  xori       $v0, $a1, 0x1
    /* 3E4CC 800A6CCC 40160200 */  sll        $v0, $v0, 25
    /* 3E4D0 800A6CD0 25186200 */  or         $v1, $v1, $v0
    /* 3E4D4 800A6CD4 1300A524 */  addiu      $a1, $a1, 0x13
    /* 3E4D8 800A6CD8 8180020C */  jal        func_800A0204
    /* 3E4DC 800A6CDC AC0523AE */   sw        $v1, 0x5AC($s1)
    /* 3E4E0 800A6CE0 B49B0208 */  j          .L800A6ED0
    /* 3E4E4 800A6CE4 00000000 */   nop
  .L800A6CE8:
    /* 3E4E8 800A6CE8 04008210 */  beq        $a0, $v0, .L800A6CFC
    /* 3E4EC 800A6CEC 13001024 */   addiu     $s0, $zero, 0x13
    /* 3E4F0 800A6CF0 0F000224 */  addiu      $v0, $zero, 0xF
    /* 3E4F4 800A6CF4 02008214 */  bne        $a0, $v0, .L800A6D00
    /* 3E4F8 800A6CF8 00000000 */   nop
  .L800A6CFC:
    /* 3E4FC 800A6CFC 14001024 */  addiu      $s0, $zero, 0x14
  .L800A6D00:
    /* 3E500 800A6D00 0F002492 */  lbu        $a0, 0xF($s1)
    /* 3E504 800A6D04 21280002 */  addu       $a1, $s0, $zero
    /* 3E508 800A6D08 959B0208 */  j          .L800A6E54
    /* 3E50C 800A6D0C 04000624 */   addiu     $a2, $zero, 0x4
  .L800A6D10:
    /* 3E510 800A6D10 4500A018 */  blez       $a1, .L800A6E28
    /* 3E514 800A6D14 D2FF8224 */   addiu     $v0, $a0, -0x2E
    /* 3E518 800A6D18 0B00422C */  sltiu      $v0, $v0, 0xB
    /* 3E51C 800A6D1C 1C004014 */  bnez       $v0, .L800A6D90
    /* 3E520 800A6D20 F7FF8224 */   addiu     $v0, $a0, -0x9
    /* 3E524 800A6D24 0400422C */  sltiu      $v0, $v0, 0x4
    /* 3E528 800A6D28 19004014 */  bnez       $v0, .L800A6D90
    /* 3E52C 800A6D2C F3FF8224 */   addiu     $v0, $a0, -0xD
    /* 3E530 800A6D30 0200422C */  sltiu      $v0, $v0, 0x2
    /* 3E534 800A6D34 05004010 */  beqz       $v0, .L800A6D4C
    /* 3E538 800A6D38 02000224 */   addiu     $v0, $zero, 0x2
    /* 3E53C 800A6D3C 6400C214 */  bne        $a2, $v0, .L800A6ED0
    /* 3E540 800A6D40 FFFD043C */   lui       $a0, (0xFDFFFFFF >> 16)
    /* 3E544 800A6D44 659B0208 */  j          .L800A6D94
    /* 3E548 800A6D48 00000000 */   nop
  .L800A6D4C:
    /* 3E54C 800A6D4C F1FF8224 */  addiu      $v0, $a0, -0xF
    /* 3E550 800A6D50 0200422C */  sltiu      $v0, $v0, 0x2
    /* 3E554 800A6D54 05004010 */  beqz       $v0, .L800A6D6C
    /* 3E558 800A6D58 02000224 */   addiu     $v0, $zero, 0x2
    /* 3E55C 800A6D5C 5C00C210 */  beq        $a2, $v0, .L800A6ED0
    /* 3E560 800A6D60 FFFD043C */   lui       $a0, (0xFDFFFFFF >> 16)
    /* 3E564 800A6D64 659B0208 */  j          .L800A6D94
    /* 3E568 800A6D68 00000000 */   nop
  .L800A6D6C:
    /* 3E56C 800A6D6C 01000224 */  addiu      $v0, $zero, 0x1
    /* 3E570 800A6D70 07008210 */  beq        $a0, $v0, .L800A6D90
    /* 3E574 800A6D74 06000224 */   addiu     $v0, $zero, 0x6
    /* 3E578 800A6D78 05008210 */  beq        $a0, $v0, .L800A6D90
    /* 3E57C 800A6D7C 11000224 */   addiu     $v0, $zero, 0x11
    /* 3E580 800A6D80 03008210 */  beq        $a0, $v0, .L800A6D90
    /* 3E584 800A6D84 12000224 */   addiu     $v0, $zero, 0x12
    /* 3E588 800A6D88 17008214 */  bne        $a0, $v0, .L800A6DE8
    /* 3E58C 800A6D8C 13000224 */   addiu     $v0, $zero, 0x13
  .L800A6D90:
    /* 3E590 800A6D90 FFFD043C */  lui        $a0, (0xFDFFFFFF >> 16)
  .L800A6D94:
    /* 3E594 800A6D94 AC05238E */  lw         $v1, 0x5AC($s1)
    /* 3E598 800A6D98 FFFF8434 */  ori        $a0, $a0, (0xFDFFFFFF & 0xFFFF)
    /* 3E59C 800A6D9C 42160300 */  srl        $v0, $v1, 25
    /* 3E5A0 800A6DA0 01004230 */  andi       $v0, $v0, 0x1
    /* 3E5A4 800A6DA4 FF004530 */  andi       $a1, $v0, 0xFF
    /* 3E5A8 800A6DA8 0D00B024 */  addiu      $s0, $a1, 0xD
    /* 3E5AC 800A6DAC 24186400 */  and        $v1, $v1, $a0
    /* 3E5B0 800A6DB0 01004238 */  xori       $v0, $v0, 0x1
    /* 3E5B4 800A6DB4 40160200 */  sll        $v0, $v0, 25
    /* 3E5B8 800A6DB8 25186200 */  or         $v1, $v1, $v0
    /* 3E5BC 800A6DBC 02000224 */  addiu      $v0, $zero, 0x2
    /* 3E5C0 800A6DC0 0200C214 */  bne        $a2, $v0, .L800A6DCC
    /* 3E5C4 800A6DC4 AC0523AE */   sw        $v1, 0x5AC($s1)
    /* 3E5C8 800A6DC8 0F00B024 */  addiu      $s0, $a1, 0xF
  .L800A6DCC:
    /* 3E5CC 800A6DCC 0F002492 */  lbu        $a0, 0xF($s1)
    /* 3E5D0 800A6DD0 21280002 */  addu       $a1, $s0, $zero
    /* 3E5D4 800A6DD4 21300000 */  addu       $a2, $zero, $zero
    /* 3E5D8 800A6DD8 8180020C */  jal        func_800A0204
    /* 3E5DC 800A6DDC 06000724 */   addiu     $a3, $zero, 0x6
    /* 3E5E0 800A6DE0 B49B0208 */  j          .L800A6ED0
    /* 3E5E4 800A6DE4 00000000 */   nop
  .L800A6DE8:
    /* 3E5E8 800A6DE8 06008210 */  beq        $a0, $v0, .L800A6E04
    /* 3E5EC 800A6DEC 0D001024 */   addiu     $s0, $zero, 0xD
    /* 3E5F0 800A6DF0 0F000224 */  addiu      $v0, $zero, 0xF
    /* 3E5F4 800A6DF4 03008210 */  beq        $a0, $v0, .L800A6E04
    /* 3E5F8 800A6DF8 00000000 */   nop
    /* 3E5FC 800A6DFC 03009014 */  bne        $a0, $s0, .L800A6E0C
    /* 3E600 800A6E00 02000224 */   addiu     $v0, $zero, 0x2
  .L800A6E04:
    /* 3E604 800A6E04 01001026 */  addiu      $s0, $s0, 0x1
    /* 3E608 800A6E08 02000224 */  addiu      $v0, $zero, 0x2
  .L800A6E0C:
    /* 3E60C 800A6E0C 0200C214 */  bne        $a2, $v0, .L800A6E18
    /* 3E610 800A6E10 00000000 */   nop
    /* 3E614 800A6E14 02001026 */  addiu      $s0, $s0, 0x2
  .L800A6E18:
    /* 3E618 800A6E18 0F002492 */  lbu        $a0, 0xF($s1)
    /* 3E61C 800A6E1C 21280002 */  addu       $a1, $s0, $zero
    /* 3E620 800A6E20 959B0208 */  j          .L800A6E54
    /* 3E624 800A6E24 04000624 */   addiu     $a2, $zero, 0x4
  .L800A6E28:
    /* 3E628 800A6E28 F3FF8224 */  addiu      $v0, $a0, -0xD
    /* 3E62C 800A6E2C 0400422C */  sltiu      $v0, $v0, 0x4
    /* 3E630 800A6E30 0C004010 */  beqz       $v0, .L800A6E64
    /* 3E634 800A6E34 06000524 */   addiu     $a1, $zero, 0x6
    /* 3E638 800A6E38 21300000 */  addu       $a2, $zero, $zero
    /* 3E63C 800A6E3C 0F002492 */  lbu        $a0, 0xF($s1)
    /* 3E640 800A6E40 8180020C */  jal        func_800A0204
    /* 3E644 800A6E44 0A000724 */   addiu     $a3, $zero, 0xA
    /* 3E648 800A6E48 01000524 */  addiu      $a1, $zero, 0x1
    /* 3E64C 800A6E4C 0A000624 */  addiu      $a2, $zero, 0xA
    /* 3E650 800A6E50 0F002492 */  lbu        $a0, 0xF($s1)
  .L800A6E54:
    /* 3E654 800A6E54 7280020C */  jal        func_800A01C8
    /* 3E658 800A6E58 21380000 */   addu      $a3, $zero, $zero
    /* 3E65C 800A6E5C B49B0208 */  j          .L800A6ED0
    /* 3E660 800A6E60 00000000 */   nop
  .L800A6E64:
    /* 3E664 800A6E64 01000224 */  addiu      $v0, $zero, 0x1
    /* 3E668 800A6E68 0A008210 */  beq        $a0, $v0, .L800A6E94
    /* 3E66C 800A6E6C 06000224 */   addiu     $v0, $zero, 0x6
    /* 3E670 800A6E70 48182392 */  lbu        $v1, 0x1848($s1)
    /* 3E674 800A6E74 00000000 */  nop
    /* 3E678 800A6E78 06006210 */  beq        $v1, $v0, .L800A6E94
    /* 3E67C 800A6E7C 01000524 */   addiu     $a1, $zero, 0x1
    /* 3E680 800A6E80 21300000 */  addu       $a2, $zero, $zero
    /* 3E684 800A6E84 0F002492 */  lbu        $a0, 0xF($s1)
    /* 3E688 800A6E88 8180020C */  jal        func_800A0204
    /* 3E68C 800A6E8C 0A000724 */   addiu     $a3, $zero, 0xA
    /* 3E690 800A6E90 B30520A2 */  sb         $zero, 0x5B3($s1)
  .L800A6E94:
    /* 3E694 800A6E94 0680023C */  lui        $v0, %hi(vs_gametime_tickspeed)
    /* 3E698 800A6E98 4CE2438C */  lw         $v1, %lo(vs_gametime_tickspeed)($v0)
    /* 3E69C 800A6E9C 00000000 */  nop
    /* 3E6A0 800A6EA0 C2170300 */  srl        $v0, $v1, 31
    /* 3E6A4 800A6EA4 21186200 */  addu       $v1, $v1, $v0
    /* 3E6A8 800A6EA8 B3052292 */  lbu        $v0, 0x5B3($s1)
    /* 3E6AC 800A6EAC 43180300 */  sra        $v1, $v1, 1
    /* 3E6B0 800A6EB0 21104300 */  addu       $v0, $v0, $v1
    /* 3E6B4 800A6EB4 B30522A2 */  sb         $v0, 0x5B3($s1)
    /* 3E6B8 800A6EB8 FF004230 */  andi       $v0, $v0, 0xFF
    /* 3E6BC 800A6EBC FA00422C */  sltiu      $v0, $v0, 0xFA
    /* 3E6C0 800A6EC0 03004014 */  bnez       $v0, .L800A6ED0
    /* 3E6C4 800A6EC4 00000000 */   nop
    /* 3E6C8 800A6EC8 FA000224 */  addiu      $v0, $zero, 0xFA
    /* 3E6CC 800A6ECC B30522A2 */  sb         $v0, 0x5B3($s1)
  .L800A6ED0:
    /* 3E6D0 800A6ED0 2000BF8F */  lw         $ra, 0x20($sp)
    /* 3E6D4 800A6ED4 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 3E6D8 800A6ED8 1800B08F */  lw         $s0, 0x18($sp)
    /* 3E6DC 800A6EDC 2800BD27 */  addiu      $sp, $sp, 0x28
    /* 3E6E0 800A6EE0 0800E003 */  jr         $ra
    /* 3E6E4 800A6EE4 00000000 */   nop
endlabel func_800A6AA0
