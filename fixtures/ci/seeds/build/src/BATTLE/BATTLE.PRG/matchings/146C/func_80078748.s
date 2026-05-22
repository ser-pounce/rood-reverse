nonmatching func_80078748, 0xA8

glabel func_80078748
    /* FF48 80078748 0F80023C */  lui        $v0, %hi(D_800F19CC)
    /* FF4C 8007874C CC19448C */  lw         $a0, %lo(D_800F19CC)($v0)
    /* FF50 80078750 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* FF54 80078754 1400BFAF */  sw         $ra, 0x14($sp)
    /* FF58 80078758 1000B0AF */  sw         $s0, 0x10($sp)
    /* FF5C 8007875C 0000838C */  lw         $v1, 0x0($a0)
    /* FF60 80078760 00000000 */  nop
    /* FF64 80078764 03006330 */  andi       $v1, $v1, 0x3
    /* FF68 80078768 40110300 */  sll        $v0, $v1, 5
    /* FF6C 8007876C 21104300 */  addu       $v0, $v0, $v1
    /* FF70 80078770 80100200 */  sll        $v0, $v0, 2
    /* FF74 80078774 21104300 */  addu       $v0, $v0, $v1
    /* FF78 80078778 80100200 */  sll        $v0, $v0, 2
    /* FF7C 8007877C 23104300 */  subu       $v0, $v0, $v1
    /* FF80 80078780 80100200 */  sll        $v0, $v0, 2
    /* FF84 80078784 54084224 */  addiu      $v0, $v0, 0x854
    /* FF88 80078788 172D030C */  jal        func_800CB45C
    /* FF8C 8007878C 21808200 */   addu      $s0, $a0, $v0
    /* FF90 80078790 13004014 */  bnez       $v0, .L800787E0
    /* FF94 80078794 00000000 */   nop
    /* FF98 80078798 04000492 */  lbu        $a0, 0x4($s0)
    /* FF9C 8007879C F882020C */  jal        func_800A0BE0
    /* FFA0 800787A0 00000000 */   nop
    /* FFA4 800787A4 0008033C */  lui        $v1, (0x8000100 >> 16)
    /* FFA8 800787A8 00016334 */  ori        $v1, $v1, (0x8000100 & 0xFFFF)
    /* FFAC 800787AC 24104300 */  and        $v0, $v0, $v1
    /* FFB0 800787B0 0B004314 */  bne        $v0, $v1, .L800787E0
    /* FFB4 800787B4 00000000 */   nop
    /* FFB8 800787B8 6C65020C */  jal        vs_battle_getEmptyObjectDataSlot
    /* FFBC 800787BC 00000000 */   nop
    /* FFC0 800787C0 07004014 */  bnez       $v0, .L800787E0
    /* FFC4 800787C4 00000000 */   nop
    /* FFC8 800787C8 AF3B030C */  jal        func_800CEEBC
    /* FFCC 800787CC 00000000 */   nop
    /* FFD0 800787D0 03004010 */  beqz       $v0, .L800787E0
    /* FFD4 800787D4 00000000 */   nop
    /* FFD8 800787D8 2CC1010C */  jal        func_800704B0
    /* FFDC 800787DC 00000000 */   nop
  .L800787E0:
    /* FFE0 800787E0 1400BF8F */  lw         $ra, 0x14($sp)
    /* FFE4 800787E4 1000B08F */  lw         $s0, 0x10($sp)
    /* FFE8 800787E8 0800E003 */  jr         $ra
    /* FFEC 800787EC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80078748
