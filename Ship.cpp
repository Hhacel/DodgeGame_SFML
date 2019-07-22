#include "Ship.h"

Ship::Ship(sf::Vector2f size)
{
    move_speed = 0.3;
    gravity = 0.3;
    ship.setSize(size);
}

Ship::~Ship()
{
    //dtor
}

void Ship::draw_to(sf::RenderWindow &window)
{

    window.draw(ship);
    for (std::list<sf::Vector2f>::iterator it = bullet.begin(); it!= bullet.end(); it++ )
        {
            sf::RectangleShape rectangle(sf::Vector2f(10,10));
            rectangle.setPosition(*it);
            window.draw(rectangle);
        }
}

void Ship::move(sf::Vector2f distance)
{
    ship.move(distance);
}
void Ship::set_position(sf::Vector2f new_position)
{
    ship.setPosition(new_position);
}

bool Ship::collision_test()
{
for (std::list<sf::Vector2f>::iterator it = bullet.begin(); it!= bullet.end(); it++)
{
    if(ship.getGlobalBounds().contains(*it))
        return true;
}
        return false;
}
