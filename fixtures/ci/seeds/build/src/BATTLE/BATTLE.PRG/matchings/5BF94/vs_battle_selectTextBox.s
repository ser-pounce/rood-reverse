nonmatching vs_battle_selectTextBox, 0x384

glabel vs_battle_selectTextBox
    /* 5E48C 800C6C8C A0FFBD27 */  addiu      $sp, $sp, -0x60
    /* 5E490 800C6C90 0F80023C */  lui        $v0, %hi(textBoxSelector)
    /* 5E494 800C6C94 5800B2AF */  sw         $s2, 0x58($sp)
    /* 5E498 800C6C98 A84E5224 */  addiu      $s2, $v0, %lo(textBoxSelector)
    /* 5E49C 800C6C9C 5C00BFAF */  sw         $ra, 0x5C($sp)
    /* 5E4A0 800C6CA0 5400B1AF */  sw         $s1, 0x54($sp)
    /* 5E4A4 800C6CA4 5000B0AF */  sw         $s0, 0x50($sp)
    /* 5E4A8 800C6CA8 0B004292 */  lbu        $v0, 0xB($s2)
    /* 5E4AC 800C6CAC 00000000 */  nop
    /* 5E4B0 800C6CB0 3E004014 */  bnez       $v0, .L800C6DAC
    /* 5E4B4 800C6CB4 21880000 */   addu      $s1, $zero, $zero
    /* 5E4B8 800C6CB8 21282002 */  addu       $a1, $s1, $zero
    /* 5E4BC 800C6CBC FF7F0724 */  addiu      $a3, $zero, 0x7FFF
    /* 5E4C0 800C6CC0 FF008430 */  andi       $a0, $a0, 0xFF
    /* 5E4C4 800C6CC4 4000A327 */  addiu      $v1, $sp, 0x40
    /* 5E4C8 800C6CC8 0F80023C */  lui        $v0, %hi(vs_battle_textBoxes)
    /* 5E4CC 800C6CCC E04F4624 */  addiu      $a2, $v0, %lo(vs_battle_textBoxes)
  .L800C6CD0:
    /* 5E4D0 800C6CD0 0710A400 */  srav       $v0, $a0, $a1
    /* 5E4D4 800C6CD4 01004230 */  andi       $v0, $v0, 0x1
    /* 5E4D8 800C6CD8 04004010 */  beqz       $v0, .L800C6CEC
    /* 5E4DC 800C6CDC 000067A4 */   sh        $a3, 0x0($v1)
    /* 5E4E0 800C6CE0 1600C294 */  lhu        $v0, 0x16($a2)
    /* 5E4E4 800C6CE4 01003126 */  addiu      $s1, $s1, 0x1
    /* 5E4E8 800C6CE8 000062A4 */  sh         $v0, 0x0($v1)
  .L800C6CEC:
    /* 5E4EC 800C6CEC 02006324 */  addiu      $v1, $v1, 0x2
    /* 5E4F0 800C6CF0 0100A524 */  addiu      $a1, $a1, 0x1
    /* 5E4F4 800C6CF4 0800A228 */  slti       $v0, $a1, 0x8
    /* 5E4F8 800C6CF8 F5FF4014 */  bnez       $v0, .L800C6CD0
    /* 5E4FC 800C6CFC 3000C624 */   addiu     $a2, $a2, 0x30
    /* 5E500 800C6D00 1E002012 */  beqz       $s1, .L800C6D7C
    /* 5E504 800C6D04 21280000 */   addu      $a1, $zero, $zero
    /* 5E508 800C6D08 4000A827 */  addiu      $t0, $sp, 0x40
    /* 5E50C 800C6D0C 0F80023C */  lui        $v0, %hi(textBoxSelector)
    /* 5E510 800C6D10 A84E4924 */  addiu      $t1, $v0, %lo(textBoxSelector)
    /* 5E514 800C6D14 21380000 */  addu       $a3, $zero, $zero
  .L800C6D18:
    /* 5E518 800C6D18 2130E000 */  addu       $a2, $a3, $zero
    /* 5E51C 800C6D1C 21200001 */  addu       $a0, $t0, $zero
  .L800C6D20:
    /* 5E520 800C6D20 40100700 */  sll        $v0, $a3, 1
    /* 5E524 800C6D24 21100201 */  addu       $v0, $t0, $v0
    /* 5E528 800C6D28 00004384 */  lh         $v1, 0x0($v0)
    /* 5E52C 800C6D2C 00008284 */  lh         $v0, 0x0($a0)
    /* 5E530 800C6D30 00000000 */  nop
    /* 5E534 800C6D34 2A104300 */  slt        $v0, $v0, $v1
    /* 5E538 800C6D38 02004010 */  beqz       $v0, .L800C6D44
    /* 5E53C 800C6D3C 00000000 */   nop
    /* 5E540 800C6D40 2138C000 */  addu       $a3, $a2, $zero
  .L800C6D44:
    /* 5E544 800C6D44 0100C624 */  addiu      $a2, $a2, 0x1
    /* 5E548 800C6D48 0800C228 */  slti       $v0, $a2, 0x8
    /* 5E54C 800C6D4C F4FF4014 */  bnez       $v0, .L800C6D20
    /* 5E550 800C6D50 02008424 */   addiu     $a0, $a0, 0x2
    /* 5E554 800C6D54 2110A900 */  addu       $v0, $a1, $t1
    /* 5E558 800C6D58 0100A524 */  addiu      $a1, $a1, 0x1
    /* 5E55C 800C6D5C 000047A0 */  sb         $a3, 0x0($v0)
    /* 5E560 800C6D60 40100700 */  sll        $v0, $a3, 1
    /* 5E564 800C6D64 21100201 */  addu       $v0, $t0, $v0
    /* 5E568 800C6D68 FF7F0324 */  addiu      $v1, $zero, 0x7FFF
    /* 5E56C 800C6D6C 000043A4 */  sh         $v1, 0x0($v0)
    /* 5E570 800C6D70 2B10B100 */  sltu       $v0, $a1, $s1
    /* 5E574 800C6D74 E8FF4014 */  bnez       $v0, .L800C6D18
    /* 5E578 800C6D78 21380000 */   addu      $a3, $zero, $zero
  .L800C6D7C:
    /* 5E57C 800C6D7C 0680023C */  lui        $v0, %hi(vs_main_stateFlags + 0x11)
    /* 5E580 800C6D80 A9154290 */  lbu        $v0, %lo(vs_main_stateFlags + 0x11)($v0)
    /* 5E584 800C6D84 00000000 */  nop
    /* 5E588 800C6D88 FFFF5024 */  addiu      $s0, $v0, -0x1
    /* 5E58C 800C6D8C 2B101102 */  sltu       $v0, $s0, $s1
    /* 5E590 800C6D90 02004014 */  bnez       $v0, .L800C6D9C
    /* 5E594 800C6D94 0F80023C */   lui       $v0, %hi(textBoxSelector)
    /* 5E598 800C6D98 21800000 */  addu       $s0, $zero, $zero
  .L800C6D9C:
    /* 5E59C 800C6D9C A84E4224 */  addiu      $v0, $v0, %lo(textBoxSelector)
    /* 5E5A0 800C6DA0 0A0040A0 */  sb         $zero, 0xA($v0)
    /* 5E5A4 800C6DA4 801B0308 */  j          .L800C6E00
    /* 5E5A8 800C6DA8 0B0051A0 */   sb        $s1, 0xB($v0)
  .L800C6DAC:
    /* 5E5AC 800C6DAC 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 5E5B0 800C6DB0 0A005092 */  lbu        $s0, 0xA($s2)
    /* 5E5B4 800C6DB4 D0E1438C */  lw         $v1, %lo(vs_main_buttonsPressed)($v0)
    /* 5E5B8 800C6DB8 0B005192 */  lbu        $s1, 0xB($s2)
    /* 5E5BC 800C6DBC FF006230 */  andi       $v0, $v1, 0xFF
    /* 5E5C0 800C6DC0 06004010 */  beqz       $v0, .L800C6DDC
    /* 5E5C4 800C6DC4 00106230 */   andi      $v0, $v1, 0x1000
    /* 5E5C8 800C6DC8 BC00030C */  jal        vs_battle_playMenuSelectSfx
    /* 5E5CC 800C6DCC 00000000 */   nop
    /* 5E5D0 800C6DD0 0B0040A2 */  sb         $zero, 0xB($s2)
    /* 5E5D4 800C6DD4 FE1B0308 */  j          .L800C6FF8
    /* 5E5D8 800C6DD8 01000226 */   addiu     $v0, $s0, 0x1
  .L800C6DDC:
    /* 5E5DC 800C6DDC 02004010 */  beqz       $v0, .L800C6DE8
    /* 5E5E0 800C6DE0 FFFF0226 */   addiu     $v0, $s0, -0x1
    /* 5E5E4 800C6DE4 21805100 */  addu       $s0, $v0, $s1
  .L800C6DE8:
    /* 5E5E8 800C6DE8 00406230 */  andi       $v0, $v1, 0x4000
    /* 5E5EC 800C6DEC 02004010 */  beqz       $v0, .L800C6DF8
    /* 5E5F0 800C6DF0 00000000 */   nop
    /* 5E5F4 800C6DF4 01001026 */  addiu      $s0, $s0, 0x1
  .L800C6DF8:
    /* 5E5F8 800C6DF8 1B001102 */  divu       $zero, $s0, $s1
    /* 5E5FC 800C6DFC 10800000 */  mfhi       $s0
  .L800C6E00:
    /* 5E600 800C6E00 0F80023C */  lui        $v0, %hi(textBoxSelector)
    /* 5E604 800C6E04 A84E5224 */  addiu      $s2, $v0, %lo(textBoxSelector)
    /* 5E608 800C6E08 0A004292 */  lbu        $v0, 0xA($s2)
    /* 5E60C 800C6E0C 00000000 */  nop
    /* 5E610 800C6E10 05000212 */  beq        $s0, $v0, .L800C6E28
    /* 5E614 800C6E14 21300002 */   addu      $a2, $s0, $zero
    /* 5E618 800C6E18 BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 5E61C 800C6E1C 00000000 */   nop
    /* 5E620 800C6E20 0A0050A2 */  sb         $s0, 0xA($s2)
    /* 5E624 800C6E24 21300002 */  addu       $a2, $s0, $zero
  .L800C6E28:
    /* 5E628 800C6E28 0F002012 */  beqz       $s1, .L800C6E68
    /* 5E62C 800C6E2C 21280000 */   addu      $a1, $zero, $zero
    /* 5E630 800C6E30 21204002 */  addu       $a0, $s2, $zero
    /* 5E634 800C6E34 2110C400 */  addu       $v0, $a2, $a0
  .L800C6E38:
    /* 5E638 800C6E38 2118A400 */  addu       $v1, $a1, $a0
    /* 5E63C 800C6E3C 00004290 */  lbu        $v0, 0x0($v0)
    /* 5E640 800C6E40 00006390 */  lbu        $v1, 0x0($v1)
    /* 5E644 800C6E44 00000000 */  nop
    /* 5E648 800C6E48 2B104300 */  sltu       $v0, $v0, $v1
    /* 5E64C 800C6E4C 02004010 */  beqz       $v0, .L800C6E58
    /* 5E650 800C6E50 00000000 */   nop
    /* 5E654 800C6E54 2130A000 */  addu       $a2, $a1, $zero
  .L800C6E58:
    /* 5E658 800C6E58 0100A524 */  addiu      $a1, $a1, 0x1
    /* 5E65C 800C6E5C 2B10B100 */  sltu       $v0, $a1, $s1
    /* 5E660 800C6E60 F5FF4014 */  bnez       $v0, .L800C6E38
    /* 5E664 800C6E64 2110C400 */   addu      $v0, $a2, $a0
  .L800C6E68:
    /* 5E668 800C6E68 1000A827 */  addiu      $t0, $sp, 0x10
    /* 5E66C 800C6E6C 0F80033C */  lui        $v1, %hi(textBoxSelector)
    /* 5E670 800C6E70 A84E6324 */  addiu      $v1, $v1, %lo(textBoxSelector)
    /* 5E674 800C6E74 21280302 */  addu       $a1, $s0, $v1
    /* 5E678 800C6E78 0F80043C */  lui        $a0, %hi(vs_battle_textBoxes)
    /* 5E67C 800C6E7C E04F8424 */  addiu      $a0, $a0, %lo(vs_battle_textBoxes)
    /* 5E680 800C6E80 0000A790 */  lbu        $a3, 0x0($a1)
    /* 5E684 800C6E84 2118C300 */  addu       $v1, $a2, $v1
    /* 5E688 800C6E88 40100700 */  sll        $v0, $a3, 1
    /* 5E68C 800C6E8C 21104700 */  addu       $v0, $v0, $a3
    /* 5E690 800C6E90 00110200 */  sll        $v0, $v0, 4
    /* 5E694 800C6E94 21204400 */  addu       $a0, $v0, $a0
    /* 5E698 800C6E98 00006290 */  lbu        $v0, 0x0($v1)
    /* 5E69C 800C6E9C 30008624 */  addiu      $a2, $a0, 0x30
    /* 5E6A0 800C6EA0 0000A2A0 */  sb         $v0, 0x0($a1)
    /* 5E6A4 800C6EA4 000067A0 */  sb         $a3, 0x0($v1)
  .L800C6EA8:
    /* 5E6A8 800C6EA8 00008A8C */  lw         $t2, 0x0($a0)
    /* 5E6AC 800C6EAC 04008B8C */  lw         $t3, 0x4($a0)
    /* 5E6B0 800C6EB0 08008C8C */  lw         $t4, 0x8($a0)
    /* 5E6B4 800C6EB4 0C008D8C */  lw         $t5, 0xC($a0)
    /* 5E6B8 800C6EB8 00000AAD */  sw         $t2, 0x0($t0)
    /* 5E6BC 800C6EBC 04000BAD */  sw         $t3, 0x4($t0)
    /* 5E6C0 800C6EC0 08000CAD */  sw         $t4, 0x8($t0)
    /* 5E6C4 800C6EC4 0C000DAD */  sw         $t5, 0xC($t0)
    /* 5E6C8 800C6EC8 10008424 */  addiu      $a0, $a0, 0x10
    /* 5E6CC 800C6ECC F6FF8614 */  bne        $a0, $a2, .L800C6EA8
    /* 5E6D0 800C6ED0 10000825 */   addiu     $t0, $t0, 0x10
    /* 5E6D4 800C6ED4 0F80053C */  lui        $a1, %hi(vs_battle_textBoxes)
    /* 5E6D8 800C6ED8 E04FA524 */  addiu      $a1, $a1, %lo(vs_battle_textBoxes)
    /* 5E6DC 800C6EDC 40180700 */  sll        $v1, $a3, 1
    /* 5E6E0 800C6EE0 21186700 */  addu       $v1, $v1, $a3
    /* 5E6E4 800C6EE4 00190300 */  sll        $v1, $v1, 4
    /* 5E6E8 800C6EE8 0F80023C */  lui        $v0, %hi(textBoxSelector)
    /* 5E6EC 800C6EEC A84E4224 */  addiu      $v0, $v0, %lo(textBoxSelector)
    /* 5E6F0 800C6EF0 21100202 */  addu       $v0, $s0, $v0
    /* 5E6F4 800C6EF4 00004490 */  lbu        $a0, 0x0($v0)
    /* 5E6F8 800C6EF8 21186500 */  addu       $v1, $v1, $a1
    /* 5E6FC 800C6EFC 40100400 */  sll        $v0, $a0, 1
    /* 5E700 800C6F00 21104400 */  addu       $v0, $v0, $a0
    /* 5E704 800C6F04 00110200 */  sll        $v0, $v0, 4
    /* 5E708 800C6F08 21104500 */  addu       $v0, $v0, $a1
    /* 5E70C 800C6F0C 30004424 */  addiu      $a0, $v0, 0x30
  .L800C6F10:
    /* 5E710 800C6F10 00004A8C */  lw         $t2, 0x0($v0)
    /* 5E714 800C6F14 04004B8C */  lw         $t3, 0x4($v0)
    /* 5E718 800C6F18 08004C8C */  lw         $t4, 0x8($v0)
    /* 5E71C 800C6F1C 0C004D8C */  lw         $t5, 0xC($v0)
    /* 5E720 800C6F20 00006AAC */  sw         $t2, 0x0($v1)
    /* 5E724 800C6F24 04006BAC */  sw         $t3, 0x4($v1)
    /* 5E728 800C6F28 08006CAC */  sw         $t4, 0x8($v1)
    /* 5E72C 800C6F2C 0C006DAC */  sw         $t5, 0xC($v1)
    /* 5E730 800C6F30 10004224 */  addiu      $v0, $v0, 0x10
    /* 5E734 800C6F34 F6FF4414 */  bne        $v0, $a0, .L800C6F10
    /* 5E738 800C6F38 10006324 */   addiu     $v1, $v1, 0x10
    /* 5E73C 800C6F3C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 5E740 800C6F40 4000A627 */  addiu      $a2, $sp, 0x40
    /* 5E744 800C6F44 0F80043C */  lui        $a0, %hi(vs_battle_textBoxes)
    /* 5E748 800C6F48 0F80023C */  lui        $v0, %hi(textBoxSelector)
    /* 5E74C 800C6F4C A84E4224 */  addiu      $v0, $v0, %lo(textBoxSelector)
    /* 5E750 800C6F50 21100202 */  addu       $v0, $s0, $v0
    /* 5E754 800C6F54 00004390 */  lbu        $v1, 0x0($v0)
    /* 5E758 800C6F58 E04F8424 */  addiu      $a0, $a0, %lo(vs_battle_textBoxes)
    /* 5E75C 800C6F5C 40100300 */  sll        $v0, $v1, 1
    /* 5E760 800C6F60 21104300 */  addu       $v0, $v0, $v1
    /* 5E764 800C6F64 00110200 */  sll        $v0, $v0, 4
    /* 5E768 800C6F68 21104400 */  addu       $v0, $v0, $a0
  .L800C6F6C:
    /* 5E76C 800C6F6C 0000AA8C */  lw         $t2, 0x0($a1)
    /* 5E770 800C6F70 0400AB8C */  lw         $t3, 0x4($a1)
    /* 5E774 800C6F74 0800AC8C */  lw         $t4, 0x8($a1)
    /* 5E778 800C6F78 0C00AD8C */  lw         $t5, 0xC($a1)
    /* 5E77C 800C6F7C 00004AAC */  sw         $t2, 0x0($v0)
    /* 5E780 800C6F80 04004BAC */  sw         $t3, 0x4($v0)
    /* 5E784 800C6F84 08004CAC */  sw         $t4, 0x8($v0)
    /* 5E788 800C6F88 0C004DAC */  sw         $t5, 0xC($v0)
    /* 5E78C 800C6F8C 1000A524 */  addiu      $a1, $a1, 0x10
    /* 5E790 800C6F90 F6FFA614 */  bne        $a1, $a2, .L800C6F6C
    /* 5E794 800C6F94 10004224 */   addiu     $v0, $v0, 0x10
    /* 5E798 800C6F98 16002012 */  beqz       $s1, .L800C6FF4
    /* 5E79C 800C6F9C 21280000 */   addu      $a1, $zero, $zero
    /* 5E7A0 800C6FA0 0F80023C */  lui        $v0, %hi(vs_battle_textBoxes)
    /* 5E7A4 800C6FA4 E04F4824 */  addiu      $t0, $v0, %lo(vs_battle_textBoxes)
    /* 5E7A8 800C6FA8 0F80023C */  lui        $v0, %hi(textBoxSelector)
    /* 5E7AC 800C6FAC A84E4724 */  addiu      $a3, $v0, %lo(textBoxSelector)
    /* 5E7B0 800C6FB0 80000624 */  addiu      $a2, $zero, 0x80
    /* 5E7B4 800C6FB4 40000424 */  addiu      $a0, $zero, 0x40
    /* 5E7B8 800C6FB8 2110A700 */  addu       $v0, $a1, $a3
  .L800C6FBC:
    /* 5E7BC 800C6FBC 00004390 */  lbu        $v1, 0x0($v0)
    /* 5E7C0 800C6FC0 00000000 */  nop
    /* 5E7C4 800C6FC4 40100300 */  sll        $v0, $v1, 1
    /* 5E7C8 800C6FC8 21104300 */  addu       $v0, $v0, $v1
    /* 5E7CC 800C6FCC 00110200 */  sll        $v0, $v0, 4
    /* 5E7D0 800C6FD0 0300B014 */  bne        $a1, $s0, .L800C6FE0
    /* 5E7D4 800C6FD4 21104800 */   addu      $v0, $v0, $t0
    /* 5E7D8 800C6FD8 F91B0308 */  j          .L800C6FE4
    /* 5E7DC 800C6FDC 1E0046A0 */   sb        $a2, 0x1E($v0)
  .L800C6FE0:
    /* 5E7E0 800C6FE0 1E0044A0 */  sb         $a0, 0x1E($v0)
  .L800C6FE4:
    /* 5E7E4 800C6FE4 0100A524 */  addiu      $a1, $a1, 0x1
    /* 5E7E8 800C6FE8 2B10B100 */  sltu       $v0, $a1, $s1
    /* 5E7EC 800C6FEC F3FF4014 */  bnez       $v0, .L800C6FBC
    /* 5E7F0 800C6FF0 2110A700 */   addu      $v0, $a1, $a3
  .L800C6FF4:
    /* 5E7F4 800C6FF4 21100000 */  addu       $v0, $zero, $zero
  .L800C6FF8:
    /* 5E7F8 800C6FF8 5C00BF8F */  lw         $ra, 0x5C($sp)
    /* 5E7FC 800C6FFC 5800B28F */  lw         $s2, 0x58($sp)
    /* 5E800 800C7000 5400B18F */  lw         $s1, 0x54($sp)
    /* 5E804 800C7004 5000B08F */  lw         $s0, 0x50($sp)
    /* 5E808 800C7008 0800E003 */  jr         $ra
    /* 5E80C 800C700C 6000BD27 */   addiu     $sp, $sp, 0x60
endlabel vs_battle_selectTextBox
