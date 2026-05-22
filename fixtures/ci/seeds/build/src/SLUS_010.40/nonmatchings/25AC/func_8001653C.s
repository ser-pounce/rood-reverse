nonmatching func_8001653C, 0x1AC

glabel func_8001653C
    /* 6D3C 8001653C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6D40 80016540 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6D44 80016544 21808000 */  addu       $s0, $a0, $zero
    /* 6D48 80016548 2140A000 */  addu       $t0, $a1, $zero
    /* 6D4C 8001654C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6D50 80016550 2188C000 */  addu       $s1, $a2, $zero
    /* 6D54 80016554 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6D58 80016558 0000028D */  lw         $v0, 0x0($t0)
    /* 6D5C 8001655C 00000000 */  nop
    /* 6D60 80016560 3C0002AE */  sw         $v0, 0x3C($s0)
    /* 6D64 80016564 0400028D */  lw         $v0, 0x4($t0)
    /* 6D68 80016568 2128E000 */  addu       $a1, $a3, $zero
    /* 6D6C 8001656C 280002AE */  sw         $v0, 0x28($s0)
    /* 6D70 80016570 08000391 */  lbu        $v1, 0x8($t0)
    /* 6D74 80016574 00800234 */  ori        $v0, $zero, 0x8000
    /* 6D78 80016578 6E0000A6 */  sh         $zero, 0x6E($s0)
    /* 6D7C 8001657C 8E0002A6 */  sh         $v0, 0x8E($s0)
    /* 6D80 80016580 900000A6 */  sh         $zero, 0x90($s0)
    /* 6D84 80016584 001A0300 */  sll        $v1, $v1, 8
    /* 6D88 80016588 6C0003A6 */  sh         $v1, 0x6C($s0)
    /* 6D8C 8001658C 0C000295 */  lhu        $v0, 0xC($t0)
    /* 6D90 80016590 01000324 */  addiu      $v1, $zero, 0x1
    /* 6D94 80016594 8C0000A6 */  sh         $zero, 0x8C($s0)
    /* 6D98 80016598 7F004230 */  andi       $v0, $v0, 0x7F
    /* 6D9C 8001659C 00120200 */  sll        $v0, $v0, 8
    /* 6DA0 800165A0 DC0002A6 */  sh         $v0, 0xDC($s0)
    /* 6DA4 800165A4 1000068D */  lw         $a2, 0x10($t0)
    /* 6DA8 800165A8 02000224 */  addiu      $v0, $zero, 0x2
    /* 6DAC 800165AC 660002A6 */  sh         $v0, 0x66($s0)
    /* 6DB0 800165B0 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 6DB4 800165B4 680003A6 */  sh         $v1, 0x68($s0)
    /* 6DB8 800165B8 640003A6 */  sh         $v1, 0x64($s0)
    /* 6DBC 800165BC 580002AE */  sw         $v0, 0x58($s0)
    /* 6DC0 800165C0 400000AE */  sw         $zero, 0x40($s0)
    /* 6DC4 800165C4 860000A6 */  sh         $zero, 0x86($s0)
    /* 6DC8 800165C8 0418C300 */  sllv       $v1, $v1, $a2
    /* 6DCC 800165CC 2757000C */  jal        func_80015C9C
    /* 6DD0 800165D0 380003AE */   sw        $v1, 0x38($s0)
    /* 6DD4 800165D4 05000524 */  addiu      $a1, $zero, 0x5
    /* 6DD8 800165D8 0480033C */  lui        $v1, %hi(g_Sound_VoiceChannelConfigs)
    /* 6DDC 800165DC F400028E */  lw         $v0, 0xF4($s0)
    /* 6DE0 800165E0 689B6324 */  addiu      $v1, $v1, %lo(g_Sound_VoiceChannelConfigs)
    /* 6DE4 800165E4 80100200 */  sll        $v0, $v0, 2
    /* 6DE8 800165E8 21104300 */  addu       $v0, $v0, $v1
    /* 6DEC 800165EC 000040AC */  sw         $zero, 0x0($v0)
    /* 6DF0 800165F0 F400048E */  lw         $a0, 0xF4($s0)
    /* 6DF4 800165F4 354F000C */  jal        SetVoiceAdsrReleaseRateAndMode
    /* 6DF8 800165F8 03000624 */   addiu     $a2, $zero, 0x3
    /* 6DFC 800165FC 0380063C */  lui        $a2, %hi(g_Sound_VoiceSchedulerState)
    /* 6E00 80016600 9078C424 */  addiu      $a0, $a2, %lo(g_Sound_VoiceSchedulerState)
    /* 6E04 80016604 9078C28C */  lw         $v0, %lo(g_Sound_VoiceSchedulerState)($a2)
    /* 6E08 80016608 0C00838C */  lw         $v1, 0xC($a0)
    /* 6E0C 8001660C 25105100 */  or         $v0, $v0, $s1
    /* 6E10 80016610 25187100 */  or         $v1, $v1, $s1
    /* 6E14 80016614 9078C2AC */  sw         $v0, %lo(g_Sound_VoiceSchedulerState)($a2)
    /* 6E18 80016618 0400828C */  lw         $v0, 0x4($a0)
    /* 6E1C 8001661C 27881100 */  nor        $s1, $zero, $s1
    /* 6E20 80016620 0C0083AC */  sw         $v1, 0xC($a0)
    /* 6E24 80016624 0800838C */  lw         $v1, 0x8($a0)
    /* 6E28 80016628 24105100 */  and        $v0, $v0, $s1
    /* 6E2C 8001662C 040082AC */  sw         $v0, 0x4($a0)
    /* 6E30 80016630 1C00828C */  lw         $v0, 0x1C($a0)
    /* 6E34 80016634 24187100 */  and        $v1, $v1, $s1
    /* 6E38 80016638 080083AC */  sw         $v1, 0x8($a0)
    /* 6E3C 8001663C 2000838C */  lw         $v1, 0x20($a0)
    /* 6E40 80016640 24105100 */  and        $v0, $v0, $s1
    /* 6E44 80016644 24187100 */  and        $v1, $v1, $s1
    /* 6E48 80016648 200083AC */  sw         $v1, 0x20($a0)
    /* 6E4C 8001664C 0480033C */  lui        $v1, %hi(D_80039B64)
    /* 6E50 80016650 1C0082AC */  sw         $v0, 0x1C($a0)
    /* 6E54 80016654 2400828C */  lw         $v0, 0x24($a0)
    /* 6E58 80016658 649B638C */  lw         $v1, %lo(D_80039B64)($v1)
    /* 6E5C 8001665C 24105100 */  and        $v0, $v0, $s1
    /* 6E60 80016660 02006330 */  andi       $v1, $v1, 0x2
    /* 6E64 80016664 1B006010 */  beqz       $v1, .L800166D4
    /* 6E68 80016668 240082AC */   sw        $v0, 0x24($a0)
    /* 6E6C 8001666C 00101124 */  addiu      $s1, $zero, 0x1000
    /* 6E70 80016670 0380023C */  lui        $v0, %hi(D_80035910)
    /* 6E74 80016674 10595024 */  addiu      $s0, $v0, %lo(D_80035910)
    /* 6E78 80016678 0C000524 */  addiu      $a1, $zero, 0xC
    /* 6E7C 8001667C 2138C000 */  addu       $a3, $a2, $zero
    /* 6E80 80016680 21308000 */  addu       $a2, $a0, $zero
    /* 6E84 80016684 0002083C */  lui        $t0, (0x2000000 >> 16)
  .L80016688:
    /* 6E88 80016688 9078E48C */  lw         $a0, %lo(g_Sound_VoiceSchedulerState)($a3)
    /* 6E8C 8001668C 00000000 */  nop
    /* 6E90 80016690 24109100 */  and        $v0, $a0, $s1
    /* 6E94 80016694 0B004010 */  beqz       $v0, .L800166C4
    /* 6E98 80016698 00000000 */   nop
    /* 6E9C 8001669C 2800028E */  lw         $v0, 0x28($s0)
    /* 6EA0 800166A0 00000000 */  nop
    /* 6EA4 800166A4 24104800 */  and        $v0, $v0, $t0
    /* 6EA8 800166A8 06004014 */  bnez       $v0, .L800166C4
    /* 6EAC 800166AC 27101100 */   nor       $v0, $zero, $s1
    /* 6EB0 800166B0 1000C38C */  lw         $v1, 0x10($a2)
    /* 6EB4 800166B4 24108200 */  and        $v0, $a0, $v0
    /* 6EB8 800166B8 9078E2AC */  sw         $v0, %lo(g_Sound_VoiceSchedulerState)($a3)
    /* 6EBC 800166BC 25187100 */  or         $v1, $v1, $s1
    /* 6EC0 800166C0 1000C3AC */  sw         $v1, 0x10($a2)
  .L800166C4:
    /* 6EC4 800166C4 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 6EC8 800166C8 10011026 */  addiu      $s0, $s0, 0x110
    /* 6ECC 800166CC EEFFA014 */  bnez       $a1, .L80016688
    /* 6ED0 800166D0 40881100 */   sll       $s1, $s1, 1
  .L800166D4:
    /* 6ED4 800166D4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6ED8 800166D8 1400B18F */  lw         $s1, 0x14($sp)
    /* 6EDC 800166DC 1000B08F */  lw         $s0, 0x10($sp)
    /* 6EE0 800166E0 0800E003 */  jr         $ra
    /* 6EE4 800166E4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8001653C
