#pragma once
#include "global.h"
#include "graphics.h"

extern WORD g_nTotalShapes;
extern struct ShapeData shapeData[512];
extern bool fileEdited;

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