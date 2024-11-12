#pragma once

#include "Cat.h"

class FakeCat: public Cat
{
public:
    FakeCat() : Cat() {
        create_pasaport();
    }

    void create_pasaport() override;
    bool IsPasaportValid() override;

};
