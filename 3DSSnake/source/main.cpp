/*
 * Name: Brandon Mitchell
 * Description: This bad boy is a snake game I made in C++.  The apple
 *              spawns randomly.  Run into one to grow!
 *
 *              Modified from the original to run on the 3DS.  I am using
 *              ctrulib datatypes.  For example, u8 means an unsigned,
 *              eight-bit integer.  I also use s8, or a signed integer.
 *              There are also volatile versions of each data type, like vu8.
 *
 *              There could be a problem if you are good enough to get a
 *              snake longer than 255, but I hope no one that is really good
 *              at snake decides to play this.
 */

#include <time.h>     // Time since epoch used as seed

#include "game1.h"
#include "game2.h"
#include "menu.h"

int main(int argc, char **argv)
{
    // For setting the apple
    srand(time(0));

    gfxInitDefault();

    // Bind to which screen you want, must be bound or else the system will crash
    // Four different screens to bind to: top left, top right, top, bottom
    PrintConsole topScreen, bottomScreen;

    // If no handle is needed, use NULL, else bind to handle
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);

	// Select which console using the pre-bound handle
	consoleSelect(&topScreen);

	Menu menu;
	menu.score = loadScore();
	menu.drawEverything();

    while (aptMainLoop())
    {
        hidScanInput();

        // One of the ctrulib data types, 32 bits of memory
        u32 kDown = hidKeysDown();

        // Keys come in as binary values, bitwise and them with kDown
        // (all keys pressed) to determine if it was pressed or not
        // There also exists hidKeysHeld(), but I didn't have a use for it
        if (kDown & KEY_START) {break;}

        if (kDown & KEY_A)
        {
            if      (menu.getPlayerCursor() == 0) {gameMode1(menu.score); menu.drawEverything();}
            else if (menu.getPlayerCursor() == 1) {gameMode2(topScreen, bottomScreen, menu.score); menu.drawEverything();}
            else if (menu.getPlayerCursor() == 2) {gameMode1(menu.score, 3); menu.drawEverything();}
            else {break;} // Exit choice
        }
        else if (kDown & KEY_DDOWN) {menu.setPlayerCursor(1);}
        else if (kDown & KEY_DUP)   {menu.setPlayerCursor(-1);}

        gfxFlushBuffers();
        gfxSwapBuffers();

        // 3DS works at 60 frames per second, must wait before trying
        // to draw again or things look ugly and messed up.
        gspWaitForVBlank();
    }

    saveScore(menu.score);

	gfxExit();
	return 0;
}
