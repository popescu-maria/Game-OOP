#pragma once

#include "Documente.h"
#include "DocFalsifier.h"

class Id : public Documente
{
    int m_age{};
    int m_height{};
    int m_weight{};
    std::string m_district = {};
    void create_document() override;
public:
    Id() = default;

    Id(sf::Vector2f pos, const std::string& name, const std::string& fileName, int age, int height, int weight
       , float scaleX, float scaleY);
    void setText() override;
    void SetFakeDistrict(const std::string& fakeDistrict);

    std::shared_ptr<DocFalsifier> getFalsifier() const override
    {
        return std::make_shared<IDFalsifier>();
    }
};
