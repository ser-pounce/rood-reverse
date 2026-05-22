nonmatching func_800F9FB8, 0x15C

glabel func_800F9FB8
    /* 7B8 800F9FB8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 7BC 800F9FBC E000043C */  lui        $a0, (0xE00140 >> 16)
    /* 7C0 800F9FC0 40018434 */  ori        $a0, $a0, (0xE00140 & 0xFFFF)
    /* 7C4 800F9FC4 06000524 */  addiu      $a1, $zero, 0x6
    /* 7C8 800F9FC8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 7CC 800F9FCC 21980000 */  addu       $s3, $zero, $zero
    /* 7D0 800F9FD0 801F033C */  lui        $v1, (0x1F800000 >> 16)
    /* 7D4 800F9FD4 00006224 */  addiu      $v0, $v1, %lo(D_1F800000)
    /* 7D8 800F9FD8 2400BFAF */  sw         $ra, 0x24($sp)
    /* 7DC 800F9FDC 2000B4AF */  sw         $s4, 0x20($sp)
    /* 7E0 800F9FE0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 7E4 800F9FE4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7E8 800F9FE8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7EC 800F9FEC 0800548C */  lw         $s4, 0x8($v0)
    /* 7F0 800F9FF0 0000668C */  lw         $a2, (0x1F800000 & 0xFFFF)($v1)
    /* 7F4 800F9FF4 AFE7030C */  jal        func_800F9EBC
    /* 7F8 800F9FF8 21388002 */   addu      $a3, $s4, $zero
    /* 7FC 800F9FFC E000043C */  lui        $a0, (0xE00000 >> 16)
    /* 800 800FA000 16000524 */  addiu      $a1, $zero, 0x16
    /* 804 800FA004 21304000 */  addu       $a2, $v0, $zero
    /* 808 800FA008 AFE7030C */  jal        func_800F9EBC
    /* 80C 800FA00C 21388002 */   addu      $a3, $s4, $zero
    /* 810 800FA010 21206002 */  addu       $a0, $s3, $zero
    /* 814 800FA014 26000524 */  addiu      $a1, $zero, 0x26
    /* 818 800FA018 21304000 */  addu       $a2, $v0, $zero
    /* 81C 800FA01C AFE7030C */  jal        func_800F9EBC
    /* 820 800FA020 21388002 */   addu      $a3, $s4, $zero
    /* 824 800FA024 40010424 */  addiu      $a0, $zero, 0x140
    /* 828 800FA028 36000524 */  addiu      $a1, $zero, 0x36
    /* 82C 800FA02C 21304000 */  addu       $a2, $v0, $zero
    /* 830 800FA030 AFE7030C */  jal        func_800F9EBC
    /* 834 800FA034 21388002 */   addu      $a3, $s4, $zero
    /* 838 800FA038 21904000 */  addu       $s2, $v0, $zero
    /* 83C 800FA03C 24005126 */  addiu      $s1, $s2, 0x24
  .L800FA040:
    /* 840 800FA040 FF00023C */  lui        $v0, (0xFFFFFF >> 16)
    /* 844 800FA044 FFFF4234 */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* 848 800FA048 00E1073C */  lui        $a3, (0xE1000220 >> 16)
    /* 84C 800FA04C 2002E734 */  ori        $a3, $a3, (0xE1000220 & 0xFFFF)
    /* 850 800FA050 A03A063C */  lui        $a2, (0x3AA0A0A0 >> 16)
    /* 854 800FA054 A0A0C634 */  ori        $a2, $a2, (0x3AA0A0A0 & 0xFFFF)
    /* 858 800FA058 01007026 */  addiu      $s0, $s3, 0x1
    /* 85C 800FA05C 21200002 */  addu       $a0, $s0, $zero
    /* 860 800FA060 0000838E */  lw         $v1, 0x0($s4)
    /* 864 800FA064 80000524 */  addiu      $a1, $zero, 0x80
    /* 868 800FA068 24186200 */  and        $v1, $v1, $v0
    /* 86C 800FA06C 0009023C */  lui        $v0, (0x9000000 >> 16)
    /* 870 800FA070 25186200 */  or         $v1, $v1, $v0
    /* 874 800FA074 000043AE */  sw         $v1, 0x0($s2)
    /* 878 800FA078 E0FF27AE */  sw         $a3, -0x20($s1)
    /* 87C 800FA07C 7EE7030C */  jal        func_800F9DF8
    /* 880 800FA080 E4FF26AE */   sw        $a2, -0x1C($s1)
    /* 884 800FA084 A000033C */  lui        $v1, (0xA0A0A0 >> 16)
    /* 888 800FA088 A0A06334 */  ori        $v1, $v1, (0xA0A0A0 & 0xFFFF)
    /* 88C 800FA08C 21206002 */  addu       $a0, $s3, $zero
    /* 890 800FA090 80000524 */  addiu      $a1, $zero, 0x80
    /* 894 800FA094 E8FF22AE */  sw         $v0, -0x18($s1)
    /* 898 800FA098 7EE7030C */  jal        func_800F9DF8
    /* 89C 800FA09C ECFF23AE */   sw        $v1, -0x14($s1)
    /* 8A0 800FA0A0 21200002 */  addu       $a0, $s0, $zero
    /* 8A4 800FA0A4 60000524 */  addiu      $a1, $zero, 0x60
    /* 8A8 800FA0A8 F0FF22AE */  sw         $v0, -0x10($s1)
    /* 8AC 800FA0AC 7EE7030C */  jal        func_800F9DF8
    /* 8B0 800FA0B0 F4FF20AE */   sw        $zero, -0xC($s1)
    /* 8B4 800FA0B4 21206002 */  addu       $a0, $s3, $zero
    /* 8B8 800FA0B8 60000524 */  addiu      $a1, $zero, 0x60
    /* 8BC 800FA0BC F8FF22AE */  sw         $v0, -0x8($s1)
    /* 8C0 800FA0C0 7EE7030C */  jal        func_800F9DF8
    /* 8C4 800FA0C4 FCFF20AE */   sw        $zero, -0x4($s1)
    /* 8C8 800FA0C8 000022AE */  sw         $v0, 0x0($s1)
    /* 8CC 800FA0CC 28003126 */  addiu      $s1, $s1, 0x28
    /* 8D0 800FA0D0 00121200 */  sll        $v0, $s2, 8
    /* 8D4 800FA0D4 21980002 */  addu       $s3, $s0, $zero
    /* 8D8 800FA0D8 02120200 */  srl        $v0, $v0, 8
    /* 8DC 800FA0DC 000082AE */  sw         $v0, 0x0($s4)
    /* 8E0 800FA0E0 4000622A */  slti       $v0, $s3, 0x40
    /* 8E4 800FA0E4 D6FF4014 */  bnez       $v0, .L800FA040
    /* 8E8 800FA0E8 28005226 */   addiu     $s2, $s2, 0x28
    /* 8EC 800FA0EC 2400BF8F */  lw         $ra, 0x24($sp)
    /* 8F0 800FA0F0 2000B48F */  lw         $s4, 0x20($sp)
    /* 8F4 800FA0F4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 8F8 800FA0F8 801F023C */  lui        $v0, (0x1F800000 >> 16)
    /* 8FC 800FA0FC 000052AC */  sw         $s2, (0x1F800000 & 0xFFFF)($v0)
    /* 900 800FA100 1800B28F */  lw         $s2, 0x18($sp)
    /* 904 800FA104 1400B18F */  lw         $s1, 0x14($sp)
    /* 908 800FA108 1000B08F */  lw         $s0, 0x10($sp)
    /* 90C 800FA10C 0800E003 */  jr         $ra
    /* 910 800FA110 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800F9FB8
