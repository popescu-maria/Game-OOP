#include "../Headers/GameLogic.h"
#include "../Headers/FakeCat.h"
#include "../Headers/Exceptions.h"
#include "../Headers/RuleBook.h"
#include "../Headers/Pasaport.h"

#include <iostream>
#include <ostream>
#include <memory>
#include <random>
#include <chrono>

void Game::loadBackground()
{
    if (!m_backgroundTexture.loadFromFile("Img/background.png"))
    {
        throw missingTexture("Texture not found!\n");
        // End the game if the background cannot be loaded
    }

    m_backgroundSprite.setTexture(m_backgroundTexture);

    const sf::Vector2u windowSize = m_window.getSize();
    const sf::Vector2u textureSize = m_backgroundTexture.getSize();
    m_backgroundSprite.setScale(
        static_cast<float>(windowSize.x) / static_cast<float>(textureSize.x),
        static_cast<float>(windowSize.y) / static_cast<float>(textureSize.y)
    );
}


bool Game::checkPlayerDecision() const
{
    bool isValid = m_current_cat.getCurrentCat()->IsDocValid();
    bool playerDecision = false;
    if (dynamic_cast<EntryGranted*>(m_context.getCurrentState()))
    {
        playerDecision = true;
    }
    else if (dynamic_cast<EntryDenied*>(m_context.getCurrentState()))
    {
        playerDecision = false;
    }
    if (isValid == playerDecision)
        return true;
    return false;
}

bool Game::isGameOver() const
{
    if (GameState > 7)
        return true;
    return false;
}

// void Game::resetGame()
// {
//     m_incercari = 0;
//     m_isGameOver = false;
//     GameState = 1;
// }

Game::Game()
    : m_window(sf::VideoMode(1200, 900), "Cats apocalypse"), m_current_cat(m_window, "Img/CatShadow.png", 2)
      , m_context(std::make_unique<OpenStampRack>()), m_RBcontext(std::make_unique<ClosedRB>("Img/RuleBook.png"))
{
}

void Game::handlePlayerChoice()
{
    m_current_cat.getCurrentCat()->clearDoc();
    m_context.TransitionTo(std::make_unique<OpenStampRack>());
    m_current_cat.getCurrentCat()->leave();
}


void Game::HandleEvents(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        sf::Vector2f mousePos = m_window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});

        m_context.HandleClick(mousePos);
        m_RBcontext.HandleClick(mousePos);

        if (m_current_cat.getCurrentCat())
        {
            for (const auto& doc : m_current_cat.getCurrentCat()->getDocumente())
            {
                if (const auto* pasaport = dynamic_cast<Pasaport*>(doc.get()))
                {
                    if (pasaport->getBounds().contains(mousePos))
                    {
                        if (dynamic_cast<EntryGranted*>(m_context.getCurrentState()) ||
                            dynamic_cast<EntryDenied*>(m_context.getCurrentState()))
                        {
                            if (checkPlayerDecision())
                                m_pisiciCorecte++;
                            //std::cout << "\n" << m_pisiciCorecte << " " << m_pisiciTotale;
                            CatManager::increaseCatsCount();
                            handlePlayerChoice();
                            docsChecked = true;
                        }
                        break;
                    }
                }
            }
        }
    }
    if (docsChecked && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::N)
    {
        m_current_cat.replaceCat(m_window, "Img/CatShadow.png", GameState);
        docsChecked = false;
    }
}

void Game::drawIntro()
{
    m_window.clear(sf::Color::Black);
    if (!introDisplayed)
    {
        TextBuilder builder;

        m_introText = builder.setString(
                                 "Cats Apocalypse\n\n"
                                 "Regulile jocului:\n"
                                 "Da click pe butonul din dreapta pentru a alege ce stampila vrei sa pui pe pasaport, \n"
                                 "apoi apasa pe pasaport pentru a finaliza actiunea.\n\n"
                                 "                               Press N for next Cat!!!\n\n"
                                 "Apasa pe butonul de regulament (plasat stanga jos) pentru a te uita la atributele valide \n"
                                 "si a le compara cu cele de pe documente! Pentru a inchide regulamnentul la loc da click pe el.\n\n"
                                 "Atentie la pasapoarte! Nu lasati pisicile cu pasapoarte expirate sa intre in TaraPisicilor!\n\n"
                             )
                             .setSize(20)
                             .setCol(sf::Color::White)
                             .build();

        m_startText = builder.setString("Press enter to start!")
                             .setSize(40)
                             .setCol(sf::Color::Green)
                             .build();

        const sf::Vector2u windowSize = m_window.getSize();
        const sf::FloatRect introTextBounds = m_introText.getText().getGlobalBounds();
        const sf::FloatRect startTextBounds = m_startText.getText().getGlobalBounds();

        const float introX = (windowSize.x - introTextBounds.width) / 2.0f;
        const float introY = (windowSize.y - introTextBounds.height) / 2.0f;
        m_introText.getText().setPosition(introX, introY);

        const float startX = (windowSize.x - startTextBounds.width) / 2.0f;
        const float startY = introY + introTextBounds.height + 10.0f;
        m_startText.getText().setPosition(startX, startY);

        introDisplayed = true;
    }

    m_window.draw(m_introText.getText());
    m_window.draw(m_startText.getText());
}

void Game::drawNivelEnd()
{
    m_window.clear(sf::Color::Black);
    TextBuilder builder;

    Text totalCatsText = builder.setString(
                                    "Total pisici evaluate: " + std::to_string(CatManager::getCatsCount()))
                                .setSize(40)
                                .setCol(sf::Color::White)
                                .build();

    Text correctCatsText = builder.setString(
                                      "Pisici evaluate corect: " + std::to_string(m_pisiciCorecte))
                                  .setSize(40)
                                  .setCol(sf::Color::Green)
                                  .build();

    const sf::Vector2u windowSize = m_window.getSize();
    const sf::FloatRect totalCatsBounds = totalCatsText.getText().getGlobalBounds();
    const sf::FloatRect correctCatsBounds = correctCatsText.getText().getGlobalBounds();

    totalCatsText.getText().setPosition((windowSize.x - totalCatsBounds.width) / 2.0f, windowSize.y / 3.0f);
    correctCatsText.getText().setPosition((windowSize.x - correctCatsBounds.width) / 2.0f, windowSize.y / 2.0f);

    m_window.draw(totalCatsText.getText());
    m_window.draw(correctCatsText.getText());
}

void Game::drawGameOver()
{
    m_window.clear(sf::Color::Black);
    TextBuilder builder;

    Text totalPointsText = builder.setString(
                                      "Puncte totale acumulate: " + std::to_string(m_pisiciCorecte))
                                  .setSize(40)
                                  .setCol(sf::Color::Green)
                                  .build();

    Text totalCatsCheckedText = builder.setString(
                                           "Total pisici evaluate: " + std::to_string(CatManager::getCatsCount()))
                                       .setSize(30)
                                       .setCol(sf::Color::White)
                                       .build();
    Text gameOverText = builder.setString("GAME OVER!")
                               .setSize(60)
                               .setCol(sf::Color::Red)
                               .build();

    const sf::Vector2u windowSize = m_window.getSize();

    const sf::FloatRect pointsBounds = totalPointsText.getText().getGlobalBounds();
    const sf::FloatRect catsBounds = totalCatsCheckedText.getText().getGlobalBounds();
    const sf::FloatRect gameOverBounds = gameOverText.getText().getGlobalBounds();

    const float centerX = static_cast<float>(windowSize.x) / 2.0f;

    totalPointsText.getText().setPosition(centerX - pointsBounds.width / 2.0f, windowSize.y / 3.0f);
    totalCatsCheckedText.getText().setPosition(centerX - catsBounds.width / 2.0f, windowSize.y / 2.5f);
    gameOverText.getText().setPosition(centerX - gameOverBounds.width / 2.0f, windowSize.y / 2.0f);

    m_window.draw(totalPointsText.getText());
    m_window.draw(totalCatsCheckedText.getText());
    m_window.draw(gameOverText.getText());
}


void Game::draw()
{
    loadBackground();
    m_window.draw(m_backgroundSprite);

    if (m_current_cat.getCurrentCat())
    {
        m_current_cat.getCurrentCat()->drawCurrentCat(m_window);
        for (const auto& doc : m_current_cat.getCurrentCat()->getDocumente())
        {
            doc->move(m_window);
        }
        m_context.draw(m_window);
        m_RBcontext.draw(m_window);
    }
}

void Game::Play()
{
    sf::Clock clock;
    sf::Time elapsedTime;

    while (m_window.isOpen())
    {
        sf::Event event{};
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
            switch (GameState)
            {
            case INTRO:
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                    GameState = NIVEL_1;
                break;

            case NIVEL_1_END:
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                    GameState = NIVEL_2;
                break;
            case NIVEL_2_END:
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                    GameState = NIVEL_3;
                break;

            case NIVEL_1:
            case NIVEL_2:
            case NIVEL_3:
                HandleEvents(event);
                break;

            default: break;
            }
        }

        m_window.clear();

        if (!isGameOver())
        {
            switch (GameState)
            {
            case INTRO:
                drawIntro();
                clock.restart();
                break;

            case NIVEL_1:
            case NIVEL_2:
            case NIVEL_3:
                draw();

                elapsedTime = clock.getElapsedTime();

                if (elapsedTime.asSeconds() >= m_levelTimeLimit)
                {
                    if (GameState == NIVEL_1)
                        GameState = NIVEL_1_END;
                    else if (GameState == NIVEL_2)
                        GameState = NIVEL_2_END;
                    else if (GameState == NIVEL_3)
                        GameState = GAME_OVER;

                    clock.restart();
                }
                break;

            case NIVEL_1_END:
            case NIVEL_2_END:
                drawNivelEnd();
                clock.restart();
                break;

            case GAME_OVER:
                drawGameOver();
                break;

            default: break;
            }
        }
        m_window.display();
    }
}

// void Game::calcPisiciTotale(const int pisiciZi) { m_pisiciTotale += pisiciZi; }
//
// void Game::calcScorFinal(const int ScorZi) { m_scor += ScorZi;}

std::ostream& operator<<(std::ostream& os, const Game& game)
{
    os << "Is Game Over: " << (game.m_isGameOver ? "Yes" : "No");
    return os;
}
