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

    [[nodiscard]] std::shared_ptr<Cat> getCurrentCat() const;
    void replaceCat(sf::RenderWindow& window, const std::string& fileName, int nivelNr);
    static void increaseCatsCount();
    static int getCatsCount();
    static void resetCatsCount();
};