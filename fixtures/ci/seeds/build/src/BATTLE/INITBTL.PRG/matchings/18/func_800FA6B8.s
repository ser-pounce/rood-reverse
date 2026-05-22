nonmatching func_800FA6B8, 0xF8

glabel func_800FA6B8
    /* EB8 800FA6B8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* EBC 800FA6BC 1000B0AF */  sw         $s0, 0x10($sp)
    /* EC0 800FA6C0 0F80103C */  lui        $s0, %hi(D_800F1CE0)
    /* EC4 800FA6C4 E01C1026 */  addiu      $s0, $s0, %lo(D_800F1CE0)
    /* EC8 800FA6C8 21200002 */  addu       $a0, $s0, $zero
    /* ECC 800FA6CC 1400BFAF */  sw         $ra, 0x14($sp)
    /* ED0 800FA6D0 4424010C */  jal        vs_main_bzero
    /* ED4 800FA6D4 20000524 */   addiu     $a1, $zero, 0x20
    /* ED8 800FA6D8 0F80043C */  lui        $a0, %hi(vs_battle_roomData)
    /* EDC 800FA6DC F81B8424 */  addiu      $a0, $a0, %lo(vs_battle_roomData)
    /* EE0 800FA6E0 4424010C */  jal        vs_main_bzero
    /* EE4 800FA6E4 C4000524 */   addiu     $a1, $zero, 0xC4
    /* EE8 800FA6E8 0F80043C */  lui        $a0, %hi(D_800F1CC8)
    /* EEC 800FA6EC C81C8424 */  addiu      $a0, $a0, %lo(D_800F1CC8)
    /* EF0 800FA6F0 4424010C */  jal        vs_main_bzero
    /* EF4 800FA6F4 0C000524 */   addiu     $a1, $zero, 0xC
    /* EF8 800FA6F8 0F80043C */  lui        $a0, %hi(vs_battle_menu9CursorMemory)
    /* EFC 800FA6FC F01B8424 */  addiu      $a0, $a0, %lo(vs_battle_menu9CursorMemory)
    /* F00 800FA700 4424010C */  jal        vs_main_bzero
    /* F04 800FA704 08000524 */   addiu     $a1, $zero, 0x8
    /* F08 800FA708 0F80043C */  lui        $a0, %hi(vs_battle_manualDisplayState)
    /* F0C 800FA70C C81B8424 */  addiu      $a0, $a0, %lo(vs_battle_manualDisplayState)
    /* F10 800FA710 4424010C */  jal        vs_main_bzero
    /* F14 800FA714 24000524 */   addiu     $a1, $zero, 0x24
    /* F18 800FA718 B10F010C */  jal        vs_main_allocHeap
    /* F1C 800FA71C 00080424 */   addiu     $a0, $zero, 0x800
    /* F20 800FA720 00030424 */  addiu      $a0, $zero, 0x300
    /* F24 800FA724 0F80033C */  lui        $v1, %hi(D_800F1BA8)
    /* F28 800FA728 B10F010C */  jal        vs_main_allocHeap
    /* F2C 800FA72C A81B62AC */   sw        $v0, %lo(D_800F1BA8)($v1)
    /* F30 800FA730 80000424 */  addiu      $a0, $zero, 0x80
    /* F34 800FA734 0F80033C */  lui        $v1, %hi(D_800F1BAC)
    /* F38 800FA738 B10F010C */  jal        vs_main_allocHeap
    /* F3C 800FA73C AC1B62AC */   sw        $v0, %lo(D_800F1BAC)($v1)
    /* F40 800FA740 0F80033C */  lui        $v1, %hi(D_800F1CBC)
    /* F44 800FA744 BC1C62AC */  sw         $v0, %lo(D_800F1CBC)($v1)
    /* F48 800FA748 0F80033C */  lui        $v1, %hi(vs_battle_doorEntered)
    /* F4C 800FA74C FFFF0224 */  addiu      $v0, $zero, -0x1
    /* F50 800FA750 BE1B62A4 */  sh         $v0, %lo(vs_battle_doorEntered)($v1)
    /* F54 800FA754 0F80023C */  lui        $v0, %hi(D_800F1BA4)
    /* F58 800FA758 A41B40A4 */  sh         $zero, %lo(D_800F1BA4)($v0)
    /* F5C 800FA75C 0F80023C */  lui        $v0, %hi(D_800F1BB6)
    /* F60 800FA760 B61B40A4 */  sh         $zero, %lo(D_800F1BB6)($v0)
    /* F64 800FA764 0F80023C */  lui        $v0, %hi(_submenuState)
    /* F68 800FA768 D81C40AC */  sw         $zero, %lo(_submenuState)($v0)
    /* F6C 800FA76C 0F80023C */  lui        $v0, %hi(vs_battle_sceneBuffer)
    /* F70 800FA770 0F80033C */  lui        $v1, %hi(D_800F1CD6)
    /* F74 800FA774 C01B40AC */  sw         $zero, %lo(vs_battle_sceneBuffer)($v0)
    /* F78 800FA778 01000224 */  addiu      $v0, $zero, 0x1
    /* F7C 800FA77C D61C62A0 */  sb         $v0, %lo(D_800F1CD6)($v1)
    /* F80 800FA780 0F80033C */  lui        $v1, %hi(D_800F1CD4)
    /* F84 800FA784 08000224 */  addiu      $v0, $zero, 0x8
    /* F88 800FA788 233A020C */  jal        func_8008E88C
    /* F8C 800FA78C D41C62A4 */   sh        $v0, %lo(D_800F1CD4)($v1)
    /* F90 800FA790 AD2D020C */  jal        func_8008B6B4
    /* F94 800FA794 00000000 */   nop
    /* F98 800FA798 CC3A020C */  jal        func_8008EB30
    /* F9C 800FA79C 21200002 */   addu      $a0, $s0, $zero
    /* FA0 800FA7A0 1400BF8F */  lw         $ra, 0x14($sp)
    /* FA4 800FA7A4 1000B08F */  lw         $s0, 0x10($sp)
    /* FA8 800FA7A8 0800E003 */  jr         $ra
    /* FAC 800FA7AC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800FA6B8
