nonmatching func_800AD62C, 0xE8

glabel func_800AD62C
    /* 44E2C 800AD62C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 44E30 800AD630 1800B2AF */  sw         $s2, 0x18($sp)
    /* 44E34 800AD634 2190A000 */  addu       $s2, $a1, $zero
    /* 44E38 800AD638 0F80033C */  lui        $v1, %hi(D_800F4538)
    /* 44E3C 800AD63C 38456324 */  addiu      $v1, $v1, %lo(D_800F4538)
    /* 44E40 800AD640 80100400 */  sll        $v0, $a0, 2
    /* 44E44 800AD644 21104300 */  addu       $v0, $v0, $v1
    /* 44E48 800AD648 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 44E4C 800AD64C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 44E50 800AD650 1000B0AF */  sw         $s0, 0x10($sp)
    /* 44E54 800AD654 0000508C */  lw         $s0, 0x0($v0)
    /* 44E58 800AD658 00000000 */  nop
    /* 44E5C 800AD65C E4170392 */  lbu        $v1, 0x17E4($s0)
    /* 44E60 800AD660 02000224 */  addiu      $v0, $zero, 0x2
    /* 44E64 800AD664 06006214 */  bne        $v1, $v0, .L800AD680
    /* 44E68 800AD668 2188C000 */   addu      $s1, $a2, $zero
    /* 44E6C 800AD66C 80000224 */  addiu      $v0, $zero, 0x80
    /* 44E70 800AD670 21002012 */  beqz       $s1, .L800AD6F8
    /* 44E74 800AD674 000042AE */   sw        $v0, 0x0($s2)
    /* 44E78 800AD678 BEB50208 */  j          .L800AD6F8
    /* 44E7C 800AD67C 000020AE */   sw        $zero, 0x0($s1)
  .L800AD680:
    /* 44E80 800AD680 3F00023C */  lui        $v0, (0x3F9F00 >> 16)
    /* 44E84 800AD684 0800038E */  lw         $v1, 0x8($s0)
    /* 44E88 800AD688 009F4234 */  ori        $v0, $v0, (0x3F9F00 & 0xFFFF)
    /* 44E8C 800AD68C 24186200 */  and        $v1, $v1, $v0
    /* 44E90 800AD690 00800234 */  ori        $v0, $zero, 0x8000
    /* 44E94 800AD694 04006210 */  beq        $v1, $v0, .L800AD6A8
    /* 44E98 800AD698 FF000524 */   addiu     $a1, $zero, 0xFF
    /* 44E9C 800AD69C FC060626 */  addiu      $a2, $s0, 0x6FC
    /* 44EA0 800AD6A0 A084020C */  jal        func_800A1280
    /* 44EA4 800AD6A4 21380000 */   addu      $a3, $zero, $zero
  .L800AD6A8:
    /* 44EA8 800AD6A8 FC06048E */  lw         $a0, 0x6FC($s0)
    /* 44EAC 800AD6AC 00070586 */  lh         $a1, 0x700($s0)
    /* 44EB0 800AD6B0 6B16010C */  jal        vs_main_computeSfxPan
    /* 44EB4 800AD6B4 00000000 */   nop
    /* 44EB8 800AD6B8 21184000 */  addu       $v1, $v0, $zero
    /* 44EBC 800AD6BC 03140300 */  sra        $v0, $v1, 16
    /* 44EC0 800AD6C0 000042AE */  sw         $v0, 0x0($s2)
    /* 44EC4 800AD6C4 E5170292 */  lbu        $v0, 0x17E5($s0)
    /* 44EC8 800AD6C8 00000000 */  nop
    /* 44ECC 800AD6CC 02004010 */  beqz       $v0, .L800AD6D8
    /* 44ED0 800AD6D0 00000000 */   nop
    /* 44ED4 800AD6D4 000042AE */  sw         $v0, 0x0($s2)
  .L800AD6D8:
    /* 44ED8 800AD6D8 07002012 */  beqz       $s1, .L800AD6F8
    /* 44EDC 800AD6DC FFFF6230 */   andi      $v0, $v1, 0xFFFF
    /* 44EE0 800AD6E0 000022AE */  sw         $v0, 0x0($s1)
    /* 44EE4 800AD6E4 E6170292 */  lbu        $v0, 0x17E6($s0)
    /* 44EE8 800AD6E8 00000000 */  nop
    /* 44EEC 800AD6EC 02004010 */  beqz       $v0, .L800AD6F8
    /* 44EF0 800AD6F0 00000000 */   nop
    /* 44EF4 800AD6F4 000022AE */  sw         $v0, 0x0($s1)
  .L800AD6F8:
    /* 44EF8 800AD6F8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 44EFC 800AD6FC 1800B28F */  lw         $s2, 0x18($sp)
    /* 44F00 800AD700 1400B18F */  lw         $s1, 0x14($sp)
    /* 44F04 800AD704 1000B08F */  lw         $s0, 0x10($sp)
    /* 44F08 800AD708 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 44F0C 800AD70C 0800E003 */  jr         $ra
    /* 44F10 800AD710 00000000 */   nop
endlabel func_800AD62C
