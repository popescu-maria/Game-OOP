#pragma once

#include <SFML/Graphics.hpp>
#include "Text.h"

class Context;

class State
{
protected:
    Context* m_context = nullptr;
    sf::RectangleShape m_button;

public:
    virtual ~State() = default;

    void set_context(Context* context) { m_context = context; }

    virtual void handleClick() = 0;
    virtual void setupButton() = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual sf::RectangleShape& getButton() { return m_button; }
};

class Context
{
private:
    std::unique_ptr<State> m_state;
public:
    explicit Context(std::unique_ptr<State> state);

    ~Context() = default;

    void TransitionTo(std::unique_ptr<State> state);

    void HandleClick(const sf::Vector2f& mousePosition) const;
    void draw(sf::RenderWindow& window) const;
    [[nodiscard]] State* getCurrentState() const { return m_state.get(); }
};
