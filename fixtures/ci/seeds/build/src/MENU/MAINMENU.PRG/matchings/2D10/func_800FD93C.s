nonmatching func_800FD93C, 0x1C8

glabel func_800FD93C
    /* 413C 800FD93C 1080023C */  lui        $v0, %hi(vs_mainMenu_itemHelp)
    /* 4140 800FD940 1080033C */  lui        $v1, %hi(vs_mainMenu_weapons)
    /* 4144 800FD944 4025428C */  lw         $v0, %lo(vs_mainMenu_itemHelp)($v0)
    /* 4148 800FD948 7024638C */  lw         $v1, %lo(vs_mainMenu_weapons)($v1)
    /* 414C 800FD94C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 4150 800FD950 2800B2AF */  sw         $s2, 0x28($sp)
    /* 4154 800FD954 2400B1AF */  sw         $s1, 0x24($sp)
    /* 4158 800FD958 1C684224 */  addiu      $v0, $v0, 0x681C
    /* 415C 800FD95C 1400A2AF */  sw         $v0, 0x14($sp)
    /* 4160 800FD960 1080023C */  lui        $v0, %hi(D_801024A1)
    /* 4164 800FD964 A1245290 */  lbu        $s2, %lo(D_801024A1)($v0)
    /* 4168 800FD968 21888000 */  addu       $s1, $a0, $zero
    /* 416C 800FD96C 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 4170 800FD970 2000B0AF */  sw         $s0, 0x20($sp)
    /* 4174 800FD974 40111200 */  sll        $v0, $s2, 5
    /* 4178 800FD978 E0FF4224 */  addiu      $v0, $v0, -0x20
    /* 417C 800FD97C 21806200 */  addu       $s0, $v1, $v0
    /* 4180 800FD980 0600222E */  sltiu      $v0, $s1, 0x6
    /* 4184 800FD984 50004010 */  beqz       $v0, .L800FDAC8
    /* 4188 800FD988 1080023C */   lui       $v0, %hi(jtbl_800F992C)
    /* 418C 800FD98C 2C994224 */  addiu      $v0, $v0, %lo(jtbl_800F992C)
    /* 4190 800FD990 80181100 */  sll        $v1, $s1, 2
    /* 4194 800FD994 21186200 */  addu       $v1, $v1, $v0
    /* 4198 800FD998 0000628C */  lw         $v0, 0x0($v1)
    /* 419C 800FD99C 00000000 */  nop
    /* 41A0 800FD9A0 08004000 */  jr         $v0
    /* 41A4 800FD9A4 00000000 */   nop
    /* 41A8 800FD9A8 21200002 */  addu       $a0, $s0, $zero
    /* 41AC 800FD9AC 1000A527 */  addiu      $a1, $sp, 0x10
    /* 41B0 800FD9B0 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 41B4 800FD9B4 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 41B8 800FD9B8 82F2030C */  jal        vs_mainMenu_initUiWeapon
    /* 41BC 800FD9BC 1800A627 */   addiu     $a2, $sp, 0x18
    /* 41C0 800FD9C0 B3F60308 */  j          .L800FDACC
    /* 41C4 800FD9C4 0A002426 */   addiu     $a0, $s1, 0xA
    /* 41C8 800FD9C8 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 41CC 800FD9CC 0B000424 */   addiu     $a0, $zero, 0xB
    /* 41D0 800FD9D0 1000A527 */  addiu      $a1, $sp, 0x10
    /* 41D4 800FD9D4 1800A627 */  addiu      $a2, $sp, 0x18
    /* 41D8 800FD9D8 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 41DC 800FD9DC 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 41E0 800FD9E0 01000292 */  lbu        $v0, 0x1($s0)
    /* 41E4 800FD9E4 1080033C */  lui        $v1, %hi(vs_mainMenu_blades)
    /* 41E8 800FD9E8 40200200 */  sll        $a0, $v0, 1
    /* 41EC 800FD9EC 21208200 */  addu       $a0, $a0, $v0
    /* 41F0 800FD9F0 80200400 */  sll        $a0, $a0, 2
    /* 41F4 800FD9F4 23208200 */  subu       $a0, $a0, $v0
    /* 41F8 800FD9F8 80200400 */  sll        $a0, $a0, 2
    /* 41FC 800FD9FC 6424628C */  lw         $v0, %lo(vs_mainMenu_blades)($v1)
    /* 4200 800FDA00 D4FF8424 */  addiu      $a0, $a0, -0x2C
    /* 4204 800FDA04 A9F2030C */  jal        vs_mainMenu_setUiBlade
    /* 4208 800FDA08 21204400 */   addu      $a0, $v0, $a0
    /* 420C 800FDA0C 01000492 */  lbu        $a0, 0x1($s0)
    /* 4210 800FDA10 01F5030C */  jal        vs_mainMenu_setUiBladeStats
    /* 4214 800FDA14 00000000 */   nop
    /* 4218 800FDA18 B3F60308 */  j          .L800FDACC
    /* 421C 800FDA1C 0A002426 */   addiu     $a0, $s1, 0xA
    /* 4220 800FDA20 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 4224 800FDA24 08000424 */   addiu     $a0, $zero, 0x8
    /* 4228 800FDA28 1000A527 */  addiu      $a1, $sp, 0x10
    /* 422C 800FDA2C 1800A627 */  addiu      $a2, $sp, 0x18
    /* 4230 800FDA30 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 4234 800FDA34 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 4238 800FDA38 1080023C */  lui        $v0, %hi(vs_mainMenu_grips)
    /* 423C 800FDA3C 02000492 */  lbu        $a0, 0x2($s0)
    /* 4240 800FDA40 6024428C */  lw         $v0, %lo(vs_mainMenu_grips)($v0)
    /* 4244 800FDA44 00210400 */  sll        $a0, $a0, 4
    /* 4248 800FDA48 F0FF8424 */  addiu      $a0, $a0, -0x10
    /* 424C 800FDA4C 03F3030C */  jal        vs_mainMenu_setUiGrip
    /* 4250 800FDA50 21204400 */   addu      $a0, $v0, $a0
    /* 4254 800FDA54 02000492 */  lbu        $a0, 0x2($s0)
    /* 4258 800FDA58 41F5030C */  jal        vs_mainMenu_setUiGripStats
    /* 425C 800FDA5C 00000000 */   nop
    /* 4260 800FDA60 B3F60308 */  j          .L800FDACC
    /* 4264 800FDA64 0A002426 */   addiu     $a0, $s1, 0xA
    /* 4268 800FDA68 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 426C 800FDA6C 08000424 */   addiu     $a0, $zero, 0x8
    /* 4270 800FDA70 21103002 */  addu       $v0, $s1, $s0
    /* 4274 800FDA74 01005090 */  lbu        $s0, 0x1($v0)
    /* 4278 800FDA78 00000000 */  nop
    /* 427C 800FDA7C 10000012 */  beqz       $s0, .L800FDAC0
    /* 4280 800FDA80 1000A527 */   addiu     $a1, $sp, 0x10
    /* 4284 800FDA84 1800A627 */  addiu      $a2, $sp, 0x18
    /* 4288 800FDA88 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 428C 800FDA8C 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 4290 800FDA90 1080023C */  lui        $v0, %hi(vs_mainMenu_gems)
    /* 4294 800FDA94 C0201000 */  sll        $a0, $s0, 3
    /* 4298 800FDA98 23209000 */  subu       $a0, $a0, $s0
    /* 429C 800FDA9C 80200400 */  sll        $a0, $a0, 2
    /* 42A0 800FDAA0 5824428C */  lw         $v0, %lo(vs_mainMenu_gems)($v0)
    /* 42A4 800FDAA4 E4FF8424 */  addiu      $a0, $a0, -0x1C
    /* 42A8 800FDAA8 38F4030C */  jal        vs_mainMenu_setUiGem
    /* 42AC 800FDAAC 21204400 */   addu      $a0, $v0, $a0
    /* 42B0 800FDAB0 1EF6030C */  jal        vs_mainMenu_setGemStats
    /* 42B4 800FDAB4 21200002 */   addu      $a0, $s0, $zero
    /* 42B8 800FDAB8 B3F60308 */  j          .L800FDACC
    /* 42BC 800FDABC 0A002426 */   addiu     $a0, $s1, 0xA
  .L800FDAC0:
    /* 42C0 800FDAC0 88F4030C */  jal        vs_mainMenu_resetStats
    /* 42C4 800FDAC4 00000000 */   nop
  .L800FDAC8:
    /* 42C8 800FDAC8 0A002426 */  addiu      $a0, $s1, 0xA
  .L800FDACC:
    /* 42CC 800FDACC 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentSubtype)
    /* 42D0 800FDAD0 01001024 */  addiu      $s0, $zero, 0x1
    /* 42D4 800FDAD4 452550A0 */  sb         $s0, %lo(vs_mainMenu_equipmentSubtype)($v0)
    /* 42D8 800FDAD8 1080023C */  lui        $v0, %hi(D_801024A1)
    /* 42DC 800FDADC 9223030C */  jal        vs_battle_getMenuItem
    /* 42E0 800FDAE0 A12452A0 */   sb        $s2, %lo(D_801024A1)($v0)
    /* 42E4 800FDAE4 060050A0 */  sb         $s0, 0x6($v0)
    /* 42E8 800FDAE8 1400A28F */  lw         $v0, 0x14($sp)
    /* 42EC 800FDAEC 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 42F0 800FDAF0 2800B28F */  lw         $s2, 0x28($sp)
    /* 42F4 800FDAF4 2400B18F */  lw         $s1, 0x24($sp)
    /* 42F8 800FDAF8 2000B08F */  lw         $s0, 0x20($sp)
    /* 42FC 800FDAFC 0800E003 */  jr         $ra
    /* 4300 800FDB00 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800FD93C
