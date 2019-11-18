#include "read_file.h"

bool ReadFile(void)
{
	cleardevice();
	InitUI(0);
	const short int TOTAL_LN = 2;
	short int readResult; // indicates whether the reading action is successful
	bool isReadyToExit = false;

	printf("请在菜单界面用鼠标点击操作\n");

	mouse_msg msg;

	DrawMenuOutline(TOTAL_LN);
	setcolor(0xFFFFFF);
	setfont(EGE_FONT_SIZE, 0, EGE_FONT);
	
	xyprintf(8, 8 + 0 * MENU_HIGHT, "1. 读取绘图存档");
	xyprintf(8, 8 + 1 * MENU_HIGHT, "2. 不读取绘图存档");
	xyprintf(MENU_LENGTH + 15, 8 + 2 * MENU_HIGHT, "用鼠标点击菜单");
	xyprintf(MENU_LENGTH + 15, 8 + 3 * MENU_HIGHT, "注：要模拟读取情况");
	xyprintf(MENU_LENGTH + 15, 8 + 4 * MENU_HIGHT, "    请直接运行Debug文件夹里的.exe文件 相对路径下有个save.draw文件模拟读取情况");

	FILE *fp;

	for (; !isReadyToExit; delay_fps(800))
	{
		msg = getmouse();

		switch (msg.msg)
		{
		case mouse_msg_down:
			switch (GetMouseCurrentLn(TOTAL_LN))
			{
			case 1:
				case1:
				if ((fp = fopen(".\\save.draw", "r")) == NULL) // unsuccessful reading
				{
					cleardevice();
					InitUI(0);
					int selection = MessageBox(NULL, 
						TEXT("请检查文件是否存在或完整"), 
						TEXT("读取错误！"), 
						MB_ABORTRETRYIGNORE | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);
					switch (selection)
					{
					case IDRETRY:
						goto case1;
						break;
					case IDABORT:
						isReadyToExit = false;
						break;
					case IDIGNORE:
						isReadyToExit = true;
						readResult = 0;
						break;
					default:
						break;
					}
				}
				else // successful reading
				{
					cleardevice();
					InitUI(0);
					MessageBox(NULL, 
						TEXT("读取成功"), 
						TEXT("提示"), 
						MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION);
					readResult = 1;
					isReadyToExit = true;
				}
				break;
			case 2: // do not read file
				cleardevice();
				InitUI(0);
				MessageBox(NULL,
					TEXT("未读取"),
					TEXT("提示"),
					MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION);
				readResult = 0;
				isReadyToExit = true;
				break;
			default:
				break;
			}
			break; // not needed
		case mouse_msg_move:
			setcolor(0x90FF90);
			xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
			DrawMenuOutline(TOTAL_LN);
			switch (GetMouseCurrentLn(TOTAL_LN))
			{
			case 0:
				DrawMenuOutline(TOTAL_LN);
				setcolor(0xFFFFFF);
				xyprintf(8, 8 + 0 * MENU_HIGHT, "1. 读取绘图存档");
				xyprintf(8, 8 + 1 * MENU_HIGHT, "2. 不读取绘图存档");
				break;
			case 1:
				setcolor(0xFFFFFF);
				xyprintf(8, 8 + 0 * MENU_HIGHT, "1. 读取绘图存档");
				xyprintf(8, 8 + 1 * MENU_HIGHT, "2. 不读取绘图存档");
				setcolor(0x9090FF);
				xyprintf(8, 8 + 0 * MENU_HIGHT, "1. 读取绘图存档");
				break;
			case 2:
				setcolor(0xFFFFFF);
				xyprintf(8, 8 + 0 * MENU_HIGHT, "1. 读取绘图存档");
				xyprintf(8, 8 + 1 * MENU_HIGHT, "2. 不读取绘图存档");
				setcolor(0x9090FF);
				xyprintf(8, 8 + 1 * MENU_HIGHT, "2. 不读取绘图存档");
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
	return readResult;
}