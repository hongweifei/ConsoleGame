
#include "widget.h"
#include "../Graphics/print.h"


#ifndef BUTTON_HEAD
#define BUTTON_HEAD

#define TYPE_BUTTON "button"

typedef struct
{
	//Widget *widget;
	short id;
	char *type;

	short x;
	short y;
	Paint *paint;
	WidgetFunction destroy;
	WidgetFunction update;
	RenderEvent render;

	char *text;
	short focus;//焦点
}Button;


void ButtonRender(Widget *widget, Paint *paint);
Button *ButtonInit(char* text, short x, short y);

void ButtonSetFontColor(Button *button,PrintForeGroundColor color);
void ButtonSetBackGroundColor(Button *button, PrintBackGroundColor color);

#endif // !BUTTON_HEAD









