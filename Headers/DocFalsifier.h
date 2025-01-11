#pragma once

#include <memory>
#include "Documente.h"


class DocFalsifier
{
public:
    virtual ~DocFalsifier() = default;
    virtual void falsify(std::shared_ptr<Documente>& doc) = 0;
};

class PasaportFalsifier : public DocFalsifier
{
public:
    void falsify(std::shared_ptr<Documente>& doc) override;
};

class IDFalsifier : public DocFalsifier
{
public:
    void falsify(std::shared_ptr<Documente>& doc) override;
};

class PermitFalsifier : public DocFalsifier
{
public:
    //PermitFalsifier();
    void falsify(std::shared_ptr<Documente>& doc) override;
private:
    //sf::Texture fakeSealTexture;
};
