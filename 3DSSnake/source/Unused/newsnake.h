#pragma once

#include "snake.h"

class NewSnake : public Snake
{
protected:

    unsigned short newWidth;

    bool notInsidePlayArea()
	{
        if (getSnakeHead().getScreen())
        {
            if (getSnakeHeadX() > 4 && getSnakeHeadX() < 45 && getSnakeHeadY() == HEIGHT)
            {
                getSnakeHead().setSegment(getSnakeHeadX() - 5, 0, false);
                return false;
            }
            newWidth = TWIDTH;
        }
        else
        {
            if (getSnakeHeadY() > HEIGHT)
            {
                getSnakeHead().setSegment(getSnakeHeadX() + 5, HEIGHT - 1, true);
                return false;
            }
            newWidth = BWIDTH;
        }
		return (getSnakeHeadX() > newWidth - 1 || getSnakeHeadY() > HEIGHT - 1);
	}

public:

    NewSnake() : Snake(TWIDTH) {}

    void drawSnakeHead(PrintConsole &topScreen, PrintConsole &bottomScreen)
	{
	    if (getSnakeHead().getScreen()) {consoleSelect(&topScreen);}
	    else {consoleSelect(&bottomScreen);}
		getSnakeHead().drawSegment();

		if (snake[0].getScreen()) {consoleSelect(&topScreen);}
	    else {consoleSelect(&bottomScreen);}
		clearTrail();
	}

	bool areYouDeadYet()
	{
		return (isTheSnakeEatingItself() || notInsidePlayArea());
	}
};
