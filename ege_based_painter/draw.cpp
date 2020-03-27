#include "draw.h"

void DrawAllPrevShapes(bool withColor)
{
    int coordData[255] = { 0 }; // coordinate data used for polygon drawing

    // stops if there is no shapes
    if (g_nTotalShapes > 0)
    {
        // draw shapes one by one
        for (int i = 0; i < g_nTotalShapes; i++)
        {
            // set foreground color and fill color
            if (withColor)
            {
                setcolor(shapeData[i].foregroundColor);

                if (shapeData[i].isFill)
                {
                    setfillcolor(shapeData[i].fillColor);
                }
                else
                {
                    setfillcolor(0xFFFFFF);
                } // end of if
            }
            else
            {
                setcolor(0xCCCCCC);
                setfillcolor(0xDDDDDD);
            } // end of if

            switch (shapeData[i].shapeType)
            {
                case shape_line:
                    /*line(shapeData[i].coords[0].x,
                        shapeData[i].coords[0].y,
                        shapeData[i].coords[1].x,
                        shapeData[i].coords[1].y);*/
                    line(((shapeData + i)->coords)->x,
                         ((shapeData + i)->coords)->y,
                         ((shapeData + i)->coords + 1)->x,
                         ((shapeData + i)->coords + 1)->y);
                    break;

                case shape_circle:

                    /*circle(shapeData[i].coords[0].x,
                           shapeData[i].coords[0].y,
                           (int)sqrt(pow(shapeData[i].coords[0].x - shapeData[i].coords[1].x, 2) +
                                     pow(shapeData[i].coords[0].y - shapeData[i].coords[1].y, 2)));*/
                    if (shapeData[i].isFill)
                    {
                        pieslice(((shapeData + i)->coords)->x,
                                 ((shapeData + i)->coords)->y,
                                 0,
                                 360,
                                 (int)sqrt(pow(((shapeData + i)->coords)->x - ((shapeData + i)->coords + 1)->x,
                                               2) +
                                           pow(((shapeData + i)->coords)->y - ((shapeData + i)->coords + 1)->y, 2)));
                    }
                    else
                    {
                        circle(((shapeData + i)->coords)->x,
                               ((shapeData + i)->coords)->y,
                               (int)sqrt(pow(((shapeData + i)->coords)->x - ((shapeData + i)->coords + 1)->x,
                                             2) +
                                         pow(((shapeData + i)->coords)->y - ((shapeData + i)->coords + 1)->y, 2)));
                    }

                    break;

                case shape_rectangle:
                    if (shapeData[i].isFill)
                    {
                        bar(((shapeData + i)->coords)->x,
                            ((shapeData + i)->coords)->y,
                            ((shapeData + i)->coords + 1)->x,
                            ((shapeData + i)->coords + 1)->y);
                    }
                    else
                    {
                        rectangle(((shapeData + i)->coords)->x,
                                  ((shapeData + i)->coords)->y,
                                  ((shapeData + i)->coords + 1)->x,
                                  ((shapeData + i)->coords + 1)->y);
                    }

                    /*rectangle(((shapeData + i)->coords)->x,
                        ((shapeData + i)->coords)->y,
                        ((shapeData + i)->coords + 1)->x,
                        ((shapeData + i)->coords + 1)->y);*/
                    break;

                case shape_polygon:

                    //for (int j = 0; j < shapeData[i].extraData[0]; j++)
                    //{
                    //  coordData[2 * j] = shapeData[i].coords[j].x;
                    //  coordData[2 * j + 1] = shapeData[i].coords[j].y;
                    //}
                    ////coordData[shapeData[i].extraData[0] * 2] = shapeData[i].coords[0].x;
                    ////coordData[shapeData[i].extraData[0] * 2 + 1] = shapeData[i].coords[0].y;
                    ////setfillcolor(0xAAAAAA);
                    //fillpoly(shapeData[i].extraData[0], coordData);

                    // prepare the data in shapeData for drawing
                    for (int j = 0; j < * ((shapeData + i)->extraData); j++)
                    {
                        *(coordData + 2 * j) = ((shapeData + i)->coords + j)->x;
                        *(coordData + 2 * j + 1) = ((shapeData + i)->coords + j)->y;
                    }

                    *(coordData + 2 * (*((shapeData + i)->extraData))) = ((shapeData +
                            i)->coords)->x;
                    *(coordData + 2 * (*((shapeData + i)->extraData)) + 1) = ((
                                shapeData + i)->coords)->y;

                    if (shapeData[i].isFill)
                    {
                        fillpoly(*((shapeData + i)->extraData), coordData);
                    }
                    else
                    {
                        drawpoly(*((shapeData + i)->extraData) + 1, coordData);
                    }

                    break;

                default:
                    break;
            } // end of switch
        } // end of for
    } // end of if
}

int RandColor(void)
{
    int R = 0, G = 0, B = 0;
    int hexColorValue; // the final hexadecimal output

    do
    {
        randomize();
        R = random(255);// randInt(0, 255);
        randomize();
        G = random(255);// randInt(0, 255);
        randomize();
        B = random(255);// randInt(0, 255);
    } while ((R >= 180) || (G >= 180)

             || (B >= 180)); // condition added to avoid the colors that are too dark. readibility improved.

    hexColorValue = (R << 16) + (G << 8) +
                    B; // convert separate RGB channels into a single value that represents colors
    // printf("%x", hexValue); // display the output value of the function for debug purposes
    return hexColorValue;
}

void PrintMouseDrawingInsideMenu(WORD lnToPrint)
{
    switch (lnToPrint)
    {
        case 0:
            xyprintf(8, 8 + 0 * MENU_HIGHT, "返回");
            xyprintf(8, 8 + 1 * MENU_HIGHT, "撤销");
            xyprintf(8, 8 + 2 * MENU_HIGHT, "选择当前前景色");
            xyprintf(8, 8 + 3 * MENU_HIGHT, "设置填充并选择填充色");
            break;

        case 1:
            xyprintf(8, 8 + 0 * MENU_HIGHT, "返回");
            break;

        case 2:
            xyprintf(8, 8 + 1 * MENU_HIGHT, "撤销");
            break;

        case 3:
            xyprintf(8, 8 + 2 * MENU_HIGHT, "选择当前前景色");
            break;

        case 4:
            xyprintf(8, 8 + 3 * MENU_HIGHT, "设置填充并选择填充色");
            break;

        default:
            break;
    }
}

void PrintCoordDrawingInsideMenu(WORD lnToPrint)
{
    switch (lnToPrint)
    {
        case 0:
            xyprintf(8, 8 + 0 * MENU_HIGHT, "返回");
            xyprintf(8, 8 + 1 * MENU_HIGHT, "撤销");
            xyprintf(8, 8 + 2 * MENU_HIGHT, "画一个多边形");
            xyprintf(8, 8 + 3 * MENU_HIGHT, "选择当前前景色");
            xyprintf(8, 8 + 4 * MENU_HIGHT, "设置填充并选择填充色");
            break;

        case 1:
            xyprintf(8, 8 + 0 * MENU_HIGHT, "返回");
            break;

        case 2:
            xyprintf(8, 8 + 1 * MENU_HIGHT, "撤销");
            break;

        case 3:
            xyprintf(8, 8 + 2 * MENU_HIGHT, "画一个多边形");
            break;

        case 4:
            xyprintf(8, 8 + 3 * MENU_HIGHT, "选择当前前景色");
            break;

        case 5:
            xyprintf(8, 8 + 4 * MENU_HIGHT, "设置填充并选择填充色");
            break;

        default:
            break;
    }
}