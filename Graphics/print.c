
#include "print.h"


/*ms为毫秒*/
void PrintSleep(unsigned long ms)
{
#ifdef _WIN32
	Sleep(ms);
#endif

#ifndef _WIN32
	//unsigned long s = ms / 1000;//秒数
	sleep(ms / 1000);
	#endif
}

void PrintClear()
{
#ifdef _WIN32
	cursor_x = 0;
	cursor_y = 0;
	COORD coord = { cursor_x,cursor_y };

	DWORD chars_written;
	CONSOLE_SCREEN_BUFFER_INFO info;

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(handle,&info);

	unsigned long console_size = info.dwSize.X * info.dwSize.Y;

	FillConsoleOutputCharacterW(handle, TEXT(' '), console_size, coord, &chars_written);
	FillConsoleOutputAttribute(handle, info.wAttributes, console_size, coord, &chars_written);

	SetConsoleCursorPosition(handle, coord);
#endif

#ifndef _WIN32
	//printf("\033c");
	ioctl(STDIN_FILENO,TIOCGWINSZ,&window_size);
	static unsigned short i = 0;
	static unsigned short j = 0;
	for (i = 0; i < window_size.ws_row; i++)
	{
		for (j = 0; j < window_size.ws_col; j++)
		{
			PrintPosition(" ",j,i);
		}
	}
#endif
}

/*移動光標*/
void PrintMoveTo(short x, short y)
{
#ifdef _WIN32
	cursor_x = x;
	cursor_y = y;
	static COORD coord = { 0,0 };
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#endif // _WIN32

#ifndef _WIN32
	printf("\033[%d;%dH", y, x);
#endif
}

/*光標上移*/
void PrintMoveUp(short y)
{
#ifdef _WIN32
	cursor_y -= y;
	COORD coord = { cursor_x,cursor_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#endif // _WIN32

#ifndef _WIN32
	printf("\033[%dA", y);
#endif
}

/*光標下移*/
inline void PrintMoveDown(short y)
{
#ifdef _WIN32
	cursor_y += y;
	COORD coord = { cursor_x,cursor_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#endif // _WIN32

#ifndef _WIN32
	printf("\033[%dB", y);
#endif
}

/*光标左移*/
void PrintMoveLeft(short x)
{
#ifdef _WIN32
	cursor_x -= x;
	COORD coord = { cursor_x,cursor_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#endif // _WIN32

#ifndef _WIN32
	printf("\033[%dD", x);
#endif
}

/*光标右移*/
void PrintMoveRight(short x)
{
#ifdef _WIN32
	cursor_x += x;
	COORD coord = { cursor_x,cursor_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#endif // _WIN32

#ifndef _WIN32
	printf("\033[%dC", x);
#endif
}

/*在指定位置输出文本*/
void PrintPosition(const char *text, short x, short y)
{
#ifdef _WIN32
	PrintMoveTo(x, y);
	printf(text);
#endif // _WIN32

#ifndef _WIN32
	printf("\033[%d;%dH%s\033[0m", y , x, text);
#endif
}

/*输出带有颜色的文本*/
void PrintHaveColor(const char *text, PrintForeGroundColor fore_ground_color, PrintBackGroundColor back_ground_color)
{
#ifdef _WIN32
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fore_ground_color | back_ground_color);
	printf(text);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
#endif // _WIN32

#ifndef _WIN32
	printf("\033[%d;%dm%s\033[0m", fore_ground_color, back_ground_color, text);
#endif // __linux

}

/*输出带有前景色的文本*/
void PrintHaveForeGroundColor(const char *text, PrintForeGroundColor fore_ground_color)
 { PrintHaveColor(text, fore_ground_color, 0); }

/*输出带有背景颜色的文本*/
void PrintHaveBackGroundColor(const char *text, PrintBackGroundColor back_ground_color) 
{ PrintHaveColor(text, 0, back_ground_color); }


