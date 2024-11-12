
#include <Helper.h>
#include <iostream>

#include "Headers/Cat.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Headers/FakeCat.h"


int main()
{
    // const unsigned int WindowWidth{1000}, WindowHeight{800};
    //
    // sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "My window");
    // sf::CircleShape shape(50.f);
    //
    // shape.setFillColor(sf::Color(100, 250, 50));
    //
    // float circle_x{200};
    // float circle_y{700};
    //
    // float velocity{0};
    // const float gravity{1};
    //
    // sf:: Texture textureCat;
    // sf:: Sprite spriteCat;
    //
    // if (!textureCat.loadFromFile("pisica.png"))
    // {
    //     std:: cout << "eroare incarcare";
    // }
    // spriteCat.setTexture(textureCat);
    //
    // while (window.isOpen())
    // {
    //     // check all the window's events that were triggered since the last iteration of the loop
    //     sf::Event event;
    //
    //     while (window.pollEvent(event))
    //     {
    //         // "close requested" event: we close the window
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }
    //
    //
    //     // if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && circle_y > 0) {
    //     //     circle_y -= velocity; // Move up
    //     // }
    //     // if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && circle_y < (float)WindowHeight - 2 * shape.getRadius()) {
    //     //     circle_y += velocity; // Move down
    //     // }
    //     // if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && circle_x > 0) {
    //     //     circle_x -= velocity; // Move left
    //     // }
    //     // if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && circle_x < (float)WindowWidth - 2 * shape.getRadius()) {
    //     //     circle_x += velocity; // Move right
    //     // }
    //
    //
    //     if(circle_y >= WindowHeight - 2 * shape.getRadius())
    //     {
    //         velocity = 0;
    //     }
    //     else
    //     {
    //         velocity += gravity;
    //     }
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && circle_y >= WindowHeight - 2 * shape.getRadius())
    //     {
    //         velocity -= 15;
    //     }
    //     circle_y += velocity;
    //
    //
    //     // clear the window with black color
    //     window.clear(sf::Color::Black);
    //
    //     shape.setPosition(circle_x, circle_y);
    //
    //      // if (circle_y < 0 || circle_y > WindowHeight - 2 * shape.getRadius())
    //      // {
    //      //     velocity = -velocity;
    //      // }
    //
    //
    //     window.draw(spriteCat);
    //     window.draw(shape);
    //
    //     window.display();
    // }
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
    std::cout << currentPasaport << std::endl;
    std::cout << "pisica fake\n" << fakeCat << std::endl;
    //std::cout << anotherCat << std::endl;

    Helper helper;
    helper.help();

    return 0;
}
