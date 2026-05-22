nonmatching vs_battle_applyWeapon, 0x180

glabel vs_battle_applyWeapon
    /* 26AC 8006AEAC D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 26B0 8006AEB0 2400B5AF */  sw         $s5, 0x24($sp)
    /* 26B4 8006AEB4 21A88000 */  addu       $s5, $a0, $zero
    /* 26B8 8006AEB8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 26BC 8006AEBC 2198A000 */  addu       $s3, $a1, $zero
    /* 26C0 8006AEC0 0C010424 */  addiu      $a0, $zero, 0x10C
    /* 26C4 8006AEC4 2800BFAF */  sw         $ra, 0x28($sp)
    /* 26C8 8006AEC8 2000B4AF */  sw         $s4, 0x20($sp)
    /* 26CC 8006AECC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 26D0 8006AED0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 26D4 8006AED4 8F0F010C */  jal        vs_main_allocHeapR
    /* 26D8 8006AED8 1000B0AF */   sw        $s0, 0x10($sp)
    /* 26DC 8006AEDC 21904000 */  addu       $s2, $v0, $zero
    /* 26E0 8006AEE0 21204002 */  addu       $a0, $s2, $zero
    /* 26E4 8006AEE4 4424010C */  jal        vs_main_bzero
    /* 26E8 8006AEE8 0C010524 */   addiu     $a1, $zero, 0x10C
    /* 26EC 8006AEEC 42006012 */  beqz       $s3, .L8006AFF8
    /* 26F0 8006AEF0 2120A002 */   addu      $a0, $s5, $zero
    /* 26F4 8006AEF4 00006292 */  lbu        $v0, 0x0($s3)
    /* 26F8 8006AEF8 00000000 */  nop
    /* 26FC 8006AEFC F20042A6 */  sh         $v0, 0xF2($s2)
    /* 2700 8006AF00 01006292 */  lbu        $v0, 0x1($s3)
    /* 2704 8006AF04 00000000 */  nop
    /* 2708 8006AF08 16004010 */  beqz       $v0, .L8006AF64
    /* 270C 8006AF0C 21204002 */   addu      $a0, $s2, $zero
    /* 2710 8006AF10 40280200 */  sll        $a1, $v0, 1
    /* 2714 8006AF14 2128A200 */  addu       $a1, $a1, $v0
    /* 2718 8006AF18 80280500 */  sll        $a1, $a1, 2
    /* 271C 8006AF1C 2328A200 */  subu       $a1, $a1, $v0
    /* 2720 8006AF20 80280500 */  sll        $a1, $a1, 2
    /* 2724 8006AF24 0680103C */  lui        $s0, %hi(D_800603BC)
    /* 2728 8006AF28 BC031026 */  addiu      $s0, $s0, %lo(D_800603BC)
    /* 272C 8006AF2C D1AA010C */  jal        vs_battle_copyInventoryBladeStats
    /* 2730 8006AF30 2128B000 */   addu      $a1, $a1, $s0
    /* 2734 8006AF34 01006392 */  lbu        $v1, 0x1($s3)
    /* 2738 8006AF38 00000000 */  nop
    /* 273C 8006AF3C FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 2740 8006AF40 40100300 */  sll        $v0, $v1, 1
    /* 2744 8006AF44 21104300 */  addu       $v0, $v0, $v1
    /* 2748 8006AF48 80100200 */  sll        $v0, $v0, 2
    /* 274C 8006AF4C 23104300 */  subu       $v0, $v0, $v1
    /* 2750 8006AF50 80100200 */  sll        $v0, $v0, 2
    /* 2754 8006AF54 21800202 */  addu       $s0, $s0, $v0
    /* 2758 8006AF58 54000292 */  lbu        $v0, 0x54($s0)
    /* 275C 8006AF5C 00000000 */  nop
    /* 2760 8006AF60 F00042A2 */  sb         $v0, 0xF0($s2)
  .L8006AF64:
    /* 2764 8006AF64 02006292 */  lbu        $v0, 0x2($s3)
    /* 2768 8006AF68 00000000 */  nop
    /* 276C 8006AF6C 06004010 */  beqz       $v0, .L8006AF88
    /* 2770 8006AF70 30004426 */   addiu     $a0, $s2, 0x30
    /* 2774 8006AF74 00110200 */  sll        $v0, $v0, 4
    /* 2778 8006AF78 0680053C */  lui        $a1, %hi(D_80060698)
    /* 277C 8006AF7C 9806A524 */  addiu      $a1, $a1, %lo(D_80060698)
    /* 2780 8006AF80 1DAB010C */  jal        vs_battle_copyInventoryGripStats
    /* 2784 8006AF84 21284500 */   addu      $a1, $v0, $a1
  .L8006AF88:
    /* 2788 8006AF88 21800000 */  addu       $s0, $zero, $zero
    /* 278C 8006AF8C 0680023C */  lui        $v0, %hi(D_80060A0C)
    /* 2790 8006AF90 0C0A5424 */  addiu      $s4, $v0, %lo(D_80060A0C)
    /* 2794 8006AF94 60001124 */  addiu      $s1, $zero, 0x60
  .L8006AF98:
    /* 2798 8006AF98 21187002 */  addu       $v1, $s3, $s0
    /* 279C 8006AF9C 04006290 */  lbu        $v0, 0x4($v1)
    /* 27A0 8006AFA0 00000000 */  nop
    /* 27A4 8006AFA4 06004010 */  beqz       $v0, .L8006AFC0
    /* 27A8 8006AFA8 21205102 */   addu      $a0, $s2, $s1
    /* 27AC 8006AFAC C0280200 */  sll        $a1, $v0, 3
    /* 27B0 8006AFB0 2328A200 */  subu       $a1, $a1, $v0
    /* 27B4 8006AFB4 80280500 */  sll        $a1, $a1, 2
    /* 27B8 8006AFB8 83AB010C */  jal        vs_battle_copyInventoryGemStats
    /* 27BC 8006AFBC 2128B400 */   addu      $a1, $a1, $s4
  .L8006AFC0:
    /* 27C0 8006AFC0 01001026 */  addiu      $s0, $s0, 0x1
    /* 27C4 8006AFC4 0300022A */  slti       $v0, $s0, 0x3
    /* 27C8 8006AFC8 F3FF4014 */  bnez       $v0, .L8006AF98
    /* 27CC 8006AFCC 30003126 */   addiu     $s1, $s1, 0x30
    /* 27D0 8006AFD0 21800000 */  addu       $s0, $zero, $zero
    /* 27D4 8006AFD4 21185002 */  addu       $v1, $s2, $s0
  .L8006AFD8:
    /* 27D8 8006AFD8 21107002 */  addu       $v0, $s3, $s0
    /* 27DC 8006AFDC 08004290 */  lbu        $v0, 0x8($v0)
    /* 27E0 8006AFE0 01001026 */  addiu      $s0, $s0, 0x1
    /* 27E4 8006AFE4 F40062A0 */  sb         $v0, 0xF4($v1)
    /* 27E8 8006AFE8 1800022A */  slti       $v0, $s0, 0x18
    /* 27EC 8006AFEC FAFF4014 */  bnez       $v0, .L8006AFD8
    /* 27F0 8006AFF0 21185002 */   addu      $v1, $s2, $s0
    /* 27F4 8006AFF4 2120A002 */  addu       $a0, $s5, $zero
  .L8006AFF8:
    /* 27F8 8006AFF8 CDA8010C */  jal        vs_battle_applyWeaponStats
    /* 27FC 8006AFFC 21284002 */   addu      $a1, $s2, $zero
    /* 2800 8006B000 180F010C */  jal        vs_main_freeHeapR
    /* 2804 8006B004 21204002 */   addu      $a0, $s2, $zero
    /* 2808 8006B008 2800BF8F */  lw         $ra, 0x28($sp)
    /* 280C 8006B00C 2400B58F */  lw         $s5, 0x24($sp)
    /* 2810 8006B010 2000B48F */  lw         $s4, 0x20($sp)
    /* 2814 8006B014 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2818 8006B018 1800B28F */  lw         $s2, 0x18($sp)
    /* 281C 8006B01C 1400B18F */  lw         $s1, 0x14($sp)
    /* 2820 8006B020 1000B08F */  lw         $s0, 0x10($sp)
    /* 2824 8006B024 0800E003 */  jr         $ra
    /* 2828 8006B028 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel vs_battle_applyWeapon
