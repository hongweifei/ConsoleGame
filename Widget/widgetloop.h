

#pragma once

#include "widget.h"

#include <conio.h> 

#ifdef _WIN32
#define KBHIT _kbhit()
#define GETCH _getch()
#endif // _WIN32

#ifndef _WIN32
#define KBHIT kbhit()
#define GETCH getch()
#endif // !_WIN32



static Widget** widgets = NULL;
static short widget_count = 0;


void AddWidgetToMainLoop(Widget* widget);
void RemoveWidgetInMainLoop(unsigned short index);

void WidgetMainLoop();

