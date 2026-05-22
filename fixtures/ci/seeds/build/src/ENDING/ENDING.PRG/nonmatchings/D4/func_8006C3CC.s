nonmatching func_8006C3CC, 0x148

glabel func_8006C3CC
    /* 3BCC 8006C3CC C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 3BD0 8006C3D0 3400BFAF */  sw         $ra, 0x34($sp)
    /* 3BD4 8006C3D4 3000BEAF */  sw         $fp, 0x30($sp)
    /* 3BD8 8006C3D8 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 3BDC 8006C3DC 2800B6AF */  sw         $s6, 0x28($sp)
    /* 3BE0 8006C3E0 2400B5AF */  sw         $s5, 0x24($sp)
    /* 3BE4 8006C3E4 2000B4AF */  sw         $s4, 0x20($sp)
    /* 3BE8 8006C3E8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3BEC 8006C3EC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3BF0 8006C3F0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3BF4 8006C3F4 02008104 */  bgez       $a0, .L8006C400
    /* 3BF8 8006C3F8 1000B0AF */   sw        $s0, 0x10($sp)
    /* 3BFC 8006C3FC 21200000 */  addu       $a0, $zero, $zero
  .L8006C400:
    /* 3C00 8006C400 41008228 */  slti       $v0, $a0, 0x41
    /* 3C04 8006C404 02004014 */  bnez       $v0, .L8006C410
    /* 3C08 8006C408 00000000 */   nop
    /* 3C0C 8006C40C 40000424 */  addiu      $a0, $zero, 0x40
  .L8006C410:
    /* 3C10 8006C410 34008018 */  blez       $a0, .L8006C4E4
    /* 3C14 8006C414 40A00400 */   sll       $s4, $a0, 1
    /* 3C18 8006C418 801F133C */  lui        $s3, (0x1F800000 >> 16)
    /* 3C1C 8006C41C 0000738E */  lw         $s3, (0x1F800000 & 0xFFFF)($s3)
    /* 3C20 8006C420 21880000 */  addu       $s1, $zero, $zero
    /* 3C24 8006C424 08001E24 */  addiu      $fp, $zero, 0x8
    /* 3C28 8006C428 E8001724 */  addiu      $s7, $zero, 0xE8
    /* 3C2C 8006C42C 40001624 */  addiu      $s6, $zero, 0x40
    /* 3C30 8006C430 E0001524 */  addiu      $s5, $zero, 0xE0
    /* 3C34 8006C434 40001224 */  addiu      $s2, $zero, 0x40
    /* 3C38 8006C438 21806002 */  addu       $s0, $s3, $zero
    /* 3C3C 8006C43C 09000224 */  addiu      $v0, $zero, 0x9
  .L8006C440:
    /* 3C40 8006C440 030002A2 */  sb         $v0, 0x3($s0)
    /* 3C44 8006C444 2C000224 */  addiu      $v0, $zero, 0x2C
    /* 3C48 8006C448 070002A2 */  sb         $v0, 0x7($s0)
    /* 3C4C 8006C44C 80111100 */  sll        $v0, $s1, 6
    /* 3C50 8006C450 080002A6 */  sh         $v0, 0x8($s0)
    /* 3C54 8006C454 180002A6 */  sh         $v0, 0x18($s0)
    /* 3C58 8006C458 10002226 */  addiu      $v0, $s1, 0x10
    /* 3C5C 8006C45C 80014234 */  ori        $v0, $v0, 0x180
    /* 3C60 8006C460 21280002 */  addu       $a1, $s0, $zero
    /* 3C64 8006C464 0A001EA6 */  sh         $fp, 0xA($s0)
    /* 3C68 8006C468 100012A6 */  sh         $s2, 0x10($s0)
    /* 3C6C 8006C46C 12001EA6 */  sh         $fp, 0x12($s0)
    /* 3C70 8006C470 1A0017A6 */  sh         $s7, 0x1A($s0)
    /* 3C74 8006C474 200012A6 */  sh         $s2, 0x20($s0)
    /* 3C78 8006C478 220017A6 */  sh         $s7, 0x22($s0)
    /* 3C7C 8006C47C 0C0000A2 */  sb         $zero, 0xC($s0)
    /* 3C80 8006C480 0D0000A2 */  sb         $zero, 0xD($s0)
    /* 3C84 8006C484 140016A2 */  sb         $s6, 0x14($s0)
    /* 3C88 8006C488 150000A2 */  sb         $zero, 0x15($s0)
    /* 3C8C 8006C48C 1C0000A2 */  sb         $zero, 0x1C($s0)
    /* 3C90 8006C490 1D0015A2 */  sb         $s5, 0x1D($s0)
    /* 3C94 8006C494 240016A2 */  sb         $s6, 0x24($s0)
    /* 3C98 8006C498 250015A2 */  sb         $s5, 0x25($s0)
    /* 3C9C 8006C49C 040014A2 */  sb         $s4, 0x4($s0)
    /* 3CA0 8006C4A0 050014A2 */  sb         $s4, 0x5($s0)
    /* 3CA4 8006C4A4 060014A2 */  sb         $s4, 0x6($s0)
    /* 3CA8 8006C4A8 0E0000A6 */  sh         $zero, 0xE($s0)
    /* 3CAC 8006C4AC 160002A6 */  sh         $v0, 0x16($s0)
    /* 3CB0 8006C4B0 28001026 */  addiu      $s0, $s0, 0x28
    /* 3CB4 8006C4B4 28007326 */  addiu      $s3, $s3, 0x28
    /* 3CB8 8006C4B8 40005226 */  addiu      $s2, $s2, 0x40
    /* 3CBC 8006C4BC 801F043C */  lui        $a0, (0x1F800004 >> 16)
    /* 3CC0 8006C4C0 0400848C */  lw         $a0, (0x1F800004 & 0xFFFF)($a0)
    /* 3CC4 8006C4C4 01003126 */  addiu      $s1, $s1, 0x1
    /* 3CC8 8006C4C8 35AD000C */  jal        AddPrim
    /* 3CCC 8006C4CC F81F8424 */   addiu     $a0, $a0, 0x1FF8
    /* 3CD0 8006C4D0 0500222A */  slti       $v0, $s1, 0x5
    /* 3CD4 8006C4D4 DAFF4014 */  bnez       $v0, .L8006C440
    /* 3CD8 8006C4D8 09000224 */   addiu     $v0, $zero, 0x9
    /* 3CDC 8006C4DC 801F013C */  lui        $at, (0x1F800000 >> 16)
    /* 3CE0 8006C4E0 000033AC */  sw         $s3, (0x1F800000 & 0xFFFF)($at)
  .L8006C4E4:
    /* 3CE4 8006C4E4 3400BF8F */  lw         $ra, 0x34($sp)
    /* 3CE8 8006C4E8 3000BE8F */  lw         $fp, 0x30($sp)
    /* 3CEC 8006C4EC 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 3CF0 8006C4F0 2800B68F */  lw         $s6, 0x28($sp)
    /* 3CF4 8006C4F4 2400B58F */  lw         $s5, 0x24($sp)
    /* 3CF8 8006C4F8 2000B48F */  lw         $s4, 0x20($sp)
    /* 3CFC 8006C4FC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3D00 8006C500 1800B28F */  lw         $s2, 0x18($sp)
    /* 3D04 8006C504 1400B18F */  lw         $s1, 0x14($sp)
    /* 3D08 8006C508 1000B08F */  lw         $s0, 0x10($sp)
    /* 3D0C 8006C50C 0800E003 */  jr         $ra
    /* 3D10 8006C510 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8006C3CC
