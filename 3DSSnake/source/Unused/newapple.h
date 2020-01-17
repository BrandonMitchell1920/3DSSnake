#pragma once

#include "newsnake.h"

class NewApple : public Apple
{
public:

    NewApple() : Apple(TWIDTH) {}

    void drawSegment(PrintConsole &topScreen, PrintConsole &bottomScreen)
    {
        if (getScreen()) {consoleSelect(&topScreen);}
        else {consoleSelect(&bottomScreen);}

        printToConsole(x, y, APPLE_COLOR);
    }

	// Sets the position of the apple
	void setApple(NewSnake &snake)
	{
	    if (getRand(2) == 0)
        {
            flipScreen();
        }

	    if (getScreen()) {width = TWIDTH;}
	    else {width = BWIDTH;}

		unsigned short snakeSize = snake.getSnakeSize();
		std::vector<SnakeSegment> tempSnake = snake.getSnake();

		unsigned short snakeCount;

        do
        {
            snakeCount = 0;

            setSegment(getRand(width), getRand(HEIGHT), getScreen());

            for (unsigned short i = 0; i < snakeSize; i++)
			{
				if (!sameCoords(tempSnake[i])) {snakeCount++;}
			}
        }
        while (snakeCount != snakeSize);
	}
};
