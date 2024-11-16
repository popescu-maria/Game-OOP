
#include <Helper.h>
#include <iostream>

#include "Headers/GameLogic.h"


int main()
{
    std::cout << "\nPisicile au cucerit cu succes taraPisicilor (numele dat de noi)!!\n";
    std::cout << "Ai fost repartizat la granita!\n";
    std::cout << "O cutie va fi oferita tie si familiei tale\nSi 500 de monede" << std::endl;
    std::cout << "Misiunea ta este sa decizi daca pasapoartele noilor veniti sunt valide sau nu\n" <<
        "si sa raportezi totul consiliului de pisici\n";
    std::cout << "......................................................................\n";
    std::cout << "\nPisicile care au pasapoartele expirate, sunt oameni deghizati si nu trebuie\n";
    std::cout << "lasa-ti in taraPisicilor\n" << std::endl;

    Game currentGame;
    currentGame.Play();


    Helper helper;
    helper.help();

    return 0;
}
