nonmatching SoundVM_FE19_unk, 0x90

glabel SoundVM_FE19_unk
    /* BE54 8001B654 21308000 */  addu       $a2, $a0, $zero
    /* BE58 8001B658 0000C28C */  lw         $v0, 0x0($a2)
    /* BE5C 8001B65C 00000000 */  nop
    /* BE60 8001B660 00004380 */  lb         $v1, 0x0($v0)
    /* BE64 8001B664 01004224 */  addiu      $v0, $v0, 0x1
    /* BE68 8001B668 0000C2AC */  sw         $v0, 0x0($a2)
    /* BE6C 8001B66C C01D0300 */  sll        $v1, $v1, 23
    /* BE70 8001B670 5C00C3AC */  sw         $v1, 0x5C($a2)
    /* BE74 8001B674 00004390 */  lbu        $v1, 0x0($v0)
    /* BE78 8001B678 01004224 */  addiu      $v0, $v0, 0x1
    /* BE7C 8001B67C 0000C2AC */  sw         $v0, 0x0($a2)
    /* BE80 8001B680 03006014 */  bnez       $v1, .L8001B690
    /* BE84 8001B684 8A00C3A4 */   sh        $v1, 0x8A($a2)
    /* BE88 8001B688 00010224 */  addiu      $v0, $zero, 0x100
    /* BE8C 8001B68C 8A00C2A4 */  sh         $v0, 0x8A($a2)
  .L8001B690:
    /* BE90 8001B690 0000C48C */  lw         $a0, 0x0($a2)
    /* BE94 8001B694 5C00C58C */  lw         $a1, 0x5C($a2)
    /* BE98 8001B698 00008280 */  lb         $v0, 0x0($a0)
    /* BE9C 8001B69C 8A00C394 */  lhu        $v1, 0x8A($a2)
    /* BEA0 8001B6A0 C0150200 */  sll        $v0, $v0, 23
    /* BEA4 8001B6A4 23104500 */  subu       $v0, $v0, $a1
    /* BEA8 8001B6A8 1A004300 */  div        $zero, $v0, $v1
    /* BEAC 8001B6AC 02006014 */  bnez       $v1, .L8001B6B8
    /* BEB0 8001B6B0 00000000 */   nop
    /* BEB4 8001B6B4 0D000700 */  break      7
  .L8001B6B8:
    /* BEB8 8001B6B8 FFFF0124 */  addiu      $at, $zero, -0x1
    /* BEBC 8001B6BC 04006114 */  bne        $v1, $at, .L8001B6D0
    /* BEC0 8001B6C0 0080013C */   lui       $at, (0x80000000 >> 16)
    /* BEC4 8001B6C4 02004114 */  bne        $v0, $at, .L8001B6D0
    /* BEC8 8001B6C8 00000000 */   nop
    /* BECC 8001B6CC 0D000600 */  break      6
  .L8001B6D0:
    /* BED0 8001B6D0 12100000 */  mflo       $v0
    /* BED4 8001B6D4 01008424 */  addiu      $a0, $a0, 0x1
    /* BED8 8001B6D8 0000C4AC */  sw         $a0, 0x0($a2)
    /* BEDC 8001B6DC 0800E003 */  jr         $ra
    /* BEE0 8001B6E0 6000C2AC */   sw        $v0, 0x60($a2)
endlabel SoundVM_FE19_unk
