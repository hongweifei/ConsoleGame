


#include <stdlib.h>
#include <string.h>
#include "label.h"

void LabelRender(Widget *widget, Paint *paint)
{
	Label *label = (Label*)widget;
	//PrintPosition(button->text, button->widget->x, button->widget->y);
	PaintDrawText(paint, label->text, label->widget.x, label->widget.y);
}

Label *LabelInit(char *text, short x, short y)
{
	Label *label = (Label*)malloc(sizeof(Label));

	label->widget = *WidgetInit(x, y);
	label->widget.type = TYPE_LABEL;
	label->widget.focus_can = FALSE;
	label->widget.render = LabelRender;

	//label->paint = PaintInit();
	//label->widget->paint = label->paint;

	LabelSetText(label, text);

	//AddWidgetToMainLoop((Widget*)label);

	return label;
}

void LabelSetFontColor(Label *label, PrintForeGroundColor color)
{
	Paint paint = { color,label->widget.paint->background_color };
	label->widget.paint = &paint;
}

void LabelSetBackGroundColor(Label *label, PrintBackGroundColor color)
{
	Paint paint = { label->widget.paint->foreground_color,color };
	label->widget.paint = &paint;
}

void LabelSetText(Label *label, const char *text)
{
	label->text = (char*)calloc(1,sizeof(Label));
	strcpy(label->text, text);
}

void LabelAddChar(Label* label, int ch)
{
	unsigned short length = strlen(label->text);
	label->text = (char*)realloc(label->text,sizeof(char) * (length + 1 + 1));
	label->text[length] = (char)ch;
	label->text[length + 1] = '\0';
}

void LabelRemoveLastChar(Label *label)
{
	unsigned short length = strlen(label->text);
	if (length > 1)
	{
		label->text = (char*)realloc(label->text, sizeof(char) * (length - 1));
		label->text[length - 1] = '\0';
	}
	else if (length == 1)
	{
		LabelSetText(label, "");
	}
}

