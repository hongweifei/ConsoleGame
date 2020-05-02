

#include "widgetloop.h"

#include "widget.h"
#include "button.h"


void AddWidgetToMainLoop(Widget* widget)
{
	if (widgets == NULL)
	{
		widget_count = 0;
		widgets = (Widget**)malloc(sizeof(Widget*));
	}
	else
		widgets = (Widget**)realloc(widgets, sizeof(Widget*) * (widget_count + 1));

	widgets[widget_count] = widget;
	widget->id = widget_count;
	widget_count++;
}


void WidgetLoop()
{
	int i = 0;
	int key = 0;

	while (1)
	{
		if (KBHIT)
		{
			int key = GETCH;
			if (key == KEY_UP)
			{
				for (i = 0; i < widget_count; i++)
				{
					if (widgets[i]->type == TYPE_BUTTON)
					{
						Button* button = (Button*)widgets[i];
						if (!button->focus)
						{
							button->focus = 1;
						}
					}
				}
			}
			else if (key == KEY_DOWN)
			{
				Button* button = (Button*)widgets[0];
				for (i = 0; i < widget_count; i++)
				{
					
					if (widgets[i]->type == TYPE_BUTTON)
					{
						Button* button = (Button*)widgets[i];
						if (!button->focus)
						{
							button->focus = 1;
						}
					}
				}
			}
		}

		for (i = 0; i < widget_count; i++)
		{
			Paint *paint = PaintInit();
			*paint = *widgets[i]->paint;

			if (widgets[i]->type == TYPE_BUTTON)
			{
				Button* button = (Button*)widgets[i];
				if (button->focus)
				{
					paint->foreground_color = PrintForeGroundColorBlack;
					paint->background_color = PrintBackGroundColorWhite;
				}
			}
			
			widgets[i]->render(widgets[i], paint);
		}

	#ifdef _WIN32
		static unsigned long ms = 1000 / 30;
		Sleep(ms);
	#endif

	#ifndef _WIN32
		static unsigned long s = 1000 / 30 / 1000;//秒数
		sleep(s);
	#endif
	}

	for (i = 0; i < widget_count; i++)
		free(widgets[i]);
}


void WidgetMainLoop()
{
#ifdef _WIN32
	//_beginthread(WidgetLoop,0,NULL);
	WidgetLoop();
#endif // _WIN32

#ifndef _WIN32
	pthread_t thread;
	int result = pthread_create(&thread, NULL, WidgetLoop, NULL);
#endif // !_WIN32
}