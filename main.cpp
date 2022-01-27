#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"
#include "SpriteTransformProvider.h"
#include "FpsController.h"
#include "RichText.h"
#include "BackGround.h"
#include<string.h>
int main()
{
    SpriteTransformProvider stp;
    sf::RenderWindow window(sf::VideoMode(1000, 600), "DragonTyping");
    sf::Texture Drag;
    sf::Image img;
    img.loadFromFile("E:/Game/Dragon2.png");
    img.createMaskFromColor(sf::Color::White);
    Drag.loadFromImage(img);
   
    Animation flyFail = Animation(stp.flyFail, Drag, 4);
    Animation flySlow = Animation(stp.flySlow, Drag, 6);
    Animation flyNormal = Animation(stp.flyNormal, Drag, 4);
    Animation flyFast = Animation(stp.flyFast, Drag, 2);
    sf::Clock clock;
    FpsController fpsController(30);

    sfe::RichText text;
    sf::Font font;
    font.loadFromFile("E:/Game/static/Inter-Medium.ttf");
    text.setFont(font);
    int id = 0;
    string str = "for start below study open very always change why their another leave write large tell out black time want grow use run high watch add sea again may enough book something no in once number by had country left grow side call why mother study before group had or him an over live or being help children light few did example me life such write grow high work once upon her make he example as those big had could paper change its two there not put give name how write";
    text << sf::Color::White << str;

    text.setCharacterSize(20);
    text.setPosition(300.f,500.f);

    int countStreak = 0;
    int result = 0;

    BackGround bkg("E:/Game/BackGround.png");
    
    while (window.isOpen())
    {
        
        int stamp = clock.getElapsedTime().asMilliseconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                sf::Keyboard::Key key;
                char curChar = str[id];

                if (curChar == ' ')
                    key = sf::Keyboard::Space;
                else if ('a' <= curChar && curChar <= 'z')
                    key = sf::Keyboard::Key(curChar - 'a');
                else
                    key = sf::Keyboard::Unknown;
                    

                if (sf::Keyboard::isKeyPressed(key))
                {
                    text.setCharacterColor(0, id, sf::Color::Green);
                    countStreak++;
                    result++;
                }
                else
                {
                    text.setCharacterColor(0, id, sf::Color::Red);
                    countStreak = 0;
                }
                

                id++;
            }
        }
        

        if (fpsController.isNextFrame(stamp))
        {
            sf::Sprite memFail = flyFail.getNextSprite();
            sf::Sprite memSlow = flySlow.getNextSprite();
            sf::Sprite memNormal = flyNormal.getNextSprite();
            sf::Sprite memFast = flyFast.getNextSprite();
            memNormal.setPosition(400.f, 250.f);
            memFail.setPosition(400.f, 250.f);
            memFast.setPosition(400.f, 250.f);
            memSlow.setPosition(400.f, 250.f);
           // text.move(-1.f, 0.f);
            window.clear();
            window.draw(bkg.bg1);
            
            text.move(-(countStreak + 5) / 10.f, 0.f);
            if (countStreak > 10) text.move(-3/2.0f, 0.f);
            if (text.getPosition().x + id * 8.15 < 0)
            {
                std::cout << "over screen" << std::endl;
                countStreak = -5;
            }

            if (countStreak >= 10)
            {
                window.draw(memFast);
            }
            if (countStreak >= 5 && countStreak < 10) window.draw(memNormal);
            if (countStreak < 5 && countStreak != 0 ) window.draw(memSlow);
            if (countStreak == 0) window.draw(memFail);

            window.draw(text);
            window.display();
        }
    }
}
