#include "mouse_draw.h"

void mouse_DrawCircle(void)
{
	const short int TOTAL_LN = 4; // total items in the menu bar
	bool            isInProgress = false; // To determine whether the mouse click is the first step or the second step
	int             circleCenterX;
	int             circleCenterY;
	int            	circleOuterX;
	int             circleOuterY;
	
	printf("已进入鼠标画圆模式\n");
	printf("操作指南：\n");
	printf("用鼠标先点选圆心再点选圆上任意一点即可连续画圆\n");
	DrawAllPrevShapes(true);
	DrawMenuOutline(1, TOTAL_LN, 1);
	setcolor(0x000000);
	PrintMouseDrawingInsideMenu(0);
	mouse_msg msg;

	for (; is_run(); delay_fps(REFRESH_RATE)) // Using "for" statement to draw multiple circles at a time and refresh the screen
	{
		msg = getmouse();
	
		switch (msg.msg)
		{
		case mouse_msg_down:
			switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
			{
			case 1:
				return;
				break;
			case 2:
				if (g_nTotalShapes > 0)
				{
					if (!isInProgress)
					{
						g_nTotalShapes--;
					}
				}
				// refresh the windows with menu contents
				cleardevice();
				InitUI(0);
				DrawMenuOutline(1, TOTAL_LN, 1);
				setcolor(0x000000);
				PrintMouseDrawingInsideMenu(0);
				setcolor(0x50AA50);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
				DrawAllPrevShapes(true);
				goto move;
				break;
			case 3:
				ChooseColor_EGE(0);
				cleardevice();
				InitUI(0);
				DrawAllPrevShapes(true);
				goto move;
				break;
			case 4:
				ChooseColor_EGE(1);
				cleardevice();
				InitUI(0);
				DrawAllPrevShapes(true);
				goto move;
				break;
			default:
				break;
			}

			/* if the mouse click indicates the first dot, store the position data of the center of the circle */
			if (!isInProgress)
			{
				circleCenterX = msg.x;
				circleCenterY = msg.y;

				// print a big dot
				putpixel(circleCenterX, circleCenterY, 0x707000);
				putpixel(circleCenterX + 1, circleCenterY, 0x707000);
				putpixel(circleCenterX - 1, circleCenterY, 0x707000);
				putpixel(circleCenterX, circleCenterY + 1, 0x707000);
				putpixel(circleCenterX, circleCenterY - 1, 0x707000);

				printf("	您已选中圆心 (%d, %d)\n", circleCenterX, circleCenterY);

				isInProgress = true;
				break;
			}

			/* if the mouse click indicates the first dot, store the position data of another dot on the circle */
			if (isInProgress)
			{

				circleOuterX = msg.x;
				circleOuterY = msg.y;

				printf("	您已选中圆上一点 (%d, %d)\n", circleOuterX, circleOuterY);
			
				g_nTotalShapes++;
				shapeData[g_nTotalShapes - 1].shapeType = shape_circle;
				shapeData[g_nTotalShapes - 1].coords[0].x = circleCenterX;
				shapeData[g_nTotalShapes - 1].coords[0].y = circleCenterY;
				shapeData[g_nTotalShapes - 1].coords[1].x = circleOuterX;
				shapeData[g_nTotalShapes - 1].coords[1].y = circleOuterY;

				if (!g_isUserSetColor)
				{
					shapeData[g_nTotalShapes - 1].foregroundColor = RandColor();
				}
				else
				{
					shapeData[g_nTotalShapes - 1].foregroundColor = g_customColor;
				}
				if (!g_isUserSetFillColor)
				{
					shapeData[g_nTotalShapes - 1].isFill = false;
				}
				else
				{
					shapeData[g_nTotalShapes - 1].isFill = true;
					if (g_isFillColorRandom)
					{
						shapeData[g_nTotalShapes - 1].fillColor = RandColor();
					}
					else
					{
						shapeData[g_nTotalShapes - 1].fillColor = g_customFillColor;
					}				
				}

				DrawAllPrevShapes(true);
			
				printf("	已画出以 (%d, %d) 为圆心，(%d, %d) 为圆上一点，半径为 %d 的一个圆\n", 
					circleCenterX, 
					circleCenterY, 
					circleOuterX, 
					circleOuterY, 
					(int)sqrt(pow(shapeData[g_nTotalShapes - 1].coords[0].x - shapeData[g_nTotalShapes - 1].coords[1].x, 2) +
							  pow(shapeData[g_nTotalShapes - 1].coords[0].y - shapeData[g_nTotalShapes - 1].coords[1].y, 2)));

				isInProgress = false;
				goto move;
				break;
			}
			break; // not needed
		case mouse_msg_move:
			move:
			if (!isInProgress)
			{
				InitUI(0);
				//DrawMenuOutline(1, TOTAL_LN, 1);
				//setcolor(0x000000);
				//PrintMouseDrawingInsideMenu(0);
				setcolor(0x50AA50);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
				switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
				{
				case 0:
					DrawMenuOutline(1, TOTAL_LN, 1);
					setcolor(0x000000);
					PrintMouseDrawingInsideMenu(0);
					break;
				case 1:
					setcolor(0x000000);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x5050AA);
					PrintMouseDrawingInsideMenu(1);
					break;
				case 2:
					setcolor(0x000000);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x5050AA);
					PrintMouseDrawingInsideMenu(2);
					break;
				case 3:
					setcolor(0x000000);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x5050AA);
					PrintMouseDrawingInsideMenu(3);
					break;
				case 4:
					setcolor(0x000000);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x5050AA);
					PrintMouseDrawingInsideMenu(4);
					break;
				default:
					break;
				}
			}
			
			if (isInProgress)
			{
				cleardevice(); 
				delay_fps(10000);
				InitUI(1);
				setcolor(0x50AA50);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);

				putpixel(circleCenterX, circleCenterY, 0x707000);
				putpixel(circleCenterX + 1, circleCenterY, 0x707000);
				putpixel(circleCenterX - 1, circleCenterY, 0x707000);
				putpixel(circleCenterX, circleCenterY + 1, 0x707000);
				putpixel(circleCenterX, circleCenterY - 1, 0x707000);
				putpixel(msg.x, msg.y, 0x707000);
				putpixel(msg.x + 1, msg.y, 0x707000);
				putpixel(msg.x - 1, msg.y, 0x707000);
				putpixel(msg.x, msg.y + 1, 0x707000);
				putpixel(msg.x, msg.y - 1, 0x707000);
				DrawAllPrevShapes(true);
				setcolor(0x909090);
				
				circle(circleCenterX, circleCenterY, (int)sqrt(pow((double)circleCenterX - (double)msg.x, 2) + pow((double)circleCenterY - (double)msg.y, 2)));
			}


			break;
		default:
			break;
		}
	}
}

void mouse_DrawLine(void)
{
	const short int TOTAL_LN = 4;
	bool			isInProgress = false;; // To determine whether the mouse click is the first step or the second step
	int				lineStartPositionX;
	int				lineStartPositionY;
	int				lineEndPositionX;
	int				lineEndPositionY;
	
	printf("已进入鼠标画线模式\n");
	printf("操作指南：\n");
	printf("用鼠标先点选起点再点选终点即可连续画线\n");
	//setcolor(0x909090);
	DrawAllPrevShapes(true);
	DrawMenuOutline(1, TOTAL_LN, 1);
	setcolor(0x000000);
	PrintMouseDrawingInsideMenu(0);
	mouse_msg msg;
	
	for (; is_run(); delay_fps(REFRESH_RATE)) // Using "for" statement to draw multiple circles at a time and refresh the screen
	{
		msg = getmouse(); // Get mouse clicks and position

		switch (msg.msg)
		{
		case mouse_msg_down:
			switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
			{
			case 1:
				return;
				break;
			case 2:
				if (g_nTotalShapes > 0)
				{
					if (!isInProgress)
					{
						g_nTotalShapes--;
					}
				}
				// refresh the windows with menu contents
				cleardevice();
				InitUI(0);
				DrawMenuOutline(1, TOTAL_LN, 1);
				setcolor(0x000000);
				PrintMouseDrawingInsideMenu(0);
				setcolor(0x50AA50);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
				DrawAllPrevShapes(true);
				goto move;
				break;
			case 3:
				ChooseColor_EGE(0);
				cleardevice();
				InitUI(0);
				DrawAllPrevShapes(true);
				goto move;
				break;
			case 4:
				ChooseColor_EGE(1);
				cleardevice();
				InitUI(0);
				DrawAllPrevShapes(true);
				goto move;
				break;
			default:
				break;
			}

			/* if the mouse click indicates the first dot, store the position data of the starting point */
			if (!isInProgress)
			{
				lineStartPositionX = msg.x;
				lineStartPositionY = msg.y;

				putpixel(lineStartPositionX, lineStartPositionY, 0x707000);
				putpixel(lineStartPositionX + 1, lineStartPositionY, 0x707000);
				putpixel(lineStartPositionX - 1, lineStartPositionY, 0x707000);
				putpixel(lineStartPositionX, lineStartPositionY + 1, 0x707000);
				putpixel(lineStartPositionX, lineStartPositionY - 1, 0x707000);

				printf("	您已选中起点 (%d, %d)\n", lineStartPositionX, lineStartPositionY);

				isInProgress = true; // updete the drawing process

				break;
			}

			/* if the mouse click indicates the second dot, store the position data of the ending point */
			if (isInProgress)
			{
				lineEndPositionX = msg.x;
				lineEndPositionY = msg.y;

				printf("	您已选中终点 (%d, %d)\n", lineEndPositionX, lineEndPositionY);

				g_nTotalShapes++;
				shapeData[g_nTotalShapes - 1].shapeType = shape_line;
				shapeData[g_nTotalShapes - 1].coords[0].x = lineStartPositionX;
				shapeData[g_nTotalShapes - 1].coords[0].y = lineStartPositionY;
				shapeData[g_nTotalShapes - 1].coords[1].x = lineEndPositionX;
				shapeData[g_nTotalShapes - 1].coords[1].y = lineEndPositionY;
				if (!g_isUserSetColor)
				{
					shapeData[g_nTotalShapes - 1].foregroundColor = RandColor();
				}
				else
				{
					shapeData[g_nTotalShapes - 1].foregroundColor = g_customColor;
				}

				DrawAllPrevShapes(true);
				
				printf("	已画出从 (%d, %d) 到 (%d, %d) 的一条直线\n", 
					lineStartPositionX, 
					lineStartPositionY, 
					lineEndPositionX, 
					lineEndPositionY);

				isInProgress = false; // reset the drawing process
				goto move;
				break;
			}
			break; // not needed
		case mouse_msg_move:
			move:
			if (!isInProgress)
			{
				InitUI(0);
				//DrawMenuOutline(1, TOTAL_LN, 1);
				//setcolor(0x000000);
				//PrintMouseDrawingInsideMenu(0);
				setcolor(0x50AA50);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
				switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
				{
				case 0:
					DrawMenuOutline(1, TOTAL_LN, 1);
					setcolor(0x000000);
					PrintMouseDrawingInsideMenu(0);
					break;
				case 1:
					setcolor(0x000000);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x5050AA);
					PrintMouseDrawingInsideMenu(1);
					break;
				case 2:
					setcolor(0x000000);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x5050AA);
					PrintMouseDrawingInsideMenu(2);
					break;
				case 3:
					setcolor(0x000000);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x5050AA);
					PrintMouseDrawingInsideMenu(3);
					break;
				case 4:
					setcolor(0x000000);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x5050AA);
					PrintMouseDrawingInsideMenu(4);
					break;
				default:
					break;
				}
			}

			if (isInProgress)
			{
				cleardevice();
				delay_fps(10000);
				InitUI(1);
				setcolor(0x50AA50);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);

				putpixel(lineStartPositionX, lineStartPositionY, 0x707000);
				putpixel(lineStartPositionX + 1, lineStartPositionY, 0x707000);
				putpixel(lineStartPositionX - 1, lineStartPositionY, 0x707000);
				putpixel(lineStartPositionX, lineStartPositionY + 1, 0x707000);
				putpixel(lineStartPositionX, lineStartPositionY - 1, 0x707000);
				putpixel(msg.x, msg.y, 0x707000);
				putpixel(msg.x + 1, msg.y, 0x707000);
				putpixel(msg.x - 1, msg.y, 0x707000);
				putpixel(msg.x, msg.y + 1, 0x707000);
				putpixel(msg.x, msg.y - 1, 0x707000);

				DrawAllPrevShapes(true);
				setcolor(0x909090);

				line(lineStartPositionX, lineStartPositionY, msg.x, msg.y);
			}
			break;
		default:
			break;
		}
	}
}

void mouse_DrawRectangle(void)
{
	const short int TOTAL_LN = 4; // total items in the menu bar
	bool			isInProgress = false; // To determine whether the mouse click is the first step or the second step
	int				rectUpLCornerX;
	int				rectUpLCornerY;
	int				rectLowRCornerX;
	int				rectLowRCornerY;

	printf("已进入鼠标画矩形模式\n");
	printf("操作指南：\n");
	printf("用鼠标点选两个对角点即可连续画矩形\n");
	//setcolor(0x909090);
	DrawAllPrevShapes(true);
	DrawMenuOutline(1, TOTAL_LN, 1);
	setcolor(0x000000);
	PrintMouseDrawingInsideMenu(0);
	mouse_msg msg;

	for (; is_run(); delay_fps(REFRESH_RATE)) // Using "for" statement to draw multiple circles at a time and refresh the screen
	{
		msg = getmouse();

		switch (msg.msg)
		{
		case mouse_msg_down:
			switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
			{
			case 1:
				return;
				break;
			case 2:
				if (g_nTotalShapes > 0)
				{
					if (!isInProgress)
					{
						g_nTotalShapes--;
					}
				}
				// refresh the windows with menu contents
				cleardevice();
				InitUI(0);
				DrawMenuOutline(1, TOTAL_LN, 1);
				setcolor(0x000000);
				PrintMouseDrawingInsideMenu(0);
				setcolor(0x50AA50);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
				DrawAllPrevShapes(true);
				goto move;
				break;
			case 3:
				ChooseColor_EGE(0);
				cleardevice();
				InitUI(0);
				DrawAllPrevShapes(true);
				goto move;
				break;
			case 4:
				ChooseColor_EGE(1);
				cleardevice();
				InitUI(0);
				DrawAllPrevShapes(true);
				goto move;
				break;
			default:
				break;
			}

			/* if the mouse click indicates the first dot, store the position data of the center of the circle */
			if (!isInProgress)
			{
				rectUpLCornerX = msg.x;
				rectUpLCornerY = msg.y;

				// print a big dot
				putpixel(rectUpLCornerX, rectUpLCornerY, 0x707000);
				putpixel(rectUpLCornerX + 1, rectUpLCornerY, 0x707000);
				putpixel(rectUpLCornerX - 1, rectUpLCornerY, 0x707000);
				putpixel(rectUpLCornerX, rectUpLCornerY + 1, 0x707000);
				putpixel(rectUpLCornerX, rectUpLCornerY - 1, 0x707000);

				printf("	您已选中点 (%d, %d)\n", rectUpLCornerX, rectUpLCornerY);

				isInProgress = true;
				break;
			}

			/* if the mouse click indicates the first dot, store the position data of another dot on the circle */
			if (isInProgress)
			{

				rectLowRCornerX = msg.x;
				rectLowRCornerY = msg.y;

				printf("	您已选中点 (%d, %d)\n", rectLowRCornerX, rectLowRCornerY);

				g_nTotalShapes++;
				shapeData[g_nTotalShapes - 1].shapeType = shape_rectangle;
				shapeData[g_nTotalShapes - 1].coords[0].x = rectUpLCornerX;
				shapeData[g_nTotalShapes - 1].coords[0].y = rectUpLCornerY;
				shapeData[g_nTotalShapes - 1].coords[1].x = rectLowRCornerX;
				shapeData[g_nTotalShapes - 1].coords[1].y = rectLowRCornerY;

				if (!g_isUserSetColor)
				{
					shapeData[g_nTotalShapes - 1].foregroundColor = RandColor();
				}
				else
				{
					shapeData[g_nTotalShapes - 1].foregroundColor = g_customColor;
				}
				if (!g_isUserSetFillColor)
				{
					shapeData[g_nTotalShapes - 1].isFill = false;
				}
				else
				{
					shapeData[g_nTotalShapes - 1].isFill = true;
					if (g_isFillColorRandom)
					{
						shapeData[g_nTotalShapes - 1].fillColor = RandColor();
					}
					else
					{
						shapeData[g_nTotalShapes - 1].fillColor = g_customFillColor;
					}
				}

				DrawAllPrevShapes(true);

				printf("	已画出以 (%d, %d) 和 (%d, %d) 为对角点的一个矩形\n",
					rectUpLCornerX,
					rectUpLCornerY,
					rectLowRCornerX,
					rectLowRCornerY);

				isInProgress = false;
				goto move;
				break;
			}
			break; // not needed
		case mouse_msg_move:
			move:
			if (!isInProgress)
			{
				InitUI(0);
				//DrawMenuOutline(1, TOTAL_LN, 1);
				//setcolor(0x000000);
				//PrintMouseDrawingInsideMenu(0);
				setcolor(0x50AA50);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
				switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
				{
				case 0:
					DrawMenuOutline(1, TOTAL_LN, 1);
					setcolor(0x000000);
					PrintMouseDrawingInsideMenu(0);
					break;
				case 1:
					setcolor(0x000000);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x5050AA);
					PrintMouseDrawingInsideMenu(1);
					break;
				case 2:
					setcolor(0x000000);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x5050AA);
					PrintMouseDrawingInsideMenu(2);
				case 3:
					setcolor(0x000000);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x5050AA);
					PrintMouseDrawingInsideMenu(3);
					break;
				case 4:
					setcolor(0x000000);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x5050AA);
					PrintMouseDrawingInsideMenu(4);
					break;
				default:
					break;
				}
			}

			if (isInProgress)
			{
				cleardevice();
				delay_fps(10000);
				InitUI(1);
				setcolor(0x50AA50);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);


				putpixel(rectUpLCornerX, rectUpLCornerY, 0x707000);
				putpixel(rectUpLCornerX + 1, rectUpLCornerY, 0x707000);
				putpixel(rectUpLCornerX - 1, rectUpLCornerY, 0x707000);
				putpixel(rectUpLCornerX, rectUpLCornerY + 1, 0x707000);
				putpixel(rectUpLCornerX, rectUpLCornerY - 1, 0x707000);
				putpixel(msg.x, msg.y, 0x707000);
				putpixel(msg.x + 1, msg.y, 0x707000);
				putpixel(msg.x - 1, msg.y, 0x707000);
				putpixel(msg.x, msg.y + 1, 0x707000);
				putpixel(msg.x, msg.y - 1, 0x707000);
				DrawAllPrevShapes(true);
				setcolor(0x909090);

				rectangle(rectUpLCornerX, rectUpLCornerY, msg.x, msg.y);
			}
			break;
		default:
			break;
		}
	}
}

void mouse_DrawPoly(void)
{
	const short int TOTAL_LN = 4; // total items in the menu bar
	bool			isInProgress = false; // To determine whether the mouse click is the first step or the second step
	WORD            polyCoords[50];
	WORD            sides = 0;
	printf("已进入鼠标画多边形模式\n");
	printf("操作指南：\n");
	printf("用鼠标点选顶点，最后一个点靠近起始点来结束\n");
	DrawAllPrevShapes(true);
	DrawMenuOutline(1, TOTAL_LN, 1);
	setcolor(0x000000);
	PrintMouseDrawingInsideMenu(0);
	mouse_msg msg;

	for (; is_run(); delay_fps(REFRESH_RATE)) // Using "for" statement to draw multiple circles at a time and refresh the screen
	{
		msg = getmouse();

		switch (msg.msg)
		{
		case mouse_msg_down:
			switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
			{
			case 1:
				return;
				break;
			case 2:
				if (g_nTotalShapes > 0)
				{
					if (!isInProgress)
					{
						g_nTotalShapes--;
					}
				}
				// refresh the windows with menu contents
				cleardevice();
				InitUI(0);
				DrawMenuOutline(1, TOTAL_LN, 1);
				setcolor(0x000000);
				PrintMouseDrawingInsideMenu(0);
				setcolor(0x50AA50);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
				DrawAllPrevShapes(true);
				goto move;
				break;
			case 3:
				ChooseColor_EGE(0);
				cleardevice();
				InitUI(0);
				DrawAllPrevShapes(true);
				goto move;
				break;
			case 4:
				ChooseColor_EGE(1);
				cleardevice();
				InitUI(0);
				DrawAllPrevShapes(true);
				goto move;
				break;
			default:
				break;
			}

			/* if the mouse click indicates the first dot, store the position data of the center of the circle */
			if (!isInProgress)
			{
				polyCoords[0] = msg.x;
				polyCoords[1] = msg.y;
				sides = 0;
				printf("	您已选中点 (%d, %d)\n", polyCoords[0], polyCoords[1]);

				isInProgress = true;
				break;
			}

			/* if the mouse click indicates the first dot, store the position data of other dots on the circle */
			if (isInProgress)
			{
				sides++;
				polyCoords[2 * sides] = msg.x;
				polyCoords[2 * sides + 1] = msg.y;
				
				printf("	您已选中点 (%d, %d)\n", polyCoords[2 * sides], polyCoords[2 * sides + 1]);

				if (sqrt(pow(polyCoords[0] - polyCoords[2 * sides], 2) +
					pow(polyCoords[1] - polyCoords[2 * sides + 1], 2)) <= 8
					&& sides >= 3)
				{
					polyCoords[2 * sides] = polyCoords[0];
					polyCoords[2 * sides + 1] = polyCoords[1];
					g_nTotalShapes++;
					shapeData[g_nTotalShapes - 1].shapeType = shape_polygon;
					shapeData[g_nTotalShapes - 1].extraData[0] = sides; // record the sides

					// prepare the coordinate data for storage
					for (int j = 0; j < shapeData[g_nTotalShapes - 1].extraData[0]; j++)
					{
						shapeData[g_nTotalShapes - 1].coords[j].x = polyCoords[2 * j];
						shapeData[g_nTotalShapes - 1].coords[j].y = polyCoords[2 * j + 1];
					}

					if (!g_isUserSetColor)
					{
						shapeData[g_nTotalShapes - 1].foregroundColor = RandColor();
					}
					else
					{
						shapeData[g_nTotalShapes - 1].foregroundColor = g_customColor;
					}
					if (!g_isUserSetFillColor)
					{
						shapeData[g_nTotalShapes - 1].isFill = false;
					}
					else
					{
						shapeData[g_nTotalShapes - 1].isFill = true;
						if (g_isFillColorRandom)
						{
							shapeData[g_nTotalShapes - 1].fillColor = RandColor();
						}
						else
						{
							shapeData[g_nTotalShapes - 1].fillColor = g_customFillColor;
						}
					}
					DrawAllPrevShapes(true);
					isInProgress = false;
					printf("	已完成%d边形的绘图\n", sides);
					goto move;
				}
				if (sides >= 24)
				{
					MessageBox(NULL,
						TEXT("边数过多，请立即将正在绘画的多边形封口"),
						TEXT("即将溢出！"),
						MB_OK | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);
				}
				break;
			}
			break; // not needed
		case mouse_msg_move:
		move:
			if (!isInProgress)
			{
				InitUI(0);
				//DrawMenuOutline(1, TOTAL_LN, 1);
				//setcolor(0x000000);
				//PrintMouseDrawingInsideMenu(0);
				setcolor(0x50AA50);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
				switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
				{
				case 0:
					DrawMenuOutline(1, TOTAL_LN, 1);
					setcolor(0x000000);
					PrintMouseDrawingInsideMenu(0);
					break;
				case 1:
					setcolor(0x000000);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x5050AA);
					PrintMouseDrawingInsideMenu(1);
					break;
				case 2:
					setcolor(0x000000);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x5050AA);
					PrintMouseDrawingInsideMenu(2);
				case 3:
					setcolor(0x000000);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x5050AA);
					PrintMouseDrawingInsideMenu(3);
					break;
				case 4:
					setcolor(0x000000);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x5050AA);
					PrintMouseDrawingInsideMenu(4);
					break;
				default:
					break;
				}
			}

			if (isInProgress)
			{
				cleardevice();
				delay_fps(10000);
				InitUI(1);
				setcolor(0x50AA50);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);


				DrawAllPrevShapes(true);
				setcolor(0x909090);

				if (sides >= 1)
				{
					for (int i = 0; i < sides * 2; i += 2)
					{
						line(polyCoords[i], polyCoords[i + 1], polyCoords[i + 2], polyCoords[i + 3]);
					}

				}

				if (sqrt(pow((double)polyCoords[0] - (double)msg.x, 2) +
					pow((double)polyCoords[1] - (double)msg.y, 2)) <= 8
					&& sides >= 2)
				{
					line(polyCoords[sides * 2], polyCoords[sides * 2 + 1], polyCoords[0], polyCoords[1]);
				}
				else
				{
					line(polyCoords[sides * 2], polyCoords[sides * 2 + 1], msg.x, msg.y);
				}

			}
			break;
		default:
			break;
		}
	}
}