#include "../Headers/RuleBook.h"
#include <sstream>

ClosedRB::ClosedRB(const std::string& fileName)
{
    if (!m_texture.loadFromFile(fileName))
    {
        throw missingTexture("Texture not found!\n");
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setScale(0.3f, 0.3f);
}


void ClosedRB::handleClick()
{
    m_context->TransitionTo(std::make_unique<OpenRB>("Img/ValidSeals.png"));
}

void ClosedRB::setupButton()
{
    m_button.setSize({45.f, 75.f});
    m_button.setFillColor(sf::Color::White);
    m_button.setPosition({240.f, 755.f});

    m_sprite.setPosition(235.f, 750.f);
}

void ClosedRB::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}

OpenRB::OpenRB(const std::string& fileName)
{
    if (!m_texture.loadFromFile(fileName))
    {
        throw missingTexture("Texture not found!\n");
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setScale(0.65f, 0.65f);
    setText();
}

void OpenRB::handleClick()
{
    m_context->TransitionTo(std::make_unique<ClosedRB>("Img/RuleBook.png"));
}

void OpenRB::setupButton()
{
    m_button.setSize({350.f, 170.f});
    m_button.setFillColor(sf::Color::White);
    m_button.setPosition({10.f, 580.f});

    m_sprite.setPosition(15.f, 620.f);
}

void OpenRB::setText()
{
    std::ostringstream oss;
    oss << "Valid districts:\n";
    for (const auto& district : m_validDistricts)
    {
        oss << "- " << district << '\n';
    }

    TextBuilder builder;
    m_districtText = builder.setString(oss.str())
                            .setSize(16)
                            .setCol(sf::Color::Black)
                            .setPos(200.f, 576.f)
                            .build();
}


void OpenRB::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
    window.draw(m_districtText.getText());
}
