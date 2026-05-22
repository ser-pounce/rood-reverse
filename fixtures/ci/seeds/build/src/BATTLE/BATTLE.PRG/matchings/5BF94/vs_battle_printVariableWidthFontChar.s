nonmatching vs_battle_printVariableWidthFontChar, 0x118

glabel vs_battle_printVariableWidthFontChar
    /* 5E8F8 800C70F8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 5E8FC 800C70FC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5E900 800C7100 21808000 */  addu       $s0, $a0, $zero
    /* 5E904 800C7104 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5E908 800C7108 2188A000 */  addu       $s1, $a1, $zero
    /* 5E90C 800C710C 2128C000 */  addu       $a1, $a2, $zero
    /* 5E910 800C7110 8F000224 */  addiu      $v0, $zero, 0x8F
    /* 5E914 800C7114 38000212 */  beq        $s0, $v0, .L800C71F8
    /* 5E918 800C7118 1800BFAF */   sw        $ra, 0x18($sp)
    /* 5E91C 800C711C 0C00063C */  lui        $a2, (0xC000C >> 16)
    /* 5E920 800C7120 0F80023C */  lui        $v0, %hi(_fontTable)
    /* 5E924 800C7124 0C00C634 */  ori        $a2, $a2, (0xC000C & 0xFFFF)
    /* 5E928 800C7128 002C0500 */  sll        $a1, $a1, 16
    /* 5E92C 800C712C B94C4290 */  lbu        $v0, %lo(_fontTable)($v0)
    /* 5E930 800C7130 0C00E724 */  addiu      $a3, $a3, 0xC
    /* 5E934 800C7134 40180200 */  sll        $v1, $v0, 1
    /* 5E938 800C7138 21186200 */  addu       $v1, $v1, $v0
    /* 5E93C 800C713C 80110300 */  sll        $v0, $v1, 6
    /* 5E940 800C7140 23104300 */  subu       $v0, $v0, $v1
    /* 5E944 800C7144 21800202 */  addu       $s0, $s0, $v0
    /* 5E948 800C7148 0F80033C */  lui        $v1, %hi(_fontBrightness)
    /* 5E94C 800C714C FFFF2232 */  andi       $v0, $s1, 0xFFFF
    /* 5E950 800C7150 BC4C648C */  lw         $a0, %lo(_fontBrightness)($v1)
    /* 5E954 800C7154 8C00030C */  jal        vs_battle_setSprite
    /* 5E958 800C7158 25284500 */   or        $a1, $v0, $a1
    /* 5E95C 800C715C 1886053C */  lui        $a1, (0x86186187 >> 16)
    /* 5E960 800C7160 8761A534 */  ori        $a1, $a1, (0x86186187 & 0xFFFF)
    /* 5E964 800C7164 19000502 */  multu      $s0, $a1
    /* 5E968 800C7168 00E1033C */  lui        $v1, (0xE100002D >> 16)
    /* 5E96C 800C716C 2D006334 */  ori        $v1, $v1, (0xE100002D & 0xFFFF)
    /* 5E970 800C7170 040043AC */  sw         $v1, 0x4($v0)
    /* 5E974 800C7174 10280000 */  mfhi       $a1
    /* 5E978 800C7178 23180502 */  subu       $v1, $s0, $a1
    /* 5E97C 800C717C 42180300 */  srl        $v1, $v1, 1
    /* 5E980 800C7180 2128A300 */  addu       $a1, $a1, $v1
    /* 5E984 800C7184 02290500 */  srl        $a1, $a1, 4
    /* 5E988 800C7188 80180500 */  sll        $v1, $a1, 2
    /* 5E98C 800C718C 21186500 */  addu       $v1, $v1, $a1
    /* 5E990 800C7190 80180300 */  sll        $v1, $v1, 2
    /* 5E994 800C7194 21186500 */  addu       $v1, $v1, $a1
    /* 5E998 800C7198 23180302 */  subu       $v1, $s0, $v1
    /* 5E99C 800C719C 40300300 */  sll        $a2, $v1, 1
    /* 5E9A0 800C71A0 2130C300 */  addu       $a2, $a2, $v1
    /* 5E9A4 800C71A4 80300600 */  sll        $a2, $a2, 2
    /* 5E9A8 800C71A8 40200500 */  sll        $a0, $a1, 1
    /* 5E9AC 800C71AC 21208500 */  addu       $a0, $a0, $a1
    /* 5E9B0 800C71B0 80220400 */  sll        $a0, $a0, 10
    /* 5E9B4 800C71B4 0F80033C */  lui        $v1, %hi(D_800F4CB8)
    /* 5E9B8 800C71B8 B84C6390 */  lbu        $v1, %lo(D_800F4CB8)($v1)
    /* 5E9BC 800C71BC 2530C400 */  or         $a2, $a2, $a0
    /* 5E9C0 800C71C0 00190300 */  sll        $v1, $v1, 4
    /* 5E9C4 800C71C4 40036324 */  addiu      $v1, $v1, 0x340
    /* 5E9C8 800C71C8 03190300 */  sra        $v1, $v1, 4
    /* 5E9CC 800C71CC 3F006330 */  andi       $v1, $v1, 0x3F
    /* 5E9D0 800C71D0 80376334 */  ori        $v1, $v1, 0x3780
    /* 5E9D4 800C71D4 001C0300 */  sll        $v1, $v1, 16
    /* 5E9D8 800C71D8 2530C300 */  or         $a2, $a2, $v1
    /* 5E9DC 800C71DC 100046AC */  sw         $a2, 0x10($v0)
    /* 5E9E0 800C71E0 0F80023C */  lui        $v0, %hi(vs_battle_characterWidths)
    /* 5E9E4 800C71E4 10B84224 */  addiu      $v0, $v0, %lo(vs_battle_characterWidths)
    /* 5E9E8 800C71E8 21100202 */  addu       $v0, $s0, $v0
    /* 5E9EC 800C71EC 00004290 */  lbu        $v0, 0x0($v0)
    /* 5E9F0 800C71F0 7F1C0308 */  j          .L800C71FC
    /* 5E9F4 800C71F4 21102202 */   addu      $v0, $s1, $v0
  .L800C71F8:
    /* 5E9F8 800C71F8 06002226 */  addiu      $v0, $s1, 0x6
  .L800C71FC:
    /* 5E9FC 800C71FC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 5EA00 800C7200 1400B18F */  lw         $s1, 0x14($sp)
    /* 5EA04 800C7204 1000B08F */  lw         $s0, 0x10($sp)
    /* 5EA08 800C7208 0800E003 */  jr         $ra
    /* 5EA0C 800C720C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_battle_printVariableWidthFontChar
