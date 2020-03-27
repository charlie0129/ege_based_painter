#pragma once
#include "global.h"

extern bool
g_isUserSetColor; // global variable. used to determine whether the user has set a custom color
extern bool g_isUserSetFillColor;
extern bool  g_isFillColorRandom;
extern int g_customColor;
extern int g_customFillColor;
extern WORD g_nTotalShapes;
extern struct ShapeData shapeData[512];
extern int colorInf[7];

void DrawAllPrevShapes(bool withColor);
int RandColor(void);
void PrintMouseDrawingInsideMenu(WORD lnToPrint);
void PrintCoordDrawingInsideMenu(WORD lnToPrint);