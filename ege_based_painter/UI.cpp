#include "UI.h"


void InitUI(short int errCode)
{
	static WORD tmp_totalShapes;
	static WORD nLines;
	static WORD nCircles;
	static WORD nRectangles;
	static WORD nPolygons;

	// count the number of each shape
	if (tmp_totalShapes != g_nTotalShapes)
	{
		fileEdited = true;
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
	line(142, 579, 142, CANVAS_HIGHT);
	line(280, 579, 280, CANVAS_HIGHT);
	line(62, 579, 62, CANVAS_HIGHT);
	line(10 + MENU_LENGTH, 1, 10 + MENU_LENGTH, 579);

	if (errCode == 0)
	{
		setcolor(0x90FF90);
		xyprintf(2, 582, "准备就绪");
	}
	else
	{
		setcolor(0xFFFF90);
		xyprintf(2, 582, "正在绘图");
	}

	if (fileEdited)
	{
		setcolor(0xFF9090);
		xyprintf(67, 582, "更改未保存");
	}
	else
	{
		setcolor(0x90FF90);
		xyprintf(67, 582, "更改已保存");
	}


	setcolor(0xFFFFFF);
	xyprintf(133 + 16, 582, "提示信息请看控制台");
	xyprintf(203 + 81, 582, "线: %d", nLines);
	xyprintf(245 + 81, 582, "圆: %d", nCircles);
	xyprintf(287 + 81, 582, "矩形: %d", nRectangles);
	xyprintf(343 + 81, 582, "多边形: %d", nPolygons);
}

void ClearData(void)
{

	memset(shapeData, '\0', sizeof(shapeData));
	g_nTotalShapes = 0;
}

void DrawMenuOutline(WORD lnStart,
	WORD lnEnd,
	WORD col)
{
	setcolor(0x555555);
	// vertical lines
	for (int j = 0; j <= col; j++)
	{
		line(5 + j * MENU_LENGTH / col,
			5 + MENU_HIGHT * (lnStart - 1),
			5 + j * MENU_LENGTH / col,
			5 + MENU_HIGHT * lnEnd);
	}

	// horizontal lines
	for (int i = lnStart - 1; i <= lnEnd; i++)
	{
		line(5, 
			5 + MENU_HIGHT * i, 
			5 + MENU_LENGTH, 
			5 + MENU_HIGHT * i);
		//xyprintf(6 + MENU_LENGTH, 5 + MENU_HIGHT * (i - 1) - 10,"%d\n", 5 + MENU_HIGHT * (i - 1));
		//xyprintf(5, 5 + MENU_HIGHT * (i - 1) + 1, "%d", i);
	}
}

struct MenuLnAndCol GetMouseCurrentLnAndCol(
	WORD lnStart,
	WORD lnEnd,
	WORD colNeeded,
	WORD colTotal)
{
	int x, y;
	struct MenuLnAndCol coord;
	coord.ln = 0;
	coord.col = 0;
	mousepos(&x, &y);

	/*
	at first, i used the getmouse() function
	but a i encountered a issue where the function keeps waiting mouse input when there is no mouse input
	thus causing possible delays
	later i switched to the mousepos() function
	finally!!!!
	there is no delay
	*/

	if ((x >= 5 + (colNeeded -1) * (MENU_LENGTH / colTotal)) 
		&& (y >= 5 + (lnStart - 1) * MENU_HIGHT) 
		&& (x <= 5 + (colNeeded) * (MENU_LENGTH / colTotal))
		&& (y <= 5 + lnEnd * MENU_HIGHT))
	{
		coord.ln = (y - 5) / MENU_HIGHT + 1;
		coord.col = (x - 5) / (MENU_LENGTH / colTotal) + 1;
	}
	
	/*for (short int i = 0; i < lnTotal; i++)
	{
		if ((x >= 5) && 
			(y >= 5 + i * MENU_HIGHT) && 
			(x <= 5 + MENU_LENGTH) && 
			(y <= 5 + (i + 1) * MENU_HIGHT))
		{
			coord.ln = i + 1;
		}
		for (short int j = 0; j < colTotal; j++)
		{
			if ((x >= 5) &&
				(y >= 5 + i * MENU_HIGHT) &&
				(x <= 5 + MENU_LENGTH) &&
				(y <= 5 + (i + 1) * MENU_HIGHT))
			{
				coord.ln = i + 1;
			}
		}
	}*/
	return coord;
}