#include "../Headers/GameLogic.h"
#include "../Headers/FakeCat.h"
#include "../Headers/Exceptions.h"

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

    // Set the background sprite
    m_backgroundSprite.setTexture(m_backgroundTexture);

    // Scale the background to fit the window size
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
    // if (m_money <= 0)
    // {
    //     std::cout << "Ai ramas fara bani!" << std::endl;
    //     return true;
    // }
    if (m_incercari >= 3)
    {
        std::cout << "Ai lasat 3 oameni in taraPisicilor! Esti concediat" << std::endl;
        return true;
    }
    return false;
}

void Game::resetGame()
{
    money.reset();
    m_incercari = 0;
    m_isGameOver = false;
    m_CurrentNivel->ResetLevel();
    //m_context(std::make_unique<OpenStampRack>());
}

Game::Game()
    : m_window(sf::VideoMode(1200, 900), "Cats apocalypse"), m_current_cat(m_window, "Img/CatShadow.png"), m_context(std::make_unique<OpenStampRack>())
{
    loadBackground();
    m_CurrentNivel = std::make_shared<Nivel>();
}

void Game::draw()
{
    m_window.draw(m_backgroundSprite);

    if (m_current_cat.getCurrentCat())
    {
        m_current_cat.getCurrentCat()->move();
        //m_context.HandleClick(m_window);
        m_current_cat.getCurrentCat()->drawCurrentCat(m_window);
        for (const auto& doc : m_current_cat.getCurrentCat()->getDocumente())
        {
            doc->move(m_window);
            //doc->setText();
            doc->drawDoc(m_window);
        }
        m_context.draw(m_window);
    }
}

void Game::Play()
{
    sf::Clock clock;
    //m_currentDocs = m_current_cat->getDocumente();

    while (m_window.isOpen())
    {
        sf::Event event{};
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();

            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mousePos = m_window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
                m_context.HandleClick(mousePos);
            }
        }
        m_window.clear();

        if (!isGameOver())
        {
            static bool docsCreated = false;
            if (!docsCreated)
            {
                m_current_cat.getCurrentCat()->createCurrentDocs(Nivel::GetLevelNr());
                docsCreated = true; // Avoid re-creating documents
            }
            m_current_cat.checkCat();
            draw();
        }

        //next level trebuie refacut pentru interfata. In next level vom avea un fundal nou ce va afisa banii facuti
        //in acea zi si data curenta => sa fac money class
        //CurrentNivel.NextLevel();
        m_window.display();
    }
}


std::ostream& operator<<(std::ostream& os, const Game& game)
{
    os << "Is Game Over: " << (game.m_isGameOver ? "Yes" : "No");
    return os;
}
