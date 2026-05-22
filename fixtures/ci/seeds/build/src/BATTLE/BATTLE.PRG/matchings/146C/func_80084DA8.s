nonmatching func_80084DA8, 0x80

glabel func_80084DA8
    /* 1C5A8 80084DA8 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 1C5AC 80084DAC 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 1C5B0 80084DB0 0F80043C */  lui        $a0, %hi(D_800F19CC)
    /* 1C5B4 80084DB4 0000C290 */  lbu        $v0, 0x0($a2)
    /* 1C5B8 80084DB8 CC19848C */  lw         $a0, %lo(D_800F19CC)($a0)
    /* 1C5BC 80084DBC 80100200 */  sll        $v0, $v0, 2
    /* 1C5C0 80084DC0 21104300 */  addu       $v0, $v0, $v1
    /* 1C5C4 80084DC4 01000324 */  addiu      $v1, $zero, 0x1
    /* 1C5C8 80084DC8 2800848C */  lw         $a0, 0x28($a0)
    /* 1C5CC 80084DCC 0000428C */  lw         $v0, 0x0($v0)
    /* 1C5D0 80084DD0 03008430 */  andi       $a0, $a0, 0x3
    /* 1C5D4 80084DD4 3C00458C */  lw         $a1, 0x3C($v0)
    /* 1C5D8 80084DD8 03008310 */  beq        $a0, $v1, .L80084DE8
    /* 1C5DC 80084DDC 03000224 */   addiu     $v0, $zero, 0x3
    /* 1C5E0 80084DE0 0F008214 */  bne        $a0, $v0, .L80084E20
    /* 1C5E4 80084DE4 00000000 */   nop
  .L80084DE8:
    /* 1C5E8 80084DE8 EC01A294 */  lhu        $v0, 0x1EC($a1)
    /* 1C5EC 80084DEC 00000000 */  nop
    /* 1C5F0 80084DF0 0B004010 */  beqz       $v0, .L80084E20
    /* 1C5F4 80084DF4 0001043C */   lui       $a0, (0x1000000 >> 16)
    /* 1C5F8 80084DF8 FFFC023C */  lui        $v0, (0xFCFFFFFF >> 16)
    /* 1C5FC 80084DFC FFFF4234 */  ori        $v0, $v0, (0xFCFFFFFF & 0xFFFF)
    /* 1C600 80084E00 1C00C38C */  lw         $v1, 0x1C($a2)
    /* 1C604 80084E04 B002A594 */  lhu        $a1, 0x2B0($a1)
    /* 1C608 80084E08 24186200 */  and        $v1, $v1, $v0
    /* 1C60C 80084E0C 3E00C294 */  lhu        $v0, 0x3E($a2)
    /* 1C610 80084E10 25186400 */  or         $v1, $v1, $a0
    /* 1C614 80084E14 1C00C3AC */  sw         $v1, 0x1C($a2)
    /* 1C618 80084E18 21104500 */  addu       $v0, $v0, $a1
    /* 1C61C 80084E1C 3E00C2A4 */  sh         $v0, 0x3E($a2)
  .L80084E20:
    /* 1C620 80084E20 0800E003 */  jr         $ra
    /* 1C624 80084E24 00000000 */   nop
endlabel func_80084DA8
