nonmatching func_800CD158, 0x248

glabel func_800CD158
    /* 64958 800CD158 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 6495C 800CD15C 3400B7AF */  sw         $s7, 0x34($sp)
    /* 64960 800CD160 40180400 */  sll        $v1, $a0, 1
    /* 64964 800CD164 21186400 */  addu       $v1, $v1, $a0
    /* 64968 800CD168 00190300 */  sll        $v1, $v1, 4
    /* 6496C 800CD16C 0F80023C */  lui        $v0, %hi(vs_battle_textBoxes)
    /* 64970 800CD170 E04F4224 */  addiu      $v0, $v0, %lo(vs_battle_textBoxes)
    /* 64974 800CD174 3000B6AF */  sw         $s6, 0x30($sp)
    /* 64978 800CD178 21B06200 */  addu       $s6, $v1, $v0
    /* 6497C 800CD17C 0F80023C */  lui        $v0, %hi(D_800F51B8)
    /* 64980 800CD180 B851428C */  lw         $v0, %lo(D_800F51B8)($v0)
    /* 64984 800CD184 00210400 */  sll        $a0, $a0, 4
    /* 64988 800CD188 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 6498C 800CD18C 3800BEAF */  sw         $fp, 0x38($sp)
    /* 64990 800CD190 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 64994 800CD194 2800B4AF */  sw         $s4, 0x28($sp)
    /* 64998 800CD198 2400B3AF */  sw         $s3, 0x24($sp)
    /* 6499C 800CD19C 2000B2AF */  sw         $s2, 0x20($sp)
    /* 649A0 800CD1A0 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 649A4 800CD1A4 1800B0AF */  sw         $s0, 0x18($sp)
    /* 649A8 800CD1A8 1600D286 */  lh         $s2, 0x16($s6)
    /* 649AC 800CD1AC 21104400 */  addu       $v0, $v0, $a0
    /* 649B0 800CD1B0 04005524 */  addiu      $s5, $v0, 0x4
    /* 649B4 800CD1B4 0680023C */  lui        $v0, %hi(vs_main_frameBuf)
    /* 649B8 800CD1B8 10E2428C */  lw         $v0, %lo(vs_main_frameBuf)($v0)
    /* 649BC 800CD1BC 2A00C486 */  lh         $a0, 0x2A($s6)
    /* 649C0 800CD1C0 02004014 */  bnez       $v0, .L800CD1CC
    /* 649C4 800CD1C4 21B80000 */   addu      $s7, $zero, $zero
    /* 649C8 800CD1C8 40011724 */  addiu      $s7, $zero, 0x140
  .L800CD1CC:
    /* 649CC 800CD1CC 03004016 */  bnez       $s2, .L800CD1DC
    /* 649D0 800CD1D0 F0000224 */   addiu     $v0, $zero, 0xF0
    /* 649D4 800CD1D4 78340308 */  j          .L800CD1E0
    /* 649D8 800CD1D8 21908000 */   addu      $s2, $a0, $zero
  .L800CD1DC:
    /* 649DC 800CD1DC 23904400 */  subu       $s2, $v0, $a0
  .L800CD1E0:
    /* 649E0 800CD1E0 2100C392 */  lbu        $v1, 0x21($s6)
    /* 649E4 800CD1E4 00000000 */  nop
    /* 649E8 800CD1E8 40100300 */  sll        $v0, $v1, 1
    /* 649EC 800CD1EC 21104300 */  addu       $v0, $v0, $v1
    /* 649F0 800CD1F0 80100200 */  sll        $v0, $v0, 2
    /* 649F4 800CD1F4 21104300 */  addu       $v0, $v0, $v1
    /* 649F8 800CD1F8 FCFF8324 */  addiu      $v1, $a0, -0x4
    /* 649FC 800CD1FC 23A04300 */  subu       $s4, $v0, $v1
    /* 64A00 800CD200 1100822E */  sltiu      $v0, $s4, 0x11
    /* 64A04 800CD204 03004014 */  bnez       $v0, .L800CD214
    /* 64A08 800CD208 0400822E */   sltiu     $v0, $s4, 0x4
    /* 64A0C 800CD20C 88340308 */  j          .L800CD220
    /* 64A10 800CD210 10001424 */   addiu     $s4, $zero, 0x10
  .L800CD214:
    /* 64A14 800CD214 02004010 */  beqz       $v0, .L800CD220
    /* 64A18 800CD218 00000000 */   nop
    /* 64A1C 800CD21C 04001424 */  addiu      $s4, $zero, 0x4
  .L800CD220:
    /* 64A20 800CD220 33008012 */  beqz       $s4, .L800CD2F0
    /* 64A24 800CD224 21980000 */   addu      $s3, $zero, $zero
    /* 64A28 800CD228 0001E226 */  addiu      $v0, $s7, 0x100
    /* 64A2C 800CD22C 82110200 */  srl        $v0, $v0, 6
    /* 64A30 800CD230 00014234 */  ori        $v0, $v0, 0x100
    /* 64A34 800CD234 00E11E3C */  lui        $fp, (0xE1000000 >> 16)
    /* 64A38 800CD238 25105E00 */  or         $v0, $v0, $fp
    /* 64A3C 800CD23C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 64A40 800CD240 23809302 */  subu       $s0, $s4, $s3
  .L800CD244:
    /* 64A44 800CD244 C0811000 */  sll        $s0, $s0, 7
    /* 64A48 800CD248 01008226 */  addiu      $v0, $s4, 0x1
    /* 64A4C 800CD24C 1B000202 */  divu       $zero, $s0, $v0
    /* 64A50 800CD250 12800000 */  mflo       $s0
    /* 64A54 800CD254 008C1200 */  sll        $s1, $s2, 16
    /* 64A58 800CD258 00012536 */  ori        $a1, $s1, 0x100
    /* 64A5C 800CD25C 0100063C */  lui        $a2, (0x10040 >> 16)
    /* 64A60 800CD260 4000C634 */  ori        $a2, $a2, (0x10040 & 0xFFFF)
    /* 64A64 800CD264 2138A002 */  addu       $a3, $s5, $zero
    /* 64A68 800CD268 8C00030C */  jal        vs_battle_setSprite
    /* 64A6C 800CD26C 21200002 */   addu      $a0, $s0, $zero
    /* 64A70 800CD270 21184000 */  addu       $v1, $v0, $zero
    /* 64A74 800CD274 21200002 */  addu       $a0, $s0, $zero
    /* 64A78 800CD278 21282002 */  addu       $a1, $s1, $zero
    /* 64A7C 800CD27C 0100063C */  lui        $a2, (0x10100 >> 16)
    /* 64A80 800CD280 0001C634 */  ori        $a2, $a2, (0x10100 & 0xFFFF)
    /* 64A84 800CD284 2138A002 */  addu       $a3, $s5, $zero
    /* 64A88 800CD288 1000A88F */  lw         $t0, 0x10($sp)
    /* 64A8C 800CD28C 00821200 */  sll        $s0, $s2, 8
    /* 64A90 800CD290 100070AC */  sw         $s0, 0x10($v1)
    /* 64A94 800CD294 8C00030C */  jal        vs_battle_setSprite
    /* 64A98 800CD298 040068AC */   sw        $t0, 0x4($v1)
    /* 64A9C 800CD29C 21184000 */  addu       $v1, $v0, $zero
    /* 64AA0 800CD2A0 82111700 */  srl        $v0, $s7, 6
    /* 64AA4 800CD2A4 00014234 */  ori        $v0, $v0, 0x100
    /* 64AA8 800CD2A8 25105E00 */  or         $v0, $v0, $fp
    /* 64AAC 800CD2AC 040062AC */  sw         $v0, 0x4($v1)
    /* 64AB0 800CD2B0 8000422A */  slti       $v0, $s2, 0x80
    /* 64AB4 800CD2B4 06004010 */  beqz       $v0, .L800CD2D0
    /* 64AB8 800CD2B8 100070AC */   sw        $s0, 0x10($v1)
    /* 64ABC 800CD2BC FFFF5226 */  addiu      $s2, $s2, -0x1
    /* 64AC0 800CD2C0 0C004006 */  bltz       $s2, .L800CD2F4
    /* 64AC4 800CD2C4 8000422A */   slti      $v0, $s2, 0x80
    /* 64AC8 800CD2C8 B9340308 */  j          .L800CD2E4
    /* 64ACC 800CD2CC 01007326 */   addiu     $s3, $s3, 0x1
  .L800CD2D0:
    /* 64AD0 800CD2D0 01005226 */  addiu      $s2, $s2, 0x1
    /* 64AD4 800CD2D4 F000422A */  slti       $v0, $s2, 0xF0
    /* 64AD8 800CD2D8 06004010 */  beqz       $v0, .L800CD2F4
    /* 64ADC 800CD2DC 8000422A */   slti      $v0, $s2, 0x80
    /* 64AE0 800CD2E0 01007326 */  addiu      $s3, $s3, 0x1
  .L800CD2E4:
    /* 64AE4 800CD2E4 2B107402 */  sltu       $v0, $s3, $s4
    /* 64AE8 800CD2E8 D6FF4014 */  bnez       $v0, .L800CD244
    /* 64AEC 800CD2EC 23809302 */   subu      $s0, $s4, $s3
  .L800CD2F0:
    /* 64AF0 800CD2F0 8000422A */  slti       $v0, $s2, 0x80
  .L800CD2F4:
    /* 64AF4 800CD2F4 0B004010 */  beqz       $v0, .L800CD324
    /* 64AF8 800CD2F8 F000422A */   slti      $v0, $s2, 0xF0
    /* 64AFC 800CD2FC 1C004006 */  bltz       $s2, .L800CD370
    /* 64B00 800CD300 2120A002 */   addu      $a0, $s5, $zero
    /* 64B04 800CD304 0060053C */  lui        $a1, (0x60000000 >> 16)
    /* 64B08 800CD308 21300000 */  addu       $a2, $zero, $zero
    /* 64B0C 800CD30C 01004726 */  addiu      $a3, $s2, 0x1
    /* 64B10 800CD310 003C0700 */  sll        $a3, $a3, 16
    /* 64B14 800CD314 2E33030C */  jal        func_800CCCB8
    /* 64B18 800CD318 4001E734 */   ori       $a3, $a3, 0x140
    /* 64B1C 800CD31C DC340308 */  j          .L800CD370
    /* 64B20 800CD320 00000000 */   nop
  .L800CD324:
    /* 64B24 800CD324 07004010 */  beqz       $v0, .L800CD344
    /* 64B28 800CD328 2120A002 */   addu      $a0, $s5, $zero
    /* 64B2C 800CD32C 0060053C */  lui        $a1, (0x60000000 >> 16)
    /* 64B30 800CD330 00341200 */  sll        $a2, $s2, 16
    /* 64B34 800CD334 F000073C */  lui        $a3, (0xF00000 >> 16)
    /* 64B38 800CD338 2338E600 */  subu       $a3, $a3, $a2
    /* 64B3C 800CD33C 2E33030C */  jal        func_800CCCB8
    /* 64B40 800CD340 4001E734 */   ori       $a3, $a3, 0x140
  .L800CD344:
    /* 64B44 800CD344 2200C292 */  lbu        $v0, 0x22($s6)
    /* 64B48 800CD348 1C00C386 */  lh         $v1, 0x1C($s6)
    /* 64B4C 800CD34C 01004224 */  addiu      $v0, $v0, 0x1
    /* 64B50 800CD350 07006214 */  bne        $v1, $v0, .L800CD370
    /* 64B54 800CD354 F9FF4426 */   addiu     $a0, $s2, -0x7
    /* 64B58 800CD358 0000C58E */  lw         $a1, 0x0($s6)
    /* 64B5C 800CD35C 00000000 */  nop
    /* 64B60 800CD360 022A0500 */  srl        $a1, $a1, 8
    /* 64B64 800CD364 0F00A530 */  andi       $a1, $a1, 0xF
    /* 64B68 800CD368 3F34030C */  jal        func_800CD0FC
    /* 64B6C 800CD36C FFFFA524 */   addiu     $a1, $a1, -0x1
  .L800CD370:
    /* 64B70 800CD370 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 64B74 800CD374 3800BE8F */  lw         $fp, 0x38($sp)
    /* 64B78 800CD378 3400B78F */  lw         $s7, 0x34($sp)
    /* 64B7C 800CD37C 3000B68F */  lw         $s6, 0x30($sp)
    /* 64B80 800CD380 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 64B84 800CD384 2800B48F */  lw         $s4, 0x28($sp)
    /* 64B88 800CD388 2400B38F */  lw         $s3, 0x24($sp)
    /* 64B8C 800CD38C 2000B28F */  lw         $s2, 0x20($sp)
    /* 64B90 800CD390 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 64B94 800CD394 1800B08F */  lw         $s0, 0x18($sp)
    /* 64B98 800CD398 0800E003 */  jr         $ra
    /* 64B9C 800CD39C 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_800CD158
