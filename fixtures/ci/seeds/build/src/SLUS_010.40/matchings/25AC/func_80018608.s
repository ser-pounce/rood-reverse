nonmatching func_80018608, 0xDC

glabel func_80018608
    /* 8E08 80018608 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 8E0C 8001860C 0380023C */  lui        $v0, %hi(D_80035910)
    /* 8E10 80018610 1800B2AF */  sw         $s2, 0x18($sp)
    /* 8E14 80018614 10595224 */  addiu      $s2, $v0, %lo(D_80035910)
    /* 8E18 80018618 1400B1AF */  sw         $s1, 0x14($sp)
    /* 8E1C 8001861C 00101124 */  addiu      $s1, $zero, 0x1000
    /* 8E20 80018620 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 8E24 80018624 21980000 */  addu       $s3, $zero, $zero
    /* 8E28 80018628 2400B5AF */  sw         $s5, 0x24($sp)
    /* 8E2C 8001862C 0380153C */  lui        $s5, %hi(g_Sound_VoiceSchedulerState)
    /* 8E30 80018630 2000B4AF */  sw         $s4, 0x20($sp)
    /* 8E34 80018634 9078B426 */  addiu      $s4, $s5, %lo(g_Sound_VoiceSchedulerState)
    /* 8E38 80018638 2800B6AF */  sw         $s6, 0x28($sp)
    /* 8E3C 8001863C 0002163C */  lui        $s6, (0x2000000 >> 16)
    /* 8E40 80018640 1000B0AF */  sw         $s0, 0x10($sp)
    /* 8E44 80018644 34005026 */  addiu      $s0, $s2, 0x34
    /* 8E48 80018648 2C00BFAF */  sw         $ra, 0x2C($sp)
  .L8001864C:
    /* 8E4C 8001864C 9078A28E */  lw         $v0, %lo(g_Sound_VoiceSchedulerState)($s5)
    /* 8E50 80018650 00000000 */  nop
    /* 8E54 80018654 24105100 */  and        $v0, $v0, $s1
    /* 8E58 80018658 0C004010 */  beqz       $v0, .L8001868C
    /* 8E5C 8001865C 00000000 */   nop
    /* 8E60 80018660 F4FF028E */  lw         $v0, -0xC($s0)
    /* 8E64 80018664 00000000 */  nop
    /* 8E68 80018668 24105600 */  and        $v0, $v0, $s6
    /* 8E6C 8001866C 07004014 */  bnez       $v0, .L8001868C
    /* 8E70 80018670 21204002 */   addu      $a0, $s2, $zero
    /* 8E74 80018674 0C00828E */  lw         $v0, 0xC($s4)
    /* 8E78 80018678 21282002 */  addu       $a1, $s1, $zero
    /* 8E7C 8001867C 25105100 */  or         $v0, $v0, $s1
    /* 8E80 80018680 336C000C */  jal        Sound_ClearVoiceFromSchedulerState
    /* 8E84 80018684 0C0082AE */   sw        $v0, 0xC($s4)
    /* 8E88 80018688 000000AE */  sw         $zero, 0x0($s0)
  .L8001868C:
    /* 8E8C 8001868C 01007326 */  addiu      $s3, $s3, 0x1
    /* 8E90 80018690 10011026 */  addiu      $s0, $s0, 0x110
    /* 8E94 80018694 10015226 */  addiu      $s2, $s2, 0x110
    /* 8E98 80018698 0C00622E */  sltiu      $v0, $s3, 0xC
    /* 8E9C 8001869C EBFF4014 */  bnez       $v0, .L8001864C
    /* 8EA0 800186A0 40881100 */   sll       $s1, $s1, 1
    /* 8EA4 800186A4 0480033C */  lui        $v1, %hi(g_Sound_GlobalFlags)
    /* 8EA8 800186A8 F89A6324 */  addiu      $v1, $v1, %lo(g_Sound_GlobalFlags)
    /* 8EAC 800186AC 0800628C */  lw         $v0, 0x8($v1)
    /* 8EB0 800186B0 00000000 */  nop
    /* 8EB4 800186B4 10014234 */  ori        $v0, $v0, 0x110
    /* 8EB8 800186B8 080062AC */  sw         $v0, 0x8($v1)
    /* 8EBC 800186BC 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 8EC0 800186C0 2800B68F */  lw         $s6, 0x28($sp)
    /* 8EC4 800186C4 2400B58F */  lw         $s5, 0x24($sp)
    /* 8EC8 800186C8 2000B48F */  lw         $s4, 0x20($sp)
    /* 8ECC 800186CC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 8ED0 800186D0 1800B28F */  lw         $s2, 0x18($sp)
    /* 8ED4 800186D4 1400B18F */  lw         $s1, 0x14($sp)
    /* 8ED8 800186D8 1000B08F */  lw         $s0, 0x10($sp)
    /* 8EDC 800186DC 0800E003 */  jr         $ra
    /* 8EE0 800186E0 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_80018608
