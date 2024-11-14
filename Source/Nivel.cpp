#include <iostream>
#include <sstream>

#include "../Headers/Nivel.h"


void Nivel::incrementDate()
{
    m_date = std::chrono::year_month_day{std::chrono::sys_days{m_date} + std::chrono::days{1}};
}

std::string Nivel::get_date() const
{
    std::ostringstream date_stream;
    date_stream << static_cast<unsigned>(m_date.month()) << "/"
        << static_cast<unsigned>(m_date.day()) << "/"
        << static_cast<int>(m_date.year());

    return date_stream.str();
}

Nivel::Nivel(Cat& current_cat, Pasaport& current_pasaport)
    : currentCat(current_cat),
      currentPasaport(current_pasaport),
    m_date(std::chrono::year_month_day{std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now())})

{
}


void Nivel::NextLevel()
{
    if (m_levelNr < m_maxNr)
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
    const std::chrono::time_point now = std::chrono::system_clock::now();
    m_date = std::chrono::year_month_day{std::chrono::floor<std::chrono::days>(now)};
}

