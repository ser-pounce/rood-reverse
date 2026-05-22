nonmatching vs_battle_script_jumpBackIf, 0x6C

glabel vs_battle_script_jumpBackIf
    /* 5047C 800B8C7C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 50480 800B8C80 1000B0AF */  sw         $s0, 0x10($sp)
    /* 50484 800B8C84 21808000 */  addu       $s0, $a0, $zero
    /* 50488 800B8C88 1400BFAF */  sw         $ra, 0x14($sp)
    /* 5048C 800B8C8C 01000392 */  lbu        $v1, 0x1($s0)
    /* 50490 800B8C90 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 50494 800B8C94 0B006210 */  beq        $v1, $v0, .L800B8CC4
    /* 50498 800B8C98 0F80023C */   lui       $v0, %hi(D_800F4C10)
    /* 5049C 800B8C9C 01000392 */  lbu        $v1, 0x1($s0)
    /* 504A0 800B8CA0 104C4224 */  addiu      $v0, $v0, %lo(D_800F4C10)
    /* 504A4 800B8CA4 21186200 */  addu       $v1, $v1, $v0
    /* 504A8 800B8CA8 00006290 */  lbu        $v0, 0x0($v1)
    /* 504AC 800B8CAC 00000000 */  nop
    /* 504B0 800B8CB0 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 504B4 800B8CB4 000062A0 */  sb         $v0, 0x0($v1)
    /* 504B8 800B8CB8 FF004230 */  andi       $v0, $v0, 0xFF
    /* 504BC 800B8CBC 06004010 */  beqz       $v0, .L800B8CD8
    /* 504C0 800B8CC0 21100000 */   addu      $v0, $zero, $zero
  .L800B8CC4:
    /* 504C4 800B8CC4 80FF020C */  jal        vs_battle_getShort
    /* 504C8 800B8CC8 02000426 */   addiu     $a0, $s0, 0x2
    /* 504CC 800B8CCC 00140200 */  sll        $v0, $v0, 16
    /* 504D0 800B8CD0 03140200 */  sra        $v0, $v0, 16
    /* 504D4 800B8CD4 23100202 */  subu       $v0, $s0, $v0
  .L800B8CD8:
    /* 504D8 800B8CD8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 504DC 800B8CDC 1000B08F */  lw         $s0, 0x10($sp)
    /* 504E0 800B8CE0 0800E003 */  jr         $ra
    /* 504E4 800B8CE4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_jumpBackIf
