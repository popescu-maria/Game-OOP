#include "../Headers/FakeCat.h"
#include "../Headers/FalsifierFactory.h"
#include "../Headers/Exceptions.h"

#include <iostream>
#include <chrono>
#include <vector>
#include <random>


void FakeCat::createCurrentDocs(int levelNr)
{
    makeDoc(levelNr);

    if (!m_documente.empty())
    {
        FalsifierFactory factory;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, m_documente.size() - 1);

        auto randomDoc = m_documente[dist(gen)];

        if (auto falsifier = factory.getFalsifier(randomDoc))
        {
            falsifier->falsify(randomDoc);
        }
        else
        {
            throw missingFalsifier("No falsifier available for this document type.\n");
        }
    }
    else
    {
        throw missingDoc ("No documents available to falsify.\n");
    }
    for (const auto& doc : m_documente)
    {
        doc->setText();
    }
}

bool FakeCat::IsDocValid()
{
    return false;
}


