


#include "print.h"




#ifndef PAINT_HEAD
#define PAINT_HEAD


typedef struct _paint
{
	PrintForeGroundColor foreground_color;
	PrintBackGroundColor background_color;
}Paint;

#ifdef _cplusplus
extern "C" {
#endif // _cplusplus


Paint *PaintInit();
void PaintDrawText(Paint *paint, const char *text, short x, short y);


#ifdef _cplusplus
}
#endif // _cplusplus



#endif // !PAINT_HEAD
