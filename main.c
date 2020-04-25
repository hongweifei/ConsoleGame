

#include <stdio.h>
#include "Graphics/print.h"
#include "Widget/button.h"

#include "Widget/widgetloop.h"

int main()
{
	int quit = 0;

	Button *button_start = ButtonInit("StartGame",40 - strlen("StartGame") / 2,5);
	Button *button_exit = ButtonInit("ExitGame", 40 - strlen("ExitGame") / 2, 10);
	//ButtonSetFontColor(button, PrintForeGroundColorRed);

	AddWidgetToMainLoop((Widget*)button_start);
	AddWidgetToMainLoop((Widget*)button_exit);

	WidgetMainLoop();

	return 0;
}



