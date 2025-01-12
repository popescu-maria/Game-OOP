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
    return document->getFalsifier();
}