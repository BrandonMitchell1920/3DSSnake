#pragma once

#include <3ds.h>

#include "newapple.h"

void twoScreenSnake(PrintConsole &topScreen, PrintConsole &bottomScreen)
{
    unsigned short frameCount = 0;

    NewSnake snake;
	NewApple apple;

	apple.setApple(snake);

	short xIncre = 1, yIncre = 0;

    drawBackground(TWIDTH, HEIGHT, BACKGROUND_COLOR);

    snake.drawTheWholeDarnSnake();

    consoleSelect(&bottomScreen);
    drawBackground(BWIDTH, HEIGHT, BACKGROUND_COLOR);

    apple.drawSegment(topScreen, bottomScreen);

    while (aptMainLoop())
    {
        hidScanInput();

        u32 kDown = hidKeysDown();

        if (kDown & KEY_START)  {break;}

        if      (kDown & KEY_DUP)    {xIncre =  0; yIncre = -1;}
        else if (kDown & KEY_DDOWN)  {xIncre =  0; yIncre =  1;}
        else if (kDown & KEY_DLEFT)  {xIncre = -1; yIncre =  0;}
        else if (kDown & KEY_DRIGHT) {xIncre =  1; yIncre =  0;}

        if (frameCount == 5)
        {
            snake.updateTheSnake(xIncre, yIncre);

            if (snake.areYouDeadYet()) {break;}

            if (apple.sameCoords(snake.getSnakeHead()))
            {
                apple.setApple(snake);
                apple.drawSegment(topScreen, bottomScreen);
                snake.addSegment();
            }

            snake.drawSnakeHead(topScreen, bottomScreen);

            frameCount = 0;
        }

        else {frameCount++;}

        gfxFlushBuffers();
        gfxSwapBuffers();

        gspWaitForVBlank();
    }
    consoleSelect(&bottomScreen);
    drawBackground(BWIDTH, HEIGHT, CLEAR_COLOR);

    consoleSelect(&topScreen);
}
