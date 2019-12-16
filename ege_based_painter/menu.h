#pragma once
#include "global.h"
#include "mouse_draw.h"
#include "coord_draw.h"
#include "color_selector.h"
#include "UI.h"
#include "save_file.h"

extern WORD g_nTotalShapes;
extern bool g_isFileEdited;

void Menu(bool readResult);
void PrintMenu(short int lnToPrint);