#include "common.h"
#include <strings.h>
#include <kernel.h>

static void (*D_80039E70)(void*, signed char*, struct DIRENTRY*);
static int _ __attribute__((unused));
static signed char D_80039E78[40];

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libapi/FIRST", firstfile);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libapi/FIRST", func_80026D30);
