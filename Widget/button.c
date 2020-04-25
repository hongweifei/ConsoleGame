

#include "button.h"

void ButtonRender(Widget *widget)
{
	Button *button = (Button*)widget;
	PrintPosition(button->text, button->widget->x, button->widget->y);
}

Button *ButtonInit(char *text, short x, short y)
{
	Button *button = (Button*)malloc(sizeof(Button));
	button->widget = WidgetInit(x, y);
	button->widget->render = ButtonRender;
	button->text = text;

	AddWidgetToMainLoop(button);

	return button;
}
