#pragma once

#include "Cat.h"
#include "Nivel.h"

//#include <map>
//#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Game
{
    bool m_isGameOver{false};
    int m_money{500};
    int m_incercari{0};
    Nivel CurrentNivel;
    sf::Clock m_clock;
    float m_timeLimit;

    Cat m_currrent_cat;
    Pasaport m_currrent_pasaport;
    //std::map<std::string, sf::Texture> m_textures;
    //sf::RenderWindow m_window;
    void setTimeLimit();
    bool checkPlayerDecision(const Pasaport& pasaport);

public:
    Game() = default;
    //void loadTextures();

    bool checkPlayerDecision();
    void Play();

    friend std::ostream& operator<<(std::ostream& os, const Game& game);

    void resetGame();
};


