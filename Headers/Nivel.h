#pragma once

#include <chrono>

class Nivel
{
private:
    std::chrono::year_month_day m_date;

    int m_levelNr{1};

    void incrementDate();
    [[nodiscard]] std::string get_date() const;

public:

    Nivel();

    void NextLevel();
    [[nodiscard]] int GetLevelNr() const;
    void ResetLevel();
};
