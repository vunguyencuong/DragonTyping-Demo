#include "Typing.h"
#include <iostream>

Typing::Typing(std::string passage, std::string fontFile, int fontSize)
{
	x = 500;
	y = 525;

	this->passage = passage;
	this->streak = 0;
	this->id = 0;
	font.loadFromFile(fontFile);
	text.setFont(font);
	text.setCharacterSize(fontSize);
	text << sf::Color::White << passage;

	/*bg2.loadFromFile("E:/Game/mbg7.png");
	bkg2.setTexture(bg2);*/
}

void Typing::update()
{

}

void Typing::render(sf::RenderWindow* window)
{
	/*bkg2.setPosition(0, 500);
	window->draw(bkg2);*/
	text.setPosition(x, y);
	window->draw(text);
}

void Typing::setPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

int Typing::getStreak()
{
	return streak;
}

int Typing::getResults()
{
	return results;
}

void Typing::onKeyPressed(sf::Event& e)
{
	sf::Keyboard::Key key;
	char curChar = passage[id];

	if (curChar == ' ')
		key = sf::Keyboard::Space;
	else if ('a' <= curChar && curChar <= 'z')
		key = sf::Keyboard::Key(curChar - 'a');
	else
	{
		key = sf::Keyboard::Unknown;
	}
	if (sf::Keyboard::isKeyPressed(key))
	{
		text.setCharacterColor(0, id, sf::Color::Green);
		results++;

		if (streak < 0)
			streak = 1;
		else
			streak++;
	}
	else
	{
		text.setCharacterColor(0, id, sf::Color::Red);
		streak = -1;
	}
	id++;

	// update  x position
	x -= 12;

	callNotify();
}