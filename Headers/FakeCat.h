#pragma once

#include "Cat.h"

class FakeCat : public Cat
{
public:
    FakeCat() = default;
    FakeCat(const sf::RenderWindow& window, const std::string& fileName) : Cat(window,fileName){}
    void createCurrentDocs(int levelNr) override;

    bool IsDocValid() const override;

};
