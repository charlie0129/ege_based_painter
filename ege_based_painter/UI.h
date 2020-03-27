#pragma once
#include "global.h"
#include "graphics.h"

extern WORD   g_nTotalShapes;
extern struct ShapeData shapeData[512];
extern bool   g_isFileEdited;
extern bool
g_isUserSetColor; // global variable. used to determine whether the user has set a custom color
extern bool   g_isUserSetFillColor;
extern bool   g_isFillColorRandom;
extern int    g_customColor;
extern int    g_customFillColor;

void InitUI(short int errCode);
void ClearData(void);
void DrawMenuOutline(
    WORD lnStart,
    WORD lnEnd,
    WORD col);
struct MenuLnAndCol GetMouseCurrentLnAndCol(
    WORD lnStart,
    WORD lnEnd,
    WORD colNeeded,
    WORD colTotal);