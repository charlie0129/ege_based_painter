#pragma once
#include "global.h"
#include "UI.h"

extern struct ShapeData shapeData[512];
extern char fileValidityCheckSuffix;

bool ReadFromFile(void);
void TCHARToChar(const TCHAR *tchar, char *_char);