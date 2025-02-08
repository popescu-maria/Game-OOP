#pragma once

#include <functional>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../Headers/Documente.h"
#include "Singleton.h"

enum GameStates
{
    INTRO = 1,
    NIVEL_1 = 2,
    NIVEL_1_END = 3,
    NIVEL_2 = 4,
    NIVEL_2_END = 5,
    NIVEL_3 = 6,
    GAME_OVER = 7
};

class LevelProgress : public Singleton<LevelProgress>
{
    friend class Singleton;
    LevelProgress() = default;

public:
    static void handleGameState(int& gameState, const sf::Event& event, const std::function<void()>& restartGame);
    static void handleCatDocuments(int levelNr, std::vector<std::shared_ptr<Documente>>& documents,
                                   const std::string& name, int age, char gender, float height, float weight);
    static void handleLevelLogic(int& gameState, sf::RenderWindow& window, sf::Clock& clock, sf::Time& elapsedTime,
                                 float levelTimeLimit,
                                 const std::function<void()>& drawIntro, const std::function<void()>& draw,
                                 const std::function<void()>& drawNivelEnd, const std::function<void()>& drawGameOver,
                                 sf::Music& backgroundMusic);
};

