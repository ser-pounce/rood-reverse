void _remove_ChgclrPAD()
{
    static int returnAddr = 0;
    __asm__("sw      $ra, %0;"
            "jal     EnterCriticalSection;"
            "nop;"
            "li      $t1, 0x57;"
            "li      $t2, 0xB0;"
            "jalr    $t2;"
            "nop;"
            "li      $t2, 0x9;"
            "lw      $v0, 0x16C($v0);"
            "nop;"
            "addi    $v1, $v0, 0x62C;"
            ".%=:"
            "sw      $zero, 0x0($v1);"
            "addiu   $v1, $v1, 0x4;"
            "addiu   $t2, $t2, -0x1;"
            "bnez    $t2, .%=;"
            "nop;"
            "jal     FlushCache;"
            "nop;"
            "jal     ExitCriticalSection;"
            "nop;"
            "lw      $ra, %0;"
            "nop;"
            : "=m"(returnAddr));
}
