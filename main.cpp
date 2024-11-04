
#include <Helper.h>
#include <iostream>

#include "Headers/Cat.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main() {
    unsigned int WindowWidth{600}, WindowHeight{800};

    sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "My window");
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color(100, 250, 50));
    float circle_x{40};
    float circle_y{300};
    float speed{0.3f};

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Movement logic based on key presses
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && circle_y > 0) {
        //     circle_y -= speed; // Move up
        // }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && circle_y < (float)WindowHeight - 2 * shape.getRadius()) {
        //     circle_y += speed; // Move down
        // }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && circle_x > 0) {
        //     circle_x -= speed; // Move left
        // }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && circle_x < (float)WindowWidth - 2 * shape.getRadius()) {
        //     circle_x += speed; // Move right
        // }

        // clear the window with black color
        window.clear(sf::Color::Black);

        shape.setPosition(circle_x, circle_y);

        circle_y += speed;
        if (circle_y < 0 || circle_y > WindowHeight - 2 * shape.getRadius())
        {
            speed = -speed;
        }


        window.draw(shape);

        window.display();
    }

    cat myCat("Sofi", "Striped", "Gray", "Green", 3, 'M');
    myCat.create_pasaport(15, 10, 2024);

    myCat.print_details();

    Helper helper;
    helper.help();

    return 0;
}
