nonmatching func_801061F8, 0x330

glabel func_801061F8
    /* 39F8 801061F8 68FFBD27 */  addiu      $sp, $sp, -0x98
    /* 39FC 801061FC 8000B4AF */  sw         $s4, 0x80($sp)
    /* 3A00 80106200 21A08000 */  addu       $s4, $a0, $zero
    /* 3A04 80106204 7400B1AF */  sw         $s1, 0x74($sp)
    /* 3A08 80106208 1080023C */  lui        $v0, %hi(D_80102970)
    /* 3A0C 8010620C 9400BFAF */  sw         $ra, 0x94($sp)
    /* 3A10 80106210 9000BEAF */  sw         $fp, 0x90($sp)
    /* 3A14 80106214 8C00B7AF */  sw         $s7, 0x8C($sp)
    /* 3A18 80106218 8800B6AF */  sw         $s6, 0x88($sp)
    /* 3A1C 8010621C 8400B5AF */  sw         $s5, 0x84($sp)
    /* 3A20 80106220 7C00B3AF */  sw         $s3, 0x7C($sp)
    /* 3A24 80106224 7800B2AF */  sw         $s2, 0x78($sp)
    /* 3A28 80106228 7000B0AF */  sw         $s0, 0x70($sp)
    /* 3A2C 8010622C 70294B24 */  addiu      $t3, $v0, %lo(D_80102970)
    /* 3A30 80106230 0000688D */  lw         $t0, 0x0($t3)
    /* 3A34 80106234 0400698D */  lw         $t1, 0x4($t3)
    /* 3A38 80106238 08006A8D */  lw         $t2, 0x8($t3)
    /* 3A3C 8010623C 1800A8AF */  sw         $t0, 0x18($sp)
    /* 3A40 80106240 1C00A9AF */  sw         $t1, 0x1C($sp)
    /* 3A44 80106244 2000AAAF */  sw         $t2, 0x20($sp)
    /* 3A48 80106248 0C00688D */  lw         $t0, 0xC($t3)
    /* 3A4C 8010624C 1000698D */  lw         $t1, 0x10($t3)
    /* 3A50 80106250 14006A8D */  lw         $t2, 0x14($t3)
    /* 3A54 80106254 2400A8AF */  sw         $t0, 0x24($sp)
    /* 3A58 80106258 2800A9AF */  sw         $t1, 0x28($sp)
    /* 3A5C 8010625C 2C00AAAF */  sw         $t2, 0x2C($sp)
    /* 3A60 80106260 0800822A */  slti       $v0, $s4, 0x8
    /* 3A64 80106264 03004010 */  beqz       $v0, .L80106274
    /* 3A68 80106268 2188A000 */   addu      $s1, $a1, $zero
    /* 3A6C 8010626C 4A19040C */  jal        func_80106528
    /* 3A70 80106270 00000000 */   nop
  .L80106274:
    /* 3A74 80106274 03000224 */  addiu      $v0, $zero, 0x3
    /* 3A78 80106278 1B002212 */  beq        $s1, $v0, .L801062E8
    /* 3A7C 8010627C 00000000 */   nop
    /* 3A80 80106280 3565020C */  jal        vs_battle_getGeomOffset
    /* 3A84 80106284 5000A427 */   addiu     $a0, $sp, 0x50
    /* 3A88 80106288 02000224 */  addiu      $v0, $zero, 0x2
    /* 3A8C 8010628C 06002216 */  bne        $s1, $v0, .L801062A8
    /* 3A90 80106290 08000324 */   addiu     $v1, $zero, 0x8
    /* 3A94 80106294 08000224 */  addiu      $v0, $zero, 0x8
    /* 3A98 80106298 23105400 */  subu       $v0, $v0, $s4
    /* 3A9C 8010629C 40110200 */  sll        $v0, $v0, 5
    /* 3AA0 801062A0 AE180408 */  j          .L801062B8
    /* 3AA4 801062A4 A0004224 */   addiu     $v0, $v0, 0xA0
  .L801062A8:
    /* 3AA8 801062A8 23187400 */  subu       $v1, $v1, $s4
    /* 3AAC 801062AC 40190300 */  sll        $v1, $v1, 5
    /* 3AB0 801062B0 A0000224 */  addiu      $v0, $zero, 0xA0
    /* 3AB4 801062B4 23104300 */  subu       $v0, $v0, $v1
  .L801062B8:
    /* 3AB8 801062B8 5800A2AF */  sw         $v0, 0x58($sp)
    /* 3ABC 801062BC 68000224 */  addiu      $v0, $zero, 0x68
    /* 3AC0 801062C0 5C00A2AF */  sw         $v0, 0x5C($sp)
    /* 3AC4 801062C4 3D65020C */  jal        vs_battle_setGeomOffset
    /* 3AC8 801062C8 5800A427 */   addiu     $a0, $sp, 0x58
    /* 3ACC 801062CC 3000B027 */  addiu      $s0, $sp, 0x30
    /* 3AD0 801062D0 2F13040C */  jal        func_80104CBC
    /* 3AD4 801062D4 21200002 */   addu      $a0, $s0, $zero
    /* 3AD8 801062D8 AEE7030C */  jal        func_800F9EB8
    /* 3ADC 801062DC 21200002 */   addu      $a0, $s0, $zero
    /* 3AE0 801062E0 3D65020C */  jal        vs_battle_setGeomOffset
    /* 3AE4 801062E4 5000A427 */   addiu     $a0, $sp, 0x50
  .L801062E8:
    /* 3AE8 801062E8 0200201A */  blez       $s1, .L801062F4
    /* 3AEC 801062EC 1180023C */   lui       $v0, %hi(D_8010A45C)
    /* 3AF0 801062F0 08001424 */  addiu      $s4, $zero, 0x8
  .L801062F4:
    /* 3AF4 801062F4 5CA4428C */  lw         $v0, %lo(D_8010A45C)($v0)
    /* 3AF8 801062F8 00000000 */  nop
    /* 3AFC 801062FC 7E004014 */  bnez       $v0, .L801064F8
    /* 3B00 80106300 21200000 */   addu      $a0, $zero, $zero
    /* 3B04 80106304 08001224 */  addiu      $s2, $zero, 0x8
    /* 3B08 80106308 23905402 */  subu       $s2, $s2, $s4
    /* 3B0C 8010630C 00911200 */  sll        $s2, $s2, 4
    /* 3B10 80106310 B8004526 */  addiu      $a1, $s2, 0xB8
    /* 3B14 80106314 A6000624 */  addiu      $a2, $zero, 0xA6
    /* 3B18 80106318 00010724 */  addiu      $a3, $zero, 0x100
    /* 3B1C 8010631C 1180173C */  lui        $s7, %hi(D_8010A450)
    /* 3B20 80106320 50A4E386 */  lh         $v1, %lo(D_8010A450)($s7)
    /* 3B24 80106324 11801E3C */  lui        $fp, %hi(_monBinData)
    /* 3B28 80106328 1000A0AF */  sw         $zero, 0x10($sp)
    /* 3B2C 8010632C 40100300 */  sll        $v0, $v1, 1
    /* 3B30 80106330 21104300 */  addu       $v0, $v0, $v1
    /* 3B34 80106334 80100200 */  sll        $v0, $v0, 2
    /* 3B38 80106338 23104300 */  subu       $v0, $v0, $v1
    /* 3B3C 8010633C 70A4C38F */  lw         $v1, %lo(_monBinData)($fp)
    /* 3B40 80106340 80100200 */  sll        $v0, $v0, 2
    /* 3B44 80106344 21186200 */  addu       $v1, $v1, $v0
    /* 3B48 80106348 12006324 */  addiu      $v1, $v1, 0x12
    /* 3B4C 8010634C 9723030C */  jal        vs_battle_setMenuItem
    /* 3B50 80106350 1400A3AF */   sw        $v1, 0x14($sp)
    /* 3B54 80106354 1E24030C */  jal        func_800C9078
    /* 3B58 80106358 21204000 */   addu      $a0, $v0, $zero
    /* 3B5C 8010635C 9223030C */  jal        vs_battle_getMenuItem
    /* 3B60 80106360 21200000 */   addu      $a0, $zero, $zero
    /* 3B64 80106364 06000424 */  addiu      $a0, $zero, 0x6
    /* 3B68 80106368 00A11400 */  sll        $s4, $s4, 4
    /* 3B6C 8010636C 88FF9326 */  addiu      $s3, $s4, -0x78
    /* 3B70 80106370 21286002 */  addu       $a1, $s3, $zero
    /* 3B74 80106374 801F113C */  lui        $s1, (0x1F800004 >> 16)
    /* 3B78 80106378 000040A0 */  sb         $zero, 0x0($v0)
    /* 3B7C 8010637C 0400278E */  lw         $a3, (0x1F800004 & 0xFFFF)($s1)
    /* 3B80 80106380 0F000624 */  addiu      $a2, $zero, 0xF
    /* 3B84 80106384 1AFF030C */  jal        vs_mainmenu_drawButton
    /* 3B88 80106388 1800E724 */   addiu     $a3, $a3, 0x18
    /* 3B8C 8010638C 1080043C */  lui        $a0, %hi(D_80102988)
    /* 3B90 80106390 88298424 */  addiu      $a0, $a0, %lo(D_80102988)
    /* 3B94 80106394 9CFF9026 */  addiu      $s0, $s4, -0x64
    /* 3B98 80106398 FFFF1032 */  andi       $s0, $s0, 0xFFFF
    /* 3B9C 8010639C 1200053C */  lui        $a1, (0x120000 >> 16)
    /* 3BA0 801063A0 25280502 */  or         $a1, $s0, $a1
    /* 3BA4 801063A4 1180023C */  lui        $v0, %hi(D_8010A458)
    /* 3BA8 801063A8 0400278E */  lw         $a3, (0x1F800004 & 0xFFFF)($s1)
    /* 3BAC 801063AC 58A4468C */  lw         $a2, %lo(D_8010A458)($v0)
    /* 3BB0 801063B0 5019030C */  jal        vs_battle_renderTextRawColor
    /* 3BB4 801063B4 1800E724 */   addiu     $a3, $a3, 0x18
    /* 3BB8 801063B8 90FF9626 */  addiu      $s6, $s4, -0x70
    /* 3BBC 801063BC 2120C002 */  addu       $a0, $s6, $zero
    /* 3BC0 801063C0 12000524 */  addiu      $a1, $zero, 0x12
    /* 3BC4 801063C4 60000624 */  addiu      $a2, $zero, 0x60
    /* 3BC8 801063C8 0C000724 */  addiu      $a3, $zero, 0xC
    /* 3BCC 801063CC 03001524 */  addiu      $s5, $zero, 0x3
    /* 3BD0 801063D0 DD13040C */  jal        func_80104F74
    /* 3BD4 801063D4 1000B5AF */   sw        $s5, 0x10($sp)
    /* 3BD8 801063D8 07000424 */  addiu      $a0, $zero, 0x7
    /* 3BDC 801063DC 21286002 */  addu       $a1, $s3, $zero
    /* 3BE0 801063E0 0400278E */  lw         $a3, (0x1F800004 & 0xFFFF)($s1)
    /* 3BE4 801063E4 22000624 */  addiu      $a2, $zero, 0x22
    /* 3BE8 801063E8 1AFF030C */  jal        vs_mainmenu_drawButton
    /* 3BEC 801063EC 1800E724 */   addiu     $a3, $a3, 0x18
    /* 3BF0 801063F0 1080043C */  lui        $a0, %hi(D_80102994)
    /* 3BF4 801063F4 94298424 */  addiu      $a0, $a0, %lo(D_80102994)
    /* 3BF8 801063F8 2400053C */  lui        $a1, (0x240000 >> 16)
    /* 3BFC 801063FC 25280502 */  or         $a1, $s0, $a1
    /* 3C00 80106400 1180023C */  lui        $v0, %hi(D_8010A454)
    /* 3C04 80106404 0400278E */  lw         $a3, (0x1F800004 & 0xFFFF)($s1)
    /* 3C08 80106408 54A4468C */  lw         $a2, %lo(D_8010A454)($v0)
    /* 3C0C 8010640C 5019030C */  jal        vs_battle_renderTextRawColor
    /* 3C10 80106410 1800E724 */   addiu     $a3, $a3, 0x18
    /* 3C14 80106414 2120C002 */  addu       $a0, $s6, $zero
    /* 3C18 80106418 24000524 */  addiu      $a1, $zero, 0x24
    /* 3C1C 8010641C 4E000624 */  addiu      $a2, $zero, 0x4E
    /* 3C20 80106420 0C000724 */  addiu      $a3, $zero, 0xC
    /* 3C24 80106424 DD13040C */  jal        func_80104F74
    /* 3C28 80106428 1000B5AF */   sw        $s5, 0x10($sp)
    /* 3C2C 8010642C 6000B027 */  addiu      $s0, $sp, 0x60
    /* 3C30 80106430 21200002 */  addu       $a0, $s0, $zero
    /* 3C34 80106434 1080053C */  lui        $a1, %hi(D_8010299C)
    /* 3C38 80106438 9C29A524 */  addiu      $a1, $a1, %lo(D_8010299C)
    /* 3C3C 8010643C 50A4E686 */  lh         $a2, %lo(D_8010A450)($s7)
    /* 3C40 80106440 4E000724 */  addiu      $a3, $zero, 0x4E
    /* 3C44 80106444 BD9B000C */  jal        sprintf
    /* 3C48 80106448 0100C624 */   addiu     $a2, $a2, 0x1
    /* 3C4C 8010644C 21200002 */  addu       $a0, $s0, $zero
    /* 3C50 80106450 FFFF7332 */  andi       $s3, $s3, 0xFFFF
    /* 3C54 80106454 A000053C */  lui        $a1, (0xA00000 >> 16)
    /* 3C58 80106458 25286502 */  or         $a1, $s3, $a1
    /* 3C5C 8010645C 8000063C */  lui        $a2, (0x808080 >> 16)
    /* 3C60 80106460 0400278E */  lw         $a3, (0x1F800004 & 0xFFFF)($s1)
    /* 3C64 80106464 8080C634 */  ori        $a2, $a2, (0x808080 & 0xFFFF)
    /* 3C68 80106468 5019030C */  jal        vs_battle_renderTextRawColor
    /* 3C6C 8010646C 1C00E724 */   addiu     $a3, $a3, 0x1C
    /* 3C70 80106470 80FF8426 */  addiu      $a0, $s4, -0x80
    /* 3C74 80106474 A0000524 */  addiu      $a1, $zero, 0xA0
    /* 3C78 80106478 64000624 */  addiu      $a2, $zero, 0x64
    /* 3C7C 8010647C 0C000724 */  addiu      $a3, $zero, 0xC
    /* 3C80 80106480 02000224 */  addiu      $v0, $zero, 0x2
    /* 3C84 80106484 6B14040C */  jal        func_801051AC
    /* 3C88 80106488 1000A2AF */   sw        $v0, 0x10($sp)
    /* 3C8C 8010648C BC004526 */  addiu      $a1, $s2, 0xBC
    /* 3C90 80106490 FFFFA530 */  andi       $a1, $a1, 0xFFFF
    /* 3C94 80106494 9B00023C */  lui        $v0, (0x9B0000 >> 16)
    /* 3C98 80106498 2528A200 */  or         $a1, $a1, $v0
    /* 3C9C 8010649C 50A4E386 */  lh         $v1, %lo(D_8010A450)($s7)
    /* 3CA0 801064A0 8000063C */  lui        $a2, (0x808080 >> 16)
    /* 3CA4 801064A4 40100300 */  sll        $v0, $v1, 1
    /* 3CA8 801064A8 21104300 */  addu       $v0, $v0, $v1
    /* 3CAC 801064AC 80100200 */  sll        $v0, $v0, 2
    /* 3CB0 801064B0 23104300 */  subu       $v0, $v0, $v1
    /* 3CB4 801064B4 70A4C38F */  lw         $v1, %lo(_monBinData)($fp)
    /* 3CB8 801064B8 80100200 */  sll        $v0, $v0, 2
    /* 3CBC 801064BC 21104300 */  addu       $v0, $v0, $v1
    /* 3CC0 801064C0 02004284 */  lh         $v0, 0x2($v0)
    /* 3CC4 801064C4 8080C634 */  ori        $a2, $a2, (0x808080 & 0xFFFF)
    /* 3CC8 801064C8 80100200 */  sll        $v0, $v0, 2
    /* 3CCC 801064CC 2110A203 */  addu       $v0, $sp, $v0
    /* 3CD0 801064D0 1800448C */  lw         $a0, 0x18($v0)
    /* 3CD4 801064D4 5019030C */  jal        vs_battle_renderTextRawColor
    /* 3CD8 801064D8 21380000 */   addu      $a3, $zero, $zero
    /* 3CDC 801064DC B4004426 */  addiu      $a0, $s2, 0xB4
    /* 3CE0 801064E0 9B000524 */  addiu      $a1, $zero, 0x9B
    /* 3CE4 801064E4 8C000624 */  addiu      $a2, $zero, 0x8C
    /* 3CE8 801064E8 1A000724 */  addiu      $a3, $zero, 0x1A
    /* 3CEC 801064EC 01000224 */  addiu      $v0, $zero, 0x1
    /* 3CF0 801064F0 6B14040C */  jal        func_801051AC
    /* 3CF4 801064F4 1000A2AF */   sw        $v0, 0x10($sp)
  .L801064F8:
    /* 3CF8 801064F8 9400BF8F */  lw         $ra, 0x94($sp)
    /* 3CFC 801064FC 9000BE8F */  lw         $fp, 0x90($sp)
    /* 3D00 80106500 8C00B78F */  lw         $s7, 0x8C($sp)
    /* 3D04 80106504 8800B68F */  lw         $s6, 0x88($sp)
    /* 3D08 80106508 8400B58F */  lw         $s5, 0x84($sp)
    /* 3D0C 8010650C 8000B48F */  lw         $s4, 0x80($sp)
    /* 3D10 80106510 7C00B38F */  lw         $s3, 0x7C($sp)
    /* 3D14 80106514 7800B28F */  lw         $s2, 0x78($sp)
    /* 3D18 80106518 7400B18F */  lw         $s1, 0x74($sp)
    /* 3D1C 8010651C 7000B08F */  lw         $s0, 0x70($sp)
    /* 3D20 80106520 0800E003 */  jr         $ra
    /* 3D24 80106524 9800BD27 */   addiu     $sp, $sp, 0x98
endlabel func_801061F8
