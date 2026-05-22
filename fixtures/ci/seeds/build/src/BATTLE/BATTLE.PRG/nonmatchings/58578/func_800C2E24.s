/* Handwritten function */
nonmatching func_800C2E24, 0x182C

glabel func_800C2E24
    /* 5A624 800C2E24 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 5A628 800C2E28 3000BEAF */  sw         $fp, 0x30($sp)
    /* 5A62C 800C2E2C 21F08000 */  addu       $fp, $a0, $zero
    /* 5A630 800C2E30 2000B4AF */  sw         $s4, 0x20($sp)
    /* 5A634 800C2E34 801F143C */  lui        $s4, (0x1F800088 >> 16)
    /* 5A638 800C2E38 88009436 */  ori        $s4, $s4, (0x1F800088 & 0xFFFF)
    /* 5A63C 800C2E3C 0101043C */  lui        $a0, (0x1010101 >> 16)
    /* 5A640 800C2E40 01018434 */  ori        $a0, $a0, (0x1010101 & 0xFFFF)
    /* 5A644 800C2E44 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5A648 800C2E48 14001224 */  addiu      $s2, $zero, 0x14
    /* 5A64C 800C2E4C 801F033C */  lui        $v1, (0x1F8000D8 >> 16)
    /* 5A650 800C2E50 0F80023C */  lui        $v0, %hi(D_800EB9B8)
    /* 5A654 800C2E54 B8B9428C */  lw         $v0, %lo(D_800EB9B8)($v0)
    /* 5A658 800C2E58 D8006334 */  ori        $v1, $v1, (0x1F8000D8 & 0xFFFF)
    /* 5A65C 800C2E5C 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 5A660 800C2E60 2800B6AF */  sw         $s6, 0x28($sp)
    /* 5A664 800C2E64 2400B5AF */  sw         $s5, 0x24($sp)
    /* 5A668 800C2E68 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 5A66C 800C2E6C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5A670 800C2E70 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5A674 800C2E74 3C00A5AF */  sw         $a1, 0x3C($sp)
    /* 5A678 800C2E78 4000A6AF */  sw         $a2, 0x40($sp)
    /* 5A67C 800C2E7C 0800B4AF */  sw         $s4, 0x8($sp)
    /* 5A680 800C2E80 70434524 */  addiu      $a1, $v0, 0x4370
  .L800C2E84:
    /* 5A684 800C2E84 000064AC */  sw         $a0, 0x0($v1)
    /* 5A688 800C2E88 FFFF5226 */  addiu      $s2, $s2, -0x1
    /* 5A68C 800C2E8C FDFF4106 */  bgez       $s2, .L800C2E84
    /* 5A690 800C2E90 FCFF6324 */   addiu     $v1, $v1, -0x4
    /* 5A694 800C2E94 0800B48F */  lw         $s4, 0x8($sp)
    /* 5A698 800C2E98 15001224 */  addiu      $s2, $zero, 0x15
    /* 5A69C 800C2E9C 54008326 */  addiu      $v1, $s4, 0x54
    /* 5A6A0 800C2EA0 530080A2 */  sb         $zero, 0x53($s4)
  .L800C2EA4:
    /* 5A6A4 800C2EA4 000060AC */  sw         $zero, 0x0($v1)
    /* 5A6A8 800C2EA8 01005226 */  addiu      $s2, $s2, 0x1
    /* 5A6AC 800C2EAC 7A00422A */  slti       $v0, $s2, 0x7A
    /* 5A6B0 800C2EB0 FCFF4014 */  bnez       $v0, .L800C2EA4
    /* 5A6B4 800C2EB4 04006324 */   addiu     $v1, $v1, 0x4
    /* 5A6B8 800C2EB8 0F80023C */  lui        $v0, %hi(D_800EB9B8)
    /* 5A6BC 800C2EBC B8B9428C */  lw         $v0, %lo(D_800EB9B8)($v0)
    /* 5A6C0 800C2EC0 00000000 */  nop
    /* 5A6C4 800C2EC4 22004284 */  lh         $v0, 0x22($v0)
    /* 5A6C8 800C2EC8 0200D687 */  lh         $s6, 0x2($fp)
    /* 5A6CC 800C2ECC 00FE4224 */  addiu      $v0, $v0, -0x200
    /* 5A6D0 800C2ED0 83120200 */  sra        $v0, $v0, 10
    /* 5A6D4 800C2ED4 03004330 */  andi       $v1, $v0, 0x3
    /* 5A6D8 800C2ED8 01000224 */  addiu      $v0, $zero, 0x1
    /* 5A6DC 800C2EDC 34006210 */  beq        $v1, $v0, .L800C2FB0
    /* 5A6E0 800C2EE0 21900000 */   addu      $s2, $zero, $zero
    /* 5A6E4 800C2EE4 02006228 */  slti       $v0, $v1, 0x2
    /* 5A6E8 800C2EE8 05004010 */  beqz       $v0, .L800C2F00
    /* 5A6EC 800C2EEC 02000224 */   addiu     $v0, $zero, 0x2
    /* 5A6F0 800C2EF0 09006010 */  beqz       $v1, .L800C2F18
    /* 5A6F4 800C2EF4 21C00000 */   addu      $t8, $zero, $zero
    /* 5A6F8 800C2EF8 5A0C0308 */  j          .L800C3168
    /* 5A6FC 800C2EFC 00000000 */   nop
  .L800C2F00:
    /* 5A700 800C2F00 51006210 */  beq        $v1, $v0, .L800C3048
    /* 5A704 800C2F04 03000224 */   addiu     $v0, $zero, 0x3
    /* 5A708 800C2F08 74006210 */  beq        $v1, $v0, .L800C30DC
    /* 5A70C 800C2F0C 08000E24 */   addiu     $t6, $zero, 0x8
    /* 5A710 800C2F10 5A0C0308 */  j          .L800C3168
    /* 5A714 800C2F14 00000000 */   nop
  .L800C2F18:
    /* 5A718 800C2F18 0800B48F */  lw         $s4, 0x8($sp)
    /* 5A71C 800C2F1C 21700000 */  addu       $t6, $zero, $zero
    /* 5A720 800C2F20 21205402 */  addu       $a0, $s2, $s4
  .L800C2F24:
    /* 5A724 800C2F24 2110D801 */  addu       $v0, $t6, $t8
    /* 5A728 800C2F28 80100200 */  sll        $v0, $v0, 2
    /* 5A72C 800C2F2C 21104500 */  addu       $v0, $v0, $a1
    /* 5A730 800C2F30 0000488C */  lw         $t0, 0x0($v0)
    /* 5A734 800C2F34 00000000 */  nop
    /* 5A738 800C2F38 C0130800 */  sll        $v0, $t0, 15
    /* 5A73C 800C2F3C 43540200 */  sra        $t2, $v0, 17
    /* 5A740 800C2F40 2A10CA02 */  slt        $v0, $s6, $t2
    /* 5A744 800C2F44 0A004014 */  bnez       $v0, .L800C2F70
    /* 5A748 800C2F48 435C0800 */   sra       $t3, $t0, 17
    /* 5A74C 800C2F4C 01000231 */  andi       $v0, $t0, 0x1
    /* 5A750 800C2F50 0C004010 */  beqz       $v0, .L800C2F84
    /* 5A754 800C2F54 2318CA02 */   subu      $v1, $s6, $t2
    /* 5A758 800C2F58 31006228 */  slti       $v0, $v1, 0x31
    /* 5A75C 800C2F5C 02004014 */  bnez       $v0, .L800C2F68
    /* 5A760 800C2F60 00000000 */   nop
    /* 5A764 800C2F64 30000324 */  addiu      $v1, $zero, 0x30
  .L800C2F68:
    /* 5A768 800C2F68 E10B0308 */  j          .L800C2F84
    /* 5A76C 800C2F6C 000083A0 */   sb        $v1, 0x0($a0)
  .L800C2F70:
    /* 5A770 800C2F70 03006011 */  beqz       $t3, .L800C2F80
    /* 5A774 800C2F74 2A107601 */   slt       $v0, $t3, $s6
    /* 5A778 800C2F78 02004010 */  beqz       $v0, .L800C2F84
    /* 5A77C 800C2F7C 00000000 */   nop
  .L800C2F80:
    /* 5A780 800C2F80 000080A0 */  sb         $zero, 0x0($a0)
  .L800C2F84:
    /* 5A784 800C2F84 01008424 */  addiu      $a0, $a0, 0x1
    /* 5A788 800C2F88 0100CE25 */  addiu      $t6, $t6, 0x1
    /* 5A78C 800C2F8C 0900C229 */  slti       $v0, $t6, 0x9
    /* 5A790 800C2F90 E4FF4014 */  bnez       $v0, .L800C2F24
    /* 5A794 800C2F94 01005226 */   addiu     $s2, $s2, 0x1
    /* 5A798 800C2F98 09001827 */  addiu      $t8, $t8, 0x9
    /* 5A79C 800C2F9C 4900022B */  slti       $v0, $t8, 0x49
    /* 5A7A0 800C2FA0 71004010 */  beqz       $v0, .L800C3168
    /* 5A7A4 800C2FA4 00000000 */   nop
    /* 5A7A8 800C2FA8 C60B0308 */  j          .L800C2F18
    /* 5A7AC 800C2FAC 00000000 */   nop
  .L800C2FB0:
    /* 5A7B0 800C2FB0 21700000 */  addu       $t6, $zero, $zero
  .L800C2FB4:
    /* 5A7B4 800C2FB4 0800B48F */  lw         $s4, 0x8($sp)
    /* 5A7B8 800C2FB8 48001824 */  addiu      $t8, $zero, 0x48
    /* 5A7BC 800C2FBC 21205402 */  addu       $a0, $s2, $s4
  .L800C2FC0:
    /* 5A7C0 800C2FC0 2110D801 */  addu       $v0, $t6, $t8
    /* 5A7C4 800C2FC4 80100200 */  sll        $v0, $v0, 2
    /* 5A7C8 800C2FC8 21104500 */  addu       $v0, $v0, $a1
    /* 5A7CC 800C2FCC 0000488C */  lw         $t0, 0x0($v0)
    /* 5A7D0 800C2FD0 00000000 */  nop
    /* 5A7D4 800C2FD4 C0130800 */  sll        $v0, $t0, 15
    /* 5A7D8 800C2FD8 43540200 */  sra        $t2, $v0, 17
    /* 5A7DC 800C2FDC 2A10CA02 */  slt        $v0, $s6, $t2
    /* 5A7E0 800C2FE0 0A004014 */  bnez       $v0, .L800C300C
    /* 5A7E4 800C2FE4 435C0800 */   sra       $t3, $t0, 17
    /* 5A7E8 800C2FE8 01000231 */  andi       $v0, $t0, 0x1
    /* 5A7EC 800C2FEC 0C004010 */  beqz       $v0, .L800C3020
    /* 5A7F0 800C2FF0 2318CA02 */   subu      $v1, $s6, $t2
    /* 5A7F4 800C2FF4 31006228 */  slti       $v0, $v1, 0x31
    /* 5A7F8 800C2FF8 02004014 */  bnez       $v0, .L800C3004
    /* 5A7FC 800C2FFC 00000000 */   nop
    /* 5A800 800C3000 30000324 */  addiu      $v1, $zero, 0x30
  .L800C3004:
    /* 5A804 800C3004 080C0308 */  j          .L800C3020
    /* 5A808 800C3008 000083A0 */   sb        $v1, 0x0($a0)
  .L800C300C:
    /* 5A80C 800C300C 03006011 */  beqz       $t3, .L800C301C
    /* 5A810 800C3010 2A107601 */   slt       $v0, $t3, $s6
    /* 5A814 800C3014 02004010 */  beqz       $v0, .L800C3020
    /* 5A818 800C3018 00000000 */   nop
  .L800C301C:
    /* 5A81C 800C301C 000080A0 */  sb         $zero, 0x0($a0)
  .L800C3020:
    /* 5A820 800C3020 01008424 */  addiu      $a0, $a0, 0x1
    /* 5A824 800C3024 F7FF1827 */  addiu      $t8, $t8, -0x9
    /* 5A828 800C3028 E5FF0107 */  bgez       $t8, .L800C2FC0
    /* 5A82C 800C302C 01005226 */   addiu     $s2, $s2, 0x1
    /* 5A830 800C3030 0100CE25 */  addiu      $t6, $t6, 0x1
    /* 5A834 800C3034 0900C229 */  slti       $v0, $t6, 0x9
    /* 5A838 800C3038 4B004010 */  beqz       $v0, .L800C3168
    /* 5A83C 800C303C 00000000 */   nop
    /* 5A840 800C3040 ED0B0308 */  j          .L800C2FB4
    /* 5A844 800C3044 00000000 */   nop
  .L800C3048:
    /* 5A848 800C3048 48001824 */  addiu      $t8, $zero, 0x48
  .L800C304C:
    /* 5A84C 800C304C 0800B48F */  lw         $s4, 0x8($sp)
    /* 5A850 800C3050 08000E24 */  addiu      $t6, $zero, 0x8
    /* 5A854 800C3054 21205402 */  addu       $a0, $s2, $s4
  .L800C3058:
    /* 5A858 800C3058 2110D801 */  addu       $v0, $t6, $t8
    /* 5A85C 800C305C 80100200 */  sll        $v0, $v0, 2
    /* 5A860 800C3060 21104500 */  addu       $v0, $v0, $a1
    /* 5A864 800C3064 0000488C */  lw         $t0, 0x0($v0)
    /* 5A868 800C3068 00000000 */  nop
    /* 5A86C 800C306C C0130800 */  sll        $v0, $t0, 15
    /* 5A870 800C3070 43540200 */  sra        $t2, $v0, 17
    /* 5A874 800C3074 2A10CA02 */  slt        $v0, $s6, $t2
    /* 5A878 800C3078 0A004014 */  bnez       $v0, .L800C30A4
    /* 5A87C 800C307C 435C0800 */   sra       $t3, $t0, 17
    /* 5A880 800C3080 01000231 */  andi       $v0, $t0, 0x1
    /* 5A884 800C3084 0C004010 */  beqz       $v0, .L800C30B8
    /* 5A888 800C3088 2318CA02 */   subu      $v1, $s6, $t2
    /* 5A88C 800C308C 31006228 */  slti       $v0, $v1, 0x31
    /* 5A890 800C3090 02004014 */  bnez       $v0, .L800C309C
    /* 5A894 800C3094 00000000 */   nop
    /* 5A898 800C3098 30000324 */  addiu      $v1, $zero, 0x30
  .L800C309C:
    /* 5A89C 800C309C 2E0C0308 */  j          .L800C30B8
    /* 5A8A0 800C30A0 000083A0 */   sb        $v1, 0x0($a0)
  .L800C30A4:
    /* 5A8A4 800C30A4 03006011 */  beqz       $t3, .L800C30B4
    /* 5A8A8 800C30A8 2A107601 */   slt       $v0, $t3, $s6
    /* 5A8AC 800C30AC 02004010 */  beqz       $v0, .L800C30B8
    /* 5A8B0 800C30B0 00000000 */   nop
  .L800C30B4:
    /* 5A8B4 800C30B4 000080A0 */  sb         $zero, 0x0($a0)
  .L800C30B8:
    /* 5A8B8 800C30B8 01008424 */  addiu      $a0, $a0, 0x1
    /* 5A8BC 800C30BC FFFFCE25 */  addiu      $t6, $t6, -0x1
    /* 5A8C0 800C30C0 E5FFC105 */  bgez       $t6, .L800C3058
    /* 5A8C4 800C30C4 01005226 */   addiu     $s2, $s2, 0x1
    /* 5A8C8 800C30C8 F7FF1827 */  addiu      $t8, $t8, -0x9
    /* 5A8CC 800C30CC 26000007 */  bltz       $t8, .L800C3168
    /* 5A8D0 800C30D0 00000000 */   nop
    /* 5A8D4 800C30D4 130C0308 */  j          .L800C304C
    /* 5A8D8 800C30D8 00000000 */   nop
  .L800C30DC:
    /* 5A8DC 800C30DC 0800B48F */  lw         $s4, 0x8($sp)
    /* 5A8E0 800C30E0 21C00000 */  addu       $t8, $zero, $zero
    /* 5A8E4 800C30E4 21205402 */  addu       $a0, $s2, $s4
  .L800C30E8:
    /* 5A8E8 800C30E8 2110D801 */  addu       $v0, $t6, $t8
    /* 5A8EC 800C30EC 80100200 */  sll        $v0, $v0, 2
    /* 5A8F0 800C30F0 21104500 */  addu       $v0, $v0, $a1
    /* 5A8F4 800C30F4 0000488C */  lw         $t0, 0x0($v0)
    /* 5A8F8 800C30F8 00000000 */  nop
    /* 5A8FC 800C30FC C0130800 */  sll        $v0, $t0, 15
    /* 5A900 800C3100 43540200 */  sra        $t2, $v0, 17
    /* 5A904 800C3104 2A10CA02 */  slt        $v0, $s6, $t2
    /* 5A908 800C3108 0A004014 */  bnez       $v0, .L800C3134
    /* 5A90C 800C310C 435C0800 */   sra       $t3, $t0, 17
    /* 5A910 800C3110 01000231 */  andi       $v0, $t0, 0x1
    /* 5A914 800C3114 0C004010 */  beqz       $v0, .L800C3148
    /* 5A918 800C3118 2318CA02 */   subu      $v1, $s6, $t2
    /* 5A91C 800C311C 31006228 */  slti       $v0, $v1, 0x31
    /* 5A920 800C3120 02004014 */  bnez       $v0, .L800C312C
    /* 5A924 800C3124 00000000 */   nop
    /* 5A928 800C3128 30000324 */  addiu      $v1, $zero, 0x30
  .L800C312C:
    /* 5A92C 800C312C 520C0308 */  j          .L800C3148
    /* 5A930 800C3130 000083A0 */   sb        $v1, 0x0($a0)
  .L800C3134:
    /* 5A934 800C3134 03006011 */  beqz       $t3, .L800C3144
    /* 5A938 800C3138 2A107601 */   slt       $v0, $t3, $s6
    /* 5A93C 800C313C 02004010 */  beqz       $v0, .L800C3148
    /* 5A940 800C3140 00000000 */   nop
  .L800C3144:
    /* 5A944 800C3144 000080A0 */  sb         $zero, 0x0($a0)
  .L800C3148:
    /* 5A948 800C3148 01008424 */  addiu      $a0, $a0, 0x1
    /* 5A94C 800C314C 09001827 */  addiu      $t8, $t8, 0x9
    /* 5A950 800C3150 4900022B */  slti       $v0, $t8, 0x49
    /* 5A954 800C3154 E4FF4014 */  bnez       $v0, .L800C30E8
    /* 5A958 800C3158 01005226 */   addiu     $s2, $s2, 0x1
    /* 5A95C 800C315C FFFFCE25 */  addiu      $t6, $t6, -0x1
    /* 5A960 800C3160 DEFFC105 */  bgez       $t6, .L800C30DC
    /* 5A964 800C3164 00000000 */   nop
  .L800C3168:
    /* 5A968 800C3168 0800B48F */  lw         $s4, 0x8($sp)
    /* 5A96C 800C316C 21900000 */  addu       $s2, $zero, $zero
    /* 5A970 800C3170 21C04002 */  addu       $t8, $s2, $zero
    /* 5A974 800C3174 01000524 */  addiu      $a1, $zero, 0x1
    /* 5A978 800C3178 34019526 */  addiu      $s5, $s4, 0x134
    /* 5A97C 800C317C 21700000 */  addu       $t6, $zero, $zero
  .L800C3180:
    /* 5A980 800C3180 0800B48F */  lw         $s4, 0x8($sp)
    /* 5A984 800C3184 00000000 */  nop
    /* 5A988 800C3188 21109202 */  addu       $v0, $s4, $s2
    /* 5A98C 800C318C 00004290 */  lbu        $v0, 0x0($v0)
    /* 5A990 800C3190 00000000 */  nop
    /* 5A994 800C3194 0F004014 */  bnez       $v0, .L800C31D4
    /* 5A998 800C3198 01005226 */   addiu     $s2, $s2, 0x1
    /* 5A99C 800C319C 2110D801 */  addu       $v0, $t6, $t8
    /* 5A9A0 800C31A0 2110A202 */  addu       $v0, $s5, $v0
    /* 5A9A4 800C31A4 00004390 */  lbu        $v1, 0x0($v0)
    /* 5A9A8 800C31A8 09004490 */  lbu        $a0, 0x9($v0)
    /* 5A9AC 800C31AC 2318A300 */  subu       $v1, $a1, $v1
    /* 5A9B0 800C31B0 000043A0 */  sb         $v1, 0x0($v0)
    /* 5A9B4 800C31B4 0A004390 */  lbu        $v1, 0xA($v0)
    /* 5A9B8 800C31B8 2320A400 */  subu       $a0, $a1, $a0
    /* 5A9BC 800C31BC 090044A0 */  sb         $a0, 0x9($v0)
    /* 5A9C0 800C31C0 13004490 */  lbu        $a0, 0x13($v0)
    /* 5A9C4 800C31C4 2318A300 */  subu       $v1, $a1, $v1
    /* 5A9C8 800C31C8 2320A400 */  subu       $a0, $a1, $a0
    /* 5A9CC 800C31CC 0A0043A0 */  sb         $v1, 0xA($v0)
    /* 5A9D0 800C31D0 130044A0 */  sb         $a0, 0x13($v0)
  .L800C31D4:
    /* 5A9D4 800C31D4 0100CE25 */  addiu      $t6, $t6, 0x1
    /* 5A9D8 800C31D8 0900C229 */  slti       $v0, $t6, 0x9
    /* 5A9DC 800C31DC E8FF4014 */  bnez       $v0, .L800C3180
    /* 5A9E0 800C31E0 00000000 */   nop
    /* 5A9E4 800C31E4 13001827 */  addiu      $t8, $t8, 0x13
    /* 5A9E8 800C31E8 9900022B */  slti       $v0, $t8, 0x99
    /* 5A9EC 800C31EC E4FF4014 */  bnez       $v0, .L800C3180
    /* 5A9F0 800C31F0 21700000 */   addu      $t6, $zero, $zero
    /* 5A9F4 800C31F4 20FFB726 */  addiu      $s7, $s5, -0xE0
    /* 5A9F8 800C31F8 21900000 */  addu       $s2, $zero, $zero
    /* 5A9FC 800C31FC 007C1600 */  sll        $t7, $s6, 16
    /* 5AA00 800C3200 0F80023C */  lui        $v0, %hi(D_800EA130)
    /* 5AA04 800C3204 30A15024 */  addiu      $s0, $v0, %lo(D_800EA130)
    /* 5AA08 800C3208 2138A002 */  addu       $a3, $s5, $zero
    /* 5AA0C 800C320C 0F80023C */  lui        $v0, %hi(D_800EB9B8)
    /* 5AA10 800C3210 B8B9448C */  lw         $a0, %lo(D_800EB9B8)($v0)
    /* 5AA14 800C3214 0000C297 */  lhu        $v0, 0x0($fp)
    /* 5AA18 800C3218 0400C397 */  lhu        $v1, 0x4($fp)
    /* 5AA1C 800C321C 700B9124 */  addiu      $s1, $a0, 0xB70
    /* 5AA20 800C3220 00140200 */  sll        $v0, $v0, 16
    /* 5AA24 800C3224 C3150200 */  sra        $v0, $v0, 23
    /* 5AA28 800C3228 FCFF4224 */  addiu      $v0, $v0, -0x4
    /* 5AA2C 800C322C C0710200 */  sll        $t6, $v0, 7
    /* 5AA30 800C3230 001C0300 */  sll        $v1, $v1, 16
    /* 5AA34 800C3234 C31D0300 */  sra        $v1, $v1, 23
    /* 5AA38 800C3238 FCFF6324 */  addiu      $v1, $v1, -0x4
    /* 5AA3C 800C323C 22008284 */  lh         $v0, 0x22($a0)
    /* 5AA40 800C3240 C0C10300 */  sll        $t8, $v1, 7
    /* 5AA44 800C3244 00FE4224 */  addiu      $v0, $v0, -0x200
    /* 5AA48 800C3248 83120200 */  sra        $v0, $v0, 10
    /* 5AA4C 800C324C 03004230 */  andi       $v0, $v0, 0x3
    /* 5AA50 800C3250 40180200 */  sll        $v1, $v0, 1
    /* 5AA54 800C3254 21186200 */  addu       $v1, $v1, $v0
    /* 5AA58 800C3258 00110300 */  sll        $v0, $v1, 4
    /* 5AA5C 800C325C 23104300 */  subu       $v0, $v0, $v1
    /* 5AA60 800C3260 C0100200 */  sll        $v0, $v0, 3
    /* 5AA64 800C3264 B4444224 */  addiu      $v0, $v0, 0x44B4
    /* 5AA68 800C3268 21208200 */  addu       $a0, $a0, $v0
    /* 5AA6C 800C326C 21608000 */  addu       $t4, $a0, $zero
    /* 5AA70 800C3270 0000A4AF */  sw         $a0, 0x0($sp)
  .L800C3274:
    /* 5AA74 800C3274 0000E290 */  lbu        $v0, 0x0($a3)
    /* 5AA78 800C3278 00000000 */  nop
    /* 5AA7C 800C327C AB004010 */  beqz       $v0, .L800C352C
    /* 5AA80 800C3280 00000000 */   nop
    /* 5AA84 800C3284 00008895 */  lhu        $t0, 0x0($t4)
    /* 5AA88 800C3288 00000000 */  nop
    /* 5AA8C 800C328C 0F000231 */  andi       $v0, $t0, 0xF
    /* 5AA90 800C3290 C0110200 */  sll        $v0, $v0, 7
    /* 5AA94 800C3294 2110C201 */  addu       $v0, $t6, $v0
    /* 5AA98 800C3298 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 5AA9C 800C329C 25504F00 */  or         $t2, $v0, $t7
    /* 5AAA0 800C32A0 C0100800 */  sll        $v0, $t0, 3
    /* 5AAA4 800C32A4 80074230 */  andi       $v0, $v0, 0x780
    /* 5AAA8 800C32A8 21480203 */  addu       $t1, $t8, $v0
    /* 5AAAC 800C32AC 00008A48 */  mtc2       $t2, $0 /* handwritten instruction */
    /* 5AAB0 800C32B0 00088948 */  mtc2       $t1, $1 /* handwritten instruction */
    /* 5AAB4 800C32B4 42690800 */  srl        $t5, $t0, 5
    /* 5AAB8 800C32B8 8007AD31 */  andi       $t5, $t5, 0x780
    /* 5AABC 800C32BC 0100184A */  rtps
    /* 5AAC0 800C32C0 2168B801 */  addu       $t5, $t5, $t8
    /* 5AAC4 800C32C4 42100800 */  srl        $v0, $t0, 1
    /* 5AAC8 800C32C8 80074230 */  andi       $v0, $v0, 0x780
    /* 5AACC 800C32CC 2110C201 */  addu       $v0, $t6, $v0
    /* 5AAD0 800C32D0 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 5AAD4 800C32D4 25584F00 */  or         $t3, $v0, $t7
    /* 5AAD8 800C32D8 00700A48 */  mfc2       $t2, $14 /* handwritten instruction */
    /* 5AADC 800C32DC 00008B48 */  mtc2       $t3, $0 /* handwritten instruction */
    /* 5AAE0 800C32E0 00088D48 */  mtc2       $t5, $1 /* handwritten instruction */
    /* 5AAE4 800C32E4 034C0A00 */  sra        $t1, $t2, 16
    /* 5AAE8 800C32E8 00540A00 */  sll        $t2, $t2, 16
    /* 5AAEC 800C32EC 0100184A */  rtps
    /* 5AAF0 800C32F0 0000E0A0 */  sb         $zero, 0x0($a3)
    /* 5AAF4 800C32F4 00700B48 */  mfc2       $t3, $14 /* handwritten instruction */
    /* 5AAF8 800C32F8 00800134 */  ori        $at, $zero, 0x8000
    /* 5AAFC 800C32FC 21504101 */  addu       $t2, $t2, $at
    /* 5AB00 800C3300 036C0B00 */  sra        $t5, $t3, 16
    /* 5AB04 800C3304 00140B00 */  sll        $v0, $t3, 16
    /* 5AB08 800C3308 00804B34 */  ori        $t3, $v0, 0x8000
    /* 5AB0C 800C330C 23102D01 */  subu       $v0, $t1, $t5
    /* 5AB10 800C3310 02004224 */  addiu      $v0, $v0, 0x2
    /* 5AB14 800C3314 0500422C */  sltiu      $v0, $v0, 0x5
    /* 5AB18 800C3318 06004010 */  beqz       $v0, .L800C3334
    /* 5AB1C 800C331C 2A106A01 */   slt       $v0, $t3, $t2
    /* 5AB20 800C3320 02004014 */  bnez       $v0, .L800C332C
    /* 5AB24 800C3324 FF000224 */   addiu     $v0, $zero, 0xFF
    /* 5AB28 800C3328 7F000224 */  addiu      $v0, $zero, 0x7F
  .L800C332C:
    /* 5AB2C 800C332C 0000E2A0 */  sb         $v0, 0x0($a3)
    /* 5AB30 800C3330 B400E9A0 */  sb         $t1, 0xB4($a3)
  .L800C3334:
    /* 5AB34 800C3334 2A102D01 */  slt        $v0, $t1, $t5
    /* 5AB38 800C3338 3E004010 */  beqz       $v0, .L800C3434
    /* 5AB3C 800C333C 2A10A901 */   slt       $v0, $t5, $t1
    /* 5AB40 800C3340 7A00A019 */  blez       $t5, .L800C352C
    /* 5AB44 800C3344 E0002229 */   slti      $v0, $t1, 0xE0
    /* 5AB48 800C3348 78004010 */  beqz       $v0, .L800C352C
    /* 5AB4C 800C334C 00000000 */   nop
    /* 5AB50 800C3350 02002105 */  bgez       $t1, .L800C335C
    /* 5AB54 800C3354 21402001 */   addu      $t0, $t1, $zero
    /* 5AB58 800C3358 21400000 */  addu       $t0, $zero, $zero
  .L800C335C:
    /* 5AB5C 800C335C 0000E290 */  lbu        $v0, 0x0($a3)
    /* 5AB60 800C3360 00000000 */  nop
    /* 5AB64 800C3364 13004014 */  bnez       $v0, .L800C33B4
    /* 5AB68 800C3368 23186A01 */   subu      $v1, $t3, $t2
    /* 5AB6C 800C336C 2110E802 */  addu       $v0, $s7, $t0
    /* 5AB70 800C3370 00004390 */  lbu        $v1, 0x0($v0)
    /* 5AB74 800C3374 23106A01 */  subu       $v0, $t3, $t2
    /* 5AB78 800C3378 06004004 */  bltz       $v0, .L800C3394
    /* 5AB7C 800C337C 01006224 */   addiu     $v0, $v1, 0x1
    /* 5AB80 800C3380 01004230 */  andi       $v0, $v0, 0x1
    /* 5AB84 800C3384 06004014 */  bnez       $v0, .L800C33A0
    /* 5AB88 800C3388 2110E802 */   addu      $v0, $s7, $t0
    /* 5AB8C 800C338C ED0C0308 */  j          .L800C33B4
    /* 5AB90 800C3390 23186A01 */   subu      $v1, $t3, $t2
  .L800C3394:
    /* 5AB94 800C3394 01006230 */  andi       $v0, $v1, 0x1
    /* 5AB98 800C3398 05004010 */  beqz       $v0, .L800C33B0
    /* 5AB9C 800C339C 2110E802 */   addu      $v0, $s7, $t0
  .L800C33A0:
    /* 5ABA0 800C33A0 00004290 */  lbu        $v0, 0x0($v0)
    /* 5ABA4 800C33A4 00000000 */  nop
    /* 5ABA8 800C33A8 01004224 */  addiu      $v0, $v0, 0x1
    /* 5ABAC 800C33AC 0000E2A0 */  sb         $v0, 0x0($a3)
  .L800C33B0:
    /* 5ABB0 800C33B0 23186A01 */  subu       $v1, $t3, $t2
  .L800C33B4:
    /* 5ABB4 800C33B4 2310A901 */  subu       $v0, $t5, $t1
    /* 5ABB8 800C33B8 40100200 */  sll        $v0, $v0, 1
    /* 5ABBC 800C33BC 21105000 */  addu       $v0, $v0, $s0
    /* 5ABC0 800C33C0 00004294 */  lhu        $v0, 0x0($v0)
    /* 5ABC4 800C33C4 C31B0300 */  sra        $v1, $v1, 15
    /* 5ABC8 800C33C8 18006200 */  mult       $v1, $v0
    /* 5ABCC 800C33CC E100A229 */  slti       $v0, $t5, 0xE1
    /* 5ABD0 800C33D0 12580000 */  mflo       $t3
    /* 5ABD4 800C33D4 02004014 */  bnez       $v0, .L800C33E0
    /* 5ABD8 800C33D8 00000000 */   nop
    /* 5ABDC 800C33DC E0000D24 */  addiu      $t5, $zero, 0xE0
  .L800C33E0:
    /* 5ABE0 800C33E0 04002105 */  bgez       $t1, .L800C33F4
    /* 5ABE4 800C33E4 B400EDA0 */   sb        $t5, 0xB4($a3)
  .L800C33E8:
    /* 5ABE8 800C33E8 01002925 */  addiu      $t1, $t1, 0x1
    /* 5ABEC 800C33EC FEFF2005 */  bltz       $t1, .L800C33E8
    /* 5ABF0 800C33F0 21504B01 */   addu      $t2, $t2, $t3
  .L800C33F4:
    /* 5ABF4 800C33F4 2128E902 */  addu       $a1, $s7, $t1
    /* 5ABF8 800C33F8 40210900 */  sll        $a0, $t1, 5
    /* 5ABFC 800C33FC 01002925 */  addiu      $t1, $t1, 0x1
    /* 5AC00 800C3400 03340A00 */  sra        $a2, $t2, 16
    /* 5AC04 800C3404 0000A390 */  lbu        $v1, 0x0($a1)
    /* 5AC08 800C3408 21504B01 */  addu       $t2, $t2, $t3
    /* 5AC0C 800C340C 01006224 */  addiu      $v0, $v1, 0x1
    /* 5AC10 800C3410 FF006330 */  andi       $v1, $v1, 0xFF
    /* 5AC14 800C3414 21208300 */  addu       $a0, $a0, $v1
    /* 5AC18 800C3418 40200400 */  sll        $a0, $a0, 1
    /* 5AC1C 800C341C 21209100 */  addu       $a0, $a0, $s1
    /* 5AC20 800C3420 0000A2A0 */  sb         $v0, 0x0($a1)
    /* 5AC24 800C3424 2A102D01 */  slt        $v0, $t1, $t5
    /* 5AC28 800C3428 F2FF4014 */  bnez       $v0, .L800C33F4
    /* 5AC2C 800C342C 000086A4 */   sh        $a2, 0x0($a0)
    /* 5AC30 800C3430 2A10A901 */  slt        $v0, $t5, $t1
  .L800C3434:
    /* 5AC34 800C3434 3D004010 */  beqz       $v0, .L800C352C
    /* 5AC38 800C3438 00000000 */   nop
    /* 5AC3C 800C343C 3B002019 */  blez       $t1, .L800C352C
    /* 5AC40 800C3440 E000A229 */   slti      $v0, $t5, 0xE0
    /* 5AC44 800C3444 39004010 */  beqz       $v0, .L800C352C
    /* 5AC48 800C3448 00000000 */   nop
    /* 5AC4C 800C344C 0200A105 */  bgez       $t5, .L800C3458
    /* 5AC50 800C3450 2140A001 */   addu      $t0, $t5, $zero
    /* 5AC54 800C3454 21400000 */  addu       $t0, $zero, $zero
  .L800C3458:
    /* 5AC58 800C3458 0000E290 */  lbu        $v0, 0x0($a3)
    /* 5AC5C 800C345C 00000000 */  nop
    /* 5AC60 800C3460 13004014 */  bnez       $v0, .L800C34B0
    /* 5AC64 800C3464 23184B01 */   subu      $v1, $t2, $t3
    /* 5AC68 800C3468 2110E802 */  addu       $v0, $s7, $t0
    /* 5AC6C 800C346C 00004390 */  lbu        $v1, 0x0($v0)
    /* 5AC70 800C3470 23104B01 */  subu       $v0, $t2, $t3
    /* 5AC74 800C3474 06004004 */  bltz       $v0, .L800C3490
    /* 5AC78 800C3478 01006224 */   addiu     $v0, $v1, 0x1
    /* 5AC7C 800C347C 01004230 */  andi       $v0, $v0, 0x1
    /* 5AC80 800C3480 06004014 */  bnez       $v0, .L800C349C
    /* 5AC84 800C3484 2110E802 */   addu      $v0, $s7, $t0
    /* 5AC88 800C3488 2C0D0308 */  j          .L800C34B0
    /* 5AC8C 800C348C 23184B01 */   subu      $v1, $t2, $t3
  .L800C3490:
    /* 5AC90 800C3490 01006230 */  andi       $v0, $v1, 0x1
    /* 5AC94 800C3494 05004010 */  beqz       $v0, .L800C34AC
    /* 5AC98 800C3498 2110E802 */   addu      $v0, $s7, $t0
  .L800C349C:
    /* 5AC9C 800C349C 00004290 */  lbu        $v0, 0x0($v0)
    /* 5ACA0 800C34A0 00000000 */  nop
    /* 5ACA4 800C34A4 81004224 */  addiu      $v0, $v0, 0x81
    /* 5ACA8 800C34A8 0000E2A0 */  sb         $v0, 0x0($a3)
  .L800C34AC:
    /* 5ACAC 800C34AC 23184B01 */  subu       $v1, $t2, $t3
  .L800C34B0:
    /* 5ACB0 800C34B0 23102D01 */  subu       $v0, $t1, $t5
    /* 5ACB4 800C34B4 40100200 */  sll        $v0, $v0, 1
    /* 5ACB8 800C34B8 21105000 */  addu       $v0, $v0, $s0
    /* 5ACBC 800C34BC 00004294 */  lhu        $v0, 0x0($v0)
    /* 5ACC0 800C34C0 C31B0300 */  sra        $v1, $v1, 15
    /* 5ACC4 800C34C4 18006200 */  mult       $v1, $v0
    /* 5ACC8 800C34C8 E1002229 */  slti       $v0, $t1, 0xE1
    /* 5ACCC 800C34CC 12500000 */  mflo       $t2
    /* 5ACD0 800C34D0 02004014 */  bnez       $v0, .L800C34DC
    /* 5ACD4 800C34D4 00000000 */   nop
    /* 5ACD8 800C34D8 E0000924 */  addiu      $t1, $zero, 0xE0
  .L800C34DC:
    /* 5ACDC 800C34DC 0400A105 */  bgez       $t5, .L800C34F0
    /* 5ACE0 800C34E0 B400E9A0 */   sb        $t1, 0xB4($a3)
  .L800C34E4:
    /* 5ACE4 800C34E4 0100AD25 */  addiu      $t5, $t5, 0x1
    /* 5ACE8 800C34E8 FEFFA005 */  bltz       $t5, .L800C34E4
    /* 5ACEC 800C34EC 21586A01 */   addu      $t3, $t3, $t2
  .L800C34F0:
    /* 5ACF0 800C34F0 2128ED02 */  addu       $a1, $s7, $t5
    /* 5ACF4 800C34F4 40210D00 */  sll        $a0, $t5, 5
    /* 5ACF8 800C34F8 0100AD25 */  addiu      $t5, $t5, 0x1
    /* 5ACFC 800C34FC 03340B00 */  sra        $a2, $t3, 16
    /* 5AD00 800C3500 0000A390 */  lbu        $v1, 0x0($a1)
    /* 5AD04 800C3504 21586A01 */  addu       $t3, $t3, $t2
    /* 5AD08 800C3508 01006224 */  addiu      $v0, $v1, 0x1
    /* 5AD0C 800C350C FF006330 */  andi       $v1, $v1, 0xFF
    /* 5AD10 800C3510 21208300 */  addu       $a0, $a0, $v1
    /* 5AD14 800C3514 40200400 */  sll        $a0, $a0, 1
    /* 5AD18 800C3518 21209100 */  addu       $a0, $a0, $s1
    /* 5AD1C 800C351C 0000A2A0 */  sb         $v0, 0x0($a1)
    /* 5AD20 800C3520 2A10A901 */  slt        $v0, $t5, $t1
    /* 5AD24 800C3524 F2FF4014 */  bnez       $v0, .L800C34F0
    /* 5AD28 800C3528 000086A4 */   sh        $a2, 0x0($a0)
  .L800C352C:
    /* 5AD2C 800C352C 0100E724 */  addiu      $a3, $a3, 0x1
    /* 5AD30 800C3530 01005226 */  addiu      $s2, $s2, 0x1
    /* 5AD34 800C3534 B400422A */  slti       $v0, $s2, 0xB4
    /* 5AD38 800C3538 4EFF4014 */  bnez       $v0, .L800C3274
    /* 5AD3C 800C353C 02008C25 */   addiu     $t4, $t4, 0x2
    /* 5AD40 800C3540 0A001224 */  addiu      $s2, $zero, 0xA
    /* 5AD44 800C3544 2198B202 */  addu       $s3, $s5, $s2
  .L800C3548:
    /* 5AD48 800C3548 00006692 */  lbu        $a2, 0x0($s3)
    /* 5AD4C 800C354C 00000000 */  nop
    /* 5AD50 800C3550 C801C010 */  beqz       $a2, .L800C3C74
    /* 5AD54 800C3554 0F80023C */   lui       $v0, %hi(D_800EA6B0)
    /* 5AD58 800C3558 B0A64224 */  addiu      $v0, $v0, %lo(D_800EA6B0)
    /* 5AD5C 800C355C 40201200 */  sll        $a0, $s2, 1
    /* 5AD60 800C3560 21108200 */  addu       $v0, $a0, $v0
    /* 5AD64 800C3564 00004894 */  lhu        $t0, 0x0($v0)
    /* 5AD68 800C3568 0800B48F */  lw         $s4, 0x8($sp)
    /* 5AD6C 800C356C FF000331 */  andi       $v1, $t0, 0xFF
    /* 5AD70 800C3570 21188302 */  addu       $v1, $s4, $v1
    /* 5AD74 800C3574 03120800 */  sra        $v0, $t0, 8
    /* 5AD78 800C3578 21108202 */  addu       $v0, $s4, $v0
    /* 5AD7C 800C357C 00006390 */  lbu        $v1, 0x0($v1)
    /* 5AD80 800C3580 00004290 */  lbu        $v0, 0x0($v0)
    /* 5AD84 800C3584 00000000 */  nop
    /* 5AD88 800C3588 21C86200 */  addu       $t9, $v1, $v0
    /* 5AD8C 800C358C 0200222B */  slti       $v0, $t9, 0x2
    /* 5AD90 800C3590 B8014014 */  bnez       $v0, .L800C3C74
    /* 5AD94 800C3594 00000000 */   nop
    /* 5AD98 800C3598 0000B48F */  lw         $s4, 0x0($sp)
    /* 5AD9C 800C359C 00000000 */  nop
    /* 5ADA0 800C35A0 21109400 */  addu       $v0, $a0, $s4
    /* 5ADA4 800C35A4 00004894 */  lhu        $t0, 0x0($v0)
    /* 5ADA8 800C35A8 8000C230 */  andi       $v0, $a2, 0x80
    /* 5ADAC 800C35AC 04004010 */  beqz       $v0, .L800C35C0
    /* 5ADB0 800C35B0 03120800 */   sra       $v0, $t0, 8
    /* 5ADB4 800C35B4 001A0800 */  sll        $v1, $t0, 8
    /* 5ADB8 800C35B8 25104300 */  or         $v0, $v0, $v1
    /* 5ADBC 800C35BC FFFF4830 */  andi       $t0, $v0, 0xFFFF
  .L800C35C0:
    /* 5ADC0 800C35C0 0F000231 */  andi       $v0, $t0, 0xF
    /* 5ADC4 800C35C4 C0110200 */  sll        $v0, $v0, 7
    /* 5ADC8 800C35C8 2110C201 */  addu       $v0, $t6, $v0
    /* 5ADCC 800C35CC FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 5ADD0 800C35D0 2318D902 */  subu       $v1, $s6, $t9
    /* 5ADD4 800C35D4 001C0300 */  sll        $v1, $v1, 16
    /* 5ADD8 800C35D8 25504300 */  or         $t2, $v0, $v1
    /* 5ADDC 800C35DC C0100800 */  sll        $v0, $t0, 3
    /* 5ADE0 800C35E0 80074230 */  andi       $v0, $v0, 0x780
    /* 5ADE4 800C35E4 21480203 */  addu       $t1, $t8, $v0
    /* 5ADE8 800C35E8 00008A48 */  mtc2       $t2, $0 /* handwritten instruction */
    /* 5ADEC 800C35EC 00088948 */  mtc2       $t1, $1 /* handwritten instruction */
    /* 5ADF0 800C35F0 42690800 */  srl        $t5, $t0, 5
    /* 5ADF4 800C35F4 8007AD31 */  andi       $t5, $t5, 0x780
    /* 5ADF8 800C35F8 0100184A */  rtps
    /* 5ADFC 800C35FC 2168B801 */  addu       $t5, $t5, $t8
    /* 5AE00 800C3600 43100800 */  sra        $v0, $t0, 1
    /* 5AE04 800C3604 80074230 */  andi       $v0, $v0, 0x780
    /* 5AE08 800C3608 2110C201 */  addu       $v0, $t6, $v0
    /* 5AE0C 800C360C FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 5AE10 800C3610 25584300 */  or         $t3, $v0, $v1
    /* 5AE14 800C3614 00700A48 */  mfc2       $t2, $14 /* handwritten instruction */
    /* 5AE18 800C3618 00008B48 */  mtc2       $t3, $0 /* handwritten instruction */
    /* 5AE1C 800C361C 00088D48 */  mtc2       $t5, $1 /* handwritten instruction */
    /* 5AE20 800C3620 034C0A00 */  sra        $t1, $t2, 16
    /* 5AE24 800C3624 00540A00 */  sll        $t2, $t2, 16
    /* 5AE28 800C3628 0100184A */  rtps
    /* 5AE2C 800C362C 03CC0A00 */  sra        $t9, $t2, 16
    /* 5AE30 800C3630 00700B48 */  mfc2       $t3, $14 /* handwritten instruction */
    /* 5AE34 800C3634 00800134 */  ori        $at, $zero, 0x8000
    /* 5AE38 800C3638 21504101 */  addu       $t2, $t2, $at
    /* 5AE3C 800C363C 036C0B00 */  sra        $t5, $t3, 16
    /* 5AE40 800C3640 00140B00 */  sll        $v0, $t3, 16
    /* 5AE44 800C3644 8B01A019 */  blez       $t5, .L800C3C74
    /* 5AE48 800C3648 00804B34 */   ori       $t3, $v0, 0x8000
    /* 5AE4C 800C364C 7F00C330 */  andi       $v1, $a2, 0x7F
    /* 5AE50 800C3650 7F000224 */  addiu      $v0, $zero, 0x7F
    /* 5AE54 800C3654 70006214 */  bne        $v1, $v0, .L800C3818
    /* 5AE58 800C3658 2310A901 */   subu      $v0, $t5, $t1
    /* 5AE5C 800C365C 21502003 */  addu       $t2, $t9, $zero
    /* 5AE60 800C3660 B4006D92 */  lbu        $t5, 0xB4($s3)
    /* 5AE64 800C3664 00000000 */  nop
    /* 5AE68 800C3668 E000A229 */  slti       $v0, $t5, 0xE0
    /* 5AE6C 800C366C 02004014 */  bnez       $v0, .L800C3678
    /* 5AE70 800C3670 035C0B00 */   sra       $t3, $t3, 16
    /* 5AE74 800C3674 E0000D24 */  addiu      $t5, $zero, 0xE0
  .L800C3678:
    /* 5AE78 800C3678 03002105 */  bgez       $t1, .L800C3688
    /* 5AE7C 800C367C 2A102D01 */   slt       $v0, $t1, $t5
    /* 5AE80 800C3680 21480000 */  addu       $t1, $zero, $zero
    /* 5AE84 800C3684 2A102D01 */  slt        $v0, $t1, $t5
  .L800C3688:
    /* 5AE88 800C3688 7A014010 */  beqz       $v0, .L800C3C74
    /* 5AE8C 800C368C 21783701 */   addu      $t7, $t1, $s7
  .L800C3690:
    /* 5AE90 800C3690 0000E291 */  lbu        $v0, 0x0($t7)
    /* 5AE94 800C3694 00000000 */  nop
    /* 5AE98 800C3698 58004010 */  beqz       $v0, .L800C37FC
    /* 5AE9C 800C369C 21400000 */   addu      $t0, $zero, $zero
    /* 5AEA0 800C36A0 40610900 */  sll        $t4, $t1, 5
    /* 5AEA4 800C36A4 2138E001 */  addu       $a3, $t7, $zero
    /* 5AEA8 800C36A8 21108801 */  addu       $v0, $t4, $t0
  .L800C36AC:
    /* 5AEAC 800C36AC 40100200 */  sll        $v0, $v0, 1
    /* 5AEB0 800C36B0 21285100 */  addu       $a1, $v0, $s1
    /* 5AEB4 800C36B4 0200A484 */  lh         $a0, 0x2($a1)
    /* 5AEB8 800C36B8 00000000 */  nop
    /* 5AEBC 800C36BC 2A104401 */  slt        $v0, $t2, $a0
    /* 5AEC0 800C36C0 49004010 */  beqz       $v0, .L800C37E8
    /* 5AEC4 800C36C4 00000000 */   nop
    /* 5AEC8 800C36C8 0000A384 */  lh         $v1, 0x0($a1)
    /* 5AECC 800C36CC 00000000 */  nop
    /* 5AED0 800C36D0 2A106B00 */  slt        $v0, $v1, $t3
    /* 5AED4 800C36D4 49004010 */  beqz       $v0, .L800C37FC
    /* 5AED8 800C36D8 2A106401 */   slt       $v0, $t3, $a0
    /* 5AEDC 800C36DC 02004010 */  beqz       $v0, .L800C36E8
    /* 5AEE0 800C36E0 2A186A00 */   slt       $v1, $v1, $t2
    /* 5AEE4 800C36E4 02006324 */  addiu      $v1, $v1, 0x2
  .L800C36E8:
    /* 5AEE8 800C36E8 01000224 */  addiu      $v0, $zero, 0x1
    /* 5AEEC 800C36EC 22006210 */  beq        $v1, $v0, .L800C3778
    /* 5AEF0 800C36F0 02006228 */   slti      $v0, $v1, 0x2
    /* 5AEF4 800C36F4 05004010 */  beqz       $v0, .L800C370C
    /* 5AEF8 800C36F8 02000224 */   addiu     $v0, $zero, 0x2
    /* 5AEFC 800C36FC 09006010 */  beqz       $v1, .L800C3724
    /* 5AF00 800C3700 21300001 */   addu      $a2, $t0, $zero
    /* 5AF04 800C3704 000E0308 */  j          .L800C3800
    /* 5AF08 800C3708 0100EF25 */   addiu     $t7, $t7, 0x1
  .L800C370C:
    /* 5AF0C 800C370C 1C006210 */  beq        $v1, $v0, .L800C3780
    /* 5AF10 800C3710 03000224 */   addiu     $v0, $zero, 0x3
    /* 5AF14 800C3714 1C006210 */  beq        $v1, $v0, .L800C3788
    /* 5AF18 800C3718 00000000 */   nop
    /* 5AF1C 800C371C 000E0308 */  j          .L800C3800
    /* 5AF20 800C3720 0100EF25 */   addiu     $t7, $t7, 0x1
  .L800C3724:
    /* 5AF24 800C3724 0000E290 */  lbu        $v0, 0x0($a3)
    /* 5AF28 800C3728 00000000 */  nop
    /* 5AF2C 800C372C FEFF4224 */  addiu      $v0, $v0, -0x2
    /* 5AF30 800C3730 0000E2A0 */  sb         $v0, 0x0($a3)
    /* 5AF34 800C3734 FF004230 */  andi       $v0, $v0, 0xFF
    /* 5AF38 800C3738 2A10C200 */  slt        $v0, $a2, $v0
    /* 5AF3C 800C373C 2F004010 */  beqz       $v0, .L800C37FC
    /* 5AF40 800C3740 2120E000 */   addu      $a0, $a3, $zero
    /* 5AF44 800C3744 21108601 */  addu       $v0, $t4, $a2
  .L800C3748:
    /* 5AF48 800C3748 40100200 */  sll        $v0, $v0, 1
    /* 5AF4C 800C374C 21105100 */  addu       $v0, $v0, $s1
    /* 5AF50 800C3750 04004394 */  lhu        $v1, 0x4($v0)
    /* 5AF54 800C3754 00000000 */  nop
    /* 5AF58 800C3758 000043A4 */  sh         $v1, 0x0($v0)
    /* 5AF5C 800C375C 00008290 */  lbu        $v0, 0x0($a0)
    /* 5AF60 800C3760 0100C624 */  addiu      $a2, $a2, 0x1
    /* 5AF64 800C3764 2A10C200 */  slt        $v0, $a2, $v0
    /* 5AF68 800C3768 F7FF4014 */  bnez       $v0, .L800C3748
    /* 5AF6C 800C376C 21108601 */   addu      $v0, $t4, $a2
    /* 5AF70 800C3770 000E0308 */  j          .L800C3800
    /* 5AF74 800C3774 0100EF25 */   addiu     $t7, $t7, 0x1
  .L800C3778:
    /* 5AF78 800C3778 FF0D0308 */  j          .L800C37FC
    /* 5AF7C 800C377C 0200AAA4 */   sh        $t2, 0x2($a1)
  .L800C3780:
    /* 5AF80 800C3780 FF0D0308 */  j          .L800C37FC
    /* 5AF84 800C3784 0000ABA4 */   sh        $t3, 0x0($a1)
  .L800C3788:
    /* 5AF88 800C3788 0000E290 */  lbu        $v0, 0x0($a3)
    /* 5AF8C 800C378C 00000000 */  nop
    /* 5AF90 800C3790 FFFF4624 */  addiu      $a2, $v0, -0x1
    /* 5AF94 800C3794 2A100601 */  slt        $v0, $t0, $a2
    /* 5AF98 800C3798 09004010 */  beqz       $v0, .L800C37C0
    /* 5AF9C 800C379C 21108601 */   addu      $v0, $t4, $a2
  .L800C37A0:
    /* 5AFA0 800C37A0 40100200 */  sll        $v0, $v0, 1
    /* 5AFA4 800C37A4 21105100 */  addu       $v0, $v0, $s1
    /* 5AFA8 800C37A8 00004394 */  lhu        $v1, 0x0($v0)
    /* 5AFAC 800C37AC FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 5AFB0 800C37B0 040043A4 */  sh         $v1, 0x4($v0)
    /* 5AFB4 800C37B4 2A100601 */  slt        $v0, $t0, $a2
    /* 5AFB8 800C37B8 F9FF4014 */  bnez       $v0, .L800C37A0
    /* 5AFBC 800C37BC 21108601 */   addu      $v0, $t4, $a2
  .L800C37C0:
    /* 5AFC0 800C37C0 0000E290 */  lbu        $v0, 0x0($a3)
    /* 5AFC4 800C37C4 00000000 */  nop
    /* 5AFC8 800C37C8 02004224 */  addiu      $v0, $v0, 0x2
    /* 5AFCC 800C37CC 0000E2A0 */  sb         $v0, 0x0($a3)
    /* 5AFD0 800C37D0 21108601 */  addu       $v0, $t4, $a2
    /* 5AFD4 800C37D4 40100200 */  sll        $v0, $v0, 1
    /* 5AFD8 800C37D8 21105100 */  addu       $v0, $v0, $s1
    /* 5AFDC 800C37DC 02004AA4 */  sh         $t2, 0x2($v0)
    /* 5AFE0 800C37E0 FF0D0308 */  j          .L800C37FC
    /* 5AFE4 800C37E4 04004BA4 */   sh        $t3, 0x4($v0)
  .L800C37E8:
    /* 5AFE8 800C37E8 0000E290 */  lbu        $v0, 0x0($a3)
    /* 5AFEC 800C37EC 02000825 */  addiu      $t0, $t0, 0x2
    /* 5AFF0 800C37F0 2A100201 */  slt        $v0, $t0, $v0
    /* 5AFF4 800C37F4 ADFF4014 */  bnez       $v0, .L800C36AC
    /* 5AFF8 800C37F8 21108801 */   addu      $v0, $t4, $t0
  .L800C37FC:
    /* 5AFFC 800C37FC 0100EF25 */  addiu      $t7, $t7, 0x1
  .L800C3800:
    /* 5B000 800C3800 01002925 */  addiu      $t1, $t1, 0x1
    /* 5B004 800C3804 2A102D01 */  slt        $v0, $t1, $t5
    /* 5B008 800C3808 A1FF4014 */  bnez       $v0, .L800C3690
    /* 5B00C 800C380C 00000000 */   nop
    /* 5B010 800C3810 1E0F0308 */  j          .L800C3C78
    /* 5B014 800C3814 01007326 */   addiu     $s3, $s3, 0x1
  .L800C3818:
    /* 5B018 800C3818 23186A01 */  subu       $v1, $t3, $t2
    /* 5B01C 800C381C 40100200 */  sll        $v0, $v0, 1
    /* 5B020 800C3820 0F80143C */  lui        $s4, %hi(D_800EA130)
    /* 5B024 800C3824 30A19426 */  addiu      $s4, $s4, %lo(D_800EA130)
    /* 5B028 800C3828 21105400 */  addu       $v0, $v0, $s4
    /* 5B02C 800C382C 00004294 */  lhu        $v0, 0x0($v0)
    /* 5B030 800C3830 C31B0300 */  sra        $v1, $v1, 15
    /* 5B034 800C3834 18006200 */  mult       $v1, $v0
    /* 5B038 800C3838 E100A229 */  slti       $v0, $t5, 0xE1
    /* 5B03C 800C383C 12580000 */  mflo       $t3
    /* 5B040 800C3840 02004014 */  bnez       $v0, .L800C384C
    /* 5B044 800C3844 00000000 */   nop
    /* 5B048 800C3848 E0000D24 */  addiu      $t5, $zero, 0xE0
  .L800C384C:
    /* 5B04C 800C384C 05002105 */  bgez       $t1, .L800C3864
    /* 5B050 800C3850 0100C230 */   andi      $v0, $a2, 0x1
  .L800C3854:
    /* 5B054 800C3854 01002925 */  addiu      $t1, $t1, 0x1
    /* 5B058 800C3858 FEFF2005 */  bltz       $t1, .L800C3854
    /* 5B05C 800C385C 21504B01 */   addu      $t2, $t2, $t3
    /* 5B060 800C3860 0100C230 */  andi       $v0, $a2, 0x1
  .L800C3864:
    /* 5B064 800C3864 84004010 */  beqz       $v0, .L800C3A78
    /* 5B068 800C3868 2A102D01 */   slt       $v0, $t1, $t5
    /* 5B06C 800C386C 3F004010 */  beqz       $v0, .L800C396C
    /* 5B070 800C3870 00000000 */   nop
    /* 5B074 800C3874 21383701 */  addu       $a3, $t1, $s7
  .L800C3878:
    /* 5B078 800C3878 2128E000 */  addu       $a1, $a3, $zero
    /* 5B07C 800C387C 0000E290 */  lbu        $v0, 0x0($a3)
    /* 5B080 800C3880 00000000 */  nop
    /* 5B084 800C3884 34004010 */  beqz       $v0, .L800C3958
    /* 5B088 800C3888 21400000 */   addu      $t0, $zero, $zero
    /* 5B08C 800C388C 40210900 */  sll        $a0, $t1, 5
    /* 5B090 800C3890 03640A00 */  sra        $t4, $t2, 16
    /* 5B094 800C3894 2178E000 */  addu       $t7, $a3, $zero
    /* 5B098 800C3898 21108800 */  addu       $v0, $a0, $t0
  .L800C389C:
    /* 5B09C 800C389C 40100200 */  sll        $v0, $v0, 1
    /* 5B0A0 800C38A0 21185100 */  addu       $v1, $v0, $s1
    /* 5B0A4 800C38A4 02006284 */  lh         $v0, 0x2($v1)
    /* 5B0A8 800C38A8 00000000 */  nop
    /* 5B0AC 800C38AC 2A108201 */  slt        $v0, $t4, $v0
    /* 5B0B0 800C38B0 23004010 */  beqz       $v0, .L800C3940
    /* 5B0B4 800C38B4 00000000 */   nop
    /* 5B0B8 800C38B8 00006384 */  lh         $v1, 0x0($v1)
    /* 5B0BC 800C38BC 00000000 */  nop
    /* 5B0C0 800C38C0 2A106C00 */  slt        $v0, $v1, $t4
    /* 5B0C4 800C38C4 24004010 */  beqz       $v0, .L800C3958
    /* 5B0C8 800C38C8 2A107900 */   slt       $v0, $v1, $t9
    /* 5B0CC 800C38CC 18004010 */  beqz       $v0, .L800C3930
    /* 5B0D0 800C38D0 21108800 */   addu      $v0, $a0, $t0
    /* 5B0D4 800C38D4 0000A290 */  lbu        $v0, 0x0($a1)
    /* 5B0D8 800C38D8 00000000 */  nop
    /* 5B0DC 800C38DC FFFF4624 */  addiu      $a2, $v0, -0x1
    /* 5B0E0 800C38E0 2A100601 */  slt        $v0, $t0, $a2
    /* 5B0E4 800C38E4 09004010 */  beqz       $v0, .L800C390C
    /* 5B0E8 800C38E8 21108600 */   addu      $v0, $a0, $a2
  .L800C38EC:
    /* 5B0EC 800C38EC 40100200 */  sll        $v0, $v0, 1
    /* 5B0F0 800C38F0 21105100 */  addu       $v0, $v0, $s1
    /* 5B0F4 800C38F4 00004394 */  lhu        $v1, 0x0($v0)
    /* 5B0F8 800C38F8 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 5B0FC 800C38FC 040043A4 */  sh         $v1, 0x4($v0)
    /* 5B100 800C3900 2A100601 */  slt        $v0, $t0, $a2
    /* 5B104 800C3904 F9FF4014 */  bnez       $v0, .L800C38EC
    /* 5B108 800C3908 21108600 */   addu      $v0, $a0, $a2
  .L800C390C:
    /* 5B10C 800C390C 0000E291 */  lbu        $v0, 0x0($t7)
    /* 5B110 800C3910 02000825 */  addiu      $t0, $t0, 0x2
    /* 5B114 800C3914 02004224 */  addiu      $v0, $v0, 0x2
    /* 5B118 800C3918 0000E2A1 */  sb         $v0, 0x0($t7)
    /* 5B11C 800C391C 21108600 */  addu       $v0, $a0, $a2
    /* 5B120 800C3920 40100200 */  sll        $v0, $v0, 1
    /* 5B124 800C3924 21105100 */  addu       $v0, $v0, $s1
    /* 5B128 800C3928 020059A4 */  sh         $t9, 0x2($v0)
    /* 5B12C 800C392C 21108800 */  addu       $v0, $a0, $t0
  .L800C3930:
    /* 5B130 800C3930 40100200 */  sll        $v0, $v0, 1
    /* 5B134 800C3934 21105100 */  addu       $v0, $v0, $s1
    /* 5B138 800C3938 560E0308 */  j          .L800C3958
    /* 5B13C 800C393C 00004CA4 */   sh        $t4, 0x0($v0)
  .L800C3940:
    /* 5B140 800C3940 2128E902 */  addu       $a1, $s7, $t1
    /* 5B144 800C3944 0000A290 */  lbu        $v0, 0x0($a1)
    /* 5B148 800C3948 02000825 */  addiu      $t0, $t0, 0x2
    /* 5B14C 800C394C 2A100201 */  slt        $v0, $t0, $v0
    /* 5B150 800C3950 D2FF4014 */  bnez       $v0, .L800C389C
    /* 5B154 800C3954 21108800 */   addu      $v0, $a0, $t0
  .L800C3958:
    /* 5B158 800C3958 0100E724 */  addiu      $a3, $a3, 0x1
    /* 5B15C 800C395C 01002925 */  addiu      $t1, $t1, 0x1
    /* 5B160 800C3960 2A102D01 */  slt        $v0, $t1, $t5
    /* 5B164 800C3964 C4FF4014 */  bnez       $v0, .L800C3878
    /* 5B168 800C3968 21504B01 */   addu      $t2, $t2, $t3
  .L800C396C:
    /* 5B16C 800C396C B4006992 */  lbu        $t1, 0xB4($s3)
    /* 5B170 800C3970 00000000 */  nop
    /* 5B174 800C3974 2A10A901 */  slt        $v0, $t5, $t1
    /* 5B178 800C3978 BE004010 */  beqz       $v0, .L800C3C74
    /* 5B17C 800C397C 03540A00 */   sra       $t2, $t2, 16
    /* 5B180 800C3980 2138B701 */  addu       $a3, $t5, $s7
  .L800C3984:
    /* 5B184 800C3984 2128E000 */  addu       $a1, $a3, $zero
    /* 5B188 800C3988 0000E290 */  lbu        $v0, 0x0($a3)
    /* 5B18C 800C398C 00000000 */  nop
    /* 5B190 800C3990 33004010 */  beqz       $v0, .L800C3A60
    /* 5B194 800C3994 21400000 */   addu      $t0, $zero, $zero
    /* 5B198 800C3998 40210D00 */  sll        $a0, $t5, 5
    /* 5B19C 800C399C 2158E000 */  addu       $t3, $a3, $zero
    /* 5B1A0 800C39A0 21108800 */  addu       $v0, $a0, $t0
  .L800C39A4:
    /* 5B1A4 800C39A4 40100200 */  sll        $v0, $v0, 1
    /* 5B1A8 800C39A8 21185100 */  addu       $v1, $v0, $s1
    /* 5B1AC 800C39AC 02006284 */  lh         $v0, 0x2($v1)
    /* 5B1B0 800C39B0 00000000 */  nop
    /* 5B1B4 800C39B4 2A104201 */  slt        $v0, $t2, $v0
    /* 5B1B8 800C39B8 23004010 */  beqz       $v0, .L800C3A48
    /* 5B1BC 800C39BC 00000000 */   nop
    /* 5B1C0 800C39C0 00006384 */  lh         $v1, 0x0($v1)
    /* 5B1C4 800C39C4 00000000 */  nop
    /* 5B1C8 800C39C8 2A106A00 */  slt        $v0, $v1, $t2
    /* 5B1CC 800C39CC 24004010 */  beqz       $v0, .L800C3A60
    /* 5B1D0 800C39D0 2A107900 */   slt       $v0, $v1, $t9
    /* 5B1D4 800C39D4 18004010 */  beqz       $v0, .L800C3A38
    /* 5B1D8 800C39D8 21108800 */   addu      $v0, $a0, $t0
    /* 5B1DC 800C39DC 0000A290 */  lbu        $v0, 0x0($a1)
    /* 5B1E0 800C39E0 00000000 */  nop
    /* 5B1E4 800C39E4 FFFF4624 */  addiu      $a2, $v0, -0x1
    /* 5B1E8 800C39E8 2A100601 */  slt        $v0, $t0, $a2
    /* 5B1EC 800C39EC 09004010 */  beqz       $v0, .L800C3A14
    /* 5B1F0 800C39F0 21108600 */   addu      $v0, $a0, $a2
  .L800C39F4:
    /* 5B1F4 800C39F4 40100200 */  sll        $v0, $v0, 1
    /* 5B1F8 800C39F8 21105100 */  addu       $v0, $v0, $s1
    /* 5B1FC 800C39FC 00004394 */  lhu        $v1, 0x0($v0)
    /* 5B200 800C3A00 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 5B204 800C3A04 040043A4 */  sh         $v1, 0x4($v0)
    /* 5B208 800C3A08 2A100601 */  slt        $v0, $t0, $a2
    /* 5B20C 800C3A0C F9FF4014 */  bnez       $v0, .L800C39F4
    /* 5B210 800C3A10 21108600 */   addu      $v0, $a0, $a2
  .L800C3A14:
    /* 5B214 800C3A14 00006291 */  lbu        $v0, 0x0($t3)
    /* 5B218 800C3A18 02000825 */  addiu      $t0, $t0, 0x2
    /* 5B21C 800C3A1C 02004224 */  addiu      $v0, $v0, 0x2
    /* 5B220 800C3A20 000062A1 */  sb         $v0, 0x0($t3)
    /* 5B224 800C3A24 21108600 */  addu       $v0, $a0, $a2
    /* 5B228 800C3A28 40100200 */  sll        $v0, $v0, 1
    /* 5B22C 800C3A2C 21105100 */  addu       $v0, $v0, $s1
    /* 5B230 800C3A30 020059A4 */  sh         $t9, 0x2($v0)
    /* 5B234 800C3A34 21108800 */  addu       $v0, $a0, $t0
  .L800C3A38:
    /* 5B238 800C3A38 40100200 */  sll        $v0, $v0, 1
    /* 5B23C 800C3A3C 21105100 */  addu       $v0, $v0, $s1
    /* 5B240 800C3A40 980E0308 */  j          .L800C3A60
    /* 5B244 800C3A44 00004AA4 */   sh        $t2, 0x0($v0)
  .L800C3A48:
    /* 5B248 800C3A48 2128ED02 */  addu       $a1, $s7, $t5
    /* 5B24C 800C3A4C 0000A290 */  lbu        $v0, 0x0($a1)
    /* 5B250 800C3A50 02000825 */  addiu      $t0, $t0, 0x2
    /* 5B254 800C3A54 2A100201 */  slt        $v0, $t0, $v0
    /* 5B258 800C3A58 D2FF4014 */  bnez       $v0, .L800C39A4
    /* 5B25C 800C3A5C 21108800 */   addu      $v0, $a0, $t0
  .L800C3A60:
    /* 5B260 800C3A60 0100AD25 */  addiu      $t5, $t5, 0x1
    /* 5B264 800C3A64 2A10A901 */  slt        $v0, $t5, $t1
    /* 5B268 800C3A68 C6FF4014 */  bnez       $v0, .L800C3984
    /* 5B26C 800C3A6C 0100E724 */   addiu     $a3, $a3, 0x1
    /* 5B270 800C3A70 1E0F0308 */  j          .L800C3C78
    /* 5B274 800C3A74 01007326 */   addiu     $s3, $s3, 0x1
  .L800C3A78:
    /* 5B278 800C3A78 3E004010 */  beqz       $v0, .L800C3B74
    /* 5B27C 800C3A7C 00000000 */   nop
    /* 5B280 800C3A80 21603701 */  addu       $t4, $t1, $s7
  .L800C3A84:
    /* 5B284 800C3A84 21308001 */  addu       $a2, $t4, $zero
    /* 5B288 800C3A88 00008291 */  lbu        $v0, 0x0($t4)
    /* 5B28C 800C3A8C 00000000 */  nop
    /* 5B290 800C3A90 33004010 */  beqz       $v0, .L800C3B60
    /* 5B294 800C3A94 21400000 */   addu      $t0, $zero, $zero
    /* 5B298 800C3A98 037C0A00 */  sra        $t7, $t2, 16
    /* 5B29C 800C3A9C 21808001 */  addu       $s0, $t4, $zero
    /* 5B2A0 800C3AA0 40390900 */  sll        $a3, $t1, 5
    /* 5B2A4 800C3AA4 2128E000 */  addu       $a1, $a3, $zero
  .L800C3AA8:
    /* 5B2A8 800C3AA8 40100500 */  sll        $v0, $a1, 1
    /* 5B2AC 800C3AAC 21185100 */  addu       $v1, $v0, $s1
    /* 5B2B0 800C3AB0 02006484 */  lh         $a0, 0x2($v1)
    /* 5B2B4 800C3AB4 00000000 */  nop
    /* 5B2B8 800C3AB8 2A10E401 */  slt        $v0, $t7, $a0
    /* 5B2BC 800C3ABC 22004010 */  beqz       $v0, .L800C3B48
    /* 5B2C0 800C3AC0 00000000 */   nop
    /* 5B2C4 800C3AC4 00006284 */  lh         $v0, 0x0($v1)
    /* 5B2C8 800C3AC8 00000000 */  nop
    /* 5B2CC 800C3ACC 2A104F00 */  slt        $v0, $v0, $t7
    /* 5B2D0 800C3AD0 23004010 */  beqz       $v0, .L800C3B60
    /* 5B2D4 800C3AD4 2A102403 */   slt       $v0, $t9, $a0
    /* 5B2D8 800C3AD8 18004010 */  beqz       $v0, .L800C3B3C
    /* 5B2DC 800C3ADC 40100500 */   sll       $v0, $a1, 1
    /* 5B2E0 800C3AE0 0000C290 */  lbu        $v0, 0x0($a2)
    /* 5B2E4 800C3AE4 00000000 */  nop
    /* 5B2E8 800C3AE8 FFFF4624 */  addiu      $a2, $v0, -0x1
    /* 5B2EC 800C3AEC 2A100601 */  slt        $v0, $t0, $a2
    /* 5B2F0 800C3AF0 09004010 */  beqz       $v0, .L800C3B18
    /* 5B2F4 800C3AF4 2110E600 */   addu      $v0, $a3, $a2
  .L800C3AF8:
    /* 5B2F8 800C3AF8 40100200 */  sll        $v0, $v0, 1
    /* 5B2FC 800C3AFC 21105100 */  addu       $v0, $v0, $s1
    /* 5B300 800C3B00 00004394 */  lhu        $v1, 0x0($v0)
    /* 5B304 800C3B04 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 5B308 800C3B08 040043A4 */  sh         $v1, 0x4($v0)
    /* 5B30C 800C3B0C 2A100601 */  slt        $v0, $t0, $a2
    /* 5B310 800C3B10 F9FF4014 */  bnez       $v0, .L800C3AF8
    /* 5B314 800C3B14 2110E600 */   addu      $v0, $a3, $a2
  .L800C3B18:
    /* 5B318 800C3B18 00000292 */  lbu        $v0, 0x0($s0)
    /* 5B31C 800C3B1C 00000000 */  nop
    /* 5B320 800C3B20 02004224 */  addiu      $v0, $v0, 0x2
    /* 5B324 800C3B24 000002A2 */  sb         $v0, 0x0($s0)
    /* 5B328 800C3B28 2110E600 */  addu       $v0, $a3, $a2
    /* 5B32C 800C3B2C 40100200 */  sll        $v0, $v0, 1
    /* 5B330 800C3B30 21105100 */  addu       $v0, $v0, $s1
    /* 5B334 800C3B34 040059A4 */  sh         $t9, 0x4($v0)
    /* 5B338 800C3B38 40100500 */  sll        $v0, $a1, 1
  .L800C3B3C:
    /* 5B33C 800C3B3C 21105100 */  addu       $v0, $v0, $s1
    /* 5B340 800C3B40 D80E0308 */  j          .L800C3B60
    /* 5B344 800C3B44 02004FA4 */   sh        $t7, 0x2($v0)
  .L800C3B48:
    /* 5B348 800C3B48 2130E902 */  addu       $a2, $s7, $t1
    /* 5B34C 800C3B4C 0000C290 */  lbu        $v0, 0x0($a2)
    /* 5B350 800C3B50 02000825 */  addiu      $t0, $t0, 0x2
    /* 5B354 800C3B54 2A100201 */  slt        $v0, $t0, $v0
    /* 5B358 800C3B58 D3FF4014 */  bnez       $v0, .L800C3AA8
    /* 5B35C 800C3B5C 0200A524 */   addiu     $a1, $a1, 0x2
  .L800C3B60:
    /* 5B360 800C3B60 01008C25 */  addiu      $t4, $t4, 0x1
    /* 5B364 800C3B64 01002925 */  addiu      $t1, $t1, 0x1
    /* 5B368 800C3B68 2A102D01 */  slt        $v0, $t1, $t5
    /* 5B36C 800C3B6C C5FF4014 */  bnez       $v0, .L800C3A84
    /* 5B370 800C3B70 21504B01 */   addu      $t2, $t2, $t3
  .L800C3B74:
    /* 5B374 800C3B74 B4006992 */  lbu        $t1, 0xB4($s3)
    /* 5B378 800C3B78 00000000 */  nop
    /* 5B37C 800C3B7C 2A10A901 */  slt        $v0, $t5, $t1
    /* 5B380 800C3B80 3C004010 */  beqz       $v0, .L800C3C74
    /* 5B384 800C3B84 03540A00 */   sra       $t2, $t2, 16
    /* 5B388 800C3B88 2158B701 */  addu       $t3, $t5, $s7
  .L800C3B8C:
    /* 5B38C 800C3B8C 21306001 */  addu       $a2, $t3, $zero
    /* 5B390 800C3B90 00006291 */  lbu        $v0, 0x0($t3)
    /* 5B394 800C3B94 00000000 */  nop
    /* 5B398 800C3B98 32004010 */  beqz       $v0, .L800C3C64
    /* 5B39C 800C3B9C 21400000 */   addu      $t0, $zero, $zero
    /* 5B3A0 800C3BA0 21606001 */  addu       $t4, $t3, $zero
    /* 5B3A4 800C3BA4 40390D00 */  sll        $a3, $t5, 5
    /* 5B3A8 800C3BA8 2128E000 */  addu       $a1, $a3, $zero
  .L800C3BAC:
    /* 5B3AC 800C3BAC 40100500 */  sll        $v0, $a1, 1
    /* 5B3B0 800C3BB0 21185100 */  addu       $v1, $v0, $s1
    /* 5B3B4 800C3BB4 02006484 */  lh         $a0, 0x2($v1)
    /* 5B3B8 800C3BB8 00000000 */  nop
    /* 5B3BC 800C3BBC 2A104401 */  slt        $v0, $t2, $a0
    /* 5B3C0 800C3BC0 22004010 */  beqz       $v0, .L800C3C4C
    /* 5B3C4 800C3BC4 00000000 */   nop
    /* 5B3C8 800C3BC8 00006284 */  lh         $v0, 0x0($v1)
    /* 5B3CC 800C3BCC 00000000 */  nop
    /* 5B3D0 800C3BD0 2A104201 */  slt        $v0, $t2, $v0
    /* 5B3D4 800C3BD4 23004014 */  bnez       $v0, .L800C3C64
    /* 5B3D8 800C3BD8 2A102403 */   slt       $v0, $t9, $a0
    /* 5B3DC 800C3BDC 18004010 */  beqz       $v0, .L800C3C40
    /* 5B3E0 800C3BE0 40100500 */   sll       $v0, $a1, 1
    /* 5B3E4 800C3BE4 0000C290 */  lbu        $v0, 0x0($a2)
    /* 5B3E8 800C3BE8 00000000 */  nop
    /* 5B3EC 800C3BEC FFFF4624 */  addiu      $a2, $v0, -0x1
    /* 5B3F0 800C3BF0 2A100601 */  slt        $v0, $t0, $a2
    /* 5B3F4 800C3BF4 09004010 */  beqz       $v0, .L800C3C1C
    /* 5B3F8 800C3BF8 2110E600 */   addu      $v0, $a3, $a2
  .L800C3BFC:
    /* 5B3FC 800C3BFC 40100200 */  sll        $v0, $v0, 1
    /* 5B400 800C3C00 21105100 */  addu       $v0, $v0, $s1
    /* 5B404 800C3C04 00004394 */  lhu        $v1, 0x0($v0)
    /* 5B408 800C3C08 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 5B40C 800C3C0C 040043A4 */  sh         $v1, 0x4($v0)
    /* 5B410 800C3C10 2A100601 */  slt        $v0, $t0, $a2
    /* 5B414 800C3C14 F9FF4014 */  bnez       $v0, .L800C3BFC
    /* 5B418 800C3C18 2110E600 */   addu      $v0, $a3, $a2
  .L800C3C1C:
    /* 5B41C 800C3C1C 00008291 */  lbu        $v0, 0x0($t4)
    /* 5B420 800C3C20 00000000 */  nop
    /* 5B424 800C3C24 02004224 */  addiu      $v0, $v0, 0x2
    /* 5B428 800C3C28 000082A1 */  sb         $v0, 0x0($t4)
    /* 5B42C 800C3C2C 2110E600 */  addu       $v0, $a3, $a2
    /* 5B430 800C3C30 40100200 */  sll        $v0, $v0, 1
    /* 5B434 800C3C34 21105100 */  addu       $v0, $v0, $s1
    /* 5B438 800C3C38 040059A4 */  sh         $t9, 0x4($v0)
    /* 5B43C 800C3C3C 40100500 */  sll        $v0, $a1, 1
  .L800C3C40:
    /* 5B440 800C3C40 21105100 */  addu       $v0, $v0, $s1
    /* 5B444 800C3C44 190F0308 */  j          .L800C3C64
    /* 5B448 800C3C48 02004AA4 */   sh        $t2, 0x2($v0)
  .L800C3C4C:
    /* 5B44C 800C3C4C 2130ED02 */  addu       $a2, $s7, $t5
    /* 5B450 800C3C50 0000C290 */  lbu        $v0, 0x0($a2)
    /* 5B454 800C3C54 02000825 */  addiu      $t0, $t0, 0x2
    /* 5B458 800C3C58 2A100201 */  slt        $v0, $t0, $v0
    /* 5B45C 800C3C5C D3FF4014 */  bnez       $v0, .L800C3BAC
    /* 5B460 800C3C60 0200A524 */   addiu     $a1, $a1, 0x2
  .L800C3C64:
    /* 5B464 800C3C64 0100AD25 */  addiu      $t5, $t5, 0x1
    /* 5B468 800C3C68 2A10A901 */  slt        $v0, $t5, $t1
    /* 5B46C 800C3C6C C7FF4014 */  bnez       $v0, .L800C3B8C
    /* 5B470 800C3C70 01006B25 */   addiu     $t3, $t3, 0x1
  .L800C3C74:
    /* 5B474 800C3C74 01007326 */  addiu      $s3, $s3, 0x1
  .L800C3C78:
    /* 5B478 800C3C78 01005226 */  addiu      $s2, $s2, 0x1
    /* 5B47C 800C3C7C AA00422A */  slti       $v0, $s2, 0xAA
    /* 5B480 800C3C80 31FE4014 */  bnez       $v0, .L800C3548
    /* 5B484 800C3C84 0F80023C */   lui       $v0, %hi(D_800EA130)
    /* 5B488 800C3C88 21900000 */  addu       $s2, $zero, $zero
    /* 5B48C 800C3C8C 007C1600 */  sll        $t7, $s6, 16
    /* 5B490 800C3C90 00801334 */  ori        $s3, $zero, 0x8000
    /* 5B494 800C3C94 30A15024 */  addiu      $s0, $v0, %lo(D_800EA130)
    /* 5B498 800C3C98 21400000 */  addu       $t0, $zero, $zero
  .L800C3C9C:
    /* 5B49C 800C3C9C 0F80023C */  lui        $v0, %hi(D_800EB9B8)
  .L800C3CA0:
    /* 5B4A0 800C3CA0 C0181200 */  sll        $v1, $s2, 3
    /* 5B4A4 800C3CA4 21187200 */  addu       $v1, $v1, $s2
    /* 5B4A8 800C3CA8 B8B9428C */  lw         $v0, %lo(D_800EB9B8)($v0)
    /* 5B4AC 800C3CAC 21180301 */  addu       $v1, $t0, $v1
    /* 5B4B0 800C3CB0 21104300 */  addu       $v0, $v0, $v1
    /* 5B4B4 800C3CB4 B84A4690 */  lbu        $a2, 0x4AB8($v0)
    /* 5B4B8 800C3CB8 00000000 */  nop
    /* 5B4BC 800C3CBC 0901C010 */  beqz       $a2, .L800C40E4
    /* 5B4C0 800C3CC0 8438023C */   lui       $v0, (0x38847780 >> 16)
    /* 5B4C4 800C3CC4 80774234 */  ori        $v0, $v0, (0x38847780 & 0xFFFF)
    /* 5B4C8 800C3CC8 07C8C200 */  srav       $t9, $v0, $a2
    /* 5B4CC 800C3CCC FCFF0425 */  addiu      $a0, $t0, -0x4
    /* 5B4D0 800C3CD0 0000C397 */  lhu        $v1, 0x0($fp)
    /* 5B4D4 800C3CD4 0400C297 */  lhu        $v0, 0x4($fp)
    /* 5B4D8 800C3CD8 001C0300 */  sll        $v1, $v1, 16
    /* 5B4DC 800C3CDC C31D0300 */  sra        $v1, $v1, 23
    /* 5B4E0 800C3CE0 21706400 */  addu       $t6, $v1, $a0
    /* 5B4E4 800C3CE4 00140200 */  sll        $v0, $v0, 16
    /* 5B4E8 800C3CE8 C3150200 */  sra        $v0, $v0, 23
    /* 5B4EC 800C3CEC FCFF4326 */  addiu      $v1, $s2, -0x4
    /* 5B4F0 800C3CF0 21C04300 */  addu       $t8, $v0, $v1
    /* 5B4F4 800C3CF4 01002233 */  andi       $v0, $t9, 0x1
    /* 5B4F8 800C3CF8 2110C201 */  addu       $v0, $t6, $v0
    /* 5B4FC 800C3CFC C0110200 */  sll        $v0, $v0, 7
    /* 5B500 800C3D00 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 5B504 800C3D04 25504F00 */  or         $t2, $v0, $t7
    /* 5B508 800C3D08 43101900 */  sra        $v0, $t9, 1
    /* 5B50C 800C3D0C 01004230 */  andi       $v0, $v0, 0x1
    /* 5B510 800C3D10 21100203 */  addu       $v0, $t8, $v0
    /* 5B514 800C3D14 C0490200 */  sll        $t1, $v0, 7
    /* 5B518 800C3D18 00008A48 */  mtc2       $t2, $0 /* handwritten instruction */
    /* 5B51C 800C3D1C 00088948 */  mtc2       $t1, $1 /* handwritten instruction */
    /* 5B520 800C3D20 83101900 */  sra        $v0, $t9, 2
    /* 5B524 800C3D24 01004230 */  andi       $v0, $v0, 0x1
    /* 5B528 800C3D28 2110C201 */  addu       $v0, $t6, $v0
    /* 5B52C 800C3D2C C0110200 */  sll        $v0, $v0, 7
    /* 5B530 800C3D30 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 5B534 800C3D34 25504F00 */  or         $t2, $v0, $t7
    /* 5B538 800C3D38 C3101900 */  sra        $v0, $t9, 3
    /* 5B53C 800C3D3C 01004230 */  andi       $v0, $v0, 0x1
    /* 5B540 800C3D40 21100203 */  addu       $v0, $t8, $v0
    /* 5B544 800C3D44 C0490200 */  sll        $t1, $v0, 7
    /* 5B548 800C3D48 00108A48 */  mtc2       $t2, $2 /* handwritten instruction */
    /* 5B54C 800C3D4C 00188948 */  mtc2       $t1, $3 /* handwritten instruction */
    /* 5B550 800C3D50 03111900 */  sra        $v0, $t9, 4
    /* 5B554 800C3D54 01004230 */  andi       $v0, $v0, 0x1
    /* 5B558 800C3D58 2110C201 */  addu       $v0, $t6, $v0
    /* 5B55C 800C3D5C C0110200 */  sll        $v0, $v0, 7
    /* 5B560 800C3D60 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 5B564 800C3D64 25504F00 */  or         $t2, $v0, $t7
    /* 5B568 800C3D68 43111900 */  sra        $v0, $t9, 5
    /* 5B56C 800C3D6C 01004230 */  andi       $v0, $v0, 0x1
    /* 5B570 800C3D70 21100203 */  addu       $v0, $t8, $v0
    /* 5B574 800C3D74 C0490200 */  sll        $t1, $v0, 7
    /* 5B578 800C3D78 00208A48 */  mtc2       $t2, $4 /* handwritten instruction */
    /* 5B57C 800C3D7C 00288948 */  mtc2       $t1, $5 /* handwritten instruction */
    /* 5B580 800C3D80 00000000 */  nop
    /* 5B584 800C3D84 00000000 */  nop
    /* 5B588 800C3D88 3000284A */  rtpt
    /* 5B58C 800C3D8C 0000ACEA */  swc2       $12, 0x0($s5)
    /* 5B590 800C3D90 0400A226 */  addiu      $v0, $s5, 0x4
    /* 5B594 800C3D94 00004DE8 */  swc2       $13, 0x0($v0)
    /* 5B598 800C3D98 0800A226 */  addiu      $v0, $s5, 0x8
    /* 5B59C 800C3D9C 00004EE8 */  swc2       $14, 0x0($v0)
    /* 5B5A0 800C3DA0 0200A296 */  lhu        $v0, 0x2($s5)
    /* 5B5A4 800C3DA4 0600A386 */  lh         $v1, 0x6($s5)
    /* 5B5A8 800C3DA8 00140200 */  sll        $v0, $v0, 16
    /* 5B5AC 800C3DAC 03340200 */  sra        $a2, $v0, 16
    /* 5B5B0 800C3DB0 0000A28E */  lw         $v0, 0x0($s5)
    /* 5B5B4 800C3DB4 00000000 */  nop
    /* 5B5B8 800C3DB8 0C00A2AE */  sw         $v0, 0xC($s5)
    /* 5B5BC 800C3DBC 2A106600 */  slt        $v0, $v1, $a2
    /* 5B5C0 800C3DC0 02004010 */  beqz       $v0, .L800C3DCC
    /* 5B5C4 800C3DC4 21C8C000 */   addu      $t9, $a2, $zero
    /* 5B5C8 800C3DC8 21306000 */  addu       $a2, $v1, $zero
  .L800C3DCC:
    /* 5B5CC 800C3DCC 2A102303 */  slt        $v0, $t9, $v1
    /* 5B5D0 800C3DD0 02004010 */  beqz       $v0, .L800C3DDC
    /* 5B5D4 800C3DD4 00000000 */   nop
    /* 5B5D8 800C3DD8 21C86000 */  addu       $t9, $v1, $zero
  .L800C3DDC:
    /* 5B5DC 800C3DDC 0A00A386 */  lh         $v1, 0xA($s5)
    /* 5B5E0 800C3DE0 00000000 */  nop
    /* 5B5E4 800C3DE4 2A106600 */  slt        $v0, $v1, $a2
    /* 5B5E8 800C3DE8 02004010 */  beqz       $v0, .L800C3DF4
    /* 5B5EC 800C3DEC 2A102303 */   slt       $v0, $t9, $v1
    /* 5B5F0 800C3DF0 21306000 */  addu       $a2, $v1, $zero
  .L800C3DF4:
    /* 5B5F4 800C3DF4 02004010 */  beqz       $v0, .L800C3E00
    /* 5B5F8 800C3DF8 00000000 */   nop
    /* 5B5FC 800C3DFC 21C86000 */  addu       $t9, $v1, $zero
  .L800C3E00:
    /* 5B600 800C3E00 0200C104 */  bgez       $a2, .L800C3E0C
    /* 5B604 800C3E04 E100222B */   slti      $v0, $t9, 0xE1
    /* 5B608 800C3E08 21300000 */  addu       $a2, $zero, $zero
  .L800C3E0C:
    /* 5B60C 800C3E0C 02004014 */  bnez       $v0, .L800C3E18
    /* 5B610 800C3E10 21C00000 */   addu      $t8, $zero, $zero
    /* 5B614 800C3E14 E0001924 */  addiu      $t9, $zero, 0xE0
  .L800C3E18:
    /* 5B618 800C3E18 2120A002 */  addu       $a0, $s5, $zero
  .L800C3E1C:
    /* 5B61C 800C3E1C 00008E8C */  lw         $t6, 0x0($a0)
    /* 5B620 800C3E20 00000000 */  nop
    /* 5B624 800C3E24 034C0E00 */  sra        $t1, $t6, 16
    /* 5B628 800C3E28 00140E00 */  sll        $v0, $t6, 16
    /* 5B62C 800C3E2C 04008E8C */  lw         $t6, 0x4($a0)
    /* 5B630 800C3E30 21505300 */  addu       $t2, $v0, $s3
    /* 5B634 800C3E34 00140E00 */  sll        $v0, $t6, 16
    /* 5B638 800C3E38 21585300 */  addu       $t3, $v0, $s3
    /* 5B63C 800C3E3C 036C0E00 */  sra        $t5, $t6, 16
    /* 5B640 800C3E40 2A102D01 */  slt        $v0, $t1, $t5
    /* 5B644 800C3E44 1F004010 */  beqz       $v0, .L800C3EC4
    /* 5B648 800C3E48 23186A01 */   subu      $v1, $t3, $t2
    /* 5B64C 800C3E4C 2310A901 */  subu       $v0, $t5, $t1
    /* 5B650 800C3E50 40100200 */  sll        $v0, $v0, 1
    /* 5B654 800C3E54 21105000 */  addu       $v0, $v0, $s0
    /* 5B658 800C3E58 00004294 */  lhu        $v0, 0x0($v0)
    /* 5B65C 800C3E5C C31B0300 */  sra        $v1, $v1, 15
    /* 5B660 800C3E60 18006200 */  mult       $v1, $v0
    /* 5B664 800C3E64 E100A229 */  slti       $v0, $t5, 0xE1
    /* 5B668 800C3E68 12580000 */  mflo       $t3
    /* 5B66C 800C3E6C 02004014 */  bnez       $v0, .L800C3E78
    /* 5B670 800C3E70 00000000 */   nop
    /* 5B674 800C3E74 E0000D24 */  addiu      $t5, $zero, 0xE0
  .L800C3E78:
    /* 5B678 800C3E78 05002105 */  bgez       $t1, .L800C3E90
    /* 5B67C 800C3E7C 2A102D01 */   slt       $v0, $t1, $t5
  .L800C3E80:
    /* 5B680 800C3E80 01002925 */  addiu      $t1, $t1, 0x1
    /* 5B684 800C3E84 FEFF2005 */  bltz       $t1, .L800C3E80
    /* 5B688 800C3E88 21504B01 */   addu      $t2, $t2, $t3
    /* 5B68C 800C3E8C 2A102D01 */  slt        $v0, $t1, $t5
  .L800C3E90:
    /* 5B690 800C3E90 28004010 */  beqz       $v0, .L800C3F34
    /* 5B694 800C3E94 00000000 */   nop
  .L800C3E98:
    /* 5B698 800C3E98 23102601 */  subu       $v0, $t1, $a2
    /* 5B69C 800C3E9C 80100200 */  sll        $v0, $v0, 2
    /* 5B6A0 800C3EA0 21105500 */  addu       $v0, $v0, $s5
    /* 5B6A4 800C3EA4 031C0A00 */  sra        $v1, $t2, 16
    /* 5B6A8 800C3EA8 120043A4 */  sh         $v1, 0x12($v0)
    /* 5B6AC 800C3EAC 01002925 */  addiu      $t1, $t1, 0x1
    /* 5B6B0 800C3EB0 2A102D01 */  slt        $v0, $t1, $t5
    /* 5B6B4 800C3EB4 F8FF4014 */  bnez       $v0, .L800C3E98
    /* 5B6B8 800C3EB8 21504B01 */   addu      $t2, $t2, $t3
    /* 5B6BC 800C3EBC CE0F0308 */  j          .L800C3F38
    /* 5B6C0 800C3EC0 04008424 */   addiu     $a0, $a0, 0x4
  .L800C3EC4:
    /* 5B6C4 800C3EC4 23184B01 */  subu       $v1, $t2, $t3
    /* 5B6C8 800C3EC8 23102D01 */  subu       $v0, $t1, $t5
    /* 5B6CC 800C3ECC 40100200 */  sll        $v0, $v0, 1
    /* 5B6D0 800C3ED0 21105000 */  addu       $v0, $v0, $s0
    /* 5B6D4 800C3ED4 00004294 */  lhu        $v0, 0x0($v0)
    /* 5B6D8 800C3ED8 C31B0300 */  sra        $v1, $v1, 15
    /* 5B6DC 800C3EDC 18006200 */  mult       $v1, $v0
    /* 5B6E0 800C3EE0 E1002229 */  slti       $v0, $t1, 0xE1
    /* 5B6E4 800C3EE4 12500000 */  mflo       $t2
    /* 5B6E8 800C3EE8 02004014 */  bnez       $v0, .L800C3EF4
    /* 5B6EC 800C3EEC 00000000 */   nop
    /* 5B6F0 800C3EF0 E0000924 */  addiu      $t1, $zero, 0xE0
  .L800C3EF4:
    /* 5B6F4 800C3EF4 0D00A105 */  bgez       $t5, .L800C3F2C
    /* 5B6F8 800C3EF8 2A10A901 */   slt       $v0, $t5, $t1
  .L800C3EFC:
    /* 5B6FC 800C3EFC 0100AD25 */  addiu      $t5, $t5, 0x1
    /* 5B700 800C3F00 FEFFA005 */  bltz       $t5, .L800C3EFC
    /* 5B704 800C3F04 21586A01 */   addu      $t3, $t3, $t2
    /* 5B708 800C3F08 CB0F0308 */  j          .L800C3F2C
    /* 5B70C 800C3F0C 2A10A901 */   slt       $v0, $t5, $t1
  .L800C3F10:
    /* 5B710 800C3F10 80100200 */  sll        $v0, $v0, 2
    /* 5B714 800C3F14 21105500 */  addu       $v0, $v0, $s5
    /* 5B718 800C3F18 031C0B00 */  sra        $v1, $t3, 16
    /* 5B71C 800C3F1C 100043A4 */  sh         $v1, 0x10($v0)
    /* 5B720 800C3F20 0100AD25 */  addiu      $t5, $t5, 0x1
    /* 5B724 800C3F24 21586A01 */  addu       $t3, $t3, $t2
    /* 5B728 800C3F28 2A10A901 */  slt        $v0, $t5, $t1
  .L800C3F2C:
    /* 5B72C 800C3F2C F8FF4014 */  bnez       $v0, .L800C3F10
    /* 5B730 800C3F30 2310A601 */   subu      $v0, $t5, $a2
  .L800C3F34:
    /* 5B734 800C3F34 04008424 */  addiu      $a0, $a0, 0x4
  .L800C3F38:
    /* 5B738 800C3F38 01001827 */  addiu      $t8, $t8, 0x1
    /* 5B73C 800C3F3C 0300022B */  slti       $v0, $t8, 0x3
    /* 5B740 800C3F40 B6FF4014 */  bnez       $v0, .L800C3E1C
    /* 5B744 800C3F44 2A10D900 */   slt       $v0, $a2, $t9
    /* 5B748 800C3F48 66004010 */  beqz       $v0, .L800C40E4
    /* 5B74C 800C3F4C 21C0C000 */   addu      $t8, $a2, $zero
    /* 5B750 800C3F50 2168D700 */  addu       $t5, $a2, $s7
    /* 5B754 800C3F54 23100603 */  subu       $v0, $t8, $a2
  .L800C3F58:
    /* 5B758 800C3F58 80100200 */  sll        $v0, $v0, 2
    /* 5B75C 800C3F5C 21105500 */  addu       $v0, $v0, $s5
    /* 5B760 800C3F60 10004A84 */  lh         $t2, 0x10($v0)
    /* 5B764 800C3F64 0000A391 */  lbu        $v1, 0x0($t5)
    /* 5B768 800C3F68 12004B84 */  lh         $t3, 0x12($v0)
    /* 5B76C 800C3F6C 58006010 */  beqz       $v1, .L800C40D0
    /* 5B770 800C3F70 21700000 */   addu      $t6, $zero, $zero
    /* 5B774 800C3F74 40611800 */  sll        $t4, $t8, 5
    /* 5B778 800C3F78 2138A001 */  addu       $a3, $t5, $zero
    /* 5B77C 800C3F7C 21108E01 */  addu       $v0, $t4, $t6
  .L800C3F80:
    /* 5B780 800C3F80 40100200 */  sll        $v0, $v0, 1
    /* 5B784 800C3F84 21285100 */  addu       $a1, $v0, $s1
    /* 5B788 800C3F88 0200A484 */  lh         $a0, 0x2($a1)
    /* 5B78C 800C3F8C 00000000 */  nop
    /* 5B790 800C3F90 2A104401 */  slt        $v0, $t2, $a0
    /* 5B794 800C3F94 49004010 */  beqz       $v0, .L800C40BC
    /* 5B798 800C3F98 00000000 */   nop
    /* 5B79C 800C3F9C 0000A384 */  lh         $v1, 0x0($a1)
    /* 5B7A0 800C3FA0 00000000 */  nop
    /* 5B7A4 800C3FA4 2A106B00 */  slt        $v0, $v1, $t3
    /* 5B7A8 800C3FA8 49004010 */  beqz       $v0, .L800C40D0
    /* 5B7AC 800C3FAC 2A106401 */   slt       $v0, $t3, $a0
    /* 5B7B0 800C3FB0 02004010 */  beqz       $v0, .L800C3FBC
    /* 5B7B4 800C3FB4 2A186A00 */   slt       $v1, $v1, $t2
    /* 5B7B8 800C3FB8 02006324 */  addiu      $v1, $v1, 0x2
  .L800C3FBC:
    /* 5B7BC 800C3FBC 01000224 */  addiu      $v0, $zero, 0x1
    /* 5B7C0 800C3FC0 22006210 */  beq        $v1, $v0, .L800C404C
    /* 5B7C4 800C3FC4 02006228 */   slti      $v0, $v1, 0x2
    /* 5B7C8 800C3FC8 05004010 */  beqz       $v0, .L800C3FE0
    /* 5B7CC 800C3FCC 02000224 */   addiu     $v0, $zero, 0x2
    /* 5B7D0 800C3FD0 09006010 */  beqz       $v1, .L800C3FF8
    /* 5B7D4 800C3FD4 2148C001 */   addu      $t1, $t6, $zero
    /* 5B7D8 800C3FD8 35100308 */  j          .L800C40D4
    /* 5B7DC 800C3FDC 0100AD25 */   addiu     $t5, $t5, 0x1
  .L800C3FE0:
    /* 5B7E0 800C3FE0 1C006210 */  beq        $v1, $v0, .L800C4054
    /* 5B7E4 800C3FE4 03000224 */   addiu     $v0, $zero, 0x3
    /* 5B7E8 800C3FE8 1C006210 */  beq        $v1, $v0, .L800C405C
    /* 5B7EC 800C3FEC 00000000 */   nop
    /* 5B7F0 800C3FF0 35100308 */  j          .L800C40D4
    /* 5B7F4 800C3FF4 0100AD25 */   addiu     $t5, $t5, 0x1
  .L800C3FF8:
    /* 5B7F8 800C3FF8 0000E290 */  lbu        $v0, 0x0($a3)
    /* 5B7FC 800C3FFC 00000000 */  nop
    /* 5B800 800C4000 FEFF4224 */  addiu      $v0, $v0, -0x2
    /* 5B804 800C4004 0000E2A0 */  sb         $v0, 0x0($a3)
    /* 5B808 800C4008 FF004230 */  andi       $v0, $v0, 0xFF
    /* 5B80C 800C400C 2A102201 */  slt        $v0, $t1, $v0
    /* 5B810 800C4010 2F004010 */  beqz       $v0, .L800C40D0
    /* 5B814 800C4014 2120E000 */   addu      $a0, $a3, $zero
    /* 5B818 800C4018 21108901 */  addu       $v0, $t4, $t1
  .L800C401C:
    /* 5B81C 800C401C 40100200 */  sll        $v0, $v0, 1
    /* 5B820 800C4020 21105100 */  addu       $v0, $v0, $s1
    /* 5B824 800C4024 04004394 */  lhu        $v1, 0x4($v0)
    /* 5B828 800C4028 00000000 */  nop
    /* 5B82C 800C402C 000043A4 */  sh         $v1, 0x0($v0)
    /* 5B830 800C4030 00008290 */  lbu        $v0, 0x0($a0)
    /* 5B834 800C4034 01002925 */  addiu      $t1, $t1, 0x1
    /* 5B838 800C4038 2A102201 */  slt        $v0, $t1, $v0
    /* 5B83C 800C403C F7FF4014 */  bnez       $v0, .L800C401C
    /* 5B840 800C4040 21108901 */   addu      $v0, $t4, $t1
    /* 5B844 800C4044 35100308 */  j          .L800C40D4
    /* 5B848 800C4048 0100AD25 */   addiu     $t5, $t5, 0x1
  .L800C404C:
    /* 5B84C 800C404C 34100308 */  j          .L800C40D0
    /* 5B850 800C4050 0200AAA4 */   sh        $t2, 0x2($a1)
  .L800C4054:
    /* 5B854 800C4054 34100308 */  j          .L800C40D0
    /* 5B858 800C4058 0000ABA4 */   sh        $t3, 0x0($a1)
  .L800C405C:
    /* 5B85C 800C405C 0000E290 */  lbu        $v0, 0x0($a3)
    /* 5B860 800C4060 00000000 */  nop
    /* 5B864 800C4064 FFFF4924 */  addiu      $t1, $v0, -0x1
    /* 5B868 800C4068 2A10C901 */  slt        $v0, $t6, $t1
    /* 5B86C 800C406C 09004010 */  beqz       $v0, .L800C4094
    /* 5B870 800C4070 21108901 */   addu      $v0, $t4, $t1
  .L800C4074:
    /* 5B874 800C4074 40100200 */  sll        $v0, $v0, 1
    /* 5B878 800C4078 21105100 */  addu       $v0, $v0, $s1
    /* 5B87C 800C407C 00004394 */  lhu        $v1, 0x0($v0)
    /* 5B880 800C4080 FFFF2925 */  addiu      $t1, $t1, -0x1
    /* 5B884 800C4084 040043A4 */  sh         $v1, 0x4($v0)
    /* 5B888 800C4088 2A10C901 */  slt        $v0, $t6, $t1
    /* 5B88C 800C408C F9FF4014 */  bnez       $v0, .L800C4074
    /* 5B890 800C4090 21108901 */   addu      $v0, $t4, $t1
  .L800C4094:
    /* 5B894 800C4094 0000E290 */  lbu        $v0, 0x0($a3)
    /* 5B898 800C4098 00000000 */  nop
    /* 5B89C 800C409C 02004224 */  addiu      $v0, $v0, 0x2
    /* 5B8A0 800C40A0 0000E2A0 */  sb         $v0, 0x0($a3)
    /* 5B8A4 800C40A4 21108901 */  addu       $v0, $t4, $t1
    /* 5B8A8 800C40A8 40100200 */  sll        $v0, $v0, 1
    /* 5B8AC 800C40AC 21105100 */  addu       $v0, $v0, $s1
    /* 5B8B0 800C40B0 02004AA4 */  sh         $t2, 0x2($v0)
    /* 5B8B4 800C40B4 34100308 */  j          .L800C40D0
    /* 5B8B8 800C40B8 04004BA4 */   sh        $t3, 0x4($v0)
  .L800C40BC:
    /* 5B8BC 800C40BC 0000E290 */  lbu        $v0, 0x0($a3)
    /* 5B8C0 800C40C0 0200CE25 */  addiu      $t6, $t6, 0x2
    /* 5B8C4 800C40C4 2A10C201 */  slt        $v0, $t6, $v0
    /* 5B8C8 800C40C8 ADFF4014 */  bnez       $v0, .L800C3F80
    /* 5B8CC 800C40CC 21108E01 */   addu      $v0, $t4, $t6
  .L800C40D0:
    /* 5B8D0 800C40D0 0100AD25 */  addiu      $t5, $t5, 0x1
  .L800C40D4:
    /* 5B8D4 800C40D4 01001827 */  addiu      $t8, $t8, 0x1
    /* 5B8D8 800C40D8 2A101903 */  slt        $v0, $t8, $t9
    /* 5B8DC 800C40DC 9EFF4014 */  bnez       $v0, .L800C3F58
    /* 5B8E0 800C40E0 23100603 */   subu      $v0, $t8, $a2
  .L800C40E4:
    /* 5B8E4 800C40E4 01000825 */  addiu      $t0, $t0, 0x1
    /* 5B8E8 800C40E8 09000229 */  slti       $v0, $t0, 0x9
    /* 5B8EC 800C40EC ECFE4014 */  bnez       $v0, .L800C3CA0
    /* 5B8F0 800C40F0 0F80023C */   lui       $v0, %hi(D_800EB9B8)
    /* 5B8F4 800C40F4 01005226 */  addiu      $s2, $s2, 0x1
    /* 5B8F8 800C40F8 0900422A */  slti       $v0, $s2, 0x9
    /* 5B8FC 800C40FC E7FE4014 */  bnez       $v0, .L800C3C9C
    /* 5B900 800C4100 21400000 */   addu      $t0, $zero, $zero
    /* 5B904 800C4104 3C00B48F */  lw         $s4, 0x3C($sp)
    /* 5B908 800C4108 00000000 */  nop
    /* 5B90C 800C410C 00008286 */  lh         $v0, 0x0($s4)
    /* 5B910 800C4110 4000B48F */  lw         $s4, 0x40($sp)
    /* 5B914 800C4114 00000000 */  nop
    /* 5B918 800C4118 18005400 */  mult       $v0, $s4
    /* 5B91C 800C411C 3C00B48F */  lw         $s4, 0x3C($sp)
    /* 5B920 800C4120 00000000 */  nop
    /* 5B924 800C4124 0C008286 */  lh         $v0, 0xC($s4)
    /* 5B928 800C4128 12180000 */  mflo       $v1
    /* 5B92C 800C412C 4000B48F */  lw         $s4, 0x40($sp)
    /* 5B930 800C4130 00000000 */  nop
    /* 5B934 800C4134 18005400 */  mult       $v0, $s4
    /* 5B938 800C4138 3C00B48F */  lw         $s4, 0x3C($sp)
    /* 5B93C 800C413C 00000000 */  nop
    /* 5B940 800C4140 04008286 */  lh         $v0, 0x4($s4)
    /* 5B944 800C4144 12200000 */  mflo       $a0
    /* 5B948 800C4148 4000B48F */  lw         $s4, 0x40($sp)
    /* 5B94C 800C414C 00000000 */  nop
    /* 5B950 800C4150 18005400 */  mult       $v0, $s4
    /* 5B954 800C4154 E0000824 */  addiu      $t0, $zero, 0xE0
    /* 5B958 800C4158 3C00B48F */  lw         $s4, 0x3C($sp)
    /* 5B95C 800C415C 00B41600 */  sll        $s6, $s6, 16
    /* 5B960 800C4160 10008286 */  lh         $v0, 0x10($s4)
    /* 5B964 800C4164 12280000 */  mflo       $a1
    /* 5B968 800C4168 4000B48F */  lw         $s4, 0x40($sp)
    /* 5B96C 800C416C 2138A002 */  addu       $a3, $s5, $zero
    /* 5B970 800C4170 18005400 */  mult       $v0, $s4
    /* 5B974 800C4174 10000F24 */  addiu      $t7, $zero, 0x10
    /* 5B978 800C4178 0F80023C */  lui        $v0, %hi(D_800EA818)
    /* 5B97C 800C417C 18A85324 */  addiu      $s3, $v0, %lo(D_800EA818)
    /* 5B980 800C4180 21806002 */  addu       $s0, $s3, $zero
    /* 5B984 800C4184 00086224 */  addiu      $v0, $v1, 0x800
    /* 5B988 800C4188 03530200 */  sra        $t2, $v0, 12
    /* 5B98C 800C418C 00088224 */  addiu      $v0, $a0, 0x800
    /* 5B990 800C4190 034B0200 */  sra        $t1, $v0, 12
    /* 5B994 800C4194 0008A224 */  addiu      $v0, $a1, 0x800
    /* 5B998 800C4198 035B0200 */  sra        $t3, $v0, 12
    /* 5B99C 800C419C 4000A0AF */  sw         $zero, 0x40($sp)
    /* 5B9A0 800C41A0 12680000 */  mflo       $t5
    /* 5B9A4 800C41A4 0008A225 */  addiu      $v0, $t5, 0x800
    /* 5B9A8 800C41A8 036B0200 */  sra        $t5, $v0, 12
  .L800C41AC:
    /* 5B9AC 800C41AC 2110F301 */  addu       $v0, $t7, $s3
    /* 5B9B0 800C41B0 00004684 */  lh         $a2, 0x0($v0)
    /* 5B9B4 800C41B4 00000000 */  nop
    /* 5B9B8 800C41B8 18004601 */  mult       $t2, $a2
    /* 5B9BC 800C41BC 12100000 */  mflo       $v0
    /* 5B9C0 800C41C0 00001986 */  lh         $t9, 0x0($s0)
    /* 5B9C4 800C41C4 00000000 */  nop
    /* 5B9C8 800C41C8 18003901 */  mult       $t1, $t9
    /* 5B9CC 800C41CC 12180000 */  mflo       $v1
    /* 5B9D0 800C41D0 00000000 */  nop
    /* 5B9D4 800C41D4 00000000 */  nop
    /* 5B9D8 800C41D8 18006601 */  mult       $t3, $a2
    /* 5B9DC 800C41DC 12280000 */  mflo       $a1
    /* 5B9E0 800C41E0 00000000 */  nop
    /* 5B9E4 800C41E4 00000000 */  nop
    /* 5B9E8 800C41E8 1800B901 */  mult       $t5, $t9
    /* 5B9EC 800C41EC 21104300 */  addu       $v0, $v0, $v1
    /* 5B9F0 800C41F0 00084224 */  addiu      $v0, $v0, 0x800
    /* 5B9F4 800C41F4 0000C387 */  lh         $v1, 0x0($fp)
    /* 5B9F8 800C41F8 03130200 */  sra        $v0, $v0, 12
    /* 5B9FC 800C41FC 21186200 */  addu       $v1, $v1, $v0
    /* 5BA00 800C4200 FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 5BA04 800C4204 25707600 */  or         $t6, $v1, $s6
    /* 5BA08 800C4208 0400C387 */  lh         $v1, 0x4($fp)
    /* 5BA0C 800C420C 12200000 */  mflo       $a0
    /* 5BA10 800C4210 2110A400 */  addu       $v0, $a1, $a0
    /* 5BA14 800C4214 00084224 */  addiu      $v0, $v0, 0x800
    /* 5BA18 800C4218 03130200 */  sra        $v0, $v0, 12
    /* 5BA1C 800C421C 21C06200 */  addu       $t8, $v1, $v0
    /* 5BA20 800C4220 00008E48 */  mtc2       $t6, $0 /* handwritten instruction */
    /* 5BA24 800C4224 00089848 */  mtc2       $t8, $1 /* handwritten instruction */
    /* 5BA28 800C4228 00000000 */  nop
    /* 5BA2C 800C422C 00000000 */  nop
    /* 5BA30 800C4230 0100184A */  rtps
    /* 5BA34 800C4234 0000EEE8 */  swc2       $14, 0x0($a3)
    /* 5BA38 800C4238 0400E224 */  addiu      $v0, $a3, 0x4
    /* 5BA3C 800C423C 00980C48 */  mfc2       $t4, $19 /* handwritten instruction */
    /* 5BA40 800C4240 00000000 */  nop
    /* 5BA44 800C4244 83600C00 */  sra        $t4, $t4, 2
    /* 5BA48 800C4248 00004CAC */  sw         $t4, 0x0($v0)
    /* 5BA4C 800C424C 0200E384 */  lh         $v1, 0x2($a3)
    /* 5BA50 800C4250 00000000 */  nop
    /* 5BA54 800C4254 2A106800 */  slt        $v0, $v1, $t0
    /* 5BA58 800C4258 03004010 */  beqz       $v0, .L800C4268
    /* 5BA5C 800C425C 00000000 */   nop
    /* 5BA60 800C4260 21406000 */  addu       $t0, $v1, $zero
    /* 5BA64 800C4264 4000B28F */  lw         $s2, 0x40($sp)
  .L800C4268:
    /* 5BA68 800C4268 0800E724 */  addiu      $a3, $a3, 0x8
    /* 5BA6C 800C426C 02001026 */  addiu      $s0, $s0, 0x2
    /* 5BA70 800C4270 4000B48F */  lw         $s4, 0x40($sp)
    /* 5BA74 800C4274 0200EF25 */  addiu      $t7, $t7, 0x2
    /* 5BA78 800C4278 01009426 */  addiu      $s4, $s4, 0x1
    /* 5BA7C 800C427C 2000822A */  slti       $v0, $s4, 0x20
    /* 5BA80 800C4280 CAFF4014 */  bnez       $v0, .L800C41AC
    /* 5BA84 800C4284 4000B4AF */   sw        $s4, 0x40($sp)
    /* 5BA88 800C4288 4000B2AF */  sw         $s2, 0x40($sp)
    /* 5BA8C 800C428C 00800634 */  ori        $a2, $zero, 0x8000
    /* 5BA90 800C4290 0F80023C */  lui        $v0, %hi(D_800EA130)
    /* 5BA94 800C4294 30A14724 */  addiu      $a3, $v0, %lo(D_800EA130)
    /* 5BA98 800C4298 FFFF4226 */  addiu      $v0, $s2, -0x1
  .L800C429C:
    /* 5BA9C 800C429C 1F005230 */  andi       $s2, $v0, 0x1F
  .L800C42A0:
    /* 5BAA0 800C42A0 01004226 */  addiu      $v0, $s2, 0x1
    /* 5BAA4 800C42A4 1F004230 */  andi       $v0, $v0, 0x1F
    /* 5BAA8 800C42A8 C0100200 */  sll        $v0, $v0, 3
    /* 5BAAC 800C42AC 21105500 */  addu       $v0, $v0, $s5
    /* 5BAB0 800C42B0 00004A8C */  lw         $t2, 0x0($v0)
    /* 5BAB4 800C42B4 C0101200 */  sll        $v0, $s2, 3
    /* 5BAB8 800C42B8 21105500 */  addu       $v0, $v0, $s5
    /* 5BABC 800C42BC 00004B8C */  lw         $t3, 0x0($v0)
    /* 5BAC0 800C42C0 034C0A00 */  sra        $t1, $t2, 16
    /* 5BAC4 800C42C4 036C0B00 */  sra        $t5, $t3, 16
    /* 5BAC8 800C42C8 03002D11 */  beq        $t1, $t5, .L800C42D8
    /* 5BACC 800C42CC 00000000 */   nop
    /* 5BAD0 800C42D0 0700A105 */  bgez       $t5, .L800C42F0
    /* 5BAD4 800C42D4 2A10A901 */   slt       $v0, $t5, $t1
  .L800C42D8:
    /* 5BAD8 800C42D8 4000B48F */  lw         $s4, 0x40($sp)
    /* 5BADC 800C42DC 00000000 */  nop
    /* 5BAE0 800C42E0 3A005412 */  beq        $s2, $s4, .L800C43CC
    /* 5BAE4 800C42E4 FFFF4226 */   addiu     $v0, $s2, -0x1
    /* 5BAE8 800C42E8 A8100308 */  j          .L800C42A0
    /* 5BAEC 800C42EC 1F005230 */   andi      $s2, $v0, 0x1F
  .L800C42F0:
    /* 5BAF0 800C42F0 36004014 */  bnez       $v0, .L800C43CC
    /* 5BAF4 800C42F4 E0002229 */   slti      $v0, $t1, 0xE0
    /* 5BAF8 800C42F8 34004010 */  beqz       $v0, .L800C43CC
    /* 5BAFC 800C42FC 00140A00 */   sll       $v0, $t2, 16
    /* 5BB00 800C4300 21504600 */  addu       $t2, $v0, $a2
    /* 5BB04 800C4304 00140B00 */  sll        $v0, $t3, 16
    /* 5BB08 800C4308 21584600 */  addu       $t3, $v0, $a2
    /* 5BB0C 800C430C 23186A01 */  subu       $v1, $t3, $t2
    /* 5BB10 800C4310 2310A901 */  subu       $v0, $t5, $t1
    /* 5BB14 800C4314 40100200 */  sll        $v0, $v0, 1
    /* 5BB18 800C4318 21104700 */  addu       $v0, $v0, $a3
    /* 5BB1C 800C431C 00004294 */  lhu        $v0, 0x0($v0)
    /* 5BB20 800C4320 C31B0300 */  sra        $v1, $v1, 15
    /* 5BB24 800C4324 18006200 */  mult       $v1, $v0
    /* 5BB28 800C4328 E100A229 */  slti       $v0, $t5, 0xE1
    /* 5BB2C 800C432C 12580000 */  mflo       $t3
    /* 5BB30 800C4330 02004014 */  bnez       $v0, .L800C433C
    /* 5BB34 800C4334 00000000 */   nop
    /* 5BB38 800C4338 E0000D24 */  addiu      $t5, $zero, 0xE0
  .L800C433C:
    /* 5BB3C 800C433C 04002105 */  bgez       $t1, .L800C4350
    /* 5BB40 800C4340 21203701 */   addu      $a0, $t1, $s7
    /* 5BB44 800C4344 01002925 */  addiu      $t1, $t1, 0x1
    /* 5BB48 800C4348 21504B01 */  addu       $t2, $t2, $t3
    /* 5BB4C 800C434C 21203701 */  addu       $a0, $t1, $s7
  .L800C4350:
    /* 5BB50 800C4350 00008E90 */  lbu        $t6, 0x0($a0)
    /* 5BB54 800C4354 00000000 */  nop
    /* 5BB58 800C4358 1400C019 */  blez       $t6, .L800C43AC
    /* 5BB5C 800C435C 03C40A00 */   sra       $t8, $t2, 16
    /* 5BB60 800C4360 40290900 */  sll        $a1, $t1, 5
    /* 5BB64 800C4364 2110AE00 */  addu       $v0, $a1, $t6
  .L800C4368:
    /* 5BB68 800C4368 40100200 */  sll        $v0, $v0, 1
    /* 5BB6C 800C436C 21185100 */  addu       $v1, $v0, $s1
    /* 5BB70 800C4370 FCFF6284 */  lh         $v0, -0x4($v1)
    /* 5BB74 800C4374 00000000 */  nop
    /* 5BB78 800C4378 2A105800 */  slt        $v0, $v0, $t8
    /* 5BB7C 800C437C 08004010 */  beqz       $v0, .L800C43A0
    /* 5BB80 800C4380 00000000 */   nop
    /* 5BB84 800C4384 FEFF6284 */  lh         $v0, -0x2($v1)
    /* 5BB88 800C4388 00000000 */  nop
    /* 5BB8C 800C438C 2A100203 */  slt        $v0, $t8, $v0
    /* 5BB90 800C4390 06004010 */  beqz       $v0, .L800C43AC
    /* 5BB94 800C4394 00000000 */   nop
    /* 5BB98 800C4398 EB100308 */  j          .L800C43AC
    /* 5BB9C 800C439C FEFF78A4 */   sh        $t8, -0x2($v1)
  .L800C43A0:
    /* 5BBA0 800C43A0 FEFFCE25 */  addiu      $t6, $t6, -0x2
    /* 5BBA4 800C43A4 F0FFC01D */  bgtz       $t6, .L800C4368
    /* 5BBA8 800C43A8 2110AE00 */   addu      $v0, $a1, $t6
  .L800C43AC:
    /* 5BBAC 800C43AC 00008EA0 */  sb         $t6, 0x0($a0)
    /* 5BBB0 800C43B0 01008424 */  addiu      $a0, $a0, 0x1
    /* 5BBB4 800C43B4 01002925 */  addiu      $t1, $t1, 0x1
    /* 5BBB8 800C43B8 2A102D01 */  slt        $v0, $t1, $t5
    /* 5BBBC 800C43BC E4FF4014 */  bnez       $v0, .L800C4350
    /* 5BBC0 800C43C0 21504B01 */   addu      $t2, $t2, $t3
    /* 5BBC4 800C43C4 A7100308 */  j          .L800C429C
    /* 5BBC8 800C43C8 FFFF4226 */   addiu     $v0, $s2, -0x1
  .L800C43CC:
    /* 5BBCC 800C43CC 801F033C */  lui        $v1, (0x1F800000 >> 16)
    /* 5BBD0 800C43D0 FF001E3C */  lui        $fp, (0xFFFFFF >> 16)
    /* 5BBD4 800C43D4 FFFFDE37 */  ori        $fp, $fp, (0xFFFFFF & 0xFFFF)
    /* 5BBD8 800C43D8 4000B28F */  lw         $s2, 0x40($sp)
    /* 5BBDC 800C43DC 00006F8C */  lw         $t7, (0x1F800000 & 0xFFFF)($v1)
    /* 5BBE0 800C43E0 01004226 */  addiu      $v0, $s2, 0x1
  .L800C43E4:
    /* 5BBE4 800C43E4 1F005230 */  andi       $s2, $v0, 0x1F
  .L800C43E8:
    /* 5BBE8 800C43E8 FFFF4226 */  addiu      $v0, $s2, -0x1
    /* 5BBEC 800C43EC 1F004230 */  andi       $v0, $v0, 0x1F
    /* 5BBF0 800C43F0 C0100200 */  sll        $v0, $v0, 3
    /* 5BBF4 800C43F4 21205500 */  addu       $a0, $v0, $s5
    /* 5BBF8 800C43F8 C0101200 */  sll        $v0, $s2, 3
    /* 5BBFC 800C43FC 21185500 */  addu       $v1, $v0, $s5
    /* 5BC00 800C4400 00008A8C */  lw         $t2, 0x0($a0)
    /* 5BC04 800C4404 00006B8C */  lw         $t3, 0x0($v1)
    /* 5BC08 800C4408 034C0A00 */  sra        $t1, $t2, 16
    /* 5BC0C 800C440C 036C0B00 */  sra        $t5, $t3, 16
    /* 5BC10 800C4410 03002D11 */  beq        $t1, $t5, .L800C4420
    /* 5BC14 800C4414 00000000 */   nop
    /* 5BC18 800C4418 0700A105 */  bgez       $t5, .L800C4438
    /* 5BC1C 800C441C 2A10A901 */   slt       $v0, $t5, $t1
  .L800C4420:
    /* 5BC20 800C4420 4000B48F */  lw         $s4, 0x40($sp)
    /* 5BC24 800C4424 00000000 */  nop
    /* 5BC28 800C4428 7C005412 */  beq        $s2, $s4, .L800C461C
    /* 5BC2C 800C442C 01004226 */   addiu     $v0, $s2, 0x1
    /* 5BC30 800C4430 FA100308 */  j          .L800C43E8
    /* 5BC34 800C4434 1F005230 */   andi      $s2, $v0, 0x1F
  .L800C4438:
    /* 5BC38 800C4438 78004014 */  bnez       $v0, .L800C461C
    /* 5BC3C 800C443C E0002229 */   slti      $v0, $t1, 0xE0
    /* 5BC40 800C4440 76004010 */  beqz       $v0, .L800C461C
    /* 5BC44 800C4444 00801434 */   ori       $s4, $zero, 0x8000
    /* 5BC48 800C4448 04008284 */  lh         $v0, 0x4($a0)
    /* 5BC4C 800C444C 04006384 */  lh         $v1, 0x4($v1)
    /* 5BC50 800C4450 00140200 */  sll        $v0, $v0, 16
    /* 5BC54 800C4454 21305400 */  addu       $a2, $v0, $s4
    /* 5BC58 800C4458 001C0300 */  sll        $v1, $v1, 16
    /* 5BC5C 800C445C 21C87400 */  addu       $t9, $v1, $s4
    /* 5BC60 800C4460 23182603 */  subu       $v1, $t9, $a2
    /* 5BC64 800C4464 2310A901 */  subu       $v0, $t5, $t1
    /* 5BC68 800C4468 40100200 */  sll        $v0, $v0, 1
    /* 5BC6C 800C446C 0F80143C */  lui        $s4, %hi(D_800EA130)
    /* 5BC70 800C4470 30A19426 */  addiu      $s4, $s4, %lo(D_800EA130)
    /* 5BC74 800C4474 21105400 */  addu       $v0, $v0, $s4
    /* 5BC78 800C4478 00004494 */  lhu        $a0, 0x0($v0)
    /* 5BC7C 800C447C C31B0300 */  sra        $v1, $v1, 15
    /* 5BC80 800C4480 18006400 */  mult       $v1, $a0
    /* 5BC84 800C4484 00140A00 */  sll        $v0, $t2, 16
    /* 5BC88 800C4488 00801434 */  ori        $s4, $zero, 0x8000
    /* 5BC8C 800C448C 21505400 */  addu       $t2, $v0, $s4
    /* 5BC90 800C4490 00140B00 */  sll        $v0, $t3, 16
    /* 5BC94 800C4494 21585400 */  addu       $t3, $v0, $s4
    /* 5BC98 800C4498 12C80000 */  mflo       $t9
    /* 5BC9C 800C449C 23106A01 */  subu       $v0, $t3, $t2
    /* 5BCA0 800C44A0 C3130200 */  sra        $v0, $v0, 15
    /* 5BCA4 800C44A4 18004400 */  mult       $v0, $a0
    /* 5BCA8 800C44A8 E100A229 */  slti       $v0, $t5, 0xE1
    /* 5BCAC 800C44AC 12580000 */  mflo       $t3
    /* 5BCB0 800C44B0 02004014 */  bnez       $v0, .L800C44BC
    /* 5BCB4 800C44B4 00000000 */   nop
    /* 5BCB8 800C44B8 E0000D24 */  addiu      $t5, $zero, 0xE0
  .L800C44BC:
    /* 5BCBC 800C44BC 06002105 */  bgez       $t1, .L800C44D8
    /* 5BCC0 800C44C0 00E1103C */   lui       $s0, (0xE1000220 >> 16)
  .L800C44C4:
    /* 5BCC4 800C44C4 01002925 */  addiu      $t1, $t1, 0x1
    /* 5BCC8 800C44C8 21504B01 */  addu       $t2, $t2, $t3
    /* 5BCCC 800C44CC FDFF2005 */  bltz       $t1, .L800C44C4
    /* 5BCD0 800C44D0 2130D900 */   addu      $a2, $a2, $t9
    /* 5BCD4 800C44D4 00E1103C */  lui        $s0, (0xE1000220 >> 16)
  .L800C44D8:
    /* 5BCD8 800C44D8 20021036 */  ori        $s0, $s0, (0xE1000220 & 0xFFFF)
  .L800C44DC:
    /* 5BCDC 800C44DC 03C40600 */  sra        $t8, $a2, 16
    /* 5BCE0 800C44E0 0008022F */  sltiu      $v0, $t8, 0x800
    /* 5BCE4 800C44E4 46004010 */  beqz       $v0, .L800C4600
    /* 5BCE8 800C44E8 43100900 */   sra       $v0, $t1, 1
    /* 5BCEC 800C44EC 00120200 */  sll        $v0, $v0, 8
    /* 5BCF0 800C44F0 0042033C */  lui        $v1, (0x42000000 >> 16)
    /* 5BCF4 800C44F4 25B04300 */  or         $s6, $v0, $v1
    /* 5BCF8 800C44F8 80201800 */  sll        $a0, $t8, 2
    /* 5BCFC 800C44FC 03C40A00 */  sra        $t8, $t2, 16
    /* 5BD00 800C4500 2110E902 */  addu       $v0, $s7, $t1
    /* 5BD04 800C4504 801F143C */  lui        $s4, %hi(D_1F800000)
    /* 5BD08 800C4508 00009426 */  addiu      $s4, $s4, %lo(D_1F800000)
    /* 5BD0C 800C450C 0400838E */  lw         $v1, 0x4($s4)
    /* 5BD10 800C4510 00004E90 */  lbu        $t6, 0x0($v0)
    /* 5BD14 800C4514 00000000 */  nop
    /* 5BD18 800C4518 3900C019 */  blez       $t6, .L800C4600
    /* 5BD1C 800C451C 21606400 */   addu      $t4, $v1, $a0
    /* 5BD20 800C4520 40990900 */  sll        $s3, $t1, 5
    /* 5BD24 800C4524 FFFF0233 */  andi       $v0, $t8, 0xFFFF
    /* 5BD28 800C4528 003C0900 */  sll        $a3, $t1, 16
    /* 5BD2C 800C452C 25104700 */  or         $v0, $v0, $a3
    /* 5BD30 800C4530 0800A2AF */  sw         $v0, 0x8($sp)
    /* 5BD34 800C4534 1000E525 */  addiu      $a1, $t7, 0x10
    /* 5BD38 800C4538 21106E02 */  addu       $v0, $s3, $t6
  .L800C453C:
    /* 5BD3C 800C453C 40100200 */  sll        $v0, $v0, 1
    /* 5BD40 800C4540 21105100 */  addu       $v0, $v0, $s1
    /* 5BD44 800C4544 FCFF488C */  lw         $t0, -0x4($v0)
    /* 5BD48 800C4548 FCFF4384 */  lh         $v1, -0x4($v0)
    /* 5BD4C 800C454C 03240800 */  sra        $a0, $t0, 16
    /* 5BD50 800C4550 2A106400 */  slt        $v0, $v1, $a0
    /* 5BD54 800C4554 27004010 */  beqz       $v0, .L800C45F4
    /* 5BD58 800C4558 2A107800 */   slt       $v0, $v1, $t8
    /* 5BD5C 800C455C 13004010 */  beqz       $v0, .L800C45AC
    /* 5BD60 800C4560 2A100403 */   slt       $v0, $t8, $a0
    /* 5BD64 800C4564 26004010 */  beqz       $v0, .L800C4600
    /* 5BD68 800C4568 001A0F00 */   sll       $v1, $t7, 8
    /* 5BD6C 800C456C 0004143C */  lui        $s4, (0x4000000 >> 16)
    /* 5BD70 800C4570 0000828D */  lw         $v0, 0x0($t4)
    /* 5BD74 800C4574 021A0300 */  srl        $v1, $v1, 8
    /* 5BD78 800C4578 24105E00 */  and        $v0, $v0, $fp
    /* 5BD7C 800C457C 25105400 */  or         $v0, $v0, $s4
    /* 5BD80 800C4580 0000E2AD */  sw         $v0, 0x0($t7)
    /* 5BD84 800C4584 1400EF25 */  addiu      $t7, $t7, 0x14
    /* 5BD88 800C4588 02140800 */  srl        $v0, $t0, 16
    /* 5BD8C 800C458C F4FFB0AC */  sw         $s0, -0xC($a1)
    /* 5BD90 800C4590 F8FFB6AC */  sw         $s6, -0x8($a1)
    /* 5BD94 800C4594 0800B48F */  lw         $s4, 0x8($sp)
    /* 5BD98 800C4598 25104700 */  or         $v0, $v0, $a3
    /* 5BD9C 800C459C FCFFB4AC */  sw         $s4, -0x4($a1)
    /* 5BDA0 800C45A0 0000A2AC */  sw         $v0, 0x0($a1)
    /* 5BDA4 800C45A4 80110308 */  j          .L800C4600
    /* 5BDA8 800C45A8 000083AD */   sw        $v1, 0x0($t4)
  .L800C45AC:
    /* 5BDAC 800C45AC 0000828D */  lw         $v0, 0x0($t4)
    /* 5BDB0 800C45B0 0004143C */  lui        $s4, (0x4000000 >> 16)
    /* 5BDB4 800C45B4 24105E00 */  and        $v0, $v0, $fp
    /* 5BDB8 800C45B8 25105400 */  or         $v0, $v0, $s4
    /* 5BDBC 800C45BC 0000E2AD */  sw         $v0, 0x0($t7)
    /* 5BDC0 800C45C0 FFFF0231 */  andi       $v0, $t0, 0xFFFF
    /* 5BDC4 800C45C4 25104700 */  or         $v0, $v0, $a3
    /* 5BDC8 800C45C8 FCFFA2AC */  sw         $v0, -0x4($a1)
    /* 5BDCC 800C45CC 02140800 */  srl        $v0, $t0, 16
    /* 5BDD0 800C45D0 25104700 */  or         $v0, $v0, $a3
    /* 5BDD4 800C45D4 F4FFB0AC */  sw         $s0, -0xC($a1)
    /* 5BDD8 800C45D8 F8FFB6AC */  sw         $s6, -0x8($a1)
    /* 5BDDC 800C45DC 0000A2AC */  sw         $v0, 0x0($a1)
    /* 5BDE0 800C45E0 1400A524 */  addiu      $a1, $a1, 0x14
    /* 5BDE4 800C45E4 00120F00 */  sll        $v0, $t7, 8
    /* 5BDE8 800C45E8 1400EF25 */  addiu      $t7, $t7, 0x14
    /* 5BDEC 800C45EC 02120200 */  srl        $v0, $v0, 8
    /* 5BDF0 800C45F0 000082AD */  sw         $v0, 0x0($t4)
  .L800C45F4:
    /* 5BDF4 800C45F4 FEFFCE25 */  addiu      $t6, $t6, -0x2
    /* 5BDF8 800C45F8 D0FFC01D */  bgtz       $t6, .L800C453C
    /* 5BDFC 800C45FC 21106E02 */   addu      $v0, $s3, $t6
  .L800C4600:
    /* 5BE00 800C4600 01002925 */  addiu      $t1, $t1, 0x1
    /* 5BE04 800C4604 21504B01 */  addu       $t2, $t2, $t3
    /* 5BE08 800C4608 2A102D01 */  slt        $v0, $t1, $t5
    /* 5BE0C 800C460C B3FF4014 */  bnez       $v0, .L800C44DC
    /* 5BE10 800C4610 2130D900 */   addu      $a2, $a2, $t9
    /* 5BE14 800C4614 F9100308 */  j          .L800C43E4
    /* 5BE18 800C4618 01004226 */   addiu     $v0, $s2, 0x1
  .L800C461C:
    /* 5BE1C 800C461C 3000BE8F */  lw         $fp, 0x30($sp)
    /* 5BE20 800C4620 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 5BE24 800C4624 2800B68F */  lw         $s6, 0x28($sp)
    /* 5BE28 800C4628 2400B58F */  lw         $s5, 0x24($sp)
    /* 5BE2C 800C462C 2000B48F */  lw         $s4, 0x20($sp)
    /* 5BE30 800C4630 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 5BE34 800C4634 1800B28F */  lw         $s2, 0x18($sp)
    /* 5BE38 800C4638 1400B18F */  lw         $s1, 0x14($sp)
    /* 5BE3C 800C463C 1000B08F */  lw         $s0, 0x10($sp)
    /* 5BE40 800C4640 801F023C */  lui        $v0, (0x1F800000 >> 16)
    /* 5BE44 800C4644 00004FAC */  sw         $t7, (0x1F800000 & 0xFFFF)($v0)
    /* 5BE48 800C4648 0800E003 */  jr         $ra
    /* 5BE4C 800C464C 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_800C2E24
