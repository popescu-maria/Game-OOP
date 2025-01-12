#include "../Headers/FalsifierFactory.h"
#include "../Headers/Pasaport.h"
#include "../Headers/ID.h"
#include "../Headers/EntryPermit.h"

FalsifierFactory::FalsifierFactory()
{
    falsifierMap[typeid(Pasaport)] = std::make_shared<PasaportFalsifier>();
    falsifierMap[typeid(Id)] = std::make_shared<IDFalsifier>();
    falsifierMap[typeid(EntryPermit)] = std::make_shared<PermitFalsifier>();

}

std::shared_ptr<DocFalsifier> FalsifierFactory:: getFalsifier(const std::shared_ptr<Documente>& document)
{
    if (!document)
    {
        return nullptr;
    }

    const std::type_info& documentType = typeid(*document);  // Avoid side effects
    if (const auto it = falsifierMap.find(documentType); it != falsifierMap.end())
    {
        return it->second;
    }
    return nullptr;
}