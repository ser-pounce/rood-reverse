nonmatching _padResetDefaults, 0xC0

glabel _padResetDefaults
    /* 33834 80043034 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 33838 80043038 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3383C 8004303C 21888000 */  addu       $s1, $a0, $zero
    /* 33840 80043040 02000524 */  addiu      $a1, $zero, 0x2
    /* 33844 80043044 21300000 */  addu       $a2, $zero, $zero
    /* 33848 80043048 03191100 */  sra        $v1, $s1, 4
    /* 3384C 8004304C 40100300 */  sll        $v0, $v1, 1
    /* 33850 80043050 21104300 */  addu       $v0, $v0, $v1
    /* 33854 80043054 0410A200 */  sllv       $v0, $v0, $a1
    /* 33858 80043058 23104300 */  subu       $v0, $v0, $v1
    /* 3385C 8004305C 0580033C */  lui        $v1, %hi(_portInfo)
    /* 33860 80043060 90016324 */  addiu      $v1, $v1, %lo(_portInfo)
    /* 33864 80043064 1000B0AF */  sw         $s0, 0x10($sp)
    /* 33868 80043068 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3386C 8004306C 57AE000C */  jal        PadInfoMode
    /* 33870 80043070 21804300 */   addu      $s0, $v0, $v1
    /* 33874 80043074 010002A2 */  sb         $v0, 0x1($s0)
    /* 33878 80043078 FF004230 */  andi       $v0, $v0, 0xFF
    /* 3387C 8004307C 0E004010 */  beqz       $v0, .L800430B8
    /* 33880 80043080 21202002 */   addu      $a0, $s1, $zero
    /* 33884 80043084 03000524 */  addiu      $a1, $zero, 0x3
    /* 33888 80043088 21300000 */  addu       $a2, $zero, $zero
    /* 3388C 8004308C 02000224 */  addiu      $v0, $zero, 0x2
    /* 33890 80043090 080000A2 */  sb         $zero, 0x8($s0)
    /* 33894 80043094 090000A2 */  sb         $zero, 0x9($s0)
    /* 33898 80043098 57AE000C */  jal        PadInfoMode
    /* 3389C 8004309C 070002A2 */   sb        $v0, 0x7($s0)
    /* 338A0 800430A0 21202002 */  addu       $a0, $s1, $zero
    /* 338A4 800430A4 07000692 */  lbu        $a2, 0x7($s0)
    /* 338A8 800430A8 02AF000C */  jal        PadSetMainMode
    /* 338AC 800430AC 21284000 */   addu      $a1, $v0, $zero
    /* 338B0 800430B0 310C0108 */  j          .L800430C4
    /* 338B4 800430B4 21202002 */   addu      $a0, $s1, $zero
  .L800430B8:
    /* 338B8 800430B8 40000224 */  addiu      $v0, $zero, 0x40
    /* 338BC 800430BC 080002A2 */  sb         $v0, 0x8($s0)
    /* 338C0 800430C0 090000A2 */  sb         $zero, 0x9($s0)
  .L800430C4:
    /* 338C4 800430C4 08000526 */  addiu      $a1, $s0, 0x8
    /* 338C8 800430C8 14AF000C */  jal        PadSetAct
    /* 338CC 800430CC 02000624 */   addiu     $a2, $zero, 0x2
    /* 338D0 800430D0 21202002 */  addu       $a0, $s1, $zero
    /* 338D4 800430D4 0580053C */  lui        $a1, %hi(_actParams)
    /* 338D8 800430D8 F4AE000C */  jal        PadSetActAlign
    /* 338DC 800430DC 1CA5A524 */   addiu     $a1, $a1, %lo(_actParams)
    /* 338E0 800430E0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 338E4 800430E4 1400B18F */  lw         $s1, 0x14($sp)
    /* 338E8 800430E8 1000B08F */  lw         $s0, 0x10($sp)
    /* 338EC 800430EC 0800E003 */  jr         $ra
    /* 338F0 800430F0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _padResetDefaults
