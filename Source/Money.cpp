#include "../Headers/Money.h"

#include <iostream>

void Money::earn(const int nrOfCheckedCats)
{
    m_salary += 10 * nrOfCheckedCats;
}

bool Money::spend(const int amount)
{
    if(amount > m_salary){
        int deficit = amount - m_salary;
        m_salary = 0;
        if(deficit > m_savings){
            std::cout << "game over";
            return false;
        }
        m_savings -= deficit;
    }else
    {
        m_salary -= amount;
    }
    return true;
}

void Money::new_level()
{
    m_savings += m_salary;
}

void Money::reset()
{
    m_salary = 30;
    m_salary = 0;
}
