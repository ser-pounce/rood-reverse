nonmatching vs_battle_setDoorEntered2, 0xDC

glabel vs_battle_setDoorEntered2
    /* 25148 8008D948 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0x9C)
    /* 2514C 8008D94C 941C438C */  lw         $v1, %lo(vs_battle_roomData + 0x9C)($v0)
    /* 25150 8008D950 0F80023C */  lui        $v0, %hi(vs_battle_doorEntered)
    /* 25154 8008D954 31006010 */  beqz       $v1, .L8008DA1C
    /* 25158 8008D958 BE1B44A4 */   sh        $a0, %lo(vs_battle_doorEntered)($v0)
    /* 2515C 8008D95C 21286000 */  addu       $a1, $v1, $zero
    /* 25160 8008D960 0000A38C */  lw         $v1, 0x0($a1)
    /* 25164 8008D964 00000000 */  nop
    /* 25168 8008D968 40100300 */  sll        $v0, $v1, 1
    /* 2516C 8008D96C 21104300 */  addu       $v0, $v0, $v1
    /* 25170 8008D970 80100200 */  sll        $v0, $v0, 2
    /* 25174 8008D974 04004224 */  addiu      $v0, $v0, 0x4
    /* 25178 8008D978 2128A200 */  addu       $a1, $a1, $v0
    /* 2517C 8008D97C 0000A28C */  lw         $v0, 0x0($a1)
    /* 25180 8008D980 00000000 */  nop
    /* 25184 8008D984 C0100200 */  sll        $v0, $v0, 3
    /* 25188 8008D988 04004224 */  addiu      $v0, $v0, 0x4
    /* 2518C 8008D98C 2128A200 */  addu       $a1, $a1, $v0
    /* 25190 8008D990 0000A28C */  lw         $v0, 0x0($a1)
    /* 25194 8008D994 00000000 */  nop
    /* 25198 8008D998 80100200 */  sll        $v0, $v0, 2
    /* 2519C 8008D99C 04004224 */  addiu      $v0, $v0, 0x4
    /* 251A0 8008D9A0 2128A200 */  addu       $a1, $a1, $v0
    /* 251A4 8008D9A4 0000A28C */  lw         $v0, 0x0($a1)
    /* 251A8 8008D9A8 00000000 */  nop
    /* 251AC 8008D9AC 80100200 */  sll        $v0, $v0, 2
    /* 251B0 8008D9B0 04004224 */  addiu      $v0, $v0, 0x4
    /* 251B4 8008D9B4 2128A200 */  addu       $a1, $a1, $v0
    /* 251B8 8008D9B8 0000A28C */  lw         $v0, 0x0($a1)
    /* 251BC 8008D9BC 00000000 */  nop
    /* 251C0 8008D9C0 80100200 */  sll        $v0, $v0, 2
    /* 251C4 8008D9C4 04004224 */  addiu      $v0, $v0, 0x4
    /* 251C8 8008D9C8 2128A200 */  addu       $a1, $a1, $v0
    /* 251CC 8008D9CC 0000A28C */  lw         $v0, 0x0($a1)
    /* 251D0 8008D9D0 21300000 */  addu       $a2, $zero, $zero
    /* 251D4 8008D9D4 80100200 */  sll        $v0, $v0, 2
    /* 251D8 8008D9D8 04004224 */  addiu      $v0, $v0, 0x4
    /* 251DC 8008D9DC 2128A200 */  addu       $a1, $a1, $v0
    /* 251E0 8008D9E0 0000A78C */  lw         $a3, 0x0($a1)
    /* 251E4 8008D9E4 00000000 */  nop
    /* 251E8 8008D9E8 0C00E018 */  blez       $a3, .L8008DA1C
    /* 251EC 8008D9EC 0400A524 */   addiu     $a1, $a1, 0x4
    /* 251F0 8008D9F0 0200A324 */  addiu      $v1, $a1, 0x2
  .L8008D9F4:
    /* 251F4 8008D9F4 0500C414 */  bne        $a2, $a0, .L8008DA0C
    /* 251F8 8008D9F8 00000000 */   nop
    /* 251FC 8008D9FC 00006290 */  lbu        $v0, 0x0($v1)
    /* 25200 8008DA00 00000000 */  nop
    /* 25204 8008DA04 10004234 */  ori        $v0, $v0, 0x10
    /* 25208 8008DA08 000062A0 */  sb         $v0, 0x0($v1)
  .L8008DA0C:
    /* 2520C 8008DA0C 0100C624 */  addiu      $a2, $a2, 0x1
    /* 25210 8008DA10 2A10C700 */  slt        $v0, $a2, $a3
    /* 25214 8008DA14 F7FF4014 */  bnez       $v0, .L8008D9F4
    /* 25218 8008DA18 04006324 */   addiu     $v1, $v1, 0x4
  .L8008DA1C:
    /* 2521C 8008DA1C 0800E003 */  jr         $ra
    /* 25220 8008DA20 00000000 */   nop
endlabel vs_battle_setDoorEntered2
