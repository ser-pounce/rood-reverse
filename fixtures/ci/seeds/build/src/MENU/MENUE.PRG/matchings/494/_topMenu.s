nonmatching _topMenu, 0x108

glabel _topMenu
    /* 111C 8010391C 78FFBD27 */  addiu      $sp, $sp, -0x88
    /* 1120 80103920 05008010 */  beqz       $a0, .L80103938
    /* 1124 80103924 8000BFAF */   sw        $ra, 0x80($sp)
    /* 1128 80103928 1080023C */  lui        $v0, %hi(_topMenu_state)
    /* 112C 8010392C 305240AC */  sw         $zero, %lo(_topMenu_state)($v0)
    /* 1130 80103930 1080023C */  lui        $v0, %hi(_selectedRow)
    /* 1134 80103934 345240AC */  sw         $zero, %lo(_selectedRow)($v0)
  .L80103938:
    /* 1138 80103938 1080023C */  lui        $v0, %hi(_topMenu_state)
    /* 113C 8010393C 3052438C */  lw         $v1, %lo(_topMenu_state)($v0)
    /* 1140 80103940 00000000 */  nop
    /* 1144 80103944 05006010 */  beqz       $v1, .L8010395C
    /* 1148 80103948 01000224 */   addiu     $v0, $zero, 0x1
    /* 114C 8010394C 28006210 */  beq        $v1, $v0, .L801039F0
    /* 1150 80103950 00000000 */   nop
    /* 1154 80103954 850E0408 */  j          .L80103A14
    /* 1158 80103958 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8010395C:
    /* 115C 8010395C 21500000 */  addu       $t2, $zero, $zero
    /* 1160 80103960 1C000924 */  addiu      $t1, $zero, 0x1C
    /* 1164 80103964 04000824 */  addiu      $t0, $zero, 0x4
    /* 1168 80103968 1000AB27 */  addiu      $t3, $sp, 0x10
    /* 116C 8010396C 21306001 */  addu       $a2, $t3, $zero
    /* 1170 80103970 1080023C */  lui        $v0, %hi(_menuText)
    /* 1174 80103974 544E4724 */  addiu      $a3, $v0, %lo(_menuText)
    /* 1178 80103978 2128E000 */  addu       $a1, $a3, $zero
  .L8010397C:
    /* 117C 8010397C 21182701 */  addu       $v1, $t1, $a3
    /* 1180 80103980 02002925 */  addiu      $t1, $t1, 0x2
    /* 1184 80103984 21206801 */  addu       $a0, $t3, $t0
    /* 1188 80103988 08000825 */  addiu      $t0, $t0, 0x8
    /* 118C 8010398C 0000A294 */  lhu        $v0, 0x0($a1)
    /* 1190 80103990 0200A524 */  addiu      $a1, $a1, 0x2
    /* 1194 80103994 01004A25 */  addiu      $t2, $t2, 0x1
    /* 1198 80103998 40100200 */  sll        $v0, $v0, 1
    /* 119C 8010399C 21104700 */  addu       $v0, $v0, $a3
    /* 11A0 801039A0 0000C2AC */  sw         $v0, 0x0($a2)
    /* 11A4 801039A4 00006294 */  lhu        $v0, 0x0($v1)
    /* 11A8 801039A8 00000000 */  nop
    /* 11AC 801039AC 40100200 */  sll        $v0, $v0, 1
    /* 11B0 801039B0 21104700 */  addu       $v0, $v0, $a3
    /* 11B4 801039B4 000082AC */  sw         $v0, 0x0($a0)
    /* 11B8 801039B8 0E004229 */  slti       $v0, $t2, 0xE
    /* 11BC 801039BC EFFF4014 */  bnez       $v0, .L8010397C
    /* 11C0 801039C0 0800C624 */   addiu     $a2, $a2, 0x8
    /* 11C4 801039C4 0F80023C */  lui        $v0, %hi(vs_battle_manualDisplayState)
    /* 11C8 801039C8 0E000424 */  addiu      $a0, $zero, 0xE
    /* 11CC 801039CC C81B4594 */  lhu        $a1, %lo(vs_battle_manualDisplayState)($v0)
    /* 11D0 801039D0 360B040C */  jal        _setMenuRows
    /* 11D4 801039D4 1000A627 */   addiu     $a2, $sp, 0x10
    /* 11D8 801039D8 1080033C */  lui        $v1, %hi(_topMenu_state)
    /* 11DC 801039DC 3052628C */  lw         $v0, %lo(_topMenu_state)($v1)
    /* 11E0 801039E0 00000000 */  nop
    /* 11E4 801039E4 01004224 */  addiu      $v0, $v0, 0x1
    /* 11E8 801039E8 840E0408 */  j          .L80103A10
    /* 11EC 801039EC 305262AC */   sw        $v0, %lo(_topMenu_state)($v1)
  .L801039F0:
    /* 11F0 801039F0 7C0B040C */  jal        _getSelectedRow
    /* 11F4 801039F4 00000000 */   nop
    /* 11F8 801039F8 21184000 */  addu       $v1, $v0, $zero
    /* 11FC 801039FC 1080023C */  lui        $v0, %hi(_selectedRow)
    /* 1200 80103A00 345243AC */  sw         $v1, %lo(_selectedRow)($v0)
    /* 1204 80103A04 FFFF0424 */  addiu      $a0, $zero, -0x1
    /* 1208 80103A08 02006414 */  bne        $v1, $a0, .L80103A14
    /* 120C 80103A0C 21106000 */   addu      $v0, $v1, $zero
  .L80103A10:
    /* 1210 80103A10 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L80103A14:
    /* 1214 80103A14 8000BF8F */  lw         $ra, 0x80($sp)
    /* 1218 80103A18 00000000 */  nop
    /* 121C 80103A1C 0800E003 */  jr         $ra
    /* 1220 80103A20 8800BD27 */   addiu     $sp, $sp, 0x88
endlabel _topMenu
