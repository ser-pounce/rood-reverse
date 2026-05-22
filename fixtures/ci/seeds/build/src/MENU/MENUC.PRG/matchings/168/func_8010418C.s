nonmatching func_8010418C, 0x3A8

glabel func_8010418C
    /* 198C 8010418C C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 1990 80104190 21288000 */  addu       $a1, $a0, $zero
    /* 1994 80104194 2000B2AF */  sw         $s2, 0x20($sp)
    /* 1998 80104198 21900000 */  addu       $s2, $zero, $zero
    /* 199C 8010419C 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 19A0 801041A0 3800BEAF */  sw         $fp, 0x38($sp)
    /* 19A4 801041A4 3400B7AF */  sw         $s7, 0x34($sp)
    /* 19A8 801041A8 3000B6AF */  sw         $s6, 0x30($sp)
    /* 19AC 801041AC 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 19B0 801041B0 2800B4AF */  sw         $s4, 0x28($sp)
    /* 19B4 801041B4 2400B3AF */  sw         $s3, 0x24($sp)
    /* 19B8 801041B8 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 19BC 801041BC 1800B0AF */  sw         $s0, 0x18($sp)
    /* 19C0 801041C0 0D00A010 */  beqz       $a1, .L801041F8
    /* 19C4 801041C4 1000A0AF */   sw        $zero, 0x10($sp)
    /* 19C8 801041C8 0C000424 */  addiu      $a0, $zero, 0xC
    /* 19CC 801041CC 1180033C */  lui        $v1, %hi(D_8010BC0A)
    /* 19D0 801041D0 7F00A230 */  andi       $v0, $a1, 0x7F
    /* 19D4 801041D4 0ABC62A0 */  sb         $v0, %lo(D_8010BC0A)($v1)
    /* 19D8 801041D8 1180033C */  lui        $v1, %hi(D_8010BC09)
    /* 19DC 801041DC 03120500 */  sra        $v0, $a1, 8
    /* 19E0 801041E0 630F040C */  jal        func_80103D8C
    /* 19E4 801041E4 09BC62A0 */   sb        $v0, %lo(D_8010BC09)($v1)
    /* 19E8 801041E8 21104002 */  addu       $v0, $s2, $zero
    /* 19EC 801041EC 1180033C */  lui        $v1, %hi(D_8010BC08)
    /* 19F0 801041F0 41110408 */  j          .L80104504
    /* 19F4 801041F4 08BC60A0 */   sb        $zero, %lo(D_8010BC08)($v1)
  .L801041F8:
    /* 19F8 801041F8 1180033C */  lui        $v1, %hi(D_8010BC09)
    /* 19FC 801041FC 09BC6290 */  lbu        $v0, %lo(D_8010BC09)($v1)
    /* 1A00 80104200 00000000 */  nop
    /* 1A04 80104204 09004010 */  beqz       $v0, .L8010422C
    /* 1A08 80104208 40180200 */   sll       $v1, $v0, 1
    /* 1A0C 8010420C 21186200 */  addu       $v1, $v1, $v0
    /* 1A10 80104210 80180300 */  sll        $v1, $v1, 2
    /* 1A14 80104214 23186200 */  subu       $v1, $v1, $v0
    /* 1A18 80104218 80180300 */  sll        $v1, $v1, 2
    /* 1A1C 8010421C 0680023C */  lui        $v0, %hi(D_800603BC)
    /* 1A20 80104220 BC034224 */  addiu      $v0, $v0, %lo(D_800603BC)
    /* 1A24 80104224 21186200 */  addu       $v1, $v1, $v0
    /* 1A28 80104228 1000A3AF */  sw         $v1, 0x10($sp)
  .L8010422C:
    /* 1A2C 8010422C 1180033C */  lui        $v1, %hi(D_8010BC0A)
    /* 1A30 80104230 0ABC6290 */  lbu        $v0, %lo(D_8010BC0A)($v1)
    /* 1A34 80104234 00000000 */  nop
    /* 1A38 80104238 05004010 */  beqz       $v0, .L80104250
    /* 1A3C 8010423C 21184000 */   addu      $v1, $v0, $zero
    /* 1A40 80104240 00190300 */  sll        $v1, $v1, 4
    /* 1A44 80104244 0680023C */  lui        $v0, %hi(D_80060698)
    /* 1A48 80104248 98064224 */  addiu      $v0, $v0, %lo(D_80060698)
    /* 1A4C 8010424C 21906200 */  addu       $s2, $v1, $v0
  .L80104250:
    /* 1A50 80104250 1180023C */  lui        $v0, %hi(D_8010BC08)
    /* 1A54 80104254 08BC4390 */  lbu        $v1, %lo(D_8010BC08)($v0)
    /* 1A58 80104258 01001024 */  addiu      $s0, $zero, 0x1
    /* 1A5C 8010425C 6C007010 */  beq        $v1, $s0, .L80104410
    /* 1A60 80104260 02006228 */   slti      $v0, $v1, 0x2
    /* 1A64 80104264 05004010 */  beqz       $v0, .L8010427C
    /* 1A68 80104268 02000224 */   addiu     $v0, $zero, 0x2
    /* 1A6C 8010426C 07006010 */  beqz       $v1, .L8010428C
    /* 1A70 80104270 21100000 */   addu      $v0, $zero, $zero
    /* 1A74 80104274 41110408 */  j          .L80104504
    /* 1A78 80104278 00000000 */   nop
  .L8010427C:
    /* 1A7C 8010427C 99006210 */  beq        $v1, $v0, .L801044E4
    /* 1A80 80104280 21100000 */   addu      $v0, $zero, $zero
    /* 1A84 80104284 41110408 */  j          .L80104504
    /* 1A88 80104288 00000000 */   nop
  .L8010428C:
    /* 1A8C 8010428C 74EA030C */  jal        vs_mainmenu_ready
    /* 1A90 80104290 00000000 */   nop
    /* 1A94 80104294 9B004010 */  beqz       $v0, .L80104504
    /* 1A98 80104298 21100000 */   addu      $v0, $zero, $zero
    /* 1A9C 8010429C 8F0F010C */  jal        vs_main_allocHeapR
    /* 1AA0 801042A0 2C070424 */   addiu     $a0, $zero, 0x72C
    /* 1AA4 801042A4 21B84000 */  addu       $s7, $v0, $zero
    /* 1AA8 801042A8 0C004016 */  bnez       $s2, .L801042DC
    /* 1AAC 801042AC A406FE26 */   addiu     $fp, $s7, 0x6A4
    /* 1AB0 801042B0 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 1AB4 801042B4 A424438C */  lw         $v1, %lo(vs_mainMenu_menu12Text)($v0)
    /* 1AB8 801042B8 00000000 */  nop
    /* 1ABC 801042BC 2C086224 */  addiu      $v0, $v1, 0x82C
    /* 1AC0 801042C0 A406E2AE */  sw         $v0, 0x6A4($s7)
    /* 1AC4 801042C4 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 1AC8 801042C8 844E428C */  lw         $v0, %lo(vs_battle_rowTypeBuf)($v0)
    /* 1ACC 801042CC 32086324 */  addiu      $v1, $v1, 0x832
    /* 1AD0 801042D0 0400C3AF */  sw         $v1, 0x4($fp)
    /* 1AD4 801042D4 BD100408 */  j          .L801042F4
    /* 1AD8 801042D8 000050AC */   sw        $s0, 0x0($v0)
  .L801042DC:
    /* 1ADC 801042DC 21204002 */  addu       $a0, $s2, $zero
    /* 1AE0 801042E0 2128C003 */  addu       $a1, $fp, $zero
    /* 1AE4 801042E4 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 1AE8 801042E8 844E468C */  lw         $a2, %lo(vs_battle_rowTypeBuf)($v0)
    /* 1AEC 801042EC 03F3030C */  jal        vs_mainMenu_setUiGrip
    /* 1AF0 801042F0 2138E002 */   addu      $a3, $s7, $zero
  .L801042F4:
    /* 1AF4 801042F4 01001424 */  addiu      $s4, $zero, 0x1
    /* 1AF8 801042F8 21A80000 */  addu       $s5, $zero, $zero
    /* 1AFC 801042FC 1180033C */  lui        $v1, %hi(D_8010BCA4)
    /* 1B00 80104300 6000F626 */  addiu      $s6, $s7, 0x60
    /* 1B04 80104304 1180023C */  lui        $v0, %hi(D_8010BC0A)
    /* 1B08 80104308 0ABC4290 */  lbu        $v0, %lo(D_8010BC0A)($v0)
    /* 1B0C 8010430C 0800D327 */  addiu      $s3, $fp, 0x8
    /* 1B10 80104310 A4BC62A0 */  sb         $v0, %lo(D_8010BCA4)($v1)
    /* 1B14 80104314 0680083C */  lui        $t0, %hi(vs_main_inventoryIndices)
  .L80104318:
    /* 1B18 80104318 D8190825 */  addiu      $t0, $t0, %lo(vs_main_inventoryIndices)
    /* 1B1C 8010431C 2110A802 */  addu       $v0, $s5, $t0
    /* 1B20 80104320 18005090 */  lbu        $s0, 0x18($v0)
    /* 1B24 80104324 00000000 */  nop
    /* 1B28 80104328 2A000012 */  beqz       $s0, .L801043D4
    /* 1B2C 8010432C 1180023C */   lui       $v0, %hi(D_8010BC0A)
    /* 1B30 80104330 0ABC4290 */  lbu        $v0, %lo(D_8010BC0A)($v0)
    /* 1B34 80104334 00000000 */  nop
    /* 1B38 80104338 26000212 */  beq        $s0, $v0, .L801043D4
    /* 1B3C 8010433C 00111000 */   sll       $v0, $s0, 4
    /* 1B40 80104340 0680083C */  lui        $t0, %hi(D_80060698)
    /* 1B44 80104344 98060825 */  addiu      $t0, $t0, %lo(D_80060698)
    /* 1B48 80104348 21904800 */  addu       $s2, $v0, $t0
    /* 1B4C 8010434C 0C004296 */  lhu        $v0, 0xC($s2)
    /* 1B50 80104350 00000000 */  nop
    /* 1B54 80104354 1F004014 */  bnez       $v0, .L801043D4
    /* 1B58 80104358 21204002 */   addu      $a0, $s2, $zero
    /* 1B5C 8010435C 21286002 */  addu       $a1, $s3, $zero
    /* 1B60 80104360 2138C002 */  addu       $a3, $s6, $zero
    /* 1B64 80104364 0F80083C */  lui        $t0, %hi(vs_battle_rowTypeBuf)
    /* 1B68 80104368 844E068D */  lw         $a2, %lo(vs_battle_rowTypeBuf)($t0)
    /* 1B6C 8010436C 80881400 */  sll        $s1, $s4, 2
    /* 1B70 80104370 03F3030C */  jal        vs_mainMenu_setUiGrip
    /* 1B74 80104374 2130D100 */   addu      $a2, $a2, $s1
    /* 1B78 80104378 1000A48F */  lw         $a0, 0x10($sp)
    /* 1B7C 8010437C CF0C040C */  jal        _isValidGrip
    /* 1B80 80104380 21284002 */   addu      $a1, $s2, $zero
    /* 1B84 80104384 0D004014 */  bnez       $v0, .L801043BC
    /* 1B88 80104388 1180083C */   lui       $t0, %hi(D_8010BCA4)
    /* 1B8C 8010438C 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 1B90 80104390 0F80083C */  lui        $t0, %hi(vs_battle_rowTypeBuf)
    /* 1B94 80104394 A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 1B98 80104398 844E038D */  lw         $v1, %lo(vs_battle_rowTypeBuf)($t0)
    /* 1B9C 8010439C 6A024224 */  addiu      $v0, $v0, 0x26A
    /* 1BA0 801043A0 21182302 */  addu       $v1, $s1, $v1
    /* 1BA4 801043A4 040062AE */  sw         $v0, 0x4($s3)
    /* 1BA8 801043A8 0000628C */  lw         $v0, 0x0($v1)
    /* 1BAC 801043AC 00000000 */  nop
    /* 1BB0 801043B0 01004234 */  ori        $v0, $v0, 0x1
    /* 1BB4 801043B4 000062AC */  sw         $v0, 0x0($v1)
    /* 1BB8 801043B8 1180083C */  lui        $t0, %hi(D_8010BCA4)
  .L801043BC:
    /* 1BBC 801043BC A4BC0825 */  addiu      $t0, $t0, %lo(D_8010BCA4)
    /* 1BC0 801043C0 21108802 */  addu       $v0, $s4, $t0
    /* 1BC4 801043C4 000050A0 */  sb         $s0, 0x0($v0)
    /* 1BC8 801043C8 6000D626 */  addiu      $s6, $s6, 0x60
    /* 1BCC 801043CC 08007326 */  addiu      $s3, $s3, 0x8
    /* 1BD0 801043D0 01009426 */  addiu      $s4, $s4, 0x1
  .L801043D4:
    /* 1BD4 801043D4 0100B526 */  addiu      $s5, $s5, 0x1
    /* 1BD8 801043D8 1000A22A */  slti       $v0, $s5, 0x10
    /* 1BDC 801043DC CEFF4014 */  bnez       $v0, .L80104318
    /* 1BE0 801043E0 0680083C */   lui       $t0, %hi(vs_main_inventoryIndices)
    /* 1BE4 801043E4 21208002 */  addu       $a0, $s4, $zero
    /* 1BE8 801043E8 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 1BEC 801043EC 844E468C */  lw         $a2, %lo(vs_battle_rowTypeBuf)($v0)
    /* 1BF0 801043F0 FF0C040C */  jal        _populateItemsList
    /* 1BF4 801043F4 2128C003 */   addu      $a1, $fp, $zero
    /* 1BF8 801043F8 180F010C */  jal        vs_main_freeHeapR
    /* 1BFC 801043FC 2120E002 */   addu      $a0, $s7, $zero
    /* 1C00 80104400 1180033C */  lui        $v1, %hi(D_8010BC08)
    /* 1C04 80104404 01000224 */  addiu      $v0, $zero, 0x1
    /* 1C08 80104408 40110408 */  j          .L80104500
    /* 1C0C 8010440C 08BC62A0 */   sb        $v0, %lo(D_8010BC08)($v1)
  .L80104410:
    /* 1C10 80104410 1180033C */  lui        $v1, %hi(D_8010BCA4)
    /* 1C14 80104414 1180023C */  lui        $v0, %hi(D_8010BCA2)
    /* 1C18 80104418 1180053C */  lui        $a1, %hi(D_8010BC9C)
    /* 1C1C 8010441C A2BC4290 */  lbu        $v0, %lo(D_8010BCA2)($v0)
    /* 1C20 80104420 9CBCA58C */  lw         $a1, %lo(D_8010BC9C)($a1)
    /* 1C24 80104424 A4BC6324 */  addiu      $v1, $v1, %lo(D_8010BCA4)
    /* 1C28 80104428 21104500 */  addu       $v0, $v0, $a1
    /* 1C2C 8010442C 21104300 */  addu       $v0, $v0, $v1
    /* 1C30 80104430 00005090 */  lbu        $s0, 0x0($v0)
    /* 1C34 80104434 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 1C38 80104438 08000424 */   addiu     $a0, $zero, 0x8
    /* 1C3C 8010443C 05000012 */  beqz       $s0, .L80104454
    /* 1C40 80104440 00000000 */   nop
    /* 1C44 80104444 41F5030C */  jal        vs_mainMenu_setUiGripStats
    /* 1C48 80104448 21200002 */   addu      $a0, $s0, $zero
    /* 1C4C 8010444C 1A110408 */  j          .L80104468
    /* 1C50 80104450 1180043C */   lui       $a0, %hi(D_8010BC9C)
  .L80104454:
    /* 1C54 80104454 E3EE030C */  jal        func_800FBB8C
    /* 1C58 80104458 04000424 */   addiu     $a0, $zero, 0x4
    /* 1C5C 8010445C 88F4030C */  jal        vs_mainMenu_resetStats
    /* 1C60 80104460 00000000 */   nop
    /* 1C64 80104464 1180043C */  lui        $a0, %hi(D_8010BC9C)
  .L80104468:
    /* 1C68 80104468 1180023C */  lui        $v0, %hi(D_8010BCA2)
    /* 1C6C 8010446C 1180033C */  lui        $v1, %hi(D_8010BCA0)
    /* 1C70 80104470 A2BC4290 */  lbu        $v0, %lo(D_8010BCA2)($v0)
    /* 1C74 80104474 9CBC848C */  lw         $a0, %lo(D_8010BC9C)($a0)
    /* 1C78 80104478 A0BC6590 */  lbu        $a1, %lo(D_8010BCA0)($v1)
    /* 1C7C 8010447C 79FE030C */  jal        vs_mainMenu_printInformation
    /* 1C80 80104480 21208200 */   addu      $a0, $a0, $v0
    /* 1C84 80104484 820D040C */  jal        func_80103608
    /* 1C88 80104488 02000424 */   addiu     $a0, $zero, 0x2
    /* 1C8C 8010448C 780D040C */  jal        func_801035E0
    /* 1C90 80104490 1180103C */   lui       $s0, %hi(D_8010BC04)
    /* 1C94 80104494 01004224 */  addiu      $v0, $v0, 0x1
    /* 1C98 80104498 19004010 */  beqz       $v0, .L80104500
    /* 1C9C 8010449C 04BC02AE */   sw        $v0, %lo(D_8010BC04)($s0)
    /* 1CA0 801044A0 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 1CA4 801044A4 28000424 */   addiu     $a0, $zero, 0x28
    /* 1CA8 801044A8 04BC038E */  lw         $v1, %lo(D_8010BC04)($s0)
    /* 1CAC 801044AC FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 1CB0 801044B0 14006210 */  beq        $v1, $v0, .L80104504
    /* 1CB4 801044B4 00000000 */   nop
    /* 1CB8 801044B8 06006018 */  blez       $v1, .L801044D4
    /* 1CBC 801044BC 1180023C */   lui       $v0, %hi(D_8010BCA4)
    /* 1CC0 801044C0 A4BC4224 */  addiu      $v0, $v0, %lo(D_8010BCA4)
    /* 1CC4 801044C4 21106200 */  addu       $v0, $v1, $v0
    /* 1CC8 801044C8 FFFF4290 */  lbu        $v0, -0x1($v0)
    /* 1CCC 801044CC 00000000 */  nop
    /* 1CD0 801044D0 04BC02AE */  sw         $v0, %lo(D_8010BC04)($s0)
  .L801044D4:
    /* 1CD4 801044D4 1180033C */  lui        $v1, %hi(D_8010BC08)
    /* 1CD8 801044D8 02000224 */  addiu      $v0, $zero, 0x2
    /* 1CDC 801044DC 40110408 */  j          .L80104500
    /* 1CE0 801044E0 08BC62A0 */   sb        $v0, %lo(D_8010BC08)($v1)
  .L801044E4:
    /* 1CE4 801044E4 74EA030C */  jal        vs_mainmenu_ready
    /* 1CE8 801044E8 00000000 */   nop
    /* 1CEC 801044EC 04004010 */  beqz       $v0, .L80104500
    /* 1CF0 801044F0 1180023C */   lui       $v0, %hi(D_8010BC04)
    /* 1CF4 801044F4 04BC428C */  lw         $v0, %lo(D_8010BC04)($v0)
    /* 1CF8 801044F8 41110408 */  j          .L80104504
    /* 1CFC 801044FC 00000000 */   nop
  .L80104500:
    /* 1D00 80104500 21100000 */  addu       $v0, $zero, $zero
  .L80104504:
    /* 1D04 80104504 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 1D08 80104508 3800BE8F */  lw         $fp, 0x38($sp)
    /* 1D0C 8010450C 3400B78F */  lw         $s7, 0x34($sp)
    /* 1D10 80104510 3000B68F */  lw         $s6, 0x30($sp)
    /* 1D14 80104514 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 1D18 80104518 2800B48F */  lw         $s4, 0x28($sp)
    /* 1D1C 8010451C 2400B38F */  lw         $s3, 0x24($sp)
    /* 1D20 80104520 2000B28F */  lw         $s2, 0x20($sp)
    /* 1D24 80104524 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1D28 80104528 1800B08F */  lw         $s0, 0x18($sp)
    /* 1D2C 8010452C 0800E003 */  jr         $ra
    /* 1D30 80104530 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_8010418C
