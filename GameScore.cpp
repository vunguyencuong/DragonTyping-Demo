#include "GameScore.h"
#include"Typing.h"
#include"string"
#include"iostream"
#include"string"
#include"fstream"
GameScore::GameScore()
{
    
    font.loadFromFile("E:/Game/static/Inter-Medium.ttf");
    text.setFont(font);
    text.setCharacterSize(50);

    results = 0;
}

void GameScore::saveScore()
{
    std::ifstream readFile;
    readFile.open("E:/Game/HighScore.txt");

    if (readFile.is_open())
    {
        while (!readFile.eof())
        {
            readFile >> highScore;
        }
    }
    readFile.close();

    std::ofstream writeFile("E:/Game/HighScore.txt");

    if (writeFile.is_open())
    {
        if (results > highScore)
        {
            highScore = results;
        }
        writeFile << highScore;
    }
    writeFile.close();
}

void GameScore::render(sf::RenderWindow* window)
{
    std:: string score = std::to_string(results);
    
    text.setString(score);

	window->draw(text);
}

void GameScore::notify(Publisher* publisher)
{
	results = ((Typing*)publisher)->getResults();
}

int GameScore::getResults()
{
    return results;
}
