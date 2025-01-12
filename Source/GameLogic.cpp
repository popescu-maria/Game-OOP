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


// bool Game::checkPlayerDecision() const
// {
//     //const bool IsValid = m_current_cat.getCurrentCat()->IsPasaportValid();
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_real_distribution distrib(0.0f, 2.5f);
//
//     if (IsValid)
//     {
//         const float secNr = distrib(gen);
//         std::cout << "checking.......\n";
//         sf::sleep(sf::seconds(secNr));
//         std::cout << "Documentele sunt valide!" << std::endl;
//     }
//     else
//     {
//         std::cout << "checking.......\n" << std::endl;
//         sf::sleep(sf::seconds(2));
//         std::cout << "Documente invalide!" << std::endl;
//     }
//
//     return IsValid;
// }

bool Game::isGameOver() const
{
    if (GameState == 7)
        return true;
    return false;
}

void Game::resetGame()
{
    m_incercari = 0;
    m_isGameOver = false;
    GameState = 1;
}

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

void Game::handleNivelEndInput()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
        {
            GameState++;
        }
        else if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }
    }
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
                if (auto* pasaport = dynamic_cast<Pasaport*>(doc.get()))
                {
                    if (pasaport->getBounds().contains(mousePos))
                    {
                        if (dynamic_cast<EntryGranted*>(m_context.getCurrentState()) ||
                            dynamic_cast<EntryDenied*>(m_context.getCurrentState()))
                        {
                            std::cout << "\nam ales daca e bun sau fals";
                            //m_current_cat.getCurrentCat()->clearDocuments();
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
    m_window.display();

}

void Game::drawNivelEnd()
{
    m_window.clear(sf::Color::Black);
    m_window.display();

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
            case NIVEL_2_END:
                handleNivelEndInput();
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
                break;


            case NIVEL_1:
            case NIVEL_2:
            case NIVEL_3:
                draw();
                if (docsChecked)
                {
                    GameState++;
                    docsChecked = false;
                }
                break;

            case NIVEL_1_END:
            case NIVEL_2_END:
                drawNivelEnd();
                break;

            case GAME_OVER:
            m_window.clear(sf::Color::Black);
                // Draw game over screen call gameoverdraw
                m_window.display();
                break;

            default: break;
            }
        }
        m_window.display();
    }
}


std::ostream& operator<<(std::ostream& os, const Game& game)
{
    os << "Is Game Over: " << (game.m_isGameOver ? "Yes" : "No");
    return os;
}
