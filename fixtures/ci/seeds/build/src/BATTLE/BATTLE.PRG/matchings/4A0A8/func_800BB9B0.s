nonmatching func_800BB9B0, 0x14C

glabel func_800BB9B0
    /* 531B0 800BB9B0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 531B4 800BB9B4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 531B8 800BB9B8 21900000 */  addu       $s2, $zero, $zero
    /* 531BC 800BB9BC 0F80023C */  lui        $v0, %hi(D_800F4B30)
    /* 531C0 800BB9C0 0F80033C */  lui        $v1, %hi(D_800EB9BC)
    /* 531C4 800BB9C4 BCB9638C */  lw         $v1, %lo(D_800EB9BC)($v1)
    /* 531C8 800BB9C8 304B4224 */  addiu      $v0, $v0, %lo(D_800F4B30)
    /* 531CC 800BB9CC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 531D0 800BB9D0 03005024 */  addiu      $s0, $v0, 0x3
    /* 531D4 800BB9D4 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 531D8 800BB9D8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 531DC 800BB9DC 03007124 */  addiu      $s1, $v1, 0x3
  .L800BB9E0:
    /* 531E0 800BB9E0 00000292 */  lbu        $v0, 0x0($s0)
    /* 531E4 800BB9E4 00000000 */  nop
    /* 531E8 800BB9E8 36004010 */  beqz       $v0, .L800BBAC4
    /* 531EC 800BB9EC 0680023C */   lui       $v0, %hi(vs_gametime_tickspeed)
    /* 531F0 800BB9F0 4CE2428C */  lw         $v0, %lo(vs_gametime_tickspeed)($v0)
    /* 531F4 800BB9F4 FFFF0392 */  lbu        $v1, -0x1($s0)
    /* 531F8 800BB9F8 FEFF0492 */  lbu        $a0, -0x2($s0)
    /* 531FC 800BB9FC 00000692 */  lbu        $a2, 0x0($s0)
    /* 53200 800BBA00 43100200 */  sra        $v0, $v0, 1
    /* 53204 800BBA04 21186200 */  addu       $v1, $v1, $v0
    /* 53208 800BBA08 FFFF03A2 */  sb         $v1, -0x1($s0)
    /* 5320C 800BBA0C AFFF020C */  jal        func_800BFEBC
    /* 53210 800BBA10 FF006530 */   andi      $a1, $v1, 0xFF
    /* 53214 800BBA14 0F80033C */  lui        $v1, %hi(D_800EB9BC)
    /* 53218 800BBA18 BCB9638C */  lw         $v1, %lo(D_800EB9BC)($v1)
    /* 5321C 800BBA1C 00000000 */  nop
    /* 53220 800BBA20 21006010 */  beqz       $v1, .L800BBAA8
    /* 53224 800BBA24 00240200 */   sll       $a0, $v0, 16
    /* 53228 800BBA28 05000286 */  lh         $v0, 0x5($s0)
    /* 5322C 800BBA2C 03240400 */  sra        $a0, $a0, 16
    /* 53230 800BBA30 18004400 */  mult       $v0, $a0
    /* 53234 800BBA34 01000296 */  lhu        $v0, 0x1($s0)
    /* 53238 800BBA38 12380000 */  mflo       $a3
    /* 5323C 800BBA3C 031B0700 */  sra        $v1, $a3, 12
    /* 53240 800BBA40 21104300 */  addu       $v0, $v0, $v1
    /* 53244 800BBA44 050022A6 */  sh         $v0, 0x5($s1)
    /* 53248 800BBA48 07000286 */  lh         $v0, 0x7($s0)
    /* 5324C 800BBA4C 00000000 */  nop
    /* 53250 800BBA50 18004400 */  mult       $v0, $a0
    /* 53254 800BBA54 03000296 */  lhu        $v0, 0x3($s0)
    /* 53258 800BBA58 12380000 */  mflo       $a3
    /* 5325C 800BBA5C 031B0700 */  sra        $v1, $a3, 12
    /* 53260 800BBA60 21104300 */  addu       $v0, $v0, $v1
    /* 53264 800BBA64 070022A6 */  sh         $v0, 0x7($s1)
    /* 53268 800BBA68 0B000286 */  lh         $v0, 0xB($s0)
    /* 5326C 800BBA6C 00000000 */  nop
    /* 53270 800BBA70 18004400 */  mult       $v0, $a0
    /* 53274 800BBA74 09000296 */  lhu        $v0, 0x9($s0)
    /* 53278 800BBA78 12380000 */  mflo       $a3
    /* 5327C 800BBA7C 031B0700 */  sra        $v1, $a3, 12
    /* 53280 800BBA80 21104300 */  addu       $v0, $v0, $v1
    /* 53284 800BBA84 090022A6 */  sh         $v0, 0x9($s1)
    /* 53288 800BBA88 0F000286 */  lh         $v0, 0xF($s0)
    /* 5328C 800BBA8C 00000000 */  nop
    /* 53290 800BBA90 18004400 */  mult       $v0, $a0
    /* 53294 800BBA94 0D000292 */  lbu        $v0, 0xD($s0)
    /* 53298 800BBA98 12380000 */  mflo       $a3
    /* 5329C 800BBA9C 031B0700 */  sra        $v1, $a3, 12
    /* 532A0 800BBAA0 21104300 */  addu       $v0, $v0, $v1
    /* 532A4 800BBAA4 000022A2 */  sb         $v0, 0x0($s1)
  .L800BBAA8:
    /* 532A8 800BBAA8 FFFF0292 */  lbu        $v0, -0x1($s0)
    /* 532AC 800BBAAC 00000392 */  lbu        $v1, 0x0($s0)
    /* 532B0 800BBAB0 00000000 */  nop
    /* 532B4 800BBAB4 2B104300 */  sltu       $v0, $v0, $v1
    /* 532B8 800BBAB8 03004014 */  bnez       $v0, .L800BBAC8
    /* 532BC 800BBABC 01004226 */   addiu     $v0, $s2, 0x1
    /* 532C0 800BBAC0 000000A2 */  sb         $zero, 0x0($s0)
  .L800BBAC4:
    /* 532C4 800BBAC4 01004226 */  addiu      $v0, $s2, 0x1
  .L800BBAC8:
    /* 532C8 800BBAC8 21904000 */  addu       $s2, $v0, $zero
    /* 532CC 800BBACC 14001026 */  addiu      $s0, $s0, 0x14
    /* 532D0 800BBAD0 00140200 */  sll        $v0, $v0, 16
    /* 532D4 800BBAD4 03140200 */  sra        $v0, $v0, 16
    /* 532D8 800BBAD8 03004228 */  slti       $v0, $v0, 0x3
    /* 532DC 800BBADC C0FF4014 */  bnez       $v0, .L800BB9E0
    /* 532E0 800BBAE0 F8033126 */   addiu     $s1, $s1, 0x3F8
    /* 532E4 800BBAE4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 532E8 800BBAE8 1800B28F */  lw         $s2, 0x18($sp)
    /* 532EC 800BBAEC 1400B18F */  lw         $s1, 0x14($sp)
    /* 532F0 800BBAF0 1000B08F */  lw         $s0, 0x10($sp)
    /* 532F4 800BBAF4 0800E003 */  jr         $ra
    /* 532F8 800BBAF8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800BB9B0
