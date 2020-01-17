#pragma once

#include "snake.h"

class Apple : public SnakeSegment
{
private:

    u8 width;

public:

    Apple(u8 newWidth) :
        width(newWidth) {}

	void drawSegment()
	{
		printToConsole(x, y, APPLE_COLOR);
	}

	// Sets the position of the apple, checks for snake collisions
	void setApple(const std::vector<SnakeSegment> &snake)
	{
		u8 snakeSize = snake.size();

		bool collision;

        do
        {
            collision = false;

            setSegment(getRand(width), getRand(HEIGHT));

            for (u8 i = 0; i < snakeSize; i++)
			{
				if (sameCoords(snake[i])) {collision = true;}
			}
        }
        while (collision);
	}
};
