#ifndef BULLETS_H
#define BULLETS_H
#include <SFML/Graphics.hpp>
#include <list>
#include <random>
#include <iostream>


class Bullets
{
    public:
        Bullets();
        virtual ~Bullets();

        std::list<sf::Vector2f> bullet;
        void create_bullet(sf::Vector2f measurments);
        void moveBullet(sf::Vector2f distance);
        void draw_bullet(sf::RenderWindow &window);
        void pop_bullet();

    protected:

    private:
        std::random_device rd;
};

#endif // BULLETS_H
