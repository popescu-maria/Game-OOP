#include "../Headers/FalsifierFactory.h"
#include "../Headers/Pasaport.h"
#include "../Headers/ID.h"

FalsifierFactory::FalsifierFactory()
{
    falsifierMap[typeid(Pasaport)] = std::make_shared<PasaportFalsifier>();
    falsifierMap[typeid(Id)] = std::make_shared<IDFalsifier>();
}

std::shared_ptr<DocFalsifier> FalsifierFactory:: getFalsifier(const std::shared_ptr<Documente>& document)
{
    auto it = falsifierMap.find(typeid(*document));
    if (it != falsifierMap.end())
    {
        return it->second;
    }
    return nullptr;
}