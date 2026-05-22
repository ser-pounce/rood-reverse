nonmatching vs_battle_initialiseCameraFromSpherical, 0x104

glabel vs_battle_initialiseCameraFromSpherical
    /* 14570 8007CD70 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 14574 8007CD74 2400B1AF */  sw         $s1, 0x24($sp)
    /* 14578 8007CD78 21888000 */  addu       $s1, $a0, $zero
    /* 1457C 8007CD7C 2000B0AF */  sw         $s0, 0x20($sp)
    /* 14580 8007CD80 2180A000 */  addu       $s0, $a1, $zero
    /* 14584 8007CD84 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 14588 8007CD88 0C00C210 */  beq        $a2, $v0, .L8007CDBC
    /* 1458C 8007CD8C 2800BFAF */   sw        $ra, 0x28($sp)
    /* 14590 8007CD90 2110C000 */  addu       $v0, $a2, $zero
    /* 14594 8007CD94 0F80033C */  lui        $v1, %hi(vs_battle_cameraCurrentSpherical)
    /* 14598 8007CD98 0200C104 */  bgez       $a2, .L8007CDA4
    /* 1459C 8007CD9C D0196424 */   addiu     $a0, $v1, %lo(vs_battle_cameraCurrentSpherical)
    /* 145A0 8007CDA0 0700C224 */  addiu      $v0, $a2, 0x7
  .L8007CDA4:
    /* 145A4 8007CDA4 C3100200 */  sra        $v0, $v0, 3
    /* 145A8 8007CDA8 C0100200 */  sll        $v0, $v0, 3
    /* 145AC 8007CDAC 2310C200 */  subu       $v0, $a2, $v0
    /* 145B0 8007CDB0 40120200 */  sll        $v0, $v0, 9
    /* 145B4 8007CDB4 140082AC */  sw         $v0, 0x14($a0)
    /* 145B8 8007CDB8 D01962AC */  sw         $v0, %lo(vs_battle_cameraCurrentSpherical)($v1)
  .L8007CDBC:
    /* 145BC 8007CDBC 01000224 */  addiu      $v0, $zero, 0x1
    /* 145C0 8007CDC0 0800E214 */  bne        $a3, $v0, .L8007CDE4
    /* 145C4 8007CDC4 02000224 */   addiu     $v0, $zero, 0x2
    /* 145C8 8007CDC8 0F80023C */  lui        $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 145CC 8007CDCC D0194224 */  addiu      $v0, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* 145D0 8007CDD0 00060324 */  addiu      $v1, $zero, 0x600
    /* 145D4 8007CDD4 200043AC */  sw         $v1, 0x20($v0)
    /* 145D8 8007CDD8 080043AC */  sw         $v1, 0x8($v0)
    /* 145DC 8007CDDC 81F30108 */  j          .L8007CE04
    /* 145E0 8007CDE0 1C0040AC */   sw        $zero, 0x1C($v0)
  .L8007CDE4:
    /* 145E4 8007CDE4 0800E214 */  bne        $a3, $v0, .L8007CE08
    /* 145E8 8007CDE8 21200000 */   addu      $a0, $zero, $zero
    /* 145EC 8007CDEC 0F80023C */  lui        $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 145F0 8007CDF0 D0194224 */  addiu      $v0, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* 145F4 8007CDF4 00090324 */  addiu      $v1, $zero, 0x900
    /* 145F8 8007CDF8 200043AC */  sw         $v1, 0x20($v0)
    /* 145FC 8007CDFC 080043AC */  sw         $v1, 0x8($v0)
    /* 14600 8007CE00 1C0047AC */  sw         $a3, 0x1C($v0)
  .L8007CE04:
    /* 14604 8007CE04 21200000 */  addu       $a0, $zero, $zero
  .L8007CE08:
    /* 14608 8007CE08 4284020C */  jal        func_800A1108
    /* 1460C 8007CE0C 1000A527 */   addiu     $a1, $sp, 0x10
    /* 14610 8007CE10 FAFF033C */  lui        $v1, (0xFFFA6000 >> 16)
    /* 14614 8007CE14 1400A287 */  lh         $v0, 0x14($sp)
    /* 14618 8007CE18 00606334 */  ori        $v1, $v1, (0xFFFA6000 & 0xFFFF)
    /* 1461C 8007CE1C 00130200 */  sll        $v0, $v0, 12
    /* 14620 8007CE20 000002AE */  sw         $v0, 0x0($s0)
    /* 14624 8007CE24 1600A287 */  lh         $v0, 0x16($sp)
    /* 14628 8007CE28 21200002 */  addu       $a0, $s0, $zero
    /* 1462C 8007CE2C 00130200 */  sll        $v0, $v0, 12
    /* 14630 8007CE30 21104300 */  addu       $v0, $v0, $v1
    /* 14634 8007CE34 040002AE */  sw         $v0, 0x4($s0)
    /* 14638 8007CE38 1800A287 */  lh         $v0, 0x18($sp)
    /* 1463C 8007CE3C 21280002 */  addu       $a1, $s0, $zero
    /* 14640 8007CE40 00130200 */  sll        $v0, $v0, 12
    /* 14644 8007CE44 7FB6010C */  jal        _clampPositionToZoneBounds
    /* 14648 8007CE48 080002AE */   sw        $v0, 0x8($s0)
    /* 1464C 8007CE4C 21202002 */  addu       $a0, $s1, $zero
    /* 14650 8007CE50 21280002 */  addu       $a1, $s0, $zero
    /* 14654 8007CE54 0F80063C */  lui        $a2, %hi(vs_battle_cameraCurrentSpherical)
    /* 14658 8007CE58 77EA010C */  jal        _computeSphericalOffset
    /* 1465C 8007CE5C D019C624 */   addiu     $a2, $a2, %lo(vs_battle_cameraCurrentSpherical)
    /* 14660 8007CE60 2800BF8F */  lw         $ra, 0x28($sp)
    /* 14664 8007CE64 2400B18F */  lw         $s1, 0x24($sp)
    /* 14668 8007CE68 2000B08F */  lw         $s0, 0x20($sp)
    /* 1466C 8007CE6C 0800E003 */  jr         $ra
    /* 14670 8007CE70 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel vs_battle_initialiseCameraFromSpherical
