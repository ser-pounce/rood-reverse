nonmatching func_8008EB30, 0x118

glabel func_8008EB30
    /* 26330 8008EB30 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 26334 8008EB34 1000B0AF */  sw         $s0, 0x10($sp)
    /* 26338 8008EB38 21808000 */  addu       $s0, $a0, $zero
    /* 2633C 8008EB3C 0F80043C */  lui        $a0, %hi(D_800F1D78)
    /* 26340 8008EB40 781D8424 */  addiu      $a0, $a0, %lo(D_800F1D78)
    /* 26344 8008EB44 21280002 */  addu       $a1, $s0, $zero
    /* 26348 8008EB48 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2634C 8008EB4C 2C24010C */  jal        vs_main_memcpy
    /* 26350 8008EB50 14000624 */   addiu     $a2, $zero, 0x14
    /* 26354 8008EB54 0780023C */  lui        $v0, %hi(D_80068C1C)
    /* 26358 8008EB58 1C8C4424 */  addiu      $a0, $v0, %lo(D_80068C1C)
    /* 2635C 8008EB5C 08008424 */  addiu      $a0, $a0, 0x8
    /* 26360 8008EB60 FF00023C */  lui        $v0, (0xFFFFFF >> 16)
    /* 26364 8008EB64 FFFF4234 */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* 26368 8008EB68 0000038E */  lw         $v1, 0x0($s0)
    /* 2636C 8008EB6C 04001026 */  addiu      $s0, $s0, 0x4
    /* 26370 8008EB70 FF00063C */  lui        $a2, (0xFFFFFF >> 16)
    /* 26374 8008EB74 FFFFC634 */  ori        $a2, $a2, (0xFFFFFF & 0xFFFF)
    /* 26378 8008EB78 0030073C */  lui        $a3, (0x30000000 >> 16)
    /* 2637C 8008EB7C 07000524 */  addiu      $a1, $zero, 0x7
    /* 26380 8008EB80 24186200 */  and        $v1, $v1, $v0
    /* 26384 8008EB84 2110E000 */  addu       $v0, $a3, $zero
    /* 26388 8008EB88 25186200 */  or         $v1, $v1, $v0
    /* 2638C 8008EB8C 000083AC */  sw         $v1, 0x0($a0)
    /* 26390 8008EB90 04008424 */  addiu      $a0, $a0, 0x4
  .L8008EB94:
    /* 26394 8008EB94 08008424 */  addiu      $a0, $a0, 0x8
    /* 26398 8008EB98 0000028E */  lw         $v0, 0x0($s0)
    /* 2639C 8008EB9C FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 263A0 8008EBA0 24104600 */  and        $v0, $v0, $a2
    /* 263A4 8008EBA4 25104700 */  or         $v0, $v0, $a3
    /* 263A8 8008EBA8 000082AC */  sw         $v0, 0x0($a0)
    /* 263AC 8008EBAC F9FFA104 */  bgez       $a1, .L8008EB94
    /* 263B0 8008EBB0 04008424 */   addiu     $a0, $a0, 0x4
    /* 263B4 8008EBB4 04001026 */  addiu      $s0, $s0, 0x4
    /* 263B8 8008EBB8 FF00033C */  lui        $v1, (0xFFFFFF >> 16)
    /* 263BC 8008EBBC FFFF6334 */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* 263C0 8008EBC0 0030063C */  lui        $a2, (0x30000000 >> 16)
    /* 263C4 8008EBC4 0F000524 */  addiu      $a1, $zero, 0xF
  .L8008EBC8:
    /* 263C8 8008EBC8 08008424 */  addiu      $a0, $a0, 0x8
    /* 263CC 8008EBCC 0000028E */  lw         $v0, 0x0($s0)
    /* 263D0 8008EBD0 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 263D4 8008EBD4 24104300 */  and        $v0, $v0, $v1
    /* 263D8 8008EBD8 25104600 */  or         $v0, $v0, $a2
    /* 263DC 8008EBDC 000082AC */  sw         $v0, 0x0($a0)
    /* 263E0 8008EBE0 F9FFA104 */  bgez       $a1, .L8008EBC8
    /* 263E4 8008EBE4 04008424 */   addiu     $a0, $a0, 0x4
    /* 263E8 8008EBE8 04001026 */  addiu      $s0, $s0, 0x4
    /* 263EC 8008EBEC FF00033C */  lui        $v1, (0xFFFFFF >> 16)
    /* 263F0 8008EBF0 FFFF6334 */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* 263F4 8008EBF4 0030063C */  lui        $a2, (0x30000000 >> 16)
    /* 263F8 8008EBF8 07000524 */  addiu      $a1, $zero, 0x7
  .L8008EBFC:
    /* 263FC 8008EBFC 08008424 */  addiu      $a0, $a0, 0x8
    /* 26400 8008EC00 0000028E */  lw         $v0, 0x0($s0)
    /* 26404 8008EC04 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 26408 8008EC08 24104300 */  and        $v0, $v0, $v1
    /* 2640C 8008EC0C 25104600 */  or         $v0, $v0, $a2
    /* 26410 8008EC10 000082AC */  sw         $v0, 0x0($a0)
    /* 26414 8008EC14 F9FFA104 */  bgez       $a1, .L8008EBFC
    /* 26418 8008EC18 04008424 */   addiu     $a0, $a0, 0x4
    /* 2641C 8008EC1C FF00023C */  lui        $v0, (0xFFFFFF >> 16)
    /* 26420 8008EC20 0400038E */  lw         $v1, 0x4($s0)
    /* 26424 8008EC24 FFFF4234 */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* 26428 8008EC28 24186200 */  and        $v1, $v1, $v0
    /* 2642C 8008EC2C 0030023C */  lui        $v0, (0x30000000 >> 16)
    /* 26430 8008EC30 25186200 */  or         $v1, $v1, $v0
    /* 26434 8008EC34 080083AC */  sw         $v1, 0x8($a0)
    /* 26438 8008EC38 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2643C 8008EC3C 1000B08F */  lw         $s0, 0x10($sp)
    /* 26440 8008EC40 0800E003 */  jr         $ra
    /* 26444 8008EC44 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008EB30
