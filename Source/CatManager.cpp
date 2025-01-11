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
    if (probability < 0.6)
        return 0;
    return 0;

}

void CatManager::createNewCat(sf::RenderWindow& window, const std::string& fileName)
{
    //fac geturile pentru filenames publice ca sa dau layer peste pisica de baza
    //std::string CurrentCatTexture = "./Cat" + std::to_string(m_currentCat->getColorFilename) + ".png";

    if(decideTypeOfCat())
        m_currentCat = std::make_shared<Cat>(window,fileName);
    else
        m_currentCat = std::make_shared<FakeCat>(window, fileName);

    //m_currentCat->setPosition();
    m_currentCat->createCurrentDocs(Nivel::GetLevelNr());
}

CatManager::CatManager(sf::RenderWindow& window, const std::string& fileName)
{
    createNewCat(window, fileName);
}

std::shared_ptr<Cat> CatManager::getCurrentCat()
{
    return m_currentCat;
}


void CatManager::checkCat() const
{
    if(m_currentCat)
    {
        for(const auto &e: m_currentCat->getDocumente())
            if(e && m_currentCat->IsDocValid())
                m_CatsCount++;
        //createNewCat();
    }
}

void CatManager::nextLevel(sf::RenderWindow& window, const std::string& fileName)
{
    m_CatsCount = 0;
    createNewCat(window, fileName);
}

int CatManager::getCatsCount()
{
    return m_CatsCount;
}
