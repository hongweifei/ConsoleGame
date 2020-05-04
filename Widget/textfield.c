

#include <stdlib.h>
#include <string.h>

#include "textfield.h"
#include "../Graphics/print.h"


void TextFieldRender(Widget *widget, Paint *paint)
{
	TextField *field = (TextField*)widget;

	static short i = 0;
	static short j = 0;

	static unsigned int length = 0;
	static unsigned short last_height = 1;

	length = strlen(field->label.text);

	
	static BOOL init = FALSE;
	if (!init)
	{
		if (field->width > 80 - field->label.widget.x - 2)
		{
			field->width = 80 - field->label.widget.x - 2;
			init = TRUE;
		}
		if(field->height < 1)
			field->height = 1;
	}

	field->height = length / field->width + 1;

	if (last_height != field->height)
	{
		for (i = 0; i < field->width; i++)
		{
			PrintPosition(" ",field->label.widget.x + i, field->label.widget.y + last_height);
		}
		
		if (last_height > field->height)//高度减少了
		{
			PrintPosition("  ", field->label.widget.x - 2, field->label.widget.y + last_height);
			PrintPosition("  ", field->label.widget.x + field->width, field->label.widget.y + last_height);
		}

		last_height = field->height;
	}

	
	for (i = 0; i < field->width; i++)
	{
		PaintDrawText(paint, "─", field->label.widget.x + i, field->label.widget.y - 1);
		PaintDrawText(paint, "─", field->label.widget.x + i, field->label.widget.y + field->height);
		i++;
	}
	

	PaintDrawText(paint, "┌", field->label.widget.x - 2, field->label.widget.y - 1);
	PaintDrawText(paint, "┐", field->label.widget.x + field->width, field->label.widget.y - 1);
	PaintDrawText(paint, "└", field->label.widget.x - 2, field->label.widget.y + field->height);
	PaintDrawText(paint, "┘", field->label.widget.x + field->width, field->label.widget.y + field->height);
	for (i = 0; i < field->height; i++)
	{
		PaintDrawText(paint, "│", field->label.widget.x - 2, field->label.widget.y + i);
		PaintDrawText(paint, "│", field->label.widget.x + field->width, field->label.widget.y + i);
	}

	if (field->height == 1)
	{
		PaintDrawText(paint, field->label.text, field->label.widget.x, field->label.widget.y);
		PrintPosition(" ", field->label.widget.x + length, field->label.widget.y);
	}
	else if(field->height > 1)
	{
		static char str[2] = {'\0'};
		static short count = 0;
		static short x = 0;
		static short y = 0;
		for (i = 0; i < field->height; i++)
		{
			for (j = 0; j < field->width; j++)
			{
				count = i * field->width + j;
				x = field->label.widget.x + j;
				y = field->label.widget.y + i;

				if (count < length)
				{
					sprintf(str, "%c", field->label.text[count]);
					PaintDrawText(paint, str, x, y);
				}
				else
					break;
			}
		}
		PrintPosition(" ",x, field->label.widget.y + field->height - 1);
	}
}

TextField *TextFieldInit(short x,short y)
{
	TextField *field = (TextField*)malloc(sizeof(TextField));

	field->label = *LabelInit("",x,y);
	field->label.widget.type = TYPE_TEXT_FIELD;
	field->label.widget.focus_can = TRUE;
	field->label.widget.render = TextFieldRender;

	field->width = 20;
	field->height = 1;

	return field;
}

void TextFieldSetText(TextField* field, const char* text)
{
	LabelSetText(&field->label,text);
	field->height = strlen(field->label.text) / field->width + 1;
}

void TextFieldAddChar(TextField *field, int ch)
{
	LabelAddChar(&field->label, ch);
	field->height = strlen(field->label.text) / field->width + 1;
}

void TextFieldRemoveLastChar(TextField* field)
{
	LabelRemoveLastChar(&field->label);
	field->height = strlen(field->label.text) / field->width + 1;
}
