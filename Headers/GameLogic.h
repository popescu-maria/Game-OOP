#pragma once

#include "Cat.h"
#include "Nivel.h"

//#include <map>
//#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>


class Game
{
    bool m_isGameOver{false};
    int m_money{500};
    int m_incercari{0};
    Nivel CurrentNivel;
    sf::Clock m_clock;
    //float m_timeLimit;

    std::shared_ptr<Cat> m_currrent_cat;
    Pasaport m_currrent_pasaport;
    //std::map<std::string, sf::Texture> m_textures;
    //sf::RenderWindow m_window;
    //void setTimeLimit();
    static std::shared_ptr<Cat> getCurrentCat();
    [[nodiscard]] bool checkPlayerDecision() const;
    [[nodiscard]] bool isGameOver() const;
    void resetGame();

public:
    Game() = default;
    //void loadTextures();

    void Play();
    friend std::ostream& operator<<(std::ostream& os, const Game& game);

    ~Game() = default;
};


