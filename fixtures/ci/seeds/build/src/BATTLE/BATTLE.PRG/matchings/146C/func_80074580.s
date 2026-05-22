nonmatching func_80074580, 0x6C

glabel func_80074580
    /* BD80 80074580 0680023C */  lui        $v0, %hi(vs_main_projectionDistance)
    /* BD84 80074584 48E2428C */  lw         $v0, %lo(vs_main_projectionDistance)($v0)
    /* BD88 80074588 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* BD8C 8007458C 10014228 */  slti       $v0, $v0, 0x110
    /* BD90 80074590 07004010 */  beqz       $v0, .L800745B0
    /* BD94 80074594 1000BFAF */   sw        $ra, 0x10($sp)
    /* BD98 80074598 F882020C */  jal        func_800A0BE0
    /* BD9C 8007459C 21200000 */   addu      $a0, $zero, $zero
    /* BDA0 800745A0 21200000 */  addu       $a0, $zero, $zero
    /* BDA4 800745A4 FDFF0524 */  addiu      $a1, $zero, -0x3
    /* BDA8 800745A8 1F82020C */  jal        func_800A087C
    /* BDAC 800745AC 24284500 */   and       $a1, $v0, $a1
  .L800745B0:
    /* BDB0 800745B0 81BC010C */  jal        _stepCameraTransition
    /* BDB4 800745B4 00000000 */   nop
    /* BDB8 800745B8 08004010 */  beqz       $v0, .L800745DC
    /* BDBC 800745BC 0F80023C */   lui       $v0, %hi(_cameraMode)
    /* BDC0 800745C0 01000324 */  addiu      $v1, $zero, 0x1
    /* BDC4 800745C4 F01843AC */  sw         $v1, %lo(_cameraMode)($v0)
    /* BDC8 800745C8 0F80023C */  lui        $v0, %hi(_firstPersonViewEnabled)
    /* BDCC 800745CC 6C1843AC */  sw         $v1, %lo(_firstPersonViewEnabled)($v0)
    /* BDD0 800745D0 0F80023C */  lui        $v0, %hi(D_800F19C8)
    /* BDD4 800745D4 0331020C */  jal        func_8008C40C
    /* BDD8 800745D8 C81943AC */   sw        $v1, %lo(D_800F19C8)($v0)
  .L800745DC:
    /* BDDC 800745DC 1000BF8F */  lw         $ra, 0x10($sp)
    /* BDE0 800745E0 00000000 */  nop
    /* BDE4 800745E4 0800E003 */  jr         $ra
    /* BDE8 800745E8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80074580
