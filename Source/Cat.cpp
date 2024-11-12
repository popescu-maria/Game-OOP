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
    std::uniform_int_distribution<> ageDist(0, 20);
    std::uniform_int_distribution<> genderDist(0, 1);

    m_name = names[nameDist(gen)];
    m_color = colors[colorDist(gen)];
    m_patterns = patterns[patternDist(gen)];
    m_color_of_eyes = eyeColors[eyeColorDist(gen)];
    m_age = ageDist(gen);
    m_gender = genderDist(gen) == 0 ? 'M' : 'F';
}

// std::string Cat::getTextureFilename() const
// {
//     return "Cat_" + m_color + "_" + m_patterns + "_" + m_color_of_eyes + ".png";
// }

Cat::Cat(const std::string& name,
         const std::string& patterns,
         const std::string& color,
         const std::string& color_of_eyes,
         int age, char gender)
    : m_name(name), m_patterns(patterns),
      m_color(color), m_color_of_eyes(color_of_eyes), m_age(age), m_gender(gender)
{
}

Cat::Cat()
{
    generateRandomCat();
}

void Cat::create_pasaport()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> monthDist(1, 12);
    int luna = monthDist(gen);
    int an = 2024;

    int maxDay;
    switch (luna)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        maxDay = 30;
        break;
    case 2:
        maxDay = 28;
        break;
    default:
        maxDay = 31;
    }

    std::uniform_int_distribution<> dayDist(1, maxDay);
    int zi = dayDist(gen);

    m_pasaport = Pasaport(zi, luna, an, m_name, m_age, m_gender);
}

bool Cat::IsPasaportValid()
{
    return true;
}

const Pasaport& Cat::getPasaport() const {
    return m_pasaport;
}


std::ostream& operator<<(std::ostream& os, const Cat& Cat)
{
    os << "Nume: " << Cat.m_name << "\nModel: " << Cat.m_patterns
        << "\nCuloare: " << Cat.m_color << "\nCuloarea ochilor: " << Cat.m_color_of_eyes
        << "\nVarsta: " << Cat.m_age << "\nGenul: " << Cat.m_gender << "\n";
    return os;
}
