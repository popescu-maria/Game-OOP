#include "../Headers/ButtonState.h"

Context::Context(std::unique_ptr<State> state) : m_state(nullptr)
{
    if (!m_pressButtonBuffer.loadFromFile("Sounds/openStampRack.wav"))
    {
        throw std::runtime_error("Failed to load click sound effect!");
    }
    m_pressButtonSound.setBuffer(m_pressButtonBuffer);
    m_pressButtonSound.setVolume(50);

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

void Context::HandleClick(const sf::Vector2f& mousePosition)
{
    if (m_state && m_state->getButton().getGlobalBounds().contains(mousePosition)) {
        m_pressButtonSound.play();
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

