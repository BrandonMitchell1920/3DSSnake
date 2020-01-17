#pragma once

#include "snakesegment.h"

class NewSnakeSegment : public SnakeSegment
{
protected:

    bool topScreen;

public:

    NewSnakeSegment(unsigned short x, unsigned short y, bool screen)
    : SnakeSegment(x, y)
    {
        topScreen = screen;
    }

    bool getScreen()
	{
	    return topScreen;
	}

	void flipScreen()
	{
	    topScreen = !topScreen;
	}

    bool sameCoords(NewSnakeSegment other)
	{
		return (getSegmentX() == other.getSegmentX() &&
			    getSegmentY() == other.getSegmentY() &&
                getScreen()   == other.getScreen());
	}

    void setSegment(unsigned short newX, unsigned short newY, bool screen)
	{
		x = newX; y = newY; topScreen = screen;
	}
};
