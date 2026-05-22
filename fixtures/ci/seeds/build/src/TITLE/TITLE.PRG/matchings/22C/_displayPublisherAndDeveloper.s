nonmatching _displayPublisherAndDeveloper, 0x2D0

glabel _displayPublisherAndDeveloper
    /* 6D4C 8006F54C 50FFBD27 */  addiu      $sp, $sp, -0xB0
    /* 6D50 8006F550 9000A427 */  addiu      $a0, $sp, 0x90
    /* 6D54 8006F554 21280000 */  addu       $a1, $zero, $zero
    /* 6D58 8006F558 2130A000 */  addu       $a2, $a1, $zero
    /* 6D5C 8006F55C 2138A000 */  addu       $a3, $a1, $zero
    /* 6D60 8006F560 40010224 */  addiu      $v0, $zero, 0x140
    /* 6D64 8006F564 9400A2A7 */  sh         $v0, 0x94($sp)
    /* 6D68 8006F568 00020224 */  addiu      $v0, $zero, 0x200
    /* 6D6C 8006F56C A800BFAF */  sw         $ra, 0xA8($sp)
    /* 6D70 8006F570 A400B3AF */  sw         $s3, 0xA4($sp)
    /* 6D74 8006F574 A000B2AF */  sw         $s2, 0xA0($sp)
    /* 6D78 8006F578 9C00B1AF */  sw         $s1, 0x9C($sp)
    /* 6D7C 8006F57C 9800B0AF */  sw         $s0, 0x98($sp)
    /* 6D80 8006F580 9000A0A7 */  sh         $zero, 0x90($sp)
    /* 6D84 8006F584 9200A0A7 */  sh         $zero, 0x92($sp)
    /* 6D88 8006F588 F5A1000C */  jal        ClearImage
    /* 6D8C 8006F58C 9600A2A7 */   sh        $v0, 0x96($sp)
    /* 6D90 8006F590 4000043C */  lui        $a0, (0x400140 >> 16)
    /* 6D94 8006F594 40018434 */  ori        $a0, $a0, (0x400140 & 0xFFFF)
    /* 6D98 8006F598 0780103C */  lui        $s0, %hi(_publisher)
    /* 6D9C 8006F59C 0C2F1026 */  addiu      $s0, $s0, %lo(_publisher)
    /* 6DA0 8006F5A0 21280002 */  addu       $a1, $s0, $zero
    /* 6DA4 8006F5A4 0100063C */  lui        $a2, (0x10010 >> 16)
    /* 6DA8 8006F5A8 F7A2010C */  jal        _drawImage
    /* 6DAC 8006F5AC 1000C634 */   ori       $a2, $a2, (0x10010 & 0xFFFF)
    /* 6DB0 8006F5B0 40010424 */  addiu      $a0, $zero, 0x140
    /* 6DB4 8006F5B4 20000526 */  addiu      $a1, $s0, 0x20
    /* 6DB8 8006F5B8 3000063C */  lui        $a2, (0x300040 >> 16)
    /* 6DBC 8006F5BC F7A2010C */  jal        _drawImage
    /* 6DC0 8006F5C0 4000C634 */   ori       $a2, $a2, (0x300040 & 0xFFFF)
    /* 6DC4 8006F5C4 1800A427 */  addiu      $a0, $sp, 0x18
    /* 6DC8 8006F5C8 21280000 */  addu       $a1, $zero, $zero
    /* 6DCC 8006F5CC 00010624 */  addiu      $a2, $zero, 0x100
    /* 6DD0 8006F5D0 40010724 */  addiu      $a3, $zero, 0x140
    /* 6DD4 8006F5D4 F0001024 */  addiu      $s0, $zero, 0xF0
    /* 6DD8 8006F5D8 0DAD000C */  jal        SetDefDispEnv
    /* 6DDC 8006F5DC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 6DE0 8006F5E0 3000B127 */  addiu      $s1, $sp, 0x30
    /* 6DE4 8006F5E4 21202002 */  addu       $a0, $s1, $zero
    /* 6DE8 8006F5E8 21280000 */  addu       $a1, $zero, $zero
    /* 6DEC 8006F5EC 2130A000 */  addu       $a2, $a1, $zero
    /* 6DF0 8006F5F0 40010724 */  addiu      $a3, $zero, 0x140
    /* 6DF4 8006F5F4 DDAC000C */  jal        SetDefDrawEnv
    /* 6DF8 8006F5F8 1000B0AF */   sw        $s0, 0x10($sp)
    /* 6DFC 8006F5FC 1800A427 */  addiu      $a0, $sp, 0x18
    /* 6E00 8006F600 08000224 */  addiu      $v0, $zero, 0x8
    /* 6E04 8006F604 2200A2A7 */  sh         $v0, 0x22($sp)
    /* 6E08 8006F608 E0000224 */  addiu      $v0, $zero, 0xE0
    /* 6E0C 8006F60C A0A3000C */  jal        PutDispEnv
    /* 6E10 8006F610 2600A2A7 */   sh        $v0, 0x26($sp)
    /* 6E14 8006F614 2DA3000C */  jal        PutDrawEnv
    /* 6E18 8006F618 21202002 */   addu      $a0, $s1, $zero
    /* 6E1C 8006F61C 94A1000C */  jal        DrawSync
    /* 6E20 8006F620 21200000 */   addu      $a0, $zero, $zero
    /* 6E24 8006F624 B17D000C */  jal        VSync
    /* 6E28 8006F628 21200000 */   addu      $a0, $zero, $zero
    /* 6E2C 8006F62C 6EA1000C */  jal        SetDispMask
    /* 6E30 8006F630 01000424 */   addiu     $a0, $zero, 0x1
    /* 6E34 8006F634 21900000 */  addu       $s2, $zero, $zero
    /* 6E38 8006F638 21980002 */  addu       $s3, $s0, $zero
    /* 6E3C 8006F63C 2000422A */  slti       $v0, $s2, 0x20
  .L8006F640:
    /* 6E40 8006F640 04004010 */  beqz       $v0, .L8006F654
    /* 6E44 8006F644 21380000 */   addu      $a3, $zero, $zero
    /* 6E48 8006F648 1F000224 */  addiu      $v0, $zero, 0x1F
    /* 6E4C 8006F64C 23105200 */  subu       $v0, $v0, $s2
    /* 6E50 8006F650 80380200 */  sll        $a3, $v0, 2
  .L8006F654:
    /* 6E54 8006F654 4C01422A */  slti       $v0, $s2, 0x14C
    /* 6E58 8006F658 02004014 */  bnez       $v0, .L8006F664
    /* 6E5C 8006F65C B5FE4226 */   addiu     $v0, $s2, -0x14B
    /* 6E60 8006F660 80380200 */  sll        $a3, $v0, 2
  .L8006F664:
    /* 6E64 8006F664 5800043C */  lui        $a0, (0x580020 >> 16)
    /* 6E68 8006F668 20008434 */  ori        $a0, $a0, (0x580020 & 0xFFFF)
    /* 6E6C 8006F66C 1410053C */  lui        $a1, (0x10140000 >> 16)
    /* 6E70 8006F670 3000063C */  lui        $a2, (0x300100 >> 16)
    /* 6E74 8006F674 0001C634 */  ori        $a2, $a2, (0x300100 & 0xFFFF)
    /* 6E78 8006F678 003C0700 */  sll        $a3, $a3, 16
    /* 6E7C 8006F67C DEA9010C */  jal        _drawSprt
    /* 6E80 8006F680 0500E734 */   ori       $a3, $a3, 0x5
    /* 6E84 8006F684 1800A427 */  addiu      $a0, $sp, 0x18
    /* 6E88 8006F688 21280000 */  addu       $a1, $zero, $zero
    /* 6E8C 8006F68C 01005032 */  andi       $s0, $s2, 0x1
    /* 6E90 8006F690 00321000 */  sll        $a2, $s0, 8
    /* 6E94 8006F694 40010724 */  addiu      $a3, $zero, 0x140
    /* 6E98 8006F698 0DAD000C */  jal        SetDefDispEnv
    /* 6E9C 8006F69C 1000B3AF */   sw        $s3, 0x10($sp)
    /* 6EA0 8006F6A0 21202002 */  addu       $a0, $s1, $zero
    /* 6EA4 8006F6A4 21280000 */  addu       $a1, $zero, $zero
    /* 6EA8 8006F6A8 01000624 */  addiu      $a2, $zero, 0x1
    /* 6EAC 8006F6AC 2330D000 */  subu       $a2, $a2, $s0
    /* 6EB0 8006F6B0 00320600 */  sll        $a2, $a2, 8
    /* 6EB4 8006F6B4 40010724 */  addiu      $a3, $zero, 0x140
    /* 6EB8 8006F6B8 DDAC000C */  jal        SetDefDrawEnv
    /* 6EBC 8006F6BC 1000B3AF */   sw        $s3, 0x10($sp)
    /* 6EC0 8006F6C0 21200000 */  addu       $a0, $zero, $zero
    /* 6EC4 8006F6C4 08000224 */  addiu      $v0, $zero, 0x8
    /* 6EC8 8006F6C8 2200A2A7 */  sh         $v0, 0x22($sp)
    /* 6ECC 8006F6CC E0000224 */  addiu      $v0, $zero, 0xE0
    /* 6ED0 8006F6D0 B17D000C */  jal        VSync
    /* 6ED4 8006F6D4 2600A2A7 */   sh        $v0, 0x26($sp)
    /* 6ED8 8006F6D8 A0A3000C */  jal        PutDispEnv
    /* 6EDC 8006F6DC 1800A427 */   addiu     $a0, $sp, 0x18
    /* 6EE0 8006F6E0 2DA3000C */  jal        PutDrawEnv
    /* 6EE4 8006F6E4 21202002 */   addu      $a0, $s1, $zero
    /* 6EE8 8006F6E8 01005226 */  addiu      $s2, $s2, 0x1
    /* 6EEC 8006F6EC 6C01422A */  slti       $v0, $s2, 0x16C
    /* 6EF0 8006F6F0 D3FF4014 */  bnez       $v0, .L8006F640
    /* 6EF4 8006F6F4 2000422A */   slti      $v0, $s2, 0x20
    /* 6EF8 8006F6F8 F000043C */  lui        $a0, (0xF00000 >> 16)
    /* 6EFC 8006F6FC 0780053C */  lui        $a1, %hi(_developer)
    /* 6F00 8006F700 2C47A524 */  addiu      $a1, $a1, %lo(_developer)
    /* 6F04 8006F704 0E00063C */  lui        $a2, (0xE0020 >> 16)
    /* 6F08 8006F708 F7A2010C */  jal        _drawImage
    /* 6F0C 8006F70C 2000C634 */   ori       $a2, $a2, (0xE0020 & 0xFFFF)
    /* 6F10 8006F710 21900000 */  addu       $s2, $zero, $zero
    /* 6F14 8006F714 F0001324 */  addiu      $s3, $zero, 0xF0
    /* 6F18 8006F718 2000422A */  slti       $v0, $s2, 0x20
  .L8006F71C:
    /* 6F1C 8006F71C 05004010 */  beqz       $v0, .L8006F734
    /* 6F20 8006F720 21380000 */   addu      $a3, $zero, $zero
    /* 6F24 8006F724 1F000224 */  addiu      $v0, $zero, 0x1F
    /* 6F28 8006F728 23105200 */  subu       $v0, $v0, $s2
    /* 6F2C 8006F72C D8BD0108 */  j          .L8006F760
    /* 6F30 8006F730 80380200 */   sll       $a3, $v0, 2
  .L8006F734:
    /* 6F34 8006F734 4C01422A */  slti       $v0, $s2, 0x14C
    /* 6F38 8006F738 04004014 */  bnez       $v0, .L8006F74C
    /* 6F3C 8006F73C 0680023C */   lui       $v0, %hi(vs_main_buttonsState)
    /* 6F40 8006F740 B5FE4226 */  addiu      $v0, $s2, -0x14B
    /* 6F44 8006F744 D8BD0108 */  j          .L8006F760
    /* 6F48 8006F748 80380200 */   sll       $a3, $v0, 2
  .L8006F74C:
    /* 6F4C 8006F74C 38E24294 */  lhu        $v0, %lo(vs_main_buttonsState)($v0)
    /* 6F50 8006F750 00000000 */  nop
    /* 6F54 8006F754 02004010 */  beqz       $v0, .L8006F760
    /* 6F58 8006F758 00000000 */   nop
    /* 6F5C 8006F75C 4B011224 */  addiu      $s2, $zero, 0x14B
  .L8006F760:
    /* 6F60 8006F760 6800043C */  lui        $a0, (0x680060 >> 16)
    /* 6F64 8006F764 60008434 */  ori        $a0, $a0, (0x680060 & 0xFFFF)
    /* 6F68 8006F768 403F053C */  lui        $a1, (0x3F40F000 >> 16)
    /* 6F6C 8006F76C 00F0A534 */  ori        $a1, $a1, (0x3F40F000 & 0xFFFF)
    /* 6F70 8006F770 0D00063C */  lui        $a2, (0xD0080 >> 16)
    /* 6F74 8006F774 8000C634 */  ori        $a2, $a2, (0xD0080 & 0xFFFF)
    /* 6F78 8006F778 DEA9010C */  jal        _drawSprt
    /* 6F7C 8006F77C 003C0700 */   sll       $a3, $a3, 16
    /* 6F80 8006F780 1800A427 */  addiu      $a0, $sp, 0x18
    /* 6F84 8006F784 21280000 */  addu       $a1, $zero, $zero
    /* 6F88 8006F788 01005032 */  andi       $s0, $s2, 0x1
    /* 6F8C 8006F78C 00321000 */  sll        $a2, $s0, 8
    /* 6F90 8006F790 40010724 */  addiu      $a3, $zero, 0x140
    /* 6F94 8006F794 0DAD000C */  jal        SetDefDispEnv
    /* 6F98 8006F798 1000B3AF */   sw        $s3, 0x10($sp)
    /* 6F9C 8006F79C 21202002 */  addu       $a0, $s1, $zero
    /* 6FA0 8006F7A0 21280000 */  addu       $a1, $zero, $zero
    /* 6FA4 8006F7A4 01000624 */  addiu      $a2, $zero, 0x1
    /* 6FA8 8006F7A8 2330D000 */  subu       $a2, $a2, $s0
    /* 6FAC 8006F7AC 00320600 */  sll        $a2, $a2, 8
    /* 6FB0 8006F7B0 40010724 */  addiu      $a3, $zero, 0x140
    /* 6FB4 8006F7B4 DDAC000C */  jal        SetDefDrawEnv
    /* 6FB8 8006F7B8 1000B3AF */   sw        $s3, 0x10($sp)
    /* 6FBC 8006F7BC 21200000 */  addu       $a0, $zero, $zero
    /* 6FC0 8006F7C0 08000224 */  addiu      $v0, $zero, 0x8
    /* 6FC4 8006F7C4 2200A2A7 */  sh         $v0, 0x22($sp)
    /* 6FC8 8006F7C8 E0000224 */  addiu      $v0, $zero, 0xE0
    /* 6FCC 8006F7CC B17D000C */  jal        VSync
    /* 6FD0 8006F7D0 2600A2A7 */   sh        $v0, 0x26($sp)
    /* 6FD4 8006F7D4 500E010C */  jal        vs_main_processPadState
    /* 6FD8 8006F7D8 01005226 */   addiu     $s2, $s2, 0x1
    /* 6FDC 8006F7DC A0A3000C */  jal        PutDispEnv
    /* 6FE0 8006F7E0 1800A427 */   addiu     $a0, $sp, 0x18
    /* 6FE4 8006F7E4 2DA3000C */  jal        PutDrawEnv
    /* 6FE8 8006F7E8 21202002 */   addu      $a0, $s1, $zero
    /* 6FEC 8006F7EC 6C01422A */  slti       $v0, $s2, 0x16C
    /* 6FF0 8006F7F0 CAFF4014 */  bnez       $v0, .L8006F71C
    /* 6FF4 8006F7F4 2000422A */   slti      $v0, $s2, 0x20
    /* 6FF8 8006F7F8 6EA1000C */  jal        SetDispMask
    /* 6FFC 8006F7FC 21200000 */   addu      $a0, $zero, $zero
    /* 7000 8006F800 A800BF8F */  lw         $ra, 0xA8($sp)
    /* 7004 8006F804 A400B38F */  lw         $s3, 0xA4($sp)
    /* 7008 8006F808 A000B28F */  lw         $s2, 0xA0($sp)
    /* 700C 8006F80C 9C00B18F */  lw         $s1, 0x9C($sp)
    /* 7010 8006F810 9800B08F */  lw         $s0, 0x98($sp)
    /* 7014 8006F814 0800E003 */  jr         $ra
    /* 7018 8006F818 B000BD27 */   addiu     $sp, $sp, 0xB0
endlabel _displayPublisherAndDeveloper
