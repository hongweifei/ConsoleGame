


#include <stdlib.h>
#include "button.h"


void ButtonRender(Widget *widget,Paint *paint)
{
	Button *button = (Button*)widget;
	//PrintPosition(button->text, button->widget->x, button->widget->y);

	
	if (button->label.widget.focus && button->label.widget.focus_can && button->style == BUTTON_STYLE_DEFAULT)
		PaintDrawText(&paint_style_default, button->label.text, button->label.widget.x, button->label.widget.y);
	else if(!button->label.widget.focus || !button->label.widget.focus_can)
		PaintDrawText(paint, button->label.text, button->label.widget.x, button->label.widget.y);
}


Button *ButtonInit(char *text, short x, short y)
{
	Button *button = (Button*)malloc(sizeof(Button));

	button->label = *LabelInit(text, x, y);
	button->label.widget.type = TYPE_BUTTON;
	button->label.widget.focus_can = TRUE;
	button->label.widget.render = ButtonRender;

	button->style = BUTTON_STYLE_DEFAULT;

	//button->paint = PaintInit();
	//button->widget->paint = button->paint;

	button->enter = NULL;

	//AddWidgetToMainLoop((Widget*)button);

	return button;
}

void ButtonSetFontColor(Button *button, PrintForeGroundColor color)
{
	Paint paint = { color,button->label.widget.paint->background_color };
	button->label.widget.paint = &paint;
}

void ButtonSetBackGroundColor(Button *button, PrintBackGroundColor color)
{
	Paint paint = { button->label.widget.paint->foreground_color,color };
	button->label.widget.paint = &paint;
}


