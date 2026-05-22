nonmatching vs_mainMenu_ensureItemNamesLoaded, 0x58

glabel vs_mainMenu_ensureItemNamesLoaded
    /* 4E94 800FE694 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4E98 800FE698 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4E9C 800FE69C 1080103C */  lui        $s0, %hi(vs_mainMenu_itemNames)
    /* 4EA0 800FE6A0 9C22028E */  lw         $v0, %lo(vs_mainMenu_itemNames)($s0)
    /* 4EA4 800FE6A4 00000000 */  nop
    /* 4EA8 800FE6A8 03004014 */  bnez       $v0, .L800FE6B8
    /* 4EAC 800FE6AC 1400BFAF */   sw        $ra, 0x14($sp)
    /* 4EB0 800FE6B0 B7F90308 */  j          .L800FE6DC
    /* 4EB4 800FE6B4 01000224 */   addiu     $v0, $zero, 0x1
  .L800FE6B8:
    /* 4EB8 800FE6B8 73F9030C */  jal        vs_mainMenu_loadItemNames
    /* 4EBC 800FE6BC 21200000 */   addu      $a0, $zero, $zero
    /* 4EC0 800FE6C0 06004010 */  beqz       $v0, .L800FE6DC
    /* 4EC4 800FE6C4 21100000 */   addu      $v0, $zero, $zero
    /* 4EC8 800FE6C8 9C22048E */  lw         $a0, %lo(vs_mainMenu_itemNames)($s0)
    /* 4ECC 800FE6CC 180F010C */  jal        vs_main_freeHeapR
    /* 4ED0 800FE6D0 00000000 */   nop
    /* 4ED4 800FE6D4 01000224 */  addiu      $v0, $zero, 0x1
    /* 4ED8 800FE6D8 9C2200AE */  sw         $zero, %lo(vs_mainMenu_itemNames)($s0)
  .L800FE6DC:
    /* 4EDC 800FE6DC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4EE0 800FE6E0 1000B08F */  lw         $s0, 0x10($sp)
    /* 4EE4 800FE6E4 0800E003 */  jr         $ra
    /* 4EE8 800FE6E8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_mainMenu_ensureItemNamesLoaded
