#pragma once

#include "../Headers/Cat.h"

class Nivel
{
private:
    struct Date
    {
        int zi;
        int luna;
        int an;
    };
    int m_levelNr{1};
    int m_maxNr{15};
    Date m_currentDate;

    Cat& currentCat;
    Pasaport& currentPasaport;

    void incrementDate();
    [[nodiscard]] std::string get_date() const;

public:
    Nivel(Cat& cat, Pasaport& pasaport);

    void NextLevel();
    [[nodiscard]]int GetLevelNr() const;
    void ResetLevel();
};
