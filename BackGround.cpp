#include "BackGround.h"

void BackGround::move(float speed)
{
	sf::Vector2f oldPos = bg1.getPosition();
	bg1.setPosition(oldPos.x - speed, oldPos.y);

	oldPos = bg2.getPosition();
	bg2.setPosition(oldPos.x - speed, oldPos.y);
}

BackGround::BackGround(string path)
{
	sf::Texture bg;
	bg.loadFromFile(path);

	bg1.setTexture(bg);
	bg2.setTexture(bg);


	//dim = sf::Vector2f(bg1.getLocalBounds().width, bg1.getLocalBounds().height);

	//temp = bg1;
	//bg1.setPosition(0, 0);
	//bg2.setPosition(1000, 0);
}

sf::Sprite BackGround::background(float speed)
{
	/*move(speed);

	if (bg1.getPosition().x <= -dim.x)
	{
		temp = bg2;
		bg1.setPosition(1000.f, bg1.getPosition().y);
	}

	if (bg2.getPosition().x <= -dim.x)
	{
		temp = bg1;
		bg2.setPosition(1000.f, bg2.getPosition().y);
	}*/

	return bg1;
}
