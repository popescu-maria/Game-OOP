#include <sstream>
#include "../Headers/Pasaport.h"

#include <iostream>


pasaport::pasaport() : m_date{0, 0, 0}, m_name(""), m_age(0), m_gender(' ')
{
}

pasaport::pasaport(int zi, int luna, int an, const std::string& name, int age, char gender)
    : m_date{zi, luna, an}, m_name(name), m_age(age), m_gender(gender)
{
}

pasaport::pasaport(const pasaport& other)
    : m_date(other.m_date), m_name(other.m_name), m_age(other.m_age), m_gender(other.m_gender)
{
    std::cout << "constructor de copiere pentru pasaport\n";
}

pasaport& pasaport::operator=(const pasaport& other)
{
    m_date.zi = other.m_date.zi;
    m_date.luna = other.m_date.luna;
    m_date.an = other.m_date.an;
    m_age = other.m_age;
    m_gender = other.m_gender;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const pasaport& ps)
{
    os << "Data de expirare: " << ps.get_date() << "\nNume pisica: " << ps.m_name
        << "\nVarsta pisica: " << ps.m_age << "\nGenul pisica: " << ps.m_gender << "\n";
}

std::string pasaport::get_date() const
{
    std::ostringstream date_stream;
    date_stream << m_date.zi << "/" << m_date.luna << "/" << m_date.an;
    return date_stream.str();
}

pasaport::~pasaport()
{
    std::cout << "destructor explicit" << std::endl;
}
