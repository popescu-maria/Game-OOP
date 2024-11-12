#include <iostream>
#include <sstream>

#include "../Headers/Nivel.h"


void Nivel::incrementDate()
{
    m_currentDate.zi++;

    switch (m_currentDate.luna)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        if (m_currentDate.zi > 31) {
            m_currentDate.zi = 1;
            m_currentDate.luna++;
        }
        break;
    case 2:
        if (m_currentDate.zi > 28)
        {
            m_currentDate.zi = 1;
            m_currentDate.luna++;
        }
        break;
    case 4: case 6: case 9: case 11:
        if (m_currentDate.zi > 30)
        {
            m_currentDate.zi = 1;
            m_currentDate.luna++;
        }
        break;
    default:
        std::cout << "luna invalida!" << std::endl;
        break;
    }
    if (m_currentDate.luna > 12) {
        m_currentDate.luna = 1;
        m_currentDate.an++;
    }
}

std::string Nivel:: get_date() const
{
    std::ostringstream date_stream;
    date_stream << m_currentDate.zi << "/" << m_currentDate.luna << "/" << m_currentDate.an;
    return date_stream.str();
}

Nivel:: Nivel(Cat& current_cat, Pasaport& current_pasaport)
        : currentCat(current_cat),
          currentPasaport(current_pasaport), m_currentDate(1, 1, 2024)
{
}


void Nivel::NextLevel()
{
    if(m_levelNr < m_maxNr)
    {
        m_levelNr++;
        incrementDate();
        std::cout << "Felicitari, ai ajuns la ziua: " << m_levelNr
        << ", in data de: " << get_date() << std::endl;
    }
    else
    {
        std::cout << "Ai completat toate nivelele, poti sa te pensionezi!!" << std::endl;
    }
}

int Nivel::GetLevelNr() const
{
    return m_levelNr;
}

void Nivel::ResetLevel()
{
    m_levelNr = 1;
    m_currentDate = Date(1, 1, 2024);
}

