#include "menu.h"


void Menu(bool readResult, unsigned short int nOfShapesToDraw)
{
	unsigned short int tmpNOfShapes = g_nTotalShapes;

	cleardevice();
	InitUI(0);
	printf("���ڲ˵����������������\n");

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
						TEXT("���������ͼ��"),
						TEXT("��ʾ"),
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
				xyprintf(678, 582, "��ǰ����: (%03d, %03d)", msg.x, msg.y);
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
						TEXT("���������ͼ��"),
						TEXT("��ʾ"),
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
				xyprintf(678, 582, "��ǰ����: (%03d, %03d)", msg.x, msg.y);
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
			xyprintf(MENU_LENGTH + 170, 250, "��ӭ���� CC ����");			
			setfont(EGE_FONT_SIZE, 0, EGE_FONT);
			xyprintf(MENU_LENGTH + 118, 300, "ע����������ҵ�������뿴���С�(��ҵ)����ѡ��");
			xyprintf(8, 8 + 0 * MENU_HIGHT, "�������ͼ��");
			xyprintf(8, 8 + 1 * MENU_HIGHT, "�ػ�����");
			xyprintf(8, 8 + 2 * MENU_HIGHT, "����껭��");
			xyprintf(8, 8 + 3 * MENU_HIGHT, "����껭����Բ");
			xyprintf(8, 8 + 4 * MENU_HIGHT, "����껭���ľ���");
			xyprintf(8, 8 + 5 * MENU_HIGHT, "!!!����ҵ��������ƶ����");
			break;
		case 1:
			xyprintf(8, 8 + 0 * MENU_HIGHT, "�������ͼ��");
			break;
		case 2:
			xyprintf(8, 8 + 1 * MENU_HIGHT, "�ػ�����");
			break;
		case 3:
			xyprintf(8, 8 + 2 * MENU_HIGHT, "����껭��");
			break;
		case 4:
			xyprintf(8, 8 + 3 * MENU_HIGHT, "����껭����Բ");
			break;
		case 5:
			xyprintf(8, 8 + 4 * MENU_HIGHT, "����껭���ľ���");
			break;
		case 6:
			xyprintf(8, 8 + 5 * MENU_HIGHT, "!!!����ҵ��������ƶ����");
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
			xyprintf(MENU_LENGTH + 170, 250, "��ӭ���� CC ����");
			setfont(EGE_FONT_SIZE, 0, EGE_FONT);
			xyprintf(MENU_LENGTH + 118, 300, "ע����������ҵ�������뿴���С�(��ҵ)����ѡ��");
			xyprintf(8, 8 + 0 * MENU_HIGHT, "�������ͼ��");
			xyprintf(8, 8 + 1 * MENU_HIGHT, "�ػ�ȫ������ʦ��ʱδҪ��");
			xyprintf(8, 8 + 2 * MENU_HIGHT, "�ػ�����");
			xyprintf(8, 8 + 3 * MENU_HIGHT, "����껭��");
			xyprintf(8, 8 + 4 * MENU_HIGHT, "����껭����Բ");
			xyprintf(8, 8 + 5 * MENU_HIGHT, "����껭���ľ���");
			xyprintf(8, 8 + 6 * MENU_HIGHT, "!!!����ҵ��������ƶ����");
			break;
		case 1:
			xyprintf(8, 8 + 0 * MENU_HIGHT, "�������ͼ��");
			break;
		case 2:
			xyprintf(8, 8 + 1 * MENU_HIGHT, "�ػ���δʵ�֣�");
			break;
		case 3:
			xyprintf(8, 8 + 2 * MENU_HIGHT, "�ػ�����");
			break;
		case 4:
			xyprintf(8, 8 + 3 * MENU_HIGHT, "����껭��");
			break;
		case 5:
			xyprintf(8, 8 + 4 * MENU_HIGHT, "����껭����Բ");
			break;
		case 6:
			xyprintf(8, 8 + 5 * MENU_HIGHT, "����껭���ľ���");
			break;
		case 7:
			xyprintf(8, 8 + 6 * MENU_HIGHT, "!!!����ҵ��������ƶ����");
			break;
		default:
			break;
		}
	}
}

