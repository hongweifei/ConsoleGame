
#pragma once


#include "label.h"

#define TYPE_TEXT_FIELD "text_field"

typedef struct
{
	Label label;
	unsigned short width;
	unsigned short height;
}TextField;

void TextFieldRender(Widget *widget, Paint *paint);
TextField *TextFieldInit(short x, short y);

void TextFieldSetText(TextField *field, const char *text);
void TextFieldAddChar(TextField *field, int ch);
void TextFieldRemoveLastChar(TextField *field);

