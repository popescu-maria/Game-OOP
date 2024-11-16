#include "../Headers/FakeCat.h"

#include <iostream>
#include <chrono>
#include <vector>
#include <random>

void FakeCat::create_pasaport()
{
    auto today = std::chrono::system_clock::now();
    auto today_sys_days = std::chrono::floor<std::chrono::days>(today);

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 30);

    auto random_days = dist(gen);

    auto expDate = std::chrono::year_month_day{today_sys_days - std::chrono::days(random_days)};

    m_pasaport = Pasaport(expDate, m_name, m_age, m_gender);
}

bool FakeCat::IsPasaportValid()
{
    return false;
}


