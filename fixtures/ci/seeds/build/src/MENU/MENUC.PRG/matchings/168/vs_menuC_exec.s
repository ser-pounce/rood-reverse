nonmatching vs_menuC_exec, 0x4C0

glabel vs_menuC_exec
    /* 8178 8010A978 B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 817C 8010A97C 4800B2AF */  sw         $s2, 0x48($sp)
    /* 8180 8010A980 21908000 */  addu       $s2, $a0, $zero
    /* 8184 8010A984 4C00BFAF */  sw         $ra, 0x4C($sp)
    /* 8188 8010A988 4400B1AF */  sw         $s1, 0x44($sp)
    /* 818C 8010A98C 4000B0AF */  sw         $s0, 0x40($sp)
    /* 8190 8010A990 00004392 */  lbu        $v1, 0x0($s2)
    /* 8194 8010A994 00000000 */  nop
    /* 8198 8010A998 0C00622C */  sltiu      $v0, $v1, 0xC
    /* 819C 8010A99C 1F014010 */  beqz       $v0, .L8010AE1C
    /* 81A0 8010A9A0 1080023C */   lui       $v0, %hi(jtbl_80102920)
    /* 81A4 8010A9A4 20294224 */  addiu      $v0, $v0, %lo(jtbl_80102920)
    /* 81A8 8010A9A8 80180300 */  sll        $v1, $v1, 2
    /* 81AC 8010A9AC 21186200 */  addu       $v1, $v1, $v0
    /* 81B0 8010A9B0 0000628C */  lw         $v0, 0x0($v1)
    /* 81B4 8010A9B4 00000000 */  nop
    /* 81B8 8010A9B8 08004000 */  jr         $v0
    /* 81BC 8010A9BC 00000000 */   nop
    /* 81C0 8010A9C0 1180033C */  lui        $v1, %hi(D_8010BC7F)
    /* 81C4 8010A9C4 01000224 */  addiu      $v0, $zero, 0x1
    /* 81C8 8010A9C8 7FBC62A0 */  sb         $v0, %lo(D_8010BC7F)($v1)
    /* 81CC 8010A9CC 21800000 */  addu       $s0, $zero, $zero
  .L8010A9D0:
    /* 81D0 8010A9D0 2CFA030C */  jal        vs_mainMenu_rebuildInventory
    /* 81D4 8010A9D4 21200002 */   addu      $a0, $s0, $zero
    /* 81D8 8010A9D8 01001026 */  addiu      $s0, $s0, 0x1
    /* 81DC 8010A9DC 0700022A */  slti       $v0, $s0, 0x7
    /* 81E0 8010A9E0 FBFF4014 */  bnez       $v0, .L8010A9D0
    /* 81E4 8010A9E4 FE070424 */   addiu     $a0, $zero, 0x7FE
    /* 81E8 8010A9E8 0501040C */  jal        func_80100414
    /* 81EC 8010A9EC 80000524 */   addiu     $a1, $zero, 0x80
    /* 81F0 8010A9F0 9223030C */  jal        vs_battle_getMenuItem
    /* 81F4 8010A9F4 21200000 */   addu      $a0, $zero, $zero
    /* 81F8 8010A9F8 21204000 */  addu       $a0, $v0, $zero
    /* 81FC 8010A9FC 00008390 */  lbu        $v1, 0x0($a0)
    /* 8200 8010AA00 01000224 */  addiu      $v0, $zero, 0x1
    /* 8204 8010AA04 05006214 */  bne        $v1, $v0, .L8010AA1C
    /* 8208 8010AA08 B4000224 */   addiu     $v0, $zero, 0xB4
    /* 820C 8010AA0C 14008384 */  lh         $v1, 0x14($a0)
    /* 8210 8010AA10 00000000 */  nop
    /* 8214 8010AA14 05006210 */  beq        $v1, $v0, .L8010AA2C
    /* 8218 8010AA18 02000224 */   addiu     $v0, $zero, 0x2
  .L8010AA1C:
    /* 821C 8010AA1C 21200000 */  addu       $a0, $zero, $zero
    /* 8220 8010AA20 740A040C */  jal        func_801029D0
    /* 8224 8010AA24 57000524 */   addiu     $a1, $zero, 0x57
    /* 8228 8010AA28 02000224 */  addiu      $v0, $zero, 0x2
  .L8010AA2C:
    /* 822C 8010AA2C 872B0408 */  j          .L8010AE1C
    /* 8230 8010AA30 000042A2 */   sb        $v0, 0x0($s2)
    /* 8234 8010AA34 74EA030C */  jal        vs_mainmenu_ready
    /* 8238 8010AA38 00000000 */   nop
    /* 823C 8010AA3C F7004010 */  beqz       $v0, .L8010AE1C
    /* 8240 8010AA40 21800000 */   addu      $s0, $zero, $zero
    /* 8244 8010AA44 04000824 */  addiu      $t0, $zero, 0x4
    /* 8248 8010AA48 1000A927 */  addiu      $t1, $sp, 0x10
    /* 824C 8010AA4C 21302001 */  addu       $a2, $t1, $zero
    /* 8250 8010AA50 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 8254 8010AA54 0F80033C */  lui        $v1, %hi(vs_battle_rowTypeBuf)
    /* 8258 8010AA58 A424478C */  lw         $a3, %lo(vs_mainMenu_menu12Text)($v0)
    /* 825C 8010AA5C 844E658C */  lw         $a1, %lo(vs_battle_rowTypeBuf)($v1)
    /* 8260 8010AA60 2120E000 */  addu       $a0, $a3, $zero
  .L8010AA64:
    /* 8264 8010AA64 21182801 */  addu       $v1, $t1, $t0
    /* 8268 8010AA68 08000825 */  addiu      $t0, $t0, 0x8
    /* 826C 8010AA6C 02008294 */  lhu        $v0, 0x2($a0)
    /* 8270 8010AA70 01001026 */  addiu      $s0, $s0, 0x1
    /* 8274 8010AA74 40100200 */  sll        $v0, $v0, 1
    /* 8278 8010AA78 2110E200 */  addu       $v0, $a3, $v0
    /* 827C 8010AA7C 0000C2AC */  sw         $v0, 0x0($a2)
    /* 8280 8010AA80 0800C624 */  addiu      $a2, $a2, 0x8
    /* 8284 8010AA84 04008294 */  lhu        $v0, 0x4($a0)
    /* 8288 8010AA88 04008424 */  addiu      $a0, $a0, 0x4
    /* 828C 8010AA8C 40100200 */  sll        $v0, $v0, 1
    /* 8290 8010AA90 2110E200 */  addu       $v0, $a3, $v0
    /* 8294 8010AA94 000062AC */  sw         $v0, 0x0($v1)
    /* 8298 8010AA98 0000A0AC */  sw         $zero, 0x0($a1)
    /* 829C 8010AA9C 0600022A */  slti       $v0, $s0, 0x6
    /* 82A0 8010AAA0 F0FF4014 */  bnez       $v0, .L8010AA64
    /* 82A4 8010AAA4 0400A524 */   addiu     $a1, $a1, 0x4
    /* 82A8 8010AAA8 21200000 */  addu       $a0, $zero, $zero
    /* 82AC 8010AAAC 9BFA030C */  jal        vs_mainMenu_getItemCount
    /* 82B0 8010AAB0 21288000 */   addu      $a1, $a0, $zero
    /* 82B4 8010AAB4 21804000 */  addu       $s0, $v0, $zero
    /* 82B8 8010AAB8 08000224 */  addiu      $v0, $zero, 0x8
    /* 82BC 8010AABC 09000216 */  bne        $s0, $v0, .L8010AAE4
    /* 82C0 8010AAC0 1080023C */   lui       $v0, %hi(vs_mainMenu_menu12Text)
    /* 82C4 8010AAC4 A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 82C8 8010AAC8 00000000 */  nop
    /* 82CC 8010AACC 90064224 */  addiu      $v0, $v0, 0x690
    /* 82D0 8010AAD0 1400A2AF */  sw         $v0, 0x14($sp)
    /* 82D4 8010AAD4 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 82D8 8010AAD8 844E438C */  lw         $v1, %lo(vs_battle_rowTypeBuf)($v0)
    /* 82DC 8010AADC 01000224 */  addiu      $v0, $zero, 0x1
    /* 82E0 8010AAE0 000062AC */  sw         $v0, 0x0($v1)
  .L8010AAE4:
    /* 82E4 8010AAE4 09000016 */  bnez       $s0, .L8010AB0C
    /* 82E8 8010AAE8 1080023C */   lui       $v0, %hi(vs_mainMenu_menu12Text)
    /* 82EC 8010AAEC A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 82F0 8010AAF0 00000000 */  nop
    /* 82F4 8010AAF4 B4064224 */  addiu      $v0, $v0, 0x6B4
    /* 82F8 8010AAF8 2C00A2AF */  sw         $v0, 0x2C($sp)
    /* 82FC 8010AAFC 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 8300 8010AB00 844E438C */  lw         $v1, %lo(vs_battle_rowTypeBuf)($v0)
    /* 8304 8010AB04 01000224 */  addiu      $v0, $zero, 0x1
    /* 8308 8010AB08 0C0062AC */  sw         $v0, 0xC($v1)
  .L8010AB0C:
    /* 830C 8010AB0C F434020C */  jal        vs_battle_inWorkshop
    /* 8310 8010AB10 00000000 */   nop
    /* 8314 8010AB14 1180033C */  lui        $v1, %hi(_inWorkshop)
    /* 8318 8010AB18 80BC62A0 */  sb         $v0, %lo(_inWorkshop)($v1)
    /* 831C 8010AB1C FF004230 */  andi       $v0, $v0, 0xFF
    /* 8320 8010AB20 17004014 */  bnez       $v0, .L8010AB80
    /* 8324 8010AB24 0680023C */   lui       $v0, %hi(vs_main_settings)
    /* 8328 8010AB28 03001024 */  addiu      $s0, $zero, 0x3
    /* 832C 8010AB2C 06000824 */  addiu      $t0, $zero, 0x6
    /* 8330 8010AB30 1000A627 */  addiu      $a2, $sp, 0x10
    /* 8334 8010AB34 01000724 */  addiu      $a3, $zero, 0x1
    /* 8338 8010AB38 1C000424 */  addiu      $a0, $zero, 0x1C
    /* 833C 8010AB3C 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 8340 8010AB40 0F80033C */  lui        $v1, %hi(vs_battle_rowTypeBuf)
    /* 8344 8010AB44 A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 8348 8010AB48 844E658C */  lw         $a1, %lo(vs_battle_rowTypeBuf)($v1)
    /* 834C 8010AB4C 62064324 */  addiu      $v1, $v0, 0x662
  .L8010AB50:
    /* 8350 8010AB50 01001026 */  addiu      $s0, $s0, 0x1
    /* 8354 8010AB54 03000816 */  bne        $s0, $t0, .L8010AB64
    /* 8358 8010AB58 08008424 */   addiu     $a0, $a0, 0x8
    /* 835C 8010AB5C 04000424 */  addiu      $a0, $zero, 0x4
    /* 8360 8010AB60 21800000 */  addu       $s0, $zero, $zero
  .L8010AB64:
    /* 8364 8010AB64 2110C400 */  addu       $v0, $a2, $a0
    /* 8368 8010AB68 000043AC */  sw         $v1, 0x0($v0)
    /* 836C 8010AB6C 80101000 */  sll        $v0, $s0, 2
    /* 8370 8010AB70 21104500 */  addu       $v0, $v0, $a1
    /* 8374 8010AB74 F6FF0016 */  bnez       $s0, .L8010AB50
    /* 8378 8010AB78 000047AC */   sw        $a3, 0x0($v0)
    /* 837C 8010AB7C 0680023C */  lui        $v0, %hi(vs_main_settings)
  .L8010AB80:
    /* 8380 8010AB80 20005124 */  addiu      $s1, $v0, %lo(vs_main_settings)
    /* 8384 8010AB84 1180033C */  lui        $v1, %hi(D_8010BC7F)
    /* 8388 8010AB88 7FBC6290 */  lbu        $v0, %lo(D_8010BC7F)($v1)
    /* 838C 8010AB8C 01003092 */  lbu        $s0, 0x1($s1)
    /* 8390 8010AB90 03004014 */  bnez       $v0, .L8010ABA0
    /* 8394 8010AB94 06000424 */   addiu     $a0, $zero, 0x6
    /* 8398 8010AB98 01000224 */  addiu      $v0, $zero, 0x1
    /* 839C 8010AB9C 010022A2 */  sb         $v0, 0x1($s1)
  .L8010ABA0:
    /* 83A0 8010ABA0 35010524 */  addiu      $a1, $zero, 0x135
    /* 83A4 8010ABA4 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 83A8 8010ABA8 844E478C */  lw         $a3, %lo(vs_battle_rowTypeBuf)($v0)
    /* 83AC 8010ABAC 1000A627 */  addiu      $a2, $sp, 0x10
    /* 83B0 8010ABB0 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 83B4 8010ABB4 7FBC60A0 */   sb        $zero, %lo(D_8010BC7F)($v1)
    /* 83B8 8010ABB8 03000224 */  addiu      $v0, $zero, 0x3
    /* 83BC 8010ABBC 010030A2 */  sb         $s0, 0x1($s1)
    /* 83C0 8010ABC0 872B0408 */  j          .L8010AE1C
    /* 83C4 8010ABC4 000042A2 */   sb        $v0, 0x0($s2)
    /* 83C8 8010ABC8 2C02040C */  jal        func_801008B0
    /* 83CC 8010ABCC 00000000 */   nop
    /* 83D0 8010ABD0 1080033C */  lui        $v1, %hi(D_801023D0)
    /* 83D4 8010ABD4 D0236590 */  lbu        $a1, %lo(D_801023D0)($v1)
    /* 83D8 8010ABD8 79FE030C */  jal        vs_mainMenu_printInformation
    /* 83DC 8010ABDC 21204000 */   addu      $a0, $v0, $zero
    /* 83E0 8010ABE0 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 83E4 8010ABE4 00000000 */   nop
    /* 83E8 8010ABE8 21184000 */  addu       $v1, $v0, $zero
    /* 83EC 8010ABEC 01007024 */  addiu      $s0, $v1, 0x1
    /* 83F0 8010ABF0 8A000012 */  beqz       $s0, .L8010AE1C
    /* 83F4 8010ABF4 00000000 */   nop
    /* 83F8 8010ABF8 0E000106 */  bgez       $s0, .L8010AC34
    /* 83FC 8010ABFC 0600622C */   sltiu     $v0, $v1, 0x6
    /* 8400 8010AC00 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 8404 8010AC04 28000424 */   addiu     $a0, $zero, 0x28
    /* 8408 8010AC08 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 840C 8010AC0C 04000216 */  bne        $s0, $v0, .L8010AC20
    /* 8410 8010AC10 0F80043C */   lui       $a0, %hi(vs_battle_menuState)
    /* 8414 8010AC14 0F80023C */  lui        $v0, %hi(D_800F514C)
    /* 8418 8010AC18 6E2B0408 */  j          .L8010ADB8
    /* 841C 8010AC1C 4C5140A4 */   sh        $zero, %lo(D_800F514C)($v0)
  .L8010AC20:
    /* 8420 8010AC20 C0518224 */  addiu      $v0, $a0, %lo(vs_battle_menuState)
    /* 8424 8010AC24 01004390 */  lbu        $v1, 0x1($v0)
    /* 8428 8010AC28 010040A0 */  sb         $zero, 0x1($v0)
    /* 842C 8010AC2C 812B0408 */  j          .L8010AE04
    /* 8430 8010AC30 C05183A0 */   sb        $v1, %lo(vs_battle_menuState)($a0)
  .L8010AC34:
    /* 8434 8010AC34 79004010 */  beqz       $v0, .L8010AE1C
    /* 8438 8010AC38 1080023C */   lui       $v0, %hi(jtbl_80102950)
    /* 843C 8010AC3C 50294224 */  addiu      $v0, $v0, %lo(jtbl_80102950)
    /* 8440 8010AC40 80180300 */  sll        $v1, $v1, 2
    /* 8444 8010AC44 21186200 */  addu       $v1, $v1, $v0
    /* 8448 8010AC48 0000628C */  lw         $v0, 0x0($v1)
    /* 844C 8010AC4C 00000000 */  nop
    /* 8450 8010AC50 08004000 */  jr         $v0
    /* 8454 8010AC54 00000000 */   nop
    /* 8458 8010AC58 2612040C */  jal        func_80104898
    /* 845C 8010AC5C 01000424 */   addiu     $a0, $zero, 0x1
    /* 8460 8010AC60 04000224 */  addiu      $v0, $zero, 0x4
    /* 8464 8010AC64 872B0408 */  j          .L8010AE1C
    /* 8468 8010AC68 000042A2 */   sb        $v0, 0x0($s2)
    /* 846C 8010AC6C F918040C */  jal        func_801063E4
    /* 8470 8010AC70 01000424 */   addiu     $a0, $zero, 0x1
    /* 8474 8010AC74 05000224 */  addiu      $v0, $zero, 0x5
    /* 8478 8010AC78 872B0408 */  j          .L8010AE1C
    /* 847C 8010AC7C 000042A2 */   sb        $v0, 0x0($s2)
    /* 8480 8010AC80 191B040C */  jal        func_80106C64
    /* 8484 8010AC84 01000424 */   addiu     $a0, $zero, 0x1
    /* 8488 8010AC88 06000224 */  addiu      $v0, $zero, 0x6
    /* 848C 8010AC8C 872B0408 */  j          .L8010AE1C
    /* 8490 8010AC90 000042A2 */   sb        $v0, 0x0($s2)
    /* 8494 8010AC94 B31B040C */  jal        func_80106ECC
    /* 8498 8010AC98 01000424 */   addiu     $a0, $zero, 0x1
    /* 849C 8010AC9C 07000224 */  addiu      $v0, $zero, 0x7
    /* 84A0 8010ACA0 872B0408 */  j          .L8010AE1C
    /* 84A4 8010ACA4 000042A2 */   sb        $v0, 0x0($s2)
    /* 84A8 8010ACA8 BF1C040C */  jal        func_801072FC
    /* 84AC 8010ACAC 01000424 */   addiu     $a0, $zero, 0x1
    /* 84B0 8010ACB0 08000224 */  addiu      $v0, $zero, 0x8
    /* 84B4 8010ACB4 872B0408 */  j          .L8010AE1C
    /* 84B8 8010ACB8 000042A2 */   sb        $v0, 0x0($s2)
    /* 84BC 8010ACBC AF29040C */  jal        func_8010A6BC
    /* 84C0 8010ACC0 01000424 */   addiu     $a0, $zero, 0x1
    /* 84C4 8010ACC4 09000224 */  addiu      $v0, $zero, 0x9
    /* 84C8 8010ACC8 872B0408 */  j          .L8010AE1C
    /* 84CC 8010ACCC 000042A2 */   sb        $v0, 0x0($s2)
    /* 84D0 8010ACD0 2612040C */  jal        func_80104898
    /* 84D4 8010ACD4 21200000 */   addu      $a0, $zero, $zero
    /* 84D8 8010ACD8 21804000 */  addu       $s0, $v0, $zero
    /* 84DC 8010ACDC 4F000012 */  beqz       $s0, .L8010AE1C
    /* 84E0 8010ACE0 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 84E4 8010ACE4 34000212 */  beq        $s0, $v0, .L8010ADB8
    /* 84E8 8010ACE8 0A000224 */   addiu     $v0, $zero, 0xA
    /* 84EC 8010ACEC 000042A2 */  sb         $v0, 0x0($s2)
    /* 84F0 8010ACF0 01000224 */  addiu      $v0, $zero, 0x1
    /* 84F4 8010ACF4 06000216 */  bne        $s0, $v0, .L8010AD10
    /* 84F8 8010ACF8 0F80033C */   lui       $v1, %hi(vs_battle_menuState)
    /* 84FC 8010ACFC 08000224 */  addiu      $v0, $zero, 0x8
    /* 8500 8010AD00 EAFE030C */  jal        func_800FFBA8
    /* 8504 8010AD04 C05162A0 */   sb        $v0, %lo(vs_battle_menuState)($v1)
    /* 8508 8010AD08 872B0408 */  j          .L8010AE1C
    /* 850C 8010AD0C 00000000 */   nop
  .L8010AD10:
    /* 8510 8010AD10 F2FE030C */  jal        func_800FFBC8
    /* 8514 8010AD14 00000000 */   nop
    /* 8518 8010AD18 872B0408 */  j          .L8010AE1C
    /* 851C 8010AD1C 00000000 */   nop
    /* 8520 8010AD20 F918040C */  jal        func_801063E4
    /* 8524 8010AD24 21200000 */   addu      $a0, $zero, $zero
    /* 8528 8010AD28 21804000 */  addu       $s0, $v0, $zero
  .L8010AD2C:
    /* 852C 8010AD2C 3B000012 */  beqz       $s0, .L8010AE1C
    /* 8530 8010AD30 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 8534 8010AD34 20000212 */  beq        $s0, $v0, .L8010ADB8
    /* 8538 8010AD38 0A000224 */   addiu     $v0, $zero, 0xA
    /* 853C 8010AD3C 872B0408 */  j          .L8010AE1C
    /* 8540 8010AD40 000042A2 */   sb        $v0, 0x0($s2)
    /* 8544 8010AD44 191B040C */  jal        func_80106C64
    /* 8548 8010AD48 21200000 */   addu      $a0, $zero, $zero
    /* 854C 8010AD4C 4B2B0408 */  j          .L8010AD2C
    /* 8550 8010AD50 21804000 */   addu      $s0, $v0, $zero
    /* 8554 8010AD54 B31B040C */  jal        func_80106ECC
    /* 8558 8010AD58 21200000 */   addu      $a0, $zero, $zero
    /* 855C 8010AD5C 21804000 */  addu       $s0, $v0, $zero
    /* 8560 8010AD60 2E000012 */  beqz       $s0, .L8010AE1C
    /* 8564 8010AD64 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 8568 8010AD68 13000212 */  beq        $s0, $v0, .L8010ADB8
    /* 856C 8010AD6C 0A000224 */   addiu     $v0, $zero, 0xA
    /* 8570 8010AD70 000042A2 */  sb         $v0, 0x0($s2)
    /* 8574 8010AD74 01000224 */  addiu      $v0, $zero, 0x1
    /* 8578 8010AD78 28000216 */  bne        $s0, $v0, .L8010AE1C
    /* 857C 8010AD7C 0F80033C */   lui       $v1, %hi(vs_battle_menuState)
    /* 8580 8010AD80 08000224 */  addiu      $v0, $zero, 0x8
    /* 8584 8010AD84 872B0408 */  j          .L8010AE1C
    /* 8588 8010AD88 C05162A0 */   sb        $v0, %lo(vs_battle_menuState)($v1)
    /* 858C 8010AD8C BF1C040C */  jal        func_801072FC
    /* 8590 8010AD90 21200000 */   addu      $a0, $zero, $zero
    /* 8594 8010AD94 4B2B0408 */  j          .L8010AD2C
    /* 8598 8010AD98 21804000 */   addu      $s0, $v0, $zero
    /* 859C 8010AD9C AF29040C */  jal        func_8010A6BC
    /* 85A0 8010ADA0 21200000 */   addu      $a0, $zero, $zero
    /* 85A4 8010ADA4 21804000 */  addu       $s0, $v0, $zero
    /* 85A8 8010ADA8 1C000012 */  beqz       $s0, .L8010AE1C
    /* 85AC 8010ADAC FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 85B0 8010ADB0 04000216 */  bne        $s0, $v0, .L8010ADC4
    /* 85B4 8010ADB4 0A000224 */   addiu     $v0, $zero, 0xA
  .L8010ADB8:
    /* 85B8 8010ADB8 0B000224 */  addiu      $v0, $zero, 0xB
    /* 85BC 8010ADBC 872B0408 */  j          .L8010AE1C
    /* 85C0 8010ADC0 000042A2 */   sb        $v0, 0x0($s2)
  .L8010ADC4:
    /* 85C4 8010ADC4 872B0408 */  j          .L8010AE1C
    /* 85C8 8010ADC8 000042A2 */   sb        $v0, 0x0($s2)
    /* 85CC 8010ADCC F2FE030C */  jal        func_800FFBC8
    /* 85D0 8010ADD0 00000000 */   nop
    /* 85D4 8010ADD4 74EA030C */  jal        vs_mainmenu_ready
    /* 85D8 8010ADD8 00000000 */   nop
    /* 85DC 8010ADDC 0F004010 */  beqz       $v0, .L8010AE1C
    /* 85E0 8010ADE0 01000224 */   addiu     $v0, $zero, 0x1
    /* 85E4 8010ADE4 872B0408 */  j          .L8010AE1C
    /* 85E8 8010ADE8 000042A2 */   sb        $v0, 0x0($s2)
    /* 85EC 8010ADEC 0F80053C */  lui        $a1, %hi(vs_battle_menuState)
    /* 85F0 8010ADF0 C051A324 */  addiu      $v1, $a1, %lo(vs_battle_menuState)
    /* 85F4 8010ADF4 01006490 */  lbu        $a0, 0x1($v1)
    /* 85F8 8010ADF8 01000224 */  addiu      $v0, $zero, 0x1
    /* 85FC 8010ADFC 010062A0 */  sb         $v0, 0x1($v1)
    /* 8600 8010AE00 C051A4A0 */  sb         $a0, %lo(vs_battle_menuState)($a1)
  .L8010AE04:
    /* 8604 8010AE04 0F80043C */  lui        $a0, %hi(D_800F4EA0)
    /* 8608 8010AE08 A04E828C */  lw         $v0, %lo(D_800F4EA0)($a0)
    /* 860C 8010AE0C FFFD0324 */  addiu      $v1, $zero, -0x201
    /* 8610 8010AE10 24104300 */  and        $v0, $v0, $v1
    /* 8614 8010AE14 A04E82AC */  sw         $v0, %lo(D_800F4EA0)($a0)
    /* 8618 8010AE18 000040A2 */  sb         $zero, 0x0($s2)
  .L8010AE1C:
    /* 861C 8010AE1C 4C00BF8F */  lw         $ra, 0x4C($sp)
    /* 8620 8010AE20 4800B28F */  lw         $s2, 0x48($sp)
    /* 8624 8010AE24 4400B18F */  lw         $s1, 0x44($sp)
    /* 8628 8010AE28 4000B08F */  lw         $s0, 0x40($sp)
    /* 862C 8010AE2C 21100000 */  addu       $v0, $zero, $zero
    /* 8630 8010AE30 0800E003 */  jr         $ra
    /* 8634 8010AE34 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel vs_menuC_exec
