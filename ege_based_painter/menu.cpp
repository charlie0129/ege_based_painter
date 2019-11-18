#include "menu.h"


void Menu(bool readResult, unsigned short int nOfShapesToDraw)
{
	unsigned short int tmpNOfShapes = g_nTotalShapes;

	cleardevice();
	InitUI(0);
	printf("请在菜单界面用鼠标点击操作\n");

	mouse_msg msg;

	if (readResult)
	{
		const short int TOTAL_LN = 7;
		DrawMenuOutline(TOTAL_LN);
		setcolor(0xFFFFFF);
		PrintMenu(0, readResult);

		for (; ; delay_fps(800))
		{
			if (!(g_nTotalShapes - nOfShapesToDraw < tmpNOfShapes))
			{
				return;
			}

			msg = getmouse();

			switch (msg.msg)
			{
			case mouse_msg_down:
				switch (GetMouseCurrentLn(TOTAL_LN))
				{
				case 1:
					cleardevice();
					MessageBox(NULL,
						TEXT("已清除所有图形"),
						TEXT("提示"),
						MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION);
					InitUI(0);
					ClearData();
					break;
				case 3:
					cleardevice();
					InitUI(0);
					



					cleardevice();
					InitUI(0);
					break;
				case 4:
					cleardevice();
					InitUI(0);
					mouse_DrawLine();
					cleardevice();
					InitUI(0);
					break;
				case 5:
					cleardevice();
					InitUI(0);
					mouse_DrawCircle(nOfShapesToDraw);
					cleardevice();
					InitUI(0);
					break;
				case 6:
					cleardevice();
					InitUI(0);
					mouse_DrawRectangle();
					cleardevice();
					InitUI(0);
					break;
				case 7:
					cleardevice();
					InitUI(0);
					coord_DrawPoly();
					cleardevice();
					InitUI(0);
					break;
				default:
					break;
				}
				break; // not needed
			case mouse_msg_move:
				setcolor(0x90FF90);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
				setcolor(0x202030);
				DrawAllPrevShapes(false);
				DrawMenuOutline(TOTAL_LN);
				switch (GetMouseCurrentLn(TOTAL_LN))
				{
				case 0:
					DrawMenuOutline(TOTAL_LN);
					setcolor(0xFFFFFF);
					PrintMenu(0, readResult);
					break;
				case 1:
					setcolor(0xFFFFFF);
					PrintMenu(0, readResult);
					setcolor(0x9090FF);
					PrintMenu(1, readResult);
					break;
				case 2:
					setcolor(0xFFFFFF);
					PrintMenu(0, readResult);
					setcolor(0x9090FF);
					PrintMenu(2, readResult);
					break;
				case 3:
					setcolor(0xFFFFFF);
					PrintMenu(0, readResult);
					setcolor(0x9090FF);
					PrintMenu(3, readResult);
					break;
				case 4:
					setcolor(0xFFFFFF);
					PrintMenu(0, readResult);
					setcolor(0x9090FF);
					PrintMenu(4, readResult);
					break;
				case 5:
					setcolor(0xFFFFFF);
					PrintMenu(0, readResult);
					setcolor(0x9090FF);
					PrintMenu(5, readResult);
					break;
				case 6:
					setcolor(0xFFFFFF);
					PrintMenu(0, readResult);
					setcolor(0x9090FF);
					PrintMenu(6, readResult);
					break;
				case 7:
					setcolor(0xFFFFFF);
					PrintMenu(0, readResult);
					setcolor(0x9090FF);
					PrintMenu(7, readResult);
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}
	}

	if (!readResult)
	{
		const short int TOTAL_LN = 6;
		DrawMenuOutline(TOTAL_LN);
		setcolor(0xFFFFFF);
		PrintMenu(0, readResult);



		for (; ; delay_fps(800))
		{
			if (!(g_nTotalShapes - nOfShapesToDraw < tmpNOfShapes))
			{
				return;
			}

			msg = getmouse();

			switch (msg.msg)
			{
			case mouse_msg_down:
				switch (GetMouseCurrentLn(TOTAL_LN))
				{
				case 1:
					cleardevice();
					MessageBox(NULL,
						TEXT("已清除所有图形"),
						TEXT("提示"),
						MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION);
					InitUI(0);
					ClearData();
					break;
				case 2:
					cleardevice();
					InitUI(0);
					



					cleardevice();
					InitUI(0);
					break;
				case 3:
					cleardevice();
					InitUI(0);
					mouse_DrawLine();
					cleardevice();
					InitUI(0);
					break;
				case 4:
					cleardevice();
					InitUI(0);
					mouse_DrawCircle(nOfShapesToDraw);
					cleardevice();
					InitUI(0);
					break;
				case 5:
					cleardevice();
					InitUI(0);
					mouse_DrawRectangle();
					cleardevice();
					InitUI(0);
					break;
				case 6:
					cleardevice();
					InitUI(0);
					coord_DrawPoly();
					cleardevice();
					InitUI(0);
					break;
				default:
					break;
				}
				break; // not needed
			case mouse_msg_move:
				setcolor(0x90FF90);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
				setcolor(0x202030);
				DrawAllPrevShapes(false);
				DrawMenuOutline(TOTAL_LN);
				switch (GetMouseCurrentLn(TOTAL_LN))
				{
				case 0:
					DrawMenuOutline(TOTAL_LN);
					setcolor(0xFFFFFF);
					PrintMenu(0, readResult);
					break;
				case 1:
					setcolor(0xFFFFFF);
					PrintMenu(0, readResult);
					setcolor(0x9090FF);
					PrintMenu(1, readResult);
					break;
				case 2:
					setcolor(0xFFFFFF);
					PrintMenu(0, readResult);
					setcolor(0x9090FF);
					PrintMenu(2, readResult);
					break;
				case 3:
					setcolor(0xFFFFFF);
					PrintMenu(0, readResult);
					setcolor(0x9090FF);
					PrintMenu(3, readResult);
					break;
				case 4:
					setcolor(0xFFFFFF);
					PrintMenu(0, readResult);
					setcolor(0x9090FF);
					PrintMenu(4, readResult);
					break;
				case 5:
					setcolor(0xFFFFFF);
					PrintMenu(0, readResult);
					setcolor(0x9090FF);
					PrintMenu(5, readResult);
					break;
				case 6:
					setcolor(0xFFFFFF);
					PrintMenu(0, readResult);
					setcolor(0x9090FF);
					PrintMenu(6, readResult);
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}
	}
}



void PrintMenu(short int lnToPrint, short int errCode)
{
	if (errCode == 0)
	{
		switch (lnToPrint)
		{
		case 0:
			setfont(40, 0, "Segoe UI");
			xyprintf(MENU_LENGTH + 170, 250, "欢迎来到 CC 画板");			
			setfont(EGE_FONT_SIZE, 0, EGE_FONT);
			xyprintf(MENU_LENGTH + 118, 300, "注：如需检查作业完成情况请看带有“(作业)”的选项");
			xyprintf(8, 8 + 0 * MENU_HIGHT, "清除所有图形");
			xyprintf(8, 8 + 1 * MENU_HIGHT, "重画单个");
			xyprintf(8, 8 + 2 * MENU_HIGHT, "用鼠标画线");
			xyprintf(8, 8 + 3 * MENU_HIGHT, "用鼠标画空心圆");
			xyprintf(8, 8 + 4 * MENU_HIGHT, "用鼠标画空心矩形");
			xyprintf(8, 8 + 5 * MENU_HIGHT, "!!!（作业）坐标绘制多边形");
			break;
		case 1:
			xyprintf(8, 8 + 0 * MENU_HIGHT, "清除所有图形");
			break;
		case 2:
			xyprintf(8, 8 + 1 * MENU_HIGHT, "重画单个");
			break;
		case 3:
			xyprintf(8, 8 + 2 * MENU_HIGHT, "用鼠标画线");
			break;
		case 4:
			xyprintf(8, 8 + 3 * MENU_HIGHT, "用鼠标画空心圆");
			break;
		case 5:
			xyprintf(8, 8 + 4 * MENU_HIGHT, "用鼠标画空心矩形");
			break;
		case 6:
			xyprintf(8, 8 + 5 * MENU_HIGHT, "!!!（作业）坐标绘制多边形");
			break;
		default:
			break;
		}
	}

	if (errCode == 1)
	{
		switch (lnToPrint)
		{
		case 0:
			setfont(40, 0, "Segoe UI");
			xyprintf(MENU_LENGTH + 170, 250, "欢迎来到 CC 画板");
			setfont(EGE_FONT_SIZE, 0, EGE_FONT);
			xyprintf(MENU_LENGTH + 118, 300, "注：如需检查作业完成情况请看带有“(作业)”的选项");
			xyprintf(8, 8 + 0 * MENU_HIGHT, "清除所有图形");
			xyprintf(8, 8 + 1 * MENU_HIGHT, "重画全部（老师暂时未要求）");
			xyprintf(8, 8 + 2 * MENU_HIGHT, "重画单个");
			xyprintf(8, 8 + 3 * MENU_HIGHT, "用鼠标画线");
			xyprintf(8, 8 + 4 * MENU_HIGHT, "用鼠标画空心圆");
			xyprintf(8, 8 + 5 * MENU_HIGHT, "用鼠标画空心矩形");
			xyprintf(8, 8 + 6 * MENU_HIGHT, "!!!（作业）坐标绘制多边形");
			break;
		case 1:
			xyprintf(8, 8 + 0 * MENU_HIGHT, "清除所有图形");
			break;
		case 2:
			xyprintf(8, 8 + 1 * MENU_HIGHT, "重画（未实现）");
			break;
		case 3:
			xyprintf(8, 8 + 2 * MENU_HIGHT, "重画单个");
			break;
		case 4:
			xyprintf(8, 8 + 3 * MENU_HIGHT, "用鼠标画线");
			break;
		case 5:
			xyprintf(8, 8 + 4 * MENU_HIGHT, "用鼠标画空心圆");
			break;
		case 6:
			xyprintf(8, 8 + 5 * MENU_HIGHT, "用鼠标画空心矩形");
			break;
		case 7:
			xyprintf(8, 8 + 6 * MENU_HIGHT, "!!!（作业）坐标绘制多边形");
			break;
		default:
			break;
		}
	}
}

