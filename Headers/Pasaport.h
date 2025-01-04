#pragma once

#include "Documente.h"

class Pasaport : public Documente
{
    int m_age{};
    char m_gender{};
    void create_document() override;
public:
    Pasaport() = default;

    Pasaport(sf::Vector2f pos, std::string name, const std::string& fileName, int age, char gen, float scaleX,
             float scaleY);
    void SetFakeDate(const std::chrono::year_month_day& fakeDate);

    std::shared_ptr<Documente> clone() const override
    {
        return std::make_shared<Pasaport>(*this);
    }
};
