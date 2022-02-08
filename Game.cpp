#include "Game.h"
#include "StartScene.h"
#include "EndScene.h"

Scene* Game::scene = nullptr;

Game::Game(int width, int height, std::string title)
{
	this->window = new sf::RenderWindow(sf::VideoMode(width, height), title);
}

void Game::init()
{
	scene = (Scene*) new StartScene();
}

void Game::start()
{
	sf::Event event;

	int i = 0;
	while (window->isOpen())
	{
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
			else if (scene)
				scene->onEvent(event);
		}

		if (scene)
		{
			window->clear();

			scene->update();
			scene->render(window);

			window->display();
		}
	}
}


void Game::setFrameRateLimit(unsigned int limit)
{
	window->setFramerateLimit(limit);
}

void Game::setScene(Scene* scene)
{
	Game::scene = scene;
}


