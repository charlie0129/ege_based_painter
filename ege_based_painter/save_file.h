#pragma once
#include "global.h"
#include "read_file.h"

extern        WORD g_nTotalShapes;
extern char   fileValidityCheckSuffix;
extern bool   g_isFileEdited;

void WriteToFile(void);