#include "../Headers/FakeCat.h"
#include "../Headers/FalsifierFactory.h"

#include <iostream>
#include <chrono>
#include <vector>
#include <random>


void FakeCat::createCurrentDocs(int levelNr)
{
    Cat::createCurrentDocs(levelNr);

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
            std::cerr << "No falsifier available for this document type.\n";
        }
    }
    else
    {
        std::cerr << "No documents available to falsify.\n";
    }
}


bool FakeCat::IsDocValid()
{
    return false;
}


