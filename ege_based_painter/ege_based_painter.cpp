// ege_based_painter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "global.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "graphics.h"
#include "menu.h"
#include "read_file.h"

bool g_isUserSetColor = false; // global variable. used to determine whether the user has set a custom color
bool g_isUserSetFillColor = false;
int g_customColor = 0x0;
int g_customFillColor = 0x0;

struct ShapeData shapeData[512];
unsigned short int g_nTotalShapes = 0;
unsigned short int g_nCircle = 0;
unsigned short int g_nLine = 0;

int main(void)
{
	initgraph(CANVAS_WIDTH, CANVAS_HIGHT);
	//setrendermode(RENDER_AUTO);
	setfont(EGE_FONT_SIZE, 0, EGE_FONT);
	Menu(ReadFile(), 512);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
