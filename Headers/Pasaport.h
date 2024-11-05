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
    pasaport();

    explicit pasaport(int zi, int luna, int an, const std::string& name, int age, char gender);

    pasaport(const pasaport& other);

    pasaport& operator=(const pasaport& other);
    friend std::ostream& operator<<(std::ostream& os, const pasaport& ps);


    [[nodiscard]] std::string get_date() const;

    ~pasaport();
};
