#include "UI.h"


void InitUI(short int errCode)
{
	static unsigned short int tmp_totalShapes;
	static unsigned short int nLines;
	static unsigned short int nCircles;
	static unsigned short int nRectangles;
	static unsigned short int nPolygons;

	// count the number of each shape
	if (tmp_totalShapes != g_nTotalShapes)
	{
		nLines = 0;
		nCircles = 0;
		nRectangles = 0;
		nPolygons = 0;

		for (int i = 0; i < g_nTotalShapes; i++)
		{
			switch (shapeData[i].shapeType)
			{
			case shape_line:	
				nLines++;
				break;
			case shape_circle:
				nCircles++;
				break;
			case shape_rectangle:
				nRectangles++;
				break;
			case shape_polygon:
				nPolygons++;
				break;
			default:
				break;
			}
		}
	}
		
	tmp_totalShapes = g_nTotalShapes;

	setcaption("CC 画板");
	setcolor(0x555555);
	line(0, 579, 800, 579);
	line(675, 579, 675, CANVAS_HIGHT);
	line(197, 579, 197, CANVAS_HIGHT);
	line(62, 579, 62, CANVAS_HIGHT);
	line(10 + MENU_LENGTH, 1, 10 + MENU_LENGTH, 579);

	if (errCode == 0)
	{
		setcolor(0x90FF90);
		xyprintf(2, 582, "准备就绪");
	}
	if (errCode == 1)
	{
		setcolor(0xFFFF90);
		xyprintf(2, 582, "正在绘图");
	}
	setcolor(0xFFFFFF);
	xyprintf(67, 582, "提示信息请看控制台");
	xyprintf(203, 582, "线: %d", nLines);
	xyprintf(245, 582, "圆: %d", nCircles);
	xyprintf(287, 582, "矩形: %d", nRectangles);
	xyprintf(343, 582, "多边形: %d", nPolygons);
}

void ClearData(void)
{

	memset(shapeData, '\0', sizeof(shapeData));
	g_nTotalShapes = 0;
}

void DrawMenuOutline(short int ln)
{
	setcolor(0x555555);
	line(5, 5, 5, 5 + ln * MENU_HIGHT);
	line(5 + MENU_LENGTH, 5, 5 + MENU_LENGTH, 5 + ln * MENU_HIGHT);
	for (int i = 1; i <= ln + 1; i++)
	{
		line(5, 5 + MENU_HIGHT * (i - 1), 5 + MENU_LENGTH, 5 + MENU_HIGHT * (i - 1));
		//xyprintf(6 + MENU_LENGTH, 5 + MENU_HIGHT * (i - 1) - 10,"%d\n", 5 + MENU_HIGHT * (i - 1));
		//xyprintf(5, 5 + MENU_HIGHT * (i - 1) + 1, "%d", i);
	}
}

int GetMouseCurrentLn(short int TOTAL_LN)
{
	int x, y;
	int ln = 0;
	mousepos(&x, &y);

	/*
	at first, i used the getmouse() function
	but a i encountered a issue where the function keeps waiting mouse input when there is no mouse input
	thus causing possible delays
	later i switched to the mousepos() function
	finally!!!!!!!!!!!!!!!!!!!!
	there is no delay
	*/

	for (short int i = 0; i < TOTAL_LN; i++)
	{
		if ((x >= 5) && 
			(y >= 5 + i * MENU_HIGHT) && 
			(x <= 5 + MENU_LENGTH) && 
			(y <= 5 + (i + 1) * MENU_HIGHT))
		{
			ln = i + 1;
		}
	}
	return ln;
}