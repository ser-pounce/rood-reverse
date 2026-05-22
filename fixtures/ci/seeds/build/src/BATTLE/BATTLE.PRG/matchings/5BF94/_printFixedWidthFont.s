nonmatching _printFixedWidthFont, 0x318

glabel _printFixedWidthFont
    /* 5F3A4 800C7BA4 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 5F3A8 800C7BA8 3000B4AF */  sw         $s4, 0x30($sp)
    /* 5F3AC 800C7BAC 21A08000 */  addu       $s4, $a0, $zero
    /* 5F3B0 800C7BB0 3C00B7AF */  sw         $s7, 0x3C($sp)
    /* 5F3B4 800C7BB4 21B8A000 */  addu       $s7, $a1, $zero
    /* 5F3B8 800C7BB8 3400B5AF */  sw         $s5, 0x34($sp)
    /* 5F3BC 800C7BBC 21A80000 */  addu       $s5, $zero, $zero
    /* 5F3C0 800C7BC0 40101700 */  sll        $v0, $s7, 1
    /* 5F3C4 800C7BC4 21105700 */  addu       $v0, $v0, $s7
    /* 5F3C8 800C7BC8 4400BFAF */  sw         $ra, 0x44($sp)
    /* 5F3CC 800C7BCC 4000BEAF */  sw         $fp, 0x40($sp)
    /* 5F3D0 800C7BD0 3800B6AF */  sw         $s6, 0x38($sp)
    /* 5F3D4 800C7BD4 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 5F3D8 800C7BD8 2800B2AF */  sw         $s2, 0x28($sp)
    /* 5F3DC 800C7BDC 2400B1AF */  sw         $s1, 0x24($sp)
    /* 5F3E0 800C7BE0 2000B0AF */  sw         $s0, 0x20($sp)
    /* 5F3E4 800C7BE4 0800908E */  lw         $s0, 0x8($s4)
    /* 5F3E8 800C7BE8 80900200 */  sll        $s2, $v0, 2
    /* 5F3EC 800C7BEC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5F3F0 800C7BF0 0C008296 */  lhu        $v0, 0xC($s4)
    /* 5F3F4 800C7BF4 21405702 */  addu       $t0, $s2, $s7
    /* 5F3F8 800C7BF8 A4004010 */  beqz       $v0, .L800C7E8C
    /* 5F3FC 800C7BFC 1C00A8AF */   sw        $t0, 0x1C($sp)
    /* 5F400 800C7C00 10008286 */  lh         $v0, 0x10($s4)
    /* 5F404 800C7C04 14008386 */  lh         $v1, 0x14($s4)
    /* 5F408 800C7C08 00000000 */  nop
    /* 5F40C 800C7C0C 23104300 */  subu       $v0, $v0, $v1
    /* 5F410 800C7C10 18005700 */  mult       $v0, $s7
    /* 5F414 800C7C14 0F80073C */  lui        $a3, %hi(D_800F4CB8)
    /* 5F418 800C7C18 16008486 */  lh         $a0, 0x16($s4)
    /* 5F41C 800C7C1C 00008292 */  lbu        $v0, 0x0($s4)
    /* 5F420 800C7C20 12008386 */  lh         $v1, 0x12($s4)
    /* 5F424 800C7C24 27100200 */  nor        $v0, $zero, $v0
    /* 5F428 800C7C28 01004230 */  andi       $v0, $v0, 0x1
    /* 5F42C 800C7C2C 80100200 */  sll        $v0, $v0, 2
    /* 5F430 800C7C30 23186400 */  subu       $v1, $v1, $a0
    /* 5F434 800C7C34 0F80043C */  lui        $a0, %hi(_fontTable)
    /* 5F438 800C7C38 B84CE2A0 */  sb         $v0, %lo(D_800F4CB8)($a3)
    /* 5F43C 800C7C3C 0000828E */  lw         $v0, 0x0($s4)
    /* 5F440 800C7C40 12280000 */  mflo       $a1
    /* 5F444 800C7C44 0F004230 */  andi       $v0, $v0, 0xF
    /* 5F448 800C7C48 04004238 */  xori       $v0, $v0, 0x4
    /* 5F44C 800C7C4C 18007700 */  mult       $v1, $s7
    /* 5F450 800C7C50 2B10A202 */  sltu       $v0, $s5, $v0
    /* 5F454 800C7C54 B94C82A0 */  sb         $v0, %lo(_fontTable)($a0)
    /* 5F458 800C7C58 1E008292 */  lbu        $v0, 0x1E($s4)
    /* 5F45C 800C7C5C 0F80063C */  lui        $a2, %hi(_fontBrightness)
    /* 5F460 800C7C60 BC4CC2AC */  sw         $v0, %lo(_fontBrightness)($a2)
    /* 5F464 800C7C64 26008286 */  lh         $v0, 0x26($s4)
    /* 5F468 800C7C68 24008386 */  lh         $v1, 0x24($s4)
    /* 5F46C 800C7C6C 00140200 */  sll        $v0, $v0, 16
    /* 5F470 800C7C70 001C0300 */  sll        $v1, $v1, 16
    /* 5F474 800C7C74 21286500 */  addu       $a1, $v1, $a1
    /* 5F478 800C7C78 12480000 */  mflo       $t1
    /* 5F47C 800C7C7C 21884900 */  addu       $s1, $v0, $t1
    /* 5F480 800C7C80 0000828E */  lw         $v0, 0x0($s4)
    /* 5F484 800C7C84 02000324 */  addiu      $v1, $zero, 0x2
    /* 5F488 800C7C88 0F004230 */  andi       $v0, $v0, 0xF
    /* 5F48C 800C7C8C 03004314 */  bne        $v0, $v1, .L800C7C9C
    /* 5F490 800C7C90 21B0A000 */   addu      $s6, $a1, $zero
    /* 5F494 800C7C94 B94C80A0 */  sb         $zero, %lo(_fontTable)($a0)
    /* 5F498 800C7C98 B84CE0A0 */  sb         $zero, %lo(D_800F4CB8)($a3)
  .L800C7C9C:
    /* 5F49C 800C7C9C 1E009392 */  lbu        $s3, 0x1E($s4)
    /* 5F4A0 800C7CA0 21F08000 */  addu       $fp, $a0, $zero
    /* 5F4A4 800C7CA4 00121300 */  sll        $v0, $s3, 8
    /* 5F4A8 800C7CA8 25106202 */  or         $v0, $s3, $v0
    /* 5F4AC 800C7CAC 001C1300 */  sll        $v1, $s3, 16
    /* 5F4B0 800C7CB0 21980000 */  addu       $s3, $zero, $zero
    /* 5F4B4 800C7CB4 25104300 */  or         $v0, $v0, $v1
    /* 5F4B8 800C7CB8 002C033C */  lui        $v1, (0x2C000000 >> 16)
    /* 5F4BC 800C7CBC 25104300 */  or         $v0, $v0, $v1
    /* 5F4C0 800C7CC0 BC4CC2AC */  sw         $v0, %lo(_fontBrightness)($a2)
  .L800C7CC4:
    /* 5F4C4 800C7CC4 00000492 */  lbu        $a0, 0x0($s0)
    /* 5F4C8 800C7CC8 00000000 */  nop
    /* 5F4CC 800C7CCC EC00822C */  sltiu      $v0, $a0, 0xEC
    /* 5F4D0 800C7CD0 28004010 */  beqz       $v0, .L800C7D74
    /* 5F4D4 800C7CD4 01001026 */   addiu     $s0, $s0, 0x1
    /* 5F4D8 800C7CD8 E500822C */  sltiu      $v0, $a0, 0xE5
    /* 5F4DC 800C7CDC 08004010 */  beqz       $v0, .L800C7D00
    /* 5F4E0 800C7CE0 21302002 */   addu      $a2, $s1, $zero
    /* 5F4E4 800C7CE4 1800A88F */  lw         $t0, 0x18($sp)
    /* 5F4E8 800C7CE8 21384002 */  addu       $a3, $s2, $zero
    /* 5F4EC 800C7CEC 1400B7AF */  sw         $s7, 0x14($sp)
    /* 5F4F0 800C7CF0 761E030C */  jal        _printFixedWidthFontChar
    /* 5F4F4 800C7CF4 1000A8AF */   sw        $t0, 0x10($sp)
    /* 5F4F8 800C7CF8 311F0308 */  j          .L800C7CC4
    /* 5F4FC 800C7CFC 21284000 */   addu      $a1, $v0, $zero
  .L800C7D00:
    /* 5F500 800C7D00 1BFF8224 */  addiu      $v0, $a0, -0xE5
    /* 5F504 800C7D04 02000824 */  addiu      $t0, $zero, 0x2
    /* 5F508 800C7D08 05004810 */  beq        $v0, $t0, .L800C7D20
    /* 5F50C 800C7D0C 03000824 */   addiu     $t0, $zero, 0x3
    /* 5F510 800C7D10 05004810 */  beq        $v0, $t0, .L800C7D28
    /* 5F514 800C7D14 00000000 */   nop
    /* 5F518 800C7D18 591F0308 */  j          .L800C7D64
    /* 5F51C 800C7D1C 00000000 */   nop
  .L800C7D20:
    /* 5F520 800C7D20 591F0308 */  j          .L800C7D64
    /* 5F524 800C7D24 01001324 */   addiu     $s3, $zero, 0x1
  .L800C7D28:
    /* 5F528 800C7D28 0B00A012 */  beqz       $s5, .L800C7D58
    /* 5F52C 800C7D2C 2128C002 */   addu      $a1, $s6, $zero
    /* 5F530 800C7D30 041C030C */  jal        vs_battle_getTextLineLength
    /* 5F534 800C7D34 21200002 */   addu      $a0, $s0, $zero
    /* 5F538 800C7D38 20008392 */  lbu        $v1, 0x20($s4)
    /* 5F53C 800C7D3C 00000000 */  nop
    /* 5F540 800C7D40 40180300 */  sll        $v1, $v1, 1
    /* 5F544 800C7D44 23186200 */  subu       $v1, $v1, $v0
    /* 5F548 800C7D48 83101200 */  sra        $v0, $s2, 2
    /* 5F54C 800C7D4C 18006200 */  mult       $v1, $v0
    /* 5F550 800C7D50 12400000 */  mflo       $t0
    /* 5F554 800C7D54 2128C802 */  addu       $a1, $s6, $t0
  .L800C7D58:
    /* 5F558 800C7D58 1C00A88F */  lw         $t0, 0x1C($sp)
    /* 5F55C 800C7D5C 00000000 */  nop
    /* 5F560 800C7D60 21882802 */  addu       $s1, $s1, $t0
  .L800C7D64:
    /* 5F564 800C7D64 49006016 */  bnez       $s3, .L800C7E8C
    /* 5F568 800C7D68 00000000 */   nop
    /* 5F56C 800C7D6C 311F0308 */  j          .L800C7CC4
    /* 5F570 800C7D70 00000000 */   nop
  .L800C7D74:
    /* 5F574 800C7D74 00000692 */  lbu        $a2, 0x0($s0)
    /* 5F578 800C7D78 08FF8224 */  addiu      $v0, $a0, -0xF8
    /* 5F57C 800C7D7C 02000824 */  addiu      $t0, $zero, 0x2
    /* 5F580 800C7D80 06004810 */  beq        $v0, $t0, .L800C7D9C
    /* 5F584 800C7D84 01001026 */   addiu     $s0, $s0, 0x1
    /* 5F588 800C7D88 03000824 */  addiu      $t0, $zero, 0x3
    /* 5F58C 800C7D8C 19004810 */  beq        $v0, $t0, .L800C7DF4
    /* 5F590 800C7D90 F800C230 */   andi      $v0, $a2, 0xF8
    /* 5F594 800C7D94 311F0308 */  j          .L800C7CC4
    /* 5F598 800C7D98 00000000 */   nop
  .L800C7D9C:
    /* 5F59C 800C7D9C F000C22C */  sltiu      $v0, $a2, 0xF0
    /* 5F5A0 800C7DA0 0C004014 */  bnez       $v0, .L800C7DD4
    /* 5F5A4 800C7DA4 1800D200 */   mult      $a2, $s2
    /* 5F5A8 800C7DA8 00010224 */  addiu      $v0, $zero, 0x100
    /* 5F5AC 800C7DAC 23104600 */  subu       $v0, $v0, $a2
    /* 5F5B0 800C7DB0 18005200 */  mult       $v0, $s2
    /* 5F5B4 800C7DB4 12180000 */  mflo       $v1
    /* 5F5B8 800C7DB8 AAAA023C */  lui        $v0, (0xAAAAAAAB >> 16)
    /* 5F5BC 800C7DBC ABAA4234 */  ori        $v0, $v0, (0xAAAAAAAB & 0xFFFF)
    /* 5F5C0 800C7DC0 19006200 */  multu      $v1, $v0
    /* 5F5C4 800C7DC4 10180000 */  mfhi       $v1
    /* 5F5C8 800C7DC8 C2100300 */  srl        $v0, $v1, 3
    /* 5F5CC 800C7DCC 311F0308 */  j          .L800C7CC4
    /* 5F5D0 800C7DD0 2328A200 */   subu      $a1, $a1, $v0
  .L800C7DD4:
    /* 5F5D4 800C7DD4 12180000 */  mflo       $v1
    /* 5F5D8 800C7DD8 AAAA023C */  lui        $v0, (0xAAAAAAAB >> 16)
    /* 5F5DC 800C7DDC ABAA4234 */  ori        $v0, $v0, (0xAAAAAAAB & 0xFFFF)
    /* 5F5E0 800C7DE0 19006200 */  multu      $v1, $v0
    /* 5F5E4 800C7DE4 10180000 */  mfhi       $v1
    /* 5F5E8 800C7DE8 C2100300 */  srl        $v0, $v1, 3
    /* 5F5EC 800C7DEC 311F0308 */  j          .L800C7CC4
    /* 5F5F0 800C7DF0 2128A200 */   addu      $a1, $a1, $v0
  .L800C7DF4:
    /* 5F5F4 800C7DF4 05004010 */  beqz       $v0, .L800C7E0C
    /* 5F5F8 800C7DF8 C2100600 */   srl       $v0, $a2, 3
    /* 5F5FC 800C7DFC 18005700 */  mult       $v0, $s7
    /* 5F600 800C7E00 12400000 */  mflo       $t0
    /* 5F604 800C7E04 311F0308 */  j          .L800C7CC4
    /* 5F608 800C7E08 21882802 */   addu      $s1, $s1, $t0
  .L800C7E0C:
    /* 5F60C 800C7E0C 06000224 */  addiu      $v0, $zero, 0x6
    /* 5F610 800C7E10 0300C214 */  bne        $a2, $v0, .L800C7E20
    /* 5F614 800C7E14 05000224 */   addiu     $v0, $zero, 0x5
    /* 5F618 800C7E18 311F0308 */  j          .L800C7CC4
    /* 5F61C 800C7E1C B94CC0A3 */   sb        $zero, %lo(_fontTable)($fp)
  .L800C7E20:
    /* 5F620 800C7E20 0400C214 */  bne        $a2, $v0, .L800C7E34
    /* 5F624 800C7E24 04000224 */   addiu     $v0, $zero, 0x4
    /* 5F628 800C7E28 01000224 */  addiu      $v0, $zero, 0x1
    /* 5F62C 800C7E2C 311F0308 */  j          .L800C7CC4
    /* 5F630 800C7E30 B94CC2A3 */   sb        $v0, %lo(_fontTable)($fp)
  .L800C7E34:
    /* 5F634 800C7E34 0F00C214 */  bne        $a2, $v0, .L800C7E74
    /* 5F638 800C7E38 0F80033C */   lui       $v1, %hi(D_800F4CB8)
    /* 5F63C 800C7E3C 0100B53A */  xori       $s5, $s5, 0x1
    /* 5F640 800C7E40 A0FFA012 */  beqz       $s5, .L800C7CC4
    /* 5F644 800C7E44 00000000 */   nop
    /* 5F648 800C7E48 041C030C */  jal        vs_battle_getTextLineLength
    /* 5F64C 800C7E4C 21200002 */   addu      $a0, $s0, $zero
    /* 5F650 800C7E50 20008392 */  lbu        $v1, 0x20($s4)
    /* 5F654 800C7E54 00000000 */  nop
    /* 5F658 800C7E58 40180300 */  sll        $v1, $v1, 1
    /* 5F65C 800C7E5C 23186200 */  subu       $v1, $v1, $v0
    /* 5F660 800C7E60 83101200 */  sra        $v0, $s2, 2
    /* 5F664 800C7E64 18006200 */  mult       $v1, $v0
    /* 5F668 800C7E68 12400000 */  mflo       $t0
    /* 5F66C 800C7E6C 311F0308 */  j          .L800C7CC4
    /* 5F670 800C7E70 2128C802 */   addu      $a1, $s6, $t0
  .L800C7E74:
    /* 5F674 800C7E74 B84C6290 */  lbu        $v0, %lo(D_800F4CB8)($v1)
    /* 5F678 800C7E78 00000000 */  nop
    /* 5F67C 800C7E7C 04004230 */  andi       $v0, $v0, 0x4
    /* 5F680 800C7E80 25104600 */  or         $v0, $v0, $a2
    /* 5F684 800C7E84 311F0308 */  j          .L800C7CC4
    /* 5F688 800C7E88 B84C62A0 */   sb        $v0, %lo(D_800F4CB8)($v1)
  .L800C7E8C:
    /* 5F68C 800C7E8C 4400BF8F */  lw         $ra, 0x44($sp)
    /* 5F690 800C7E90 4000BE8F */  lw         $fp, 0x40($sp)
    /* 5F694 800C7E94 3C00B78F */  lw         $s7, 0x3C($sp)
    /* 5F698 800C7E98 3800B68F */  lw         $s6, 0x38($sp)
    /* 5F69C 800C7E9C 3400B58F */  lw         $s5, 0x34($sp)
    /* 5F6A0 800C7EA0 3000B48F */  lw         $s4, 0x30($sp)
    /* 5F6A4 800C7EA4 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 5F6A8 800C7EA8 2800B28F */  lw         $s2, 0x28($sp)
    /* 5F6AC 800C7EAC 2400B18F */  lw         $s1, 0x24($sp)
    /* 5F6B0 800C7EB0 2000B08F */  lw         $s0, 0x20($sp)
    /* 5F6B4 800C7EB4 0800E003 */  jr         $ra
    /* 5F6B8 800C7EB8 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel _printFixedWidthFont
