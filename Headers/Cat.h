#pragma once

#include <string>
#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>
#include "Documente.h"

class Cat
{
private:
    sf::Texture m_baseTexture;
    std::vector<sf::Texture> m_layers;
    sf::Sprite m_finalSprite;
    sf::RenderTexture m_renderTexture;
    sf::Vector2<float> m_position{0.f, 0.f};

    bool m_isMoving{false};
    const float m_moveDistance{100.f};
    const float m_speed{};
    float targetX{0.f};

    // std::string m_patterns;
    // std::string m_color;
    // std::string m_color_of_eyes;

    void generateRandomCat();
    // [[nodiscard]] std::string getColorFilename() const;
    // [[nodiscard]] std::string getPatternsFilename() const;
    // [[nodiscard]] std::string getColorOfEyeFilename() const;

    std::string m_name;
    int m_age{};
    char m_gender{'F'};
    int m_height{};
    int m_weight{};

protected:
    std::vector<std::shared_ptr<Documente>> m_documente;

public:
    Cat() { generateRandomCat(); };

    Cat(const sf::RenderWindow& window, const std::string& fileName);

    //clears the m_documents vector and based on what level you are it gives the cat more or less documents
    //that the player has to check
    virtual void createCurrentDocs(int levelNr);
    void drawCurrentCat(sf::RenderWindow& window) const;
    virtual bool IsDocValid();
    [[nodiscard]] std::vector<std::shared_ptr<Documente>> getDocumente() const;

    void setMoveTarget();
    void move();

    std::vector<std::shared_ptr<Documente>>& operator+=(const std::shared_ptr<Documente>& doc);
    friend std::ostream& operator<<(std::ostream& os, const Cat& cat);

    virtual ~Cat() = default;
};


