

#include <stdio.h>
#include "../Graphics/paint.h"

#ifndef WIDGET_HEAD
#define WIDGET_HEAD

#define ASSIGN(NAME, TYPE)	TYPE NAME = (TYPE)malloc(sizeof(TYPE))
#define ZEROSET(NAME, TYPE) memset(NAME, 0, sizeof(TYPE))
#define NEW(TYPE, COUNT)	(TYPE *)calloc(COUNT, sizeof(TYPE))

typedef struct _widget Widget;
typedef void(*WidgetFunction)(Widget*);
typedef void(*RenderEvent)(Widget*,Paint*);

#define TYPE_WIDGET "widget"


#ifndef BOOL
#define BOOL	short
#define TRUE	1
#define FALSE	0
#endif // !BOOL


typedef struct _widget
{
	short id;
	char *type;

	short x;
	short y;

	BOOL focus_can;
	BOOL focus;

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


