nonmatching func_80076D50, 0x1D4

glabel func_80076D50
    /* E550 80076D50 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* E554 80076D54 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* E558 80076D58 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* E55C 80076D5C 80100400 */  sll        $v0, $a0, 2
    /* E560 80076D60 21104300 */  addu       $v0, $v0, $v1
    /* E564 80076D64 2000BFAF */  sw         $ra, 0x20($sp)
    /* E568 80076D68 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* E56C 80076D6C 1800B2AF */  sw         $s2, 0x18($sp)
    /* E570 80076D70 1400B1AF */  sw         $s1, 0x14($sp)
    /* E574 80076D74 1000B0AF */  sw         $s0, 0x10($sp)
    /* E578 80076D78 0000518C */  lw         $s1, 0x0($v0)
    /* E57C 80076D7C 3800B38F */  lw         $s3, 0x38($sp)
    /* E580 80076D80 3C00308E */  lw         $s0, 0x3C($s1)
    /* E584 80076D84 2190A000 */  addu       $s2, $a1, $zero
    /* E588 80076D88 040024AE */  sw         $a0, 0x4($s1)
    /* E58C 80076D8C 180032A6 */  sh         $s2, 0x18($s1)
    /* E590 80076D90 1A0020A6 */  sh         $zero, 0x1A($s1)
    /* E594 80076D94 2A0026A2 */  sb         $a2, 0x2A($s1)
    /* E598 80076D98 2B0027A2 */  sb         $a3, 0x2B($s1)
    /* E59C 80076D9C 06008010 */  beqz       $a0, .L80076DB8
    /* E5A0 80076DA0 200020AE */   sw        $zero, 0x20($s1)
    /* E5A4 80076DA4 01000224 */  addiu      $v0, $zero, 0x1
    /* E5A8 80076DA8 05008210 */  beq        $a0, $v0, .L80076DC0
    /* E5AC 80076DAC 03006332 */   andi      $v1, $s3, 0x3
    /* E5B0 80076DB0 72DB0108 */  j          .L80076DC8
    /* E5B4 80076DB4 00000000 */   nop
  .L80076DB8:
    /* E5B8 80076DB8 89DB0108 */  j          .L80076E24
    /* E5BC 80076DBC 01000224 */   addiu     $v0, $zero, 0x1
  .L80076DC0:
    /* E5C0 80076DC0 89DB0108 */  j          .L80076E24
    /* E5C4 80076DC4 02000224 */   addiu     $v0, $zero, 0x2
  .L80076DC8:
    /* E5C8 80076DC8 0B006210 */  beq        $v1, $v0, .L80076DF8
    /* E5CC 80076DCC 02006228 */   slti      $v0, $v1, 0x2
    /* E5D0 80076DD0 05004010 */  beqz       $v0, .L80076DE8
    /* E5D4 80076DD4 04006228 */   slti      $v0, $v1, 0x4
    /* E5D8 80076DD8 11006010 */  beqz       $v1, .L80076E20
    /* E5DC 80076DDC 1C006232 */   andi      $v0, $s3, 0x1C
    /* E5E0 80076DE0 8CDB0108 */  j          .L80076E30
    /* E5E4 80076DE4 240022A2 */   sb        $v0, 0x24($s1)
  .L80076DE8:
    /* E5E8 80076DE8 0F004010 */  beqz       $v0, .L80076E28
    /* E5EC 80076DEC 08000224 */   addiu     $v0, $zero, 0x8
    /* E5F0 80076DF0 8ADB0108 */  j          .L80076E28
    /* E5F4 80076DF4 1C0022A6 */   sh        $v0, 0x1C($s1)
  .L80076DF8:
    /* E5F8 80076DF8 04000324 */  addiu      $v1, $zero, 0x4
    /* E5FC 80076DFC 01000524 */  addiu      $a1, $zero, 0x1
    /* E600 80076E00 2000228E */  lw         $v0, 0x20($s1)
    /* E604 80076E04 21300000 */  addu       $a2, $zero, $zero
    /* E608 80076E08 1C0023A6 */  sh         $v1, 0x1C($s1)
    /* E60C 80076E0C 01004234 */  ori        $v0, $v0, 0x1
    /* E610 80076E10 4D76020C */  jal        func_8009D934
    /* E614 80076E14 200022AE */   sw        $v0, 0x20($s1)
    /* E618 80076E18 8BDB0108 */  j          .L80076E2C
    /* E61C 80076E1C 1C006232 */   andi      $v0, $s3, 0x1C
  .L80076E20:
    /* E620 80076E20 02000224 */  addiu      $v0, $zero, 0x2
  .L80076E24:
    /* E624 80076E24 1C0022A6 */  sh         $v0, 0x1C($s1)
  .L80076E28:
    /* E628 80076E28 1C006232 */  andi       $v0, $s3, 0x1C
  .L80076E2C:
    /* E62C 80076E2C 240022A2 */  sb         $v0, 0x24($s1)
  .L80076E30:
    /* E630 80076E30 64000224 */  addiu      $v0, $zero, 0x64
    /* E634 80076E34 2F0020A2 */  sb         $zero, 0x2F($s1)
    /* E638 80076E38 2E0020A2 */  sb         $zero, 0x2E($s1)
    /* E63C 80076E3C 2D0020A2 */  sb         $zero, 0x2D($s1)
    /* E640 80076E40 2C0020A2 */  sb         $zero, 0x2C($s1)
    /* E644 80076E44 1E0020A2 */  sb         $zero, 0x1E($s1)
    /* E648 80076E48 080020A2 */  sb         $zero, 0x8($s1)
    /* E64C 80076E4C 1A0002A6 */  sh         $v0, 0x1A($s0)
    /* E650 80076E50 180002A6 */  sh         $v0, 0x18($s0)
    /* E654 80076E54 1E0002A6 */  sh         $v0, 0x1E($s0)
    /* E658 80076E58 1C0002A6 */  sh         $v0, 0x1C($s0)
    /* E65C 80076E5C 29000224 */  addiu      $v0, $zero, 0x29
    /* E660 80076E60 200000A6 */  sh         $zero, 0x20($s0)
    /* E664 80076E64 05004216 */  bne        $s2, $v0, .L80076E7C
    /* E668 80076E68 540900A6 */   sh        $zero, 0x954($s0)
    /* E66C 80076E6C 10000224 */  addiu      $v0, $zero, 0x10
    /* E670 80076E70 300002A2 */  sb         $v0, 0x30($s0)
    /* E674 80076E74 A7DB0108 */  j          .L80076E9C
    /* E678 80076E78 20000224 */   addiu     $v0, $zero, 0x20
  .L80076E7C:
    /* E67C 80076E7C 30000224 */  addiu      $v0, $zero, 0x30
    /* E680 80076E80 04004216 */  bne        $s2, $v0, .L80076E94
    /* E684 80076E84 02000224 */   addiu     $v0, $zero, 0x2
    /* E688 80076E88 300002A2 */  sb         $v0, 0x30($s0)
    /* E68C 80076E8C A7DB0108 */  j          .L80076E9C
    /* E690 80076E90 08000224 */   addiu     $v0, $zero, 0x8
  .L80076E94:
    /* E694 80076E94 300002A2 */  sb         $v0, 0x30($s0)
    /* E698 80076E98 04000224 */  addiu      $v0, $zero, 0x4
  .L80076E9C:
    /* E69C 80076E9C 320002A2 */  sb         $v0, 0x32($s0)
    /* E6A0 80076EA0 FEFF043C */  lui        $a0, (0xFFFEFFFF >> 16)
    /* E6A4 80076EA4 FFFF8434 */  ori        $a0, $a0, (0xFFFEFFFF & 0xFFFF)
    /* E6A8 80076EA8 FF07053C */  lui        $a1, (0x7FFFFFF >> 16)
    /* E6AC 80076EAC FFFFA534 */  ori        $a1, $a1, (0x7FFFFFF & 0xFFFF)
    /* E6B0 80076EB0 09000224 */  addiu      $v0, $zero, 0x9
    /* E6B4 80076EB4 310002A2 */  sb         $v0, 0x31($s0)
    /* E6B8 80076EB8 12000224 */  addiu      $v0, $zero, 0x12
    /* E6BC 80076EBC 330002A2 */  sb         $v0, 0x33($s0)
    /* E6C0 80076EC0 14000224 */  addiu      $v0, $zero, 0x14
    /* E6C4 80076EC4 470102A2 */  sb         $v0, 0x147($s0)
    /* E6C8 80076EC8 04000224 */  addiu      $v0, $zero, 0x4
    /* E6CC 80076ECC 610102A2 */  sb         $v0, 0x161($s0)
    /* E6D0 80076ED0 5409028E */  lw         $v0, 0x954($s0)
    /* E6D4 80076ED4 05000324 */  addiu      $v1, $zero, 0x5
    /* E6D8 80076ED8 600103A2 */  sb         $v1, 0x160($s0)
    /* E6DC 80076EDC 620103A2 */  sb         $v1, 0x162($s0)
    /* E6E0 80076EE0 6001038E */  lw         $v1, 0x160($s0)
    /* E6E4 80076EE4 24104400 */  and        $v0, $v0, $a0
    /* E6E8 80076EE8 24186500 */  and        $v1, $v1, $a1
    /* E6EC 80076EEC 540902AE */  sw         $v0, 0x954($s0)
    /* E6F0 80076EF0 80000224 */  addiu      $v0, $zero, 0x80
    /* E6F4 80076EF4 600103AE */  sw         $v1, 0x160($s0)
    /* E6F8 80076EF8 270022A2 */  sb         $v0, 0x27($s1)
    /* E6FC 80076EFC 290020A2 */  sb         $zero, 0x29($s1)
    /* E700 80076F00 280020A2 */  sb         $zero, 0x28($s1)
    /* E704 80076F04 570902A2 */  sb         $v0, 0x957($s0)
    /* E708 80076F08 2000BF8F */  lw         $ra, 0x20($sp)
    /* E70C 80076F0C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* E710 80076F10 1800B28F */  lw         $s2, 0x18($sp)
    /* E714 80076F14 1400B18F */  lw         $s1, 0x14($sp)
    /* E718 80076F18 1000B08F */  lw         $s0, 0x10($sp)
    /* E71C 80076F1C 0800E003 */  jr         $ra
    /* E720 80076F20 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80076D50
