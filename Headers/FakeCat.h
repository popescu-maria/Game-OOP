#pragma once

#include "../Headers/Cat.h"

class FakeCat : public Cat
{
public:
    //In viitor (pentru tema 2) pisica va avea mai multe acte, ca si pasaportul,
    //care vor fi modificate in functie de dificultatea nivelului. Atunci vor
    //fi mai multe functii ce vor trebuie modificate, de aceea am creat o clasa noua
    FakeCat() = default;
    FakeCat(const sf::RenderWindow& window, const std::string& fileName) : Cat(window,fileName){}

    bool IsPasaportValid() override;

};
