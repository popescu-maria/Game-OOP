#pragma once

#include "Cat.h"
#include "Pasaport.h"
#include "map"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Game
{
    bool m_isGameOver{false};
    int m_score{0};

    std::map<std::string, sf::Texture> m_textures;
    sf::RenderWindow m_window;

    Cat currentCat;
    Pasaport currentPasaport;

    Cat generateRandomCat();
    bool checkPlayerDecision(const Cat& cat, const Pasaport& pasaport);

public:
    Game(const Cat& cat, const Pasaport& pasaport);

    void loadTextures();
    void drawCat(const Cat& cat);

    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};


