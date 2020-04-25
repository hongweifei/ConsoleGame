

#include "widget.h"

#ifdef _WIN32
#include <process.h>	// for _beginthread()
#endif // _WIN32

#ifndef _WIN32
#include <pthread.h>
#endif // !_WIN32


void WidgetRender(Widget *widget)
{

}

Widget *WidgetInit(short x, short y)
{
	Widget *widget = (Widget*)malloc(sizeof(Widget));
	widget->x = x;
	widget->y = y;
	widget->render = WidgetRender;

	//AddWidgetToMainLoop(widget);

	return widget;
}

void AddWidgetToMainLoop(Widget* widget)
{
	if (widgets == NULL)
		widgets = (Widget**)malloc(sizeof(Widget*));
	else
		widgets = (Widget**)realloc(widgets,sizeof(Widget*) * (widget_count + 1));
	
	widgets[widget_count] = widget;
	widget_count++;
}


void WidgetLoop()
{
	int i = 0;

	while (1)
	{
		for (i = 0; i < widget_count; i++)
		{
			widgets[i]->render(widgets[i]);
		}
	}
	
}


void WidgetMainLoop()
{
#ifdef _WIN32
	//_beginthread(WidgetLoop,0,NULL);
	WidgetLoop();
#endif // _WIN32

#ifndef _WIN32

#endif // !_WIN32
}


