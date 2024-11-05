#pragma once

#include <string>
#include "../Headers/Pasaport.h"


class Cat
{
private:
    std::string m_name;
    std::string m_patterns;
    std::string m_color;
    std::string m_color_of_eyes;
    int m_age;
    char m_gender;
    Pasaport m_pasaport;

public:
    Cat(const std::string& name, const std::string& patterns, const std::string& color,
        const std::string& color_of_eyes, int age, char gender);

    Cat() { generateRandomCat(); }

    void generateRandomCat();

    void create_pasaport(int zi, int luna, int an);
    [[nodiscard]] std::string getTextureFilename() const;

    friend std::ostream& operator<<(std::ostream& os, const Cat& cat);
};


