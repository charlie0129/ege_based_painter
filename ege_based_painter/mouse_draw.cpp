#include "mouse_draw.h"



void mouse_DrawCircle(unsigned short int nOfShapesToDraw)
{
	const short int TOTAL_LN = 2; // total items in the menu bar
	bool isInProgress = false; // To determine whether the mouse click is the first step or the second step
	int circleCenterX;
	int circleCenterY;
	int	circleOuterX;
	int circleOuterY;
	unsigned short int tmpNOfShapes = g_nTotalShapes;
	

	printf("已进入鼠标画空心圆模式\n");
	printf("操作指南：\n");
	printf("用鼠标先点选圆心再点选圆上任意一点即可连续画空心圆\n");
	//setcolor(0x555555);
	DrawAllPrevShapes(true);
	DrawMenuOutline(TOTAL_LN);
	setcolor(0xFFFFFF);
	PrintMouseDrawingInsideMenu(0);
	mouse_msg msg;

	

	for (; is_run(); delay_fps(800)) // Using "for" statement to draw multiple circles at a time and refresh the screen
	{

		msg = getmouse();
	
		switch (msg.msg)
		{
		case mouse_msg_down:
			if (GetMouseCurrentLn(TOTAL_LN) == 2) // undo
			{
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
				DrawMenuOutline(TOTAL_LN);
				setcolor(0xFFFFFF);
				PrintMouseDrawingInsideMenu(0);
				setcolor(0x90FF90);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
				DrawAllPrevShapes(true);
				break;
			}

			if (GetMouseCurrentLn(TOTAL_LN) == 1)
			{
				return;
			}

			/* if the mouse click indicates the first dot, store the position data of the center of the circle */
			if (!isInProgress && 
				(g_nTotalShapes - nOfShapesToDraw < tmpNOfShapes))
			{
				circleCenterX = msg.x;
				circleCenterY = msg.y;

				// print a big dot
				putpixel(circleCenterX, circleCenterY, 0xFCFC54);
				putpixel(circleCenterX + 1, circleCenterY, 0xFCFC54);
				putpixel(circleCenterX - 1, circleCenterY, 0xFCFC54);
				putpixel(circleCenterX, circleCenterY + 1, 0xFCFC54);
				putpixel(circleCenterX, circleCenterY - 1, 0xFCFC54);

				printf("	您已选中圆心 (%d, %d)\n", circleCenterX, circleCenterY);

				isInProgress = true;
				break;
			}

			/* if the mouse click indicates the first dot, store the position data of another dot on the circle */
			if (isInProgress &&
				(g_nTotalShapes - nOfShapesToDraw < tmpNOfShapes))
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
				
				DrawAllPrevShapes(true);
			

				printf("	已画出以 (%d, %d) 为圆心，(%d, %d) 为圆上一点，半径为 %d 的一个空心圆\n", 
					circleCenterX, 
					circleCenterY, 
					circleOuterX, 
					circleOuterY, 
					(int)sqrt(pow(shapeData[g_nTotalShapes - 1].coords[0].x - shapeData[g_nTotalShapes - 1].coords[1].x, 2) +
							  pow(shapeData[g_nTotalShapes - 1].coords[0].y - shapeData[g_nTotalShapes - 1].coords[1].y, 2)));
				isInProgress = false;

				break;
			}
			break; // not needed
		case mouse_msg_move:

			if (!isInProgress)
			{
				InitUI(0);
				//DrawMenuOutline(TOTAL_LN);
				//setcolor(0xFFFFFF);
				//PrintMouseDrawingInsideMenu(0);
				setcolor(0x90FF90);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
				switch (GetMouseCurrentLn(TOTAL_LN))
				{
				case 0:
					DrawMenuOutline(TOTAL_LN);
					setcolor(0xFFFFFF);
					PrintMouseDrawingInsideMenu(0);
					break;
				case 1:
					setcolor(0xFFFFFF);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x9090FF);
					PrintMouseDrawingInsideMenu(1);
					break;
				case 2:
					setcolor(0xFFFFFF);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x9090FF);
					PrintMouseDrawingInsideMenu(2);
				default:
					break;
				}
			}
			
			if (isInProgress)
			{
				cleardevice(); 
				delay_fps(10000);
				InitUI(1);
				setcolor(0x90FF90);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);


				putpixel(circleCenterX, circleCenterY, 0xFCFC54);
				putpixel(circleCenterX + 1, circleCenterY, 0xFCFC54);
				putpixel(circleCenterX - 1, circleCenterY, 0xFCFC54);
				putpixel(circleCenterX, circleCenterY + 1, 0xFCFC54);
				putpixel(circleCenterX, circleCenterY - 1, 0xFCFC54);
				putpixel(msg.x, msg.y, 0xFCFC54);
				putpixel(msg.x + 1, msg.y, 0xFCFC54);
				putpixel(msg.x - 1, msg.y, 0xFCFC54);
				putpixel(msg.x, msg.y + 1, 0xFCFC54);
				putpixel(msg.x, msg.y - 1, 0xFCFC54);
				DrawAllPrevShapes(true);
				setcolor(0x555555);
				
				circle(circleCenterX, circleCenterY, (int)sqrt(pow(circleCenterX - msg.x, 2) + pow(circleCenterY - msg.y, 2)));
			}


			break;
		default:
			break;
		}
	}
}

void mouse_DrawLine(void)
{
	const short int TOTAL_LN = 2;
	bool isInProgress = false;; // To determine whether the mouse click is the first step or the second step
	int lineStartPositionX;
	int lineStartPositionY;
	int	lineEndPositionX;
	int lineEndPositionY;
	

	printf("已进入鼠标画线模式\n");
	printf("操作指南：\n");
	printf("用鼠标先点选起点再点选终点即可连续画线\n");
	//setcolor(0x555555);
	DrawAllPrevShapes(true);
	DrawMenuOutline(TOTAL_LN);
	setcolor(0xFFFFFF);
	PrintMouseDrawingInsideMenu(0);

	mouse_msg msg;
	

	for (; is_run(); delay_fps(800)) // Using "for" statement to draw multiple circles at a time and refresh the screen
	{
		msg = getmouse(); // Get mouse clicks and position

		switch (msg.msg)
		{
		case mouse_msg_down:

			if (GetMouseCurrentLn(TOTAL_LN) == 2)
			{
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
				DrawMenuOutline(TOTAL_LN);
				setcolor(0xFFFFFF);
				PrintMouseDrawingInsideMenu(0);
				setcolor(0x90FF90);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
				DrawAllPrevShapes(true);
				break;
			}

			if (GetMouseCurrentLn(TOTAL_LN) == 1)
			{
				return;
			}




			/* if the mouse click indicates the first dot, store the position data of the starting point */
			if (!isInProgress)
			{
				lineStartPositionX = msg.x;
				lineStartPositionY = msg.y;

				putpixel(lineStartPositionX, lineStartPositionY, 0xFCFC54);
				putpixel(lineStartPositionX + 1, lineStartPositionY, 0xFCFC54);
				putpixel(lineStartPositionX - 1, lineStartPositionY, 0xFCFC54);
				putpixel(lineStartPositionX, lineStartPositionY + 1, 0xFCFC54);
				putpixel(lineStartPositionX, lineStartPositionY - 1, 0xFCFC54);

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

				break;
			}
			break; // not needed
		case mouse_msg_move:

			if (!isInProgress)
			{
				InitUI(0);
				//DrawMenuOutline(TOTAL_LN);
				//setcolor(0xFFFFFF);
				//PrintMouseDrawingInsideMenu(0);
				setcolor(0x90FF90);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
				switch (GetMouseCurrentLn(TOTAL_LN))
				{
				case 0:
					DrawMenuOutline(TOTAL_LN);
					setcolor(0xFFFFFF);
					PrintMouseDrawingInsideMenu(0);
					break;
				case 1:
					setcolor(0xFFFFFF);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x9090FF);
					PrintMouseDrawingInsideMenu(1);
					break;
				case 2:
					setcolor(0xFFFFFF);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x9090FF);
					PrintMouseDrawingInsideMenu(2);
				default:
					break;
				}
			}

			if (isInProgress)
			{
				cleardevice();
				delay_fps(10000);
				InitUI(1);
				setcolor(0x90FF90);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);

				putpixel(lineStartPositionX, lineStartPositionY, 0xFCFC54);
				putpixel(lineStartPositionX + 1, lineStartPositionY, 0xFCFC54);
				putpixel(lineStartPositionX - 1, lineStartPositionY, 0xFCFC54);
				putpixel(lineStartPositionX, lineStartPositionY + 1, 0xFCFC54);
				putpixel(lineStartPositionX, lineStartPositionY - 1, 0xFCFC54);
				putpixel(msg.x, msg.y, 0xFCFC54);
				putpixel(msg.x + 1, msg.y, 0xFCFC54);
				putpixel(msg.x - 1, msg.y, 0xFCFC54);
				putpixel(msg.x, msg.y + 1, 0xFCFC54);
				putpixel(msg.x, msg.y - 1, 0xFCFC54);
				DrawAllPrevShapes(true);
				setcolor(0x555555);

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
	const short int TOTAL_LN = 2; // total items in the menu bar
	bool isInProgress = false; // To determine whether the mouse click is the first step or the second step
	int rectUpLCornerX;
	int rectUpLCornerY;
	int	rectLowRCornerX;
	int rectLowRCornerY;

	printf("已进入鼠标画空心矩形模式\n");
	printf("操作指南：\n");
	printf("用鼠标点选两个对角点即可连续画空矩形\n");
	//setcolor(0x555555);
	DrawAllPrevShapes(true);
	DrawMenuOutline(TOTAL_LN);
	setcolor(0xFFFFFF);
	PrintMouseDrawingInsideMenu(0);
	mouse_msg msg;

	for (; is_run(); delay_fps(800)) // Using "for" statement to draw multiple circles at a time and refresh the screen
	{

		msg = getmouse();

		switch (msg.msg)
		{
		case mouse_msg_down:
			if (GetMouseCurrentLn(TOTAL_LN) == 2) // undo
			{
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
				DrawMenuOutline(TOTAL_LN);
				setcolor(0xFFFFFF);
				PrintMouseDrawingInsideMenu(0);
				setcolor(0x90FF90);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
				DrawAllPrevShapes(true);
				break;
			}

			if (GetMouseCurrentLn(TOTAL_LN) == 1)
			{
				return;
			}

			/* if the mouse click indicates the first dot, store the position data of the center of the circle */
			if (!isInProgress)
			{
				rectUpLCornerX = msg.x;
				rectUpLCornerY = msg.y;

				// print a big dot
				putpixel(rectUpLCornerX, rectUpLCornerY, 0xFCFC54);
				putpixel(rectUpLCornerX + 1, rectUpLCornerY, 0xFCFC54);
				putpixel(rectUpLCornerX - 1, rectUpLCornerY, 0xFCFC54);
				putpixel(rectUpLCornerX, rectUpLCornerY + 1, 0xFCFC54);
				putpixel(rectUpLCornerX, rectUpLCornerY - 1, 0xFCFC54);

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

				DrawAllPrevShapes(true);


				printf("	已画出以 (%d, %d) 和 (%d, %d) 为对角点的一个矩形\n",
					rectUpLCornerX,
					rectUpLCornerY,
					rectLowRCornerX,
					rectLowRCornerY);
				isInProgress = false;

				break;
			}
			break; // not needed
		case mouse_msg_move:

			if (!isInProgress)
			{
				InitUI(0);
				//DrawMenuOutline(TOTAL_LN);
				//setcolor(0xFFFFFF);
				//PrintMouseDrawingInsideMenu(0);
				setcolor(0x90FF90);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
				switch (GetMouseCurrentLn(TOTAL_LN))
				{
				case 0:
					DrawMenuOutline(TOTAL_LN);
					setcolor(0xFFFFFF);
					PrintMouseDrawingInsideMenu(0);
					break;
				case 1:
					setcolor(0xFFFFFF);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x9090FF);
					PrintMouseDrawingInsideMenu(1);
					break;
				case 2:
					setcolor(0xFFFFFF);
					PrintMouseDrawingInsideMenu(0);
					setcolor(0x9090FF);
					PrintMouseDrawingInsideMenu(2);
				default:
					break;
				}
			}

			if (isInProgress)
			{
				cleardevice();
				delay_fps(10000);
				InitUI(1);
				setcolor(0x90FF90);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);


				putpixel(rectUpLCornerX, rectUpLCornerY, 0xFCFC54);
				putpixel(rectUpLCornerX + 1, rectUpLCornerY, 0xFCFC54);
				putpixel(rectUpLCornerX - 1, rectUpLCornerY, 0xFCFC54);
				putpixel(rectUpLCornerX, rectUpLCornerY + 1, 0xFCFC54);
				putpixel(rectUpLCornerX, rectUpLCornerY - 1, 0xFCFC54);
				putpixel(msg.x, msg.y, 0xFCFC54);
				putpixel(msg.x + 1, msg.y, 0xFCFC54);
				putpixel(msg.x - 1, msg.y, 0xFCFC54);
				putpixel(msg.x, msg.y + 1, 0xFCFC54);
				putpixel(msg.x, msg.y - 1, 0xFCFC54);
				DrawAllPrevShapes(true);
				setcolor(0x555555);

				rectangle(rectUpLCornerX, rectUpLCornerY, msg.x, msg.y);
			}


			break;
		default:
			break;
		}
	}
}