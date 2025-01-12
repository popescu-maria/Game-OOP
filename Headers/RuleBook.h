#pragma once
#include "ButtonState.h"
#include "Text.h"

class ClosedRB : public State
{
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
public:
    explicit ClosedRB(const std::string& fileName);
    void handleClick() override;
    void setupButton() override;
    //void setText(const std::string& text);
    void draw(sf::RenderWindow& window) override;
};

class OpenRB : public State
{
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;

    Text m_districtText;
    std::vector<std::string> m_validDistricts = {
        "TORCOVIA", "MIORLAIA", "PADURENI", "MUSTACESTI",
        "GHEARASOV", "PORT MIAUNOV", "TUNDRA NORDICA", "FELINOVA", "PISICIENI"
    };
public:
    explicit OpenRB(const std::string& fileName);
    void handleClick() override;
    void setupButton() override;
    void setText();
    void draw(sf::RenderWindow& window) override;
};