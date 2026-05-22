nonmatching _loadMpdEnemySection, 0x88

glabel _loadMpdEnemySection
    /* 2145C 80089C5C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 21460 80089C60 1800B2AF */  sw         $s2, 0x18($sp)
    /* 21464 80089C64 21908000 */  addu       $s2, $a0, $zero
    /* 21468 80089C68 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2146C 80089C6C 2188A000 */  addu       $s1, $a1, $zero
    /* 21470 80089C70 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 21474 80089C74 11002012 */  beqz       $s1, .L80089CBC
    /* 21478 80089C78 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2147C 80089C7C B10F010C */  jal        vs_main_allocHeap
    /* 21480 80089C80 21202002 */   addu      $a0, $s1, $zero
    /* 21484 80089C84 21204000 */  addu       $a0, $v0, $zero
    /* 21488 80089C88 0F80103C */  lui        $s0, %hi(_zoneContext)
    /* 2148C 80089C8C 80181026 */  addiu      $s0, $s0, %lo(_zoneContext)
    /* 21490 80089C90 21284002 */  addu       $a1, $s2, $zero
    /* 21494 80089C94 21302002 */  addu       $a2, $s1, $zero
    /* 21498 80089C98 2C24010C */  jal        vs_main_memcpy
    /* 2149C 80089C9C 640004AE */   sw        $a0, 0x64($s0)
    /* 214A0 80089CA0 CCCC023C */  lui        $v0, (0xCCCCCCCD >> 16)
    /* 214A4 80089CA4 CDCC4234 */  ori        $v0, $v0, (0xCCCCCCCD & 0xFFFF)
    /* 214A8 80089CA8 19002202 */  multu      $s1, $v0
    /* 214AC 80089CAC 10180000 */  mfhi       $v1
    /* 214B0 80089CB0 42110300 */  srl        $v0, $v1, 5
    /* 214B4 80089CB4 33270208 */  j          .L80089CCC
    /* 214B8 80089CB8 600002AE */   sw        $v0, 0x60($s0)
  .L80089CBC:
    /* 214BC 80089CBC 0F80023C */  lui        $v0, %hi(_zoneContext)
    /* 214C0 80089CC0 80184224 */  addiu      $v0, $v0, %lo(_zoneContext)
    /* 214C4 80089CC4 640040AC */  sw         $zero, 0x64($v0)
    /* 214C8 80089CC8 600040AC */  sw         $zero, 0x60($v0)
  .L80089CCC:
    /* 214CC 80089CCC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 214D0 80089CD0 1800B28F */  lw         $s2, 0x18($sp)
    /* 214D4 80089CD4 1400B18F */  lw         $s1, 0x14($sp)
    /* 214D8 80089CD8 1000B08F */  lw         $s0, 0x10($sp)
    /* 214DC 80089CDC 0800E003 */  jr         $ra
    /* 214E0 80089CE0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _loadMpdEnemySection
