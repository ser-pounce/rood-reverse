nonmatching _loadScreff2, 0x90

glabel _loadScreff2
    /* 62E78 800CB678 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 62E7C 800CB67C 0F80023C */  lui        $v0, %hi(D_800EB9B4)
    /* 62E80 800CB680 1800B0AF */  sw         $s0, 0x18($sp)
    /* 62E84 800CB684 B4B9508C */  lw         $s0, %lo(D_800EB9B4)($v0)
    /* 62E88 800CB688 11008010 */  beqz       $a0, .L800CB6D0
    /* 62E8C 800CB68C 1C00BFAF */   sw        $ra, 0x1C($sp)
    /* 62E90 800CB690 0200033C */  lui        $v1, (0x20F58 >> 16)
    /* 62E94 800CB694 580F6334 */  ori        $v1, $v1, (0x20F58 & 0xFFFF)
    /* 62E98 800CB698 1000A427 */  addiu      $a0, $sp, 0x10
    /* 62E9C 800CB69C 01000224 */  addiu      $v0, $zero, 0x1
    /* 62EA0 800CB6A0 000002A2 */  sb         $v0, 0x0($s0)
    /* 62EA4 800CB6A4 00100224 */  addiu      $v0, $zero, 0x1000
    /* 62EA8 800CB6A8 1000A3AF */  sw         $v1, 0x10($sp)
    /* 62EAC 800CB6AC C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 62EB0 800CB6B0 1400A2AF */   sw        $v0, 0x14($sp)
    /* 62EB4 800CB6B4 0180033C */  lui        $v1, %hi(vs_overlay_slots + 0x4)
    /* 62EB8 800CB6B8 0400658C */  lw         $a1, %lo(vs_overlay_slots + 0x4)($v1)
    /* 62EBC 800CB6BC 21204000 */  addu       $a0, $v0, $zero
    /* 62EC0 800CB6C0 F112010C */  jal        vs_main_cdEnqueue
    /* 62EC4 800CB6C4 0C0004AE */   sw        $a0, 0xC($s0)
    /* 62EC8 800CB6C8 BE2D0308 */  j          .L800CB6F8
    /* 62ECC 800CB6CC 00000000 */   nop
  .L800CB6D0:
    /* 62ED0 800CB6D0 0C00048E */  lw         $a0, 0xC($s0)
    /* 62ED4 800CB6D4 00000000 */  nop
    /* 62ED8 800CB6D8 00008384 */  lh         $v1, 0x0($a0)
    /* 62EDC 800CB6DC 04000224 */  addiu      $v0, $zero, 0x4
    /* 62EE0 800CB6E0 05006214 */  bne        $v1, $v0, .L800CB6F8
    /* 62EE4 800CB6E4 00000000 */   nop
    /* 62EE8 800CB6E8 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 62EEC 800CB6EC 00000000 */   nop
    /* 62EF0 800CB6F0 1D0B010C */  jal        vs_main_wait
    /* 62EF4 800CB6F4 000000A2 */   sb        $zero, 0x0($s0)
  .L800CB6F8:
    /* 62EF8 800CB6F8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 62EFC 800CB6FC 1800B08F */  lw         $s0, 0x18($sp)
    /* 62F00 800CB700 0800E003 */  jr         $ra
    /* 62F04 800CB704 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _loadScreff2
