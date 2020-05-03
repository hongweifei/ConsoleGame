
#pragma once


#include "label.h"

#define TYPE_TEXT_FIELD "text_field"

typedef struct
{
	Label label;
}TextField;

void TextFieldRender(Widget *widget, Paint *paint);
TextField *TextFieldInit(short x, short y);

