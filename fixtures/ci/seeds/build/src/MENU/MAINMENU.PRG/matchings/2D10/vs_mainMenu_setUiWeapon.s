nonmatching vs_mainMenu_setUiWeapon, 0x1AC

glabel vs_mainMenu_setUiWeapon
    /* 305C 800FC85C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 3060 800FC860 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3064 800FC864 2198A000 */  addu       $s3, $a1, $zero
    /* 3068 800FC868 2000B4AF */  sw         $s4, 0x20($sp)
    /* 306C 800FC86C 21A0C000 */  addu       $s4, $a2, $zero
    /* 3070 800FC870 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3074 800FC874 2190E000 */  addu       $s2, $a3, $zero
    /* 3078 800FC878 21280000 */  addu       $a1, $zero, $zero
    /* 307C 800FC87C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3080 800FC880 18009124 */  addiu      $s1, $a0, 0x18
    /* 3084 800FC884 2400BFAF */  sw         $ra, 0x24($sp)
    /* 3088 800FC888 66E9030C */  jal        vs_mainMenu_getEquipmentMaxStats
    /* 308C 800FC88C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 3090 800FC890 21304000 */  addu       $a2, $v0, $zero
    /* 3094 800FC894 0F80043C */  lui        $a0, %hi(vs_battle_stringContext)
    /* 3098 800FC898 1080033C */  lui        $v1, %hi(vs_mainMenu_itemHelp)
    /* 309C 800FC89C FF00C230 */  andi       $v0, $a2, 0xFF
    /* 30A0 800FC8A0 4025658C */  lw         $a1, %lo(vs_mainMenu_itemHelp)($v1)
    /* 30A4 800FC8A4 40100200 */  sll        $v0, $v0, 1
    /* 30A8 800FC8A8 21104500 */  addu       $v0, $v0, $a1
    /* 30AC 800FC8AC E8024294 */  lhu        $v0, 0x2E8($v0)
    /* 30B0 800FC8B0 68518424 */  addiu      $a0, $a0, %lo(vs_battle_stringContext)
    /* 30B4 800FC8B4 40100200 */  sll        $v0, $v0, 1
    /* 30B8 800FC8B8 2110A200 */  addu       $v0, $a1, $v0
    /* 30BC 800FC8BC 280082AC */  sw         $v0, 0x28($a0)
    /* 30C0 800FC8C0 03120600 */  sra        $v0, $a2, 8
    /* 30C4 800FC8C4 FF004330 */  andi       $v1, $v0, 0xFF
    /* 30C8 800FC8C8 07006010 */  beqz       $v1, .L800FC8E8
    /* 30CC 800FC8CC C3130600 */   sra       $v0, $a2, 15
    /* 30D0 800FC8D0 21106200 */  addu       $v0, $v1, $v0
    /* 30D4 800FC8D4 40100200 */  sll        $v0, $v0, 1
    /* 30D8 800FC8D8 21104500 */  addu       $v0, $v0, $a1
    /* 30DC 800FC8DC 5A044294 */  lhu        $v0, 0x45A($v0)
    /* 30E0 800FC8E0 41F20308 */  j          .L800FC904
    /* 30E4 800FC8E4 40100200 */   sll       $v0, $v0, 1
  .L800FC8E8:
    /* 30E8 800FC8E8 04002292 */  lbu        $v0, 0x4($s1)
    /* 30EC 800FC8EC 00000000 */  nop
    /* 30F0 800FC8F0 40100200 */  sll        $v0, $v0, 1
    /* 30F4 800FC8F4 21104500 */  addu       $v0, $v0, $a1
    /* 30F8 800FC8F8 FC024294 */  lhu        $v0, 0x2FC($v0)
    /* 30FC 800FC8FC 00000000 */  nop
    /* 3100 800FC900 40100200 */  sll        $v0, $v0, 1
  .L800FC904:
    /* 3104 800FC904 2110A200 */  addu       $v0, $a1, $v0
    /* 3108 800FC908 0F80073C */  lui        $a3, %hi(vs_battle_stringContext)
    /* 310C 800FC90C 6851E724 */  addiu      $a3, $a3, %lo(vs_battle_stringContext)
    /* 3110 800FC910 2C0082AC */  sw         $v0, 0x2C($a0)
    /* 3114 800FC914 1080043C */  lui        $a0, %hi(vs_mainMenu_itemNames)
    /* 3118 800FC918 13002392 */  lbu        $v1, 0x13($s1)
    /* 311C 800FC91C 1080103C */  lui        $s0, %hi(vs_mainMenu_itemHelp)
    /* 3120 800FC920 40100300 */  sll        $v0, $v1, 1
    /* 3124 800FC924 21104300 */  addu       $v0, $v0, $v1
    /* 3128 800FC928 C0100200 */  sll        $v0, $v0, 3
    /* 312C 800FC92C 9C22838C */  lw         $v1, %lo(vs_mainMenu_itemNames)($a0)
    /* 3130 800FC930 B8174224 */  addiu      $v0, $v0, 0x17B8
    /* 3134 800FC934 21186200 */  addu       $v1, $v1, $v0
    /* 3138 800FC938 4C00E3AC */  sw         $v1, 0x4C($a3)
    /* 313C 800FC93C 04002292 */  lbu        $v0, 0x4($s1)
    /* 3140 800FC940 4025068E */  lw         $a2, %lo(vs_mainMenu_itemHelp)($s0)
    /* 3144 800FC944 40100200 */  sll        $v0, $v0, 1
    /* 3148 800FC948 21104600 */  addu       $v0, $v0, $a2
    /* 314C 800FC94C 1C034294 */  lhu        $v0, 0x31C($v0)
    /* 3150 800FC950 00000000 */  nop
    /* 3154 800FC954 40100200 */  sll        $v0, $v0, 1
    /* 3158 800FC958 2110C200 */  addu       $v0, $a2, $v0
    /* 315C 800FC95C 4800E2AC */  sw         $v0, 0x48($a3)
    /* 3160 800FC960 10002292 */  lbu        $v0, 0x10($s1)
    /* 3164 800FC964 00000000 */  nop
    /* 3168 800FC968 40100200 */  sll        $v0, $v0, 1
    /* 316C 800FC96C 21104600 */  addu       $v0, $v0, $a2
    /* 3170 800FC970 30034294 */  lhu        $v0, 0x330($v0)
    /* 3174 800FC974 00000000 */  nop
    /* 3178 800FC978 40100200 */  sll        $v0, $v0, 1
    /* 317C 800FC97C 2110C200 */  addu       $v0, $a2, $v0
    /* 3180 800FC980 4400E2AC */  sw         $v0, 0x44($a3)
    /* 3184 800FC984 1080023C */  lui        $v0, %hi(vs_mainMenu_weaponHands)
    /* 3188 800FC988 04002392 */  lbu        $v1, 0x4($s1)
    /* 318C 800FC98C 40214224 */  addiu      $v0, $v0, %lo(vs_mainMenu_weaponHands)
    /* 3190 800FC990 21186200 */  addu       $v1, $v1, $v0
    /* 3194 800FC994 FFFF6290 */  lbu        $v0, -0x1($v1)
    /* 3198 800FC998 21204002 */  addu       $a0, $s2, $zero
    /* 319C 800FC99C 40100200 */  sll        $v0, $v0, 1
    /* 31A0 800FC9A0 21104600 */  addu       $v0, $v0, $a2
    /* 31A4 800FC9A4 38034294 */  lhu        $v0, 0x338($v0)
    /* 31A8 800FC9A8 EA67C524 */  addiu      $a1, $a2, 0x67EA
    /* 31AC 800FC9AC 40100200 */  sll        $v0, $v0, 1
    /* 31B0 800FC9B0 2130C200 */  addu       $a2, $a2, $v0
    /* 31B4 800FC9B4 171A030C */  jal        vs_battle_printf
    /* 31B8 800FC9B8 4000E6AC */   sw        $a2, 0x40($a3)
    /* 31BC 800FC9BC 4025058E */  lw         $a1, %lo(vs_mainMenu_itemHelp)($s0)
    /* 31C0 800FC9C0 21204000 */  addu       $a0, $v0, $zero
    /* 31C4 800FC9C4 171A030C */  jal        vs_battle_printf
    /* 31C8 800FC9C8 F667A524 */   addiu     $a1, $a1, 0x67F6
    /* 31CC 800FC9CC 040072AE */  sw         $s2, 0x4($s3)
    /* 31D0 800FC9D0 04002392 */  lbu        $v1, 0x4($s1)
    /* 31D4 800FC9D4 13002292 */  lbu        $v0, 0x13($s1)
    /* 31D8 800FC9D8 801E0300 */  sll        $v1, $v1, 26
    /* 31DC 800FC9DC 00140200 */  sll        $v0, $v0, 16
    /* 31E0 800FC9E0 21186200 */  addu       $v1, $v1, $v0
    /* 31E4 800FC9E4 000083AE */  sw         $v1, 0x0($s4)
    /* 31E8 800FC9E8 2400BF8F */  lw         $ra, 0x24($sp)
    /* 31EC 800FC9EC 2000B48F */  lw         $s4, 0x20($sp)
    /* 31F0 800FC9F0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 31F4 800FC9F4 1800B28F */  lw         $s2, 0x18($sp)
    /* 31F8 800FC9F8 1400B18F */  lw         $s1, 0x14($sp)
    /* 31FC 800FC9FC 1000B08F */  lw         $s0, 0x10($sp)
    /* 3200 800FCA00 0800E003 */  jr         $ra
    /* 3204 800FCA04 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel vs_mainMenu_setUiWeapon
