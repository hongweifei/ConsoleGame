

#pragma once

#include "widget.h"

#define KEY_UP		72
#define KEY_DOWN	80
#define KEY_LEFT	75
#define KEY_RIGHT	77

#ifdef _WIN32
#include <conio.h> 
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

void WidgetMainLoop();

