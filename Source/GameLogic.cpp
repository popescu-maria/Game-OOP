
#include "../Headers/GameLogic.h"

#include <map>
#include <iostream>
#include <ostream>
#include <limits>

// void loadTextures()
// {
//     // Example
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

void Game::setTimeLimit() {
    if (CurrentNivel.GetLevelNr() <= 5) {
        m_timeLimit = 30.0f;
    } else if (CurrentNivel.GetLevelNr() <= 7) {
        m_timeLimit = 20.0f;
    } else {
        m_timeLimit = 10.0f;
    }
}

bool Game::checkPlayerDecision(const Pasaport& pasaport)
{
    bool IsValid = pasaport.IsPasaportValid();
    if(IsValid)
    {
        std::cout << "checking......." << std::endl;
        sf::sleep(sf::seconds(2));
        std::cout << "Documentele sunt valide!\n";
        m_money += 100;
    }
    else
    {
    std::cout << "checking......." << std::endl;
    sf::sleep(sf::seconds(2));
    std::cout << "Documente invalide!" << " Un intrus de tip uman a patruns in tara pisicilor" << std::endl;
    m_money -= 100;
    m_incercari++;
    }

    return IsValid;
}

void Game::Play()
{
    //while(!m_isGameOver())

}


std::ostream& operator<<(std::ostream& os, const Game& game)
{
    os << "Money: " << game.m_money << "\nIs Game Over: " << (game.m_isGameOver ? "Yes" : "No");
    return os;
}