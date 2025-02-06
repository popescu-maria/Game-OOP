#include "../Headers/ButtonState.h"

Context::Context(std::unique_ptr<State> state) : m_state(nullptr)
{
    TransitionTo(std::move(state));
    m_state->set_context(this);
}

void Context::TransitionTo(std::unique_ptr<State> state)
{
    m_state = std::move(state);
    if (m_state) {
        m_state->set_context(this);
        m_state->setupButton();
    }
}

void Context::HandleClick(const sf::Vector2f& mousePosition) const
{
    if (m_state && m_state->getButton().getGlobalBounds().contains(mousePosition)) {
            m_state->handleClick();
    }
}

void Context::draw(sf::RenderWindow& window) const
{
    if (m_state) {
        window.draw(m_state->getButton());
        m_state->draw(window);
    }
}

