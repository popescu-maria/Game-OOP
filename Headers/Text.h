#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

class Text {
private:
    std::shared_ptr<sf::Font> font;
    sf::Text text;

    friend class TextBuilder;
public:
    Text() : font(std::make_shared<sf::Font>()){
        if (!font->loadFromFile("./ocr-a-extended.ttf")) {
            throw std::runtime_error("The font was not found!\n");
        }
        text.setFont(*font);
    }

    sf::Text& getText() {
        return text;
    }

    const sf::Text& getText() const {
        return text;
    }
};

class TextBuilder {
private:
    Text curr;
public:
    TextBuilder() = default;
    TextBuilder& setFont() {
        return *this;
    }
    TextBuilder& setSize(float size) {
        curr.text.setCharacterSize(static_cast<int>(size));
        return *this;
    }
    TextBuilder& setCol(sf::Color col) {
        curr.text.setFillColor(col);
        return *this;
    }
    TextBuilder& setPos(sf::Vector2f pos) {
        curr.text.setPosition(pos);
        return *this;
    }
    TextBuilder& setPos(float x, float y) {
        curr.text.setPosition(x, y);
        return *this;
    }
    TextBuilder& setString(const std::string& s) {
        curr.text.setString(s);
        return *this;
    }
    Text build() {
        return curr;
    }
};
