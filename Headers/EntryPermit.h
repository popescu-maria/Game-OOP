#pragma once

#include "Documente.h"

class EntryPermit : public Documente
{
    sf::Texture m_sealTexture;
    sf::Sprite m_sealSprite;
    sf::IntRect m_sealRect;

    std::string m_passaportNr = {};
    std::string m_purpose = {};
    int duration{};
    void create_document() override;

public:
    EntryPermit() = default;

    EntryPermit(sf::Vector2f pos, const std::string& name, const std::string& fileName, float scaleX, float scaleY);
    void setFakeSeal(const sf::Sprite& fakeSprite);

    std::shared_ptr<Documente> clone() const override
    {
        return std::make_shared<EntryPermit>(*this);
    }
};
