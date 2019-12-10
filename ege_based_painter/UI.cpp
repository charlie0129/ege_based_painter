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

	// draw basic lines
	setcaption("CC ����");
	setcolor(0x909090);
	line(0, 579, 800, 579);
	line(675, 579, 675, CANVAS_HIGHT);
	line(142, 579, 142, CANVAS_HIGHT);
	line(280, 579, 280, CANVAS_HIGHT);
	line(500, 579, 500, CANVAS_HIGHT);
	line(62, 579, 62, CANVAS_HIGHT);
	line(10 + MENU_LENGTH, 1, 10 + MENU_LENGTH, 579);

	if (errCode == 0)
	{
		setcolor(0x50AA50);
		xyprintf(2, 582, "׼������");
	}
	else
	{
		setcolor(0xAAAA50);
		xyprintf(2, 582, "���ڻ�ͼ");
	}

	if (fileEdited)
	{
		setcolor(0xAA5050);
		xyprintf(67, 582, "����δ����");
	}
	else
	{
		setcolor(0x50AA50);
		xyprintf(67, 582, "�����ѱ���");
	}

	setcolor(0x000000);
	xyprintf(133 + 16, 582, "��ʾ��Ϣ�뿴����̨");

	// display the number of each shape
	xyprintf(203 + 81, 582, "��: %d", nLines);
	xyprintf(245 + 81, 582, "Բ: %d", nCircles);
	xyprintf(287 + 81, 582, "����: %d", nRectangles);
	xyprintf(343 + 81, 582, "�����: %d", nPolygons);

	// shhow the current color settings
	xyprintf(505, 582, "ǰ��:");
	if (g_isUserSetColor)
	{
		setfillcolor(g_customColor);
		bar(540, 585, 565, 597);
	}
	else
	{
		setcolor(0x000000);
		xyprintf(540, 582, "���");
	}
	xyprintf(585, 582, "���:");
	if (g_isUserSetFillColor)
	{
		if (g_isFillColorRandom)
		{
			setcolor(0x000000);
			xyprintf(620, 582, "���");
		}
		else
		{
			setfillcolor(g_customFillColor);
			bar(620, 585, 645, 597);
		}
	}
	else
	{
		setcolor(0x000000);
		xyprintf(620, 582, "��");
	}
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
	setcolor(0x909090);
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
	
	return coord;
}