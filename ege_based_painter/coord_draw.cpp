#include "coord_draw.h"

void coord_DrawPolyPrompt(void)
{	
	const int INPUT_MIN = 0;
	const int INPUT_MAX = 800;

	// variables needed for the first prompt
	bool isInputValid;
	char str1[255]; // a string to store the input
	WORD sides;

	// variables needed for the second prompt
	char str[511]; // a string to store the input
	char *readTmp;
	int numRead[255]; // an array to store the separated inputs
	int i; // loop controller. I didn't use "for" loop because in this situation it's not a good idea.
	
	isInputValid = true;

	// the first prompt starts here
	// asks the user to input a sides of a polygon
	do // exits after a valid input
	{	
		memset(str1, 0, sizeof(str1));

		if (isInputValid)
		{
			inputbox_getline("请按照提示输入", "请输入多边形边数", str1, sizeof(str1) / sizeof(*str1));
		}
		else if (!isInputValid)
		{
			inputbox_getline("输入无效！请重新输入", "请输入多边形边数", str1, sizeof(str1) / sizeof(*str1));
		}


		// make sure the input is all numbers
		if (strspn(str1, "0123456789") != strlen(str1))
		{
			isInputValid = false;
			continue;
		}

		// convert the separated inputs to integers
		sides = atoi(str1);

		// avoid out-of-range input numbers
		if (sides < 3)
		{
			isInputValid = false;
			continue;
		}


		isInputValid = true;
			
			
	}
	while (!isInputValid);


	// the second prompt starts here
	isInputValid = true;

	// asks the user to input the coordinates
	do // exits after a valid input
	{
		i = 0; // it is better not to use "for" statment
		memset(str, 0, sizeof(str));

		if (isInputValid)
		{
			inputbox_getline("请按照提示输入", "请依次输入多边形的各个点(x,y)坐标，用\",\"分开。如: 1,2,3,4,5,6", str, sizeof(str) / sizeof(*str));
		}
		else if (!isInputValid)
		{
			inputbox_getline("输入无效！请重新输入", "请依次输入多边形的各个点(x,y)坐标，用\",\"分开。如: 1,2,3,4,5,6", str, sizeof(str) / sizeof(*str));
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
			if (i >= (sides * 2))
			{
				isInputValid = false;
				break;
			}

			// convert the separated inputs to integers and store them in a array
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
		if (i < (sides * 2))
		{
			isInputValid = false;
		}
	}
	while (!isInputValid);
	fillpoly(sides, numRead );
	g_nTotalShapes++;
	shapeData[g_nTotalShapes - 1].shapeType = shape_polygon;
	shapeData[g_nTotalShapes - 1].extraData[0] = sides; // record the sides
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
}

void coord_DrawPoly(void)
{
	const short int TOTAL_LN = 3; // total items in the menu bar

	bool isInProgress = false;


	printf("已进入坐标画多边形模式\n");

	//setcolor(0x555555);
	coord_DrawPolyPrompt();
	DrawAllPrevShapes(true);
	DrawMenuOutline(1, TOTAL_LN, 1);
	setcolor(0xFFFFFF);
	PrintCoordDrawingInsideMenu(0);
	
	mouse_msg msg;



	for (; is_run(); delay_fps(REFRESH_RATE)) // Using "for" statement to draw multiple circles at a time and refresh the screen
	{

		msg = getmouse();

		switch (msg.msg)
		{
		case mouse_msg_down:
			if (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln == 3)
			{
				coord_DrawPolyPrompt();
				DrawAllPrevShapes(true);
			}

			if (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln == 2) // undo
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
				DrawMenuOutline(1, TOTAL_LN, 1);
				setcolor(0xFFFFFF);
				PrintCoordDrawingInsideMenu(0);
				setcolor(0x90FF90);
				xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
				DrawAllPrevShapes(true);
				break;
			}

			if (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln == 1)
			{
				return;
			}




			break; // not needed
		case mouse_msg_move:

			
			InitUI(0);
			//DrawMenuOutline(1, TOTAL_LN, 1);
			//setcolor(0xFFFFFF);
			//PrintCoordDrawingInsideMenu(0);
			setcolor(0x90FF90);
			xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
			switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
			{
			case 0:
				DrawMenuOutline(1, TOTAL_LN, 1);
				setcolor(0xFFFFFF);
				PrintCoordDrawingInsideMenu(0);
				break;
			case 1:
				setcolor(0xFFFFFF);
				PrintCoordDrawingInsideMenu(0);
				setcolor(0x9090FF);
				PrintCoordDrawingInsideMenu(1);
				break;
			case 2:
				setcolor(0xFFFFFF);
				PrintCoordDrawingInsideMenu(0);
				setcolor(0x9090FF);
				PrintCoordDrawingInsideMenu(2);
				break;
			case 3:
				setcolor(0xFFFFFF);
				PrintCoordDrawingInsideMenu(0);
				setcolor(0x9090FF);
				PrintCoordDrawingInsideMenu(3);
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