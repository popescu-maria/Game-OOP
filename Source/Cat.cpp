#include <iostream>
#include <vector>
#include <random>
#include "../Headers/Cat.h"

void Cat::generateRandomCat()
{
    static std::vector<std::string> names = {
        "Whiskers", "Luna", "Milo", "Bella", "Oliver", "Simba", "Chloe", "Shadow", "Leo", "Nala",
        "Pumpkin", "Mittens", "Sassy", "Tiger", "Gizmo", "Tigger", "Cleo", "Oreo", "Missy", "Ziggy",
        "Kitty", "Jasper", "Boots", "Salem", "Lily", "Felix", "Misty", "Socks", "Mocha", "Pepper",
        "Rusty", "Lucky", "Toffee", "Peanut", "Smokey", "Biscuit", "Mochi", "Ash", "Bandit", "Garfield",
        "Midnight", "Toby", "Mango", "Willow", "Finn", "Hazel", "Cinnamon", "Cali", "Mimi", "Bubbles",
        "Snowball", "Honey", "Benny", "Blue", "Cuddles", "Chester", "Mabel", "Sushi", "Daisy", "Buttons"
    };
    static std::vector<std::string> colors = {"Black", "White", "Orange", "Gray", "Brown"};
    static std::vector<std::string> patterns = {"Striped", "Solid", "Spotted", "Mixed"};
    static std::vector<std::string> eyeColors = {"Green", "Blue", "Yellow", "Brown"};

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> nameDist(0, names.size() - 1);
    std::uniform_int_distribution<> colorDist(0, colors.size() - 1);
    std::uniform_int_distribution<> patternDist(0, patterns.size() - 1);
    std::uniform_int_distribution<> eyeColorDist(0, eyeColors.size() - 1);
    std::uniform_int_distribution<> ageDist(1, 18);
    std::uniform_int_distribution<> genderDist(0, 1);
    m_name = names[nameDist(gen)];
    m_color = colors[colorDist(gen)];
    m_patterns = patterns[patternDist(gen)];
    m_color_of_eyes = eyeColors[eyeColorDist(gen)];
    m_age = ageDist(gen);
    m_gender = genderDist(gen) == 0 ? 'M' : 'F';

}

std::string Cat::getColorFilename() const { return "Cat_" + m_color + ".png"; }
std::string Cat::getPatternsFilename() const { return "Cat_" + m_patterns + ".png"; }
std::string Cat::getColorOfEyeFilename() const { return "Cat_" + m_color_of_eyes + ".png"; }

Cat::Cat(const sf::RenderWindow& window, const std::string& fileName): m_speed(100.f)
{
    generateRandomCat();
    //adauga si celelalte atribute mai incolo, momeentan doar baza
    if (!m_baseTexture.loadFromFile(fileName))
        std::cerr << "Can't load texture for the base of the cat" << std::endl;
    m_finalSprite.setTexture(m_baseTexture);

    m_position.x = (static_cast<float>(window.getSize().x) - m_finalSprite.getGlobalBounds().height) / 30.f;
    m_position.y = (static_cast<float>(window.getSize().y) - m_finalSprite.getGlobalBounds().height) - 475.f;

    m_finalSprite.setPosition(
        m_position.x - (static_cast<float>(m_baseTexture.getSize().x) - m_finalSprite.getGlobalBounds().height) / 2.f,
        m_position.y - (static_cast<float>(m_baseTexture.getSize().y) - m_finalSprite.getGlobalBounds().height) / 2.f
    );

    m_finalSprite.setScale(2.5f, 2.5f);
}

void Cat::createCurrentDocs(int levelNr)
{
    m_documente.clear();
    if (levelNr <= 5)
    {
        //de apelat const cu parametrii ca sa i setam poziti si fileName , poate le citim dintrun fisier
        auto prototypePasaport = std::make_shared<Pasaport>( sf::Vector2f(100.f, 100.f), m_name, "Img/Pasaport.png", m_age, m_gender, 0.35f, 0.35f);

        //auto pasaport = prototypePasaport->clone();
        prototypePasaport->createDoc();
        m_documente.emplace_back(prototypePasaport);
    }
}

void Cat::drawCurrentCat(sf::RenderWindow& window) const
{
    window.draw(m_finalSprite);
}


bool Cat::IsPasaportValid()
{
    return true;
}

std::vector<std::shared_ptr<Documente>> Cat::getDocumente() const
{
    return m_documente;
}

void Cat::setMoveTarget()
{
    if (!m_isMoving) {
        targetX = m_moveDistance;
        //m_isMoving = true;
    }
}

void Cat::move()
{
    //setMoveTarget();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::N))
    {
        m_finalSprite.setPosition(m_finalSprite.getPosition() + sf::Vector2f(1, 0));
    }
}


std::vector<std::shared_ptr<Documente>>& Cat::operator+=(const std::shared_ptr<Documente>& doc)
{
    this->m_documente.push_back(doc);
    return this->m_documente;
}


std::ostream& operator<<(std::ostream& os, const Cat& Cat)
{
    os << "Nume: " << Cat.m_name << "\nModel: " << Cat.m_patterns
        << "\nCuloare: " << Cat.m_color << "\nCuloarea ochilor: " << Cat.m_color_of_eyes
        << "\nVarsta: " << Cat.m_age << "\nGenul: " << Cat.m_gender << "\n";
    return os;
}
