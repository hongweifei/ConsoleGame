

#include <stdio.h>
#include "Graphics/print.h"
#include "Widget/button.h"

int main()
{
	Widget *button = ButtonInit("AAA",0,0);

	WidgetMainLoop();

	return 0;
}


