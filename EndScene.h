#pragma once
#include"Scene.h"
#include"string"
#include"BackGround.h"
class EndScene : public Scene
{
	BackGround endBackground;

	sf::Text text1;
	sf::Text text2;
	sf::Text text3;
	sf::Font font;
	std::string s1;
	std::string s2;
	std::string score;

	float counter;

public:
	EndScene(int results);
	virtual void render(sf::RenderWindow* window);
	virtual void onEvent(sf::Event& event);
	virtual void update();
};

