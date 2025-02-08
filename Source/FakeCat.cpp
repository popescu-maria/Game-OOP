#include "../Headers/FakeCat.h"
#include "../Headers/FalsifierFactory.h"
#include "../Headers/Exceptions.h"

#include <iostream>
#include <chrono>
#include <vector>
#include <random>

void FakeCat::createCurrentDocs(const int levelNr)
{
    makeDoc(levelNr);

    if (!m_documente.empty())
    {
        FalsifierFactory factory;
        std::random_device rd;
        std::mt19937 gen(rd());

        //last document has a higher chance of being falsified(60%)
        std::vector weights(m_documente.size(), 0.4 / (m_documente.size() - 1));
        weights.back() = 0.6;

        std::discrete_distribution<> dist(weights.begin(), weights.end());

        auto randomDoc = m_documente[dist(gen)];

        if (const auto falsifier = factory.getFalsifier(randomDoc))
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
        throw missingDoc("No documents available to falsify.\n");
    }
    for (const auto& doc : m_documente)
    {
        doc->setText();
    }
}

bool FakeCat::IsDocValid() const
{
    return false;
}