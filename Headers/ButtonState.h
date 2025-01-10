#pragma once

#include <SFML/Graphics.hpp>
#include "Text.h"

class Context;

class State
{
protected:
    Context* m_context = nullptr;

public:
    virtual ~State() = default;

    void set_context(Context* context) { m_context = context; }

    virtual void handleClick() = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};

class Context
{
private:
    std::unique_ptr<State> m_state;
    sf::RectangleShape m_button;
    Text m_buttonText;

public:
    explicit Context(std::unique_ptr<State> state);

    ~Context() = default;

    void TransitionTo(std::unique_ptr<State> state);

    void HandleClick(const sf::Vector2f& mousePosition) const;
    void draw(sf::RenderWindow& window) const;
};
