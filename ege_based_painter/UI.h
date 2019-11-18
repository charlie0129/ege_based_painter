#pragma once
#include "global.h"
#include "graphics.h"

extern unsigned short int g_nTotalShapes;
extern struct ShapeData shapeData[512];

void InitUI(short int errCode);
void ClearData(void);
void DrawMenuOutline(short int ln);
int GetMouseCurrentLn(short int TOTAL_LN);