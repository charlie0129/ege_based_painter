#include "color_selector.h"

int colorInf[7] = { 0x5454FC,   //LIGHTBLUE
					0x54FC54,   //LIGHTGREEN
					0x54FCFC,   //LIGHTCYAN
					0xFC5454,   //LIGHTRED
					0xFC54FC,   //LIGHTMAGENTA
					0xFCFC54,   //YELLOW
					0xFCFCFC }; //WHITE



void ChooseColor(void)
{
	const int TOTAL_LN = 10; // total items in the menu bar
	bool hasSetColor = false;

	// used for color customization
	const short int N_OF_NUMS_TO_READ = 3;
	const int LEN_OF_STR_TO_READ = 11;
	const int INPUT_MIN = 0;
	const int INPUT_MAX = 255;

	// initialization of varibles needed to read inputs
	char str[LEN_OF_STR_TO_READ];
	char *readTmp;
	bool isInputValid = true;
	int numRead[N_OF_NUMS_TO_READ];
	int i; // loop controller. I didn't use "for" loop because in this situation it's not a good idea.


	printf("�ѽ�����ɫѡ��ģʽ\n");
	printf("����ָ�ϣ�\n");
	printf("������ȵ�ѡ��ɫ\n");

	DrawMenuOutline(TOTAL_LN);
	

	PrintColorChoosingInsideMenu(0, true);

	
	mouse_msg msg;
	
	msg = getmouse();
		
	for (; !hasSetColor; delay_fps(800))
	{

		msg = getmouse();
		switch (msg.msg)
		{
		case mouse_msg_down:
			switch (GetMouseCurrentLn(TOTAL_LN))
			{
			case 1:
				return;
		
			case 2:
				hasSetColor = true;
				g_isUserSetColor = true;
				g_customColor = colorInf[0];
				printf("		�ѽ�ǰ��ɫ����Ϊ����ɫ\n");
				break;
			case 3:
				hasSetColor = true;
				g_isUserSetColor = true;
				g_customColor = colorInf[1];
				printf("		�ѽ�ǰ��ɫ����Ϊ����ɫ\n");

				break;
			case 4:
				hasSetColor = true;
				g_isUserSetColor = true;
				g_customColor = colorInf[2];
				printf("		�ѽ�ǰ��ɫ����Ϊ����ɫ\n");


				break;
			case 5:
				hasSetColor = true;
				g_isUserSetColor = true;
				g_customColor = colorInf[3];
				printf("		�ѽ�ǰ��ɫ����Ϊ����ɫ\n");
				break;
			case 6:
				hasSetColor = true;
				g_isUserSetColor = true;
				g_customColor = colorInf[4];
				printf("		�ѽ�ǰ��ɫ����Ϊ����ɫ\n");
				break;
			case 7:
				hasSetColor = true;
				g_isUserSetColor = true;
				g_customColor = colorInf[5];
				printf("		�ѽ�ǰ��ɫ����Ϊ��ɫ\n");
				break;
			case 8:
				hasSetColor = true;
				g_isUserSetColor = true;
				g_customColor = colorInf[6];
				printf("		�ѽ�ǰ��ɫ����Ϊ��ɫ\n");
				break;
			case 9:
				hasSetColor = true;
				g_isUserSetColor = true;

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
				}
				while (!isInputValid);

				g_customColor = EGERGB(numRead[0], numRead[1], numRead[2]);
				printf("		�ѽ�ǰ��ɫ����Ϊ #%02X%02X%02X ɫ\n", numRead[0], numRead[1], numRead[2]);
				break;
			case 10:
				hasSetColor = true;
				g_isUserSetColor = false;
				printf("		�ѽ�ǰ��ɫ����Ϊ���ɫ\n");
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
				PrintColorChoosingInsideMenu(0, true);
				break;
			case 1:
				PrintColorChoosingInsideMenu(0, true);
				setcolor(0x9090FF);
				PrintColorChoosingInsideMenu(1, false);
				break;
			case 2:
				PrintColorChoosingInsideMenu(0, true);
				setcolor(0x9090FF);
				PrintColorChoosingInsideMenu(2, false);
				break;
			case 3:
				PrintColorChoosingInsideMenu(0, true);
				setcolor(0x9090FF);
				PrintColorChoosingInsideMenu(3, false);
				break;
			case 4:
				PrintColorChoosingInsideMenu(0, true);
				setcolor(0x9090FF);
				PrintColorChoosingInsideMenu(4, false);
				break;
			case 5:
				PrintColorChoosingInsideMenu(0, true);
				setcolor(0x9090FF);
				PrintColorChoosingInsideMenu(5, false);
				break;
			case 6:
				PrintColorChoosingInsideMenu(0, true);
				setcolor(0x9090FF);
				PrintColorChoosingInsideMenu(6, false);
				break;
			case 7:
				PrintColorChoosingInsideMenu(0, true);
				setcolor(0x9090FF);
				PrintColorChoosingInsideMenu(7, false);
				break;
			case 8:
				PrintColorChoosingInsideMenu(0, true);
				setcolor(0x9090FF);
				PrintColorChoosingInsideMenu(8, false);
				break;
			case 9:
				PrintColorChoosingInsideMenu(0, true);
				setcolor(0x9090FF);
				PrintColorChoosingInsideMenu(9, false);
				break;
			case 10:
				PrintColorChoosingInsideMenu(0, true);
				setcolor(0x9090FF);
				PrintColorChoosingInsideMenu(10, false);
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


void PrintColorChoosingInsideMenu(short int lnToPrint, bool withColor)
{
	switch (lnToPrint)
	{
	case 0:
		if (withColor) setcolor(0xFFFFFF);
		xyprintf(8, 8 + 0 * MENU_HIGHT, "1. ����");
		if (withColor) setcolor(colorInf[0]);
		xyprintf(8, 8 + 1 * MENU_HIGHT, "2. ����ɫ");
		if (withColor) setcolor(colorInf[1]);
		xyprintf(8, 8 + 2 * MENU_HIGHT, "3. ����ɫ");
		if (withColor) setcolor(colorInf[2]);
		xyprintf(8, 8 + 3 * MENU_HIGHT, "4. ����ɫ");
		if (withColor) setcolor(colorInf[3]);
		xyprintf(8, 8 + 4 * MENU_HIGHT, "5. ����ɫ");
		if (withColor) setcolor(colorInf[4]);
		xyprintf(8, 8 + 5 * MENU_HIGHT, "6. ����ɫ");
		if (withColor) setcolor(colorInf[5]);
		xyprintf(8, 8 + 6 * MENU_HIGHT, "7. ��ɫ");
		if (withColor) setcolor(colorInf[6]);
		xyprintf(8, 8 + 7 * MENU_HIGHT, "8. ��ɫ");
		if (withColor) setcolor(0xFFFFFF);
		xyprintf(8, 8 + 8 * MENU_HIGHT, "9. �Զ���");
		if (withColor) setcolor(0xFFFFFF);
		xyprintf(8, 8 + 9 * MENU_HIGHT, "10. ���");
		break;
	case 1:
		if (withColor) setcolor(0xFFFFFF);
		xyprintf(8, 8 + 0 * MENU_HIGHT, "1. ����");
		break;
	case 2:
		if (withColor) setcolor(colorInf[0]);
		xyprintf(8, 8 + 1 * MENU_HIGHT, "2. ����ɫ");
		break;
	case 3:
		if (withColor) setcolor(colorInf[1]);
		xyprintf(8, 8 + 2 * MENU_HIGHT, "3. ����ɫ");
		break;
	case 4:
		if (withColor) setcolor(colorInf[2]);
		xyprintf(8, 8 + 3 * MENU_HIGHT, "4. ����ɫ");
		break;
	case 5:
		if (withColor) setcolor(colorInf[3]);
		xyprintf(8, 8 + 4 * MENU_HIGHT, "5. ����ɫ");
		break;
	case 6:
		if (withColor) setcolor(colorInf[4]);
		xyprintf(8, 8 + 5 * MENU_HIGHT, "6. ����ɫ");
		break;
	case 7:
		if (withColor) setcolor(colorInf[5]);
		xyprintf(8, 8 + 6 * MENU_HIGHT, "7. ��ɫ");
		break;
	case 8:
		if (withColor) setcolor(colorInf[6]);
		xyprintf(8, 8 + 7 * MENU_HIGHT, "8. ��ɫ");
		break;
	case 9:
		if (withColor) setcolor(0xFFFFFF);
		xyprintf(8, 8 + 8 * MENU_HIGHT, "9. �Զ���");
		break;
	case 10:
		if (withColor) setcolor(0xFFFFFF);
		xyprintf(8, 8 + 9 * MENU_HIGHT, "10. ���");
		break;
	default:
		break;
	}
}