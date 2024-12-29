#pragma once

#include <chrono>

class Nivel
{
private:
    std::chrono::year_month_day m_date;
    std::chrono::duration<double> m_elapsed_time;

    static int m_levelNr;

    void incrementDate();
    [[nodiscard]] std::string get_date() const;

public:
    Nivel();

    void NextLevel();
    static int GetLevelNr();
    void ResetLevel();
};
