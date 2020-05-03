

#include <stdio.h>
#include "Graphics/print.h"

#include "Widget/button.h"
#include "Widget/textfield.h"
#include "Widget/widgetloop.h"


void StartGame(Widget *widget)
{
	printf("\a");
	
	RemoveWidgetInMainLoop(1);
	RemoveWidgetInMainLoop(0);

	PrintClear();
	
	Label *label = LabelInit("请输入你的角色名字：", 40 - strlen("请输入你的角色名字：") / 2, 5);
	AddWidgetToMainLoop((Widget*)label);
	
	TextField *field = TextFieldInit(20,15);
	AddWidgetToMainLoop((Widget*)field);

	Button *button1 = ButtonInit("确定", 40 - strlen("确定") / 2, 20);
	AddWidgetToMainLoop((Widget*)button1);

	Button* button2 = ButtonInit("取消", 40 - strlen("取消") / 2, 25);
	AddWidgetToMainLoop((Widget*)button2);
}


void ExitGame(Widget *widget)
{
	PrintClear();
	exit(0);
}


int main()
{
	int quit = 0;

	Button *button_start = ButtonInit("StartGame",40 - strlen("StartGame") / 2,5);
	Button *button_exit = ButtonInit("ExitGame", 40 - strlen("ExitGame") / 2, 10);
	//ButtonSetFontColor(button, PrintForeGroundColorRed);

	button_start->enter = StartGame;
	button_exit->enter = ExitGame;

	AddWidgetToMainLoop((Widget*)button_start);
	AddWidgetToMainLoop((Widget*)button_exit);

	WidgetMainLoop();

	return 0;
}



