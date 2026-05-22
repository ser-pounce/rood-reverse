nonmatching func_8002F154, 0x130

glabel func_8002F154
    /* 1F954 8002F154 50FFBD27 */  addiu      $sp, $sp, -0xB0
    /* 1F958 8002F158 9000B0AF */  sw         $s0, 0x90($sp)
    /* 1F95C 8002F15C 21808000 */  addu       $s0, $a0, $zero
    /* 1F960 8002F160 A000B4AF */  sw         $s4, 0xA0($sp)
    /* 1F964 8002F164 21A0A000 */  addu       $s4, $a1, $zero
    /* 1F968 8002F168 9C00B3AF */  sw         $s3, 0x9C($sp)
    /* 1F96C 8002F16C 2198C000 */  addu       $s3, $a2, $zero
    /* 1F970 8002F170 9400B1AF */  sw         $s1, 0x94($sp)
    /* 1F974 8002F174 21880000 */  addu       $s1, $zero, $zero
    /* 1F978 8002F178 21186002 */  addu       $v1, $s3, $zero
    /* 1F97C 8002F17C 21280000 */  addu       $a1, $zero, $zero
    /* 1F980 8002F180 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 1F984 8002F184 A800BFAF */  sw         $ra, 0xA8($sp)
    /* 1F988 8002F188 A400B5AF */  sw         $s5, 0xA4($sp)
    /* 1F98C 8002F18C 9800B2AF */  sw         $s2, 0x98($sp)
  .L8002F190:
    /* 1F990 8002F190 00006290 */  lbu        $v0, 0x0($v1)
    /* 1F994 8002F194 01006324 */  addiu      $v1, $v1, 0x1
    /* 1F998 8002F198 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 1F99C 8002F19C 2610A200 */  xor        $v0, $a1, $v0
    /* 1F9A0 8002F1A0 FBFF8104 */  bgez       $a0, .L8002F190
    /* 1F9A4 8002F1A4 21284000 */   addu      $a1, $v0, $zero
    /* 1F9A8 8002F1A8 000062A0 */  sb         $v0, 0x0($v1)
    /* 1F9AC 8002F1AC 01001524 */  addiu      $s5, $zero, 0x1
    /* 1F9B0 8002F1B0 1000B227 */  addiu      $s2, $sp, 0x10
  .L8002F1B4:
    /* 1F9B4 8002F1B4 0800222A */  slti       $v0, $s1, 0x8
    /* 1F9B8 8002F1B8 29004010 */  beqz       $v0, .L8002F260
    /* 1F9BC 8002F1BC 21100000 */   addu      $v0, $zero, $zero
    /* 1F9C0 8002F1C0 49BA000C */  jal        _new_card
    /* 1F9C4 8002F1C4 00000000 */   nop
    /* 1F9C8 8002F1C8 21200002 */  addu       $a0, $s0, $zero
    /* 1F9CC 8002F1CC 21288002 */  addu       $a1, $s4, $zero
    /* 1F9D0 8002F1D0 45BA000C */  jal        _card_write
    /* 1F9D4 8002F1D4 21306002 */   addu      $a2, $s3, $zero
    /* 1F9D8 8002F1D8 21005514 */  bne        $v0, $s5, .L8002F260
    /* 1F9DC 8002F1DC 21100000 */   addu      $v0, $zero, $zero
  .L8002F1E0:
    /* 1F9E0 8002F1E0 49BD000C */  jal        _card_status
    /* 1F9E4 8002F1E4 03211000 */   sra       $a0, $s0, 4
    /* 1F9E8 8002F1E8 01004230 */  andi       $v0, $v0, 0x1
    /* 1F9EC 8002F1EC FCFF4010 */  beqz       $v0, .L8002F1E0
    /* 1F9F0 8002F1F0 21204002 */   addu      $a0, $s2, $zero
    /* 1F9F4 8002F1F4 C9B8000C */  jal        bzero
    /* 1F9F8 8002F1F8 80000524 */   addiu     $a1, $zero, 0x80
    /* 1F9FC 8002F1FC 49BA000C */  jal        _new_card
    /* 1FA00 8002F200 00000000 */   nop
    /* 1FA04 8002F204 21200002 */  addu       $a0, $s0, $zero
    /* 1FA08 8002F208 21288002 */  addu       $a1, $s4, $zero
    /* 1FA0C 8002F20C 45BD000C */  jal        _card_read
    /* 1FA10 8002F210 21304002 */   addu      $a2, $s2, $zero
    /* 1FA14 8002F214 06005514 */  bne        $v0, $s5, .L8002F230
    /* 1FA18 8002F218 1000A427 */   addiu     $a0, $sp, 0x10
  .L8002F21C:
    /* 1FA1C 8002F21C 49BD000C */  jal        _card_status
    /* 1FA20 8002F220 03211000 */   sra       $a0, $s0, 4
    /* 1FA24 8002F224 01004230 */  andi       $v0, $v0, 0x1
    /* 1FA28 8002F228 FCFF4010 */  beqz       $v0, .L8002F21C
    /* 1FA2C 8002F22C 1000A427 */   addiu     $a0, $sp, 0x10
  .L8002F230:
    /* 1FA30 8002F230 21280000 */  addu       $a1, $zero, $zero
    /* 1FA34 8002F234 7E000324 */  addiu      $v1, $zero, 0x7E
  .L8002F238:
    /* 1FA38 8002F238 00008290 */  lbu        $v0, 0x0($a0)
    /* 1FA3C 8002F23C 01008424 */  addiu      $a0, $a0, 0x1
    /* 1FA40 8002F240 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 1FA44 8002F244 FCFF6104 */  bgez       $v1, .L8002F238
    /* 1FA48 8002F248 2628A200 */   xor       $a1, $a1, $v0
    /* 1FA4C 8002F24C 7F006392 */  lbu        $v1, 0x7F($s3)
    /* 1FA50 8002F250 FF00A230 */  andi       $v0, $a1, 0xFF
    /* 1FA54 8002F254 D7FF6214 */  bne        $v1, $v0, .L8002F1B4
    /* 1FA58 8002F258 01003126 */   addiu     $s1, $s1, 0x1
    /* 1FA5C 8002F25C 01000224 */  addiu      $v0, $zero, 0x1
  .L8002F260:
    /* 1FA60 8002F260 A800BF8F */  lw         $ra, 0xA8($sp)
    /* 1FA64 8002F264 A400B58F */  lw         $s5, 0xA4($sp)
    /* 1FA68 8002F268 A000B48F */  lw         $s4, 0xA0($sp)
    /* 1FA6C 8002F26C 9C00B38F */  lw         $s3, 0x9C($sp)
    /* 1FA70 8002F270 9800B28F */  lw         $s2, 0x98($sp)
    /* 1FA74 8002F274 9400B18F */  lw         $s1, 0x94($sp)
    /* 1FA78 8002F278 9000B08F */  lw         $s0, 0x90($sp)
    /* 1FA7C 8002F27C 0800E003 */  jr         $ra
    /* 1FA80 8002F280 B000BD27 */   addiu     $sp, $sp, 0xB0
endlabel func_8002F154
