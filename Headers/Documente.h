#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
#include <chrono>
#include "Text.h"

class DocFalsifier;
class Cat;

class Documente
{
private:
    virtual void create_document() = 0;

protected:
    sf::Vector2f m_position;
    sf::Texture m_texture;
    sf::Sprite m_documentSprite;
    std::vector<std::pair<Text, sf::Vector2f>> m_textsWithOffsets;

    std::optional<sf::Sprite> m_sealSprite;
    sf::Vector2f m_sealOffset = {0.f, 0.f};

    bool m_isDragging = false;
    sf::Vector2f m_dragOffset;

    std::chrono::year_month_day m_expDate = std::chrono::year_month_day{std::chrono::year{2024} / 1 / 1};
    std::string m_name;

public:
    Documente() = default;
    void createDoc();
    Documente(const Documente& oth);
    Documente& operator=(const Documente& oth);
    Documente(sf::Vector2f pos, std::string name, const std::string& fileName);

    [[nodiscard]] std::string get_date() const;
    sf::FloatRect getBounds() const;
    void setScale(float x, float y);
    [[maybe_unused]] void setSeal(const sf::Texture& sealTexture, const sf::IntRect& rect, const sf::Vector2f& offset);

    void AddText(const Text& text, const sf::Vector2f& offset);
    virtual void setText() = 0;
    virtual std::shared_ptr<DocFalsifier> getFalsifier() const = 0;

    void checkBounds(sf::RenderWindow& window);
    void move(sf::RenderWindow& window);

    void drawDoc(sf::RenderWindow& window);

    virtual ~Documente() = default;
};
