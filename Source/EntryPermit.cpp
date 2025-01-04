#include "../Headers/EntryPermit.h"

#include <utility>
#include <random>

void EntryPermit::create_document()
{
    auto today = std::chrono::system_clock::now();
    auto today_sys_days = std::chrono::floor<std::chrono::days>(today);

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 365);

    auto random_days = dist(gen);
    m_expDate = std::chrono::year_month_day{today_sys_days + std::chrono::days(random_days)};

    std::uniform_int_distribution<> passportNumDist(100000, 999999);
    m_passaportNr = "C-" + std::to_string(passportNumDist(gen));

    static std::vector<std::string> purposes = {"transit", "visit", "work", "immigration"};
    std::uniform_int_distribution<> purposeDist(0, purposes.size() - 1);
    m_purpose = purposes[purposeDist(gen)];

    std::uniform_int_distribution<> durationDist(1, 365);
    duration = durationDist(gen);


    if (!m_sealTexture.loadFromFile("Img/setSeals1.png"))
    {
        throw std::runtime_error("Failed to load seal texture.");
    }
    const int sealWidth = 100;
    const int sealHeight = m_sealTexture.getSize().y;
    const int numSeals = m_sealTexture.getSize().x / sealWidth;

    std::uniform_int_distribution<> sealDist(0, numSeals - 1);
    int randomSealIndex = sealDist(gen);

    m_sealRect = sf::IntRect(randomSealIndex * sealWidth, 0, sealWidth, sealHeight);

    setSeal(m_sealTexture, m_sealRect, sf::Vector2f(150.f, 200.f));

    const sf::Vector2f nameOffset(10.f, 20.f);
    const sf::Vector2f passportNrOffset(10.f, 200.f);
    const sf::Vector2f purposeOffset(10.f, 230.f);
    const sf::Vector2f durationOffset(10.f, 260.f);
    const sf::Vector2f expDateOffset(10.f, 290.f);

    TextBuilder builder;
    AddText(builder.setFont().setSize(30).setCol(sf::Color::Black)
                   .setPos(m_documentSprite.getPosition() + nameOffset)
                   .setString(m_name).build(), nameOffset);
    AddText(builder.setFont().setSize(20).setCol(sf::Color::Black)
                   .setPos(m_documentSprite.getPosition() + passportNrOffset)
                   .setString(m_passaportNr).build(), passportNrOffset);
    AddText(builder.setFont().setSize(20).setCol(sf::Color::Black)
                   .setPos(m_documentSprite.getPosition() + purposeOffset)
                   .setString(m_purpose).build(), purposeOffset);
    AddText(builder.setFont().setSize(20).setCol(sf::Color::Black)
                   .setPos(m_documentSprite.getPosition() + durationOffset)
                   .setString(std::to_string(duration) + " days").build(), durationOffset);
    AddText(builder.setFont().setSize(20).setCol(sf::Color::Black)
                       .setPos(m_documentSprite.getPosition() + expDateOffset)
                       .setString(get_date()).build(), expDateOffset);
}

EntryPermit::EntryPermit(sf::Vector2f pos, const std::string& name, const std::string& fileName, float scaleX = 0.5f, float scaleY = 0.5f)
    : Documente(pos, name, fileName)
{
    setScale(scaleX, scaleY);
    createDoc();
}

void EntryPermit::setFakeSeal(const sf::Sprite& fakeSprite)
{
    m_sealSprite = fakeSprite;
}

