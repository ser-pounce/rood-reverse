nonmatching vs_mainMenu_initUiWeapon, 0x9C

glabel vs_mainMenu_initUiWeapon
    /* 3208 800FCA08 40FEBD27 */  addiu      $sp, $sp, -0x1C0
    /* 320C 800FCA0C A801B0AF */  sw         $s0, 0x1A8($sp)
    /* 3210 800FCA10 21808000 */  addu       $s0, $a0, $zero
    /* 3214 800FCA14 AC01B1AF */  sw         $s1, 0x1AC($sp)
    /* 3218 800FCA18 2188A000 */  addu       $s1, $a1, $zero
    /* 321C 800FCA1C B001B2AF */  sw         $s2, 0x1B0($sp)
    /* 3220 800FCA20 2190C000 */  addu       $s2, $a2, $zero
    /* 3224 800FCA24 B401B3AF */  sw         $s3, 0x1B4($sp)
    /* 3228 800FCA28 2198E000 */  addu       $s3, $a3, $zero
    /* 322C 800FCA2C 1080023C */  lui        $v0, %hi(vs_mainMenu_weapons)
    /* 3230 800FCA30 7024438C */  lw         $v1, %lo(vs_mainMenu_weapons)($v0)
    /* 3234 800FCA34 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 3238 800FCA38 68014224 */  addiu      $v0, $v0, %lo(vs_battle_inventory)
    /* 323C 800FCA3C 06006214 */  bne        $v1, $v0, .L800FCA58
    /* 3240 800FCA40 B801BFAF */   sw        $ra, 0x1B8($sp)
    /* 3244 800FCA44 1000A427 */  addiu      $a0, $sp, 0x10
    /* 3248 800FCA48 ABAB010C */  jal        vs_battle_applyWeapon
    /* 324C 800FCA4C 21280002 */   addu      $a1, $s0, $zero
    /* 3250 800FCA50 9CF20308 */  j          .L800FCA70
    /* 3254 800FCA54 1000A427 */   addiu     $a0, $sp, 0x10
  .L800FCA58:
    /* 3258 800FCA58 1000A427 */  addiu      $a0, $sp, 0x10
    /* 325C 800FCA5C 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 3260 800FCA60 8C9A468C */  lw         $a2, %lo(vs_menuD_containerData)($v0)
    /* 3264 800FCA64 8D0A040C */  jal        vs_menuD_initUiWeapon
    /* 3268 800FCA68 21280002 */   addu      $a1, $s0, $zero
    /* 326C 800FCA6C 1000A427 */  addiu      $a0, $sp, 0x10
  .L800FCA70:
    /* 3270 800FCA70 21282002 */  addu       $a1, $s1, $zero
    /* 3274 800FCA74 21304002 */  addu       $a2, $s2, $zero
    /* 3278 800FCA78 17F2030C */  jal        vs_mainMenu_setUiWeapon
    /* 327C 800FCA7C 21386002 */   addu      $a3, $s3, $zero
    /* 3280 800FCA80 08000226 */  addiu      $v0, $s0, 0x8
    /* 3284 800FCA84 000022AE */  sw         $v0, 0x0($s1)
    /* 3288 800FCA88 B801BF8F */  lw         $ra, 0x1B8($sp)
    /* 328C 800FCA8C B401B38F */  lw         $s3, 0x1B4($sp)
    /* 3290 800FCA90 B001B28F */  lw         $s2, 0x1B0($sp)
    /* 3294 800FCA94 AC01B18F */  lw         $s1, 0x1AC($sp)
    /* 3298 800FCA98 A801B08F */  lw         $s0, 0x1A8($sp)
    /* 329C 800FCA9C 0800E003 */  jr         $ra
    /* 32A0 800FCAA0 C001BD27 */   addiu     $sp, $sp, 0x1C0
endlabel vs_mainMenu_initUiWeapon
