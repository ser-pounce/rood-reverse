nonmatching func_8007B1B8, 0xE4

glabel func_8007B1B8
    /* 129B8 8007B1B8 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 129BC 8007B1BC 2400B3AF */  sw         $s3, 0x24($sp)
    /* 129C0 8007B1C0 21988000 */  addu       $s3, $a0, $zero
    /* 129C4 8007B1C4 2800B4AF */  sw         $s4, 0x28($sp)
    /* 129C8 8007B1C8 21A0A000 */  addu       $s4, $a1, $zero
    /* 129CC 8007B1CC 2000B2AF */  sw         $s2, 0x20($sp)
    /* 129D0 8007B1D0 00940600 */  sll        $s2, $a2, 16
    /* 129D4 8007B1D4 21300000 */  addu       $a2, $zero, $zero
    /* 129D8 8007B1D8 03941200 */  sra        $s2, $s2, 16
    /* 129DC 8007B1DC 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 129E0 8007B1E0 008C0700 */  sll        $s1, $a3, 16
    /* 129E4 8007B1E4 21384002 */  addu       $a3, $s2, $zero
    /* 129E8 8007B1E8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 129EC 8007B1EC 4000B08F */  lw         $s0, 0x40($sp)
    /* 129F0 8007B1F0 038C1100 */  sra        $s1, $s1, 16
    /* 129F4 8007B1F4 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 129F8 8007B1F8 1000B1AF */  sw         $s1, 0x10($sp)
    /* 129FC 8007B1FC 00841000 */  sll        $s0, $s0, 16
    /* 12A00 8007B200 03841000 */  sra        $s0, $s0, 16
    /* 12A04 8007B204 A01C010C */  jal        vs_main_transformClutSlot
    /* 12A08 8007B208 1400B0AF */   sw        $s0, 0x14($sp)
    /* 12A0C 8007B20C 21206002 */  addu       $a0, $s3, $zero
    /* 12A10 8007B210 21288002 */  addu       $a1, $s4, $zero
    /* 12A14 8007B214 01000624 */  addiu      $a2, $zero, 0x1
    /* 12A18 8007B218 21384002 */  addu       $a3, $s2, $zero
    /* 12A1C 8007B21C 1000B1AF */  sw         $s1, 0x10($sp)
    /* 12A20 8007B220 A01C010C */  jal        vs_main_transformClutSlot
    /* 12A24 8007B224 1400B0AF */   sw        $s0, 0x14($sp)
    /* 12A28 8007B228 21206002 */  addu       $a0, $s3, $zero
    /* 12A2C 8007B22C 21288002 */  addu       $a1, $s4, $zero
    /* 12A30 8007B230 02000624 */  addiu      $a2, $zero, 0x2
    /* 12A34 8007B234 21384002 */  addu       $a3, $s2, $zero
    /* 12A38 8007B238 1000B1AF */  sw         $s1, 0x10($sp)
    /* 12A3C 8007B23C A01C010C */  jal        vs_main_transformClutSlot
    /* 12A40 8007B240 1400B0AF */   sw        $s0, 0x14($sp)
    /* 12A44 8007B244 21206002 */  addu       $a0, $s3, $zero
    /* 12A48 8007B248 21288002 */  addu       $a1, $s4, $zero
    /* 12A4C 8007B24C 21300000 */  addu       $a2, $zero, $zero
    /* 12A50 8007B250 21384002 */  addu       $a3, $s2, $zero
    /* 12A54 8007B254 1000B1AF */  sw         $s1, 0x10($sp)
    /* 12A58 8007B258 F01F010C */  jal        func_80047FC0
    /* 12A5C 8007B25C 1400B0AF */   sw        $s0, 0x14($sp)
    /* 12A60 8007B260 21206002 */  addu       $a0, $s3, $zero
    /* 12A64 8007B264 21288002 */  addu       $a1, $s4, $zero
    /* 12A68 8007B268 0D000624 */  addiu      $a2, $zero, 0xD
    /* 12A6C 8007B26C 21384002 */  addu       $a3, $s2, $zero
    /* 12A70 8007B270 1000B1AF */  sw         $s1, 0x10($sp)
    /* 12A74 8007B274 A01C010C */  jal        vs_main_transformClutSlot
    /* 12A78 8007B278 1400B0AF */   sw        $s0, 0x14($sp)
    /* 12A7C 8007B27C 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 12A80 8007B280 2800B48F */  lw         $s4, 0x28($sp)
    /* 12A84 8007B284 2400B38F */  lw         $s3, 0x24($sp)
    /* 12A88 8007B288 2000B28F */  lw         $s2, 0x20($sp)
    /* 12A8C 8007B28C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 12A90 8007B290 1800B08F */  lw         $s0, 0x18($sp)
    /* 12A94 8007B294 0800E003 */  jr         $ra
    /* 12A98 8007B298 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8007B1B8
