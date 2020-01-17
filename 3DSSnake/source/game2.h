#pragma once

#include <3ds.h>

#include "apple.h"

void gameMode2(PrintConsole &topScreen, PrintConsole &bottomScreen, u8 &score)
{
    u8 frameCount = 0;

    Snake t_snake(TWIDTH);
    Snake b_snake(BWIDTH);

	Apple t_apple(TWIDTH);
	Apple b_apple(BWIDTH);

	t_apple.setApple(t_snake.getSnake());
	b_apple.setApple(b_snake.getSnake());

	s8 t_xIncre = 1, t_yIncre = 0, b_xIncre = 1, b_yIncre = 0;

	consoleSelect(&topScreen);
    drawBackground(TWIDTH, HEIGHT, BACKGROUND_COLOR);
    t_snake.drawTheWholeDarnSnake();
    t_apple.drawSegment();

    consoleSelect(&bottomScreen);
    drawBackground(BWIDTH, HEIGHT, BACKGROUND_COLOR);
    b_snake.drawTheWholeDarnSnake();
    b_apple.drawSegment();

    while (aptMainLoop())
    {
        hidScanInput();

        u32 kDown = hidKeysDown();

        if (kDown & KEY_START) {break;}

        if      (kDown & KEY_DUP)    {t_xIncre =  0; t_yIncre = -1;}
        else if (kDown & KEY_DDOWN)  {t_xIncre =  0; t_yIncre =  1;}
        else if (kDown & KEY_DLEFT)  {t_xIncre = -1; t_yIncre =  0;}
        else if (kDown & KEY_DRIGHT) {t_xIncre =  1; t_yIncre =  0;}

        if      (kDown & KEY_X) {b_xIncre =  0; b_yIncre = -1;}
        else if (kDown & KEY_B) {b_xIncre =  0; b_yIncre =  1;}
        else if (kDown & KEY_Y) {b_xIncre = -1; b_yIncre =  0;}
        else if (kDown & KEY_A) {b_xIncre =  1; b_yIncre =  0;}

        if (frameCount == 5)
        {
            t_snake.updateTheSnake(t_xIncre, t_yIncre);
            b_snake.updateTheSnake(b_xIncre, b_yIncre);

            if (t_snake.areYouDeadYet() || b_snake.areYouDeadYet()) {break;}

            if (t_apple.sameCoords(t_snake.getSnakeHead()))
            {
                t_apple.setApple(t_snake.getSnake());

                consoleSelect(&topScreen);
                t_apple.drawSegment();

                t_snake.addSegment();
            }

            if (b_apple.sameCoords(b_snake.getSnakeHead()))
            {
                b_apple.setApple(b_snake.getSnake());

                consoleSelect(&bottomScreen);
                b_apple.drawSegment();

                b_snake.addSegment();
            }

            consoleSelect(&topScreen);
            t_snake.drawSnakeHead();

            consoleSelect(&bottomScreen);
            b_snake.drawSnakeHead();

            frameCount = 0;
        }

        else {frameCount++;}

        gfxFlushBuffers();
        gfxSwapBuffers();

        gspWaitForVBlank();
    }

    // Clears bottom screen and selects top screen
    consoleSelect(&bottomScreen);
    drawBackground(BWIDTH, HEIGHT, CLEAR_COLOR);

    consoleSelect(&topScreen);

    // Two snakes, two scores
    u8 firstScore  = t_snake.getSnake().size() - 1;
    u8 secondScore = b_snake.getSnake().size() - 1;

    if (firstScore  > score) {score = firstScore;}
    if (secondScore > score) {score = secondScore;}
}

