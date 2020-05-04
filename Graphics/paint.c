

#include <stdlib.h>
#include "paint.h"

Paint *PaintInit()
{
	Paint *paint = (Paint*)malloc(sizeof(Paint));

	paint->foreground_color = PrintForeGroundColorWhite;
	paint->background_color = PrintBackGroundColorBlack;

	return paint;
}

void PaintDrawText(Paint *paint, const char* text, short x, short y)
{
	PrintMoveTo(x, y);
	PrintHaveColor(text, paint->foreground_color, paint->background_color);
}
