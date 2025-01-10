#pragma once

#include "CatManager.h"
#include "Nivel.h"
#include "Money.h"
#include "ButtonState.h"
#include "Button.h"
//#include <map>
//#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class Game
{
    sf::RenderWindow m_window;
    sf::Texture m_backgroundTexture;
    sf::Sprite m_backgroundSprite;

    bool m_isGameOver{false};
    int m_incercari{0};
    sf::Clock m_clock;

    std::shared_ptr<Nivel> m_CurrentNivel;
    CatManager m_current_cat;
    std::vector<std::shared_ptr<Documente>> m_currentDocs;
    Money& money = Money::get_money();
    Context m_context;
    //std::map<std::string, sf::Texture> m_textures;
    //void setTimeLimit();
    auto loadBackground() -> void;
    //[[nodiscard]] bool checkPlayerDecision() const;
    [[nodiscard]] bool isGameOver() const;
    void resetGame();

public:
    Game();
    //void loadTextures();

    void draw();
    void Play();
    friend std::ostream& operator<<(std::ostream& os, const Game& game);

    ~Game() = default;
};


