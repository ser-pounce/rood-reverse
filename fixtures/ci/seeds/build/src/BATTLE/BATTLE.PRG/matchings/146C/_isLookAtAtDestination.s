nonmatching _isLookAtAtDestination, 0xD4

glabel _isLookAtAtDestination
    /* F5F0 80077DF0 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* F5F4 80077DF4 21200000 */  addu       $a0, $zero, $zero
    /* F5F8 80077DF8 4000BFAF */  sw         $ra, 0x40($sp)
    /* F5FC 80077DFC 4284020C */  jal        func_800A1108
    /* F600 80077E00 3000A527 */   addiu     $a1, $sp, 0x30
    /* F604 80077E04 FAFF043C */  lui        $a0, (0xFFFA6000 >> 16)
    /* F608 80077E08 00608434 */  ori        $a0, $a0, (0xFFFA6000 & 0xFFFF)
    /* F60C 80077E0C 3400A287 */  lh         $v0, 0x34($sp)
    /* F610 80077E10 3600A387 */  lh         $v1, 0x36($sp)
    /* F614 80077E14 00130200 */  sll        $v0, $v0, 12
    /* F618 80077E18 001B0300 */  sll        $v1, $v1, 12
    /* F61C 80077E1C 1000A2AF */  sw         $v0, 0x10($sp)
    /* F620 80077E20 3800A287 */  lh         $v0, 0x38($sp)
    /* F624 80077E24 21186400 */  addu       $v1, $v1, $a0
    /* F628 80077E28 1400A3AF */  sw         $v1, 0x14($sp)
    /* F62C 80077E2C 00130200 */  sll        $v0, $v0, 12
    /* F630 80077E30 02006018 */  blez       $v1, .L80077E3C
    /* F634 80077E34 1800A2AF */   sw        $v0, 0x18($sp)
    /* F638 80077E38 1400A0AF */  sw         $zero, 0x14($sp)
  .L80077E3C:
    /* F63C 80077E3C 1000A427 */  addiu      $a0, $sp, 0x10
    /* F640 80077E40 7FB6010C */  jal        _clampPositionToZoneBounds
    /* F644 80077E44 21288000 */   addu      $a1, $a0, $zero
    /* F648 80077E48 801F023C */  lui        $v0, %hi(D_1F800000)
    /* F64C 80077E4C 00004224 */  addiu      $v0, $v0, %lo(D_1F800000)
    /* F650 80077E50 00F00524 */  addiu      $a1, $zero, -0x1000
    /* F654 80077E54 4400468C */  lw         $a2, 0x44($v0)
    /* F658 80077E58 4800478C */  lw         $a3, 0x48($v0)
    /* F65C 80077E5C 4C00488C */  lw         $t0, 0x4C($v0)
    /* F660 80077E60 5000498C */  lw         $t1, 0x50($v0)
    /* F664 80077E64 2000A6AF */  sw         $a2, 0x20($sp)
    /* F668 80077E68 2400A7AF */  sw         $a3, 0x24($sp)
    /* F66C 80077E6C 2800A8AF */  sw         $t0, 0x28($sp)
    /* F670 80077E70 2C00A9AF */  sw         $t1, 0x2C($sp)
    /* F674 80077E74 2000A28F */  lw         $v0, 0x20($sp)
    /* F678 80077E78 1000A38F */  lw         $v1, 0x10($sp)
    /* F67C 80077E7C 24104500 */  and        $v0, $v0, $a1
    /* F680 80077E80 0C006214 */  bne        $v1, $v0, .L80077EB4
    /* F684 80077E84 21100000 */   addu      $v0, $zero, $zero
    /* F688 80077E88 2800A28F */  lw         $v0, 0x28($sp)
    /* F68C 80077E8C 1800A38F */  lw         $v1, 0x18($sp)
    /* F690 80077E90 24104500 */  and        $v0, $v0, $a1
    /* F694 80077E94 07006214 */  bne        $v1, $v0, .L80077EB4
    /* F698 80077E98 21100000 */   addu      $v0, $zero, $zero
    /* F69C 80077E9C 2400A38F */  lw         $v1, 0x24($sp)
    /* F6A0 80077EA0 1400A48F */  lw         $a0, 0x14($sp)
    /* F6A4 80077EA4 24186500 */  and        $v1, $v1, $a1
    /* F6A8 80077EA8 02008310 */  beq        $a0, $v1, .L80077EB4
    /* F6AC 80077EAC 01000224 */   addiu     $v0, $zero, 0x1
    /* F6B0 80077EB0 21100000 */  addu       $v0, $zero, $zero
  .L80077EB4:
    /* F6B4 80077EB4 4000BF8F */  lw         $ra, 0x40($sp)
    /* F6B8 80077EB8 00000000 */  nop
    /* F6BC 80077EBC 0800E003 */  jr         $ra
    /* F6C0 80077EC0 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel _isLookAtAtDestination
