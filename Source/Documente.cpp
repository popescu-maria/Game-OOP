#include <sstream>
#include <utility>
#include "../Headers/Documente.h"


Documente::Documente(const sf::Vector2f pos, std::string  name, const std::string& fileName): m_position(pos), m_name(std::move(name))
{
    if(!m_texture.loadFromFile(fileName)){
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
    if(this != &oth)
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

sf::Vector2f Documente::getSize() const {
    return { m_documentSprite.getGlobalBounds().width, m_documentSprite.getGlobalBounds().height };
}
sf::Vector2f Documente::getPos() const { return m_position; }

void Documente::setScale(float x, float y)
{
    m_documentSprite.setScale(x, y);
}

void Documente::move() {
    // Check if the right mouse button is pressed
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        // Get the mouse position relative to the window
        sf::Vector2i mousePos = sf::Mouse::getPosition();  // Position in window coordinates
        sf::Vector2f worldMousePos(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

        // Check if the mouse is over the document (check if the mouse is inside the sprite's bounds)
        if (m_documentSprite.getGlobalBounds().contains(worldMousePos)) {
            // Set the document's position to follow the mouse
            m_documentSprite.setPosition(worldMousePos);
        }
    }
}

void Documente::AddText(const Text& text)
{
    m_texts.push_back(text);
}

void Documente::drawDoc(sf::RenderWindow& window) const
{
    window.draw(m_documentSprite);
    // for (const auto& text : m_texts) {
    //     window.draw(text.getText());
    // }
}

