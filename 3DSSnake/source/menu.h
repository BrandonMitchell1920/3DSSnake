#pragma once

#include <vector>

#include "printing.h"

class Menu
{
private:

    s8 playerCursor = 0;
    const std::vector<std::string> choices = {"Normal", "Dual Snake", "Fast Snake", "Exit"};

    // I got this from a ASCII text generator, I just ignore the periods
    const std::vector<std::string> title = {".######..##....##....###....##....##.########",
                                            "##....##.###...##...##.##...##...##..##......",
                                            "##.......####..##..##...##..##..##...##......",
                                            ".######..##.##.##.##.....##.#####....######..",
                                            "......##.##..####.#########.##..##...##......",
                                            "##....##.##...###.##.....##.##...##..##......",
                                            ".######..##....##.##.....##.##....##.########"};

    void drawMenuBackground()
    {
        drawBackground(TWIDTH, HEIGHT, MENU_BACKGROUND);
    }

    void drawMenuTitle()
    {
        for (u8 i = 0; i < title.size(); i++)
        {
            for (u8 j = 0; j < title[i].size(); j++)
            {
                if (title[i][j] == '#') {printToConsole(2 + j, 2 + i, WHITE);}
            }
        }
        printToConsole(2, 10, MENU_TEXT, "Brandon Mitchell, Jan. 2020");
        printToConsole(TWIDTH / 2, 18, MENU_TEXT, "Score: " + std::to_string(score));
    }

    void drawSelection()
    {
        for (u8 i = 0; i < choices.size(); i++)
        {
            if (i == playerCursor) {printToConsole(TWIDTH / 2, 20 + i, SELECTION, choices[i]);}
            else {printToConsole(TWIDTH / 2, 20 + i, MENU_TEXT, choices[i]);}
        }
    }

public:

    u8 score;

    inline u8 getPlayerCursor() const
    {
        return playerCursor;
    }

    void setPlayerCursor(s8 change)
    {
        playerCursor += change;

        if (playerCursor < 0) {playerCursor = choices.size() - 1;}
        else if (playerCursor > choices.size() - 1) {playerCursor = 0;}

        // No need to redraw everything
        drawSelection();
    }

    void drawEverything()
    {
        drawMenuBackground();
        drawMenuTitle();
        drawSelection();
    }
};
