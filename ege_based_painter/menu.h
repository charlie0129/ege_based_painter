#pragma once
#include "global.h"
#include "mouse_draw.h"
#include "coord_draw.h"
#include "color_selector.h"
#include "UI.h"
#include "save_file.h"

extern unsigned short int g_nTotalShapes;

void Menu(bool readResult, unsigned short int nOfShapesToDraw);
void PrintMenu(short int lnToPrint);