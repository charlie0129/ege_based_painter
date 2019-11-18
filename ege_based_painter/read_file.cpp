#include "read_file.h"

bool ReadFile(void)
{
	cleardevice();
	InitUI(0);
	const short int TOTAL_LN = 2;
	short int readResult; // indicates whether the reading action is successful
	bool isReadyToExit = false;

	printf("���ڲ˵����������������\n");

	mouse_msg msg;

	DrawMenuOutline(TOTAL_LN);
	setcolor(0xFFFFFF);
	setfont(EGE_FONT_SIZE, 0, EGE_FONT);
	
	xyprintf(8, 8 + 0 * MENU_HIGHT, "1. ��ȡ��ͼ�浵");
	xyprintf(8, 8 + 1 * MENU_HIGHT, "2. ����ȡ��ͼ�浵");
	xyprintf(MENU_LENGTH + 15, 8 + 2 * MENU_HIGHT, "��������˵�");
	xyprintf(MENU_LENGTH + 15, 8 + 3 * MENU_HIGHT, "ע��Ҫģ���ȡ���");
	xyprintf(MENU_LENGTH + 15, 8 + 4 * MENU_HIGHT, "    ��ֱ������Debug�ļ������.exe�ļ� ���·�����и�save.draw�ļ�ģ���ȡ���");

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
						TEXT("�����ļ��Ƿ���ڻ�����"), 
						TEXT("��ȡ����"), 
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
						TEXT("��ȡ�ɹ�"), 
						TEXT("��ʾ"), 
						MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION);
					readResult = 1;
					isReadyToExit = true;
				}
				break;
			case 2: // do not read file
				cleardevice();
				InitUI(0);
				MessageBox(NULL,
					TEXT("δ��ȡ"),
					TEXT("��ʾ"),
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
			xyprintf(678, 582, "��ǰ����: (%03d, %03d)", msg.x, msg.y);
			DrawMenuOutline(TOTAL_LN);
			switch (GetMouseCurrentLn(TOTAL_LN))
			{
			case 0:
				DrawMenuOutline(TOTAL_LN);
				setcolor(0xFFFFFF);
				xyprintf(8, 8 + 0 * MENU_HIGHT, "1. ��ȡ��ͼ�浵");
				xyprintf(8, 8 + 1 * MENU_HIGHT, "2. ����ȡ��ͼ�浵");
				break;
			case 1:
				setcolor(0xFFFFFF);
				xyprintf(8, 8 + 0 * MENU_HIGHT, "1. ��ȡ��ͼ�浵");
				xyprintf(8, 8 + 1 * MENU_HIGHT, "2. ����ȡ��ͼ�浵");
				setcolor(0x9090FF);
				xyprintf(8, 8 + 0 * MENU_HIGHT, "1. ��ȡ��ͼ�浵");
				break;
			case 2:
				setcolor(0xFFFFFF);
				xyprintf(8, 8 + 0 * MENU_HIGHT, "1. ��ȡ��ͼ�浵");
				xyprintf(8, 8 + 1 * MENU_HIGHT, "2. ����ȡ��ͼ�浵");
				setcolor(0x9090FF);
				xyprintf(8, 8 + 1 * MENU_HIGHT, "2. ����ȡ��ͼ�浵");
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