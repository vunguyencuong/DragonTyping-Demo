#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

class SpriteTransformProvider
{
public:
	SpriteTransformProvider();
	vector<sf::IntRect> flySlow;
	vector<sf::IntRect> flyNormal;
	vector<sf::IntRect> flyFast;
	vector<sf::IntRect> flyFail;
};