#pragma once

#include <chrono>

class Pasaport
{
private:
    std::chrono::year_month_day m_expDate = std::chrono::year_month_day{std::chrono::year{2020} / 1 / 1};
    std::string m_name;
    int m_age = 0;
    char m_gender = 'U';

public:
    Pasaport() = default;

    explicit Pasaport(std::chrono::year_month_day expDate, const std::string& name, int age, char gender);
    Pasaport(const Pasaport& other);

    Pasaport& operator=(const Pasaport& other);
    friend std::ostream& operator<<(std::ostream& os, const Pasaport& ps);


    [[nodiscard]] std::string get_date() const;

    virtual ~Pasaport() = default;
};
