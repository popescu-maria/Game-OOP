#include <vector>
#include <random>
#include <fstream>

#include "../Headers/Pasaport.h"
#include "../Headers/ID.h"
#include "../Headers/Cat.h"
#include "../Headers/EntryPermit.h"
#include "../Headers/Exceptions.h"
#include "../Headers/LevelManager.h"

std::vector<std::string> Cat::s_names = Cat::loadNamesFromFile("cat_names.txt");

void Cat::generateRandomCat()
{
    if (s_names.empty())
    {
        throw std::runtime_error("No names loaded from file.");
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> nameDist(0, s_names.size() - 1);
    std::uniform_int_distribution<> ageDist(1, 18);
    std::uniform_int_distribution<> genderDist(0, 1);
    std::uniform_real_distribution<> heightDist(20.0, 40.0);
    std::uniform_real_distribution<> weightDist(2.0, 7.0);

    m_name = s_names[nameDist(gen)];
    m_age = ageDist(gen);
    m_gender = genderDist(gen) == 0 ? 'M' : 'F';
    m_height = heightDist(gen);
    m_weight = weightDist(gen);

}

std::vector<std::string> Cat::loadNamesFromFile(const std::string& filename)
{
    std::vector<std::string> names;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open())
    {
        throw std::runtime_error("Could not open names file.");
    }

    while (std::getline(file, line))
    {
        if (!line.empty())
        {
            names.push_back(line);
        }
    }

    file.close();
    return names;
}

// std::string Cat::getColorFilename() const { return "Cat_" + m_color + ".png"; }
// std::string Cat::getPatternsFilename() const { return "Cat_" + m_patterns + ".png"; }
// std::string Cat::getColorOfEyeFilename() const { return "Cat_" + m_color_of_eyes + ".png"; }

Cat::Cat(const sf::RenderWindow& window, const std::string& fileName) : m_distance(300.f)
{
    generateRandomCat();
    if (!m_baseTexture.loadFromFile(fileName))
    {
        throw missingTexture("Texture not found!\n");
    }
    m_finalSprite.setTexture(m_baseTexture);

    m_position.x = (static_cast<float>(window.getSize().x) - m_finalSprite.getGlobalBounds().height) / 30.f;
    m_position.y = (static_cast<float>(window.getSize().y) - m_finalSprite.getGlobalBounds().height) - 475.f;

    m_finalSprite.setPosition(
        m_position.x - (static_cast<float>(m_baseTexture.getSize().x) - m_finalSprite.getGlobalBounds().height) / 2.f,
        m_position.y - (static_cast<float>(m_baseTexture.getSize().y) - m_finalSprite.getGlobalBounds().height) / 2.f
    );

    m_finalSprite.setScale(2.5f, 2.5f);
}

void Cat::makeDoc(const int levelNr)
{
    LevelManager::handleCatDocuments(levelNr, m_documente, m_name, m_age, m_gender, m_height, m_weight);
}

void Cat::clearDoc()
{
    m_documente.clear();
}


void Cat::createCurrentDocs(int levelNr)
{
    makeDoc(levelNr);
    for (const auto& doc : m_documente)
    {
        doc->setText();
    }
}

void Cat::drawCurrentCat(sf::RenderWindow& window) const
{
    window.draw(m_finalSprite);
    if (!m_documente.empty())
    {
        for (const auto& doc : m_documente)
        {
            doc->drawDoc(window);
        }
    }
}

bool Cat::IsDocValid() const
{
    return true;
}

const std::vector<std::shared_ptr<Documente>>& Cat::getDocumente() const
{
    return m_documente;
}

void Cat::move()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
    {
        m_finalSprite.setPosition(m_finalSprite.getPosition() + sf::Vector2f(1, 0));
    }
}

void Cat::leave()
{
    if (m_position.x + m_finalSprite.getGlobalBounds().width <= 0)
    {
        return;
    }

    m_position.x -= m_distance;

    m_finalSprite.setPosition(m_position);
}


std::vector<std::shared_ptr<Documente>>& Cat::operator+=(const std::shared_ptr<Documente>& doc)
{
    this->m_documente.push_back(doc);
    return this->m_documente;
}

std::ostream& operator<<(std::ostream& os, const Cat& Cat)
{
    os << "Nume: " << Cat.m_name
       << "\nVarsta: " << Cat.m_age
       << "\nGenul: " << Cat.m_gender
       << "\nInaltime: " << Cat.m_height << " cm"
       << "\nGreutate: " << Cat.m_weight << " kg";
    return os;
}
