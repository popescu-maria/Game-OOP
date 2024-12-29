#include <sstream>
#include <random>

#include "../Headers/Pasaport.h"
#include "../Headers/Cat.h"

#include <iostream>
#include <utility>

void Pasaport::create_document()
{
    auto today = std::chrono::system_clock::now();
    auto today_sys_days = std::chrono::floor<std::chrono::days>(today);

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 365);

    auto random_days = dist(gen);
    m_expDate = std::chrono::year_month_day{today_sys_days + std::chrono::days(random_days)};

    const sf::Vector2f nameOffset(20.f, 30.f);
    const sf::Vector2f dobOffset(300.f, 215.f);
    const sf::Vector2f genderOffset(300.f, 245.f);
    //const sf::Vector2f issueOffset(300.f, 275.f);
    const sf::Vector2f expDateOffset(300.f, 305.f);

    TextBuilder builder;
    AddText(builder.setFont().setSize(20).setCol(sf::Color::Black)
        .setPos(m_documentSprite.getPosition() + nameOffset)
        .setString(m_name).build());
    AddText(builder.setFont().setSize(15).setCol(sf::Color::Black)
        .setPos(m_documentSprite.getPosition() + dobOffset)
        .setString(std::to_string(m_age)).build());
    AddText(builder.setFont().setSize(15).setCol(sf::Color::Black)
        .setPos(m_documentSprite.getPosition() + genderOffset)
        .setString(std::string(1, m_gender)).build());
    //ISS : AddText(builder.setFont().setSize(15).setCol(sf::Color::Black).setPos(m_documentSprite.getPosition() + dobOffset).setString(m_age).build());
    AddText(builder.setFont().setSize(15).setCol(sf::Color::Black)
        .setPos(m_documentSprite.getPosition() + expDateOffset)
        .setString(get_date()).build());

}

Pasaport::Pasaport(const sf::Vector2f pos, std::string name, const std::string& fileName, const int age, const char gen, float scaleX = 0.5f, float scaleY = 0.5f)
    : Documente(pos, std::move(name), fileName), m_age(age), m_gender(gen)
{
    setScale(scaleX, scaleY);
}

