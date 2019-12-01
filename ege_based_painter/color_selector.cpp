#include "color_selector.h"

int colorInf[7] = { 0x0000AA,   //BLUE
					0x00AA00,   //GREEN
					0x00AAAA,   //CYAN
					0xAA0000,   //RED
					0xAA00AA,   //MAGENTA
					0xAAAA00,   //YELLOW
					0x808080 }; //GRAY

void ChooseColor_EGE(WORD mode)
{
	const int TOTAL_LN = 10 + mode;
	bool hasSetColor = false;

	// used for color customization
	const short int N_OF_NUMS_TO_READ = 3;
	const int LEN_OF_STR_TO_READ = 11;
	const int INPUT_MIN = 0;
	const int INPUT_MAX = 255;

	// initialization of varibles needed to read inputs
	char str[LEN_OF_STR_TO_READ];
	char* readTmp;
	bool isInputValid = true;
	int numRead[N_OF_NUMS_TO_READ];
	int i; // loop controller. I didn't use "for" loop because in this situation it's not a good idea.


	printf("�ѽ�����ɫѡ��ģʽ\n");
	printf("����ָ�ϣ�\n");
	printf("������ȵ�ѡ��ɫ\n");
	cleardevice();
	InitUI(1);
	DrawMenuOutline(1, TOTAL_LN, 1);
	DrawAllPrevShapes(true);

	PrintColorChoosingInsideMenu(0, true, mode);


	mouse_msg msg;

	msg = getmouse();

	for (; !hasSetColor; delay_fps(800))
	{

		msg = getmouse();
		switch (msg.msg)
		{
		case mouse_msg_down:
			switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
			{
			case 1:
				return;

			case 2:
				hasSetColor = true;
				if (mode == 0)
				{
					g_isUserSetColor = true;
					g_customColor = colorInf[0];
				}
				else
				{
					g_isFillColorRandom = false;
					g_isUserSetFillColor = true;
					g_customFillColor = colorInf[0];
				}				
				printf("		������Ϊ��ɫ\n");
				break;
			case 3:
				hasSetColor = true;
				if (mode == 0)
				{
					g_isUserSetColor = true;
					g_customColor = colorInf[1];
				}
				else
				{
					g_isFillColorRandom = false;
					g_isUserSetFillColor = true;
					g_customFillColor = colorInf[1];
				}
				printf("		������Ϊ��ɫ\n");

				break;
			case 4:
				hasSetColor = true;
				if (mode == 0)
				{
					g_isUserSetColor = true;
					g_customColor = colorInf[2];
				}
				else
				{
					g_isFillColorRandom = false;
					g_isUserSetFillColor = true;
					g_customFillColor = colorInf[2];
				}
				printf("		������Ϊ��ɫ\n");
				break;
			case 5:
				hasSetColor = true;
				if (mode == 0)
				{
					g_isUserSetColor = true;
					g_customColor = colorInf[3];
				}
				else
				{
					g_isFillColorRandom = false;
					g_isUserSetFillColor = true;
					g_customFillColor = colorInf[3];
				}
				printf("		������Ϊ��ɫ\n");
				break;
			case 6:
				hasSetColor = true;
				if (mode == 0)
				{
					g_isUserSetColor = true;
					g_customColor = colorInf[4];
				}
				else
				{
					g_isFillColorRandom = false;
					g_isUserSetFillColor = true;
					g_customFillColor = colorInf[4];
				}
				printf("		������Ϊ��ɫ\n");
				break;
			case 7:
				hasSetColor = true;
				if (mode == 0)
				{
					g_isUserSetColor = true;
					g_customColor = colorInf[5];
				}
				else
				{
					g_isFillColorRandom = false;
					g_isUserSetFillColor = true;
					g_customFillColor = colorInf[5];
				}
				printf("		������Ϊ��ɫ\n");
				break;
			case 8:
				hasSetColor = true;
				if (mode == 0)
				{
					g_isUserSetColor = true;
					g_customColor = colorInf[6];
				}
				else
				{
					g_isFillColorRandom = false;
					g_isUserSetFillColor = true;
					g_customFillColor = colorInf[6];
				}
				printf("		������Ϊ��ɫ\n");
				break;
			case 9:
				hasSetColor = true;

				do // ������Ч���˳�
				{
					i = 0;
					memset(str, 0, sizeof(str));

					if (isInputValid)
					{
						inputbox_getline("�밴����ʾ����", "������10����8����RGB��ɫ����\",\"�ֿ�����: 255,255,255", str, sizeof(str) / sizeof(*str));
					}
					else if (!isInputValid)
					{
						inputbox_getline("������Ч������������", "������10����8����RGB��ɫ����\",\"�ֿ�����: 255,255,255", str, sizeof(str) / sizeof(*str));
					}

					readTmp = strtok(str, ","); // separate the input string

					while (readTmp != NULL)
					{
						// make sure the input is all numbers
						if (strspn(readTmp, "0123456789") != strlen(readTmp))
						{
							isInputValid = false;
							break;
						}

						// avoid too many input numbers 
						if (i >= N_OF_NUMS_TO_READ)
						{
							isInputValid = false;
							break;
						}
						numRead[i] = atoi(readTmp);

						// avoid out-of-range input numbers
						if ((numRead[i] > INPUT_MAX) || (numRead[i] < INPUT_MIN))
						{
							isInputValid = false;
							break;
						}

						i++;
						isInputValid = true;
						readTmp = strtok(NULL, ",");
					}

					// avoid too few input numbers
					if (i < N_OF_NUMS_TO_READ)
					{
						isInputValid = false;
					}
				} while (!isInputValid);
				if (mode == 0)
				{
					g_isUserSetColor = true;
					g_customColor = EGERGB(numRead[0], numRead[1], numRead[2]);
				}
				else
				{
					g_isFillColorRandom = false;
					g_isUserSetFillColor = true;
					g_customFillColor = EGERGB(numRead[0], numRead[1], numRead[2]);
				}
				printf("		������Ϊ #%02X%02X%02X ɫ\n", numRead[0], numRead[1], numRead[2]);
				break;
			case 10:
				hasSetColor = true;
				if (mode == 0)
				{
					g_isUserSetColor = false;
				}
				else
				{
					g_isUserSetFillColor = true;
					g_isFillColorRandom = true;
				}
				printf("		������Ϊ���ɫ\n");
				break;
			case 11:
				hasSetColor = true;
				g_isUserSetFillColor = false;
				printf("		��ȡ�����ɫ\n");
				break;
			default:
				break;
			}
			break; // not needed
		case mouse_msg_move:
			setcolor(0x50AA50);
			xyprintf(678, 582, "��ǰ����: (%03d, %03d)", msg.x, msg.y);
			setcolor(0x202030);
			DrawAllPrevShapes(true);
			DrawMenuOutline(1, TOTAL_LN, 1);
			switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
			{
			case 0:
				DrawMenuOutline(1, TOTAL_LN, 1);
				PrintColorChoosingInsideMenu(0, true, mode);
				break;
			case 1:
				PrintColorChoosingInsideMenu(0, true, mode);
				setcolor(0x5050AA);
				PrintColorChoosingInsideMenu(1, false, mode);
				break;
			case 2:
				PrintColorChoosingInsideMenu(0, true, mode);
				setcolor(0x5050AA);
				PrintColorChoosingInsideMenu(2, false, mode);
				break;
			case 3:
				PrintColorChoosingInsideMenu(0, true, mode);
				setcolor(0x5050AA);
				PrintColorChoosingInsideMenu(3, false, mode);
				break;
			case 4:
				PrintColorChoosingInsideMenu(0, true, mode);
				setcolor(0x5050AA);
				PrintColorChoosingInsideMenu(4, false, mode);
				break;
			case 5:
				PrintColorChoosingInsideMenu(0, true, mode);
				setcolor(0x5050AA);
				PrintColorChoosingInsideMenu(5, false, mode);
				break;
			case 6:
				PrintColorChoosingInsideMenu(0, true, mode);
				setcolor(0x5050AA);
				PrintColorChoosingInsideMenu(6, false, mode);
				break;
			case 7:
				PrintColorChoosingInsideMenu(0, true, mode);
				setcolor(0x5050AA);
				PrintColorChoosingInsideMenu(7, false, mode);
				break;
			case 8:
				PrintColorChoosingInsideMenu(0, true, mode);
				setcolor(0x5050AA);
				PrintColorChoosingInsideMenu(8, false, mode);
				break;
			case 9:
				PrintColorChoosingInsideMenu(0, true, mode);
				setcolor(0x5050AA);
				PrintColorChoosingInsideMenu(9, false, mode);
				break;
			case 10:
				PrintColorChoosingInsideMenu(0, true, mode);
				setcolor(0x5050AA);
				PrintColorChoosingInsideMenu(10, false, mode);
				break;
			case 11:
				PrintColorChoosingInsideMenu(0, true, mode);
				setcolor(0x5050AA);
				PrintColorChoosingInsideMenu(11, false, mode);
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


void PrintColorChoosingInsideMenu(WORD lnToPrint, bool withColor, WORD mode)
{
	switch (lnToPrint)
	{
	case 0:
		if (withColor) setcolor(0x000000);
		xyprintf(8, 8 + 0 * MENU_HIGHT, "����");
		if (withColor) setcolor(colorInf[0]);
		xyprintf(8, 8 + 1 * MENU_HIGHT, "��ɫ");
		if (withColor) setcolor(colorInf[1]);
		xyprintf(8, 8 + 2 * MENU_HIGHT, "��ɫ");
		if (withColor) setcolor(colorInf[2]);
		xyprintf(8, 8 + 3 * MENU_HIGHT, "��ɫ");
		if (withColor) setcolor(colorInf[3]);
		xyprintf(8, 8 + 4 * MENU_HIGHT, "��ɫ");
		if (withColor) setcolor(colorInf[4]);
		xyprintf(8, 8 + 5 * MENU_HIGHT, "��ɫ");
		if (withColor) setcolor(colorInf[5]);
		xyprintf(8, 8 + 6 * MENU_HIGHT, "��ɫ");
		if (withColor) setcolor(colorInf[6]);
		xyprintf(8, 8 + 7 * MENU_HIGHT, "��ɫ");
		if (withColor) setcolor(0x000000);
		xyprintf(8, 8 + 8 * MENU_HIGHT, "�Զ���");
		if (withColor) setcolor(0x000000);
		xyprintf(8, 8 + 9 * MENU_HIGHT, "���");
		if (mode == 1)
		{
			if (withColor) setcolor(0x000000);
			xyprintf(8, 8 + 10 * MENU_HIGHT, "��");
		}
		
		break;
	case 1:
		if (withColor) setcolor(0x000000);
		xyprintf(8, 8 + 0 * MENU_HIGHT, "����");
		break;
	case 2:
		if (withColor) setcolor(colorInf[0]);
		xyprintf(8, 8 + 1 * MENU_HIGHT, "��ɫ");
		break;
	case 3:
		if (withColor) setcolor(colorInf[1]);
		xyprintf(8, 8 + 2 * MENU_HIGHT, "��ɫ");
		break;
	case 4:
		if (withColor) setcolor(colorInf[2]);
		xyprintf(8, 8 + 3 * MENU_HIGHT, "��ɫ");
		break;
	case 5:
		if (withColor) setcolor(colorInf[3]);
		xyprintf(8, 8 + 4 * MENU_HIGHT, "��ɫ");
		break;
	case 6:
		if (withColor) setcolor(colorInf[4]);
		xyprintf(8, 8 + 5 * MENU_HIGHT, "��ɫ");
		break;
	case 7:
		if (withColor) setcolor(colorInf[5]);
		xyprintf(8, 8 + 6 * MENU_HIGHT, "��ɫ");
		break;
	case 8:
		if (withColor) setcolor(colorInf[6]);
		xyprintf(8, 8 + 7 * MENU_HIGHT, "��ɫ");
		break;
	case 9:
		if (withColor) setcolor(0x000000);
		xyprintf(8, 8 + 8 * MENU_HIGHT, "�Զ���");
		break;
	case 10:
		if (withColor) setcolor(0x000000);
		xyprintf(8, 8 + 9 * MENU_HIGHT, "���");
		break;
	case 11:
		if (withColor) setcolor(0x000000);
		xyprintf(8, 8 + 10 * MENU_HIGHT, "��");
		break;
	default:
		break;
	}
}