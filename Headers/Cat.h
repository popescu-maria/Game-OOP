#pragma once

#include <string>
#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>
#include "Documente.h"

class Cat
{
    sf::Texture m_baseTexture;
    std::vector<sf::Texture> m_layers;
    sf::Sprite m_finalSprite;
    sf::RenderTexture m_renderTexture;
    sf::Vector2<float> m_position{0.f, 0.f};

    const float m_distance{};

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

    static std::vector<std::string> loadNamesFromFile(const std::string& filename);
    static std::vector<std::string> s_names;
protected:
    std::vector<std::shared_ptr<Documente>> m_documente;
    void makeDoc(int levelNr);

public:
    Cat() { generateRandomCat(); };

    Cat(const sf::RenderWindow& window, const std::string& fileName);

    //clears the m_documents vector and based on what level you are it gives the cat more or less documents
    //that the player has to check
    virtual void createCurrentDocs(int levelNr);
    void clearDoc();
    void drawCurrentCat(sf::RenderWindow& window) const;
    virtual bool IsDocValid() const;
    [[nodiscard]] const std::vector<std::shared_ptr<Documente>>& getDocumente() const;

    void move();
    void leave();

    std::vector<std::shared_ptr<Documente>>& operator+=(const std::shared_ptr<Documente>& doc);
    friend std::ostream& operator<<(std::ostream& os, const Cat& cat);

    virtual ~Cat() = default;
};
