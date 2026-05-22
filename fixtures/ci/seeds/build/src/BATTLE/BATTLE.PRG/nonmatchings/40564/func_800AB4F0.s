nonmatching func_800AB4F0, 0x298

glabel func_800AB4F0
    /* 42CF0 800AB4F0 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 42CF4 800AB4F4 2400B3AF */  sw         $s3, 0x24($sp)
    /* 42CF8 800AB4F8 21988000 */  addu       $s3, $a0, $zero
    /* 42CFC 800AB4FC 0F80033C */  lui        $v1, %hi(D_800E8F30)
    /* 42D00 800AB500 308F6324 */  addiu      $v1, $v1, %lo(D_800E8F30)
    /* 42D04 800AB504 3000BFAF */  sw         $ra, 0x30($sp)
    /* 42D08 800AB508 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 42D0C 800AB50C 2800B4AF */  sw         $s4, 0x28($sp)
    /* 42D10 800AB510 2000B2AF */  sw         $s2, 0x20($sp)
    /* 42D14 800AB514 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 42D18 800AB518 1800B0AF */  sw         $s0, 0x18($sp)
    /* 42D1C 800AB51C BB056492 */  lbu        $a0, 0x5BB($s3)
    /* 42D20 800AB520 21880000 */  addu       $s1, $zero, $zero
    /* 42D24 800AB524 80280400 */  sll        $a1, $a0, 2
    /* 42D28 800AB528 2110A300 */  addu       $v0, $a1, $v1
    /* 42D2C 800AB52C 21186500 */  addu       $v1, $v1, $a1
    /* 42D30 800AB530 00004284 */  lh         $v0, 0x0($v0)
    /* 42D34 800AB534 02006384 */  lh         $v1, 0x2($v1)
    /* 42D38 800AB538 80A90200 */  sll        $s5, $v0, 6
    /* 42D3C 800AB53C 0F80023C */  lui        $v0, %hi(D_800E8F90)
    /* 42D40 800AB540 908F4224 */  addiu      $v0, $v0, %lo(D_800E8F90)
    /* 42D44 800AB544 21208200 */  addu       $a0, $a0, $v0
    /* 42D48 800AB548 00008290 */  lbu        $v0, 0x0($a0)
    /* 42D4C 800AB54C 001A0300 */  sll        $v1, $v1, 8
    /* 42D50 800AB550 80110200 */  sll        $v0, $v0, 6
    /* 42D54 800AB554 21A06200 */  addu       $s4, $v1, $v0
    /* 42D58 800AB558 C0201100 */  sll        $a0, $s1, 3
  .L800AB55C:
    /* 42D5C 800AB55C 1C068224 */  addiu      $v0, $a0, 0x61C
    /* 42D60 800AB560 21406202 */  addu       $t0, $s3, $v0
    /* 42D64 800AB564 02000291 */  lbu        $v0, 0x2($t0)
    /* 42D68 800AB568 00000000 */  nop
    /* 42D6C 800AB56C 78004010 */  beqz       $v0, .L800AB750
    /* 42D70 800AB570 0680023C */   lui       $v0, %hi(vs_gametime_tickspeed)
    /* 42D74 800AB574 1C188424 */  addiu      $a0, $a0, 0x181C
    /* 42D78 800AB578 21306402 */  addu       $a2, $s3, $a0
    /* 42D7C 800AB57C 4CE2438C */  lw         $v1, %lo(vs_gametime_tickspeed)($v0)
    /* 42D80 800AB580 0500C490 */  lbu        $a0, 0x5($a2)
    /* 42D84 800AB584 C2170300 */  srl        $v0, $v1, 31
    /* 42D88 800AB588 21186200 */  addu       $v1, $v1, $v0
    /* 42D8C 800AB58C 43180300 */  sra        $v1, $v1, 1
    /* 42D90 800AB590 0400C290 */  lbu        $v0, 0x4($a2)
    /* 42D94 800AB594 21208300 */  addu       $a0, $a0, $v1
    /* 42D98 800AB598 0500C4A0 */  sb         $a0, 0x5($a2)
    /* 42D9C 800AB59C FF008430 */  andi       $a0, $a0, 0xFF
    /* 42DA0 800AB5A0 2B104400 */  sltu       $v0, $v0, $a0
    /* 42DA4 800AB5A4 6A004010 */  beqz       $v0, .L800AB750
    /* 42DA8 800AB5A8 80101100 */   sll       $v0, $s1, 2
    /* 42DAC 800AB5AC F4054224 */  addiu      $v0, $v0, 0x5F4
    /* 42DB0 800AB5B0 0500C0A0 */  sb         $zero, 0x5($a2)
    /* 42DB4 800AB5B4 02000391 */  lbu        $v1, 0x2($t0)
    /* 42DB8 800AB5B8 00000000 */  nop
    /* 42DBC 800AB5BC 64006010 */  beqz       $v1, .L800AB750
    /* 42DC0 800AB5C0 21686202 */   addu      $t5, $s3, $v0
    /* 42DC4 800AB5C4 21486000 */  addu       $t1, $v1, $zero
    /* 42DC8 800AB5C8 61003211 */  beq        $t1, $s2, .L800AB750
    /* 42DCC 800AB5CC 00000000 */   nop
    /* 42DD0 800AB5D0 0200AA91 */  lbu        $t2, 0x2($t5)
    /* 42DD4 800AB5D4 0000C490 */  lbu        $a0, 0x0($a2)
    /* 42DD8 800AB5D8 0200CC80 */  lb         $t4, 0x2($a2)
    /* 42DDC 800AB5DC 0100C390 */  lbu        $v1, 0x1($a2)
    /* 42DE0 800AB5E0 0300C280 */  lb         $v0, 0x3($a2)
    /* 42DE4 800AB5E4 00000791 */  lbu        $a3, 0x0($t0)
    /* 42DE8 800AB5E8 0300B291 */  lbu        $s2, 0x3($t5)
    /* 42DEC 800AB5EC 21288C00 */  addu       $a1, $a0, $t4
    /* 42DF0 800AB5F0 21586200 */  addu       $t3, $v1, $v0
    /* 42DF4 800AB5F4 2118E900 */  addu       $v1, $a3, $t1
    /* 42DF8 800AB5F8 01000491 */  lbu        $a0, 0x1($t0)
    /* 42DFC 800AB5FC 03000291 */  lbu        $v0, 0x3($t0)
    /* 42E00 800AB600 0200C990 */  lbu        $t1, 0x2($a2)
    /* 42E04 800AB604 21208200 */  addu       $a0, $a0, $v0
    /* 42E08 800AB608 2110AA00 */  addu       $v0, $a1, $t2
    /* 42E0C 800AB60C 2A186200 */  slt        $v1, $v1, $v0
    /* 42E10 800AB610 03006014 */  bnez       $v1, .L800AB620
    /* 42E14 800AB614 2A10A700 */   slt       $v0, $a1, $a3
    /* 42E18 800AB618 0C004010 */  beqz       $v0, .L800AB64C
    /* 42E1C 800AB61C 21107201 */   addu      $v0, $t3, $s2
  .L800AB620:
    /* 42E20 800AB620 06000291 */  lbu        $v0, 0x6($t0)
    /* 42E24 800AB624 00000000 */  nop
    /* 42E28 800AB628 01004230 */  andi       $v0, $v0, 0x1
    /* 42E2C 800AB62C 05004010 */  beqz       $v0, .L800AB644
    /* 42E30 800AB630 40100C00 */   sll       $v0, $t4, 1
    /* 42E34 800AB634 2328A200 */  subu       $a1, $a1, $v0
    /* 42E38 800AB638 23100900 */  negu       $v0, $t1
    /* 42E3C 800AB63C 92AD0208 */  j          .L800AB648
    /* 42E40 800AB640 0200C2A0 */   sb        $v0, 0x2($a2)
  .L800AB644:
    /* 42E44 800AB644 2128E000 */  addu       $a1, $a3, $zero
  .L800AB648:
    /* 42E48 800AB648 21107201 */  addu       $v0, $t3, $s2
  .L800AB64C:
    /* 42E4C 800AB64C 2A108200 */  slt        $v0, $a0, $v0
    /* 42E50 800AB650 06004014 */  bnez       $v0, .L800AB66C
    /* 42E54 800AB654 00000000 */   nop
    /* 42E58 800AB658 01000291 */  lbu        $v0, 0x1($t0)
    /* 42E5C 800AB65C 00000000 */  nop
    /* 42E60 800AB660 2A106201 */  slt        $v0, $t3, $v0
    /* 42E64 800AB664 0E004010 */  beqz       $v0, .L800AB6A0
    /* 42E68 800AB668 00000000 */   nop
  .L800AB66C:
    /* 42E6C 800AB66C 06000291 */  lbu        $v0, 0x6($t0)
    /* 42E70 800AB670 00000000 */  nop
    /* 42E74 800AB674 01004230 */  andi       $v0, $v0, 0x1
    /* 42E78 800AB678 08004010 */  beqz       $v0, .L800AB69C
    /* 42E7C 800AB67C 00000000 */   nop
    /* 42E80 800AB680 0300C380 */  lb         $v1, 0x3($a2)
    /* 42E84 800AB684 0300C290 */  lbu        $v0, 0x3($a2)
    /* 42E88 800AB688 40180300 */  sll        $v1, $v1, 1
    /* 42E8C 800AB68C 23586301 */  subu       $t3, $t3, $v1
    /* 42E90 800AB690 23100200 */  negu       $v0, $v0
    /* 42E94 800AB694 A8AD0208 */  j          .L800AB6A0
    /* 42E98 800AB698 0300C2A0 */   sb        $v0, 0x3($a2)
  .L800AB69C:
    /* 42E9C 800AB69C 01000B91 */  lbu        $t3, 0x1($t0)
  .L800AB6A0:
    /* 42EA0 800AB6A0 0000C5A0 */  sb         $a1, 0x0($a2)
    /* 42EA4 800AB6A4 0100CBA0 */  sb         $t3, 0x1($a2)
    /* 42EA8 800AB6A8 AC05628E */  lw         $v0, 0x5AC($s3)
    /* 42EAC 800AB6AC 0008033C */  lui        $v1, (0x8000000 >> 16)
    /* 42EB0 800AB6B0 24104300 */  and        $v0, $v0, $v1
    /* 42EB4 800AB6B4 0C004014 */  bnez       $v0, .L800AB6E8
    /* 42EB8 800AB6B8 C2170500 */   srl       $v0, $a1, 31
    /* 42EBC 800AB6BC 0200A104 */  bgez       $a1, .L800AB6C8
    /* 42EC0 800AB6C0 2110A000 */   addu      $v0, $a1, $zero
    /* 42EC4 800AB6C4 0300A224 */  addiu      $v0, $a1, 0x3
  .L800AB6C8:
    /* 42EC8 800AB6C8 83280200 */  sra        $a1, $v0, 2
    /* 42ECC 800AB6CC 02004105 */  bgez       $t2, .L800AB6D8
    /* 42ED0 800AB6D0 21184001 */   addu      $v1, $t2, $zero
    /* 42ED4 800AB6D4 03004325 */  addiu      $v1, $t2, 0x3
  .L800AB6D8:
    /* 42ED8 800AB6D8 0000A291 */  lbu        $v0, 0x0($t5)
    /* 42EDC 800AB6DC 83500300 */  sra        $t2, $v1, 2
    /* 42EE0 800AB6E0 C1AD0208 */  j          .L800AB704
    /* 42EE4 800AB6E4 82180200 */   srl       $v1, $v0, 2
  .L800AB6E8:
    /* 42EE8 800AB6E8 2110A200 */  addu       $v0, $a1, $v0
    /* 42EEC 800AB6EC 43280200 */  sra        $a1, $v0, 1
    /* 42EF0 800AB6F0 C2170A00 */  srl        $v0, $t2, 31
    /* 42EF4 800AB6F4 21104201 */  addu       $v0, $t2, $v0
    /* 42EF8 800AB6F8 0000A391 */  lbu        $v1, 0x0($t5)
    /* 42EFC 800AB6FC 43500200 */  sra        $t2, $v0, 1
    /* 42F00 800AB700 42180300 */  srl        $v1, $v1, 1
  .L800AB704:
    /* 42F04 800AB704 2110A502 */  addu       $v0, $s5, $a1
    /* 42F08 800AB708 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 42F0C 800AB70C 21108B02 */  addu       $v0, $s4, $t3
    /* 42F10 800AB710 1000A527 */  addiu      $a1, $sp, 0x10
    /* 42F14 800AB714 801F103C */  lui        $s0, (0x1F800000 >> 16)
    /* 42F18 800AB718 0000108E */  lw         $s0, (0x1F800000 & 0xFFFF)($s0)
    /* 42F1C 800AB71C 2130A302 */  addu       $a2, $s5, $v1
    /* 42F20 800AB720 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 42F24 800AB724 1400AAA7 */  sh         $t2, 0x14($sp)
    /* 42F28 800AB728 1600B2A7 */  sh         $s2, 0x16($sp)
    /* 42F2C 800AB72C 0100A791 */  lbu        $a3, 0x1($t5)
    /* 42F30 800AB730 21200002 */  addu       $a0, $s0, $zero
    /* 42F34 800AB734 ADAD000C */  jal        SetDrawMove
    /* 42F38 800AB738 21388702 */   addu      $a3, $s4, $a3
    /* 42F3C 800AB73C 09EA010C */  jal        func_8007A824
    /* 42F40 800AB740 21200002 */   addu      $a0, $s0, $zero
    /* 42F44 800AB744 18001026 */  addiu      $s0, $s0, 0x18
    /* 42F48 800AB748 801F013C */  lui        $at, (0x1F800000 >> 16)
    /* 42F4C 800AB74C 000030AC */  sw         $s0, (0x1F800000 & 0xFFFF)($at)
  .L800AB750:
    /* 42F50 800AB750 01003126 */  addiu      $s1, $s1, 0x1
    /* 42F54 800AB754 0400222A */  slti       $v0, $s1, 0x4
    /* 42F58 800AB758 80FF4014 */  bnez       $v0, .L800AB55C
    /* 42F5C 800AB75C C0201100 */   sll       $a0, $s1, 3
    /* 42F60 800AB760 3000BF8F */  lw         $ra, 0x30($sp)
    /* 42F64 800AB764 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 42F68 800AB768 2800B48F */  lw         $s4, 0x28($sp)
    /* 42F6C 800AB76C 2400B38F */  lw         $s3, 0x24($sp)
    /* 42F70 800AB770 2000B28F */  lw         $s2, 0x20($sp)
    /* 42F74 800AB774 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 42F78 800AB778 1800B08F */  lw         $s0, 0x18($sp)
    /* 42F7C 800AB77C 3800BD27 */  addiu      $sp, $sp, 0x38
    /* 42F80 800AB780 0800E003 */  jr         $ra
    /* 42F84 800AB784 00000000 */   nop
endlabel func_800AB4F0
