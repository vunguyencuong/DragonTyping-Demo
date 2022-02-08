#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main()
{
    Game game(1000, 600, "Dragon Typing");

    game.init();

    game.setFrameRateLimit(60);

    game.start();
}