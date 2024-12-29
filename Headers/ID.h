#pragma once

#include "Documente.h"

#include <iostream>

class Id : public Documente
{
private:
    std::chrono::year_month_day m_dob = std::chrono::year_month_day{std::chrono::year{2000} / 1 / 1};
    float m_height{};
    float m_weight{};
    std::string m_district;
    void create_document() override;
public:
    Id() = default;

    Id(sf::Vector2f pos, const std::string& name, const std::string& fileName, float height, float weight, std::string district);
    std::shared_ptr<Documente> clone() const override
    {
        return std::make_shared<Id>(*this);
    }
};
