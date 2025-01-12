#pragma once

#include "Documente.h"
#include "DocFalsifier.h"

class EntryPermit : public Documente
{
    sf::Texture m_sealTexture;
    sf::IntRect m_sealRect;

    std::string m_passaportNr = {};
    std::string m_purpose = {};
    int duration{};
    void create_document() override;

public:
    EntryPermit() = default;

    EntryPermit(sf::Vector2f pos, const std::string& name, const std::string& fileName, float scaleX, float scaleY);
    void setText() override;
    void setFakeSeal(const sf::Texture& fakeTexture);

    std::shared_ptr<DocFalsifier> getFalsifier() const override
    {
        return std::make_shared<PasaportFalsifier>();
    }
};
