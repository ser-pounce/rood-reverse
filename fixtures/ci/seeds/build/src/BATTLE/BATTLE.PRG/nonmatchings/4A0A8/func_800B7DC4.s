nonmatching func_800B7DC4, 0x12C

glabel func_800B7DC4
    /* 4F5C4 800B7DC4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 4F5C8 800B7DC8 2000B0AF */  sw         $s0, 0x20($sp)
    /* 4F5CC 800B7DCC 21808000 */  addu       $s0, $a0, $zero
    /* 4F5D0 800B7DD0 01000426 */  addiu      $a0, $s0, 0x1
    /* 4F5D4 800B7DD4 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 4F5D8 800B7DD8 2800B2AF */  sw         $s2, 0x28($sp)
    /* 4F5DC 800B7DDC 80FF020C */  jal        vs_battle_getShort
    /* 4F5E0 800B7DE0 2400B1AF */   sw        $s1, 0x24($sp)
    /* 4F5E4 800B7DE4 94FF020C */  jal        func_800BFE50
    /* 4F5E8 800B7DE8 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4F5EC 800B7DEC 21884000 */  addu       $s1, $v0, $zero
    /* 4F5F0 800B7DF0 05000392 */  lbu        $v1, 0x5($s0)
    /* 4F5F4 800B7DF4 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 4F5F8 800B7DF8 02006210 */  beq        $v1, $v0, .L800B7E04
    /* 4F5FC 800B7DFC FFFF1224 */   addiu     $s2, $zero, -0x1
    /* 4F600 800B7E00 05001292 */  lbu        $s2, 0x5($s0)
  .L800B7E04:
    /* 4F604 800B7E04 04000292 */  lbu        $v0, 0x4($s0)
    /* 4F608 800B7E08 00000000 */  nop
    /* 4F60C 800B7E0C 26004010 */  beqz       $v0, .L800B7EA8
    /* 4F610 800B7E10 FFFF2432 */   andi      $a0, $s1, 0xFFFF
    /* 4F614 800B7E14 4284020C */  jal        func_800A1108
    /* 4F618 800B7E18 1000A527 */   addiu     $a1, $sp, 0x10
    /* 4F61C 800B7E1C 03000292 */  lbu        $v0, 0x3($s0)
    /* 4F620 800B7E20 1A00A387 */  lh         $v1, 0x1A($sp)
    /* 4F624 800B7E24 00110200 */  sll        $v0, $v0, 4
    /* 4F628 800B7E28 23284300 */  subu       $a1, $v0, $v1
    /* 4F62C 800B7E2C 00F8A228 */  slti       $v0, $a1, -0x800
    /* 4F630 800B7E30 03004010 */  beqz       $v0, .L800B7E40
    /* 4F634 800B7E34 0108A228 */   slti      $v0, $a1, 0x801
    /* 4F638 800B7E38 0010A524 */  addiu      $a1, $a1, 0x1000
    /* 4F63C 800B7E3C 0108A228 */  slti       $v0, $a1, 0x801
  .L800B7E40:
    /* 4F640 800B7E40 02004014 */  bnez       $v0, .L800B7E4C
    /* 4F644 800B7E44 00000000 */   nop
    /* 4F648 800B7E48 00F0A524 */  addiu      $a1, $a1, -0x1000
  .L800B7E4C:
    /* 4F64C 800B7E4C 04000482 */  lb         $a0, 0x4($s0)
    /* 4F650 800B7E50 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 4F654 800B7E54 05008210 */  beq        $a0, $v0, .L800B7E6C
    /* 4F658 800B7E58 01000224 */   addiu     $v0, $zero, 0x1
    /* 4F65C 800B7E5C 07008210 */  beq        $a0, $v0, .L800B7E7C
    /* 4F660 800B7E60 FFFF2432 */   andi      $a0, $s1, 0xFFFF
    /* 4F664 800B7E64 A4DF0208 */  j          .L800B7E90
    /* 4F668 800B7E68 002C0500 */   sll       $a1, $a1, 16
  .L800B7E6C:
    /* 4F66C 800B7E6C 0700A018 */  blez       $a1, .L800B7E8C
    /* 4F670 800B7E70 FFFF2432 */   andi      $a0, $s1, 0xFFFF
    /* 4F674 800B7E74 A3DF0208 */  j          .L800B7E8C
    /* 4F678 800B7E78 00F0A524 */   addiu     $a1, $a1, -0x1000
  .L800B7E7C:
    /* 4F67C 800B7E7C 0300A104 */  bgez       $a1, .L800B7E8C
    /* 4F680 800B7E80 00000000 */   nop
    /* 4F684 800B7E84 0010A524 */  addiu      $a1, $a1, 0x1000
    /* 4F688 800B7E88 FFFF2432 */  andi       $a0, $s1, 0xFFFF
  .L800B7E8C:
    /* 4F68C 800B7E8C 002C0500 */  sll        $a1, $a1, 16
  .L800B7E90:
    /* 4F690 800B7E90 032C0500 */  sra        $a1, $a1, 16
    /* 4F694 800B7E94 00341200 */  sll        $a2, $s2, 16
    /* 4F698 800B7E98 8EA7020C */  jal        func_800A9E38
    /* 4F69C 800B7E9C 03340600 */   sra       $a2, $a2, 16
    /* 4F6A0 800B7EA0 B0DF0208 */  j          .L800B7EC0
    /* 4F6A4 800B7EA4 0F80023C */   lui       $v0, %hi(D_800F4B70)
  .L800B7EA8:
    /* 4F6A8 800B7EA8 03000592 */  lbu        $a1, 0x3($s0)
    /* 4F6AC 800B7EAC 00341200 */  sll        $a2, $s2, 16
    /* 4F6B0 800B7EB0 03340600 */  sra        $a2, $a2, 16
    /* 4F6B4 800B7EB4 ADA7020C */  jal        func_800A9EB4
    /* 4F6B8 800B7EB8 00290500 */   sll       $a1, $a1, 4
    /* 4F6BC 800B7EBC 0F80023C */  lui        $v0, %hi(D_800F4B70)
  .L800B7EC0:
    /* 4F6C0 800B7EC0 704B4224 */  addiu      $v0, $v0, %lo(D_800F4B70)
    /* 4F6C4 800B7EC4 FFFF2332 */  andi       $v1, $s1, 0xFFFF
    /* 4F6C8 800B7EC8 21186200 */  addu       $v1, $v1, $v0
    /* 4F6CC 800B7ECC 01000224 */  addiu      $v0, $zero, 0x1
    /* 4F6D0 800B7ED0 000062A0 */  sb         $v0, 0x0($v1)
    /* 4F6D4 800B7ED4 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 4F6D8 800B7ED8 2800B28F */  lw         $s2, 0x28($sp)
    /* 4F6DC 800B7EDC 2400B18F */  lw         $s1, 0x24($sp)
    /* 4F6E0 800B7EE0 2000B08F */  lw         $s0, 0x20($sp)
    /* 4F6E4 800B7EE4 21100000 */  addu       $v0, $zero, $zero
    /* 4F6E8 800B7EE8 0800E003 */  jr         $ra
    /* 4F6EC 800B7EEC 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800B7DC4
