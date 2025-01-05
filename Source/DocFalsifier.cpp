#include "../Headers/DocFalsifier.h"
#include "../Headers/Pasaport.h"
#include "../Headers/ID.h"
#include <random>

#include "../Headers/EntryPermit.h"

void PasaportFalsifier::falsify(std::shared_ptr<Documente>& doc)
{
    if (auto passport = std::dynamic_pointer_cast<Pasaport>(doc))
    {
        auto today = std::chrono::system_clock::now();
        auto today_sys_days = std::chrono::floor<std::chrono::days>(today);

        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, 30);

        auto random_days = dist(gen);
        auto fakeExpDate = std::chrono::year_month_day{today_sys_days - std::chrono::days(random_days)};

        passport->SetFakeDate(fakeExpDate);
        std::cout << "\ndata falsificata: " << fakeExpDate << std::endl;
    }
}

void IDFalsifier::falsify(std::shared_ptr<Documente>& doc)
{
    if (auto id = std::dynamic_pointer_cast<Id>(doc))
    {
        static std::vector<std::string> districts = {
            "TORCOVANI", "PADURESTI",
            "MUSTANESTI", "GHEARASOVI", "PISICENA"
        };
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> nameDist(0, districts.size() - 1);

        id->SetFakeDistrict(districts[nameDist(gen)]);
        std::cout << "\ndistrict falsificata: " << districts[nameDist(gen)] << std::endl;
    }
}

void PermitFalsifier::falsify(std::shared_ptr<Documente>& doc)
{
    if (auto entryPermit = std::dynamic_pointer_cast<EntryPermit>(doc))
    {
        sf::Texture fakeSealTexture;
        if (!fakeSealTexture.loadFromFile("Img/setSeals2.png"))
        {
            throw std::runtime_error("Failed to load fake seal texture.");
        }

        const int sealWidth = 100;
        const int sealHeight = fakeSealTexture.getSize().y;

        const int numSeals = fakeSealTexture.getSize().x / sealWidth;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> sealDist(0, numSeals - 1);
        int randomSealIndex = sealDist(gen);

        sf::IntRect sealRect(randomSealIndex * sealWidth, 0, sealWidth, sealHeight);

        sf::Sprite fakeSealSprite;
        fakeSealSprite.setTexture(fakeSealTexture);
        fakeSealSprite.setTextureRect(sealRect);

        entryPermit->setFakeSeal(fakeSealSprite);
    }
}
