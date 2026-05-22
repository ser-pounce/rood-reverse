nonmatching vs_main_memcpy, 0x60

glabel vs_main_memcpy
    /* 398B0 800490B0 02410600 */  srl        $t0, $a2, 4
    /* 398B4 800490B4 0E000011 */  beqz       $t0, .L800490F0
    /* 398B8 800490B8 0C00CD30 */   andi      $t5, $a2, 0xC
  .L800490BC:
    /* 398BC 800490BC 0000A98C */  lw         $t1, 0x0($a1)
    /* 398C0 800490C0 0400AA8C */  lw         $t2, 0x4($a1)
    /* 398C4 800490C4 0800AB8C */  lw         $t3, 0x8($a1)
    /* 398C8 800490C8 0C00AC8C */  lw         $t4, 0xC($a1)
    /* 398CC 800490CC FFFF0825 */  addiu      $t0, $t0, -0x1
    /* 398D0 800490D0 000089AC */  sw         $t1, 0x0($a0)
    /* 398D4 800490D4 04008AAC */  sw         $t2, 0x4($a0)
    /* 398D8 800490D8 08008BAC */  sw         $t3, 0x8($a0)
    /* 398DC 800490DC 0C008CAC */  sw         $t4, 0xC($a0)
    /* 398E0 800490E0 1000A524 */  addiu      $a1, $a1, 0x10
    /* 398E4 800490E4 F5FF0015 */  bnez       $t0, .L800490BC
    /* 398E8 800490E8 10008424 */   addiu     $a0, $a0, 0x10
    /* 398EC 800490EC 0600A011 */  beqz       $t5, .L80049108
  .L800490F0:
    /* 398F0 800490F0 0000A98C */   lw        $t1, 0x0($a1)
    /* 398F4 800490F4 FCFFAD25 */  addiu      $t5, $t5, -0x4
    /* 398F8 800490F8 000089AC */  sw         $t1, 0x0($a0)
    /* 398FC 800490FC 0400A524 */  addiu      $a1, $a1, 0x4
    /* 39900 80049100 FBFFA015 */  bnez       $t5, .L800490F0
    /* 39904 80049104 04008424 */   addiu     $a0, $a0, 0x4
  .L80049108:
    /* 39908 80049108 0800E003 */  jr         $ra
    /* 3990C 8004910C 00000000 */   nop
endlabel vs_main_memcpy
