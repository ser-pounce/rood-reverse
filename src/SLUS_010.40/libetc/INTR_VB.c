#include "common.h"

void InterruptCallback(int, void (*)());
void func_8001FFEC(void);
void func_80020058(int, void (*)(void));
void func_80020084(long* ptr, long size);

extern void (*D_800320F4[8])(void);
extern int D_80032114;
extern int* D_80032118;

void* startIntrVSync(void)
{
    *D_80032118 = 0x100;
    D_80032114 = 0;
    func_80020084((long*)D_800320F4, 8);
    InterruptCallback(0, func_8001FFEC);
    return func_80020058;
}

void func_8001FFEC(void)
{
    int i;

    D_80032114++;
    for (i = 0; i < 8; i++) {
        if (D_800320F4[i] != NULL) {
            D_800320F4[i]();
        }
    }
}

void func_80020058(int index, void (*callback)(void))
{
    if (callback != D_800320F4[index]) {
        D_800320F4[index] = callback;
    }
}

void func_80020084(long* ptr, long size)
{
    long i = size - 1;

    if (size != 0) {
        do {
            *ptr++ = 0;
        } while (--i != -1);
    }
}
