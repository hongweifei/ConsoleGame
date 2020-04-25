

#pragma once

#include "widget.h"


static Widget** widgets = NULL;
static short widget_count = 0;


void AddWidgetToMainLoop(Widget* widget);

void WidgetMainLoop();

