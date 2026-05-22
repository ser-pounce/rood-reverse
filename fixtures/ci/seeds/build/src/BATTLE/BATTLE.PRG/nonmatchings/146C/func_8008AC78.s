nonmatching func_8008AC78, 0x584

glabel func_8008AC78
    /* 22478 8008AC78 98FFBD27 */  addiu      $sp, $sp, -0x68
    /* 2247C 8008AC7C 801F043C */  lui        $a0, (0x1F800014 >> 16)
    /* 22480 8008AC80 14008434 */  ori        $a0, $a0, (0x1F800014 & 0xFFFF)
    /* 22484 8008AC84 6000BFAF */  sw         $ra, 0x60($sp)
    /* 22488 8008AC88 5C00B5AF */  sw         $s5, 0x5C($sp)
    /* 2248C 8008AC8C 5800B4AF */  sw         $s4, 0x58($sp)
    /* 22490 8008AC90 5400B3AF */  sw         $s3, 0x54($sp)
    /* 22494 8008AC94 5000B2AF */  sw         $s2, 0x50($sp)
    /* 22498 8008AC98 4C00B1AF */  sw         $s1, 0x4C($sp)
    /* 2249C 8008AC9C 6605010C */  jal        SetRotMatrix
    /* 224A0 8008ACA0 4800B0AF */   sw        $s0, 0x48($sp)
    /* 224A4 8008ACA4 801F043C */  lui        $a0, (0x1F800014 >> 16)
    /* 224A8 8008ACA8 5E05010C */  jal        SetTransMatrix
    /* 224AC 8008ACAC 14008434 */   ori       $a0, $a0, (0x1F800014 & 0xFFFF)
    /* 224B0 8008ACB0 C537020C */  jal        func_8008DF14
    /* 224B4 8008ACB4 00000000 */   nop
    /* 224B8 8008ACB8 9F58020C */  jal        func_8009627C
    /* 224BC 8008ACBC 00000000 */   nop
    /* 224C0 8008ACC0 3030020C */  jal        func_8008C0C0
    /* 224C4 8008ACC4 00000000 */   nop
    /* 224C8 8008ACC8 0F80023C */  lui        $v0, %hi(D_800F1BA4)
    /* 224CC 8008ACCC A41B4294 */  lhu        $v0, %lo(D_800F1BA4)($v0)
    /* 224D0 8008ACD0 00000000 */  nop
    /* 224D4 8008ACD4 0F004014 */  bnez       $v0, .L8008AD14
    /* 224D8 8008ACD8 0680033C */   lui       $v1, %hi(vs_gametime_tickspeed)
    /* 224DC 8008ACDC 4CE2628C */  lw         $v0, %lo(vs_gametime_tickspeed)($v1)
    /* 224E0 8008ACE0 00000000 */  nop
    /* 224E4 8008ACE4 43100200 */  sra        $v0, $v0, 1
    /* 224E8 8008ACE8 0A004018 */  blez       $v0, .L8008AD14
    /* 224EC 8008ACEC 21800000 */   addu      $s0, $zero, $zero
    /* 224F0 8008ACF0 21886000 */  addu       $s1, $v1, $zero
  .L8008ACF4:
    /* 224F4 8008ACF4 C146020C */  jal        func_80091B04
    /* 224F8 8008ACF8 01001026 */   addiu     $s0, $s0, 0x1
    /* 224FC 8008ACFC 4CE2228E */  lw         $v0, %lo(vs_gametime_tickspeed)($s1)
    /* 22500 8008AD00 00000000 */  nop
    /* 22504 8008AD04 43100200 */  sra        $v0, $v0, 1
    /* 22508 8008AD08 2A100202 */  slt        $v0, $s0, $v0
    /* 2250C 8008AD0C F9FF4014 */  bnez       $v0, .L8008ACF4
    /* 22510 8008AD10 00000000 */   nop
  .L8008AD14:
    /* 22514 8008AD14 AC33020C */  jal        func_8008CEB0
    /* 22518 8008AD18 0F80103C */   lui       $s0, %hi(vs_battle_roomData)
    /* 2251C 8008AD1C BB43020C */  jal        func_80090EEC
    /* 22520 8008AD20 F81B1226 */   addiu     $s2, $s0, %lo(vs_battle_roomData)
    /* 22524 8008AD24 F81B1196 */  lhu        $s1, %lo(vs_battle_roomData)($s0)
    /* 22528 8008AD28 01010224 */  addiu      $v0, $zero, 0x101
    /* 2252C 8008AD2C 2A012216 */  bne        $s1, $v0, .L8008B1D8
    /* 22530 8008AD30 00000000 */   nop
    /* 22534 8008AD34 6400448E */  lw         $a0, 0x64($s2)
    /* 22538 8008AD38 00000000 */  nop
    /* 2253C 8008AD3C 1A008010 */  beqz       $a0, .L8008ADA8
    /* 22540 8008AD40 801F083C */   lui       $t0, (0x1F800010 >> 16)
    /* 22544 8008AD44 C0090624 */  addiu      $a2, $zero, 0x9C0
    /* 22548 8008AD48 01000724 */  addiu      $a3, $zero, 0x1
    /* 2254C 8008AD4C 40080324 */  addiu      $v1, $zero, 0x840
    /* 22550 8008AD50 5800058D */  lw         $a1, (0x1F800058 & 0xFFFF)($t0)
    /* 22554 8008AD54 00090224 */  addiu      $v0, $zero, 0x900
    /* 22558 8008AD58 2330C500 */  subu       $a2, $a2, $a1
    /* 2255C 8008AD5C FF0FC630 */  andi       $a2, $a2, 0xFFF
    /* 22560 8008AD60 43320600 */  sra        $a2, $a2, 9
    /* 22564 8008AD64 0430C700 */  sllv       $a2, $a3, $a2
    /* 22568 8008AD68 23186500 */  subu       $v1, $v1, $a1
    /* 2256C 8008AD6C FF0F6330 */  andi       $v1, $v1, 0xFFF
    /* 22570 8008AD70 431A0300 */  sra        $v1, $v1, 9
    /* 22574 8008AD74 04186700 */  sllv       $v1, $a3, $v1
    /* 22578 8008AD78 23104500 */  subu       $v0, $v0, $a1
    /* 2257C 8008AD7C FF0F4230 */  andi       $v0, $v0, 0xFFF
    /* 22580 8008AD80 43120200 */  sra        $v0, $v0, 9
    /* 22584 8008AD84 04384700 */  sllv       $a3, $a3, $v0
    /* 22588 8008AD88 1000028D */  lw         $v0, (0x1F800010 & 0xFFFF)($t0)
    /* 2258C 8008AD8C 00FF0524 */  addiu      $a1, $zero, -0x100
    /* 22590 8008AD90 24104500 */  and        $v0, $v0, $a1
    /* 22594 8008AD94 25104600 */  or         $v0, $v0, $a2
    /* 22598 8008AD98 25104300 */  or         $v0, $v0, $v1
    /* 2259C 8008AD9C 25104700 */  or         $v0, $v0, $a3
    /* 225A0 8008ADA0 7F2C020C */  jal        func_8008B1FC
    /* 225A4 8008ADA4 100002AD */   sw        $v0, (0x1F800010 & 0xFFFF)($t0)
  .L8008ADA8:
    /* 225A8 8008ADA8 F81B0296 */  lhu        $v0, %lo(vs_battle_roomData)($s0)
    /* 225AC 8008ADAC 00000000 */  nop
    /* 225B0 8008ADB0 09015114 */  bne        $v0, $s1, .L8008B1D8
    /* 225B4 8008ADB4 0680023C */   lui       $v0, %hi(D_80060029)
    /* 225B8 8008ADB8 29004290 */  lbu        $v0, %lo(D_80060029)($v0)
    /* 225BC 8008ADBC 00000000 */  nop
    /* 225C0 8008ADC0 01004230 */  andi       $v0, $v0, 0x1
    /* 225C4 8008ADC4 04014010 */  beqz       $v0, .L8008B1D8
    /* 225C8 8008ADC8 00000000 */   nop
    /* 225CC 8008ADCC 9C00428E */  lw         $v0, 0x9C($s2)
    /* 225D0 8008ADD0 00000000 */  nop
    /* 225D4 8008ADD4 00014010 */  beqz       $v0, .L8008B1D8
    /* 225D8 8008ADD8 0F80023C */   lui       $v0, %hi(D_800F1CD6)
    /* 225DC 8008ADDC D61C4290 */  lbu        $v0, %lo(D_800F1CD6)($v0)
    /* 225E0 8008ADE0 00000000 */  nop
    /* 225E4 8008ADE4 0D004010 */  beqz       $v0, .L8008AE1C
    /* 225E8 8008ADE8 0F80033C */   lui       $v1, %hi(D_800F1CD4)
    /* 225EC 8008ADEC D41C6294 */  lhu        $v0, %lo(D_800F1CD4)($v1)
    /* 225F0 8008ADF0 00000000 */  nop
    /* 225F4 8008ADF4 01004224 */  addiu      $v0, $v0, 0x1
    /* 225F8 8008ADF8 D41C62A4 */  sh         $v0, %lo(D_800F1CD4)($v1)
    /* 225FC 8008ADFC 00140200 */  sll        $v0, $v0, 16
    /* 22600 8008AE00 03140200 */  sra        $v0, $v0, 16
    /* 22604 8008AE04 09004228 */  slti       $v0, $v0, 0x9
    /* 22608 8008AE08 0D004014 */  bnez       $v0, .L8008AE40
    /* 2260C 8008AE0C 0F80023C */   lui       $v0, %hi(D_800F1CD4)
    /* 22610 8008AE10 08000224 */  addiu      $v0, $zero, 0x8
    /* 22614 8008AE14 8F2B0208 */  j          .L8008AE3C
    /* 22618 8008AE18 D41C62A4 */   sh        $v0, %lo(D_800F1CD4)($v1)
  .L8008AE1C:
    /* 2261C 8008AE1C D41C6294 */  lhu        $v0, %lo(D_800F1CD4)($v1)
    /* 22620 8008AE20 00000000 */  nop
    /* 22624 8008AE24 FEFF4224 */  addiu      $v0, $v0, -0x2
    /* 22628 8008AE28 D41C62A4 */  sh         $v0, %lo(D_800F1CD4)($v1)
    /* 2262C 8008AE2C 00140200 */  sll        $v0, $v0, 16
    /* 22630 8008AE30 03004104 */  bgez       $v0, .L8008AE40
    /* 22634 8008AE34 0F80023C */   lui       $v0, %hi(D_800F1CD4)
    /* 22638 8008AE38 D41C60A4 */  sh         $zero, %lo(D_800F1CD4)($v1)
  .L8008AE3C:
    /* 2263C 8008AE3C 0F80023C */  lui        $v0, %hi(D_800F1CD4)
  .L8008AE40:
    /* 22640 8008AE40 D41C4284 */  lh         $v0, %lo(D_800F1CD4)($v0)
    /* 22644 8008AE44 00000000 */  nop
    /* 22648 8008AE48 E3004018 */  blez       $v0, .L8008B1D8
    /* 2264C 8008AE4C 2800B027 */   addiu     $s0, $sp, 0x28
    /* 22650 8008AE50 21200002 */  addu       $a0, $s0, $zero
    /* 22654 8008AE54 801F113C */  lui        $s1, (0x1F800000 >> 16)
    /* 22658 8008AE58 5800228E */  lw         $v0, (0x1F800058 & 0xFFFF)($s1)
    /* 2265C 8008AE5C 00080524 */  addiu      $a1, $zero, 0x800
    /* 22660 8008AE60 642D020C */  jal        func_8008B590
    /* 22664 8008AE64 2328A200 */   subu      $a1, $a1, $v0
    /* 22668 8008AE68 6605010C */  jal        SetRotMatrix
    /* 2266C 8008AE6C 21200002 */   addu      $a0, $s0, $zero
    /* 22670 8008AE70 0680123C */  lui        $s2, %hi(vs_main_frameBuf)
    /* 22674 8008AE74 0680103C */  lui        $s0, %hi(vs_main_drawEnv)
    /* 22678 8008AE78 D0E01026 */  addiu      $s0, $s0, %lo(vs_main_drawEnv)
    /* 2267C 8008AE7C 0000338E */  lw         $s3, (0x1F800000 & 0xFFFF)($s1)
    /* 22680 8008AE80 10E2428E */  lw         $v0, %lo(vs_main_frameBuf)($s2)
    /* 22684 8008AE84 21206002 */  addu       $a0, $s3, $zero
    /* 22688 8008AE88 01004224 */  addiu      $v0, $v0, 0x1
    /* 2268C 8008AE8C 01004230 */  andi       $v0, $v0, 0x1
    /* 22690 8008AE90 40280200 */  sll        $a1, $v0, 1
    /* 22694 8008AE94 2128A200 */  addu       $a1, $a1, $v0
    /* 22698 8008AE98 C0280500 */  sll        $a1, $a1, 3
    /* 2269C 8008AE9C 2328A200 */  subu       $a1, $a1, $v0
    /* 226A0 8008AEA0 80280500 */  sll        $a1, $a1, 2
    /* 226A4 8008AEA4 F7A4000C */  jal        SetDrawArea
    /* 226A8 8008AEA8 2128B000 */   addu      $a1, $a1, $s0
    /* 226AC 8008AEAC 0400248E */  lw         $a0, (0x1F800004 & 0xFFFF)($s1)
    /* 226B0 8008AEB0 21286002 */  addu       $a1, $s3, $zero
    /* 226B4 8008AEB4 35AD000C */  jal        AddPrim
    /* 226B8 8008AEB8 14008424 */   addiu     $a0, $a0, 0x14
    /* 226BC 8008AEBC 10E2438E */  lw         $v1, %lo(vs_main_frameBuf)($s2)
    /* 226C0 8008AEC0 0C007326 */  addiu      $s3, $s3, 0xC
    /* 226C4 8008AEC4 000033AE */  sw         $s3, (0x1F800000 & 0xFFFF)($s1)
    /* 226C8 8008AEC8 01006324 */  addiu      $v1, $v1, 0x1
    /* 226CC 8008AECC 01006330 */  andi       $v1, $v1, 0x1
    /* 226D0 8008AED0 40100300 */  sll        $v0, $v1, 1
    /* 226D4 8008AED4 21104300 */  addu       $v0, $v0, $v1
    /* 226D8 8008AED8 C0100200 */  sll        $v0, $v0, 3
    /* 226DC 8008AEDC 23104300 */  subu       $v0, $v0, $v1
    /* 226E0 8008AEE0 80100200 */  sll        $v0, $v0, 2
    /* 226E4 8008AEE4 21105000 */  addu       $v0, $v0, $s0
    /* 226E8 8008AEE8 00004284 */  lh         $v0, 0x0($v0)
    /* 226EC 8008AEEC 00000000 */  nop
    /* 226F0 8008AEF0 40014228 */  slti       $v0, $v0, 0x140
    /* 226F4 8008AEF4 02004014 */  bnez       $v0, .L8008AF00
    /* 226F8 8008AEF8 D8000224 */   addiu     $v0, $zero, 0xD8
    /* 226FC 8008AEFC 18020224 */  addiu      $v0, $zero, 0x218
  .L8008AF00:
    /* 22700 8008AF00 2000A2A7 */  sh         $v0, 0x20($sp)
    /* 22704 8008AF04 1000A427 */  addiu      $a0, $sp, 0x10
    /* 22708 8008AF08 9C000224 */  addiu      $v0, $zero, 0x9C
    /* 2270C 8008AF0C 2200A2A7 */  sh         $v0, 0x22($sp)
    /* 22710 8008AF10 60000224 */  addiu      $v0, $zero, 0x60
    /* 22714 8008AF14 2400A2A7 */  sh         $v0, 0x24($sp)
    /* 22718 8008AF18 40000224 */  addiu      $v0, $zero, 0x40
    /* 2271C 8008AF1C 2600A2A7 */  sh         $v0, 0x26($sp)
    /* 22720 8008AF20 0F80023C */  lui        $v0, %hi(D_800F1CD4)
    /* 22724 8008AF24 D41C4384 */  lh         $v1, %lo(D_800F1CD4)($v0)
    /* 22728 8008AF28 C4000224 */  addiu      $v0, $zero, 0xC4
    /* 2272C 8008AF2C 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 22730 8008AF30 88010224 */  addiu      $v0, $zero, 0x188
    /* 22734 8008AF34 00190300 */  sll        $v1, $v1, 4
    /* 22738 8008AF38 23104300 */  subu       $v0, $v0, $v1
    /* 2273C 8008AF3C 3565020C */  jal        vs_battle_getGeomOffset
    /* 22740 8008AF40 1800A2AF */   sw        $v0, 0x18($sp)
    /* 22744 8008AF44 3D65020C */  jal        vs_battle_setGeomOffset
    /* 22748 8008AF48 1800A427 */   addiu     $a0, $sp, 0x18
    /* 2274C 8008AF4C 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0x9C)
    /* 22750 8008AF50 941C448C */  lw         $a0, %lo(vs_battle_roomData + 0x9C)($v0)
    /* 22754 8008AF54 E363020C */  jal        func_80098F8C
    /* 22758 8008AF58 801F153C */   lui       $s5, (0x1F800000 >> 16)
    /* 2275C 8008AF5C 3D65020C */  jal        vs_battle_setGeomOffset
    /* 22760 8008AF60 1000A427 */   addiu     $a0, $sp, 0x10
    /* 22764 8008AF64 801F043C */  lui        $a0, (0x1F800014 >> 16)
    /* 22768 8008AF68 6605010C */  jal        SetRotMatrix
    /* 2276C 8008AF6C 14008434 */   ori       $a0, $a0, (0x1F800014 & 0xFFFF)
    /* 22770 8008AF70 0000B38E */  lw         $s3, (0x1F800000 & 0xFFFF)($s5)
    /* 22774 8008AF74 2000A527 */  addiu      $a1, $sp, 0x20
    /* 22778 8008AF78 F7A4000C */  jal        SetDrawArea
    /* 2277C 8008AF7C 21206002 */   addu      $a0, $s3, $zero
    /* 22780 8008AF80 0400A48E */  lw         $a0, (0x1F800004 & 0xFFFF)($s5)
    /* 22784 8008AF84 21286002 */  addu       $a1, $s3, $zero
    /* 22788 8008AF88 35AD000C */  jal        AddPrim
    /* 2278C 8008AF8C 14008424 */   addiu     $a0, $a0, 0x14
    /* 22790 8008AF90 0680023C */  lui        $v0, %hi(D_80060029)
    /* 22794 8008AF94 29004290 */  lbu        $v0, %lo(D_80060029)($v0)
    /* 22798 8008AF98 0C007326 */  addiu      $s3, $s3, 0xC
    /* 2279C 8008AF9C 02004230 */  andi       $v0, $v0, 0x2
    /* 227A0 8008AFA0 8D004010 */  beqz       $v0, .L8008B1D8
    /* 227A4 8008AFA4 0000B3AE */   sw        $s3, (0x1F800000 & 0xFFFF)($s5)
    /* 227A8 8008AFA8 5555033C */  lui        $v1, (0x55555555 >> 16)
    /* 227AC 8008AFAC 55556334 */  ori        $v1, $v1, (0x55555555 & 0xFFFF)
    /* 227B0 8008AFB0 21286002 */  addu       $a1, $s3, $zero
    /* 227B4 8008AFB4 09000224 */  addiu      $v0, $zero, 0x9
    /* 227B8 8008AFB8 030062A2 */  sb         $v0, 0x3($s3)
    /* 227BC 8008AFBC 5C000224 */  addiu      $v0, $zero, 0x5C
    /* 227C0 8008AFC0 D7001124 */  addiu      $s1, $zero, 0xD7
    /* 227C4 8008AFC4 9B001224 */  addiu      $s2, $zero, 0x9B
    /* 227C8 8008AFC8 070062A2 */  sb         $v0, 0x7($s3)
    /* 227CC 8008AFCC 39010224 */  addiu      $v0, $zero, 0x139
    /* 227D0 8008AFD0 100062A6 */  sh         $v0, 0x10($s3)
    /* 227D4 8008AFD4 180062A6 */  sh         $v0, 0x18($s3)
    /* 227D8 8008AFD8 07006292 */  lbu        $v0, 0x7($s3)
    /* 227DC 8008AFDC DC001024 */  addiu      $s0, $zero, 0xDC
    /* 227E0 8008AFE0 240063AE */  sw         $v1, 0x24($s3)
    /* 227E4 8008AFE4 170060A2 */  sb         $zero, 0x17($s3)
    /* 227E8 8008AFE8 1F0060A2 */  sb         $zero, 0x1F($s3)
    /* 227EC 8008AFEC 080071A6 */  sh         $s1, 0x8($s3)
    /* 227F0 8008AFF0 0A0072A6 */  sh         $s2, 0xA($s3)
    /* 227F4 8008AFF4 120072A6 */  sh         $s2, 0x12($s3)
    /* 227F8 8008AFF8 1A0070A6 */  sh         $s0, 0x1A($s3)
    /* 227FC 8008AFFC 200071A6 */  sh         $s1, 0x20($s3)
    /* 22800 8008B000 220070A6 */  sh         $s0, 0x22($s3)
    /* 22804 8008B004 02004234 */  ori        $v0, $v0, 0x2
    /* 22808 8008B008 070062A2 */  sb         $v0, 0x7($s3)
    /* 2280C 8008B00C 28006226 */  addiu      $v0, $s3, 0x28
    /* 22810 8008B010 0400A48E */  lw         $a0, (0x1F800004 & 0xFFFF)($s5)
    /* 22814 8008B014 21A04000 */  addu       $s4, $v0, $zero
    /* 22818 8008B018 35AD000C */  jal        AddPrim
    /* 2281C 8008B01C 14008424 */   addiu     $a0, $a0, 0x14
    /* 22820 8008B020 04000224 */  addiu      $v0, $zero, 0x4
    /* 22824 8008B024 030082A2 */  sb         $v0, 0x3($s4)
    /* 22828 8008B028 52000224 */  addiu      $v0, $zero, 0x52
    /* 2282C 8008B02C 0A0090A6 */  sh         $s0, 0xA($s4)
    /* 22830 8008B030 21808002 */  addu       $s0, $s4, $zero
    /* 22834 8008B034 070082A2 */  sb         $v0, 0x7($s4)
    /* 22838 8008B038 080091A6 */  sh         $s1, 0x8($s4)
    /* 2283C 8008B03C 100091A6 */  sh         $s1, 0x10($s4)
    /* 22840 8008B040 120092A6 */  sh         $s2, 0x12($s4)
    /* 22844 8008B044 3C007426 */  addiu      $s4, $s3, 0x3C
    /* 22848 8008B048 0400A48E */  lw         $a0, (0x1F800004 & 0xFFFF)($s5)
    /* 2284C 8008B04C 21280002 */  addu       $a1, $s0, $zero
    /* 22850 8008B050 35AD000C */  jal        AddPrim
    /* 22854 8008B054 14008424 */   addiu     $a0, $a0, 0x14
    /* 22858 8008B058 05001824 */  addiu      $t8, $zero, 0x5
    /* 2285C 8008B05C 60001924 */  addiu      $t9, $zero, 0x60
    /* 22860 8008B060 0000B4AE */  sw         $s4, (0x1F800000 & 0xFFFF)($s5)
    /* 22864 8008B064 801F0B3C */  lui        $t3, (0x1F800000 >> 16)
    /* 22868 8008B068 80401800 */  sll        $t0, $t8, 2
    /* 2286C 8008B06C 04006C8D */  lw         $t4, (0x1F800004 & 0xFFFF)($t3)
    /* 22870 8008B070 00006F8D */  lw         $t7, (0x1F800000 & 0xFFFF)($t3)
    /* 22874 8008B074 21400C01 */  addu       $t0, $t0, $t4
    /* 22878 8008B078 0000098D */  lw         $t1, 0x0($t0)
    /* 2287C 8008B07C 00E10C3C */  lui        $t4, (0xE1000200 >> 16)
    /* 22880 8008B080 FF012E33 */  andi       $t6, $t9, 0x1FF
    /* 22884 8008B084 00028C35 */  ori        $t4, $t4, (0xE1000200 & 0xFFFF)
    /* 22888 8008B088 25608E01 */  or         $t4, $t4, $t6
    /* 2288C 8008B08C 0400ECAD */  sw         $t4, 0x4($t7)
    /* 22890 8008B090 0800E0AD */  sw         $zero, 0x8($t7)
    /* 22894 8008B094 FF000D3C */  lui        $t5, (0xFFFFFF >> 16)
    /* 22898 8008B098 FFFFAD35 */  ori        $t5, $t5, (0xFFFFFF & 0xFFFF)
    /* 2289C 8008B09C 00020C3C */  lui        $t4, (0x2000000 >> 16)
    /* 228A0 8008B0A0 00FF0E3C */  lui        $t6, (0xFF000000 >> 16)
    /* 228A4 8008B0A4 24502D01 */  and        $t2, $t1, $t5
    /* 228A8 8008B0A8 25608A01 */  or         $t4, $t4, $t2
    /* 228AC 8008B0AC 0000ECAD */  sw         $t4, 0x0($t7)
    /* 228B0 8008B0B0 24502E01 */  and        $t2, $t1, $t6
    /* 228B4 8008B0B4 2460ED01 */  and        $t4, $t7, $t5
    /* 228B8 8008B0B8 25608A01 */  or         $t4, $t4, $t2
    /* 228BC 8008B0BC 00000CAD */  sw         $t4, 0x0($t0)
    /* 228C0 8008B0C0 0C00EA25 */  addiu      $t2, $t7, 0xC
    /* 228C4 8008B0C4 00006AAD */  sw         $t2, (0x1F800000 & 0xFFFF)($t3)
    /* 228C8 8008B0C8 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 228CC 8008B0CC FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 228D0 8008B0D0 00000000 */  nop
    /* 228D4 8008B0D4 2000438C */  lw         $v1, 0x20($v0)
    /* 228D8 8008B0D8 01000224 */  addiu      $v0, $zero, 0x1
    /* 228DC 8008B0DC 28006214 */  bne        $v1, $v0, .L8008B180
    /* 228E0 8008B0E0 0F80023C */   lui       $v0, %hi(D_800F1BA0)
    /* 228E4 8008B0E4 0F80113C */  lui        $s1, %hi(D_800F1BA0)
    /* 228E8 8008B0E8 A01B248E */  lw         $a0, %lo(D_800F1BA0)($s1)
    /* 228EC 8008B0EC CA03010C */  jal        rsin
    /* 228F0 8008B0F0 00220400 */   sll       $a0, $a0, 8
    /* 228F4 8008B0F4 21204000 */  addu       $a0, $v0, $zero
    /* 228F8 8008B0F8 02008104 */  bgez       $a0, .L8008B104
    /* 228FC 8008B0FC 0680023C */   lui       $v0, %hi(vs_gametime_tickspeed)
    /* 22900 8008B100 3F008424 */  addiu      $a0, $a0, 0x3F
  .L8008B104:
    /* 22904 8008B104 4CE2428C */  lw         $v0, %lo(vs_gametime_tickspeed)($v0)
    /* 22908 8008B108 00000000 */  nop
    /* 2290C 8008B10C C21F0200 */  srl        $v1, $v0, 31
    /* 22910 8008B110 21104300 */  addu       $v0, $v0, $v1
    /* 22914 8008B114 A01B238E */  lw         $v1, %lo(D_800F1BA0)($s1)
    /* 22918 8008B118 43100200 */  sra        $v0, $v0, 1
    /* 2291C 8008B11C 21186200 */  addu       $v1, $v1, $v0
    /* 22920 8008B120 83110400 */  sra        $v0, $a0, 6
    /* 22924 8008B124 A01B23AE */  sw         $v1, %lo(D_800F1BA0)($s1)
    /* 22928 8008B128 80000324 */  addiu      $v1, $zero, 0x80
    /* 2292C 8008B12C 23186200 */  subu       $v1, $v1, $v0
    /* 22930 8008B130 20006424 */  addiu      $a0, $v1, 0x20
    /* 22934 8008B134 3F006224 */  addiu      $v0, $v1, 0x3F
    /* 22938 8008B138 040063A2 */  sb         $v1, 0x4($s3)
    /* 2293C 8008B13C 050060A2 */  sb         $zero, 0x5($s3)
    /* 22940 8008B140 060060A2 */  sb         $zero, 0x6($s3)
    /* 22944 8008B144 0C0064A2 */  sb         $a0, 0xC($s3)
    /* 22948 8008B148 0D0060A2 */  sb         $zero, 0xD($s3)
    /* 2294C 8008B14C 0E0060A2 */  sb         $zero, 0xE($s3)
    /* 22950 8008B150 140062A2 */  sb         $v0, 0x14($s3)
    /* 22954 8008B154 150060A2 */  sb         $zero, 0x15($s3)
    /* 22958 8008B158 160060A2 */  sb         $zero, 0x16($s3)
    /* 2295C 8008B15C 1C0064A2 */  sb         $a0, 0x1C($s3)
    /* 22960 8008B160 1D0060A2 */  sb         $zero, 0x1D($s3)
    /* 22964 8008B164 1E0060A2 */  sb         $zero, 0x1E($s3)
    /* 22968 8008B168 040004A2 */  sb         $a0, 0x4($s0)
    /* 2296C 8008B16C 050000A2 */  sb         $zero, 0x5($s0)
    /* 22970 8008B170 060000A2 */  sb         $zero, 0x6($s0)
    /* 22974 8008B174 0C0003A2 */  sb         $v1, 0xC($s0)
    /* 22978 8008B178 752C0208 */  j          .L8008B1D4
    /* 2297C 8008B17C 0D0000A2 */   sb        $zero, 0xD($s0)
  .L8008B180:
    /* 22980 8008B180 80000424 */  addiu      $a0, $zero, 0x80
    /* 22984 8008B184 C0000324 */  addiu      $v1, $zero, 0xC0
    /* 22988 8008B188 A01B40AC */  sw         $zero, %lo(D_800F1BA0)($v0)
    /* 2298C 8008B18C FF000224 */  addiu      $v0, $zero, 0xFF
    /* 22990 8008B190 040060A2 */  sb         $zero, 0x4($s3)
    /* 22994 8008B194 050064A2 */  sb         $a0, 0x5($s3)
    /* 22998 8008B198 060060A2 */  sb         $zero, 0x6($s3)
    /* 2299C 8008B19C 0C0060A2 */  sb         $zero, 0xC($s3)
    /* 229A0 8008B1A0 0D0063A2 */  sb         $v1, 0xD($s3)
    /* 229A4 8008B1A4 0E0060A2 */  sb         $zero, 0xE($s3)
    /* 229A8 8008B1A8 140060A2 */  sb         $zero, 0x14($s3)
    /* 229AC 8008B1AC 150062A2 */  sb         $v0, 0x15($s3)
    /* 229B0 8008B1B0 160060A2 */  sb         $zero, 0x16($s3)
    /* 229B4 8008B1B4 1C0060A2 */  sb         $zero, 0x1C($s3)
    /* 229B8 8008B1B8 1D0063A2 */  sb         $v1, 0x1D($s3)
    /* 229BC 8008B1BC 1E0060A2 */  sb         $zero, 0x1E($s3)
    /* 229C0 8008B1C0 040000A2 */  sb         $zero, 0x4($s0)
    /* 229C4 8008B1C4 050003A2 */  sb         $v1, 0x5($s0)
    /* 229C8 8008B1C8 060000A2 */  sb         $zero, 0x6($s0)
    /* 229CC 8008B1CC 0C0000A2 */  sb         $zero, 0xC($s0)
    /* 229D0 8008B1D0 0D0004A2 */  sb         $a0, 0xD($s0)
  .L8008B1D4:
    /* 229D4 8008B1D4 0E0000A2 */  sb         $zero, 0xE($s0)
  .L8008B1D8:
    /* 229D8 8008B1D8 6000BF8F */  lw         $ra, 0x60($sp)
    /* 229DC 8008B1DC 5C00B58F */  lw         $s5, 0x5C($sp)
    /* 229E0 8008B1E0 5800B48F */  lw         $s4, 0x58($sp)
    /* 229E4 8008B1E4 5400B38F */  lw         $s3, 0x54($sp)
    /* 229E8 8008B1E8 5000B28F */  lw         $s2, 0x50($sp)
    /* 229EC 8008B1EC 4C00B18F */  lw         $s1, 0x4C($sp)
    /* 229F0 8008B1F0 4800B08F */  lw         $s0, 0x48($sp)
    /* 229F4 8008B1F4 0800E003 */  jr         $ra
    /* 229F8 8008B1F8 6800BD27 */   addiu     $sp, $sp, 0x68
endlabel func_8008AC78
