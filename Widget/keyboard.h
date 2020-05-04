

#pragma once



#ifdef _WIN32
#include <conio.h> 
#define KBHIT _kbhit()
#define GETCH _getch()
#endif // _WIN32

#ifdef __linux

int Getch()
{
	int ch;
	system("stty -icanon");
	ch = getchar();
	system("stty icanon");
	return ch;
}

//#define KBHIT kbhit()
#define GETCH Getch()
#endif // !_WIN32


typedef enum _keyboard
{
	#ifdef _WIN32
	KEY_UP = 72,
	KEY_DOWN = 80,
	KEY_LEFT = 75,
	KEY_RIGHT = 77,
	
	KEY_ENTER = 13,
	#endif


	#ifdef __linux
	KEY_UP = 65,
	KEY_DOWN = 66,
	KEY_LEFT = 68,
	KEY_RIGHT = 67,

	//KEY_ENTER = 10,
	#endif


	KEY_A = 'a',
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z,
}Keyboard;



