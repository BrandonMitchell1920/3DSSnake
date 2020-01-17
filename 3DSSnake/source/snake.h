#pragma once

#include <vector>

#include "snakesegment.h"

class Snake
{
private:

    std::vector<SnakeSegment> snake;
    u8 width;

    void updateSnakeHead(s8 xIncre, s8 yIncre)
    {
        snake[snake.size() - 1].updateSegment(xIncre, yIncre);
    }

    // Checks that the snake's head is not colliding with its body
    bool isTheSnakeEatingItself()
    {
        for (u8 i = 0; i < snake.size() - 1; i++)
        {
            if (i == 0) {continue;}
            else if (snake[i].sameCoords(snake[snake.size() - 1])) {return true;}
        }
        return false;
    }

    // Checks that the snake head is in the play area
    bool notInsidePlayArea()
    {
        return (snake[snake.size() - 1].getSegmentX() > width  - 1 ||
                snake[snake.size() - 1].getSegmentY() > HEIGHT - 1);
    }

    // Removes the blue trail the snake would leave otherwise
    void clearTrail()
    {
        printToConsole(snake[0].getSegmentX(), snake[0].getSegmentY(), BACKGROUND_COLOR);
    }

public:

    Snake(u8 newWidth)
    {
        width = newWidth;

        for (u8 i = 0; i < INIT_SNAKE_LEN + 1; i++)
        {
            snake.insert(snake.begin(), SnakeSegment(width / 2 - i, HEIGHT / 2));
        }
    }

    void addSegment()
    {
        snake.insert(snake.begin(), SnakeSegment(snake[0].getSegmentX(), snake[0].getSegmentY()));
    }

    void drawTheWholeDarnSnake()
    {
        for (u8 i = 0; i < snake.size(); i++)
        {
            snake[i].drawSegment();
        }
        clearTrail();
    }

    void updateTheSnake(s8 xIncre, s8 yIncre)
    {
        for (u8 i = 0; i < snake.size(); i++)
        {
            if (i == snake.size() - 1) {updateSnakeHead(xIncre, yIncre);}
            else {snake[i].setSegment(snake[i + 1].getSegmentX(), snake[i + 1].getSegmentY());}
        }
    }

    bool areYouDeadYet()
    {
        return (isTheSnakeEatingItself() || notInsidePlayArea());
    }

    inline const std::vector<SnakeSegment>& getSnake() const
    {
        return snake;
    }

    inline SnakeSegment getSnakeHead() const
    {
        return snake[snake.size() - 1];
    }

    // Clears trail first so it doesn't cover the head if head nearby
    void drawSnakeHead()
    {
        clearTrail();
        snake[snake.size() - 1].drawSegment();
    }
};
