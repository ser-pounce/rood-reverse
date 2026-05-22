nonmatching func_800D6D24, 0x100

glabel func_800D6D24
    /* 6E524 800D6D24 21308000 */  addu       $a2, $a0, $zero
    /* 6E528 800D6D28 0600C290 */  lbu        $v0, 0x6($a2)
    /* 6E52C 800D6D2C 00000000 */  nop
    /* 6E530 800D6D30 05004010 */  beqz       $v0, .L800D6D48
    /* 6E534 800D6D34 FEFF4224 */   addiu     $v0, $v0, -0x2
    /* 6E538 800D6D38 0600C2A0 */  sb         $v0, 0x6($a2)
    /* 6E53C 800D6D3C FF004230 */  andi       $v0, $v0, 0xFF
    /* 6E540 800D6D40 36004014 */  bnez       $v0, .L800D6E1C
    /* 6E544 800D6D44 00000000 */   nop
  .L800D6D48:
    /* 6E548 800D6D48 1800C78C */  lw         $a3, 0x18($a2)
    /* 6E54C 800D6D4C 00F00A3C */  lui        $t2, (0xF0000000 >> 16)
    /* 6E550 800D6D50 0010043C */  lui        $a0, (0x10000000 >> 16)
    /* 6E554 800D6D54 0020093C */  lui        $t1, (0x20000000 >> 16)
    /* 6E558 800D6D58 0030083C */  lui        $t0, (0x30000000 >> 16)
  .L800D6D5C:
    /* 6E55C 800D6D5C 0E00C294 */  lhu        $v0, 0xE($a2)
    /* 6E560 800D6D60 00000000 */  nop
    /* 6E564 800D6D64 2110E200 */  addu       $v0, $a3, $v0
    /* 6E568 800D6D68 0000458C */  lw         $a1, 0x0($v0)
    /* 6E56C 800D6D6C 00000000 */  nop
    /* 6E570 800D6D70 2418AA00 */  and        $v1, $a1, $t2
    /* 6E574 800D6D74 1D006410 */  beq        $v1, $a0, .L800D6DEC
    /* 6E578 800D6D78 2B108300 */   sltu      $v0, $a0, $v1
    /* 6E57C 800D6D7C 05004014 */  bnez       $v0, .L800D6D94
    /* 6E580 800D6D80 00000000 */   nop
    /* 6E584 800D6D84 09006010 */  beqz       $v1, .L800D6DAC
    /* 6E588 800D6D88 0F80033C */   lui       $v1, %hi(D_800F569C)
    /* 6E58C 800D6D8C 575B0308 */  j          .L800D6D5C
    /* 6E590 800D6D90 00000000 */   nop
  .L800D6D94:
    /* 6E594 800D6D94 1F006910 */  beq        $v1, $t1, .L800D6E14
    /* 6E598 800D6D98 00000000 */   nop
    /* 6E59C 800D6D9C 1F006810 */  beq        $v1, $t0, .L800D6E1C
    /* 6E5A0 800D6DA0 00000000 */   nop
    /* 6E5A4 800D6DA4 575B0308 */  j          .L800D6D5C
    /* 6E5A8 800D6DA8 00000000 */   nop
  .L800D6DAC:
    /* 6E5AC 800D6DAC 1600C290 */  lbu        $v0, 0x16($a2)
    /* 6E5B0 800D6DB0 9C56638C */  lw         $v1, %lo(D_800F569C)($v1)
    /* 6E5B4 800D6DB4 80100200 */  sll        $v0, $v0, 2
    /* 6E5B8 800D6DB8 21186200 */  addu       $v1, $v1, $v0
    /* 6E5BC 800D6DBC 03140500 */  sra        $v0, $a1, 16
    /* 6E5C0 800D6DC0 9800648C */  lw         $a0, 0x98($v1)
    /* 6E5C4 800D6DC4 FF3F4230 */  andi       $v0, $v0, 0x3FFF
    /* 6E5C8 800D6DC8 0600C2A4 */  sh         $v0, 0x6($a2)
    /* 6E5CC 800D6DCC FFFFA230 */  andi       $v0, $a1, 0xFFFF
    /* 6E5D0 800D6DD0 0E00C394 */  lhu        $v1, 0xE($a2)
    /* 6E5D4 800D6DD4 80100200 */  sll        $v0, $v0, 2
    /* 6E5D8 800D6DD8 04006324 */  addiu      $v1, $v1, 0x4
    /* 6E5DC 800D6DDC 21208200 */  addu       $a0, $a0, $v0
    /* 6E5E0 800D6DE0 0E00C3A4 */  sh         $v1, 0xE($a2)
    /* 6E5E4 800D6DE4 0800E003 */  jr         $ra
    /* 6E5E8 800D6DE8 1C00C4AC */   sw        $a0, 0x1C($a2)
  .L800D6DEC:
    /* 6E5EC 800D6DEC 80140500 */  sll        $v0, $a1, 18
    /* 6E5F0 800D6DF0 83140200 */  sra        $v0, $v0, 18
    /* 6E5F4 800D6DF4 0800C2A4 */  sh         $v0, 0x8($a2)
    /* 6E5F8 800D6DF8 00110500 */  sll        $v0, $a1, 4
    /* 6E5FC 800D6DFC 0E00C394 */  lhu        $v1, 0xE($a2)
    /* 6E600 800D6E00 83140200 */  sra        $v0, $v0, 18
    /* 6E604 800D6E04 0A00C2A4 */  sh         $v0, 0xA($a2)
    /* 6E608 800D6E08 04006324 */  addiu      $v1, $v1, 0x4
    /* 6E60C 800D6E0C 575B0308 */  j          .L800D6D5C
    /* 6E610 800D6E10 0E00C3A4 */   sh        $v1, 0xE($a2)
  .L800D6E14:
    /* 6E614 800D6E14 575B0308 */  j          .L800D6D5C
    /* 6E618 800D6E18 0E00C0A4 */   sh        $zero, 0xE($a2)
  .L800D6E1C:
    /* 6E61C 800D6E1C 0800E003 */  jr         $ra
    /* 6E620 800D6E20 00000000 */   nop
endlabel func_800D6D24
