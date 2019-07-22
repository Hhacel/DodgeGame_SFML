#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ship.h"

int main()
{
    float width = 400;
    float height = 600;
    sf::Vector2f measurements = {10, 10};
    sf::Vector2f ship_size = {30, 60};
    sf::Vector2f window_size = {50, 500};
    sf::Texture ship_texture;
    ship_texture.loadFromFile("space_ship.jpg");

    sf::RenderWindow window(sf::VideoMode(width, height), "Dodge");
    Ship ship(sf::Vector2f(30, 60));
    ship.ship.setTexture(&ship_texture);
    ship.set_position(sf::Vector2f(50, 500));

    sf::Clock clock;
    sf::Time time_step = sf::seconds(0.4);

    while (window.isOpen())
    {



        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            ship.move({ship.move_speed, 0});
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            ship.move({-ship.move_speed, 0});
        }

        if (clock.getElapsedTime() > time_step)
        {
            if(time_step > sf::seconds(0.13))
            time_step -= sf::seconds(0.0005);
            ship.create_bullet(measurements);
            clock.restart();
        }
        ship.moveBullet(sf::Vector2f(0, -ship.gravity));



            window.clear();
            ship.draw_to(window);
            window.display();

    }
    return 0;
}
