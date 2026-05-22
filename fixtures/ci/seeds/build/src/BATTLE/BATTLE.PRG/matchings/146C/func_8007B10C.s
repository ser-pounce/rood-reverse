nonmatching func_8007B10C, 0xAC

glabel func_8007B10C
    /* 1290C 8007B10C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 12910 8007B110 2400B3AF */  sw         $s3, 0x24($sp)
    /* 12914 8007B114 21988000 */  addu       $s3, $a0, $zero
    /* 12918 8007B118 2800B4AF */  sw         $s4, 0x28($sp)
    /* 1291C 8007B11C 21A0A000 */  addu       $s4, $a1, $zero
    /* 12920 8007B120 2000B2AF */  sw         $s2, 0x20($sp)
    /* 12924 8007B124 00940600 */  sll        $s2, $a2, 16
    /* 12928 8007B128 21300000 */  addu       $a2, $zero, $zero
    /* 1292C 8007B12C 03941200 */  sra        $s2, $s2, 16
    /* 12930 8007B130 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 12934 8007B134 008C0700 */  sll        $s1, $a3, 16
    /* 12938 8007B138 21384002 */  addu       $a3, $s2, $zero
    /* 1293C 8007B13C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 12940 8007B140 4000B08F */  lw         $s0, 0x40($sp)
    /* 12944 8007B144 038C1100 */  sra        $s1, $s1, 16
    /* 12948 8007B148 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 1294C 8007B14C 1000B1AF */  sw         $s1, 0x10($sp)
    /* 12950 8007B150 00841000 */  sll        $s0, $s0, 16
    /* 12954 8007B154 03841000 */  sra        $s0, $s0, 16
    /* 12958 8007B158 A01C010C */  jal        vs_main_transformClutSlot
    /* 1295C 8007B15C 1400B0AF */   sw        $s0, 0x14($sp)
    /* 12960 8007B160 21206002 */  addu       $a0, $s3, $zero
    /* 12964 8007B164 21288002 */  addu       $a1, $s4, $zero
    /* 12968 8007B168 01000624 */  addiu      $a2, $zero, 0x1
    /* 1296C 8007B16C 21384002 */  addu       $a3, $s2, $zero
    /* 12970 8007B170 1000B1AF */  sw         $s1, 0x10($sp)
    /* 12974 8007B174 A01C010C */  jal        vs_main_transformClutSlot
    /* 12978 8007B178 1400B0AF */   sw        $s0, 0x14($sp)
    /* 1297C 8007B17C 21206002 */  addu       $a0, $s3, $zero
    /* 12980 8007B180 21288002 */  addu       $a1, $s4, $zero
    /* 12984 8007B184 02000624 */  addiu      $a2, $zero, 0x2
    /* 12988 8007B188 21384002 */  addu       $a3, $s2, $zero
    /* 1298C 8007B18C 1000B1AF */  sw         $s1, 0x10($sp)
    /* 12990 8007B190 A01C010C */  jal        vs_main_transformClutSlot
    /* 12994 8007B194 1400B0AF */   sw        $s0, 0x14($sp)
    /* 12998 8007B198 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 1299C 8007B19C 2800B48F */  lw         $s4, 0x28($sp)
    /* 129A0 8007B1A0 2400B38F */  lw         $s3, 0x24($sp)
    /* 129A4 8007B1A4 2000B28F */  lw         $s2, 0x20($sp)
    /* 129A8 8007B1A8 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 129AC 8007B1AC 1800B08F */  lw         $s0, 0x18($sp)
    /* 129B0 8007B1B0 0800E003 */  jr         $ra
    /* 129B4 8007B1B4 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8007B10C
