#include <iostream>
#include <vector>
#include <random>

#include "Cat.h"

cat::cat(const std::string& name, const std::string& patterns, const std::string& color,
        const std::string& color_of_eyes, int age, char gender)
    : m_name(name), m_patterns(patterns),
    m_color(color), m_color_of_eyes(color_of_eyes), m_age(age), m_gender(gender)
{
}

void cat::create_pasaport(int zi, int luna, int an)
{
    m_pasaport = pasaport(zi, luna, an, m_name, m_age, m_gender);
}

void cat:: generateRandomCat() {
    static std::vector<std::string> colors = {"Black", "White", "Orange", "Gray"};
    static std::vector<std::string> patterns = {"Striped", "Solid", "Spotted", "Mixed"};
    static std::vector<std::string> eyeColors = {"Green", "Blue", "Yellow", "Brown"};

    m_color = colors[rand() % colors.size()];
    m_patterns = patterns[rand() % patterns.size()];
    m_color_of_eyes = eyeColors[rand() % eyeColors.size()];
    m_age = rand() % 20; // Random age between 0 and 20
    m_gender = (rand() % 2 == 0) ? 'M' : 'F'; // Random gender
}

// Display cat's details in the game interface

//doar pentru vreificare, o sa dispara
void cat::print_details() const {
    std::cout << "Nume: " << m_name << "\n"
              << "Patterns: " << m_patterns << "\n"
              << "Color: " << m_color << "\n"
              << "Eye Color: " << m_color_of_eyes << "\n"
              << "Age: " << m_age << "\n"
              << "Gender: " << m_gender << "\n"
              << "Pasaport Expiry: " << m_pasaport.get_date() << "\n";
}
