
#include "widget.h"
#include "label.h"
#include "../Graphics/print.h"


#ifndef BUTTON_HEAD
#define BUTTON_HEAD

#define TYPE_BUTTON "button"

typedef struct
{
	Label label;
	WidgetFunction enter;
}Button;


//void ButtonRender(Widget *widget, Paint *paint);
Button *ButtonInit(char* text, short x, short y);

void ButtonSetFontColor(Button *button,PrintForeGroundColor color);
void ButtonSetBackGroundColor(Button *button, PrintBackGroundColor color);

#endif // !BUTTON_HEAD









