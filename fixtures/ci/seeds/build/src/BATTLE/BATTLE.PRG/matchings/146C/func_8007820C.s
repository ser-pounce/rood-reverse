nonmatching func_8007820C, 0x3C

glabel func_8007820C
    /* FA0C 8007820C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* FA10 80078210 1800B0AF */  sw         $s0, 0x18($sp)
    /* FA14 80078214 21808000 */  addu       $s0, $a0, $zero
    /* FA18 80078218 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* FA1C 8007821C 2AE0010C */  jal        func_800780A8
    /* FA20 80078220 1000A427 */   addiu     $a0, $sp, 0x10
    /* FA24 80078224 04000012 */  beqz       $s0, .L80078238
    /* FA28 80078228 1000A427 */   addiu     $a0, $sp, 0x10
    /* FA2C 8007822C 01000524 */  addiu      $a1, $zero, 0x1
    /* FA30 80078230 BFB7010C */  jal        _stepTowardTarget
    /* FA34 80078234 28000624 */   addiu     $a2, $zero, 0x28
  .L80078238:
    /* FA38 80078238 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* FA3C 8007823C 1800B08F */  lw         $s0, 0x18($sp)
    /* FA40 80078240 0800E003 */  jr         $ra
    /* FA44 80078244 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007820C
