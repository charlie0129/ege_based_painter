#pragma once
#include "global.h"

extern bool g_isUserSetColor; // global variable. used to determine whether the user has set a custom color
extern bool g_isUserSetFillColor;
extern int g_customColor;
extern int g_customFillColor;
extern unsigned short int g_nTotalShapes;
extern struct ShapeData shapeData[512];

void DrawAllPrevShapes(bool withColor);
int RandColor(void);
void PrintMouseDrawingInsideMenu(short int lnToPrint);
void PrintCoordDrawingInsideMenu(short int lnToPrint);