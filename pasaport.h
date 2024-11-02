#pragma once

class pasaport
{
private:
    struct data_expirare
    {
        int zi;
        int luna;
        int an;
    };
    data_expirare m_date;
    std::string m_name;
    int m_age;
    char m_gender;
public:
    pasaport() : m_date{0, 0, 0}, m_name(""), m_age(0), m_gender(' ') {}
    pasaport(int zi, int luna, int an, std::string& name, int age, char gender);

    pasaport(const pasaport& other);

    pasaport& operator=(const pasaport& other);
    std::string get_date() const;

    ~pasaport() = default;

};