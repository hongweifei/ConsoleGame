

#pragma once

#include "widget.h"

#define TYPE_LABEL "label"

typedef struct _label
{
	Widget widget;
	char* text;
}Label;

void LabelRender(Widget* widget, Paint* paint);
Label *LabelInit(char* text, short x, short y);

void LabelSetFontColor(Label *label, PrintForeGroundColor color);
void LabelSetBackGroundColor(Label *label, PrintBackGroundColor color);

void LabelSetText(Label *label,const char *text);
void LabelAddChar(Label *label,int ch);
void LabelRemoveLastChar(Label *label);
