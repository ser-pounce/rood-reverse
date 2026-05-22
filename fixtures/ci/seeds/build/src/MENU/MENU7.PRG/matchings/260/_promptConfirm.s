nonmatching _promptConfirm, 0x218

glabel _promptConfirm
    /* 38C8 801060C8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 38CC 801060CC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 38D0 801060D0 08008010 */  beqz       $a0, .L801060F4
    /* 38D4 801060D4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 38D8 801060D8 21100000 */  addu       $v0, $zero, $zero
    /* 38DC 801060DC 1180033C */  lui        $v1, %hi(_promptConfirmCancelled)
    /* 38E0 801060E0 01000424 */  addiu      $a0, $zero, 0x1
    /* 38E4 801060E4 ADAA64A0 */  sb         $a0, %lo(_promptConfirmCancelled)($v1)
    /* 38E8 801060E8 1180033C */  lui        $v1, %hi(_promptConfirmState)
    /* 38EC 801060EC B4180408 */  j          .L801062D0
    /* 38F0 801060F0 ACAA60A0 */   sb        $zero, %lo(_promptConfirmState)($v1)
  .L801060F4:
    /* 38F4 801060F4 1180103C */  lui        $s0, %hi(_promptConfirmState)
    /* 38F8 801060F8 ACAA0792 */  lbu        $a3, %lo(_promptConfirmState)($s0)
    /* 38FC 801060FC 02000224 */  addiu      $v0, $zero, 0x2
    /* 3900 80106100 1E00E210 */  beq        $a3, $v0, .L8010617C
    /* 3904 80106104 0300E228 */   slti      $v0, $a3, 0x3
    /* 3908 80106108 05004014 */  bnez       $v0, .L80106120
    /* 390C 8010610C 03000224 */   addiu     $v0, $zero, 0x3
    /* 3910 80106110 2100E210 */  beq        $a3, $v0, .L80106198
    /* 3914 80106114 21100000 */   addu      $v0, $zero, $zero
    /* 3918 80106118 B4180408 */  j          .L801062D0
    /* 391C 8010611C 00000000 */   nop
  .L80106120:
    /* 3920 80106120 6A00E004 */  bltz       $a3, .L801062CC
    /* 3924 80106124 0300E424 */   addiu     $a0, $a3, 0x3
    /* 3928 80106128 00290700 */  sll        $a1, $a3, 4
    /* 392C 8010612C 1200A524 */  addiu      $a1, $a1, 0x12
    /* 3930 80106130 002C0500 */  sll        $a1, $a1, 16
    /* 3934 80106134 82FFA534 */  ori        $a1, $a1, 0xFF82
    /* 3938 80106138 0C00063C */  lui        $a2, (0xC007E >> 16)
    /* 393C 8010613C 1180023C */  lui        $v0, %hi(_textTable)
    /* 3940 80106140 F8AD438C */  lw         $v1, %lo(_textTable)($v0)
    /* 3944 80106144 40100700 */  sll        $v0, $a3, 1
    /* 3948 80106148 21104300 */  addu       $v0, $v0, $v1
    /* 394C 8010614C 48004794 */  lhu        $a3, 0x48($v0)
    /* 3950 80106150 7E00C634 */  ori        $a2, $a2, (0xC007E & 0xFFFF)
    /* 3954 80106154 40380700 */  sll        $a3, $a3, 1
    /* 3958 80106158 6E13040C */  jal        _initFileMenuElement
    /* 395C 8010615C 21386700 */   addu      $a3, $v1, $a3
    /* 3960 80106160 04000324 */  addiu      $v1, $zero, 0x4
    /* 3964 80106164 000043A0 */  sb         $v1, 0x0($v0)
    /* 3968 80106168 ACAA0392 */  lbu        $v1, %lo(_promptConfirmState)($s0)
    /* 396C 8010616C 080040A4 */  sh         $zero, 0x8($v0)
    /* 3970 80106170 01006324 */  addiu      $v1, $v1, 0x1
    /* 3974 80106174 B3180408 */  j          .L801062CC
    /* 3978 80106178 ACAA03A2 */   sb        $v1, %lo(_promptConfirmState)($s0)
  .L8010617C:
    /* 397C 8010617C C113040C */  jal        _fileMenuElementsActive
    /* 3980 80106180 00000000 */   nop
    /* 3984 80106184 ACAA0392 */  lbu        $v1, %lo(_promptConfirmState)($s0)
    /* 3988 80106188 00000000 */  nop
    /* 398C 8010618C 21186200 */  addu       $v1, $v1, $v0
    /* 3990 80106190 B3180408 */  j          .L801062CC
    /* 3994 80106194 ACAA03A2 */   sb        $v1, %lo(_promptConfirmState)($s0)
  .L80106198:
    /* 3998 80106198 1180023C */  lui        $v0, %hi(_fileMenuElements)
    /* 399C 8010619C 1180103C */  lui        $s0, %hi(_promptConfirmCancelled)
    /* 39A0 801061A0 ADAA0392 */  lbu        $v1, %lo(_promptConfirmCancelled)($s0)
    /* 39A4 801061A4 50AE4724 */  addiu      $a3, $v0, %lo(_fileMenuElements)
    /* 39A8 801061A8 03006324 */  addiu      $v1, $v1, 0x3
    /* 39AC 801061AC 40100300 */  sll        $v0, $v1, 1
    /* 39B0 801061B0 21104300 */  addu       $v0, $v0, $v1
    /* 39B4 801061B4 80100200 */  sll        $v0, $v0, 2
    /* 39B8 801061B8 21104300 */  addu       $v0, $v0, $v1
    /* 39BC 801061BC 80100200 */  sll        $v0, $v0, 2
    /* 39C0 801061C0 21104700 */  addu       $v0, $v0, $a3
    /* 39C4 801061C4 01000324 */  addiu      $v1, $zero, 0x1
    /* 39C8 801061C8 040043A0 */  sb         $v1, 0x4($v0)
    /* 39CC 801061CC ADAA0292 */  lbu        $v0, %lo(_promptConfirmCancelled)($s0)
    /* 39D0 801061D0 04000324 */  addiu      $v1, $zero, 0x4
    /* 39D4 801061D4 23186200 */  subu       $v1, $v1, $v0
    /* 39D8 801061D8 40100300 */  sll        $v0, $v1, 1
    /* 39DC 801061DC 21104300 */  addu       $v0, $v0, $v1
    /* 39E0 801061E0 80100200 */  sll        $v0, $v0, 2
    /* 39E4 801061E4 21104300 */  addu       $v0, $v0, $v1
    /* 39E8 801061E8 80100200 */  sll        $v0, $v0, 2
    /* 39EC 801061EC 21104700 */  addu       $v0, $v0, $a3
    /* 39F0 801061F0 040040A0 */  sb         $zero, 0x4($v0)
    /* 39F4 801061F4 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 39F8 801061F8 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 39FC 801061FC 00000000 */  nop
    /* 3A00 80106200 60004230 */  andi       $v0, $v0, 0x60
    /* 3A04 80106204 1F004010 */  beqz       $v0, .L80106284
    /* 3A08 80106208 1180023C */   lui       $v0, %hi(_selectCursorXy)
    /* 3A0C 8010620C A0B040AC */  sw         $zero, %lo(_selectCursorXy)($v0)
    /* 3A10 80106210 03000424 */  addiu      $a0, $zero, 0x3
    /* 3A14 80106214 04000624 */  addiu      $a2, $zero, 0x4
    /* 3A18 80106218 82FF0524 */  addiu      $a1, $zero, -0x7E
    /* 3A1C 8010621C 9C00E324 */  addiu      $v1, $a3, 0x9C
  .L80106220:
    /* 3A20 80106220 000066A0 */  sb         $a2, 0x0($v1)
    /* 3A24 80106224 080065A4 */  sh         $a1, 0x8($v1)
    /* 3A28 80106228 01008424 */  addiu      $a0, $a0, 0x1
    /* 3A2C 8010622C 05008228 */  slti       $v0, $a0, 0x5
    /* 3A30 80106230 FBFF4014 */  bnez       $v0, .L80106220
    /* 3A34 80106234 34006324 */   addiu     $v1, $v1, 0x34
    /* 3A38 80106238 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 3A3C 8010623C D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 3A40 80106240 00000000 */  nop
    /* 3A44 80106244 20004230 */  andi       $v0, $v0, 0x20
    /* 3A48 80106248 09004010 */  beqz       $v0, .L80106270
    /* 3A4C 8010624C 1180023C */   lui       $v0, %hi(_promptConfirmCancelled)
    /* 3A50 80106250 ADAA4290 */  lbu        $v0, %lo(_promptConfirmCancelled)($v0)
    /* 3A54 80106254 00000000 */  nop
    /* 3A58 80106258 06004014 */  bnez       $v0, .L80106274
    /* 3A5C 8010625C 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 3A60 80106260 6216010C */  jal        vs_main_playSfxDefault
    /* 3A64 80106264 05000524 */   addiu     $a1, $zero, 0x5
    /* 3A68 80106268 B4180408 */  j          .L801062D0
    /* 3A6C 8010626C 01000224 */   addiu     $v0, $zero, 0x1
  .L80106270:
    /* 3A70 80106270 7E000424 */  addiu      $a0, $zero, 0x7E
  .L80106274:
    /* 3A74 80106274 6216010C */  jal        vs_main_playSfxDefault
    /* 3A78 80106278 06000524 */   addiu     $a1, $zero, 0x6
    /* 3A7C 8010627C B4180408 */  j          .L801062D0
    /* 3A80 80106280 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L80106284:
    /* 3A84 80106284 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 3A88 80106288 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 3A8C 8010628C 00000000 */  nop
    /* 3A90 80106290 00504230 */  andi       $v0, $v0, 0x5000
    /* 3A94 80106294 07004010 */  beqz       $v0, .L801062B4
    /* 3A98 80106298 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 3A9C 8010629C 6216010C */  jal        vs_main_playSfxDefault
    /* 3AA0 801062A0 04000524 */   addiu     $a1, $zero, 0x4
    /* 3AA4 801062A4 ADAA0392 */  lbu        $v1, %lo(_promptConfirmCancelled)($s0)
    /* 3AA8 801062A8 01000224 */  addiu      $v0, $zero, 0x1
    /* 3AAC 801062AC 23104300 */  subu       $v0, $v0, $v1
    /* 3AB0 801062B0 ADAA02A2 */  sb         $v0, %lo(_promptConfirmCancelled)($s0)
  .L801062B4:
    /* 3AB4 801062B4 ADAA0292 */  lbu        $v0, %lo(_promptConfirmCancelled)($s0)
    /* 3AB8 801062B8 1180033C */  lui        $v1, %hi(_selectCursorXy)
    /* 3ABC 801062BC 00110200 */  sll        $v0, $v0, 4
    /* 3AC0 801062C0 0A004224 */  addiu      $v0, $v0, 0xA
    /* 3AC4 801062C4 00140200 */  sll        $v0, $v0, 16
    /* 3AC8 801062C8 A0B062AC */  sw         $v0, %lo(_selectCursorXy)($v1)
  .L801062CC:
    /* 3ACC 801062CC 21100000 */  addu       $v0, $zero, $zero
  .L801062D0:
    /* 3AD0 801062D0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 3AD4 801062D4 1000B08F */  lw         $s0, 0x10($sp)
    /* 3AD8 801062D8 0800E003 */  jr         $ra
    /* 3ADC 801062DC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _promptConfirm
