#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"
#include "SpriteTransformProvider.h"
#include "FpsController.h"
#include<string.h>
int main()
{
    SpriteTransformProvider stp;
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "DragonTyping");
    sf::Texture Drag;
    Drag.loadFromFile("E:/Game/Dragon2.png");
    Animation flyFail = Animation(stp.flyFail, Drag, 4);
    Animation flySlow = Animation(stp.flySlow, Drag, 6);
    Animation flyNormal = Animation(stp.flyNormal, Drag, 4);
    Animation flyFast = Animation(stp.flyFast, Drag, 2);
    sf::Clock clock;
    FpsController fpsController(30);

    sf::Text text;
    sf::Font font;
    font.loadFromFile("E:/Game/static/Inter-Medium.ttf");
    text.setFont(font);
    /*vector<char> s;
    for (int i = 0; i < 1000; i++)
    {
        s.push_back('a' + rand() % 26);
    }
    int id = 0;
    string x = s[id].toString();
    text.setString(x);*/
    text.setString("abc");
    text.setCharacterSize(16);
    text.setPosition(5.f,0.f);
    text.setFillColor(sf::Color::White);
    while (window.isOpen())
    {
        
        int stamp = clock.getElapsedTime().asMilliseconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            /*else if (event.type == sf::Event::KeyPressed)
            {

                sf::Keyboard::Key key;
                string curChar = text.getString();

                
            }*/
        }
       
        if (fpsController.isNextFrame(stamp))
        {
            text.move(0.f, 1.f);
            window.clear();
           // window.draw(flySlow.getNextSprite());
            window.draw(text);
            window.display();
        }
    }
}
