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

Nivel::Nivel()
    : m_date(std::chrono::year_month_day{std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now())})
{
}


void Nivel::NextLevel()
{
    std::cout << "Felicitari, ai ajuns la ziua: " << m_levelNr
        << ", in data de: " << get_date() << std::endl;
    m_levelNr++;
    incrementDate();
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
