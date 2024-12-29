#include <utility>

#include "../Headers/ID.h"

void Id::create_document()
{

}


Id::Id(const sf::Vector2f pos, const std::string& name, const std::string& fileName, const float height, const float weight, std::string district)
: Documente(pos, name, fileName), m_height(height), m_weight(weight), m_district(std::move(district))
{

}

