nonmatching vs_main_padConnect, 0xD0

glabel vs_main_padConnect
    /* 33A50 80043250 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 33A54 80043254 3000B2AF */  sw         $s2, 0x30($sp)
    /* 33A58 80043258 21908000 */  addu       $s2, $a0, $zero
    /* 33A5C 8004325C 3800B4AF */  sw         $s4, 0x38($sp)
    /* 33A60 80043260 21A0A000 */  addu       $s4, $a1, $zero
    /* 33A64 80043264 03111200 */  sra        $v0, $s2, 4
    /* 33A68 80043268 40180200 */  sll        $v1, $v0, 1
    /* 33A6C 8004326C 21186200 */  addu       $v1, $v1, $v0
    /* 33A70 80043270 80180300 */  sll        $v1, $v1, 2
    /* 33A74 80043274 23186200 */  subu       $v1, $v1, $v0
    /* 33A78 80043278 0580023C */  lui        $v0, %hi(_portInfo)
    /* 33A7C 8004327C 90014224 */  addiu      $v0, $v0, %lo(_portInfo)
    /* 33A80 80043280 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 33A84 80043284 21886200 */  addu       $s1, $v1, $v0
    /* 33A88 80043288 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 33A8C 8004328C 3400B3AF */  sw         $s3, 0x34($sp)
    /* 33A90 80043290 24AE000C */  jal        PadGetState
    /* 33A94 80043294 2800B0AF */   sw        $s0, 0x28($sp)
    /* 33A98 80043298 21804000 */  addu       $s0, $v0, $zero
    /* 33A9C 8004329C 01001324 */  addiu      $s3, $zero, 0x1
    /* 33AA0 800432A0 02001316 */  bne        $s0, $s3, .L800432AC
    /* 33AA4 800432A4 00000000 */   nop
    /* 33AA8 800432A8 0A0020A2 */  sb         $zero, 0xA($s1)
  .L800432AC:
    /* 33AAC 800432AC 0A002292 */  lbu        $v0, 0xA($s1)
    /* 33AB0 800432B0 00000000 */  nop
    /* 33AB4 800432B4 12004014 */  bnez       $v0, .L80043300
    /* 33AB8 800432B8 21204002 */   addu      $a0, $s2, $zero
    /* 33ABC 800432BC 08002526 */  addiu      $a1, $s1, 0x8
    /* 33AC0 800432C0 14AF000C */  jal        PadSetAct
    /* 33AC4 800432C4 02000624 */   addiu     $a2, $zero, 0x2
    /* 33AC8 800432C8 02000224 */  addiu      $v0, $zero, 0x2
    /* 33ACC 800432CC 08000212 */  beq        $s0, $v0, .L800432F0
    /* 33AD0 800432D0 06000224 */   addiu     $v0, $zero, 0x6
    /* 33AD4 800432D4 0A000216 */  bne        $s0, $v0, .L80043300
    /* 33AD8 800432D8 21204002 */   addu      $a0, $s2, $zero
    /* 33ADC 800432DC 0580053C */  lui        $a1, %hi(_actParams)
    /* 33AE0 800432E0 F4AE000C */  jal        PadSetActAlign
    /* 33AE4 800432E4 1CA5A524 */   addiu     $a1, $a1, %lo(_actParams)
    /* 33AE8 800432E8 05004010 */  beqz       $v0, .L80043300
    /* 33AEC 800432EC 00000000 */   nop
  .L800432F0:
    /* 33AF0 800432F0 21204002 */  addu       $a0, $s2, $zero
    /* 33AF4 800432F4 0D0C010C */  jal        _padResetDefaults
    /* 33AF8 800432F8 21288002 */   addu      $a1, $s4, $zero
    /* 33AFC 800432FC 0A0033A2 */  sb         $s3, 0xA($s1)
  .L80043300:
    /* 33B00 80043300 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 33B04 80043304 3800B48F */  lw         $s4, 0x38($sp)
    /* 33B08 80043308 3400B38F */  lw         $s3, 0x34($sp)
    /* 33B0C 8004330C 3000B28F */  lw         $s2, 0x30($sp)
    /* 33B10 80043310 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 33B14 80043314 2800B08F */  lw         $s0, 0x28($sp)
    /* 33B18 80043318 0800E003 */  jr         $ra
    /* 33B1C 8004331C 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel vs_main_padConnect
