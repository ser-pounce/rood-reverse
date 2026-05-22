nonmatching func_800B6B98, 0x1B0

glabel func_800B6B98
    /* 4E398 800B6B98 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 4E39C 800B6B9C 2400B1AF */  sw         $s1, 0x24($sp)
    /* 4E3A0 800B6BA0 21888000 */  addu       $s1, $a0, $zero
    /* 4E3A4 800B6BA4 2000B0AF */  sw         $s0, 0x20($sp)
    /* 4E3A8 800B6BA8 2180A000 */  addu       $s0, $a1, $zero
    /* 4E3AC 800B6BAC 2800B2AF */  sw         $s2, 0x28($sp)
    /* 4E3B0 800B6BB0 2190C000 */  addu       $s2, $a2, $zero
    /* 4E3B4 800B6BB4 1800A427 */  addiu      $a0, $sp, 0x18
    /* 4E3B8 800B6BB8 FF00E730 */  andi       $a3, $a3, 0xFF
    /* 4E3BC 800B6BBC 3000BFAF */  sw         $ra, 0x30($sp)
    /* 4E3C0 800B6BC0 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 4E3C4 800B6BC4 05000592 */  lbu        $a1, 0x5($s0)
    /* 4E3C8 800B6BC8 04002686 */  lh         $a2, 0x4($s1)
    /* 4E3CC 800B6BCC 06000392 */  lbu        $v1, 0x6($s0)
    /* 4E3D0 800B6BD0 07000292 */  lbu        $v0, 0x7($s0)
    /* 4E3D4 800B6BD4 2630C700 */  xor        $a2, $a2, $a3
    /* 4E3D8 800B6BD8 0F00A530 */  andi       $a1, $a1, 0xF
    /* 4E3DC 800B6BDC 80300600 */  sll        $a2, $a2, 2
    /* 4E3E0 800B6BE0 21386000 */  addu       $a3, $v1, $zero
    /* 4E3E4 800B6BE4 8433030C */  jal        func_800CCE10
    /* 4E3E8 800B6BE8 1000A2AF */   sw        $v0, 0x10($sp)
    /* 4E3EC 800B6BEC 1800A28F */  lw         $v0, 0x18($sp)
    /* 4E3F0 800B6BF0 21980000 */  addu       $s3, $zero, $zero
    /* 4E3F4 800B6BF4 000042AE */  sw         $v0, 0x0($s2)
    /* 4E3F8 800B6BF8 00150200 */  sll        $v0, $v0, 20
    /* 4E3FC 800B6BFC 03150200 */  sra        $v0, $v0, 20
    /* 4E400 800B6C00 00002496 */  lhu        $a0, 0x0($s1)
    /* 4E404 800B6C04 0000438E */  lw         $v1, 0x0($s2)
    /* 4E408 800B6C08 21308200 */  addu       $a2, $a0, $v0
    /* 4E40C 800B6C0C 001A0300 */  sll        $v1, $v1, 8
    /* 4E410 800B6C10 040046A6 */  sh         $a2, 0x4($s2)
    /* 4E414 800B6C14 02002496 */  lhu        $a0, 0x2($s1)
    /* 4E418 800B6C18 031D0300 */  sra        $v1, $v1, 20
    /* 4E41C 800B6C1C 21208300 */  addu       $a0, $a0, $v1
    /* 4E420 800B6C20 060044A6 */  sh         $a0, 0x6($s2)
    /* 4E424 800B6C24 07000392 */  lbu        $v1, 0x7($s0)
    /* 4E428 800B6C28 00000000 */  nop
    /* 4E42C 800B6C2C 40100300 */  sll        $v0, $v1, 1
    /* 4E430 800B6C30 21104300 */  addu       $v0, $v0, $v1
    /* 4E434 800B6C34 80100200 */  sll        $v0, $v0, 2
    /* 4E438 800B6C38 21104300 */  addu       $v0, $v0, $v1
    /* 4E43C 800B6C3C 06000392 */  lbu        $v1, 0x6($s0)
    /* 4E440 800B6C40 04004724 */  addiu      $a3, $v0, 0x4
    /* 4E444 800B6C44 40100300 */  sll        $v0, $v1, 1
    /* 4E448 800B6C48 21104300 */  addu       $v0, $v0, $v1
    /* 4E44C 800B6C4C 80100200 */  sll        $v0, $v0, 2
    /* 4E450 800B6C50 08004524 */  addiu      $a1, $v0, 0x8
    /* 4E454 800B6C54 00140600 */  sll        $v0, $a2, 16
    /* 4E458 800B6C58 031C0200 */  sra        $v1, $v0, 16
    /* 4E45C 800B6C5C 04006228 */  slti       $v0, $v1, 0x4
    /* 4E460 800B6C60 06004010 */  beqz       $v0, .L800B6C7C
    /* 4E464 800B6C64 21886002 */   addu      $s1, $s3, $zero
    /* 4E468 800B6C68 04000224 */  addiu      $v0, $zero, 0x4
    /* 4E46C 800B6C6C 040042A6 */  sh         $v0, 0x4($s2)
    /* 4E470 800B6C70 04000224 */  addiu      $v0, $zero, 0x4
    /* 4E474 800B6C74 27DB0208 */  j          .L800B6C9C
    /* 4E478 800B6C78 23984300 */   subu      $s3, $v0, $v1
  .L800B6C7C:
    /* 4E47C 800B6C7C 21106500 */  addu       $v0, $v1, $a1
    /* 4E480 800B6C80 41014228 */  slti       $v0, $v0, 0x141
    /* 4E484 800B6C84 06004014 */  bnez       $v0, .L800B6CA0
    /* 4E488 800B6C88 00140400 */   sll       $v0, $a0, 16
    /* 4E48C 800B6C8C 40010224 */  addiu      $v0, $zero, 0x140
    /* 4E490 800B6C90 23104500 */  subu       $v0, $v0, $a1
    /* 4E494 800B6C94 040042A6 */  sh         $v0, 0x4($s2)
    /* 4E498 800B6C98 23984600 */  subu       $s3, $v0, $a2
  .L800B6C9C:
    /* 4E49C 800B6C9C 00140400 */  sll        $v0, $a0, 16
  .L800B6CA0:
    /* 4E4A0 800B6CA0 031C0200 */  sra        $v1, $v0, 16
    /* 4E4A4 800B6CA4 04006228 */  slti       $v0, $v1, 0x4
    /* 4E4A8 800B6CA8 05004010 */  beqz       $v0, .L800B6CC0
    /* 4E4AC 800B6CAC 04000224 */   addiu     $v0, $zero, 0x4
    /* 4E4B0 800B6CB0 060042A6 */  sh         $v0, 0x6($s2)
    /* 4E4B4 800B6CB4 04000224 */  addiu      $v0, $zero, 0x4
    /* 4E4B8 800B6CB8 38DB0208 */  j          .L800B6CE0
    /* 4E4BC 800B6CBC 23884300 */   subu      $s1, $v0, $v1
  .L800B6CC0:
    /* 4E4C0 800B6CC0 2110E300 */  addu       $v0, $a3, $v1
    /* 4E4C4 800B6CC4 D9004228 */  slti       $v0, $v0, 0xD9
    /* 4E4C8 800B6CC8 06004014 */  bnez       $v0, .L800B6CE4
    /* 4E4CC 800B6CCC 00141300 */   sll       $v0, $s3, 16
    /* 4E4D0 800B6CD0 D8000224 */  addiu      $v0, $zero, 0xD8
    /* 4E4D4 800B6CD4 23104700 */  subu       $v0, $v0, $a3
    /* 4E4D8 800B6CD8 060042A6 */  sh         $v0, 0x6($s2)
    /* 4E4DC 800B6CDC 23884400 */  subu       $s1, $v0, $a0
  .L800B6CE0:
    /* 4E4E0 800B6CE0 00141300 */  sll        $v0, $s3, 16
  .L800B6CE4:
    /* 4E4E4 800B6CE4 06004014 */  bnez       $v0, .L800B6D00
    /* 4E4E8 800B6CE8 00141300 */   sll       $v0, $s3, 16
    /* 4E4EC 800B6CEC 00141100 */  sll        $v0, $s1, 16
    /* 4E4F0 800B6CF0 03004014 */  bnez       $v0, .L800B6D00
    /* 4E4F4 800B6CF4 00141300 */   sll       $v0, $s3, 16
    /* 4E4F8 800B6CF8 4BDB0208 */  j          .L800B6D2C
    /* 4E4FC 800B6CFC 01000224 */   addiu     $v0, $zero, 0x1
  .L800B6D00:
    /* 4E500 800B6D00 03140200 */  sra        $v0, $v0, 16
    /* 4E504 800B6D04 18004200 */  mult       $v0, $v0
    /* 4E508 800B6D08 12180000 */  mflo       $v1
    /* 4E50C 800B6D0C 00141100 */  sll        $v0, $s1, 16
    /* 4E510 800B6D10 03140200 */  sra        $v0, $v0, 16
    /* 4E514 800B6D14 18004200 */  mult       $v0, $v0
    /* 4E518 800B6D18 12480000 */  mflo       $t1
    /* 4E51C 800B6D1C E506010C */  jal        vs_gte_rsqrt
    /* 4E520 800B6D20 21206900 */   addu      $a0, $v1, $t1
    /* 4E524 800B6D24 080042AE */  sw         $v0, 0x8($s2)
    /* 4E528 800B6D28 21100000 */  addu       $v0, $zero, $zero
  .L800B6D2C:
    /* 4E52C 800B6D2C 3000BF8F */  lw         $ra, 0x30($sp)
    /* 4E530 800B6D30 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 4E534 800B6D34 2800B28F */  lw         $s2, 0x28($sp)
    /* 4E538 800B6D38 2400B18F */  lw         $s1, 0x24($sp)
    /* 4E53C 800B6D3C 2000B08F */  lw         $s0, 0x20($sp)
    /* 4E540 800B6D40 0800E003 */  jr         $ra
    /* 4E544 800B6D44 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_800B6B98
