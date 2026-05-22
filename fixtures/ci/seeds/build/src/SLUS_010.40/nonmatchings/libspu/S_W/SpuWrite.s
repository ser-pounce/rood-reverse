nonmatching SpuWrite, 0x5C

glabel SpuWrite
    /* F364 8001EB64 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F368 8001EB68 1000B0AF */  sw         $s0, 0x10($sp)
    /* F36C 8001EB6C 2180A000 */  addu       $s0, $a1, $zero
    /* F370 8001EB70 0700023C */  lui        $v0, (0x7EFF0 >> 16)
    /* F374 8001EB74 F0EF4234 */  ori        $v0, $v0, (0x7EFF0 & 0xFFFF)
    /* F378 8001EB78 2B105000 */  sltu       $v0, $v0, $s0
    /* F37C 8001EB7C 03004010 */  beqz       $v0, .L8001EB8C
    /* F380 8001EB80 1400BFAF */   sw        $ra, 0x14($sp)
    /* F384 8001EB84 0700103C */  lui        $s0, (0x7EFF0 >> 16)
    /* F388 8001EB88 F0EF1036 */  ori        $s0, $s0, (0x7EFF0 & 0xFFFF)
  .L8001EB8C:
    /* F38C 8001EB8C 9E78000C */  jal        _spu_Fw
    /* F390 8001EB90 21280002 */   addu      $a1, $s0, $zero
    /* F394 8001EB94 0380023C */  lui        $v0, %hi(D_80030898)
    /* F398 8001EB98 9808428C */  lw         $v0, %lo(D_80030898)($v0)
    /* F39C 8001EB9C 00000000 */  nop
    /* F3A0 8001EBA0 03004014 */  bnez       $v0, .L8001EBB0
    /* F3A4 8001EBA4 21100002 */   addu      $v0, $s0, $zero
    /* F3A8 8001EBA8 0380013C */  lui        $at, %hi(D_80030894)
    /* F3AC 8001EBAC 940820AC */  sw         $zero, %lo(D_80030894)($at)
  .L8001EBB0:
    /* F3B0 8001EBB0 1400BF8F */  lw         $ra, 0x14($sp)
    /* F3B4 8001EBB4 1000B08F */  lw         $s0, 0x10($sp)
    /* F3B8 8001EBB8 0800E003 */  jr         $ra
    /* F3BC 8001EBBC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel SpuWrite
    /* F3C0 8001EBC0 00000000 */  nop
