nonmatching _getHitGemModifier, 0xD8

glabel _getHitGemModifier
    /* 1619C 8007E99C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 161A0 8007E9A0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 161A4 8007E9A4 21908000 */  addu       $s2, $a0, $zero
    /* 161A8 8007E9A8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 161AC 8007E9AC 2188C000 */  addu       $s1, $a2, $zero
    /* 161B0 8007E9B0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 161B4 8007E9B4 2198E000 */  addu       $s3, $a3, $zero
    /* 161B8 8007E9B8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 161BC 8007E9BC 64001024 */  addiu      $s0, $zero, 0x64
    /* 161C0 8007E9C0 1100A010 */  beqz       $a1, .L8007EA08
    /* 161C4 8007E9C4 2000BFAF */   sw        $ra, 0x20($sp)
    /* 161C8 8007E9C8 4000A28C */  lw         $v0, 0x40($a1)
    /* 161CC 8007E9CC 00000000 */  nop
    /* 161D0 8007E9D0 0D004014 */  bnez       $v0, .L8007EA08
    /* 161D4 8007E9D4 0F80033C */   lui       $v1, %hi(vs_battle_actors)
    /* 161D8 8007E9D8 0000A290 */  lbu        $v0, 0x0($a1)
    /* 161DC 8007E9DC 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 161E0 8007E9E0 80100200 */  sll        $v0, $v0, 2
    /* 161E4 8007E9E4 21104300 */  addu       $v0, $v0, $v1
    /* 161E8 8007E9E8 0000428C */  lw         $v0, 0x0($v0)
    /* 161EC 8007E9EC 00000000 */  nop
    /* 161F0 8007E9F0 3C00458C */  lw         $a1, 0x3C($v0)
    /* 161F4 8007E9F4 78F9010C */  jal        _getAttackGemBuff
    /* 161F8 8007E9F8 00000000 */   nop
    /* 161FC 8007E9FC 00140200 */  sll        $v0, $v0, 16
    /* 16200 8007EA00 03140200 */  sra        $v0, $v0, 16
    /* 16204 8007EA04 21805000 */  addu       $s0, $v0, $s0
  .L8007EA08:
    /* 16208 8007EA08 13002012 */  beqz       $s1, .L8007EA58
    /* 1620C 8007EA0C 21100002 */   addu      $v0, $s0, $zero
    /* 16210 8007EA10 4000228E */  lw         $v0, 0x40($s1)
    /* 16214 8007EA14 00000000 */  nop
    /* 16218 8007EA18 0F004014 */  bnez       $v0, .L8007EA58
    /* 1621C 8007EA1C 21100002 */   addu      $v0, $s0, $zero
    /* 16220 8007EA20 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 16224 8007EA24 00002292 */  lbu        $v0, 0x0($s1)
    /* 16228 8007EA28 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 1622C 8007EA2C 80100200 */  sll        $v0, $v0, 2
    /* 16230 8007EA30 21104300 */  addu       $v0, $v0, $v1
    /* 16234 8007EA34 0000428C */  lw         $v0, 0x0($v0)
    /* 16238 8007EA38 21204002 */  addu       $a0, $s2, $zero
    /* 1623C 8007EA3C 3C00458C */  lw         $a1, 0x3C($v0)
    /* 16240 8007EA40 A8F9010C */  jal        _getDefenseGemBuff
    /* 16244 8007EA44 21306002 */   addu      $a2, $s3, $zero
    /* 16248 8007EA48 00140200 */  sll        $v0, $v0, 16
    /* 1624C 8007EA4C 03140200 */  sra        $v0, $v0, 16
    /* 16250 8007EA50 23800202 */  subu       $s0, $s0, $v0
    /* 16254 8007EA54 21100002 */  addu       $v0, $s0, $zero
  .L8007EA58:
    /* 16258 8007EA58 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1625C 8007EA5C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 16260 8007EA60 1800B28F */  lw         $s2, 0x18($sp)
    /* 16264 8007EA64 1400B18F */  lw         $s1, 0x14($sp)
    /* 16268 8007EA68 1000B08F */  lw         $s0, 0x10($sp)
    /* 1626C 8007EA6C 0800E003 */  jr         $ra
    /* 16270 8007EA70 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _getHitGemModifier
