nonmatching func_800D49A4, 0xF0

glabel func_800D49A4
    /* 6C1A4 800D49A4 540D8394 */  lhu        $v1, 0xD54($a0)
    /* 6C1A8 800D49A8 00000000 */  nop
    /* 6C1AC 800D49AC FAFF6224 */  addiu      $v0, $v1, -0x6
    /* 6C1B0 800D49B0 1000422C */  sltiu      $v0, $v0, 0x10
    /* 6C1B4 800D49B4 09004014 */  bnez       $v0, .L800D49DC
    /* 6C1B8 800D49B8 0F80023C */   lui       $v0, %hi(D_800F569C)
    /* 6C1BC 800D49BC 00140300 */  sll        $v0, $v1, 16
    /* 6C1C0 800D49C0 031C0200 */  sra        $v1, $v0, 16
    /* 6C1C4 800D49C4 21000224 */  addiu      $v0, $zero, 0x21
    /* 6C1C8 800D49C8 03006210 */  beq        $v1, $v0, .L800D49D8
    /* 6C1CC 800D49CC 24000224 */   addiu     $v0, $zero, 0x24
    /* 6C1D0 800D49D0 15006214 */  bne        $v1, $v0, .L800D4A28
    /* 6C1D4 800D49D4 38000224 */   addiu     $v0, $zero, 0x38
  .L800D49D8:
    /* 6C1D8 800D49D8 0F80023C */  lui        $v0, %hi(D_800F569C)
  .L800D49DC:
    /* 6C1DC 800D49DC 9C56458C */  lw         $a1, %lo(D_800F569C)($v0)
    /* 6C1E0 800D49E0 00000000 */  nop
    /* 6C1E4 800D49E4 B400A28C */  lw         $v0, 0xB4($a1)
    /* 6C1E8 800D49E8 00000000 */  nop
    /* 6C1EC 800D49EC 15004290 */  lbu        $v0, 0x15($v0)
    /* 6C1F0 800D49F0 00000000 */  nop
    /* 6C1F4 800D49F4 24004010 */  beqz       $v0, .L800D4A88
    /* 6C1F8 800D49F8 21180000 */   addu      $v1, $zero, $zero
    /* 6C1FC 800D49FC 80FF0624 */  addiu      $a2, $zero, -0x80
  .L800D4A00:
    /* 6C200 800D4A00 3C0086AC */  sw         $a2, 0x3C($a0)
    /* 6C204 800D4A04 B400A28C */  lw         $v0, 0xB4($a1)
    /* 6C208 800D4A08 00000000 */  nop
    /* 6C20C 800D4A0C 15004290 */  lbu        $v0, 0x15($v0)
    /* 6C210 800D4A10 01006324 */  addiu      $v1, $v1, 0x1
    /* 6C214 800D4A14 2A106200 */  slt        $v0, $v1, $v0
    /* 6C218 800D4A18 F9FF4014 */  bnez       $v0, .L800D4A00
    /* 6C21C 800D4A1C D0008424 */   addiu     $a0, $a0, 0xD0
    /* 6C220 800D4A20 0800E003 */  jr         $ra
    /* 6C224 800D4A24 01000224 */   addiu     $v0, $zero, 0x1
  .L800D4A28:
    /* 6C228 800D4A28 18006214 */  bne        $v1, $v0, .L800D4A8C
    /* 6C22C 800D4A2C 01000224 */   addiu     $v0, $zero, 0x1
    /* 6C230 800D4A30 13008390 */  lbu        $v1, 0x13($a0)
    /* 6C234 800D4A34 2B000224 */  addiu      $v0, $zero, 0x2B
    /* 6C238 800D4A38 14006214 */  bne        $v1, $v0, .L800D4A8C
    /* 6C23C 800D4A3C 01000224 */   addiu     $v0, $zero, 0x1
    /* 6C240 800D4A40 0F80023C */  lui        $v0, %hi(D_800F569C)
    /* 6C244 800D4A44 9C56458C */  lw         $a1, %lo(D_800F569C)($v0)
    /* 6C248 800D4A48 00000000 */  nop
    /* 6C24C 800D4A4C B400A28C */  lw         $v0, 0xB4($a1)
    /* 6C250 800D4A50 00000000 */  nop
    /* 6C254 800D4A54 15004290 */  lbu        $v0, 0x15($v0)
    /* 6C258 800D4A58 00000000 */  nop
    /* 6C25C 800D4A5C 0A004010 */  beqz       $v0, .L800D4A88
    /* 6C260 800D4A60 21180000 */   addu      $v1, $zero, $zero
    /* 6C264 800D4A64 80000624 */  addiu      $a2, $zero, 0x80
  .L800D4A68:
    /* 6C268 800D4A68 3C0086AC */  sw         $a2, 0x3C($a0)
    /* 6C26C 800D4A6C B400A28C */  lw         $v0, 0xB4($a1)
    /* 6C270 800D4A70 00000000 */  nop
    /* 6C274 800D4A74 15004290 */  lbu        $v0, 0x15($v0)
    /* 6C278 800D4A78 01006324 */  addiu      $v1, $v1, 0x1
    /* 6C27C 800D4A7C 2A106200 */  slt        $v0, $v1, $v0
    /* 6C280 800D4A80 F9FF4014 */  bnez       $v0, .L800D4A68
    /* 6C284 800D4A84 D0008424 */   addiu     $a0, $a0, 0xD0
  .L800D4A88:
    /* 6C288 800D4A88 01000224 */  addiu      $v0, $zero, 0x1
  .L800D4A8C:
    /* 6C28C 800D4A8C 0800E003 */  jr         $ra
    /* 6C290 800D4A90 00000000 */   nop
endlabel func_800D49A4
