#pragma once

#include <unordered_map>
#include <typeindex>
#include <memory>
#include "Documente.h"
#include "DocFalsifier.h"

class FalsifierFactory
{
public:
    FalsifierFactory();
    std::shared_ptr<DocFalsifier> getFalsifier(const std::shared_ptr<Documente>& document);
private:
    std::unordered_map<std::type_index, std::shared_ptr<DocFalsifier>> falsifierMap;
};