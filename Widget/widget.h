

#include <stdio.h>
#include "../Graphics/paint.h"

#ifndef WIDGET_HEAD
#define WIDGET_HEAD

#define ASSIGN(NAME, TYPE)	TYPE NAME = (TYPE)malloc(sizeof(TYPE))
#define ZEROSET(NAME, TYPE) memset(NAME, 0, sizeof(TYPE))
#define NEW(TYPE, COUNT)	(TYPE *)calloc(COUNT, sizeof(TYPE))

typedef struct Widget;
typedef void(*WidgetFunction)(struct Widget*);
typedef void(*RenderEvent)(struct Widget*,Paint *paint);

#define TYPE_WIDGET "widget"

typedef struct
{
	short id;
	char *type;

	short x;
	short y;
	Paint *paint;
	WidgetFunction destroy;
	WidgetFunction update;
	RenderEvent render;
	void *data;
}Widget;



void WidgetRender(Widget *widget, Paint *paint);
Widget *WidgetInit(short x, short y);


#define Widget_Init(x,y)				\
do										\
{										\
	Widget *widget = WidgetInit(x, y);	\
	AddWidgetToMainLoop(widget);		\
	return widget;						\
} while (0)






#endif // !WIDGET_HEAD


