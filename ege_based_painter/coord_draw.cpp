#include "coord_draw.h"

void coord_DrawPolyPrompt(void)
{	
	const int INPUT_MIN = 0;
	const int INPUT_MAX = 800;

	// variables needed for the first prompt
	char      str1[255]; // a string to store the input
	WORD      sides;

	// variables needed for the second prompt
	char      str[511]; // a string to store the input
	char      *readTmp;
	int       numRead[255]; // an array to store the separated inputs
	int       i; // loop controller. I didn't use "for" loop because in this situation it's not a good idea.
	WORD      errCode = 0;


	// the first prompt starts here
	// asks the user to input a sides of a polygon
	do // exits after a valid input
	{	
		memset(str1, '\0', sizeof(str1));

		if (errCode == 0)
		{
			inputbox_getline("请按照提示输入", 
				"请输入多边形边数", 
				str1, 
				sizeof(str1) / sizeof(*str1));
			errCode = 0;
		}
		else
		{
			inputbox_getline("输入无效！请重新输入", 
				"请输入多边形边数", 
				str1,
				sizeof(str1) / sizeof(*str1));
			errCode = 0;
		}

		// make sure the input is all numbers
		if (strspn(str1, "0123456789") != strlen(str1))
		{
			MessageBox(NULL, TEXT("边数只能包含数字"), NULL, MB_OK | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);
			errCode++;
			continue;
		}

		// convert the separated inputs to integers
		sides = atoi(str1);

		// avoid out-of-range input numbers
		if (sides < 3)
		{
			MessageBox(NULL, TEXT("不能构成多边形"), NULL, MB_OK | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);
			errCode++;
			continue;
		}

		if (sides >= 24)
		{
			MessageBox(NULL, TEXT("边数过多"), NULL, MB_OK | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);
			errCode++;
			continue;
		}
			
			
	}
	while (!(errCode == 0));

	// the second prompt starts here
	// asks the user to input the coordinates
	do // exits after a valid input
	{
		i = 0; // it is better not to use "for" statment
		memset(str, '\0', sizeof(str));

		if (errCode == 0)
		{
			inputbox_getline("请按照提示输入",
				"请依次输入多边形的各个点(x,y)坐标，用\",\"分开。如: 1,2,3,4,5,6",
				str, 
				sizeof(str) / sizeof(*str));
			errCode = 0;
		}
		else
		{
			inputbox_getline("输入无效！请重新输入",
				"请依次输入多边形的各个点(x,y)坐标，用\",\"分开。如: 1,2,3,4,5,6", 
				str,
				sizeof(str) / sizeof(*str));
		}

		readTmp = strtok(str, ","); // separate the input string

		while (readTmp != NULL)
		{
			// make sure the input is all numbers
			if (strspn(readTmp, "0123456789") != strlen(readTmp))
			{
				MessageBox(NULL, TEXT("坐标只能包含数字"), NULL, MB_OK | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);
				errCode++;
				break;
				errCode = 0;
			}

			// avoid too many input numbers 
			if (i >= (sides * 2))
			{
				MessageBox(NULL, TEXT("坐标个数过多"), NULL, MB_OK | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);
				errCode++;
				break;
			}

			// convert the separated inputs to integers and store them in a array
			numRead[i] = atoi(readTmp);

			// avoid out-of-range input numbers
			if ((numRead[i] > INPUT_MAX) || (numRead[i] < INPUT_MIN))
			{
				MessageBox(NULL, TEXT("坐标范围无效"), NULL, MB_OK | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);
				errCode++;
				break;
			}

			i++;
			readTmp = strtok(NULL, ",");
		}

		// avoid too few input numbers
		if (i < (sides * 2))
		{
			MessageBox(NULL, TEXT("坐标个数过少"), NULL, MB_OK | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);
			errCode++;
		}
	}
	while (!(errCode == 0));

	fillpoly(sides, numRead );
	g_nTotalShapes++;
	shapeData[g_nTotalShapes - 1].shapeType = shape_polygon;
	shapeData[g_nTotalShapes - 1].extraData[0] = sides; // record the sides

	// prepare the coordinate data for storage
	for (int j = 0; j < shapeData[g_nTotalShapes - 1].extraData[0]; j++)
	{
		shapeData[g_nTotalShapes - 1].coords[j].x = numRead[2 * j];
		shapeData[g_nTotalShapes - 1].coords[j].y = numRead[2 * j + 1];
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
}

void coord_DrawPoly(void)
{
	const short int TOTAL_LN = 5; // total items in the menu bar
	bool            isInProgress = false;

	printf("已进入坐标画多边形模式\n");
	DrawAllPrevShapes(true);
	DrawMenuOutline(1, TOTAL_LN, 1);
	setcolor(0x000000);
	PrintCoordDrawingInsideMenu(0);	
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
			case 2: // undo
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
			case 3: // draw a polygon
				coord_DrawPolyPrompt();
				cleardevice();
				InitUI(0);
				DrawAllPrevShapes(true);
				break;
			case 4: // choose foreground color
				ChooseColor_EGE(0);
				cleardevice();
				InitUI(0);
				DrawAllPrevShapes(true);
				goto move;
				break;
			case 5: // choose fill color
				ChooseColor_EGE(1);
				cleardevice();
				InitUI(0);
				DrawAllPrevShapes(true);
				goto move;
				break;
			default:
				break;
			}
			break; // not needed
		case mouse_msg_move:
			move:
			
			InitUI(0);
			DrawAllPrevShapes(true);
			//DrawMenuOutline(1, TOTAL_LN, 1);
			//setcolor(0x000000);
			//PrintCoordDrawingInsideMenu(0);
			setcolor(0x50AA50);
			xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
			switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
			{
			case 0:
				DrawMenuOutline(1, TOTAL_LN, 1);
				setcolor(0x000000);
				PrintCoordDrawingInsideMenu(0);
				break;
			case 1:
				setcolor(0x000000);
				PrintCoordDrawingInsideMenu(0);
				setcolor(0x5050AA);
				PrintCoordDrawingInsideMenu(1);
				break;
			case 2:
				setcolor(0x000000);
				PrintCoordDrawingInsideMenu(0);
				setcolor(0x5050AA);
				PrintCoordDrawingInsideMenu(2);
				break;
			case 3:
				setcolor(0x000000);
				PrintCoordDrawingInsideMenu(0);
				setcolor(0x5050AA);
				PrintCoordDrawingInsideMenu(3);
				break;
			case 4:
				setcolor(0x000000);
				PrintCoordDrawingInsideMenu(0);
				setcolor(0x5050AA);
				PrintCoordDrawingInsideMenu(4);
				break;
			case 5:
				setcolor(0x000000);
				PrintCoordDrawingInsideMenu(0);
				setcolor(0x5050AA);
				PrintCoordDrawingInsideMenu(5);
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