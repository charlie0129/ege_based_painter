#include "menu.h"

void Menu(bool readResult)
{
	const short int TOTAL_LN = 7;

	cleardevice();
	InitUI(0);
	printf("请在菜单界面用鼠标点击操作\n");
	DrawMenuOutline(1, TOTAL_LN, 1);
	setcolor(0x000000);
	PrintMenu(0);
	mouse_msg msg;

	for (; ; delay_fps(REFRESH_RATE))
	{
		msg = getmouse();

		switch (msg.msg)
		{
		case mouse_msg_down:
			switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
			{
			case 1: // 退出
				return;
				break;
			case 2: // 另存为
				SaveFile();
				goto move;
				break;
			case 3: // 清除所有图形
				
				cleardevice();
				MessageBox(NULL,
					TEXT("已清除所有图形"),
					TEXT("提示"),
					MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION);
				InitUI(0);
				ClearData();
				goto move;
				break;
			case 4: // 画线
				cleardevice();
				InitUI(0);
				mouse_DrawLine();
				cleardevice();
				InitUI(0);
				goto move;
				break;
			case 5: // 画圆
				cleardevice();
				InitUI(0);
				mouse_DrawCircle();
				cleardevice();
				InitUI(0);
				goto move;
				break;
			case 6: // 画矩形
				cleardevice();
				InitUI(0);
				mouse_DrawRectangle();
				cleardevice();
				InitUI(0);
				goto move;
				break;
			case 7: // 画多边形
				cleardevice();
				InitUI(0);
				coord_DrawPoly();
				cleardevice();
				InitUI(0);
				goto move;
				break;
			default:
				break;
			}
			break; // not needed
		case mouse_msg_move:
			move:
			setcolor(0x50AA50);
			xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
			DrawAllPrevShapes(false);
			DrawMenuOutline(1, TOTAL_LN, 1);
			switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
			{
			case 0:
				DrawMenuOutline(1, TOTAL_LN, 1);
				setcolor(0x000000);
				PrintMenu(0);
				break;
			case 1:
				setcolor(0x000000);
				PrintMenu(0);
				setcolor(0x5050AA);
				PrintMenu(1);
				break;
			case 2:
				setcolor(0x000000);
				PrintMenu(0);
				setcolor(0x5050AA);
				PrintMenu(2);
				break;
			case 3:
				setcolor(0x000000);
				PrintMenu(0);
				setcolor(0x5050AA);
				PrintMenu(3);
				break;
			case 4:
				setcolor(0x000000);
				PrintMenu(0);
				setcolor(0x5050AA);
				PrintMenu(4);
				break;
			case 5:
				setcolor(0x000000);
				PrintMenu(0);
				setcolor(0x5050AA);
				PrintMenu(5);
				break;
			case 6:
				setcolor(0x000000);
				PrintMenu(0);
				setcolor(0x5050AA);
				PrintMenu(6);
				break;
			case 7:
				setcolor(0x000000);
				PrintMenu(0);
				setcolor(0x5050AA);
				PrintMenu(7);
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


void PrintMenu(short int lnToPrint)
{
	switch (lnToPrint)
	{
	case 0:
		setfont(40, 0, "Segoe UI");
		xyprintf(MENU_LENGTH + 170, 250, "欢迎来到 CC 画板");
		setfont(EGE_FONT_SIZE, 0, EGE_FONT);
		xyprintf(MENU_LENGTH + 118, 300, "注：如需检查作业完成情况请看带有“(作业)”的选项");
		xyprintf(8, 8 + 0 * MENU_HIGHT, "退出");
		xyprintf(8, 8 + 1 * MENU_HIGHT, "另存为");
		xyprintf(8, 8 + 2 * MENU_HIGHT, "清除所有图形");
		xyprintf(8, 8 + 3 * MENU_HIGHT, "用鼠标画线");
		xyprintf(8, 8 + 4 * MENU_HIGHT, "用鼠标画圆");
		xyprintf(8, 8 + 5 * MENU_HIGHT, "用鼠标画矩形");
		xyprintf(8, 8 + 6 * MENU_HIGHT, "!!!（作业）坐标绘制多边形");
		break;
	case 1:
		xyprintf(8, 8 + 0 * MENU_HIGHT, "退出");
		break;
	case 2:
		xyprintf(8, 8 + 1 * MENU_HIGHT, "另存为");
		break;
	case 3:
		xyprintf(8, 8 + 2 * MENU_HIGHT, "清除所有图形");
		break;
	case 4:
		xyprintf(8, 8 + 3 * MENU_HIGHT, "用鼠标画线");
		break;
	case 5:
		xyprintf(8, 8 + 4 * MENU_HIGHT, "用鼠标画圆");
		break;
	case 6:
		xyprintf(8, 8 + 5 * MENU_HIGHT, "用鼠标画矩形");
		break;
	case 7:
		xyprintf(8, 8 + 6 * MENU_HIGHT, "!!!（作业）坐标绘制多边形");
		break;
	default:
		break;
	}
}

