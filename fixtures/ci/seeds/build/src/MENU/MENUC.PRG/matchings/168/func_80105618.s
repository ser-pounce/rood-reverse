nonmatching func_80105618, 0x5C

glabel func_80105618
    /* 2E18 80105618 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2E1C 8010561C 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 2E20 80105620 00310500 */  sll        $a2, $a1, 4
    /* 2E24 80105624 0A00A424 */  addiu      $a0, $a1, 0xA
    /* 2E28 80105628 40010524 */  addiu      $a1, $zero, 0x140
    /* 2E2C 8010562C 1200C624 */  addiu      $a2, $a2, 0x12
    /* 2E30 80105630 A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 2E34 80105634 97000724 */  addiu      $a3, $zero, 0x97
    /* 2E38 80105638 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2E3C 8010563C 1000A0AF */  sw         $zero, 0x10($sp)
    /* 2E40 80105640 42084224 */  addiu      $v0, $v0, 0x842
    /* 2E44 80105644 9723030C */  jal        vs_battle_setMenuItem
    /* 2E48 80105648 1400A2AF */   sw        $v0, 0x14($sp)
    /* 2E4C 8010564C 02000324 */  addiu      $v1, $zero, 0x2
    /* 2E50 80105650 000043A0 */  sb         $v1, 0x0($v0)
    /* 2E54 80105654 A9000324 */  addiu      $v1, $zero, 0xA9
    /* 2E58 80105658 180043A4 */  sh         $v1, 0x18($v0)
    /* 2E5C 8010565C 01000324 */  addiu      $v1, $zero, 0x1
    /* 2E60 80105660 0A0043A0 */  sb         $v1, 0xA($v0)
    /* 2E64 80105664 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2E68 80105668 00000000 */  nop
    /* 2E6C 8010566C 0800E003 */  jr         $ra
    /* 2E70 80105670 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80105618
