#pragma once

#include <string>
#include "pasaport.h"

#include "pasaport.h"

class cat
{
private:
    std::string m_name;
    std::string m_patterns;
    std::string m_color;
    std::string m_color_of_eyes;
    int m_age;
    char m_gender;
    pasaport m_pasaport;
public:

    cat(const std::string& name, const std::string& patterns, const std::string& color, const std::string& color_of_eyes);

    cat(const std::string& name, const std::string& patterns, const std::string& color, const std::string& color_of_eyes,
        const int& age, char gender);

    cat() { generateRandomCat(); }

    void generateRandomCat();

    void create_pasaport(int zi, int luna, int an);

    void print_details() const;

};


