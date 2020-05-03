

#include <stdio.h>

#ifndef PRINT_HEAD
#define PRINT_HEAD


#ifdef _WIN32
#include <Windows.h>

/*
#define PRINT_FOREGROUND_BLACK		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
#define PRINT_FOREGROUND_WHITE		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
#define PRINT_FOREGROUND_RED		FOREGROUND_RED			// text color contains red.
#define PRINT_FOREGROUND_GREEN		FOREGROUND_GREEN		// text color contains green.
#define PRINT_FOREGROUND_BLUE		FOREGROUND_BLUE			// text color contains blue.
//#define PRINT_FOREGROUND_INTENSITY	FOREGROUND_INTENSITY	// text color is intensified.

#define PRINT_BACKGROUND_BLACK		BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE
#define PRINT_BACKGROUND_WHITE		BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE
#define PRINT_BACKGROUND_RED		BACKGROUND_RED			// background color contains red.
#define PRINT_BACKGROUND_GREEN		BACKGROUND_GREEN		// background color contains green.
#define PRINT_BACKGROUND_BLUE		BACKGROUND_BLUE			// background color contains blue.
//#define PRINT_BACKGROUND_INTENSITY	BACKGROUND_INTENSITY	// background color is intensified.
*/

typedef enum _print_foreground_color
{
	PrintForeGroundColorBlack,
	PrintForeGroundColorWhite = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	PrintForeGroundColorRed = FOREGROUND_RED,
	PrintForeGroundColorGreen = FOREGROUND_GREEN,
	PrintForeGroundColorBlue = FOREGROUND_BLUE
}PrintForeGroundColor;


typedef enum _print_background_color
{
	PrintBackGroundColorBlack,
	PrintBackGroundColorWhite = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
	PrintBackGroundColorRed = BACKGROUND_RED,
	PrintBackGroundColorGreen = BACKGROUND_GREEN,
	PrintBackGroundColorBlue = BACKGROUND_BLUE
}PrintBackGroundColor;


static short cursor_x = 0;
static short cursor_y = 0;

#endif // _WIN32


#ifndef _WIN32

#include<unistd.h>

/*
#define PRINT_FOREGROUND_BLACK		30
#define PRINT_FOREGROUND_WHITE		37
#define PRINT_FOREGROUND_RED		31		// text color contains red.
#define PRINT_FOREGROUND_GREEN		32		// text color contains green.
#define PRINT_FOREGROUND_BLUE		34		// text color contains blue.


#define PRINT_BACKGROUND_BLACK		40
#define PRINT_BACKGROUND_WHITE		47
#define PRINT_BACKGROUND_RED		41		// background color contains red.
#define PRINT_BACKGROUND_GREEN		42		// background color contains green.
#define PRINT_BACKGROUND_BLUE		44		// background color contains blue.
*/


typedef enum _print_foreground_color
{
	PrintForeGroundColorBlack = 30,
	PrintForeGroundColorWhite = 37,
	PrintForeGroundColorRed = 31,
	PrintForeGroundColorGreen = 32,
	PrintForeGroundColorBlue = 34
}PrintForeGroundColor;


typedef enum _print_background_color
{
	PrintBackGroundColorBlack = 40,
	PrintBackGroundColorWhite = 47,
	PrintBackGroundColorRed = 41,
	PrintBackGroundColorGreen = 42,
	PrintBackGroundColorBlue = 44
}PrintBackGroundColor;



// 光标复位
#define RESET_CURSOR() printf("\033[H")
// 隐藏光标
#define HIDE_CURSOR() printf("\033[?25l")

// 显示光标
#define SHOW_CURSOR() printf("\033[?25h")

//清除从光标到行尾的内容
#define CLEAR_LINE() printf("\033[K")
//反显
#define HIGHT_LIGHT() printf("\033[7m")
#define UN_HIGHT_LIGHT() printf("\033[27m")

//设置颜色
#define SET_FRONT_COLOR(color) printf("\033[%dm",(color))
#define SET_BACKGROUND_COLOR(color) printf("\033[%dm",(color))

#endif // !_WIN32


#ifdef _cplusplus
extern "C" {
#endif

	/*ms为毫秒*/
	inline void PrintSleep(unsigned long ms)
	{
	#ifdef _WIN32
		Sleep(ms);
	#endif

	#ifndef _WIN32
		static unsigned long s = ms / 1000;//秒数
		sleep(s);
	#endif
	}

	inline void PrintClear()
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
		printf("\033[2J");
	#endif
	}

	/*移動光標*/
	inline void PrintMoveTo(short x, short y)
	{
	#ifdef _WIN32
		cursor_x = x;
		cursor_y = y;
		COORD coord = { cursor_x,cursor_y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	#endif // _WIN32

	#ifndef _WIN32
		printf("\033[%d;%dH", x, y);
	#endif
	}

	/*光標上移*/
	inline void PrintMoveUp(short y)
	{
	#ifdef _WIN32
		cursor_y -= y;
		COORD coord = { cursor_x,cursor_y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	#endif // _WIN32

	#ifndef _WIN32
		printf("\033[%dA", x);
	#endif
	}

	/*光標下移*/
	inline void PrintMoveDown(short x, short y)
	{
	#ifdef _WIN32
		cursor_y += y;
		COORD coord = { cursor_x,cursor_y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	#endif // _WIN32

	#ifndef _WIN32
		printf("\033[%dB", x);
	#endif
	}

	/*光标左移*/
	inline void PrintMoveLeft(short x, short y)
	{
	#ifdef _WIN32
		cursor_x -= x;
		COORD coord = { cursor_x,cursor_y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	#endif // _WIN32

	#ifndef _WIN32
		printf("\033[%dD", y);
	#endif
	}

	/*光标右移*/
	inline void PrintMoveRight(short x)
	{
	#ifdef _WIN32
		cursor_x += x;
		COORD coord = { cursor_x,cursor_y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	#endif // _WIN32

	#ifndef _WIN32
		printf("\033[%dC", y);
	#endif
	}

	/*在指定位置输出文本*/
	inline void PrintPosition(const char *text, short x, short y)
	{
	#ifdef _WIN32
		cursor_x = x;
		cursor_y = y;
		COORD coord = { cursor_x,cursor_y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		printf(text);
	#endif // _WIN32

	#ifndef _WIN32
		printf("\033[%d;%dH%s", x, y, text);
	#endif
	}

	/*输出带有颜色的文本*/
	inline void PrintHaveColor(const char *text, PrintForeGroundColor fore_ground_color, PrintBackGroundColor back_ground_color)
	{
	#ifdef _WIN32
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fore_ground_color | back_ground_color);
		printf(text);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	#endif // _WIN32

	#ifndef _WIN32
		printf("\033[%d;%d%s\033[0m", fore_ground_color, back_ground_color, text);
	#endif // __linux

	}

	/*输出带有前景色的文本*/
	inline void PrintHaveForeGroundColor(const char *text, PrintForeGroundColor fore_ground_color) { PrintHaveColor(text, fore_ground_color, 0); }

	/*输出带有背景颜色的文本*/
	inline void PrintHaveBackGroundColor(const char *text, PrintBackGroundColor back_ground_color) { PrintHaveColor(text, 0, back_ground_color); }



#ifdef _cplusplus
}
#endif // _cplusplus



#endif // !PRINT_HEAD