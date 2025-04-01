#pragma once

#ifndef PERMUTER

#define INCLUDE_CMN(SECTION, FOLDER, NAME)                                               \
    __asm__(".pushsection ." #SECTION ";"                                                \
            ".set push;"                                                                 \
            ".include \"" FOLDER "/" #NAME ".s\";"                                       \
            ".set pop;"                                                                  \
            ".popsection")

#define INCLUDE_ASM(FOLDER, NAME) INCLUDE_CMN(text, FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME) INCLUDE_CMN(rodata, FOLDER, NAME)

#define BIOS_STUB(name, table, id)                                                       \
    __asm__(".set noat;"                                                                 \
            ".set noreorder;"                                                            \
            "glabel " #name ";"                                                          \
            "li  $t2, " #table ";"                                                       \
            "jr  $t2;"                                                                   \
            "li  $t1, " #id ";");

#define SYSCALL(id)                                                                      \
    __asm__("li $a0, " #id ";"                                                           \
            "syscall 0;");

#define EMBED_BETWEEN(path, symbol, offset, len)                                         \
    __asm__(".pushsection .data;"                                                        \
            ".incbin \"" path "\"," #offset "," #len ";"                                 \
            ".popsection");

#define EMBED_FROM(path, symbol, offset)                                                 \
    __asm__(".pushsection .data;"                                                        \
            ".incbin \"" path "\"," #offset ";"                                          \
            ".popsection");

#define EMBED_RGBA16(path, symbol)                                                       \
    EMBED_BETWEEN(path, symbol##_header, 0, 4)                                           \
    EMBED_FROM(path, symbol##_data, 4)                                                   \
    extern ImgHeader symbol##_header;                                                    \
    extern unsigned long symbol##_data[];

#else
#define INCLUDE_ASM(FOLDER, NAME) void dummy()
#define INCLUDE_RODATA(FOLDER, NAME)
#define BIOS_STUB(name, table, id)
#define EMBED_RGBA16(path, symbol)                                                       \
    extern ImgHeader symbol##_header;                                                    \
    extern unsigned long symbol##_data[];
#define __attribute__(x)
#define __asm__(...)
#endif // PERMUTER