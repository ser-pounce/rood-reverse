nonmatching func_800BAEA0, 0xCC

glabel func_800BAEA0
    /* 526A0 800BAEA0 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 526A4 800BAEA4 3000B0AF */  sw         $s0, 0x30($sp)
    /* 526A8 800BAEA8 21808000 */  addu       $s0, $a0, $zero
    /* 526AC 800BAEAC 01000426 */  addiu      $a0, $s0, 0x1
    /* 526B0 800BAEB0 3800BFAF */  sw         $ra, 0x38($sp)
    /* 526B4 800BAEB4 80FF020C */  jal        vs_battle_getShort
    /* 526B8 800BAEB8 3400B1AF */   sw        $s1, 0x34($sp)
    /* 526BC 800BAEBC 94FF020C */  jal        func_800BFE50
    /* 526C0 800BAEC0 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 526C4 800BAEC4 21204000 */  addu       $a0, $v0, $zero
    /* 526C8 800BAEC8 4284020C */  jal        func_800A1108
    /* 526CC 800BAECC 1000A527 */   addiu     $a1, $sp, 0x10
    /* 526D0 800BAED0 80FF020C */  jal        vs_battle_getShort
    /* 526D4 800BAED4 03000426 */   addiu     $a0, $s0, 0x3
    /* 526D8 800BAED8 94FF020C */  jal        func_800BFE50
    /* 526DC 800BAEDC FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 526E0 800BAEE0 21204000 */  addu       $a0, $v0, $zero
    /* 526E4 800BAEE4 4284020C */  jal        func_800A1108
    /* 526E8 800BAEE8 2000A527 */   addiu     $a1, $sp, 0x20
    /* 526EC 800BAEEC 05000426 */  addiu      $a0, $s0, 0x5
    /* 526F0 800BAEF0 1400B097 */  lhu        $s0, 0x14($sp)
    /* 526F4 800BAEF4 2400A397 */  lhu        $v1, 0x24($sp)
    /* 526F8 800BAEF8 1800B197 */  lhu        $s1, 0x18($sp)
    /* 526FC 800BAEFC 2800A297 */  lhu        $v0, 0x28($sp)
    /* 52700 800BAF00 23800302 */  subu       $s0, $s0, $v1
    /* 52704 800BAF04 80FF020C */  jal        vs_battle_getShort
    /* 52708 800BAF08 23882202 */   subu      $s1, $s1, $v0
    /* 5270C 800BAF0C 00841000 */  sll        $s0, $s0, 16
    /* 52710 800BAF10 03841000 */  sra        $s0, $s0, 16
    /* 52714 800BAF14 18001002 */  mult       $s0, $s0
    /* 52718 800BAF18 12180000 */  mflo       $v1
    /* 5271C 800BAF1C 008C1100 */  sll        $s1, $s1, 16
    /* 52720 800BAF20 038C1100 */  sra        $s1, $s1, 16
    /* 52724 800BAF24 18003102 */  mult       $s1, $s1
    /* 52728 800BAF28 00140200 */  sll        $v0, $v0, 16
    /* 5272C 800BAF2C 03840200 */  sra        $s0, $v0, 16
    /* 52730 800BAF30 12380000 */  mflo       $a3
    /* 52734 800BAF34 E506010C */  jal        vs_gte_rsqrt
    /* 52738 800BAF38 21206700 */   addu      $a0, $v1, $a3
    /* 5273C 800BAF3C 02004104 */  bgez       $v0, .L800BAF48
    /* 52740 800BAF40 21200002 */   addu      $a0, $s0, $zero
    /* 52744 800BAF44 7F004224 */  addiu      $v0, $v0, 0x7F
  .L800BAF48:
    /* 52748 800BAF48 C3290200 */  sra        $a1, $v0, 7
    /* 5274C 800BAF4C 05FB020C */  jal        vs_battle_setStateFlag
    /* 52750 800BAF50 FF00A530 */   andi      $a1, $a1, 0xFF
    /* 52754 800BAF54 3800BF8F */  lw         $ra, 0x38($sp)
    /* 52758 800BAF58 3400B18F */  lw         $s1, 0x34($sp)
    /* 5275C 800BAF5C 3000B08F */  lw         $s0, 0x30($sp)
    /* 52760 800BAF60 21100000 */  addu       $v0, $zero, $zero
    /* 52764 800BAF64 0800E003 */  jr         $ra
    /* 52768 800BAF68 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_800BAEA0
