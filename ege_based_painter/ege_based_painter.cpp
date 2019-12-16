/* refer to README.md for descriptions*/

#include "global.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "graphics.h"
#include "menu.h"
#include "read_file.h"

bool		     g_isUserSetColor = false; // global variable. used to determine whether the user has set a custom color
bool		     g_isUserSetFillColor = false;
bool		     g_isFillColorRandom = false;
int			     g_customColor = 0x0;
int			     g_customFillColor = 0x0;
struct ShapeData shapeData[512];
WORD		     g_nTotalShapes = 0;
bool	         g_isFileEdited = false;
char		     fileValidityCheckSuffix = '\0';


int main(void)
{
	initgraph(CANVAS_WIDTH, CANVAS_HIGHT);
	//setrendermode(RENDER_AUTO);
	setbkcolor(WHITE);
	setfont(EGE_FONT_SIZE, 0, EGE_FONT);
	Menu(ReadFromFile());
	return 0;
}
