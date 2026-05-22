nonmatching _handleItemPaging, 0xB4

glabel _handleItemPaging
    /* 260 80102A60 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 264 80102A64 1000B0AF */  sw         $s0, 0x10($sp)
    /* 268 80102A68 2180A000 */  addu       $s0, $a1, $zero
    /* 26C 80102A6C 0680023C */  lui        $v0, %hi(vs_main_buttonsState)
    /* 270 80102A70 38E2428C */  lw         $v0, %lo(vs_main_buttonsState)($v0)
    /* 274 80102A74 0C000324 */  addiu      $v1, $zero, 0xC
    /* 278 80102A78 1800BFAF */  sw         $ra, 0x18($sp)
    /* 27C 80102A7C 0C004230 */  andi       $v0, $v0, 0xC
    /* 280 80102A80 1E004310 */  beq        $v0, $v1, .L80102AFC
    /* 284 80102A84 1400B1AF */   sw        $s1, 0x14($sp)
    /* 288 80102A88 21880002 */  addu       $s1, $s0, $zero
    /* 28C 80102A8C 9BFA030C */  jal        vs_mainMenu_getItemCount
    /* 290 80102A90 21280000 */   addu      $a1, $zero, $zero
    /* 294 80102A94 21284000 */  addu       $a1, $v0, $zero
    /* 298 80102A98 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 29C 80102A9C DCDF438C */  lw         $v1, %lo(vs_main_buttonRepeat)($v0)
    /* 2A0 80102AA0 00000000 */  nop
    /* 2A4 80102AA4 04006230 */  andi       $v0, $v1, 0x4
    /* 2A8 80102AA8 03004010 */  beqz       $v0, .L80102AB8
    /* 2AC 80102AAC 2120A000 */   addu      $a0, $a1, $zero
    /* 2B0 80102AB0 FFFF0226 */  addiu      $v0, $s0, -0x1
    /* 2B4 80102AB4 21804500 */  addu       $s0, $v0, $a1
  .L80102AB8:
    /* 2B8 80102AB8 08006230 */  andi       $v0, $v1, 0x8
    /* 2BC 80102ABC 03004010 */  beqz       $v0, .L80102ACC
    /* 2C0 80102AC0 2A100402 */   slt       $v0, $s0, $a0
    /* 2C4 80102AC4 01001026 */  addiu      $s0, $s0, 0x1
    /* 2C8 80102AC8 2A100402 */  slt        $v0, $s0, $a0
  .L80102ACC:
    /* 2CC 80102ACC 02004014 */  bnez       $v0, .L80102AD8
    /* 2D0 80102AD0 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 2D4 80102AD4 23800402 */  subu       $s0, $s0, $a0
  .L80102AD8:
    /* 2D8 80102AD8 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 2DC 80102ADC 00000000 */  nop
    /* 2E0 80102AE0 0C004230 */  andi       $v0, $v0, 0xC
    /* 2E4 80102AE4 06004010 */  beqz       $v0, .L80102B00
    /* 2E8 80102AE8 21100002 */   addu      $v0, $s0, $zero
    /* 2EC 80102AEC 04001116 */  bne        $s0, $s1, .L80102B00
    /* 2F0 80102AF0 00000000 */   nop
    /* 2F4 80102AF4 B800030C */  jal        vs_battle_playInvalidSfx
    /* 2F8 80102AF8 00000000 */   nop
  .L80102AFC:
    /* 2FC 80102AFC 21100002 */  addu       $v0, $s0, $zero
  .L80102B00:
    /* 300 80102B00 1800BF8F */  lw         $ra, 0x18($sp)
    /* 304 80102B04 1400B18F */  lw         $s1, 0x14($sp)
    /* 308 80102B08 1000B08F */  lw         $s0, 0x10($sp)
    /* 30C 80102B0C 0800E003 */  jr         $ra
    /* 310 80102B10 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _handleItemPaging
