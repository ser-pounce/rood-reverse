nonmatching func_80012E50, 0x6C

glabel func_80012E50
    /* 3650 80012E50 0380023C */  lui        $v0, %hi(D_80036770)
    /* 3654 80012E54 7067438C */  lw         $v1, %lo(D_80036770)($v0)
    /* 3658 80012E58 00000000 */  nop
    /* 365C 80012E5C 08006414 */  bne        $v1, $a0, .L80012E80
    /* 3660 80012E60 70674224 */   addiu     $v0, $v0, %lo(D_80036770)
    /* 3664 80012E64 0480023C */  lui        $v0, %hi(g_Sound_GlobalFlags)
    /* 3668 80012E68 F89A4224 */  addiu      $v0, $v0, %lo(g_Sound_GlobalFlags)
    /* 366C 80012E6C 0400438C */  lw         $v1, 0x4($v0)
    /* 3670 80012E70 0100043C */  lui        $a0, (0x10000 >> 16)
    /* 3674 80012E74 25186400 */  or         $v1, $v1, $a0
    /* 3678 80012E78 AA4B0008 */  j          .L80012EA8
    /* 367C 80012E7C 040043AC */   sw        $v1, 0x4($v0)
  .L80012E80:
    /* 3680 80012E80 0400428C */  lw         $v0, 0x4($v0)
    /* 3684 80012E84 00000000 */  nop
    /* 3688 80012E88 07004414 */  bne        $v0, $a0, .L80012EA8
    /* 368C 80012E8C FEFF043C */   lui       $a0, (0xFFFEFFFF >> 16)
    /* 3690 80012E90 0480033C */  lui        $v1, %hi(g_Sound_GlobalFlags)
    /* 3694 80012E94 F89A6324 */  addiu      $v1, $v1, %lo(g_Sound_GlobalFlags)
    /* 3698 80012E98 0400628C */  lw         $v0, 0x4($v1)
    /* 369C 80012E9C FFFF8434 */  ori        $a0, $a0, (0xFFFEFFFF & 0xFFFF)
    /* 36A0 80012EA0 24104400 */  and        $v0, $v0, $a0
    /* 36A4 80012EA4 040062AC */  sw         $v0, 0x4($v1)
  .L80012EA8:
    /* 36A8 80012EA8 0480023C */  lui        $v0, %hi(D_80039AFC)
    /* 36AC 80012EAC FC9A438C */  lw         $v1, %lo(D_80039AFC)($v0)
    /* 36B0 80012EB0 0100023C */  lui        $v0, (0x10000 >> 16)
    /* 36B4 80012EB4 0800E003 */  jr         $ra
    /* 36B8 80012EB8 24106200 */   and       $v0, $v1, $v0
endlabel func_80012E50
