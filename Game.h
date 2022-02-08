#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Scene.h"

class Game
{
	static Scene* scene;

	std::vector<GameObject*> objects;
	sf::RenderWindow* window = nullptr;
	
	sf::Clock clock;

public:
	Game() = delete;
	Game(int width, int height, std::string title);
	void init();
	void start();
	void setFrameRateLimit(unsigned int limit);
	static void setScene(Scene* scene);
};