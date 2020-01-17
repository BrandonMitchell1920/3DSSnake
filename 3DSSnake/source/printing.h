#pragma once

#include <iostream>
#include <fstream>
#include <string>

// ANSI escape codes
const std::string SNAKE_COLOR      = "\x1b[44;34m";
const std::string APPLE_COLOR      = "\x1b[41;31m";
const std::string BACKGROUND_COLOR = "\x1b[42;32m";
const std::string SELECTION        = "\x1b[47;36m";
const std::string MENU_TEXT        = "\x1b[46;37m";
const std::string MENU_BACKGROUND  = "\x1b[46;36m";
const std::string WHITE            = "\x1b[47;37m";
const std::string CLEAR_COLOR      = "\x1b[0m";

const u8 TWIDTH = 50;
const u8 BWIDTH = 40;
const u8 HEIGHT = 30;

const u8 INIT_SNAKE_LEN = 5;

u8 getRand(u8 num)
{
	return (rand() % num);
}

void printToConsole(u8 x, u8 y, std::string color, std::string sentence = " ")
{
	std::string position = "\x1b[" + std::to_string(y + 1) + ";" + std::to_string(x + 1) + "H";
	std::cout <<  position + color + sentence;
	std::cout.flush();
}

void drawBackground(u8 width, u8 height, std::string color)
{
	for (u8 i = 0; i < width; i++)
	{
		for (u8 j = 0; j < height; j++)
		{
			printToConsole(i, j, color);
		}
	}
}

// Max snake size is 255, so max score is 255
u8 loadScore()
{
    u8 score = 0;

    std::ifstream inFile;

    inFile.open("sdmc:/SCORE.hiss", std::ifstream::in);

    // inFile  is NULL if it doesn't exist or can't be opened
    if (inFile)
    {
        inFile >> score;
        inFile.close();
    }

    return score;
}

void saveScore(u8 score)
{
    std::fstream outFile;

    outFile.open("sdmc:/SCORE.hiss", std::ofstream::out);

    // Overwrite
    if (outFile)
    {
        outFile << score;
        outFile.close();
    }
}
