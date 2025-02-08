#include <random>

#include "../Headers/CatManager.h"
#include "../Headers/FakeCat.h"

int CatManager:: m_CatsCount = 0;


int CatManager::decideTypeOfCat()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    double probability = dis(gen);
    if (probability < 0.5)
        return 1;
    return 0;

}

void CatManager::createNewCat(sf::RenderWindow& window, const std::string& fileName, int nivelNr)
{

    if(decideTypeOfCat())
        m_currentCat = std::make_shared<Cat>(window,fileName);
    else
        m_currentCat = std::make_shared<FakeCat>(window, fileName);

    m_currentCat->createCurrentDocs(nivelNr);
}

CatManager::CatManager(sf::RenderWindow& window, const std::string& fileName, int nivelNr)
{
    createNewCat(window, fileName, nivelNr);
}

std::shared_ptr<Cat> CatManager::getCurrentCat() const
{
    return m_currentCat;
}
void CatManager::replaceCat(sf::RenderWindow& window, const std::string& fileName, int nivelNr)
{
    createNewCat(window, fileName, nivelNr);
}

void CatManager::increaseCatsCount()
{
    m_CatsCount++;
}

int CatManager::getCatsCount()
{
    return m_CatsCount;
}

void CatManager::resetCatsCount()
{
    m_CatsCount = 0;
}
