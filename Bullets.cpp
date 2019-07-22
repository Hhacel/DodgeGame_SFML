#include "Bullets.h"

Bullets::Bullets()
{

}
void Bullets::create_bullet(sf::Vector2f measurments)
{
    bullet.push_back(sf::Vector2f(rd() % 400, 0));
}
void Bullets::moveBullet(sf::Vector2f distance)
{
        for (std::list<sf::Vector2f>::iterator it = bullet.begin(); it!= bullet.end(); it++ )
        {
            *it -= distance;
        }
}

Bullets::~Bullets()
{
    //dtor
}
