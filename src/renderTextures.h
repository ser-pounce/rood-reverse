#include "texture_t.h"

void renderTextureFadeInTint(int x, int y, int texId, CVECTOR colors[])
{
    POLY_GT4* poly;
    void** p;

    if (colors[0].cd == 0) {
        return;
    }

    poly = *(void**)0x1F800000;

    setPolyGT4(poly);
    setXY4(poly, x, y, disMap[texId].w + x, y, x, disMap[texId].h + y,
        disMap[texId].w + x, disMap[texId].h + y);
    setUV4(poly, disMap[texId].x, disMap[texId].y, disMap[texId].x + disMap[texId].w,
        disMap[texId].y, disMap[texId].x, disMap[texId].y + disMap[texId].h,
        disMap[texId].x + disMap[texId].w, disMap[texId].y + disMap[texId].h);

    if (colors[0].cd < 8) {
        setRGB0(poly, (colors[0].r * colors[0].cd) / 8, (colors[0].g * colors[0].cd) / 8,
            (colors[0].b * colors[0].cd) / 8);
        setRGB1(poly, (colors[1].r * colors[0].cd) / 8, (colors[1].g * colors[0].cd) / 8,
            (colors[1].b * colors[0].cd) / 8);
        setRGB2(poly, (colors[0].r * colors[0].cd) / 8, (colors[0].g * colors[0].cd) / 8,
            (colors[0].b * colors[0].cd) / 8);
        setRGB3(poly, (colors[1].r * colors[0].cd) / 8, (colors[1].g * colors[0].cd) / 8,
            (colors[1].b * colors[0].cd) / 8);
    } else {
        setRGB0(poly, colors[0].r, colors[0].g, colors[0].b);
        setRGB1(poly, colors[1].r, colors[1].g, colors[1].b);
        setRGB2(poly, colors[0].r, colors[0].g, colors[0].b);
        setRGB3(poly, colors[1].r, colors[1].g, colors[1].b);
    }

    setSemiTrans(poly, 1);

    if (colors[0].cd < 8) {
        poly->clut = disMap[texId].clut + 1;
        poly->tpage = disMap[texId].tpage | 0x20;
    } else {
        poly->clut = disMap[texId].clut;
        poly->tpage = disMap[texId].tpage;
    }

    p = (void**)0x1F800000;

    AddPrim(p[1] - 0x1C, poly++);

    p[0] = poly;
}

static inline int adjust(int component, int weight)
{
    int ret = (component * weight) + ((4 - weight) * 192);
    return ret / 4;
}

void renderTexturePopIn(int x, int y, int texId, CVECTOR colors[])
{
    POLY_GT4* poly;
    void** p;

    if (colors[0].cd != 0) {
        poly = *(void**)0x1F800000;

        setPolyGT4(poly);
        setXY4(poly, x, y, disMap[texId].w + x, y, x, disMap[texId].h + y,
            disMap[texId].w + x, disMap[texId].h + y);
        setUV4(poly, disMap[texId].x, disMap[texId].y, disMap[texId].x + disMap[texId].w,
            disMap[texId].y, disMap[texId].x, disMap[texId].y + disMap[texId].h,
            disMap[texId].x + disMap[texId].w, disMap[texId].y + disMap[texId].h);

        if (colors[0].cd < 8) {
            setRGB0(poly, (colors[0].r * colors[0].cd) / 8,
                (colors[0].g * colors[0].cd) / 8, (colors[0].b * colors[0].cd) / 8);
            setRGB1(poly, (colors[1].r * colors[0].cd) / 8,
                (colors[1].g * colors[0].cd) / 8, (colors[1].b * colors[0].cd) / 8);
            setRGB2(poly, (colors[0].r * colors[0].cd) / 8,
                (colors[0].g * colors[0].cd) / 8, (colors[0].b * colors[0].cd) / 8);
            setRGB3(poly, (colors[1].r * colors[0].cd) / 8,
                (colors[1].g * colors[0].cd) / 8, (colors[1].b * colors[0].cd) / 8);
        } else if (colors[0].cd == 8) {
            setRGB0(poly, 192, 192, 192);
            setRGB1(poly, 192, 192, 192);
            setRGB2(poly, 192, 192, 192);
            setRGB3(poly, 192, 192, 192);
        } else if (colors[0].cd == 9) {
            setRGB0(poly, 224, 224, 224);
            setRGB1(poly, 224, 224, 224);
            setRGB2(poly, 224, 224, 224);
            setRGB3(poly, 224, 224, 224);
        } else if (colors[0].cd < 14) {
            int temp_a0 = colors[0].cd - 10;
            setRGB0(poly, adjust(colors[0].r, temp_a0), adjust(colors[0].g, temp_a0),
                adjust(colors[0].b, temp_a0));
            setRGB1(poly, adjust(colors[1].r, temp_a0), adjust(colors[1].g, temp_a0),
                adjust(colors[1].b, temp_a0));
            setRGB2(poly, adjust(colors[0].r, temp_a0), adjust(colors[0].g, temp_a0),
                adjust(colors[0].b, temp_a0));
            setRGB3(poly, adjust(colors[1].r, temp_a0), adjust(colors[1].g, temp_a0),
                adjust(colors[1].b, temp_a0));
        } else {
            setRGB0(poly, colors[0].r, colors[0].g, colors[0].b);
            setRGB1(poly, colors[1].r, colors[1].g, colors[1].b);
            setRGB2(poly, colors[0].r, colors[0].g, colors[0].b);
            setRGB3(poly, colors[1].r, colors[1].g, colors[1].b);
        }

        setSemiTrans(poly, 1);

        if (colors[0].cd < 10) {
            poly->clut = disMap[texId].clut + getClut(16, 0);
            poly->tpage = disMap[texId].tpage | getTPage(0, 1, 0, 0);
        } else {
            poly->clut = disMap[texId].clut;
            poly->tpage = disMap[texId].tpage;
        }

        p = (void**)0x1F800000;

        AddPrim(p[1] - 0x1C, poly++);

        p[0] = poly;
    }
}

void renderTextureWipe(int x, int y, int texId, CVECTOR colors[], int maxX)
{
    int temp_a1;
    int var_a0;
    int i;
    char var_s6;
    POLY_GT4* poly;
    void** scratch;

    if ((x + disMap[texId].w) < (maxX - 64)) {

        scratch = (void**)0x1F800000;
        poly = scratch[0];

        setPolyGT4(poly);
        setXY4(poly, x, y, disMap[texId].w + x, y, x, disMap[texId].h + y,
            disMap[texId].w + x, disMap[texId].h + y);
        setUV4(poly, disMap[texId].x, disMap[texId].y, disMap[texId].x + disMap[texId].w,
            disMap[texId].y, disMap[texId].x, disMap[texId].y + disMap[texId].h,
            disMap[texId].x + disMap[texId].w, disMap[texId].y + disMap[texId].h);
        setRGB0(poly, colors[0].r, colors[0].g, colors[0].b);
        setRGB1(poly, colors[1].r, colors[1].g, colors[1].b);
        setRGB2(poly, colors[0].r, colors[0].g, colors[0].b);
        setRGB3(poly, colors[1].r, colors[1].g, colors[1].b);
        setSemiTrans(poly, 1);

        poly->clut = disMap[texId].clut;
        poly->tpage = disMap[texId].tpage;

        scratch = (void**)0x1F800000;

        AddPrim(scratch[1] - 0x1C, poly++);

        scratch[0] = poly;
        return;
    }

    if (x < maxX) {

        scratch = (void**)0x1F800000;
        poly = scratch[0];
        var_s6 = disMap[texId].x;

        for (i = 0; i < disMap[texId].w; i += 12, x += 12, var_s6 += 12) {

            var_a0 = 12;

            if ((i + 12) >= disMap[texId].w) {
                var_a0 = disMap[texId].w - i;
            }

            setPolyGT4(poly);
            temp_a1 = x + var_a0;
            setXY4(poly, x, y, temp_a1, y, x, disMap[texId].h + y, temp_a1,
                disMap[texId].h + y);
            setUV4(poly, var_s6, disMap[texId].y, var_s6 + var_a0, disMap[texId].y,
                var_s6, disMap[texId].y + disMap[texId].h, var_s6 + var_a0,
                disMap[texId].y + disMap[texId].h);

            var_a0 = maxX - x;

            if (var_a0 > 64) {
                var_a0 = 64;
            }

            if (var_a0 < 0) {
                var_a0 = 0;
            }

            setRGB0(poly, (colors[0].r * var_a0) / 64, (colors[0].g * var_a0) / 64,
                (colors[0].b * var_a0) / 64);
            setRGB2(poly, (colors[0].r * var_a0) / 64, (colors[0].g * var_a0) / 64,
                (colors[0].b * var_a0) / 64);

            var_a0 = maxX - temp_a1;

            if (var_a0 > 64) {
                var_a0 = 64;
            }

            if (var_a0 < 0) {
                var_a0 = 0;
            }

            setRGB1(poly, (colors[1].r * var_a0) / 64, (colors[1].g * var_a0) / 64,
                (colors[1].b * var_a0) / 64);
            setRGB3(poly, (colors[1].r * var_a0) / 64, (colors[1].g * var_a0) / 64,
                (colors[1].b * var_a0) / 64);

            setSemiTrans(poly, 1);

            poly->clut = (disMap[texId].clut + 1);
            poly->tpage = (disMap[texId].tpage | 0x20);

            scratch = (void**)0x1F800000;

            AddPrim(scratch[1] - 0x1C, poly++);
        }

        scratch = (void**)0x1F800000;
        scratch[0] = poly;
    }
}
