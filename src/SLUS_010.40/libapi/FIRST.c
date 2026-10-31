#include "common.h"
#include <strings.h>
#include <kernel.h>
#include <fs.h>

static void (*D_80039E70)(void*, signed char*, struct DIRENTRY*);
static int _ __attribute__((unused));
static signed char D_80039E78[40];

extern struct DIRENTRY* firstfile2(char*, struct DIRENTRY*);
void func_80026D30(void* fcb, signed char* name, struct DIRENTRY* dir);

/* BIOS device table: pointer at 0x150, size in bytes at 0x154 */
#define DEVICE_TABLE (*(struct device_table**)0x150)
#define DEVICE_TABLE_SIZE (*(u_long*)0x154)

static inline int findDevice(void)
{
    struct device_table* table;
    struct device_table* dev;
    u_long n;

    n = DEVICE_TABLE_SIZE / sizeof(struct device_table);
    table = DEVICE_TABLE;
    for (dev = table; dev < table + n; dev++) {
        if (dev->dt_string != NULL && strcmp(dev->dt_string, D_80039E78) == 0) {
            D_80039E70 =
                (void (*)(void*, signed char*, struct DIRENTRY*))dev->dt_firstfile;
            return 1;
        }
    }
    return 0;
}

struct DIRENTRY* firstfile(char* name, struct DIRENTRY* dir)
{
    struct device_table* table;
    struct device_table* dev;
    signed char* src;
    signed char* dst;
    u_long n;

    src = name;
    dst = D_80039E78;
    while (*src >= ';') {
        *dst++ = *src++;
    }
    *dst = 0;

    if (!findDevice()) {
        return NULL;
    }
    n = DEVICE_TABLE_SIZE / sizeof(struct device_table);
    table = DEVICE_TABLE;
    for (dev = table; dev < table + n; dev++) {
        if (dev->dt_string != NULL && strcmp(dev->dt_string, D_80039E78) == 0) {
            dev->dt_firstfile = (int (*)())func_80026D30;
            break;
        }
    }
    return firstfile2(name, dir);
}

void func_80026D30(void* fcb, signed char* name, struct DIRENTRY* dir)
{
    struct device_table* table;
    struct device_table* dev;
    void (*func)(void*, signed char*, struct DIRENTRY*);
    u_long n;

    if (*(int*)fcb == 0) {
        *(int*)fcb = 1;
    }
    n = DEVICE_TABLE_SIZE / sizeof(struct device_table);
    table = DEVICE_TABLE;
    func = D_80039E70;
    for (dev = table; dev < table + n; dev++) {
        if (dev->dt_string != NULL && strcmp(dev->dt_string, D_80039E78) == 0) {
            dev->dt_firstfile = (int (*)())func;
            break;
        }
    }
    D_80039E70(fcb, name, dir);
}
