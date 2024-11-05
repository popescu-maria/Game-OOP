#pragma once


class Pasaport
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
    Pasaport();

    explicit Pasaport(int zi, int luna, int an, const std::string& name, int age, char gender);

    Pasaport(const Pasaport& other);

    Pasaport& operator=(const Pasaport& other);
    friend std::ostream& operator<<(std::ostream& os, const Pasaport& ps);


    [[nodiscard]] std::string get_date() const;

    ~Pasaport();
};
