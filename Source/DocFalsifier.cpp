#include "../Headers/DocFalsifier.h"
#include "../Headers/Pasaport.h"
#include "../Headers/ID.h"
#include "../Headers/Exceptions.h"
#include "../Headers/EntryPermit.h"

#include <random>

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
        std::cout << "\ndata falsificata" << std::endl;
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

        const auto& fakeDistrict = districts[nameDist(gen)];
        id->SetFakeDistrict(fakeDistrict);
        std::cout << "\ndistrict falsificata: " << fakeDistrict << std::endl;
    }
}


void PermitFalsifier::falsify(std::shared_ptr<Documente>& doc)
{
    if (auto entryPermit = std::dynamic_pointer_cast<EntryPermit>(doc))
    {
        sf::Texture fakeSealTexture;
        if (!fakeSealTexture.loadFromFile("Img/setSeals2.png"))
        {
            throw missingTexture("Texture not found!\n");
        }

        entryPermit->setFakeSeal(fakeSealTexture);
        std::cout << "\nfake seal";
    }
}