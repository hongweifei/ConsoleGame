

#pragma once


#include <conio.h> 

#ifdef _WIN32
#define KBHIT _kbhit()
#define GETCH _getch()
#endif // _WIN32

#ifndef _WIN32
#define KBHIT kbhit()
#define GETCH getch()
#endif // !_WIN32


typedef enum _keyboard
{
	KEY_UP = 72,
	KEY_DOWN = 80,
	KEY_LEFT = 75,
	KEY_RIGHT = 77,

	KEY_ENTER = 13,

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



