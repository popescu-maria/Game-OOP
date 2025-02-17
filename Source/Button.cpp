#include "../Headers/Button.h"

OpenStampRack::OpenStampRack()
{
    setText("Open Stamp\n   Rack");
}

void OpenStampRack::handleClick()
{
    m_context->TransitionTo(std::make_unique<EntryGranted>("Img/ENTRYGRANTED.png"));
}

void OpenStampRack::setupButton()
{
    m_button.setSize({150.f, 60.f});
    m_button.setFillColor(sf::Color::White);
    m_button.setPosition({1050.f, 245.f});

    m_button.setOutlineColor(sf::Color::Black);
    m_button.setOutlineThickness(4.f);
}

void OpenStampRack::setText(const std::string& textString)
{
    TextBuilder builder;
    m_OpenText = builder.setString(textString)
                        .setSize(19)
                        .setCol(sf::Color::Black)
                        .setPos(1060.f, 255.f)
                        .build();
}

void OpenStampRack::draw(sf::RenderWindow& window)
{
    window.draw(m_OpenText.getText());
}

EntryGranted::EntryGranted(const std::string& fileName)
{
    if (!m_texture.loadFromFile(fileName))
    {
        throw missingTexture("Texture not found!\n");
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setScale(0.45f, 0.45f);
    setText(" Entry\nGranted");
}

void EntryGranted::setText(const std::string& textString)
{
    TextBuilder builder;
    m_EntryText = builder.setString(textString)
                         .setSize(20)
                         .setCol(sf::Color::Green)
                         .setPos(1080.f, 255.f)
                         .build();
}

void EntryGranted::handleClick()
{
    m_context->TransitionTo(std::make_unique<EntryDenied>("Img/ENTRYDENIED.png"));
}

void EntryGranted::setupButton()
{
    m_button.setSize({150.f, 60.f});
    m_button.setFillColor(sf::Color::White);
    m_button.setPosition({1050.f, 245.f});

    m_button.setOutlineColor(sf::Color::Black);
    m_button.setOutlineThickness(4.f);
}

void EntryGranted::draw(sf::RenderWindow& window)
{
    window.draw(m_EntryText.getText());

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
    sf::Vector2u windowSize = window.getSize();
    m_activArea = sf::FloatRect(360.f, 305.f, windowSize.x - 360.f, windowSize.y - 305.f);

    if (m_activArea.contains(worldPos))
    {
        m_sprite.setPosition(worldPos);
        window.draw(m_sprite);
    }
}


EntryDenied::EntryDenied(const std::string& fileName)
{
    if (!m_texture.loadFromFile(fileName))
    {
        throw missingTexture("Texture not found!\n");
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setScale(0.45f, 0.45f);
    setText(" Entry\nDenied");
}

void EntryDenied::setText(const std::string& textString)
{
    TextBuilder builder;
    m_EntryText = builder.setString(textString)
                         .setSize(20)
                         .setCol(sf::Color::Red)
                         .setPos(1080.f, 255.f)
                         .build();
}

void EntryDenied::handleClick()
{
    m_context->TransitionTo(std::make_unique<OpenStampRack>());
}

void EntryDenied::setupButton()
{
    m_button.setSize({150.f, 60.f});
    m_button.setFillColor(sf::Color::White);
    m_button.setPosition({1050.f, 245.f});

    m_button.setOutlineColor(sf::Color::Black);
    m_button.setOutlineThickness(4.f);
}

void EntryDenied::draw(sf::RenderWindow& window)
{
    window.draw(m_EntryText.getText());

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
    sf::Vector2u windowSize = window.getSize();
    m_activArea = sf::FloatRect(360.f, 305.f, windowSize.x - 360.f, windowSize.y - 305.f);

    if (m_activArea.contains(worldPos))
    {
        m_sprite.setPosition(worldPos);
        window.draw(m_sprite);
    }
}
