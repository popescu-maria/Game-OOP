#include "../Headers/ButtonState.h"

Context::Context(std::unique_ptr<State> state) : m_state(nullptr)
{
    TransitionTo(std::move(state));
    m_state->set_context(this);

    m_button.setSize({150.f, 60.f});
    m_button.setFillColor(sf::Color::White);
    m_button.setPosition({1050.f, 245.f});

    m_button.setOutlineColor(sf::Color::Black);
    m_button.setOutlineThickness(4.f);
}

void Context::TransitionTo(std::unique_ptr<State> state)
{
    m_state = std::move(state);
    if (m_state)
    {
        m_state->set_context(this);
    }
}

void Context::HandleClick(const sf::Vector2f& mousePosition) const
{
    if (m_button.getGlobalBounds().contains(mousePosition))
    {
        m_state->handleClick();
    }
}


void Context::draw(sf::RenderWindow& window) const
{
    window.draw(m_button);
    if (m_state)
    {
        m_state->draw(window);
    }
}

