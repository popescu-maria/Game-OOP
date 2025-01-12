#pragma once

#include "CatManager.h"
#include "ButtonState.h"
#include "Button.h"
//#include <map>
//#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

enum GameStates {
    INTRO = 1,
    NIVEL_1 = 2,
    NIVEL_1_END = 3,
    NIVEL_2 = 4,
    NIVEL_2_END = 5,
    NIVEL_3 = 6,
    GAME_OVER = 7
};

class Game
{
    sf::RenderWindow m_window;
    sf::Texture m_backgroundTexture;
    sf::Sprite m_backgroundSprite;

    bool m_isGameOver{false};
    bool docsChecked = false;
    int m_incercari{0};
    //sf::Clock m_clock;

    //std::shared_ptr<Nivel> m_CurrentNivel;
    CatManager m_current_cat;
    std::vector<std::shared_ptr<Documente>> m_currentDocs;
    Context m_context;
    Context m_RBcontext;
    auto loadBackground() -> void;
    int GameState = INTRO;
    //[[nodiscard]] bool checkPlayerDecision() const;
    void handlePlayerChoice();
    [[nodiscard]] bool isGameOver() const;
    void resetGame();
    void HandleEvents(const sf::Event& event);
    void handleNivelEndInput();
    void drawIntro();
    void drawNivelEnd();
    void draw();

public:
    Game();
    void Play();
    friend std::ostream& operator<<(std::ostream& os, const Game& game);

    ~Game() = default;
};


