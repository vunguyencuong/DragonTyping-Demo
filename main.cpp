#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"
#include "SpriteTransformProvider.h"
#include "PassageProvider.h"
#include "FpsController.h"
#include "RichText.h"
#include "BackGround.h"
#include "Dragon.h"
#include "Observer.h"

#include<string.h>
#include "Typing.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "DragonTyping");

    sf::Clock clock;
    FpsController fpsController(50);

    sf::Texture bg2;
    bg2.loadFromFile("E:/Game/mbg7.png");
    sf::Sprite bkg2;
    bkg2.setTexture(bg2);
    bkg2.setPosition(0, 500);

    std::vector<GameObject*> objects;
    BackGround *bkg = new BackGround("E:/Game/BackGround.png", 2.f);
    Dragon *dragon = new Dragon();
    Typing *typing = new Typing(PassageProvider::getInstance()->random(), "E:/Game/static/Inter-Medium.ttf", 25);

    typing->addSubscriber((Subscriber*) dragon);

    objects.push_back(bkg);
    objects.push_back(dragon);
    objects.push_back(typing);
    
    while (window.isOpen())
    {
        int stamp = clock.getElapsedTime().asMilliseconds();
        sf::Event event;
        string score = to_string(typing->getResults());
        sf::Text num;
        sf::Font f;
        f.loadFromFile("E:/Game/static/Inter-Medium.ttf");
        num.setFont(f);
        num.setCharacterSize(50);
        num.setString(score);


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                typing->onKeyPressed(event);
            }
        }
        

        if (fpsController.isNextFrame(stamp))
        {
            window.clear();
            window.draw(bkg2);
            for (int i = 0; i < objects.size(); i++)
            {
                objects[i]->update();
            }

            if (dragon->isDead())
            {
                window.close();
            }
            for (int i = 0; i < objects.size(); i++)
            {
                objects[i]->render(window);
            }
            window.draw(num);
            window.display();
        }
    }
}
