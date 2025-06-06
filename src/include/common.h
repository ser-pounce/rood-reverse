#pragma once
#include <stddef.h>

#define INCLUDE_CMN(SECTION, FOLDER, NAME)                                               \
    __asm__(".pushsection ." #SECTION ";"                                                \
            ".set push;"                                                                 \
            ".set noat;"                                                                 \
            ".set noreorder;"                                                            \
            ".include \"" FOLDER "/" #NAME ".s\";"                                       \
            ".set pop;"                                                                  \
            ".popsection")

#define BIOS_STUB(name, table, id)                                                       \
    __asm__(".set push;"                                                                 \
            ".set noat;"                                                                 \
            ".set noreorder;"                                                            \
            "glabel " #name ";"                                                          \
            "li  $t2, " #table ";"                                                       \
            "jr  $t2;"                                                                   \
            "li  $t1, " #id ";"                                                          \
            ".set pop;");

#define SYSCALL(id)                                                                      \
    __asm__("li $a0, " #id ";"                                                           \
            "syscall 0;");

#if !defined(PERMUTER) && !defined(OBJDIFF)
#define INCLUDE_ASM(FOLDER, NAME) INCLUDE_CMN(text, FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME) INCLUDE_CMN(rodata, FOLDER, NAME)
#else
#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME)
#endif // PERMUTER && OBJDIFF

#if defined(PERMUTER)
#define __attribute__(x)
#define __asm__(...)
#endif // PERMUTER