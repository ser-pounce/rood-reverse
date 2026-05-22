nonmatching func_800AB358, 0x198

glabel func_800AB358
    /* 42B58 800AB358 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 42B5C 800AB35C 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 42B60 800AB360 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 42B64 800AB364 80200400 */  sll        $a0, $a0, 2
    /* 42B68 800AB368 21208200 */  addu       $a0, $a0, $v0
    /* 42B6C 800AB36C 0F80033C */  lui        $v1, %hi(D_800E8F2C)
    /* 42B70 800AB370 0F80023C */  lui        $v0, %hi(D_800F2450)
    /* 42B74 800AB374 2C8F6390 */  lbu        $v1, %lo(D_800E8F2C)($v1)
    /* 42B78 800AB378 50244224 */  addiu      $v0, $v0, %lo(D_800F2450)
    /* 42B7C 800AB37C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 42B80 800AB380 1800B0AF */  sw         $s0, 0x18($sp)
    /* 42B84 800AB384 21106200 */  addu       $v0, $v1, $v0
    /* 42B88 800AB388 00004290 */  lbu        $v0, 0x0($v0)
    /* 42B8C 800AB38C 0000868C */  lw         $a2, 0x0($a0)
    /* 42B90 800AB390 52004010 */  beqz       $v0, .L800AB4DC
    /* 42B94 800AB394 2110C300 */   addu      $v0, $a2, $v1
    /* 42B98 800AB398 0200AB90 */  lbu        $t3, 0x2($a1)
    /* 42B9C 800AB39C 0300AD90 */  lbu        $t5, 0x3($a1)
    /* 42BA0 800AB3A0 3E184390 */  lbu        $v1, 0x183E($v0)
    /* 42BA4 800AB3A4 0100A290 */  lbu        $v0, 0x1($a1)
    /* 42BA8 800AB3A8 2168A301 */  addu       $t5, $t5, $v1
    /* 42BAC 800AB3AC 80100200 */  sll        $v0, $v0, 2
    /* 42BB0 800AB3B0 F4054224 */  addiu      $v0, $v0, 0x5F4
    /* 42BB4 800AB3B4 2160C200 */  addu       $t4, $a2, $v0
    /* 42BB8 800AB3B8 0008033C */  lui        $v1, (0x8000000 >> 16)
    /* 42BBC 800AB3BC 00008A91 */  lbu        $t2, 0x0($t4)
    /* 42BC0 800AB3C0 02008991 */  lbu        $t1, 0x2($t4)
    /* 42BC4 800AB3C4 AC05C28C */  lw         $v0, 0x5AC($a2)
    /* 42BC8 800AB3C8 03008E91 */  lbu        $t6, 0x3($t4)
    /* 42BCC 800AB3CC 24104300 */  and        $v0, $v0, $v1
    /* 42BD0 800AB3D0 0E004014 */  bnez       $v0, .L800AB40C
    /* 42BD4 800AB3D4 00000000 */   nop
    /* 42BD8 800AB3D8 02006105 */  bgez       $t3, .L800AB3E4
    /* 42BDC 800AB3DC 21106001 */   addu      $v0, $t3, $zero
    /* 42BE0 800AB3E0 03006225 */  addiu      $v0, $t3, 0x3
  .L800AB3E4:
    /* 42BE4 800AB3E4 83580200 */  sra        $t3, $v0, 2
    /* 42BE8 800AB3E8 02002105 */  bgez       $t1, .L800AB3F4
    /* 42BEC 800AB3EC 21102001 */   addu      $v0, $t1, $zero
    /* 42BF0 800AB3F0 03002225 */  addiu      $v0, $t1, 0x3
  .L800AB3F4:
    /* 42BF4 800AB3F4 83480200 */  sra        $t1, $v0, 2
    /* 42BF8 800AB3F8 02004105 */  bgez       $t2, .L800AB404
    /* 42BFC 800AB3FC 21104001 */   addu      $v0, $t2, $zero
    /* 42C00 800AB400 03004225 */  addiu      $v0, $t2, 0x3
  .L800AB404:
    /* 42C04 800AB404 0CAD0208 */  j          .L800AB430
    /* 42C08 800AB408 83500200 */   sra       $t2, $v0, 2
  .L800AB40C:
    /* 42C0C 800AB40C C2170B00 */  srl        $v0, $t3, 31
    /* 42C10 800AB410 21106201 */  addu       $v0, $t3, $v0
    /* 42C14 800AB414 43580200 */  sra        $t3, $v0, 1
    /* 42C18 800AB418 C2170900 */  srl        $v0, $t1, 31
    /* 42C1C 800AB41C 21102201 */  addu       $v0, $t1, $v0
    /* 42C20 800AB420 43480200 */  sra        $t1, $v0, 1
    /* 42C24 800AB424 C2170A00 */  srl        $v0, $t2, 31
    /* 42C28 800AB428 21104201 */  addu       $v0, $t2, $v0
    /* 42C2C 800AB42C 43500200 */  sra        $t2, $v0, 1
  .L800AB430:
    /* 42C30 800AB430 0F80053C */  lui        $a1, %hi(D_800E8F30)
    /* 42C34 800AB434 308FA524 */  addiu      $a1, $a1, %lo(D_800E8F30)
    /* 42C38 800AB438 0F80033C */  lui        $v1, %hi(D_800E8F2C)
    /* 42C3C 800AB43C 801F103C */  lui        $s0, (0x1F800000 >> 16)
    /* 42C40 800AB440 0000108E */  lw         $s0, (0x1F800000 & 0xFFFF)($s0)
    /* 42C44 800AB444 BB05C890 */  lbu        $t0, 0x5BB($a2)
    /* 42C48 800AB448 2C8F6390 */  lbu        $v1, %lo(D_800E8F2C)($v1)
    /* 42C4C 800AB44C 21200002 */  addu       $a0, $s0, $zero
    /* 42C50 800AB450 80100800 */  sll        $v0, $t0, 2
    /* 42C54 800AB454 21304500 */  addu       $a2, $v0, $a1
    /* 42C58 800AB458 2128A200 */  addu       $a1, $a1, $v0
    /* 42C5C 800AB45C 0F80023C */  lui        $v0, %hi(D_800E8F90)
    /* 42C60 800AB460 908F4224 */  addiu      $v0, $v0, %lo(D_800E8F90)
    /* 42C64 800AB464 21400201 */  addu       $t0, $t0, $v0
    /* 42C68 800AB468 0F80023C */  lui        $v0, %hi(D_800F2450)
    /* 42C6C 800AB46C 50244224 */  addiu      $v0, $v0, %lo(D_800F2450)
    /* 42C70 800AB470 21186200 */  addu       $v1, $v1, $v0
    /* 42C74 800AB474 0000C684 */  lh         $a2, 0x0($a2)
    /* 42C78 800AB478 0200A784 */  lh         $a3, 0x2($a1)
    /* 42C7C 800AB47C 00000591 */  lbu        $a1, 0x0($t0)
    /* 42C80 800AB480 01008891 */  lbu        $t0, 0x1($t4)
    /* 42C84 800AB484 00006290 */  lbu        $v0, 0x0($v1)
    /* 42C88 800AB488 0001A325 */  addiu      $v1, $t5, 0x100
    /* 42C8C 800AB48C 1200A3A7 */  sh         $v1, 0x12($sp)
    /* 42C90 800AB490 1400A9A7 */  sh         $t1, 0x14($sp)
    /* 42C94 800AB494 1600AEA7 */  sh         $t6, 0x16($sp)
    /* 42C98 800AB498 0F004230 */  andi       $v0, $v0, 0xF
    /* 42C9C 800AB49C 80110200 */  sll        $v0, $v0, 6
    /* 42CA0 800AB4A0 21104B00 */  addu       $v0, $v0, $t3
    /* 42CA4 800AB4A4 80310600 */  sll        $a2, $a2, 6
    /* 42CA8 800AB4A8 003A0700 */  sll        $a3, $a3, 8
    /* 42CAC 800AB4AC 80290500 */  sll        $a1, $a1, 6
    /* 42CB0 800AB4B0 2138E500 */  addu       $a3, $a3, $a1
    /* 42CB4 800AB4B4 1000A527 */  addiu      $a1, $sp, 0x10
    /* 42CB8 800AB4B8 21304601 */  addu       $a2, $t2, $a2
    /* 42CBC 800AB4BC 2138E800 */  addu       $a3, $a3, $t0
    /* 42CC0 800AB4C0 ADAD000C */  jal        SetDrawMove
    /* 42CC4 800AB4C4 1000A2A7 */   sh        $v0, 0x10($sp)
    /* 42CC8 800AB4C8 09EA010C */  jal        func_8007A824
    /* 42CCC 800AB4CC 21200002 */   addu      $a0, $s0, $zero
    /* 42CD0 800AB4D0 18001026 */  addiu      $s0, $s0, 0x18
    /* 42CD4 800AB4D4 801F013C */  lui        $at, (0x1F800000 >> 16)
    /* 42CD8 800AB4D8 000030AC */  sw         $s0, (0x1F800000 & 0xFFFF)($at)
  .L800AB4DC:
    /* 42CDC 800AB4DC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 42CE0 800AB4E0 1800B08F */  lw         $s0, 0x18($sp)
    /* 42CE4 800AB4E4 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 42CE8 800AB4E8 0800E003 */  jr         $ra
    /* 42CEC 800AB4EC 00000000 */   nop
endlabel func_800AB358
