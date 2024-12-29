#pragma once

class Money
{
    int m_savings = 30;
    int m_salary = 0;
    Money() = default;
public:
    Money(const Money&) = delete;
    Money& operator=(const Money&) = delete;

    static Money& get_money() {
        static Money money;
        return money;
    }

    void earn(int nrOfCheckedCats);
    bool spend(int amount);
    void new_level();
    void reset();
};
