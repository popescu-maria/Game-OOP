#pragma once

#include "Singleton.h"
#include "CatManager.h"
#include "ButtonState.h"
//#include "ProgressBar.h"
#include "Button.h"
#include "Text.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>
#include <memory>
#include <vector>


class Game : public Singleton<Game>
{
    friend class Singleton;
    Game();

    sf::RenderWindow m_window;
    sf::Texture m_backgroundTexture;
    sf::Sprite m_backgroundSprite;
    Text m_introText;
    Text m_startText;
    //sound for when putting the stamp on the document
    sf::SoundBuffer m_StampPressBuffer;
    sf::Sound m_StampPressSound;
    //sound for "next"(in cats language)
    sf::SoundBuffer m_meowBuffer;
    sf::Sound m_meowSound;
    sf::Music m_backgroundMusic;
    //ProgressBar m_progressBar;

    int m_pisiciCorecte = 0;

    bool m_isGameOver{false};
    bool docsChecked = false;
    const float m_levelTimeLimit = 30.0f;

    CatManager m_current_cat;
    std::vector<std::shared_ptr<Documente>> m_currentDocs;
    Context m_context;
    Context m_RBcontext;
    void SetUp();
    auto loadBackground() -> void;
    int GameState;

    [[nodiscard]] bool checkPlayerDecision() const;
    void handlePlayerChoice();
    //[[nodiscard]] bool isGameOver() const;
    void HandleEvents(const sf::Event& event);
    void drawIntro();
    bool introDisplayed = false;
    void drawNivelEnd();
    void drawGameOver();
    void draw();

public:
    void Play();
    friend std::ostream& operator<<(std::ostream& os, const Game& game);

    ~Game() = default;
};


