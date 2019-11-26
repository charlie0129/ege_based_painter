#pragma once
#include "global.h"
#include "menu.h"
#include "UI.h"


void ChooseColor_EGE(WORD mode);
void PrintColorChoosingInsideMenu(WORD lnToPrint, bool withColor, WORD mode);

extern bool g_isUserSetColor; // global variable. used to determine whether the user has set a custom color
extern bool g_isUserSetFillColor;
extern int g_customColor;
extern int g_customFillColor;
extern bool   g_isFillColorRandom;