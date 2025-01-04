#pragma once

#include "../Headers/Cat.h"

class FakeCat : public Cat
{
public:
    FakeCat() = default;
    FakeCat(const sf::RenderWindow& window, const std::string& fileName) : Cat(window,fileName){}

    bool IsDocValid() override;

};
