#pragma once
#include<SFML/Graphics.hpp>
#include<string>
using namespace std;
class BackGround
{
	sf::Vector2f dim;
	
	sf::Sprite temp;
	void move(float speed);
public :
	BackGround(string path);
	sf::Sprite bg1;
	sf::Sprite bg2;
	sf::Sprite background(float speed);
};

