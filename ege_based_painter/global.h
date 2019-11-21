#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define SHOW_CONSOLE // Display the console in addition to the EGE window, providing easier drawing experience
#define CANVAS_WIDTH 800
#define CANVAS_HIGHT 602
#define EGE_FONT_SIZE 18
#define EGE_FONT "Segoe UI"
#define MENU_LENGTH 220
#define MENU_HIGHT 21
#define REFRESH_RATE 800

#include "graphics.h"
#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <Commdlg.h>

enum SHAPE
{
	shape_line,
	shape_circle,
	shape_rectangle,
	shape_polygon
};

struct Coordinate
{
	WORD x;
	WORD y;
};

struct ShapeData
{
	enum SHAPE shapeType;
	int extraData[10];
	struct Coordinate coords[20];
	WORD lineThickness;
	bool isFill;
	UINT foregroundColor;
	UINT fillColor;
};

struct MenuLnAndCol
{
	WORD ln;
	WORD col;
};