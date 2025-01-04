#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/System/Vector2.hpp"

#include <chrono>
#include "Text.h"
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

    bool m_isDragging = false;
    sf::Vector2f m_dragOffset;
    std::chrono::year_month_day m_expDate = std::chrono::year_month_day{std::chrono::year{2024} / 1 / 1};
    std::string m_name;

public:
    // Move funct and checking function and how do i make more use of the createDoc fct
    Documente() = default;
    void createDoc();
    Documente(const Documente& oth);
    Documente& operator=(const Documente& oth);
    Documente(sf::Vector2f pos, std::string name, const std::string& fileName);
    virtual std::shared_ptr<Documente> clone() const = 0;

    [[nodiscard]] std::string get_date() const;
    sf::Vector2f getSize() const;
    sf::Vector2f getPos() const;
    void setScale(float x, float y);

    void AddText(const Text& text, const sf::Vector2f& offset);

    void checkBounds(sf::RenderWindow& window);
    void move(sf::RenderWindow& window);

    void drawDoc(sf::RenderWindow& window) const;

    virtual ~Documente() = default;
};
