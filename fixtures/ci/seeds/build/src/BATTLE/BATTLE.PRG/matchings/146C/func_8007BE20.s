nonmatching func_8007BE20, 0xA4

glabel func_8007BE20
    /* 13620 8007BE20 00FFBD27 */  addiu      $sp, $sp, -0x100
    /* 13624 8007BE24 21300000 */  addu       $a2, $zero, $zero
    /* 13628 8007BE28 2118C000 */  addu       $v1, $a2, $zero
    /* 1362C 8007BE2C 1000A827 */  addiu      $t0, $sp, 0x10
    /* 13630 8007BE30 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 13634 8007BE34 28194724 */  addiu      $a3, $v0, %lo(vs_battle_actors)
    /* 13638 8007BE38 01000224 */  addiu      $v0, $zero, 0x1
    /* 1363C 8007BE3C 1200A2A3 */  sb         $v0, 0x12($sp)
    /* 13640 8007BE40 05000224 */  addiu      $v0, $zero, 0x5
    /* 13644 8007BE44 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 13648 8007BE48 04000224 */  addiu      $v0, $zero, 0x4
    /* 1364C 8007BE4C F800BFAF */  sw         $ra, 0xF8($sp)
    /* 13650 8007BE50 1000A4A7 */  sh         $a0, 0x10($sp)
    /* 13654 8007BE54 1300A0A3 */  sb         $zero, 0x13($sp)
    /* 13658 8007BE58 1C00A0A7 */  sh         $zero, 0x1C($sp)
    /* 1365C 8007BE5C 1A00A0A7 */  sh         $zero, 0x1A($sp)
    /* 13660 8007BE60 1800A0A7 */  sh         $zero, 0x18($sp)
    /* 13664 8007BE64 2000A2A7 */  sh         $v0, 0x20($sp)
    /* 13668 8007BE68 2400A5A3 */  sb         $a1, 0x24($sp)
    /* 1366C 8007BE6C 2600A0A3 */  sb         $zero, 0x26($sp)
  .L8007BE70:
    /* 13670 8007BE70 0000E28C */  lw         $v0, 0x0($a3)
    /* 13674 8007BE74 00000000 */  nop
    /* 13678 8007BE78 05004010 */  beqz       $v0, .L8007BE90
    /* 1367C 8007BE7C 00000000 */   nop
    /* 13680 8007BE80 03006510 */  beq        $v1, $a1, .L8007BE90
    /* 13684 8007BE84 21100601 */   addu      $v0, $t0, $a2
    /* 13688 8007BE88 D00043A0 */  sb         $v1, 0xD0($v0)
    /* 1368C 8007BE8C 0100C624 */  addiu      $a2, $a2, 0x1
  .L8007BE90:
    /* 13690 8007BE90 01006324 */  addiu      $v1, $v1, 0x1
    /* 13694 8007BE94 10006228 */  slti       $v0, $v1, 0x10
    /* 13698 8007BE98 F5FF4014 */  bnez       $v0, .L8007BE70
    /* 1369C 8007BE9C 0400E724 */   addiu     $a3, $a3, 0x4
    /* 136A0 8007BEA0 1000A427 */  addiu      $a0, $sp, 0x10
    /* 136A4 8007BEA4 21280000 */  addu       $a1, $zero, $zero
    /* 136A8 8007BEA8 1300A6A3 */  sb         $a2, 0x13($sp)
    /* 136AC 8007BEAC 3A3C030C */  jal        func_800CF0E8
    /* 136B0 8007BEB0 2130A000 */   addu      $a2, $a1, $zero
    /* 136B4 8007BEB4 F800BF8F */  lw         $ra, 0xF8($sp)
    /* 136B8 8007BEB8 00000000 */  nop
    /* 136BC 8007BEBC 0800E003 */  jr         $ra
    /* 136C0 8007BEC0 0001BD27 */   addiu     $sp, $sp, 0x100
endlabel func_8007BE20
