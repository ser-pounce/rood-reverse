nonmatching vs_mainMenu_initSetShieldGemMenu, 0x158

glabel vs_mainMenu_initSetShieldGemMenu
    /* 2F04 800FC704 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 2F08 800FC708 3800B4AF */  sw         $s4, 0x38($sp)
    /* 2F0C 800FC70C 21A08000 */  addu       $s4, $a0, $zero
    /* 2F10 800FC710 3000B2AF */  sw         $s2, 0x30($sp)
    /* 2F14 800FC714 21900000 */  addu       $s2, $zero, $zero
    /* 2F18 800FC718 2800B0AF */  sw         $s0, 0x28($sp)
    /* 2F1C 800FC71C FFFF9026 */  addiu      $s0, $s4, -0x1
    /* 2F20 800FC720 1080033C */  lui        $v1, %hi(vs_mainMenu_shields)
    /* 2F24 800FC724 40100500 */  sll        $v0, $a1, 1
    /* 2F28 800FC728 21104500 */  addu       $v0, $v0, $a1
    /* 2F2C 800FC72C 00110200 */  sll        $v0, $v0, 4
    /* 2F30 800FC730 6C24638C */  lw         $v1, %lo(vs_mainMenu_shields)($v1)
    /* 2F34 800FC734 D0FF4224 */  addiu      $v0, $v0, -0x30
    /* 2F38 800FC738 4000BFAF */  sw         $ra, 0x40($sp)
    /* 2F3C 800FC73C 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* 2F40 800FC740 3400B3AF */  sw         $s3, 0x34($sp)
    /* 2F44 800FC744 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 2F48 800FC748 21206200 */  addu       $a0, $v1, $v0
    /* 2F4C 800FC74C 10008290 */  lbu        $v0, 0x10($a0)
    /* 2F50 800FC750 00000000 */  nop
    /* 2F54 800FC754 2A100202 */  slt        $v0, $s0, $v0
    /* 2F58 800FC758 1A004010 */  beqz       $v0, .L800FC7C4
    /* 2F5C 800FC75C 21A8C000 */   addu      $s5, $a2, $zero
    /* 2F60 800FC760 1080023C */  lui        $v0, %hi(vs_mainMenu_itemHelp)
    /* 2F64 800FC764 4025428C */  lw         $v0, %lo(vs_mainMenu_itemHelp)($v0)
    /* 2F68 800FC768 0058033C */  lui        $v1, (0x58000000 >> 16)
    /* 2F6C 800FC76C 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* 2F70 800FC770 2000A3AF */  sw         $v1, 0x20($sp)
    /* 2F74 800FC774 16684224 */  addiu      $v0, $v0, 0x6816
    /* 2F78 800FC778 1800A2AF */  sw         $v0, 0x18($sp)
    /* 2F7C 800FC77C 21109000 */  addu       $v0, $a0, $s0
    /* 2F80 800FC780 2C004390 */  lbu        $v1, 0x2C($v0)
    /* 2F84 800FC784 00000000 */  nop
    /* 2F88 800FC788 0C006010 */  beqz       $v1, .L800FC7BC
    /* 2F8C 800FC78C 1800A527 */   addiu     $a1, $sp, 0x18
    /* 2F90 800FC790 2000A627 */  addiu      $a2, $sp, 0x20
    /* 2F94 800FC794 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 2F98 800FC798 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 2F9C 800FC79C 1080023C */  lui        $v0, %hi(vs_mainMenu_gems)
    /* 2FA0 800FC7A0 C0200300 */  sll        $a0, $v1, 3
    /* 2FA4 800FC7A4 23208300 */  subu       $a0, $a0, $v1
    /* 2FA8 800FC7A8 80200400 */  sll        $a0, $a0, 2
    /* 2FAC 800FC7AC 5824428C */  lw         $v0, %lo(vs_mainMenu_gems)($v0)
    /* 2FB0 800FC7B0 E4FF8424 */  addiu      $a0, $a0, -0x1C
    /* 2FB4 800FC7B4 38F4030C */  jal        vs_mainMenu_setUiGem
    /* 2FB8 800FC7B8 21204400 */   addu      $a0, $v0, $a0
  .L800FC7BC:
    /* 2FBC 800FC7BC F2F10308 */  j          .L800FC7C8
    /* 2FC0 800FC7C0 97001024 */   addiu     $s0, $zero, 0x97
  .L800FC7C4:
    /* 2FC4 800FC7C4 21800000 */  addu       $s0, $zero, $zero
  .L800FC7C8:
    /* 2FC8 800FC7C8 0A009126 */  addiu      $s1, $s4, 0xA
    /* 2FCC 800FC7CC E4FE030C */  jal        vs_mainMenu_deactivateMenuItem
    /* 2FD0 800FC7D0 21202002 */   addu      $a0, $s1, $zero
    /* 2FD4 800FC7D4 17000012 */  beqz       $s0, .L800FC834
    /* 2FD8 800FC7D8 21202002 */   addu      $a0, $s1, $zero
    /* 2FDC 800FC7DC 40011324 */  addiu      $s3, $zero, 0x140
    /* 2FE0 800FC7E0 23887002 */  subu       $s1, $s3, $s0
    /* 2FE4 800FC7E4 21282002 */  addu       $a1, $s1, $zero
    /* 2FE8 800FC7E8 00311400 */  sll        $a2, $s4, 4
    /* 2FEC 800FC7EC 1200C624 */  addiu      $a2, $a2, 0x12
    /* 2FF0 800FC7F0 1000A0AF */  sw         $zero, 0x10($sp)
    /* 2FF4 800FC7F4 1800A28F */  lw         $v0, 0x18($sp)
    /* 2FF8 800FC7F8 21380002 */  addu       $a3, $s0, $zero
    /* 2FFC 800FC7FC 9723030C */  jal        vs_battle_setMenuItem
    /* 3000 800FC800 1400A2AF */   sw        $v0, 0x14($sp)
    /* 3004 800FC804 21904000 */  addu       $s2, $v0, $zero
    /* 3008 800FC808 1C00A38F */  lw         $v1, 0x1C($sp)
    /* 300C 800FC80C 0100A232 */  andi       $v0, $s5, 0x1
    /* 3010 800FC810 0100632C */  sltiu      $v1, $v1, 0x1
    /* 3014 800FC814 05004010 */  beqz       $v0, .L800FC82C
    /* 3018 800FC818 070043A2 */   sb        $v1, 0x7($s2)
    /* 301C 800FC81C 02000224 */  addiu      $v0, $zero, 0x2
    /* 3020 800FC820 140053A6 */  sh         $s3, 0x14($s2)
    /* 3024 800FC824 000042A2 */  sb         $v0, 0x0($s2)
    /* 3028 800FC828 180051A6 */  sh         $s1, 0x18($s2)
  .L800FC82C:
    /* 302C 800FC82C 16000224 */  addiu      $v0, $zero, 0x16
    /* 3030 800FC830 090042A2 */  sb         $v0, 0x9($s2)
  .L800FC834:
    /* 3034 800FC834 21104002 */  addu       $v0, $s2, $zero
    /* 3038 800FC838 4000BF8F */  lw         $ra, 0x40($sp)
    /* 303C 800FC83C 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 3040 800FC840 3800B48F */  lw         $s4, 0x38($sp)
    /* 3044 800FC844 3400B38F */  lw         $s3, 0x34($sp)
    /* 3048 800FC848 3000B28F */  lw         $s2, 0x30($sp)
    /* 304C 800FC84C 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 3050 800FC850 2800B08F */  lw         $s0, 0x28($sp)
    /* 3054 800FC854 0800E003 */  jr         $ra
    /* 3058 800FC858 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel vs_mainMenu_initSetShieldGemMenu
