nonmatching SoundVM_BB_SustainMode, 0x78

glabel SoundVM_BB_SustainMode
    /* CDB0 8001C5B0 21288000 */  addu       $a1, $a0, $zero
    /* CDB4 8001C5B4 0000A28C */  lw         $v0, 0x0($a1)
    /* CDB8 8001C5B8 0801A394 */  lhu        $v1, 0x108($a1)
    /* CDBC 8001C5BC 00004490 */  lbu        $a0, 0x0($v0)
    /* CDC0 8001C5C0 01004224 */  addiu      $v0, $v0, 0x1
    /* CDC4 8001C5C4 FF3F6330 */  andi       $v1, $v1, 0x3FFF
    /* CDC8 8001C5C8 0000A2AC */  sw         $v0, 0x0($a1)
    /* CDCC 8001C5CC 05000224 */  addiu      $v0, $zero, 0x5
    /* CDD0 8001C5D0 FFFF8430 */  andi       $a0, $a0, 0xFFFF
    /* CDD4 8001C5D4 0D008210 */  beq        $a0, $v0, .L8001C60C
    /* CDD8 8001C5D8 0801A3A4 */   sh        $v1, 0x108($a1)
    /* CDDC 8001C5DC 06008228 */  slti       $v0, $a0, 0x6
    /* CDE0 8001C5E0 05004010 */  beqz       $v0, .L8001C5F8
    /* CDE4 8001C5E4 03000224 */   addiu     $v0, $zero, 0x3
    /* CDE8 8001C5E8 09008210 */  beq        $a0, $v0, .L8001C610
    /* CDEC 8001C5EC 00406234 */   ori       $v0, $v1, 0x4000
    /* CDF0 8001C5F0 85710008 */  j          .L8001C614
    /* CDF4 8001C5F4 00000000 */   nop
  .L8001C5F8:
    /* CDF8 8001C5F8 07000224 */  addiu      $v0, $zero, 0x7
    /* CDFC 8001C5FC 04008210 */  beq        $a0, $v0, .L8001C610
    /* CE00 8001C600 00C06234 */   ori       $v0, $v1, 0xC000
    /* CE04 8001C604 85710008 */  j          .L8001C614
    /* CE08 8001C608 00000000 */   nop
  .L8001C60C:
    /* CE0C 8001C60C 00806234 */  ori        $v0, $v1, 0x8000
  .L8001C610:
    /* CE10 8001C610 0801A2A4 */  sh         $v0, 0x108($a1)
  .L8001C614:
    /* CE14 8001C614 F800A28C */  lw         $v0, 0xF8($a1)
    /* CE18 8001C618 00000000 */  nop
    /* CE1C 8001C61C 00024234 */  ori        $v0, $v0, 0x200
    /* CE20 8001C620 0800E003 */  jr         $ra
    /* CE24 8001C624 F800A2AC */   sw        $v0, 0xF8($a1)
endlabel SoundVM_BB_SustainMode
