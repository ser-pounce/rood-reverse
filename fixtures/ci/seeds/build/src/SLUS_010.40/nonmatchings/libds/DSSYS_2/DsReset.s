nonmatching DsReset, 0x10C

glabel DsReset
    /* 14208 80023A08 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1420C 80023A0C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 14210 80023A10 1400B1AF */  sw         $s1, 0x14($sp)
    /* 14214 80023A14 B895000C */  jal        DS_stop
    /* 14218 80023A18 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1421C 80023A1C 21180000 */  addu       $v1, $zero, $zero
    /* 14220 80023A20 0480023C */  lui        $v0, %hi(D_80039E60)
    /* 14224 80023A24 609E4224 */  addiu      $v0, $v0, %lo(D_80039E60)
    /* 14228 80023A28 000040AC */  sw         $zero, 0x0($v0)
    /* 1422C 80023A2C 040040AC */  sw         $zero, 0x4($v0)
    /* 14230 80023A30 080040AC */  sw         $zero, 0x8($v0)
    /* 14234 80023A34 0480023C */  lui        $v0, %hi(D_80039CC0)
    /* 14238 80023A38 C09C4224 */  addiu      $v0, $v0, %lo(D_80039CC0)
    /* 1423C 80023A3C 200040AC */  sw         $zero, 0x20($v0)
    /* 14240 80023A40 100040AC */  sw         $zero, 0x10($v0)
    /* 14244 80023A44 000040AC */  sw         $zero, 0x0($v0)
    /* 14248 80023A48 240040A0 */  sb         $zero, 0x24($v0)
    /* 1424C 80023A4C 140040A0 */  sb         $zero, 0x14($v0)
    /* 14250 80023A50 040040A0 */  sb         $zero, 0x4($v0)
  .L80023A54:
    /* 14254 80023A54 0480013C */  lui        $at, %hi(D_80039CC5)
    /* 14258 80023A58 21082300 */  addu       $at, $at, $v1
    /* 1425C 80023A5C C59C20A0 */  sb         $zero, %lo(D_80039CC5)($at)
    /* 14260 80023A60 0480013C */  lui        $at, %hi(D_80039CD5)
    /* 14264 80023A64 21082300 */  addu       $at, $at, $v1
    /* 14268 80023A68 D59C20A0 */  sb         $zero, %lo(D_80039CD5)($at)
    /* 1426C 80023A6C 0480013C */  lui        $at, %hi(D_80039CE5)
    /* 14270 80023A70 21082300 */  addu       $at, $at, $v1
    /* 14274 80023A74 E59C20A0 */  sb         $zero, %lo(D_80039CE5)($at)
    /* 14278 80023A78 01006324 */  addiu      $v1, $v1, 0x1
    /* 1427C 80023A7C 08006228 */  slti       $v0, $v1, 0x8
    /* 14280 80023A80 F4FF4014 */  bnez       $v0, .L80023A54
    /* 14284 80023A84 21880000 */   addu      $s1, $zero, $zero
    /* 14288 80023A88 0480103C */  lui        $s0, %hi(D_80039CF0)
    /* 1428C 80023A8C F09C1026 */  addiu      $s0, $s0, %lo(D_80039CF0)
  .L80023A90:
    /* 14290 80023A90 798C000C */  jal        func_800231E4
    /* 14294 80023A94 21200002 */   addu      $a0, $s0, $zero
    /* 14298 80023A98 01003126 */  addiu      $s1, $s1, 0x1
    /* 1429C 80023A9C 0800222A */  slti       $v0, $s1, 0x8
    /* 142A0 80023AA0 FBFF4014 */  bnez       $v0, .L80023A90
    /* 142A4 80023AA4 18001026 */   addiu     $s0, $s0, 0x18
    /* 142A8 80023AA8 07000324 */  addiu      $v1, $zero, 0x7
    /* 142AC 80023AAC 70000224 */  addiu      $v0, $zero, 0x70
    /* 142B0 80023AB0 0480013C */  lui        $at, %hi(D_80039DB4)
    /* 142B4 80023AB4 B49D20AC */  sw         $zero, %lo(D_80039DB4)($at)
    /* 142B8 80023AB8 0480013C */  lui        $at, %hi(D_80039DB0)
    /* 142BC 80023ABC B09D20AC */  sw         $zero, %lo(D_80039DB0)($at)
    /* 142C0 80023AC0 0480013C */  lui        $at, %hi(D_80039DB8)
    /* 142C4 80023AC4 B89D20AC */  sw         $zero, %lo(D_80039DB8)($at)
  .L80023AC8:
    /* 142C8 80023AC8 0480013C */  lui        $at, %hi(D_80039DC0)
    /* 142CC 80023ACC 21082200 */  addu       $at, $at, $v0
    /* 142D0 80023AD0 C09D20AC */  sw         $zero, %lo(D_80039DC0)($at)
    /* 142D4 80023AD4 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 142D8 80023AD8 FBFF6104 */  bgez       $v1, .L80023AC8
    /* 142DC 80023ADC F0FF4224 */   addiu     $v0, $v0, -0x10
    /* 142E0 80023AE0 0480013C */  lui        $at, %hi(D_80039E40)
    /* 142E4 80023AE4 EB99000C */  jal        ER_clear
    /* 142E8 80023AE8 409E20AC */   sw        $zero, %lo(D_80039E40)($at)
    /* 142EC 80023AEC D398000C */  jal        DsReadySystemMode
    /* 142F0 80023AF0 21200000 */   addu      $a0, $zero, $zero
    /* 142F4 80023AF4 D695000C */  jal        DS_restart
    /* 142F8 80023AF8 00000000 */   nop
    /* 142FC 80023AFC 01000224 */  addiu      $v0, $zero, 0x1
    /* 14300 80023B00 1800BF8F */  lw         $ra, 0x18($sp)
    /* 14304 80023B04 1400B18F */  lw         $s1, 0x14($sp)
    /* 14308 80023B08 1000B08F */  lw         $s0, 0x10($sp)
    /* 1430C 80023B0C 0800E003 */  jr         $ra
    /* 14310 80023B10 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel DsReset
