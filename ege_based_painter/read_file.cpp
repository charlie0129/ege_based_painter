#include "read_file.h"

bool ReadFile(void)
{
	
	FILE*           fp;
	const short int TOTAL_LN = 2;
	short int       readResult; // indicates whether the reading action is successful
	bool            isReadyToExit = false;
	OPENFILENAME    ofn = { 0 };
	TCHAR           strFilename[MAX_PATH] = { 0 };
	char            c_strFilename[MAX_PATH] = { 0 };
	begin:
	cleardevice();
	InitUI(0);
	printf("请在菜单界面用鼠标点击操作\n");

	mouse_msg msg;

	DrawMenuOutline(1, TOTAL_LN, 1);
	setcolor(0x000000);
	setfont(EGE_FONT_SIZE, 0, EGE_FONT);
	
	xyprintf(8, 8 + 0 * MENU_HIGHT, "读取绘图存档");
	xyprintf(8, 8 + 1 * MENU_HIGHT, "不读取绘图存档");
	xyprintf(MENU_LENGTH + 15, 8 + 2 * MENU_HIGHT, "用鼠标点击菜单");



	for (; !isReadyToExit; delay_fps(REFRESH_RATE))
	{
		msg = getmouse();

		switch (msg.msg)
		{
		case mouse_msg_down:
			switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
			{
			case 1:
			case1:				
				ofn.lStructSize = sizeof(OPENFILENAME);
				ofn.hwndOwner = NULL;
				ofn.lpstrFilter = TEXT("Shape Data (*.draw)\0*.draw\0All (*.*)\0*.*\0\0");
				ofn.nFilterIndex = 1;
				ofn.lpstrFile = strFilename;
				ofn.nMaxFile = sizeof(strFilename);
				ofn.lpstrInitialDir = NULL;
				ofn.lpstrTitle = TEXT("请选择一个文件");
				ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;
				if (!(GetOpenFileName(&ofn)))
				{				
					goto begin;
				}

				TCHARToChar(strFilename, c_strFilename);
				
				fp = fopen(c_strFilename, "rb");
				rewind(fp);

				if (fp == NULL)
				{
					READINGFAILED:
					cleardevice();
					InitUI(0);
					int selection = MessageBox(NULL, 
						TEXT("请检查文件是否存在或正确\n确保路径没有中文"), 
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
				else 
				{
					cleardevice();
					InitUI(0);
					if ((fread(shapeData, 
							sizeof(shapeData[0]), 
							sizeof(shapeData) / sizeof(shapeData[0]), 
							fp) == 
							sizeof(shapeData) / sizeof(shapeData[0]))  
						&& (fread(&g_nTotalShapes, 
							sizeof(WORD), 
							1, 
							fp) == 1) 
						&& (fread(&fileValidityCheckSuffix, 
							sizeof(fileValidityCheckSuffix), 
							1, 
							fp) == 1) 
						&& (fileValidityCheckSuffix == 'C'))
					{
						MessageBox(NULL,
							TEXT("读取成功"),
							TEXT("提示"),
							MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION);
						fclose(fp);
						readResult = 1;
						isReadyToExit = true;
					}
					else
					{
						goto READINGFAILED;
					}
				}
				break;
			case 2: // do not read file
				readResult = 0;
				isReadyToExit = true;
				break;
			default:
				break;
			}
			break; // not needed
		case mouse_msg_move:
			setcolor(0x50AA50);
			xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
			DrawMenuOutline(1, TOTAL_LN, 1);
			switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
			{
			case 0:
				DrawMenuOutline(1, TOTAL_LN, 1);
				setcolor(0x000000);
				xyprintf(8, 8 + 0 * MENU_HIGHT, "读取绘图存档");
				xyprintf(8, 8 + 1 * MENU_HIGHT, "不读取绘图存档");
				break;
			case 1:
				setcolor(0x000000);
				xyprintf(8, 8 + 0 * MENU_HIGHT, "读取绘图存档");
				xyprintf(8, 8 + 1 * MENU_HIGHT, "不读取绘图存档");
				setcolor(0x5050AA);
				xyprintf(8, 8 + 0 * MENU_HIGHT, "读取绘图存档");
				break;
			case 2:
				setcolor(0x000000);
				xyprintf(8, 8 + 0 * MENU_HIGHT, "读取绘图存档");
				xyprintf(8, 8 + 1 * MENU_HIGHT, "不读取绘图存档");
				setcolor(0x5050AA);
				xyprintf(8, 8 + 1 * MENU_HIGHT, "不读取绘图存档");
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
	InitUI(0);
	fileEdited = false;
	return readResult;
}


void TCHARToChar(const TCHAR* tchar, char* _char)
{
	int iLength;
	iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);
	WideCharToMultiByte(CP_ACP, 0, tchar, -1, _char, iLength, NULL, NULL);
}