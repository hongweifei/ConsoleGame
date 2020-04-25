

#include "button.h"

void ButtonRender(Widget *widget,Paint *paint)
{
	Button *button = (Button*)widget;
	//PrintPosition(button->text, button->widget->x, button->widget->y);
	PaintDrawText(paint, button->text, button->x, button->y);
}

Button *ButtonInit(char *text, short x, short y)
{
	Button *button = (Button*)malloc(sizeof(Button));

	button = (Button*)WidgetInit(x, y);
	button->type = TYPE_BUTTON;

	button->render = ButtonRender;
	button->text = text;
	button->focus = 0;

	//AddWidgetToMainLoop((Widget*)button);

	return button;
}

void ButtonSetFontColor(Button* button, PrintForeGroundColor color)
{
	Paint paint = { color,button->paint->background_color };
	*button->paint = paint;
}

void ButtonSetBackGroundColor(Button* button, PrintBackGroundColor color)
{
	Paint paint = { button->paint->foreground_color,color };
	*button->paint = paint;
}


