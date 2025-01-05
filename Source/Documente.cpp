#include <sstream>
#include <utility>
#include "../Headers/Documente.h"


Documente::Documente(const sf::Vector2f pos, std::string name, const std::string& fileName): m_position(pos),
    m_name(std::move(name))
{
    if (!m_texture.loadFromFile(fileName))
    {
        throw std::runtime_error("Failed to load document texture!");
    }
    m_documentSprite.setTexture(m_texture);
    m_documentSprite.setPosition(m_position);
}

Documente::Documente(const Documente& oth)
    : m_position(oth.m_position), m_documentSprite(oth.m_documentSprite),
      m_expDate(oth.m_expDate), m_name(oth.m_name)
{
}

void Documente::createDoc()
{
    create_document();
}

Documente& Documente::operator=(const Documente& oth)
{
    if (this != &oth)
    {
        m_position = oth.m_position;
        m_documentSprite = oth.m_documentSprite;
        m_expDate = oth.m_expDate;
        m_name = oth.m_name;
    }
    return *this;
}

std::string Documente::get_date() const
{
    std::ostringstream date_stream;
    date_stream << static_cast<unsigned>(m_expDate.month()) << "/"
        << static_cast<unsigned>(m_expDate.day()) << "/"
        << static_cast<int>(m_expDate.year());

    return date_stream.str();
}

sf::Vector2f Documente::getSize() const
{
    return {m_documentSprite.getGlobalBounds().width, m_documentSprite.getGlobalBounds().height};
}

sf::Vector2f Documente::getPos() const { return m_position; }

void Documente::setSeal(const sf::Texture& sealTexture, const sf::IntRect& rect, const sf::Vector2f& offset)
{
    m_sealSprite.emplace();
    m_sealSprite->setTexture(sealTexture);
    m_sealSprite->setTextureRect(rect);
    m_sealOffset = offset;
    m_sealSprite->setPosition(m_documentSprite.getPosition() + m_sealOffset);
    m_sealSprite->setScale(0.5f, 0.5f);
}

void Documente::setScale(float x, float y)
{
    m_documentSprite.setScale(x, y);
}

void Documente::AddText(const Text& text, const sf::Vector2f& offset)
{
    m_textsWithOffsets.emplace_back(text, offset);
}

void Documente::checkBounds(sf::RenderWindow& window)
{
    float topBound = 305.f;
    float leftBound = 350.f;

    sf::Vector2u windowSize = window.getSize();
    auto rightBound = static_cast<float>(windowSize.x);
    auto bottomBound = static_cast<float>(windowSize.y);

    sf::Vector2f position = m_documentSprite.getPosition();
    sf::Vector2f size(m_documentSprite.getGlobalBounds().width, m_documentSprite.getGlobalBounds().height);

    if (position.x < leftBound) {
        position.x = leftBound;
    }
    if (position.y < topBound) {
        position.y = topBound;
    }
    if (position.x + size.x > rightBound) {
        position.x = rightBound - size.x;
    }
    if (position.y + size.y > bottomBound) {
        position.y = bottomBound - size.y;
    }

    m_documentSprite.setPosition(position);

    for (auto& [text, offset] : m_textsWithOffsets) {
        text.getText().setPosition(position + offset);
    }
    if (m_sealSprite)
    {
        m_sealSprite->setPosition(position + m_sealOffset);
    }
}

void Documente::move(sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f worldMousePos = window.mapPixelToCoords(mousePos);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (!m_isDragging && m_documentSprite.getGlobalBounds().contains(worldMousePos))
        {
            m_isDragging = true;
            m_dragOffset = worldMousePos - m_documentSprite.getPosition();
        }

        if (m_isDragging)
        {
            m_documentSprite.setPosition(worldMousePos - m_dragOffset);

            for (auto& [text, offset] : m_textsWithOffsets) {
                text.getText().setPosition(worldMousePos - m_dragOffset + offset);
            }
            //if the document has a seal, move it
            if (m_sealSprite)
            {
                m_sealSprite->setPosition(worldMousePos - m_dragOffset + m_sealOffset);
            }
        }
    }
    else
    {
        m_isDragging = false;
    }
    checkBounds(window);
}

void Documente::drawDoc(sf::RenderWindow& window) const
{
    window.draw(m_documentSprite);

    for (const auto& [text, offset] : m_textsWithOffsets) {
        window.draw(text.getText());
    }
    //if the document has a seal, draw it
    if (m_sealSprite)
    {
        window.draw(*m_sealSprite);
    }
}

