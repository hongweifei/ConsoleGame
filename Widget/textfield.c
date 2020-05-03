

#include "textfield.h"

void TextFieldRender(Widget *widget, Paint *paint)
{
	Label* label = (Label*)widget;

	unsigned int length = strlen(label->text);
	
	int i;
	for (i = 0; i < length; i++)
	{
		PaintDrawText(paint, "_", label->widget.x + i, label->widget.y - 1);
		PaintDrawText(paint, "-", label->widget.x + i, label->widget.y + 1);
	}

	PaintDrawText(paint, label->text, label->widget.x, label->widget.y);
	PaintDrawText(paint, " ", label->widget.x + length, label->widget.y);
	PaintDrawText(paint, " ", label->widget.x + length, label->widget.y - 1);
	PaintDrawText(paint, " ", label->widget.x + length, label->widget.y + 1);
}

TextField *TextFieldInit(short x,short y)
{
	TextField *field = (TextField*)malloc(sizeof(TextField));

	field->label = *LabelInit("",x,y);
	field->label.widget.type = TYPE_TEXT_FIELD;
	field->label.widget.focus_can = TRUE;
	field->label.widget.render = TextFieldRender;

	return field;
}
