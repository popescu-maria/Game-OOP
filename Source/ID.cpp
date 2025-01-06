#include <utility>
#include <random>

#include "../Headers/ID.h"

void Id::create_document()
{
    static std::vector<std::string> districts = {
        "TORCOVIA", "MIORLAIA", "PADURENI", "MUSTACESTI",
        "GHEARASOV", "PORT MIAUNOV", "TUNDRA NORDICA", "FELINOVA", "PISICIENI"
    };

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> nameDist(0, districts.size() - 1);

    m_district = districts[nameDist(gen)];

}

void Id::setText()
{
    const sf::Vector2f districtOffset(10.f, 20.f);
    const sf::Vector2f nameOffset(120.f, 35.f);
    const sf::Vector2f ageOffset(160.f, 90.f);
    const sf::Vector2f heightOffset(160.f, 115.f);
    const sf::Vector2f weightOffset(160.f, 140.f);

    TextBuilder builder;
    AddText(builder.setFont().setSize(20).setCol(sf::Color::Black)
                   .setPos(m_documentSprite.getPosition() + districtOffset)
                   .setString(m_district + " DISTRICT").build(), districtOffset);
    AddText(builder.setFont().setSize(30).setCol(sf::Color::Black)
                   .setPos(m_documentSprite.getPosition() + nameOffset)
                   .setString(m_name).build(), nameOffset);
    AddText(builder.setFont().setSize(20).setCol(sf::Color::Black)
                   .setPos(m_documentSprite.getPosition() + ageOffset)
                   .setString(std::to_string(m_age) + " ani").build(), ageOffset);
    AddText(builder.setFont().setSize(20).setCol(sf::Color::Black)
                   .setPos(m_documentSprite.getPosition() + heightOffset)
                   .setString(std::to_string(m_height) + " cm").build(), heightOffset);
    AddText(builder.setFont().setSize(20).setCol(sf::Color::Black)
                   .setPos(m_documentSprite.getPosition() + weightOffset)
                   .setString(std::to_string(m_weight) + " kg").build(), weightOffset);
}


void Id::SetFakeDistrict(const std::string& fakeDistrict)
{
    m_district = fakeDistrict;
    setText();
}

Id::Id(const sf::Vector2f pos, const std::string& name, const std::string& fileName, const int age, const int height,
       const int weight
       , float scaleX = 2.f, float scaleY = 2.f)
    : Documente(pos, name, fileName), m_age(age), m_height(height), m_weight(weight)
{
    setScale(scaleX, scaleY);
}
