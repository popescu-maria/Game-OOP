#pragma once

#include "Cat.h"
#include "Pasaport.h"


class game {
    bool m_isGameOver = false;
    int m_score = 0;
    cat generateRandomCat();
    bool checkPlayerDecision(const cat& cat, const pasaport& pasaport);
public:

};


