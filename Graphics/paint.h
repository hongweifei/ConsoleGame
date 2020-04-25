


#include "print.h"




#ifndef PAINT_HEAD
#define PAINT_HEAD


typedef struct
{
	PrintForeGroundColor foreground_color;
	PrintBackGroundColor background_color;
}Paint;

#ifdef _cplusplus
extern "C" {
#endif // _cplusplus


Paint* PaintInit()
{
	Paint* paint = (Paint*)malloc(sizeof(Paint));

	paint->foreground_color = PrintForeGroundColorWhite;
	paint->background_color = PrintBackGroundColorBlack;

	return paint;
}


void DrawText(Paint* paint, const char* text, short x, short y)
{
	PrintMoveTo(x, y);
	PrintHaveColor(text, paint->foreground_color, paint->background_color);
}


#ifdef _cplusplus
}
#endif // _cplusplus



#endif // !PAINT_HEAD
