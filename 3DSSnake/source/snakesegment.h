#pragma once

#include "printing.h"

class SnakeSegment
{
protected:

    u8 x, y;

public:

    SnakeSegment(u8 newX = 0, u8 newY = 0) :
        x(newX), y(newY) {}

    void drawSegment()
    {
        printToConsole(x, y, SNAKE_COLOR);
    }

    // All segments except head are given the position of the segment in front
    void setSegment(u8 newX, u8 newY)
    {
        x = newX; y = newY;
    }

    // Method only called for snake's head
    void updateSegment(s8 newX, s8 newY)
    {
        x += newX; y += newY;
    }

    inline u8 getSegmentX() const
    {
        return x;
    }

    inline u8 getSegmentY() const
    {
        return y;
    }

    // Returns true if SnakeSegment and another SnakeSegment share coords,
    // used for apple and snake collisions
    bool sameCoords(SnakeSegment other)
    {
        return (x == other.getSegmentX() &&
                y == other.getSegmentY());
    }
};
