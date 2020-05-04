

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

#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

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


struct winsize window_size;


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
	void PrintSleep(unsigned long ms);

	void PrintClear();

	/*移動光標*/
	void PrintMoveTo(short x, short y);

	/*光標上移*/
	void PrintMoveUp(short y);

	/*光標下移*/
	void PrintMoveDown(short y);

	/*光标左移*/
	void PrintMoveLeft(short x);

	/*光标右移*/
	void PrintMoveRight(short x);

	/*在指定位置输出文本*/
	void PrintPosition(const char *text, short x, short y);

	/*输出带有颜色的文本*/
	void PrintHaveColor(const char *text, PrintForeGroundColor fore_ground_color, PrintBackGroundColor back_ground_color);

	/*输出带有前景色的文本*/
	void PrintHaveForeGroundColor(const char *text, PrintForeGroundColor fore_ground_color) ;

	/*输出带有背景颜色的文本*/
	void PrintHaveBackGroundColor(const char *text, PrintBackGroundColor back_ground_color) ;



#ifdef _cplusplus
}
#endif // _cplusplus



#endif // !PRINT_HEAD