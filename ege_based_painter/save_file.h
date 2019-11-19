#pragma once
#include "global.h"
#include "read_file.h"

extern struct ShapeData shapeData[512];
extern unsigned short int g_nTotalShapes;
extern char fileValidityCheckSuffix;

int SaveFile(void);