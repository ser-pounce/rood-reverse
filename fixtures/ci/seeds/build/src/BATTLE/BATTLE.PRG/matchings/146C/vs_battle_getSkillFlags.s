nonmatching vs_battle_getSkillFlags, 0x12C

glabel vs_battle_getSkillFlags
    /* 21DD0 8008A5D0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 21DD4 8008A5D4 2000B4AF */  sw         $s4, 0x20($sp)
    /* 21DD8 8008A5D8 21A08000 */  addu       $s4, $a0, $zero
    /* 21DDC 8008A5DC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 21DE0 8008A5E0 2190A000 */  addu       $s2, $a1, $zero
    /* 21DE4 8008A5E4 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 21DE8 8008A5E8 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 21DEC 8008A5EC 80101400 */  sll        $v0, $s4, 2
    /* 21DF0 8008A5F0 21104300 */  addu       $v0, $v0, $v1
    /* 21DF4 8008A5F4 0580033C */  lui        $v1, %hi(vs_main_skills)
    /* 21DF8 8008A5F8 DCB96324 */  addiu      $v1, $v1, %lo(vs_main_skills)
    /* 21DFC 8008A5FC 2400BFAF */  sw         $ra, 0x24($sp)
    /* 21E00 8008A600 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 21E04 8008A604 1400B1AF */  sw         $s1, 0x14($sp)
    /* 21E08 8008A608 1000B0AF */  sw         $s0, 0x10($sp)
    /* 21E0C 8008A60C 0000428C */  lw         $v0, 0x0($v0)
    /* 21E10 8008A610 21204002 */  addu       $a0, $s2, $zero
    /* 21E14 8008A614 3C00518C */  lw         $s1, 0x3C($v0)
    /* 21E18 8008A618 21300000 */  addu       $a2, $zero, $zero
    /* 21E1C 8008A61C 54092296 */  lhu        $v0, 0x954($s1)
    /* 21E20 8008A620 21282002 */  addu       $a1, $s1, $zero
    /* 21E24 8008A624 2B800200 */  sltu       $s0, $zero, $v0
    /* 21E28 8008A628 40101200 */  sll        $v0, $s2, 1
    /* 21E2C 8008A62C 21105200 */  addu       $v0, $v0, $s2
    /* 21E30 8008A630 80100200 */  sll        $v0, $v0, 2
    /* 21E34 8008A634 21105200 */  addu       $v0, $v0, $s2
    /* 21E38 8008A638 80100200 */  sll        $v0, $v0, 2
    /* 21E3C 8008A63C D315020C */  jal        func_8008574C
    /* 21E40 8008A640 21984300 */   addu      $s3, $v0, $v1
    /* 21E44 8008A644 00FF033C */  lui        $v1, (0xFF000000 >> 16)
    /* 21E48 8008A648 24104300 */  and        $v0, $v0, $v1
    /* 21E4C 8008A64C 02004014 */  bnez       $v0, .L8008A658
    /* 21E50 8008A650 00000000 */   nop
    /* 21E54 8008A654 02001036 */  ori        $s0, $s0, 0x2
  .L8008A658:
    /* 21E58 8008A658 07008016 */  bnez       $s4, .L8008A678
    /* 21E5C 8008A65C 8D00422A */   slti      $v0, $s2, 0x8D
    /* 21E60 8008A660 0C00628E */  lw         $v0, 0xC($s3)
    /* 21E64 8008A664 00000000 */  nop
    /* 21E68 8008A668 00804230 */  andi       $v0, $v0, 0x8000
    /* 21E6C 8008A66C 02004014 */  bnez       $v0, .L8008A678
    /* 21E70 8008A670 8D00422A */   slti      $v0, $s2, 0x8D
    /* 21E74 8008A674 04001036 */  ori        $s0, $s0, 0x4
  .L8008A678:
    /* 21E78 8008A678 04004010 */  beqz       $v0, .L8008A68C
    /* 21E7C 8008A67C 00000000 */   nop
    /* 21E80 8008A680 4809228E */  lw         $v0, 0x948($s1)
    /* 21E84 8008A684 B3290208 */  j          .L8008A6CC
    /* 21E88 8008A688 00104230 */   andi      $v0, $v0, 0x1000
  .L8008A68C:
    /* 21E8C 8008A68C E000422A */  slti       $v0, $s2, 0xE0
    /* 21E90 8008A690 11004010 */  beqz       $v0, .L8008A6D8
    /* 21E94 8008A694 0F80033C */   lui       $v1, %hi(vs_battle_actors)
    /* 21E98 8008A698 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 21E9C 8008A69C 80101400 */  sll        $v0, $s4, 2
    /* 21EA0 8008A6A0 21104300 */  addu       $v0, $v0, $v1
    /* 21EA4 8008A6A4 0000428C */  lw         $v0, 0x0($v0)
    /* 21EA8 8008A6A8 00000000 */  nop
    /* 21EAC 8008A6AC 2000428C */  lw         $v0, 0x20($v0)
    /* 21EB0 8008A6B0 00000000 */  nop
    /* 21EB4 8008A6B4 02004014 */  bnez       $v0, .L8008A6C0
    /* 21EB8 8008A6B8 00000000 */   nop
    /* 21EBC 8008A6BC 04001036 */  ori        $s0, $s0, 0x4
  .L8008A6C0:
    /* 21EC0 8008A6C0 4809228E */  lw         $v0, 0x948($s1)
    /* 21EC4 8008A6C4 00000000 */  nop
    /* 21EC8 8008A6C8 00204230 */  andi       $v0, $v0, 0x2000
  .L8008A6CC:
    /* 21ECC 8008A6CC 03004010 */  beqz       $v0, .L8008A6DC
    /* 21ED0 8008A6D0 21100002 */   addu      $v0, $s0, $zero
    /* 21ED4 8008A6D4 04001036 */  ori        $s0, $s0, 0x4
  .L8008A6D8:
    /* 21ED8 8008A6D8 21100002 */  addu       $v0, $s0, $zero
  .L8008A6DC:
    /* 21EDC 8008A6DC 2400BF8F */  lw         $ra, 0x24($sp)
    /* 21EE0 8008A6E0 2000B48F */  lw         $s4, 0x20($sp)
    /* 21EE4 8008A6E4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 21EE8 8008A6E8 1800B28F */  lw         $s2, 0x18($sp)
    /* 21EEC 8008A6EC 1400B18F */  lw         $s1, 0x14($sp)
    /* 21EF0 8008A6F0 1000B08F */  lw         $s0, 0x10($sp)
    /* 21EF4 8008A6F4 0800E003 */  jr         $ra
    /* 21EF8 8008A6F8 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel vs_battle_getSkillFlags
