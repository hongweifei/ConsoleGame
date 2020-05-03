

#include "widgetloop.h"

#include "widget.h"
#include "button.h"
#include "textfield.h"

#include "keyboard.h"

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

void RemoveWidgetInMainLoop(unsigned short index)
{
	short i;
	for (i = index;i < widget_count - 1;i++)
	{
		widgets[i] = widgets[i + 1];
	}
	
	widgets = (Widget**)realloc(widgets, sizeof(Widget*) * (widget_count - 1));
	widget_count--;
}

void WidgetLoop()
{
	int i = 0;
	int j = 0;
	int key = 0;

	while (1)
	{
		if (KBHIT)
		{
			int key = GETCH;
			
			short focus_count = 0;

			/*WidgetFocus*/
			for (i = 0; i < widget_count; i++)
			{
				if (!widgets[i]->focus)
					focus_count++;

				if (widgets[i]->focus && key == KEY_UP && i > 0)
				{
					widgets[i]->focus = FALSE;
					for (j = i - 1; j > 0; j--)
					{
						if (widgets[j]->focus_can)
						{
							widgets[j]->focus = TRUE;
							break;
						}
					}
					break;
				}
				else if (widgets[i]->focus && key == KEY_DOWN && i < widget_count - 1)
				{
					widgets[i]->focus = FALSE;
					for (j = i + 1; j < widget_count; j--)
					{
						if (widgets[j]->focus_can)
						{
							widgets[j]->focus = TRUE;
							break;
						}
					}
					break;
				}

				if (widgets[i]->type == TYPE_BUTTON && widgets[i]->focus && key == KEY_ENTER)
				{
					Button *button = (Button*)widgets[i];
					if (button->enter != NULL)
						button->enter(button);
				}

				if (widgets[i]->type == TYPE_TEXT_FIELD && widgets[i]->focus && (key >= ' ' && key <= '~'))
				{
					TextField *field = (TextField*)widgets[i];
					LabelAddChar(&field->label,key);
				}
				else if (widgets[i]->type == TYPE_TEXT_FIELD && widgets[i]->focus && key == 8)
				{
					TextField* field = (TextField*)widgets[i];
					LabelRemoveLastChar(&field->label);
				}
			}

			if (focus_count == widget_count && widgets != NULL)
			{
				for (i = 0; i < widget_count; i++)
				{
					if (widgets[i]->focus_can)
					{
						widgets[i]->focus = TRUE;
						break;
					}
				}
			}
		}

		for (i = 0; i < widget_count; i++)
		{
			static Paint paint_cache;
			paint_cache.foreground_color = widgets[i]->paint->foreground_color;
			paint_cache.background_color = widgets[i]->paint->background_color;

			if (widgets[i]->type == TYPE_BUTTON)
			{
				Button* button = (Button*)widgets[i];
				if (button->label.widget.focus)
				{
					paint_cache.foreground_color = PrintForeGroundColorBlack;
					paint_cache.background_color = PrintBackGroundColorWhite;
				}
			}
			
			widgets[i]->render(widgets[i], &paint_cache);
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