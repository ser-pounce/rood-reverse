nonmatching func_800CED60, 0x15C

glabel func_800CED60
    /* 66560 800CED60 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 66564 800CED64 0F80023C */  lui        $v0, %hi(D_800F54B0)
    /* 66568 800CED68 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6656C 800CED6C B054518C */  lw         $s1, %lo(D_800F54B0)($v0)
    /* 66570 800CED70 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 66574 800CED74 21980000 */  addu       $s3, $zero, $zero
    /* 66578 800CED78 2400BFAF */  sw         $ra, 0x24($sp)
    /* 6657C 800CED7C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 66580 800CED80 1800B2AF */  sw         $s2, 0x18($sp)
    /* 66584 800CED84 44002012 */  beqz       $s1, .L800CEE98
    /* 66588 800CED88 1000B0AF */   sw        $s0, 0x10($sp)
  .L800CED8C:
    /* 6658C 800CED8C 0F80023C */  lui        $v0, %hi(D_800F53BC)
    /* 66590 800CED90 BC5351AC */  sw         $s1, %lo(D_800F53BC)($v0)
    /* 66594 800CED94 03000224 */  addiu      $v0, $zero, 0x3
    /* 66598 800CED98 560D2386 */  lh         $v1, 0xD56($s1)
    /* 6659C 800CED9C 0000348E */  lw         $s4, 0x0($s1)
    /* 665A0 800CEDA0 07006210 */  beq        $v1, $v0, .L800CEDC0
    /* 665A4 800CEDA4 04006228 */   slti      $v0, $v1, 0x4
    /* 665A8 800CEDA8 35004014 */  bnez       $v0, .L800CEE80
    /* 665AC 800CEDAC 04000224 */   addiu     $v0, $zero, 0x4
    /* 665B0 800CEDB0 0A006210 */  beq        $v1, $v0, .L800CEDDC
    /* 665B4 800CEDB4 0F80023C */   lui       $v0, %hi(D_800F569C)
    /* 665B8 800CEDB8 A03B0308 */  j          .L800CEE80
    /* 665BC 800CEDBC 00000000 */   nop
  .L800CEDC0:
    /* 665C0 800CEDC0 A649030C */  jal        func_800D2698
    /* 665C4 800CEDC4 FF000424 */   addiu     $a0, $zero, 0xFF
    /* 665C8 800CEDC8 04000424 */  addiu      $a0, $zero, 0x4
    /* 665CC 800CEDCC 213D030C */  jal        func_800CF484
    /* 665D0 800CEDD0 21282002 */   addu      $a1, $s1, $zero
    /* 665D4 800CEDD4 A03B0308 */  j          .L800CEE80
    /* 665D8 800CEDD8 00000000 */   nop
  .L800CEDDC:
    /* 665DC 800CEDDC 9C56428C */  lw         $v0, %lo(D_800F569C)($v0)
    /* 665E0 800CEDE0 00000000 */  nop
    /* 665E4 800CEDE4 8C00428C */  lw         $v0, 0x8C($v0)
    /* 665E8 800CEDE8 00000000 */  nop
    /* 665EC 800CEDEC 04004010 */  beqz       $v0, .L800CEE00
    /* 665F0 800CEDF0 00000000 */   nop
    /* 665F4 800CEDF4 16002496 */  lhu        $a0, 0x16($s1)
    /* 665F8 800CEDF8 4144030C */  jal        func_800D1104
    /* 665FC 800CEDFC 00000000 */   nop
  .L800CEE00:
    /* 66600 800CEE00 3C5E030C */  jal        func_800D78F0
    /* 66604 800CEE04 00000000 */   nop
    /* 66608 800CEE08 500D308E */  lw         $s0, 0xD50($s1)
    /* 6660C 800CEE0C 00000000 */  nop
    /* 66610 800CEE10 0D000012 */  beqz       $s0, .L800CEE48
    /* 66614 800CEE14 21200002 */   addu      $a0, $s0, $zero
  .L800CEE18:
    /* 66618 800CEE18 02000524 */  addiu      $a1, $zero, 0x2
    /* 6661C 800CEE1C 0400028E */  lw         $v0, 0x4($s0)
    /* 66620 800CEE20 0000128E */  lw         $s2, 0x0($s0)
    /* 66624 800CEE24 09F84000 */  jalr       $v0
    /* 66628 800CEE28 21300000 */   addu      $a2, $zero, $zero
    /* 6662C 800CEE2C 03004014 */  bnez       $v0, .L800CEE3C
    /* 66630 800CEE30 21202002 */   addu      $a0, $s1, $zero
    /* 66634 800CEE34 C33D030C */  jal        func_800CF70C
    /* 66638 800CEE38 21280002 */   addu      $a1, $s0, $zero
  .L800CEE3C:
    /* 6663C 800CEE3C 21804002 */  addu       $s0, $s2, $zero
    /* 66640 800CEE40 F5FF0016 */  bnez       $s0, .L800CEE18
    /* 66644 800CEE44 21200002 */   addu      $a0, $s0, $zero
  .L800CEE48:
    /* 66648 800CEE48 7654030C */  jal        func_800D51D8
    /* 6664C 800CEE4C 21202002 */   addu      $a0, $s1, $zero
    /* 66650 800CEE50 07004014 */  bnez       $v0, .L800CEE70
    /* 66654 800CEE54 00000000 */   nop
    /* 66658 800CEE58 853D030C */  jal        func_800CF614
    /* 6665C 800CEE5C 21202002 */   addu      $a0, $s1, $zero
    /* 66660 800CEE60 E349030C */  jal        func_800D278C
    /* 66664 800CEE64 00000000 */   nop
    /* 66668 800CEE68 A03B0308 */  j          .L800CEE80
    /* 6666C 800CEE6C 00000000 */   nop
  .L800CEE70:
    /* 66670 800CEE70 16002296 */  lhu        $v0, 0x16($s1)
    /* 66674 800CEE74 00000000 */  nop
    /* 66678 800CEE78 01004224 */  addiu      $v0, $v0, 0x1
    /* 6667C 800CEE7C 160022A6 */  sh         $v0, 0x16($s1)
  .L800CEE80:
    /* 66680 800CEE80 1400228E */  lw         $v0, 0x14($s1)
    /* 66684 800CEE84 21888002 */  addu       $s1, $s4, $zero
    /* 66688 800CEE88 02120200 */  srl        $v0, $v0, 8
    /* 6668C 800CEE8C 07004230 */  andi       $v0, $v0, 0x7
    /* 66690 800CEE90 BEFF2016 */  bnez       $s1, .L800CED8C
    /* 66694 800CEE94 25986202 */   or        $s3, $s3, $v0
  .L800CEE98:
    /* 66698 800CEE98 21106002 */  addu       $v0, $s3, $zero
    /* 6669C 800CEE9C 2400BF8F */  lw         $ra, 0x24($sp)
    /* 666A0 800CEEA0 2000B48F */  lw         $s4, 0x20($sp)
    /* 666A4 800CEEA4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 666A8 800CEEA8 1800B28F */  lw         $s2, 0x18($sp)
    /* 666AC 800CEEAC 1400B18F */  lw         $s1, 0x14($sp)
    /* 666B0 800CEEB0 1000B08F */  lw         $s0, 0x10($sp)
    /* 666B4 800CEEB4 0800E003 */  jr         $ra
    /* 666B8 800CEEB8 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800CED60
