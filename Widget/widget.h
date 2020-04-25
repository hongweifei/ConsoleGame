

//#include <stdio.h>
#include <stdlib.h>



#ifndef WIDGET_HEAD
#define WIDGET_HEAD

typedef struct Widget;
typedef void(*RenderEvent)(struct Widget *widget);


typedef struct
{
	short x;
	short y;
	RenderEvent render;
}Widget;


static Widget **widgets = NULL;
static short widget_count = 0;


void WidgetRender(Widget *widget);
Widget *WidgetInit(short x, short y);

void AddWidgetToMainLoop(Widget *widget);

void WidgetMainLoop();


#endif // !WIDGET_HEAD


