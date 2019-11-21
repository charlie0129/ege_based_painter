#pragma once
#include "global.h"
#include "read_file.h"

extern struct ShapeData shapeData[512];
extern WORD g_nTotalShapes;
extern char fileValidityCheckSuffix;
extern bool fileEdited;

void SaveFile(void);