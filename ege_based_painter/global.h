#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define SHOW_CONSOLE // Display the console in addition to the EGE window, providing easier drawing experience
#define CANVAS_WIDTH 800
#define CANVAS_HIGHT 602
#define EGE_FONT_SIZE 18
#define EGE_FONT "Segoe UI"
#define MENU_LENGTH 220
#define MENU_HIGHT 21

#include "graphics.h"
#include <stdio.h>
#include <math.h>
#include <Windows.h>

enum SHAPE
{
	shape_line,
	shape_circle,
	shape_rectangle,
	shape_polygon
};

struct Coordinate
{
	unsigned short int x;
	unsigned short int y;
};

struct ShapeData
{
	enum SHAPE shapeType;
	int extraData[10];
	struct Coordinate coords[20];
	unsigned short int lineThickness;
	bool isFill;
	unsigned int foregroundColor;
	unsigned int fillColor;
};