#pragma once

#include <SFML/Graphics.hpp>
#include "Cat.h"
#include "Nivel.h"

class CatManager
{
private:
    //sf::RenderWindow& m_window;
    std::shared_ptr<Cat> m_currentCat;
    static int m_CatsCount;

    //decides if the next cat is a real(1) or a fake(0) cat
    static int decideTypeOfCat();
    void createNewCat(sf::RenderWindow& window, const std::string& fileName);
public:
    explicit CatManager(sf::RenderWindow& window, const std::string& fileName);

    std::shared_ptr<Cat> getCurrentCat();
    void replaceCat(sf::RenderWindow& window, const std::string& fileName);
    void nextLevel(sf::RenderWindow& window, const std::string& fileName);
    static int getCatsCount();

};