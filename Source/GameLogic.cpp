
#include "../Headers/GameLogic.h"
#include "map";

#include <iostream>
#include <ostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

//NU AM INCARCAT TEXTURES, NU E COMPLET. TREBUIE SA GASESC O METODA SA CORESPUNDA ANTRIBUTELE PISICII CU IMAGINEA
//STRICT PENTRU TEMA 1

Game::Game(const Cat& cat, const Pasaport& pasaport)
    : currentCat(cat), currentPasaport(pasaport), m_window(sf::VideoMode(800, 600), "Cats Apocalypse") {
    //loadTextures();
}

void loadTextures() {
    // Example
    Cat cat("Cat", "Solid", "Black", "Green", 2, 'M');
    std::string textureFile = cat.getTextureFilename();

    sf::Texture texture;
    // if (texture.loadFromFile(textureFile)) {
    //     m_textures[textureFile] = texture;
    // } else {
    //     std::cerr << "Failed to load texture: " << textureFile << std::endl;
    // }
}

void Game::drawCat(const Cat& cat) {
    sf::Sprite sprite;
    std::string textureFile = cat.getTextureFilename();

    if (m_textures.find(textureFile) != m_textures.end()) {
        sprite.setTexture(m_textures[textureFile]);
        m_window.draw(sprite);//Desenez pisica
    } else {
        std::cerr << "Texture not found: " << textureFile << std::endl;
    }
}

bool Game::checkPlayerDecision(const Cat& cat, const Pasaport& pasaport) {
    // logica bazata pe compararea pisicii cu pasaportul
    return true;
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
    os << "Score: " << game.m_score << "\nIs Game Over: " << (game.m_isGameOver ? "Yes" : "No");
    return os;
}