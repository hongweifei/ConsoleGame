

#include <stdlib.h>

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

	#ifdef __linux
	printf("\033[?25l");
	#endif

	while (1)
	{
		PrintClear();

		#ifdef _WIN32
		if (KBHIT)
		#endif

		#ifdef __linux
		if((key = GETCH))
		#endif
		{
			#ifdef _WIN32
			int key = GETCH;
			#endif

			//printf("%d\n",key);
			
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
						button->enter((Widget*)button);
				}

				if (widgets[i]->type == TYPE_TEXT_FIELD && widgets[i]->focus && (key >= ' ' && key <= '~'))
				{
					TextField *field = (TextField*)widgets[i];
					TextFieldAddChar(field,key);
				}
				else if (widgets[i]->type == TYPE_TEXT_FIELD && widgets[i]->focus && key == 8)
				{
					TextField* field = (TextField*)widgets[i];
					TextFieldRemoveLastChar(field);
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
			widgets[i]->render(widgets[i], widgets[i]->paint);

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
	//#include <windows.h>
	//_beginthread(WidgetLoop,0,NULL);
	WidgetLoop();
#endif // _WIN32

#ifndef _WIN32
	//#include <pthread.h>
	//pthread_t thread;
	//int result = pthread_create(&thread, NULL, WidgetLoop, NULL);
	WidgetLoop();
#endif // !_WIN32
}
