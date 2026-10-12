#pragma once
#include "common.h"
#include <libds.h>

typedef struct {
    int id;
    u_char com;
    u_char param[4];
    u_char* pparam;
    int x10;
    int x14;
} DS_CQ;

typedef struct {
    DS_CQ q[DslMaxCOMMANDS]; /* 80039CF0 */
    int head; /* 80039DB0 */
    int tail; /* 80039DB4 */
    int len; /* 80039DB8 */
} DS_CQS;

extern DS_CQS D_80039CF0;
extern int D_80039DB4;
extern int D_80039DB0;
extern int DS_system_status(int);
extern int DS_cw(u_char, u_char*);
extern int DS_ready(u_char*);
extern void (*D_80039E68)(u_char);
extern void func_8002480C(void);
extern int DS_lastcom(void);
extern int DS_status(void);
extern int DS_shell_open(void);
extern void DS_stop(void);
extern int DsQueueLen(void);
extern void DS_restart(void);
extern int _DsPacket2(u_char, DslLOC*, u_char, DslCB, int, int);

extern int D_80039DB8;

typedef struct {
    int id;
    u_char intr;
    u_char result[8];
} DS_RES;

typedef struct {
    DS_RES ent[8]; /* 80039DC0 */
    int idx; /* 80039E40 */
} DS_RESQ;

extern DS_RESQ D_80039DC0;

typedef struct {
    int flag;
    u_char intr;
    u_char result[8];
} DS_RDY;

extern DS_RDY D_80039CD0; /* DslDataReady / DslDiskError */
extern DS_RDY D_80039CE0; /* DslDataEnd */
extern DslCB D_80039E64;
extern void func_800233B4(u_char, u_char*);
extern void rescpy(u_char*, u_char*);
