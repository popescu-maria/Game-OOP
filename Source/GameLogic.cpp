#include "../Headers/GameLogic.h"
#include "../Headers/FakeCat.h"
//#include <map>
#include <iostream>
#include <ostream>
#include <memory>
#include <random>
//#include <limits>

// void loadTextures()
// {
//     Cat cat("Cat", "Solid", "Black", "Green", 2, 'M');
//     std::string textureFile = cat.getTextureFilename();
//
//     sf::Texture texture;
//     // if (texture.loadFromFile(textureFile)) {
//     //     m_textures[textureFile] = texture;
//     // } else {
//     //     std::cerr << "Failed to load texture: " << textureFile << std::endl;
//     // }
// }

// void Game::setTimeLimit()
// {
//     if (CurrentNivel.GetLevelNr() <= 5)
//     {
//         m_timeLimit = 30.0f;
//     }
//     else if (CurrentNivel.GetLevelNr() <= 7)
//     {
//         m_timeLimit = 20.0f;
//     }
//     else
//     {
//         m_timeLimit = 10.0f;
//     }
// }

std::shared_ptr<Cat> Game::getCurrentCat()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    double probability = dis(gen);
    if (probability < 0.7)
    {
        return std::make_shared<Cat>();
    }
    return std::make_shared<FakeCat>();
}

bool Game::checkPlayerDecision() const
{
    bool IsValid = m_currrent_cat->IsPasaportValid();
    if (IsValid)
    {
        std::cout << "checking.......\n";
        sf::sleep(sf::seconds(2));
        std::cout << "Documentele sunt valide!" << std::endl;
    }
    else
    {
        std::cout << "checking.......\n" << std::endl;
        sf::sleep(sf::seconds(2));
        std::cout << "Documente invalide!" << std::endl;
    }

    return IsValid;
}

bool Game::isGameOver() const
{
    if (m_money <= 0)
    {
        std::cout << "Ai ramas fara bani!" << std::endl;
        return false;
    }
    if (m_incercari >= 3)
    {
        std::cout << "Ai lasat 3 oameni in taraPisicilor! Esti concediat" << std::endl;
        return false;
    }
    return true;
}

void Game::resetGame()
{
    m_money = 500;
    m_incercari = 0;
    m_isGameOver = false;
    CurrentNivel.ResetLevel();
}


void Game::Play()
{
    while (!m_isGameOver)
    {
        CurrentNivel.NextLevel();
        m_currrent_cat = getCurrentCat();
        m_currrent_cat->create_pasaport();
        m_currrent_pasaport = m_currrent_cat->getPasaport();

        std::cout << "Press enter for next cat";
        std::cin.get();

        std::cout << "\nPisica: \n" << *m_currrent_cat << std::endl;
        std::cout << "Pasaportul piscii: \n" << m_currrent_pasaport << std::endl;

        std::cout << "Do you think the cat's passaport is valid? (y/n)  ";

        char choice;
        bool isValid;
        while (true)
        {
            std::cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                isValid = true;
                break;
            }
            if (choice == 'n' || choice == 'N')
            {
                isValid = false;
                break;
            }
            std::cout << "Alege o varianta valida! y or n\n";
        }

        if (checkPlayerDecision() == isValid)
        {
            m_money += 100;
            std::cout << "Ai primit 100 de monede pentru pisici!" << std::endl;
        }
        else
        {
            std::cout << "Ai pierdut 100 de monede!" << std::endl;
            m_money -= 100;
            m_incercari++;
        }
        std::cout << "Monedele tale:               " << m_money << "\n";
        std::cout << "Chirie pentru cutie:        " << "-200" << std::endl;
        m_money -= 200;
        int optMancare;
        std::cout << "Poti alege daca vrei sa cumperi: \n";
        std::cout << "Pliculete pentru pisici:    " << "-100\n";
        std::cout << "Mancare tare:               " << "-50\n";
        std::cout << "Poti alege 1, 2, sau 0 daca nu vrei mancare" << std::endl;

        while (true)
        {
            std::cin >> optMancare;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                optMancare = 0;
            }
            if (optMancare == 0)
            {
                break;
            }
            if (optMancare == 1)
            {
                m_money -= 100;
                break;
            }
            if (optMancare == 2)
            {
                m_money -= 50;
                break;
            }
            std::cout << "Alege o varianta valida! 1, 2 or 0\n";
        }

        m_isGameOver = isGameOver();

        char newGame;
        if (CurrentNivel.GetLevelNr() > 5)
        {
            std::cout << "Ai completat toate nivelele, poti sa te pensionezi!" << std::endl;
            std::cout << "Vrei sa joci un joc nou? (y/n)\n";


            while (true)
            {
                std::cin >> newGame;
                if (newGame == 'y' || newGame == 'Y')
                {
                    resetGame();
                    break;
                }
                if (newGame == 'n' || newGame == 'N')
                {
                    m_isGameOver = false;
                    break;
                }
                std::cout << "Alege o varianta valida! y or n\n";
            }
            m_isGameOver = isGameOver();
        }
    }
    std::cout << "GAME OVER!" << std::endl;
}


std::ostream& operator<<(std::ostream& os, const Game& game)
{
    os << "Money: " << game.m_money << "\nIs Game Over: " << (game.m_isGameOver ? "Yes" : "No");
    return os;
}
