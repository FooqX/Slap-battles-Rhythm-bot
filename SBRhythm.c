#include <stdio.h>
#include <Windows.h>
#include <process.h>
#include <stdbool.h>
#include <utilapiset.h>
#include <synchapi.h>
#include <stdlib.h>

const unsigned short int pixel_x = 962;  // Update with the correct x coordinate
const unsigned short int pixel_y = 892;  // Update with the correct y coordinate

volatile bool running = false;

static bool is_tile_present() {
	HDC hdcScreen = GetDC(NULL);
	COLORREF pixel = GetPixel(hdcScreen, pixel_x, pixel_y);
	ReleaseDC(NULL, hdcScreen);

	// Check if the pixel is white or yellow
	return (GetRValue(pixel) == 255 && GetGValue(pixel) == 255 && GetBValue(pixel) == 255) ||
		(GetRValue(pixel) == 255 && GetGValue(pixel) == 192 && GetBValue(pixel) == 67);
}

static void beep_on() {
	Beep(1000, 100);
}

static void beep_off() {
	Beep(1000, 500);
}

static void toggle_script() {
	running = !running;

	if (running) {
		printf("Script started\n");
		beep_on();
	}
	else {
		printf("Script paused\n");
		beep_off();
	}
}

static void main_loop() {
	while (true) {
		if (is_tile_present() && running) {
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}

		Sleep(10);
	}
}

int main() {
	printf("SBRhythm.c / Version 1.0.1\nPress 'R' to toggle the script.\nPress 'P' to exit out of the program.\n");

	// Set up hotkeys for toggling the script
	RegisterHotKey(NULL, 1, MOD_NOREPEAT, 'R');
	RegisterHotKey(NULL, 2, MOD_NOREPEAT, 'P');

	// Start the main loop in a separate thread
	_beginthread(&main_loop, 0, NULL);

	// Message loop to handle hotkey
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		if (msg.message == WM_HOTKEY) {
			if (msg.wParam == 1) {
				toggle_script();
			} else if (msg.wParam == 2) {
				exit(0);
			}
		}
	}
	return 0;
}
