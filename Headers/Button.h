#pragma once

#include <SFML/Graphics.hpp>
#include "ButtonState.h"
#include "Text.h"

class OpenStampRack : public State
{
private:
    Text m_OpenText;

public:
    OpenStampRack();
    void handleClick() override;
    void setText(const std::string& text);
    void draw(sf::RenderWindow& window) override;
};

class EntryGranted : public State
{
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    Text m_EntryText;
    //rect for when the sprite should appear on the screen
    sf::FloatRect m_activArea;

public:
    explicit EntryGranted(const std::string& fileName);
    void handleClick() override;
    void setText(const std::string& text);
    void draw(sf::RenderWindow& window) override;
};

class EntryDenied : public State
{
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    Text m_EntryText;
    //rect for when the sprite should appear on the screen
    sf::FloatRect m_activArea;

public:
    explicit EntryDenied(const std::string& fileName);
    void handleClick() override;
    void setText(const std::string& text);
    void draw(sf::RenderWindow& window) override;
};