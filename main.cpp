
#include <Helper.h>
#include <iostream>
#include <chrono>

#include "Headers/Cat.h"
#include "Headers/FakeCat.h"


int main()
{

    std::cout << "Pisicile au cucerit cu succes taraPisicilor (numele dat de noi)!!\n";
    std::cout << "Ai fost repartizat la granita!\n";
    std::cout << "O cutie va fi oferita tie si familiei tale!\nSi 500 de monede" << std::endl;
    std::cout << "Misiunea ta este sa decizi daca pasapoartele noilor veniti sunt valide sau nu\n" <<
        "si sa raportezi totul consiliului de pisici\n";
    std::cout << "......................................................................\n";
    std::cout << "Pisicile care au orice detalii suspecte in pasaport (ex: este expirat, \n";
    std::cout << "nu respecta detaliile pisiciilor), sunt oameni deghizati si nu trebuie\n";
    std::cout << "lasa-ti in taraPisicilor\n" << std::endl;

    Cat myCat;
    FakeCat fakeCat;
    //Cat anotherCat;
    Pasaport currentPasaport;
    myCat.create_pasaport();
    currentPasaport = myCat.getPasaport();
    //myCat.create_pasaport(15, 10, 2024);

    std::cout << myCat << std::endl;
    std::cout << "pasaport:\n" << currentPasaport << std::endl;
    std::cout << "pisica fake\n" << fakeCat << std::endl;
    //std::cout << anotherCat << std::endl;

    Helper helper;
    helper.help();

    return 0;
}
