#include "../Headers/LevelManager.h"
#include "../Headers/Pasaport.h"
#include "../Headers/ID.h"
#include "../Headers/EntryPermit.h"

void LevelProgress::handleGameState(int& gameState, const sf::Event& event, const std::function<void()>& restartGame)
{
    switch (gameState)
    {
    case INTRO:
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
            gameState = NIVEL_1;
        break;

    case NIVEL_1_END:
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
            gameState = NIVEL_2;
        break;
    case NIVEL_2_END:
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
            gameState = NIVEL_3;
        break;
    case GAME_OVER:
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
        {
            gameState = INTRO;
            restartGame();
        }
        break;

    default: break;
    }
}

void LevelProgress::handleCatDocuments(const int levelNr, std::vector<std::shared_ptr<Documente>>& documents,
                                      const std::string& name, int age, char gender, float height, float weight)
{
    documents.clear();

    documents.emplace_back(std::make_shared<Pasaport>(sf::Vector2f(350.f, 305.f), name, "Img/Pasaport.png", age, gender,
                                                      0.35f, 0.35f));

    if (levelNr >= 4)
    {
        documents.emplace_back(std::make_shared<Id>(sf::Vector2f(600.f, 305.f), name, "Img/Id.png", age, height, weight,
                                                    1.2f, 1.2f));
    }
    if (levelNr >= 6)
    {
        documents.emplace_back(
            std::make_shared<EntryPermit>(sf::Vector2f(900.f, 305.f), name, "Img/EntryPermit.png", 0.9f, 0.9f));
    }

    for (const auto& doc : documents)
    {
        doc->createDoc();
    }
}

void LevelProgress::handleLevelLogic(int& gameState, sf::RenderWindow& window, sf::Clock& clock, sf::Time& elapsedTime,
                                    float levelTimeLimit,
                                    const std::function<void()>& drawIntro, const std::function<void()>& draw,
                                    const std::function<void()>& drawNivelEnd,
                                    const std::function<void()>& drawGameOver,
                                 sf::Music& backgroundMusic)
{
    window.clear();

    switch (gameState)
    {
    case INTRO:
        drawIntro();
        clock.restart();
        break;

    case NIVEL_1:
    case NIVEL_2:
    case NIVEL_3:
        if (backgroundMusic.getStatus() == sf::Music::Playing)
            backgroundMusic.pause();
        draw();

        elapsedTime = clock.getElapsedTime();

        if (elapsedTime.asSeconds() >= levelTimeLimit)
        {
            if (gameState == NIVEL_1)
                gameState = NIVEL_1_END;
            else if (gameState == NIVEL_2)
                gameState = NIVEL_2_END;
            else if (gameState == NIVEL_3)
                gameState = GAME_OVER;

            clock.restart();
        }
        break;

    case NIVEL_1_END:
    case NIVEL_2_END:
        if (backgroundMusic.getStatus() == sf::Music::Paused)
            backgroundMusic.play();
        drawNivelEnd();
        clock.restart();
        break;

    case GAME_OVER:
        if (backgroundMusic.getStatus() == sf::Music::Paused)
            backgroundMusic.play();
        drawGameOver();
        break;

    default: break;
    }

    window.display();
}
