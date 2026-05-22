nonmatching func_80044F60, 0xA0

glabel func_80044F60
    /* 35760 80044F60 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 35764 80044F64 2138A000 */  addu       $a3, $a1, $zero
    /* 35768 80044F68 2128C000 */  addu       $a1, $a2, $zero
    /* 3576C 80044F6C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 35770 80044F70 1800B2AF */  sw         $s2, 0x18($sp)
    /* 35774 80044F74 1400B1AF */  sw         $s1, 0x14($sp)
    /* 35778 80044F78 1A008010 */  beqz       $a0, .L80044FE4
    /* 3577C 80044F7C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 35780 80044F80 0680033C */  lui        $v1, %hi(vs_main_soundData)
    /* 35784 80044F84 38E07124 */  addiu      $s1, $v1, %lo(vs_main_soundData)
    /* 35788 80044F88 FFFF9224 */  addiu      $s2, $a0, -0x1
    /* 3578C 80044F8C 80101200 */  sll        $v0, $s2, 2
    /* 35790 80044F90 21805100 */  addu       $s0, $v0, $s1
    /* 35794 80044F94 2400028E */  lw         $v0, 0x24($s0)
    /* 35798 80044F98 00000000 */  nop
    /* 3579C 80044F9C 0D004010 */  beqz       $v0, .L80044FD4
    /* 357A0 80044FA0 2130E000 */   addu      $a2, $a3, $zero
    /* 357A4 80044FA4 38E064AC */  sw         $a0, %lo(vs_main_soundData)($v1)
    /* 357A8 80044FA8 2400048E */  lw         $a0, 0x24($s0)
    /* 357AC 80044FAC 2048000C */  jal        func_80012080
    /* 357B0 80044FB0 0C0024AE */   sw        $a0, 0xC($s1)
    /* 357B4 80044FB4 03004010 */  beqz       $v0, .L80044FC4
    /* 357B8 80044FB8 00000000 */   nop
    /* 357BC 80044FBC 140002AE */  sw         $v0, 0x14($s0)
    /* 357C0 80044FC0 040022AE */  sw         $v0, 0x4($s1)
  .L80044FC4:
    /* 357C4 80044FC4 21105102 */  addu       $v0, $s2, $s1
    /* 357C8 80044FC8 10004290 */  lbu        $v0, 0x10($v0)
    /* 357CC 80044FCC 00000000 */  nop
    /* 357D0 80044FD0 080022AE */  sw         $v0, 0x8($s1)
  .L80044FD4:
    /* 357D4 80044FD4 0680023C */  lui        $v0, %hi(vs_main_soundData + 0x4)
    /* 357D8 80044FD8 3CE0428C */  lw         $v0, %lo(vs_main_soundData + 0x4)($v0)
    /* 357DC 80044FDC FA130108 */  j          .L80044FE8
    /* 357E0 80044FE0 00000000 */   nop
  .L80044FE4:
    /* 357E4 80044FE4 21100000 */  addu       $v0, $zero, $zero
  .L80044FE8:
    /* 357E8 80044FE8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 357EC 80044FEC 1800B28F */  lw         $s2, 0x18($sp)
    /* 357F0 80044FF0 1400B18F */  lw         $s1, 0x14($sp)
    /* 357F4 80044FF4 1000B08F */  lw         $s0, 0x10($sp)
    /* 357F8 80044FF8 0800E003 */  jr         $ra
    /* 357FC 80044FFC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80044F60
