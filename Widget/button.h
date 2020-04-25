
#include "widget.h"
#include "../Graphics/print.h"


#ifndef BUTTON_HEAD
#define BUTTON_HEAD

typedef struct
{
	Widget *widget;
	char *text;
}Button;


void ButtonRender(Widget *widget);
Button *ButtonInit(char* text, short x, short y);


#endif // !BUTTON_HEAD









