#include <sstream>
#include "../Headers/Pasaport.h"

#include <iostream>

    Pasaport::Pasaport(std::chrono::year_month_day expDate, const std::string& name, int age, char gender)
        : m_expDate{expDate}, m_name(name), m_age(age), m_gender(gender)
    {
    }

Pasaport::Pasaport(const Pasaport& other)
    : m_expDate(other.m_expDate), m_name(other.m_name), m_age(other.m_age), m_gender(other.m_gender)
{
    std::cout << "constructor de copiere pentru pasaport\n";
}

bool Pasaport:: IsPasaportValid() const{
    return true;
}

Pasaport& Pasaport::operator=(const Pasaport& other)
{
    m_expDate = other.m_expDate;
    m_name = other.m_name;
    m_age = other.m_age;
    m_gender = other.m_gender;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Pasaport& ps)
{
    os << "Data de expirare: " << ps.get_date() << "\nNume pisica: " << ps.m_name
        << "\nVarsta pisica: " << ps.m_age << "\nGenul pisica: " << ps.m_gender << "\n";
    return os;
}

std::string Pasaport::get_date() const
{
        std::ostringstream date_stream;
        date_stream << static_cast<unsigned>(m_expDate.month()) << "/"
        << static_cast<unsigned>(m_expDate.day()) << "/"
        << static_cast<int>(m_expDate.year());

        return date_stream.str();
}

Pasaport::~Pasaport()
{
    std::cout << "destructor explicit pasaport" << std::endl;
}
