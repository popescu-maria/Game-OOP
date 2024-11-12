#pragma once

#include <string>
#include <SFML/Graphics.hpp>

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
    sf:: Texture m_textureCat;

    void generateRandomCat();
    [[nodiscard]] std::string getTextureFilename() const;

public:
    Cat(const std::string& name, const std::string& patterns, const std::string& color,
        const std::string& color_of_eyes, int age, char gender);

    Cat();

    void displayCat() const;
    virtual void create_pasaport();
    virtual bool IsPasaportValid();
    const Pasaport& getPasaport() const;

    friend std::ostream& operator<<(std::ostream& os, const Cat& cat);

    virtual ~Cat() = default;
};


