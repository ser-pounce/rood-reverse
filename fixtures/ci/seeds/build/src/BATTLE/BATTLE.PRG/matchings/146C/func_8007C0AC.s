nonmatching func_8007C0AC, 0x12C

glabel func_8007C0AC
    /* 138AC 8007C0AC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 138B0 8007C0B0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 138B4 8007C0B4 21808000 */  addu       $s0, $a0, $zero
    /* 138B8 8007C0B8 2138A000 */  addu       $a3, $a1, $zero
    /* 138BC 8007C0BC 02000224 */  addiu      $v0, $zero, 0x2
    /* 138C0 8007C0C0 1800E214 */  bne        $a3, $v0, .L8007C124
    /* 138C4 8007C0C4 1400BFAF */   sw        $ra, 0x14($sp)
    /* 138C8 8007C0C8 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 138CC 8007C0CC 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* 138D0 8007C0D0 80181000 */  sll        $v1, $s0, 2
    /* 138D4 8007C0D4 21186200 */  addu       $v1, $v1, $v0
    /* 138D8 8007C0D8 0000648C */  lw         $a0, 0x0($v1)
    /* 138DC 8007C0DC 00000000 */  nop
    /* 138E0 8007C0E0 2000828C */  lw         $v0, 0x20($a0)
    /* 138E4 8007C0E4 00000000 */  nop
    /* 138E8 8007C0E8 01004238 */  xori       $v0, $v0, 0x1
    /* 138EC 8007C0EC 200082AC */  sw         $v0, 0x20($a0)
    /* 138F0 8007C0F0 0000628C */  lw         $v0, 0x0($v1)
    /* 138F4 8007C0F4 00000000 */  nop
    /* 138F8 8007C0F8 2000428C */  lw         $v0, 0x20($v0)
    /* 138FC 8007C0FC 00000000 */  nop
    /* 13900 8007C100 01004230 */  andi       $v0, $v0, 0x1
    /* 13904 8007C104 04004010 */  beqz       $v0, .L8007C118
    /* 13908 8007C108 21200002 */   addu      $a0, $s0, $zero
    /* 1390C 8007C10C 01000524 */  addiu      $a1, $zero, 0x1
    /* 13910 8007C110 69F00108 */  j          .L8007C1A4
    /* 13914 8007C114 21300000 */   addu      $a2, $zero, $zero
  .L8007C118:
    /* 13918 8007C118 21280000 */  addu       $a1, $zero, $zero
    /* 1391C 8007C11C 69F00108 */  j          .L8007C1A4
    /* 13920 8007C120 2130A000 */   addu      $a2, $a1, $zero
  .L8007C124:
    /* 13924 8007C124 12000012 */  beqz       $s0, .L8007C170
    /* 13928 8007C128 0F80033C */   lui       $v1, %hi(vs_battle_actors)
    /* 1392C 8007C12C 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 13930 8007C130 80101000 */  sll        $v0, $s0, 2
    /* 13934 8007C134 21104300 */  addu       $v0, $v0, $v1
    /* 13938 8007C138 0000438C */  lw         $v1, 0x0($v0)
    /* 1393C 8007C13C 00000000 */  nop
    /* 13940 8007C140 1C006494 */  lhu        $a0, 0x1C($v1)
    /* 13944 8007C144 04000524 */  addiu      $a1, $zero, 0x4
    /* 13948 8007C148 03008510 */  beq        $a0, $a1, .L8007C158
    /* 1394C 8007C14C 08000224 */   addiu     $v0, $zero, 0x8
    /* 13950 8007C150 16008214 */  bne        $a0, $v0, .L8007C1AC
    /* 13954 8007C154 00000000 */   nop
  .L8007C158:
    /* 13958 8007C158 0300E010 */  beqz       $a3, .L8007C168
    /* 1395C 8007C15C 08000224 */   addiu     $v0, $zero, 0x8
    /* 13960 8007C160 6BF00108 */  j          .L8007C1AC
    /* 13964 8007C164 1C0065A4 */   sh        $a1, 0x1C($v1)
  .L8007C168:
    /* 13968 8007C168 6BF00108 */  j          .L8007C1AC
    /* 1396C 8007C16C 1C0062A4 */   sh        $v0, 0x1C($v1)
  .L8007C170:
    /* 13970 8007C170 0F80063C */  lui        $a2, %hi(vs_battle_actors)
    /* 13974 8007C174 2819C58C */  lw         $a1, %lo(vs_battle_actors)($a2)
    /* 13978 8007C178 21200000 */  addu       $a0, $zero, $zero
    /* 1397C 8007C17C 2000A28C */  lw         $v0, 0x20($a1)
    /* 13980 8007C180 FEFF0324 */  addiu      $v1, $zero, -0x2
    /* 13984 8007C184 24104300 */  and        $v0, $v0, $v1
    /* 13988 8007C188 2000A2AC */  sw         $v0, 0x20($a1)
    /* 1398C 8007C18C 2819C38C */  lw         $v1, %lo(vs_battle_actors)($a2)
    /* 13990 8007C190 2128E000 */  addu       $a1, $a3, $zero
    /* 13994 8007C194 2000628C */  lw         $v0, 0x20($v1)
    /* 13998 8007C198 01000624 */  addiu      $a2, $zero, 0x1
    /* 1399C 8007C19C 25104500 */  or         $v0, $v0, $a1
    /* 139A0 8007C1A0 200062AC */  sw         $v0, 0x20($v1)
  .L8007C1A4:
    /* 139A4 8007C1A4 4D76020C */  jal        func_8009D934
    /* 139A8 8007C1A8 00000000 */   nop
  .L8007C1AC:
    /* 139AC 8007C1AC 06000016 */  bnez       $s0, .L8007C1C8
    /* 139B0 8007C1B0 0F80023C */   lui       $v0, %hi(vs_battle_characterState)
    /* 139B4 8007C1B4 FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 139B8 8007C1B8 00000000 */  nop
    /* 139BC 8007C1BC 2000448C */  lw         $a0, 0x20($v0)
    /* 139C0 8007C1C0 982D030C */  jal        func_800CB660
    /* 139C4 8007C1C4 01008430 */   andi      $a0, $a0, 0x1
  .L8007C1C8:
    /* 139C8 8007C1C8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 139CC 8007C1CC 1000B08F */  lw         $s0, 0x10($sp)
    /* 139D0 8007C1D0 0800E003 */  jr         $ra
    /* 139D4 8007C1D4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007C0AC
