#pragma once

#include <3ds.h>

#include "apple.h"

void gameMode1(u8 &score, u8 framesToWait = 5)
{
    // Sixty frames per second is too fast, so I only draw every
    // fifth or so frame.
    u8 frameCount = 0;

    Snake snake(TWIDTH);
	Apple apple(TWIDTH);

	apple.setApple(snake.getSnake());

	s8 xIncre = 1, yIncre = 0;

    drawBackground(TWIDTH, HEIGHT, BACKGROUND_COLOR);

    snake.drawTheWholeDarnSnake();
    apple.drawSegment();

    while (aptMainLoop())
    {
        hidScanInput();

        u32 kDown = hidKeysDown();

        if (kDown & KEY_START) {break;}

        if      (kDown & KEY_DUP)    {xIncre =  0; yIncre = -1;}
        else if (kDown & KEY_DDOWN)  {xIncre =  0; yIncre =  1;}
        else if (kDown & KEY_DLEFT)  {xIncre = -1; yIncre =  0;}
        else if (kDown & KEY_DRIGHT) {xIncre =  1; yIncre =  0;}

        if (frameCount == framesToWait)
        {
            snake.updateTheSnake(xIncre, yIncre);

            // What do you think this does?
            if (snake.areYouDeadYet()) {break;}

            if (apple.sameCoords(snake.getSnakeHead()))
            {
                apple.setApple(snake.getSnake());
                apple.drawSegment();
                snake.addSegment();
            }

            // Only the head and piece behind tail are drawn
            snake.drawSnakeHead();

            frameCount = 0;
        }

        else {frameCount++;}

        gfxFlushBuffers();
        gfxSwapBuffers();

        gspWaitForVBlank();
    }

    // Minus one due to tail piece
    u8 tempScore = snake.getSnake().size() - 1;

    if (tempScore > score) {score = tempScore;}
}
