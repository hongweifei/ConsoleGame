

#include "widget.h"

#ifdef _WIN32
#include <process.h>	// for _beginthread()
#endif // _WIN32

#ifndef _WIN32
#include <pthread.h>
#pragma comment(lib,"pthread")
#endif // !_WIN32

void WidgetRender(Widget *widget, Paint *paint)
{

}


Widget *WidgetInit(short x, short y)
{
	Widget *widget = (Widget*)malloc(sizeof(Widget));
	widget->id = -1;
	widget->type = TYPE_WIDGET;
	widget->x = x;
	widget->y = y;
	widget->paint = PaintInit();
	widget->render = WidgetRender;

	return widget;
}










