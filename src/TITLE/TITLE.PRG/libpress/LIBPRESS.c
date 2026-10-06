#include "common.h"
#include <libpress.h>
#include <libetc.h>
#include <stdio.h>

static void MDEC_reset(int);

void DecDCTReset(int mode)
{
    if (mode == 0) {
        ResetCallback();
    }
    MDEC_reset(mode);
}

static char mdec_iq_y[] = { 0x01, 0x00, 0x00, 0x40, 0x02, 0x10, 0x10, 0x13, 0x10, 0x13,
    0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x1A, 0x18, 0x1A, 0x1B, 0x1B, 0x1B, 0x1A, 0x1A,
    0x1A, 0x1A, 0x1B, 0x1B, 0x1B, 0x1D, 0x1D, 0x1D, 0x22, 0x22, 0x22, 0x1D, 0x1D, 0x1D,
    0x1B, 0x1B, 0x1D, 0x1D, 0x20, 0x20, 0x22, 0x22, 0x25, 0x26, 0x25, 0x23, 0x23, 0x22,
    0x23, 0x26, 0x26, 0x28, 0x28, 0x28, 0x30, 0x30, 0x2E, 0x2E, 0x38, 0x38, 0x3A, 0x45,
    0x45, 0x53 };
static char mdec_iq_c[] = { 0x02, 0x10, 0x10, 0x13, 0x10, 0x13, 0x16, 0x16, 0x16, 0x16,
    0x16, 0x16, 0x1A, 0x18, 0x1A, 0x1B, 0x1B, 0x1B, 0x1A, 0x1A, 0x1A, 0x1A, 0x1B, 0x1B,
    0x1B, 0x1D, 0x1D, 0x1D, 0x22, 0x22, 0x22, 0x1D, 0x1D, 0x1D, 0x1B, 0x1B, 0x1D, 0x1D,
    0x20, 0x20, 0x22, 0x22, 0x25, 0x26, 0x25, 0x23, 0x23, 0x22, 0x23, 0x26, 0x26, 0x28,
    0x28, 0x28, 0x30, 0x30, 0x2E, 0x2E, 0x38, 0x38, 0x3A, 0x45, 0x45, 0x53 };
static short mdec_coef[] = { 0x0000, 0x6000, 0x5A82, 0x5A82, 0x5A82, 0x5A82, 0x5A82,
    0x5A82, 0x5A82, 0x5A82, 0x7D8A, 0x6A6D, 0x471C, 0x18F8, 0xE707, 0xB8E3, 0x9592,
    0x8275, 0x7641, 0x30FB, 0xCF04, 0x89BE, 0x89BE, 0xCF04, 0x30FB, 0x7641, 0x6A6D,
    0xE707, 0x8275, 0xB8E3, 0x471C, 0x7D8A, 0x18F8, 0x9592, 0x5A82, 0xA57D, 0xA57D,
    0x5A82, 0x5A82, 0xA57D, 0xA57D, 0x5A82, 0x471C, 0x8275, 0x18F8, 0x6A6D, 0x9592,
    0xE707, 0x7D8A, 0xB8E3, 0x30FB, 0x89BE, 0x7641, 0xCF04, 0xCF04, 0x7641, 0x89BE,
    0x30FB, 0x18F8, 0xB8E3, 0x6A6D, 0x8275, 0x7D8A, 0x9592, 0x471C, 0xE707, 0x7350,
    0x000E, 0x0000, 0x0045 };

static inline void _memcpy(u_long* dst, u_long* src, size_t size)
{
    while (size--) {
        *dst++ = *src++;
    }
}

DECDCTENV* DecDCTGetEnv(DECDCTENV* env)
{

    _memcpy((u_long*)&env->iq_y, (u_long*)mdec_iq_y + 1, 16);
    _memcpy((u_long*)&env->iq_c, (u_long*)mdec_iq_c, 16);
    _memcpy((u_long*)&env->dct, (u_long*)mdec_coef + 1, 32);

    return env;
}

static void MDEC_in(u_long* arg0, u_int arg1);

DECDCTENV* DecDCTPutEnv(DECDCTENV* arg0)
{
    _memcpy((u_long*)mdec_iq_y + 1, (u_long*)&arg0->iq_y, 16);
    _memcpy((u_long*)mdec_iq_c, (u_long*)&arg0->iq_c, 16);

    MDEC_in((u_long*)mdec_iq_y, 32);
    MDEC_in((u_long*)mdec_coef, 32);

    return arg0;
}

void DecDCTin(u_long* buf, int mode)
{
    if (mode & 1) {
        *buf &= 0xF7FFFFFF;
    } else {
        *buf |= 0x08000000;
    }

    if (mode & 2) {
        *buf |= 0x02000000;
    } else {
        *buf &= 0xFDFFFFFF;
    }

    MDEC_in(buf, (u_short)*buf);
}

static void MDEC_out(u_long* buf, u_int size);

void DecDCTout(u_long* buf, int size) { MDEC_out(buf, size); }

static u_int get_mdec1(void);

static int MDEC_in_sync(void);

int DecDCTinSync(int mode)
{
    if (mode != 0) {
        return (get_mdec1() >> 0x1D) & 1;
    }
    return MDEC_in_sync();
}

static int MDEC_out_sync(void);

int DecDCToutSync(int mode)
{
    if (mode != 0) {
        return (get_mdec1() >> 0x18) & 1;
    }
    return MDEC_out_sync();
}

int DMACallback(int, void (*)(void));

int DecDCTinCallback(void (*func)(void)) { return DMACallback(0, func); }

int DecDCToutCallback(void (*func)(void)) { return DMACallback(1, func); }

static u_int volatile* d0_madr = (u_int volatile*)0x1F801080;
static u_int volatile* d0_bcr = (u_int volatile*)0x1F801084;
static u_int volatile* d0_chcr = (u_int volatile*)0x1F801088;
static u_int volatile* d1_madr = (u_int volatile*)0x1F801090;
static u_int volatile* d1_bcr = (u_int volatile*)0x1F801094;
static u_int volatile* d1_chcr = (u_int volatile*)0x1F801098;
static u_int volatile* d2_madr = (u_int volatile*)0x1F8010A0;
static u_int volatile* d2_bcr = (u_int volatile*)0x1F8010A4;
static u_int volatile* d2_chcr = (u_int volatile*)0x1F8010A8;
static u_int volatile* d3_madr = (u_int volatile*)0x1F8010B0;
static u_int volatile* d3_bcr = (u_int volatile*)0x1F8010B4;
static u_int volatile* d3_chcr = (u_int volatile*)0x1F8010B8;
static u_int volatile* mdec0 = (u_int volatile*)0x1F801820;
static u_int volatile* mdec1 = (u_int volatile*)0x1F801824;

static void MDEC_reset(int arg0)
{
    switch (arg0) {
    case 0:
        *mdec1 = 0x80000000;
        *d0_chcr = 0;
        *d1_chcr = 0;
        *mdec1 = 0x60000000;
        MDEC_in((u_long*)mdec_iq_y, 32);
        MDEC_in((u_long*)mdec_coef, 32);
        return;
    case 1:
        *mdec1 = 0x80000000;
        *d0_chcr = 0;
        *d1_chcr = 0;
        *d1_chcr;
        *mdec1 = 0x60000000;
        return;
    default:
        printf("MDEC_rest:bad option(%d)\n", arg0);
        return;
    }
}

static u_int volatile* d_pcr = (u_int volatile*)0x1F8010F0;

static void MDEC_in(u_long* arg0, u_int arg1)
{
    MDEC_in_sync();
    *d_pcr |= 0x88;
    *d0_madr = (u_int)(arg0 + 1);
    *d0_bcr = ((arg1 >> 5) << 0x10) | 0x20;
    *mdec0 = *arg0;
    *d0_chcr = 0x01000201;
}

static void MDEC_out(u_long* arg0, u_int arg1)
{
    MDEC_out_sync();
    *d_pcr |= 0x88;
    *d1_chcr = 0;
    *d1_madr = (u_int)arg0;
    *d1_bcr = ((arg1 >> 5) << 0x10) | 0x20;
    *d1_chcr = 0x01000200;
}

static int timeout(char* arg0);

static int MDEC_in_sync(void)
{
    volatile int retries = 0x100000;

    while (*mdec1 & 0x20000000) {
        if (--retries == -1) {
            timeout("MDEC_in_sync");
            return -1;
        }
    }

    return 0;
}

static int MDEC_out_sync(void)
{
    volatile int retries = 0x100000;

    while (*d1_chcr & 0x01000000) {
        if (--retries == -1) {
            timeout("MDEC_out_sync");
            return -1;
        }
    }

    return 0;
}

static u_int get_mdec1(void) { return *mdec1; }

static int timeout(char* arg0)
{
    printf("%s timeout:\n", arg0);
    *mdec1 = 0x80000000;
    *d0_chcr = 0;
    *d1_chcr = 0;
    *d1_chcr;
    *mdec1 = 0x60000000;
    return 0;
}

static const char _[4] = { 0 };
