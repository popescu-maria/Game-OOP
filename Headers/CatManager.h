#pragma once

#include <SFML/Graphics.hpp>
#include "Cat.h"

class CatManager
{
private:
    std::shared_ptr<Cat> m_currentCat;
    static int m_CatsCount;

    static int decideTypeOfCat();
    void createNewCat(sf::RenderWindow& window, const std::string& fileName, int nivelNr);
public:
    explicit CatManager(sf::RenderWindow& window, const std::string& fileName, int nivelNr);

    std::shared_ptr<Cat> getCurrentCat();
    void replaceCat(sf::RenderWindow& window, const std::string& fileName, int nivelNr);
    void nextLevel(sf::RenderWindow& window, const std::string& fileName, int nivelNr);
    static int getCatsCount();

};