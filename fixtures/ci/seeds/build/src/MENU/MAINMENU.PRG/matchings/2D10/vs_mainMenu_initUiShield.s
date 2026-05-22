nonmatching vs_mainMenu_initUiShield, 0x8C

glabel vs_mainMenu_initUiShield
    /* 3640 800FCE40 78FEBD27 */  addiu      $sp, $sp, -0x188
    /* 3644 800FCE44 21408000 */  addu       $t0, $a0, $zero
    /* 3648 800FCE48 7801B0AF */  sw         $s0, 0x178($sp)
    /* 364C 800FCE4C 2180A000 */  addu       $s0, $a1, $zero
    /* 3650 800FCE50 7C01B1AF */  sw         $s1, 0x17C($sp)
    /* 3654 800FCE54 2188C000 */  addu       $s1, $a2, $zero
    /* 3658 800FCE58 8001B2AF */  sw         $s2, 0x180($sp)
    /* 365C 800FCE5C 2190E000 */  addu       $s2, $a3, $zero
    /* 3660 800FCE60 1080023C */  lui        $v0, %hi(vs_mainMenu_shields)
    /* 3664 800FCE64 6C24438C */  lw         $v1, %lo(vs_mainMenu_shields)($v0)
    /* 3668 800FCE68 0680023C */  lui        $v0, %hi(D_80060268)
    /* 366C 800FCE6C 68024224 */  addiu      $v0, $v0, %lo(D_80060268)
    /* 3670 800FCE70 06006214 */  bne        $v1, $v0, .L800FCE8C
    /* 3674 800FCE74 8401BFAF */   sw        $ra, 0x184($sp)
    /* 3678 800FCE78 1000A427 */  addiu      $a0, $sp, 0x10
    /* 367C 800FCE7C 0BAC010C */  jal        vs_battle_applyShield
    /* 3680 800FCE80 21280001 */   addu      $a1, $t0, $zero
    /* 3684 800FCE84 A9F30308 */  j          .L800FCEA4
    /* 3688 800FCE88 1000A427 */   addiu     $a0, $sp, 0x10
  .L800FCE8C:
    /* 368C 800FCE8C 1000A427 */  addiu      $a0, $sp, 0x10
    /* 3690 800FCE90 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 3694 800FCE94 8C9A468C */  lw         $a2, %lo(vs_menuD_containerData)($v0)
    /* 3698 800FCE98 EC0A040C */  jal        vs_menuD_initUiShield
    /* 369C 800FCE9C 21280001 */   addu      $a1, $t0, $zero
    /* 36A0 800FCEA0 1000A427 */  addiu      $a0, $sp, 0x10
  .L800FCEA4:
    /* 36A4 800FCEA4 21280002 */  addu       $a1, $s0, $zero
    /* 36A8 800FCEA8 21302002 */  addu       $a2, $s1, $zero
    /* 36AC 800FCEAC 3AF3030C */  jal        vs_mainMenu_setUiShield
    /* 36B0 800FCEB0 21384002 */   addu      $a3, $s2, $zero
    /* 36B4 800FCEB4 8401BF8F */  lw         $ra, 0x184($sp)
    /* 36B8 800FCEB8 8001B28F */  lw         $s2, 0x180($sp)
    /* 36BC 800FCEBC 7C01B18F */  lw         $s1, 0x17C($sp)
    /* 36C0 800FCEC0 7801B08F */  lw         $s0, 0x178($sp)
    /* 36C4 800FCEC4 0800E003 */  jr         $ra
    /* 36C8 800FCEC8 8801BD27 */   addiu     $sp, $sp, 0x188
endlabel vs_mainMenu_initUiShield
