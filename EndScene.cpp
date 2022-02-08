#include "EndScene.h"
#include "Game.h"
#include "PlayScene.h"
#include <iostream>

EndScene::EndScene(int results)
{
	font.loadFromFile("E:/Game/static/Inter-Medium.ttf");
	//font.loadFromFile("E:/Game/Haedus-nRGn4.ttf");
	text1.setFont(font);
	text1.setCharacterSize(35);
	text2.setFont(font);
	text2.setCharacterSize(30);
	text3.setFont(font);
	text3.setCharacterSize(25);
	s1 = "Your Score";
	s2 = "Press SPACE to replay";
	score = std::to_string(results);
	text1.setString(s1);
	text1.setPosition(410, 250);
	text2.setString(score);
	text2.setPosition(495, 300);
	text3.setString(s2);
	text3.setPosition(365, 450);

	counter = 20;
}

void EndScene::render(sf::RenderWindow* window)
{
	if (counter > 0)
		counter--;
	endBackground.setSpeed(0.5 + counter / 20.0);
	endBackground.render(window);
	window->draw(text1);
	window->draw(text2);
	window->draw(text3);
}

void EndScene::update()
{
	endBackground.update();
}

void EndScene::onEvent(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			Game::setScene(new PlayScene());
}
