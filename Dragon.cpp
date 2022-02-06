#include "Dragon.h"
#include "SpriteTransformProvider.h"
#include "Typing.h"

Dragon::Dragon()
{
	currentState = State::SLOW;
	sf::Image img;
	img.loadFromFile("E:/Game/Dragon2.png");
	img.createMaskFromColor(sf::Color::White);
	texture.loadFromImage(img);

	animations = std::vector<Animation>(4);

	animations[State::SLOW] = Animation(SpriteTransformProvider::getInstance()->flySlow, texture, 6);
	animations[State::NORMAL] = Animation(SpriteTransformProvider::getInstance()->flyNormal, texture, 4);
	animations[State::FAST] = Animation(SpriteTransformProvider::getInstance()->flyFast, texture, 4);
	animations[State::FAIL] = Animation(SpriteTransformProvider::getInstance()->flyFail, texture, 4);

	relativeSpeed = 0;
	x = 400;
	y = 250;
	w = 150;
	h = 400;
}

void Dragon::update()
{
	if (streak >= 15)
	{
		currentState = State::FAST;
		relativeSpeed = 1;
		if (streak >= 20 && streak < 25) relativeSpeed = -1;
		if (streak >= 25 && streak < 30) relativeSpeed = 1;
		if (streak >= 30 && streak < 35) relativeSpeed = -1;
	}
	if (streak >= 5 && streak < 15)
	{
		currentState = State::NORMAL;
		relativeSpeed = 0;
	}
	if (streak >= 0 && streak < 5)
	{
		currentState = State::SLOW;
		relativeSpeed = -1;
	}
	if (streak < 0)
	{
		currentState = State::FAIL;
		relativeSpeed = -2;
	}

	x += relativeSpeed;
}

void Dragon::render(sf::RenderWindow &window)
{
	sf::Sprite s = animations[currentState].getNextSprite();

	s.setPosition(x, y);
	window.draw(s);
}

void Dragon::notify(Publisher* publisher)
{
	streak = ((Typing*) publisher)->getStreak();
}

void Dragon::setStreak(int streak)
{
	this->streak = streak;
}

bool Dragon::isDead()
{
	return x + w <= 0;
}